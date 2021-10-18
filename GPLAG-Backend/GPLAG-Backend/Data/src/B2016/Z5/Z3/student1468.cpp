/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise



#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <limits>
#include <cmath>


class Razlomak 
{
  long long int brojnik;
  long  long int nazivnik;
  static long long int NZD (long long int p,long long int q){ if (q==0) return p; else return NZD(q, p%q); }
  
  
  static long long int Sabiranje (long long int X,long long int Y)
  {
        long long int m(std::numeric_limits<long long int>::min()), M(std::numeric_limits<long long int>::max());
        if (Y >= 0 && X > M - Y) throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
        else if(Y < 0 && X < m - Y) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        return X+Y;
  }
  static long long int Oduzimanje (long long int X, long long int Y)
  {
      long long int m(std::numeric_limits<long long int>::min()), M(std::numeric_limits<long long int>::max());
       if (Y >= 0 && X < m + Y) throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
        else if(Y < 0 && X > M + Y) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        return X-Y;
  }
  static long long int Mnozenje (long long int X, long long int Y)
  {
      long long int m(std::numeric_limits<long long int>::min()), M(std::numeric_limits<long long int>::max());
       if (Y >= 0 && (X < m / Y || X > M / Y)) throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
       else if (Y < 0 && (X == m || -X > M / (-Y) || -X < m / (-Y))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
       return X*Y;
  }
  
  
  
  public:
  // aritmetičke operacije bacaju izuzetak ukoliko rezultat nije egzaktno reprezentabilan ?
  

  Razlomak (long long int br=0,long long int naz=1);
  // vrši automatska pretvorba int u Razlomak
    Razlomak(std::initializer_list<long long int> lista);
  // zabrana da brojnik i nazivnik budu realni brojevi
 Razlomak &operator +=(Razlomak Y) { return *this = *this + Y; }
 Razlomak &operator -=(Razlomak Y) { return *this = *this - Y; }
 Razlomak &operator *=(Razlomak Y) { return *this = *this * Y; }
 Razlomak &operator /=(Razlomak Y) { return *this = *this / Y; }
  
  long long int DajBrojnik()const {return brojnik;};
 long long int  DajNazivnik()const {return nazivnik;};
 friend Razlomak operator + (Razlomak X, Razlomak Y);
friend Razlomak operator - (Razlomak X, Razlomak Y);
friend Razlomak operator * (Razlomak X, Razlomak Y);
friend Razlomak operator / (Razlomak X, Razlomak Y);
friend Razlomak operator +(Razlomak X);
friend Razlomak operator -(Razlomak Y);
friend Razlomak &operator ++ (Razlomak &X);
friend Razlomak operator ++ (Razlomak &X, int);
friend Razlomak &operator -- (Razlomak &X);
friend Razlomak operator -- (Razlomak &X, int);
friend bool operator < (Razlomak X, Razlomak Y);
friend bool operator > (Razlomak X, Razlomak Y);
friend bool operator <= (Razlomak X, Razlomak Y);
friend bool operator >= (Razlomak X, Razlomak Y);
friend bool operator == (Razlomak X, Razlomak Y);
friend bool operator != (Razlomak X, Razlomak Y);
friend std::ostream &operator <<(std::ostream &tok, Razlomak X);
friend std::istream &operator >>(std::istream &tok, Razlomak &X);

  
 
  operator long double () const { return (long double) brojnik / nazivnik; } // unose kao p/q

  
};

// kopirano iz klase 
Razlomak::Razlomak(long long int br, long long int naz)
{
   if(naz==0) throw std::logic_error ("Nekorektan razlomak"); 
   if (naz<0)
   {
    brojnik=(-1)*br; nazivnik=(-1)*naz; 
    
   }
   long long int nzd(NZD (std::abs(br),std::abs(naz))); 
   br/=nzd; naz/=nzd; 
   brojnik=br;nazivnik=naz;
   
  }  
  
