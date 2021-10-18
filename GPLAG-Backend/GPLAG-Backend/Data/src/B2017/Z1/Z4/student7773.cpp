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
std::string NapraviPalindrom(std::string s, std::vector<std::string> v){
	if(v.size()==0) return s;
    else return std::string();

	
}
std::string NapraviPoluPalindrom(std::string s, std::vector<std::string> v){
	if(v.size()==0) return s;
	else re
	
}

int main ()
{
	std::cout<<"Unesite recenicu: ";
	std::string rec;
	std::getline(std::cin, rec);
	std::cout<<"Unesite fraze: ";
	std::string s;
	std::vector<std::string> v;
    for(;;){
    	std::getline(std::cin,s);
    	if(s.length()==0)break;
    	v.push_back(s);
    	//std::cin.clear();
    	//std::cin.ignore(10000, '\n');
    }
    std::string palindrom=NapraviPalindrom(rec,v);
    std::string polupalindrom=NapraviPoluPalindrom(rec,v);
    std::cout<<"Recenica nakon Palindrom transformacije: "<<palindrom;
    std::cout<<"\nRecenica nakon PoluPalindrom transformacije: "<<polupalindrom;

	return 0;
}