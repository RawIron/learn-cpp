#ifndef DATA_STORE_DECORATOR_H
#define DATA_STORE_DECORATOR_H

#include <string>
#include <vector>
#include <map>
#include "data_store.h"
#include "data_store_driver.h"
using namespace std;


class data_store_client_decorator : public data_store_client {
    public:
    explicit data_store_client_decorator(data_store_driver ds) : data_store_client(ds), decorated_client(ds) {};
    void setDs(const data_store_client dc) {decorated_client = dc;};
    virtual vector<string> find(const string query) = 0;
    virtual map<string,int> findHash(const string query) = 0;
    protected:
    data_store_client decorated_client;
};

#endif
