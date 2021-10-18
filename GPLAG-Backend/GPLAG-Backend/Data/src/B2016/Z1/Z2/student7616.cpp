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

Matrica HorizontalnoOgledalo(Matrica mat)
{
	for(int i=0; i<mat.size(); i++)
	{
		for(int j=0; j<mat[i].size() / 2; j++)
		{
			int tmp=mat[i][mat[i].size()-j-1];
			mat[i][mat[i].size()-j-1]=mat[i][j];
			mat[i][j]=tmp;
		}
	}
	return mat;
}

Matrica VertikalnoOgledalo(Matrica mat)
{
	for(int i=0; i<mat.size()/2; i++)
	{
		for(int j=0; j<mat[i].size(); j++)
		{
			int tmp(mat[mat.size()-i-1][j]);
			mat[mat.size()-i-1][j]=mat[i][j];
			mat[i][j]=tmp;
		}
	}
			
	return mat;
}
Matrica KombinovanoOgledalo(Matrica m)
{
	m=HorizontalnoOgledalo(m);
	m=VertikalnoOgledalo(m);
	return m;
}

Matrica OgledaloMatrica(Matrica mat)
{
	if(mat.size()==0) return mat;
	if(mat.size()>1 && mat[0].size() != mat[1].size() ) throw std::domain_error("Matrica nije korektna");
	
	Matrica H(HorizontalnoOgledalo(mat));
	Matrica V(VertikalnoOgledalo(mat));
	Matrica HV (KombinovanoOgledalo(mat));
	
	
	Matrica m(3*mat.size(),std::vector<double>(3*mat[0].size()));
	for(int i=0; i< m.size(); i++)
	{
		for(int j=0; j<m[i].size(); j++)
		{
			if(i<HV.size() && j<HV[0].size()) m[i][j]=HV[i][j];
			else if(i<HV.size() && j>= HV[0].size()*2) m[i][j]=HV[i][j-HV[0].size()*2];
			else if(i>=HV.size()*2 && j<HV[0].size()) m[i][j]=HV[i-HV.size()*2][j];
			else if(i>=HV.size()*2 && j>=HV[0].size()*2) m[i][j]=HV[i-HV.size()*2][j-HV[0].size()*2];
			else if(i<HV.size() && j>=HV[0].size()) m[i][j]=V[i][j-HV[0].size()];
			else if(i>=HV.size()*2 && j>=HV[0].size()) m[i][j]=V[i-HV.size()*2][j-HV[0].size()];
			else if(i>=HV.size() && j<HV[0].size()) m[i][j]=H[i-HV.size()][j];
			else if(i>=HV.size() && j>=HV[0].size()*2) m[i][j]=H[i-HV.size()][j-HV[0].size()*2];
			else m[i][j]=mat[i-HV.size()][j-HV[0].size()];
		}
	}
	return m;
}

void Ispisi( Matrica mat)
{
	for(int i=0; i<mat.size(); i++)
	{
		for(int j=0; j<mat[i].size(); j++)
		std::cout<<std::setw(4)<<mat[i][j];
		std::cout<<std::endl;
	}
}

int main ()
{
	int m,n;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>m>>n;
	if(m < 0 || n < 0 ) {
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
 	Matrica mat(m, std::vector<double> (n));
	std::cout<<"Unesite elemente matrice: ";
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			std::cin>>mat[i][j];
		}
	}
	std::cout<<std::endl<<"Rezultantna matrica: ";
		std::cout<<std::endl;
	//Matrica mat{{1,2,3},{4,5},{2}};
	try
	{
		Ispisi(OgledaloMatrica(mat));
	}
		catch (std::domain_error poruka)
		{
			std::cout<<poruka.what();
		}
	return 0;
}