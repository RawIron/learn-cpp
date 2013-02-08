#include "memcache_client.h"
#include <string>
#include <vector>
#include <map>

using namespace std;

memcache_client::memcache_client(data_store_driver ds) : data_store_client(ds) {};

vector<string> memcache_client::find(string query) {
    map<string,int> hash;
    vector<string> result;

    hash = findHash(query);
    result = convert_hash(hash);
    return result;
}

map<string,int> memcache_client::findHash(string query) {
    map<string,int> result;
    result = driver.findHash(query);
    return result;
}

