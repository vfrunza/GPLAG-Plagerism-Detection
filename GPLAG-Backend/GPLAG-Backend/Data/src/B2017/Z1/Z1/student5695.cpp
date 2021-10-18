#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool JeLiProst(int a) {
	if(a==2) return true;
	for(int i=2;i<a/2;i++) {
		if(a%i==0) return false;
	}
	return true;
}

vector<int> PrebaciUTernarni(int broj) {
	vector<int> ternarni;
	if(broj==0) ternarni.push_back(0);
	else {
		while(broj!=0) {
			ternarni.push_back(broj%3);
			broj/=3;
		}
	}
	return ternarni;
}

bool JeLiSimetrican(int broj) {
	broj=fabs(broj);
	vector<int> ternarni(PrebaciUTernarni(broj));
	for(int i=0;i<ternarni.size()/2;i++) {
		if(ternarni.at(i)!=ternarni.at(ternarni.size()-1-i)) return false;
	}
	return true;
}

vector<int> IzdvojiSimetricneTernarne(vector<int> vektor, bool a) {
	vector<int> rezultantni_vektor;
	for(int i=0;i<vektor.size()-1;i++) {
		for(int j=i+1;j<vektor.size();j++) {
			if(vektor.at(i)==vektor.at(j)) {
				vektor.erase(vektor.begin()+j);
				j--;
			}
		} 
	}
	for(int i=0;i<vektor.size();i++) {
		if(JeLiProst(vektor.at(i))==a && vektor.at(i)!=1) {
			if(JeLiSimetrican(vektor.at(i))) rezultantni_vektor.push_back(vektor.at(i));
		}  
	}
	return rezultantni_vektor;
}

int main() {
	vector<int> vektor;
	cout << "Unesite elemente vektora (-1 za kraj): ";
	int n(0);
	for(;;) {
		cin >> n;
		if(n==-1) break;
		vektor.push_back(n);
	}
	cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	cin >> n;
	while(n!=1 && n!=0) {
		cout << "Neispravan unos! Unesite ponovo: ";
		cin >> n;
	}
	if(n==1) {
		vector<int> finalni_vektor(IzdvojiSimetricneTernarne(vektor,1));
		if(finalni_vektor.size()==0) cout << "Nema prostih simetricnih brojeva u vektoru.";
		else {
			cout << "Prosti simetricni brojevi iz vektora su: ";
			for(int i=0;i<finalni_vektor.size();i++) {
				if(i==finalni_vektor.size()-1) cout << finalni_vektor.at(i) << "." << endl;
				else cout << finalni_vektor.at(i) << ", ";
			}
		}
	}
	else if(n==0) {
		vector<int> finalni_vektor(IzdvojiSimetricneTernarne(vektor,0));
		if(finalni_vektor.size()==0) cout << "Nema slozenih simetricnih brojeva u vektoru.";
		else {
			cout << "Slozeni simetricni brojevi iz vektora su: ";
			for(int i=0;i<finalni_vektor.size();i++) {
				if(i==finalni_vektor.size()-1) cout << finalni_vektor.at(i) << "." << endl;
				else cout << finalni_vektor.at(i) << ", ";
			}
		}
	}
	return 0;
}