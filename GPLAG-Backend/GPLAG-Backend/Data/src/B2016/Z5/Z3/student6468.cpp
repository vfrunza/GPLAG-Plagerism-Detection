/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <cmath>

class Razlomak 
{
    long long  int brojnik;
    long long  int nazivnik;
    
    static long long int  NZD(long long int vrijednost_brojnika,long long int vrijednost_nazivnika)
    {
        if (vrijednost_nazivnika == 0) return vrijednost_brojnika;
        return NZD(vrijednost_nazivnika, vrijednost_brojnika%vrijednost_nazivnika);
         
    }
    
    public:
    Razlomak () { brojnik = 0; nazivnik = 1; }
    
    Razlomak (long long int vrijednost_brojnika) { brojnik = vrijednost_brojnika; nazivnik = 1;}
    
    Razlomak (long long int vrijednost_brojnika, long long int vrijednost_nazivnika)
    {
        if (vrijednost_nazivnika == 0)
        {
            throw std::logic_error ("Nekorektan razlomak");
        }
        
        if (vrijednost_nazivnika < 0)
        {
           vrijednost_brojnika = -vrijednost_brojnika;
           vrijednost_nazivnika = -vrijednost_nazivnika;
        }
        
        if (vrijednost_brojnika < 0 && vrijednost_nazivnika < 0)
        {
            vrijednost_brojnika *=-1;
            vrijednost_nazivnika *=-1;
           
        }
        
        long long int skrati = NZD(abs(vrijednost_brojnika), abs(vrijednost_nazivnika));
        
        vrijednost_brojnika = vrijednost_brojnika/skrati;
        vrijednost_nazivnika = vrijednost_nazivnika/skrati;

        
         this -> brojnik = vrijednost_brojnika;
         this -> nazivnik = vrijednost_nazivnika;
        
    }
    
    friend Razlomak operator + (const Razlomak &a, const Razlomak &b)
    {
        int r = NZD(a.nazivnik,b.nazivnik);
        return Razlomak((a.brojnik*(b.nazivnik/r) + b.brojnik*(a.nazivnik/r)), a.nazivnik*(b.nazivnik/r));
    }
  
    friend Razlomak operator - (Razlomak a, Razlomak b)
    {
        int r = NZD(a.nazivnik, b.nazivnik);
        return Razlomak((a.brojnik*(b.nazivnik/r) - b.brojnik*(a.nazivnik/r)), a.nazivnik*(b.nazivnik/r));
    }
    
    friend Razlomak operator * (const Razlomak &a, const Razlomak &b)
    {
        int s = NZD(a.brojnik, b.nazivnik);
        int t = NZD(b.brojnik, a.nazivnik);
        return Razlomak((a.brojnik/s)*(b.brojnik/t), (a.nazivnik/t)*(b.nazivnik/s));
    }
    
    friend Razlomak operator / (const Razlomak &a, const Razlomak &b)
    {
        int r = NZD(a.nazivnik, b.nazivnik);
        int u = NZD(a.brojnik, a.nazivnik);
        return Razlomak((a.brojnik/u)*(b.nazivnik/r), (a.nazivnik/r)*(b.brojnik/u));
    }
    
    Razlomak operator - () const;
    
    Razlomak operator + () const;
    
    
    friend Razlomak &operator -= (const Razlomak &a, const Razlomak &b)
    {
        Razlomak r(a);
        r -= b;
        return r;
    }
    
    friend Razlomak &operator *= (const Razlomak &a, const Razlomak &b)
    {
        Razlomak r(a);
        r *= b;
        return r;
    }
    
    friend Razlomak &operator /= (const Razlomak &a, const Razlomak &b)
    {
        Razlomak r(a);
        r /= b;
        return r;
    }
    
    friend Razlomak &operator ++ (Razlomak &r)
    {
        r.brojnik++;
        r.nazivnik++;
        
        return r; 
    }
    
    friend Razlomak operator ++ (Razlomak &r, int)
    {
        Razlomak pomocni(r);
        r++;
        return Razlomak(pomocni.brojnik,pomocni.nazivnik);
    }
    
    friend Razlomak &operator -- (Razlomak &r)
    {
        r.brojnik--;
        r.nazivnik--;
        return r;
    }
    
