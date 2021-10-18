#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <cmath>
#include <cstdlib>
#define EPS 0.0001

typedef std::vector<std::vector<double>> Matrica;

Matrica NajvecaPlaninaMatrice(Matrica mat)
{
	Matrica rezultat2;
	if(mat.size()==0) return rezultat2;
	
	for(int i=0;i<mat.size();i++)
	{
		if(mat.at(0).size()!=mat.at(i).size())
			throw std::domain_error("Matrica nije korektna");
	}
	
	int veli(int(mat.size())), velj(mat.at(0).size());
	Matrica planine;
	
	for(int i=0;i<veli;i++)
	{
		for(int j=0;j<velj;j++)
		{
			double prethodna_suma(mat.at(i).at(j));
			int k(1);

			while(i-k>=0 && j-k>=0 && i+k<veli && j+k<velj)
			{
				double suma(0);
				for(int x=-k;x<=k;x++)
					for(int y=-k;y<=k;y++)
					{
						if(std::abs(x)==k || std::abs(y)==k)
							suma=suma+mat.at(i+x).at(j+y);
					}
					
			//	if(k>1)
			//	{
					if(suma<prethodna_suma)
					{
						k++;
						prethodna_suma=suma;
					}
					else break;
			//	}
				/*else
				{
					k++;
				}*/
			}
			planine.push_back(std::vector<double>());
			planine.at( int(planine.size()-1) ).push_back(k-1);
			planine.at( int(planine.size()-1) ).push_back(mat.at(i).at(j));
			planine.at( int(planine.size()-1) ).push_back(i);
			planine.at( int(planine.size()-1) ).push_back(j);
		}
	}
	
	double maxk(0),maxi(0),maxj(0),maxvrh(0);
	
	if(planine.size()>0)
	{
		maxk=planine.at(0).at(0);
		maxvrh=planine.at(0).at(1);
		maxi=planine.at(0).at(2);
		maxj=planine.at(0).at(3);
	}
	
	for(int p=1;p<planine.size();p++)
	{
		if(planine.at(p).at(0)>maxk)
		{
			maxk=planine.at(p).at(0);
			maxvrh=planine.at(p).at(1);
			maxi=planine.at(p).at(2);
			maxj=planine.at(p).at(3);
		}
		else if(std::fabs(planine.at(p).at(0)-maxk)<EPS)
		{
			if(planine.at(p).at(1)>maxvrh)
			{
				maxk=planine.at(p).at(0);
				maxvrh=planine.at(p).at(1);
				maxi=planine.at(p).at(2);
				maxj=planine.at(p).at(3);
			}
			else if( std::fabs(planine.at(p).at(1)-maxvrh)<EPS )
			{
				if(planine.at(p).at(2)<maxi)
				{
					maxk=planine.at(p).at(0);
					maxvrh=planine.at(p).at(1);
					maxi=planine.at(p).at(2);
					maxj=planine.at(p).at(3);
				}
				else if( std::fabs(planine.at(p).at(2)-maxi)<EPS )
				{
					if(planine.at(p).at(3)<maxj)
					{
						maxk=planine.at(p).at(0);
						maxvrh=planine.at(p).at(1);
						maxi=planine.at(p).at(2);
						maxj=planine.at(p).at(3);
					}
				}
			}
		}
	}
	
	Matrica rezultat;
	
	for(int i=-maxk;i<=maxk;i++)
	{
		rezultat.push_back(std::vector<double>());
		for(int j=-maxk;j<=maxk;j++)
			rezultat.at( int(rezultat.size()-1) ).push_back(mat.at(int(maxi)+i).at(int(maxj)+j));
	}
	
	return rezultat;

}



int main ()
{
	std::cout<<"Unesite dimenzije matrice (m i n): ";
	int m,n;
	std::cin>>m>>n;
	
	if(m<0 || n<0)
	{
		std::cout<<"Dimenzije matrice moraju biti nenegativne!"<<std::endl;
		return 0;
	}
	
	Matrica mat(m,std::vector<double>(n));
	std::cout<<"Unesite elemente matrice: ";
	for(int i=0;i<mat.size();i++)
		for(int j=0;j<mat.at(i).size();j++)
			std::cin>>mat.at(i).at(j);
			
	std::cout<<std::endl<<"Najveca planina unesene matrice je: "<<std::endl;
	try
	{
		mat=NajvecaPlaninaMatrice(mat);
	}
	catch(std::domain_error izuzetak)
	{
		std::cout<<izuzetak.what()<<std::endl;
	}
	
	for(int i=0;i<mat.size();i++)
	{
		for(int j=0;j<mat.at(i).size();j++)
		{
			std::cout<<std::setw(6)<<mat.at(i).at(j);
		}
		std::cout<<std::endl;
	}
	
return 0;
}