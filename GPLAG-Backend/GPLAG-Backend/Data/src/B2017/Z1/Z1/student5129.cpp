/*B 2017/2018, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
#include <cmath>

#include <limits>
#include <cstdio>

/*
 *  KONVENCIJA: U mom kodu volim koristiti static_cast, mada to bilu u nekim
 *  slucajevima redudantno, cisto radi lakseg deduciranja potrebnog tipa
 *  na prvi pogled
 */

// PROTOTIPI funkcija
// Prvo idu pomocne funkcije, te onda glavna
// Objasnjenja funkcija se nalaze uz njihovu implementaciju
bool isPrime(int);
bool isSymmetric(std::string);
bool exists(std::vector<int>, int);

// Funkcije direktno vezane za zadatak
std::string Dec2Tert(int);

// Funkcija zadata za implementaciju
std::vector<int> IzdvojiSimetricneTernarne(std::vector<int>, bool);

int main ()
{
	std::vector<int> vect;
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	do
	{
		int tmpUnos;
		std::cin >> tmpUnos;
		
		if (tmpUnos == -1)
			break;
			
		vect.push_back(tmpUnos);
	}
	while (true);
	
	int primeReq;
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	std::cin >> primeReq;
	while (primeReq != 0 && primeReq != 1) {
		std::cout << "Neispravan unos! Unesite ponovo: ";
		std::cin >> primeReq;
	}
	
	std::vector<int> res{std::move(IzdvojiSimetricneTernarne(vect, static_cast<bool>(primeReq)))};
	
	if (res.size() == 0)
		std::cout << "Nema "
			<< (primeReq ? "prostih" : "slozenih")
			<< " simetricnih brojeva u vektoru." << std::endl;
	else
	{
		std::cout << (primeReq ? "Prosti" : "Slozeni")
			<< " simetricni brojevi iz vektora su: ";
		
		for (int i{0}; i < res.size(); i++)
			std::cout << res.at(i)
				<< ((i < res.size() - 1) ? ", " : ".");
				
		std::cout << std::endl;
	}
	
	return 0;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> vect, bool primeReq)
{
	std::vector<int> res;
	
	for (int num : vect)
		// 1 i -1 se moraju preskociti jer nisu ni prosti ni slozeni
		// exists provjerava da li se vec nalazi u rjesenju
		if (num != -1 && num != 1 && !exists(res, num) &&
			isSymmetric(Dec2Tert(num)) && isPrime(num) == primeReq)
				res.push_back(num);
			
	return res;
}

// Funkcija vraca string sa ternarnim zapisom broja koji joj je proslijedjen kao parametar
std::string Dec2Tert(int num)
{
	std::string res{""};
	
	do {
		char tmp{static_cast<char>(std::abs(num % 3) + '0')};
		res = std::move(tmp + res);
		num /= 3;
	}
	while (num != 0);
	
	return res;
}

// Funkcija vraca true ukoliko je apsolutna vrijednost broja prosta,
// a false u suprotnom
bool isPrime(int num)
{
	// Ukoliko je manji ili jednak od 1 po modulu, broj nije prost
	// On nije ni slozen, mada nas to ne interesira (funkcija provjerava prostost)
	if (num >= -1 && num <= 1)
		return false;
	
	// Da je N tipa int, za -2^31 bi ovdje doslo do overflow-a
	unsigned int N{static_cast<unsigned int>((num < 0) ? -num : num)};
	
	// Optimizacija koja bi trebala prepoloviti broj operacija
	if (N > 2 && N % 2 == 0)
		return false;
	
	// i <= N / i je isto sto i i^2 <= N, a to je isto sto i i <= sqrt(N)
	for (unsigned int i{3}; i <= N / i; i += 2)
		if (N % i == 0)
			return false;
			
	return true;
}

// Funkcija vraca true ukoliko je proslijedjeni string palindrom,
// a false u suprotnom
bool isSymmetric(std::string str)
{
	int len = str.length();
	for (int i{0}; i <= len / 2; i++)
		if (str.at(i) != str.at(len - 1 - i))
			return false;
			
	return true;
}

// Funkcija vraca true ukoliko se u vektoru pronadje broj,
// a false u suprotnom
bool exists(std::vector<int> vect, int toBeFound)
{
	for (int num : vect)
		if (toBeFound == num)
			return true;
			
	return false;
}