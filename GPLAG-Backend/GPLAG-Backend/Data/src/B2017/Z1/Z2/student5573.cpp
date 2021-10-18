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
std::vector<std::vector<double>> NajvecaPlaninaMatrice(std::vector<std::vector<double>> matrica)
{
	int t(matrica.at(0).size());
	for(int i=1;i<matrica.size();i++)
	{
		if(matrica.at(i).size()!=t)
		{
			throw std::domain_error("Matrica nije korektna");
		}
	}
	std::vector<std::vector<double>> vrati,skladiste;
	int k(0),brojac;
	for(int i=0;i<matrica.size();i++)
	{
		for(int j=0;j<matrica.at(i).size();j++)
		{
			int l(0),p(1);
			skladiste.resize(skladiste.size()+1);
			skladiste.at(k).push_back(i);
			skladiste.at(k).push_back(j);
			skladiste.at(k).push_back(matrica.at(i).at(j));
			while(0<=i-p && 0<=j-p && i+p<matrica.size() && j+p<matrica.at(i).size())
			{
				double suma(0),suma2(0);
				for(int m=i-p;m<=i+p;m++)
				{
					for(int n=j-p;n<=j+p;n++)
					{
						suma+=matrica.at(m).at(n);
					}
				}
				p++;
				for(int m=2;m<skladiste.at(k).size();m++)	suma2+=skladiste.at(k).at(m);
				if((suma-suma2)<skladiste.at(k).at(2+l))
				{
					skladiste.at(k).push_back(suma-suma2);
					l++;
				}
				else	break;
			}
			k++;
		}
	}
	brojac=skladiste.at(0).size();
	k=0;
	for(int i=1;i<skladiste.size();i++)
	if(skladiste.at(i).size()>=brojac)
	{
		brojac=skladiste.at(i).size();
		k=i;
	}
	int l(0);
	for(int i=skladiste.at(k).at(0)-skladiste.at(k).size()+3;i<=skladiste.at(k).at(0)+skladiste.at(k).size()-3;i++)
	{
		vrati.resize(vrati.size()+1);
		for(int j=skladiste.at(k).at(0)-skladiste.at(k).size()+3;j<=skladiste.at(k).at(1)+skladiste.at(k).size()-3;j++)
		{
			vrati.at(l).push_back(matrica.at(i).at(j));
		}
		l++;
	}
	return vrati;
}
int main ()
{
	try
	{
		std::cout<<"Unesite dimenzije matrice (m i n): ";
		int m,n;
		std::cin>>m>>n;
		if(m<0 || n<0)
		{
			std::cout<<"Dimenzije matrice moraju biti nenegativne!";
			return 0;
		}
		std::cout<<"Unesite elemente matrice:"<<std::endl;
		std::vector<std::vector<double>> matrica(m,std::vector<double> (n)),matrica2;
		for(int i=0;i<m;i++)
		{
			
			for(int j=0;j<n;j++)
			{
				std::cin>>matrica.at(i).at(j);
			}
		}
		matrica2=NajvecaPlaninaMatrice(matrica);
		std::cout<<"Najveca planina unesene matrice je:"<<std::endl;
		for(int i=0;i<matrica2.size();i++)
		{
			for(int j=0;j<matrica2.at(i).size();j++)
			{
				std::cout<<std::setw(6);
				std::cout<<matrica2.at(i).at(j);
			}
			std::cout<<std::endl;
		}
		return 0;
	}
	catch(std::domain_error e)
	{
		std::cout<<e.what();
	}
}