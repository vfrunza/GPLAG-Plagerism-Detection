/*B 2017/2018, Zadaća 1, Zadatak 3*/
#include <iostream>
#include <vector>
#include <deque>

typedef std::vector<int> Vektor;
typedef std::deque<Vektor> Matrica;
enum Smjer{Rastuci=1, Opadajuci};

bool StepenDvojke(int n){
	if(n==0) return false;
	while(n != 1){
		if(n%2 != 0) return false;
		n /= 2;
	}
	return true;
}

Matrica MaksimalniPodnizoviStepenaDvojke(Vektor v, Smjer smjer){
	Matrica m;
	for(int i=0; i<v.size(); i++){
		if(!StepenDvojke(v.at(i))) continue;
		if(i+1<v.size()){
			i++;
			if(!StepenDvojke(v.at(i))) continue;
			else if((smjer == Opadajuci && v.at(i) > v.at(i-1)) || (smjer == Rastuci && v.at(i) < v.at(i-1))) {
				i--; //treba i njega provjeriti - niz moze biti opadaj/rastuci od tog clana
				continue;
			}
			Vektor vtmp;
			vtmp.push_back(v.at(i-1));
			vtmp.push_back(v.at(i));
			while(i+1<v.size() && StepenDvojke(v.at(i+1)) && ((smjer == Opadajuci && v.at(i+1) <= v.at(i)) || (smjer == Rastuci && v.at(i+1) >= v.at(i)))){
				i++;
				vtmp.push_back(v.at(i));
			}
			m.push_back(vtmp);
		}
	
	}
	return m;
}

using std::cout;
using std::endl;
using std::cin;
int main (){
	cout << "Unesite broj elemenata vektora: ";
	int n;
	cin >> n;
	cout << "Unesite elemente vektora: ";
	Vektor vec;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		vec.push_back(x);
	}
	cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	cin >> n;
	Smjer smjer(Rastuci);
	if(n == 1) cout << "Maksimalni rastuci podnizovi: ";
	else if(n == 2) {
		smjer = Opadajuci;
		cout << "Maksimalni opadajuci podnizovi: ";
	}
	else return 0; //??
	cout << endl;
	Matrica mat(MaksimalniPodnizoviStepenaDvojke(vec, smjer));
	for(int i=0; i<mat.size(); i++){
		for(int j=0; j<mat.at(i).size(); j++)
			cout << mat.at(i).at(j) << " ";
		cout << endl;
	}

	return 0;
}