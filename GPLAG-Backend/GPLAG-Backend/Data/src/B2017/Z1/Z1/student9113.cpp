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
#include<vector>
#include<cmath>

bool Jesu_Simetricni(int c)
{
	int broj(0),pretvoreni_broj(0),k(0),cijeli_broj(0);
	while(c!=0) {
		broj=abs(c%3);
		pretvoreni_broj=k*10+broj;
		k=pretvoreni_broj;
		c/=3;
	}
	broj=pretvoreni_broj;
	k=0;
	while(broj!=0) {
		c=abs(broj%10);
		cijeli_broj=k*10+c;
		k=cijeli_broj;
		broj/=10;
	}
	if(cijeli_broj==pretvoreni_broj) return true;
	return false;
}

bool Prosti(int x)
{
	bool jel=true;
	if(x%2==0 || x<2) jel=false;
	if(x==2) jel=true;
	{
		for(int i=3; i<=sqrt(x); i+=2) {
			if(x%i==0) jel=false;
		}
	}
	return jel;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v, bool a)
{
	std::vector<int> v1;
	std::vector<int> v2;
	bool m;
	for(int i=0; i<v.size(); i++) {
		if(Jesu_Simetricni(v.at(i)) && Prosti(v.at(i))) v1.push_back(v.at(i));
		m=Prosti(v.at(i));
		if(Jesu_Simetricni(v.at(i)) &&  m==false) v2.push_back(v.at(i));
	}
	for(int i=0;i<v1.size();i++){
		for(int j=i;j<v1.size();j++){
			if(v1.at(i)==v1.at(j) && i!=j) {
				v1.erase(v1.begin()+j);
				j--;
			}
		}
	}
	for(int i=0;i<v2.size();i++){
		for(int j=i;j<v2.size();j++){
			if(v2.at(i)==v2.at(j) && i!=j){
				v2.erase(v2.begin()+j);
				j--;
			}
		}
	}
	
	if(a==true) return v1;
	else return v2;

}



int main ()
{
	std::vector<int> vektor;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	int broj(0);
	do {
		std::cin>>broj;
		if(broj!=-1) vektor.push_back(broj);


	} while(broj!=-1);
	std::vector<int> vektor1;
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	std::cin>>broj;
	if(broj!=1 && broj!=0) {
		while(broj!=1 && broj!=0) {
			std::cout<<"Neispravan unos! ";
			std::cout<<"Unesite ponovo: ";
			std::cin>>broj;
		}
	}
	if(broj==1) {
		vektor1=IzdvojiSimetricneTernarne(vektor,true);
		int i=0;
		if(vektor1.size()==0) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		else {
			std::cout<<"Prosti simetricni brojevi iz vektora su: ";
			for(i = 0; i < vektor1.size()-1; i++) {
				std::cout<<vektor1.at(i)<<", ";
			}
			std::cout<<vektor1.at(i)<<".";
		}
	}
	if(broj==0) {
		vektor1=IzdvojiSimetricneTernarne(vektor,false);
		int i=0;
		if(vektor1.size()==0) std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		else {
			std::cout<<"Slozeni simetricni brojevi iz vektora su: ";

			for(i=0; i<vektor1.size()-1; i++) {
				std::cout<<vektor1.at(i)<<", ";

			}
			std::cout<<vektor1.at(i)<<".";
		}
	}

	return 0;
}