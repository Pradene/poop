#ifndef PACKAGEREDUCTIONDISCOUNTCOMMAND_HPP
#define PACKAGEREDUCTIONDISCOUNTCOMMAND_HPP

#include "Command.hpp"

class PackageReductionDiscountCommand : public Command {
private:
  PackageReductionDiscountCommand();

public:
  PackageReductionDiscountCommand(size_t clientId) : Command(clientId) {}

  virtual float getPrice() const {
    float price = 0;
    std::vector<Article *>::const_iterator it = _articles.begin();
    while (it != _articles.end()) {
      price += (*it)->getPrice();
      ++it;
    }
    return (price >= 150.0f) ? price - 10 : price;
  }
};


#endif // PACKAGEREDUCTIONDISCOUNTCOMMAND_HPP
