#ifndef FILE_WRITER
#define FILE_WRITER

#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
using std::string, std::vector, std::ofstream, std::runtime_error;

class FileWriter {
    private:
        ofstream _writer;
    public:
        FileWriter(const string& filePath);
        ~FileWriter();
    public:
        void writeLine(const string& line);
        void writeLines(const vector<string>& lines);
};

#endif
