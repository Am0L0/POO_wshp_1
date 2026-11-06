#include <iostream>
#include <cmath>

class Circle{
    public:
        double x, y, r;
    };
    
class Rectangle{
    public:
    double x, y, w, h;
};

void setPos(Circle *c, double nx, double ny){
    // Change la position du centre du cercle
    c->x = nx;
    c->y = ny;
}

double perimeter(Circle c){
    // Calcule le perimietre du cercle
    return 2*M_PI * c.r;
}

void setPos(Rectangle *r,double nx, double ny){
    // Change la position du coin (haut-gauche) du rectangle
    r->x = nx;
    r->y = ny;
}

double perimeter(Rectangle r){
    // Calcule le perimetre du rectangle
    return 2 * (r.w + r.h);
}


int main(){
    Circle c{0,0,1};
    std::cout << perimeter(c) << std::endl;
    setPos(&c, 1, 1);
    std::cout << "Coordinates of the center: (" << c.x << ", " << c.y << ")" << std::endl;


    Rectangle r{0,0,1,2};
    std::cout << perimeter(r) << std::endl;
    setPos(&r, -1, -1);
    std::cout << "Coordinates of the top left corner: (" << r.x << ", " << r.y << ")" << std::endl;
    return 0;
}