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
#include <deque>
using namespace std;

bool jelprost(int broj){
	if(broj<=0 || broj==1)return false;
	bool pom(true);
	for(int i=2;i<=sqrt(broj);i++){
		if(broj%i==0){
			pom=false;
			break;
		}
	}
	
	return pom;
}

 bool pomocna(int n){
	deque<int>d1,d2;
	do{
		int c=n%3;
		d1.push_front(c);
		d2.push_back(c);
		n/=3;
	}while(n!=0);
	for(int i=0;i<d1.size();i++){
		if(d1.at(i)!=d2.at(i))return false;
	}
	return true;
	
}


	vector<int>IzdvojiSimetricneTernarne(vector<int>v, bool prom){
		vector<int>v1;
		int pom(0);
	if(prom){
			for(int i=0;i<v.size();i++){
				if(i==v.size())break;
				if(v.at(i)<0)
				pom=v.at(i)*(-1);
				pom=v.at(i);
				if(pom==1)continue;
				if(jelprost(pom) && pomocna(pom))
				v1.push_back(v.at(i));
				
			}
		}
		else if(prom==false){
			for(int i=0;i<v.size();i++){
				if(i==v.size())break;
				if(v.at(i)<0)
					pom=v.at(i)*(-1);
					pom=v.at(i);
					if(pom==1)continue;
				if((jelprost(pom)==false) && pomocna(pom))
				v1.push_back(v.at(i));
				
			}
			
		}
		
		for(int i=0;i<int(v1.size())-1;i++){
			for(int j=i+1;j<int(v1.size());j++){
				if(v.at(i)==v.at(j)){
					v1.erase(v1.begin()+j);
					j--;
				}
			}
		
		}
		return v1;
	}
int main ()
{
	vector<int>v;
	cout<<"Unesite elemente vektora (-1 za kraj): ";
	int broj;
	do{
		cin>>broj;
		if(broj==-1)break;
		v.push_back(broj);
	}while(broj!=-1);
	int pom;
	cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	cin>>pom;
	/*vector<int>v1=IzdvojiSimetricneTernarne(v, 1);
	vector<int>v2=IzdvojiSimetricneTernarne(v, 0);
	*/
	

	if(pom!=0 && pom!=1){
		do{
		cout<<"Neispravan unos!"<<" Unesite ponovo: ";
		cin>>pom;
		}while(pom!=0 &&  pom!=1);
	} 
	vector<int>v1=IzdvojiSimetricneTernarne(v, pom);
	if(pom==1){
	if(v1.size()==0){cout<<"Nema prostih simetricnih brojeva u vektoru.";
	return 0;}
	else {cout<<"Prosti simetricni brojevi iz vektora su: ";
	for(int i=0;i<v1.size();i++){
		if(i==v1.size()-1)cout<<v1.at(i)<<".";
		else
		cout<<v1.at(i)<<", ";
	}
	}
	}
	else if(pom==0){
		if(v1.size()==0){cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		return 0;
	}
	else{
		cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for(int i=0;i<v1.size();i++){
			if(i==v1.size()-1)cout<<v1.at(i)<<".";
			else 
			cout<<v1.at(i)<<", ";
		}
	}
	}
	
	return 0;
}