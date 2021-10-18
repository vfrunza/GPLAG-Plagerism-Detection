/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <limits>
#include <math.h>

#define eps 0.00000001
class Razlomak{
    long long int brojnik, nazivnik;
    const static long long int m = std::numeric_limits<long long int>::min(); 
    const static long long int M = std::numeric_limits<long long int>::max();
    static long long int NZD(long long int p, long long int q){
        if(p < q){
            auto temp = p;
            p = q;
            q = temp;
        }
        while(q != 0){
            long long int g(p), h(q); 
            p = h; 
            q = g%h;
        }
        return p;
        
    }
    static void PrekoracenjeSabiranja(long long int x, long long int y){
        
        
        if( y > 0){
            if(x > M - y) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        }
        else if( y < 0){
            if(x < m - y) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        }
        
    }
    static void PrekoracenjeOduzimanja(long long int x, long long int y){
        PrekoracenjeSabiranja(x,(-1)*y);
    }
    static void PrekoracenjeMnozenja(long long int x, long long int y){
        
        if( y > 0){
            if(x < m/y || x > M/y) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
            
        }
        else if( y < 0){
            if(x == m || (-1)*x > M/((-1)*y) || (-1)*x < m/((-1)*y)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        }
        
    }
    
public:
    
    
    Razlomak(long long int brojnik =0, long long int nazivnik=1){
        if(nazivnik < 0 && (brojnik > 0 || brojnik < 0)) {
            brojnik*=-1;
            nazivnik*=-1;
        }
        if(nazivnik == 0) throw std::logic_error("Nekorektan razlomak");
        auto k = NZD(brojnik, nazivnik);
        brojnik/=k;
        nazivnik/=k;
        this->brojnik = brojnik;
        this->nazivnik = nazivnik;
    }
    //dodati operator = i konstruktor koji prima razlomak
    Razlomak(const Razlomak &r){
        this->brojnik = r.brojnik;
        this->nazivnik = r.nazivnik;
    }
    
    Razlomak &operator =(const Razlomak &r){
        this->brojnik = r.brojnik;
        this->nazivnik = r.nazivnik;
        return *this;
    }
    
    Razlomak &operator =(Razlomak &&r){
        this->brojnik = r.brojnik;
        this->nazivnik = r.nazivnik;
        return *this;
    }
    long long int DajBrojnik(){
        return brojnik;
    }
    long long int DajNazivnik(){
        return nazivnik;
    }
    friend Razlomak operator +(const Razlomak &r2, const Razlomak &r1){
        auto r = NZD(r2.nazivnik, r1.nazivnik);
        
        PrekoracenjeMnozenja(r2.brojnik,r1.nazivnik/r);
        PrekoracenjeMnozenja(r2.nazivnik,r1.nazivnik/r);
        PrekoracenjeMnozenja(r1.brojnik, r2.nazivnik/r);
        
        PrekoracenjeSabiranja(r2.brojnik * (r1.nazivnik/r), r1.brojnik *(r2.nazivnik /r));
        
        long long int br = r2.brojnik * (r1.nazivnik/r) + r1.brojnik *(r2.nazivnik /r);
        long long int na = r2.nazivnik *(r1.nazivnik/r);
        
        Razlomak ra(br,na);
        return ra;
        
    }
    friend Razlomak operator -(const Razlomak &r2, const Razlomak &r1){
        auto r = NZD(r2.nazivnik, r1.nazivnik);
        
        PrekoracenjeMnozenja(r2.brojnik,r1.nazivnik/r);
        PrekoracenjeMnozenja(r2.nazivnik,r1.nazivnik/r);
        PrekoracenjeMnozenja(r1.brojnik, r2.nazivnik/r);
        
        PrekoracenjeOduzimanja(r2.brojnik * (r1.nazivnik/r), r1.brojnik *(r2.nazivnik /r));
        
        long long int br = r2.brojnik * (r1.nazivnik/r) - r1.brojnik *(r2.nazivnik /r);
        long long int na = r2.nazivnik *(r1.nazivnik/r);
        
        Razlomak ra(br,na);
        return ra;
    }
    friend Razlomak operator *(const Razlomak &r2, const Razlomak &r1){
        auto s = NZD(r2.brojnik, r1.nazivnik);
        auto t = NZD(r1.brojnik, r2.nazivnik);
        
        PrekoracenjeMnozenja(r2.brojnik/s,r1.brojnik/t);
        PrekoracenjeMnozenja(r2.nazivnik/t,r1.nazivnik/s);
        
        long long int br= (r2.brojnik/s)*(r1.brojnik/t);
        long long int na = (r2.nazivnik/t)*(r1.nazivnik/s);
        
        Razlomak ra(br,na);
        return ra;
        
    }
    friend Razlomak operator /(const Razlomak &r2,const Razlomak &r1){
        auto u = NZD(r2.brojnik, r1.brojnik);
        auto r = NZD(r2.nazivnik, r1.nazivnik);
        
        PrekoracenjeMnozenja(r2.brojnik/u,r1.nazivnik/r);
        PrekoracenjeMnozenja(r2.nazivnik/r,r1.brojnik/u);
        
        long long int br = (r2.brojnik/u)*(r1.nazivnik/r);
        long long int na = (r2.nazivnik/r)*(r1.brojnik/u);
        
        Razlomak ra(br,na);
        return ra;
    }
    
    friend Razlomak &operator +=(Razlomak &r2, const Razlomak &r1){
        auto r = NZD(r2.nazivnik, r1.nazivnik);
        
        PrekoracenjeMnozenja(r2.brojnik,r1.nazivnik/r);
        PrekoracenjeMnozenja(r2.nazivnik,r1.nazivnik/r);
        PrekoracenjeMnozenja(r1.brojnik, r2.nazivnik/r);
        
        PrekoracenjeSabiranja(r2.brojnik * (r1.nazivnik/r), r1.brojnik *(r2.nazivnik /r));
        
        r2.brojnik = r2.brojnik * (r1.nazivnik/r) + r1.brojnik *(r2.nazivnik /r);
        r2.nazivnik = r2.nazivnik *(r1.nazivnik/r);
        
        auto k = NZD(r2.brojnik, r2.nazivnik);
        r2.brojnik/=k;
        r2.nazivnik/=k;
        return r2;
    }
    
    friend Razlomak &operator -=(Razlomak &r2, const Razlomak &r1){
        auto r = NZD(r2.nazivnik, r1.nazivnik);
        
        PrekoracenjeMnozenja(r2.brojnik,r1.nazivnik/r);
        PrekoracenjeMnozenja(r2.nazivnik,r1.nazivnik/r);
        PrekoracenjeMnozenja(r1.brojnik, r2.nazivnik/r);
        
        PrekoracenjeOduzimanja(r2.brojnik * (r1.nazivnik/r), r1.brojnik *(r2.nazivnik /r));
        
        r2.brojnik = r2.brojnik * (r1.nazivnik/r) - r1.brojnik *(r2.nazivnik /r);
        r2.nazivnik = r2.nazivnik *(r1.nazivnik/r);
        
        auto k = NZD(r2.brojnik, r2.nazivnik);
        r2.brojnik/=k;
        r2.nazivnik/=k;
        return r2;
        
    }
    
    friend Razlomak &operator *=(Razlomak &r2, const Razlomak &r1){
        auto s = NZD(r2.brojnik, r1.nazivnik);
        auto t = NZD(r1.brojnik, r2.nazivnik);
        
        PrekoracenjeMnozenja(r2.brojnik/s,r1.brojnik/t);
        PrekoracenjeMnozenja(r2.nazivnik/t,r1.nazivnik/s);
        
        r2.brojnik = (r2.brojnik/s)*(r1.brojnik/t);
        r2.nazivnik = (r2.nazivnik/t)*(r1.nazivnik/s);
        
        auto k = NZD(r2.brojnik, r2.nazivnik);
        r2.brojnik/=k;
        r2.nazivnik/=k;
        return r2;
        
    }
    
    friend Razlomak &operator /=(Razlomak &r2, const Razlomak &r1){
         auto u = NZD(r2.brojnik, r1.brojnik);
        auto r = NZD(r2.nazivnik, r1.nazivnik);
        
        PrekoracenjeMnozenja(r2.brojnik/u,r1.nazivnik/r);
        PrekoracenjeMnozenja(r2.nazivnik/r,r1.brojnik/u);
        
        r2.brojnik = (r2.brojnik/u)*(r1.nazivnik/r);
        r2.brojnik = (r2.nazivnik/r)*(r1.brojnik/u);
        
        auto k = NZD(r2.brojnik, r2.nazivnik);
        r2.brojnik/=k;
        r2.nazivnik/=k;
        return r2;
    }
    
    friend Razlomak &operator ++(Razlomak &r2){
        Razlomak r(1);
        r2+=r;
        return r2;
    }
    
    friend Razlomak operator ++(Razlomak &r2, int){
        auto pom = r2;
        ++r2;
        return pom;
    }
    friend Razlomak &operator --(Razlomak &r2){
        Razlomak r(1);
        r2 -= r;
        return r2;
    }
    
    friend Razlomak operator --(Razlomak &r2, int){
        auto pom = r2;
        --r2;
        return pom;
    }
    
    friend bool operator ==(const Razlomak &r1, const Razlomak &r2){
        long double raz1 = r1.brojnik/r1.nazivnik;
        long double raz2 = r2.brojnik/r2.nazivnik;
        if(fabs(raz1-raz2)<eps) return true;
        return false;
    }
    
    friend bool operator !=(const Razlomak &r1, const Razlomak &r2){
        return !(r1 == r2);
    }
    
    friend bool operator >(const Razlomak &r1, const Razlomak &r2){
        long double raz1 = r1.brojnik/r1.nazivnik;
        long double raz2 = r2.brojnik/r2.nazivnik;
        if(raz1-raz2> eps) return true;
        return false;
    }
    friend bool operator <(const Razlomak &r1, const Razlomak &r2){
        return r2 > r1;
    }
    friend bool operator >=(const Razlomak &r1, const Razlomak &r2){
        return (r1 > r2 || r1 == r2);
    }
    friend bool operator <=(const Razlomak &r1, const Razlomak &r2){
        return (r1 < r2 || r1 == r2);
    }
    
    friend std::ostream &operator <<(std::ostream &tok, const Razlomak &r){
        if(r.nazivnik == 1) return tok << r.brojnik;
        return tok << r.brojnik << "/" << r.nazivnik;
    }
    
    friend std::istream &operator >>(std::istream &tok, Razlomak &r){
        //std::cout << "in";
        char znak = 'a';
        r.brojnik = 0;
        r.nazivnik = 1;
        
        tok >> std::ws; //sa predavanja
        if((tok.peek() >= 'A' && tok.peek() <='Z') || (tok.peek() >= 'a' && tok.peek() <='z')) {
            tok.setstate(std::ios::failbit); return tok;
        }
        tok >> r.brojnik; 
        znak = tok.peek();
        if( znak == '/') {
            tok.get();
            tok >> r.nazivnik; 
            
           
           if(tok.peek() != '\n' && tok.peek() != ' '  && tok.peek() != '\r' && tok.peek() != '\f' && tok.peek() != '\v' 
                && tok.peek() != '\t' && tok.peek() != EOF) {tok.setstate(std::ios::failbit); return tok;}
            r.skrati();
            
        }
        else if(znak == '\n' || znak == ' ' ||  znak == '\r' || znak == '\f' || znak == '\v' 
            || znak == '\t' || znak == EOF) {
            r.nazivnik = 1;
            
            //std::cout << "In";
        }
        
        
        
        return tok;
    }
    operator long double() const {
        return brojnik/(long double)nazivnik;
    }
    private:
    void skrati(){
         auto k = NZD(brojnik, nazivnik);
       brojnik/=k;
       nazivnik/=k;
    }
};
int main ()
{
    Razlomak a(6);
    ++a;
    a++;
    a--;
    --a;
    std::cout <<a;
    
	return 0;
}