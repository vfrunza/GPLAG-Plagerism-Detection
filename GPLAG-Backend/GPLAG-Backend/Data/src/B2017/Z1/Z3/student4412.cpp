#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

typedef std::vector<int> IntVektor;
typedef std::deque<IntVektor> DekVektora;										//uvodimo deque ciji su elementi vektori cijelih brojeva
enum Smjer {Rastuci, Opadajuci};

bool StepenDvojke (int x)   													//fja koja provjerava da li je poslani broj stepen dvojka
{
	if(x==1) return true;														//vraca logicku vrijednost: true ili false
	if(x==0) return false;
	do {
		if(x%2!=0) return false;
		x/=2;
	} while(x!=1);
	return true;
}

DekVektora OpadajuciPodnizovi (IntVektor v)										
{
	DekVektora trazeni_dek (0, IntVektor(0));
	IntVektor pomocni(0);
	v.push_back(1000000);														//dodajemo jako veliki broj koji ce biti pomocni
	for(int i=0; i<v.size(); i++) {
		if(v.at(i)!=1000000 && v.at(i)>=v.at(i+1) && StepenDvojke(v.at(i)))
			pomocni.push_back(v.at(i));
		else {
			if(pomocni.size()!=0) {
				if(StepenDvojke(v.at(i))) pomocni.push_back(v.at(i));
				if(pomocni.size()!=1) trazeni_dek.push_back(pomocni);			//jedan pronadjeni opadajuci podniz/vektor se smjesta u dek
			}
			pomocni.resize(0);
		}
	}
	return trazeni_dek;
}

DekVektora RastuciPodnizovi (IntVektor v)
{
	DekVektora trazeni_dek (0, IntVektor (0));
	IntVektor pomocni(0);
	v.push_back(-1000000);														//dodaje se jako mali broj na kraj vektora
	for(int i=0; i<v.size(); i++) {
		if(v.at(i)!=-1000000 && v.at(i)<=v.at(i+1) && StepenDvojke(v.at(i)))
			pomocni.push_back(v.at(i));
		else {
			if (pomocni.size()!=0) {
				if(StepenDvojke(v.at(i))) pomocni.push_back(v.at(i)); 			
				if(pomocni.size()!=1) trazeni_dek.push_back(pomocni);			//rastuci podniz/vektor se dodaje u dek
			}
			pomocni.resize(0);
		}
	}
	return trazeni_dek;
}

DekVektora MaksimalniPodnizoviStepenaDvojke(IntVektor v, Smjer x)				//trazena fja poziva vise pomocnih fja
{
	DekVektora rezultat;
	if(x==0) rezultat=RastuciPodnizovi(v);
	else rezultat=OpadajuciPodnizovi(v);
	return rezultat;
}


int main ()
{
	std::cout<<"Unesite broj elemenata vektora: ";								//unos broja elemenata
	int broj_elemenata;
	std::cin>>broj_elemenata;

	std::cout<<"Unesite elemente vektora: ";
	IntVektor uneseni_vektor(0);
	for(int i=0; i<broj_elemenata; i++) {										//unos elemenata
		int unos;
		std::cin>>unos;
		uneseni_vektor.push_back(unos);
	}

	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int x;
	std::cin>>x;
	Smjer zadani_tok(Smjer(x-1));

	DekVektora rezultat
		(MaksimalniPodnizoviStepenaDvojke(uneseni_vektor, zadani_tok));

	if(x==1)
		std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	else
		std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;

	for(int i=0; i<rezultat.size(); i++) {										//ispis deka vektora
		for(int j=0; j<rezultat.at(i).size(); j++)
			std::cout<<rezultat.at(i).at(j)<<" ";
		std::cout<<std::endl;
	}

	return 0;
}