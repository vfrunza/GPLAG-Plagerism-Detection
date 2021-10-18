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
bool DaLiJeProst(int n)
{
	if(n<=1)
	return false;
	int i;
	for(i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		return false;
	}
	return true;
}

vector<int> PretvoriUTernarni(int a){
	vector<int>m,n;
	if(a==0) return{3};
	int x;
	int y=a;
	while(a){
		x=a%3;
		m.push_back(x);
		a/=3;
	}
	for(int i=m.size()-1;i<=0;i--)
	n.push_back(m.at(i));
	 if(y<0){
	 	for(int i=0;i<n.size();i++){
	 		if(i!=0)
	 		n.at(i)*=-1;
	 	}
}
return n;
}
//provjera da li je simetrican.
bool DaLiJeTernarniSimetrican(vector<int>h){
	bool m=true;
	for (int i=0;i<h.size();i++){
		if(h.at(i)<0)h.at(i)*=-1;
		if(h.at(i)!=h.at(h.size()-i-1)) 
		m=false; 
	}
	return m;
}
vector<int>IzdvojiSimetricneTrnarne(vector<int>m,bool n)
{
	vector<int>prosti,slozeni,rezultat1,rezultat2;
	for(int i=0;i<m.size();i++){
		if(DaLiJeProst(i)) prosti.push_back(i);
		if(DaLiJeProst(i)==false &&(i!=1)&&(i!=0)) slozeni.push_back(i);
	}
	for(int j: prosti){
		if(DaLiJeTernarniSimetrican(PretvoriUTernarni(j)))
		rezultat2.push_back(j);
		
	}
	for(int k: slozeni){
		if(DaLiJeTernarniSimetrican(PretvoriUTernarni(k)))
		rezultat1.push_back(k);
}
for(int i: rezultat1){
	for(int j: rezultat1){
		if(rezultat1.at(i)==rezultat1.at(j)){
			rezultat1.erase(rezultat1.begin()+j);
			j--;
		}
	}
}
if(n) return rezultat1;
return rezultat2;
	
}
int main ()
{
	vector<int>m;
	cout<<"Unesite elemente vektora(-1 za kraj): ";
	int a,b;
	do{
		cin>>a;
		if(a!=-1) m.push_back(a);
	}while(a!=-1);
	 
	cout<<"Ujesite 1 za proste brojeve, 0 za slozene brojeve: ";
	Pocetak:
	cin>>b;
	if(b!=-1 && b!=0){
		cout<<"Neispravan unos! "<<"Unesite ponovo: ";
	
		goto Pocetak;
	}
	
	bool h=b;
	if(IzdvojiSimetricneTrnarne(m,true).size()==0){
		cout<<"Nema prostih simetricnih brojeva u vektoru.";
		goto Kraj;
	}
	if(IzdvojiSimetricneTrnarne(m,false).size()==0){
		cout<<"Nema slozenih simetricnih brojeva u vektoru:";
		goto Kraj;
	}
	if(h){
		cout<<"Prosti simetricni brojevi iz vektora su: ";
		for (int i=0;i<IzdvojiSimetricneTrnarne(m,h).size();i++){
			cout<<IzdvojiSimetricneTrnarne(m,h).at(i);
			if(i!=IzdvojiSimetricneTrnarne(m,h).size()-1) 
			cout<<", ";
		}
		cout<<".";
	}
	Kraj:
	return 0;
}