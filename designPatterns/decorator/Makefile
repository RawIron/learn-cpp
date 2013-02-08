agent.o:	agent.cpp agent.h data_store.h
	g++ -c --debug agent.cpp

data_store_driver.o:	data_store_driver.cpp data_store_driver.h
	g++ -c --debug data_store_driver.cpp

data_store.o:	data_store.cpp data_store.h
	g++ -c --debug data_store.cpp

mysql_client.o:	mysql_client.cpp mysql_client.h data_store.h
	g++ -c --debug mysql_client.cpp

memcache_driver.o:	memcache_driver.cpp memcache_driver.h
	g++ -c --debug memcache_driver.cpp

memcache_client.o:	memcache_client.cpp memcache_client.h data_store.h
	g++ -c --debug memcache_client.cpp

read_cache_decorator.o:	read_cache_decorator.cpp read_cache_decorator.h data_store_decorator.h
	g++ -c --debug read_cache_decorator.cpp

main.o:	main.cpp
	g++ -c --debug main.cpp

a.out:	main.o agent.o data_store.o mysql_client.o memcache_client.o read_cache_decorator.o data_store_driver.o memcache_driver.o
	g++ -lm main.o agent.o data_store.o mysql_client.o memcache_client.o read_cache_decorator.o data_store_driver.o memcache_driver.o

clean:	
	rm -f *.o


