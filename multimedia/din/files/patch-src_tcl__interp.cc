--- src/tcl_interp.cc.orig	2017-09-08 00:02:00 UTC
+++ src/tcl_interp.cc
@@ -22,7 +22,7 @@ extern float VOLUME;
 void add_commands (Tcl_Interp* ti);
 
 int tcl_run (ClientData cd, Tcl_Interp* ti, int objc, Tcl_Obj* CONST objv[]) {
-	command* cmdp = cmdlst.cmds [(unsigned int) cd];
+	command* cmdp = cmdlst.cmds [(uintptr_t) cd];
   if (cmdp) {
     cmdlst.result = "";
     vector<string> args;
