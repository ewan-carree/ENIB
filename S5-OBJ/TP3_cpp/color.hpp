#ifndef COLOR_HPP
#define COLOR_HPP
#include <stdexcept>
#include <iostream>

namespace tp3 {

using uchar = unsigned char;

struct Color {
  uchar red, green, blue;

  Color(uchar r, uchar g, uchar b) : red{r},
                                     green{g},
                                     blue{b}{}
  Color() : Color(0,0,0) {}   // constructeur par délégation  
 
  uchar operator[](int i) const {
    if(i==0) return red;
    else if(i==1) return green;
    else if(i==2) return blue;
    else throw std::out_of_range{"index out of range"};
  }
  
    uchar& operator[](int i) {
    if(i==0) return red;
    else if(i==1) return green;
    else if(i==2) return blue;
    else throw std::out_of_range{"index out of range"};
  }

};

inline
std::ostream& operator<<(std::ostream& os, Color c) {
  return os << (int)c[0] << ' ' << (int)c[1] << ' ' << (int)c[2];
}

inline
Color grey(Color c) {
  uchar g = uchar(((int)c[0] + c[1] + c[2])/3);
  return Color{g,g,g};
}

} // namespace s5loo

#endif





