#include <string>
#include <vector>
#include <cstring>
#include <stdexcept>
#include <iostream>

int PotencijalniKrivci(char** &pok, std::vector<std::string> v) {
	char** nizovi_znakova(nullptr);
	
	if (v.size() == 0) return 0;
	
	try {
		nizovi_znakova = new char*[v.size()];
	}
	catch(std::bad_alloc) {
		delete[] nizovi_znakova;
		throw;
	}
	catch(...) {
		delete[] nizovi_znakova;
		throw std::bad_alloc();
	}
	
	for (int i = 0; i < v.size(); i++) nizovi_znakova[i] = nullptr;
	
	try {
		for (int i = 0; i < v.size(); i++) {
			nizovi_znakova[i] = new char[v[i].size() + 1];
			for (int j = 0; j < v[i].size(); j++) {
				nizovi_znakova[i][j] = v[i][j];
			}
			nizovi_znakova[i][v[i].size()] = 0;
		}
		
		pok = nizovi_znakova;
		
		return v.size();
	}
	catch (std::bad_alloc) {
		for (int i = 0; i < v.size(); i++) {
			delete[] nizovi_znakova[i];
		}
		delete[] nizovi_znakova;
		
		throw;
	}
	catch (...) {
		for (int i = 0; i < v.size(); i++) {
			delete[] nizovi_znakova[i];
		}
		delete[] nizovi_znakova;
		
		throw std::bad_alloc();
	}
}

int OdbaciOptuzbu(char** &pok, int n, std::string s) {
	int idx(-1);
	
	for (int i = 0; i < n; i++) {
		if (pok[i] == nullptr) continue;
		int len(std::strlen(pok[i]));
		if (len != s.size()) continue;
		
		if (std::strcmp(pok[i], s.c_str()) == 0) {
			idx = i;
			break;
		}
	}
	
	if (idx < 0) throw std::domain_error("Osoba sa imenom " + s + " nije bila optuzena");
	
	delete[] pok[idx];
	pok[idx] = nullptr;
	
	int cnt(0);
	for (int i = 0; i < n; i++) {
		if (pok[i] == nullptr) cnt++;
	}
	
	if (cnt <= 10) return n;
	
	char** novi(nullptr);
	try {
		int m(n - cnt);
		
		novi = new char*[m];
		
		for (int i = 0, j = 0; i < n; i++) {
			if (pok[i] != nullptr) {
				novi[j++] = pok[i];
			}
		}
		
		delete[] pok;
		pok = novi;
		
		return m;
	}
	catch(...) {
		delete[] novi;
		return n;
	}
}

int DodajOptuzbu(char** &pok, int n, std::string s) {
	char* str(nullptr);
	
	try {
		str = new char[s.size() + 1];
		for (int i = 0; i < s.size(); i++) str[i] = s[i];
		str[s.size()] = 0;
	}
	catch(std::bad_alloc) {
		delete[] str;
		throw;
	}
	catch(...) {
		delete[] str;
		throw std::bad_alloc();
	}
	
	for (int i = 0; i < n; i++) {
		if (pok[i] == nullptr) {
			pok[i] = str;
			return n;
		}
	}
	
	char** novi(nullptr);
	
	try {
		novi = new char*[n + 1];
		for (int i = 0; i < n; i++) novi[i] = pok[i];
		novi[n] = str;
	}
	catch(std::bad_alloc) {
		delete[] novi;
		throw;
	}
	catch(...) {
		delete[] novi;
		throw std::bad_alloc();
	}
	
	delete[] pok;
	pok = novi;
	
	return n + 1;
}

void IzlistajOptuzbu(char** pok, int n) {
	for (int i = 0; i < n; i++) {
		if (pok[i] != nullptr) std::cout << pok[i] << std::endl;
	}
}

int main () {
	char** pok(nullptr);
	
	std::cout << "Koliko potencijalnih krivaca zelite unijeti?\n";
	int n;
	
	std::cin >> n;
	
	try {
		if (n > 0) {
			std::cout << "Unesite potencijalne krivce:\n";
			
			std::vector<std::string> v(n);
			for (int i = 0; i < n; i++) std::cin >> v[i];
			n = PotencijalniKrivci(pok, v);
		}
		else n = 0;
	}
	catch(std::bad_alloc) {
		n = 0;
	}
	
	
	for (;;) {
		try {
			std::cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj:\n";
			int op;	std::cin >> op;
			if (op == 0) break;
			
			if (op == 1) {
				std::cout << "Unesite ime novog optuzenog:\n";
				std::string ime; std::cin >> ime;
				
				n = DodajOptuzbu(pok, n, ime);
			}
			else if (op == 2) {
				std::cout << "Unesite ime koje zelite izbaciti:\n";
				std::string ime; std::cin >> ime;
				
				n = OdbaciOptuzbu(pok, n, ime);
				
			}
			else if (op == 3) {
				IzlistajOptuzbu(pok, n);
			}
		}
		catch (std::domain_error e) {
			std::cout << e.what() << std::endl;
		}
		catch (...) {
			
		}
	}

	
	for (int i = 0; i < n; i++) delete[] pok[i];
	delete[] pok;
	
	return 0;
}