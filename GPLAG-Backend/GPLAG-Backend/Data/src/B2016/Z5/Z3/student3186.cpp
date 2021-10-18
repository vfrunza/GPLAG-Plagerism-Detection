/B16/17 (Zadaća 5, Zadatak 3) a.k.a Wolfram Alpha
#include <stdexcept>
#include <iostream>
#include <limits>
#include <string>
#include <cmath>

class Razlomak {
    long long int brojnik, nazivnik;
    static long long int NZD (long long int x_, long long int y_) {
        if (y_ == 0) return x_; return Razlomak::NZD(y_, x_%y_);
    }
    static void overflow_test (const long long int &x, const long long int &y, char kontrol_znak) {
        if (kontrol_znak == '+') {
            if (y > 0) if (x > std::numeric_limits<long long int>::max() - y) throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
            if (y < 0) if (x < std::numeric_limits<long long int>::min() - y) throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
        }   else if (kontrol_znak == '*') {
            if (y > 0) 
                if (x < (std::numeric_limits<long long int>::min() / y) or x > (std::numeric_limits<long long int>::max() / y))
                    throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
            if (y < 0)
                if (x == std::numeric_limits<long long int>::min() or (-1)*x > (std::numeric_limits<long long int>::max() / ((-1)*y)) or 
                (-1)*x < (std::numeric_limits<long long int>::min() / ((-1)*y)))  throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
        }
    }
    static bool JesuLiJednaki (long double x, long double y, double Eps = 1e-10) {
        return std::fabs(x - y) <= Eps * (std::fabs(x) + std::fabs(y));
    }
public:
    Razlomak (long long int brojnik = 0, long long int nazivnik = 1) {
        if (nazivnik == 0) throw std::logic_error ("Nekorektan razlomak");
        if (brojnik < 0 and nazivnik < 0) brojnik *= -1, nazivnik *= -1;
        else if (brojnik > 0 and nazivnik < 0) brojnik *= -1, nazivnik *= -1;
            Razlomak::brojnik = brojnik/NZD(std::abs(brojnik), std::abs(nazivnik));
            Razlomak::nazivnik = nazivnik/NZD(std::abs(brojnik), std::abs(nazivnik));
    }
    
    long long int DajBrojnik() const {  return brojnik; }
    long long int DajNazivnik() const { return nazivnik; }
    
    // automatizovana konverzija 
    operator long double() const;
    // Osnovni operatori (binarni)..
    friend Razlomak operator +(const Razlomak &x, const Razlomak &y);
    friend Razlomak operator -(const Razlomak &x, const Razlomak &y);
    friend Razlomak operator *(const Razlomak &x, const Razlomak &y);
    friend Razlomak operator /(const Razlomak &x, const Razlomak &y);
    // Unarni operatori ..
    friend Razlomak operator +(const Razlomak &razlomak);
    friend Razlomak operator -(const Razlomak &razlomak);
    // +=, -=, *=, /= ..
    Razlomak &operator +=(const Razlomak &razlomak);
    Razlomak &operator -=(const Razlomak &razlomak);
    Razlomak &operator *=(const Razlomak &razlomak);
    Razlomak &operator /=(const Razlomak &razlomak);
    // ++i, i++, --i, i-- ..
    friend Razlomak &operator ++(const Razlomak &razlomak);
    friend Razlomak &operator ++(const Razlomak &razlomak, int);
    friend Razlomak &operator --(const Razlomak &razlomak);
    friend Razlomak &operator --(const Razlomak &razlomak, int);
    // Par buleana ..
    friend Razlomak operator <(const Razlomak &x, const Razlomak &y);
    friend Razlomak operator >(const Razlomak &x, const Razlomak &y);
    friend Razlomak operator <=(const Razlomak &x, const Razlomak &y);
    friend Razlomak operator >=(const Razlomak &x, const Razlomak &y);
    friend Razlomak operator ==(const Razlomak &x, const Razlomak &y);
    friend Razlomak operator !=(const Razlomak &x, const Razlomak &y);
    // << >> << >> ..
    friend std::ostream &operator <<(std::ostream &tok, const Razlomak &raz);
    friend std::istream &operator >>(std::istream &tok, Razlomak &raz);
};

