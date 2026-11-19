// @category S-YXG50
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import java.io.File;
import java.io.PrintWriter;
public class DecompileVegParameters extends GhidraScript {
 public void run() throws Exception {
  File dir=new File(getScriptArgs()[0]);dir.mkdirs();
  DecompInterface decompiler=new DecompInterface();decompiler.openProgram(currentProgram);
  try {
   FunctionIterator it=currentProgram.getFunctionManager().getFunctions(true);
   while(it.hasNext()){
    Function f=it.next();long a=f.getEntryPoint().getOffset();
    if(!((a>=0x10012000L&&a<0x100136f0L)||(a>=0x10004f00L&&a<0x10005300L)||a==0x10002ed0L||a==0x10003810L))continue;
    try(PrintWriter out=new PrintWriter(new File(dir,f.getEntryPoint()+".c"),"UTF-8")){
     out.println("/* VEG parameter conversion, VA "+f.getEntryPoint()+" */");
     var result=decompiler.decompileFunction(f,45,monitor);
     out.println(result.decompileCompleted()?result.getDecompiledFunction().getC():result.getErrorMessage());
    }
   }
  }finally{decompiler.dispose();}
 }
}
