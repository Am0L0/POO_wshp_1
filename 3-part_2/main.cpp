#include <iostream>
#include <numeric>

using namespace std;


class Fraction {
    private :
        double num;
        double denum;
    public : 
        Fraction() : num(1), denum(1) {}
        Fraction(double n, double d) {
            setNum(n);
            setDenum(d);
        }

        double getNum(){
            return num;
        }
        void setNum(double n){
            num = n;
        }
        double getDenum(){
            return denum;
        }
        void setDenum(double d){
            if (d != 0){
                denum = d;
            }else {
                std::cout << "Valeur de denominateur invalide (0)" << std::endl;
            }
        }
        void afficher(){
            std::cout << num << "/" << denum << std::endl;
        }

        void simplify(){
            int res = std::gcd(int(num), int(denum));
            num /= res;
            denum /= res;
        }

        Fraction add(Fraction f){
            double n = (num * f.getDenum()) + (denum * f.getNum());
            double d = denum * f.getDenum();
            Fraction ff(n, d);
            ff.simplify();
            return ff;
        }
        
        Fraction minus(Fraction f){
            double n = (num * f.getDenum()) - (denum * f.getNum());
            double d = denum * f.getDenum();
            Fraction ff(n, d);
            ff.simplify();
            return ff;
        }

        Fraction multiply(Fraction f){
            double n = num * f.getNum();
            double d = denum * f.getDenum();
            Fraction ff(n, d);
            ff.simplify();
            return ff;
        }

        Fraction divide(Fraction f){
            Fraction inv(f.getDenum(), f.getNum());
            Fraction temp = multiply(inv);
            temp.simplify();
            return temp;
        }

};

int main()
{
    /* Test constructors */
    Fraction f0;
    if (f0.getNum() == 1 && f0.getDenum() == 1) {
        cout << "[OK] Default constructor works" << endl;
    }
    else {
        cout << "[FAILURE] Default constructor doesn't work" << endl;
    }

    Fraction f1(1, 2);
    if (f1.getNum() == 1 && f1.getDenum() == 2) {
        cout << "[OK] Constructor with parameters works" << endl;
    }
    else {
        cout << "[FAILURE] Constructor with parameters doesn't work" << endl;
    }

    Fraction f2(3, 4);

    /* Test add */
    Fraction f3 = f1.add(f2);
    if ((f3.getNum() == 10 && f3.getDenum() == 8)||(f3.getNum() == 5 && f3.getDenum() == 4)) {
        cout << "[OK] Add method works" << endl;
    }
    else {
        cout << "[FAILURE] Add method doesn't work" << endl;
    }

    /* Test minus */
    f3 = f1.minus(f2);
    if ((f3.getNum() == -2 && f3.getDenum() == 8)||(f3.getNum() == -1 && f3.getDenum() == 4)) {
        cout << "[OK] Minus method works" << endl;
    }
    else {
        cout << "[FAILURE] Minus method doesn't work" << endl;
    }

    /* Test multiply */
    f3 = f1.multiply(f2);
    if (f3.getNum() == 3 && f3.getDenum() == 8) {
        cout << "[OK] Multiply method works" << endl;
    }
    else {
        cout << "[FAILURE] Multiply method doesn't work" << endl;
    }

    /* Test divide */
    f3 = f1.divide(f2);
    if ((f3.getNum() == 4 && f3.getDenum() == 6)||(f3.getNum() == 2 && f3.getDenum() == 3)) {
        cout << "[OK] Divide method works" << endl;
    }
    else {
        cout << "[FAILURE] Divide method doesn't work" << endl;
    }
    return 0;
}