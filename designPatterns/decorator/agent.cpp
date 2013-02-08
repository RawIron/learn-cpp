#include <string>
#include "agent.h"
#include "data_store.h"
#include "data_store_driver.h"

using namespace std;

data_store_client data_store_agent::ask(string question) {
    data_store_driver driver;
    data_store_client ds(driver);
    return ds;
}


