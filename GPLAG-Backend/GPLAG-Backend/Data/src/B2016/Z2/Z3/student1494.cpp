/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <deque>

int SumaDjelilaca(long long int n) {
	int suma(0);
	for(int i(1); i<=n; i++) {
		if(n%i==0)
		suma+=i;
	}
	return suma;
}

int BrojProstihFaktora(long long int n) {
	std::vector<int> v;
	bool prost(true);
	int brojac(0);
	for(int i(1); i<=n; i++) {
		if(n%i==0) {
		v.push_back(i);
		}
			for(int j(0); j<v.size(); j++) {
				if(v[i]<=1) prost=false;
					for(int k(2); k<v[i]; k++)
						if(v[i]%k==0) {
						prost=false;
						}
							else { 
							brojac++;
							}
			}		
			
	}
	return brojac;
}

int BrojSavrsenihDjelilaca(long long int n) {
	int brojac(0);
	std::vector<int> v;
	for(int i(1); i<=n; i++) {
		if(n%i==0)
		v.push_back(i);
	}	
		int suma(0);
		for(int j(0); j<=v[i]; j++) {
			if(v[i]%j==0) {
			suma+=v[j];
			}
				if(v[i]==suma)
					brojac++;
		}
		return brojac;
}

template <typename Tip1, typename Tip2, typename Tip3, typename TipFoo>

std::vector<std::vector<double>> UvrnutiPresjek(Tip1 it1, Tip1 it2, Tip2 it3, Tip2 it4, TipFoo (*f)(Tip3)) -> typename remove_reference<decltype(*it1 + *it2)>::type {
	
	
}

template <typename Tip1, typename Tip2, typename Tip3 ,typename TipFoo>

std::vector<std::vector<double>> UvrnutiPresjek(Tip1 it1, Tip1 it2, Tip2 it3, TipFoo (*f)(Tip3))

int main ()
{
	int a;
	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	std::cin >> a;
	std::deque<int> d1;
	std::cout << "Unesite elemente prvog kontejnera: ";
	for(int i(0); i<a; i++) {
		int x;
		cin >> x;
		d1.push_back(x);
	}
	
	int b;
	std::cout << "Unesite broj elemenata drugog kontejnera: ";
	std::cin >> b;
	std::deque<int> d2;
	std::cout << "Unesite elemente drugog kontejnera: ";
	for(int j(0); j<b; j++) {
		int y;
		cin >> y;
		d2.push_back(y);
	}
	
	std::cout << "Uvrnuti presjek kontejnera: " << std::endl;
	std::cout << "Uvrnuta razlika kontejnera: " << std::endl;
	
	std::cout << "Dovidjenja!";
	
	return 0;
}