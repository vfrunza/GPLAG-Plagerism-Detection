#include <iostream>
#include <vector>
#include <cmath>

bool DaLiJeProst(int x) { //kao eto radi za negativne ali ne uzimaj ti to k srcu previse jer postoji mogucnost da si ti to bas zeznula nesto
	if(x==1 || x==0 || x==-1) return false; 
	long long int novi(x); 
	novi=x; //ovo si kao eto rijesila a vjerovatno nisi, razmotri ti neke nove stvari tu jer ovo skoro pa je cheating
	if(novi<0) novi=(-1)*(novi); 
	for(unsigned int i=2; i<=sqrt(novi); i++) //ovo ti moze stvoriti problem radi opsega integera mozda
	if(novi%i==0) return 0; 
	return 1; 
} 

std::vector<int> UTetrarneVektore(int x) { //ona ce ti raditi i iako je negativan ja mislim jer uzimas ovo abs pa ce ono uvijek biti ok 
	std::vector<int> rezultat; 
	// ako je x nula neka ti vrati samo vektor od jednog elementa koji je nuli

	while (x) { //jel ovo false kada je negativan broj ili kako to ide dunno
	
		rezultat.push_back(abs(x%3)); 
		x=x/3; 
		}
	return rezultat; 
}

//std::vector<int> ObrniVektor(std::vector<int> v) { //mozda ti ovdje i ne treba ova funkcija vec samo provjeri simetriju lijepo nemoj biti debil pa komplicirati stvari kao sto imas naviku 
//	std::vector<int> rezultat;
//	if(v.size()==0 || v.size()==1) return v; //ako mi posalje prazan vektor po nekoj logici vratim mu prazan vektor ili ako mi posalje jednoclan vektor 
//	for(int i=v.size()-1; i>=0; --i) 
//	rezultat.push_back(v.at(i)); 
//	return rezultat;
//}

bool DaLiJeSimetrican(int x) { //ovo eventualno izmijeni da krenes s dvije petlje jedna od kraja jedna s pocetka i da se nadju na sredini i da tako provjeravas da li je isto kao recimo sto si radila za one stringove nekada a mislim da ti je to efikasnije u svakom slucaju, na taj nacin ti ne treba ni obrtati vektor niti ista od tog dijela sto si pisala 
	std::vector<int> taj_vektor(UTetrarneVektore(x));
//	std::vector<int> obrnuti(ObrniVektor(taj_vektor)); 
//	if(taj_vektor==obrnuti) return true; 
//	return false;
	if(taj_vektor.size()==0 || taj_vektor.size()==1) return true; 
	int j=0; 
	for(int i=taj_vektor.size()-1; i>=taj_vektor.size()/2; i--) {
		if(taj_vektor.at(i)!=taj_vektor.at(j)) return false; 
		j++; 
	}
	return true; 
}

int IzVektorUInt(std::vector<int> v) {
	int rezultat(0); 
	for(unsigned int i=0; i<v.size(); i++)
	rezultat=rezultat+v.at(i)*pow(10, v.size()-1-i); 
	
	return rezultat; 
}

bool DaLiJeBio(std::vector<int> v, int x) {
	if(v.size()==0) return false; 
	for(int i=0; i<v.size(); i++)
	if(v.at(i)==x) return true; 
	return false; 
}
//napravifunkciju dalijebio koja prima vektor integera i integer taj neki i onda tako ces to mozda lakse nego da brises, mozda je efektivnije 

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v, bool t) {
	std::vector<int> simetricni; 
	for(unsigned int i=0; i<v.size(); i++) {
		if((t && DaLiJeProst(v.at(i))) || (!t && !DaLiJeProst(v.at(i)))) {
			if(DaLiJeSimetrican(v.at(i)) && !DaLiJeBio(simetricni, v.at(i))) simetricni.push_back(v.at(i));
		}
	}
	
	return simetricni; 
}

int main ()
{
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	std::vector<int> a; 
	while(1) {
		int x; 
		std::cin >> x;  // ovdje uradi onu lijepu provjeru za unos ovih intova jel uopce unijeo integere i tako to
		if(x==-1) break; 
		a.push_back(x); 
	}
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int nesto; //neka ti nesto bude double pa uradi onu lijepu provjeru
	std::cin >> nesto; 
	if(nesto!=0 && nesto!=1) {
		std::cout << "Neispravan unos! Unesite ponovo: "; 
	//	std::cin.ignore(1000, '\n'); zasto ovo kada nije u komentaru ne radi, i dont seem to understand it zb
		std::cin >> nesto; 
	}

	std::vector<int> asja(IzdvojiSimetricneTernarne(a, nesto)); 
	if(asja.size()==0)  {
		if(nesto==1) 
	std::cout << "Nema prostih simetricnih brojeva u vektoru.";
	else std::cout << "Nema slozenih simetricnih brojeva u vektoru."; }
	else {
		if(nesto==1) std::cout << "Prosti simetricni brojevi iz vektora su: ";
		else std::cout << "Slozeni simetricni brojevi iz vektora su: "; 
		for(int i=0; i<asja.size(); i++) {
		if(i==asja.size()-1) std::cout << asja.at(i) << "."; 
		else
		std::cout << asja.at(i) << ", "; }
	}
	
	return 0;
}