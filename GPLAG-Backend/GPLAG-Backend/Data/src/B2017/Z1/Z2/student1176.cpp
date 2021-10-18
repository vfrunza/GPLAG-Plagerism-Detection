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

bool DaLiJePlanina(std::vector<std::vector<double>> matrica, int a, int b, int vel)
{
	double vs = matrica.at(a).at(b);
	int h;
	
	for(h=1; h<=vel/2; h++)
	{
		double ms(0);
		
		for(int i=a-h; i<=a+h; i++)
		{
			for(int j=b-h; j<=b+h; j++)
			{
				if(j!=b-h && j!=b+h) 
				{
					continue;
				}
				ms = ms + matrica.at(i).at(j);			
			}
		}
		if(ms>vs) 
		{
			return false;
		}
		
		ms=vs;
	}
	return true;
}

std::vector<std::vector<double>> NajvecaPlaninaMatrice(std::vector<std::vector<double>> matrica)
{
	// test grbawe matrice
	
	int red = matrica.at(0).size();
	
	for(int i=0; i<matrica.size(); i++)
	{
		if(matrica.at(i).size() != red) throw std::domain_error("Matrica nije korektna");
	}
	
	
	
	int h, MXI(0), MXJ(0);
	if(matrica.size() > matrica.at(0).size())
	{
		h = matrica.at(0).size();
	}
	else
	{
		h = matrica.size();
	}
	for(h; h>2; h--)
	{
		for(int i=0; i<matrica.size(); i++)
		{
			if(i+h/2 >= matrica.size() || i-h/2 < 0)
			{
				continue;
			}
			for(int j=0; j<matrica.at(0).size(); j++)
			{
				if(j+h/2 >= matrica.at(0).size() || j-h/2<0)
				{
					continue;
				}
				
				if(DaLiJePlanina(matrica, i, j, h))
				{
					if(!MXI)
					{
						MXI = i;
						MXJ = j;
					}
					else
					{
						if(matrica.at(i).at(j) > matrica.at(MXI).at(MXJ))
						{
							MXI = i;
							MXJ = j;
						}
						else if(matrica.at(i).at(j) == matrica.at(MXI).at(MXJ))
						{
							if(i<MXI)
							{
								MXI = i;
								MXJ = j;
							}
							else if(i == MXI)
							{
								if(j<MXI)
								{
									MXI = i;
									MXJ = j;
								}
							}
						}
					}
				}
			}
		}
		if(MXI)
		{
			break;
		}
	}
	int a(0);
	
	std::vector<std::vector<double>> planina(h, std::vector<double>());
	for(int i=MXI - h/2; i <= MXI + h/2; i++)
	{
		for(int j=MXJ-h/2; j<=MXJ+h/2; j++)
		{
			planina.at(a).push_back(matrica.at(i).at(j));
		}
		a++;
	}
	return planina;
}


int main ()
{
	
	std::vector<std::vector<double>> M;
	
	int m, n;
	
	std::cout << "Unesite dimenzije matrice (m i n): ";
	
	std::cin >> m >> n;
	
	if(m < 0 || n < 0)
	{
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	
	std::vector<std::vector<double>> matrica(m, std::vector<double>(n));
	
	std::cout << "Unesite elemente matrice: ";
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
		std::cin >>	matrica.at(i).at(j);
	 
		}
	}
	
	
	std::cout << std::endl << "Najveca planina unesene matrice je: " << std::endl;
	try
	{
		M = NajvecaPlaninaMatrice(matrica);
	}
	catch(std::domain_error izuzetak)
	{
		std::cout << izuzetak.what() <<std::endl;
	}
	for(int i=0; i<M.size(); i++)
	{
		for(int j=0; j<M.at(i).size(); j++)
		{
			std::cout << std::right << std::setw(6) << M.at(i).at(j);
		}
		std::cout << std::endl;
	}
	return 0;
}