// automatische konverzische
Razlomak::operator long double()const {
    long double x = (long double)(brojnik)/nazivnik;
    return x;
}

// Osnovni operatori (binarni)..
Razlomak operator +(const Razlomak &x, const Razlomak &y) {
    long long int NZD_ = Razlomak::NZD(x.nazivnik, y.nazivnik);
    Razlomak::overflow_test(x.brojnik, (y.nazivnik/NZD_), '*'); 
    Razlomak::overflow_test(y.brojnik, (x.nazivnik/NZD_), '*');
    Razlomak::overflow_test(x.nazivnik, (y.nazivnik/NZD_), '*');
    Razlomak::overflow_test((x.brojnik*(y.nazivnik/NZD_)), (y.brojnik*(x.nazivnik/NZD_)), '+');
    Razlomak output ({(x.brojnik * (y.nazivnik/NZD_)) + (y.brojnik * (x.nazivnik/NZD_))}, 
        {x.nazivnik * (y.nazivnik/NZD_)});  return output;
}

Razlomak operator -(const Razlomak &x, const Razlomak &y) {
    long long int NZD_ = Razlomak::NZD(x.nazivnik, y.nazivnik);
    Razlomak::overflow_test(x.brojnik, (y.nazivnik/NZD_), '*');
    Razlomak::overflow_test(y.brojnik, (x.nazivnik/NZD_), '*');
    Razlomak::overflow_test(x.nazivnik, (y.nazivnik/NZD_), '*');
    Razlomak::overflow_test((x.brojnik*(y.nazivnik/NZD_)), (y.brojnik*(x.nazivnik/NZD_)), '+');
    Razlomak output ({(x.brojnik * (y.nazivnik/NZD_)) - (y.brojnik * (x.nazivnik/NZD_))},
        {x.nazivnik * (y.nazivnik/NZD_)});  return output;
}

Razlomak operator *(const Razlomak &x, const Razlomak &y) {
    long long int s = Razlomak::NZD(x.brojnik, y.nazivnik), t = Razlomak::NZD(y.brojnik, x.nazivnik);
    Razlomak::overflow_test((x.brojnik/s), (y.brojnik/t), '*');
    Razlomak::overflow_test((x.nazivnik/t), (y.nazivnik/s), '*');
    Razlomak output ({(x.brojnik/s)*(y.brojnik/t)}, {(x.nazivnik/t)*(y.nazivnik/s)}); return output;
}

Razlomak operator /(const Razlomak &x, const Razlomak &y) {
    long long int r = Razlomak::NZD(x.nazivnik, y.nazivnik), u = Razlomak::NZD(x.brojnik, y.brojnik);
    Razlomak::overflow_test((x.brojnik/u), (y.nazivnik/r), '*');
    Razlomak::overflow_test((x.nazivnik/r), (y.brojnik/u), '*');
    Razlomak output ({(x.brojnik/u)*(y.nazivnik/r)}, {(x.nazivnik/r)*(y.brojnik/u)}); return output;
}

// Unarni operatori ..
Razlomak operator +(const Razlomak &razlomak) {
    return razlomak;
}

Razlomak operator -(const Razlomak &razlomak) {
    Razlomak::overflow_test((-1), razlomak.brojnik, '*');
    return Razlomak {(-1)*razlomak.brojnik, razlomak.nazivnik};
}

// +=, -=, *=, /= ...
Razlomak &Razlomak::operator +=(const Razlomak &razlomak) {
    Razlomak(brojnik, nazivnik) = Razlomak(brojnik, nazivnik) + razlomak;
    return *this;
}

Razlomak &Razlomak::operator -=(const Razlomak &razlomak) {
    Razlomak(brojnik, nazivnik) = Razlomak(brojnik, nazivnik) + razlomak;
    return *this;
}

