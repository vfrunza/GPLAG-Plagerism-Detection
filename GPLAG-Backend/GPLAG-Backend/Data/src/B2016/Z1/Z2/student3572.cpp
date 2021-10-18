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
typedef std::vector<std::vector<double>> matrica;


matrica KreirajMatricu(int m, int n)
{if(m!=0)
return matrica(m,std::vector<double>(n));
return matrica (m);
}

matrica HorizontalnaMatrica( matrica a){
    int m=a.size();
    int n;
    if(m!=0) n=a[0].size();
    if(m==0) {matrica b=KreirajMatricu(0,0); return b;}
    
    else {matrica b=KreirajMatricu(m,n);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			b[i][n-j-1]=a[i][j];
		}
	}
    
	return b;}
}
matrica VertikalnaMatrica( matrica a){
    int m=a.size();
    int n;
    if(m!=0) n=a[0].size();
    if(m==0) {matrica b=KreirajMatricu(0,0); return b;}
    else {matrica b=KreirajMatricu(m,n);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			b[m-1-i][j]=a[i][j];
		}
	}
	return b;
}}
matrica HVMatrica( matrica a){
    int m=a.size();
    int n;
    if(m!=0) n=a[0].size();
    if(m==0) {matrica b=KreirajMatricu(0,0); return b;}
    else {matrica b=KreirajMatricu(m,n);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			b[m-1-i][n-1-j]=a[i][j];
		}
	}
	return b;
}}

matrica OgledaloMatrica(matrica a)
{
int m=a.size();
int n;
if(m!=0) n=a[0].size();
for(int i=0; i<m; i++)
{
	if(a[i].size()!=a[0].size()) throw std::domain_error ("Matrica nije korektna");
}
if(m==0){matrica b =KreirajMatricu(0,0);return b;}
else {matrica b= KreirajMatricu(3*m,3*n);
matrica c=HorizontalnaMatrica(a);
matrica d=VertikalnaMatrica(a);
matrica e=HVMatrica(a);
for(int i=0;i<3*m;i++)
{
	for(int j=0;j<3*n;j++)
	{

	if(i<m && j<n)
	{
	   b[i][j]=e[i][j];
	}
	if(i<m && j>=n &&j<2*n)
	{
		b[i][j]=d[i][j-n];
	}
	if(i<m && j>=2*n && j<3*n)
	{
		b[i][j]=e[i][j-2*n];
	}
	if(i>=m && i<2*m && j<n)
	{
	b[i][j]=c[i-m][j];
	}
	if(i>=m && i<2*m&&j>=n&&j<2*n)
	{
	b[i][j]=a[i-m][j-n];
	}
	if((i>=m&&i<2*m)&&(j>=2*n&&j<3*n))
	{
	b[i][j]=c[i-m][j-2*n];
	}
	if((i>=2*m&&i<3*m)&&(j<n))
	{
	b[i][j]=e[i-2*m][j];
	}
	if((i>=2*m&&i<3*m)&&(j>=n&&j<2*n))
	{
	b[i][j]=d[i-2*m][j-n];
	}
    if((i>=2*m&&i<3*m) && (j>=2*n&&j<3*n))
	{
		b[i][j]=e[i-2*m][j-2*n];
	}
	}
	}
return b;}
}


int main ()
{
	try
	{
		int m,n;
		std::cout<<"Unesite dimenzije matrice (m n): ";
		std::cin>>m>>n;
	    if(m<0||n<0) {std::cout<<"Dimenzije matrice moraju biti nenegativne!"; return 0;}
		std::cin.ignore(10000,'\n');
		
		matrica a= KreirajMatricu(m,n);
		std::cout<<"Unesite elemente matrice:"<<std::endl;
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				std::cin>>a[i][j];
			}
		}
	matrica b=OgledaloMatrica(a);
	

	std::cout<<"Rezultantna matrica: "<<std::endl;
	for(int i=0;i<b.size();i++){
		for(int j=0;j<b[0].size();j++){
			std::cout<<std::right<<std::setw(4)<<b[i][j];
		}
		std::cout<<std::endl;
	}
	}
		catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what()<<std::endl; 
	
	}
	
	return 0;
}