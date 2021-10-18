#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;

typedef std::vector<double> Vektor;
typedef std::vector<std::vector<double>> Matrica;

constexpr double EPSILON = 0.00000000000001;

Matrica RastuciPodnizovi(Vektor niz){
	Matrica rezultat;
	int combo(1),redovi(0);
	bool zadnji_upada(false);
	for(unsigned int i=0; i<niz.size(); i++) {
		if(!i) continue;
		if(( niz.at(i)>niz.at(i-1) or fabs(niz.at(i)-niz.at(i-1))<EPSILON) ){
            if(i==niz.size()-1) zadnji_upada=true;
			combo++;
            if(i!=niz.size()-1) continue;
		}
		if(combo>1){
			rezultat.resize(++redovi);
			if(zadnji_upada)
                for(int j=combo-1; j>=0; j--) rezultat.at(redovi-1).push_back(niz.at(i-j));
            else
                for(unsigned int j=combo; j>0; j--) rezultat.at(redovi-1).push_back(niz.at(i-j));
			combo=1;
		}
	}
	return rezultat;
}

Matrica OpadajuciPodnizovi(Vektor niz){
	Matrica rezultat;
	int combo(1),redovi(0);
	bool zadnji_upada(false);
	for(unsigned int i=0; i<niz.size(); i++) {
		if(!i) continue;
		if(( niz.at(i)<niz.at(i-1) or fabs(niz.at(i)-niz.at(i-1))<EPSILON) ){
            if(i==niz.size()-1) zadnji_upada=true;
			combo++;
            if(i!=niz.size()-1) continue;
		}
		if(combo>1){
			rezultat.resize(++redovi);
			if(zadnji_upada)
                for(int j=combo-1; j>=0; j--) rezultat.at(redovi-1).push_back(niz.at(i-j));
            else
                for(unsigned int j=combo; j>0; j--) rezultat.at(redovi-1).push_back(niz.at(i-j));
			combo=1;
		}
	}
	return rezultat;
}

int main ()
{
	Vektor vektor;
	double clan;
	int broj;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>broj;
	if(!cin){
			cout<<"Pogresan unos!!!";
			return 0;
		}
	cout<<"Unesite elemente vektora: ";
	while(broj>0){
		broj--;
		cin>>clan;
		if(!cin){
			cout<<"Pogresan unos!!!";
			return 0;
		}
		vektor.push_back(clan);
	}
	cout<<"Maksimalni rastuci podnizovi:\n";
	Matrica rez(RastuciPodnizovi(vektor));
	for(auto red:rez){
		for(auto clan:red){
			cout<<std::setprecision(12)<<clan<<" ";
		}
		cout<<"\n";
	}
	rez=OpadajuciPodnizovi(vektor);
	cout<<"Maksimalni opadajuci podnizovi:\n";
	for(auto red:rez){
		for(auto clan:red){
			cout<<std::setprecision(12)<<clan<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
