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
            return 2 * M_PI * r;
        }

        double area(){
            // Calcule l'aire du cercle
            return M_PI * r * r;
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

        double area(){
            // Calcule l'aire du rectangle
            return w * h;
        }
};

int main(){
    Circle c{0,0,1};
    std::cout << "Circle :" << std::endl << c.perimeter() << std::endl;
    std::cout << c.area() << std::endl;
    c.setPos(1, 1);
    std::cout << "Coordinates of the center: (" << c.x << ", " << c.y << ")" << std::endl;


    Rectangle r{0,0,1,2};
    std::cout << "Rectangle :" << std::endl << c.perimeter() << std::endl;
    std::cout << r.area() << std::endl;
    r.setPos(-1, -1);
    std::cout << "Coordinates of the top left corner: (" << r.x << ", " << r.y << ")" << std::endl;
    return 0;
}