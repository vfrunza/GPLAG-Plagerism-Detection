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

std::vector<int> Pretvori(int n){
	int i;
	std::vector<int> a;
	do {
		i=n%3;
		n=n/3;
		a.push_back(i);
	} while (n!=0);
return a;
}

bool DaLiJeProst(int n){
	for (int i=2; i<=std::sqrt(n); i++){
		if (n%i==0 || n<0)
		return false;
	}
	if (n>1) return true;
	if (n<=1) return false;
	return false;
}

std::vector<int> Obrni (std::vector<int> v){
	std::vector<int> obrnuti;
	for (int i=v.size()-1; i>=0; i--){
		obrnuti.push_back(v.at(i));
	}
	return obrnuti;
}

std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> v, bool a){
	std::vector<int> prosti;
	std::vector<int> slozeni;
	for (int i=0; i<v.size(); i++){
		int x(v.at(i));
		if (x<0) x*=-1;
		if (DaLiJeProst(x))
		prosti.push_back(v.at(i));
		else slozeni.push_back(v.at(i));
	}
	
	if (!a) prosti=slozeni;
	
	std::vector <std::vector<int>> ternarni;
	for (int i=0; i<prosti.size(); i++){	
		int x(prosti.at(i));
		if (x<0) x*=-1;
		ternarni.push_back(Pretvori(x));
	}
	
	std::vector <std::vector<int>> obrnuti;
	for(int i=0; i<ternarni.size(); i++){
		obrnuti.push_back(Obrni(ternarni.at(i)));
	}
	
	std::vector<int> simetricni;
	for (int i=0; i<ternarni.size(); i++){
			if (ternarni.at(i)==obrnuti.at(i)) simetricni.push_back(prosti.at(i));
		}
		
		for (int i=0; i<simetricni.size(); i++){
			for (int j=i+1; j<simetricni.size(); j++){
				if (simetricni.at(i)==simetricni.at(j)){
				 simetricni.erase(simetricni.begin()+j);
				 j--;
				}
			}
		}
		
	return simetricni;
}
	
int main ()
{
	
std::vector<int> a;
int n;
std::cout << "Unesite elemente vektora (-1 za kraj): ";
std::cin >> n;
int x;
do {
	std::cin >> x;
	if (x==-1) break;
	a.push_back(x);
} while (x!=(-1));

int tacno;
std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
while(1) {
	std::cin >> tacno;
	if (tacno==0 || tacno==1) break;
	std::cout <<  "Neispravan unos! Unesite ponovo: ";
};
bool pitanje=tacno;
std::vector<int> vektor=IzdvojiSimetricneTernarne(a,pitanje);

int i;
if (vektor.size()==0){
	if (tacno) std::cout << "Nema prostih simetricnih brojeva u vektoru." << std::endl;
	if (!tacno) std::cout << "Nema slozenih simetricnih brojeva u vektoru." << std::endl;
} else {
	if (tacno) std::cout << "Prosti simetricni brojevi iz vektora su: ";
	if (!tacno) std::cout << "Slozeni simetricni brojevi iz vektora su: ";

	for (i=0; i<vektor.size()-1; i++){
		std::cout << vektor.at(i) << ", ";
} 
std::cout << vektor.at(i) << "." << std::endl;
}
	return 0;
}