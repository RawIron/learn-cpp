#ifndef MEMCACHE_DRIVER_H
#define MEMCACHE_DRIVER_H

#include <string>
#include <vector>
#include <map>
#include "data_store_driver.h"
using namespace std;


class memcache_driver : public data_store_driver_interface {
    public:
    explicit memcache_driver();
    virtual map<string,int> findHash(string query) throw(bool);
    private:
    map<string,int> storage;
};

#endif
