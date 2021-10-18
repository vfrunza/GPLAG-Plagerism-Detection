#include <iostream>
#include <cmath>
#include <stdexcept>

class Razlomak {
  long long int brojnik, nazivnik;
  static int NZD(long long int a, long long int b){
      
        while(a!=b){
            if(a > b)
                a -= b;
            else b -= a;
        }
      return a;
  }
  public:
  
  Razlomak(){
      brojnik = 0;
  };
  Razlomak(const Razlomak &r){ brojnik = r.brojnik; nazivnik = r.nazivnik; };
  Razlomak(long long int b, long long int n = 1){
      if(n==0) throw std::logic_error ("Nekorektan razlomak");
      
      int temp = 0;
      if((n < 0 && b > 0) || (b < 0 && n > 0)) 
        temp = 1;
        b = abs(b);
        n = abs(n);
      
      int a = NZD(b,n);
      b /= a;
      n /= a;
      if(temp == 1)
            b *= -1;
      brojnik = b;
      nazivnik = n;
  }
    long long int DajBrojnik() const {
       return brojnik;
   } 
    long long int DajNazivnik() const {
        return nazivnik;
    }
    
    friend Razlomak operator +(const Razlomak &r1, const Razlomak &r2){
        int n = NZD(r1.nazivnik,r2.nazivnik);
        long long int m = r1.brojnik*(r2.nazivnik/n) + r2.brojnik*(r1.nazivnik/n);
        long long int c;
        c = r1.nazivnik*(r2.nazivnik/n);
        return Razlomak(m,c);
    }
    
    friend Razlomak operator *(const Razlomak &r1, const Razlomak &r2){
        int s = NZD(r1.brojnik,r2.nazivnik);
        int t = NZD(r2.brojnik,r1.nazivnik);
        long long int m = (r1.brojnik/s)*(r2.brojnik/t);
        long long int c = (r1.nazivnik/t)*(r2.nazivnik/s);
        return Razlomak(m,c);
    }
    friend Razlomak operator -(const Razlomak &r1, const Razlomak &r2){
        int n = NZD(r1.nazivnik,r2.nazivnik);
        long long int m = r1.brojnik*(r2.nazivnik/n) - r2.brojnik*(r1.nazivnik/n);
        long long int c = r1.nazivnik*(r2.nazivnik/n);
        return Razlomak(m,c);
    }
    friend Razlomak operator /(const Razlomak &r1, const Razlomak &r2){
        int u = NZD(r1.brojnik,r2.brojnik);
        int s = NZD(r1.nazivnik,r2.nazivnik);
        long long int m = (r1.brojnik/u)*(r2.nazivnik/s);
        long long int c = (r1.nazivnik/s)*(r2.brojnik/u);
        return Razlomak(m,c);
    }
    friend std::ostream &operator <<(std::ostream &cout, const Razlomak &r){
        if(r.brojnik == 0)
            std::cout<<r.DajBrojnik();
        else if(r.DajNazivnik()!=1)
            std::cout<<r.DajBrojnik()<<"/"<<r.DajNazivnik();
        else if(r.DajNazivnik()==1)
            std::cout<<r.DajBrojnik();
        return cout;
    }
    Razlomak &operator +=(const Razlomak &r){
        return *this=*this+r;
    }
    Razlomak &operator -=(const Razlomak &r){
        return *this=*this-r;
    }
    friend std::istream &operator >>(std::istream &tok, Razlomak &r){
            char znak1;
            long long int a, b, c;
            tok >> std::ws;
            if (tok.peek() < '0' || tok.peek() > '9') {
                tok.setstate(std::ios::failbit);
                return tok;
            }
            
            tok >> a;
            
            if(tok.peek()!='/'){
                c = 1;
                r = Razlomak(a,c);
            }
            
            else{
                tok >> znak1;
                if(znak1!='/') {
                    tok.setstate(std::ios::failbit);
                    return tok;
                }
                tok >> b;
                if((tok.peek() >= 'a' && tok.peek() <= 'z') || (tok.peek() >= 'Z' && tok.peek() <= 'Z')) { 
                    tok.setstate(std::ios::failbit);
                    return tok;
                }
                r = Razlomak(a,b);
            }
            
            return tok;
    }
    explicit operator long double () const {
        double a, b;
        a = double(brojnik);
        b = double(nazivnik);
        double suma=a/b;
        return suma;
    } 
    
};

int main ()
{
        Razlomak r, p, q;
        std::cin >> r; //5/17
        std::cout << r << std::endl;
        std::cin.clear(); std::cin.ignore (100, '\n');
        //tri zaredom
        std::cin >> r >> p >> q; //10 20 30 -> 10/1 20/1 30/1
        std::cout << r << " " << p << " " << q<< std::endl;
    
       
	return 0;
}