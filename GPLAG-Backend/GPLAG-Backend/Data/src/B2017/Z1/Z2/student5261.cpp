/*B 2017/2018, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

std::vector<std::vector<double>> KreirajMatricu(int m, int n)
{
	return std::vector<std::vector<double>> (m, std::vector<double>(n));
}

std::vector<std::vector<double>> UnesiMatricu(int m, int n)
{
	auto mat(KreirajMatricu(m, n));
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			std::cin >> mat.at(i).at(j);
		}
	}
	return mat;
}
void IspisiMatricu(std::vector<std::vector<double>> mat)
{
	for(int i=0; i<mat.size(); i++)
	{
		for(int j=0; j<mat.at(i).size(); j++)
		{
			std::cout << std::setw(6) << mat.at(i).at(j);
		}
		std::cout << std::endl;
	}
}

double Vanjski(std::vector<std::vector<double>> mat)
{
	double suma(0);
	for(int i=0; i<mat.size(); i++)
	{
		for(int j=0; j<mat.at(i).size(); j++)
		{
			if(i==0 || i==mat.size()-1 || j==0 || j==mat.at(i).size()-1)
				suma += mat.at(i).at(j); 
		}
	}
	return suma;
}

double Unutarnji(std::vector<std::vector<double>> mat)
{
	double suma(0);
	for(int i=0; i<mat.size(); i++)
	{
		for(int j=0; j<mat.at(i).size(); j++)
		{
			if(i==1 && j>0 && j<mat.at(i).size()) suma +=mat.at(i).at(j);
			else if(i==mat.size()-2 && j>0 && j<mat.at(i).size()-1) suma += mat.at(i).at(j);
			else if(j==mat.at(i).size()-2 && i>0 && i<mat.size()-1) suma += mat.at(i).at(j);
			else if(j==0 && i>0 && i<mat.size()-1) suma += mat.at(i).at(j);
		}
	}
	return suma;
}

std::vector<std::vector<double>> Formirana_podmatrica(std::vector<std::vector<double>> mat, int a, int b, int n)
{
	int d(n*2+1);
	auto pom = KreirajMatricu(n*2+1, d);
	int x(a-n);
	int y(b-n);
	int k(0), l(0);
	for(int i=x; i<d+x; i++)
	{
		l=0;
		for(int j=y; j<d+y; j++)
		{
			pom.at(k).at(l) = mat.at(i).at(j);
			l++;
		}
		k++;
	}
	return pom;
}

std::vector<std::vector<double>> NajvecaPlaninaMatrice(std::vector<std::vector<double>> mat)
{
	std::vector<std::vector<double>> planina_matrice;
	for(int i=0; i<mat.size()-1; i++)				
	{
		if(mat.at(i).size() != mat.at(i+1).size())
			throw std::domain_error("Matrica nije korektna");
	}
	
	for(int i=0; i<mat.size(); i++)
	{
		for(int j=0; j<mat.at(i).size(); j++)
		{
			int n(0);
			while(i+n < mat.size() && i-n >= 0 && j+n < mat.at(0).size() && j-n >= 0)
			{
				/*std::vector<std::vector<double>> pomocna;
				int d(n*2 + 1);
				int x(i-n);
				int y(j-n);
				pomocna.resize(n*2 + 1);
				for(int k=0; k<d; k++)
					pomocna.at(i).resize(d);
				int b1(0), b2(0);
				for(int t=x; t<d+x; t++)
				{
					b2 = 0;
					for(int s=y; s<d+y; s++)
					{
						pomocna.at(b1).at(b2) = mat.at(t).at(s);
						b2++;
					}
					b1++;
				}*/
				std::vector<std::vector<double>> pomocna = Formirana_podmatrica(mat, i, j, n);
				if(((Vanjski(pomocna) < Unutarnji(pomocna)) || pomocna.size() == 1) && 
				 (pomocna.size() > planina_matrice.size() || pomocna.size() == planina_matrice.size()))
					planina_matrice = pomocna;
				n++;
			}
			//n++;
		}
	}
	return planina_matrice;
}

int main()
{
	try
	{
		int m,n;
		std::cout << "Unesite dimenzije matrice (m i n): ";
		std::cin >> m >> n;
		if(m<0 || n<0)
		{
			std::cout << "Dimenzije matrice moraju biti nenegativne!";
			return 0;
		}
		//std::vector<std::vector<double>> mat;
		std::cout << "Unesite elemente matrice:" << std::endl;
		auto mat = UnesiMatricu(m, n);
		std::vector<std::vector<double>> najveca_planina;
		najveca_planina = NajvecaPlaninaMatrice(mat);
		std::cout << "Najveca planina unesene matrice je:" << std::endl;
		IspisiMatricu(najveca_planina);
	}
	catch(std::domain_error e)
	{
		std::cout << "Izuzetak: " << e.what() << std::endl;
	}
	return 0;
}
