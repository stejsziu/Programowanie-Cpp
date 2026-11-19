#include <iostream>
#include <cmath>

const double PI = 4 * std::atan(1);

// g++ -Wall -Wextra lab3.cpp -o lab3
// ./lab3
// ALBO
// g++ -Wall -Wextra lab3.cpp -o lab3 && ./lab3

class BytGeometryczny
{
    public:
        virtual void id();
};

class Figura : public BytGeometryczny
{
    public:
        Figura(double wymiar) : pole{wymiar} {}
        virtual ~Figura() { std::cout << "Nastapilo morderstwo figury\n"; }
        double getPole() const { return pole; }
        virtual void id() const { std::cout << "figura, pole = " << getPole() << std::endl; }

    protected:
        double pole = 0;
};

class Kolo : public Figura
{
    public:
        Kolo(double promien) : Figura{PI*promien*promien} {}
        virtual ~Kolo() { std::cout << "Nastapilo morderstwo kola\n"; }
        void id() const override { std::cout << "kolo, pole = " << getPole() << std::endl; }
};

class Kwadrat : public Figura
{
    public:
        Kwadrat(double bok) : Figura{bok*bok} {}
        virtual ~Kwadrat() { std::cout << "Nastapilo morderstwo kwadratu\n"; }
        void id() const override { std::cout << "kwadrat, pole = " << getPole() << std::endl; }
};

class WektorFigur
{
    new tabblica
};

void id(const Figura& figurka){
    figurka.id();
}

int main()
{
    BytGeometryczny xd;

    /* ---- do zad13
    Figura* f = new Kwadrat{3.};
    delete f;
    */
    /* ---- do zad12
    Figura* f = new Kwadrat{3.};
    Kwadrat* k = dynamic_cast<Kwadrat*>(f);
    Kolo* c = dynamic_cast<Kolo*>(f);
    std::cout << k << "\t" << c << std::endl;
    */
    /* ---- do zad11 ----
    Kwadrat kw{3.};
    Kolo kolo{3.};
    id(kw);
    kw.id();
    kolo.id();
    Figura fig = static_cast<Figura>( kw );
    id(fig);
    fig.id();
    */
    /* ---- do zad7 ----
    Kolo kolko{2.};
    std::cout << "Pole kola = " << kolko.getPole() << "\n";
    Kwadrat kwadracik{3.};
    std::cout << "Pole kwadratu = " << kwadracik.getPole() << "\n";
    */
    /* ---- do zad4 ----
    Kolo kolko{2.};
    std::cout << "Pole kola = " << kolko.getPole() << "\n";
    Kwadrat kwadracik{3., 4.};
    std::cout << "Pole kwadratu = " << kwadracik.getPole() << "\n";
    */

    return 0;
}


/* ------------ do zad4 ------------
    class Figura
    {
        public:
            double getPole() const { return pole; }
            void setPole(double nowePole) { pole = nowePole; }

        private:
            double pole = 0;
    };

    class Kolo : public Figura
    {
        public:
            Kolo(double promien) { setPole(PI*promien*promien); }
    };

    class Kwadrat : public Figura
    {
        public:
            Kwadrat(double a, double b) { setPole(a*b); }
    };
 */

/* ------------ do zad7 ------------
    class Figura
    {
        public:
            Figura(double wymiar) : pole{wymiar} {}
            double getPole() const { return pole; }

        protected:
            double pole = 0;
    };

    class Kolo : public Figura
    {
        public:
            Kolo(double promien) : Figura{PI*promien*promien} {}
    };

    class Kwadrat : public Figura
    {
        public:
            Kwadrat(double bok) : Figura{bok*bok} {}
};
*/

/* ------------ do zad10 ------------
    class Figura
    {
        public:
            Figura(double wymiar) : pole{wymiar} {}
            double getPole() const { return pole; }
            void id() const { std::cout << "figura, pole = " << getPole() << std::endl; }

        protected:
            double pole = 0;
    };

    class Kolo : public Figura
    {
        public:
            Kolo(double promien) : Figura{PI*promien*promien} {}
            void id() const { std::cout << "kolo, pole = " << getPole() << std::endl; }
    };

    class Kwadrat : public Figura
    {
        public:
            Kwadrat(double bok) : Figura{bok*bok} {}
            void id() const { std::cout << "kwadrat, pole = " << getPole() << std::endl; }
    };

    void id(const Figura& figurka){
        figurka.id();
    }
*/

/* ------------ do zadania 13 ------------
    class Figura
    {
        public:
            Figura(double wymiar) : pole{wymiar} {}
            virtual ~Figura() { std::cout << "Nastapilo morderstwo figury\n"; }
            double getPole() const { return pole; }
            virtual void id() const { std::cout << "figura, pole = " << getPole() << std::endl; }

        protected:
            double pole = 0;
    };

    class Kolo : public Figura
    {
        public:
            Kolo(double promien) : Figura{PI*promien*promien} {}
            virtual ~Kolo() { std::cout << "Nastapilo morderstwo kola\n"; }
            void id() const override { std::cout << "kolo, pole = " << getPole() << std::endl; }
    };

    class Kwadrat : public Figura
    {
        public:
            Kwadrat(double bok) : Figura{bok*bok} {}
            virtual ~Kwadrat() { std::cout << "Nastapilo morderstwo kwadratu\n"; }
            void id() const override { std::cout << "kwadrat, pole = " << getPole() << std::endl; }
    };

    void id(const Figura& figurka){
        figurka.id();
    }
*/

/* ------------ do zadania 14 ------------
    lass BytGeometryczny
    {
        public:
            virtual void id();
    };

    class Figura : public BytGeometryczny
    {
        public:
            Figura(double wymiar) : pole{wymiar} {}
            virtual ~Figura() { std::cout << "Nastapilo morderstwo figury\n"; }
            double getPole() const { return pole; }
            virtual void id() const { std::cout << "figura, pole = " << getPole() << std::endl; }

        protected:
            double pole = 0;
    };
 */
