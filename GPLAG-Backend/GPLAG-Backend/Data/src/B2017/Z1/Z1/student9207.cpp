#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
using std::cout;
using std::vector;
using std::cin;
bool DaLiJeSimetrican(int n)
{
	//vraca bool u zavisnosti da li je sim ili ne sim broj
	vector<int>cifre;
	int cifra;
	while (n!=0) {
		cifra=abs(n%10);
		cifre.push_back(cifra);
		n/=10;
	}
	for(int i=0; i<cifre.size()/2; i++) {
		if(cifre.at(i)!=cifre.at(cifre.size()-1-i)){
		return false;
		}
	}
	return true;
}
int dec2tern(int n)
{
	//"Skolska" konverzija dijeljenjem iz dec u tern sistem
	vector<int> rez;
	int final(0),broj(1),ostatak;
	while(n!=0) {
		ostatak=n%3;
		rez.push_back(ostatak);
		n/=3;
	}
	//slijedeci blok broj naopako stvori
	for(int i=0; i<rez.size(); i++) {
		final+=rez.at(i)*broj;
		broj*=10;
	}
	return final;
}
vector<int> UnesiVektor()
{
	//Jednostavni unos vektora
	vector<int> vektor;
	int a;
	while(true) {
		cin>>a;
		if (a==-1) {
			break;
		}
		vektor.push_back(a);
	}
	return vektor;
}
bool DaLiJeProst(int n)
{
	//Provjera da li je prost sa zanemarenjem predznaka, long int zbog
	//potencijalnog prekoracenja kada bi se minimum int-u promijenio predznak
	if(n==1||n==0||n==-1) {
		return false;
	}
	long int temp(n);
	if(temp<0) {
		temp*=(-1);
	}
	for(int i=2; i<=sqrt(temp); i++) {
		if((temp%i)==0) {
			return false;
		}
	}


	return true;
}
vector<int> IzdvojiSimetricneTernarne(vector<int> vektor,bool logika)
{
	//Funkcija ide element po element i gleda da li je blok 1 uslova ili blok 2 uslova zadovoljen
	//I puni vektor rez sa elementima
	vector<int> rez;
	for(int i=0; i<vektor.size(); i++) {
		if(logika&&DaLiJeProst(vektor.at(i))&&DaLiJeSimetrican(dec2tern(vektor.at(i)))) {
			rez.push_back(vektor.at(i));
		} else if(!logika&&!DaLiJeProst(vektor.at(i))&&DaLiJeSimetrican(dec2tern(vektor.at(i)))) {
			rez.push_back(vektor.at(i));
		}
	}
	for(int i=0;i<(int)rez.size()-1;i++){
		for(int j=i+1;j<rez.size();j++){
			if(rez.at(i)==rez.at(j)){
				rez.erase(rez.begin()+j);
				j--;
			}
		}
	}
	return rez;
}
void IspisiVektor(vector<int>vektor, bool logika)
{
	if(vektor.size()==0&&logika) {
		cout<<"Nema prostih simetricnih brojeva u vektoru.";
	} else if (vektor.size()==0) {
		cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	} else {
		if(logika){
			cout<<"Prosti simetricni brojevi iz vektora su: ";
		} else {
			cout<<"Slozeni simetricni brojevi iz vektora su: ";
			}
			int i;
		for(i=0;i<vektor.size()-1;i++) {
			cout<<vektor.at(i)<<", ";
		}
		cout<<vektor.at(i)<<".";
	}
}
int main ()
{
	int logika;
	vector<int> vektor;
	cout<<"Unesite elemente vektora (-1 za kraj): ";
	vektor=UnesiVektor();
	cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	while(true) {
		cin>>logika;
		if(logika==0||logika==1) {
			break;
		} else {
			cout<<"Neispravan unos! Unesite ponovo: ";
		}
	}

	vektor=IzdvojiSimetricneTernarne(vektor,logika);
	IspisiVektor(vektor,logika);

	return 0;
}