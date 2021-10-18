/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <vector>
#include <limits>
#include <iomanip>
#include <cmath>
#include <sstream>
    const long long int M = std::numeric_limits<long long int>::max();
    const long long int m = std::numeric_limits<long long int>::min();
    
    void PrekoracenjeOduzimanja(long long int a, long long int b){
        if((b > 0 && a < m - b) || (b < 0 && a > M - b))
            throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    }
    void PrekoracenjeSabiranja(long long int a, long long int b){
        if((b > 0 && a > M - b) || (b < 0 && a < m - b))
            throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    }
    void PrekoracenjeMnozenja(long long int a, long long int b){
        if((b > 0 && (a < m/b || a > M/b)) || ( b < 0 && (a == m || -a > M/-b  || -a < m/-b)))
            throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    }
    class Razlomak{
        long long int brojnik;
        long long int nazivnik;
        static int NZD(long long int broj1, long long int broj2){
            if(broj2 == 0) return broj1;
            broj1 = broj1 % broj2;
            return NZD(broj2,broj1);
        }
    public:
        Razlomak(){brojnik = 0, nazivnik = 0;}
        Razlomak(long long int brojnik, long long int nazivnik = 1);
        long long int DajBrojnik()const{ return brojnik; }
        long long int DajNazivnik()const{ return nazivnik; }
        friend Razlomak operator +(const Razlomak &r1, const Razlomak &r2);
        friend Razlomak operator -(const Razlomak &r1, const Razlomak &r2);
        friend Razlomak operator *(const Razlomak &r1, const Razlomak &r2);
        friend Razlomak operator /(const Razlomak &r1, const Razlomak &r2);
        friend Razlomak &operator +=(Razlomak &r1, const Razlomak &r2);
        friend Razlomak &operator -=(Razlomak &r1, const Razlomak &r2);
        friend Razlomak &operator *=(Razlomak &r1, const Razlomak &r2);
        friend Razlomak &operator /=(Razlomak &r1, const Razlomak &r2);
        friend Razlomak &operator ++(Razlomak &r);
        friend Razlomak &operator --(Razlomak &r);
        friend Razlomak operator ++(Razlomak &r, int);
        friend Razlomak operator --(Razlomak &r,int);
        friend bool operator ==(const Razlomak &r1, const Razlomak &r2){
            return r1.brojnik == r2.brojnik && r1.nazivnik == r2.nazivnik;
        }
        friend bool operator !=(const Razlomak &r1, const Razlomak &r2){
            return r1.brojnik != r2.brojnik || r1.nazivnik != r2.nazivnik;
        }
        friend bool operator >(const Razlomak &r1, const Razlomak &r2);
        friend bool operator <(const Razlomak &r1, const Razlomak &r2);
        friend bool operator >=(const Razlomak &r1, const Razlomak &r2);
        friend bool operator <=(const Razlomak &r1, const Razlomak &r2);
        friend std::ostream &operator <<(std::ostream &tok, const Razlomak &r);
        friend std::istream &operator >>(std::istream &tok, Razlomak &r);
        operator long double()const;
        friend Razlomak operator +(const Razlomak &r){
            return {r.brojnik,r.nazivnik};
        }
        friend Razlomak operator -(const Razlomak &r);
    };
    
    Razlomak::Razlomak(long long int brojnik, long long int nazivnik){
        if(nazivnik == 0) throw std::logic_error("Nekorektan razlomak");
        int nzd = NZD(brojnik,nazivnik);
        brojnik /= nzd;
        nazivnik /= nzd;
        if(brojnik < 0 && nazivnik < 0){
            brojnik *= -1;
            nazivnik *= -1;
            Razlomak::brojnik = brojnik;
            Razlomak::nazivnik = nazivnik;
        }
        else if(brojnik > 0 && nazivnik < 0){
            brojnik *= -1;
            nazivnik *= -1;
            Razlomak::brojnik = brojnik;
            Razlomak::nazivnik = nazivnik;
        }
        else{
            Razlomak::brojnik = brojnik;
            Razlomak::nazivnik = nazivnik;
        }
    }
    
    Razlomak::operator long double()const{
        return static_cast<long double>(brojnik)/static_cast<long double>(nazivnik);
    }
    
    Razlomak operator -(const Razlomak &r){
        PrekoracenjeOduzimanja(-r.brojnik,-r.nazivnik);
        return { -r.brojnik, -r.nazivnik };
    }
    Razlomak &operator +=(Razlomak &r1, const Razlomak &r2){
        int n = Razlomak::NZD(r1.nazivnik,r2.nazivnik);
      /*  PrekoracenjeMnozenja(r1.brojnik,r2.nazivnik/n);
        PrekoracenjeMnozenja(r2.brojnik,r1.nazivnik/n);
        PrekoracenjeMnozenja(r1.nazivnik,r2.nazivnik/n);
        PrekoracenjeOduzimanja(r1.brojnik* (r2.nazivnik/n),r2.brojnik * (r1.nazivnik/n));*/
        r1.brojnik = r1.brojnik * (r2.nazivnik/n) + r2.brojnik * (r1.nazivnik/n);
        r1.nazivnik = r1.nazivnik * (r2.nazivnik/n);
        Razlomak{r1.brojnik,r1.nazivnik};
        return r1;
    }
    Razlomak &operator -=(Razlomak &r1, const Razlomak &r2){
        int n = Razlomak::NZD(r1.nazivnik,r2.nazivnik);
       /* PrekoracenjeMnozenja(r1.brojnik,r2.nazivnik/n);
        PrekoracenjeMnozenja(r2.brojnik,r1.nazivnik/n);
        PrekoracenjeMnozenja(r1.nazivnik,r2.nazivnik/n);
        PrekoracenjeSabiranja(r1.brojnik* (r2.nazivnik/n),r2.brojnik * (r1.nazivnik/n*/
        r1.brojnik = r1.brojnik * (r2.nazivnik/n) - r2.brojnik * (r1.nazivnik/n);
        r1.nazivnik = r1.nazivnik * (r2.nazivnik/n);
        Razlomak{r1.brojnik,r1.nazivnik};
        return r1;
    }
    Razlomak &operator *=(Razlomak &r1, const Razlomak &r2){
        int s = Razlomak::NZD(r1.brojnik,r2.nazivnik);
        int t = Razlomak::NZD(r2.brojnik,r1.nazivnik);
        /*PrekoracenjeMnozenja(r1.brojnik,s);
        PrekoracenjeMnozenja(r2.brojnik,t);
        PrekoracenjeMnozenja(r1.nazivnik,t);
        PrekoracenjeMnozenja(r2.nazivnik,s);*/
        r1.brojnik = (r1.brojnik * s) / (r2.brojnik * t);
        r1.nazivnik = (r1.nazivnik * t) / (r2.nazivnik * s);
        Razlomak{r1.brojnik,r1.nazivnik};
        return r1;
    }
    Razlomak &operator /=(Razlomak &r1, const Razlomak &r2){
        int r = Razlomak::NZD(r1.nazivnik,r2.nazivnik);
        int u = Razlomak::NZD(r2.brojnik,r1.nazivnik);
        /*PrekoracenjeMnozenja(r1.brojnik / u,r2.nazivnik / r);
        PrekoracenjeMnozenja(r1.nazivnik / r,r2.brojnik / u);*/
        r1.brojnik = (r1.brojnik / u) * (r2.nazivnik / r);
        r1.nazivnik = (r1.nazivnik / r) * (r2.brojnik / u);
        Razlomak{r1.brojnik,r1.nazivnik};
        return r1;
    }
    Razlomak &operator ++(Razlomak &r){
        r.brojnik++; r.nazivnik++;
      //  PrekoracenjeSabiranja(r.brojnik,r.nazivnik);
        return r;
    }
    Razlomak &operator --(Razlomak &r){
        r.brojnik--; r.nazivnik--;
        PrekoracenjeOduzimanja(r.brojnik,r.nazivnik);
        return r;
    }
    Razlomak operator ++(Razlomak &r, int){
        Razlomak povratni(r);
        r.brojnik++; r.nazivnik++;
   //     PrekoracenjeSabiranja(r.brojnik,r.nazivnik);
        return povratni;
    }
    Razlomak operator --(Razlomak &r, int){
        Razlomak povratni(r);
        r.brojnik--; r.nazivnik--;
      //  PrekoracenjeOduzimanja(r.brojnik,r.nazivnik);
        return povratni;
    }
    bool operator >(const Razlomak &r1, const Razlomak &r2){
        long double x = static_cast<long double> (r1.brojnik)/static_cast<long double>(r1.nazivnik);
        long double y = static_cast<long double>(r2.brojnik)/static_cast<long double>(r2.nazivnik);
        return x > y;
    }
    bool operator <(const Razlomak &r1, const Razlomak &r2){
        long double x = static_cast<long double>(r1.brojnik)/static_cast<long double>(r1.nazivnik);
        long double y =static_cast<long double>(r2.brojnik)/static_cast<long double>(r2.nazivnik);
        return x < y;
    }
    bool operator >=(const Razlomak &r1, const Razlomak &r2){
        double const eps(0.0000000001);
        long double x = static_cast<long double>(r1.brojnik)/static_cast<long double>(r1.nazivnik);
        long double y = static_cast<long double>(r2.brojnik)/static_cast<long double>(r2.nazivnik);
        return x > y || fabs(x - y) < eps;
    }
    bool operator <=(const Razlomak &r1, const Razlomak &r2){
        double const eps(0.0000000001);
        long double x = static_cast<long double>(r1.brojnik)/static_cast<long double>(r1.nazivnik);
        long double y = static_cast<long double>(r2.brojnik)/static_cast<long double>(r2.nazivnik);
        return x < y || fabs(x - y) < eps;
    }
    
    std::ostream &operator <<(std::ostream &tok, const Razlomak &r){
        if(r.nazivnik == 1) tok << r.brojnik;
        else if(r.brojnik == 0) tok << 0;
        else
            tok << r.brojnik << "/" << r.nazivnik;
        
        return tok;
    }
    
    Razlomak operator +(const Razlomak &r1, const Razlomak &r2){
        int n = Razlomak::NZD(r1.DajNazivnik(),r2.DajNazivnik());
       /* PrekoracenjeMnozenja(r1.brojnik,r2.nazivnik/n);
        PrekoracenjeMnozenja(r2.brojnik,r1.nazivnik/n);
        PrekoracenjeMnozenja(r1.nazivnik,r2.nazivnik/n);
        PrekoracenjeSabiranja(r1.brojnik* (r2.nazivnik/n),r2.brojnik * (r1.nazivnik/n));*/
        long long int brojnik{r1.brojnik* (r2.nazivnik/n) + r2.brojnik * (r1.nazivnik/n)};
        long long int nazivnik{r1.nazivnik * (r2.nazivnik/n)};
        return {brojnik,nazivnik};
    }
    Razlomak operator -(const Razlomak &r1, const Razlomak &r2){
        int n = Razlomak::NZD(r1.nazivnik,r2.nazivnik);
       /* PrekoracenjeMnozenja(r1.brojnik,r2.nazivnik/n);
        PrekoracenjeMnozenja(r2.brojnik,r1.nazivnik/n);
        PrekoracenjeMnozenja(r1.nazivnik,r2.nazivnik/n);
        PrekoracenjeSabiranja(r1.brojnik* (r2.nazivnik/n),r2.brojnik * (r1.nazivnik/n));*/
        long long int brojnik{r1.brojnik * (r2.nazivnik/n) - r2.brojnik * (r1.nazivnik/n)};
        long long int nazivnik{r1.nazivnik * (r2.nazivnik/n)};
        return {brojnik,nazivnik};
    }
    Razlomak operator *(const Razlomak &r1, const Razlomak &r2){
        int s = Razlomak::NZD(r1.brojnik,r2.nazivnik);
        int t = Razlomak::NZD(r2.brojnik,r1.nazivnik);
/*      PrekoracenjeMnozenja(r1.brojnik,s);
        PrekoracenjeMnozenja(r2.brojnik,t);
        PrekoracenjeMnozenja(r1.nazivnik,t);
        PrekoracenjeMnozenja(r2.nazivnik,s);*/
        long long int brojnik{(r1.brojnik * s) / (r2.brojnik * t)};
        long long int nazivnik{(r1.nazivnik * t) / (r2.nazivnik * s)};
        return {brojnik,nazivnik};
    }
    Razlomak operator /(const Razlomak &r1, const Razlomak &r2){
        int r = Razlomak::NZD(r1.nazivnik,r2.nazivnik);
        int u = Razlomak::NZD(r2.brojnik,r1.nazivnik);
       /* PrekoracenjeMnozenja(r1.brojnik/u,r2.nazivnik/r);
        PrekoracenjeMnozenja(r1.nazivnik/r,r2.brojnik/u);*/
        long long int brojnik{(r1.brojnik/u) * (r2.nazivnik/r)};
        long long int nazivnik{(r1.nazivnik/r) * (r2.brojnik/u)};
        return {brojnik,nazivnik};
    }
        
        std::istream &operator >>(std::istream &tok, Razlomak &r){
        char znak;
        long long int x;
        long long int y;
        
        tok >> std::ws;
        tok >> x;
        
        if(tok.peek() == EOF || tok.peek() == ' ' || tok.peek() == '\t' || tok.peek() == '\r' || tok.peek() == '\v'|| tok.peek() == '\n'){
            r.brojnik = x;
            r.nazivnik = 1;
            return tok;
        }
        tok >> znak;
        if(znak != '/'){ tok.setstate(std::ios::failbit);
         tok.clear(); 
        }
        tok >> y;
        if(tok.peek() != EOF && tok.peek() != ' ' && tok.peek() != '\t' && tok.peek() != '\r' && tok.peek() != '\v'&& tok.peek() != '\n'){
            tok.setstate(std::ios::failbit);
        
        }
        if(tok) tok.clear();
        int z = Razlomak::NZD(x,y);
        r.brojnik = x/z; r.nazivnik = y/z;
    
        if(tok) tok.clear();
        
        return tok;
            
    }
int main ()
{   
    try{
        Razlomak r1,r2;
        std::cout << "Unesite dva razlomka: "<<std::endl;
        std::cin >> r1 >> r2;
        std::cout << "Zbir zazlomaka r1 i r2 je: r1 + r2 = "<< r1 + r2<<std::endl;
        std::cout << "Razlika zazlomaka r1 i r2 je: r1 - r2 = "<< r1 - r2<<std::endl;
        r1 += r2;
        r1--;
        Razlomak r3(r1/r2);
        std::cout << "Razlomak r1 iznosi: "<< r1<<std::endl;
        std::cout << "Razlomak r3 iznosi: "<< r3<<std::endl;
    }
    catch(std::overflow_error e){
        std::cout << e.what();
    }
    catch(std::logic_error e){
        std::cout << e.what();
    }
	return 0;
}