#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <iomanip>

template<typename Tip>
bool Periodicnost (const std::vector<Tip> &v, int p)  // Provjerava da li je dati vektor periodican za dati period p
{
	if (p>=v.size() || v.size()==1) return false;
	for (int i = 0; i<v.size()-p; i++)
		if (fabs (v.at(i)-v.at(i+p))>0.0000001) return false;
	return true;

}

template <typename Tip>
int OdrediOsnovniPeriod(const std::vector<Tip> &v)  // Određuje osnovni period vektora zajedno sa funkcijom Periodicnost
{
	for (int i = 1; i< v.size(); i++)
		if (Periodicnost(v,i)) return i;
	return 0;
}

template <typename Tip>
void Periodiziraj(const std::vector<Tip> &v, int Period, int &koliko_puta) // Trazi kolika je vrijednost od koliko_puta
{
	if (!Period)   // Ako je period 0 onda moraju biti dva perioda
		koliko_puta=2;
	else {
		double broj_perioda;
		broj_perioda = double (v.size())/Period;
		if ((broj_perioda-int(broj_perioda)) < 0.000001)
			koliko_puta=int(broj_perioda);
		else
			koliko_puta=int(broj_perioda)+1;
	}
}

template <typename Tip>
int Max (const std::vector<Tip> v) // Trazi najveci broj u vektoru
{
	int max(0);
	for (int i = 0; i<v.size(); i++)
		if (v.at(i)>max) max=v.at(i);
	return max;
}

template <typename Tip>
int SumaPeriode (const std::vector<Tip> v)  // Trazi sumu jednog perioda
{
	Tip suma(0);
	int novi_period;

	if (!OdrediOsnovniPeriod(v)) novi_period=v.size();
	else novi_period=OdrediOsnovniPeriod(v);

	for (int i = 0; i<novi_period; i++)
		suma+=v.at(i);
	return suma;
}

template <typename Tip>
Tip **AlocirajFragmentirano (const std::vector<Tip> &v, int &koliko_puta)
{
	try {
		if (!v.size()) throw std::domain_error ("Prazan vektor!");
		for (int i = 0; i<v.size(); i++)
			if (v.at(i)<=0) throw std::domain_error ("Neispravan vektor!");
	} catch (std::domain_error izuzetak) {
		throw;
	}

	int broj(Max(v)),pomoc(broj),s(0),novi_period;   // s- mi govori koji je po redu element jedne periode // broj je najveci element vektora

	if (!OdrediOsnovniPeriod(v)) novi_period=v.size();
	else novi_period=OdrediOsnovniPeriod(v);

	Periodiziraj (v,OdrediOsnovniPeriod(v),koliko_puta);

	Tip **mat(new int *[novi_period*koliko_puta]);   // Broj redova matrice
	for (int k = 0; k<koliko_puta; k++) {
		for (int i = 0; i<novi_period; i++) {
			mat[s]=new int [v.at(i)];
			for (int j = v.at(i)-1; j>=0; j--) {
				mat[s][j]=broj;
				broj--;
			}
			broj=pomoc;
			s++;
		}
	}
	return mat;
}

template <typename Tip>
Tip **AlocirajKontinualno (const std::vector<Tip> &v, int &koliko_puta)
{
	try {
		if (v.size()==0) throw std::domain_error ("Prazan vektor!");
		for (int i = 0; i<v.size(); i++)
			if (v.at(i)<=0) throw std::domain_error("Neispravan vektor!");
	} catch (std::domain_error izuzetak) {
		throw;
	}
	int novi_period;
	if (!OdrediOsnovniPeriod(v)) novi_period=v.size();
	else novi_period=OdrediOsnovniPeriod(v);
	Periodiziraj(v,OdrediOsnovniPeriod(v),koliko_puta);

	Tip **mat(new int*[novi_period*koliko_puta]);

	mat[0]=new int[koliko_puta*SumaPeriode(v)];
	int s(0);
	for (int i = 1; i<novi_period*koliko_puta; i++) {
		mat[i]=mat[i-1]+v.at(s);
		s++;
		if (s==novi_period) s=0;
	}
	s=0;
	for (int j = 0; j<novi_period*koliko_puta; j++) {
		Tip jedan(1);
		for (int k = v.at(s)-1; k>=0; k--) {
			mat[j][k]=jedan;
			jedan++;
		}
		s++;
		if (s==novi_period) s=0;
	}
	return mat;
}

int main ()
{
	try {
		std::cout<<"Unesite broj elemenata vektora: ";
		int n;
		std::cin>>n;
		std::cout<<"Unesite elemente vektora: ";
		std::vector<int> v;
		for (int i = 0; i<n; i++) {
			int broj;
			std::cin>>broj;
			v.push_back(broj);
		}

		std::cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
		int alokacija,koliko_puta;
		std::cin>>alokacija;

		if (alokacija) {
			auto mat(AlocirajFragmentirano(v,koliko_puta));
			std::cout<<"Dinamicki alocirana matrica:"<<std::endl;
			int novi_period;
			if (!OdrediOsnovniPeriod(v)) novi_period=v.size();  // novi_period je novi period vektora
			else novi_period=OdrediOsnovniPeriod(v);
			int s(0);   // s-je red matrice koju treba ispisati

			for (int i = 0; i<koliko_puta; i++) {
				for (int k = 0; k<novi_period; k++) {
					for (int j = 0; j<v.at(k); j++) {
						std::cout<<std::left<<std::setw(3)<<mat[s][j];
					}
					s++;
					std::cout<<std::endl;
				}
			}
			for (int i = 0; i<koliko_puta*3; i++) delete[] mat[i];
			delete []mat;
		} else {
			auto mat(AlocirajKontinualno(v,koliko_puta));
			std::cout<<"Dinamicki alocirana matrica:"<<std::endl;
			int novi_period;
			if (!OdrediOsnovniPeriod(v)) novi_period=v.size();  // novi_period je novi period vektora
			else novi_period=OdrediOsnovniPeriod(v);
			int s(0);   // s-je red matrice koju treba ispisati

			for (int i = 0; i<koliko_puta; i++) {
				for (int k = 0; k<novi_period; k++) {
					for (int j = 0; j<v.at(k); j++) {
						std::cout<<std::left<<std::setw(3)<<mat[s][j];
					}
					s++;
					std::cout<<std::endl;
				}
			}
			delete [] mat[0];
			delete [] mat;

		}
	} catch (std::domain_error izuzetak) {
		std::cout<<"Izuzetak: "<<izuzetak.what();
	} catch (...) {
		std::cout<<"Izuzetak: Nešto ne valja";
	}
	return 0;
}