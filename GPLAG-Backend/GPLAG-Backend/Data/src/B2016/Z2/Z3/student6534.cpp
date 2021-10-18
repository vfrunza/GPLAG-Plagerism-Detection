/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <iomanip>
#include <new>
#include <deque>
#include <algorithm>
template <typename tip1,tip2>
auto UvrnutiPresjek <tip1 pocetak1,tip2 kraj1,tip2 pocetak2,tip1 kraj2,f)->
int main ()
{	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	int a,b;
	std::cin >> a;
	std::cout << "Unesite elemente prvog kontejnera: " << std::endl;
	std::vector<int> v1,v2;
	for(int i=0;i<a;i++){
		int x;
		std::cin >> x;
		v1.push_back(x);
	}
	std::cout << "Unesite broj elemenata drugog kontejnera: " << std::endl;
	std::cin >> b;
	for(int i=0;i<b;i++){
		int x;
		std::cin >> x;
		v2.push_back(x);
	}
	
	std::cout << "Dovidjenja!" << std::endl;
	return 0;
}