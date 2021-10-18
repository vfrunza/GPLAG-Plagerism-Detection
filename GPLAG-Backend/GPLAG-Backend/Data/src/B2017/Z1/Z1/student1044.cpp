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
using namespace std;
typedef vector<int> Vektor;

bool daLiJeSimetrican (int broj){
	int terarnaCifra, terarniBroj=0;
	int brojac=0;
	
	while (broj!=0) {
		terarnaCifra=broj%3;
		terarniBroj+= terarnaCifra*pow(10,brojac);
		brojac++;
		broj/=3;
		
	}
	
	int r=0,z=0,x;
	x=terarniBroj;
	while(x!=0){
		r=x%10;
		z=z*10+r;
		x=x/10;
	}
	if(z==terarniBroj){
		return true;
	}
	return false;
	}
	
Vektor IzdvojiSimetricneTernarne(vector<int> vektorBrojeva, bool prosteBrojeve){
	vector<int>brojevi;
	for(int i(0);i<vektorBrojeva.size();i++){
		bool daLiJeSlozen=false;
		for(int j(2);j<vektorBrojeva.at(i);j++){
			if(vektorBrojeva.at(i)%j==0){
				daLiJeSlozen=true;
				if(daLiJeSimetrican(vektorBrojeva.at(i)) && !prosteBrojeve){
			brojevi.push_back(vektorBrojeva.at(i));
				}
			break;
					}
		}
		if(!daLiJeSlozen){
			if(daLiJeSimetrican(vektorBrojeva.at(i)) && prosteBrojeve){
				brojevi.push_back(vektorBrojeva.at(i));
			}
		}
	}
	for(int i(0);i<brojevi.size();i++){
		for(int j=i+1;j<brojevi.size();j++){
			if(brojevi.at(i)==brojevi.at(j)){
				brojevi.erase(brojevi.begin()+j);
			}
		}
	}
	return brojevi;
}
int main ()
{	/*vector<int> values {191, 233, 43, -313, 142, 13, 121, 678, -151, 23, -12, 727, 173, 233};
vector<int>val=IzdvojiSimetricneTernarne(values, true);
for(int i(0); i<val.size();i++){
	cout<<val.at(i);
	if(i!=(val.size()-1)) cout<<",";
}*/
cout<<"Unesite elemente vektora (-1 za kraj): ";
vector<int>values;
int n;
while(cin>>n, n!=-1){
	values.push_back(n);
	}
cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
int pom;
vector<int>val;
cin>>pom;
//PROVJERITIIIIIIIIIIII
while (pom<0 || pom>1){
	cout<<"Neispravan unos! Unesite ponovo: ";
	cin>>pom;
}
if(pom==1) {
	val=IzdvojiSimetricneTernarne(values, 1);
	if(val.size()==0) cout<<"Nema prostih simetricnih brojeva u vektoru.";
	else{
	cout<<"Prosti simetricni brojevi iz vektora su: ";
	for(int i(0); i<val.size();i++){
		cout<<val.at(i);
if(i!=(val.size()-1)) cout<<", ";
else cout<<".";
	}
}
}
if(pom==0)
{
	val=IzdvojiSimetricneTernarne(values, 0);
	if(val.size()==0) cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	else{
	cout<<"Slozeni simetricni brojevi iz vektora su: ";
	for(int i(0); i<val.size();i++){
	cout<<val.at(i);
	if(i!=(val.size()-1)) cout<<", ";
	else cout<<".";
	}
}
}
	return 0;
}