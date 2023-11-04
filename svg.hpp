#ifndef SVG_HPP
#define SVG_HPP
#include <cmath>
#include <istream>
#include <ostream>
#include <iostream>

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
private:
    Color fillColor; // Задаёт аттрибут "fill" --- цвет заливки.
    Color strokeColor; // Задаёт аттрибут "stroke" --- цвет линии.
    double strokeWidth; // Задаёт аттрибут "stroke-width" --- толщину линии.
public:
const Color& get_fillColor(std::ostream& out) const {
        out << fillColor;
        return fillColor;
    }
Color& give_fillColor() {
        std::cout << "введите цвет заливки";
        std::cout << "\n";
        std::cin >> fillColor;
        std::cout << "\n";
        return fillColor;
    }
const Color& get_strokeColor(std::ostream& out) const {
        out << strokeColor;
        return strokeColor;
    }
Color& give_strokeColor() {
        std::cout << "введите цвет обводки";
        std::cout << "\n";
        std::cin >> strokeColor;
        std::cout << "\n";
        return strokeColor;
    }
const double& get_strokeWidth(std::ostream& out) const {
        out << strokeWidth;
        return strokeWidth;
    }
double& give_strokeWidth() {
        std::cout << "введите толщину обводки";
        std::cout << "\n";
        std::cin >> strokeWidth;
        std::cout << "\n";
        return strokeWidth;
    }
//Реализовать методы, задающие указанные параметры.
// Методы должны выбрасывать исключение в случае некорректных параметров.
//Вывести объект в поток. 
~Object() {
    strokeWidth=0;
    fillColor={0,0,0};
    strokeColor={0,0,0};
}

virtual void Print(std::ostream& out) const = 0;
};


class Circle : public Object {
private:
Point center;
double radius;
/*проработать выброс исключений*/
public:
const double& get_center_x(std::ostream& out) const {
        out << center.x;
        return center.x;
    }
const double& get_center_y(std::ostream& out) const {
        out << center.y;
        return center.y;
    }
Point& give_center() {
        std::cout << "введите центр";
        std::cout << "\n";
        std::cin >> center;
        std::cout << "\n";
        return center;
    }
const double& get_radius(std::ostream& out) const {
        out << radius;
        return radius;
    }
double& give_radius() {
        std::cout << "введите радиус";
        std::cout << "\n";
        std::cin >> radius;
        std::cout << "\n";
        return radius;
    }
void Print(std::ostream& out) const override;
};

class Polyline : public Object {
private:
Point* points;
size_t count;
/*проработать выброс исключений*/
public:
Polyline(size_t size) {
    points = new Point[size];
    count=size;
}
~Polyline() {
    delete[] points;
}

const size_t& get_points(std::ostream& out) const {
        for (int i=0; i<count; i++) {
            out << points[i].X();
            out << ",";
            out << points[i].Y();
            out << " ";
        }
        return count;
    }

size_t& give_points() {
    std::cout << "введите точки ломаной:";
        for (int i=0; i<count; i++) {
            std::cin >> points[i].X();
            std::cin.get();
            std::cin >> points[i].Y();
            std::cin.get();

        }
        return count;
    }
const size_t& get_count(std::ostream& out) const {
        out << count;
        return count;
    }
void Print(std::ostream& out) const override;
};



#endif