#include <fstream>
#include <string>
#include <vector>
using std::ifstream, std::string, std::vector;

class FileReader{
    private:
        ifstream _reader;
    public:  
        FileReader(string);
        ~FileReader();
        vector<string> getAllLines();
};