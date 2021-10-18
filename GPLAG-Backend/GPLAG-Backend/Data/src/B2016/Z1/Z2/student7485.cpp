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

using std::cout;
using std::cin;
using std::vector;

typedef vector<vector<double>> Matrica;



Matrica OgledaloMatrica(Matrica mat){
	
	Matrica vracaj_matricu;
	vracaj_matricu.resize(3*mat.size());
	
	if (mat.size()==0) return mat;
	
			for(int i=0;i<mat.size()-1;i++)
			{
				if (mat[i].size()!=mat[i+1].size())
					throw std::domain_error("Matrica nije korektna");
				}
	int k;
	k=0;
	for(int i=mat.size()-1;i>=0;i--)
	{
		for(int j=mat[i].size()-1;j>=0;j--)
		{
			vracaj_matricu[k].push_back(mat[i][j]);
		}
		k++;
	}
	k=0;
	for(int i=mat.size()-1;i>=0;i--)
	{
		for(int j=0;j<mat[i].size();j++)
		{
			vracaj_matricu[k].push_back(mat[i][j]);
		}
		k++;
	}
	k=0;
	for(int i=mat.size()-1;i>=0;i--)
	{
		for(int j=mat[i].size()-1;j>=0;j--)
		{
			vracaj_matricu[k].push_back(mat[i][j]);
		}
		k++;
	}
	
	k=mat.size();
	for(int i=0;i<mat.size();i++)
	{
		for(int j=mat[i].size()-1;j>=0;j--)
		{
			vracaj_matricu[k].push_back(mat[i][j]);
		}
		k++;
	}
	k=mat.size();
	for(int i=0;i<mat.size();i++)
	{
		for(int j=0;j<mat[i].size();j++)
		{
			vracaj_matricu[k].push_back(mat[i][j]);
		}
		k++;
	}
	k=mat.size();
	for(int i=0;i<mat.size();i++)
	{
		for(int j=mat[i].size()-1;j>=0;j--)
		{
			vracaj_matricu[k].push_back(mat[i][j]);
		}
		k++;
	}
	k=2*mat.size();
	for(int i=mat.size()-1;i>=0;i--)
	{
		for(int j=mat[i].size()-1;j>=0;j--)
		{
			vracaj_matricu[k].push_back(mat[i][j]);
		}
		k++;
	}
	k=2*mat.size();
	for(int i=mat.size()-1;i>=0;i--)
	{
		for(int j=0;j<mat[i].size();j++)
		{
			vracaj_matricu[k].push_back(mat[i][j]);
		}
		k++;
	}
	k=2*mat.size();
	for(int i=mat.size()-1;i>=0;i--)
	{
		for(int j=mat[i].size()-1;j>=0;j--)
		{
			vracaj_matricu[k].push_back(mat[i][j]);
		}
		k++;
	}
		return vracaj_matricu;
	}


int main ()
{
	Matrica mat;
	Matrica matrica;
	int m,n;
	cout<<"Unesite dimenzije matrice (m n): ";
	cin>>m>>n;
	if (m<0 || n<0)
		{
			cout<<"Dimenzije matrice moraju biti nenegativne!";
			return 0;
		}	
	mat.resize(m);
	cout<<"Unesite elemente matrice: ";
	cout<<"\n";

	for(int i=0;i<mat.size();i++)
	{
		for(int j=0;j<n;j++)
		{
			double broj;
			cin>>broj;
			mat[i].push_back(broj);
		}
	}
	cout<<"Rezultantna matrica: ";
	try{
	matrica=OgledaloMatrica(mat);
	cout<<"\n";
		for(vector<double>x:matrica)
		{
			for(double y:x)
				cout<<std::setw(4)<<y;
				cout<<"\n";
		}
	}
	catch(std::domain_error izuzetak){
		cout<<izuzetak.what();
	}

	return 0;
}