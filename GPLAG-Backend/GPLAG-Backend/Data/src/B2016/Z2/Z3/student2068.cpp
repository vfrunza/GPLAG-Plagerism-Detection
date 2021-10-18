/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <cmath>
#include <iomanip>

int SumaCifara(long long int x) {
	int suma(0);
	while(x) {
		suma+=abs(x%10);
		x/=10;
	}
	return suma;
}

int SumaDjelilaca(long long int x) {
	int suma(0);
	for(int i=1; i<=abs(x); i++) if(!(x%i)) suma+=i;
	return suma;
}

bool DaLiJeProst(long long int x) {
	if(x<2) return 0; if(x==2) return 1; if(x%2==0) return 0;
	for(int i=3; i<=sqrt(x); i+=2) if(x%i==0) return 0;
	return 1;
}

int BrojProstihFaktora(long long int x) {
	int broj(0);/*
	for(int i=2; i<=abs(x); i++) if(x%i==0 && DaLiJeProst(i)) broj++;
	return broj;*/
	while(x>1) {
		for(int i=2; i<=abs(x); i++) {
			if(x%i==0) {
				x/=i;
				broj++;
				break;
			}
		}
	}
	return broj;
}

int BrojSavrsenihDjelilaca(long long int x) {
	int broj(0);
	for(int i=1; i<=abs(x); i++) if(!(x%i) && SumaDjelilaca(i)==i+i) broj++;
	return broj;
}

template <typename Tip1, typename Tip2, typename Tip3, typename Tip4>
auto UvrnutiPresjek(Tip1 pok1a, Tip1 pok1b, Tip2 pok2a, Tip2 pok2b, Tip3 F(Tip4)) -> typename std::vector<std::vector<Tip3>> {
	std::vector<std::vector<Tip3>>matrica;
	
	for(Tip1 temp1=pok1a; temp1!=pok1b; temp1++) {
		for(Tip2 temp2=pok2a; temp2!=pok2b; temp2++) {
			if(F(*temp1)==F(*temp2)) {
				std::vector<Tip3>vek={*temp1, *temp2, F(*temp1)};
				matrica.push_back(vek);
			}
		}
	}
	std::sort(matrica.begin(), matrica.end(), [](std::vector<Tip3> a, std::vector<Tip3> b) { 
		if(a[2]!=b[2]) return a[2]<b[2]; if(a[0]!=b[0]) return a[0]<b[0]; return a[1]<b[1]; 
		
	});
	return matrica;
}


template <typename Tip1, typename Tip2>
auto UvrnutiPresjek(Tip1 pok1a, Tip1 pok1b, Tip2 pok2a, Tip2 pok2b) -> typename std::vector<std::vector<typename std::remove_reference<decltype(*pok1a)>::type>> {      
	typename std::vector<std::vector<typename std::remove_reference<decltype(*pok1a)>::type>>matrica;
	
	for(Tip1 temp1=pok1a; temp1!=pok1b; temp1++) {
		for(Tip2 temp2=pok2a; temp2!=pok2b; temp2++) {
			if(*temp1==*temp2) {
				std::vector<typename std::remove_reference<decltype(*pok1a)>::type>vek={*temp1, 0, 0};
				matrica.push_back(vek);
			}
		}
	}
	
	std::sort(matrica.begin(), matrica.end(), [](std::vector<typename std::remove_reference<decltype(*pok1a)>::type>a, std::vector<typename std::remove_reference<decltype(*pok1a)>::type>b) {
		return a[0]<b[0];
	});
	
	return matrica;
}


