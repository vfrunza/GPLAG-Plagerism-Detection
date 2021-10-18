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
using std::endl;
using std::vector;

vector<vector <double>> HorizontalnoOgledalo(vector<vector <double>> mat)
{
	vector<vector <double>> temp;
	for(int i=0; i<mat.size(); i++)
	{
		vector<double> kolone;
		for(int j=mat[i].size()-1; j>=0; j--)
		{
			kolone.push_back(mat[i][j]);
		}
		
		temp.push_back(kolone);
	}
	
	return temp;
	
}

vector<vector <double>> VertikalnoOgledalo(vector<vector <double>> mat)
{
	vector<vector <double>> temp;
	for(int i=mat.size()-1; i>=0; i--)
	{	vector<double> vrste;
		for(int j=0; j<mat[i].size(); j++)
		{
			vrste.push_back(mat[i][j]);
			
		}
		temp.push_back(vrste);
	}
	
	return temp;
}


vector<vector <double>> OgledaloMatrica(vector<vector <double>> mat)
{
	if(mat.size()==0) 
	{
		vector<vector <double>> M;
		return M;
	}
	
	else 
	{
	int pokaz(mat[0].size());
	bool isti(true);
	for(int i=0; i<mat.size(); i++)
	{
			if(pokaz!=mat[i].size())
			{
				isti=false;
				break;
			}
	}
	
	if(!isti) throw std::domain_error("Matrica nije korektna");

	
	vector<vector <double>> M;
	
	vector<vector <double>> tempH=HorizontalnoOgledalo(mat);
	vector<vector <double>> tempV=VertikalnoOgledalo(mat);
	vector<vector <double>> tempHV=HorizontalnoOgledalo(VertikalnoOgledalo(mat));
	
	for(int i=0; i<mat.size(); i++)
	{
		vector<double> redovi;
		
		
		for(int j=0; j<tempHV[i].size(); j++)
		{
			redovi.push_back(tempHV[i][j]);
		}
		for(int j=0; j<tempV[i].size(); j++)
		{
			redovi.push_back(tempV[i][j]);
		}
		for(int j=0; j<tempHV[i].size(); j++)
		{
			redovi.push_back(tempHV[i][j]);
		}
		
		
		M.push_back(redovi);
	}
	
	for(int i=0; i<mat.size(); i++)
	{
		vector<double> redovi;
		for(int j=0; j<tempH[i].size(); j++)
		{
			redovi.push_back(tempH[i][j]);
		}
		
		for(int j=0; j<mat[i].size(); j++)
		{
			redovi.push_back(mat[i][j]);
		}
		for(int j=0; j<tempH[i].size(); j++)
		{
			redovi.push_back(tempH[i][j]);
		}
		
		M.push_back(redovi);
	}
	
	for(int i=0; i<mat.size(); i++)
	{
		vector<double> redovi;
		for(int j=0; j<tempHV[i].size(); j++)
		{
			redovi.push_back(tempHV[i][j]);
		}
		for(int j=0; j<tempV[i].size(); j++)
		{
			redovi.push_back(tempV[i][j]);
		}
		for(int j=0; j<tempHV[i].size(); j++)
		{
			redovi.push_back(tempHV[i][j]);
		}
		
		M.push_back(redovi);
	}
	
	
	return M;
	}
}

int main ()
{
	int m, n;
	cout << "Unesite dimenzije matrice (m n): ";
	cin >> m >> n;
	
	if(m<0 || n<0)
	{
		cout << "Dimenzije matrice moraju biti nenegativne! ";
		return 0;
	}
	
	vector<vector <double>> mat(m, vector<double> (n));
	
	cout << "Unesite elemente matrice: ";
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin>> mat[i][j];
		}
	}
	
	try
	{
		vector<vector <double>> M(OgledaloMatrica(mat));
		cout << endl<< "Rezultantna matrica: " << endl;
		for(int i=0; i<M.size(); i++)
		{
			for(int j=0; j<M[i].size(); j++)
			{
				if(j==0) cout << std::setw(4)<< M[i][j] << " ";
				else cout << std::setw(3) << M[i][j] << " ";
			}
			
			cout << endl;
		}
	}
	catch(std::domain_error poruka)
	{
		cout << poruka.what() << endl;
	}
	
	return 0;
}