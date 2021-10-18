/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <sstream>
#include <string>
class Razlomak{
  long long int brojnik, nazivnik;
  public:
  Razlomak(long long int b, long long int n)  {
    brojnik=b;
    nazivnik=n;
    if(brojnik>0 && nazivnik<0){
      brojnik=brojnik*(-1);
      nazivnik=nazivnik*(-1);
    }
    if(brojnik<0 && nazivnik<0){
      brojnik=brojnik*(-1);
      nazivnik=nazivnik*(-1);
    }
    if(brojnik>0 && nazivnik>0){
    int modul=brojnik%nazivnik;
      int konacno=nazivnik-modul;
      if(konacno>0){
          brojnik=brojnik/konacno;
          nazivnik=nazivnik/konacno;
      }
     
  }
      
  }
  Razlomak(long long int broj ){
    brojnik=broj;
    nazivnik=1;
  }
  Razlomak(){
    brojnik=0;
    nazivnik=0;
  }
  friend std::ostream &operator <<(std::ostream &tok, const Razlomak&r){
    if(r.brojnik>0 && r.nazivnik>1){
    return tok<<r.brojnik<<"/"<<r.nazivnik;
    }
    if(r.brojnik>0 && r.nazivnik==1){
      return tok<<r.brojnik;
    }
    if(r.brojnik==0 && r.nazivnik==0){
      return tok<<r.brojnik;
    }
   
    
     return tok;
  
  }
  friend std::istream & operator >>(std::istream &tok,  Razlomak &r){
   /*  long long int brojnik(const Razlomak &r) {return r.brojnik;}
    long long int nazivnik(const Razlomak &r) {return r.nazivnik;}*/
  
    
    if(tok.peek()=='\n'){
        return tok>>r.brojnik>>r.nazivnik;
    }
    if(tok.peek()=='\r'){
        return tok;
    }
    if(tok.peek()=='\f'){
        return tok;
    }
    if(tok.peek()=='\v'){
        return tok;
    }
    if(tok.peek()=='\t'){
        return tok;
    }
    
   else{
    return tok>>r.brojnik; return tok>>r.nazivnik;
   }
   
  }
 
  };
int main ()
{
        {//AT3 (c9): operator >> (1/3) ...
     //NAPOMENA: najlogicnija izvedba op>> ce proci
     //ove ATove. Dodatne izvedbe su nelogicne i nisu u skladu
     //sa ostaim tipovima...

     //ovdje cu koristiti specijalnu klasu (ne radi se naB
     //da preko stringa simuliram ulaz
     //cisto da se vide viska razmaci

     //NAPOMENA: pod "razmakom" se smatra SVAKI znak koji je BJELINA
     //odnosno ovih 6 znakova u en-US:
     //      \n, |r, \f, \v, \t, ' '
     // i |r je sa backshashom, ali zbog buga pisem |r. Znaci, i \R (samo malo r)
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


     is.str ("173/51\n  ne zanima nas sta je nakon     "); //ispravno
     is.clear();
     is >> r; //sljedece citanje bi bilo neispravno
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
     is.str (" 1/3   5/7  4/2    nebitno"); //ispravna prva 3
     is.clear();
     is >> r >> q >> t;
     std::cout << "r = " << r << ", q = " << q << ", t = " << t;

     //dosta testova :whew:
    }
    
	return 0;
}