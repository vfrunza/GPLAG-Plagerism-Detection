#include <iostream>
#include <cmath>
#include <vector>
#include <deque>

bool DaLiJeProst (int SiliP)
{   
	if (SiliP<2) {
		return 1;
	} else {
		for (int s(2); s<=std::sqrt(SiliP); s++) {
			if (SiliP%s==0) return 0;
		}
	}
	return 1;
}

int DecimalToTernary (int Dec)
{
	int temp_1(0), Ter(0), n(0);
	while (Dec!=0) {
		temp_1=Dec%3;
		Dec/=3;
		Ter+= (std::pow (10, n++)*temp_1);
	}
	return Ter;
}

int ProvjeraSimetrije (int Decimal)
{
	int temp_0=DecimalToTernary(Decimal), vel(0),ParNepar(0);
	int temp_1=temp_0;
	//Prebroji cifre u broju
	while (temp_0!=0) {
		temp_0/=10;
		vel++;
	}
	//Ako je broj neparan postavi ParNepar na 1, ako je velicina broja manja od 2 vrati 0
	if (vel<2) return 0;
	if (vel%2==1) ParNepar=1;
	int sredina=(vel+ParNepar)/2;
	//Incijalizovana su dva deque kojim ces provjeriti simetricnost broja u ternarnom zapisu
	std::deque<int> d1;
	std::deque<int> d2;
	int pam(0);
	//Cifre s desne strane (kod parnih cifre desne polovine broja, kod neparnih cifre desno od sredine) smjesti u deque
	for (int j(0); j<sredina-ParNepar; j++) {
		pam=temp_1%10;
		d1.push_front(pam);
		temp_1/=10;
	}
	//Ukoliko je broj neparan ukloni mu sredinu
	if (ParNepar==1) temp_1=temp_1/10;
	//Smjesti preostale lijeve cifre u deque
	for (int k(0); k<sredina-ParNepar; k++) {
		pam=temp_1%10;
		d2.push_back(pam);
		temp_1/=10;
	}
	//Ako su deque-ovi jednaki (broj je simetrican) vrati tacno
	if (d1==d2) return 1;
	return 0;
}

std::vector<int> IzdvojiSimetricneTernarne (std::vector <int> Dec, bool S_P)
{
	int prost(0),simetrican(0);
	for (int i(0); i<Dec.size(); i++) {
		prost=DaLiJeProst(Dec.at(i));
		simetrican=ProvjeraSimetrije(Dec.at(i));
		if (S_P!=prost || !(simetrican)) {
			Dec.erase (Dec.begin()+i);
			i--;
		}
	}
	return Dec;
}

int main (void)
{
	int unos(0);

	std::vector<int> a;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	do {
		std::cin>>unos;
		if (unos!=-1) {
			a.push_back (unos);
		}
		if (!std::cin) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout<<"Neispravan unos! Unesite ponovo: ";
		}
	} while (unos!=-1);

	unos=0;
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	std::cin>>unos;
	while(unos!=0  && unos!=1) {
		std::cin>>unos;
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout<<"Neispravan unos! Unesite ponovo: ";
	}
	std::vector<int> VraceniVektor=IzdvojiSimetricneTernarne(a,unos);

	if (unos==1) {
		if (VraceniVektor.size()!=0) {
			std::cout<<"Prosti simetricni brojevi iz vektora su: "<<VraceniVektor[0];
			for (int i(1); i<VraceniVektor.size(); i++) {
				std::cout<<", "<<VraceniVektor.at(i);
			}
		} else {
			std::cout<<"Nema prostih simetricnih brojeva u vektoru";
		}
	}

	if (unos==0) {
		if (VraceniVektor.size()!=0) {
			std::cout<<"Slozeni simetricni brojevi iz vektora su: "<<VraceniVektor[0];
			for (int i(1); i<VraceniVektor.size(); i++) {
				std::cout<<", "<<VraceniVektor.at(i);
			}
		} else {
			std::cout<<"Nema slozenih simetricnih brojeva u vektoru";
		}
	}
	std::cout<<"."; 
	return 0;
}
