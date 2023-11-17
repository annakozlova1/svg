#include <iostream>
#include "svg.hpp"
#include <fstream>


int main () {
    std::ofstream file;
    file.open("file.svg");
    int i=0;
    size_t size=0;
    Document document;
    std::string tipe="";
    while (1) {
        tipe="";
        std::cout <<"tipe figure: "<<std::endl;
        std::cin >> tipe;
        if (tipe=="circle") {
            document.objects.push_back(new Circle ());
            document.objects[i] -> Give();
            i+=1;
            continue;
        }
        if (tipe=="polyline") {
            std::cout << "введите количество точек" <<std::endl;
            std::cin >> size;
            document.objects.push_back(new Polyline(size));
            document.objects[i] -> Give();
            i+=1;
            size=0;
            continue;
        }
        if (tipe=="rectangle") {
            std::cout << "введите количество точек" <<std::endl;
            std::cin >> size;
            document.objects.push_back(new Rectangle(size));
            document.objects[i] -> Give();
            i+=1;
            size=0;
            continue;
        }
        if (tipe=="text") {
            document.objects.push_back(new Text());
            document.objects[i] -> Give();
            i+=1;
            continue;
        }
        if (tipe=="no") {
            break;
        }
        else {
            std::cout << "error"<<std::endl;
            continue;
        }
    }
    
    document.Print(file);

    return 0;
}