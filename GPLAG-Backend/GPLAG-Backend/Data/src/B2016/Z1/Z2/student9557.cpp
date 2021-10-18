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
#include <iomanip>

std::vector<std::vector<double>> KreirajMatricu(int m,int n)
{
    return std::vector<std::vector<double>>(m,std::vector<double>(n));
}

std::vector<std::vector<double>> UnesiMatricu(int m,int n)
{
    std::vector<std::vector<double>> mat (KreirajMatricu(m,n));
    for(int i(0);i<m;i++)
     for(int j(0);j<n;j++)
     {
         std::cin>>mat[i][j];
     }
     return mat;
}


std::vector<std::vector<double>> horiz(std::vector<std::vector<double>> m){
	double temp;
	
	for(int i=0;i<m.size();i++){
	
		for(int j=0;j<m[i].size()/2;j++){
				temp=m[i][j];
		     	m[i][j]=m[i][m[i].size()-1-j];
				m[i][m[i].size()-1-j]=temp;
				
			
		}
	}
	return m;
	
}

std::vector<std::vector<double>> vert(std::vector<std::vector<double>> m){
	
	double temp;
	for(int j=0; j<m[0].size();j++){
		for(int i=0;i<m.size()/2;i++){
			temp=m[i][j];
			m[i][j]=m[m.size()-1-i][j];
			m[m.size()-1-i][j]=temp;
		}
	}
	
	return m;
}

std::vector<std::vector<double>> verhor(std::vector<std::vector<double>> m){
	std::vector<std::vector<double>> c;
	c=vert(horiz(m));
	
	
	return c;
	
}

std::vector<std::vector<double>> OgledaloMatrica(std::vector<std::vector<double>> m){
	if(m.size()==0) return m;
	
	for(int i=1;i<m.size();i++){
		if (m[i].size()<m[0].size() ||m[0].size()<m[i].size()) throw std::domain_error("Matrica nije korektna");
	}
	
	std::vector<std::vector<double>> v;
    std::vector<std::vector<double>> h;
	std::vector<std::vector<double>> hv;  
	
	v=vert(m);
	h=horiz(m);
	hv=verhor(m);
	
	int red=m.size();
	int kolona=m[0].size();
	
	std::vector<std::vector<double>> mat;
	mat.resize(m.size()*3);
	for(int k=0;k<mat.size();k++){
		mat[k].resize(m[k/3].size()*3);
	}
	for(int i=0;i<red;i++)
	{
		for (int j=0;j<kolona;j++)
		{
			mat[i][j]=hv[i][j];
			mat[2*red+i][j]=hv[i][j];
			mat[i][kolona*2+j]=hv[i][j];
			mat[red*2+i][2*kolona+j]=hv[i][j];
		}
	}
	
	for(int i=0;i<red;i++)
	{
		for (int j=0;j<kolona;j++)
		{
			mat[i][j+kolona]=v[i][j];
			mat[2*red+i][j+kolona]=v[i][j];
		}
	}
	for(int i=0;i<red;i++)
	{
		for (int j=0;j<kolona;j++)
		{
			mat[i+red][j]=h[i][j];
			mat[i+red][j+kolona*2]=h[i][j];
		}
	}
	for(int i=0;i<red;i++)
	{
		for (int j=0;j<kolona;j++)
		{
			mat[i+red][j+kolona]=m[i][j];
			
		}
	}
	
	return mat;
}
	
int main ()
{
	try {
	std::cout<<"Unesite dimenzije matrice (m n): ";
    int m,n;
    std::cin>>m>>n;
    if(m<0 || n<0) { std::cout<<"Dimenzije matrice moraju biti nenegativne!"; return 0;}
    else {
    std::cout<<"Unesite elemente matrice: "<<std::endl;
    std::vector<std::vector<double>> B;
    B=(UnesiMatricu(m,n));
    
    
 
     std::vector<std::vector<double>> C;
     C=OgledaloMatrica(B);
    std::cout<<"Rezultantna matrica:"<<std::endl;
	for(int i=0;i<C.size();i++){
		for(int j=0;j<C[i].size();j++){
			std::cout<<std::right<<std::setw(4)<<C[i][j];
		}
		std::cout << std::endl;
	}
    }
	}
    
    catch(std::domain_error izuzetak){
    	std::cout<<izuzetak.what()<<std::endl;
    }
    
    
	return 0;

}