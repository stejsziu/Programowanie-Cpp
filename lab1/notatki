#include <iostream>
#include <cmath>

// =========================================================================
// =========================================================================

class Informer {
    public:
    Informer() {
        std::cout << "Wywolano konstruktor domyslny" << "\n";
    }

    ~Informer() {
        std::cout << "Wywolano destruktor" << "\n";
    }
};

class Wektor2D {
    private:
        double x, y;
        static int num_wek;

    public:
        Informer info;
        static int getNumWek() { return num_wek; }
        static void setNumWek(int counter) { num_wek = counter; }

        Wektor2D() { ++num_wek; x = 0.; y = 0.; } // mozna zrobic pusty wektor
        Wektor2D(double wspX, double wspY) { // mozna tez zrobic od razu wartosci
            ++num_wek;
            x = wspX; 
            y = wspY;
            std::cout << "Utworzono wektor: x = " << x << ", y = " << y << "\n";
        }
        ~Wektor2D() { 
            std::cout << "Nastapilo morderstwo wektora: \
            x = " << x << ", y = " << y << "\n"; 
            --num_wek;
        }

        static Wektor2D zPolarnych(double r, double fi) {
            double wspX = r * cos(fi);
            double wspY = r * sin(fi);
            return Wektor2D{wspX, wspY};
        }

        double norm() { return sqrt(pow(x, 2) + pow(y, 2)); }
        void print() { std::cout << "x = " << x << ", y = " << y << "\n";}

        void setX(double wspX) { x = wspX; }
        void setY(double wspY) { y = wspY; }
        double getX() const { return x; }
        double getY() const { return y; }
};

Wektor2D operator+(const Wektor2D& v1, const Wektor2D& v2) {
    return Wektor2D{v1.getX() + v2.getX(), v1.getY() + v2.getY()};
}
Wektor2D operator*(const Wektor2D& v1, const Wektor2D& v2) {
    return Wektor2D{v1.getX() * v2.getY(), - v1.getY() * v2.getX()};
}

int Wektor2D::num_wek = 0;
int main()
{ 
    std::cout << "\n\nStart programu." << "\n" << "****************************\n";
    
    Wektor2D r1(1., 2.); 
    std::cout << "Liczba wektorow: " << Wektor2D::getNumWek() << "\n";

    Wektor2D r2(3., 4.); 
    std::cout << "Liczba wektorow: " << Wektor2D::getNumWek() << "\n";

    { 
        Wektor2D r3(5., 6.);
        Wektor2D r4(7., 8.);
    }
    std::cout << "Liczba wektorow: " << Wektor2D::getNumWek() << "\n";
    
    Wektor2D r5(9., 10.); 
    std::cout << "Liczba wektorow: " << Wektor2D::getNumWek() << "\n";

    Wektor2D r6 = Wektor2D::zPolarnych(9., 10.); 
    std::cout << "Liczba wektorow: " << Wektor2D::getNumWek() << "\n";

    std::cout << "\n****************************\nKoniec programu.\n\n\n";
    return 0;
} 