/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <stdexcept>

#define pb push_back

int PotencijalniKrivci(char ** &p, std::vector<std::string> vect) {
	int ret = 0;
	char **mat = nullptr;
	try {
		mat = new char*[vect.size()]{};
		for (int i = 0; i < vect.size(); i++) {
			mat[i] = new char[vect.at(i).length() + 1];
			for (int j = 0; j < vect.at(i).length(); j++) {
				mat[i][j] = vect.at(i).at(j);
			}
			mat[i][vect.at(i).length()] = '\0';
			ret++;
		}
		
		p = mat;
		
		return ret;
	}
	catch(std::bad_alloc) {
		if (mat) for (int i = 0; i < vect.size(); i++) delete[] mat[i];
		if (mat) delete[] mat;
		throw;
	}
}
int OdbaciOptuzbu(char ** &p, int n, std::string s) {
	
	int idx_trazenog = -1;
	for (int i = 0; i < n; i++) {
		char *pok = p[i];
		int micem = 0;
		bool isti = 1;
		
		while (*pok != '\0') {
			if (micem > s.length()) {
				isti = 0;
				break;
			}
			if (*pok != s[micem]) {
				isti = 0;
				break;
			}
			pok++;
			micem++;
		}
		if (isti) {
			idx_trazenog = i;
			break;
		}
	}
	
	//std::cout << "U OdbaciOptuzbu, idx_trazenog = " << idx_trazenog << "\n";
	
	if (idx_trazenog == -1) throw std::domain_error("Osoba sa imenom " + s + " nije bila optuzena");
	else {
		//std::cout << "USAO!\n";
		delete[] p[idx_trazenog];
		p[idx_trazenog] = nullptr;
		int broj_nulla = 0;
		
		for (int i = 0; i < n; i++)
			if (p[i] == nullptr) broj_nulla++;
		if (broj_nulla <= 10) return n;
		else {
			char **mat = nullptr;
			try {
				mat = new char*[n - broj_nulla]{};
				for (int i = 0; i < n; i++) {
					if (p[i] != nullptr) {
						mat[i] = p[i];
					}
				}
				p = mat;
				
				
				return n - broj_nulla;
			}
			catch (std::bad_alloc) {
				if (mat) for (int i = 0; i < n - broj_nulla; i++) delete[] mat[i];
				if (mat) delete[] mat;
				throw;
			}
		}
	}
}
int Duzina(char *p) {
	int ret = 0;
	while (*p != '\0') {
		ret++;
		p++;
	}
	return ret;
}
int DodajOptuzbu(char ** &p, int n, std::string s) {
	char *Kopirana = nullptr;
	try {
		char *Kopirana = new char[s.length() + 1]{};
		for (int i = 0; i < s.length(); i++)
			Kopirana[i] = s.at(i);
		Kopirana[s.length()] = '\0';
		
		int idx_nulla = -1;
		for (int i = 0; i < n; i++) {
			if (p[i] == nullptr) {
				idx_nulla = i; 
				break;
			}
		}
		
		//std::cout << "U DodajOptuzbu, idx_nulla = " << idx_nulla << "\n";
		
		if (idx_nulla == -1) {			// KOPIRAJ CITAV NIZ PA DODAJ NOVI CLAN NA KRAJ
			char **mat = nullptr;
			try {
				mat = new char*[n + 1]{};
				for (int i = 0; i < n; i++) {
					mat[i] = p[i];
					//std::cout << "U DodajOptuzbu, mat[" << i << "] = " << mat[i] << "\n";
				}
				
				mat[n] = new char[s.length() + 1]{};
				for (int i = 0; i < s.length(); i++)
					mat[n][i] = Kopirana[i];
				mat[n][s.length()] = '\0';
				//std::cout << "U DodajOptuzbu, mat[" << n << "] = " << mat[n] << "\n";
				delete[]p;
				p = mat;
				
				delete[] Kopirana;
				return n + 1;
			}
			catch (std::bad_alloc) {
				if (mat) for (int i = 0; i < n + 1; i++) delete[] mat[i];
				if (mat) delete[] mat;
				delete[] Kopirana;
				throw;
			}
		}
		else {
			delete[] p[idx_nulla];
			p[idx_nulla] = Kopirana;
			delete[] Kopirana;
			
			return n;
		}
		
	}
	catch (std::bad_alloc) {
		delete[] Kopirana;
		throw;
	}
}

void IzlistajOptuzbu(char ** p, int n) {
	for (int i = 0; i < n; i++) {
		if (p[i]) {
			char *pok = p[i];
			while (*pok != '\0') {
				std::cout << *pok;
				pok++;
			}
			std::cout << "\n";
		}
	}
}

int main()
{
	std::cout << "Koliko potencijalnih krivaca zelite unijeti?\n";
	int n, query; std::cin >> n;
	std::cin.ignore(10000, '\n');
	std::vector<std::string> vect;
	
	std::cout << "Unesite potencijalne krivce: \n";
	for (int i = 0; i < n; i++) {
		std::string Temporarni;
		std::getline(std::cin, Temporarni);
		vect.pb(Temporarni);
	}
	
	char ** p = nullptr;
	int Alocirano = PotencijalniKrivci(p, vect);
	
	while (1) {
		//std::cout << "BROJ CLANOVA = " << n << "\n";
		
		std::cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: \n";
		std::cin >> query;
		std::cin.ignore(10000, '\n');
		
		if (query == 0) {
			
			for (int i = 0; i < n; i++) if (p[i]) delete[] p[i];
			if (p) delete[] p;
			break;
		}
		else if (query == 1) {
			std::cout << "Unesite ime novog optuzenog: \n";
			std::string ImeOptuzenog;
			std::getline(std::cin, ImeOptuzenog);
			try { n = DodajOptuzbu(p, n, ImeOptuzenog); }
			catch(std::bad_alloc c) { std::cout << "Izuzetak: " << c.what(); }
			catch(std::domain_error c) { std::cout << "Izuzetak: " << c.what(); }
		}
		else if (query == 2) {
			std::cout << "Unesite ime koje zelite izbaciti: \n";
			std::string ImeIzbacenog;
			std::getline(std::cin, ImeIzbacenog);
			try { n = OdbaciOptuzbu(p, n, ImeIzbacenog); }
			catch(std::bad_alloc c) { std::cout << "Izuzetak: " << c.what(); }
			catch(std::domain_error c) { std::cout << "Izuzetak: " << c.what(); }
		}
		else if (query == 3) {
			IzlistajOptuzbu(p, n);
		}
	}
	return 0;
}