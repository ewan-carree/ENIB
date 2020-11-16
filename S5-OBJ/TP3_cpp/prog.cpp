#include "window.hpp"
#include "circle.hpp"
#include "color.hpp"
#include <random>

int main(void) {
  tp3::Window win{"Rectangles and Circles", 800,600};
  auto [width, height] = win.size();

  std::default_random_engine rndGen{std::random_device{}()};
  std::uniform_int_distribution<short> colorDistr{0, 255};
  std::uniform_real_distribution<double> speedDistr{-50, 50};
  std::uniform_real_distribution<double> dimDistr{10, 60};
  std::uniform_real_distribution<double> xposDistr{0, width};
  std::uniform_real_distribution<double> yposDistr{0, height};
  std::uniform_real_distribution<double> angularDistr{-15, 15};

  //win.display();

  tp3::Circle c1{int(width), int(height), xposDistr(rndGen), yposDistr(rndGen), speedDistr(rndGen), speedDistr(rndGen), dimDistr(rndGen), tp3::Color(tp3::uchar(colorDistr(rndGen)), tp3::uchar(colorDistr(rndGen)), tp3::uchar(colorDistr(rndGen)))}, 
  
  c2{int(width), int(height), xposDistr(rndGen), yposDistr(rndGen), speedDistr(rndGen), speedDistr(rndGen), dimDistr(rndGen), tp3::Color(tp3::uchar(colorDistr(rndGen)), tp3::uchar(colorDistr(rndGen)), tp3::uchar(colorDistr(rndGen)))}, 
  
  c3{int(width), int(height), xposDistr(rndGen), yposDistr(rndGen), speedDistr(rndGen), speedDistr(rndGen), dimDistr(rndGen), tp3::Color(tp3::uchar(colorDistr(rndGen)), tp3::uchar(colorDistr(rndGen)), tp3::uchar(colorDistr(rndGen)))};

  win.add(std::move(c1));
  win.add(std::move(c2));
  win.add(std::move(c3));

  win.display();

  return 0;
}
