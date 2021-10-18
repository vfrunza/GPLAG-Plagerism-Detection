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

typedef std::vector <std::vector <double>> Matrica;
Matrica UnesiMatricu (int m, int n)
{
	std::vector <std::vector <double>> mat;
	mat.resize (m);
	for (int i=0; i<mat.size(); i++)
	{
		mat[i].resize (n);
	}
	for (int i=0; i<mat.size (); i++)
	{
		for (int j=0; j<mat[i].size(); j++)
		{
			std::cin>> mat[i][j];
		}
	}
	
	return mat;
}
bool JeLiGrbava (Matrica mat)
{
	for (int i=0; i<mat.size(); i++)
	{
		if (mat[i].size()!=mat[0].size())
		    return true;
	}
	return false;
}

Matrica ObrniKolone (Matrica mat)
{
	for (int i=0; i<mat.size(); i++)
	{
		for (int j=0; j<mat[i].size()/2; j++)
		{
			double temp=mat[i][j];
			mat[i][j]=mat[i][mat[i].size()-1];
			mat[i][mat[i].size()-1]=temp;
		}
	}
	return mat;
}

Matrica ObrniRedove (Matrica mat)
{
	for (int i=0; i<mat.size()/2; i++)
	{
		for (int j=0; j<mat[i].size(); j++)
		{
			double temp=mat[i][j];
			mat[i][j]=mat[mat.size()-1][j];
		    mat[mat.size()-1][j]=temp;
		}
	}
	return mat;
}

Matrica KombinovanoOgledalo (Matrica mat)
{
	return ObrniKolone(ObrniRedove(mat));
}

Matrica OgledaloMatrica (Matrica mat )
{
	if (JeLiGrbava(mat))
	{
		throw std::domain_error("Matrica nije korektna");
	}
	Matrica komb=KombinovanoOgledalo(mat);
	Matrica red=ObrniRedove(mat);
	Matrica kol=ObrniKolone(mat);
	Matrica nova(mat.size());
	nova.resize (3*mat.size());
	for (int i=0; i<nova.size(); i++)
	    nova[i].resize(3*mat[0].size());
	for (int i=0; i<nova.size(); i++)
	    for (int j=0; j<nova[i].size(); j++)
	    {
	    	if ((i>=0 && i<nova.size()/3) && (j>=0 && j<nova[i].size()/3)) 
	    	    nova[i][j]=komb [i][j];
	    	    
	    	else if ((i>=0 && i<nova.size()/3) && (j>=nova[i].size()*2/3 && j<nova[i].size()))
	    	    nova[i][j]=komb [i][j%mat[i].size()];
	    	    
	    	else if ((i>=nova.size()*2/3 && i<nova.size()) && (j>=0 && j<nova[i].size()/3))
	    	    nova[i][j]=komb [i%mat.size()][j];
	    	    
	    	    
	    	else if ((i>=nova.size()*2/3 && i<nova.size()) && (j>=nova[i].size()*2/3 && j<nova[i].size()))
	    	    nova[i][j]=komb [i%mat.size()][j%mat[i%mat.size()].size()];
	    	    
	    	else if ((i>=0 && i<nova.size()/3) && (j>=nova[i].size()/3 && j<nova[i].size()*2/3))
	    	    nova[i][j]=red[i][j%mat[i].size()];
	    	    
	    	else if ((i>=nova.size()*2/3 && i<nova.size()) && (j>=nova[i].size()/3 && j<nova[i].size()*2/3))
	    	    nova[i][j]=red[i%mat.size()][j%mat[i%mat.size()].size()];
	    	    
	    	else if ((i>=nova.size()/3 && i<nova.size()*2/3) && (j>=0 && j<nova[i].size()/3))
	    	    nova[i][j]=kol[i%mat.size()][j];
	    	    
	    	else if ((i>=nova.size()/3 && i<nova.size()*2/3) && (j>=nova[i].size()*2/3 && j<nova[i].size()))
	    	    nova[i][j]=kol[i%mat.size()][j%mat[i%mat.size()].size()];
	    	    
	    	else 
	    	    nova[i][j]=mat[i%mat.size()][j%mat[i%mat.size()].size()];
	    }
	return nova;
}
int main ()
{
	try {
	int m,n;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>m>>n;
	if (m<0  || n<0) { 
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::cout<<"Unesite elemente matrice: ";
	Matrica mat (UnesiMatricu(m,n));
	std::cout<<std::endl;
	std::cout<<"Rezultantna matrica:";
	std::cout<<std::endl;
	mat=OgledaloMatrica (mat);
	for(int i=0; i<mat.size(); i++)
	{
		for (int j=0; j<mat[i].size(); j++)
		{
			std::cout<<std::setw(4) << mat[i][j];
		}
		std::cout<<std::endl;
	}
	}
	catch(std::domain_error grbava) {
		std::cout<<grbava.what();
	}
	return 0;
}