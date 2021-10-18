/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include<cmath>

using std::cin;
using std::cout;
using std::endl;

bool Opaki(int broj){
	int cifra;
	std::vector<int>brojaci(3,0);
	do{
		cifra=broj%3;
		if(cifra<0) cifra=(-1)*cifra;
		for(int i=0; i<3; i++)
			if(cifra==i) brojaci[i]++;
		broj/=3;
		}while(broj!=0);
	
	for(int i=0; i<3; i++){
		if(brojaci[i]==0) continue;
		if(brojaci[i]%2!=0) return 0;
	}
	
	return 1;
}
bool Odvratni(int broj){
	int cifra;
	std::vector<int>brojaci(3,0);
	do{
		cifra=broj%3;
		if(cifra<0) cifra=(-1)*cifra;
		for(int i=0; i<3; i++)
			if(cifra==i) brojaci[i]++;
		broj/=3;
	}while(broj!=0);
	
	for(int i=0; i<3; i++){
		if(brojaci[i]==0) continue;
		if(brojaci[i]%2==0) return 0;
	}
	return 1;
}
std::vector<int> IzdvojiGadne(std::vector<int>niz, bool t){
	std::vector<int>vektor;
	for(int i=0; i<niz.size(); i++){
		if(t==1){
			if(Opaki(niz[i])){
				if(vektor.size()==0) vektor.push_back(niz[i]);
				else{
					bool b(1);
					for(int j=0; j<vektor.size(); j++)
						if(vektor[j]==niz[i]) b=0;
					if(b) vektor.push_back(niz[i]);
				}
			}
		}
		else if(t==0){
			if(Odvratni(niz[i])){
				if(vektor.size()==0) vektor.push_back(niz[i]);
				else{
					bool b(1);
					for(int j=0; j<vektor.size(); j++)
						if(vektor[j]==niz[i]) b=0;
					if(b) vektor.push_back(niz[i]);
				}
			}
		}
	}
	return vektor;
}
int main ()
{
	std::vector<int>niz,opaki,odvratni;
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	int broj;
	cin>>broj;
	while(broj!=0){
		niz.push_back(broj);
		cin>>broj;
	}
	opaki=IzdvojiGadne(niz,1);
	cout<<"Opaki: ";
	for(int x: opaki)
		cout<<x<<" ";
	odvratni=IzdvojiGadne(niz,0);
	cout<<endl<<"Odvratni: ";
	for(int x: odvratni)
		cout<<x<<" ";
	
	return 0;
}