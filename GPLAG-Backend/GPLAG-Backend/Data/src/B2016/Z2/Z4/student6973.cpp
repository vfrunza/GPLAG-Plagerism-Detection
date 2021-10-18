/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <vector>


PotencijalniKrivci(char **&znak,std::vector<std::string> s)

OdbaciOptuzbu

DodajOptuzbu

void IzlistajOptuzbu(char **znak, std::vector<std::string> s){
	for(int i=0; i<s.size(); i++){
		std::cout<<s[i]<<std::endl;
	}
}



int main ()
{
	int n;
	std::vector<std::string> v;
	std::cout<<"Koliko potencijalnih krivaca zelite unijeti? ";
	std::cin>>n;
	std::cout<<"Unesite potencijalne krivce: ";
	for(int i=0; i<n; i++){
		std::string s;
		std::getline(std::cin,s);
		v.push_back(s);
	}
	
	int m;
	std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: ";
	std::cin>>m;
	switch(m){
			case 1:PotencijalniKrivci
	
			case 2:OdbaciOptuzbu
	
			case 3:DodajOptuzbu
	
			case 0:IzlistajOptuzbu
	
	}
	
	
	return 0;
}