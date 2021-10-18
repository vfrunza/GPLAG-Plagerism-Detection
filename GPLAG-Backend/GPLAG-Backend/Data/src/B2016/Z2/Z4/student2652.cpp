/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <string>
#include <vector>


void brisanje (std::vector<std::string> &vektor, std::string rijec){
	
	for (int i = 0 ; i <vektor.size(); i++){
		if (vektor[i]==rijec) vektor.erase (vektor.begin()+i);
	}
	
	
	
}


int PotencijalniKrivci ( char *&x, std::vector<std::string> y ){
	int c(0);
	char **a (new char *[y.size()]);
	for ( std::string rijec : y ){
	try {
		for (int i =0 ; i<y.size(); i++) {
			int velicina = sizeof (rijec);
			a[i] = new char [velicina]; 
			for (int j =0 ; j<velicina; j++) a[i][j]=rijec[j];
		}
		
	}
			
	catch (...){
		//for (int i =0)
	}
	
	
	}
return y.size();
	
}
int main ()
{
std::cout<<"Koliko potencijalnih krivaca zelite unijeti?";
int x;
std::cin>>x;
std::vector<std::string> krivci;
std::cout <<"Unesite potencijalne krivce:"; 
for (int i=0; i<x; i++){
	std::string krivac;
	std::cin>>krivac;
	krivci.push_back(krivac);
}

for (;;) {
std::cout <<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj:";
int opcija;
std::cin>>opcija;
if (opcija == 0) return 0;
if (opcija == 1) {std::cin>>krivac; krivci.push_back(krivac);}
if (opcija == 2) {std::cout<<"Unesite ime koje zelite izbaciti:"; std::cin>>krivac; brisanje(krivci,krivac);}
}
}



}


	
	
	
	
	return 0;
}