template <typename Tip1, typename Tip2, typename Tip3, typename Tip4>
auto UvrnutaRazlika(Tip1 pok1a, Tip1 pok1b, Tip2 pok2a, Tip2 pok2b, Tip3 F(Tip4)) -> typename std::vector<std::vector<Tip3>> {
	std::vector<std::vector<Tip3>>matrica;
	
	for(Tip1 temp1=pok1a; temp1!=pok1b; temp1++) {
		bool nadjen(false);
		for(Tip2 temp2=pok2a; temp2!=pok2b; temp2++) {
			if(F(*temp1)==F(*temp2)) {
				nadjen=true;
				break;
			}
		}
		if(!nadjen) {
			std::vector<Tip3>vek={*temp1, F(*temp1)};
			matrica.push_back(vek);
		}
	}
	
	for(Tip2 temp2=pok2a; temp2!=pok2b; temp2++) {
		bool nadjen(false);
		for(Tip1 temp1=pok1a; temp1!=pok1b; temp1++) {
			if(F(*temp1)==F(*temp2)) {
				nadjen=true;
				break;
			}
		}
		if(!nadjen) {
			std::vector<Tip3>vek={*temp2, F(*temp2)};
			matrica.push_back(vek);
		}
	}
	
	std::sort(matrica.begin(), matrica.end(), [](std::vector<Tip3>a, std::vector<Tip3> b) {
		if(a[0]!=b[0]) return b[0]<a[0]; return b[1]>a[1];
	});
	return matrica;
}

template <typename Tip1, typename Tip2>
auto UvrnutaRazlika(Tip1 pok1a, Tip1 pok1b, Tip2 pok2a, Tip2 pok2b) -> typename std::vector<std::vector<typename std::remove_reference<decltype(*pok1a)>::type>> {
	std::vector<std::vector<typename std::remove_reference<decltype(*pok1a)>::type>>matrica;
	
	for(Tip1 temp1=pok1a; temp1!=pok1b; temp1++) {
		bool nadjen(false);
		for(Tip2 temp2=pok2a; temp2!=pok2b; temp2++) {
			if(*temp1==*temp2) {
				nadjen=true;
				break;
			}
		}
		if(!nadjen) {
			std::vector<typename std::remove_reference<decltype(*pok1a)>::type>vek={*temp1, 0};
			matrica.push_back(vek);
		}
	}
	
	for(Tip2 temp2=pok2a; temp2!=pok2b; temp2++) {
		bool nadjen(false);
		for(Tip1 temp1=pok1a; temp1!=pok1b; temp1++) {
			if(*temp1==*temp2) {
				nadjen=true;
				break;
			}
		}
		if(!nadjen) {
			std::vector<typename std::remove_reference<decltype(*pok1a)>::type>vek={*temp2, 0};
			matrica.push_back(vek);
		}
	}
	
	std::sort(matrica.begin(), matrica.end(), [](std::vector<typename std::remove_reference<decltype(*pok1a)>::type>a, std::vector<typename std::remove_reference<decltype(*pok1a)>::type>b) {
		return a[0]>b[0];
	});
	
	return matrica;
}

int main () {
	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	int n1; std::cin >> n1;
	std::cout << "Unesite elemente prvog kontejnera: ";
	std::deque<int>d1(n1);
	for(int i=0; i<n1; i++) {
		std::cin >> d1[i];
		for(int j=0; j<i; j++) if(d1[j]==d1[i]) {
			i--; 
			break;
		}
	}
	d1.resize(n1);
	std::cout << "Unesite broj elemenata drugog kontejnera: ";
	int n2; std::cin >> n2;
	std::cout << "Unesite elemente drugog kontejnera: ";
	std::deque<int>d2(n2);
	for(int i=0; i<n2; i++) {
		std::cin >> d2[i];
		for(int j=0; j<i; j++) if(d2[j]==d2[i]) {
			i--;
			break;
		}
	}
	d2.resize(n2);
	auto matrica=UvrnutiPresjek(d1.begin(), d1.end(), d2.begin(), d2.end(), SumaCifara);
	std::cout << "Uvrnuti presjek kontejnera: \n";
	for(auto i : matrica) {
		for(auto j : i) {
			std::cout << std::setw(6) << j << " ";
		}
		std::cout << "\n";
	}
	
	matrica=UvrnutaRazlika(d1.begin(), d1.end(), d2.begin(), d2.end(), BrojProstihFaktora);
	std::cout << "Uvrnuta razlika kontejnera: \n";
	for(auto i : matrica) {
		for(auto j : i) {
			std::cout << std::setw(6) << j << " ";
		}
		std::cout << "\n";
	}
	
	std::cout << "Dovidjenja!";
	return 0;
}