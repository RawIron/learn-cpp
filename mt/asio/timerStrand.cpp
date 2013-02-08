#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <iostream>
#include "timerStrand.h"

using std::cout;
using std::endl;


producer_consumer::producer_consumer(boost::asio::io_service& ios)
  : strand_(ios),
  timer1_(ios, boost::posix_time::seconds(1) ),
  timer2_(ios, boost::posix_time::seconds(1) )
{
   count_ = 0;
   timer1_.async_wait(
     strand_.wrap(
     boost::bind(&producer_consumer::producer, this))); 
}

void producer_consumer::producer() {
  if ( count_ < num) {
    ++count_;
    intvec_.push_back(count_);
    std::cout << count_ <<
     " pushed back into integer vector." << std::endl;
    timer1_.async_wait(strand_.wrap(
         boost::bind(&producer_consumer::producer, this)));
    timer2_.async_wait(strand_.wrap(
         boost::bind(&producer_consumer::consumer, this)));
  }
}

void producer_consumer::consumer() {
  if (( count_ <= num ) &&
   ( !intvec_.empty()) ) {
    std::cout << intvec_.back()
     << " in the integer vector is consumed " << endl;
    intvec_.pop_back();
    timer2_.async_wait(strand_.wrap(
         boost::bind(&producer_consumer::consumer, this)));
  }
}

producer_consumer::~producer_consumer() {
  std::cout << "At the end, size of the vector container is: "
    << intvec_.size() << std::endl;
}

