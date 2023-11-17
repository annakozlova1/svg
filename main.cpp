#include <iostream>
#include "svg.hpp"


int main () {
    

    Circle circle;
    circle.give_circle();
    circle.Print(std::cout); 
    
   /* size_t size=0;
    std::cout << "введите количетсво точек" << std::endl;
    std::cin >> size;
    Polyline polyline(size);
    polyline.give_poluline();
    polyline.Print(std::cout);*/
    
    /*size_t size=0;
    std::cout << "введите количетсво точек" << std::endl;
    std::cin >> size;
    Rectangle rectangle(size);
    rectangle.give_rectangle();
    rectangle.Print(std::cout);*/

 /*   Text text;
    text.give_text();
    text.Print(std::cout);  */
  
  /*  int tipe =0;
    size_t size=0;
    std::cout << "введите количетсво элементов" << std::endl;
    std::cin >> size;
    Document document(size);
    Circle circle;
   for (int i=0; i<size; i++) {
        std::cout << "введите тип фигуры" << std::endl;
     std::cin >> tipe;
        if (tipe == 1) {
            
           // document.objects[i]->give_circle();
            tipe=0;
            continue;
        }
        else  {
            return 1;
        }
    }

    document.Print(std::cout);*/

    return 0;
}