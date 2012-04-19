import std.algorithm, std.concurrency, std.stdio;

void main() {
   enum bufferSize = 1024 * 100;
   auto tid = spawn(&fileWriter);
   foreach (buffer; stdin.byChunk(bufferSize)) {
      send(tid, buffer.idup);
   }
}

void fileWriter() {
   for (;;) {
      auto buffer = receiveOnly!(immutable(ubyte)[])();
      stdout.write(buffer);
   }
}
