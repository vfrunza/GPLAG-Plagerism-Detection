#include <iostream>
#include <limits>

class Razlomak
    {
        typedef long long int Long;
        Long b, n;
        static constexpr Long MAX = std::numeric_limits<Long>::max();
        static constexpr Long MIN = std::numeric_limits<Long>::min();
        enum class TipOF {Plus, Minus, Puta};
        static void ProvjeriOverflow (Long x, Long y, TipOF t)
        {
            if (
                (t == TipOF::Plus && (y > 0 && x > MAX - y || y < 0 && x < MIN - y)) ||
                (t == TipOF::Minus && (y < 0 && x > MAX + y || y > 0 && x < MIN + y)) ||
                (t == TipOF::Puta && ((y > 0 && (x < MIN / y || x > MAX / y)) || (y < 0 && (x < MAX / y || x > MIN / y))))
               )
            throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
        }
        Long NZD (Long p, Long q) {return !q ? p : NZD (q, p % q);}
    public:
        Razlomak (Long b = 0LL, Long n = 1LL)
        {
            if (!n) throw std::logic_error ("Nekorektan razlomak");
            Long nzd = NZD (b, n);
            n /= nzd; b /= nzd;
            if (n < 0) n = -n, b = -b;
            this->b = b; this->n = n;
        }
        Long DajBrojnik() const {return b;}
        Long DajNazivnik() const {return n;}
        friend std::ostream &operator << (std::ostream &x, const Razlomak &r)
            {
                x << r.DajBrojnik();
                if (r.DajNazivnik() != 1LL)
                    x << "/" << r.DajNazivnik();
                return x;
            }
        friend std::istream &operator >> (std::istream &x, Razlomak &r)
            {
                Long b = 0LL, n = 1LL;
                auto isws = [](const char c) {return c == ' ' || c == '\t' || c == '\n' || c == '\f' || c == '\r' || c == '\v';};
                x >> std::ws >> b;
                if (!x) return x;
                if (x.peek() == '/') {x.get(); x >> n;}
                if (!x || !isws(x.peek()))
                    x.setstate (std::ios::failbit);
                r = Razlomak (b, n);
                return x;
            }
        Razlomak operator - () const {return Razlomak (-b, n);}
        Razlomak operator + () const {return *this;}
        Razlomak &operator += (const Razlomak &raz)
        {
            Long r = NZD (n, raz.n);
            ProvjeriOverflow(b, raz.n / r, TipOF::Puta);
            ProvjeriOverflow(raz.b, n / r, TipOF::Puta);
            ProvjeriOverflow(n, raz.n / r, TipOF::Puta);
            Long p1q2 = b * (raz.n / r), p2q1 = raz.b * (n / r), q1q2 = n * (raz.n / r);
            ProvjeriOverflow(p1q2, p2q1, TipOF::Plus);
            return *this = Razlomak (p1q2 + p2q1, q1q2);
        }
        Razlomak &operator -= (const Razlomak &r) {return *this += -r;}
        friend Razlomak operator + (Razlomak A, const Razlomak &B) {return A += B;}
        friend Razlomak operator - (Razlomak A, const Razlomak &B) {return A -= B;}
        Razlomak &operator ++ () {return *this += 1;}
        Razlomak operator ++ (int) {Razlomak k = *this; ++*this; return k;}
        Razlomak &operator -- () {return *this -= 1;}
        Razlomak operator -- (int) {Razlomak k = *this; --*this; return k;}
        Razlomak &operator *= (const Razlomak &r)
            {
                Long s = NZD (b, r.n), t = NZD (r.b, n);
                ProvjeriOverflow(b / s, r.b / t, TipOF::Puta);
                ProvjeriOverflow(n / t, r.n / s, TipOF::Puta);
                return *this = Razlomak ((b / s) * (r.b / t), (n / t) * (r.n / s));
            }
        friend Razlomak operator * (Razlomak A, const Razlomak &B) {return A *= B;}
        Razlomak &operator /= (const Razlomak &raz)
            {
                Long r = NZD (n, raz.n), u = NZD (b, raz.b);
                ProvjeriOverflow(b / u, raz.n / r, TipOF::Puta);
                ProvjeriOverflow(n / r, raz.b / u, TipOF::Puta);
                return *this = Razlomak ((b / u) * (raz.n / r), (n / r) * (raz.b / u));
            }
        friend Razlomak operator / (Razlomak A, const Razlomak &B) {return A /= B;}
        operator long double () const {return (long double)b / (long double)n;}
        friend bool operator == (const Razlomak &A, const Razlomak &B) {return A.b == B.b && A.n == B.n;}
        friend bool operator != (const Razlomak &A, const Razlomak &B) {return !(A == B);}
        friend bool operator <  (const Razlomak &A, const Razlomak &B) {return (long double)A < (long double)B;}
        friend bool operator >  (const Razlomak &A, const Razlomak &B) {return (long double)A > (long double)B;}
        friend bool operator <= (const Razlomak &A, const Razlomak &B) {return A < B || A == B;}
        friend bool operator >= (const Razlomak &A, const Razlomak &B) {return A > B || A == B;}
    };
int main() {}
#if 0
#include <sstream>
//da se malo igramo, da razlomke zadajemo u formatu: a / b.
//da bude moguce 'Razlomak r = a / b', gdje su 'a' i 'b' specijalni 'brojevi'
//mozemo nauciti 'user-defined' literale iako se na predavanjima ne rade

struct RazlomakBroj {long long int x; RazlomakBroj (long long int x) : x(x) {}};
Razlomak operator / (const RazlomakBroj &b, const RazlomakBroj &n) { return {b.x, n.x};}
RazlomakBroj operator "" _r (unsigned long long int x) { return RazlomakBroj(x);}


