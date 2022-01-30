#include "Point.hpp"

int main( void ) {
  Point a1(4, 0), b1(4, 2), c1(0, 0), p1(4, 1);
  Point a2(0, 0), b2(0, 4), c2(4, 0), p2(0, 0);
  Point a3(0, 0), b3(0, 4), c3(4, 0), p3(1, 1);
  Point a4(0, 0), b4(0, 4), c4(4, 0), p4(2, 2);
  Point a5(0, 0), b5(0, 4), c5(4, 0), p5(2, 1.923323);

  std::cout << "p1(4, 1) - " << bsp(a1, b1, c1, p1) << std::endl;
  std::cout << "p2(0, 0) - " << bsp(a2, b2, c2, p2) << std::endl;
  std::cout << "p3(1, 1) - " << bsp(a3, b3, c3, p3) << std::endl;
  std::cout << "p4(2, 2) - " << bsp(a4, b4, c4, p4) << std::endl;
  std::cout << "p5(2, 1.923323) - " << bsp(a5, b5, c5, p5) << std::endl;

  return 0;
}
