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

bool DaLiJeProst (int broj) {
	if (broj==0) return false;
	if (broj<0) {
		if (broj!=-2 && broj%2==0) return false; 
	else broj=broj*(-1);
	}
  for (int i(2);i<=std::sqrt(broj);i++) {
  	if (broj%i==0) return false;
  	if (i==broj) break;
  }
  return true;
}

bool Simentrican (int broj) {
	int b;
	b=broj;
	long long int temp(0);
	while (b!=0) {
		temp= temp*10 + abs(b%10);
		b=b/10;
	}
	if (broj<0) temp=temp*(-1);
	if (temp==broj) return true;
	else return false;
}

 int PretvaranjeUTernarni (int broj) {
	int pomocni;
	pomocni=broj;
	int ternarni(0); 
	int i(0);
	do {
	ternarni+=abs((pomocni%3))*pow(10,i);
	pomocni=pomocni/3;
	i++;
	}
	while (pomocni!=0);
	return ternarni;
}
std::vector<int> IzbaciIste (std::vector<int> v) {

	for (int i(0);i<v.size();i++){
		for (int j(0);j<i;j++) {
			if (v.at(i)==v.at(j)) { v.erase(v.begin()+i);
			i--;
		}
		}
	}
	return v;
}
std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> v, bool prost) {
	std::vector <int> pomocnivector;
	std::vector <int> retvector;
	//izdvajanje prostih ili slozenih brojeva iz zadanog vektora
	if (prost==true) {
		for (int i(0);i<v.size();i++) {
		if (DaLiJeProst(v.at(i))==prost)	pomocnivector.push_back(v.at(i));
		}
	}
	else {
			for (int i(0);i<v.size();i++) {
		if (DaLiJeProst(v.at(i))!=true)	pomocnivector.push_back(v.at(i));
		}
	}
	
	for (int i(0);i<pomocnivector.size();i++) {
		if ((Simentrican(PretvaranjeUTernarni(pomocnivector.at(i))))==true) retvector.push_back(pomocnivector.at(i));
	}
	retvector=IzbaciIste(retvector);
	return retvector;
}

int main () {
	using std::cout;
	using std::cin;
	
	std::vector<int> vec;
	cout<<"Unesite elemente vektora (-1 za kraj): ";
	int broj;
	do {
		cin>>broj;
		if (broj!=-1) vec.push_back(broj);
	}
    while(broj!=-1);
 bool Prosti;
 int prosti;
cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
for (;;) {
cin>>prosti;
if (prosti==1 || prosti==0) break;
else {
	cout<<"Neispravan unos! Unesite ponovo: ";
}
}
Prosti=prosti;
if (IzdvojiSimetricneTernarne(vec,Prosti).size()==0 && Prosti==true ) cout<<"Nema prostih simetricnih brojeva u vektoru.";
else if (IzdvojiSimetricneTernarne(vec,Prosti).size()==0 && Prosti==false ) cout<<"Nema slozenih simetricnih brojeva u vektoru.";
else if (Prosti== true ){ 
	cout<<"Prosti simetricni brojevi iz vektora su: ";
for (int i(0);i<IzdvojiSimetricneTernarne(vec,Prosti).size();i++) {
	cout<<IzdvojiSimetricneTernarne(vec,Prosti).at(i);
	if (!(IzdvojiSimetricneTernarne(vec,Prosti).size()==1) && (1+i)!=IzdvojiSimetricneTernarne(vec,Prosti).size()) cout<<", ";
  	else cout<<".";
}
}
else  {
	cout<<"Slozeni simetricni brojevi iz vektora su: ";
	for (int i(0);i<IzdvojiSimetricneTernarne(vec,Prosti).size();i++) {
	cout<<IzdvojiSimetricneTernarne(vec,Prosti).at(i);
	if (!(IzdvojiSimetricneTernarne(vec,Prosti).size()==1) && (1+i)!=IzdvojiSimetricneTernarne(vec,Prosti).size()) cout<<", ";
  	else cout<<".";
}
}
return 0;
}
