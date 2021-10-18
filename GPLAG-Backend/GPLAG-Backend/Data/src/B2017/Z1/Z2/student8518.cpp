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
#include <stdexcept>
#include <iomanip>
#include <cmath>

#define Epsilon 4*atan(1)

typedef std::vector<std::vector<double>> matrica_double;

matrica_double NapraviMatricu(matrica_double M, int i, int j, int nivo)
{
	matrica_double trenutna_planina( (2*nivo+1), std::vector<double>(2*nivo+1));
	int a(0), b(0);
	
	for(int k=(i-nivo); k<=(i+nivo); k++)
	{
		for(int l=(j-nivo); l<=(j+nivo); l++)
			{
				trenutna_planina.at(a).at(b)=M.at(k).at(l);
				b++;
			}
		b=0;
		a++;
	}
	
	return trenutna_planina;
}

bool DaLiJePlanina(matrica_double M, int i, int j, int nivo, int suma)
{
	int trenutna_suma(0);
	for(int k=(i-nivo); k<=(i+nivo); k++)
	{
		for(int l=(j-nivo); l<=(j+nivo); l++)
			{
				if(k==(i-nivo) || k==(i+nivo) || l==(j-nivo) || l==(j+nivo))
				trenutna_suma+=M.at(k).at(l);		
			}	
	}
	
			
	if(trenutna_suma<suma)
	return true;
	else
	return false;
}

matrica_double NajvecaPlaninaMatrice (matrica_double M )
{
	matrica_double planina, planina2;
	
	for(int i=0; i<M.size(); i++)
	{
		if(M.at(0).size()!=M.at(i).size())
		throw std::domain_error ("Matrica nije korektna");
	}
	
	if(M.size()==0 || M.at(0).size()==0)
	return planina;  //u ovom trenutku prazna
	
	
	if(M.size()<=2 || M.at(0).size()<=2)
	{
		int maksimalan_element(M.at(0).at(0) );
		for(int i=0; i<M.size(); i++)
		{
			for(int j=0; j<M.at(0).size(); j++)
			{
				if(M.at(i).at(j) - maksimalan_element > Epsilon) ///////////dodao za epsilon
				maksimalan_element=M.at(i).at(j);
			}
		}
		planina.resize(1);
		planina.at(0).resize(1);
		planina.at(0).at(0)=maksimalan_element;
		return planina;
	}
	
	int nivo(1), maks_nivo(0);
	for(int i=0; i<M.size(); i++)
	{
		for(int j=0; j<M.at(i).size(); j++)
		{
			if(i==0 || i==M.size()-1 || j==0 || j==M.at(i).size()-1 )
			continue;
			
			nivo=1;
			
			int suma( M.at(i).at(j) );
			while( (i-nivo)>=0 && (i+nivo)<M.size() && (j+nivo)<M.at(i).size() && (j-nivo)>=0 && DaLiJePlanina(M, i, j, nivo, suma))
			{
				suma=0;	
				for(int k=(i-nivo); k<=(i+nivo); k++)
				{
					for(int l=(j-nivo); l<=(j+nivo); l++)
						{
							if(k==(i-nivo) || k==(i+nivo) || l==(j-nivo) || l==(j+nivo))
								suma+=M.at(k).at(l);		
						}	
				}
				
				nivo++;
			}
			
			if(maks_nivo<(nivo-1))
			{
				maks_nivo=(nivo-1);
				planina=NapraviMatricu(M, i, j, (nivo-1) );
			}
			else if(maks_nivo==(nivo-1) && (nivo-1)!=0)
			{
				planina2=NapraviMatricu(M, i, j, (nivo-1) );
				
				if( planina2.at(nivo).at(nivo) - planina.at(nivo).at(nivo) > Epsilon ) ///////////////////dodao za epsilon
				{
					planina=planina2;
				}
			//ukoliko su planine istog nivoa i imaju isti vrh, promjenjiva "planina" ne treba da poprimi vrijednost "planina2", jer njen vrh ima manje indekse (uslov zadatka)
			}
		}
	}
	
	if(planina.size()==0)
	{
		int maksimalan_element(M.at(0).at(0) );
		for(int i=0; i<M.size(); i++)
		{
			for(int j=0; j<M.at(0).size(); j++)
			{
				if( (i==0 || j==0 || j==M.at(0).size()-1 || i==M.size()-1 ) && M.at(i).at(j)-maksimalan_element>Epsilon)    ////////////////dodao za epsilon
				maksimalan_element=M.at(i).at(j);
			}
		}
		planina.resize(1);
		planina.at(0).resize(1);
		planina.at(0).at(0)=maksimalan_element;
		return planina;
	}
	
	return planina;
}

int main ()
{
	std::cout<<"Unesite dimenzije matrice (m i n): ";
	int a, b;
	std::cin>>a>>b;
	
	if(a<0 || b<0)
	{
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	
	matrica_double M(a, std::vector<double>(b)); ///
	
	std::cout<<"Unesite elemente matrice: "<<std::endl;
	for (int i=0; i<a; i++) 
	{
		for (int j=0; j<b; j++) 
		{
			std::cin>>M.at(i).at(j);
		}
	}
	
	
	try
	{
		M=NajvecaPlaninaMatrice(M);
		
	}
	catch(std::domain_error poruka)
	{
		std::cout<<poruka.what();
		return 0; //ne znam treba li (vidi iz autotesta)
	}
	
	std::cout<<"Najveca planina unesene matrice je: "<<std::endl;
	for(int i=0; i<M.size(); i++)
	{
		for(int j=0; j<M.at(0).size(); j++)
		{
			std::cout<<std::setw(6)<<M.at(i).at(j);
		}
		std::cout<<std::endl;
	}
	
	return 0;
}