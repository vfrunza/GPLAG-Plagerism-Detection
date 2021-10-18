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

vector<int> fun(vector<int> v, bool tf){
	vector<int> slozen, prost;
	bool a(false);
	bool neg(0);
		for(int i(0); i<v.size(); i++){
			if(v.at(i)<0) {v.at(i)=-v.at(i); neg=1;}
			for(int j(2); j<=sqrt(v.at(i)); j++){
				if(v.at(i)%j==0) a=true;
				}
				if(neg) v.at(i)=-v.at(i);
				neg=0;
				if(a==false) prost.push_back(v.at(i));
				else slozen.push_back(v.at(i));
				a=false;
			
		}
	if (tf==true) return prost;
	return slozen;
}

vector<int> PretvoriUTernarni(int broj){
	int a, b;
	vector<int> v(0);
	a=broj;
	while(1){//vrti beskonacno dok ne dodje do nule
		b=a%3;
		a=a/3;
		v.push_back(b); //dodajem ostatke u vektor
		if(a==0) break; 
	}
	return v;
}

bool SimNesim(vector<int> v){
	int duz(v.size()-1); //velicina vektora al ide od nule zato minus
	if(duz==0) return false; //za jednocifrene
	for(int i(0); i<=duz/2; i++){
		if(v.at(i)!=v.at(duz-i)) return false;
	}
	return true;
}

vector<int> IzdvojiSimetricneTernarne(vector<int> v, bool tf){
	vector<int> pom;
	vector<int> pom2;//pomocni da bi svaki element vektora pom pretvorili u ternarni(niz)
	vector<int> vek;
	if(tf==true) pom=fun(v, true);
	else pom=fun(v, false);
	for(int i(0); i<pom.size(); i++){
		pom2=PretvoriUTernarni(pom.at(i)); 
		if(SimNesim(pom2)){//ako je simetrican
			vek.push_back(pom.at(i));
		} 
	}
	return vek;
}





int main ()
{
	cout<<"Unesite elemente vektora (-1 za kraj): Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	vector<int> a;
	int c;
	int b(0);
	bool ok(true);

	for(;;){
		
		cin>>b;
		if(b==-1) break;
		a.push_back(b);
	}
	while(ok==true) {
	cin>>c;
	if(c!=0 && c!=1) {
		cout<<"Neispravan unos! Unesite ponovo: "; 
		ok=true;
	}
	else ok=false;
	}
	vector<int> a1;
	a1=IzdvojiSimetricneTernarne(a, c);
	if(a1.size()==0 && c==true) cout<<"Nema prostih simetricnih brojeva u vektoru.";
	else if(a1.size()==0 && c==false) cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	else if (c==1)
	cout<<"Prosti simetricni brojevi iz vektora su: ";
	else cout<<"Slozeni simetricni brojevi iz vektora su: ";
	for(int x : a1) {
		if(x!=a1.at(a1.size()-1))cout<<x<<", ";
		else cout<<x<<".";
	}
	
	return 0;
}