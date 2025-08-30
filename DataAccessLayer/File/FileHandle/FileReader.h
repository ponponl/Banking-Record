#ifndef FILEREADER_H
#define FILEREADER_H
#include <fstream>
#include <string>
#include <vector>
using std::ifstream, std::string, std::vector, std::runtime_error, std::ios;

class FileReader{
    private:
        ifstream _reader;
    public:  
        FileReader(string);
        ~FileReader();
        vector<string> getAllLines();
};

#endif