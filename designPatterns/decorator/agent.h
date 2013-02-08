#ifndef DATA_STORE_AGENT_H
#define DATA_STORE_AGENT_H

#include <string>
#include <vector>
#include <map>
#include "data_store.h"


class data_store_agent_interface {
    public:
    virtual data_store_client ask(std::string question) = 0;
};

class data_store_agent : public data_store_agent_interface {
    public:
    virtual data_store_client ask(std::string question);
};

#endif
