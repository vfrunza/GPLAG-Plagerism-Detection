/*B 16/17, Zadaća 2, Zadatak 3

	NAPOMENA: i javni ATo-vi su dio postavke

	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <iomanip>


int SumaCifara(long long int broj)
{

	unsigned long long int x(std::abs(broj));
	int zadnji;
	int suma(0);
	while(x!=0) {
		zadnji = x % 10;
		suma += zadnji;
		x/=10;
	}

	return suma;
}

int SumaDjelilaca(long long int broj)
{
	unsigned long long int x(std::abs(broj));
	int suma(0);
	for(int i=1; i <= x; i++){
			if(x % i == 0) suma+=i;
	}
	return suma;
}

int BrojProstihFaktora(long long int broj)
{

	unsigned long long int x(std::abs(broj));
	int i;
	i =2;
	int brojac=0;
	while(x!=1) {
		if(x%i !=0) {
			i++;
			continue;
		}
		x/=i;
		brojac++;
	}
	return brojac;

}

bool savrsen(long long int x)
{

	int suma(0);
	for(int i=1; i < x; i++) {
		if(x % i == 0) suma+=i;
	}
	return suma==x;
}

int BrojSavrsenihDjelilaca(long long int broj)
{

	unsigned long long int x(std::abs(broj));
	int brojac(0);
	for(int i=2; i <= broj; i++) {
		if(x % i == 0 && savrsen(i)) brojac++;
	}
	return brojac;
}

template <typename tip1, typename tip2, typename ptip, typename ptip2>
auto UvrnutiPresjek(tip1 pocetak1, tip1 kraj1, tip2 pocetak2, tip2 kraj2, ptip (*f)(ptip2))
-> std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>> {

	std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>> Matrica;
	unsigned int k(0);

	for(auto i = pocetak1; i != kraj1; i++) {
		for(auto j = pocetak2; j != kraj2; j++) {
			if(f(*i) == f(*j)  ) {
				Matrica.resize(k+1);
				Matrica[k].resize(3);
				Matrica[k][0] = *i;
				Matrica[k][1] = *j;
				Matrica[k][2] = f(*i);
				k++;
			}
		}
	}

	std::sort(Matrica.begin(), Matrica.end(), [](std::vector<typename std::remove_reference<decltype(Matrica[0][0])>::type> v1,
	std::vector<typename std::remove_reference<decltype(Matrica[0][0])>::type> v2) -> bool {
		return ((v1[2] < v2[2]) || (v1[2] == v2[2] && ((v1[0] < v2[0]) || (v1[0] == v2[0] && (v1[1] < v2[1])))     ));
	});

	return Matrica;
}

template <typename tip1, typename tip2>
auto UvrnutiPresjek(tip1 pocetak1, tip1 kraj1, tip2 pocetak2, tip2 kraj2)
-> std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>> {

	std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>> Matrica;
	unsigned int k(0);

	for(auto i = pocetak1; i != kraj1; i++) {
		for(auto j = pocetak2; j != kraj2; j++) {
			if(*i==*j) {
				Matrica.resize(k+1);
				Matrica[k].resize(3);
				Matrica[k][0] = *i;
				Matrica[k][1] = 0;
				Matrica[k][2] = 0;
				k++;
			}
		}
	}

	std::sort(Matrica.begin(), Matrica.end(), [](std::vector<typename std::remove_reference<decltype(Matrica[0][0])>::type> v1,
	std::vector<typename std::remove_reference<decltype(Matrica[0][0])>::type> v2) -> bool {
		return (v1[0] < v2[0]);
	});

	return Matrica;
}

bool ImaLiUDeku(std::deque<int> &v, int element)
{

	for(int i=0; i < v.size(); i++) {
		if(v[i] == element) return false;
	}
	return true;
}

template <typename tip1, typename tip2, typename ptip, typename ptip2>
auto UvrnutaRazlika(tip1 pocetak1, tip1 kraj1, tip2 pocetak2, tip2 kraj2, ptip (*f)(ptip2))
-> std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>> {

	std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>> Matrica;
	unsigned int k(0);

	for(auto i = pocetak1; i!=kraj1; i++) {
		bool Imal = true;
		for(auto j = pocetak2; j != kraj2; j++) {
			if(f(*i) == f(*j)) {
				Imal = false;
				break;
			}
		}
		if(Imal) {
			Matrica.resize(k+1);
			Matrica[k].resize(2);
			Matrica[k][0] = *i;
			Matrica[k][1] = f(*i);
			k++;
		}
	}

	for(auto i = pocetak2; i!=kraj2; i++) {
		bool Imal = true;
		for(auto j = pocetak1; j != kraj1; j++) {
			if(f(*i) == f(*j)) {
				Imal = false;
				break;
			}
		}
		if(Imal) {
			Matrica.resize(k+1);
			Matrica[k].resize(2);
			Matrica[k][0] = *i;
			Matrica[k][1] = f(*i);
			k++;
		}
	}

	std::sort(Matrica.begin(), Matrica.end(), [](std::vector<typename std::remove_reference<decltype(Matrica[0][0])>::type> v1,
	std::vector<typename std::remove_reference<decltype(Matrica[0][0])>::type> v2) -> bool {
		return ((v1[0] > v2[0]) || (v1[0] == v2[0] && ((v1[1] > v2[1]) )));
	});

	return Matrica;
}

template <typename tip1, typename tip2>
auto UvrnutaRazlika(tip1 pocetak1, tip1 kraj1, tip2 pocetak2, tip2 kraj2)
-> std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>>  {

	std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>> Matrica;
	unsigned int k(0);
	
	for(auto i = pocetak1; i != kraj1; i++){
		bool Imal = true;
		for(auto j = pocetak2; j != kraj2; j++){
			if(*i == *j){
				Imal = false;
				break;
			}
		}
		if(Imal){
			Matrica.resize(k+1);
			Matrica[k].resize(2);
			Matrica[k][0] = *i;
			Matrica[k][1] = 0;
			k++;
		}
	}
	
	for(auto i = pocetak2; i != kraj2; i++){
		bool Imal = true;
		for(auto j = pocetak1; j != kraj1; j++){
			if(*i == *j){
				Imal = false;
				break;
			}
		}
		if(Imal){
			Matrica.resize(k+1);
			Matrica[k].resize(2);
			Matrica[k][0] = *i;
			Matrica[k][1] = 0;
			k++;
		}
	}
	
	std::sort(Matrica.begin(), Matrica.end(), [](std::vector<typename std::remove_reference<decltype(Matrica[0][0])>::type> v1,
	std::vector<typename std::remove_reference<decltype(Matrica[0][0])>::type> v2) -> bool {
		return (v1[0] > v2[0]);
	});

	return Matrica;
	
}



int main ()
{
	std::deque<int> v1, v2;
	int br1, br2;
	int element;
	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	std::cin >> br1;
	std::cout << "Unesite elemente prvog kontejnera: ";
	v1.resize(br1);
	for(int i=0;; i++) {
		for(;;) {
			std::cin >> element;
			if(ImaLiUDeku(v1, element)) break;
		}
		v1[i] = element;
		if(i == v1.size()-1) break;
	}
	std::cout << "Unesite broj elemenata drugog kontejnera: ";
	std::cin >> br2;
	std::cout << "Unesite elemente drugog kontejnera: ";
	v2.resize(br2);
	for(int i=0;; i++) {

		for(;;) {
			std::cin >> element;
			if(ImaLiUDeku(v2, element)) break;
		}

		v2[i] = element;
		if(i == v2.size()-1) break;
	}
	
	std::cout << "Uvrnuti presjek kontejnera:" << std::endl;
	std::vector<std::vector<int>> matrix = UvrnutiPresjek(v1.begin(), v1.end(), v2.begin(), v2.end(), SumaCifara);
	for(auto i = 0; i < matrix.size(); i++) {
		for(auto j=0; j < matrix[i].size(); j++) {
			std::cout << std::setw(6) << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "Uvrnuta razlika kontejnera:" << std::endl;
	std::vector<std::vector<int>> matrix2 = UvrnutaRazlika(v1.begin(), v1.end(), v2.begin(), v2.end(), BrojProstihFaktora);
	for(auto i = 0; i < matrix2.size(); i++) {
		for(auto j=0; j < matrix2[i].size(); j++) {
			std::cout << std::setw(6) << matrix2[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "Dovidjenja!";
	
	return 0;
}