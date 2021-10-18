/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/

#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
#include <type_traits>


using std::cout;
using std::cin;
using std::endl;
using std::deque;
using std::vector;
using std::remove_reference;

template<typename tip1, typename tip2>
auto UvrnutiPresjek(tip1 poc1, tip1 kraj1, tip2 poc2, tip2 kraj2, 
(typename remove_reference<decltype(*poc1)>::type)f(typename remove_reference<decltype(*poc1)>::type))-> typename remove_reference<decltype(poc1)>::type**
{
	
	
	
	
	vector<vector<*poc1>> matrica;
	
	
	return matrica;
}

int main ()
{
	cout << "Unesite broj elemenata prvog kontejnera: ";
	int broj1;
	cin >> broj1;
	cout << "Unesite elemente prvog kontejnera: ";
	deque<int>dek1;
	int broj;
	
	for(int i=0; i<broj1; i++)
	{
		cin>> broj;
		int j(0);
		for(j=0; j<dek1.size(); j++)
		{
			if(broj==dek1[j]) break;
		}
		
		if(j==dek1.size()) dek1.push_back(broj);
		else i--;
		
	}
	
	cout << "Unesite broj elemenata drugog kontejnera: ";
	int broj2;
	cin >> broj2;
	cout << "Unesite elemente drugog kontejnera: ";
	deque<int>dek2;
	
	for(int i=0; i<broj2; i++)
	{
		cin>>broj;
		int j(0);
		for(int j=0; j<dek2.size(); j++)
		{
			if(broj==dek2[j]) break;
		}
		
		if(j==dek2.size()) dek2.push_back(broj);
		else i--;
	}
	
	auto matrica(UvrnutiPresjek(dek1.begin(), dek1.end(), dek2.begin(), dek2.end(), )
	
	
	cout << "Uvrnuti presjek kontejnera: ";
	
	
	
	
	return 0;
}