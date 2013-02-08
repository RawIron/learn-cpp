#include <string>
#include <iostream>
#include <fstream>


void readScan(std::ifstream& thisFile) {
    char* line;
    int size;
    thisFile.seekg(0, std::ios::end);
    size = thisFile.tellg();
    thisFile.seekg(0, std::ios::beg);
    line = new char[size];
    thisFile.read(line, size);
    std::cout << line;
    delete [] line;
}

void readLinesC(std::ifstream& thisFile) {
    const int BUFSIZE = 512;
    char lineBuffer[BUFSIZE];
    char* line;
    do {
        thisFile.getline(lineBuffer, BUFSIZE);
        line = lineBuffer;
        std::cout << line;
    } while (thisFile.gcount() > 0);
}

void readLines(std::ifstream& thisFile) {
    std::string line;
    do {
        std::getline(thisFile, line);
        std::cout << line;
    } while (thisFile.good());
    //} while ((thisFile.rdstate() & std::ifstream::eofbit) == 0);
}

void readThis(void f(std::ifstream&)) {
    const char* thisFileName = "fileIo.cpp";
    std::ifstream thisFile;

    thisFile.open(thisFileName);
    f(thisFile);
    thisFile.close();
}


int main() {
    readThis(readLinesC);
    readThis(readLines);
    readThis(readScan);
}

