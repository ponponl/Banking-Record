#include <string>
#include <vector>
#include <optional>
#include "../File/AccountParser.h"
#include "../DAOEntity/AccountRecord.h"
#include "../../BusinessLayer/BusinessEntity/Account.h"
#include "../File/FileReader.h"
#include "../File/FileWriter.h"
#include <vector>
#include <optional>
using std::vector, std::string;

class AccountRepository {
private:
    std::string filePath;

public:
    explicit AccountRepository(const std::string& filePath);

    std::vector<AccountRecord> getAll();
    std::optional<AccountRecord> findById(int id);
    std::vector<AccountRecord> searchByName(const std::string& name);
    
    void save(const AccountRecord& account);
    void remove(int id);
    void update(const AccountRecord& account);
    
};