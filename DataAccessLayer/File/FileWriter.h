
#pragma once
#include <string>
#include <vector>

class FileWriter {
public:
    static void writeLines(const std::string& filePath, const std::vector<std::string>& lines);
};
