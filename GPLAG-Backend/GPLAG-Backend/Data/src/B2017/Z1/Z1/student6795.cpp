#include <iostream>
#include <vector>
#include <cmath>
#include <deque>
#include <stdexcept>

typedef std::vector<int> IntVector;
typedef std::deque<int> IntDeque;

using std::cin;
using std::cout;
using std::endl;

//ISPITUJE DA LI JE BROJ PROST
bool Prost(int n)
{
	if(n<0) n*=-1;
	if(n==1) throw 0;
	for(int i(2); i<=std::sqrt(n); i++) {
		if(n%i == 0) return false;
	}
	return true;
}

//ISPITUJE DA LI JE BROJ SIMETRICAN
bool Simetrican(int n)
{
	int novi(0);
	int broj(n);

	while(n != 0) {
		novi = novi * 10 + n%10;
		n=n/10;
	}
	if(novi == broj) return true;

	return false;
}

//DEQUE TO INT
int DtoI (IntDeque broj)
{
	int number(0);
	for(int i(0); i<broj.size(); i++) {
		number = number * 10 + broj.at(i);
	}
	return number;
}

//PRETVORI CIJELI BROJ U TERNARNI
int Ternarni(int n)
{
	IntDeque broj;
	int num(0);
	while(n!=0) {
		broj.push_front(n%3);
		n/=3;
	}
	num = DtoI(broj);

	return num;
}

//FUNKCIJA IZ ZADATKA
IntVector IzdvojiSimetricneTernarne(IntVector v, bool DN)
{
	IntVector vektor;
	//TRAZI PROSTE I STAVLJAJ U VEKTOR
	if(DN) {
		for(int i(0); i<v.size(); i++) {
			if(v.at(i) == 1) continue;
			if(Prost(v.at(i)) == true) vektor.push_back(v.at(i));
		}
	}
	//TRAZI PRIRODNE I STAVLJAJ U VEKTOR
	if(DN == false) {
		for(int i(0); i<v.size(); i++) {
			if(v.at(i) == 1) continue;
			if(Prost(v.at(i)) == false) vektor.push_back(v.at(i));
		}
	}

	IntVector Ternarni_Simetricni;
	int pomocni;
	for(int i(0); i<vektor.size(); i++) {
		pomocni = Ternarni(vektor.at(i));
		if(Simetrican(pomocni) == true) Ternarni_Simetricni.push_back(vektor.at(i));
	}

	return Ternarni_Simetricni;
}

//IZBACUJE DUPLE BROJEVE IZ VEKTORA OSTAVLJAJUCI SAMO JEDAN ON NJIH
IntVector Duplikati(IntVector v)
{
	for(int i(0); i<v.size()-1; i++) {
		for(int j(i+1); j<v.size(); j++) {
			if(v.at(i) == v.at(j)) v.erase(v.begin() + j);
		}
	}

	return v;
}

//MAIN FUNKCIJA
int main ()
{
	bool DN;
	int IL;
	IntVector v;
	int broj;
	try {
		cout<<"Unesite elemente vektora (-1 za kraj): ";
		while(cin>>broj, broj!=-1) {
			v.push_back(broj);
		}
		cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
		cin>>IL;
		if(IL != 0 && IL != 1) throw "Neispravan unos! Unesite ponovo: ";
		DN = IL;
	} catch(const char greska[]) {
		cout<<greska;
		cin>>IL;
		if(IL != 0 && IL != 1) throw "Neispravan unos! Unesite ponovo: ";
		DN = IL;
	}

	v = Duplikati(v);
	IntVector vektor(IzdvojiSimetricneTernarne(v,DN));

	if(vektor.size() == 0) {
		if(DN) cout<<"Nema prostih simetricnih brojeva u vektoru.";
		else cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		return 0;
	}

	if(DN) cout<<"Prosti simetricni brojevi iz vektora su: ";
	else cout<<"Slozeni simetricni brojevi iz vektora su: ";

	for(int i(0); i<vektor.size(); i++) {
		cout<<vektor.at(i);
		if(i<vektor.size()-1) cout<<", ";
	}
	cout<<".\n";

	return 0;
}