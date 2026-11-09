#include <iostream>
#include <string>

class Creature{
    private :
        int pv, pa, niv;
    public :
        Creature() : pv(5), pa(5), niv(1){}
        Creature(int pv, int pa, int niv){
            setPv(pv);
            setPa(pa);
            setNiv(niv);
        }

        int getPv(){return pv;}
        int getPa(){return pa;}
        int getNiv(){return niv;}

        void setPv(int npv){if (npv >= 0){pv = npv;}}
        void setPa(int npa){if (npa >= 0){pa = npa;}}
        void setNiv(int nniv){if (nniv >= 0){niv = nniv;}}

        void affiche(){
            if (estVivant()){
            std::cout << "\033[31m" << R"ART(
    .-"""-.
   / o   o \
  |   ___   |
  |  \___/  |
   \_/\_/\_/
            )ART" << std::endl;
            std::cout << "PV : " << pv << ", PA : " << pa << ", NIV : " << niv << "\033[0m" << std::endl;
        }else {
            std::cout << "\033[31m" << R"ART(
    .-"""-.
   / x   x \
  |   ___   |
  |         |
   \_/\_/\_/
            )ART" << std::endl;
            std::cout << "La creature est morte" << std::endl;
        }}

        int attaque(){return pa;}

        void subitDegat(int degat){pv -= degat;}

        bool estVivant(){return pv>0;}
};

class Hero{
    private:
        std::string nom;
        int pv, pa, niv;
    public:
        Hero() : pv(50), pa(10), niv(1), nom("Amaury"){}
        Hero(int pv, int pa, int niv, std::string nom){
            setNom(nom);
            setPv(pv);
            setPa(pa);
            setNiv(niv);
        }

        std::string getNom(){return nom;}
        int getPv(){return pv;}
        int getPa(){return pa;}
        int getNiv(){return niv;}

        void setNom(std::string nnom){nom = nnom;}
        void setPv(int npv){if (npv > 0){pv = npv;}}
        void setPa(int npa){if (npa > 0){pa = npa;}}
        void setNiv(int nniv){if(nniv > 0){niv = nniv;}}

        void affiche() {
            if (estVivant()){
            std::cout << R"ART(
    ,-^-.   /
    (o o)  /
  [#]-|-==X
     / \
   _/   \_
            )ART" << std::endl;
            std::cout << "Nom : " << nom << ", PV : " << pv << ", PA : " << pa << ", NIV : " << niv << std::endl;
        }else{
            std::cout << nom << " est mort" << std::endl;
        }}

        int attaque(){return pa;}

        void subitDegat(int degat){pv -= degat;}

        bool estVivant(){return pv > 0;}
};

int main(){
    Hero h{50, 10, 8, "Hrun"};
    Creature c{25, 10, 5};
    int choix;

    while (c.estVivant()){
        h.affiche();
        c.affiche();

        std::cout << std::endl << "Actions : " << std::endl << "\033[33m 1. Attaquer \033[0m" << std::endl << "\033[32m 2. Utilser une potion (degat x2)\033[0m" << std::endl;
        std::cin >> choix;

        switch (choix)
        {
        case 1:
            c.subitDegat(h.attaque());
            h.subitDegat(c.attaque());
            break;
        
        case 2:
            c.subitDegat(h.attaque()*2);
            h.subitDegat(c.attaque());
            break;

        default:
            break;
        }
    }
    h.affiche();
    c.affiche();

    return 0;
}