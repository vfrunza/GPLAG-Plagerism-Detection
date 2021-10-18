/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <new>
#include <stdexcept>
using namespace std;

int PotencijalniKrivci(char** &pokazivac, vector<string> imena) 
{
	int broj_imena = imena.size();
	char **matrica = nullptr;
	try 
	{
		matrica = new char* [broj_imena];
		for(int i{0}; i < broj_imena; i++) {
			matrica[i] = nullptr;
		}
		for(int i{0}; i < broj_imena; i++) {
			matrica[i] = new char[imena[i].size()+1];
		}
	}
	catch(bad_alloc) 
	{
		if(matrica != nullptr) {
			for(int i{0}; i < broj_imena; i++) {
				delete[] matrica[i];
			}
		}
		delete[] matrica;
	}
	for(int i{0}; i < broj_imena; i++) {
		strcpy (matrica[i], imena[i].c_str());
	}
	pokazivac = matrica;
	return broj_imena;
}

int OdbaciOptuzbu(char** &imena, int broj_imena, string ime)
{
	bool nije_unesen = true;
	int index;
	for(index = 0; index < broj_imena; index++) 
	{
		if(imena[index] == nullptr) continue; 
		if(ime == string(imena[index]))
		{
			nije_unesen = false;
			break;
		}
	}
	if(nije_unesen) {
		string poruka = "Osoba sa imenom " + ime + " nije bila optuzena";
		throw domain_error(poruka);
	}
	delete[] imena[index];
	imena[index] = nullptr;
	
	char** nova_imena = nullptr;
	int broj_praznih{0};
	for(int i{0}; i < broj_imena; i++) 
	{
		if(imena[i] == nullptr)
			broj_praznih++;
	}
	
	if(broj_praznih >= 10) 
	{
		try 
		{
			nova_imena = new char* [broj_imena - broj_praznih];
		}
		catch(bad_alloc) {
			delete [] nova_imena;
			return broj_imena;
		}
		int broj_novih_imena{0};
		for(int i{0}; i < broj_imena; i++) {
			if(imena[i] != nullptr) 
				nova_imena[broj_novih_imena++] = imena[i];
		}
		delete[] imena;
		imena = nova_imena;
		return broj_imena - broj_praznih;
	}
	return broj_imena;
	
}

int DodajOptuzbu(char** &imena, int broj_imena, string ime) 
{
	char* novo_ime = nullptr;
	try {
		novo_ime = new char [ime.size()+1];
	}
	catch(bad_alloc) {
		delete[] novo_ime;
		return broj_imena;
	}
	strcpy(novo_ime, ime.c_str());
	
	bool nema_mjesta = true;
	for(int i{0}; i < broj_imena; i++) {
		if(imena[i] == nullptr) {
			nema_mjesta = false;
			imena[i] = novo_ime;
			return broj_imena;
		}
	}
	char** nova_imena = nullptr;
	if(nema_mjesta) {
		try {
			nova_imena = new char*[broj_imena + 1];
		}
		catch(bad_alloc) {
			delete[] nova_imena;
			delete[] novo_ime;
			return broj_imena;
		}
		for(int i{0}; i < broj_imena; i++) {
			nova_imena[i] = imena[i];
		}
		nova_imena[broj_imena] = novo_ime;
		delete[] imena;
		imena = nova_imena;
		return broj_imena + 1;
	}
	return broj_imena;
}

void IzlistajOptuzbu(char** imena, int broj_imena) {
	for(int i{0}; i < broj_imena; i++) {
		if(imena[i] == nullptr) continue;
		cout << imena[i] << endl;
	}
}

void IsprazniMemoriju(char** &imena, int broj_imena) {
	for (int i{0}; i < broj_imena; i++) {
		delete[] imena[i];
		imena[i] = nullptr;
	}
	delete[] imena;
	imena = nullptr;
}

int main ()
{
	char **imena_krivaca = nullptr;
	int broj_krivaca;
	cout << "Koliko potencijalnih krivaca zelite unijeti?" << endl;
	cin >> broj_krivaca;
	cin.ignore(100, '\n');
	cout << "Unesite potencijalne krivce: " << endl;
	vector<string> krivci;
	string unos;
	for(int i{0}; i < broj_krivaca; i++) {
		getline(cin, unos);
		krivci.push_back(unos);
	}
	broj_krivaca = PotencijalniKrivci(imena_krivaca, krivci);
	//IzlistajOptuzbu(imena_krivaca, broj_krivaca);
	int opcija;
	do
	{
		cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: " << endl;
		cin >> opcija;
		cin.ignore(100, '\n');
		if(opcija == 1) 
		{
			cout << "Unesite ime novog optuzenog: " << endl;
			getline(cin, unos);
			broj_krivaca = DodajOptuzbu(imena_krivaca, broj_krivaca, unos);
		}
		else if(opcija == 2) 
		{
			cout << "Unesite ime koje zelite izbaciti: " << endl;
			getline(cin, unos);
			try
			{
				broj_krivaca = OdbaciOptuzbu(imena_krivaca, broj_krivaca, unos);
			}
			catch(domain_error poruka) 
			{
				cout << poruka.what() << endl;
			}
		}
		else if(opcija == 3)
		{
			IzlistajOptuzbu(imena_krivaca, broj_krivaca);
		}
	}
	while(opcija != 0);
	IsprazniMemoriju(imena_krivaca, broj_krivaca);
	return 0;
}