#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;
typedef std::vector<int> Vektor;

bool DaLiJeProst(int n){
	if(n==0)return false;
	if(n==1)return true;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0)return false;
	}
	return true;
}

bool Provjera (Vektor v, int n){
	
	for(int x : v){
		if(x==n)return true;
	}
	return false;
	
}

int PretvoriUTernarni (int n){
	
	Vektor v;
	int b=0;
	if(n<0){
		b=1;
		n=abs(n);
	}
	int c;
	while(n!=0){
		c=n%3;
		v.push_back(c);
		n=n/3;
		
	}
	int m=0;
	int vel=int(v.size());
	for(int j=0;j<vel;j++){
		m+=v.at(j)*pow(10,j);
	}
	if(b==1){
		m=-m;
		return m;
	}
	else return m;
}

bool DaLiJeSimetrican(int n){
	
	int c;
	Vektor v;
	n=abs(n);
	while(n!=0){
		c=n%10;
		v.push_back(c);
		n=n/10;
	}
	int vel=int(v.size());
	for(int j=0;j<=vel/2;j++){
		if(v.at(j)!=v.at(vel-j-1)) return false;
	}
	return true;
}

int PretvoriUDkedne(int n){
	
	int b=0,c;
	Vektor v;
	
	if(n<0){
		b=1;
		n=abs(n);
	}
	
	while(n!=0){
		c=n%10;
		v.push_back(c);
		n=n/10;
		
	}
	int m=0;
	int vel=int(v.size());
	for(int j=0;j<vel;j++){
		m+=v.at(j)*pow(3,j);
	}
	if(b==1){
		m=-m;
		return m;
	}
	else return m;
}

Vektor IzdvojiSimetricneTernarne(Vektor v, bool b){
	
	if(b==1){
		//PROSTI!!!
		
		Vektor v1;
		
		for( int i=0;i<int(v.size());i++){
			if(Provjera(v1,v.at(i)))continue;
			
			if(DaLiJeProst(v.at(i))) v1.push_back(v.at(i));
		}
		
		//v1 VEKTOR PROSTIH BROJEVA!
		
		Vektor v12;
		
		for(int i=0;i<int(v1.size());i++){
			int TB;
			TB=PretvoriUTernarni(v1.at(i));
			v12.push_back(TB);
		}
		
		//v12 VEKTOR TERNARNIH BROJEVA!
		
		Vektor v13;
		for(int i=0;i<int(v12.size());i++){
			if(DaLiJeSimetrican(v12.at(i))) v13.push_back(v12.at(i));
		}
		Vektor v14;
		int DB;
		for(int i=0;i<int(v13.size());i++){
			DB=PretvoriUDkedne(v13.at(i));
			v14.push_back(DB);
		}
		
		return v14;
	}
	else {
		//SLOZENI!!!
		
		Vektor v1;
		
		for( int i=0;i<int(v.size());i++){
			if(Provjera(v1,v.at(i)))continue;
			
			if(!(DaLiJeProst(v.at(i)))) v1.push_back(v.at(i));
		}
		
		//v1 VEKTOR PROSTIH BROJEVA!
		
		Vektor v12;
		
		for(int i=0;i<int(v1.size());i++){
			int TB;
			TB=PretvoriUTernarni(v1.at(i));
			v12.push_back(TB);
		}
		
		//v12 VEKTOR TERNARNIH BROJEVA!
		
		Vektor v13;
		for(int i=0;i<int(v12.size());i++){
			if(DaLiJeSimetrican(v12.at(i))) v13.push_back(v12.at(i));
		}
		Vektor v14;
		int DB;
		for(int i=0;i<int(v13.size());i++){
			DB=PretvoriUDkedne(v13.at(i));
			v14.push_back(DB);
		}
		
		return v14;
	}
}

int main ()
{
	
	cout<<"Unesite elemente vektora (-1 za kraj): ";
	Vektor v;
	int n;
	int m;
	do{
		cin>>n;
		
		if(n!= -1)v.push_back(n);
		else break;
	}while(1==1);	
	
	cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	
	while(1==1){
		if(!(cin>>m)){
			cin.clear();
			cin.ignore(10000,'\n');
			cout<<"Neispravan unos! Unesite ponovo: ";
		}
		else if(m!=0 && m!=1)cout<<"Neispravan unos! Unesite ponovo: ";
		else break;
		
	}
	
	Vektor v1;

	v1=IzdvojiSimetricneTernarne(v,m);
	int vel= int (v1.size());
	
	if(m==1){
		if(vel==0) cout<<"Nema prostih simetricnih brojeva u vektoru."<<endl;
		else {
			cout<<"Prosti simetricni brojevi iz vektora su: ";
		for(int i=0;i<vel;i++){
			if(i==vel-1)cout<<v1[i]<<"."<<endl;
			else cout<<v1[i]<<", ";
		}
		}
	}
	
		if(m==0){
		if(vel==0) cout<<"Nema slozenih simetricnih brojeva u vektoru."<<endl;
		else{
			cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for(int i=0;i<vel;i++){
			if(i==vel-1)cout<<v1[i]<<"."<<endl;
			else cout<<v1[i]<<", ";
		}
		}
	}
	
	return 0;
}