#ifndef DATA_STORE_CLIENT_H
#define DATA_STORE_CLIENT_H

#include <string>
#include <vector>
#include <map>
#include "data_store_driver.h"


class data_store_client {
    public:
    explicit data_store_client(data_store_driver ds) : driver(ds) {};
    virtual std::vector<std::string> find(std::string query);
    virtual std::map<std::string,int> findHash(std::string query);
    protected:
    data_store_driver driver;
};

vector<string> convert_hash(map<string,int> rs);

#endif
