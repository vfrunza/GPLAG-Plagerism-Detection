/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	.
*/

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>

int PotencijalniKrivci(char **&p, std::vector<std::string>v) {

	char **matrica=new char*[v.size()]();

	for(int i=0; i<v.size(); i++) {
		try {
			matrica[i]=new char[v[i].length()+1];
		}
		catch(std::bad_alloc) {
			for(int j=0; j<i; j++) delete[] matrica[j];
			delete[] matrica;
			throw;
		}
		char *pok=std::copy(v[i].begin(), v[i].end(), matrica[i]);
		*pok='\0';
	}
	p=matrica;
	return v.size();
}

int OdbaciOptuzbu(char **&matrica, int vel, std::string s) {
	bool nadjen(false);
	for(int i=0; i<vel; i++) {
		if(std::equal(s.begin(), s.end(), matrica[i])) {
			nadjen=true;
			delete[] matrica[i];
			matrica[i]=nullptr;
			break;
		}
	}
	if(!nadjen) {
		throw std::domain_error("Osoba sa imenom " + s + " nije bila optuzena");
	}
	
	int broj_nultih(0);
	for(int i=0; i<vel; i++) if(!matrica[i]) broj_nultih++;
	if(broj_nultih>10) {
		char **novi=nullptr;
		try {
			int vel2(0);
			novi=new char*[vel-broj_nultih]();
			for(int i=0; i<vel; i++) if(matrica[i]) {
				novi[vel2]=matrica[i];
				vel2++;
			}
			delete[] matrica;
			matrica=novi;
			return vel2;
		}
		catch(...) {}
	}
	return vel;
}

int DodajOptuzbu(char **&matrica, int vel, std::string s) {
	
	char *niz=new char[s.length()+1];
	char *pok=std::copy(s.begin(), s.end(), niz);
	*pok='\0';
	
	
	for(int i=0; i<vel; i++) if(!matrica[i]) {
		matrica[i]=niz;
		return vel;
	}
	char **novi=nullptr;
	try { 
		novi=new char*[vel+1](); 
	}
	catch(std::bad_alloc) { 
		delete[] niz;
		throw;
	}
	
	for(int i=0; i<vel; i++) novi[i]=matrica[i];
	novi[vel]=niz;
	delete[] matrica;
	matrica=novi;
	return vel+1;
}

void ispisi(char *niz) {
	while(*niz) std::cout << *niz++;
}

void IzlistajOptuzbu(char **matrica, int vel) {
	for(int i=0; i<vel; i++) {
		if(matrica[i]) {
			ispisi(matrica[i]);
			std::cout << "\n";
		}
	} 
}

int main () {
	std::cout << "Koliko potencijalnih krivaca zelite unijeti? \n";
	int n; std::cin >> n;
	std::vector<std::string>v;
	try { v.resize(n); }
	catch(...) { return 0; }
	std::cout << "Unesite potencijalne krivce: \n";
	for(auto &s : v) std::cin >> s;
	int k; char **m=nullptr; int vel;
	try { vel=PotencijalniKrivci(m, v); }
	catch(...) { return 0; }
	do {
		std::cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: \n";
		std::cin >> k;
		if(k==1) {
			std::cout << "Unesite ime novog optuzenog: \n";
			std::string s1; std::cin >> s1;
			try { vel=DodajOptuzbu(m, vel, s1); }
			catch(...) { return 0; }
		}
		else if(k==2) {
			std::cout << "Unesite ime koje zelite izbaciti: \n";
			std::string s1; std::cin >> s1;
			try { vel=OdbaciOptuzbu(m, vel, s1); }
			catch(std::bad_alloc) { return 0; }
			catch(std::domain_error izuzetak) { std::cout << izuzetak.what(); return 0; }
		}
		else if(k==3) {
			IzlistajOptuzbu(m, vel);
		}
		
	} while(k);
	for(int i=0; i<vel; i++) delete[] m[i];
	delete[] m;
	return 0;
}