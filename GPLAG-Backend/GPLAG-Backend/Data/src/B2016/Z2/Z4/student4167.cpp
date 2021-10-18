#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <cstring>
#include <new>

int PotencijalniKrivci(char **&p, std::vector<std::string> vs) {
	//try {
		p = new char *[vs.size()];
	//}
	//catch(std::bad_alloc) {
	//	delete[] p;
	//	throw;
	//}
	for(int i(0); i<vs.size(); i++)
		p[i] = nullptr;
	try {
	for(int i(0); i<vs.size(); i++)
		p[i] = new char [vs[i].size()+1];
	}
	catch(std::bad_alloc) {
		for(int i(0); i<vs.size(); i++)
			delete[] p[i];
		delete[] p;
		throw;
	}
	for(int i(0); i<vs.size(); i++) {
		int j(0);
		for(; j<vs[i].size(); j++)
			p[i][j]=vs[i][j];//std::strcpy(p[i], vs[i]);
		p[i][j]='\0';
	}
	return vs.size();
}

int OdbaciOptuzbu(char **&p, int n, std::string s) {
	int broj(n), broj_null(0);
	char **p2(p);
	bool a(false);
	for(int i(0); i<n; i++) {
		if(p[i]==s/*std::strcmp(p[i], s)==0*/) {
			a=true;
			delete[] p[i];
			p[i]=nullptr;
			broj--;
		}
		if(p[i]==nullptr) broj_null++;
	}
	//try {
		if(!a) throw std::domain_error("Osoba sa imenom " + s + " nije bila optuzena");
	//}
	//catch(std::domain_error a) {
	//	std::cout << a.what() << std::endl;
	//}
	if(broj_null<=10) {
		return n;
	} else {
		try {
		p = new char *[broj];
		}
		catch(std::bad_alloc) {
			//delete[] p;
			p=p2;
		}
		for(int i(0); i<broj; i++)
			p[i]=nullptr;
		int i(0);
		try {
		for(; i<n; i++)
			if(p2[i]!=nullptr) {
				int j(0);
				while(p2[i][j]!='\0') j++;
					p[i] = new char [j+1];
					j=0;
					//std::strcpy(p[i], p2[i]);
					while(p2[i][j]!='\0') {
						p[i][j]=p2[i][j];
						j++;
					}
					p[i][j]='\0';
			}
		for(int i(0); i<n; i++)
			delete[] p2[i];
			delete[] p2;
		}
				catch(std::bad_alloc) {
					for(int i(0); i<broj; i++)
						delete[] p[i];
					delete[] p;
					p=p2;
					p2=nullptr;
					return n;
				}
		return broj;
	}
}

int DodajOptuzbu(char **&p, int n, std::string s) {
	char *v(new char [s.length()+1]);
	char **p2(p);
	int i(0);
	for(; i<s.length(); i++)
		v[i]=s[i];
	v[i]='\0';
	i=0;
	for(; i<n; i++)
		if(p[i]==nullptr) {
			p[i]=v;
			break;
		}
	if(i!=n) {
		return n;
	} else {
		try {
		p = new char *[n+1];
		}
		catch(std::bad_alloc) {
			//for(int i(0); i<n+1; i++)
			//	delete[] p[i];
			//delete[] p;
			p=p2;
			p2=nullptr;
			delete[] v;
			throw;
		}
		for(int i(0); i<n+1; i++)
			p[i]=nullptr;
	try {
		for(int i(0); i<n; i++)
			if(p2[i]!=nullptr) {
				int j(0);
				//j = std::strlen(p2[i]);
				while(p2[i][j]!='\0') j++;
				p[i] = new char [j+1];
				j=0;
				while(p2[i][j]!='\0') {
					p[i][j]=p2[i][j];
					j++;
				}
				p[i][j]='\0';
			}
		p[n] = v;
		for(int i(0); i<n; i++)
			delete[] p2[i];
			delete[] p2;
	}
				catch(std::bad_alloc) {
					for(int i(0); i<n+1; i++)
						delete[] p[i];
					delete[] p;
					delete[] v;
					p=p2;
					return n;
				}
		return n+1;
	}
}

void IzlistajOptuzbu(char **p, int n) {
	for(int i(0); i<n; i++) {
		if(p[i]!=nullptr) {
			std::cout << p[i];
			std::cout << std::endl;
		}
	}
}

int main () {
	int n;
	std::cout << "Koliko potencijalnih krivaca zelite unijeti? " << std::endl;
	std::cin >> n;
	std::cout << "Unesite potencijalne krivce: " << std::endl;
	char **p=nullptr;
	std::vector<std::string> vs(n);
	std::cin.ignore(1000, '\n');
	for(int i(0); i<n; i++)
		std::getline(std::cin, vs[i]);
	try {
		n = PotencijalniKrivci(p, vs);
		while(1) {
			std::cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: " << std::endl;
			int k;
			std::cin >> k;
			std::cin.ignore(1000, '\n');
			if(k==0) {
				for(int i(0); i<n; i++) delete[] p[i];
				delete[] p;
				break;
			} else if(k==1) {
				std::string s;
				std::cout << "Unesite ime novog optuzenog: " << std::endl;
				std::getline(std::cin, s);
				n = DodajOptuzbu(p, n, s);
			}
			else if(k==2) {
				std::string s;
				std::cout << "Unesite ime koje zelite izbaciti: " << std::endl;
				std::getline(std::cin, s);
				n = OdbaciOptuzbu(p, n, s);
			}
			else if(k==3) {
				IzlistajOptuzbu(p, n);
			}
			else {
				std::cout << "Pogresan izbor! Pokusajte ponovo." << std::endl;
			}
		}
	}
	catch(std::bad_alloc) {
		//for(int i(0); i<n; i++) delete[] p[i];
		//delete[] p;
		std::cout << "Neuspjela alokacija" << std::endl;
		//std::cout << "Izuzetak: Nedovoljno memorije!" << std::endl;
	}
	catch(std::domain_error a) {
		std::cout << "Izuzetak:" << a.what() << std::endl;
	}
	return 0;
}