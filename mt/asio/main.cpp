#include <boost/thread.hpp>
#include "timerStrand.h"

int main() {
  boost::asio::io_service ios;
  producer_consumer pc(ios);

  // run producer,consumer in new thread
  boost::thread t(boost::bind(&boost::asio::io_service::run, &ios));
  // run producer,consumer in current (main) thread
  ios.run();

  t.join(); 
  return 0;
}

