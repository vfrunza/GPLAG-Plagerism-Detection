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

using namespace std;

typedef vector<vector<double>> Matrica;

Matrica KreirajMatricu(int brojredova,int brojkolona)
{
	return Matrica(brojredova,vector<double>(brojkolona));
}

Matrica H(Matrica a)
{	double pomocna;

	for(int i=0;i<a.size();i++)
	{
		for(int j=0;j<a[i].size()/2;j++)
		{
			pomocna=a[i][j];
			a[i][j]=a[i][a[i].size()-1-j];
			a[i][a[i].size()-1-j]=pomocna;
			
			
		}
	}
	return a;
}

Matrica V(Matrica a)
{
	double pomocna;
	for(int i=0;i<a.size()/2;i++)
	{
		for(int j=0;j<a[i].size();j++)
		{
			pomocna=a[i][j];
			a[i][j]=a[a.size()-1-i][j];
			a[a.size()-1-i][j]=pomocna;
		}
	}
	return a;
}

Matrica K(Matrica a)
{	
	Matrica k=V(a);
	k=H(k);
	return k;
}


Matrica OgledaloMatrica(Matrica m)
{	
	Matrica vertikalna, horizontalna, kombinovana, rezultantna;
	if(m.size()==0)return rezultantna;
	int broj=m[0].size();
	for(int i=0;i<m.size();i++)
	{
	if (m[i].size()!=broj)
	throw domain_error("Matrica nije korektna");
	}
	

	int r(m.size()),k(m[0].size());
	rezultantna=KreirajMatricu(3*m.size(),3*m[0].size());
	horizontalna=KreirajMatricu(m.size(),m[0].size());
	vertikalna=KreirajMatricu(m.size(),m[0].size());
	kombinovana=KreirajMatricu(m.size(),m[0].size());
	horizontalna=H(m);
	vertikalna=V(m);
	kombinovana=K(m);
	for(int i=0;i<3*m.size();i++)
	{
		for(int j=0;j<3*m[0].size();j++)
		{
			if(i<r && j<k) rezultantna[i][j]=kombinovana[i][j]; 
        else if(i<r && j>=k && j<2*k) rezultantna[i][j]=vertikalna[i][j-k];
        else if(i<r && j>=2*k ) rezultantna[i][j]=kombinovana[i][j-2*k];
        else if(i>=r && i<2*r && j<k) rezultantna[i][j]=horizontalna[i-r][j];
        else if(i>=r && i<2*r && j>=k && j<2*k) rezultantna[i][j]=m[i-r][j-k];
        else if(i>=r && i<2*r && j>=2*k) rezultantna[i][j]=horizontalna[i-r][j-2*k];
        else if(i>=2*r && j<k) rezultantna[i][j]=kombinovana[i-2*r][j];
        else if(i>=2*r && j>=k && j<2*k) rezultantna[i][j]=vertikalna[i-2*r][j-k];
        else if(i>=2*r && j>=2*k) rezultantna[i][j]=kombinovana[i-2*r][j-2*k];
		}
	}
	return rezultantna;
}

int main ()
{
	int m,n; 
	double a; 
	cout<<"Unesite dimenzije matrice (m n): ";
	cin>>m>>n;
	if(m<0 || n<0){
		cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	Matrica mat=KreirajMatricu(m,n);
	cout<<"Unesite elemente matrice: ";
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a;
			mat[i][j]=a; 
		}
	}
	try
	{
		Matrica rezmat=OgledaloMatrica(mat);
	cout << endl;
	cout<<"Rezultantna matrica: "<<endl;
	for(int i=0;i<rezmat.size();i++)
	{
		for(int j=0;j<rezmat[i].size();j++)
		{
			cout<<setw(4)<<rezmat[i][j];
			
		}
		cout<<endl;
	}}
	catch(domain_error izuzetak)
	{
		cout<<izuzetak.what()<<endl;
	}
	return 0;
}