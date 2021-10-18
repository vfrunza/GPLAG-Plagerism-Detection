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
#include <vector>
#include <string>

using namespace std;

string ObrniUPalindrom(string recenica, string fraza)
{
	int j(0);
	int brojacznakova(0);
	for(int i=0; i<recenica.length(); i++){
		int k=i;
		brojacznakova=0;
		j=0;
		while(k<recenica.length() && j<fraza.length() && recenica.at(k) == fraza.at(j)) {
			brojacznakova++;
			j++;
			k++;
		}
		if(brojacznakova == fraza.length() && k <= recenica.length() && (k == recenica.length() || recenica.at(k) == ' ' || recenica.at(k) == ',')){
			k=i;
			j=0;
			while(k<(i+fraza.length())){
				int odmak = fraza.length();
				recenica.insert(k+odmak, 1, fraza.at(odmak - j - 1));
				j++;
				k++;
			}
			brojacznakova=0;
		}
		if(recenica.at(i) != fraza.at(j)){
			brojacznakova=0;
			j=0;
		}
	}
	return recenica;
}

string ObrniUPoluPalindrom(string recenica, string fraza)
{
	int j(0);
	int brojacznakova(0);
	for(int i=0; i<recenica.length(); i++){
		int k=i;
		brojacznakova=0;
		j=0;
		while(k<recenica.length() && j<fraza.length() && recenica.at(k)==fraza.at(j)){
			brojacznakova++;
			j++;
			k++;
		}
		if(brojacznakova==fraza.length() && k <= recenica.length() && (k == recenica.length() || recenica.at(k) == ' ' || recenica.at(k) == ',')){
			int odmak = fraza.length() / 2;
			k = i + odmak;
			j = odmak;
			while(k<(i+fraza.length())){
				recenica.at(k) = fraza.at(fraza.length()-j-1);
				j++;
				k++;
			}
			brojacznakova=0;
		}
		if(recenica.at(i) != fraza.at(j)) {
			brojacznakova=0;
			j=0;
		}
	}
	return recenica;
}

string NapraviPoluPalindrom(string recenica, vector<string> nizrijeci)
{
	if(recenica.size() == 0) return recenica;
	for(int j=0; j<nizrijeci.size(); j++){
		recenica=ObrniUPoluPalindrom(recenica, nizrijeci.at(j));
	}
	return recenica;
}

string NapraviPalindrom(string recenica, vector<string> nizrijeci)
{
	if(recenica.size() == 0) return recenica;
	for(int j=0; j<nizrijeci.size(); j++){
		recenica=ObrniUPalindrom(recenica, nizrijeci.at(j));
	}
	return recenica;
}

int main ()
{
	std::cout<< "Unesite recenicu: ";
	std::string recenica;
	std::getline(std::cin, recenica);
	std::cout<< "Unesite fraze: ";
	std::vector<std::string> fraza(0);
	while(true){
		std::string pomocni;
		std::getline(std::cin, pomocni);
		if(pomocni.length() != 0)
		fraza.push_back(pomocni);
		else break;
	}
	
	std::cout<< "Recenica nakon Palindrom transformacije: " << NapraviPalindrom(recenica, fraza)<<std::endl;
	std::cout<< "Recenica nakon PoluPalindrom transformacije: " << NapraviPoluPalindrom(recenica, fraza)<<std::endl;
	return 0;
}