Razlomak &Razlomak::operator *=(const Razlomak &razlomak) {
    Razlomak(brojnik, nazivnik) = Razlomak(brojnik, nazivnik) * razlomak;
    return *this;
}

Razlomak &Razlomak::operator /=(const Razlomak &razlomak) {
    Razlomak(brojnik, nazivnik) = Razlomak(brojnik, nazivnik) / razlomak;
    return *this;
}

// i++, i--, ++i, --i ...
Razlomak operator ++(Razlomak &razlomak) {
    razlomak += Razlomak{1};  return razlomak;
}

Razlomak operator ++(Razlomak &razlomak, int) {
    Razlomak temp{razlomak};  temp += Razlomak{1};
    return temp;
}

Razlomak operator --(Razlomak &razlomak) {
    razlomak -= Razlomak{1};  return razlomak;
}

Razlomak operator --(Razlomak &razlomak, int) {
    Razlomak temp{razlomak};  temp += Razlomak{1};
    return temp;
}

// Par buleana .....
Razlomak operator ==(const Razlomak &x, const Razlomak &y) {
    if ( Razlomak::JesuLiJednaki( (long double) x, (long double) y )) 
        return true; return false;
}

Razlomak operator !=(const Razlomak &x, const Razlomak &y) {
    if ( not( Razlomak::JesuLiJednaki( (long double) x, (long double) y ) )) 
        return true; return false;
}

Razlomak operator <(const Razlomak &x, const Razlomak &y) {
    if ( (long double) x < (long double) y ) 
        return true;   return false;
}

Razlomak operator >(const Razlomak &x, const Razlomak &y) {
    if ( (long double) x > (long double)y ) 
        return true;   return false;
}

Razlomak operator <=(const Razlomak &x, const Razlomak &y) {
    if ( (long double)x < (long double) y or Razlomak::JesuLiJednaki( (long double)x, (long double)y) )
        return true; return false;
}

Razlomak operator >=(const Razlomak &x, const Razlomak &y) {
    if ( (long double) x > (long double) y or Razlomak::JesuLiJednaki( (long double) x, (long double) y) ) 
        return true; return false;
}

// << >> << >> ...
std::ostream &operator <<(std::ostream &tok, const Razlomak &raz) {
    if (raz.brojnik == 0 or raz.nazivnik == 1) tok << raz.brojnik;
    else tok << raz.brojnik << "/" << raz.nazivnik ; return tok;
}

std::istream &operator >>(std::istream &tok, Razlomak &raz) {
    char znak; long long int x{0}, y{1};
    
    tok >> std::ws;
    if (tok.peek() >= '0' and tok.peek() <= '9')
        tok >> x;   else tok.setstate(std::ios::failbit);
    if (tok.peek() != ' ' and tok.peek() != '\n' and
    tok.peek() != '\r' and tok.peek() != '\f' and
    tok.peek() != '\v' and tok.peek() != '\t' and 
    tok.peek() != '/') tok.setstate(std::ios::failbit);
    if (tok.peek() == '/') {
        tok >> znak;
            if (tok.peek() >= '0' and tok.peek() <= '9')
                tok >> y;   else tok.setstate(std::ios::failbit);
    }   
    if (tok.peek() != ' ' and tok.peek() != '\n' and
    tok.peek() != '\r' and tok.peek() != '\f' and
    tok.peek() != '\v' and tok.peek() != '\t') tok.setstate(std::ios::failbit);
    raz = Razlomak{x,y}; return tok;
}

