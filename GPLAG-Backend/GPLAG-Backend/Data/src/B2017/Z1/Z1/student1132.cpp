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
#include <deque> 
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

bool Prost (int n)

{

  if(n<0) n*=-1; // ne pravimo razliku izmedu pozitivnih i negativnih brojeva,npr. -3 cemo smatrati prostim
	
  if(n<=1) return false;

  bool prost {true};

  for(int i=2; i<=std::sqrt(n); i++) {  //Dovoljno je gornju granicu petlje postaviti na kvadratni korijen od n
    if(n%i==0) return false;
  }


  return prost;

}

int DajTernarni (int n){
	
	int predznak{1};
	if(n<0) predznak=-1;
	
	int temp{std::abs(n)},ternarni{0};
	
	do{
		
		
		ternarni=ternarni*10+temp%3;
		
		temp/=3;
		
	}while(temp);
	
	if(n%3==0) ternarni*=10;
	
	temp=ternarni;
	ternarni=0;
	int cifra{0};
	
	
	do{
		cifra=temp%10;
		ternarni=ternarni*10+cifra;
		temp/=10;
		
	}while(temp);
	
	if(n%3==0) ternarni*=10;
	
	return ternarni*predznak;
	
}


bool Simetrican (int n){
	
	std::vector<int> ter;
	int cifra,temp{std::abs(n)};
	
	do{
		cifra=temp%10;
		ter.push_back(cifra);
		temp/=10;
		
	}while(temp);
	

	
	for(int i=0;i<=(ter.size()/2);i++){
		
		if(ter.at(i)!=ter.at(ter.size()-i-1)) return false;
	}
	
	
	return true;
}



std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v, bool t){
	
	
	std::vector<int> c;
	std::vector<bool> pojavljuje_se_1(v.size(),true);
	
	for(int i=0;i<v.size();i++){
		for(int j=i-1;j>=0;j--){
			if (v.at(i)==v.at(j)){
				pojavljuje_se_1.at(i)=false;
				break;
		}
	}
	}
	
	for(int i=0;i<v.size();i++){
		
		
		if(t){
			if(Prost(v.at(i)) && Simetrican(DajTernarni(v.at(i))) && pojavljuje_se_1.at(i))	  c.push_back(v.at(i));
		}
			
		
		else {
			
			if(!Prost(v.at(i)) && v.at(i)!=1 && v.at(i)!=-1 && Simetrican(DajTernarni(v.at(i))) && pojavljuje_se_1.at(i))  c.push_back(v.at(i));
			
		}
		
	}
	
	
	return c;
}

int main ()
{
	cout<<"Unesite elemente vektora (-1 za kraj): ";
	std::vector<int> v;
	
	int clan;
	
	do{
		
		cin>>clan;
		if(clan!=-1) v.push_back(clan);
		
	}while(clan!=-1);
	
	cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";

	
	int t;
	cin>>t;
	
	while((t!=0 && t!=1) || !cin){
		
		cout<<"Neispravan unos! Unesite ponovo: ";
		cin>>t;
		while(!cin) {
		cout<<"Neispravan unos! Unesite ponovo: ";
		std::cin.clear();
		std::cin.ignore(10000,'\n');
		cin>>t;
		}
	}
	
	
	
	if(t==1){
		std::vector<int> a (IzdvojiSimetricneTernarne(v,true));
		if(a.size()!=0){
		cout<<"Prosti simetricni brojevi iz vektora su: ";
		
		for(int i=0;i<a.size();i++){
			if(i==a.size()-1) cout<<a.at(i)<<"."<<endl;
			else cout<<a.at(i)<<", ";
	}
		}
		else cout<<"Nema prostih simetricnih brojeva u vektoru."<<endl;
	}
	
	else {
		
		std::vector<int> a (IzdvojiSimetricneTernarne(v,false));
		if(a.size()!=0){
			cout<<"Slozeni simetricni brojevi iz vektora su: ";
		
		for(int i=0;i<a.size();i++){
			if(i==a.size()-1) cout<<a.at(i)<<"."<<endl;
			else cout<<a.at(i)<<", ";
	}
		}
		else cout<<"Nema slozenih simetricnih brojeva u vektoru."<<endl;
	}
	

	
	return 0;
}
