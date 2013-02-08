#include "agent.h"
#include "data_store_driver.h"
#include "data_store.h"
#include "mysql_client.h"
#include "memcache_driver.h"
#include "memcache_client.h"
#include "read_cache_decorator.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;


void read_hash(data_store_client ms) {
    map<string,int> rows;
    map<string,int>::iterator row_it;

    try {
        rows = ms.findHash("gold");
    } catch (bool return_code) {
        cout << "no rows found";
        return;
    }
    for(row_it = rows.begin(); row_it != rows.end(); ++row_it) {
        cout << (*row_it).first << (*row_it).second;
    }
    cout << endl;
}

void read_mysql() {
    data_store_driver driver;
    mysql_client ms(driver);
    map<string,int> rows;
    map<string,int>::iterator row_it;

    try {
        rows = ms.findHash("gold");
    } catch (bool return_code) {
        cout << "no rows found";
        return;
    }
    for(row_it = rows.begin(); row_it != rows.end(); ++row_it) {
        cout << (*row_it).first << (*row_it).second;
    }
    cout << endl;
}

void read_memcache() {
    data_store_driver driver;
    memcache_client ms(driver);
    map<string,int> rows;
    map<string,int>::iterator row_it;

    try {
        rows = ms.findHash("gold");
    } catch (bool return_code) {
        cout << "no rows found";
        return;
    }
    for(row_it = rows.begin(); row_it != rows.end(); ++row_it) {
        cout << (*row_it).first << (*row_it).second;
    }
    cout << endl;
}

void read_ds() {
    data_store_agent agent;
    data_store_driver driver;
    data_store_client ds(driver);
    vector<string> names;
    vector<string>::iterator it;

    ds = agent.ask("simple");
    try {
        names = ds.find("gold");
    } catch (bool return_code) {
        cout << "no rows found";
        return;
    }
    for(it=names.begin(); it<names.end(); ++it) {
        cout << *it;
    }
    cout << endl;
}

void read_vector(data_store_client ds) {
    vector<string> names;
    vector<string>::iterator it;

    try {
        names = ds.find("gold");
    } catch (bool return_code) {
        cout << "no rows found";
        return;
    }
    for(it=names.begin(); it<names.end(); ++it) {
        cout << *it;
    }
    cout << endl;
}


int main() {
    data_store_driver driver;
    mysql_client mys(driver);
    memcache_driver cache;
    memcache_client ms(driver);
    read_cache_decorator stacked(cache);
    stacked.setDs(mys);

    read_ds();
    read_mysql();
    read_memcache();
    read_vector(ms);
    read_hash(ms);
    read_hash(stacked);
}

