#include <iostream>
#include <vector>
#include <cmath>

bool Prosti (int n)
{
	if (n==2)
		return true;
	if (n<0) n=-n;
	for (int i = 2; i<=sqrt(n); i++)
		if (n%i==0) return false;
	return true;
} // Da li je prost

bool Ternarni (int n)   // Da li je simetrican ternarni
{
	int ter(0),i(0);
	while (n>0) {            // Prebacivanje u ternarni
		ter+=(n%3)*pow(10,i);
		i++;
		n=n/3;
	}
	int obrnut(0),dummy(ter);
	for (int j =0; j<i; j++) {
		obrnut+=(dummy%10)*pow(10,i-j-1);
		dummy/=10;  // Dummy varijabla koja ima obrnute cifre od ter
	}
	if (obrnut==ter)  // Ako su iste true, nise false
		return true;
	return false;
}

std::vector<int> IzbaciIste (std::vector<int> v){   // Izbacuje iste ternanrne iz vektora
    
	for (int i = 0;i<v.size();i++)
		for (int j = i+1; j<v.size(); j++)
			if (v.at(i)==v.at(j)){
			v.erase(v.begin()+j);
			i--;
			break;
			}
	return v;
}

std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> V, bool logicka)  // logicka je true ako su prosti koje treba vratiti
{
	std::vector<int> v(IzbaciIste(V));
	std::vector<int> prosti,slozeni;
	for (int i : v) {
		if (Prosti(i) && Ternarni(i))
			prosti.push_back(i);
		if (!Prosti(i) && Ternarni(i))
			slozeni.push_back(i);
	}
	if (logicka)
		return prosti;
	return slozeni;
}

void Ispis (std::vector<int> ulaz)   //Ispis vektora
{
	for (int i =0; i<ulaz.size(); i++) {
		if (i==ulaz.size()-1)
			std::cout<<ulaz.at(i)<<".";
		else
			std::cout<<ulaz.at(i)<<", ";
	}
}

int main ()
{
	std::vector<int> ulaz;
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	int broj;
	// Unos elemenata
	do {
		std::cin>>broj;
		if (broj!=-1)
			ulaz.push_back(broj);
	} while (broj!=-1);
	std::cout <<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	// Mora biit ovako da bi mogao porediti sa 0 i 1
	int cijela_logicka;
	do {
		std::cin>>cijela_logicka;
		if (cijela_logicka!=0 && cijela_logicka!=1)
			std::cout<<"Neispravan unos! Unesite ponovo: ";
	} while (cijela_logicka!=0 && cijela_logicka!=1);
	bool logicka(cijela_logicka);
	if (logicka) {
		if (IzdvojiSimetricneTernarne(ulaz,logicka).size()==0)
			std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		else
			std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		Ispis(IzdvojiSimetricneTernarne(ulaz,logicka));
	} else {
		if (IzdvojiSimetricneTernarne(ulaz,logicka).size()==0)
			std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		else
			std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		Ispis(IzdvojiSimetricneTernarne(ulaz,logicka));
	}
	return 0;
}