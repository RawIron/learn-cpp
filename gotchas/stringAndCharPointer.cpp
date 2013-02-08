#include <string>
#include <iostream>
#include <fstream>


struct result {
    std::string s;
    int error;
};


result f(char a[]) {
    result r;
    a[1] = 'b';
    r.s = std::string(a);
    r.error = 0;
    return r;
}

result f(std::string a) {
    result r;
    char more[] = " there";
    a += more;
    r.s = a;
    r.error = 0;
    return r;
}


void runTests() {
    result r;
    char s[] = "yammi";
    std::string name;
    std::string& rname = name;
    name = s;

    r = f(rname);
    std::cout << r.s << std::endl;
    std::cout << rname << std::endl;
    r = f(s);
    std::cout << r.s << std::endl;
    std::cout << s << std::endl;
    r = f(name);
    std::cout << r.s << std::endl;
    std::cout << name << std::endl;
}

void readThis() {
    const int BUFSIZE = 512;
    char lineBuffer[BUFSIZE];
    std::string line;
    std::ifstream thisFile;

    thisFile.open("stringAndCharPointer.cpp");
    do {
        thisFile.getline(lineBuffer, BUFSIZE);
        line = lineBuffer;
        std::cout << line;
    } while (thisFile.gcount() > 0);
    thisFile.close();
}

int main() {
    readThis();
    runTests();
}

