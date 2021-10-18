/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using std::cin; using std::cout; using std::endl; using std::vector; using std::string;

int PotencijalniKrivci(char **&pok, vector<string> spisak_imena) {
	int broj_al_nizova(0);
	int n(spisak_imena.size());
	//Dinamicki alocira niz pokazivaca 
	try {
		pok=new char*[n];
		for (int i=0; i<n; i++) {pok[i]=nullptr; }
		try {
			for (int i=0; i<n; i++) {
				int m(spisak_imena[i].size()+1); //+1 za \0
				pok[i]=new char[m]; 
			}
			//Popunimo din. al. niz 
			for(int i=0; i<n; i++) {
				int m(spisak_imena[i].size()), j(0);
				for (j=0; j<m; j++) {
					pok[i][j]=spisak_imena[i][j];
				}
				pok[i][j]='\0';
				}
		}
		catch (std::bad_alloc) {
			for (int i=0; i<n; i++) {
				delete[] pok[i];
			} //Jer su neki alocirani
			delete[] pok;
			throw;
		}
	}
	catch (std::bad_alloc) {
		throw;
	}
	broj_al_nizova=n;
	return broj_al_nizova;
}

int OdbaciOptuzbu(char **&pok, int vel, string ime) {
	//Provjera da li je na spisku
	int i(0), brojac(0);
	for (i=0; i<vel; i++) {
		//Pretvorimo ime sa spiska u string i uporedimo sa imenom
		string ime_l;
		for (int j=0; ; j++) {
			if (pok[i]!=nullptr && pok[i][j]!='\0')
			ime_l.push_back(pok[i][j]);
			else break;
		}
		//cout << ime_l << " ";
		if (ime_l==ime) {
			//Brisanje osobe
			delete[] pok[i];
			pok[i]=nullptr;
			//Provjerimo koliko je nullptr u nizu pok
			brojac=0;
			for (int b=0; b<vel; b++) {
				if (!pok[b]) brojac++;
			}
			if (brojac>10) {
				int k(0);
				//Usteda memorije, alokacija novog niza
				if (vel-brojac==0) return 0; //Nema vise elemenata da nisu nullptr
				char **a(new char*[vel-brojac]); //Ako ne uspije alokacija ne trebamo nista uraditi
				for (int i=0; i<vel-brojac; i++) { a[i]=nullptr; }
				try {
					for (int i=0; i<vel-brojac; i++) {
						while(!pok[k]) k++;
						int m(0);
						//Prebrojimo koliko slova ima ovo ime
						while (pok[k][m]!='\0') {
							m++;
						}
						a[i]=new char[m+1];
						//Popunimo ime
						m=0;
						while (pok[k][m]!='\0') {
							a[i][m]=pok[i][m];
							m++;
						}
						a[i][m]='\0';
						k++;
					}
				}
				catch (...) {
					for (int i=0; i<vel-brojac; i++) delete[] a[i];
					delete[] a;
				}
				//Moramo osloboditi prvi niz
				for (int i=0; i<vel; i++) pok[i]=nullptr;
				for (int i=0; i<vel; i++) delete[] pok[i];
				delete[] pok;
				pok=a;
				pok=a;
				vel-=brojac;
			}
			break;
		}
	}
	if (i==vel) { //Nije doslo do brisanja, osobe nema na spisku
	    string tekst ("Osoba sa imenom " + ime + " nije bila optuzena");
		throw std::domain_error (tekst);
	}
	return vel;
}

int DodajOptuzbu (char **&pok, int vel, std::string ime) {
	//Alocirajmo novi niz
	char* niz;
	try {
		niz=new char [ime.size()+1];
		int i(0);
		for ( ; i<ime.size(); i++) {
			niz[i]=ime[i];
		}
		niz[i]='\0';
	}
	catch (std::bad_alloc) {
		throw;
	}
	//Pretrazimo niz pokazivaca
	for (int i=0; i<vel; i++) {
		if (!pok[i]) {
			//Pronasli smo nullptr
			pok[i]=niz; //Upisimo adresu novokreiranog niza
			return vel; //Postupak je gotov
		}
	}
	
	//Dodavanje novog imena, ako nema nullptr-a
	char **a; //Curenje
	try {
		a=new char*[vel+1];
	}
	catch (...) {
		throw;
	}
	int i(0);
	for ( ; i<vel+1; i++) { a[i]=nullptr; }
		try {
			    for (int i=0; i<vel+1; i++) {
					if (i!=vel) a[i]=pok[i];
					else a[i]=niz;
			    }
			    
		}
		catch (...) {
			for (int i=0; i<vel+1; i++) delete[] a[i];
			delete[] a;
			a=nullptr;
			throw;
		}
	//Moramo osloboditi prvi niz
	for (int i=0; i<vel; i++) pok[i]=nullptr;
	for (int i=0; i<vel; i++) delete[] pok[i];
	delete[] pok;
	pok=a;
	return vel+1;
}

void IzlistajOptuzbu (char **pok, int vel) {
	for (int i=0; i<vel; i++) {
		if (pok[i]) {
			if (i==vel-1) cout <<pok[i];
			else cout << pok[i] << endl;
		}
	}
}

int main ()
{
	cout << "Koliko potencijalnih krivaca zelite unijeti? ";
	int br_pot_k;
	cin >> br_pot_k;
	cout <<"\nUnesite potencijalne krivce: ";
	vector<string> spisak_imena_pk;
	for (int i=0; i<=br_pot_k; i++) {
		string unos;
		std::getline(cin, unos);
		spisak_imena_pk.push_back(unos);
	}
	char **pok(nullptr);
	try {
		PotencijalniKrivci(pok, spisak_imena_pk);
	}
	catch (...) {
		for (int i=0; i<spisak_imena_pk.size(); i++) delete[] pok[i];
	    delete[] pok;
	}
	int unos(0), vel=spisak_imena_pk.size();
	do {
		cout << "\nOdaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: ";
		cin >> unos;
		if (unos==1) {
			cout << "\nUnesite ime novog optuzenog: ";
			string ime;
			cin.ignore (10000, '\n');
			std::getline(cin, ime);
			try {
				vel=DodajOptuzbu(pok, vel, ime);
			}
			catch (...) {
				cout << "Problemi";
			}
		}
		else if (unos==2) {
			cout << "\nUnesite ime koje zelite izbaciti: ";
			string ime;
			cin.ignore (10000, '\n');
			std::getline(cin, ime);
			try {
				OdbaciOptuzbu(pok, spisak_imena_pk.size(), ime);
			}
			catch (std::domain_error izuzetak) {
				cout << izuzetak.what();
			}
		}
		else if (unos==3) {
			IzlistajOptuzbu(pok, vel);
		}
	}
	while (unos);
	
	//Obrisimo sto smo zauzeli
	for (int i=0; i<vel; i++) delete[] pok[i];
	delete[] pok;
	
	return 0;
}