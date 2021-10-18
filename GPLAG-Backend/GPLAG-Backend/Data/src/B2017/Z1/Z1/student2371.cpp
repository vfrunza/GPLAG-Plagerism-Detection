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
using namespace std;

bool Prost(int a){
	for(int i=2;i<a;i++){
		if(a%i==0) return 0;
	}
	return 1;
}

int Obrni (int a){
	int k=1;
	int suma=0;
	int b=a;
	while(b>9){
		k*=10;
		b/=10;
	}
	while(a!=0){
	
		suma+=k*(a%10);
		a/=10;
		k/=10;
	}
	return suma;
}

vector<int> IzdvojiSimetricneTernarne(vector<int>V,bool a){
	vector<int>pom;
	
	if (a==true) for(int i=0;i<V.size();i++){
		 if (Prost(fabs(V.at(i)))) 
		 pom.push_back(V.at(i));
	} 
	else if (a==false) for(int i=0;i<V.size();i++){
		 if (!(Prost(fabs(V.at(i)))))
		 pom.push_back(V.at(i));
	}
	
		
for(int i=0;i<pom.size();i++){
	int tern=fabs(pom.at(i));
	
	int k=1;
	int suma=0;
	while(tern !=0){
		suma+=k*(tern%3);
		tern/=3;
		k*=10;
	}
	
	if(suma != Obrni(suma)){
		for(int j=i;j<pom.size()-1;j++){
			pom.at(j)=pom.at(j+1);
			
		}
		i--;
		pom.resize(pom.size() -1);
	}
}
	
	for(int i=0;i<pom.size();i++){
		if(i!=pom.size()-1)
		for(int j=i+1;j<pom.size();j++){
			if(pom.at(j)==pom.at(i)) {
				for(int k=j;k<pom.size()-1;k++){
					pom.at(k)=pom.at(k+1);
				}
				j--;
				pom.resize(pom.size()-1);
			}
			
		}
	}
	
	return pom;
	
}




int main ()
{	
	/*vector<int>V{	191 ,233 ,43 ,313 ,142 ,13, 121 ,678 ,151 ,23 ,316 ,727 ,173 ,100};
	V=IzdvojiSimetricneTernarne(V,false);
		for(int i=0;i<V.size();i++){
		cout << V.at(i);
		if(i!=(V.size()-1)) cout <<", ";
	}
	
	*/
	
	
	cout << "Unesite elemente vektora (-1 za kraj): ";
	vector<int>V ;
	for(;;){
		int a;
		cin>>a;
		if(a!=-1)
		V.push_back(a);
		else break;
	}
	
	
	int m;
	
	cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	while(1){
		cin>>m;
		if(m!=1 && m!=0)
		cout<<"Neispravan unos! Unesite ponovo: ";
		else break;
	}
	
	
	V=IzdvojiSimetricneTernarne(V,m);
	if(m==1 && V.size()==0)
	cout<<"Nema prostih simetricnih brojeva u vektoru.";
	else if (m==0 && V.size()==0)
	cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	else {
		if(m==1) std::cout << "Prosti";
		else cout<<"Slozeni";
	cout << " simetricni brojevi iz vektora su: ";
	for(int i=0;i<V.size();i++){
		cout << V.at(i);
		if(i!=(V.size()-1)) cout <<", ";
		else std::cout << "." << std::endl;
	}
	}

	
	return 0;
}