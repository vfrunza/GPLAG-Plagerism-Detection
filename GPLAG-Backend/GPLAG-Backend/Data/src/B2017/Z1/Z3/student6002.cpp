#include <iostream>
#include <vector>
#include<deque>
typedef std::deque<std::vector<int> > Dek;
typedef std::vector<int> Vektor;

Dek MaksimalniPodnizoviStepenaDvojke(Vektor a, bool T)
{
	

}


int main ()
{
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	Vektor a;
	std::cout << "Unesite elemente vektora: ";
	for(int i = 0; i < n; i ++) std::cin >> a.at(i);
	bool T;
	std::cout << "Unesite 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int broj;
	std::cin >> broj;
	

	return 0;
}