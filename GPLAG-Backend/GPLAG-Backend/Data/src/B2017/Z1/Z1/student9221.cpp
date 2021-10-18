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
using namespace std;
bool BrojJeProst(int broj)
{
	if(broj < 0){
		broj =-broj;
		
	}
	if (broj==2){
		return true;
		
	}
	for (int i(2);i<broj;i++){
		if (broj%i==0){
			return false;
		}
		
		
	}
	return true;

}
int KreirajSimetricanBroj(int broj){
	int rezultat(0);
	if(broj < 0){
		broj=-broj;
	}
	int brojacPozicije(1);
	while(broj!=0){
		int brojZaDodati=(broj%3)*brojacPozicije;
		brojacPozicije*=10;
		rezultat+=brojZaDodati;
		broj/=3;
	}
	return rezultat;
}
bool Simetrican(int broj){
	int brojCifri(0);
	int _broj=broj;
	while(_broj !=0){
		brojCifri++;
		_broj /=10;
	}
	if(brojCifri==1){
		return true;
	}
	int brojacPozicije(1);
	for(int i(0);i<brojCifri-1;i++){
		brojacPozicije*=10;
		
	}
	int brojacOdKraja=10;
	for(int i(0);i<brojCifri;i++){
		if((broj/brojacPozicije)!=(broj%brojacOdKraja)){
			return false;
	}
	broj=(broj%brojacPozicije);
	broj/=10;
	brojacPozicije/=100;
	if(broj==0 && brojacPozicije==0){
		break;
		
	}
	if(broj/brojacPozicije==0 && broj!=0 && broj<10){
		return false;
	}
	}
	return true;
}
vector<int> IzdvojiSimetricneTernarne(vector<int> v,bool prosti){
	vector <int> rezultat;
	for(int i(0);i<(int)v.size();i++){
		if(BrojJeProst(v.at(i))==prosti){
			if(Simetrican(KreirajSimetricanBroj(v.at(i)))){
				bool postoji=false;
				for(int j(0);j<(int)rezultat.size();j++){
					if(rezultat.at(j)==v.at(i)){
						postoji=true;
						break;
					}
				}
				if(!postoji){
					rezultat.push_back(v.at(i));
				}
			}
		}
	}
	return rezultat;
}


int main ()
{
	std::vector<int>v;
	double a;
	
	
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	while(std::cin>>a,a!=-1){
		v.push_back(a);
	}
	int b;
	cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	cin>>b;
	while(b!=0&&b!=1){
		cout<<"Neispravan unos! Unesite ponovo: ";
		std::cin >> b;
	}
	std::vector<int> krajnji (IzdvojiSimetricneTernarne(v,b)) ;
	if(krajnji.size()>0){
		if(b)
			cout<<"Prosti simetricni brojevi iz vektora su: " ;
		else 
			cout<<"Slozeni simetricni brojevi iz vektora su: " ;
		for (int i = 0; i < krajnji.size()-1; i++) {
			std::cout << krajnji.at(i) << ", ";
	}
		std::cout << krajnji.at(krajnji.size()-1) << ".";
	}else if (b)
		std::cout << "Nema prostih simetricnih brojeva u vektoru." << std::endl;
	else
		std::cout << "Nema slozenih simetricnih brojeva u vektoru." << std::endl;
	
	
	return 0;
}