#include <iostream>
#include <vector>
#include <cmath>

bool ProstBroj (int n)   														//fja koja provjerava da li je broj prost ili slozen
{
	if (n<2) return false;
	for(int i=2; i<=std::sqrt(n); i++)
		if(n%i==0) return false;
	return true;
}

bool SimetricniBroj (long long int n)  											//fja koja provjerava da li je broj palindrom
{
	long long int n1(n), novi_broj(0);
	do {
		novi_broj=(novi_broj+n1%10)*10;
		n1/=10;
	} while (n1!=0);
	if(novi_broj/10==n) return true;
	else return false;
}

long long int TernarniZapis (int n)  											//zapisivati cu ostatke, pa okrenuti broj
{
	long long int rez_naopako(0), rezultat(0);
	while(n>=3) {
		rez_naopako=(rez_naopako+n%3)*10;
		n/=3;
	}
	rez_naopako+=n;
	do {
		rezultat=(rezultat+rez_naopako%10)*10;
		rez_naopako/=10;
	} while (rez_naopako!=0);
	return rezultat/10;
}

std::vector <int> BrisanjePonavljanja (std::vector <int> v)   					//fja izbacuje iz vektora elemente koji se ponavljaju
{
	for(int i=0; i<v.size(); i++) {
		for(int j=i+1; j<v.size(); j++)
			if(v.at(i)==v.at(j)) {
				v.erase(v.begin()+j);
				j--;
			}
	}
	return v;
}

std::vector<int> IzdvojiSimetricneTernarne (std::vector <int> v, bool a)
{
	std::vector<int> rezultat(0);
	for(int x: v) { 															//true-prosti brojevi
		if(a && ProstBroj(x) && SimetricniBroj(TernarniZapis(std::abs(x))))		//svaki element se provjerava
			rezultat.push_back(x);												//ako su uslovi zadovoljeni, on se smjesta i u rezultantni vektor
		else if (a==false && ProstBroj(x)==false
		         && SimetricniBroj(TernarniZapis(std::abs(x))))
			rezultat.push_back(x);
	}
	rezultat=BrisanjePonavljanja(rezultat);										//pozivanjem fje se brisu suvisna ponavljanja
	return rezultat;
}


int main ()
{
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";

	std::vector<int> uneseni_vektor(0);
	for(;;) {																	//unos elemenata
		int broj;
		std::cin>>broj;
		if(broj!=-1) uneseni_vektor.push_back(broj);
		else break;
	}

	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int x;
	for(;;) {																	//provjeravamo da li je unesen jedan od dva broja koja ocekujemo
		std::cin>>x;
		if(x==0 || x==1) break;
		else std::cout<<"Neispravan unos! Unesite ponovo: ";
	}

	auto trazeni_vektor(IzdvojiSimetricneTernarne(uneseni_vektor, x));
	if(x==1) {
		if(trazeni_vektor.size()==0)
			std::cout<<"Nema prostih simetricnih brojeva u vektoru";
		else
			std::cout<<"Prosti simetricni brojevi iz vektora su: ";
	} else {
		if(trazeni_vektor.size()==0)
			std::cout<<"Nema slozenih simetricnih brojeva u vektoru";
		else
			std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
	}

	for(int i=0; i<trazeni_vektor.size(); i++) {								//ispis elemenata vektora, tako da su razdvojeni zarezom
		std::cout<<trazeni_vektor.at(i);
		if(i!=trazeni_vektor.size()-1) std::cout<<", ";
	}
	std::cout<<".";

	return 0;
}