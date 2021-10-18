/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

typedef std::vector<std::vector<double>> Matrica;

std::vector<double> Unesi_niz (int broj_elemenata) {		//funkcija za unos niza, tj vektora brojeva
	std::vector<double> niz;
	double element;
	for (int i=0; i<broj_elemenata; i++) {
		std::cin>>element;
		niz.push_back(element);
	}
	return niz;
}

Matrica RastuciPodnizovi (std::vector<double> niz) {			//funkcija koja analizira niz, i vraca matricu rastucih podnizova 
	Matrica podnizovi;
	for (int j=0,i=0,k=0; j<niz.size(); j++,k++) {
		if (j==0) {				//uslov za prvi element niza
			podnizovi.resize(i+1); 
			podnizovi[i].push_back(niz[j]);
		}
		else if (podnizovi[i][k-1]<=niz[j]) //ako je sljedeci veci, dodajem ga u matricu
			podnizovi[i].push_back(niz[j]);
		else if (podnizovi[i][k-1]>=niz[j] && j<niz.size()) {		//ako je sljedeci manji onda prelazim na sljedeci red matrice, i smijestam element tamo
			if (podnizovi[i].size()<2) {podnizovi.resize(podnizovi.size()-1); i--;}			//ali prethodno provjeravam ovaj vec kreirani red, da li ima bar dva elementa
			i++; 
			podnizovi.resize(i+1); 
			podnizovi[i].push_back(niz[j]); 
			k=0; 
		}
	}
	if (podnizovi.size()!=0 && podnizovi[podnizovi.size()-1].size()<2) podnizovi.resize(podnizovi.size()-1);		//provjera zadnjeg reda matrice, da li ima bar dva elementa
	return podnizovi;
}

Matrica OpadajuciPodnizovi (std::vector<double> niz) {			//funkcija isto radi kao i prethodna, samo sto pronalazi opadajuce podnizove
	Matrica podnizovi;
	for (int j=0,i=0,k=0; j<niz.size(); j++,k++) {
		if (j==0) {
			podnizovi.resize(i+1); 
			podnizovi[i].push_back(niz[j]);
		}
		else if (podnizovi[i][k-1]>=niz[j])
			podnizovi[i].push_back(niz[j]);
		else if (podnizovi[i][k-1]<=niz[j] && j<niz.size()) {
			if (podnizovi[i].size()<2) {podnizovi.resize(podnizovi.size()-1); i--;}
			i++;
			podnizovi.resize(i+1);
			podnizovi[i].push_back(niz[j]);
			k=0;
		}
	}
	if (podnizovi.size()!=0 && podnizovi[podnizovi.size()-1].size()<2) podnizovi.resize(podnizovi.size()-1);
	return podnizovi;
}

void Ispisi_matricu (Matrica m) {			//ispis matrice na ekran
	for (int i=0; i<m.size(); i++){
		for (int j=0; j<m[i].size(); j++)
			std::cout<<m[i][j]<<" ";
		std::cout<<std::endl;
	}
}

int main () 
{
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::vector<double> niz_brojeva;
	std::cout<<"Unesite elemente vektora: ";
	niz_brojeva=Unesi_niz(n);
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	Ispisi_matricu(RastuciPodnizovi(niz_brojeva));
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	Ispisi_matricu(OpadajuciPodnizovi(niz_brojeva));
	return 0;
}