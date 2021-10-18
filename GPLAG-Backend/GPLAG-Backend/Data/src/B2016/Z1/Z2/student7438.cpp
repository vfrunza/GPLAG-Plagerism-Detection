/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iomanip>
#include<iostream>
#include<vector>
#include<stdexcept>
using std::cout;
using std::cin;
using std::vector;
vector<vector<double>> vM(vector<vector<double>> a)
{
	vector<double> prazan;
	for(int i=0;i<(a.size()-1)/2.;i++)
	{
		prazan=a[i];
		a[i]=a[a.size()-1-i];
		a[a.size()-1-i]=prazan;
	}
	return a;
}
vector<vector<double>> hM(vector<vector<double>> a)
{
	double temp;
	for(int i=0;i<a.size();i++)
	{
		for(int j=0;j<(a[0].size()-1)/2.;j++)
		{
			temp=a[i][j];
			a[i][j]=a[i][a[0].size()-1-j];
			a[i][a[0].size()-1-j]=temp;
		}
	}
	return a;
}
vector<vector<double>> hvM(vector<vector<double>> a)
{
	a=hM(vM(a));
	return a;
}
vector<vector<double>> OgledaloMatrica(vector<vector<double>> a)
{
	/*Provjera korektnosti matrice*/
	if(a.size()>0)
	{
		for(int i=0;i<a.size();i++)
		{
			if(a[i].size()!=a[0].size())
			throw std::domain_error("Matrica nije korektna");
		}
	}
	vector<double> prazan;
	vector<vector<double>> b;
	for(int i=0;i<3*a.size();i++)
	{
		b.push_back(prazan);
		for(int j=0;j<3*a[0].size();j++)
		{
			if(i<a.size())    /*gornja trecina matrice*/
			{
				if(j<a[0].size())
				{
					b[i].push_back(hvM(a)[i][j]);
				}
				else if(j<2*a[0].size())
				{
					b[i].push_back(vM(a)[i][j-a[0].size()]);
				}
				else
				{
					b[i].push_back(hvM(a)[i][j-2*a[0].size()]);
				}
			}
			else if(i<2*a.size())   /*srednja trecina matrice*/
			{
				if(j<a[0].size())
				{
					b[i].push_back(hM(a)[i-a.size()][j]);
				}
				else if(j<2*a[0].size())
				{
					b[i].push_back(a[i-a.size()][j-a[0].size()]);
				}
				else
				{
					b[i].push_back(hM(a)[i-a.size()][j-2*a[0].size()]);
				}
			}
			else   /*donja trecina matrice*/
			{
				if(j<a[0].size())
				{
					b[i].push_back(hvM(a)[i-2*a.size()][j]);
				}
				else if(j<2*a[0].size())
				{
					b[i].push_back(vM(a)[i-2*a.size()][j-a[0].size()]);
				}
				else
				{
					b[i].push_back(hvM(a)[i-2*a.size()][j-2*a[0].size()]);
				}
			}
		}
	}
	return b;
}
int main ()
{   
	double x;
	int m,n;
	cout<<"Unesite dimenzije matrice (m n): ";
	cin>>m>>n;
	if(m<0 || n<0)
	cout<<"Dimenzije matrice moraju biti nenegativne!";
	else
	{
		vector<vector<double>> a(m);
		cout<<"Unesite elemente matrice: \n";
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>x;
				a[i].push_back(x);
			}
		}
		try
		{
		cout<<"Rezultantna matrica: \n";
		for(int i=0;i<3*m;i++)
		{
			for(int j=0;j<3*n;j++)
			{
				cout<<std::setw(4)<<OgledaloMatrica(a)[i][j];
			}
			cout<<"\n";
		}
		}
		catch(std::domain_error izuzetak)
		{
			cout<<izuzetak.what()<<"\n";
		}
	}
	
	return 0;
}










