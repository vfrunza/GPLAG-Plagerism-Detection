/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <stdexcept>

using std::string;
using std::vector;
typedef char *cstr;

int PotencijalniKrivci(cstr* &niz, vector<string> vs) {
	niz = nullptr;
	int vel = vs.size();
	try {
		niz = new cstr[vel];
		std::fill_n(niz, vel, nullptr);
		
		for (int i = 0; i < vel; i++) {
			niz[i] = new char[vs[i].length() + 1];
			std::strcpy(niz[i], vs[i].c_str());
		}
	} catch (std::bad_alloc& e) {
		if (niz)
			for (int i = 0; i < vs.size(); i++)
				delete[] niz[i];
		delete[] niz;
		throw;
	}
	
	return vel;
}

int OdbaciOptuzbu(cstr* &niz, int vel, string s) {
	bool ima = false;
	for (int i = 0; i < vel; i++) {
		cstr x = niz[i];
		if (!(x && x == s)) continue;
		delete[] x;
		niz[i] = nullptr;
		ima = true;
	}
	if (!ima)
		throw std::domain_error("Osoba sa imenom " + s + " nije bila optuzena");
	int br = 0;
	for (int i = 0; i < vel; i++) 
		if (!niz[i]) br++;
	if (br <= 10) return vel;
	
	try {
		cstr* novi = new cstr[vel - br];
		int j = 0;
		for (int i = 0; i < vel; i++) 
			if (niz[i])
				novi[j++] = niz[i];
		niz = novi;
	} catch (std::bad_alloc& e) {
		//njam
	}
	return vel - br;
}

int DodajOptuzbu(cstr* &niz, int vel, string s) {
	cstr novi = nullptr;
	try {
		novi = new char[s.length() + 1];
		std::strcpy(novi, s.c_str());
		int i;
		for (i = 0; i < vel; i++)
			if (!niz[i]) break;
		if (i == vel) {
			cstr *prosireni = new cstr[vel+1];
			std::copy(niz, niz+vel, prosireni);
			prosireni[vel] = novi;
			delete[] niz;
			niz = prosireni;
			return vel + 1;
		} else {
			niz[i] = novi;
			return vel;
		}
	} catch (std::bad_alloc& e) {
		delete[] novi;
		throw;
	}

}


void IzlistajOptuzbu(cstr niz[], int vel) {
	for (int i = 0; i < vel; i++)
		if (niz[i]) std::cout << niz[i] << '\n';
}

int main() {
	using std::cin;
	using std::cout;
	using std::getline;
	cout << "Koliko potencijalnih krivaca zelite unijeti? \n";
	int n;
	cstr* niz = nullptr;
	cin >> n;
	try {
		vector<string> vs(n);
		cout << "Unesite potencijalne krivce: \n";
		cin >> std::ws;
		for (string& s : vs) getline(cin, s);
		n = PotencijalniKrivci(niz, vs);
		while (1) {
			cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje "
					"nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: \n";
			int unos;
			cin >> unos;
			if (unos == 0) break;
			if (unos == 1) {
				cout << "Unesite ime novog optuzenog: \n";
				string s;
				cin >> std::ws;
				getline(cin, s);
				n = DodajOptuzbu(niz, n, s);
			}
			if (unos == 2) {
				cout << "Unesite ime koje zelite izbaciti: \n";
				string s;
				cin >> std::ws;
				getline(cin, s);
				n = OdbaciOptuzbu(niz, n, s);
			}
			if (unos == 3) IzlistajOptuzbu(niz, n);
		}
	} catch (...) {
		cout << "Izuzetak!";
		//ne brisem nista ionako idemo kuci
	}
	
	if (niz)
		for (int i = 0; i < n; i++)
			delete[] niz[i];
	
	delete[] niz;
	
	return 0;
}