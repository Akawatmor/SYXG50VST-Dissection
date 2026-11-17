// Export decompiler evidence from the user's supplied binary.
// @category S-YXG50
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.address.Address;
import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.HashSet;

public class DecompileEngine extends GhidraScript {
    public void run() throws Exception {
        File directory = new File(getScriptArgs()[0]);
        directory.mkdirs();
        DecompInterface decompiler = new DecompInterface();
        decompiler.openProgram(currentProgram);
        long[] roots = {
            0x10032b80L, 0x100140f0L, 0x10016fa0L, 0x10016fd0L,
            0x1000b770L, 0x1000bd50L, 0x1000c5e0L,
            0x10017300L, 0x10017310L, 0x10018150L, 0x100181a0L,
            0x1001f870L, 0x1002fd30L, 0x1002fcd0L, 0x1002fc80L,
            0x10016d00L, 0x10016b00L
        };
        ArrayDeque<Function> queue = new ArrayDeque<>();
        for (long value : roots) {
            Address address = toAddr(value);
            Function function = getFunctionAt(address);
            if (function == null) function = createFunction(address, null);
            if (function != null) queue.add(function);
        }
        FunctionIterator functions = currentProgram.getFunctionManager().getFunctions(true);
        while (functions.hasNext()) {
            Function function = functions.next();
            long address = function.getEntryPoint().getOffset();
            if ((address >= 0x10014000L && address < 0x10017300L) ||
                (address >= 0x10018000L && address < 0x1001C300L)) queue.add(function);
        }
        HashSet<Address> visited = new HashSet<>();
        try (PrintWriter index = new PrintWriter(new File(directory, "index.tsv"), "UTF-8")) {
            while (!queue.isEmpty() && visited.size() < 450 && !monitor.isCancelled()) {
                Function function = queue.remove();
                Address address = function.getEntryPoint();
                if (!visited.add(address)) continue;
                DecompileResults results = decompiler.decompileFunction(function, 40, monitor);
                String filename = address.toString()+".c";
                try (PrintWriter writer = new PrintWriter(new File(directory, filename), "UTF-8")) {
                    writer.println("/* Ghidra analysis of supplied S-YXG50.dll at "+address+" */");
                    if (results.decompileCompleted()) writer.println(results.getDecompiledFunction().getC());
                    else writer.println("/* "+results.getErrorMessage()+" */");
                }
                index.println(address+"\t"+function.getName()+"\t"+filename);
                for (Function callee : function.getCalledFunctions(monitor)) {
                    long offset = callee.getEntryPoint().getOffset();
                    if (offset >= 0x10003700L && offset < 0x10030280L) queue.add(callee);
                }
            }
        } finally {
            decompiler.dispose();
        }
        println("Exported "+visited.size()+" functions to "+directory);
    }
}
