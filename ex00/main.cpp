#include <iostream>
#include <map>
#include <ostream>

struct Bank {
  struct Account {
  private:
    float _value;

  public:
    Account() : _value(0.0) {}

    float &getValue() { return _value; }

    friend class Bank;
  };

  class AccountNotFoundException {
  public:
    const char *what() const { return "Client doesn't exist"; }
  };
  class DepositNegativeAmount {
  public:
    const char *what() const { return "Amount negative"; }
  };
  class LiquidityNotSufficient {
  public:
    const char *what() const { return "Liquidity not sufficient"; }
  };
  class WithdrawTooMuchMoney {
  public:
    const char *what() const { return "Withdraw too much money"; }
  };

private:
  int _nextId;
  int _liquidity;
  std::map<int, Account *> _clientAccounts;

public:
  Bank() : _nextId(0), _liquidity(0) {}

  ~Bank() {
    std::map<int, Account *>::iterator it = _clientAccounts.begin();
    while (it != _clientAccounts.end()) {
      delete it->second;
      it++;
    }
    _clientAccounts.clear();
  }

  void createAccount() {
    _clientAccounts.insert(std::make_pair(_nextId++, new Account()));
  }

  void deleteAccount(int id) {
    try {
      std::map<int, Account *>::iterator it = _clientAccounts.find(id);
      if (it == _clientAccounts.end()) {
        throw AccountNotFoundException();
      }
      delete it->second;
      _clientAccounts.erase(it);
    } catch (const AccountNotFoundException &e) {
      std::cerr << e.what() << std::endl;
    }
  }

  void depositToAccount(int id, float amount) {
    try {
      if (amount < 0.0) {
        throw DepositNegativeAmount();
      }
      std::map<int, Account *>::iterator it = _clientAccounts.find(id);
      if (it == _clientAccounts.end()) {
        throw AccountNotFoundException();
      }
      float taxes = amount * 0.05;
      amount -= taxes;
      _liquidity += taxes;
      it->second->getValue() += amount;
    } catch (const AccountNotFoundException &e) {
      std::cerr << e.what() << std::endl;
    } catch (const DepositNegativeAmount &e) {
      std::cerr << e.what() << std::endl;
    }
  }

  void withdrawFromAccount(int id, float amount) {
    try {
      std::map<int, Account *>::iterator it = _clientAccounts.find(id);
      if (it == _clientAccounts.end()) {
        throw AccountNotFoundException();
      }
      if (it->second->getValue() - amount < 0.0) {
        throw WithdrawTooMuchMoney();
      } else {
        it->second->getValue() -= amount;
      }
    } catch (const AccountNotFoundException &e) {
      std::cerr << e.what() << std::endl;
    } catch (const WithdrawTooMuchMoney &e) {
      std::cerr << e.what() << std::endl;
    }
  }

  void giveLoanToAccount(int id, int amount) {
    try {
      if (_liquidity < amount) {
        throw LiquidityNotSufficient();
      }
      std::map<int, Account *>::iterator it = _clientAccounts.find(id);
      if (it == _clientAccounts.end()) {
        throw AccountNotFoundException();
      }
      _liquidity -= amount;
      it->second->getValue() += amount;
    } catch (const LiquidityNotSufficient &e) {
      std::cerr << e.what() << std::endl;
    } catch (const AccountNotFoundException &e) {
      std::cerr << e.what() << std::endl;
    }
  }
};

int main() {
  Bank bank = Bank();
  return (0);
}
