/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <limits>
#include <math.h>
class Razlomak{
  long long int brojnik;
  long long int nazivnik;
  
public:
    Razlomak(long long int br = 0, long long na = 1);
    Razlomak(const Razlomak &raz);
    Razlomak &operator =(const Razlomak &raz);
    Razlomak &operator =(Razlomak &&raz);
    long long int DajBrojnik() { return brojnik; }
    long long int DajNazivnik() { return nazivnik; }
    friend Razlomak operator +(const Razlomak &raz1, const Razlomak &raz2);
    friend Razlomak operator -(const Razlomak &raz1, const Razlomak &raz2);
    friend Razlomak operator *(const Razlomak &raz1, const Razlomak &raz2);
    friend Razlomak operator /(const Razlomak &raz1, const Razlomak &raz2);
    friend Razlomak &operator +=(Razlomak &raz1, const Razlomak &raz2);
    friend Razlomak &operator -=(Razlomak &raz1, const Razlomak &raz2);
    friend Razlomak &operator *=(Razlomak &raz1, const Razlomak &raz2);
    friend Razlomak &operator /=(Razlomak &raz1, const Razlomak &raz2);
    friend Razlomak &operator ++(Razlomak &raz);
    friend Razlomak operator ++(Razlomak &raz, int);
    friend Razlomak &operator --(Razlomak &raz);
    friend Razlomak operator --(Razlomak &raz, int);
    friend bool operator ==(const Razlomak &raz1, const Razlomak &raz2);
    friend bool operator !=(const Razlomak &raz1, const Razlomak &raz2);
    friend bool operator >(const Razlomak &raz1, const Razlomak &raz2);
    friend bool operator <(const Razlomak &raz1, const Razlomak &raz2);
    friend bool operator >=(const Razlomak &raz1, const Razlomak &raz2);
    friend bool operator <=(const Razlomak &raz1, const Razlomak &raz2);
    friend std::ostream &operator <<(std::ostream &stream, const Razlomak &raz);
    friend std::istream &operator >>(std::istream &stream, const Razlomak &raz);
    operator long double() const { return brojnik / (long double) nazivnik; }
    
private:
    static long long int IzracunajNajmanjiZajednicki(long long int x, long long int y){
        long long int c;
        if( x < y ){
            
            long long int p = y;
            long long int q = x;
            while( x != 0){
                p = y;
                q = x;
                y = q;
                x = p%q;
            }
            c=y;
        }
        else {
            long long int p = x;
            long long int q = y;
            while(y != 0){
                p = x;
                q = y;
                x = q;
                y = p%q;
                
            }
            c=x;
        }
        return c;
    }
    void skracivanjeRazlomka(){
        long long int najmanji_zajednicki = IzracunajNajmanjiZajednicki(brojnik, nazivnik); //std::cout << najmanji_zajednicki;
        brojnik = brojnik/najmanji_zajednicki;
        nazivnik = nazivnik/najmanji_zajednicki;
    }
    
    static void ProvjeraPrekoracenjaZaSabiranje(long long int x, long long int y){
        long long int mini = std::numeric_limits<long long int>::min();
        long long int Maxi = std::numeric_limits<long long int>::max();
        
        if( y > 0 ){
            if( x > Maxi - y) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        }
        else if ( y < 0 )
            if( x < mini - y) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
            
    }
    
    static void ProvjeraPrekoracenjaZaOduzimanje(long long int x, long long int y){
        long long int mini = std::numeric_limits<long long int>::min();
        long long int Maxi = std::numeric_limits<long long int>::max();
        
        y=-y;
        if( y > 0 ){
            if( x > Maxi - y) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        }
        else if ( y < 0 )
            if( x < mini - y) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    }
    
    static void ProvjeraPrekoracenjaZaMnozenje(long long int x, long long int y){
        long long int mini = std::numeric_limits<long long int>::min();
        long long int Maxi = std::numeric_limits<long long int>::max();
        
        if( y > 0 ){
            if( x < mini/y || x > Maxi/y) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        }
        
        else if ( y < 0 )
            if( x == mini || -x > Maxi / (-y) ) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    }
    
};

Razlomak::Razlomak(long long int br, long long na ){
    if(na == 0) throw std::logic_error("Nekorektan razlomak");
    if(na< 0) {
        na = -na;
        br = -br;
    }
    nazivnik = na;
    brojnik = br;
    skracivanjeRazlomka();
}

