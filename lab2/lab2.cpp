#include <iostream> // cin cout
#include <cmath>
#define PI 4*atan(1)

// =========================================================================
// =========================================================================

class Wektor
{
    public:

        // konstruktor
        Wektor(const unsigned int n) : tablica{new double[n]}, dlugosc{n}, pojemnosc{n} {
            std::cout << "Nastapilo stworzenie wektora...\n";
            for(unsigned int i = 0; i < n; i++)
                tablica[i] = 0;
        }

        // konstruktor kopiujacy (zad. 14, 16)
        Wektor(const Wektor& v)
            : tablica{new double[v.dlugosc]}, dlugosc{v.dlugosc}, pojemnosc{v.dlugosc} {
            std::cout << "Nastapilo skopiowanie wektora...\n";
            for(unsigned int i = 0; i < dlugosc; i++)
                tablica[i] = v.tablica[i];
        }

        // kopiujacy operator przypisania (zad. 17)
        Wektor& operator=(const Wektor& v) {
            std::cout << "Nastapilo przypisanie wektora...\n";
            if (this != &v) {                       // ochrona przed a = a
                double* tablica_new = new double[v.dlugosc];
                for(unsigned int i = 0; i < v.dlugosc; i++)
                    tablica_new[i] = v.tablica[i];

                delete[] tablica;                   // zwolnij stary blok
                tablica = tablica_new;
                dlugosc = v.dlugosc;
                pojemnosc = v.dlugosc;
            }
            return *this;
        }

        // destruktor
        ~Wektor() {
            std::cout << "Nastapilo morderstwo wektora:\n";
            delete[] tablica;
        }

        unsigned int getDlugosc() const { return dlugosc; }
        unsigned int getPojemnosc() const { return pojemnosc; }

        void zmienDlugosc(unsigned int n_new){
            if (n_new <= dlugosc)
                dlugosc = n_new;
            else if (n_new <= pojemnosc && n_new > dlugosc){
                for(unsigned int i = dlugosc; i < n_new; i++)
                    tablica[i] = 0;
                dlugosc = n_new;
            }
            else {
                double* tablica_new = new double[n_new];
                for(unsigned int i = 0; i < dlugosc; i++)
                    tablica_new[i] = tablica[i];
                for(unsigned int i = dlugosc; i < n_new; i++)
                    tablica_new[i] = 0;

                delete[] tablica;
                tablica = tablica_new;
                dlugosc = n_new;
                pojemnosc = n_new;
            }
        }

        void print() const {
            for(unsigned int i = 0; i < dlugosc; i++)
                std::cout << " " << tablica[i] << " ";
            std::cout << "\n";
        }

        double& operator[](unsigned int i) {
            if (i >= dlugosc)
                zmienDlugosc(i+1);
            return tablica[i];
        }

    private:
        double* tablica;
        unsigned int dlugosc, pojemnosc;
};


//Wektor2D operator+(const Wektor2D& v1, const Wektor2D& v2) {
//    return Wektor2D::kart(v1.getX() + v2.getX(), v1.getY() + v2.getY()); }


int main()
{
    std::cout << "\n\nStart programu." << "\n" << "****************************\n";

    Wektor v{5};
    v.print();
    v[3] = 3;
    v.print();
    v[0] = 42.;
    v.print();
    double a = v[0];
    a++;
    printf("%.1lf\n", a);
    v[6] = 1;
    v.print();

    Wektor w{3};
    w[0] = 1; w[1] = 2; w[2] = 3;
    w.print();        //  1  2  3
    w[5] = 9;
    w.print();        //  1  2  3  0  0  9


    std::cout << "\n****************************\nKoniec programu.\n\n\n";
    return 0;
}
