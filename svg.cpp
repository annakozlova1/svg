#include "svg.hpp"
#include <cmath>
#include <istream>
#include <ostream>

void Circle::Print(std::ostream& out) const {
    out << "\n<circle cx=\"";
    get_center_x(out);
    out << "\" cy=\"";
    get_center_y(out);
    out << "\" r=\"";
    get_radius(out);
    out << "\" fill=\"";
    get_fillColor(out);
    out << "\" stroke=\"";
    get_strokeColor(out);
    out << "\" stroke-width=\"";
    get_strokeWidth(out);
    out << "\" />";
    out << "\n";
}

void Polyline::Print(std::ostream& out) const {
    out << "\n<polyline points=\"";
    get_points(out);
    out << "\" fill=\"";
    get_fillColor(out);
    out << "\" stroke=\"";
    get_strokeColor(out);
    out << "\" stroke-width=\"";
    get_strokeWidth(out);
    out << "\" />";
    out << "\n";
}


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
    return os << "(" << color.R() << "," << color.G() << "," << color.B()
              << ")";
}

std::istream &operator>>(std::istream &in, Color &color)
{
    in >> color.R() >> color.G() >> color.B();
    return in;
}

