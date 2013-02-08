#ifndef MEMCACHE_H
#define MEMCACHE_H

#include <string>
#include <map>
#include "data_store.h"
#include "data_store_driver.h"
using namespace std;

class memcache_client : public data_store_client {
    public:
    explicit memcache_client(data_store_driver ds);
    vector<string> find(string query);
    map<string,int> findHash(string query);
};

#endif
