# Banking-Record

## Project Overview

Banking-Record is a C++23 console application simulating a banking system with support for regular, VIP, and card accounts. It demonstrates a classic 3-layer architecture (Presentation, Business, Data) and applies the MVC (Model-View-Controller) pattern in the Presentation layer. 

### Features
- Create, view, and manage accounts (Regular, VIP, Card)
- Card account support with adapter pattern
- Unique phone validation with error messaging
- File-based persistence (data.txt, card.txt, transaction.txt)
- Layered architecture: Presentation, Business, Data, Mapping, Utils
- Modern C++: smart pointers, std::expected, enum class, RAII
- Testable design with controller and service separation

## Folder Structure

```
PresentationLayer/
   View/           // UI: MenuView, InputView, AccountView
   InputModel/     // User input model: AccountModel
   Controller/     // AccountController
   Validation/     // Input validation logic
BusinessLayer/
   BusinessEntity/ // Account, RegularAccount, VipAccount, CardAccount
   Service/        // AccountService, CardAccountAdapter
   AccountFactory/ // AccountFactory (creation/serialization)
DataAccessLayer/
   DAOEntity/      // AccountRecord (pure data for file)
   Repository/     // AccountRepo, IAccountRepo
   File/
      FileHandle/   // FileReader, FileWriter
      Parser/       // AccountParser, TransactionParser
      Data/         // card.txt, data.txt, transaction.txt
Mapping/
   AccountModelParser, AccountRecordParser
Utils/
   BalanceFormatter, GetTime
main.cpp, App.cpp // Main entry and app logic
README.md         // Documentation
```

## Key Techniques & Patterns

- **Layered Architecture:** Clear separation of UI, business logic, data access, and utility layers.
- **Adapter Pattern:** `CardAccountAdapter` allows card accounts to be handled via the unified `Account` interface.
- **Factory Pattern:** `AccountFactory` creates and serializes all account types.
- **Smart Pointers:** Uses `std::unique_ptr` for memory safety and ownership.
- **Modern C++ Features:**
   - `enum class` for type safety
   - `std::expected` for error handling in validation
- **Validation:**
   - Unique phone number check via service layer
   - Name and balance format validation
   - Error reporting with specific messages
- **File Persistence:**
   - Data stored in text files, parsed and serialized via dedicated classes
- **Testable Design:**
   - Controller and service separation for easy testing and extension

## Build & Run

Compile with:

```sh
g++ -std=c++23 -O -I. App.cpp main.cpp PresentationLayer/Controller/AccountController.cpp PresentationLayer/InputModel/AccountModel.cpp PresentationLayer/InputModel/UserModel.cpp PresentationLayer/Validation/InputValidation.cpp PresentationLayer/View/AccountView.cpp PresentationLayer/View/Inputview.cpp PresentationLayer/View/MenuView.cpp PresentationLayer/View/UserView.cpp BusinessLayer/AccountFactory.cpp BusinessLayer/BusinessEntity/Account.cpp BusinessLayer/BusinessEntity/CardAccount.cpp BusinessLayer/BusinessEntity/RegularAccount.cpp BusinessLayer/BusinessEntity/User.cpp BusinessLayer/BusinessEntity/VipAccount.cpp BusinessLayer/Service/AccountService.cpp BusinessLayer/Service/CardAccountAdapter.cpp BusinessLayer/Service/UserService.cpp DataAccessLayer/DAOEntity/AccountRecord.cpp DataAccessLayer/DAOEntity/UserDAO.cpp DataAccessLayer/File/FileHandle/FileReader.cpp DataAccessLayer/File/FileHandle/FileWriter.cpp DataAccessLayer/File/Parser/AccountParser.cpp DataAccessLayer/File/Parser/UserParser.cpp DataAccessLayer/Repository/AccountRepo.cpp DataAccessLayer/Repository/UserRepo.cpp Utils/BalanceFormatter.cpp -o release/BankingApp.exe
```

Run with:

```
./BankingApp
```
## Usage

Run the app and follow the menu prompts to create, view, and manage accounts. Card accounts require card number, holder name, expiration date, CVV, and initial balance.

## Contribution & Workflow

- Use feature branches for each new feature or bugfix
- Follow clear commit message conventions (ADD, UPDATE, FIX, etc.)
- See below for branch and commit guidelines

### Branch Naming
`name/feature/<feature>`, `name/fix/<bug>`, ...

### Commit Message Prefixes
| Prefix    | Meaning                       |
|-----------|-------------------------------|
| ADD:      | Add new file/feature          |
| UPDATE:   | Update logic/data/structure   |
| FIX:      | Fix bug                      |
| REMOVE:   | Remove file/code              |
| STYLE:    | Code formatting/style         |
| REFACTOR: | Refactor code structure       |
| DOC:      | Update docs/comments          |

