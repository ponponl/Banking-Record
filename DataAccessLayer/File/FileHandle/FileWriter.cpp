#include "FileWriter.h"

FileWriter::FileWriter(const string& filePath) {
    _writer.open(filePath);
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
        _writer << line << "\n";
    }
}

void FileWriter::writeLines(const vector<string>& lines) {
    for (const auto& line : lines) {
        writeLine(line);
    }
}
