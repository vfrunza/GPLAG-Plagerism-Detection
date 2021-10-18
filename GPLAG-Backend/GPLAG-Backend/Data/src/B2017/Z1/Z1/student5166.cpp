//B 2017/2018, Zadaća 1, Zadatak 1
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool DaLiJeProst (int n){
	bool prost(true);
	if (n <= 1) prost = false;
	for (int i=1; i<=sqrt(n); i++){
		if (n%i==0 && i!=1 && i!=n) prost = false;
	}
	return prost;
} 
 
bool DaLiJePalindrom (int n){
	int temp = n;
	int flag = 0;
	while (temp){
		flag *= 10;
		flag += temp % 10;
		temp /= 10;
	}
	return (n == flag);
}

long long Decimalni_u_Ternarni (int n){
	long long ternarni_broj = 0;
	int cifra, i=1; 
	while (n!=0){
		cifra = n%3;
		n = n/3;
		ternarni_broj += cifra*i;
		i*=10;
	}
	return DaLiJePalindrom(ternarni_broj);
}

vector<int>IzdvojiSimetricneTernarne (vector<int>v, bool a){
	vector<int>novi;
	
	if (a == true){
	    for (int i=0; i<v.size(); i++){
	    	if (DaLiJeProst(v.at(i)) && Decimalni_u_Ternarni(v.at(i)))  
	        	novi.push_back(v.at(i));
	    }
	    if (novi.size()==0) cout << "Nema prostih simetricnih brojeva u vektoru.";
	    else {
	        cout << "Prosti simetricni brojevi iz vektora su: ";
	        for (int i=0; i<novi.size(); i++){
	            if (i==novi.size()-1) cout << novi.at(i) << ".";
	            else cout << novi.at(i) << ", ";
	        }
	    }
	} 
	
	else {
		for (int i=0; i<v.size(); i++){
			if (!DaLiJeProst(v.at(i)) && Decimalni_u_Ternarni(v.at(i)))
			    novi.push_back(v.at(i));
		}
		if (novi.size()==0) cout << "Nema slozenih simetricnih brojeva u vektoru.";
		else {
			cout << "Slozeni simetricni brojevi iz vektora su: ";
			for (int i=0; i<novi.size(); i++){
				if (i==novi.size()-1) cout << novi.at(i) << ".";
				else cout << novi.at(i) << ", ";
			}
		}
	}
	    
	return novi;    
}

int main (){
	
	vector<int>v;
	int n;
	cout << "Unesite elemente vektora (-1 za kraj): ";
	while (cin >> n, n!=(-1)){
		v.push_back(n);
	}
	
	bool a;
	cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	for (;;){
		cin >> a;
		if (cin && (a==1 || a==0)) break;
		else {
			cout << "Neispravan unos! Unesite ponovo: ";
			cin.clear();
		}
	}
	
	IzdvojiSimetricneTernarne(v,a);

	return 0;
}