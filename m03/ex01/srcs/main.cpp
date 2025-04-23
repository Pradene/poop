#include "PackageReductionDiscountCommand.hpp"
#include "TuesdayDiscountCommand.hpp"
#include <iostream>

int main() {
  Command c1(0);
  Command c2(0);
  PackageReductionDiscountCommand c3(0);
  TuesdayDiscountCommand c4(1);

  c1.addArticle(new Article("tomates", 3.5f));
  c3.addArticle(new Article("snickers", 200.0f));
  c4.addArticle(new Article("snickers", 2.2f));
  std::cout << c1.getClientId() << ": " << c1.getPrice() << std::endl;
  std::cout << c2.getClientId() << ": " << c2.getPrice() << std::endl;
  std::cout << c3.getClientId() << ": " << c3.getPrice() << std::endl;
  std::cout << c4.getClientId() << ": " << c4.getPrice() << std::endl;

  return 0;
}
