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
using std::endl;
using std::setw;
using std::vector;
using std::domain_error;

vector<vector<double>> OgledaloMatrica(vector<vector<double>> matrica)
{
   unsigned int n,m;
   int k,g;
   double temp;
   vector<vector<double>> h;
   vector<vector<double>> v;
   vector<vector<double>> hv;
   vector<vector<double>> empty;
   
   if (matrica.size()==0)
   {
   	return empty;
   }
   
   h=matrica;
   n=h[0].size();
   for (int i=0; i<h.size(); i++)
	{
		for (int j=0; j<h[0].size()/2; j++)
		{
			temp=h[i][j];
			h[i][j]=h[i][n-1-j];
			h[i][n-1-j]=temp;
		}
	}
   
   v=matrica;
   n=v.size();
   for (int i=0; i<v.size()/2; i++)
	{
		for (int j=0; j<v[0].size(); j++)
		{
			temp=v[i][j];
			v[i][j]=v[n-1-i][j];
			v[n-1-i][j]=temp;
		}
	}
   
   hv=matrica;
   n=hv[0].size();
   m=hv.size();
   for (int i=0; i<hv.size(); i++)
	{
		for (int j=0; j<hv[0].size()/2; j++)
		{
			temp=hv[i][j];
			hv[i][j]=hv[i][n-1-j];
			hv[i][n-1-j]=temp;
		}
	}
   
   for (int i=0; i<hv.size()/2; i++)
	{
		for (int j=0; j<hv[0].size(); j++)
		{
			temp=hv[i][j];
			hv[i][j]=hv[m-1-i][j];
			hv[m-1-i][j]=temp;
		}
	}
   
   m=hv.size();
   n=hv[0].size();
   k=3*m;
   g=3*n;
   int t;
   int l;
   vector<vector<double>> final(k,vector<double>(g));
   l=0;
   while (l<3)
   {
   	for (int i=l*(k/3); i<(l+1)*(k/3); i++)
   	{
   	  t=0;
	  while (t<3)
	  {
		if ((t==0||t==2)&&l==0)
		{
			for (int j=t*(g/3); j<(t+1)*(g/3); j++)
			{
				final[i][j]=hv[i-l*(k/3)][j-t*(g/3)];
			}
		}
		
		if (t==1&&l==0)
		{
			for (int j=t*(g/3); j<(t+1)*(g/3); j++)
			{
				final[i][j]=v[i-l*(k/3)][j-t*(g/3)];
			}
		}
		if ((t==0||t==2)&&l==1)
		{
			for (int j=t*(g/3); j<(t+1)*(g/3); j++)
			{
				final[i][j]=h[i-l*(k/3)][j-t*(g/3)];
			}
		}
		
		if (t==1&&l==1)
		{
			for (int j=t*(g/3); j<(t+1)*(g/3); j++)
			{
				final[i][j]=matrica[i-l*(k/3)][j-t*(g/3)];
			}
		}
		
		if ((t==0||t==2)&&l==2)
		{
			for (int j=t*(g/3); j<(t+1)*(g/3); j++)
			{
				final[i][j]=hv[i-l*(k/3)][j-t*(g/3)];
			}
		}
		
		if (t==1&&l==2)
		{
			for (int j=t*(g/3); j<(t+1)*(g/3); j++)
			{
				final[i][j]=v[i-l*(k/3)][j-t*(g/3)];
			}
		}
		
		t++;
	  }
   	}
   	l++;
   }
	
   return final;
}

int main ()
{
	int m,n,g,k;
	double temp;
	vector<vector<double>> rezultat;
	try
	{
		cout<<"Unesite dimenzije matrice (m n): ";
		cin>>m>>n;
		
		if (m<0||n<0) 
		{
			cout<<"Dimenzije matrice moraju biti nenegativne!";
			return 0;
		}
		
		vector<vector<double>> matrica(m,vector<double>(n));
	
		cout<<"Unesite elemente matrice: ";
		for (int i=0; i<m; i++)
		{
			for (int j=0; j<n; j++)
			{
				cin>>temp;
				matrica[i][j]=temp;
			}
		}
		cout<<endl;
		
		for (int k=0; k<m; k++)
		{
			if (matrica[0].size()!=matrica[k].size()) throw domain_error("Matrica nije korektna");
		}
	
		rezultat=OgledaloMatrica(matrica);

		cout<<"Rezultantna matrica: "<<endl;
		g=3*m;
		k=3*n;
	
		for (int i=0; i<g; i++)
		{
			for (int j=0; j<k; j++)
			{
				cout<<setw(4)<<rezultat[i][j];
			}
			cout<<endl;
		}

	}
	
	catch (domain_error izuzetakvelicina)
	{
		cout<<izuzetakvelicina.what()<<endl;
	}
	
	return 0;
}