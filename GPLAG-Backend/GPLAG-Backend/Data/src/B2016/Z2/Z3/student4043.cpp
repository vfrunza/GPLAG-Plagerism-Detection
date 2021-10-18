/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

bool Prost(long long int a) {
	for(long long int i(2);i<a;i++) {
		if(a%i==0) return false;
	}
	return true;
}

int SumaDjelilaca(long long int a) {
	int suma(0);
	for(long long int i(1);i<a;i++) {
		if(a%i==0) suma+=i;
	}
	return suma;
}

int BrojProstihFaktora(long long int a) {							//PROBAJ SKONTATI, OVO JOS NIJE GOTOVO!!!
	int br(0);
	for(long long int i(1);i<a;i++) {
		
	}
	return br;
}

int BrojSavrsenihDjelilaca(long long int a) {
	int br(0);
	for(long long int i(0);i<a;i++) {
		if(a%i==0 && i==SumaDjelilaca(i)) br++;
	}
	return br;
}

template <typename TipPok1, typename TipPok2, typename TipF>
	std::vector<std::vector<TipF>> UvrnutiPresjek(TipPok1 pocetak1, TipPok1 kraj1, TipPok2 pocetak2, TipPok2 kraj2, TipF f(TipF)) {
		std::vector<std::vector<TipF>> matrica;
		auto pomocna(pocetak2);
		int i(0);
		while(pocetak1<kraj1) {
			pocetak2=pomocna;
			while(pocetak2<kraj2) {
				int j(0);
				if(f(*pocetak1)==f(*pocetak2)) {
					matrica[i][j]=*pocetak1;
					j++;
					matrica[i][j]=*pocetak2;
					j++;
					matrica[i][j]=f(*pocetak1);
					i++;
				}
				pocetak2++;
			}
			pocetak1++;
		}
		pocetak2=pomocna;
		std::sort(pocetak2, kraj2, [] (std::vector<TipF> a, std::vector<TipF> b) { 
			if(a[2]!=b[2]) return a[2]>b[2];
			else if(a[0]!=b[0]) return a[0]>b[0];
			return a[1]>b[1]; } );
		//sortiranje sa lambda funkcijom 
		return matrica;
	}

template <typename TipPok1, typename TipPok2, typename TipF>
	std::vector<std::vector<TipF>> UvrnutaRazlika(TipPok1 pocetak1, TipPok1 kraj1, TipPok2 pocetak2, TipPok2 kraj2, TipF f(TipF)) {
		std::vector<std::vector<TipF>> matrica;
		auto pomocna(pocetak2);
		int i(0);
		while(pocetak1<kraj1) {
			pocetak2=pomocna;
			int j(0);
			bool razlika(true);
			while(pocetak2<kraj2) {
				if(f(*pocetak1)==f(*pocetak2)) {
					razlika=false;
					break;
				}
				pocetak2++;
			}
			if(razlika) {										//POTREBNO POSEBNO URADITI ZA Y?
				matrica[i][j]=*pocetak1;
				j++;
				matrica[i][j]=f(*pocetak1);
				i++;
			}
			pocetak1++;
		}
		//std::sort(matrica.begin(),matrica.end(), []->TipF (TipF x, TipF y) { })
		//SORTIRANJE
		return matrica;
	}
	
int main ()
{
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	int br_el1;
	std::cin>>br_el1;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	std::deque<long long int> kont1;
	for(int i(0);i<br_el1;i++) {
		long long int element;
		std::cin>>element;
		kont1[i]=element;
	}
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	int br_el2;
	std::cin>>br_el2;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	std::deque<long long int> kont2;
	for(int i(0);i<br_el2;i++) {
		long long int element;
		std::cin>>element;
		kont2[i]=element;
	}
	auto matr1=UvrnutiPresjek(kont1.begin(),kont1.end(),kont2.begin(),kont2.end(),SumaDjelilaca());
	std::cout<<"Uvrnuti presjek kontejnera:"<<std::endl;
	for(int i(0);i<matr1.size();i++) {
		for(int j(0);j<matr1[0].size;j++) {
			std::cout<<matr1[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	auto matr2=UvrnutaRazlika(kont1.begin(),kont1.end(),kont2.begin(),kont2.end(),SumaDjelilaca());
	std::cout<<"Uvrnuta razlika kontejnera:"<<std::endl;
	for(int i(0);i<matr2.size();i++) {
		for(int j(0);j<matr2[0].size();j++) {
			std::cout<<matr2[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	return 0;
}