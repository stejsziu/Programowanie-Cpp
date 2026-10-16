/* Stanislaw Szymanski
 log:
 12.10.2026 - stworzenie pliku + zad1
 13.10.2026 - zad2, zad3, zad4
 */

#include <iostream>
#include <cmath>

// =========================================================================
// =========================================================================
// =========================================================================

// Zad1:  ------------------------------------------------------------
// Napisz klasę Wektor2D, która przechowuje (jako publiczne zmienne) 
// współrzędną x i y dwuwymiarowego wektora. 
// Dodaj do niej metodę norm, zwracającą normę wektora, 
// oraz print, drukującą (w ładnym formacie) jego współrzędne.

struct Zad1Wektor2D {
    double x, y;
    double norm() {
        return sqrt(pow(x, 2) + pow(y, 2));
    }
    void print() {  
       std::cout << "x = " << x << ", y = " << y << "\n";
    }
};

// Zad2:  ------------------------------------------------------------
// Dodaj do klasy Wektor2D konstruktor dwuargumentowy, 
// który nadaje wartości współrzędnym wektora, a następnie je drukuje. 
// Napisz destruktor, który także drukuje tę informację. 
// Stwórz kilka różnych wektorów. 
// W jakiej kolejności są one niszczone? 
// W którym miejscu w kodzie następuje destrukcja?

struct Zad2Wektor2D {
    double x, y;

    Zad2Wektor2D(double wspX, double wspY) {
        x = wspX; 
        y = wspY;
        std::cout << "Utworzono wektor: x = " << x << ", y = " << y << "\n";
    }

    ~Zad2Wektor2D() {
        std::cout << "Nastapilo morderstwo wektora: x = " << x << ", y = " << y << "\n";
    }

    double norm() {
        return sqrt(pow(x, 2) + pow(y, 2));
    }
    void print() {
       std::cout << "x = " << x << ", y = " << y << "\n";
    }
};

// Zad3:  ------------------------------------------------------------
// Napisz klasę Informer, która posiada konstruktor domyślny, 
// drukujący informację o konstrukcji, 
// oraz destruktor, drukujący informację o destrukcji. 
// Dodaj do klasy Wektor2D pole typu Informer. 
// Które destruktory wołane są przy zniszczeniu wektora? W jakiej kolejności? 
// Zastanów się, jakie ma to implikacje dla komponowania większych obiektów 
// z mniejszych obiektów

class Informer {
    public:
    Informer() {
        std::cout << "Wywolano konstruktor domyslny" << "\n";
    }

    ~Informer() {
        std::cout << "Wywolano destruktor" << "\n";
    }
};

struct Zad3Wektor2D {
    double x, y;
    Informer info;

    Zad3Wektor2D(double wspX, double wspY) {
        x = wspX; 
        y = wspY;
        std::cout << "Utworzono wektor: x = " << x << ", y = " << y << "\n";
    }

    ~Zad3Wektor2D() {
        std::cout << "Nastapilo morderstwo wektora: x = " << x << ", y = " << y << "\n";
    }

    double norm() {
        return sqrt(pow(x, 2) + pow(y, 2));
    }

    void print() {
       std::cout << "x = " << x << ", y = " << y << "\n";
    }
};

// Zad4:  ------------------------------------------------------------
// Dodaj do klasy Wektor2D metody setX, getX, setY i getY, 
// służące do odczytywania i modyfikowania współrzędnych wektora. 
// Uczyń pola opisujące współrzędne prywatnymi. 
// Co stanie się, gdy spróbujesz zawołać np. std::print("{}", wektor.x)?

// =========================================================================
// =========================================================================
// =========================================================================

class Zad4Wektor2D {
    private:
        double x, y;

    public:
        Informer info;

        void setX(double wspX) {
            x = wspX;
        }

        double getX() {
            return x;
        }

        void setY(double wspY) {
            y = wspY;
        }

        double getY() {
            return y;
        }

        Zad4Wektor2D(double wspX, double wspY) {
            x = wspX; 
            y = wspY;
            std::cout << "Utworzono wektor: x = " << x << ", y = " << y << "\n";
        }

        ~Zad4Wektor2D() {
            std::cout << "Nastapilo morderstwo wektora: x = " << x << ", y = " << y << "\n";
        }

        double norm() {
            return sqrt(pow(x, 2) + pow(y, 2));
        }
        void print() {
        std::cout << "x = " << x << ", y = " << y << "\n";
        }
};

// Zad5:  ------------------------------------------------------------
// Przeciąż operatory `+` i `*` tak, 
// aby były zdefiniowane dla klasy `Wektor2D` 
// (zgodnie z tradycyjną algebrą).

class Zad5Wektor2D {
    private:
        double x, y;

    public:
        Informer info;

        Zad5Wektor2D() {} // mozna zrobic pusty wektor
        Zad5Wektor2D(double wspX, double wspY) { // mozna tez zrobic od razu wartosci
            x = wspX; 
            y = wspY;
            std::cout << "Utworzono wektor: x = " << x << ", y = " << y << "\n";
        }
        ~Zad5Wektor2D() { 
            std::cout << "Nastapilo morderstwo wektora: \
            x = " << x << ", y = " << y << "\n"; 
        }

        double norm() { return sqrt(pow(x, 2) + pow(y, 2)); }
        void print() { std::cout << "x = " << x << ", y = " << y << "\n";}

        void setX(double wspX) { x = wspX; }
        void setY(double wspY) { y = wspY; }
        double getX() const { return x; }
        double getY() const { return y; }
};

Zad5Wektor2D operator+(const Zad5Wektor2D& v1, const Zad5Wektor2D& v2) {
    return Zad5Wektor2D{v1.getX() + v2.getX(), v1.getY() + v2.getY()};
}
Zad5Wektor2D operator*(const Zad5Wektor2D& v1, const Zad5Wektor2D& v2) {
    return Zad5Wektor2D{v1.getX() * v2.getY(), - v1.getY() * v2.getX()};
}

int main()
{ 
    std::cout << "\n\nStart programu." << "\n" << "****************************\n";
    /*
    std::cout << "Zadanie 1" << "\n";
    Zad1Wektor2D r1;
    r1.x = 2.;
    r1.y = 5.;                           
    r1.print();
    
    std::cout << "Zadanie 2" << "\n";
    Zad2Wektor2D r21{3., 4.};
    Zad2Wektor2D r22{5., 6.};
    Zad2Wektor2D r23{6., 7.};

    std::cout << "Zadanie 3" << "\n";
    Zad3Wektor2D r3{1., 2.};

    std::cout << "Zadanie 4" << "\n";
    Zad4Wektor2D r4{1., 2.};
    // double a = r4.x; // nie dziala, bo x jest prywatne

    std::cout << "Zadanie 5" << "\n";

    Zad5Wektor2D r51{9., 10.};
    Zad5Wektor2D r52{3., 4.};

    Zad5Wektor2D r53 = r51 + r52;
    Zad5Wektor2D r54 = r51 * r52;

    std::cout << "suma: x = " << r53.getX() << ", y = " << r53.getY() << "\n";
    // Użycie .getX() i .getY() na wyniku mnożenia, by poprawnie wypisać wektor
    std::cout << "iloczyn: x = " << r54.getX() << ", y = " << r54.getY() << "\n";

    */

    std::cout << "Zadanie 7" << "\n";


    std::cout << "\n****************************\nKoniec programu.\n\n\n";
    return 0;
} 