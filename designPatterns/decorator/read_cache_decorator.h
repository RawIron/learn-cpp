#ifndef READ_CACHE_H
#define READ_CACHE_H

#include <string>
#include <vector>
#include <map>
#include "data_store_decorator.h"
using namespace std;


class read_cache_decorator : public data_store_client_decorator {
    public:
    explicit read_cache_decorator(data_store_driver ds) : data_store_client_decorator(ds) {};
    virtual vector<string> find(string query);
    virtual map<string,int> findHash(string query);
};

#endif
