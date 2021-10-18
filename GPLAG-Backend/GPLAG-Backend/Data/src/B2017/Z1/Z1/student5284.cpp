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
#include <iomanip>
#include <cmath>

using namespace std;

bool DaLiJeProst(int n) {
	
	for(int i=2; i<n; i++) {
		if(n%i==0) return false;
	}
	return true;
}

int DaLiJeTernaran(int n) {
	int rem,k=1,suma=0;
    while(n!=0)
    {
        rem=n%3;
        suma+=(k*rem);
        n/=3;
        k*=10;
    }
    return suma;
}	

int Okrenut(int n){
	int k=1;
	int suma=0;
	int b=n;
	while(b>9){
		k*=10;
		b/=10;
	}
	while(n!=0){
	
		suma+=k*(n%10);
		n/=10;
		k/=10;
	}
	return suma;
}
bool DaLiJeSimetrican(int n) {
	
	int n1=DaLiJeTernaran(n);
if(n1==Okrenut(n1))  return true;
else return false;
}


vector<int>IzdvojiSimetricneTernarne(vector<int>v, bool M) 
{
	vector<int>v1;
	vector<int>v2;
	
	for(int i=0; i<v.size(); i++) {
		if(M==1) {
			if(DaLiJeProst(v.at(i)) && DaLiJeSimetrican(fabs(v.at(i)))) v1.push_back(v.at(i));
		}
		else if(M==0) {
			if(!DaLiJeProst(v.at(i)) && DaLiJeSimetrican(fabs(v.at(i)))) v1.push_back(v.at(i));
		}
		
	}
//	for(int j=0; j<v1.size(); j++) {
//		if(DaLiJeSimetrican(fabs(v1.at(j)))) v2.push_back(v1.at(j));
//	}
	
	return v1;
}


int main ()
{
	/*vector<int> v={191, 233, 43, 313, 143, 13, 121, 678, 151, 23, -12, 727, 173};
	
	
	 cout<<"ADSdASDA ";
	v=IzdvojiSimetricneTernarne(v,true);
	for(int i=0; i<v.size(); i++) cout<<v[i]<<" "; */
	int n,M;
	vector<int>v1;
	vector<int>v;
	

	cout<<"Unesite elemente vektora (-1 za kraj): ";
		while(1) {
			cin>>n;
			if(n==-1) break;
			v.push_back(n);
		}
		cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
				while(1) {
					cin>>M;
					if(M!=0 && M!=1) {cout<<"Neispravan unos!";
					cout<<" Unesite ponovo: "; }
					else break;
				}
				
	if(M==1) {	
	v1=IzdvojiSimetricneTernarne(v,M);
	if(v1.size()==0) cout<<"Nema prostih simetricnih brojeva u vektoru.";
	else {cout<<"Prosti simetricni brojevi iz vektora su: ";
	
	for(int i=0; i<v1.size(); i++) {
		   if(i==v1.size()-1) cout<<v1.at(i)<<".";
                else cout<<v1.at(i)<<", ";
	
		}
	}
	}
	else if(M==0) {
			
			
	v1=IzdvojiSimetricneTernarne(v,M);
	if(v1.size()==0) cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	else {cout<<"Slozeni simetricni brojevi iz vektora su: ";
	for(int i=0; i<v1.size(); i++) {
		   if(i==v1.size()-1) cout<<v1.at(i)<<".";
                else cout<<v1.at(i)<<", ";
	
			}
		} 
}
return 0;
}