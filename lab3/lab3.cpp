#include <iostream>
#include <cmath>
#include <string>

const double PI = 4 * std::atan(1);

// g++ -Wall -Wextra lab3.cpp -o lab3 && ./lab3

class BytGeometryczny
{
    public:
        virtual ~BytGeometryczny() {}
        virtual void id() const = 0;
};

class Kolo;
class Kwadrat;

class WizytatorFigurBaza
{
    public:
        virtual void wizytuj(Kwadrat& kwadracik) = 0;
        virtual void wizytuj(Kolo& koleczko) = 0;
};

class Figura : public BytGeometryczny
{
    public:
        Figura(double wymiar) : pole{wymiar} {}
        virtual ~Figura() { std::cout << "Nastapilo morderstwo figury\n"; }
        double getPole() const { return pole; }
        virtual void id() const override { std::cout << "figura, pole = " << getPole() << std::endl; }
        virtual void akceptuj(WizytatorFigurBaza&) = 0;

    protected:
        double pole = 0;
};

class Kolo : public Figura
{
    public:
        Kolo(double promien) : Figura{PI*promien*promien} {}
        virtual ~Kolo() { std::cout << "Nastapilo morderstwo kola\n"; }
        void id() const override { std::cout << "kolo, pole = " << getPole() << std::endl; }
        void akceptuj(WizytatorFigurBaza& v) override { v.wizytuj(*this); }
};

class Kwadrat : public Figura
{
    public:
        Kwadrat(double bok) : Figura{bok*bok} {}
        virtual ~Kwadrat() { std::cout << "Nastapilo morderstwo kwadratu\n"; }
        void id() const override { std::cout << "kwadrat, pole = " << getPole() << std::endl; }
        void akceptuj(WizytatorFigurBaza& v) override { v.wizytuj(*this); }
};

class WektorFigur
{
    public:
        WektorFigur() {}
        ~WektorFigur() {
            for(int i = 0; i < licznik; i++)
                delete tablica[i];
        }

        Figura* operator[](int idx) const {
            if (idx < 0 || idx >= licznik)
                return nullptr;
            return tablica[idx];
        }

        void push(Figura* figurka) {
            if (licznik < 1000) {
                tablica[licznik] = figurka;
                ++licznik;
            }
        }

        void pop() {
            if (licznik > 0 && licznik < 1000) {
                --licznik;
                delete tablica[licznik];
                tablica[licznik] = nullptr;
            }
        }

        void idWszystkie() const {
            for(int i = 0; i < licznik; i++)
                tablica[i]->id();
        }

        void wizytujWszystkie(WizytatorFigurBaza& v) {
            for(int i = 0; i < licznik; i++)
                tablica[i]->akceptuj(v);
        }

    private:
        Figura* tablica[1000] = {};
        int licznik = 0;
};

void id(const Figura& figurka){
    figurka.id();
}

class FabrykaFigur
{
    public:
        Figura* operator()(const std::string& typ_figury, double rozmiar) {
            if(typ_figury == "kolo")
                return new Kolo{rozmiar};
            else if(typ_figury == "kwadrat")
                return new Kwadrat{rozmiar};
            else
             return nullptr;
        }
    };

class WizytatorDrukujacy : public WizytatorFigurBaza
{
    public:
        void wizytuj(Kwadrat& kwadracik) override { std::cout << "wizytuje kwadrat, pole = " << kwadracik.getPole() << std::endl; }
        void wizytuj(Kolo& koleczko) override { std::cout << "wizytuje kolo, pole = " << koleczko.getPole() << std::endl; }
};

int main()
{
    /* ---- do konca ---- */
    FabrykaFigur fabryka;
    WektorFigur wf;
    WizytatorDrukujacy wd;

    std::string typ;
    double rozmiar;
    std::cout << "Podawaj: typ rozmiar (kolo/kwadrat), koniec = stop\n";
    while (std::cin >> typ && typ != "stop") {
        std::cin >> rozmiar;
        Figura* f = fabryka(typ, rozmiar);
        if (f)
            wf.push(f);
        else
            std::cout << "nieznany typ\n";
    }

    wf.wizytujWszystkie(wd);

    /* --- do zad20 ---
    FabrykaFigur fabryka;
    WektorFigur wf;

    Figura* f = fabryka("kwadrat", 3.);
    if (f)
        wf.push(f);

    wf.push(fabryka("kolo", 2.));   // uwaga: push(nullptr) też by przeszło

    wf[0]->id();   // kwadrat, pole = 9
    wf[1]->id();   // kolo, pole = 12.5664
    */
    /* ---- do zad19 ---
    WektorFigur wf;
    wf.push(new Kwadrat{3.});
    wf.push(new Kolo{2.});
    wf[0]->id();   // kwadrat, pole = 9
    wf[1]->id();   // kolo, pole = 12.5664
    wf.pop();      // niszczy koło
    wf.pop();      // niszczy kwadrat
    wf.pop();      // nic się nie dzieje, wektor pusty
    */
    /* ---- do zad14
    BytGeometryczny xd;
    */
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

/* ------------ do zad19 ------------
    class BytGeometryczny
    {
        public:
            virtual ~BytGeometryczny() {}
            virtual void id() const = 0;
    };

    class Figura : public BytGeometryczny
    {
        public:
            Figura(double wymiar) : pole{wymiar} {}
            virtual ~Figura() { std::cout << "Nastapilo morderstwo figury\n"; }
            double getPole() const { return pole; }
            virtual void id() const override { std::cout << "figura, pole = " << getPole() << std::endl; }

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
        public:
            WektorFigur() {}
            ~WektorFigur() {
                for(int i = 0; i < licznik; i++)
                    delete tablica[i];
            }

            Figura* operator[](int idx) const
            {
                if (idx < 0 || idx >= licznik)
                    return nullptr;
                return tablica[idx];
            }

            void push(Figura* figurka) {
                if (licznik < 1000) {
                    tablica[licznik] = figurka;
                    ++licznik;
                }
            }

            void pop() {
                if (licznik > 0 && licznik < 1000) {
                    --licznik;
                    delete tablica[licznik];
                    tablica[licznik] = nullptr;
                }
            }

        private:
            Figura* tablica[1000] = {};
            int licznik = 0;
    };

    void id(const Figura& figurka){
        figurka.id();
    }
*/

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
