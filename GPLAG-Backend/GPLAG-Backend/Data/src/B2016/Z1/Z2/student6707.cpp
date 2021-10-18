#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
typedef std::vector<std::vector<double>> Matrica;

Matrica KreirajMatricu(int brojredova, int brojkolona)
{
	Matrica a;
	a.resize(brojredova);
	for(int i=0; i<brojredova; i++) a[i].resize(brojkolona);
	
	return a;
}

Matrica UnesiMatricu(int brojredova, int brojkolona)
{
	Matrica a=KreirajMatricu(brojredova,brojkolona);
	for(int i=0; i<brojredova; i++)
	{
		for(int j=0; j<brojkolona; j++)
		{
			std::cin>>a[i][j];
		}
	}
	
	return a;
}

void IspisiMatricu(Matrica matrica)
{
	for(int i=0; i<matrica.size(); i++)
	{
		for(int j=0; j<matrica[0].size(); j++)
		{
			std::cout<<std::right<<std::setw(4)<<matrica[i][j];
		}
		std::cout<<std::endl;
	}
}
Matrica Vrsta(Matrica a, int x)
{
	if(x==1)
{
	Matrica privremena(a.size());
	for(int i=0; i<a.size(); i++)
	{
		for(int j=a[0].size()-1; j>=0 ; j--)
		{
			privremena[i].push_back(a[i][j]);
		}
	}
	return privremena;
}
else{
	int j=0;
	Matrica privremena(a.size());
	for(int i=a.size()-1; i>=0; i--)
	{	privremena[j]=a[i];
		j++;
	}
		return privremena;
}
}
Matrica OgledaloMatrica(Matrica a)
{
	int prov=0;
	for(int i=0; i<a.size(); i++)
	{
		if(a[0].size()!=a[i].size()) prov=1;
	}
	if(prov==1) throw std::domain_error("Matrica nije korektna");
	Matrica nova(3*a.size());
	
	int i=0;
	Matrica komb=Vrsta(a,2);
	Matrica kombinovana=Vrsta(komb,1);
	Matrica vertikalna=Vrsta(a,2);
	Matrica horizontalna=Vrsta(a,1);
		for(int j=0; j<a.size();j++)
		{
			for(int k=0; k<a[0].size();k++)
			{
				nova[i].push_back(kombinovana[j][k]);
			}
				for(int k=0; k<a[0].size();k++)
			{
				nova[i].push_back(vertikalna[j][k]);
			}
			for(int k=0; k<a[0].size();k++)
			{
				nova[i].push_back(kombinovana[j][k]);
			}
			i++;
		}
			for(int j=0; j<a.size();j++)
		{
			for(int k=0; k<a[0].size();k++)
			{
				nova[i].push_back(horizontalna[j][k]);
			}
				for(int k=0; k<a[0].size();k++)
			{
				nova[i].push_back(a[j][k]);
			}
			for(int k=0; k<a[0].size();k++)
			{
				nova[i].push_back(horizontalna[j][k]);
			}
			i++;
		}
			for(int j=0; j<a.size();j++)
		{
			for(int k=0; k<a[0].size();k++)
			{
				nova[i].push_back(kombinovana[j][k]);
			}
				for(int k=0; k<a[0].size();k++)
			{
				nova[i].push_back(vertikalna[j][k]);
			}
			for(int k=0; k<a[0].size();k++)
			{
				nova[i].push_back(kombinovana[j][k]);
			}
			i++;
		}
	
	return nova;
}
int main ()
{
	try{
	int m,n;
	Matrica a;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>m>>n;
	if(m<0 || n<0) {
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::cout<<"Unesite elemente matrice: "<<std::endl;
	a=UnesiMatricu(m,n);
std::cout<<"Rezultantna matrica: "<<std::endl;
	Matrica konacna=OgledaloMatrica(a);
	IspisiMatricu(konacna);
	return 0;
	}
	catch(std::domain_error izuzetak){
		std::cout<< izuzetak.what() << std::endl;
		
	}
}