#include <string>
using std::string;

class Transaction {
    private:
        int accountId;
        string type; 
        long long amount;
        string timestamp;
    public:
        Transaction();
        Transaction(int accountId, const string& type, long long amount, const string& timestamp);
    public:
        int getAccountId() const;
        string getType() const;
        long long getAmount() const;
        string getTimestamp() const;
    public:
        void setAccountId(int id);
        void setType(const string& t);
        void setAmount(long long a);
        void setTimestamp(const string& ts);
};
