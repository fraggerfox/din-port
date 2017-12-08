--- src/din.cc.orig	2017-09-07 23:35:58 UTC
+++ src/din.cc
@@ -591,7 +591,7 @@ void din::load_drones () {
 			file >> ignore >> di.tracking;
       if (di.tracking) {
         int id; file >> id;
-        di.tracked_drone = (drone *)id;
+        di.tracked_drone = (drone *) id;
         trackers.push_back (pdi);
       }
 
@@ -664,20 +664,20 @@ void din::load_drones () {
     // convert tracked drone
     for (drone_iterator i = trackers.begin (), j = trackers.end(); i != j; ++i) {
       drone& di = *(*i);
-      int id = (int) di.tracked_drone;
+      int id = (uintptr_t) di.tracked_drone;
       di.tracked_drone = get_drone (id);
     }
 
 		// convert targets
 		for (drone_iterator i = drones.begin (), j = drones.end (); i != j; ++i) {
 			drone& di = *(*i);
-			if (di.num_targets) for (int i = 0; i < di.num_targets; ++i) di.targets[i] = get_drone ((int) di.targets[i]);
+			if (di.num_targets) for (int i = 0; i < di.num_targets; ++i) di.targets[i] = get_drone ((uintptr_t) di.targets[i]);
 		}
 
 		// convert satellites
 		for (drone_iterator i = satellites.begin (), j = satellites.end (); i != j; ++i) {
 			drone& di = *(*i);
-			di.target = get_drone ((int)di.target);
+			di.target = get_drone ((uintptr_t) di.target);
 		}
 
     update_drone_players ();
@@ -689,6 +689,7 @@ void din::load_drones () {
 
     dlog << ", done. >>>" << endl;
   }
+
 }
 
 void din::save_drones () {
@@ -772,7 +773,7 @@ void din::save_drones () {
     file << "drone_tracked_by_gravity ";
     if (dinfo.gravity.tracked_drone) {
       file << dinfo.gravity.tracked_drone->id << endl;
-    } else file << (int) dinfo.gravity.tracked_drone << endl;
+    } else file << '0' << endl;
       
     dlog << "+++ saved " << num_drones << " drones in: " << drone_file << " +++" << endl;
   }
