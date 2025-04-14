#ifndef TUESDAYDISCOUNTCOMMAND_HPP
#define TUESDAYDISCOUNTCOMMAND_HPP

#include "Command.hpp"

class TuesdayDiscountCommand : public Command {
private:
  TuesdayDiscountCommand();

public:
  TuesdayDiscountCommand(size_t clientId) : Command(clientId) {}

  bool isTueday() const {
    // tm* timeinfo = localtime(&_date);
    // return (timeinfo->tm_wday == 2);
    return true;
  }

  virtual float getPrice() const {
    float price = 0;
    float discount = (isTueday()) ? 10.0f : 0.0f;
    std::vector<Article *>::const_iterator it = _articles.begin();
    while (it != _articles.end()) {
      price += (*it)->getPrice() * (100.0f - discount) / 100.0f;
      ++it;
    }
    return price;
  }
};

#endif // TUESDAYDISCOUNTCOMMAND_HPP
