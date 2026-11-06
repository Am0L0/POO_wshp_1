#include <iostream>
#include <cmath>

class Circle{
    public:
        double x, y, r;

        void setPos(double nx, double ny){
            // Change la position du centre du cercle
            x = nx;
            y = ny;
        }

        double perimeter(){
            // Calcule le perimietre du cercle
            return 2*M_PI * r;
        }
};

class Rectangle{
    public:
        double x, y, w, h;

        void setPos(double nx, double ny){
            // Change la position du centre du rectangle
            x = nx;
            y = ny;
        }

        double perimeter(){
            // Calcule le perimetre du rectangle
            return 2 * (w + h);
        }
};

int main(){
    Circle c{0,0,1};
    std::cout << c.perimeter() << std::endl;
    c.setPos(1, 1);
    std::cout << "Coordinates of the center: (" << c.x << ", " << c.y << ")" << std::endl;


    Rectangle r{0,0,1,2};
    std::cout << r.perimeter() << std::endl;
    r.setPos(-1, -1);
    std::cout << "Coordinates of the top left corner: (" << r.x << ", " << r.y << ")" << std::endl;
    return 0;
}