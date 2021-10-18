#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>

bool samoglasnik(char slovo){
	if(slovo == 'a' || slovo == 'A' || slovo == 'E' || slovo == 'e' || slovo == 'i' || slovo=='I' || slovo=='o' || slovo == 'O' || slovo == 'U' || slovo == 'u')return true;
	else return false;
}
std::string prebaciSveUZagrade(std::string recenica){
	std::string prebacenaRecenicaUZagrade = "";
	int brojac = 0;
	while(recenica[brojac]==' '){
		prebacenaRecenicaUZagrade += recenica[brojac];
		brojac++;
	}
	
}
std::string IstakniSavrsenoRitmicneRijeci(std::string recenica){
	
}
int main ()
{
    std::string s="AKIHITO I YOKOHAMA";
    std::string pom;
    pom=SavrsenoRitmicneRijeci(s);
    std::cout<<pom;
	return 0;
}