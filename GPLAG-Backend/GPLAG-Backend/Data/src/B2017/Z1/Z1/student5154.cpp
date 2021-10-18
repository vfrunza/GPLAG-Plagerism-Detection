/*B 2017/2018, Zadaća 1, Zadatak 1
	
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
#include <cmath>

using namespace std;

bool DaLiJeProst(int n) {
	if(n<=1) n*=-1;
	for(int j=2;j<=sqrt(n);j++) {
	if(n%j==0) return false;
	}
	return true;
}  

std::vector<int> Izdvoji(std::vector<int> v, bool prost) {
	std::vector<int> v1;
	std::vector<int> v2(v.size());
	
	for(int i(0);i<v.size();i++) {
		v2.at(i)=v.at(i);
	}
	
	for(int i=0;i<v2.size();i++) {
		for(int j=i+1;j<v2.size();j++) {
			if(v2.at(j)==v2.at(i)) {
				v2.erase(v2.begin() + j);
				j--;
			}
		}
		if(prost) {
			if(DaLiJeProst(v2.at(i))) v1.push_back(v2.at(i));
		}
		else {
			if(!DaLiJeProst(v2.at(i))) v1.push_back(v2.at(i));
		}
	}
	return v1;
}

std::vector<int> TernarnaReprezentacija(std::vector<int> v, bool prost) {
	std::vector<int> v1(Izdvoji(v,prost));
	int a(0);
	for(int i(0);i<v1.size();i++) {
		int tmp(v1.at(i)), suma(0), j(1);
		while(tmp!=0) {
			a=tmp%3*j;
			suma+=a;
			j*=10;
			tmp/=3;
		}
		v1.at(i)=suma;
	}
	return v1;
}

bool Simetricno(int broj) {
	std::vector<int> v1;
	while(broj!=0) {
		int cifra(broj%10);
		v1.push_back(cifra);
		broj/=10;
	}
	for(int i(0);i<v1.size();i++) {
		if(v1.at(i)!=v1.at(v1.size()-1-i)) return false;
	}
	return true;
}

int TernarniUDecimalni(int broj) {
	int i(0),suma(0);
	while(broj!=0){
		int cifra(broj%10*pow(3,i));
		i++;
		suma+=cifra;
		broj/=10;
	}
	return suma;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v, bool prost) {
	std::vector<int> v1(TernarnaReprezentacija(v,prost));
	std::vector<int> v2;
	for(int i(0);i<v1.size();i++) {
		if(Simetricno(v1.at(i))) v2.push_back(TernarniUDecimalni(v1.at(i)));
	}
	return v2;
}

int main ()
{
	std::vector<int> a;
	cout<<"Unesite elemente vektora (-1 za kraj): ";
	int b;
    for(;;) {
        cin>>b;
        if(cin.fail()){
			cin.clear();
			cin.ignore(10000, '\n');
		}
        if(b==-1) break;
        a.push_back(b);
    }
    int unos;
    cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
    for(;;) {
    	cin>>unos;
    	if(cin.fail()){
    		cin.clear();
    		cin.ignore(10000, '\n');
    		
    	}
    	if(unos!=1 and unos!=0) {
    		cout<<"Neispravan unos! Unesite ponovo: ";
    	}
    	if(unos==1 or unos==0) break;
    }
    if(unos==1) {
    	std::vector<int> c(IzdvojiSimetricneTernarne(a,true));
    	if(c.size()==0) {
    		cout<<"Nema prostih simetricnih brojeva u vektoru.";
    		return 0;
    	}
    	cout<<"Prosti simetricni brojevi iz vektora su: ";
    	for(int i=0;i<c.size();i++) {
    		if(i<c.size()-1) cout<<c.at(i)<<", ";
    		else cout<<c.at(i)<<"."<<endl;
    	}
    }
    if(unos==0) {
    	std::vector<int> c(IzdvojiSimetricneTernarne(a,false));
    	if(c.size()==0) {
    		cout<<"Nema slozenih simetricnih brojeva u vektoru.";
    		return 0;
    	}
    	cout<<"Slozeni simetricni brojevi iz vektora su: ";
    	for(int i=0;i<c.size();i++) {
    		if(i<c.size()-1) cout<<c.at(i)<<", ";
    		else cout<<c.at(i)<<"."<<endl;
    	}
    }
	return 0;
}