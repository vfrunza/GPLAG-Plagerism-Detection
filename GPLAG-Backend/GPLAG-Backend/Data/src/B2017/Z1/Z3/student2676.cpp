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

enum Smjer{Rastuci, Opadajuci};

bool StepenDvojke(int broj){
	if(broj<=0) return false;
	if(broj==1)	return true;
	while(broj != 1){
		if(broj%2 != 0)	return false;
	if(broj==2)	return true;
	broj/=2;
}
return false;
}

deque<vector<int>> MaksimalnPodnizoviStepenaDvojke(vector<int>v, Smjer pretpostavljeni){
	deque<vector<int>>rezultat;
	for(int i(0); i<v.size();i++){
		int brojac(i);
		vector<int>podniz;
		if(pretpostavljeni == Smjer::Rastuci){
			while(brojac+1<v.size()&& v.at(brojac)<=v.at(brojac+1))	 brojac++;
			}
			else{
				while(brojac+1<v.size()&&v.at(brojac)>=v.at(brojac+1))	brojac++;
			}
			for(int j(i);j<=brojac;j++) 	podniz.push_back(v.at(j));
			vector<int>_podniz;
			for(int j(0);j<podniz.size();j++){
				if(StepenDvojke(podniz.at(j)))  	_podniz.push_back(podniz.at(j));
				else break;
			}
			if(_podniz.size()>1){
				rezultat.push_back(_podniz);
				if(_podniz.size()<3) i++;
				else i=brojac;
			}
		//	 i=brojac;
			
		}
		return rezultat;
	}

int main ()
{
	int brojelemenata;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>brojelemenata;
	vector<int> v(brojelemenata);
	cout<<"Unesite elemente vektora: ";
	int brojevi;
	for(int i(0); i<brojelemenata; i++) {
		cin>>brojevi;
		v.push_back(brojevi);
	}
	cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int prom, redoslijed;
	do{
		cin>>prom;
		cin.clear();
		cin.ignore(10000, '\n');
		if(prom == 1 || prom == 2) {
			redoslijed = prom;
			break;
		}
	} while(prom != 1 || prom != 2);
	if(redoslijed == 1) {
	deque<vector<int>> d(MaksimalnPodnizoviStepenaDvojke(v, Rastuci));
		cout<<"Maksimalni rastuci podnizovi: ";
		for(auto x : d) {
		cout<<endl;
		for(auto y : x) cout<<y<<" ";
		}
	}else if(redoslijed==2){
	deque<vector<int>> d(MaksimalnPodnizoviStepenaDvojke(v, Opadajuci));
		cout<<"Maksimalni opadajuci podnizovi: ";
		for(auto x : d) {
			cout<<endl;
			for(auto y : x) cout<<y<<" ";
		}
	}
	
	
	return 0;
}