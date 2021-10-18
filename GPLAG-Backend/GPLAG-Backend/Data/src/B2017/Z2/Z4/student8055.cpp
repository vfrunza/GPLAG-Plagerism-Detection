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
#include <vector>
template <typename tip1, typename tip2, typename tip3, typename tip4, typename tip5>
	void SortirajPodrucjeVrijednost (tip1 prviPocetak, tip1 prviKraj, tip2 drugi, tip3 treci, tip5 f1 (tip4, tip4 ), bool f2(tip4, tip4 )  ) {
		int duzina(prviKraj-prviPocetak);
		std::sort(prviPocetak, prviKraj, f2);
		std::sort(drugi, drugi + duzina, f2);
		auto pomocni (prviPocetak);
		while ( pomocni != prviKraj) {
			int razlika = pomocni - prviPocetak; 
			auto rezultat ( std::find(treci, treci+duzina,  f1(*pomocni, *(drugi+razlika))) );
			if (rezultat == treci+duzina) throw std::logic_error ("Vrijednost koja odgovara nekom od parova nije nadjena");
			pomocni++;
		}
	}
int prost (int y) {
	int broj(0); 
	int x(2);
    int q(0);
    for(; ;){
    if (y%x==0){if (q!=x) broj++; 
    
    y=y/x; q=x;}
    else x++;
    if (y==1) 
    break;
    
    }
	return broj;
}
int f (int x, int y) {return -2*x+y; }

bool  g(int x, int y) { if (prost(x) == prost(y)) return x>y; return prost(x)>prost(y); } 

int main ()
{
	int n;
	std::vector<int> v1, v2, v3;
	std::cout<<"Unesite broj elemenata: ";
	std::cin>>n;
	std::cout<<"Unesite elemente prvog vektora: ";
		int x;
	for (int i=0; i<n; i++){
		std::cin>>x;
		v1.push_back(x);
	}
	std::cout<<"Unesite elemente drugog vektora: ";
		for (int i=0; i<n; i++){
		std::cin>>x;
		v2.push_back(x);
	}
	std::cout<<"Unesite elemente treceg vektora: ";
		for (int i=0; i<n; i++){
		std::cin>>x;
		v3.push_back(x);
	}
	try {
	SortirajPodrucjeVrijednost (std::begin(v1), std::end(v1), std::begin(v2), std::begin(v3),  f, g );
}
catch (std::logic_error e) {
	
	std::cout<<"\nIzuzetak: "<<e.what() ; 
}
	
	
	
	
	return 0;
}