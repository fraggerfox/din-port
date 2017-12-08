--- src/mondrian.cc.orig	2017-09-06 22:34:38 UTC
+++ src/mondrian.cc
@@ -217,7 +217,7 @@ void mondrian::freeze_thaw_balls (list<b
   for (balls_iterator p = _balls.begin (), q = _balls.end (); p != q; ++p) {
     ball* b = *p;
     b->frozen = !b->frozen;
-		if (b->frozen == 0 && b->V == 0) cons << YELLOW << "Defrosted ball [" << (unsigned int) b << "] cant move [0 speed]" << eol;
+		if (b->frozen == 0 && b->V == 0) cons << YELLOW << "Defrosted ball [" << (uintptr_t) b << "] cant move [0 speed]" << eol;
   }
 }
 
@@ -225,7 +225,7 @@ void mondrian::freeze_balls (list<ball*>
   for (balls_iterator p = _balls.begin (), q = _balls.end (); p != q; ++p) {
     ball* b = *p;
     b->frozen = 1;
-		if (b->V == 0) cons << YELLOW << "Ball [" << (unsigned int) b << "] cant move already [0 speed]" << eol;
+		if (b->V == 0) cons << YELLOW << "Ball [" << (uintptr_t) b << "] cant move already [0 speed]" << eol;
   }
 }
 
@@ -233,7 +233,7 @@ void mondrian::thaw_balls (list<ball*>& 
   for (balls_iterator p = _balls.begin (), q = _balls.end (); p != q; ++p) {
     ball* b = *p;
     b->frozen = 0;
-		if (b->V == 0) cons << YELLOW << "Defrosted ball [" << (unsigned int) b << "] cant move [0 speed]" << eol;
+		if (b->V == 0) cons << YELLOW << "Defrosted ball [" << (uintptr_t) b << "] cant move [0 speed]" << eol;
   }
 }
 
@@ -1651,7 +1651,7 @@ void mondrian::load_boxes_and_balls () {
 			for (int p = 0; p < rect::nedges; ++p) {
 				list<slit*>& ls = R->slits[p];
 				for (slit_iterator r = ls.begin (), s = ls.end (); r != s; ++r) {
-					int ix = (int) *r;
+					int ix = (uintptr_t) *r;
 					*r = get_slit_from_index (ix);
 				}
 			}
