#ifndef MYSQL_H
#define MYSQL_H

#include <string>
#include <map>
#include "data_store.h"
#include "data_store_driver.h"
using namespace std;

class mysql_client : public data_store_client {
    public:
    explicit mysql_client(data_store_driver ds) : data_store_client(ds) {};
    virtual vector<string> find(string query);
    virtual map<string,int> findHash(string query);
};

#endif
