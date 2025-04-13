#include "Bank.hpp"
#include <exception>
#include <iostream>

int main() {
  try {
    Bank bank;
    bank.createAccount();
    bank.depositToAccount(0, 100);
    bank.withdrawFromAccount(0, 150);
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown error occurred!" << std::endl;
  }

  try {
    Bank bank;
    bank.createAccount();
    bank.deleteAccount(1);
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown error occurred!" << std::endl;
  }

  try {
    Bank bank;
    bank.createAccount();
    bank.giveLoanToAccount(0, 100);
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown error occurred!" << std::endl;
  }

  try {
    Bank bank;
    bank.createAccount();
    bank.createAccount();
    bank.deleteAccount(1);
    bank.createAccount();
    bank.depositToAccount(0, 100);
    bank.giveLoanToAccount(2, 5);
    std::cout << "Account 0 balance: " << bank[0].getBalance() << std::endl;
    std::cout << "Account 2 balance: " << bank[2].getBalance() << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown error occurred!" << std::endl;
  }

  return 0;
}
