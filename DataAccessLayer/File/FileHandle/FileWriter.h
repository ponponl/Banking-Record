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
        FileWriter(const string& filePath, bool append = true);
        ~FileWriter();
    public:
    void writeLine(const string& line);
    static void writeLines(const vector<string>& lines, const string& filePath);
};

#endif
