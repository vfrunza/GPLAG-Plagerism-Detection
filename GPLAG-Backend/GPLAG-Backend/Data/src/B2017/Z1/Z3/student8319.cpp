/*B 2017/2018, Zadaća 1, Zadatak 3
	
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
#include <deque>
#include <iomanip>

typedef std::vector<int> Vector;
typedef std::deque<std::vector<int>> DekVektora;

using std::cout;
using std::cin;
using std::endl;

enum Smjer {rastuci=1,opadajuci=2};

bool DaLiJeStepenDvojke (int broj){
     if (broj%2!=0 && broj!=1) return false;
	 if (broj==0) return false;
	 if (broj<0) return false;
	else {
		do {
			broj=broj/2;
			if (broj%2!=0 && broj!=1) return false;
		}
		while(broj!=0);
	}
   return true;
   }
   
DekVektora MaksRastuciPodniz (Vector v) {
    DekVektora ret;
    Vector pom;
    int brojac(0);
   for (int j(brojac);j<v.size();j++) {
   	Vector pom;
   	int i(brojac);
   	for (;i<v.size();i++) {
   			if (DaLiJeStepenDvojke(v.at(i))==true && (pom.size()==0 || v.at(i)>=v.at(i-1))){ brojac++; pom.push_back(v.at(i)); }
   			else {
   				if (DaLiJeStepenDvojke(v.at(i))==true) { pom.resize(0); pom.push_back(v.at(i)); brojac++; }
   				brojac++; break; }
   	}
   	
   	 if (pom.size()>=2) ret.push_back(pom);
    pom.resize(0);
   }
   /*  for (int i(0);i<v.size();i++) {
     	if (DaLiJeStepenDvojke(v.at(i))==true && (pom.size()==0 || v.at(i)>=v.at(i-1))) pom.push_back(v.at(i));
     	else {
     		 if (pom.size()>=2) ret.push_back(pom);
    pom.resize(0);
    if (DaLiJeStepenDvojke(v.at(i))==true) pom.push_back(v.at(i));
     	}
     }
     if (pom.size()==v.size()) ret.push_back(pom);
   */ 
return ret;
}

DekVektora MaksOpadajuciPodniz (Vector v) {
    DekVektora ret;
   Vector pom;
    int brojac(0);
   for (int j(brojac);j<v.size();j++) {
   	Vector pom;
   	int i(brojac);
   	for (;i<v.size();i++) {
   			if (DaLiJeStepenDvojke(v.at(i))==true && (pom.size()==0 || v.at(i)<=v.at(i-1))){ brojac++; pom.push_back(v.at(i)); }
   			else {  
   			if (DaLiJeStepenDvojke(v.at(i))==true) { pom.push_back(v.at(i)); brojac++; }
   				brojac++; break;
   			}
   	}
   	
   	 if (pom.size()>=2) ret.push_back(pom);
    pom.resize(0);
   }
     
return ret;
}

 
  
DekVektora MaksimalniPodnizoviStepenaDvojke (Vector v,enum Smjer s) {
 if (s==opadajuci) return (MaksOpadajuciPodniz(v));
 return (MaksRastuciPodniz(v));
}
   
int main ()
{ 
	Vector v;
	cout<<"Unesite broj elemenata vektora: ";
	int broj;
	cin>>broj;
	cout<<"Unesite elemente vektora: ";
	for (int i(0);i<broj;i++) {
		int br;
		cin>>br;
		v.push_back(br);
	}
	
	cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	Smjer s;
	int KojiJeSmjer;
	cin>>KojiJeSmjer;
	s=Smjer(KojiJeSmjer);
    if (s==2) 	cout<<"Maksimalni opadajuci podnizovi: "<<endl;
    if (s==1)   cout<<"Maksimalni rastuci podnizovi: "<<endl;
    	for (auto x: MaksimalniPodnizoviStepenaDvojke(v,s)) {
    		for (auto y: x) {
    			cout<<y<<" ";
    		}
    		cout<<endl;
    	}
	return 0;
}