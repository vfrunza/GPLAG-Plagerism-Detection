#include <iostream>
#include <vector>
#include <new>
#include <stdexcept>

using std::vector;

//Funkcije kopirane iz 2. zadatka tutorijala 2
template <typename cijeli>
bool TestPerioda(vector<cijeli> niz, int p) {
	//nije periodican na p, 1 <= p < n
	if (p >= niz.size() || p < 1) return false;
	
	bool periodican = true;

	for (int i = 0; i < niz.size()-p; i++) {
		if (niz[i] != niz[i + p]) {
			periodican = false;
			break;
		}
	}

	return periodican;
}

template <typename cijeli>
int OdrediOsnovniPeriod(vector<cijeli> niz) {
	int osnovni = 0;
	
	for (int i = 1; i < niz.size(); i++) {
		if (TestPerioda(niz, i)) {
			osnovni = i;
			break;
		}
	}
	
	return osnovni;
}

template <typename cijeli>
void ProvjeriVektor(const vector<cijeli> &vec){
	if(vec.size() == 0)
		throw "Prazan vektor!";
	
	//Provjeri negativne vr vektora
	for(int i = 0; i < vec.size(); i++){
		if(vec.at(i) <= 0)
			throw std::domain_error("Neispravan vektor!");
	}
}

template <typename cijeli>
void Periodi(const vector<cijeli> &vec, int &osnovni, int &brPerioda, int &koliko_puta){
	if(osnovni == 0){
		koliko_puta = 2;
		brPerioda = 1;
		osnovni = vec.size();
	}else{
		brPerioda = vec.size() / osnovni;
		koliko_puta = brPerioda;
		if(vec.size() % osnovni != 0)
			koliko_puta++;
	}
}

template <typename cijeli>
void Delete(cijeli **mat, int brRedova, bool fragmentirana){
	//Obrisi nizove
	if(fragmentirana){
		for(int i = 0; i < brRedova; i++)
			delete[] mat[i];
	}else{
		delete[] mat[0];
	}
	
	//Obrisi niz pokazivaca
	delete[] mat;
}

template <typename cijeli>
cijeli **AlocirajFragmentirano(const vector<cijeli> &vec, int &koliko_puta){
	ProvjeriVektor(vec);
	
	//Nadji osnovni period i broj ponavljanja tog perioda
	int brPerioda = 0;
	int osnovni = OdrediOsnovniPeriod(vec);
	Periodi(vec, osnovni, brPerioda, koliko_puta);
	//Broj redova u matrici
	int brRedova = koliko_puta * osnovni;
	cijeli **mat = nullptr;
	
	try{
		mat = new cijeli*[brRedova]{};
		//Nadji max br elemenata u bilo kojem redu
		int max = vec[0];
		for(int i = 1; i < osnovni; i++){
			if(vec[i] > max) max = vec[i];
		}
		
		for(int i = 0; i < brRedova; i++){
			//Osiguraj da se nakon sto se prodje posljednji period unutar vektora
			//krene sa pocetka. Ovime se simulira potpunost vektora
			int brKolona = (i < brPerioda * osnovni)? vec.at(i) : vec.at(i - brPerioda * osnovni);
			mat[i] = new cijeli[brKolona];
			int cnt = max;
			//Dodijeli odg vrijednosti elementima reda
			for(int j = brKolona-1; j >= 0; j--){
				mat[i][j] = cnt--;
			}
		}
	}catch(std::bad_alloc err){
		Delete(mat, brRedova, true);
		throw;
	}
	
	return mat;
}

template <typename cijeli>
cijeli **AlocirajKontinualno(const vector<cijeli> &vec, int &koliko_puta){
	ProvjeriVektor(vec);
	
	//Nadji osnovni period i broj ponavljanja tog perioda
	int brPerioda = 0;
	int osnovni = OdrediOsnovniPeriod(vec);
	Periodi(vec, osnovni, brPerioda, koliko_puta);
	//Broj redova u matrici
	int brRedova = koliko_puta * osnovni;
	cijeli **mat = nullptr;
	
	try{
		//Niz pokazivaca
		mat = new cijeli*[brRedova]{};
		//Ukupna "sirina" kontinualnog niza
		int ukupnoElemenata = 0;
		for(int i = 0; i < brRedova; i++){
			ukupnoElemenata += (i < brPerioda * osnovni)? vec.at(i) : vec.at(i - brPerioda * osnovni);
		}
		mat[0] = new cijeli[ukupnoElemenata];
		
		for(int i = 1; i < brRedova; i++){
			//Osiguraj da se nakon sto se prodje posljednji period unutar vektora
			//krene sa pocetka. Ovime se simulira potpunost vektora
			//BrKolona proslog reda
			int brKolona = (i-1 < brPerioda * osnovni)? vec.at(i-1) : vec.at(i - 1 - brPerioda * osnovni);
			mat[i] = mat[i-1] + brKolona;
		}
		for(int i = 0; i < brRedova; i++){
			int brKolona = (i < brPerioda * osnovni)? vec.at(i) : vec.at(i - brPerioda * osnovni);
			//Dodijeli odg vrijednosti elementima reda
			for(int j = 0; j < brKolona; j++){
				mat[i][j] = brKolona-j;
			}
		}
	}catch(std::bad_alloc err){
		Delete(mat, brRedova, false);
		throw;
	}
	
	return mat;
}

int main () {
	int n;
	int koliko_puta = 0;
	vector<int> vec;
	int **mat = nullptr;
	bool frag;
	
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	
	vec.resize(n);
	std::cout << "Unesite elemente vektora: ";
	for(int &br : vec)
		std::cin >> br;
	
	std::cout << "Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	std::cin >> frag;
	
	//Priprema za ispisivanje matrice
	int brPerioda = 0;
	int osnovni = OdrediOsnovniPeriod(vec);
	Periodi(vec, osnovni, brPerioda, koliko_puta);
	int brRedova = koliko_puta * osnovni;
	
	//Pokusaj alokaciju matrica
	try{
		if(frag)
			mat = AlocirajFragmentirano(vec, koliko_puta);
		else
			mat = AlocirajKontinualno(vec, koliko_puta);
	}catch(std::domain_error err){
		std::cout << "Izuzetak: " << err.what();
		//Delete(mat, brRedova, frag);
		return 0;
	}catch(std::bad_alloc err){
		std::cout << "Izuzetak: " << err.what();
		Delete(mat, brRedova, frag);
		return 0;
	}catch(const char* err){
		std::cout << "Izuzetak: " << err;
		return 0;
	}
	
	//Ispisivanje matrica
	std::cout << "Dinamicki alocirana matrica:\n";
	for(int i = 0; i < brRedova; i++){
		int brKolona = (i < brPerioda * osnovni)? vec.at(i) : vec.at(i - brPerioda * osnovni);
		for(int j = 0; j < brKolona; j++){
			std::cout.width(3);
			std::cout << std::left << mat[i][j];
		}
		std::cout << std::endl;
	}
	
	//Brisanje matrice
	Delete(mat, brRedova, frag);
	
	return 0;
}