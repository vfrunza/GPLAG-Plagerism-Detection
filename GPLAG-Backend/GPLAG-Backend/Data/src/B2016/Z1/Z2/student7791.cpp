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
using std::cout;
using std::cin;
using std::vector;
vector<vector<double>> OgledaloMatrica(vector<vector<double>> M)
{
int redova(M.size());
int kolona;
if(redova) //ako nema nijedan red,sigurno nema ni kolonu te ne smijemo pristupiti M[0] da bi dobili broj kolona
{
	kolona=M[0].size();
	for(int i=0;i<redova;i++)
	for(int j=0;j<M[i].size();j++)
	{
	if(M[i].size()!=kolona) throw std::domain_error("Matrica nije korektna");
	}
}
else
kolona=0;
vector<vector<double>> h(M.size(),vector<double>(kolona));
vector<vector<double>> v(M.size(),vector<double>(kolona));
vector<vector<double>> hv(M.size(),vector<double>(kolona));
for(int i=0;i<redova;i++)
{
	for(int j=0;j<kolona;j++)
	{
		h[i][j]=M[i][(kolona-1)-j];
	}
}
for(int j=0;j<kolona;j++)
{
	for(int i=0;i<redova;i++)
	{
		v[i][j]=M[(redova-1)-i][j];
	}
}
for(int i=0;i<redova;i++)
{
	for(int j=0;j<kolona;j++)
	{
		hv[i][j]=v[i][(kolona-1)-j];
	}
}
vector<vector<double>> M1(3*redova,vector<double>(3*kolona));
for(int i=0;i<3*redova;i++)
{
	for(int j=0;j<3*kolona;j++)
	{
		if((i<redova && j<kolona))
		M1[i][j]=hv[i][j];
		if((i<redova && j>=2*kolona))
		M1[i][j]=hv[i][j-2*kolona];
		if((i>=2*redova && j<kolona))
		M1[i][j]=hv[i-2*redova][j];
		if((i>=2*redova && j>=2*kolona))
		M1[i][j]=hv[i-2*redova][j-2*kolona];
		if((i<redova && j>=kolona && j<2*kolona))
		M1[i][j]=v[i][j-kolona];
		if((i>=2*redova && j>=kolona && j<2*kolona))
		M1[i][j]=v[i-2*redova][j-kolona];
		if((i>=redova && i<2*redova && j<kolona))
		M1[i][j]=h[i-redova][j];
		if(i>=redova && i<2*redova && j>=2*kolona)
		M1[i][j]=h[i-redova][j-2*kolona];
		if((i>=redova && i<2*redova && j>=kolona && j<2*kolona))
		M1[i][j]=M[i-redova][j-kolona];
	}
}
return M1;
}
int main ()
{
int m,n;
cout<<"Unesite dimenzije matrice (m n): ";
cin>>m>>n;
if(m<0 || n<0)
{
	cout<<"Dimenzije matrice moraju biti nenegativne!";
	return 0;
}
vector<vector<double>> Mat(m,vector<double>(n));
double broj;
cout<<"Unesite elemente matrice: ";
for(int i=0;i<m;i++)
{
for(int j=0;j<n;j++)
{
	cin>>broj;
	Mat[i][j]=broj;
}
}
try
{
Mat=OgledaloMatrica(Mat);
}
catch(std::domain_error izuzetak)
{
	cout<<izuzetak.what()<<std::endl;
}
cout<<std::endl<<"Rezultantna matrica: "<<std::endl;
for(int i=0;i<Mat.size();i++)
{
for(int j=0;j<Mat[0].size();j++)
{
	cout<<std::setw(4)<<Mat[i][j];
}
cout<<std::endl;
}
	return 0;
}