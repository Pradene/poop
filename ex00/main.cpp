#include <exception>
#include <iostream>
#include <map>

struct Bank {
  struct Account {
  private:
    float _value;

  public:
    Account() : _value(0.0f) {}
    float getValue() const { return _value; }

    friend struct Bank;
  };

  class AccountNotFoundException : public std::exception {
  public:
    const char *what() const throw() { return "Client doesn't exist"; }
  };
  class DepositNegativeAmount : public std::exception {
  public:
    const char *what() const throw() { return "Amount negative"; }
  };
  class LiquidityNotSufficient : public std::exception {
  public:
    const char *what() const throw() { return "Liquidity not sufficient"; }
  };
  class WithdrawTooMuchMoney : public std::exception {
  public:
    const char *what() const throw() { return "Withdraw too much money"; }
  };

private:
  size_t _nextId;
  float _liquidity;
  std::map<size_t, Account *> _clientAccounts;

  void modifyAccount(size_t id, float amount) {
    std::map<size_t, Account *>::iterator it = _clientAccounts.find(id);
    if (it == _clientAccounts.end()) {
      throw AccountNotFoundException();
    }
    it->second->_value += amount;
  }

public:
  Bank() : _nextId(0), _liquidity(0.0f) {}

  ~Bank() {
    std::map<size_t, Account *>::iterator it = _clientAccounts.begin();
    while (it != _clientAccounts.end()) {
      delete it->second;
      it++;
    }
    _clientAccounts.clear();
  }

  void createAccount() {
    _clientAccounts.insert(std::make_pair(_nextId++, new Account()));
  }

  void deleteAccount(size_t id) {
    std::map<size_t, Account *>::iterator it = _clientAccounts.find(id);
    if (it == _clientAccounts.end()) {
      throw AccountNotFoundException();
    }
    delete it->second;
    _clientAccounts.erase(it);
  }

  void depositToAccount(size_t id, float amount) {
    if (amount < 0.0f) {
      throw DepositNegativeAmount();
    }
    float taxes = amount * 0.05f;
    _liquidity += taxes;
    modifyAccount(id, amount - taxes);
  }

  void withdrawFromAccount(size_t id, float amount) {
    std::map<size_t, Account *>::iterator it = _clientAccounts.find(id);
    if (it == _clientAccounts.end()) {
      throw AccountNotFoundException();
    }
    if (it->second->getValue() < amount) {
      throw WithdrawTooMuchMoney();
    }
    modifyAccount(id, -amount);
  }

  void giveLoanToAccount(size_t id, int amount) {
    if (_liquidity < amount) {
      throw LiquidityNotSufficient();
    }
    _liquidity -= amount;
    modifyAccount(id, amount);
  }

  const Account &operator[](size_t id) const {
    std::map<size_t, Account *>::const_iterator it = _clientAccounts.find(id);
    if (it == _clientAccounts.end()) {
      throw AccountNotFoundException();
    }
    return *(it->second);
  }
};

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
    std::cout << "Account 0 balance: " << bank[0].getValue() << std::endl;
    std::cout << "Account 2 balance: " << bank[2].getValue() << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown error occurred!" << std::endl;
  }

  return 0;
}
