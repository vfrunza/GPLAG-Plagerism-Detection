/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>

int PotencijalniKrivci (char **&pok, std::vector<std::string> imena) {
//	typename std::remove_reference <decltype (*poc)>::type* pok_na_dinamicki=nullptr;
	pok=nullptr;
	try {
		pok= new char*[imena.size()];
		for (int i=0; i<imena.size(); i++){
			pok[i]=nullptr;
			try {
				pok[i]=new char[imena[i].length()+1];
				std::strcpy(pok[i],imena[i].c_str());
//std::cout<<" spisak: "<<pok[i]<<"\n";
			}
			catch (...){
				for (int i=0; i<imena.size(); i++) {
					delete [] pok[i];
					pok[i]=nullptr;
				}
				throw;
			}
		}
	}
	catch (...){
		for (int i=0; i<imena.size(); i++)
			delete[] pok[i];
		throw;
	}
	return imena.size();
}

std::string String_izuzetak (std::string ime) {
	std::string s="Osoba sa imenom ";
	s+=ime;
	s+=" nije bila optuzena";
	return s;
}

int OdbaciOptuzbu (char **&pok, int broj_nizova, std::string nevin) {
	int pom=0,brojac_obrisanih=0;
	for (int i=0; i<broj_nizova; i++){
		std::ostringstream ime;
		ime<<pok[i];
		if (ime.str()==nevin) {
			delete[] pok[i];
			pok[i]=nullptr;
			pom=1;
		}
		else;
//std::cout<<pok[i]<<" ime\n";
	} 
	try {
		if(pom==0) throw std::domain_error (String_izuzetak(nevin));
	}
	catch (std::domain_error a) {
		std::cout<<a.what()<<std::endl;
		return broj_nizova;
	}
	for (int i=0; i<broj_nizova; i++)
		if(pok[i]==nullptr) brojac_obrisanih++;
//std::cout<<"brojc obrizasni "<<brojac_obrisanih<<"\n";
	if (brojac_obrisanih>10) {
		auto stari_pok=pok;
		pok=nullptr;
		try {
			pok=new char*[broj_nizova-brojac_obrisanih];
			for (int i=0,j=0; i<broj_nizova; i++){
				if (stari_pok[i]!=nullptr) {
					pok[j]=stari_pok[i];
					j++;
				}
			}
			delete[] stari_pok;
			broj_nizova-=brojac_obrisanih;
		}
		catch (std::bad_alloc){
			delete[] pok;
			pok=nullptr;
			pok=stari_pok;
			delete[] stari_pok;
			
		}
	}
	return broj_nizova;
}

int DodajOptuzbu (char **&pok, int broj_nizova, std::string kriv) {
	char *novi_pok=nullptr;
	int pom=0;
	try {
		novi_pok=new char[kriv.length()+1];
		std::strcpy(novi_pok,kriv.c_str());
		for (int i=0; i<broj_nizova; i++)
			if (pok[i]==nullptr) {
				pok[i]=novi_pok;
				pom=1;
				break;
			}
		if (pom==0) {
			auto stari_pok=pok;
			try {
				pok=nullptr;
				pok=new char*[broj_nizova+1];
				for (int i=0; i<broj_nizova; i++)
					pok[i]=stari_pok[i];
				pok[broj_nizova]=novi_pok;
				delete[] stari_pok;
				novi_pok=nullptr;
				broj_nizova=broj_nizova+1;
			}
			catch (std::bad_alloc) {
				delete[] pok;
				pok=nullptr;
				pok=stari_pok;
				stari_pok=nullptr;
				throw;
			}
		}
	}
	catch (...) {
		delete[] novi_pok;
		throw;
	}
	return broj_nizova;
}

void IzlistajOptuzbu (char **pok, int broj_nizova) {
	for (int i=0; i<broj_nizova; i++) {
		if (pok[i]==nullptr);
		else std::cout<<pok[i]<<"\n";
	}
}

std::vector<std::string> Unos_krivaca (int velicina){
	std::vector<std::string> spisak;
	std::string ime;
	std::cin.clear();
	std::cin.ignore(10000,'\n');
	for (int i=0; i<velicina; i++){
		std::getline(std::cin,ime);
		spisak.push_back(ime);
	}
	return spisak;
}

void Ispisi (std::vector<std::string> spisak){
	for (int i=0; i<spisak.size(); i++){
		std::cout<<spisak[i];
		std::cout<<std::endl;
	}
}

int main ()
{
	try {
		int broj_krivaca;
		std::cout<<"Koliko potencijalnih krivaca zelite unijeti? \n";
		std::cin>>broj_krivaca;
		std::cout<<"Unesite potencijalne krivce: \n";
		auto krivci=Unos_krivaca(broj_krivaca);
//Ispisi(krivci);
		char **pokazivac_na_spisak;
//std::cout<<" duzina "<<krivci.size();
		int broj_alociranih_nizova=PotencijalniKrivci(pokazivac_na_spisak,krivci);
		int opcija;
		do {
			std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: \n";
			std::cin>>opcija;
			if (opcija==2) {
				std::cout<<"Unesite ime koje zelite izbaciti: \n";
				std::cin.clear();
				std::cin.ignore(10000,'\n');
				std::string oslobodjeni;
				std::getline(std::cin,oslobodjeni);
				broj_alociranih_nizova=OdbaciOptuzbu(pokazivac_na_spisak,broj_alociranih_nizova,oslobodjeni);
//std::cout<<broj_alociranih_nizova<<" broj ";
			}
			else if (opcija==1) {
				std::cout<<"Unesite ime novog optuzenog: \n";
				std::cin.clear();
				std::cin.ignore(10000,'\n');
				std::string novi_optuzeni;
				std::getline(std::cin,novi_optuzeni);
				broj_alociranih_nizova=DodajOptuzbu(pokazivac_na_spisak, broj_alociranih_nizova, novi_optuzeni);
			}
			else if (opcija==3) {
				 IzlistajOptuzbu(pokazivac_na_spisak, broj_alociranih_nizova);
			}
			else if (opcija==0) {
				for (int i=0; i<broj_alociranih_nizova; i++)
					delete[] pokazivac_na_spisak[i];
				delete[] pokazivac_na_spisak;
				break;
			}
		} while (opcija!=0);
	}
	catch (std::bad_alloc ) {
		std::cout<<"Neuspjela alokacija!";
	}
	return 0;
}