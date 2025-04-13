#include "Tool.hpp"
#include <iostream>

Tool::Tool() : _numberOfUses(0) {}
Tool::~Tool() {}

Shovel::Shovel() {}
Shovel::~Shovel() {}

void Shovel::use() {
  _numberOfUses += 1;
  std::cout << "Use shovel" << std::endl;
}

Hammer::Hammer() {}
Hammer::~Hammer() {}

void Hammer::use() {
  _numberOfUses += 1;
  std::cout << "Use hammer" << std::endl;
}
