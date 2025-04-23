#ifndef TOOL_HPP
#define TOOL_HPP

#include <cstddef>

class Tool {
protected:
  size_t _numberOfUses;

public:
  Tool();
  virtual ~Tool();
  virtual void use() = 0;
};

class Shovel : public Tool {
public:
  Shovel();
  ~Shovel();

  void use();
};

class Hammer : public Tool {
public:
  Hammer();
  ~Hammer();

  void use();
};

#endif // TOOL_HPP
