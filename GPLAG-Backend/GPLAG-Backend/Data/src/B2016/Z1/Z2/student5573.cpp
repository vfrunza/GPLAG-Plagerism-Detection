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
std::vector<std::vector<double>> OgledaloMatrica(std::vector<std::vector<double>> Matrica)
{
	int red,kolona;
	red=Matrica.size();
	if(red==0)
	{
		return Matrica;
	}
	kolona=Matrica[0].size();
	for(int i=0;i<red;i++)
	{
		if((Matrica[0].size()<Matrica[i].size()) || (Matrica[0].size()>Matrica[i].size()))
		{
			throw std::domain_error("Matrica nije korektna");
		}
	}
	std::vector<std::vector<double>> Horizontalni;
	std::vector<std::vector<double>> Vertikalni;
	std::vector<std::vector<double>> Mijesani;
	std::vector<std::vector<double>> Obicna;
	Obicna=Matrica;
	Horizontalni=Matrica;
	Vertikalni=Matrica;
	int a,pomocna;
	a=kolona-1;
	for(int i=0;i<red;i++)
	{
		for(int j=0;j<kolona/2;j++)
		{
			pomocna=Horizontalni[i][j];
			Horizontalni[i][j]=Horizontalni[i][a];
			Horizontalni[i][a]=pomocna;
			a--;
		}
		a=kolona-1;
	}
	a=red-1;
	for(int i=0;i<red/2;i++)
	{
		for(int j=0;j<kolona;j++)
		{
			pomocna=Vertikalni[i][j];
			Vertikalni[i][j]=Vertikalni[a][j];
			Vertikalni[a][j]=pomocna;
		}
		a--;
	}
	Mijesani=Vertikalni;
	a=kolona-1;
	for(int i=0;i<red;i++)
	{
		for(int j=0;j<kolona/2;j++)
		{
			pomocna=Mijesani[i][j];
			Mijesani[i][j]=Mijesani[i][a];
			Mijesani[i][a]=pomocna;
			a--;
		}
		a=kolona-1;
	}
	std::vector<std::vector<double>> Vratiti(red*3,std::vector<double> (kolona*3));
	int k=0;
	for(int i=0;i<red;i++)
	{
		for(int j=0;j<Mijesani[i].size();j++)
		{
			Vratiti[i][k]=Mijesani[i][j];
			k++;
		}
		for(int j=0;j<Vertikalni[i].size();j++)
		{
			Vratiti[i][k]=Vertikalni[i][j];
			k++;
		}
		for(int j=0;j<Mijesani[i].size();j++)
		{
			Vratiti[i][k]=Mijesani[i][j];
			k++;
		}
		k=0;
	}
	k=0;
	int ii=0;
	for(int i=red;i<red*2;i++)
	{
		for(int j=0;j<Horizontalni[ii].size();j++)
		{
			Vratiti[i][k]=Horizontalni[ii][j];
			k++;
		}
		for(int j=0;j<Obicna[ii].size();j++)
		{
			Vratiti[i][k]=Obicna[ii][j];
			k++;
		}
		for(int j=0;j<Horizontalni[ii].size();j++)
		{
			Vratiti[i][k]=Horizontalni[ii][j];
			k++;
		}
		k=0;
		ii++;
	}
	k=0;ii=0;
	for(int i=red*2;i<red*3;i++)
	{
		for(int j=0;j<Mijesani[ii].size();j++)
		{
			Vratiti[i][k]=Mijesani[ii][j];
			k++;
		}
		for(int j=0;j<Vertikalni[ii].size();j++)
		{
			Vratiti[i][k]=Vertikalni[ii][j];
			k++;
		}
		for(int j=0;j<Mijesani[ii].size();j++)
		{
			Vratiti[i][k]=Mijesani[ii][j];
			k++;
		}
		k=0;ii++;
	}
	return Vratiti;
}
int main ()
{
	try
	{
		int red,kolona;
		std::cout<<"Unesite dimenzije matrice (m n): ";
		std::cin>>red>>kolona;
		if(red<0 || kolona<0)
		{
			std::cout<<"Dimenzije matrice moraju biti nenegativne!";
			return 0;
		}
		std::cout<<"Unesite elemente matrice: "<<std::endl;
		std::vector<std::vector<double>> Pocetna(red,std::vector<double> (kolona));
		for(int i=0;i<red;i++)
		{
			for(int j=0;j<kolona;j++)
			{
				std::cin>>Pocetna[i][j];
			}
		}
		Pocetna=OgledaloMatrica(Pocetna);
		std::cout<<"Rezultantna matrica:"<<std::endl;
		for(int i=0;i<Pocetna.size();i++)
		{
			for(int j=0;j<Pocetna[i].size();j++)
			{
				std::cout<<std::setw(4)<<Pocetna[i][j];
			}
			std::cout<<std::endl;
		}
		return 0;
	}
	catch(...)
	{
		std::cout<<"Matrica nije korektna";
	}
}