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

vector<int> IzdvojiSimetricneTernarne(vector<int> v, bool vr){
	vector<int> novi;
	int prvi=0;
	for(int i=0; i<v.size(); i++){
		int a;
		if(v.at(i)<0) a=-v.at(i);
		if(v.at(i)>=0) a=v.at(i);
		int suma=0;
		while(a>0){
			suma=suma*10+(a%3);
			a/=3;
		}
		int b=suma;
		int suma2=0;
		int sim=0;
		while(b>0){
			int n=b%10;
			suma2=suma2*10+n;
			b/=10;
		}
		if(suma==suma2) sim=1;
		int prost=1;
		int c;
		if(v.at(i)<0) c=-v.at(i);
		if(v.at(i)>=0) c=v.at(i);
		for(int j=2; j<c; j++){
			if(c==1 || c%j==0){
				prost=0;
				break;
			}
		}
		if(prvi==0 && vr==true && prost==1 && sim==1 && v.at(i)!=0){
			novi.push_back(v.at(i));
			prvi++;
		}
		if(prvi==0 && vr==false && prost==0 && sim==1 && v.at(i)!=0){
			novi.push_back(v.at(i));
			prvi++;
		}
		
		int moze=1;
		for(int j=0; j<novi.size(); j++){
			if(v.at(i)==novi.at(j)){
				moze=0;
				break;
			}
		}
		if(prvi==1 && vr==true && prost==1 && sim==1 && moze==1 && v.at(i)!=0){
			novi.push_back(v.at(i));
		}
		if(prvi==1 && vr==false && prost==0 && sim==1 && moze==1 && v.at(i)!=0){
			novi.push_back(v.at(i));
		}
	}
	return novi;
}

int main ()
{
	vector<int> vektor;
	int vrijednost;
	
	vector<int> novi;
	cout << "Unesite elemente vektora (-1 za kraj): ";
	int i=0,a;
	do{
		cin >> a;
		
		i++;
		if(a==-1) break;
		vektor.push_back(a);
	} while(a!=-1);
	cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	cin >> vrijednost;
	if(vrijednost!=0 && vrijednost!=1){
		while(vrijednost!=0 && vrijednost!=1){
			cout << "Neispravan unos! Unesite ponovo: ";
			cin >> vrijednost;
			if(vrijednost==1 || vrijednost==0) break;
		}
	}
	if(vrijednost==1){
		
	    novi=IzdvojiSimetricneTernarne(vektor,true);
	}
	else{
		novi=IzdvojiSimetricneTernarne(vektor,false);
	}
	
	if(vrijednost==1){
		if(novi.size()<2){
			cout << "Nema prostih simetricnih brojeva u vektoru.";
			return 0;
		}
		cout << "Prosti simetricni brojevi iz vektora su: ";
		for(int i=0; i<novi.size(); i++){
			if(i==(novi.size()-1)) cout << novi.at(i) << ".";
			else cout << novi.at(i) << ", ";
		}
	}
	if(vrijednost==0){
		if(novi.size()<2){
			cout << "Nema slozenih simetricnih brojeva u vektoru.";
			return 0;
		}
		cout << "Slozeni simetricni brojevi iz vektora su: ";
		for(int i=0; i<novi.size(); i++){
			if(i==(novi.size()-1)) cout << novi.at(i) << ".";
			else cout << novi.at(i) << ", ";
		}
	}
	
	return 0;
}