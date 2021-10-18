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

int Ternarni(int a){
	int b=0;
	int k=10;
	while(a>0){
		b=a%3+b*k;
		a=a/3;
		
	}
	return b;
}
bool pomocna(int a){
	for(int i=2;i<=sqrt(a);i++){
		if(a%i==0){ return true; break;}
	}
	return false;
}

bool Simetrican(int a){
	int b=0;
	int c=a;
	int k=10;
	while(a>0){
		b=a%10+b*k;
		a=a/10;
	}
	if(c==b) return true;
	return false;
}
vector<int> IzdvojiSimetricneTernarne(vector<int> v, bool logicka){
	for(int i=0;i<v.size();i++){
		v.at(i)=fabs(v.at(i));
	}
	vector<int>s;
	vector<int>p;
	int broj;
	for(int i=0;i<v.size();i++){
	broj=Ternarni(v.at(i));
	if(pomocna(v.at(i)) == true && Simetrican(broj)==true) s.push_back(v.at(i));
	if(pomocna(v.at(i)) == false && Simetrican(broj)==true) p.push_back(v.at(i));
	}
if(logicka==true) return p;
return s;
}

int main ()
{
	vector<int> v;
	cout<<"Unesite elemente vektora (-1 za kraj): ";
	int broj;
	do{
	cin>>broj;
	if(broj!=-1)  v.push_back(broj);
	}while(broj!=-1);

	cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int a;
	do{
	cin>>a;
	if(a!=0 && a!=1) cout<<"Neispravan unos! Unesite ponovo: ";
	}while(a!=0 && a!=1);
	
	if(a==1){
	vector<int>ispisi_1=IzdvojiSimetricneTernarne(v,true);
	if(ispisi_1.size()==0) {
	cout<<"Nema prostih simetricnih brojeva u vektoru. ";
	return 0;
	}
	cout<<"Prosti simetricni brojevi iz vektora su: ";
	for(int i=0;i<ispisi_1.size();i++){
	if(i<ispisi_1.size()-1) cout<<ispisi_1.at(i)<<", ";
	else cout<<ispisi_1.at(i) << ".";
	}
	}
	if(a==0){
		vector<int>ispisi_2=IzdvojiSimetricneTernarne(v,false) ;
		if(ispisi_2.size()==0) {
		cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		return 0;
		}
	cout<<"Slozeni simetricni brojevi iz vektora su: ";
	for(int i=0;i<ispisi_2.size();i++){
	if(i<ispisi_2.size()-1) cout<<ispisi_2.at(i)<<", ";
	else cout<<ispisi_2.at(i) <<".";
	}
	}
	
	return 0;
}