#include "../BusinessLayer/BusinessEntity/Account.h"
#include "../BusinessLayer/BusinessEntity/RegularAccount.h"
#include "../BusinessLayer/BusinessEntity/VipAccount.h"
#include "../BusinessLayer/BusinessEntity/CardAccount.h"
#include "../BusinessLayer/BusinessEntity/User.h"
#include "../BusinessLayer/Service/AccountService.h"
#include "../BusinessLayer/Service/UserService.h"
#include "../DataAccessLayer/Repository/UserRepo.h"
#include "../BusinessLayer/AccountFactory.h"
#include <gtest/gtest.h>
#include <iostream>

TEST(BusinessLayerTest, RegularAccountFactory) {
	AccountRecord regRec("2", "200", "1500", "regular");
	auto regPtr = AccountFactory::createFrom(regRec);
	ASSERT_NE(regPtr, nullptr);
	EXPECT_EQ(regPtr->getID(), 2);
	EXPECT_EQ(regPtr->getUserId(), 200);
	regPtr->setBalance(1600);
	EXPECT_EQ(regPtr->getBalance(), 1600);
}

TEST(BusinessLayerTest, VipAccountFactory) {
	AccountRecord vipRec("3", "300", "5000", "vip");
	auto vipPtr = AccountFactory::createFrom(vipRec);
	ASSERT_NE(vipPtr, nullptr);
	EXPECT_EQ(vipPtr->getID(), 3);
	EXPECT_EQ(vipPtr->getUserId(), 300);
	vipPtr->setBalance(6000);
	EXPECT_EQ(vipPtr->getBalance(), 6000);
}

TEST(BusinessLayerTest, CardAccountFactory) {
	AccountRecord cardRec("4", "400", "card", "1234567890123456", "12/30", "123", "10000");
	auto cardPtr = AccountFactory::createFrom(cardRec);
	ASSERT_NE(cardPtr, nullptr);
	EXPECT_EQ(cardPtr->getID(), 4);
	EXPECT_EQ(cardPtr->getUserId(), 400);
	auto* cardAdapter = dynamic_cast<CardAccountAdapter*>(cardPtr.get());
	ASSERT_NE(cardAdapter, nullptr);
	EXPECT_EQ(cardAdapter->getCardAccount().getCardNumber(), "1234567890123456");
	EXPECT_EQ(cardAdapter->getCardAccount().getExpirationDate(), "12/30");
	EXPECT_EQ(cardAdapter->getCardAccount().getCvv(), "123");
	EXPECT_EQ(cardAdapter->getCardAccount().getAvailableFunds(), 10000);
	EXPECT_EQ(cardAdapter->getCardAccount().getUserId(), 400);
}

TEST(BusinessLayerTest, UserEntity) {
	User user(5, "user1", "0123456789");
	EXPECT_EQ(user.getId(), 5);
	EXPECT_EQ(user.getName(), "user1");
	user.setPhoneNumber("0999999999");
	EXPECT_EQ(user.getPhoneNumber(), "0999999999");
	user.setName("user2");
	EXPECT_EQ(user.getName(), "user2");
	user.setId(6);
	EXPECT_EQ(user.getId(), 6);
}

TEST(BusinessLayerTest, CardAccountAdapter) {
	AccountRecord cardRec2("7", "700", "card", "6543210987654321", "11/29", "321", "5000");
	auto cardPtr2 = AccountFactory::createFrom(cardRec2);
	auto* cardAdapter2 = dynamic_cast<CardAccountAdapter*>(cardPtr2.get());
	ASSERT_NE(cardAdapter2, nullptr);
	EXPECT_EQ(cardAdapter2->getCardAccount().getCardNumber(), "6543210987654321");
	EXPECT_EQ(cardAdapter2->getCardAccount().getExpirationDate(), "11/29");
	EXPECT_EQ(cardAdapter2->getCardAccount().getCvv(), "321");
	EXPECT_EQ(cardAdapter2->getCardAccount().getAvailableFunds(), 5000);
	EXPECT_EQ(cardAdapter2->getCardAccount().getUserId(), 700);
}

TEST(BusinessLayerTest, AccountServiceCRUD) {
	AccountRecord regRec2("6", "600", "1200", "regular");
	auto regPtr2 = AccountFactory::createFrom(regRec2);
	ASSERT_NE(regPtr2, nullptr);
	std::string repoFile = "test_accountrepo_business.txt";
	std::shared_ptr<AccountRepository> repo = std::make_shared<AccountRepository>(repoFile);
	std::shared_ptr<IUserRepo> userRepo = nullptr;
	AccountService service(repo, userRepo);
	service.addAccount(std::move(regPtr2));
	auto all = service.getAllAccounts();
	EXPECT_FALSE(all.empty());
	auto foundAcc = service.searchById(6);
	EXPECT_TRUE(foundAcc.has_value());
	foundAcc.value()->setBalance(1300);
	EXPECT_TRUE(service.editAccount(*foundAcc.value()));
	auto foundAccEdit = service.searchById(6);
	EXPECT_TRUE(foundAccEdit.has_value());
	EXPECT_EQ(foundAccEdit.value()->getBalance(), 1300);
	EXPECT_TRUE(service.deleteAccount(6));
	auto foundAccDel = service.searchById(6);
	EXPECT_FALSE(foundAccDel.has_value());
	std::remove(repoFile.c_str());
}

TEST(BusinessLayerTest, UserServiceCRUD) {
	std::string userRepoFile = "test_userrepo_business.txt";
	std::shared_ptr<IUserRepo> userRepoObj = std::make_shared<UserRepo>(userRepoFile);
	UserService userService(userRepoObj);
	User user1(10, "userA", "0123456788");
	EXPECT_TRUE(userService.addUser(user1));
	auto allUsers = userService.getAllUsers();
	EXPECT_FALSE(allUsers.empty());
	int foundIdUser = -1;
	for (const auto& u : allUsers) {
		if (u.getName() == "userA") foundIdUser = u.getId();
	}
	EXPECT_EQ(foundIdUser, 10);
	User userEdit(10, "userB", "0123456788");
	EXPECT_TRUE(userService.updateUser(userEdit));
	auto allUsersEdit = userService.getAllUsers();
	bool foundEditUser = false;
	for (const auto& u : allUsersEdit) {
		if (u.getName() == "userB") foundEditUser = true;
	}
	EXPECT_TRUE(foundEditUser);
	EXPECT_TRUE(userService.deleteUser("10"));
	auto allUsersDel = userService.getAllUsers();
	bool foundDelUser = false;
	for (const auto& u : allUsersDel) {
		if (u.getId() == 10) foundDelUser = true;
	}
	EXPECT_FALSE(foundDelUser);
	std::remove(userRepoFile.c_str());
}