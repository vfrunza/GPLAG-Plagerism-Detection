#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

void obrisi(char **p, int duzina) {
	for(int i=0; i<duzina; i++) delete[] p[i];
	delete[] p;
}

int PotencijalniKrivci(char **&p, std::vector<std::string> v ) {
	int broj_alociranih_nizova (0);
	p=nullptr;
	try {
		p=new char*[v.size()];
		for(int i=0; i<v.size(); i++) {
			p[i]=nullptr;
		}
		try {
			for(int i=0; i<v.size(); i++) {
				p[i]=new char[v[i].size()+1];
			}
		}
		catch(...) {
			obrisi(p, v.size());
			throw;
		}
		for(int i=0; i<v.size(); i++) {
			for(int j=0; j<v[i].size(); j++) {
				p[i][j]=v[i][j];
			}
			broj_alociranih_nizova++;
			p[i][v[i].size()]='\0';
		}
	}
	catch(std::bad_alloc izuzetak) {
		delete[] p;
		throw;
	}
	return broj_alociranih_nizova;
}

int OdbaciOptuzbu (char **&p, int broj_osumnjicenih, std::string ime) {
	int osloboden_optuzbe(0);
	int i;
	for(i=0; i<broj_osumnjicenih; i++) {
		if(p[i]==nullptr) continue;
		if(p[i]==ime) {
			delete[] p[i];
			p[i]=nullptr;
			break;
		}
	}
	if(i==broj_osumnjicenih) {
			std::string s("Osoba sa imenom ");
			s=s+ime+std::string (" nije bila optuzena");
			throw std::domain_error (s);
	}
	
	for(int i=0; i<broj_osumnjicenih; i++) if(!p[i]) osloboden_optuzbe++;
	if(osloboden_optuzbe<=10) return broj_osumnjicenih;
	
	char **novi(nullptr);
	try {
		novi=new char*[broj_osumnjicenih-osloboden_optuzbe];
		for(int i=0; i<broj_osumnjicenih-osloboden_optuzbe; i++) novi[i]=nullptr;
		int j(0);
		for(int i=0; i<broj_osumnjicenih-osloboden_optuzbe; i++) {
			if(p[j]) novi[i]=p[j];
			else i--;
			j++;
		}
		delete[] p;
		p=novi;
	}
	catch(std::bad_alloc izuzetak) {
		obrisi(novi, broj_osumnjicenih-osloboden_optuzbe);
		return broj_osumnjicenih;
	}
	return broj_osumnjicenih-osloboden_optuzbe;	
}

int DodajOptuzbu (char **&p, int broj_osumnjicenih, std::string ime) {
	char *osoba(nullptr);
	try {
		osoba=new char[ime.size()+1];
		for(int i=0; i<ime.size()+1; i++) osoba[i]=ime[i];
		osoba[ime.size()]='\0';
	}
	catch(...) {
		delete[] osoba;
		throw;
		return broj_osumnjicenih;
	}
	for(int i=0; i<broj_osumnjicenih; i++) {
		if(!p[i]) {
			p[i]=osoba;
			p[i][ime.size()]='\0';
			break;
		}
		if(i==broj_osumnjicenih-1 && p[i]) {
			char** novi(nullptr);
			try {
				novi=new char*[++broj_osumnjicenih];
				try {
					for(int i=0; i<broj_osumnjicenih; i++) novi[i]=nullptr;
					for(int i=0; i<broj_osumnjicenih-1; i++) novi[i]=p[i];
					novi[broj_osumnjicenih-1]=osoba;
					novi[broj_osumnjicenih-1][ime.size()]='\0';
					delete[] p;
					p=novi;	
					return broj_osumnjicenih;
				}
				catch(...) {
					delete[] novi[broj_osumnjicenih-1];
					delete[] novi;
				}
			}
			catch(std::bad_alloc izuzetak) {
				delete[] novi;
				return broj_osumnjicenih;
			}
		}
	}
	return broj_osumnjicenih;	
}

void IzlistajOptuzbu (char **p, int broj_osumnjicenih) {
	for(int i=0; i<broj_osumnjicenih; i++) {
		if(p[i]==nullptr) continue;
		std::cout << std::endl << p[i];
	}
	std::cout << std::endl;
}

int main ()
{
	int broj_krivaca;
	std::cout << "Koliko potencijalnih krivaca zelite unijeti? ";
	std::cin >> broj_krivaca;
	std::cout << std::endl << "Unesite potencijalne krivce: ";
	std::vector<std::string> v(broj_krivaca);
	std::cout << std::endl;
	std::string s;
	std::cin.ignore(1000, '\n');
	for(int i=0; i<broj_krivaca; i++) {
		std::getline(std::cin, s);
		v[i]=s;
	}
	char **p(nullptr);
	int broj_osumnjicenih=PotencijalniKrivci(p, v);

	for(;;) {
		std::cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: ";
		int a;
		std::cin >> a;
		if(a==1) {
			std::string s1;
			std::cout << std::endl << "Unesite ime novog optuzenog: ";
			std::cin.ignore(1000, '\n');
			std::getline(std::cin, s1);
			broj_osumnjicenih=DodajOptuzbu(p, broj_osumnjicenih, s1);
			std::cout << std::endl;
		}
		if(a==2) {
			std::string s1;
			std::cout << std::endl << "Unesite ime koje zelite izbaciti: ";
			std::cin.ignore(1000, '\n');
			std::getline(std::cin, s1);
	//		try {
				broj_osumnjicenih=OdbaciOptuzbu(p, broj_osumnjicenih, s1);
	//		} catch(std::domain_error e) { std::cout << e.what(); }
			std::cout << std::endl;
		}
		if(a==3) IzlistajOptuzbu(p, broj_osumnjicenih ); 
		if(a==0) {
			obrisi(p, broj_osumnjicenih);
			return 0;
		}
	}
	return 0;
}

