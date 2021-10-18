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
bool Prost(int n){
	for(int i=2; i<n; i++){
		if(n%i == 0) return false;
	}
	return true;
}
int Ternarni(int n){
	int pom(n),pom1(0), suma(0);
	int brojcifara(0);
	while(n != 0){
		pom1 = pom1*10 + n%3;
		n/=3;
		}
	return pom1;
}
bool Simetrican(int n){
	int pom(n),pom1(n), brojcifara(0), sim(0);
	while(pom != 0){
		brojcifara++;
		pom/=10;
	}

	while(n != 0 || brojcifara <0){
		sim += (n%10) * pow(10,brojcifara-1);
		n/=10;
		brojcifara--;
	}
	
	if(pom1==sim) return true; 
	return false;
	
}
vector <int> IzdvojiSimetricneTernarne(vector<int> v, bool b){
	vector <int> c;
	bool provjera(false);
	for(int i=0; i<v.size(); i++){
	  if(b){
	  
	  	if(v.at(i) > 0 && Prost(v.at(i)) && Simetrican(Ternarni(v.at(i))))
	  	{ for(int j=0; j<i; j++){
	  		if(v.at(j) == v.at(i)) provjera = true;
	  	}
		if(!provjera) c.push_back(v.at(i));
	  	}
	} else if(v.at(i) > 0 && !Prost(v.at(i)) && Simetrican(Ternarni(v.at(i))))
	    { for(int j=0; j<i; j++){
	    	if(v.at(j) == v.at(i)) provjera = true;
	    } if(!provjera)
		c.push_back(v.at(i)); }
	}	
		return c;
}
int main ()
{   vector<int> v;
    int a;
    bool provjera(false);
    cout << "Unesite elemente vektora (-1 za kraj): ";
    for(int i=0;;i++){
    	cin >> a;
       
    	if(a==-1) break;
    	else v.push_back(a);
    
    }
    cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
    cin >> a;
  
  	while(a != 1 && a != 0){
    	cout<<"Neispravan unos! Unesite ponovo: ";
    	cin >> a;
  	}
    
    vector <int> c;
    if(a) c = IzdvojiSimetricneTernarne(v,true);
    else c = IzdvojiSimetricneTernarne(v,false);
    
    if(a && c.size()==0) cout << "Nema prostih simetricnih brojeva u vektoru. ";
    else if(!a && c.size() == 0) cout << "Nema slozenih simetricnih brojeva u vektoru. ";
    else { if(a) cout << "Prosti simetricni brojevi iz vektora su: ";
           else cout << "Slozeni simetricni brojevi iz vektora su: ";
    	for(int i=0; i<c.size(); i++){
    		if(i==c.size()-1) cout << c.at(i) <<".";
    		else cout << c.at(i) << ", ";
    	}
    }
    
	return 0;
}