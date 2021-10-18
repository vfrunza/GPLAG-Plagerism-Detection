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


bool Prost (int n) {
	if (n<0) n*=(-1);
	for (int i(2); i<n; i++) 
	if (n%i==0) return false;
return true;
}

std::vector<int> Ternarni (int n) {
	std::vector<int> v;
	if (n<0) n*=-1;
	do {
		int cifra(n%3);
		v.push_back(cifra);
		n/=3;
	} while(n!=0);
return v;
}

bool Simetrican (std::vector<int> v) {
	std::vector<int>v1,v2;
	
	if (v.size()%2!=0) {
	for (int i(0); i<=v.size()/2; i++) v1.push_back(v.at(i));
	for (int i(v.size()-1); i>=v.size()/2; i--) v2.push_back(v.at(i));
	if(v1==v2) return true;
	}
	
	if (v.size()%2==0) {
	for (int i(0); i<v.size()/2; i++) v1.push_back(v.at(i));
	for (int i(v.size()-1); i>=v.size()/2; i--) v2.push_back(v.at(i));
	if(v1==v2) return true;
	}
		
return false;
}


std::vector<int> IzdvojiSimetricneTernarne (std::vector<int>v, bool jeste) {
	std::vector<int> pr_tr, sl_tr;
	for (int i(0); i<v.size(); i++) {
		

		if (!Prost(v.at(i)) && Simetrican(Ternarni(v.at(i))))
		sl_tr.push_back(v.at(i));
		
		if (Prost(v.at(i)) && Simetrican(Ternarni(v.at(i)))) 
		pr_tr.push_back(v.at(i));
	}
	
	for (int i(0); i<pr_tr.size(); i++) {
		for (int j(i+1); j<pr_tr.size(); j++) {
			if (pr_tr.at(i)==pr_tr.at(j)){
				pr_tr.erase(pr_tr.begin()+j);
				j--;
			}		
		}
	}
	
	for (int i(0); i<sl_tr.size(); i++) {
		for (int j(i+1); j<sl_tr.size(); j++) {
			if (sl_tr.at(i)==sl_tr.at(j)){
				sl_tr.erase(sl_tr.begin()+j);
				j--;
			}		
		}
	}
	
	if (jeste) return pr_tr;
	else return sl_tr;
}

int main ()
{
	
	std::vector<int> v; int n;
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	do {
	   std::cin >> n;
	   if (n==-1) break;
	   v.push_back(n);
	}while(n!=-1);
	
	int a;
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	do {
	std::cin >> a;
	if (a==1 || a==0) break;
	if (a!=1 || a!=0) std::cout << "Neispravan unos! Unesite ponovo: ";
	
	
	} while (a!=1 || a!=0);
	
	std::vector<int> pr_tr(IzdvojiSimetricneTernarne(v,a));
	std::vector<int> sl_tr(IzdvojiSimetricneTernarne(v,a));
	
	if (a) {
	if (pr_tr.size()==0) std::cout << "Nema prostih simetricnih brojeva u vektoru.";
	else {
		std::cout << "Prosti simetricni brojevi iz vektora su: ";
		for (int i(0); i<pr_tr.size(); i++) {
		if (i!=pr_tr.size()-1) std::cout << pr_tr.at(i) << ", ";
		else std::cout << pr_tr.at(i) << ".";
	}
	}
	}
	
	if (!a) {
	if (sl_tr.size()==0) std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
	else {
		std::cout << "Slozeni simetricni brojevi iz vektora su: ";
		for (int i(0); i<sl_tr.size(); i++) {
		if (i!=sl_tr.size()-1) std::cout << sl_tr.at(i) << ", ";
		else std::cout << sl_tr.at(i) << ".";
	}
	}
	}
	return 0;
}