/*B 16/17, Zadaća 2, Zadatak 4

	NAPOMENA: i javni ATo-vi su dio postavke

	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

int PotencijalniKrivci(char**& NaZnakove, std::vector <std::string> v)
{

	char** MatricaZnakova=nullptr;

	try {
		MatricaZnakova = new char* [v.size()];
		for(int i=0; i<v.size(); i++) {
			MatricaZnakova[i]=nullptr;
		}

	} catch(...) {
		delete[] MatricaZnakova;
		throw std::bad_alloc();


	}
	try {
		for(int i=0; i<v.size(); i++) {
			MatricaZnakova[i] = new char [v[i].size()+1];
			for(int j=0; j<v[i].size(); j++) {
				MatricaZnakova[i][j]=v[i][j];
			}
			MatricaZnakova[i][v[i].size()]='\0';

		}
	} catch(...) {
		for(int i=0; i<v.size(); i++) {
			delete[] MatricaZnakova[i];
		}
		delete[] MatricaZnakova;

		throw std::bad_alloc();
	}
	NaZnakove = MatricaZnakova;
	return v.size();

}

int OdbaciOptuzbu(char**& NaZnakove, int velicina, std::string ime)
{
	int i;
	for(i=0; i<velicina; i++) {

		if(ime == NaZnakove[i]) {
			delete[] NaZnakove[i];
			NaZnakove[i]=nullptr;
			break;
		}

	}
	if(i==velicina) throw std::domain_error("Osoba sa imenom "+ime+" nije bila optuzena");
	int brojac(0);
	for(i=0; i<velicina; i++) {
		if(NaZnakove[i]==nullptr) {
			brojac++;
		}
	}
	if(brojac>10) {
		char** pok_pok=nullptr;
		try {
			pok_pok=new char*[velicina-brojac];
			for(int j=0; j<velicina-brojac; j++) {
				pok_pok[j]=nullptr;
			}
			for(int j=0, k=0; j<velicina-brojac; j++, k++) {
				if(NaZnakove[k]==nullptr) k++;
				pok_pok[j]=NaZnakove[k];
			}
			for(int j=0; j<velicina; j++) {
				NaZnakove[j]=nullptr;
			}
			delete[] NaZnakove;
			NaZnakove=pok_pok;
			return velicina-brojac;
		}

		catch(...) {
			delete[] pok_pok;
			return velicina;
		}
	}
	return velicina;

}
int DodajOptuzbu(char **& NaZnakove, int velicina, std::string ime)
{
	for(int i=0; i<velicina; i++) {
		if(NaZnakove[i]==nullptr) {
			NaZnakove[i]=new char [ime.size()+1];
			int j;
			for(j=0; j<ime.size(); j++) {
				NaZnakove[i][j]=ime[j];
			}
			NaZnakove[i][j]='\0';

			return velicina;
		}

	}
	char** pok_pok=nullptr;
	try {
		pok_pok=new char*[velicina+1];
		for(int j=0; j<velicina+1; j++) {
			pok_pok[j]=nullptr;
		}
		for(int i=0; i<velicina; i++) {
			pok_pok[i]=NaZnakove[i];
		}
		pok_pok[velicina]=new char [ime.size()+1];
		for(int j=0; j<ime.size(); j++) {
			pok_pok[velicina][j]=ime[j];
		}
		pok_pok[velicina][ime.size()]='\0';
		
		for(int i=0; i<velicina; i++) {
			NaZnakove[i]=nullptr;
		}
		delete[] NaZnakove;
		NaZnakove=pok_pok;

	} catch(...) {
		delete[] pok_pok;
		throw std::bad_alloc();
	}
	return velicina+1;
}
void IzlistajOptuzbu(char** imena, int velicina)
{
	for(int i=0; i<velicina; i++) {
		if(imena[i]==nullptr) continue;
		std::cout<<imena[i]<<std::endl;
		
	}
}

int main ()
{
	char** NizPotencijalnih=nullptr;
	std::vector<std::string> vs;
	int broj;
	std::cout<<"Koliko potencijalnih krivaca zelite unijeti? "<<std::endl;
	std::cin>>broj;
	std::cin.clear();
	std::cin.ignore(100000, '\n');
	std::cout<<"Unesite potencijalne krivce: "<<std::endl;
	std::string ime;
	for(int i=0; i<broj; i++) {
		std::getline(std::cin, ime);
		vs.push_back(ime);
	}
	int n, nn = PotencijalniKrivci(NizPotencijalnih, vs);
	n=nn;
	int opcija;
	std::string novajlija, nevin;

	do {
		std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: ";
		std::cin>>opcija;

		std::cin.clear();
		std::cin.ignore(100000, '\n');
		std::cout<<std::endl;

		if(opcija==1) {
			std::cout<<"Unesite ime novog optuzenog: "<<std::endl;
			std::getline(std::cin, novajlija);
			try{
			n = DodajOptuzbu(NizPotencijalnih, n, novajlija);
			}
			catch(std::bad_alloc){
				std::cout<<"Neuspjela alokacija"<<std::endl;
			}
		}

		if(opcija==2) {
			std::cout<<"Unesite ime koje zelite izbaciti: "<<std::endl;
			std::getline(std::cin, nevin);
			try {
				n = OdbaciOptuzbu(NizPotencijalnih, n, nevin);
			} catch(std::domain_error poruka) {
				std::cout<<poruka.what()<<std::endl;
			}
		}

		if(opcija==3) {
			IzlistajOptuzbu(NizPotencijalnih, n);
		}


	} while(opcija != 0);
	for(int i=0; i<n; i++)delete[] NizPotencijalnih[i];
	delete[] NizPotencijalnih;

	return 0;
}