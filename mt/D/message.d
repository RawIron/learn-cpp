import std.concurrency, std.stdio;

void main() {
   auto low = 0, high = 100;
   auto tid = spawn(&writer);
   foreach (i; low .. high) {
      writeln("Main thread: ", i);
      tid.send(thisTid, i);
      //enforce(receiveOnly!Tid() == tid);
      receiveOnly!Tid();
   }
}

void writer() {
   for (;;) {
      auto msg = receiveOnly!(Tid, int)();
      writeln("Secondary thread: ", msg[1]);
      msg[0].send(thisTid);
   }
}