int main()
    {
        {//AT7 (c9): op-, op/, op konverzije, kracenje
         //za _r pogledati 'globalni opseg' komentar i AT6
         std::cout << 10_r / 7_r - 6_r / 11_r; // 10/7 - 6/11
         std::cout << std::endl;
         std::cout << (10_r / 7_r) / (6_r / 11_r); // 10/7 / 6/11
         std::cout << std::endl;
         Razlomak r = 124_r / 4_r;
         std::cout << r;
         r = r - 11_r / 77_r;
         std::cout << std::endl;
         std::cout << r << " je priblizno " << static_cast<long double>(r);
        }
        return 7;
        {//AT6 (c9): [poucan]: op+, op*
            Razlomak r = 10_r / 3_r; // 10/3
            Razlomak v = 10_r / 7_r; //10/7
            std::cout << r * v << std::endl << r + v; //isti rezultat, mnozenje, sbairanje
        }
        return 6;
    {//AT5 (c9): operator + (primjer iz postavke)
        Razlomak r(2337, 3740), q (4014, 5225);
        std::cout << r << " + " << q << " = " << r + q;
    }
        return 5;
    {//AT4 (c9): operator >> (2/3) (direktno iz std::cin)
     //NAPOMENA: pogledati AT3 za detaljna objasnjenja
        Razlomak r, p, q;
        std::cin >> r; //5/17
        std::cout << r << std::endl;
        std::cin.clear(); std::cin.ignore (100, '\n');
        //tri zaredom
        std::cin >> r >> p >> q; //10 20 30 -> 10/1 20/1 30/1
        std::cout << r << " " << p << " " << q<< std::endl;
    }
    return 4;
    {//AT3 (c9): operator >> (1/3)
     //NAPOMENA: najlogicnija izvedba op>> ce proci
     //ove ATove. Dodatne izvedbe su nelogicne i nisu u skladu
     //sa ostaim tipovima...

     //ovdje cu koristiti specijalnu klasu (ne radi se naB
     //da preko stringa simuliram ulaz
     //cisto da se vide viska razmaci

     //NAPOMENA: pod "razmakom" se smatra SVAKI znak koji je bjelina
     //odnosno ovih 6 u en-US: \n, \t, \v, \f, \r, ' '

     Razlomak r, q, t;
     std::istringstream is ("10/20"); //ne mora sa \n zavrsiti
     is >> r;
     std::cout << r << std::endl;

     is.str ("173"); //samo jedan broj, 173/1
     is.clear(); //mora, radi EOF
     is >> r;
     std::cout << r << std::endl;

     is.str ("               173/50"); //ispravno, razmaci prije
     is.clear();
     is >> r;
     std::cout << r << std::endl;

     is.str ("               173/50       "); //ispravno, razmaci prije, poslije
     is.clear();
     is >> r;
     std::cout << r << std::endl;


     is.str ("173/51  ne zanima nas sta je nakon     "); //ispravno
     is.clear();
     is >> r;
     std::cout << r << std::endl;

     is.str ("17/33e ali je vazno da nakon razlomka ide BJELINA"); //neispravno
     is.clear();
     is >> r;
     if (is.fail()) std::cout << "OK, neispravno!" << std::endl;
     else std::cout << "Nije OK! Ovo nije ispravan unos!" << std::endl;

     //nije ispravno ni npr. 10b/20, ni 10/ 20 ni a20/5
     //necu sve testirati (barem ne u javnim :troll:)

     is.str ("a17/33"); //neispravno
     is.clear();
     is >> r;
     if (is.fail()) std::cout << "OK, neispravno!" << std::endl;
     else std::cout << "Nije OK! Ovo nije ispravan unos!" << std::endl;

     std::cout << "VEOMA VAZNO: " << std::endl;
     //treba biti MOGUCE unijeti vise razlomaka odjednom! (pazite na std::ws)
     is.str (" 1/3   5/7  4/2    nebitno"); //neispravno
     is.clear();
     is >> r >> q >> t;
     std::cout << "r = " << r << ", q = " << q << ", t = " << t;

     //dosta testova :whew:
    }
        return 3;
        {//AT2 (c9): operator << + sva tri konstruktora
            Razlomak r (17, 18), t (21), v;
            std::cout << "r = " << r << ", t = " << t << ", v = " << v;
        }
        return 2;
        {//AT1 (c9): trivijalan AT
            Razlomak r (10, 17);
            std::cout << "Brojnik: " << r.DajBrojnik() << std::endl
                      << "Nazivnik: " << r.DajNazivnik();
        }
        return 1;
        Razlomak r(2337, 3740), q (4014, 5225);
        std::cout << r + q;
        while (7)
        {
            Razlomak r;
            std::cin >> r;
            if (!std::cin) {std::cout << "Neispravan unos, ponovo: "; std::cin.clear(); std::cin.ignore (100000, '\n');}
            else std::cout << "Razlomak: " << r << std::endl;
        }
        Razlomak(6, 2);
        Razlomak(6LL, -2LL);Razlomak(-6LL, 2LL);Razlomak(-6LL, -2LL);
        Razlomak (); Razlomak (5LL);
        /*
        std::cout << Razlomak::MAX << std::endl;
        std::cout << Razlomak::MIN << std::endl;
        std::cout << (long long int)((long long int)Razlomak::MIN / (-1)) << std::endl;
        try {Razlomak::ProvjeriOverflow(9223372036854775807LL, -1, Razlomak::TipOF::Puta); std::cout << "Nema izuzetka!\n";}
        catch (...) {std::cout << "Izuzetak\n";}
        */
    }
#endif