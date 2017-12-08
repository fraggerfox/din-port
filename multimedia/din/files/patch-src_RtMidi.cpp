--- src/RtMidi.cpp.orig	2017-12-06 19:45:51 UTC
+++ src/RtMidi.cpp
@@ -3409,7 +3409,7 @@ int jackProcessIn( jack_nframes_t nframe
   JackMidiData *jData = (JackMidiData *) arg;
   MidiInApi :: RtMidiInData *rtData = jData->rtMidiIn;
   jack_midi_event_t event;
-  jack_time_t long long time;
+  jack_time_t time;
 
   // Is port created?
   if ( jData->port == NULL ) return 0;
