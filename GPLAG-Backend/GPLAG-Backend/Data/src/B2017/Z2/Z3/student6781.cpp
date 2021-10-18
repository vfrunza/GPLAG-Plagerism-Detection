/*B 2017/2018, Zadaća 2, Zadatak 3

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <new>
#include <algorithm>
#include <iomanip>
#include <vector>

template <typename Tip> bool jel_period(const std::vector<Tip>  &v, int p)
{

	if(p<1  || p>=v.size()) return false;
	for(int i=0; i<v.size()-p; i++) 	if(v.at(i)!=v.at(i+p)) return false;
	return true;
}
template <typename Tip> int osnovni_period (const std::vector<Tip> &v)
{
	int osnovni(0);
	for(int i=0; i<v.size(); i++) if(jel_period(v,i)) return i;
	return osnovni;
}

template <typename Tip> auto AlocirajFragmentirano (const std::vector<Tip> &v, int &koliko_puta)-> Tip ** {
	int vel(v.size());
	if(v.size()==0) throw "Prazan vektor!";
	for(int i=0; i<v.size(); i++) if(v.at(i)<=0) throw std::domain_error ("Neispravan vektor!");
	int osnovni(osnovni_period(v));
	if(osnovni!=0) {
		while((vel%osnovni)!=0) {
			vel++;
		}
		koliko_puta=vel/osnovni;
	} else{
		osnovni=vel;
		vel=(2*v.size());
		koliko_puta=2;
	}
	Tip **a(nullptr);
	try{

		a = new Tip*[vel]{};
		int br(0);
		for(int i=0; i<vel; i++) {
			a[i]=new Tip[v.at(br)];
			br++;
			if(br==osnovni) br=0;
		}

	} catch(...) {
		for(int i=0; i<vel; i++) delete[] a[i];
		delete[] a;
		throw;
	}

	int br(0);
	for(int i=0; i<vel; i++) {
		Tip max(*(std::max_element(v.begin(), v.end())));

		for(int j=v.at(br)-1; j>=0; j--) {
			a[i][j]=max;
			max--;
		}
		br++;
		if(br==osnovni) br=0;
	}
	return a;
}

template <typename Tip> auto AlocirajKontinualno (const std::vector<Tip> &v, int &koliko_puta)-> Tip ** {
	int vel(v.size());
	if(v.size()==0) throw "Prazan vektor!";
	for(int i=0; i<v.size(); i++) if(v.at(i)<=0) throw std::domain_error ("Neispravan vektor!");
	int osnovni(osnovni_period(v));
	if(osnovni!=0) {
		while((vel%osnovni)!=0) {
			vel++;
		}
		int koliko(vel/osnovni);
		koliko_puta=koliko;
	} else{
		osnovni=vel;
		vel=(2*v.size());
		koliko_puta=2;
	}
	int kolicina(0);
	for(int i=0; i<osnovni; i++) kolicina+=v.at(i);
	kolicina*=koliko_puta;
	Tip **a(nullptr);
	try{
		a=new Tip *[vel]{};
		a[0]=new Tip [kolicina];
		int br(0);
		for(int i=1; i<vel; i++) {
			a[i]=a[i-1]+v[br];
			br++;
			if(br==osnovni) br=0;
		}

	} catch(...) {
		delete[] a[0];
		delete[] a;
		throw;
	}
	int br(0);
	for(int i=0; i<vel; i++) {
		Tip broj(0);
		broj++;

		for(int j=v.at(br)-1; j>=0; j--) {
			a[i][j]=broj;
			broj++;
		}
		br++;
		if(br==osnovni) br=0;
	}
	return a;
}

int main()
{
	std::cout << "Unesite broj elemenata vektora: ";
	int n;
	std::cin >> n;

	std::vector<int> v(n);
	std::cout << "Unesite elemente vektora: " ;
	for(int i=0; i<n; i++) {
		std::cin >> v.at(i);
	}
	std::cout << "Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	int alokacija;
	std::cin >> alokacija;
	int koliko;
	if(alokacija==1) {
		try {
			int **mat (AlocirajFragmentirano(v, koliko));
			int osnovni;
			if(osnovni_period(v)!=0) osnovni=osnovni_period(v);
			else osnovni=v.size();
			int vel(osnovni*koliko);
			std::cout << "Dinamicki alocirana matrica: " << std::endl;

			int br(0);
			for(int i =0; i<vel; i++) {
				for(int j=0; j<v.at(br); j++) {
					std::cout << std::left<< std::setw(3) <<mat[i][j];
				}
				std::cout << std::endl;
				br++;
				if (br==osnovni) br=0;
			}
			for(int i=0; i<vel; i++) delete[] mat[i];
			delete[] mat;
		} catch(std::bad_alloc) {
			std::cout << "Nedovoljno memorije!" << std::endl;
		} catch(const char poruka[]) {
			std::cout << "Izuzetak: "<< poruka << std::endl;
		} catch(std::domain_error greska) {
			std::cout << "Izuzetak: "<< greska.what() << std::endl;
		}
	} else {
		try {
			int **mat(AlocirajKontinualno(v,koliko));
			int osnovni;
			if(osnovni_period(v)!=0) osnovni=osnovni_period(v);
			else osnovni=v.size();
			int vel(osnovni*koliko);
			std::cout << "Dinamicki alocirana matrica: " << std::endl;
			int br(0);
			for(int i=0; i<vel; i++) {
				for(int j=0; j<v.at(br); j++) {
					std::cout << std::left << std::setw(3) << mat[i][j];
				}
				br ++;
				if(br==osnovni) br=0;
				std::cout << std::endl;
			}
			delete[] mat[0];
			delete[] mat;
		} catch(std::bad_alloc) {
			std::cout << "Nedovoljno memorije!" << std::endl;
		} catch(const char poruka[]) {
			std::cout << "Izuzetak: "<< poruka << std::endl;
		} catch(std::domain_error greska) {
			std::cout <<"Izuzetak: "<< greska.what() << std::endl;
		}
	}
	return 0;
}