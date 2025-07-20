#include "FileWriter.h"
#include <fstream>
#include <vector>
#include <string>

void FileWriter::writeLines(const std::string& filePath, const std::vector<std::string>& lines) {
    std::ofstream out(filePath);
    for (const auto& line : lines) {
        out << line << "\n";
    }
    out.close();
}
