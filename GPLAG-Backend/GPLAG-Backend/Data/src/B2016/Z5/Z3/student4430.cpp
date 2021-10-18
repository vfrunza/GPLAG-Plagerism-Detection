/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <sstream>
using namespace std; 
class Razlomak{
	long long int p, q; 
	static long long int NZD(long long int p, long long int q){
		if(q==0) return p; 
		return 	NZD(q, p%q); 
	}
	static void Skrati(long long int &p, long long int &q){
		int broj=NZD(p,q); 
		if(broj!=1){
		p=p/broj; 
		q=q/broj; 
		}
		return ; 
	}
public: 
	Razlomak(long long int p, long long int q){
		if(q==0) throw logic_error ("Nekorektan razlomak"); 
		if(q<0){
			q=-q; 
			p=-p; 
		}
		Skrati(p,q); 
		Razlomak::q=q; 
		Razlomak::p=p; 
	}
	Razlomak(long long int p){
		Razlomak::p=p; 
		q=1; 
	}
	Razlomak(){
		p=0; 
		q=1; 
	}
	long long int DajBrojnik() const{
		return p; 
	}
	long long int DajNazivnik() const{
		return q; 
	}
	friend Razlomak operator+ (const Razlomak prvi, const Razlomak drugi){
		int r=NZD(prvi.q, drugi.q); 
		Razlomak izlaz; 
		izlaz.p=prvi.p*(drugi.q/r)+drugi.p*(prvi.q/r); 
		izlaz.q=prvi.q*(drugi.q/r); 
		Skrati(izlaz.p, izlaz.q); 
		return izlaz; 
	}
	friend ostream &operator << (ostream &tok, const Razlomak &razlomak){
		if(razlomak.q==1)
			tok << razlomak.p; 
		else if(razlomak.p==0)
			tok << "0"; 
		else
			tok << razlomak.p << "/" << razlomak.q; 
		return tok; 
 	}
 	friend istream &operator >> (istream &tok, Razlomak &razlomak){
 		
 		char znak;
 		long long int brojnik, nazivnik; 
 			 
 		tok >> ws; 
 		tok >> brojnik; 
 		if(tok.peek()!='/'){
 			razlomak.p=brojnik;
 			razlomak.q=1; 
		return tok; 
 		}
 		tok >> znak; 
 		if(znak!='/'){
 			tok.setstate(ios::failbit); 
 		}
 		tok >> nazivnik; 
 		if(tok.peek()!='\n') tok.setstate(ios::failbit); 
 		Skrati(brojnik, nazivnik); 
 		razlomak.p=brojnik; 
 		razlomak.q=nazivnik; 
 		return tok; 
 	}
	friend Razlomak operator- (const Razlomak prvi, const Razlomak drugi){
		long long int r=NZD(prvi.q, drugi.q); 
		 
		Razlomak izlaz; 
		izlaz.p=prvi.p*(drugi.q/r)-drugi.p*(prvi.q/r); 
		izlaz.q=prvi.q*(drugi.q/r); 
		Skrati(izlaz.p, izlaz.q); 
		return izlaz; 
	}
	friend Razlomak operator *(const Razlomak prvi, const Razlomak drugi){
		long long int s=NZD(prvi.p, drugi.q); 
		long long int t=NZD(drugi.p, prvi.q); 
		Razlomak izlaz; 
		izlaz.p=(prvi.p/s)*(drugi.p/t); 
		izlaz.q=(prvi.q/t)*(drugi.q/s); 
		Skrati(izlaz.p, izlaz.q); 
		return izlaz; 
	}
	friend Razlomak operator /(const Razlomak prvi, const Razlomak drugi){
		long long int r=NZD(prvi.q, drugi.q); 
		long long int u=NZD(prvi.p, drugi.p); 
		Razlomak izlaz; 
		izlaz.p=(prvi.p/u)/(drugi.q/r); 
		izlaz.q=(prvi.q/r)/(drugi.p/u); Skrati(izlaz.p, izlaz.q); 
		return izlaz; 
	}
};
int main ()
{
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
	return 0;
}