    friend Razlomak operator -- (Razlomak &r, int)
    {
        Razlomak pomocni(r);
        r--;
        return Razlomak(pomocni.brojnik, pomocni.nazivnik);
    }
    
    friend bool operator == (const Razlomak &a, const Razlomak &b)
    {
        return a.brojnik == b.brojnik && a.nazivnik == b.nazivnik;
    }
    
    friend bool operator != (const Razlomak &a, const Razlomak &b)
    {
        return !(a==b);
    }
    
    friend bool operator > (const Razlomak &a, const Razlomak &b)
    {
       int r = NZD(a.brojnik, b.brojnik);
       int s = NZD(a.nazivnik,b.nazivnik);
       
       return ((a.brojnik/r)*(b.nazivnik/s)) > ((b.brojnik/r)*(a.nazivnik/s));
    }
    
    friend bool operator < (const Razlomak &a, const Razlomak &b)
    {
        int r = NZD(a.brojnik,b.brojnik);
        int s = NZD(a.nazivnik,b.nazivnik);
        
        return ((a.brojnik/r)*(b.nazivnik/s)) < ((b.brojnik/r)*(a.nazivnik/s));
    }
    
    friend bool operator >= (const Razlomak &a, const Razlomak &b)
    {
        int r = NZD(a.brojnik, b.brojnik);
        int s = NZD(a.nazivnik, b.nazivnik);
        
        return ((a.brojnik/r)*(b.nazivnik/s)) >= ((b.brojnik/r)*(a.nazivnik/s));
    }
    
    friend bool operator <= (const Razlomak &a, const Razlomak &b)
    {
        int r = NZD(a.brojnik,b.brojnik);
        int s = NZD(a.nazivnik, b.nazivnik);
        
        return ((a.brojnik/r)*(b.nazivnik/s)) <= ((b.brojnik/r)*(a.nazivnik/s));
    }
    operator long double() const;
   
    long long int DajBrojnik() const { return brojnik; }
    long long int DajNazivnik() const { return nazivnik; }
    
    friend std::istream &operator>>(std::istream &tok, Razlomak &r)
    {
    
       int brojnik1;
       int nazivnik1 = 1;
       int s = 0;
       bool k = false;
       int peek;
       
       tok >> brojnik1;
       
       if (nazivnik1)
       {
           s = brojnik1;
           k = true;
       }

       if (tok.peek() == '\r')
       {
           tok.ignore();
           s = brojnik1;
           tok >> nazivnik1;
           peek = tok.peek();
           k = true;
        }
       
       
       if  (tok.peek() == '/')
       {
          tok.ignore();
          tok >> nazivnik1;
          if (tok.peek() == ' ')
          k = true;
       }
       
       if (tok.peek() != ' ' )
       {
           tok.setstate(std::ios::failbit);
       }

      
       if (tok || k)
       {
         
           r = Razlomak(brojnik1,nazivnik1);
          
       }
       
    return tok;
       
       
    }
    friend std::ostream &operator << (std::ostream &tok, const Razlomak &r)
    {
        if (r.nazivnik == 1) tok << r.brojnik;
        
        else 
        {
            Razlomak(r.brojnik,r.nazivnik);
            tok << r.brojnik << "/" << r.nazivnik;
        }
        
        return tok;
    }
};
   
    Razlomak::operator long double() const 
    {
    return (long double)brojnik/nazivnik;
    }
    
    Razlomak  Razlomak::operator - () const
    {
        return Razlomak(-brojnik, -nazivnik);
    }
    
    Razlomak Razlomak::operator + () const
    {
        return Razlomak(brojnik,nazivnik);
    }
    

 
    
    
    
    int main ()
{
   /* Razlomak r(2337,3740), q(4014, 5225);
    std::cout << "r + q = " << r + q;*/
    
    /*Razlomak r(10,7), q(6,11);
    std::cout << "r - q = " << r / q << std::endl;
    std::cout << "r * q = " << r*q << std::endl;*/
    
    /*Razlomak r = 124 / 4;
    std::cout << r;*/
    
  /*  Razlomak r(1,4), q(1,2);
    
    if (r <= q)
    std::cout << "Da" << std::endl;
    else 
    std::cout << "NE";
    */
	return 0;
}