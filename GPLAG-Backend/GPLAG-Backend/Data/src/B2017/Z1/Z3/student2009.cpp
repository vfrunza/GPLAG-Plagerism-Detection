#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
#include <limits>
enum Smjer {Rastuci=1,Opadajuci=2};
using std::cout;
using std::cin;
using std::vector;
using std::deque;

bool stepenDvojke(int n){
    if(n==std::numeric_limits<int>::lowest()) return false;
	return (n && !(n&(n-1))); }

deque<vector<int>> MaksimalniPodnizoviStepenaDvojke(vector<int> x, Smjer s){
	deque<vector<int>> y;

	for(int i=0; i<x.size(); i++){
		vector<int> z;
		if(stepenDvojke(x.at(i))) {
			z.push_back(x.at(i));
			if(s==1)
				while(i<x.size()-1 && stepenDvojke(x.at(i+1)) && x.at(i)<=x.at(i+1)) 
					z.push_back(x.at(++i));

			else if(s==2) while(i<x.size()-1 && stepenDvojke(x.at(i+1)) && x.at(i)>=x.at(i+1)) 
					z.push_back(x.at(++i));
	
			if(z.size()>1) y.push_back(z);
		}
	}
	
	return y;
}

int main (){
	int n;
	cout << "Unesite broj elemenata vektora: ";
	do {
		cin>>n;
		if(n<0) { cout << "Neispravan unos! Unesite ponovo: "; cin.ignore(10000,'\n'); }
	} while(n<0);
	if(n==0) return 0;
	vector<int>x(n);
	cout << "Unesite elemente vektora: ";
	for(int i=0; i<x.size(); i++)
		cin>>x.at(i);
	int izbor;
	cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	do {
		cin>>izbor;
		if(!(izbor==1 || izbor==2)) { cout << "Neispravan unos! Unesite ponovo: "; cin.ignore(10000,'\n'); }
	} while(!(izbor==1 || izbor==2));
	deque<vector<int>> z=MaksimalniPodnizoviStepenaDvojke(x,static_cast<Smjer>(izbor));
	if(izbor==1) cout<<"Maksimalni rastuci podnizovi: " << std::endl;
	else cout<<"Maksimalni opadajuci podnizovi: " << std::endl;
	for(vector<int> y: z) {
		for(int x: y) cout << x << " ";
		cout << std::endl;
	}
	return 0;
}