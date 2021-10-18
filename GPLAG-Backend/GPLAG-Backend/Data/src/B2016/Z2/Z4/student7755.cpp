/*B 16/17, Zadaća 2, Zadatak 4

	NAPOMENA: i javni ATo-vi su dio postavke

	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>


void IzlistajOptuzbu(char **niz,int &n) {
	for(int i=0;i<n;i++) {
		if(niz[i] != nullptr) {
			std::cout << niz[i];
			std::cout<<std::endl;
		}
	}
}


int PotencijalniKrivci(char **(&niz),std::vector<std::string>krivci) {
		int duzina = 0;
	int n=krivci.size();
	niz = new char*[n];
	char **nizPokazivaca(nullptr);
	try {
		nizPokazivaca = new char*[n];
		for(int i=0;i<n;i++) {
			duzina = krivci[i].size()+1;
			nizPokazivaca[i]=new char[duzina];
			for(int j=0;j<duzina-1;j++)
				nizPokazivaca[i][j]=krivci[i][j];
		}
		std::copy(nizPokazivaca, nizPokazivaca+n, niz);
	
	/*for(int i=0;i<n;i++) {
		delete [] nizPokazivaca[i];
			delete [] nizPokazivaca;
	}*/
	return n;
	}
	catch(std::bad_alloc) {
		std::cout<<"Problem: Nema dovoljno memorije!";
	}
}

bool JesuLiIsti(char *niz, std::string s){
	for(int i=0; i<s.size(); i++){         //ovdje
		if(*niz != s[i])
			return false;
		niz++;
	}
	return true;
}

int OdbaciOptuzbu(char **(&niz),int &n,std::string osoba) {
	int brojac1(0);
	for(int i=0;i<n;i++) {
		
		if(JesuLiIsti(niz[i], osoba)) {
			delete[] niz[i];
			niz[i]=nullptr;
			int brojac(0);
			for(int j=0;j<n;j++) {
				if(niz[j]==nullptr)
					brojac++;
			}
			if(brojac>=10) {
				char **noviNiz = nullptr;
				try{
					noviNiz=new char*[n-brojac];
					int j(0);
					while(j<n-brojac) {
						for(int i=0;i<n;i++) {
							if(niz[i]!=nullptr) {
								noviNiz[j]=niz[i];
								j++;
							}
						}
					}
					for(int i=0; i<n; i++){
						delete[] niz[i];
					delete[] niz;
					}
					niz = new char*[n];
					std::copy(noviNiz, noviNiz+n, niz);
				for(int i=0;i<n;i++)
					delete[] noviNiz[i];
				delete[] noviNiz;
				return n;
		   }
		   catch(std::bad_alloc) {
					std::cout << "Problemi sa memorijom." << std::endl;
				}
				} else {
				return n;
			}
		}else{
			brojac1++;
		}

	if(brojac1 == n-1)
		throw std::domain_error("Osoba sa imenom <osoba> nije bila optuzena."); }

}

int DodajOptuzbu(char **(&niz),int &n,std::string osoba) {
 char **noviNiz = nullptr;
 char *optuzena = nullptr;
	try {
		int duzina = osoba.size()+1;
		optuzena = new char[duzina];
		for(int i=0; i<duzina; i++)
			optuzena[i] = osoba[i];
		//optuzena[duzina-1] = '\0';
		for(int i=0;i<n;i++) {
			if(niz[i] == nullptr) {
				niz[i] = optuzena;
				return n;
			}
		}
		noviNiz = new char*[n+1];
		std::copy(niz, niz+n, noviNiz);
		noviNiz[n]=optuzena;
		for(int i=0;i<n;i++)
			delete[] niz[i];
		delete [] niz;
		n++;
		niz = new char*[n];
		std::copy(noviNiz, noviNiz+n, niz);
		return n;
	
	for(int i=0;i<n;i++)
		delete[] noviNiz[i];
	delete [] noviNiz;
	delete[] optuzena;
	}
		catch(std::bad_alloc) {
		std::cout<<"Problem: Nema dovoljno memorije";
	}
}



int main ()
{   
	try {
	int n = 0;
	char **niz = nullptr;
	std::cout<<"Koliko potencijalnih krivaca zelite unijeti? "<<std::endl;
	std::cin>>n;
	//niz = new char*[n];
	std::cout << "Unesite potencijalne krivce: "<<std::endl;
	std::vector<std::string> krivci(n);
	for(int i=0; i<n; i++){
		std::cin >> krivci[i];
	}
	n = PotencijalniKrivci(niz, krivci);
	int opcija = 0;
	do{
		std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog, 3 za izlistavanje optuzenih, 0 za kraj: "<<std::endl;
		std::cin>> opcija;
		if(opcija==1){
			std::string krivac;
			std::cout << "Unesite ime novog optuzenog: "<<std::endl;
			std::cin >> krivac;
			n = DodajOptuzbu(niz, n, krivac);
		}else if(opcija == 2){
			std::string krivac;
			std::cout << "Unesite ime koje zelite izbaciti: "<<std::endl;
			std::cin >> krivac;
			n = OdbaciOptuzbu(niz, n, krivac);
		}else if(opcija == 3){
			IzlistajOptuzbu(niz, n);
		}
	}while(opcija != 0);
}
catch(std::bad_alloc) {
	std::cout<<"Nedovoljno memorije!";
}

	//AT2
	
	/*char **nizPotencijalnih;
  std::vector<std::string> imena = {"Fudo", "Pero", "Meho", "Fata", "Bajro", "Luca", "Jovo"};
  int n = PotencijalniKrivci( nizPotencijalnih, imena);
  IzlistajOptuzbu(nizPotencijalnih, n);
  
  //AT3
  int m = OdbaciOptuzbu(nizPotencijalnih, n, "Fata");
  std::cout << m << std::endl;
  dealociraj(nizPotencijalnih, n);*/
	return 0;
}