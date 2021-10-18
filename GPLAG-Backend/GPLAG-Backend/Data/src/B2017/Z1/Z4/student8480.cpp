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

bool JeLiSlovo(char slovo)
{
	if(slovo>=65 && slovo<=90 || slovo>=97 && slovo<=122) return true;
	return false;
}
std::string NapraviPalindrom (std::string recenica, std::vector<std::string> fraze)
{
	if(fraze.size()==0) return recenica;

	for(int i=0; i<fraze.size(); i++) { //petljom prolazimo kroz fraze
		if(fraze.at(i).size()>recenica.size()) continue; /*Ako je fraza duza
													od recenice, preskacemo je*/
		for(int j=0; j<=recenica.size()-fraze.at(i).size(); j++) {
			std::string tmp=recenica.substr(j,fraze.at(i).size()); /*Uzimamo
													podstringove duzine fraze*/
			if(tmp==fraze.at(i)) {
				int a(j), b(j+fraze.at(i).size()-1), c(b+1); /*indeks b je na kraju
										rijeci, a indeks c gdje se ubacuje slovo*/
				if((b==recenica.size()-1 || JeLiSlovo(recenica.at(b+1))==false) &&
				        (a==0 || JeLiSlovo(recenica.at(a-1))==false )) {
					while(b>=a) {//prolazimo kroz rijec unazad i dodajemo na poziciju c
						recenica.insert(recenica.begin()+c, recenica.at(b));
						b--;
						c++;
					}
				}
			}
		}
	}
	return recenica;
}

std::string NapraviPoluPalindrom (std::string recenica, std::vector<std::string> spisak)
{
	if(spisak.size()==0) return recenica;

	for(int i=0; i<spisak.size(); i++) {//petlja prolazi kroz fraze
		if(spisak.at(i).size()>recenica.size()) continue;
		for(int j=0; j<=recenica.size()-spisak.at(i).size(); j++) {//petlja kroz recenicu
			std::string tmp(recenica.substr(j,spisak.at(i).size()));/*uzimamo podstringove
																	duzine fraze*/
			if(tmp==spisak.at(i)) {//ako je podstring jednak trazenoj frazi
				int a(j), b(j+spisak.at(i).size()-1);
				
				if((b==recenica.size()-1 || JeLiSlovo(recenica.at(b+1))==false) &&
				        (a==0 || JeLiSlovo(recenica.at(a-1))==false)) {
					while(a<=b) {//prepisujemo prvu polovinu rijeci preko druge
						recenica.at(b)=recenica.at(a);
						a++;
						b--;
					}
				}
			}
		}
	}
	return recenica;
}

int main ()
{
	std::string recenica;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin, recenica);

	std::vector<std::string> fraze(0);
	std::cout<<"Unesite fraze: ";

	while(1) {
		std::string temp;
		std::getline(std::cin, temp);
		if(temp.size()!=0) fraze.push_back(temp);
		else break;
	}

	std::cout<<"Recenica nakon Palindrom transformacije: "<<NapraviPalindrom(recenica,fraze)<<std::endl;
	std::cout<<"Recenica nakon PoluPalindrom transformacije: "<<NapraviPoluPalindrom(recenica,fraze)<<std::endl;

	return 0;
}