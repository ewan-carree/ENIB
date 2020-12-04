#include "window.hpp"
#include "color.hpp"
#include <random>

int main(void) {

  tp3::Window win{"Rectangles and Circles", 1550,800};
  auto [width, height] = win.size();

  std::default_random_engine rndGen{std::random_device{}()};
  std::uniform_int_distribution<short> colorDistr{0, 255};
  std::uniform_real_distribution<double> speedDistr{-150, 150};
  std::uniform_real_distribution<double> dimDistr{10, 60};
  std::uniform_real_distribution<double> xposDistr{0, width};
  std::uniform_real_distribution<double> yposDistr{0, height};
  std::uniform_real_distribution<double> angularDistr{-15, 15};

for (int i = 0; i < 10; i++)
{
  win.add(std::make_unique<tp3::Circle>(int(width), int(height), xposDistr(rndGen), yposDistr(rndGen), speedDistr(rndGen), speedDistr(rndGen), dimDistr(rndGen), tp3::Color(tp3::uchar(colorDistr(rndGen)), tp3::uchar(colorDistr(rndGen)), tp3::uchar(colorDistr(rndGen)))));

  win.add(std::make_unique<tp3::Rectangle>(int(width), int(height), xposDistr(rndGen), yposDistr(rndGen), speedDistr(rndGen), speedDistr(rndGen), dimDistr(rndGen), dimDistr(rndGen), tp3::Color(tp3::uchar(colorDistr(rndGen)), tp3::uchar(colorDistr(rndGen)), tp3::uchar(colorDistr(rndGen))), angularDistr(rndGen)));
}

  

  win.display();

  return 0;
}
