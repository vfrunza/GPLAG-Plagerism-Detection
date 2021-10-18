/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <limits>

const long long int m(std::numeric_limits<long long int>::max());

int main ()
{
    long long int p(5);
    long long int q(3);
    std::cout << (double(p))/q;
	return 0;
}