#include <iostream>
#include <stdexcept>
#include <vector>
#include <iomanip>

template <typename IntTip>
int OsnovniPeriod(const std::vector<IntTip> &v) {
	if (v.size() <= 1) return 0;
	for (int i = 1; i < v.size(); i++) {
		if (v[0] == v[i]) {
			int j(0);
			for (j = 0; i+j < v.size(); j++) 
				if (v[j] != v[i+j]) break;
			if (i+j == v.size()) return i;
		}
	}
	return 0;
}

template <typename IntTip>
bool DaLiJeIspravan(const std::vector<IntTip> &v) {
	for (auto x : v) if (x < 1) return 0;
	return 1;
}

template <typename IntTip>
IntTip DuzinaNajduzeg(const std::vector<IntTip> &v) {
	IntTip duzina(0);
	for (int i = 0; i < v.size(); i++)
		if (v[i] > duzina) duzina = v[i];
	return duzina;
}

template <typename IntTip>
IntTip Suma(const std::vector<IntTip> &v, int period, int koliko_puta) {
	IntTip suma(0);
	for (int i = 0; i < period * koliko_puta; i++)
		suma += v[i%period];
	return suma;
} 

template <typename IntTip>
IntTip **AlocirajFragmentirano(const std::vector<IntTip> &v, int &koliko_puta) {
	if (v.size() == 0) throw "Prazan vektor!";
	if (!DaLiJeIspravan(v)) throw std::domain_error("Neispravan vektor!");
	int period(OsnovniPeriod(v));
	if (period != 0) {
		koliko_puta = v.size()/period;
		if (v.size() % period != 0) koliko_puta++;
	}
	else  {
		period = v.size();
		koliko_puta = 2;
	}
	IntTip **mat(new IntTip *[period*koliko_puta]);
	for (int i = 0; i < period * koliko_puta; i++) mat[i] = nullptr;
	try {
		for (int i = 0; i <	koliko_puta; i++) 
			for (int j = 0; j < period; j++) 
				mat[i*period+j] = new IntTip [v[j]];
	}
	catch(...) {
		for (int i = 0; i < period * koliko_puta; i++)
			delete [] mat[i];
		delete [] mat;
		throw;
	}
	auto max(DuzinaNajduzeg(v));
	for (int i = 0; i < period * koliko_puta; i++) 
		for (IntTip j = 0; j < v[i%period]; j++) 
			mat[i][j] = max - v[i%period] + j + 1;
	return mat;
}

template <typename IntTip>
IntTip **AlociraKontinualno(const std::vector<IntTip> &v, int &koliko_puta) {
	if (v.size() == 0) throw "Prazan vektor!";
	if (!DaLiJeIspravan(v)) throw std::domain_error("Neispravan vektor!");
	int period(OsnovniPeriod(v));
	if (period != 0) {
		koliko_puta = v.size()/period;
		if (v.size() % period != 0) koliko_puta++;
	}
	else  {
		period = v.size();
		koliko_puta = 2;
	}
	int br_el(Suma(v,period, koliko_puta));
	IntTip **mat(new IntTip *[br_el]);
	for (int i = 0; i < period * koliko_puta; i++) mat[i] = nullptr;
	try {
		mat[0] = new IntTip [br_el];
		for (int i = 1; i <	period * koliko_puta; i++) 
			mat[i] = mat[i-1] + v[i%period];
	}
	catch(...) {
		delete [] mat;
		throw;
	}
	int brojac(0);
	for (int i = 0; i < period * koliko_puta; i++) {
		auto x (v[i%period]);
		while (x > 0) mat[0][brojac++] = x--;
	}
	return mat;
}


int main ()
{
	/*try {
		int n;
		std::cout << "Unesite broj elemenata vektora: ";
		std::cin >> n;
		std::cout << "Unesite elemente vektora: ";
		std::vector<int> v(n);
		for (int &x : v) std::cin >> x;
		std::cout << "Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
		int alokacija, **mat, koliko_puta, period(OsnovniPeriod(v));
		if (period == 0) period = v.size();
		if (std::cin >> alokacija, alokacija == 1) {
			mat = AlocirajFragmentirano(v, koliko_puta);
			std::cout << "Dinamicki alocirana matrica:" << std::endl;
			for (int i = 0; i < period * koliko_puta; i++) {
				for (int j = 0; j < v[i%period]; j++)
					std::cout << std::left << std::setw(3) << mat[i][j];
				std::cout << std::endl;
			}
			for (int i = 0; i < period * koliko_puta; i++)
				delete [] mat[i];
			delete [] mat;
		}
		else if (alokacija == 0) {
			mat = AlociraKontinualno(v, koliko_puta);
			std::cout << "Dinamicki alocirana matrica:" << std::endl;
			for (int i = 0; i < Suma(v, period, koliko_puta); i++) {
				std::cout << std::left << std::setw(3) << mat[0][i];
				if (mat[0][i] == 1) std::cout << std::endl;
			}
			delete [] mat[0];
			delete [] mat;
		}
		else return 0;
	}
	catch (const char izuzetak[]) {
		std::cout << "Izuzetak: " << izuzetak;
	}
	catch (std::domain_error izuzetak) {
		std::cout << "Izuzetak: " << izuzetak.what();
	}
	catch (std::bad_alloc) {
		std::cout << "Izuzetak: Alokacija nije uspjela";
	}*/
	const std::vector<int> vektor{1, -2, 3, 4, 1, -2};
        int brojPuta{};
        int **matrica{nullptr};
        try
        {
            matrica = AlocirajKontinualno(vektor, brojPuta); 
            std::cout << "Ovo se ne smije ispisati!" << std::endl;       
        }
        catch(std::domain_error e)
        {
            if (matrica == nullptr)
                std::cout << "OK." << std::endl;
            std::cout << "Izuzetak: " << e.what();
        }
	return 0;
}