/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
PotencijalniKrivci(&,std::vector<std::string> vekt){
	
}

int main ()
{
	int n;
	std::cout<<"Koliko potencijalnih krivaca zelite unijeti?";
	std::cin>>n;
	
	std::vector<std::string>> vekt;
	
	std::cout<<"Unesite potencijalne krivce: ";
	for(int i=0;i<n;i++){
		std::string ime;
		std::cin>>ime;
		vekt.push_back(ime);
	}
	
	std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj:";
	
	return 0;
}