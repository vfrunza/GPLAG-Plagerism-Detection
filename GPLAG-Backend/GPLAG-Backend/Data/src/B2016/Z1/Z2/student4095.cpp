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

typedef std::vector<std::vector<double>> Matrica;

Matrica Horizontalna (Matrica m)
{
	for (int i=0; i<m.size(); i++)
	{
		for (int j=0; j<m[i].size()/2; j++)
		{
			double pomocna(m[i][j]);
			m[i][j]=m[i][int(m[i].size())-1-j];
			m[i][int(m[i].size())-1-j]=pomocna;
		}
	}
	return m;
}

Matrica Vertikalna (Matrica m)
{
	for (int i=0; i<m.size()/2; i++)
	{
		for (int j=0; j<m[i].size(); j++)
		{
			double pomocna(m[i][j]);
			m[i][j]=m[int(m.size())-1-i][j];
			m[int(m.size())-1-i][j]=pomocna;
		}
	}
	return m;
}

Matrica OgledaloMatrica (Matrica mat)
{
	Matrica povratna(mat);
	if (!mat.size())
		return povratna;
	else if (!mat[0].size())
	{
		povratna.resize(3*int(mat.size()));
		return povratna;
	}
	for (int i=1; i<mat.size(); i++)
	{
		if (mat[i].size()!=mat[0].size())
			throw std::domain_error ("Matrica nije korektna"); 
	}
	int m(mat.size()), n(mat[0].size());
	povratna.resize(3*m);
	for (int i=0; i<povratna.size(); i++)
		povratna[i].resize(3*n);
	Matrica hmat(Horizontalna(mat)), vmat(Vertikalna(mat)), hvmat(Vertikalna(Horizontalna(mat)));
	for (int i=0; i<povratna.size(); i++)
	{
		for (int j=0; j<povratna[i].size(); j++)
		{
			if (i<m && j<n)
				povratna[i][j]=hvmat[i][j];
			else if (i>2*m-1 && j<n)
				povratna[i][j]=hvmat[i-2*m][j];
			else if (i<m && j>2*n-1)
				povratna[i][j]=hvmat[i][j-2*n];
			else if (i>2*m-1 && j>2*n-1)
				povratna[i][j]=hvmat[i-2*m][j-2*n];
			else if (i<m && (j>n-1 && j<2*n))
				povratna[i][j]=vmat[i][j-n];
			else if (i>2*m-1 && (j>n-1 && j<2*n))
				povratna[i][j]=vmat[i-2*m][j-n];
			else if ((i>m-1 && i<2*m) && j<n)
				povratna[i][j]=hmat[i-m][j];
			else if ((i>m-1 && i<2*m) && j>2*n-1)
				povratna[i][j]=hmat[i-m][j-2*n];
			else if ((i>m-1 && i<2*m) && (j>n-1 && j<2*n))
				povratna[i][j]=mat[i-m][j-n];
		}
	}
	return povratna;
}

int main ()
{
	int m, n;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>m>>n;
	if (m<0 || n<0)
	{
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	Matrica mat(m, std::vector<double> (n));
	std::cout<<"Unesite elemente matrice: ";
	for (int i=0; i<mat.size(); i++)
		for (int j=0; j<mat[i].size(); j++)
			std::cin>>mat[i][j];
	try{
	Matrica povratna(OgledaloMatrica(mat));
	std::cout<<std::endl<<"Rezultantna matrica: "<<std::endl;
	for (int i=0; i<povratna.size(); i++)
	{
		for (int j=0; j<povratna[i].size(); j++)
		{
			std::cout<<std::setw(4)<<povratna[i][j];
		}
		std::cout<<std::endl;
	}
	}
	catch (std::domain_error izuzetak)
	{
		std::cout<<izuzetak.what()<<std::endl;
	}
	return 0;
}