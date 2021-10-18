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

bool sadrzi(vector<int> v,int n){
	for(int x:v){
		if(x==n)return true;
	}
	return false;
	
}

bool Prost(int n){
	if(n==0)return false;
	n=fabs(n);

    if(n==0 )return false;
	for(int i=2;i<=sqrt(n);i++)
		if(n%i==0) return false;
	
	return true;
}

bool Isti(int a){
	
	a=fabs(a);
	int temp=a,n=0;
	while(temp>0){
		n=n*10+temp%10;
		temp/=10;
	}
	return(n==a);
}

int Tet(int a){
	
	bool negativan=(a<0);
	int t=0;
	a=fabs(a);
	int temp=a;
	int k=0,n=0;
	
	while(1){
	  int pw=pow(3,k+1);
		if((temp/pw)<=0)break;
		k++;
	}
	
	while(k>=0){
		int ost=0;
		ost=a/pow(3,k);
	t+=pow(10,k)*ost;
	a-=ost*pow(3,k);
	k--;
	}
	if(negativan)t*=-1;
	return t;
	
}

vector<int> IzdvojiSimetricneTernarne(vector<int> v,bool prost){
	
	vector<int> svi;
	
	for(int x:v){
		
		if(prost && Prost(x)&&!sadrzi(v,Tet(x))&&Isti(Tet(x)))svi.push_back(x);
		
		if(!prost && !Prost(x)&&!sadrzi(v,Tet(x))&&Isti(Tet(x)))svi.push_back(x);
		
	
	}
	return svi;
}

int main ()
{
	
	int x;
	
	 vector<int>v;
	 cout<<"Unesite elemente vektora (-1 za kraj): ";
	 while(1){
	 	cin>>x;
	 	if(x==-1)break;
	 	v.push_back(x);
	 }
	 cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	 while(1)
	 {
	 if(!(cin>>x)){cout<<"Neispravan unos! Unesite ponovo: ";cin.clear();cin.ignore(10000, '\n');}
	 else if(x!=1 && x!=0)cout<<"Neispravan unos! Unesite ponovo: ";
	 else break;
	 }
	 
	 v=IzdvojiSimetricneTernarne(v,x);
	 if(v.size()==0){
	 	if(x==1)cout<<"Nema prostih ";
	 else cout<<"Nema slozenih ";
	 	cout<<"simetricnih brojeva u vektoru.";
	 	return 0;
	 	
	 }
	 if(x==1)cout<<"Prosti ";
	 else cout<<"Slozeni ";
	cout<<"simetricni brojevi iz vektora su: ";
	for(int i=0;i<v.size();i++){
	cout<<v.at(i);
	if(i!=v.size()-1)cout<<", ";
	}cout<<".";
	
	return 0;
}