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
#include <cmath>
#include <vector>
using namespace std;

bool DaLiJeProst(int n){
	
	int i,prost=1;
	if(n<=1){
		prost=0;
		return prost;
	} 
	for(i=2;i<=sqrt(n);i++){
		if(n%i==0 ) prost=0;
	}
	return prost;
}

vector<int>Ternarni1(vector<int>V1){
	vector<int> V2;
	int ost=0,eksp=-1,x=0;
	for(int i=0;i<V1.size();i++){
		int tmp(V1.at(i));
		do{
			eksp++;
			ost=tmp%3;
			tmp/=3;
			ost*=pow(10,eksp);
			x+=ost;
			ost=0;
		}while(tmp!=0);
		V2.push_back(x);
		x=0;
		eksp=-1;
	}
	return V2;
}

vector<int> Ternarni2(vector<int> v1){
	vector<int> v2;
	int x=0;
	for(int i=0;i<v1.size();i++){
		int tmp(v1.at(i));
		do{
			x+=tmp%3;
			tmp/=3;
			x*=10;
		}while(tmp!=0);
		x=x/10;
		v2.push_back(x);
		x=0;
	}
	return v2;
}

vector<int> IzdvojiSimetricneTernarne (vector<int> v,bool prost){
	vector<int> prosti;
	vector<int> slozen;
	for(int i=0;i<v.size();i++){
		int tmp(v.at(i));
		if(DaLiJeProst(tmp)==true) prosti.push_back(tmp);
		else slozen.push_back(tmp);
	}
	vector<int> konacan;
	if(prost==true){
		vector<int>prost1(Ternarni1(prosti));
		vector<int>prost2(Ternarni2(prosti));
		for(int i=0;i<prosti.size();i++){
			int tmp1(prost1.at(i));
			int tmp2(prost2.at(i));
			if(tmp1==tmp2) konacan.push_back(prosti.at(i));
		}
	}
	else{
		vector<int>slozen1(Ternarni1(slozen));
		vector<int>slozen2(Ternarni2(slozen));
		for(int i=0;i<slozen.size();i++){
			int tmp1=slozen1.at(i);
			int tmp2=slozen2.at(i);
			if(tmp1==tmp2)konacan.push_back(slozen.at(i));
		}
	}
	return konacan;
}

int main ()
{
	int n;
	vector<int> N;
	cout<<"Unesite elemente vektora (-1 za kraj): ";
	do{
		cin>>n;
		if(n==-1)break;
		N.push_back(n);
	}while(n!=-1);
	
	cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int prov;
	cin>>prov;
	if(prov!=0 && prov!=1){
		cout<<"Neispravan unos! Unesite ponovo: ";
		cin.clear();
		cin.ignore(1000,'/n');
		cin>>prov;
	}
	
	if(prov==1){
		vector<int> b(IzdvojiSimetricneTernarne(N,true));
		if(b.size()==0) cout<<"Nema prostih simetricnih brojeva u vektoru.";
		else{
			cout<<"Prosti simetricni brojevi iz vektora su: ";
			for(int j=0;j<b.size();j++){
				if(j==b.size()-1) cout<<b.at(j)<<".";
				else cout<<b.at(j)<<", ";
			}
		}
	}
	if(prov==0){
		vector<int> bb(IzdvojiSimetricneTernarne(N,false));
		if(bb.size()==0) cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		else{
			cout<<"Slozeni simetricni brojevi iz vektora su: ";
			for(int j=0;j<bb.size();j++){
				if(j==bb.size()-1) cout<<bb.at(j)<<".";
				else cout<<bb.at(j)<<", ";
			}
		}
	}
	return 0;
}