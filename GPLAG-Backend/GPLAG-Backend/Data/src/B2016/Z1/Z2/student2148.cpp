/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

std::vector<std::vector<double>> hor(std::vector<std::vector<double>> mat)
{
	//int m(mat.size()), n(mat[0].size());
	int m, n;
	if(mat.size()==0) { m=0; n=0; }
	else { m=mat.size(); n=mat[0].size(); }
	std::vector<std::vector<double>> pom(m, std::vector<double> (n));
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			pom[i][j]=mat[i][n-1-j];
		}
	}
	return pom;
}

std::vector<std::vector<double>> ver(std::vector<std::vector<double>> mat)
{
	int m, n;
	if(mat.size()==0) { m=0; n=0; }
	else { m=mat.size(); n=mat[0].size(); }
	std::vector<std::vector<double>> pom(m, std::vector<double> (n));
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			pom[i][j]=mat[m-1-i][j];
		}
	}
	return pom;
}

std::vector<std::vector<double>> horver(std::vector<std::vector<double>> mat)
{
	int m, n;
	if(mat.size()==0) { m=0; n=0; }
	else { m=mat.size(); n=mat[0].size(); }
	std::vector<std::vector<double>> pom(m, std::vector<double> (n));
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			pom[i][j]=mat[m-1-i][n-1-j];
		}
	}
	return pom;
}

std::vector<std::vector<double>> OgledaloMatrica(std::vector<std::vector<double>> mat)
{
	int m1, n1, m, n;
	if(mat.size()==0) { m1=0; n1=0; m=0; n=0; }
	else { m1=mat.size(); n1=mat[0].size(); m=3*mat.size(); n=3*mat[0].size(); }
	for(int i=0; i<mat.size(); i++)
	{
		if(mat[i].size()!=mat[0].size())
		{
			throw std::domain_error("Matrica nije korektna");
		}
	}
	std::vector<std::vector<double>> h(hor(mat));
	std::vector<std::vector<double>> v(ver(mat));
	std::vector<std::vector<double>> hv(horver(mat));
	std::vector<std::vector<double>> matrica(m, std::vector<double> (n));
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(i<=(m/3)-1)
			{
				if(j<=(n/3)-1) matrica[i][j]=hv[i][j];
				else if(j<=((2*n)/3)-1) matrica[i][j]=v[i][j-n1];
				else if(j<=n-1) matrica[i][j]=hv[i][j-(2*n1)];
			}
			else if(i<=((2*m)/3)-1)
			{
				if(j<=(n/3)-1) matrica[i][j]=h[i-m1][j];
				else if(j<=((2*n)/3)-1) matrica[i][j]=mat[i-m1][j-n1];
				else if(j<=n-1) matrica[i][j]=h[i-m1][j-(2*n1)];
			}
			else if(i<=m-1)
			{
				if(j<=(n/3)-1) matrica[i][j]=hv[i-(2*m1)][j];
				else if(j<=((2*n)/3)-1) matrica[i][j]=v[i-(2*m1)][j-n1];
				else if(j<=n-1) matrica[i][j]=hv[i-(2*m1)][j-(2*n1)];
			}
		}
	}
	return matrica;
}

int main ()
{
	int m, n;
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> m >> n;
	if(m<0 || n<0)
	{
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::vector<std::vector<double>> mat(m, std::vector<double> (n));
	std::cout << "Unesite elemente matrice: ";
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			std::cin >> mat[i][j];
		}
	}
	try
	{
		std::vector<std::vector<double>> matrica(OgledaloMatrica(mat));
		std::cout << std::endl << "Rezultantna matrica:" << std::endl;
		for(int i=0; i<matrica.size(); i++)
		{
			std::cout << " ";
			for(int j=0; j<matrica[0].size(); j++)
			{
				std::cout << std::setw(3) << std::right << matrica[i][j] << " ";	
			}
			std::cout << std::endl;
		}
	}
	catch(std::domain_error e)
	{
		std::cout << e.what();
	}
	return 0;
}