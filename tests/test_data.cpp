#include "../DataAccessLayer/Repository/AccountRepo.h"
#include "../DataAccessLayer/DAOEntity/AccountRecord.h"
#include "../DataAccessLayer/DAOEntity/UserDAO.h"
#include "../DataAccessLayer/Repository/UserRepo.h"
#include "../DataAccessLayer/File/FileHandle/FileReader.h"
#include "../DataAccessLayer/File/FileHandle/FileWriter.h"
#include "../DataAccessLayer/File/Parser/AccountParser.h"
#include "../DataAccessLayer/File/Parser/UserParser.h"
#include <gtest/gtest.h>
#include <iostream>

TEST(DataAccessLayerTest, AccountRecord) {
	AccountRecord rec("1", "101", "1000", "regular");
	EXPECT_EQ(rec.getID(), "1");
	EXPECT_EQ(rec.getUserId(), "101");
	EXPECT_EQ(rec.getBalance(), "1000");
	EXPECT_EQ(rec.getType(), "regular");
	rec.setCardNumber("1234567890123456");
	EXPECT_EQ(rec.getCardNumber(), "1234567890123456");
}

TEST(DataAccessLayerTest, UserDAO) {
	UserDAO user("u1", "user1", "0123456789");
	EXPECT_EQ(user.getId(), "u1");
	EXPECT_EQ(user.getName(), "user1");
	EXPECT_EQ(user.getPhoneNumber(), "0123456789");
	user.setName("user2");
	EXPECT_EQ(user.getName(), "user2");
}

TEST(DataAccessLayerTest, FileReaderWriter) {
	std::string testFile = "test_file.txt";
	FileWriter writer(testFile, false);
	writer.writeLine("hello world");
	FileReader reader(testFile);
	std::vector<std::string> lines = reader.getAllLines();
	EXPECT_FALSE(lines.empty());
	EXPECT_EQ(lines[0], "hello world");
	std::remove(testFile.c_str());
}

TEST(DataAccessLayerTest, UserParser) {
	std::string line = "u2,user2,0123456788";
	UserDAO parsed = UserParser::parse(line);
	EXPECT_EQ(parsed.getId(), "u2");
	EXPECT_EQ(parsed.getName(), "user2");
	EXPECT_EQ(parsed.getPhoneNumber(), "0123456788");
}

TEST(DataAccessLayerTest, AccountRepoCRUD) {
	std::string repoFile = "test_accountrepo.txt";
	AccountRepository repo(repoFile);
	AccountRecord rec1("10", "110", "500", "regular");
	EXPECT_TRUE(repo.addAccount(rec1));
	auto all = repo.getAll();
	EXPECT_FALSE(all.empty());
	auto found = repo.findById("10");
	EXPECT_TRUE(found.has_value());
	EXPECT_EQ(found->getUserId(), "110");
	rec1.setBalance("600");
	EXPECT_TRUE(repo.updateAccount(rec1));
	auto found2 = repo.findById("10");
	EXPECT_TRUE(found2.has_value());
	EXPECT_EQ(found2->getBalance(), "600");
	repo.removeAccount("10");
	auto found3 = repo.findById("10");
	EXPECT_FALSE(found3.has_value());
	std::remove(repoFile.c_str());
}

TEST(DataAccessLayerTest, UserRepoCRUD) {
	std::string repoFile = "test_userrepo.txt";
	UserRepo repo(repoFile);
	UserDAO user1("u10", "userA", "0123456799");
	EXPECT_TRUE(repo.addUser(user1));
	auto all = repo.getAll();
	EXPECT_FALSE(all.empty());
	bool found = false;
	for (const auto& u : all) {
		if (u.getId() == "u10" && u.getName() == "userA") found = true;
	}
	EXPECT_TRUE(found);
	user1.setName("userB");
	EXPECT_TRUE(repo.updateUser(user1));
	auto all2 = repo.getAll();
	bool found2 = false;
	for (const auto& u : all2) {
		if (u.getId() == "u10" && u.getName() == "userB") found2 = true;
	}
	EXPECT_TRUE(found2);
	EXPECT_TRUE(repo.deleteUser("u10"));
	auto all3 = repo.getAll();
	bool found3 = false;
	for (const auto& u : all3) {
		if (u.getId() == "u10") found3 = true;
	}
	EXPECT_FALSE(found3);
	std::remove(repoFile.c_str());
}
