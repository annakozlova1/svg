#ifndef SVG_HPP
#define SVG_HPP
#include <cmath>
#include <istream>
#include <ostream>

struct Point {
    double x;
    double y;
    Point() : x(0), y(0) {}
    Point(double xArg, double yArg) : x(xArg), y(yArg) {}
    double X() const { return x; }
    double &X() { return x; }
    double Y() const { return y; }
    double &Y() { return y; }
};

std::ostream &operator<<(std::ostream &os, const Point &point);
std::istream &operator>>(std::istream &in, Point &point);
struct Color {
    int red;
    int green;
    int blue;
    const char* color;
    Color() : red(0), green(0), blue(0) {}
    Color (int rArg, int gArg, int bArg) : red(rArg), green(gArg), blue(bArg) {}
    Color (const char* cArg) : color(cArg) {}
//проработать исключение
   // void Print(std::ostream& out) const;

    const char* C() const { return color; }
    const char* &C() { return color; }
    int R() const { return red; }
    int &R() { return red; }
    int G() const { return green; }
    int &G() { return green; }
    int B() const { return blue; }
    int &B() { return blue; }
};

std::ostream &operator<<(std::ostream &os, const Color &color);
std::istream &operator>>(std::istream &in, Color &color);


class Object {
public:
Color fillColor; // Задаёт аттрибут "fill" --- цвет заливки.
Color strokeColor; // Задаёт аттрибут "stroke" --- цвет линии.
double strokeWidth; // Задаёт аттрибут "stroke-width" --- толщину линии.
//Реализовать методы, задающие указанные параметры.
// Методы должны выбрасывать исключение в случае некорректных параметров.
//Вывести объект в поток. 

virtual void Print(std::ostream& out) const = 0;
};


class Circle : public Object {
private:
Point center;
double radius;
/*проработать выброс исключений*/
public:
void Print(std::ostream& out) const override {
    out << "<circle center= ";
    out << center;
    out << "radius= ";
    out << radius;
    out << " fill= ";
    out << fillColor;
    out << " stroke= ";
    out << Object::strokeColor;
    out << "stroke-width= ";
    out << Object::strokeWidth;
    out << " />";
}
};



#endif