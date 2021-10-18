#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <limits>
#include <sstream>
#include <type_traits>

class Razlomak {
    long long int brojnik, nazivnik;
    static long long int EuklidovAlgoritam(long long int a, long long int b);
    static bool DaLiJePrekoracenje(long long int a, long long int b);
    static void IzbaciRazmake(std::string &s);
    static bool DaLiJeBroj(const std::string &s);
public:
    Razlomak() : brojnik(0), nazivnik(1) {}
    Razlomak(long long int brojnik, long long int nazivnik);
    long long int DajBrojnik() const { return brojnik; }
    long long int DajNazivnik() const { return nazivnik; }
    // Binarni operatori
    friend Razlomak operator + (const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator - (const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator * (const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator / (const Razlomak &r1, const Razlomak &r2);
    friend Razlomak& operator += (Razlomak &r1, const Razlomak &r2);
    friend Razlomak& operator -= (Razlomak &r1, const Razlomak &r2);
    friend Razlomak& operator *= (Razlomak &r1, const Razlomak &r2);
    friend Razlomak& operator /= (Razlomak &r1, const Razlomak &r2);
    // Unarni operatori
    friend Razlomak operator - (const Razlomak &r);
    friend Razlomak operator + (const Razlomak &r);
    friend Razlomak& operator -- (Razlomak &r);
    friend Razlomak operator -- (Razlomak &r, int);
    friend Razlomak& operator ++ (Razlomak &r);
    friend Razlomak operator ++ (Razlomak &r, int);
    // Logicki operatori
    friend bool operator < (const Razlomak &r1, const Razlomak &r2);
    friend bool operator > (const Razlomak &r1, const Razlomak &r2);
    friend bool operator <= (const Razlomak &r1, const Razlomak &r2);
    friend bool operator >= (const Razlomak &r1, const Razlomak &r2);
    friend bool operator == (const Razlomak &r1, const Razlomak &r2);
    friend bool operator != (const Razlomak &r1, const Razlomak &r2);
    // Ulazni / Izlazni operatori
    friend std::ostream& operator << (std::ostream &tok, const Razlomak &r);
    friend std::istream& operator >> (std::istream &tok, Razlomak &r);
    // konverzija tipa razlomak u tip long double
    operator long double() const ;
};

Razlomak::Razlomak(long long int brojnik, long long int nazivnik = 1) {
    if(nazivnik == 0) throw std::logic_error("Nekoretan razlomak");
    auto NZD = EuklidovAlgoritam(brojnik, nazivnik);
    brojnik /= NZD; nazivnik /= NZD;
    if(nazivnik < 0) {
        nazivnik *= -1; brojnik *= -1;
    }
    Razlomak::brojnik = brojnik;
    Razlomak::nazivnik = nazivnik;
}
long long int Razlomak::EuklidovAlgoritam(long long int a, long long int b) {
    if(b == 0) return a;
    return EuklidovAlgoritam(b, a % b);
}

// Binarni operatori
Razlomak operator + (const Razlomak &r1, const Razlomak &r2) {
    auto r = Razlomak::EuklidovAlgoritam(r1.nazivnik, r2.nazivnik);
    auto a = (r1.brojnik * (r2.nazivnik/r)) + r2.brojnik * (r1.nazivnik/r);
    auto b = r1.nazivnik * (r2.nazivnik/r);
    return Razlomak(a, b);
}
Razlomak operator - (const Razlomak &r1, const Razlomak &r2) {
    auto r = Razlomak::EuklidovAlgoritam(r1.nazivnik, r2.nazivnik);
    auto a = (r1.brojnik * (r2.nazivnik/r)) - r2.brojnik * (r1.nazivnik/r);
    auto b = r1.nazivnik * (r2.nazivnik/r);
    return Razlomak(a, b);
}
Razlomak operator * (const Razlomak &r1, const Razlomak &r2) {
    auto s = Razlomak::EuklidovAlgoritam(r1.brojnik, r2.nazivnik);
    auto t = Razlomak::EuklidovAlgoritam(r2.brojnik, r1.nazivnik);
    auto a = (r1.brojnik/s) * (r2.brojnik/t);
    auto b = (r1.nazivnik/t) * (r2.nazivnik/s);
    return Razlomak(a,b);
}
Razlomak operator / (const Razlomak &r1, const Razlomak &r2) {
    auto r = Razlomak::EuklidovAlgoritam(r1.nazivnik, r2.nazivnik);
    auto u = Razlomak::EuklidovAlgoritam(r1.brojnik, r2.brojnik);
    auto a = (r1.brojnik/u) * (r2.nazivnik/r);
    auto b = (r1.nazivnik/r) * (r2.brojnik/u);
    return Razlomak(a,b);
}
Razlomak& operator += (Razlomak &r1, const Razlomak &r2) {
    r1 = r1 + r2;
    return r1;
}
Razlomak& operator -= (Razlomak &r1, const Razlomak &r2) {
    r1 = r1 - r2;
    Razlomak pomocni(r1.brojnik, r1.nazivnik);
    r1 = pomocni;
    return r1;
}
Razlomak& operator *= (Razlomak &r1, const Razlomak &r2) {
    r1 = r1 * r2;
    return r1;
}
Razlomak& operator /= (Razlomak &r1, const Razlomak &r2) {
    r1 = r1 / r2;
    Razlomak pomocni(r1.brojnik, r1.nazivnik);
    r1 = pomocni;
    return r1;
}

// Unarni operatori
Razlomak operator - (const Razlomak &r) {
    return {-r.brojnik, r.nazivnik};
}
Razlomak operator + (const Razlomak &r) {
    return r;
}
Razlomak& operator -- (Razlomak &r) {
    r = r - Razlomak(1,1);
    return r;
}
Razlomak operator -- (Razlomak &r, int) {
    auto original(r);
    --r;
    return original;
}
Razlomak& operator ++ (Razlomak &r) {
    r = r + Razlomak(1,1);
    return r;
}
Razlomak operator ++ (Razlomak &r, int) {
    auto original(r);
    ++r;
    return original;
}

// Logicki operatori
bool operator < (const Razlomak &r1, const Razlomak &r2) {
    auto r = Razlomak::EuklidovAlgoritam(r1.brojnik, r2.nazivnik);
    auto s = Razlomak::EuklidovAlgoritam(r1.nazivnik, r2.nazivnik);
    return (r1.brojnik/r) * (r2.nazivnik/s) < (r2.brojnik/r) * (r1.nazivnik/s);
}
bool operator > (const Razlomak &r1, const Razlomak &r2) {
    auto r = Razlomak::EuklidovAlgoritam(r1.brojnik, r2.nazivnik);
    auto s = Razlomak::EuklidovAlgoritam(r1.nazivnik, r2.nazivnik);
    return (r1.brojnik/r) * (r2.nazivnik/s) > (r2.brojnik/r) * (r1.nazivnik/s);
}
bool operator <= (const Razlomak &r1, const Razlomak &r2) {
    auto r = Razlomak::EuklidovAlgoritam(r1.brojnik, r2.nazivnik);
    auto s = Razlomak::EuklidovAlgoritam(r1.nazivnik, r2.nazivnik);
    return (r1.brojnik/r) * (r2.nazivnik/s) <= (r2.brojnik/r) * (r1.nazivnik/s);
}
bool operator >= (const Razlomak &r1, const Razlomak &r2) {
    auto r = Razlomak::EuklidovAlgoritam(r1.brojnik, r2.nazivnik);
    auto s = Razlomak::EuklidovAlgoritam(r1.nazivnik, r2.nazivnik);
    return (r1.brojnik/r) * (r2.nazivnik/s) >= (r2.brojnik/r) * (r1.nazivnik/s);
}
bool operator == (const Razlomak &r1, const Razlomak &r2) {
    auto a = Razlomak(r1.brojnik, r1.nazivnik);
    auto b = Razlomak(r2.brojnik, r2.nazivnik);
    return a.brojnik == b.brojnik && a.nazivnik == a.nazivnik;
}
bool operator != (const Razlomak &r1, const Razlomak &r2) {
    return !(r1 == r2);
}

// Ulazni / Izlazni operatori
std::ostream& operator << (std::ostream &tok, const Razlomak &r) {
    if(r.nazivnik == 1)
        tok << r.brojnik;
    else
        tok << r.brojnik << "/" << r.nazivnik;
    return tok;
}
std::istream& operator >> (std::istream &tok, Razlomak &r) {
    char znak;
    long long int a = 1, b = 1;
    tok >> std::ws >> a;
    if(tok.peek() == '/') {
        tok >> znak >> b;
        if(tok.peek() != ' ' && tok.peek() != '\t' && tok.peek() != '\n' && tok.peek() != '\v' && tok.peek() != '\f')
            tok.setstate(std::ios::failbit);
    }
    Razlomak pomocni(a,b); 
    r = pomocni;
    return tok;
}

// konverzija tipa razlomak u tip long double
Razlomak::operator long double() const {
    Razlomak pomocni(brojnik, nazivnik);
    return pomocni.brojnik / static_cast<long double>(pomocni.nazivnik);
}

// ---------------------------------- Test funkcije ----------------------------------

long long int Test(long long int a, long long int b) {
    if(b == 0) return a;
    return Test(b, a % b);
}
void Razlomak::IzbaciRazmake(std::string &s) {
    std::string pomocni;
    for(auto &x : s) 
        if(x != ' ') 
            pomocni.push_back(x);
    s = pomocni;
}
bool Razlomak::DaLiJeBroj(const std::string &s) {
    for(auto &x : s) 
        if(!(x >= '0' && x <= '9'))
            return false;
    return true;
}

// ---------------------------------- Test funkcije ----------------------------------

int main() {
    std::cout << "Unesite dva razlomka u formatu a/b\n";
    std::cout << "Unesite 1. razlomak: "; 
    Razlomak r1; std::cin >> r1;
    std::cout << "Unesite brojnik i nazivnik drugog ralomaka: ";
    long long int brojnik, nazivnik; std::cin >> brojnik >> nazivnik;
    Razlomak r2(brojnik, nazivnik);
    
    while(true) {
        try {
            std::cout << std::endl;
            std::cout << "Odaberite opciju:\n";
            
            std::cout << "1 - Ispis ralomaka" << std::endl;
            std::cout << "2 - Binarni operatori" << std::endl;
            std::cout << "3 - Unarni operatori" << std::endl;
            std::cout << "4 - Logicki operatori" << std::endl;
            std::cout << "5 - Rezultat dva razlomka" << std::endl;
            std::cout << "6 - Izlaz" << std::endl;
            
            std::cout << "Opcija: ";
            int opcija; std::cin >> opcija;
            
            if(opcija == 1) {
                std::cout << "Prvi razlomak: " << r1.DajBrojnik() << "/" << r1.DajNazivnik();
                std::cout << "\nDrugi razlomak: " << r2;
            }
            else if(opcija == 2) {
                std::cout << "operator + : " << r1 + r2;
                std::cout << "\noperator - : " << r1 - r2;
                std::cout << "\noperator * : " << r1 * r2;
                std::cout << "\noperator / : " << r1 / r2;
                r1 += r2;
                std::cout << "\noperator += : " << r1;
                r1 -= r2;
                std::cout << "\noperator -= : " << r1;
                r1 *= r2;
                std::cout << "\noperator *= : " << r1;
                r1 /= r2;
                std::cout << "\noperator /= : " << r1;
            }
            else if(opcija == 3) {
                std::cout << "Svi unarni operatori su primijenjeni na prvi razlomak:\n";
                std::cout << "\noperator - : " << -r1;
                std::cout << "\noperator + : " << +r1;
                std::cout << "\noperator -- (prefiksni) : " << --r1;
                std::cout << "\noperator -- : " << r1-- << " " << r1;
                std::cout << "\noperator ++ (prefiksni) : " << ++r1;
                std::cout << "\noperator ++ : " << r1++ << " " << r1;
            }
            else if(opcija == 4) {
                std::cout << "operator < : " << std::boolalpha << (r1 < r2);
                std::cout << "\noperator > : " << std::boolalpha << (r1 > r2);
                std::cout << "\noperator <= : " << std::boolalpha << (r1 <= r2);
                std::cout << "\noperator >= : " << std::boolalpha << (r1 >= r2);
                std::cout << "\noperator == : " << std::boolalpha << (r1 == r2);
                std::cout << "\noperator != : " << std::boolalpha << (r1 != r2);
            }
            else if(opcija == 5) {
                std::cout << "Rezultat ralomka 1: " << static_cast<long double>(r1);
                std::cout << "\nRezultat ralomka 2: " << static_cast<long double>(r2);
            }
            else if(opcija == 6) {
                break;
            }
            else {
                std::cout << "Greska pri unosu opcije\n";
            }
        }
        catch(...) {
            std::cout << "\nGreska";
            break;
        }
    }
	return 0;
}