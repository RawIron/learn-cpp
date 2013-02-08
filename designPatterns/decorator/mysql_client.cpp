#include "mysql_client.h"
#include <string>
#include <vector>
#include <map>

using namespace std;


vector<string> mysql_client::find(string query) {
    map<string,int> hash;
    vector<string> result;

    hash = findHash(query);
    result = convert_hash(hash);
    return result;
}

map<string,int> mysql_client::findHash(string query) {
    map<string,int> result;
    result = driver.findHash(query);
    return result;
}


