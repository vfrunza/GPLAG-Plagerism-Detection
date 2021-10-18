/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <iomanip>
using std::vector;
using std::deque;

template <typename Tip1, typename Tip2, typename Tip3>
	Tip3 funkcija(Tip3 n) {
		Tip3 suma(0);
		while (n!=0) {
			suma+=n%10;
			n/=10;
		}
		return suma;
	}

	vector<vector<int>> UvrnutiPresjek (Tip1 it1, Tip1 it2, Tip2 it3, Tip2 it4, Tip3 f(Tip3)) {
		vector<vector<int>> mat;
		vector<int> v(3);
		for (Tip1 i=it1; i!=it2; i++) {
			for (Tip2 j=it3; j!=it4; j++) {
				if (f(*i)==f(*j)) {
					v[0]=*i;
					v[1]=*j;
					v[2]=f(*i);
					mat.push_back(v);
				}
			}
		}
		return mat;
	}
//template <typename Tip3>	


int main ()
{
	deque<int> d1, d2;
	int br_el1, br_el2;
	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	std::cin >> br_el1;
	std::cout << "Unesite elemente prvog kontejnera: ";
	int n;
	for (int i=0; i<br_el1; i++) {
		std::cin >> n;
		bool postoji(false);
		for (int j=0; j<d1.size(); j++) {
			if (d1[j]==n) {
				postoji=true;
				break;
			}
		}
		if (!postoji)
			d1.push_back(n);
	}
	std::cout << "Unesite broj elemenata drugog kontejnera: ";
	std::cin >> br_el2;
	std::cout << "Unesite elemente drugog kontejnera: ";
	for (int i=0; i<br_el2; i++) {
		std::cin >> n;
		bool postoji(false);
		for (int j=0; j<d2.size(); j++) {
			if (d2[j]==n) {
				postoji=true;
				break;
			}
		}
		if (!postoji)
			d2.push_back(n);
	}
	vector<vector<int>> mat(UvrnutiPresjek(d1.begin(), d1.end(), d2.begin(), d2.end(), funkcija));
	for (int i=0; i<mat.size(); i++) {
		for (int j=0; j<3; j++)
			std::cout << std::setw(6) << mat[i][j] << " ";
		std::cout << std::endl;
	}
	return 0;
}