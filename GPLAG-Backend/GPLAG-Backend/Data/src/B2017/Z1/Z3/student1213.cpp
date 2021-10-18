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
#include <stdexcept>
using namespace std;

enum Smjer {Rastuci, Opadajuci};



bool stdvojke(int n) {
	for(int i=0; i<n; i++){
		int step=1;
		for(int j=0; j<i; j++) step*=2;
		if(step==n) return true;
	}
	return false;
}


deque<vector<int>>MaksimalniPodnizoviStepenaDvojke(vector<int> v, Smjer kr) {
	deque<vector<int>> d;
	if(kr==Rastuci) {
		for(int i=0; i<v.size(); i++) {
			vector<int> temp;
			if(stdvojke(v.at(i))) {temp.push_back(v.at(i));}
			i++;
			while(i!=v.size() && v.at(i-1)<=v.at(i) && stdvojke(v.at(i))) 
			{ 
				temp.push_back(v.at(i)); 
				i++;
			}
			if(temp.size()>1) {d.push_back(temp); }
			i--;
		}
	}
	else {
		for(int i=0; i<v.size(); i++) {
			vector<int> temp;
			if(stdvojke(v.at(i))) temp.push_back(v.at(i));
			i++;
			while(i!=v.size() && v.at(i-1)>=v.at(i) && stdvojke(v.at(i))) 
			{ 
				temp.push_back(v.at(i)); 
				i++;
			}
			if(temp.size()>1) d.push_back(temp);
			i--;
		}
	}
	return d;
} 

int main ()
{
	int n;
	vector<int> v;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>n;
	cout<<"Unesite elemente vektora: ";
	for(int i=0; i<n; i++) {
		int pom;
		cin>>pom;
		v.push_back(pom);
	}
	cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int p;
	for(;;) {
		cin>>p;
		if(p!=1 && p!=2) cout<<"Neispravan unos! Unesite ponovo: ";
		break;
	}
	if(p==1) {
		deque<vector<int>> d=MaksimalniPodnizoviStepenaDvojke(v,Rastuci);
		cout<<"Maksimalni rastuci podnizovi: "<<endl;
		for(int i=0; i<d.size(); i++) {
			for(int j=0; j<d.at(i).size(); j++) {
				cout<<d.at(i).at(j)<<" ";
			} cout<<endl;
		}
	}
	else if(p==2) {
		deque<vector<int>> d=MaksimalniPodnizoviStepenaDvojke(v,Opadajuci);
		cout<<"Maksimalni opadajuci podnizovi: "<<endl;
		for(int i=0; i<d.size(); i++) {
			for(int j=0; j<d.at(i).size(); j++) {
				cout<<d.at(i).at(j)<<" ";
			} cout<<endl;
		}
	}
	return 0;
}