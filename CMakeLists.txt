# Root CMakeLists.txt

cmake_minimum_required(VERSION 3.14)
project(BankingCore)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Thu thập source files
set(BUSINESS_ENTITY
    ${CMAKE_SOURCE_DIR}/BusinessLayer/BusinessEntity/Account.cpp
    ${CMAKE_SOURCE_DIR}/BusinessLayer//BusinessEntity/CardAccount.cpp
    ${CMAKE_SOURCE_DIR}/BusinessLayer//BusinessEntity/RegularAccount.cpp
    ${CMAKE_SOURCE_DIR}/BusinessLayer//BusinessEntity/User.cpp
    ${CMAKE_SOURCE_DIR}/BusinessLayer//BusinessEntity/VipAccount.cpp
)

set(BUSINESS_LAYER
    ${CMAKE_SOURCE_DIR}/BusinessLayer/AccountFactory.cpp
    ${CMAKE_SOURCE_DIR}/BusinessLayer/Service/AccountService.cpp
    ${CMAKE_SOURCE_DIR}/BusinessLayer/Service/CardAccountAdapter.cpp
    ${CMAKE_SOURCE_DIR}/BusinessLayer/Service/UserService.cpp
)

set(DATA_LAYER
    ${CMAKE_SOURCE_DIR}/DataAccessLayer/DAOEntity/AccountRecord.cpp
    ${CMAKE_SOURCE_DIR}/DataAccessLayer/DAOEntity/UserDAO.cpp
    ${CMAKE_SOURCE_DIR}/DataAccessLayer/File/FileHandle/FileReader.cpp
    ${CMAKE_SOURCE_DIR}/DataAccessLayer/File/FileHandle/FileWriter.cpp
    ${CMAKE_SOURCE_DIR}/DataAccessLayer/File/Parser/AccountParser.cpp
    ${CMAKE_SOURCE_DIR}/DataAccessLayer/File/Parser/UserParser.cpp
    ${CMAKE_SOURCE_DIR}/DataAccessLayer/Repository/AccountRepo.cpp
    ${CMAKE_SOURCE_DIR}/DataAccessLayer/Repository/UserRepo.cpp
)

set(UTILS
    ${CMAKE_SOURCE_DIR}/Utils/BalanceFormatter.cpp
)

# Gom tất cả lại thành library
add_library(BankingCore_lib
    ${BUSINESS_ENTITY}
    ${BUSINESS_LAYER}
    ${DATA_LAYER}
    ${UTILS}
)

target_include_directories(BankingCore_lib PUBLIC
    ${CMAKE_SOURCE_DIR}
)

add_subdirectory(tests)
