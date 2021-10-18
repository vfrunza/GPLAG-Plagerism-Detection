/*B 2017/2018, Zadaća 2, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <utility>
#include <cmath>
#include <type_traits>

using std::vector;

void Ispis(vector<int> v) {
	for(int x : v)
		std::cout<<x<<" ";
}
template <typename kolekcija , typename element>
    bool vecPostoji(kolekcija v, element e ) {
        for(element x : v) 
            if(x==e)
                return true;
        return false;
    }
   
template<typename kolekcija> 
	void Unos(kolekcija &s , int n) {
		int pomocna;
		for(int i=0;i<n;i++) {
			std::cin>>pomocna;
			if(!vecPostoji(s,pomocna))
				s.push_back(pomocna);
			else
				i--;
		}
	} 
 
int funkc(int x, int y) {
	return -2*x+y;
}

bool jeProst(int n) {
	
	if(n<=1)
		return false;
	for(int i=2;i<=sqrt(n);i++) {
		if(n%i==0) 
			return false;
	}
	return true;
}

int brojProstihFaktora(int x) {
	int brojac=0;
	while(true) {
		for(int i=2;i<=x;i++) {
			if(x%i==0 && jeProst(i)) {
				brojac++;
				x/=i;
				break;
			}
		}
		if(x<=1)
			break;
	}
	return brojac;
}
bool viseProstihFaktora(int x,int y) {
	if(brojProstihFaktora(x)==brojProstihFaktora(y))
		return x>y;
	return brojProstihFaktora(x)>brojProstihFaktora(y);
}

template <typename iterTip1 , typename iterTip2,typename iterTip3>
	void SortirajPodrucjeVrijednosti(iterTip1 p1,iterTip1 k1,iterTip2 p2,iterTip3 p3,
		typename std::remove_reference<decltype(*p3)>::type (*f)(typename std::remove_reference<decltype(*p1)>::type,typename std::remove_reference<decltype(*p1)>::type),       // peti parametar
			bool (*krit)(typename std::remove_reference<decltype(*p1)>::type,typename std::remove_reference<decltype(*p1)>::type)) { // Ovdje pocinje funkc "sortiraj podrucje"...
	
		int brElem=0;
		auto pomocna = p1;
		while(pomocna!=k1) {
			pomocna++;
			brElem++;
		}
		
		std::sort(p1,p1+brElem,krit);
		std::sort(p2,p2+brElem,krit);
		
		typename std::remove_reference<decltype(*p3)>::type rezFunkc;
		for(int i=0;i<brElem;i++) {
			rezFunkc = f(p1[i],p2[i]);
			auto p = std::find(p3,p3+brElem,rezFunkc);
			if(p==p3+brElem)
				throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
			// Zamjena
			std::swap(*p,p3[i]);
		}
	}
	
int main ()
{
	
	int n;
	std::cout<<"Unesite broj elemenata: ";
	std::cin>>n;
	std::cout<<"Unesite elemente prvog vektora: ";
	vector<int> s1;
	Unos(s1,n);
	std::cout<<"Unesite elemente drugog vektora: ";
	vector<int> s2;
	Unos(s2,n);
	std::cout<<"Unesite elemente treceg vektora: ";
	vector<int> s3;
	Unos(s3,n);
	try {
		SortirajPodrucjeVrijednosti(std::begin(s1),std::end(s1),std::begin(s2),std::begin(s3),funkc,viseProstihFaktora);
		std::cout<<"\nNakon sortiranja podrucja vrijednosti imamo sljedece trojke:\n";
		for(int i=0;i<n;i++) 
			std::cout<<"f("<<s1.at(i)<<", "<<s2.at(i)<<") = "<<s3.at(i)<<"\n";
	}
	catch (std::logic_error e) {
		std::cout<<"\nIzuzetak: "<<e.what();
	}
	
	return 0;
}