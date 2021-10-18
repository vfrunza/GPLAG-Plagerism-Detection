/*B 2017/2018, Zadaća 1, Zadatak 4

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.
*/
#include <iostream>
#include <string>
#include <vector>


std::string Slovo (std::string a)
{
	std::string novi;
	for(int i = 0; i < a.size(); i++) {
		novi += toupper(a.at(i));
	}
	return novi;
}

bool PorediRijec (std::string rijec1, std::string rijec2)
{

	if(rijec1 == rijec2)

		return true;
	return false;
}

void IzvrniString (std::string &a)
{
	for(int i = 0; i < a.length()/2; i++) {
		char pom = a.at(i);
		a.at(i) = a.at(a.length()-i-1);
		a.at(a.length()-i-1) = pom;
	}
}



std::string NapraviPalindrom (std::string s, std::vector < std::string > v)
{

	for(int i = 0; i < s.length(); i++) {
		for(int i = 0; i < v.size(); i++){
			
		
		
		if(PorediRijec(s,v.at(i))) {
			
                 IzvrniString(v.at(i));
                 s.insert(s.end(),v.at(i));
		}

}
	int main () {
		std::string recenica;
		std::cout << "Unesite recenicu: ";
		std::getline(std::cin, recenica);
		std::vector < std::string > fraze;
		std::cout << "Unesite fraze: ";
	    for(int i = 0; i < fraze.size(); i++)
	    {
	    	std::cin >> fraze.at(i);
	    }
	    std::string a;
	    a = NapraviPalindrom(recenica, fraze);
	    std::cout << a;
		return 0;
	}