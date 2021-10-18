/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

std::vector<std::vector<double>> h_ogledalo(std::vector<std::vector<double>> M)
{
	if(M.size() == 0) return M;
	std::vector<std::vector<double>> hM;
	for(int i=0; i<M.size(); i++)
	{
		hM.push_back(std::vector<double>());
		for(int j=M[i].size()-1; j>=0; j--)
		{
			hM[i].push_back(M[i][j]);
			
		}
	}
	return hM;
}

std::vector<std::vector<double>> v_ogledalo(std::vector<std::vector<double>> M)
{
	if(M.size() == 0) return M;
	std::vector<std::vector<double>> vM;
	for(int i=M.size()-1; i>=0; i--)
	{
		vM.push_back(std::vector<double>());
		for(int j=0; j<M[i].size(); j++)
		{
			vM[M.size()-1-i].push_back(M[i][j]);
		}
	}
	return vM;
}

std::vector<std::vector<double>> hv_ogledalo(std::vector<std::vector<double>> M)
{
	if(M.size() == 0) return M;
	std::vector<std::vector<double>> hvM;
	hvM = h_ogledalo(M);
	hvM = v_ogledalo(hvM);
	return hvM;
}

std::vector<std::vector<double>> OgledaloMatrica(std::vector<std::vector<double>> M)
{
	if(M.size() == 0) return M;
	bool ista (true);
	for(int i=0; i<M.size(); i++)
	{
		if(i < M.size()-1)
		{
			if(M[0].size() != M[i+1].size())
			{
				ista = false;
				break;
			}
		}
	}
	if(!ista) throw std::domain_error ("Matrica nije korektna!");
	
	std::vector<std::vector<double>> hM = h_ogledalo(M);
	std::vector<std::vector<double>> vM = v_ogledalo(M);
	std::vector<std::vector<double>> hvM = hv_ogledalo(M);
	std::vector<std::vector<double>> oM;
	oM.resize(M.size()*3);
	for(int i=0; i<oM.size(); i++)
	{
		oM[i].resize(M[0].size()*3);
	}
	for(int i=0; i<M.size(); i++)
	{
		for(int j=0; j<M[i].size(); j++)
		{
			oM[i][j] = hvM[i][j];
		}
	}
	for(int i=0; i<M.size(); i++)
	{
		for(int j=0; j<M[i].size(); j++)
		{
			oM[i][j+M[i].size()] = vM[i][j];
		}
	}
	for(int i=0; i<M.size(); i++)
	{
		for(int j=0; j<M[i].size(); j++)
		{
			oM[i][j+2*M[i].size()] = hvM[i][j];
		}
	}
	for(int i=0; i<M.size(); i++)
	{
		for(int j=0; j<M[i].size(); j++)
		{
			oM[i+M.size()][j] = hM[i][j];
		}
	}
	for(int i=0; i<M.size(); i++)
	{
		for(int j=0; j<M[i].size(); j++)
		{
			oM[i+M.size()][j+M[i].size()] = M[i][j];
		}
	}
	for(int i=0; i<M.size(); i++)
	{
		for(int j=0; j<M[i].size(); j++)
		{
			oM[i+M.size()][j+2*M[i].size()] = hM[i][j];
		}
	}
	for(int i=0; i<M.size(); i++)
	{
		for(int j=0; j<M[i].size(); j++)
		{
			oM[i+2*M.size()][j] = hvM[i][j];		
		}
	}
	for(int i=0; i<M.size(); i++)
	{
		for(int j=0; j<M[i].size(); j++)
		{
			oM[i+2*M.size()][j+M[i].size()] = vM[i][j];
		}
	}
	for(int i=0; i<M.size(); i++)
	{
		for(int j=0; j<M[i].size(); j++)
		{
			oM[i+2*M.size()][j+2*M[i].size()] = hvM[i][j];
		}
	}
	return oM;
}
int main()
{
	try
	{
		int m, n;
		std::cout << "Unesite dimenzije matrice (m n): ";
		std::cin >> m >> n;
		if(m<0 || n<0)
		{
			std::cout << "Dimenzije matrice moraju biti nenegativne!" << std::endl;
			return 0;
		}
		std::vector<std::vector<double>> matrica (m, std::vector<double>(n));
		std::cout << "Unesite elemente matrice: ";
		for(int i=0; i<m; i++)
		{
			for(int j=0; j<n; j++)
			{
				std::cin >> matrica[i][j];
			}
		}
		std::vector<std::vector<double>> velika_matrica = OgledaloMatrica(matrica);
		std::cout << "\nRezultantna matrica: " << std::endl;
		for(int i=0; i<velika_matrica.size(); i++)
		{
			for(int j=0; j<velika_matrica[0].size(); j++)
			{
				std::cout << std::setw(4) << velika_matrica[i][j];
			}
			std::cout << std::endl;
		}
	}
	catch(std::domain_error IZUZETAK)
	{
		std::cout << IZUZETAK.what();
	}
	return 0;
}
	

