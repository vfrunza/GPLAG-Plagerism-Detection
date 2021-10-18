/*B 2017/2018, Zadaća 1, Zadatak 3
	
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

using namespace std;

typedef deque <vector <int>> DekVektora;

enum Smjer { Rastuci=true, Opadajuci=false } ;

bool StepenDvojke(int x){
	
	double broj(x);	
	
	if (broj < 0) return false;
	
	while(broj > 1)
		broj = broj/2;
	
	if(broj == 1) return true;
	
	return false;
	
}

DekVektora MaksimalniPodnizoviStepenaDvojke(vector <int> v, enum Smjer a){
		
		DekVektora dek;
		
		if(v.size() == 0) return dek;
		
		int br(1);
		
		for(int i = 0; i < v.size() - 1; i++){
			
			if(a == Rastuci){
				
				if( !StepenDvojke (v.at(i) ) || !StepenDvojke (v.at(i+1) ) ) continue;
			
				if(v.at(i+1) > v.at(i)){
				
					dek.resize(br);
					dek.at(br-1).push_back(v.at(i));
					dek.at(br-1).push_back(v.at(i+1));
				
					i++;
					
					if(i == v.size()-1) break;
				
					while(v.at(i+1) > v.at(i)){
					
						if(!StepenDvojke(v.at(i+1))) break;
					
						dek.at(br-1).push_back(v.at(i+1));
					
						i++;
						
						if(i == v.size()-1) break;
					
					}
					br++;
				}
			}
			
			if(a == Opadajuci){
			
				if(!StepenDvojke(v.at(i)) || !StepenDvojke(v.at(i+1))) continue;
			
				if(v.at(i+1) < v.at(i)){
				
					dek.resize(br);
					dek.at(br-1).push_back(v.at(i));
					dek.at(br-1).push_back(v.at(i+1));
				
					i++;
					
					if(i == v.size()-1) break;
				
					while(v.at(i+1) < v.at(i)){
					
					
						if(!StepenDvojke(v.at(i+1))) break;
					
						dek.at(br-1).push_back(v.at(i+1));
					
						i++;
					
						if(i == v.size()-1) break;
						
					}
					br++;
				}
			}
			
		}
	return dek;
}

int main ()
{
	cout<<"Unesite broj elemenata vektora: ";
	
	int n;
	
	cin>>n;
	
	if(n < 0) { cout<<"Broj elemenata vektora mora biti pozitivan;"; return 0; } 
	
	cout<<"Unesite elemente vektora: ";
	
	vector <int> v;
	
	int broj;
	
	for(int i = 0; i < n; i++){
		
		cin>>broj;
		v.push_back(broj);
	
	}
	
	cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	
	int a;
	cin>>a;
	
	while(a != 1 && a != 2) cin>>a;
	DekVektora d;
	
	if(a == 2){
	
		d=MaksimalniPodnizoviStepenaDvojke(v,Smjer(false));
		
		cout<<"Maksimalni opadajuci podnizovi: "<<endl;
		
			for(auto v : d){
			for(auto x  : v)
				cout<<x<<" ";
			cout<<endl;
		}
	
		
	}
	else if(a == 1){
		
		d=MaksimalniPodnizoviStepenaDvojke(v,Smjer(true));
		
		cout<<"Maksimalni rastuci podnizovi: "<<endl;
		
		for(auto v : d){
			for(auto x  : v)
				cout<<x<<" ";
			cout<<endl;
		}
	}
	
	return 0;
}












