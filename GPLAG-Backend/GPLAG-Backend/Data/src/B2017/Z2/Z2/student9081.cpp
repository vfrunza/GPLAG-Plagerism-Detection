/*B 2017/2018, Zadaća 2, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <vector>
#include <deque>
#include <iomanip>
#include <stdexcept>

enum class SmjerKretanja {NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo};

int Granica (int x, int y)
{
	int temp;
	if (x<(y+1)/2)
		temp=x;
	else
		temp=y-x-1;
	return temp;
}
template <typename Tip>
Tip PjescaniSat (Tip kont, SmjerKretanja x)
{
	for (int i=0;i<kont.size();i++) {
		if (kont.at(i).size()!=kont.size())
			throw std::domain_error ("3D matrica nema oblik kocke");
		for (int j=0;j<kont.at(i).size();j++) {
			if (kont.at(i).at(j).size()!=kont.size())
				throw std::domain_error ("3D matrica nema oblik kocke");
		}
		for (int j=0;j<kont.at(i).size();j++)
		{
			for (int k=0;k<kont.at(i).at(j).size();k++) {
				if (kont.at(i).size()!=kont.at(i).at(j).size())
					throw std::domain_error("3D matrica nema oblik kocke");
			}
		}
	}
	for (int i=0;i<kont.size();i++) {
		if (kont.size()%2==0)
			throw std::length_error ("3D kontejner ne zadovoljava uvjet neparnosti");
		for (int j=0;j<kont.at(i).size();j++) {
			if (kont.at(i).at(j).size()%2==0)
				throw std::length_error ("3D kontejner ne zadovoljava uvjet neparnosti");
		}
		if (kont.at(i).size()%2==0)
			throw std::length_error ("3D kontejner ne zadovoljava uvjet neparnosti");
	}
	Tip vrati(kont.size());
	if (x==SmjerKretanja::GoreDolje)	{
		for (int i=0;i<kont.size();i++)	{
			vrati.at(i).resize(kont.at(i).size());
			for (int j=0;j<kont.at(i).size();j++) {
				int temp(Granica(j,kont.at(i).size()));
				for (int k=temp;k<kont.at(i).at(j).size()-temp;k++)
					vrati.at(i).at(j).push_back(kont.at(i).at(j).at(k));
			}
		}
	}
	else if (x==SmjerKretanja::DoljeGore) {
		for (int i=0;i<kont.size();i++)	{
			vrati.at(i).resize(kont.at(i).size());
			int indeks(0);
			for (int j=kont.at(i).size()-1;j>=0;j--) {
				int temp (Granica(j,kont.at(i).size()));
				for (int k=temp;k<kont.at(i).at(j).size()-temp;k++)	
					{vrati.at(i).at(indeks).push_back(kont.at(i).at(j).at(k));}
					indeks++;
			}
		}
	}
	else if (x==SmjerKretanja::DesnoLijevo) {
		for (int i=0;i<kont.size();i++) {
			vrati.at(i).resize(kont.at(i).size());
			int indeks(0);
			for (int j=kont.at(i).size()-1;j>=0;j--) {
				int temp(Granica(j,kont.at(i).size()));
				for (int k=temp;k<kont.at(i).at(j).size()-temp;k++) 
					{vrati.at(i).at(indeks).push_back(kont.at(i).at(k).at(j));}
					indeks++;
			}
		}
	}
	else if (x==SmjerKretanja::LijevoDesno) {
		for (int i=0;i<kont.size();i++) {
			vrati.at(i).resize(kont.at(i).size());
			int indeks(0);
			for (int j=0;j<kont.at(i).size();j++) {
				int temp(Granica(j,kont.at(i).size()));
				for (int k=temp;k<kont.at(i).at(j).size()-temp;k++)
				{	vrati.at(i).at(indeks).push_back(kont.at(i).at(k).at(j));}
					indeks++;
			}
		}
	}
	else if (x==SmjerKretanja::NaprijedNazad) {
			for (int i=0;i<kont.size();i++) {
				for (int j=0;j<kont.size();j++)
				vrati.at(j).resize(kont.size());
				for (int j=0;j<kont.at(i).size();j++) {
					int temp(Granica(i,kont.at(i).size()));
					for (int k=temp;k<kont.at(i).at(j).size()-temp;k++)
					vrati.at(j).at(i).push_back(kont.at(i).at(j).at(k));
				}
			}
	}
	else if (x==SmjerKretanja::NazadNaprijed) {
		int indeks(0);
		for (int i=kont.size()-1;i>=0;i--) {
			for (int j=0;j<kont.size();j++)
			vrati.at(j).resize(kont.size());
			for (int j=0;j<kont.at(i).size();j++) {
				int temp(Granica(i,kont.at(i).size()));
				for (int k=temp;k<kont.at(i).at(j).size()-temp;k++)
					vrati.at(j).at(indeks).push_back(kont.at(i).at(j).at(k));
			}
			indeks++;
		}
	}
	return vrati;
}

int main ()
{
	try {
	int n;
	std::cout<<"Unesite dimenziju (x/y/z): ";
	while (std::cin>>n, (n<0)) {
		std::cout<<"Dimenzija nije ispravna, unesite opet: ";
	}
	std::vector<std::deque<std::deque<int>>> kont(n,std::deque<std::deque<int>> (n,std::deque<int> (n)));
	std::cout<<"Unesite elemente kontejnera: ";
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			for (int k=0;k<n;k++) 
				std::cin>>kont.at(i).at(j).at(k);
		}
	}
	int x;
	std::cout<<"Unesite smjer kretanja [0 - 5]: ";
	while (std::cin>>x, (x<0 || x>5)) {
		std::cout<<"Smjer nije ispravan, unesite opet: ";
	}
	std::cout<<"\n";
	auto v(PjescaniSat(kont,SmjerKretanja(x)));
	std::cout<<"Pjescani sat unesene matrice je:\n";
	std::cout<<"\n";
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			int temp(Granica(j,n));
			int indeks(0);
			for (int k=0;k<n;k++) {
				if (k>=temp && k<n-temp) {
				std::cout<<std::setw(4)<<v.at(i).at(j).at(indeks);
				indeks++;
				}
				else 
				std::cout<<std::setw(4)<<"";
			}
			std::cout<<"\n";
		}
		std::cout<<"\n";
	}
	}
	catch (std::domain_error izuzetak) {
		std::cout<<"\nIzuzetak: "<<izuzetak.what()<<std::endl;
	}
	catch (std::length_error izuzetak2) {
		std::cout<<"\nIzuzetak: "<<izuzetak2.what()<<std::endl;
	}
	return 0;
}