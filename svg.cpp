#include "svg.hpp"
#include <cmath>
#include <istream>
#include <iostream>
#include <ostream>


const double& Circle::get_center_x(std::ostream& out) const {
        out << center.x;
        return center.x;
    }
const double& Circle::get_center_y(std::ostream& out) const {
        out << center.y;
        return center.y;
    }
Point& Circle::give_center() {
        std::cout << "введите центр";
        std::cout << "\n";
        std::cin >> center;
        std::cout << "\n";
        return center;
    }
const double& Circle::get_radius(std::ostream& out) const {
        out << radius;
        return radius;
    }
double& Circle::give_radius() {
        std::cout << "введите радиус";
        std::cout << "\n";
        std::cin >> radius;
        std::cout << "\n";
        return radius;
    }
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
const size_t& Polyline::get_points(std::ostream& out) const {
        for (int i=0; i<count; i++) {
            out << points[i].X();
            out << ",";
            out << points[i].Y();
            out << " ";
        }
        return count;
    }
size_t& Polyline::give_points() {
    std::cout << "введите точки ломаной:";
        for (int i=0; i<count; i++) {
            std::cin >> points[i].X();
            std::cin.get();
            std::cin >> points[i].Y();
            std::cin.get();

        }
        return count;
    }
const size_t& Polyline::get_count(std::ostream& out) const {
        out << count;
        return count;
    }

const double& Text::get_point_x(std::ostream& out) const {
        out << point.x;
        return point.x;
    }
const double& Text::get_point_y(std::ostream& out) const {
            out << point.y;
            return point.y;
    }
Point& Text::give_point() {
        std::cout << "введите aтрибуты x и y";
        std::cout << "\n";
        std::cin >> point;
        std::cout << "\n";
        return point;
    }
    const double& Text::get_offset_x(std::ostream& out) const {
        out << offset.x;
        return offset.x;
    }
    const double& Text::get_offset_y(std::ostream& out) const {
            out << offset.y;
            return offset.y;
        }
    Point& Text::give_offset() {
            std::cout << "введите aтрибуты dx и dy";
            std::cout << "\n";
            std::cin >> offset;
            std::cout << "\n";
            return offset;
        }
const unsigned& Text::get_fontSize(std::ostream& out) const {
        out << fontSize;
        return fontSize;
    }
unsigned& Text::give_fontSize() {
        std::cout << "введите размер шрифта";
        std::cout << "\n";
        std::cin >> fontSize;
        std::cout << "\n";
        return fontSize;
    }
const std::string& Text::get_fontFamily(std::ostream& out) const {
        out << fontFamily;
        return fontFamily;
    }
std::string& Text::give_fontFamily() {
        std::cout << "введите шрифт";
        std::cout << "\n";
        getline(std::cin, fontFamily);
        getline(std::cin, fontFamily);
        std::cout << "\n";
        return fontFamily;
    }
const std::string& Text::get_data(std::ostream& out) const {
        out << data;
        return data;
    }
std::string& Text::give_data() {
        std::cout << "введите текст";
        std::cout << "\n";
      //  getline(std::cin, data);
        getline(std::cin, data);
        std::cout << "\n";
        return data;
    }
void Text::Print(std::ostream& out) const {
    out << "\n<text x=\"";
    get_point_x(out);
    out << "\" y=\"";
    get_point_y(out);
    out << "\" dx=\"";
    get_offset_x(out);
    out << "\" dy=\"";
    get_offset_y(out);
    out << "\" font-size=\"";
    get_fontSize(out);
    out << "\" font-family=\"";
    get_fontFamily(out);
    out << "\" fill=\"";
    get_fillColor(out);
    out << "\" stroke=\"";
    get_strokeColor(out);
    out << "\" stroke-width=\"";
    get_strokeWidth(out);
    out << "\">\n";
    get_data(out);
    out << "\n</text>";
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

