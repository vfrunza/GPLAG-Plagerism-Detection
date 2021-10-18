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

using std::cout;
using std::cin;
using std::vector;
using std::endl;
using std::deque;

enum Smjer{Rastuci, Opadajuci};

bool DaLiJeStepenDvojke(int a){
	if((a>0) && (a & (a-1))==0){
		return true;
	}
	else{
		return false;
	}
}

deque<vector<int>> MaksimalniPodnizoviStepenaDvojke(vector<int> v, Smjer z){
	deque<vector<int>> s;
	if(v.size()==0){
		return s;
	}
	if(z==Rastuci){
		for(int i=0;i<v.size()-1;i++){
			vector<int> pomocni;
			if(DaLiJeStepenDvojke(v.at(i)) && DaLiJeStepenDvojke(v.at(i+1)) && (v.at(i+1) >=v.at(i))){
				pomocni.push_back(v.at(i));
				int naredni(i+1);
				while(1){
					if(naredni != v.size() && DaLiJeStepenDvojke(v.at(naredni)) && (v.at(naredni) >= v.at(naredni-1))){
						pomocni.push_back(v.at(naredni));
					}
					else{
						naredni--;
						break;
					}
					naredni++;
				}
				s.push_back(pomocni);
				i=naredni;
			}
		}
	}
	else{
		for(int i=0;i<v.size()-1;i++){
			vector<int> pomocni;
			if(DaLiJeStepenDvojke(v.at(i)) && DaLiJeStepenDvojke(v.at(i+1)) && (v.at(i) >= v.at(i+1))){
				pomocni.push_back(v.at(i));
				int naredni(i+1);
				while(1){
					if(naredni != v.size() && DaLiJeStepenDvojke(v.at(naredni)) && (v.at(naredni-1) >= v.at(naredni))){
						pomocni.push_back(v.at(naredni));
					}
					else{
						naredni--;
						break;
					}
					naredni++;
				}
				s.push_back(pomocni);
				i=naredni;
			}
		}
	}
	return s;
}

int main ()
{
	int n(0);
	cout << "Unesite broj elemenata vektora: ";
	cin >> n;
	vector<int> v;
	int a(0);
	cout << "Unesite elemente vektora: ";
	for(int i=0;i<n;i++){
		cin >> a;
		v.push_back(a);
	}
	Smjer k;
	int x(0);
	cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	for(;;){
		cin >> x;
		if(x==1 || x==2){
			break;
		}
		else{
			cout << "Neispravan unos! Unesite ponovo: ";
		}
	}
	if(x==1){
		k=Rastuci;
	}
	else{
		k=Opadajuci;
	}
	deque<vector<int>> s;
	s=MaksimalniPodnizoviStepenaDvojke(v, k);
	if(k==Rastuci){
		cout << "Maksimalni rastuci podnizovi: " << endl;
		for(vector<int> h : s){
			for(int j : h){
				cout << j << " ";
			}
			cout << endl;
		}
	}
	else{
		cout << "Maksimalni opadajuci podnizovi: " << endl;
		for(vector<int> h : s){
			for(int j : h){
				cout << j << " ";
			}
			cout << endl;
		}
	}
	return 0;
}