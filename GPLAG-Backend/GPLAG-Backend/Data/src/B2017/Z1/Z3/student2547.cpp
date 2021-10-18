#include <cmath>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

enum Smjer {Rastuci, Opadajuci};

bool JeLiStepenDvojke(int broj) {
	if(broj<1) return false;
	for(int i=0;i<broj;i++) {
		if(broj==(int)pow(2,i)) return true;
	}
	return false;
}

deque<vector<int>> MaksimalniPodnizoviStepenaDvojke(vector<int> vektor, Smjer monotoni) {
	deque<vector<int>> stepeni_dvojke;
	vector<int> pomocni;
	int m;
	if(monotoni==Rastuci) {
		for(int i=0;i<vektor.size();i++) {
			m=vektor.at(i);
			if(JeLiStepenDvojke(m)) {
				pomocni.push_back(m);
				while(vektor.at(i+1)>=m && JeLiStepenDvojke(vektor.at(i+1))) {
					i++;
					pomocni.push_back(vektor.at(i));
					m=vektor.at(i);
					if(i==vektor.size()-1) break;
				}
				if(pomocni.size()>=2) stepeni_dvojke.push_back(pomocni);
				pomocni.clear();
			}
		}
	}
	if(monotoni==Opadajuci) {
		for(int i=0;i<vektor.size();i++) {
			m=vektor.at(i);
			if(JeLiStepenDvojke(m)) {
				pomocni.push_back(m);
				while(vektor.at(i+1)<=m && JeLiStepenDvojke(vektor.at(i+1))) {
					i++;
					pomocni.push_back(vektor.at(i));
					m=vektor.at(i);
					if(i==vektor.size()-1) break;
				}
				if(pomocni.size()>=2) stepeni_dvojke.push_back(pomocni);
				pomocni.clear();
			}
		}
	}
	return stepeni_dvojke;
}

int main() {
	cout << "Unesite broj elemenata vektora: ";
	int n(0);
	while(n<1) {
		cin >> n;
	}
	cout << "Unesite elemente vektora: ";
	vector<int> v;
	for(int i=0;i<n;i++) {
		int m;
		cin >> m;
		v.push_back(m);
	}
	cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	n=0;
	while(n!=1 && n!=2) cin >> n;
	deque<vector<int>> nizovi;
	if(n==1) {
		cout << "Maksimalni rastuci podnizovi: " << endl;
		nizovi=(MaksimalniPodnizoviStepenaDvojke(v,Rastuci));
	}
	else {
		cout << "Maksimalni opadajuci podnizovi: " << endl;
		nizovi=(MaksimalniPodnizoviStepenaDvojke(v,Opadajuci));
	}
	for(vector<int> i : nizovi) {
		for(int j=0;j<i.size();j++) cout << i.at(j) << " ";
		cout << endl; 
	}
	return 0;
}