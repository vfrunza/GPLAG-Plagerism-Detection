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

using std::cin;
using std::cout;

typedef std::deque<std::vector<int>> Matrica;

enum Smjer{Rastuci=true, Opadajuci=false};


bool JeLiStepenDvojke(int x) {
	if(x<1) return false;
	while(x!=1) {
		if(x%2!=0) return false;
		x/=2;
	}
	return true;
}

Matrica MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, enum Smjer s) {
	Matrica povratni;
	if(v.size()==0) return povratni;
	if(s==true) {
	for(int i=0; i<v.size()-1; i++) {
		std::vector<int> pomocni;
		while(v.at(i)<=v.at(i+1) && JeLiStepenDvojke(v.at(i)) && JeLiStepenDvojke(v.at(i+1))) {
			pomocni.push_back(v.at(i));
			i++;
			if(i==v.size()-1) break;
		}
		if(i>0 && JeLiStepenDvojke(v.at(i)) && JeLiStepenDvojke(v.at(i-1)) && v.at(i)>=v.at(i-1)) pomocni.push_back(v.at(i));
		povratni.push_back(pomocni);
	}
	}
	else {
		for(int i=0; i<v.size()-1; i++) {
			std::vector<int> pomocni;
			while(v.at(i)>=v.at(i+1) && JeLiStepenDvojke(v.at(i)) && JeLiStepenDvojke(v.at(i+1))) {
				pomocni.push_back(v.at(i));
				
				i++;
				if(i==v.size()-1) break;
			}
			if(i>0 && JeLiStepenDvojke(v.at(i)) && JeLiStepenDvojke(v.at(i-1)) && v.at(i)<=v.at(i-1)) pomocni.push_back(v.at(i));
			povratni.push_back(pomocni);
		}
	}
	return povratni;
}


int main ()
{
	int n;
	cout<<"Unesite broj elemenata vektora: ";	
	cin>>n;
	std::vector<int> v;
	cout<<"Unesite elemente vektora: ";
	int x;
	for(int i=0; i<n; i++) {
		cin>>x;
		v.push_back(x);
	}
	int smjer;
	cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	cin>>smjer;;
	Matrica mat;
	if(smjer==1)
	mat=MaksimalniPodnizoviStepenaDvojke(v,Rastuci);
	else mat=MaksimalniPodnizoviStepenaDvojke(v,Opadajuci);
	if(smjer==1) cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	else cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for(auto dek : mat) {
		for(auto vektor : dek) {
			cout<<vektor<<" ";
		}
		cout<<std::endl;
	}
	
	return 0;
}