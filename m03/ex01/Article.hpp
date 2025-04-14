#ifndef ARTICLE_HPP
#define ARTICLE_HPP


class Article {
private:
  std::string _name;
  float _price;

  Article() {}

public:
  Article(std::string name, float price) : _name(name), _price(price) {}
  float getPrice() const {
    return _price;
  }

  std::string getName() const {
    return _name;
  }
};

#endif // ARTICLE_HPP
