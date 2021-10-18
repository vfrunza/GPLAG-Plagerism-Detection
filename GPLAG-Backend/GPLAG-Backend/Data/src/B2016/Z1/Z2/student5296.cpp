/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include<iomanip>

std::vector<std::vector<double>> KreirajMatricu(int br_r, int br_k)
{
	return std::vector<std::vector<double>> (br_r, std::vector<double>(br_k));
}

std::vector<std::vector<double>> Horizontalna(std::vector<std::vector<double>> M)
{
	std::vector<std::vector<double>> m;
	m.resize(M.size());
	for(int i=0; i<m.size(); i++)
	{
		m[i].resize(M[0].size());
	}
	for(int i=0; i<M.size(); i++)
	{
		for(int j=0; j<M[0].size(); j++)
		{
			m[i][j]=M[i][M[0].size()-j-1];
		}
	}
	return m;
}

std::vector<std::vector<double>> Vertikalna(std::vector<std::vector<double>> M)
{
	std::vector<std::vector<double>> m;
	m.resize(M.size());
	for(int i=0; i<m.size(); i++)
	{
		m[i].resize(M[0].size());
	}
	for(int i=0; i<M.size(); i++)
	{
		for(int j=0; j<M[0].size(); j++)
		{
			m[i][j]=M[M.size()-i-1][j];
		}
	}
	return m;
}

std::vector<std::vector<double>> Kombinovana(std::vector<std::vector<double>> M)
{
	std::vector<std::vector<double>> m;
	m.resize(M.size());
	for(int i=0; i<m.size(); i++)
	{
		m[i].resize(M[0].size());
	}
	for(int i=0; i<M.size(); i++)
	{
		for(int j=0; j<M[0].size(); j++)
		{
			m[i][j]=M[M.size()-i-1][M[0].size()-j-1];
		}
	}
	return m;
}

std::vector<std::vector<double>> OgledaloMatrica(std::vector<std::vector<double>> M)
{
		std::vector<std::vector<double>> m;
		m.resize(M.size()*3);
		for(int i=0; i<m.size(); i++)
		{
			m[i].resize(M[0].size()*3);
		}
		for(int i=0; i<m.size(); i++)
		{
			for(int j=0; j<m[0].size(); j++)
			{
				if((i<M.size() && j<M[0].size()) || (i<M.size() && j>=2*M[0].size()) || (i>=2*M.size() && j<M[0].size()) || (i>=2*M.size() && j>=2*M[0].size()))
				{ 
					if(i<m.size()/2)
					{
						if(j<m[0].size()/2) m[i][j]=Kombinovana(M)[i][j];
						else m[i][j]=Kombinovana(M)[i][j-2*M[0].size()];
					}
					else
					{
						if(j<m[0].size()/2) m[i][j]=Kombinovana(M)[i-2*M.size()][j];
						else m[i][j]=Kombinovana(M)[i-2*M.size()][j-2*M[0].size()];
					}
				}
				if(j>=M[0].size() && j<2*M[0].size())
				{
					if(i<M.size()) m[i][j]=Vertikalna(M)[i][j-M[0].size()];
					if(i>=2*M.size()) m[i][j]=Vertikalna(M)[i-2*M.size()][j-M[0].size()];
				}
				if(i>=M.size() && i<2*M.size())
				{
					if(j<M[0].size()) m[i][j]=Horizontalna(M)[i-M.size()][j];
					if(j>=2*M[0].size()) m[i][j]=Horizontalna(M)[i-M.size()][j-2*M[0].size()];
				}
				if(i>=M.size() && i<2*M.size() && j>=M[0].size() && j<2*M[0].size())
				{
					m[i][j]=M[i-M.size()][j-M[0].size()];
				}
			}
		}
		return m;
}

int main ()
{
	int a,b;
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> a >> b;
	if(a<0 || b<0) std::cout << "Dimenzije matrice moraju biti nenegativne!";
	else
	{
		std::vector<std::vector<double>> m(KreirajMatricu(a,b));
		std::cout << "Unesite elemente matrice: ";
		for(int i=0; i<m.size(); i++)
		{
			for(int j=0; j<m[0].size(); j++)
			{
				int x;
				std::cin >> x;
				m[i][j]=x;
			}
		}
		std::cout << "\nRezultantna matrica: " << std::endl;
		for(int i=0; i<OgledaloMatrica(m).size(); i++)
		{
			for(int j=0; j<OgledaloMatrica(m)[0].size(); j++)
			{
				std::cout << std::setw(4) << OgledaloMatrica(m)[i][j];
			}
			std::cout << std::endl;
		}
	}
	return 0;
} 