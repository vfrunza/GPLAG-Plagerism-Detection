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

Matrica OgledaloMatrica(Matrica stara)
{
	Matrica nova;
	
	int a;
	int vel(stara.size());
	nova.resize(3*vel);
	if(stara.size())
	{
	
		for(int i=0;i<stara.size();i++)
		{
			if(stara[i].size()!=stara[0].size())
			throw std::domain_error("Matrica nije korektna");
			
		}
	
	}
	for(int i=0;i<vel;i++)
	{
		
		a=stara[i].size();
		nova[i].resize(3*a);
		
		for(int j=0;j<a;j++)
		{
			nova[i][j]=stara[vel-i-1][a-j-1];
		}
		
		for(int j=a;j<2*a;j++)
		{
			nova[i][j]=stara[vel-1-i][j-a];
		}
		
		for(int j=2*a;j<3*a;j++)
		{
			nova[i][j]=stara[vel-1-i][3*a-1-j];
		}
		
	}
	
	
	for(int i=vel;i<2*vel;i++)
	{
		a=stara[i-vel].size();
		nova[i].resize(3*a);
		for(int j=0;j<a;j++)
		{
			nova[i][j]=stara[i-vel][a-1-j];
		}
		for(int j=a;j<2*a;j++)
		{
			nova[i][j]=stara[i-vel][j-a];
		}
		for(int j=2*a;j<3*a;j++)
		{
			nova[i][j]=stara[i-vel][3*a-1-j];
		}
		
	}
	
	for(int i=2*vel;i<3*vel;i++)
	{
		a=stara[i-2*vel].size();
		nova[i].resize(3*a);
		for(int j=0;j<a;j++)
		{
			nova[i][j]=stara[3*vel-1-i][a-1-j];
		}
		for(int j=a;j<2*a;j++)
		{
			nova[i][j]=stara[3*vel-1-i][j-a];
		}
		for(int j=2*a;j<3*a;j++)
		{
			nova[i][j]=stara[3*vel-1-i][3*a-1-j];
		}
		
	}
	
	
	return nova;
}


int main ()
{
	std::cout<<"Unesite dimenzije matrice (m n): ";
	int n,m;
	try
	{
	std::cin>>m>>n;
	
	if(n<0 || m<0)
	throw std::domain_error("Dimenzije matrice moraju biti nenegativne!");
	}
	catch(std::domain_error izuzetak)
	{
		std::cout<<izuzetak.what()<<std::endl;
		return 0;
	}
	std::cout<<"Unesite elemente matrice: ";
	Matrica matrica(m,std::vector<double>(n));
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		std::cin>>matrica[i-1][j-1];
	}
	std::cout<<std::endl<<"Rezultantna matrica: "<<std::endl;
	try
	{
	Matrica nova=OgledaloMatrica(matrica);
	}
	catch(std::domain_error izuzetak)
	{
		std::cout<<izuzetak.what()<<std::endl;
		return 0;
	}
	Matrica nova=OgledaloMatrica(matrica);
	for(int i=1;i<=3*m;i++)
	{
		for(int j=1;j<=3*n;j++)
		std::cout<<std::setw(4)<<std::right<<nova[i-1][j-1];
		std::cout<<std::endl;
	}
	
	
	
	return 0;
}