#include "read_cache_decorator.h"
#include <string>
#include <vector>
#include <map>

using namespace std;


vector<string> read_cache_decorator::find(string query) {
    vector<string> result;
    map<string,int> hash;

    hash = findHash(query);
    result = convert_hash(hash);
    return result;
}

map<string,int> read_cache_decorator::findHash(string query) {
    map<string,int> result;

    try {
        result = driver.findHash(query);
    } catch (bool) {
        result = decorated_client.findHash(query);
    }
    return result;
}

