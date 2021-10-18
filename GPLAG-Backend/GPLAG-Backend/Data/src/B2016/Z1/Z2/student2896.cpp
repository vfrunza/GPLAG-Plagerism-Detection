/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9...
	
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

std::vector<std::vector<double>> OgledaloMatrica(std::vector<std::vector<double>> mat)
{

	try
		{
		
		int m = mat.size();
		int n;
		if(m!= 0)
		{
			n = mat.at(0).size();
		}
		else
		{
			return std::vector<std::vector<double>> (0);
		}
		for(int i=0;i<mat.size()-1;i++)
		{
			if(mat.at(i).size() != mat.at(i+1).size())
			{
				throw std::domain_error("Matrica nije korektna");
			}
		}
		std::vector<std::vector<double>> mega (3*m, std::vector<double> (3*n));
		std::vector<std::vector<double>> h = mat;
		std::vector<std::vector<double>> v = mat;
		std::vector<std::vector<double>> hv = mat;
		h = mat;
		for(int i=0; i<m; i++)
		{
			for(int j=0; j<n/2; j++)
			{
				double pomocna;
				pomocna = h.at(i).at(j);
				h.at(i).at(j) = h.at(i).at(n-1-j);
				h.at(i).at(n-1-j) = pomocna;
			}
		}
		v = mat;
		for(int i=0; i<m/2;i++)
		{
			std::vector<double> pomocni(0);
			pomocni = v.at(i);
			v.at(i) = v.at(m-1-i);
			v.at(m-1-i) = pomocni;
		}
		hv =  h;
		for(int i=0; i<m/2; i++)
		{
			std::vector<double> pomocni(0);
			pomocni = hv.at(i);
			hv.at(i) = hv.at(m-1-i);
			hv.at(m-1-i) = pomocni;
		}
		for(int i=0; i<m; i++)
		{
			for(int j=0; j<n; j++)
			{
				mega.at(i).at(j) = hv.at(i).at(j);
			}
			for(int j=n; j<2*n; j++)
			{
				mega.at(i).at(j) = v.at(i).at(j-n);
			}
			for(int j=2*n; j<3*n; j++)
			{
				mega.at(i).at(j) = hv.at(i).at(j-2*n);
			}
		}
		for(int i=m; i<2*m;i++)
		{
			for(int j=0; j<n; j++)
			{
				mega.at(i).at(j) = h.at(i-m).at(j);
			}
			for(int j=n; j<2*n; j++)
			{
				mega.at(i).at(j) = mat.at(i-m).at(j-n);
			}
			for(int j=2*n; j<3*n; j++)
			{
				mega.at(i).at(j) = h.at(i-m).at(j-2*n);
			}
		}
		
		for(int i=2*m; i<3*m; i++)
		{
			for(int j=0; j<n; j++)
			{
				mega.at(i).at(j) = hv.at(i-2*m).at(j);
			}
			for(int j=n; j<2*n; j++)
			{
				mega.at(i).at(j) = v.at(i-2*m).at(j-n);
			}
			for(int j=2*n; j<3*n; j++)
			{
				mega.at(i).at(j) = hv.at(i-2*m).at(j-2*n);
			}
		}
		return mega;
	}
	catch(std::domain_error &e)
	{
		std::cout << e.what();
	}
	catch(...)
	{
		std::cout << "Matrica nije korektna";
	}
	return std::vector<std::vector<double>> (0);
}

int main ()
{
	std::cout << "Unesite dimenzije matrice (m n): ";
	int m,n;
	std::cin >> m >> n;
	if(n<0 || m<0)
	{
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::vector<std::vector<double>> mat(m,std::vector<double>(n));
	std::cout << "Unesite elemente matrice: ";
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			double unos;
			std::cin >> unos;
			if(!std::cin)
			{
				std::cout << "Pogresan unos podataka";
				return 0;
			}
			mat.at(i).at(j) = unos;
		}
	}
	std::vector<std::vector<double>> rez = OgledaloMatrica(mat);
	std::cout << "\nRezultantna matrica: ";
	for(int i=0; i<rez.size(); i++)
	{
		std::cout << std::endl;
		for(int j=0; j<rez.at(i).size(); j++)
		{
			std::cout << std::right << std::setw(4) << rez.at(i).at(j);
		}
	}
	return 0;
}