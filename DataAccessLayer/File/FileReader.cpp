#include "FileReader.h"

FileReader::FileReader(string input){
    _reader.open(input, std::ios::in);
    if (_reader.fail()){
        throw std::runtime_error("Cannot open file");
    }
}

FileReader::~FileReader(){
    _reader.close();
}

vector<string> FileReader::getAllLines(){
    vector<string> lines;
    while (!_reader.eof()){
        string line;
        getline(_reader, line);
        lines.push_back(line);
    }
    
    return lines;
}