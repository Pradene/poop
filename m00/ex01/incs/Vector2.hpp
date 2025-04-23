#ifndef VECTOR2_HPP
#define VECTOR2_HPP

class Vector2 {
private:
  float _x;
  float _y;

public:
  Vector2(float x = 0.0f, float y = 0.0f);

  float getX() const;
  float getY() const;

  int getIntX() const;
  int getIntY() const;
};

#endif