Razlomak::Razlomak(const Razlomak &raz){
    brojnik = raz.brojnik;
    nazivnik = raz.nazivnik;
}

Razlomak  &Razlomak::operator =(const Razlomak &raz) {
    brojnik = raz.brojnik;
    nazivnik = raz.nazivnik;
    return *this;
}

Razlomak &Razlomak::operator =(Razlomak &&raz){
    brojnik = raz.brojnik;
    nazivnik = raz.nazivnik;
    return *this;
}

std::ostream &operator <<(std::ostream &stream, const Razlomak &raz){
    if(raz.nazivnik == 1) 
        stream << raz.brojnik;
        
    else 
        stream << raz.brojnik << "/" << raz.nazivnik;
    return stream;
    
}

std::istream &operator >>(std::istream &stream,  Razlomak &raz){
    long long int br, na;
    //std::cout << "Usao";
    
    stream >> std::ws;
    
    stream >> br;
    char c = stream.peek();
    if(c == '\n' || c == '\r' || c == '\t' || c == '\v' || c == '\f' || c == ' ' || c == EOF) {
        na = 1;
        
    }
    else if( c == '/') {
        stream.get();
        
        stream >> na;
        c = stream.peek();
        if(!(c == '\n' || c == '\r' || c == '\t' || c == '\v' || c == '\f' || c == ' ' || c == EOF)) {
            stream.setstate(std::ios::failbit);
            return stream;
            
        }
        
    }
    else {
        stream.setstate(std::ios::failbit);
            return stream;
    }
    Razlomak novi(br, na);
    raz = novi;
    return stream;
}

Razlomak &operator +=(Razlomak &raz1, const Razlomak &raz2){
    //prema formulama iz zadace
    long long int r = Razlomak::IzracunajNajmanjiZajednicki(raz1.nazivnik, raz2.nazivnik);
    
    //Moramo provjeriti prvo da li ce doci do prekoracenja kada pomnozimo brojnike sa r/odgovarajuci nazivnik
    Razlomak::ProvjeraPrekoracenjaZaMnozenje(raz1.brojnik, raz2.nazivnik/r);
    Razlomak::ProvjeraPrekoracenjaZaMnozenje(raz2.brojnik, raz1.nazivnik/r);
    
    //Moramo provjeriti da li ce u novom nazivniku doci do prekoracenja - sto je opet mnozenje dva broja
    Razlomak::ProvjeraPrekoracenjaZaMnozenje(raz1.nazivnik/r, raz2.nazivnik);
    
    //Moramo provjeriti na kraju da li ce kada saberemo dva brojnika doci do prekoracenja
    Razlomak::ProvjeraPrekoracenjaZaSabiranje(raz1.brojnik*(raz2.nazivnik/r), raz2.brojnik*(raz1.nazivnik/r));
    
    raz1.brojnik =raz1.brojnik*(raz2.nazivnik/r) + raz2.brojnik*(raz1.nazivnik/r);
    raz1.nazivnik = (raz1.nazivnik/r)*raz2.nazivnik;
    raz1.skracivanjeRazlomka();
    return raz1;

}
Razlomak &operator -=(Razlomak &raz1, const Razlomak &raz2){
    long long int r = Razlomak::IzracunajNajmanjiZajednicki(raz1.nazivnik, raz2.nazivnik);
    
    //Moramo provjeriti prvo da li ce doci do prekoracenja kada pomnozimo brojnike sa r/odgovarajuci nazivnik
    Razlomak::ProvjeraPrekoracenjaZaMnozenje(raz1.brojnik, raz2.nazivnik/r);
    Razlomak::ProvjeraPrekoracenjaZaMnozenje(raz2.brojnik, raz1.nazivnik/r);
    
    //Moramo provjeriti da li ce u novom nazivniku doci do prekoracenja - sto je opet mnozenje dva broja
    Razlomak::ProvjeraPrekoracenjaZaMnozenje(raz1.nazivnik/r, raz2.nazivnik);
    
    //Moramo provjeriti na kraju da li ce kada saberemo dva brojnika doci do prekoracenja
    Razlomak::ProvjeraPrekoracenjaZaOduzimanje(raz1.brojnik*(raz2.nazivnik/r), raz2.brojnik*(raz1.nazivnik/r));
    
    raz1.brojnik =raz1.brojnik*(raz2.nazivnik/r) - raz2.brojnik*(raz1.nazivnik/r);
    raz1.nazivnik = (raz1.nazivnik/r)*raz2.nazivnik;
    raz1.skracivanjeRazlomka();
    return raz1;
}

