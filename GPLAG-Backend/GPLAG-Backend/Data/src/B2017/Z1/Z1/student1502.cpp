
#include <iostream>
#include <cmath>
#include <vector> 

using namespace std;

vector<int> UTernarni(long long int broj){
vector<int> rez;
if(broj==0)rez.push_back(0);
while(broj!=0){
	rez.push_back(broj%3);
	broj/=3;
	}
return rez;
}

bool Simetrija(vector<int> v){
	for(int i=0; i<v.size()/2+1;i++){
		if(v.at(i)!=v.at(v.size()-1-i)) return false;
	}
	return true;
}

bool Prost(int broj){
    if(broj<=1 or(broj%2==0 and broj!=2)) return false;
    if(broj==2)return true;
	int korijen=sqrt(broj)+1;
	for(int i=3;i<=korijen;i+=2){
		if(broj%i==0)return false;
	}
	return true;
}

bool nema (vector<int> v, int x){
	for(int y: v)if(x==y)return false;
	return true;
}

vector<int>IzdvojiSimetricneTernarne(vector<int>niz, bool valja){
	vector<int> rezultat;
	if(valja){
		for(int x: niz){
			long int y=x;
			if(x<0)y=x*-1;
			vector<int> temp=UTernarni(y);
			if(Prost(y) and Simetrija(temp)){
			if(nema(rezultat,x)and x!=1)rezultat.push_back(x);
			}
		}
	}else{
		for(int x: niz){
			int y=x;
			if(x<0)y=x*-1;
			vector<int> temp=UTernarni(y);
			if(!Prost(y) and Simetrija(temp)){
			if(nema(rezultat,x)and x!=1)rezultat.push_back(x);
			}
		}
	}
   return rezultat;	
}

int main (){
	vector<int>v;
	int a;
	cout<<"Unesite elemente vektora (-1 za kraj): ";
	for(;;){
		cin>>a;
		if(a==-1)break;
	    v.push_back(a);
	}
	cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int k=5;
	while(1){
	cin>>k;
	if(k!=0 and k!=1)cout<<"Neispravan unos! Unesite ponovo: ";
	if(k==0 or k==1)break;
		
	}
	bool p=true;
	if(k==0)p=false;
    vector<int> rez= IzdvojiSimetricneTernarne(v,p);
    if(rez.empty()and p){
    	cout<<"Nema prostih simetricnih brojeva u vektoru.";
    	return 0;
    }else if(rez.empty()and !p){
    		cout<<"Nema slozenih simetricnih brojeva u vektoru.";
    	return 0;
    }
    if(p){
    cout<<"Prosti simetricni brojevi iz vektora su: ";
    for(int i=0;i<rez.size();i++){
		
		if(i!=rez.size()-1){
			cout<<rez.at(i)<<", ";
		}else{
			cout<<rez.at(i)<<".";
		}
    }
    }else{
    	 cout<<"Slozeni simetricni brojevi iz vektora su: ";
    for(int i=0;i<rez.size();i++){
		
		if(i!=rez.size()-1){
			cout<<rez.at(i)<<", ";
		}else{
			cout<<rez.at(i)<<".";
		}
    }
     }
	return 0;
}