#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <vector>
#include <tuple>
#include "SFML/Graphics.hpp"

#include "circle.hpp"
#include "Rectangle.hpp"
#include "shape.hpp"

namespace tp3 {

class Window {
  public :
  Window(std::string n="Window", double w=700, double h=500);
    
  /* Special functions */
  //disable copy
  Window(const Window&) = delete;
  Window& operator=(const Window&) = delete;

  //default move is suitable
  Window(Window&&) = default;
  Window& operator=(Window&&) = default;

  //default destruction is suitable
  virtual ~Window() = default;
  /**/

  std::tuple<double,double> size() const;

  void display(void);

  //void add(Circle c) {circles_.push_back(std::move(c));}
  //void add(Rectangle r) {rectangles_.push_back(std::move(r));}

  //void drawAll();
  //void moveAll(double width, double height, double dt);

  private :
  std::string name_;
  double width_, height_;
  sf::RenderWindow win_;
  std::vector<Circle> circles_;
  std::vector<Rectangle> rectangles_;
};  // class Window

/* inline member functions */

inline
std::tuple<double,double> Window::size() const { return {width_, height_}; }

/* non member functions declaration */

double // seconds since 1970/01/01 00:00:00 UTC (avec des décimales allant jusqu'aux microsecondes)
getTime();


}  // namespace s5loo

#endif
