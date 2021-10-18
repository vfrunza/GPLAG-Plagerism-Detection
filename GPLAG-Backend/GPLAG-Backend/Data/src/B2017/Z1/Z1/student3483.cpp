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

int DaLiJeProst(int n)
{
	if(n==1 || n==-1) return 2;
	if(n==0) return 0;
	if(n<-1) n*=(-1);
	for(int i=2; i<=std::sqrt(n); i++) {
		if(n%i==0) return 0;
	}

	return 1;
}

//Izbacujemo brojeve koji nisu zahtjevanog tipa
std::vector<int> Tip(std::vector<int> v, bool tip)
{
	if(tip) {
		for(int i=0; i<v.size(); i++) {
			if(DaLiJeProst(v.at(i))==2 || DaLiJeProst(v.at(i))==0) {
				v.erase(v.begin()+i);
				i--;
			}
		}
	} else {
		for(int i=0; i<v.size(); i++) {
			if(DaLiJeProst(v.at(i))==2 || DaLiJeProst(v.at(i))==1) {
				v.erase(v.begin()+i);
				i--;
			}
		}
	}

	return v;
}

std::vector<int> IzbaciIste(std::vector<int> v)
{
	for(int i=0; i<v.size(); i++) {
		for(int j=i+1; j<v.size(); j++) {
			if(v.at(i)==v.at(j)) {
				v.erase(v.begin()+j);
				j--;
			}
		}
	}

	return v;
}

//Pretvaramo brojeve u ternarne 
std::vector<int> UTernarne(std::vector<int> v)
{
	std::vector<int> vec(v.size());

	for(int i=0; i<v.size(); i++) {
		int cifra, j(0), pom;
		bool negativan(false);

		if(v.at(i)<-1) {
			pom=(-1)*v.at(i);
			negativan=true;
		} else pom=v.at(i);

		while(pom!=0) {
			cifra=pom%3;
			pom/=3;
			vec.at(i)+=cifra*pow(10,j);
			j++;
		}

		if(negativan) vec.at(i)*=(-1);
	}

	return vec;
}

int BrojCifara(int broj)
{
	int duz(0);
	while(broj!=0) {
		broj/=10;
		duz++;
	}

	return duz;
}

int ObrniBroj(int broj)
{
	int pom(0);
	while(broj!=0) {
		pom=pom*10+broj%10;
		broj/=10;
	}

	return pom;
}

//Provjeravamo da li su elementi vektora simetricni, oni koji nisu izbacujemo ih
std::vector<int> Simetricni(std::vector<int> v)
{
	std::vector<int> vec=std::move(UTernarne(v));

	for(int i=0; i<v.size(); i++) {
		int duz=BrojCifara(vec.at(i));
		int prvi_dio, drugi_dio;

		if(duz%2!=0) {
			int duz1(duz/2);
			prvi_dio=vec.at(i)/pow(10,duz1+1);
			drugi_dio=vec.at(i)%int(pow(10,duz1));
		} else {
			int duz1(duz/2);
			prvi_dio=vec.at(i)/pow(10,duz1);
			drugi_dio=vec.at(i)%int(pow(10,duz1));
		}

		if(drugi_dio!=ObrniBroj(prvi_dio)) {
			v.erase(v.begin()+i);
			vec.erase(vec.begin()+i);
			i--;
		}
	}


	return v;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v, bool tip)
{
	if(tip) {
		std::vector<int> v_prosti;

		v_prosti=std::move(Tip(v,tip)); 			 //Izbacuje sve slozene
		v_prosti=std::move(IzbaciIste(v_prosti));	 //Izbacuje iste
		v_prosti=std::move(Simetricni(v_prosti));	 //Provjerava da li su simetricni i izbacuje ako nisu

		return v_prosti;
	} else {
		std::vector<int> v_slozeni;

		v_slozeni=std::move(Tip(v,tip));			  //Izbacuje sve proste
		v_slozeni=std::move(IzbaciIste(v_slozeni));
		v_slozeni=std::move(Simetricni(v_slozeni));

		return v_slozeni;
	}
}

int main ()
{
	std::vector<int> v;
	int broj, tip;

	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	std::cin >> broj;
	while(broj!=-1) {
		v.push_back(broj);
		std::cin >> broj;
	}

	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	std::cin >> tip;
	while(tip!=0 && tip!=1) {
		std::cout << "Neispravan unos! " << "Unesite ponovo: ";
		std::cin >> tip;
	}

	if(tip==1) {
		std::vector<int> v1=std::move(IzdvojiSimetricneTernarne(v,true));
		if(v1.size()!=0) {
			std::cout << "Prosti simetricni brojevi iz vektora su: ";
			for(int i=0; i<v1.size(); i++) {
				if(i!=v1.size()-1) std::cout << v1.at(i) << ", ";
				else std::cout << v1.at(i) << ".";
			}
		} else std::cout << "Nema prostih simetricnih brojeva u vektoru.";
	} else {
		std::vector<int> v1=std::move(IzdvojiSimetricneTernarne(v,false));
		if(v1.size()!=0) {
			std::cout << "Slozeni simetricni brojevi iz vektora su: ";
			for(int i=0; i<v1.size(); i++) {
				if(i!=v1.size()-1) std::cout << v1.at(i) << ", ";
				else std::cout << v1.at(i) << ".";
			}
		} else std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
	}

	return 0;
}
