#include <iostream>
#include <vector>
#include <cmath>
//Deklaracija kljucne rijeci Vektor koju cemo koristiti kao sinonim za std::vector<int> konstrukciju, tj za rad sa tipom vector
typedef std::vector<int> Vektor;

//Funkcija pomocu koje brojnu vrijednost pretvaramo iz decimalnog, u ternarni zapis, kako nalaze zadatak
//Funkcija je vrlo proste prirode, dijelimo proslijedjenu brojnu vrijednost brojem 3
//uzimamo ostatak te ga zapisujemo u pomocnu varijablu, naopakim redoslijedom, sto je bitno za napomenuti
bool DaLiSePojavio(Vektor v, int broj, int x){
	for(int i(0); i < x; i++){
		if(v.at(i) == broj) return true;
	}
	return false;
}

int UTernarnu(long long int broj)
{
	//Uvijek je dobro imati izvornu proslijedjenu vrijednost netaknutu i raditi sa temporalnim varijablamai
	int temp(broj);
	int ternarni(0), zapisi(0);
	int ostatak(0);
	//Sve dok je temporalna promjenljiva (sa proslijedjenom vrijednoscu) razlicita od nule tijelo petlje ce se izvrsavati
	while(temp != 0) {
		//dakle dijelimo temporalnu sa 3
		//pamtimo ostatak
		ostatak = temp % 3;
		//zapisujemo u drugu pomocnu varijablu
		zapisi = zapisi * 10 + ostatak;
		//dijelimo sa 3 u cilju daljnje konverzije
		temp/=3;
	}
	//Sada je temporalnoj varijabli dodijeljena vrijednost obrnuto zapisanog broja u ternarnoj bazi
	temp = zapisi;
	ostatak = 0;
	//Ponavljamo isti postupak kao i prethodno
	//s tim sto sada dijelimo sa brojem 10 jer nam nije u cilju promijeniti bazu, vec samo okrenuti broj
	while(temp != 0) {
		ostatak = temp % 10;
		ternarni = ternarni * 10 + ostatak;
		temp/=10;
	}
	//Naposlijetku vracamo ispravno pretvoren broj iz decimalnog u ternarni zapis
	return ternarni;
}

//Identicna funkcija koju smo izradili na jednom od prethodnih tutorijala
//Provjeravamo da li je proslijedjeni broj prost ili slozen, te vracamo true ili false, respektivno
//Dodatni komentar: daljna optimizacija funkcije, sem one da petlja ide do kvadr. korijena broja, bi se mogla implementirati
//U smislu da odmah provjerimo da li je uneseni broj <= 3 vratimo n > 1, provjerimo njegovu djeljivost sa 2 i 3, te u for petlji
//koja slijedi preskocimo sve djelioce ciji su faktori 2 i 3, a u istom koraku provjeramo medju-vrijednosti (npr djeljivost brojem 7)
//Medjutim, ovo je bilo dovoljno optimizovano na tutu, nadam se da je i ovdje
bool DaLiJeProst(int n)
{
	if(n <= 1) {
		return false;
	} else {
		for(int i(2); i <= std::sqrt(n); i++) {
			if(n % i == 0) {
				return false;
			}
		}
		return true;
	}
}

//Funkcija pomocu koje provjeravamo da li je broj u ternarnom zapisu proslijedjen funkciji simetrican
//tj cifre sa lijeve i desne strane su mu identicne, Npr. 22122
//Funkcija radi na principu da proslijedjenu vrijednost ne mijenjamo, vec je dodjeljujemo temporalnoj varijabli,
//okrecemo bas kao sto smo to uradili u UTernarnu funkciji, te naposlijetku poredimo sa prvobitnom vrijednoscu i vracamo odgovorajucu vrijednost
bool JeLiSimetrican(int broj)
{
	int temp(broj), poredbeni(0), ostatak(0);
	while(temp != 0) {
		ostatak = temp % 10;
		poredbeni = poredbeni * 10 + ostatak;
		temp/=10;
	}
	return abs(broj) == abs(poredbeni);
}

//Glavna funkcija koja operira uz pomoc pomocnih funkcija izradjenih iznad nje
//Prvo se poziva funkcija DaLiJeProst i provjerava kompatibilnost njenog rezultata sa istinosnom vrijednoscu proslijedjenoj funkciji
//Dakle, oni brojevi za koje funkc. DaLiJeProst vrati odgovarajuci argument koji je definiran u Istinosna_var, a koji je unesen od strane korisnika i proslijedjen iz maina
//bit ce uzeti u obzir i za njih ce se provjeriti da li su simetricni ili ne uz pomoc JeLiSimetrican funkcije
//Naravno, funkciji JeLiSimetrican saljemo efekat funkcije UTernarnu, s obzirom da trebamo raditi sa brojevima u ternarnom zapisu
//Ukoliko oba uslova bivaju zadovoljena, dati element vektora se upisuje u pomocni vektor, koji ce naposlijetku i biti vracen iz funkc.
Vektor IzdvojiSimetricneTernarne(Vektor v, bool Istinosna_var)
{
	Vektor Sim_ter;
	for(int i(0); i < v.size(); i++) {
		//Ako je DaLiJeProst = false, a i Istinosna_var = false, uzimat ćemo slozene brojeve i obratno
		if(DaLiJeProst(abs(v.at(i))) == Istinosna_var && !(DaLiSePojavio(v, v.at(i), i)) && JeLiSimetrican(UTernarnu(v.at(i)))) {
			Sim_ter.push_back(v.at(i));
		}
	}
	return Sim_ter;
}

//Funkcija za unos vektora, beskonacna petlja tece sve dok se ne unese vrijednost -1, a sve prethodne vrijednosti pravovremeno se ubacuju u vektor
Vektor UnesiVektor()
{
	Vektor unosVektor;
	for(;;) {
		int broj(0);
		std::cin >> broj;
		if(broj == -1) break;
		unosVektor.push_back(broj);
	}
	return unosVektor;
}

//Funkcija za ispis vektora koja ga ujedno i pravilno formatira
void IspisiVektor(Vektor v4)
{
	for(int i(0); i < v4.size(); i++) {
		std::cout << v4[i];
		if(i != v4.size() - 1) std::cout << ", ";
	}
	std::cout << ".";
}

int main ()
{
	//Deklarisanje vitalnih varijabli
	int logicka(0);
	//Unos podataka neophodnih za ispravno funkcionisanje programa
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	Vektor v1(UnesiVektor());
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	//Osiguravamo da je unos podataka ogranicen na vrijednosti 0 i 1
	do {
		std::cin >> logicka;
		if(logicka < 0 || logicka > 1) std::cout << "Neispravan unos! Unesite ponovo: ";
	} while(logicka < 0 || logicka > 1);
	//Ispisivanje odgovarajucih poruka ukoliko je vraceni vektor prazan
	if(logicka == true && IzdvojiSimetricneTernarne(v1, logicka).size() == 0) std::cout << "Nema prostih simetricnih brojeva u vektoru.";
	else if(logicka == false && IzdvojiSimetricneTernarne(v1, logicka).size() == 0) std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
	//Ukoliko korisnik unese 1, trazit ce se i u konacnici ispisati prosti simetricni ternarni brojevi, u suprotnom trazit ce se i ispisati slozeni
	else {
		if(logicka == true) std::cout << "Prosti simetricni brojevi iz vektora su: ";
		else std::cout << "Slozeni simetricni brojevi iz vektora su: ";
		IspisiVektor(IzdvojiSimetricneTernarne(v1, logicka));
	}


	return 0;
}