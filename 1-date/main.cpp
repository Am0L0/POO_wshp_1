#include <iostream>

class Date{
    public:
        int j, m, a;

        void afficher(void){ // j/m/a
            std::cout << j << "/" << m << "/" << a << std::endl;
        }

        void incr(){
            j++;
            switch (m){
                case 4: case 6: case 9: case 11:
                    if (j > 30){
                        j %= 30;
                        m++;
                    }
                    break;
                case 2:
                    if (j > 28){
                        j %= 28;
                        m++;
                    }
                    break;
                case 1: case 3: case 5: case 7: case 8: case 10:
                    if (j > 31){
                        j %= 31;
                        m++;
                    }
                    break;
                case 12:
                    if (j > 31){
                        j %= 31;
                        m++;
                        m %= 12;
                        a++;
                    }
                    break;
            }
        }
};

int main(){
    Date d;

    std::cout << "Jour :";
    std::cin >> d.j;
    std::cout << "Mois :";
    std::cin >> d.m;
    std::cout << "Année :";
    std::cin >> d.a;

    d.afficher();
    d.incr();
    d.afficher();
    
    return 0;
}