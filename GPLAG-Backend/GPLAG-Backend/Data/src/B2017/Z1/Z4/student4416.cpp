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

typedef std::vector<std::string> NizStringova;

std::string NapraviPalindrom(std::string recenica, NizStringova fraze)
{
	if(recenica.size()==0) return recenica;
	for(std::string fraza: fraze) {
		if(fraza.size()>recenica.size()) continue;
		for(int i(0); i<=recenica.size()-fraza.size(); i++) {
			bool fraza_u_recenici(true);
			for(int j(0); j<fraza.size(); j++) {
				if(fraza.at(j)!=recenica.at(i+j)) {
					fraza_u_recenici=false;
					break;
				}
			}
			if(fraza_u_recenici && i!=recenica.size()-fraza.size()) {
				if((recenica.at(i+fraza.size())>='a' && recenica.at(i+fraza.size())<='z') ||
				        (recenica.at(i+fraza.size())>='A' && recenica.at(i+fraza.size())<='Z'))
					fraza_u_recenici=false;
			}
			if(fraza_u_recenici && i!=0) {
				if((recenica.at(i-1)>='a' && recenica.at(i-1)<='z') || (recenica.at(i-1)>='A' && recenica.at(i-1)<='Z'))
					fraza_u_recenici=false;
			}
			if(fraza_u_recenici) {
				i+=fraza.size();
				for(int j(0); j<fraza.size(); j++) {
					recenica.push_back(recenica.at(recenica.size()-1));
					for(int k(recenica.size()-1); k>i; k--) {
						recenica.at(k)=recenica.at(k-1);
					}
					recenica.at(i)=fraza.at(j);
				}
			}
		}
	}
	return recenica;
}

std::string NapraviPoluPalindrom(std::string recenica, NizStringova fraze)
{
	if(recenica.size()==0) return recenica;
	for(std::string fraza: fraze) {
		if(fraza.size()>recenica.size()) continue;
		for(int i(0); i<=recenica.size()-fraza.size(); i++) {
			bool fraza_u_recenici(true);
			for(int j(0); j<fraza.size(); j++) {
				if(fraza.at(j)!=recenica.at(i+j)) {
					fraza_u_recenici=false;
					break;
				}
			}
			if(fraza_u_recenici && i!=recenica.size()-fraza.size()) {
				if((recenica.at(i+fraza.size())>='a' && recenica.at(i+fraza.size())<='z') ||
				        (recenica.at(i+fraza.size())>='A' && recenica.at(i+fraza.size())<='Z'))
					fraza_u_recenici=false;
			}
			if(fraza_u_recenici && i!=0) {
				if((recenica.at(i-1)>='a' && recenica.at(i-1)<='z') || (recenica.at(i-1)>='A' && recenica.at(i-1)<='Z'))
					fraza_u_recenici=false;
			}
			if(fraza_u_recenici) {
				i+=fraza.size();
				for(int j(0); j<fraza.size()/2; j++) {
					recenica.at(i-j-1)=fraza.at(j);
				}
			}
		}
	}
	return recenica;
}

int main ()
{
	std::cout << "Unesite recenicu: ";
	std::string recenica;
	std::getline(std::cin, recenica);
	std::cout << "Unesite fraze: ";
	std::string fraza;
	NizStringova fraze;
	while(std::getline(std::cin, fraza), fraza.size()!=0) fraze.push_back(fraza);
	std::cout << "Recenica nakon Palindrom transformacije: " << NapraviPalindrom(recenica, fraze) << std::endl;
	std::cout << "Recenica nakon PoluPalindrom transformacije: " << NapraviPoluPalindrom(recenica, fraze);
	return 0;
}