  Razlomak::Razlomak(std::initializer_list<long long int> lista)
  {
      if(lista.size() == 0)
      {
          brojnik = 0;
          nazivnik = 1;
      }
      else if(lista.size() == 1)
      {
          brojnik = *lista.begin();
          nazivnik = 1;
      }
      else if(lista.size() == 2)
      {
          std::initializer_list<long long int>::iterator it(lista.begin());
          brojnik = *it / NZD(std::abs(*it), std::abs(*(it + 1)));
          nazivnik = *(it + 1) / NZD(std::abs(*it), std::abs(*(it + 1)));
          if(nazivnik < 0)
          {
              brojnik *= -1;
              nazivnik *= -1;
          }
          long long int nzd(NZD(std::abs(brojnik), std::abs(nazivnik)));
          brojnik /= nzd;
          nazivnik /= nzd;
      }
  }

   Razlomak operator +(Razlomak X,Razlomak Y)
  {
     Razlomak zbir;
     int r (Razlomak::NZD(std::abs(X.nazivnik),std::abs(Y.nazivnik)));
     int p1(X.brojnik),p2(Y.brojnik),q1(X.nazivnik),q2(Y.nazivnik);
     
     zbir.brojnik=Razlomak::Sabiranje(Razlomak::Mnozenje(p1,(q2/r)),Razlomak::Mnozenje(p2,(q1/r)));
     zbir.nazivnik=Razlomak::Mnozenje(q1,(q2/r));
     zbir = Razlomak(zbir.brojnik, zbir.nazivnik);
     return zbir; 
  }
 Razlomak operator -(Razlomak X,Razlomak Y)
  {
    Razlomak razlika;
    int r(Razlomak::NZD(std::abs(X.nazivnik),std::abs(Y.nazivnik)));
    int p1(X.brojnik),p2(Y.brojnik),q1(X.nazivnik),q2(Y.nazivnik);
    razlika.brojnik=Razlomak::Oduzimanje(Razlomak::Mnozenje(p1,(q2/r)),Razlomak::Mnozenje(p2,(q1/r)));
    razlika.nazivnik=Razlomak::Mnozenje(q1,(q2/r));
    razlika = Razlomak(razlika.brojnik,razlika.nazivnik);
    return razlika;
  }
  
  Razlomak operator *(Razlomak X, Razlomak Y)
  {
    Razlomak proizvod;
    int p1(X.brojnik),p2(Y.brojnik),q1(X.nazivnik),q2(Y.nazivnik);   // kopirano iz operator -
    int s (Razlomak::NZD (std::abs(p1),std::abs(q2))),t(Razlomak::NZD(std::abs(p2),std::abs(q1)));
    
   proizvod.brojnik=(Razlomak::Mnozenje((p1/s),(p2/t)));
   proizvod.nazivnik=Razlomak::Mnozenje((q1/t),(q2/s));
    proizvod=Razlomak(proizvod.brojnik,proizvod.nazivnik);
    return proizvod;
  }
   Razlomak operator / (Razlomak X,Razlomak Y)
  {
    Razlomak kolicnik;
    int p1(X.brojnik),p2(Y.brojnik),q1(X.nazivnik),q2(Y.nazivnik); // kopirano iz operator *
    int  r(Razlomak::NZD(std::abs(X.nazivnik),std::abs(Y.nazivnik))),u(std::abs(Razlomak::NZD (p1,p2))); // kopirano
    kolicnik.brojnik=Razlomak::Mnozenje((p1/u),(q2/r));
    kolicnik.nazivnik=Razlomak::Mnozenje((q1/r),(p2/u));
    kolicnik=Razlomak(kolicnik.brojnik,kolicnik.nazivnik);
    return kolicnik;
    
  }
  
  // SVE KOPIRANO   
  
    Razlomak operator - (Razlomak X) { if(X.brojnik == std::numeric_limits<long long int>::min()) throw std::overflow_error("Nemoguce dobiti tacan rezultat"); X.brojnik = -X.brojnik; return X; }   // vraća razlomak sa izvrnutim znakom
   
