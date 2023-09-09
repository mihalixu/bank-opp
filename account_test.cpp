#include "account.hpp"
#include "catch_amalgamated.hpp"

TEST_CASE("Create at least two accounts per type","[create]"){
   bank::Account account_1("Mihael");
   bank::Account account_2("Kristina",100);

   bank::ChildAccount child_account_1("Dragan");
   bank::ChildAccount child_account_2("Branka",1000);

   bank::TransferAccount transfer_account_1("Stipo");
   bank::TransferAccount transfer_account_2("Ana",2000);

   SECTION("Test Account class")
   {
      REQUIRE(account_1.owner() == "Mihael");
      REQUIRE(account_2.owner() == "Kristina");
      CHECK(account_1.balance() == 0);
      CHECK(account_2.balance() == 100);
   }

   SECTION("Test ChildAccount class")
   {
      REQUIRE(child_account_1.owner() == "Dragan");
      REQUIRE(child_account_2.owner() == "Branka");
      CHECK(child_account_1.balance() == 0);
      CHECK(child_account_2.balance() == 1000);
   }

   SECTION("Test TransferAccount class")
   {
      REQUIRE(transfer_account_1.owner() == "Stipo");
      REQUIRE(transfer_account_2.owner() == "Ana");
      CHECK(transfer_account_1.balance() == 0);
      CHECK(transfer_account_2.balance() == 2000);
   }

}

TEST_CASE("perform multiple deposits and withdrawals","[deposit/withdrawals]"){
   bank::Account account_1("Mihael");
   bank::Account account_2("Kristina",100);

   bank::ChildAccount child_account_1("Dragan");
   bank::ChildAccount child_account_2("Branka",1000);

   bank::TransferAccount transfer_account_1("Stipo");
   bank::TransferAccount transfer_account_2("Ana",2000);

   SECTION("Deposit to all types")
   {
      account_1.deposit(100);
      account_2.deposit(100);
      child_account_1.deposit(100);
      child_account_2.deposit(100);
      transfer_account_1.deposit(100);
      transfer_account_2.deposit(100);

      CHECK(account_1.balance() == 100);
      CHECK(account_2.balance() == 200);
      CHECK(child_account_1.balance() == 100);
      CHECK(child_account_2.balance() == 1100);
      CHECK(transfer_account_1.balance() == 100);
      CHECK(transfer_account_2.balance() == 2100);
   }

   SECTION("Withdraw from all accounts")
   {
      account_1.deposit(100);
      child_account_1.deposit(100);
      transfer_account_1.deposit(100);

      account_1.withdraw(50);
      account_2.withdraw(50);
      child_account_1.withdraw(50);
      child_account_2.withdraw(50);
      transfer_account_1.withdraw(50);
      transfer_account_2.withdraw(50);

      CHECK(account_1.balance() == 50);
      CHECK(account_2.balance() == 50);
      CHECK(child_account_1.balance() == 50);
      CHECK(child_account_2.balance() == 950);
      CHECK(transfer_account_1.balance() == 50);
      CHECK(transfer_account_2.balance() == 1950);
   }

}


TEST_CASE("overdraw a child account","[overdraw]"){
    
   bank::ChildAccount child_account("Dragan",100);
   bank::Account* acc = &child_account; 

   SECTION("virtual function without ref")
   {
      REQUIRE(acc->withdraw(1000) == 100);
      CHECK(acc->balance() == 0);
   }

}


TEST_CASE("Transfer money to each account type","[transfer]"){
   bank::Account account_1("Mihael",2000);
   bank::ChildAccount child_account_1("Dragan",200000);
   bank::TransferAccount transfer_account_1("Stipo",10000);
   bank::TransferAccount transfer_account_2("Anna",3000);

   transfer_account_1.transfer(transfer_account_2,5000);
   transfer_account_1.transfer(account_1,2000);
   transfer_account_1.transfer(child_account_1,1000);
   transfer_account_2.transfer(transfer_account_1,5000);

   SECTION("Check balance of each account after transfer")
   {
      CHECK(account_1.balance() == 4000);
      CHECK(child_account_1.balance() == 201000);
      CHECK(transfer_account_1.balance() == 7000);
      CHECK(transfer_account_2.balance() == 3000);
   }

}