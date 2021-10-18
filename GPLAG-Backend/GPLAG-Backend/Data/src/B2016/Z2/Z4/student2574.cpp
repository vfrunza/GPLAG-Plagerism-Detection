#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <type_traits>



void IzlistajOptuzbu (char **znak, std::vector<std::string> prodavaci) {
	for (int i=0; i<prodavaci.size(); i++) {
		char *j (&(prodavaci[i][0]));
		while (*j!=(prodavaci.at(i).size())) {
			std::cout<<*j++;
		}
	}
}

int main () {
	int opcija(0);
	std::vector<std::string> Taj={"Jasmin Bajrić","Bajrić", "JJJ SSSS"};
	char *pok (&Taj[0][0]);
	char **znak(&pok);
	std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: ";
	for (;;) {
		std::cin>>opcija;
		if (opcija==0)
			break;
		if (opcija==3)
			IzlistajOptuzbu(znak,Taj);
			
	}
	return 0;
}