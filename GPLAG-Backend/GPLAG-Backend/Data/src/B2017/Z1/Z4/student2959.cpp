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

bool Slovo(char c)
{
	c=tolower(c);
	return (c>='a'&& c<='z');
}

std::string Palindrom(std::string s)
{
	std::string naopako;
	for(int i=s.size()-1; i>=0; i--)
		naopako+=s.at(i);
	return naopako;
}

std::string NapraviPalindrom(std::string recenica, std::vector<std::string> rijeci)
{
	for(int i=0; i<rijeci.size(); i++) {
		int d1(recenica.size());
		int d2(rijeci.at(i).size());
		for(int j=0; j<d1-d2+1; j++) {
			if(recenica.substr(j,d2)==rijeci.at(i)) {
				if(j!=0 && Slovo(recenica.at(j-1))) continue;
				if(j!=(d1-d2) && Slovo(recenica.at(j+d2))) continue;
				recenica=recenica.substr(0,j+d2)+Palindrom(rijeci.at(i))+recenica.substr(j+d2,d1-d2-j);
				j+=d2;
				d1+=d2;
			}
		}
	}
	return recenica;
}

std::string NapraviPoluPalindrom(std::string recenica, std::vector<std::string> rijeci)
{
	for(int i=0; i<rijeci.size(); i++) {
		int d1(recenica.size());
		int d2(rijeci.at(i).size());
		for(int j=0; j<d1-d2+1; j++) {
			if(recenica.substr(j,d2)==rijeci.at(i)) {
				if(j!=0 && Slovo(recenica.at(j-1))) continue;
				if(j!=(d1-d2) && Slovo(recenica.at(j+d2))) continue;
				int d;
				if(d2%2==0) d=d2/2;
				else d=(d2+1)/2;
				recenica=recenica.substr(0,j+d)+Palindrom(rijeci.at(i).substr(0,d2/2))+recenica.substr(j+d2,d1-d2-j);
				j+=d;
			}
		}
	}
	return recenica;
}

int main ()
{
	std::string s;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,s);
	std::vector<std::string> fraze;
	std::cout<<"Unesite fraze: ";
	for(;;) {
		std::string fraza;
		char z;
		bool kraj(true);
		do {
			z=std::cin.get();
			if(z!='\n') {
				fraza.push_back(z);
				kraj=false;
			}
		} while(z!='\n');
		if(!kraj) fraze.push_back(fraza);
		else break;
	}
	std::cout<<"Recenica nakon Palindrom transformacije: "<<NapraviPalindrom(s,fraze)<<std::endl;
	std::cout<<"Recenica nakon PoluPalindrom transformacije: "<<NapraviPoluPalindrom(s,fraze);
	return 0;
}