//B 2017/2018, Zadaća 1, Zadatak 2
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdexcept>

typedef std::vector<double> Vektor;
typedef std::vector<Vektor> Matrica;

Matrica NajvecaPlaninaMatrice(Matrica mat)
{
	Matrica matrica;
	bool vrh(false);
	double zbir(0),suma(0),kvadrat(0);
	int format(1),k(0),l(0);
	int x(0),y(0);
	int cif(0);
	
	for(int i=0; i<mat.size()-1; i++)
	{
		if(mat.size()==0 || mat.at(i).size()==0)
		{
			mat.resize(1);
			mat.at(0).resize(1);
			mat.at(0).at(0)=0;
			return mat;
		}
	}
	
	for(int i=0; i<mat.size()-1; i++)
		if(mat.at(i).size()!=mat.at(i+1).size())throw std::domain_error("Matrica nije korektna");
		
	
	int najveci(1);		
	for(int i=1; i<mat.size()-1; i++)
	{
		int br(1);
		for(int j=1; j<mat.at(0).size()-1; j++)
		{	
			if( i-br<br-1 || j-br<br-1)continue;
			suma=-mat.at(i).at(j);
			for(k=0; k<format+2; k++)
			{
				for(l=0; l<format+2; l++)
				{
					if(i-br+k>=0 && j-br+l>=0)
					{
						if(br>cif)cif=br;
						if(i+k-br<mat.size() && j+l-br<mat.at(0).size())suma=suma+mat.at(i-br+k).at(j-br+l);
					}
						
				} 
			}
			kvadrat=suma;
				if(format>1){
					zbir=kvadrat-zbir;
					if(zbir<kvadrat-zbir){
						vrh=true;
						format=format+2;
						br++;
						if(najveci<format)najveci=format;
					}
					else {
						vrh=false;
						br=1;
						format=1;
					}
				}
				if(format==1 && kvadrat<mat.at(i).at(j))
				{	
					zbir=kvadrat;
					vrh=true;
					format=format+2;
					if(najveci<format)
					{
						najveci=format;
						x=i;
						y=j;
					}
					if(najveci==format)
					{
						if(i<x)
						{
							x=i;y=j;
						}
						else if(i>=x && y<j)
						{
							x=i;y=j;
						}
					}
					br++;
					j--;
				}	
				else if(format==1 && kvadrat>=mat.at(i).at(j)) 
				{
					vrh=false;
					br=1;
					format=1;
				}
				suma=0;
			
		}
		br=1; 
		format=1;	
	}
	
	if(najveci>1)
	{
		matrica.resize(najveci);
    	for(int i=0; i<najveci; i++)
		{	
			matrica.at(i).resize(najveci);
			for(int j=0; j<najveci; j++)matrica.at(i).at(j)=mat.at(x-cif+i).at(y-cif+j);
		}
		return matrica;
	}
	
	else if(mat.size()==0 || mat.at(0).size()==0)
	{	
		mat.resize(0);
		mat.at(0).resize(0);
		return matrica;
	}
	else if((mat.size()>0 && mat.size()<3) || (mat.at(0).size()>0 && mat.at(0).size()<3) || vrh==false)
	{
		double max(0);
		for(int i=0; i<mat.size(); i++)
		{
			for (int j=0; j<mat.at(0).size(); j++)
			{
				if(max<mat.at(i).at(j))max=mat.at(i).at(j);
			}
		}
		mat.resize(1);
		mat.at(0).resize(1);
		for(int i=0; i<mat.size(); i++)
		{
			for (int j=0; j<mat.at(0).size(); j++)
			{
				mat.at(i).at(j)=max;
			}
		}
		
		return mat;
	}
}

int main ()
{	
	std::cout << "Unesite dimenzije matrice (m i n): ";
	int m(0),n(0);
	std::cin >> m >> n;
	if(m<0 || n<0)
	{
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	
	std::cout << "Unesite elemente matrice: " << std::endl;
	Matrica mat(m, Vektor(n));
	for(int i=0; i<m; i++)
	{
		for (int j=0; j<n; j++)
		{
			std::cin >> mat.at(i).at(j);
		}
	}
	
	std::cout << "Najveca planina unesene matrice je: " << std::endl;
	try {
		mat=NajvecaPlaninaMatrice(mat);
	}
	catch(std::domain_error izuzetak) {
 			std::cout << izuzetak.what() << std::endl;
	}
	
	for(int i=0; i<mat.size(); i++)
	{
		for (int j=0; j<mat.at(i).size(); j++)
		{
			std::cout << std::setw(6) << mat.at(i).at(j);
		} std::cout << std::endl;
	}
	return 0;
}