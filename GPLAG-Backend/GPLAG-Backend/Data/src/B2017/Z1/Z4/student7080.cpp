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
#include <cctype>

std::string ObrniRijec(std::string rijec)
{
	for(int i(0); i<rijec.length()/2; i++) {
		char pomocna=rijec.at(i);
		rijec.at(i)=rijec.at(rijec.length()-1-i);
		rijec.at(rijec.length()-1-i)=pomocna;
	}

	return rijec;
}

std::string NapraviPalindrom(std::string s, std::vector<std::string>v)
{
	std::string recenica(s);
	for(int j(0); j<v.size(); j++) {
		for(int i(0); i<recenica.length(); i++) {
			if(recenica.substr(i,v.at(j).length())==v.at(j) and ((i>0 and i<recenica.size()-v.at(j).size() and !std::isalpha(recenica.at(i+v.at(j).size()))
			        and !std::isalpha(recenica.at(i-1))) or (i==0 and !std::isalpha(recenica.at(i+v.at(j).size()))) 
			        or (i==recenica.size()-v.at(j).size() and !std::isalpha(recenica.at(i-1)))))
				recenica=recenica.substr(0,i+v.at(j).size())+ObrniRijec(v.at(j))+recenica.substr(i+v.at(j).length(),recenica.length()-v.at(j).length()-i);
		}
	}
	return recenica;
}

std::string ObrniPolaRijeci(std::string rijec)
{
	std::string novarijec;
	for(int i(0); i<rijec.size()/2; i++) novarijec.push_back(rijec.at(i));
	if(rijec.size()%2==0) {
		for(int i(rijec.size()/2-1); i>=0; i--)
			novarijec.push_back(rijec.at(i));
	} else {
		for(int i(rijec.size()/2); i>=0; i--)
			novarijec.push_back(rijec.at(i));
	}
	return novarijec;
}
std::string NapraviPoluPalindrom(std::string s, std::vector<std::string>v)
{
	std::string recenica(s);
	for(int j(0); j<v.size(); j++) {
		for(int i(0); i<recenica.length(); i++) {
			if(recenica.substr(i,v.at(j).length())==v.at(j) and ((i>0 and i<recenica.size()-v.at(j).size() and !std::isalpha(recenica.at(i+v.at(j).size()))
			        and !std::isalpha(recenica.at(i-1))) or (i==0 and !std::isalpha(recenica.at(i+v.at(j).size()))) 
			        or (i==recenica.size()-v.at(j).size() and !std::isalpha(recenica.at(i-1)))))
				recenica=recenica.substr(0,i)+ObrniPolaRijeci(v.at(j))+recenica.substr(i+v.at(j).length(),recenica.length()-i);
		}
	}
	return recenica;
}
int main ()
{
	std::cout << "Unesite recenicu: " ;
	std::string recenica;
	std::getline(std::cin, recenica);
	std::cout << "Unesite fraze: ";
	std::vector<std::string> fraze;


	bool logicko(true);
	while(logicko) {
		std::string unos;
		std::getline (std::cin, unos);
		if(unos.length()!=0) fraze.push_back(unos);
		if(unos.length()==0) logicko=false;
	}
	std::string recenicanova=NapraviPalindrom(recenica,fraze);
	std::cout << "Recenica nakon Palindrom transformacije: " <<recenicanova << std::endl;
	std::string recenicanova1=NapraviPoluPalindrom(recenica,fraze);
	std::cout << "Recenica nakon PoluPalindrom transformacije: " <<recenicanova1<< std::endl;
	return 0;
}