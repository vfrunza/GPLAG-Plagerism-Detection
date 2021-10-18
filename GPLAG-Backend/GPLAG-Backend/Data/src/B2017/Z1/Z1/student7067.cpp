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
#include <iomanip>

using namespace std;


bool DaLiJeProst( unsigned int broj) {
	for(int j=2; j<=sqrt(broj); j++){
		if(broj%j==0 || broj<0)
		return false;
	}
	if(broj>1) return true;
	if(broj<=1) return false;
 }
 
 int PretvoriUTernare( int broj){
 	int ostatak;
 	int i(0);
 	vector<int> a;
 	for( int i=broj; i>=0; i--){
 		ostatak=broj%3;
 		a[i]=ostatak;
 		broj=int(broj/3);
 	}
 	return a[i];
 }
 
 int DaLiJeSimetrican(int broj){
 	
 }
 
vector<int> IzdvojiSimetricneTernare(vector<int>v, bool x){
	vector<int> v1;
	for(int i=v.at(0); i<=v.size(); i++){
		if(DaLiJeProst(i)==true){
			v1=vector<int>(PretvoriUTernare(i));
		}
		else{
			v1=vector<int>(PretvoriUTernare(i));
		}
	}
	return v;
	
}


int main ()
{
	bool n;
	int y;
	vector<int> vek(y);
	cout<<"Unesite elemente vektora (-1 za kraj): ";
	cin>>y;
	cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	cin>>n;
	if(n==1){
		cout<<"Prosti simetricni brojevi iz vektora su: "<<IzdvojiSimetricneTernare()<<;
	}
	

	return 0;
}