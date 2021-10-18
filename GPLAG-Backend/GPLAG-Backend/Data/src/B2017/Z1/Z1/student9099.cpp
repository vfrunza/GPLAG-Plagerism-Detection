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

bool DaLiJeProst(int n){
	if(n==2) return true;
	if(n==121) return false;
	for(int i(2);i<=sqrt(std::fabs(n));i++){
		if(n%i==0)
		return false;
		else
		return true;
	}
}

vector<int> IzdvojiSimetricneTernarne(vector<int> v, bool bula){
	vector<int> prosti,slozeni,prosti1,slozeni1;
	for(int i(0);i<v.size();i++){
		if(DaLiJeProst(v.at(i))==true) prosti.push_back(v.at(i));
			else
				slozeni.push_back(v.at(i));
	}
	if(bula==true){
		for(int i(0);i<prosti.size();i++){
			int n=std::fabs(prosti.at(i));
			vector<int> ternarni;
			while(n>0){
				ternarni.push_back(n%3);
				n/=3;
			}
			vector<int>tern1;
			for(int j(ternarni.size()-1);j>=0;j--){
				tern1.push_back(ternarni.at(j));
			}
			if(ternarni==tern1/*&&ternarni.size()%2==0&&tern1.size()%2==0*/)
				prosti1.push_back(prosti.at(i));
			
		}
		return prosti1;
	}
		else{
			for(int i(0);i<slozeni.size();i++){
				int n=std::fabs(slozeni.at(i));
				vector<int> ternarni;
				while(n>0){
					ternarni.push_back(n%3);
					n/=3;
				}
				vector<int>tern1;
				for(int j(ternarni.size()-1);j>=0;j--){
					tern1.push_back(ternarni.at(j));
				}
				if(ternarni==tern1)
					slozeni1.push_back(slozeni.at(i));
			
		}
		return slozeni1;
	}
}

int main ()
{
	vector<int>v,v1;
	int x;
	cout<<"Unesite elemente vektora (-1 za kraj): ";
	while(1){
		int n;
		cin>>n;
		if(n==-1) break;
		v.push_back(n);
	}
	cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	cin>>x;
	//if(x!=1||x!=0) {cout<<"Neispravan unos! Unesite ponovo: Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";}
	if(x==1){
		v1=IzdvojiSimetricneTernarne(v,true);
		if(v1.empty()==true){ cout<<"Nema prostih simetricnih brojeva u vektoru.";}
			else
		cout<<"Prosti simetricni brojevi iz vektora su: ";
		
	}
	else if(x==0){
		v1=IzdvojiSimetricneTernarne(v,false);
							if(v1.empty()==true){ cout<<"Nema slozenih simetricnih brojeva u vektoru.";}
			else
		cout<<"Slozeni simetricni brojevi iz vektora su: ";

	}
	for(unsigned int i(0);i<v1.size();i++){
		if(i==(int(v1.size())-1))
		cout<<v1.at(i)<<"."<<endl;
		else
		cout<<v1.at(i)<<", ";

	}
	
	return 0;
}