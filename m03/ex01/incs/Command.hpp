#ifndef COMMAND_HPP
#define COMMAND_HPP
#include <vector>
#include <string>
#include <ctime>

#include "Article.hpp"

static size_t commandId = 0;

class Command {
protected:
  size_t _id;
  size_t _clientId;
  time_t _date;
  std::vector<Article *> _articles;

public:
  Command(size_t clientId) : _id(commandId++), _clientId(clientId), _date(time(NULL)) {}
  virtual ~Command() {
    std::vector<Article *>::iterator it = _articles.begin();
    for (; it != _articles.end(); ++it) {
      delete (*it);
    }
  }

  virtual float getPrice() const {
    float price = 0;
    std::vector<Article *>::const_iterator it = _articles.begin();
    while (it != _articles.end()) {
      price += (*it)->getPrice();
      ++it;
    }
    return price;
  }

  void addArticle(Article *article) {
    _articles.push_back(article);
  }

  void removeArticle(Article *article) {
    std::vector<Article *>::iterator it = _articles.begin();
    for (; it != _articles.end(); ) {
      if ((*it) == article) {
        delete *it;
        it = _articles.erase(it);
      } else {
        ++it;
      }
    }
  }

  void removeArticle(std::string name) {
    std::vector<Article *>::iterator it = _articles.begin();
    for (; it != _articles.end(); ) {
      if ((*it)->getName() == name) {
        delete *it;
        it = _articles.erase(it);
      } else {
        ++it;
      }
    }
  }

  size_t getClientId() const {
    return _clientId;
  }
};

#endif // COMMAND_HPP
