#include <iostream> // cin cout
#include <cmath>
#define PI 3.14159265358979323846

// =========================================================================
// =========================================================================

class Wektor
{
    public:
        double* tablica;

        Wektor(const unsigned int n) {
            std::cout << "Nastapilo stworzenie wektora...\n";
            tablica = new double[n];
            for(int i = 0; i < (int) n; i++)
                tablica[i] = 0;
            dlugosc = n;
            pojemnosc = n;
        }

        ~Wektor() {
            std::cout << "Nastapilo morderstwo wektora:\n";
            delete[] tablica;
        }

        unsigned int getDlugosc() { return dlugosc; }
        unsigned int getPojemnosc() { return pojemnosc; }

        void zmienDlugosc(unsigned int n_new){
            if(n_new <= dlugosc)
                dlugosc = n_new;
            else if(n_new <= pojemnosc && n_new > dlugosc){
                dlugosc = n_new;
                for(unsigned int i = 0; i < pojemnosc; i++)
                    tablica[i] = 0;
            }
            else if(n_new > pojemnosc){
                double* tablica_new = new double[n_new];
                for(unsigned int i; i < n_new; i++)
                    tablica_new[i] = 0;
                for(unsigned int i; i < pojemnosc; i++)
                    tablica_new[i] = tablica[i];

                dlugosc = n_new;
                pojemnosc = n_new;

                delete[] tablica;
                tablica = tablica_new;
                delete[] tablica_new;
            }
            else
                std::cout << "Error: impossible case reached!...stopping programme\n";
        }

        void print(){
            for(int i = 0; i < (int) dlugosc; i++)
                std::cout << " " << tablica[i] << " ";
            std::cout << "\n";
        }

    private:
        unsigned int dlugosc, pojemnosc; // czyli tylko int >= 0
};


int main()
{
    std::cout << "\n\nStart programu." << "\n" << "****************************\n";

    Wektor wektorek_testowy{3};
    std::cout << "Dlugosc nowego wektorka sprawdzamy = " << wektorek_testowy.getDlugosc() << "\n";
    wektorek_testowy.print();

    wektorek_testowy.zmienDlugosc(5);
    std::cout << "Dlugosc nowego wektorka sprawdzamy = " << wektorek_testowy.getDlugosc() << "\n";
    wektorek_testowy.print();

    std::cout << "\n****************************\nKoniec programu.\n\n\n";
    return 0;
}
