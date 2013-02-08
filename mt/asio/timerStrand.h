#ifndef TIMER_STRAND_H
#define TIMER_STRAND_H
#include <boost/asio.hpp>

class producer_consumer {
public:
  producer_consumer(boost::asio::io_service& ios);
  ~producer_consumer();
  void producer(); // producer callback handler
  void consumer(); // consumer callback handler
private:
  boost::asio::strand strand_;
  boost::asio::deadline_timer timer1_;
  boost::asio::deadline_timer timer2_;
  int count_; // data member shared between producer and consumer
  std::vector<int> intvec_; // data structure shared between producer and consumer
  enum { num = 10 }; // maximum number of integers added to the container
};
// std::cout is not thread-safe; it is implicitly shared between producer and consumer

#endif
