boost_test:	boost_test.cpp
	g++ -o boost_test boost_test.cpp /usr/lib/libboost_thread.a -lpthread

boost_callable:	boost_callable.cpp
	g++ -o boost_callable boost_callable.cpp /usr/lib/libboost_thread.a -lpthread
boost_class:	boost_class.cpp
	g++ -o boost_class boost_class.cpp /usr/lib/libboost_thread.a -lpthread

boost_mutex:	boost_mutex.cpp
	g++ -o boost_mutex boost_mutex.cpp /usr/lib/libboost_thread.a -lpthread
boost_mutex2:	boost_mutex2.cpp
	g++ -o boost_mutex2 boost_mutex2.cpp /usr/lib/libboost_thread.a -lpthread

boost_condition:	boost_condition.cpp
	g++ -o boost_condition boost_condition.cpp /usr/lib/libboost_thread.a -lpthread

clean:
	rm -f *.o boost_mutex boost_mutex2 boost_test boost_callable boost_condition boost_class
