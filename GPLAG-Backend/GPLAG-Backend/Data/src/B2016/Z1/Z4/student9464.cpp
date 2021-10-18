/*B 2016/2017, Zadaća 1, Zadatak 4

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

bool Slovo(char x)
{
	return((x>='a' && x<='z') || (x>='A' && x<='Z'));
}

std::string ObrniFraze(std::string s, std::vector<std::string> spisak)
{
	for(int i=0; i<spisak.size(); i++) {
		for(int j=0; j<s.length(); j++) {
			if(spisak[i] == s.substr(j, spisak[i].length()))  {
				std::string tmp;
				for(int k=j+spisak[i].length()-1; k>=j; k--)
					tmp.push_back(s[k]);
				for(int k=j; k<j+spisak[i].length(); k++)
					s[k]=tmp[k-j];
			}
		}
	}
	return s;
}

std::string IzmijeniUPigLatin (std::string s, std::vector<std::string> spisak)
{
	for(int i=0; i<spisak.size(); i++)
		for(int j=0; j<spisak[i].length(); j++)
			if(!Slovo(spisak[i][j]))
				throw std::domain_error("Nekorektan izbor rijeci");
	if(spisak.size() == 0) {
		for(int i=0; i<s.length(); i++) {
			if(Slovo(s[i])) {
				int j(i);
				while(Slovo(s[j]) && j<s.length())
					j++;
				j--;
				s=s.substr(0, i) + s.substr(i+1, j-i)  +  s[i]+ std::string {"ay"} + s.substr(j+1, s.length()-i);
				i=j+2;
			}
		}
	} 
	else {
		for(int i=0; i<spisak.size(); i++)
			for(int j=0; j<s.length(); j++)
				if(spisak[i] == s.substr(j, spisak[i].length()) && (j==0 || !Slovo(s[j-1])) && (j+spisak[i].length()-1 == s.length()-1 || !Slovo(s[j+spisak[i].length()])))
					s=s.substr(0, j) + s.substr(j+1, spisak[i].length()-1) + spisak[i][0] + std::string {"ay"} + s.substr(j+spisak[i].length(), s.length()-j);
	}
	return s;
}

int main ()
{
	std::cout<<"Unesite recenicu: ";
	std::string recenica;
	std::getline(std::cin, recenica);
	std::vector<std::string> spisak;
	std::cout<<"Unesite fraze: ";
	for(;;) {
		std::string tmp;
		std::getline(std::cin, tmp);
		if(tmp.size() == 0)
			break;
		spisak.push_back(tmp);
		if(std::cin.peek() == '\n')
			break;
	}
	try {
		std::cout<<"Recenica nakon PigLatin transformacije: "<<IzmijeniUPigLatin(recenica, spisak)<<std::endl;
	} catch(std::domain_error izuzetak) {
		std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
	}
	std::cout<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(recenica, spisak)<<std::endl;

	return 0;
}