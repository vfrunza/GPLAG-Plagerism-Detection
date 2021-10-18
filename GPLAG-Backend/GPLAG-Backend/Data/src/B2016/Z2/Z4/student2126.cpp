/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/

#include <iostream>
#include <string>
#include <vector>
#include <new>

int PotencijalniKrivci( char **&pokRef, std::vector<std::string> vekStr){
	char **pok = nullptr;
	int brojac = 0;
	try{
		pok = new char* [vekStr.size()];
		for(int i = 0; i < vekStr.size(); i++)pok[i] = nullptr;
		try{
			for(int i = 0; i < vekStr.size(); i++){
				pok[i] = new char[vekStr[i].size()];
				for(int j = 0; j < vekStr[i].size(); j++){
					pok[i][j] = vekStr[i][j];	
				}
				pok[i][vekStr[i].size()] = '\n';
				brojac++;
			}
			pokRef = pok;
		}catch(std::bad_alloc except1){
			for(int i = 0; i < vekStr.size(); i++)delete [] pok[i];
			throw;
		}
	}catch(std::bad_alloc except){
		delete [] pok;
		throw;
	}
	return brojac;
}

/*
 U suprotnom, treba osobu izbrisati iz spiska, odnosno
“osloboditi je optužbe”. To treba izvesti ovako. Prvo treba obrisati niz znakova koji sadrži podatke o
osobi, a nakon toga odgovarajući pokazivač u nizu pokazivača postaviti na nul-pokazivač, kao
indikator da je osoba obrisana. Ukoliko nakon toga ne bude više od 10 nul-pokazivača u nizu
pokazivača (tj. ukoliko do tada nije izbrisano više od 10 osoba), postupak je gotov. U suprotnom,
treba obaviti “uštedu” memorije, uklanjanjem prostora koji zauzimaju nul-pokazivači, tako što će se
alocirati novi niz pokazivača, onolike veličine koliko zaista ima osoba u spisku (ne brojeći obrisane
osobe), nakon čega će se svi “korisni” pokazivači prekopirati u novi niz, stari niz pokazivača će se
ukloniti, a pokazivač na novi niz će se dodijeliti prvom parametru. U slučaju da ne uspije alokacija
novog niza pokazivača, ne treba da se desi ništa (ne treba ni da se baci izuzetak), sve treba ostati
kako je bilo. Funkcija kao rezultat vraća novu veličinu niza pokazivača (to može da bude i ista
veličina kakva je bila, ukoliko nije došlo do alokacije novog niza pokazivača).*/
int OdbaciOptuzbu(char **&pokRef, int velicina, std::string nije){
	for(int i = 0; i < velicina; i++){
		while(*pokRef[i])	
	}
	throw std::domain_error("Osoba sa imenom " + nije + " nije bila optuzena." );
}


int main ()
{
	return 0;
}