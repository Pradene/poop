#ifndef UTILS_HPP
#define UTILS_HPP

template <typename T> T clamp(T value, T min, T max) {
  if (value < min) {
    return min;
  } else if (value > max) {
    return max;
  } else {
    return value;
  }
}

#endif // UTILS_HPP
