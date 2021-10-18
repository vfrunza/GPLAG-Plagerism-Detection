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
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iomanip>

template <typename element>
bool DaLiJePeriod (int n,std::vector<element> v)
{
	for (int i=0;i<v.size()-n;i++) {
		if (v.at(i)!=v.at(i+n) || i==i+n)
			return false;
	}
	return true;
}

template <typename Neki>
int OdrediOsnovniPeriod (std::vector<Neki> v) 
{
	for (int i=1;i<v.size();i++) {
		if (DaLiJePeriod(i,v))
			return i;
	}
	return 0;
}
void Obrisi (int **mat, int n) 
{
	if (!mat) return;
	for (int i=0;i<n;i++) delete[] mat[i];
	delete[] mat;
}
void Obrisi2 (int **mat, int n)
{
	if (!mat) return;
	delete[] mat[0];
	delete[] mat;
}

template <typename Tip>
int **AlocirajFragmentirano (const std::vector<Tip> &v, int &koliko_puta) 
{
	if (v.size()==0) throw "Prazan vektor!";
	for (int i=0;i<v.size();i++) {
		if (v.at(i)<=0)
			throw std::domain_error ("Neispravan vektor!");
	}
	int period(OdrediOsnovniPeriod(v));
	if (period==0) 
	koliko_puta=2;
	else {
		int vel(v.size());
		while (vel%period!=0)
		vel++;
		koliko_puta=vel/period;
	}
	if (period==0)
	period=v.size();
	int vel1(period*koliko_puta);
	int **pok(new int* [vel1] {});
	try {
		for (int i=0;i<vel1;i++) {
			if (i<v.size())
			pok[i]=new int [v.at(i)];
			else
			pok[i]=new int [v.at(i-period*(koliko_puta-1))];
		}
		for (int i=0;i<vel1;i++) {
			int maxe(*std::max_element(v.begin(),v.end()));
			if (i<v.size()) {
				for (int j=v.at(i)-1;j>=0;j--) {
				pok[i][j]=maxe;
				maxe--; }
			}
			else {
				for (int j=v.at(i-(koliko_puta-1)*period)-1;j>=0;j--) {
					pok[i][j]=maxe;
					maxe--;
				}
			}
		}
	}	
	catch (std::bad_alloc) {
		Obrisi(pok,vel1);
		throw;
	}
	return pok;
}
template <typename tip> 
int **AlocirajKontinualno (const std::vector<tip> &v, int &koliko_puta) 
{
	if (v.size()==0)	throw "Prazan vektor!";
	for (int i=0;i<v.size();i++) {
		if (v.at(i)<=0)
			throw std::domain_error ("Neispravan vektor!");
	}
	int period(OdrediOsnovniPeriod(v));
	int vel(v.size());
	if (period==0)
	koliko_puta=2;
	else {
		while (vel%period!=0)
		vel++;
		koliko_puta=vel/period;
	}
	if (period==0)
	period=v.size();
	int vel1(period*koliko_puta);
	int **pok(new int *[vel1] {});
	int suma(0);
	for (int i=0;i<vel1;i++) {
		if (i<v.size())
		suma+=v.at(i);
		else
		suma+=v.at(i-(koliko_puta-1)*period);
	}
	try {
		pok[0]=new int[suma];
		for (int i=1;i<vel1;i++) {
			if (i<=period)
			pok[i]=pok[i-1]+v.at(i-1);
			else
			pok[i]=pok[i-1]+v.at(i-period-1);
		}
		for (int i=0;i<vel1;i++) {
			int ubaci(1);
			if (i<v.size()) {
				for (int j=v.at(i)-1;j>=0;j--) {
				pok[i][j]=ubaci;
				ubaci++;}
			}
			else  {
				for (int j=v.at(i-period*(koliko_puta-1))-1;j>=0;j--) {
				pok[i][j]=ubaci;
				ubaci++; }
			}
		}
	}
	catch (std::bad_alloc) {
		Obrisi2(pok,vel1);
		throw;
	}
	return pok;
}

int main ()
{ 
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	int x,vel;
	int **pok(nullptr);
	int **pok1(nullptr);
	std::vector<int> v;
	try {
	std::cout<<"Unesite elemente vektora: ";
	for (int i=0;i<n;i++) {
		int unos;
		std::cin>>unos;
		v.push_back(unos);
	}
	std::cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	std::cin>>x;
	int koliko_puta;
	int period(OdrediOsnovniPeriod(v));
	if (x==1){
		pok=AlocirajFragmentirano(v,koliko_puta);
		std::cout<<"Dinamicki alocirana matrica:\n";
		if (period==0)
		period=v.size();
		vel=period*koliko_puta;
		for (int i=0;i<vel;i++) {
			if (i<v.size()) {
				for (int j=0;j<v.at(i);j++)
				std::cout<<std::left<<std::setw(3)<<pok[i][j];
				std::cout<<"\n";
			}
			else {
				for (int j=0;j<v.at(i-(koliko_puta-1)*period);j++) 
				std::cout<<std::left<<std::setw(3)<<pok[i][j];
				std::cout<<"\n";
			}
		}
	}
	else if (x==0) {
		pok1=AlocirajKontinualno(v,koliko_puta);
		std::cout<<"Dinamicki alocirana matrica:\n";
		if (period==0)
		period=v.size();
		vel=period*koliko_puta;
		for (int i=0;i<vel;i++) {
			if (i<v.size()) {
				for (int j=0;j<v.at(i);j++)
				std::cout<<std::left<<std::setw(3)<<pok1[i][j];
				std::cout<<"\n";
			}
			else {
				for (int j=0;j<v.at(i-(koliko_puta-1)*period);j++)
				std::cout<<std::left<<std::setw(3)<<pok1[i][j];
				std::cout<<"\n";
			}
		}
	}
	}
	catch (std::bad_alloc) {
		std::cout<<"Izuzetak: Nedostatak memorije!";
	}
	catch (const char tekst[]) {
		std::cout<<"Izuzetak: "<<tekst;
	}
	catch (std::domain_error izuzetak) {
		std::cout<<"Izuzetak: "<<izuzetak.what();
	}
	if (x==1)
		Obrisi(pok,vel);
	if (x==0)
		Obrisi2(pok1,vel);
	return 0;
}