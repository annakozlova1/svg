#include "svg.hpp"
#include <cmath>
#include <istream>
#include <ostream>

/*void Color::Print(std::ostream& out) const {
    out << color;
}*/

/*void Circle::Print() const override {
    std::fin<<"<circle "<<"cx="<<center.X()<<" cy="<<center.Y()<<" r="<<radius<<
    " fill="<<fillColor.Print()<<" stroke="<<strokeColor.Print()<<
    " stroke-width="<<strokeWidth<<" />"<<std::endl; 
  //  <circle cx="200" cy="200" r="30" fill="red" stroke="none" stroke-width="1" />
}*/


std::ostream &operator<<(std::ostream &os, const Point &point)
{
    return os << "point = (" << point.X() << "," << point.Y() << ")";
}

std::istream &operator>>(std::istream &in, Point &point)
{
    in >> point.X() >> point.Y();
    return in;
}


std::ostream &operator<<(std::ostream &os, const Color &color)
{
    return os << "color = (" << color.R() << "," << color.G() << "," << color.B()
              << ")";
}

std::istream &operator>>(std::istream &in, Color &color)
{
    in >> color.R() >> color.G() >> color.B();
    return in;
}