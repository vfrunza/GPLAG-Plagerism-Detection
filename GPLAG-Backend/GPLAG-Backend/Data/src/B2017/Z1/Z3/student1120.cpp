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

using namespace std;

	enum Smjer{Rastuci=true, Opadajuci=false};

	bool jelistependvojke(int n){
		for(int i=1;i<=n;i*=2){
			if(i<0)return false;
			if(n==i)return true;
		}
		return false;
	}
	
deque<vector<int>> MaksimalniPodnizoviStepenaDvojke(vector<int>v, Smjer mogucnost){
		deque<vector<int>>d;
		if(v.size()==0)return d;
		if(mogucnost==Rastuci){
		for(int i=0;i<int(v.size());i++){
		
			if(jelistependvojke(v.at(i)) && jelistependvojke(v.at(i+1)) && v.at(i+1)>v.at(i)){
				vector<int>pom;
				while(i<v.size() && jelistependvojke(v.at(i)) && jelistependvojke(v.at(i+1)) && v.at(i+1)>v.at(i)){
					pom.push_back(v.at(i));
					i++;
					if(i==int(v.size()-1))break;
				}
				pom.push_back(v.at(i));
				d.push_back(pom);
			}
			if(i==int(v.size()-1))break;
	}
		}
	else if(mogucnost==Opadajuci){
		for(int i=0;i<int(v.size());i++){
			if(jelistependvojke(v.at(i)) && jelistependvojke(v.at(i+1)) && v.at(i+1)<v.at(i)){
				vector<int>pom;
				while(i<v.size() && jelistependvojke(v.at(i)) && jelistependvojke(v.at(i+1)) && v.at(i+1)<v.at(i)){
					pom.push_back(v.at(i));
					
					i++;
					if(i==int(v.size()-1))break;
				}
				pom.push_back(v.at(i));
				d.push_back(pom);
			}
			if(i==int(v.size()-1))break;
	}
	}
	return d;
}
int main ()
{
	int n;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>n;
	vector<int>v;
	cout<<"Unesite elemente vektora: ";
	for(int i=0;i<n;i++){
		int broj;
		cin>>broj;
		v.push_back(broj);
	}
	
	int odaberi;
	cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	cin>>odaberi;
	
	if(odaberi==1){
		deque<vector<int>>d=MaksimalniPodnizoviStepenaDvojke(v, Rastuci);
		cout<<"Maksimalni rastuci podnizovi: "<<endl;
		for(auto x: d){
			for(auto y: x)cout<<y<<" ";
			cout<<endl;
		}
	}
		else{
			deque<vector<int>>d=MaksimalniPodnizoviStepenaDvojke(v, Opadajuci);
			cout<<"Maksimalni opadajuci podnizovi: "<<endl;
			for(auto x: d){
				for(auto y: x)cout<<y<<" ";
				cout<<endl;
			}
		}
	
	return 0;
}