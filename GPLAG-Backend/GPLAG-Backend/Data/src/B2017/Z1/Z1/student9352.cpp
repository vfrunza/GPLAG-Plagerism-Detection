/*B 2017/2018, Zadaća 1, Zadatak 1

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.
*/


#include <iostream>
#include <vector>
#include <cmath>

bool DaLiJeProstBroj(int n)
{
	if(n<=1) return false;
	for(int i=2; (unsigned int)(i*i)<=n; i++) if(n%i==0) return false;
	return true;
}

std::vector <int> IzdvojiSimetricneTernarne(std::vector <int> v,bool Tacnost)
{

	//Izdvajanje prostih ili slozenih brojeva iz vektora poslanog u funkciju u zavisnosti od tacnosti parametra Tacnost
	std::vector <int> MojVektor;
	if(Tacnost==0) {

		for(int i=0; i<v.size(); i++) {
			if(v.at(i)==1) {
				MojVektor.push_back(v.at(i));
				continue;
			}
			if((!DaLiJeProstBroj(fabs(v.at(i))))) MojVektor.push_back(v.at(i));
		}

	} else if(Tacnost==1) {

		for(int i=0; i<v.size(); i++)	if(DaLiJeProstBroj(fabs(v.at(i)))) MojVektor.push_back(v.at(i));

	}

	//Pretvaranje clan po clan u ternarni broj i provjera da li je simetrican
	std::vector <int> Vektor1;
	std::vector<int> Vektor2;
	std::vector <int> Trazeni;
	std::vector <int> Prazni(0);

	for(int i=0; i<MojVektor.size(); i++) {

		Vektor1=Prazni;
		Vektor2=Prazni;
		unsigned int temp=fabs(MojVektor.at(i));
		while(temp>0) {
			Vektor1.push_back(temp%3);
			temp=temp/3;
		}

		for(int j=Vektor1.size()-1; j>=0; j--) {
			Vektor2.push_back(Vektor1.at(j));
		}
		if(Vektor1==Vektor2) Trazeni.push_back(MojVektor.at(i));

	}

	for(int i=0; i<Trazeni.size(); i++) {
		for(int j=i+1; j<Trazeni.size(); j++) {
			if(Trazeni.at(i)==Trazeni.at(j)) {
				Trazeni.erase(Trazeni.begin()+j);
				j--;
			}
		}
	}
	return Trazeni;

}

int main ()
{
	std::vector <int> Vektor;
	int unos_elemenata;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	do {
		std::cin>>unos_elemenata;
		if(unos_elemenata!=-1) Vektor.push_back(unos_elemenata);
	} while(unos_elemenata!=-1);

	int UnosTacnosti;
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	do {
		std::cin>>UnosTacnosti;

		if(UnosTacnosti!=0 && UnosTacnosti!=1) std::cout<<"Neispravan unos! Unesite ponovo: ";
	} while(UnosTacnosti!=0 && UnosTacnosti!=1);

	std::vector <int> Rezultat(IzdvojiSimetricneTernarne(Vektor,UnosTacnosti));
	if(Rezultat.size()==0 && UnosTacnosti==1) {
		std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		return 0;
	}
	if(Rezultat.size()==0 && UnosTacnosti==0) {
		std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		return 0;
	}
	if(UnosTacnosti==1) std::cout<<"Prosti simetricni brojevi iz vektora su: ";
	else std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
	for(int i=0; i<Rezultat.size(); i++) {
		std::cout<<Rezultat.at(i);
		if(i<Rezultat.size()-1) std::cout<<", ";
		else std::cout<<".";
	}

	return 0;
}