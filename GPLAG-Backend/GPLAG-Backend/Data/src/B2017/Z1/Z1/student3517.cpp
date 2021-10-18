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

bool JeLiProst (int n)
{
	if(n==0) return false;
	if(n<0) n=-n;
	for(int i=2; i<=int(std::sqrt(n)); i++) {
		if(n%i==0) return false;
	}
	return true;
}
int PretvoriUTernarni (int n) {
	
	int br(n), ternarni=0, t=1;
	while(br!=0) {
		if(br%3>0.5) {
			ternarni=ternarni+t*2;
			t=t*10;
			br/=3;
		}
		else if(br%3<0.5) {
			ternarni=ternarni+t*1;
			t*=10;
			br/=3;
		}
	}
	return ternarni;
}
bool JeLiSimetrican(int n)
{
	int broj=PretvoriUTernarni(n);
	int brojac=0;
	std::vector<int> c;
	
	while(broj!=0) {
		int cifra=n%10;
		brojac++;
		broj/=10;
		c.push_back(cifra);
	}
	for(int i=0; i<brojac/2; i++) {
		if(c.at(i) != c.at(brojac-1-i)) return false;
	}
	return true;
}

std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> v, bool prosti) {

	std::vector<int> v1;
	std::vector<int> v2;
	//proste stavlja u v1 a slozene u v2
	for(int i=0; i<v.size(); i++) {
		if(prosti==1) {
			if(JeLiProst(v.at(i))) {
				v1.push_back(v.at(i));
			}
		} else {
			if(!JeLiProst(v.at(i))) {
				v2.push_back(v.at(i));
			}
		}
	}
	/*Izbacuje brojeve koji nisu simetricni
	for( int i=0; i<v1.size(); i++) {
		if(!JeLiSimetrican(v1.at(i))) {
			v1.erase(v1.begin()+i);
		}
	}
	for( int i=0; i<v2.size(); i++) {
		if(!JeLiSimetrican(v2.at(i))) {
			v2.erase(v2.begin()+i);
		}
	} */
   
	std::vector<int> v3;
	if(prosti) {
		for(int i=0; i<v1.size(); i++) {
			int br;
			int cifra;
			int novi_broj=0, t=1;
			br=v1.at(i);
			while(br!=0) {
				if(br%3>0.5) {
					novi_broj=novi_broj+t*2;
					t=t*10;
					br/=3;
				} else if(br%3<0.5) {
					novi_broj=novi_broj+t*1;
					t=t*10;
					br/=3;
				}
			}
			if(JeLiSimetrican(novi_broj))
			v3.push_back(v1.at(i));
		}
		return v3;
	} 
	std::vector<int> v4;
	if(!prosti) {
		for(int i=0; i<v2.size(); i++) {
			int cifra, novi_broj=0, t=1, br;
			br=v2.at(i);
			while(br!=0) {
				if(br%3>0.5) {
					novi_broj=novi_broj+t*2;
					t=t*10;
					br/=3;
				} else if(br%3<0.5) {
					novi_broj=novi_broj+t*1;
					t=t*10;
					br/=3;
				}
			}
			if(JeLiSimetrican(novi_broj));
			v4.push_back(v2.at(i));
		}
	}
	return v4;
}

int main ()
{
	std::vector<int> v;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	int br;
	do {
		std::cin>>br;
		if(br!=-1) v.push_back(br);
	} while(br!=-1);

	int n;
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	do {
		std::cin>>n;
		if(n==1 || n==0) break;
		else if(n!=1 || n!=0) {
			std::cout<<"Neispravan unos! Unesite ponovo: ";
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
	} while(n!=1 || n!=0);

	std::vector<int> T;
	T=IzdvojiSimetricneTernarne(v,n);
	if(n==1 && T.size()==0) {
		std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		return 0;
	}
	else if(n==0 && T.size()==0){
		std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		return 0;
	}
    if(n==1) {
	std::cout<<"Prosti simetricni brojevi iz vektora su: ";
	for( int i=0; i<T.size(); i++) {
		std::cout<<T.at(i)<<" ";
	} }
	else if(n==0) {
		std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for(int i=0; i<T.size(); i++) {
			std::cout<<T.at(i)<<" ";
		}
	}
	return 0;
}