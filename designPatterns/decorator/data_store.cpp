#include "data_store.h"
#include "data_store_driver.h"
#include <string>
#include <vector>
#include <map>

using namespace std;


vector<string> data_store_client::find(string query) {
    vector<string> result;
    map<string,int> hash;

    hash = findHash(query);
    result = convert_hash(hash);
    return result;
}

map<string,int> data_store_client::findHash(string query) {
    map<string,int> result;
    result = driver.findHash(query);
    return result;
}

vector<string> convert_hash(map<string,int> rs) {
    map<string,int> hash;
    map<string,int>::iterator it_hash;
    vector<string> result;
    vector<string>::iterator it_vector;

    for (it_hash=hash.begin(); it_hash != hash.end(); ++it_hash) {
        it_vector = result.insert(it_vector, (*it_hash).first);
    }
    return result;
}

