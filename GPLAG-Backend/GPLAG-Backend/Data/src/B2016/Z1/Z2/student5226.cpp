/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include<stdexcept>

typedef std::vector<std::vector<double>> Matrica;

Matrica KreirajMatricu(int broj_redova, int broj_kolona) {
	return Matrica(broj_redova,std::vector<double> (broj_kolona));
}



Matrica OgledaloMatrica (Matrica mat)
{
	int i,j;
    Matrica m; 

	if(mat.size()==0 || mat[0].size()==0) {
		return m;
	
	}
	for(i=0;i<mat.size();i++)
	{
		if(mat[i].size()!=mat[i+1].size()) throw std::domain_error("Matrica nije korektna");
	}
	for(i=0;i<m.size();i++)
	{
		
		for(j=0;j<m[i].size();j++)
		{
			int a=mat.size(), b=mat[i].size();
		    if(i<a && j<b)
		    {
		    	//hv
		    	m[i][j]=mat[a-i][b-j];
		    }
		    else if(i<a && j>=b && j<2*b)
		    {
		    	//v
		    	
		    	m[i][j]=mat[a-i][j-b];
		    }
		    else if(i<a && j>=2*b && j<3*b)
		    {
		    	//hv
		    	
		    	m[i][j]=mat[a-i][3*b-j];
		    	
		    }
		    else if(j<b && i>=a && i<2*a)
		    {
		    	//h
		    	m[i][j]=mat[i-a][b-j];
		    }
		    else if(j<b && i>=2*a && i<3*a)
		    {
		    	//hv
		    	m[i][j]=mat[3*a-i][b-j];
		    }
		    else if(i>=a && i<2*a && j>=b && j<2*b)
		    {
		    	//ob
		    	m[i][j]=mat[i-a][j-b];
		    }
		    else if(i>=a && i<2*a && j>=2*b && j<3*b)
		    {
		    	//h
		    	m[i][j]=mat[i-a][3*b-j];
		    }
		    else if(i>=2*a && i<3*a && j>=b && j<2*b)
		    {
		    	//v
		    	m[i][j]=mat[3*a-i][j-b];
		    }
		    else if(i>=2*a && i<3*a && j>=2*b && j<3*b){
		    	//hv
		    	m[i][j]=mat[3*a-i][3*b-j];
		    }
		}
	}
	
	
	return m;

}


int main ()
{
	int i,j,m,n; 

	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>m>>n;
	if(m<0 || n<0) std::cout<<"Dimenzije matrice moraju biti nenegativne!";
	else if(m==0 || n==0) {
		Matrica mat(KreirajMatricu(m,n));
		std::cout<<"Unesite elemente matrice: ";
		Matrica mat1;
		mat1=OgledaloMatrica(mat);
		std::cout<<"Rezultantna matrica: ";
	}
	else {

	
	std::cout<<"Unesite elemente matrice: ";
	try {
		
		
		Matrica mat(KreirajMatricu(m,n)),mat1;
		
		for(i=0;i<mat.size();i++)
		{
			
			for(j=0;j<mat[i].size();j++)
			{
				std::cin>>mat[i][j];
			}
		}
		
		mat1=OgledaloMatrica(mat);
		std::cout<<std::endl;
		std::cout<<"Rezultantna matrica: \n";
		for(i=0;i<3*mat.size();i++)
		{
			for(j=0;j<3*mat[i].size();j++)
			{
				std::cout<<mat1[i][j]<<" ";
			}
			std::cout<<std::endl;
		}
		
	}
	
	catch (std::domain_error izuzetak)
	{
		std::cout<<izuzetak.what()<<std::endl;
	}
	}
	return 0;
}