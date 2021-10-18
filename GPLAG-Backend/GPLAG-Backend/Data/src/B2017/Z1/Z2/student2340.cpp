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


typedef std::vector<std::vector<double>> Matrica;

Matrica KreirajMatricu(int m, int n)
{
	return Matrica(m, std::vector<double>(n));
}

Matrica NajvecaPlaninaMatrice(Matrica m)
{
	if(m.size()==0 || m.at(0).size()==0) return Matrica (0,std::vector<double>(0));
	int max=m.at(0).at(0);
	int x(0),y(0);
	for(int i(0); i<m.size(); i++)
	{
		for(int j(0); j<m.at(i).size(); j++)
		{
			if(m.at(0).size()!=m.at(i).size()) throw std::domain_error ("Matrica nije korektna");
			if(max<m.at(i).at(j)) 
			{
				max=m.at(i).at(j);
				x=j;
				y=i;
			}
		}
	}

	
	//Dimenzije primljene matrice
	int p(m.at(0).size()-1), q(m.size()-1);
	
	//Najmanja udaljenos elementa od ruba
	int xn(0), yn(0), min, a(0), b(0);
	
	if(x<=p-x) xn=x;
	else xn=p-x;
	
	if(y<=y-q) yn=y;
	else yn=q-y;
	
	if(xn<=yn) min=xn;
	else if(yn<xn) min=yn;
	
	Matrica N(KreirajMatricu((2*min)+1, (2*min)+1));
	
	if(min==0)
	{
		N.at(0).at(0)=max;
	}
	else
	{
		for(int i(x-min); i<(x+min+1); i++)
		{
			b=0;
			for(int j(y-min); j<(y+min+1); j++)
			{
				N.at(a).at(b)=m.at(i).at(j);
				b++;
			}
			a++;
		}
	}
	
	return N;
}

int main ()
{
	int m, n;
	std::cout<<"Unesite dimenzije matrice (m i n): ";
	std::cin>>m>>n;
	
	if(m<0 || n<0)
	{
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	
	double element;
	Matrica M(KreirajMatricu(m,n));
	std::cout<<"Unesite elemente matrice:";
	for(int i(0); i<M.size(); i++)
	{
		for(int j(0); j<M.at(i).size(); j++)
		{
			std::cin>>element;
			M.at(i).at(j)=element;
		}
	}
	
	
	Matrica N(NajvecaPlaninaMatrice(M));
	
	
	std::cout<<std::endl<<"Najveca planina unesene matrice je:"<<std::endl;
	
	for(int i(0); i<N.size(); i++)
	{
		for(int j(0); j<N.at(0).size(); j++)
		{
			std::cout<<std::right<<std::setw(6)<<N.at(i).at(j);
		}
		std::cout<<std::endl;
	}
	return 0;
}