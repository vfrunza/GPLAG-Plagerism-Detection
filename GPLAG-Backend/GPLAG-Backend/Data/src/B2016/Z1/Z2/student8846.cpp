/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
typedef std::vector<std::vector<double>> Matrica;
Matrica Kombinovana(Matrica m)
{
	Matrica mat(m.size(),std::vector<double>(m[0].size())); //upitno za grbavu?! :(
	for(int i=0;i<m.size();i++)
	{
		for(int j=0;j<m[i].size();j++)
		{
			mat[i][j]=m[m.size()-1-i][m[i].size()-1-j];
		}
	}
	return mat;
}

Matrica Horizontalna(Matrica m)
{
	Matrica mat(m.size(),std::vector<double>(m[0].size()));
	for(int i=0;i<m.size();i++)
	{
		for(int j=0;j<m[i].size();j++)
		{
			mat[i][j]=m[m.size()-1-i][j];
		}
	}
	return mat;
}

Matrica Vertikalna(Matrica m)
{
	Matrica mat(m.size(),std::vector<double>(m[0].size()));
	for(int i=0;i<m.size();i++){
		for(int j=0;j<m[i].size();j++){
		mat[i][j]=m[i][m[i].size()-1-j];
		}
	}
	return mat;
}

Matrica OgledaloMatrica(Matrica m)
{
	bool grbava(false);
	
	/*int p=m[0].size();*/
	for(int i=0;i<m.size();i++)
	{ if(i!=0){
		int p=m[0].size();
			if(m[i].size()!=p) 
			{
				grbava=true;
				break;
			}
	}
	else{
		std::cout<<std::endl;
	}
	}
	bool KolonaManjaOdNule(false);   // :-)
	for(int i=0;i<m.size();i++)
	{
			if (m[i].size()<0) 
			{	
				KolonaManjaOdNule=true;
				break;
			}
	}
	if(grbava || m.size()<0 || KolonaManjaOdNule) throw std::domain_error("Dimenzije matrice moraju biti nenegativne!");
	Matrica hor,ver,komb;
	/*Matrica mat;*/
	Matrica mat1(0, std::vector<double> (0,0));
	Matrica mat(3*m.size(), std::vector<double> (3*m[0].size()));
	if(m.size()!=0){
	/*Matrica mat(3*m.size(), std::vector<double> (3*m[0].size()));*/
	komb=Kombinovana(m);
	hor=Horizontalna(Kombinovana(m));
	ver=Vertikalna(Kombinovana(m));
	int k=m.size();
	int d=m[0].size();
	
	for(int i=0;i<k;i++) //1,1
	{
		for(int j=0;j<d;j++)
		{
			mat[i][j]=komb[i][j];
			
		}
	}
	
	for(int i=k;i<2*k;i++) //1,2
	{
		for(int j=0;j<d;j++)
		{
		mat[i][j]=hor[i-k][j];
		}
	}
	
	for(int i=2*k;i<3*k;i++) //1,3
	{
		for(int j=0;j<d;j++)
		{
			mat[i][j]=komb[i-2*k][j];
		}
	}
	
	
	
	for(int i =0 ;i<k;i++) //2,1
	{
		for(int j=d;j<2*d;j++)
		{
			mat[i][j]=ver[i][j-d];
		
		}
	}
	
	for(int i=k;i<2*k;i++) //2,2
	{
		for(int j=d;j<2*d;j++)
		{
			mat[i][j]=m[i-k][j-d];
			}
	}
	
	for(int i=2*k;i<3*k;i++) //2,3
	{
		for(int j=d;j<2*d;j++)
		{
			mat[i][j]=ver[i-2*k][j-d];
		}
	}
	
	
	
	for(int i =0 ;i<k;i++) //3,1
	{
		for(int j=2*d;j<3*d;j++)
		{
			mat[i][j]=komb[i][j-2*d];
		}
	}
	
	for(int i=k;i<2*k;i++) //3,2
	{
		for(int j=2*d;j<3*d;j++)
		{
			mat[i][j]=hor[i-k][j-2*d];
		}
	}
	
		for(int i=2*k;i<3*k;i++) //3,3
	{
		for(int j=2*d;j<3*d;j++)
		{
			mat[i][j]=komb[i-2*k][j-2*d];
		}
	}
	}

	else if(m.size()==0){
	for(int i=0;i<m.size();++i){
	std::cout<<"m.at(" << i <<")"<<std::endl;
	}
	}
if(m.size()!=0)
	return mat;
	else return mat1;
}

int main ()
{
    int m,n;
   
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>m>>n;
	try
	{
		if(m<0 || n<0) throw std::domain_error("Dimenzije matrice moraju biti nenegativne!");
		Matrica mat(m,std::vector<double> (n));
		std::cout<<"Unesite elemente matrice: ";
		for(int i = 0; i < m; i++) 
		{
	 		for(int j = 0; j<n; j++) 
	 		{
			 std::cin >> mat[i][j];
			}
		}	
		if(n==0 && m==0){
			std::cout<<std::endl;
		std::cout<<"Rezultantna matrica: ";
		}
		else {
		Matrica x=OgledaloMatrica(mat);
		std::cout<<"\n";
		std::cout<<"Rezultantna matrica: "<<std::endl;
	
	
		for(int i=0;i<x.size();i++)
		{
			std::cout<<" ";
			for(int j=0;j<x[0].size();j++)
			{
			
				std::cout<<std::right<<std::setw(3)<<x[i][j]<<" ";
			}
			std::cout<<"\n";
		}
	}
	}
	catch(std::domain_error poruka)
	{
		std::cout<<poruka.what();
	}
	return 0;
}