int main ()
{
    // Ma nisam puk'o 100% :') :')
    std::string lozinka;
    std::cout << "..::Dobrodosli u Svijet Razlomaka::.." << std::endl;
    std::cout << "+-----------------------------------+" << std::endl;
    std::cout << "| Molimo unesite lozinku za pristup |" << std::endl;
    std::cout << "+-----------------------------------+" << std::endl;
    std::cout << "Lozinka (HINT: ispod 50 je karaktera):"<< std::endl;
    std::getline (std::cin, lozinka);
    if (lozinka == "insomnija") {
        std::cout << "Tacno !" << std::endl;
        Razlomak prvi, drugi;
        std::cout << "Unesite prvi razlomak: " << std::endl;
        std::cin >> prvi;
        std::cout << "Unesite drugi razlomak: " << std::endl;
        std::cin >> drugi;
        for (;;) {
            int kontrolna{0};
            std::cout << "Unesite opciju (0 za listu opcija): ";
            std::cin >> kontrolna;
            if (kontrolna == 0) {
                std::cout << "+-----------------------------------+" << std::endl;
                std::cout << "| 1. Za sabiranje 2 razlomka        |" << std::endl;
                std::cout << "| 2. Za oduzimanje 2 razlomka       |" << std::endl;
                std::cout << "| 3. Za dijeljenje 2 razlomka       |" << std::endl;
                std::cout << "| 4. Za mnozenje 2 razlomka         |" << std::endl;
                std::cout << "| 5. Za == provjeru 2 razlomka      |" << std::endl;
                std::cout << "| 6. Za != provjeru 2 razlomka      |" << std::endl;
                std::cout << "| 7. Za > provjeru 2 razlomka       |" << std::endl;
                std::cout << "| 8. Za < provjeru 2 razlomka       |" << std::endl;
                std::cout << "| 9. Za >= provjeru 2 razlomka      |" << std::endl;
                std::cout << "| 10. Za ispis 2 razlomka           |" << std::endl;
                std::cout << "| 11. Za ispis u double             |" << std::endl;
                std::cout << "| 12. ili else za izlaz             |" << std::endl;
                std::cout << "+-----------------------------------+" << std::endl;
            }
            else if (kontrolna == 1) {
                std::cout << "Sabrana 2 razlomka su: " << prvi + drugi << std::endl;
            }
            else if (kontrolna == 2) {
                std::cout << "Oduzeta 2 razlomka su: " << prvi - drugi << std::endl;
            }
            else if (kontrolna == 3) {
                std::cout << "Podijeljena 2 razlomka su: " << prvi / drugi << std::endl;
            }
            else if (kontrolna == 4) {
                std::cout << "Pomnozena 2 razlomka su: " << prvi * drugi << std::endl;
            }
            else if (kontrolna == 5) {
                bool tacnost(prvi == drugi);
                std::cout << "prvi razlomak == drugi razlomak" << std::boolalpha << " je " << tacnost << "." << std::endl;
            }
            else if (kontrolna == 6) {
                bool tacnost(prvi != drugi);
                std::cout << "prvi razlomak != drugi razlomak" << std::boolalpha << " je " << tacnost << "." << std::endl;
            }
            else if (kontrolna == 7) {
                bool tacnost(prvi > drugi);
                std::cout << "prvi razlomak > drugi razlomak" << std::boolalpha << " je " << tacnost << "." << std::endl;
            }
            else if (kontrolna == 8) {
                bool tacnost (prvi < drugi);
                std::cout << "prvi razlomak < drugi razlomak" << std::boolalpha << " je " << tacnost << "." << std::endl;
            }
            else if (kontrolna == 9) {
                bool tacnost (prvi >= drugi);
                std::cout << "prvi razlomak >= drugi razlomak" << std::boolalpha << " je " << tacnost << "." << std::endl;
            }
            else if (kontrolna == 10) {
                std::cout << "Ispis 2 razlomka.. prvi: " << prvi << " drugi: " << drugi << "." << std::endl;
            }
            else if (kontrolna == 11) {
                std::cout << "Ispis u double .. prvi: " << (long double)(prvi) << " drugi: " << (long double)(drugi) << "." << std::endl;
            }   else {  std::cout << "Hvala, dođite opet!" << std::endl; break;    }
        }
    }   else std::cout << "Netacna lozinka :(";
    return 0;
}