   Razlomak operator + (Razlomak Y) {return Y;} // vraća operand neizmjenjen
   
   
   Razlomak &operator ++ (Razlomak &X) {return X=operator + (Razlomak(1,1),X);} // DA LI JE OVO ISPRAVNO ?
   Razlomak operator ++ (Razlomak &X, int){Razlomak Y(X); X=operator +(Razlomak(1,1),Y); return Y;} // postfiksni
   Razlomak &operator --  (Razlomak &X) {return X=operator -(X,Razlomak(1,1));} // prefiksni
   Razlomak operator -- (Razlomak &X, int) {Razlomak Y(X); X=operator -(X,Razlomak(1,1)); return Y;}  // postfiksni
   
   // PROVJERITI
   
   bool operator < (Razlomak X,Razlomak Y)
   {
       long double p,q;
       p=(long double)X.brojnik/X.nazivnik;
       q=(long double)Y.brojnik/Y.nazivnik;
       if ( p<q) return true;  
       return false;
   }        
   bool  operator > (Razlomak X, Razlomak Y)
   {
       long double p,q;
       p=X.brojnik/X.nazivnik;
       q=Y.brojnik/Y.nazivnik;
       if (p>q) return true;
       return false;
   }
   bool operator <=(Razlomak X, Razlomak Y)
   {
       return X < Y || X == Y;
   }
   bool operator >=(Razlomak X, Razlomak Y)
   {
       return X > Y || X == Y;
   }
   
   
   bool operator == (Razlomak X,Razlomak Y)
   {
       long double p,q;
       p=X.brojnik/X.nazivnik;
       q=Y.brojnik/Y.nazivnik;
       long double eps(1e-15);
       if (std::fabs(p-q) < eps) return true;
       return false;
   }
   bool operator != (Razlomak X,Razlomak Y)
   {
    long double p,q;
       p=X.brojnik/X.nazivnik;
       q=Y.brojnik/Y.nazivnik;
       long double eps(1e-15);
      if (!(std::fabs(p-q) < eps)) return true;  
      return false;
   }
   std::ostream &operator << (std::ostream &tok,Razlomak X)
   {
       if (X.nazivnik==1) tok << X.brojnik;
       else tok << X.brojnik << "/"<< X.nazivnik;
       return tok;
       
   }
   std::istream &operator >> (std::istream &tok, Razlomak &X)
   {
        long long int brojnik(0), nazivnik(0);
        char znak(0);
        tok >> brojnik;
        tok >> znak;
        if(znak == '/')
        {
            tok >> nazivnik;
            tok >> znak;
            if(znak == ' ' || znak == '\n')
            {
                X = Razlomak(brojnik, nazivnik);
                return tok;
            }
            else
            {
                tok.setstate(std::ios::failbit);
                return tok;
            }
        }
        else if(znak == ' ' || znak == '\n')
        {
            X = Razlomak(brojnik, 1);
            return tok;
        }
        else
            tok.setstate(std::ios::failbit);
       return tok;
   }
   
  // neispravno stanje
  

int main ()
{
    Razlomak prvi(105,374), drugi(1267,1367);
    Razlomak treci(prvi + drugi);
    std::cout << treci << std::endl;
    Razlomak cetvrti(treci);
    if(treci == cetvrti)
        std::cout << "Jednaki su" << std::endl;
    else if(treci != cetvrti)
        std::cout << "Nisu jednaki" << std::endl;
    if(treci <= drugi)
        std::cout << "Drugi je veci od treceg" << std::endl;
    else if(treci > drugi)
        std::cout << "Treci je veci od drugog" << std::endl;
    ++++++treci;
    cetvrti++;
    ----drugi;
    prvi--;
    std::cout << -prvi << " " << +drugi << std::endl;
    std::cout << prvi * drugi << " " << prvi / drugi << " " << prvi - drugi << std::endl;
    Razlomak peti{12,14};
    std::cout << peti << std::endl;
    std::cout << Razlomak({5,3}) << " " << Razlomak() << std::endl;
	return 0;
}