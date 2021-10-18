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
vector<int>IzbaciIste(vector<int>v){
    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            if(v.at(i)==v.at(j)){
                v.at(j)=v.at(j+1);
                v.erase(v.begin()+j);
                j--;
            }
        }
    }
    return v;
}
bool DaLiJeProst(int n){
	n=fabs(n);
	if(n<1) return false;
	else{
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
	}
    return true;
}


bool PretvoriUTernarni(int n){
	n=fabs(n);
	int ternarni(0);
	int k(n),b(0);
	while(k!=0){
		b=10*b+k%3;
		k/=3;
	}
	int m(b);
	while(m!=0){
		ternarni=10*ternarni+m%10;
		m/=10;
	} 
	if(b==ternarni) return true;
	 return false;
	 
} 
vector<int>IzdvojiSimetricneTernarne(vector<int>v,bool gaus){
	vector<int>p,s;
	for(int i=0;i<v.size();i++){
		if(DaLiJeProst(v.at(i))) p.push_back(v.at(i));
		else s.push_back(v.at(i));
	}
	vector<int>psim;
	if(gaus){
		for(int i=0;i<p.size();i++){
			if(PretvoriUTernarni(p.at(i))) psim.push_back(p.at(i));
		}
		return psim;
	}
	vector<int>ssim;
	if(gaus==false){
		for(int i=0;i<s.size();i++){
			if(PretvoriUTernarni(s.at(i))) ssim.push_back(s.at(i));
		}
		return ssim;
	}
}

int main ()
{
	vector<int>v;
	int n;
	cout<<"Unesite elemente vektora (-1 za kraj): ";
    do{
    	cin>>n;
    	if(n==1) cout<<"Nije ni prost ni slozen broj.";
    	if(n!=-1) v.push_back(n);
    }while(n!=-1);
	int logicka;
	v=IzbaciIste(v);
	cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	cin>>logicka;
	while(logicka!=0 && logicka!=1){
		cout<<"Neispravan unos! ";
		cout<<"Unesite ponovo: ";
		cin>>logicka;
	}
	if(logicka==1){
		vector<int>p(IzdvojiSimetricneTernarne(v,true));
		if(p.size()==0){ cout<<"Nema prostih simetricnih brojeva u vektoru."; return 0;}
		cout<<"Prosti simetricni brojevi iz vektora su: ";
		for(int i=0;i<p.size();i++){
			if(i<p.size()-1) cout<<p.at(i)<<", ";
			else cout<<p.at(i)<<".";
		}
	}
	if(logicka==0){
		vector<int>s(IzdvojiSimetricneTernarne(v,false));
		if(s.size()==0){ cout<<"Nema slozenih simetricnih brojeva u vektoru."; return 0;}
		cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for(int i=0;i<s.size();i++){
			if(i<s.size()-1) cout<<s.at(i)<<", ";
			else cout<<s.at(i)<<".";
		}
	
	}
	
	return 0;
}