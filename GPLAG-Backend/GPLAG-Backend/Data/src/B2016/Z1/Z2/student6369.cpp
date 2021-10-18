/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include<stdexcept>
#include<iomanip>

typedef std::vector<std::vector<double>> mat;

mat h(mat x)
{
	mat pomocna = x;
	mat rez;
	rez.resize(x.size());
	for(int i(0); i < x.size() ; i++)
	{
		for(int j(0); j < x[0].size(); j++)
		{
			rez[i].push_back(pomocna[i][x[0].size()-j-1]);
		}
	}
	return rez;
}

mat v(mat x)
{
	mat pomocna = x;
	mat rez;
	rez.resize(x.size());
	for(int i(0); i < x.size(); i++)
	{
		for(int j(0); j < x[0].size(); j++)
		{
			rez[i].push_back(pomocna[x.size()-i-1][j]);
		}
	}
	return rez;
}

mat hv(mat x)
{
	mat rez,temp;
	temp = h(x);
	rez = v(temp);
	return rez;
}

mat OgledaloMatrica(mat x)
{
	int m,n;
	m = x.size();
	if( m==0){
		return x;
	}
	n = x[0].size();
	if(m == 0 || n == 0)
	{
		x.resize(3*m);
		for(int i=0;i<x.size();i++)x[i].resize(3*n);
		return x;
	}
		
	for(int i(0); i < x.size();i++)
	{
		if(x[0].size() != x[i].size())
		{
			throw std::domain_error("Matrica nije korektna.");
		}
	}
	mat rez;
	mat hvmat = hv(x);
	mat vmat = v(x);
	mat hmat = h(x);
	
	
	rez.resize(3*m);
	for(int i(0); i<3*m; i++)
	{
		rez[i].resize(3*n);
	}
	for(int i(0); i < 3*m; i++)
	{
		for(int j(0); j < 3*n; j++)
		{
			if(i < m && j < n) rez[i][j] = hvmat[i][j];
			else if(i < m && j > 2*n-1 && j < 3*n) rez[i][j] = hvmat[i][j-2*n];
			else if(i > 2*m-1 && i < 3*m && j < n) rez[i][j] = hvmat[i-2*m][j];
			else if(i > 2*m-1 && i < 3*m && j > 2*n-1 && j < 3*n) rez[i][j] = hvmat[i-2*m][j-2*n];
			else if(i < m && j <= 2*n-1 && j >= n) rez[i][j] = vmat[i][j-n];
			else if(i > 2*m-1 && i < 3*m && j >= n && j <= 2*n-1) rez[i][j] = vmat[i-2*m][j-n];
			else if(i >= m && i <= 2*m-1 && j < n) rez[i][j] = hmat[i-m][j];
			else if(i >= m && i <= 2*m-1 && j > 2*n -1 && j < 3*n) rez[i][j] = hmat[i-m][j-2*n];
			else rez[i][j] = x[i-m][j-n];
		}
	}
	return rez;
}


int main ()
{
	int m,n;
	mat x;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>m>>n;
	if(m<0 || n<0){
		std::cout<<"Dimenzije matrice moraju biti nenegativne!"<<std::endl;
		return 0;
	}
	x.resize(m);
	for(int i(0); i < m; i++) x[i].resize(n);
	std::cout<<"Unesite elemente matrice: ";
	for(int i(0); i < m; i++)
	{
		for(int j(0); j<n; j++)
		{
        	std::cin>>x[i][j];
		}
		
	}
	mat rez;
	
	try{
		rez = OgledaloMatrica(x);
		std::cout<<"\nRezultantna matrica: "<<std::endl;
		for(int i=0;i<rez.size();i++)
		{
    		for(int j=0;j<rez[0].size();j++)
    		{
    			std::cout<<std::setw(4)<<rez[i][j];
			}
		 	std::cout<<std::endl;
    	}
	}
	catch (std::domain_error izuzetak)
	{
		std::cout<<izuzetak.what()<<std::endl;
 		return 0;
	}

	return 0;
}