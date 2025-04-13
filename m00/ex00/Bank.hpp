#ifndef BANK_HPP
#define BANK_HPP

#include <cstddef>
#include <exception>
#include <map>

struct Bank {
  struct Account {
  private:
    float _balance;

  public:
    Account() : _balance(0.0f) {}
    float getBalance() const { return _balance; }

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

  Account *getAccount(size_t id) {
    std::map<size_t, Account *>::iterator it = _clientAccounts.find(id);
    if (it == _clientAccounts.end()) {
      throw AccountNotFoundException();
    }
    return it->second;
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
    Account *account = Bank::getAccount(id);
    float taxes = amount * 0.05f;
    _liquidity += taxes;
    account->_balance += amount - taxes;
  }

  void withdrawFromAccount(size_t id, float amount) {
    Account *account = Bank::getAccount(id);
    if (account->_balance < amount) {
      throw WithdrawTooMuchMoney();
    }
    account->_balance -= amount;
  }

  void giveLoanToAccount(size_t id, int amount) {
    if (_liquidity < amount) {
      throw LiquidityNotSufficient();
    }
    Account *account = Bank::getAccount(id);
    _liquidity -= amount;
    account->_balance += amount;
  }

  const Account &operator[](size_t id) const {
    std::map<size_t, Account *>::const_iterator it = _clientAccounts.find(id);
    if (it == _clientAccounts.end()) {
      throw AccountNotFoundException();
    }
    return *(it->second);
  }
};

#endif
