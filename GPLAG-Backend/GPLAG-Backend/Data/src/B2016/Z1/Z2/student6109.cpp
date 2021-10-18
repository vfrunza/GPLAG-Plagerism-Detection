/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

typedef std::vector<std::vector<double>> Matrica;

Matrica KreirajMatricu(int br_redova, int br_kolona)
{
	return Matrica(br_redova, std::vector<double>(br_kolona));
}

Matrica UnesiMatricu(int br_redova, int br_kolona)
{
	Matrica M(KreirajMatricu(br_redova, br_kolona));
	std::cout<<"Unesite elemente matrice: ";
	for(int i=0;i<br_redova;i++)
	{
		for(int j=0;j<br_kolona;j++)
		{
			std::cin>>M[i][j];
		}
	}
	return M;
}

Matrica OgledaloMatrica(Matrica M)
{
	if(M.size()==0) return M;
	
	Matrica v(KreirajMatricu(M.size(), M[0].size())); 
	Matrica h(KreirajMatricu(M.size(), M[0].size()));
	Matrica hv(KreirajMatricu(M.size(), M[0].size()));
	Matrica Konacna(KreirajMatricu(M.size()*3, M[0].size()*3));
	
	
	
	for(int i=M.size()-1;i>=0;i--)
	{
		for(int j=0;j<M[i].size();j++)
		{
			v[M.size()-1-i][j]=M[i][j];
		}
	}
	
	for(int i=0;i<M.size();i++)
	{
		for(int j=M[i].size()-1;j>=0;j--)
		{
			h[i][M[0].size()-1-j]=M[i][j];
		}
	}
	
	for(int i=M.size()-1;i>=0;i--)
	{
		for(int j=M[i].size()-1;j>=0;j--)
		{
			hv[M.size()-1-i][M[0].size()-1-j]=M[i][j];
		}
	}
	
	for(int i=0;i<Konacna.size();i++)
	{
		for(int j=0;j<Konacna[0].size();j++)
		{
			if(i>=0 && i<M.size())
			{
				if(j>=0 && j<M[0].size()) Konacna[i][j]=hv[i][j];
				else if(j>=M[0].size() && j<M[0].size()*2) Konacna[i][j]=v[i][j-M[0].size()];
				else Konacna[i][j]=hv[i][j-M[0].size()*2];
			}
			else if(i>=M.size() && i<M.size()*2)
			{
				if(j>=0 && j<M[0].size()) Konacna[i][j]=h[i-M.size()][j];
				else if(j>=M[0].size() && j<M[0].size()*2) Konacna[i][j]=M[i-M.size()][j-M[0].size()];
				else Konacna[i][j]=h[i-M.size()][j-M[0].size()*2];
			}
			else
			{
				if(j>=0 && j<M[0].size()) Konacna[i][j]=hv[i-M.size()*2][j];
				else if(j>=M[0].size() && j<M[0].size()*2) Konacna[i][j]=v[i-M.size()*2][j-M[0].size()];
				else Konacna[i][j]=hv[i-M.size()*2][j-M[0].size()*2];
			}
		}
	}
	return Konacna;
}

int main ()
{
	int m,r;
	
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>m>>r;
	if(m<0 || r<0)
	{
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	Matrica M(UnesiMatricu(m,r));
	Matrica n(OgledaloMatrica(M));
	std::cout<<std::endl;
	std::cout<<"Rezultantna matrica: "<<std::endl;
	for(int i=0;i<n.size();i++)
	{
		for(int j=0;j<n[i].size();j++)
		{
			if(j==0) std::cout<<std::setw(4)<<n[i][j]<<" ";
			else std::cout<<std::setw(3)<<n[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	return 0;
}