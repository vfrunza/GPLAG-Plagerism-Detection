/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include<iostream>
#include<vector>
#include <iomanip>
#include <stdexcept>
typedef std::vector<std::vector<double>> Matrica;

Matrica HorizontalnoOgledalo(Matrica mat)
{
	Matrica rez(mat.size());
	for(int i(0); i<mat.size();i++)
	{
		for(int j(mat.at(i).size()-1);j>=0;j--)
		{
			rez.at(i).push_back(mat.at(i).at(j));
		}
	}
	return rez;
}

Matrica VertikalnoOgledalo(Matrica mat)
{
	Matrica rez(mat.size());
	int k(0);
	for(int i(mat.size()-1);i>=0;i--)
	{
		rez[k]=mat[i];
		k++;
	}
	return rez;
}

Matrica OgledaloMatrica(Matrica mat)
{
	Matrica rez2;
	if(mat.size()==0)
		return rez2;
		
	for(int i(0);i<mat.size();i++)
	{
		if(mat[0].size()!=mat[i].size())
		{
			throw std::domain_error("Matrica nije korektna");
		}
	}
		
	int m(3*mat.size()),n(3*mat[0].size());
	Matrica math,matv,mathv,rez(m,std::vector<double> (n));
	math=HorizontalnoOgledalo(mat);
	matv=VertikalnoOgledalo(mat);
	mathv=VertikalnoOgledalo(HorizontalnoOgledalo(mat));
	int veli{int(mat.size())},velj{int(mat[0].size())};
	for(int i(0);i<veli;i++)
	{
		for(int j(0);j<velj;j++)
		{
			rez.at(i).at(j)=mathv.at(i).at(j);
			rez[i][2*velj+j]=mathv[i][j];
			rez[2*veli+i][j]=mathv[i][j];
			rez[2*veli+i][2*velj+j]=mathv[i][j];
			rez[veli+i][j]=math[i][j];
			rez[veli+i][2*velj+j]=math[i][j];
			rez[i][velj+j]=matv[i][j];
			rez[2*veli+i][velj+j]=matv[i][j];
			rez[veli+i][velj+j]=mat[i][j];
		}
	}
	
	return rez;
	
}

int main ()
{
	std::cout<<"Unesite dimenzije matrice (m n): ";
	int m,n;
	std::cin>>m>>n;
	if(m<0 || n<0)
	{
		std::cout<<"Dimenzije matrice moraju biti nenegativne!"<<std::endl;
		return 0;
	}
	Matrica mat(m,std::vector<double>(n));
	std::cout<<"Unesite elemente matrice: ";
	for(int i(0);i<mat.size();i++)
	{
		for(int j(0);j<mat[i].size();j++)
		{
			std::cin>>mat[i][j];
		}
	}
	std::cout<<std::endl<<"Rezultantna matrica: "<<std::endl;
	try
	{
		mat=OgledaloMatrica(mat);
	}
	catch(std::domain_error izuzetak)
	{
		std::cout<<izuzetak.what()<<std::endl;
	}
	for(int i(0);i<mat.size();i++)
	{
		for(int j(0);j<mat[i].size();j++)
		{
			std::cout<<std::setw(4)<<mat[i][j];
		}
		std::cout<<std::endl;
	}
	

	return 0;
}