/*B 16/17, Zadaća 2, Zadatak 4

	NAPOMENA: i javni ATo-vi su dio postavke

	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <string>
#include <vector>
#include <new>
#include <stdexcept>

using std::cout;
using std::cin;
using std::string;
typedef std::vector<std::string> Vektor;

int PotencijalniKrivci (char **&pok, Vektor v)
{
	char **a;
	try {
		a = new char*[v.size()];
		int br(0);
		try {
			for(int i = 0; i < v.size(); i++) {
				a[i] = new char[v[i].length() + 1];
				br++;
			}
			pok = a;
		} catch(std::bad_alloc) {
			for(int i = 0; i < v.size(); i++) delete[] a[i];
			delete[] a;
		}
		return br;
	} catch(std::bad_alloc) {
		delete[] a;
		throw;
	}
}

int OdbaciOptuzbu (char **&pok, int n, string s)
{
	int obrisani(0);
	for(int i = 0; i < s.length(); i++) {
		for(int j = 0; j < n; j++) {
			int br(0);
			for(int k = 0; k < pok[i].size(); k++) {
				if(s[i] == pok[j][k])
					br++;
			}

			if(br != s.length())
				throw std::domain_error("Osoba sa imenom ??? nije optuzena");

			else {
				pok[0][0] = '\0';
				pok[i] = nullptr;
				obrisani++;
			}

		}
	}
	if(obrisani <= 10) return n;
/*	else {

		char **p(new char*[n - obrisani]);
		for(int i = 0; i < n-obrisani; i++){
			for(int j = 0; j < )
			if(pok[i] != nullptr)
			p[i] = new char[pok[i].size()];
		}
	} */
}
int main ()
{
	return 0;
}