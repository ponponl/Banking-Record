#include "FileWriter.h"


FileWriter::FileWriter(const string& filePath, bool append) {
    if (append)
        _writer.open(filePath, std::ios::app);
    else
        _writer.open(filePath, std::ios::out | std::ios::trunc);
    if (!_writer.is_open()) {
        throw runtime_error("Unable to open file for writing: " + filePath);
    }
}

FileWriter::~FileWriter() {
    if (_writer.is_open()) {
        _writer.close();
    }
}

void FileWriter::writeLine(const string& line) {
    if (_writer.is_open()) {
        _writer << line << "\n" ;
    }
}

void FileWriter::writeLines(const vector<string>& lines, const string& filePath) {
    std::ofstream writer(filePath, std::ios::out | std::ios::trunc);
    if (!writer.is_open()) {
        throw std::runtime_error("Unable to open file for writing: " + filePath);
    }
    for (const auto& line : lines) {
        writer << line << "\n";
    }
    writer.close();
}
