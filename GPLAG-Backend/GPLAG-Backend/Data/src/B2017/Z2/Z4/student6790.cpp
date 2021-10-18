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
#include <vector>
#include <algorithm>
#include <cmath>

typedef std::vector<int> Vektor;

template<typename NekiTip>
bool DaLiJeProst (NekiTip broj) {
	if (broj==0 || broj==1) return false;
	for(int i(2);i<broj;i++) {
		if (broj%i==0) {
			return false;
		}
	}
	return true;
} 

template<typename Tip>
int ProstiFaktor(Tip broj) {
	int brojac(0);
	
	if(DaLiJeProst(broj)) return brojac;

	for(int i(2);i<=broj;i++) {
		if(DaLiJeProst(i)) {
			if(broj%i==0){
			broj=broj/i;
			brojac++;
			i=1;
			}
		}
	}
	return brojac;
}

template<typename T>
bool Fun(T a,T b) {
	
	int br_p1(ProstiFaktor(a)); 
	int br_p2(ProstiFaktor(b));

	if(br_p1<br_p2 || (br_p1==br_p2 && a<b)) return false;
	return true;
}

template<typename Te1,typename Te3>
Te3 f(Te1 x,Te1 y) {
	return ((-2)*x+y);
}

template<typename T,typename T3>
bool DaLiPostojiBrojUS3(T broj,T3 pocS3, T3 izakrajaS3) {
	while (pocS3!=izakrajaS3) {
		if (*(pocS3)==broj) 
			return true;
		pocS3++;
	}
	return false;
}

template <typename T3,typename Te3>
int NaKojojPoziciji (T3 pocetak3, int n,Te3 element) {
	int pozicija(0);
	for(int i(0);i<n;i++) {
		if(*(pocetak3+i)==element)
			break;
		pozicija++;
	}
	
	return pozicija;
}


template<typename T1,typename T2,typename T3>
void SortirajPodrucjeVrijednosti (T1 poc1,T1 kraj1,T2 poc2,T3 poc3, 
	decltype(0+*poc3) f(decltype(*poc1+0),decltype(*poc1+0)),
	bool Fun(decltype(*poc1+0),decltype(*poc1+0))) {
	
	//Sortiranje elemenata blokova po kriteriju:
	std::sort(poc1,kraj1,Fun);
	int n(kraj1-poc1);
	std::sort(poc2,poc2+n,Fun);
	
	for(int i(0);i<n;i++) {
		decltype(0+*poc3) VrijednostFunkcije(f(*(poc1+i),*(poc2+i)));
		if(DaLiPostojiBrojUS3(VrijednostFunkcije,poc3,poc3+n)==false)
			throw std::logic_error
				("Vrijednost koja odgovara nekom od parova nije nadjena");
	}
	
	for(int i(0);i<n;i++) {
		decltype(0+*poc3) VrijednostFunkcije(f(*(poc1+i),*(poc2+i)));
		int pozicija(NaKojojPoziciji(poc3,n,VrijednostFunkcije));
		
		decltype(0+*poc3) pomocna(*(poc3));
		*(poc3)=*(poc3+pozicija);
		*(poc3+pozicija)=pomocna;
		
		poc3++;
	}

}


int main () {
	try {
	std::cout<<"Unesite broj elemenata: ";
	int broj;
	std::cin>>broj;
	
	std::cout<<"Unesite elemente prvog vektora: ";
	Vektor v1;
	int element;
	for(int i(0);i<broj;i++) {
		std::cin>>element;
		int a(count(v1.begin(),v1.end(),element));
		if(a!=0) i--;
		else v1.push_back(element);
	}
	
	std::cout<<"Unesite elemente drugog vektora: ";
	Vektor v2;

	for(int i(0);i<broj;i++) {
		std::cin>>element;
		int a(count(v2.begin(),v2.end(),element));
		if(a!=0) i--;
		else v2.push_back(element);
	}
	
	std::cout<<"Unesite elemente treceg vektora: ";
	Vektor v3;

	for(int i(0);i<broj;i++) {
		std::cin>>element;
		int a(count(v3.begin(),v3.end(),element));
		if(a!=0) i--;
		else v3.push_back(element);
	}
	std::cout<<std::endl;

	SortirajPodrucjeVrijednosti(v1.begin(),v1.end(),v2.begin(),v3.begin(),f,Fun);
	std::cout<<"Nakon sortiranja podrucja vrijednosti imamo sljedece trojke:\n";
	
	for(int i(0);i<broj;i++) 
		std::cout<<"f("<<v1.at(i)<<", "<<v2.at(i)<<") = "<<v3.at(i)<<std::endl;

	}
	
	catch(std::logic_error izuzetak) {
		std::cout<<"Izuzetak: "<<izuzetak.what();
	}
	
	
	return 0;
}