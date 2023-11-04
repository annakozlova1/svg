#include <iostream>
#include "svg.hpp"
void Print_Circle (Circle circle);
void Print_Circle (Circle circle) {
    circle.give_center();
    circle.give_radius();
    circle.give_fillColor();
    circle.give_strokeColor();
    circle.give_strokeWidth();
    circle.Print(std::cout);
}


int main () {
    Circle circle;
    
    
    size_t size=0;
    std::cout << "введите количетсво точек" << std::endl;
    std::cin >> size;
    Polyline polyline(size);
    polyline.give_points();
    polyline.give_fillColor();
    polyline.give_strokeColor();
    polyline.give_strokeWidth();
    polyline.Print(std::cout);
    return 0;
}