Razlomak &operator *=(Razlomak &raz1, const Razlomak &raz2){
    //formule iz zadace
    long long int s = Razlomak::IzracunajNajmanjiZajednicki(raz1.brojnik, raz2.nazivnik);
    long long int t = Razlomak::IzracunajNajmanjiZajednicki(raz1.nazivnik, raz2.brojnik);
    
    Razlomak::ProvjeraPrekoracenjaZaMnozenje(raz1.brojnik/s, raz2.brojnik/t);
    Razlomak::ProvjeraPrekoracenjaZaMnozenje(raz1.nazivnik/t, raz2.nazivnik/s);
    
    raz1.brojnik = (raz1.brojnik/s )*(raz2.brojnik/t);
    raz1.nazivnik =(raz1.nazivnik/t)*( raz2.nazivnik/s);
    raz1.skracivanjeRazlomka();
    return raz1;
}

Razlomak &operator /=(Razlomak &raz1, const Razlomak &raz2){
    
    //formule iz zadace
long long int r = Razlomak::IzracunajNajmanjiZajednicki(raz1.nazivnik, raz2.nazivnik);
long long int u = Razlomak::IzracunajNajmanjiZajednicki(raz1.brojnik, raz2.brojnik);
    
    Razlomak::ProvjeraPrekoracenjaZaMnozenje(raz1.brojnik/u, raz2.nazivnik/r);
    Razlomak::ProvjeraPrekoracenjaZaMnozenje(raz1.nazivnik/r, raz2.brojnik/u);
    
    raz1.brojnik = (raz1.brojnik/u )*(raz2.nazivnik/r);
    raz1.nazivnik =(raz1.nazivnik/r)*( raz2.brojnik/u);
    raz1.skracivanjeRazlomka();
    
    return raz1;
}

Razlomak &operator ++(Razlomak &raz){
    Razlomak pomocni (1);
    return raz+=pomocni;
    
}

Razlomak operator ++(Razlomak &raz, int){
    Razlomak pomocni(raz);
    Razlomak pomocni2 (1);
    raz+=pomocni2;
    return pomocni;
    
}

Razlomak &operator --(Razlomak &raz){
    Razlomak pomocni (-1);
    return raz+=pomocni;
}

Razlomak operator --(Razlomak &raz, int){
     Razlomak pomocni(raz);
    Razlomak pomocni2 (-1);
    raz+=pomocni2;
    return pomocni;
}

bool operator ==(const Razlomak &raz1, const Razlomak &raz2){
    long double prvi(static_cast<long double>(raz1)), drugi(static_cast<long double>(raz2));
    if(fabs(prvi -drugi) < 0.000001) return true;
    return false;
}
bool operator !=(const Razlomak &raz1, const Razlomak &raz2){
    if(raz1 == raz2) return false;
    return true;
}

bool operator >(const Razlomak &raz1, const Razlomak &raz2){
    long double prvi(static_cast<long double>(raz1)), drugi(static_cast<long double>(raz2));
    if(prvi - drugi > 0.0000001) return true;
    return false;
}

bool operator <(const Razlomak &raz1, const Razlomak &raz2){
    if(raz1 > raz2) return false;
    return true;
}
bool operator >=(const Razlomak &raz1, const Razlomak &raz2){
    if(raz1 > raz2 || raz1 == raz2) return true;
    return false;
}
bool operator <=(const Razlomak &raz1, const Razlomak &raz2){
    if(raz1 < raz2 || raz1 == raz2) return true;
    return false;
}
Razlomak operator +(const Razlomak &raz1, const Razlomak &raz2){
    Razlomak r;
    r+=raz1;
    r+=raz2;
    return r;
}
Razlomak operator -(const Razlomak &raz1, const Razlomak &raz2){
    Razlomak r;
    r+=raz1;
    r-=raz2;
    return r;
}
Razlomak operator *(const Razlomak &raz1, const Razlomak &raz2){
    Razlomak r(1);
    r*=raz1;
    r*=raz2;
    return r;
}
Razlomak operator /(const Razlomak &raz1, const Razlomak &raz2){
    Razlomak r(1);
    r*=raz1;
    r/=raz2;
    return r;
}
int main ()
{
    
    Razlomak r (10, 17);
    Razlomak a;
    std::cin >> a;
    //a = r;
            std::cout << "Brojnik: " << a.DajBrojnik() << std::endl
                      << "Nazivnik: " << a.DajNazivnik();
	return 0;
}