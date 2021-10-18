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
using std::vector;

typedef vector<vector<double>> Matrica;

Matrica HorizontalnoOgledalo(Matrica M)
{
	double temp;
	for (int i=0; i<M.size(); i++)
	{
		for (int j=0; j<((M[i].size())/2); j++)
		{
			temp=M[i][j];
			M[i][j]=M[i][(M[i].size())-1-j];
			M[i][(M[i].size())-1-j]=temp;
		}
	}
	return M;
}

Matrica VertikalnoOgledalo(Matrica M)
{
	double temp;
	int m=M.size();
	for (int i=0; i<(m/2); i++)
	{
		for (int j=0; j<M[i].size(); j++)
		{
			temp=M[i][j];
			M[i][j]=M[m-1-i][j];
			M[m-i-1][j]=temp;
		}
	}
	return M;
}

Matrica KombinovanoOgledalo(Matrica M)
{
	double temp;
	int m=M.size();
	for (int i=0; i<m; i++)
	{
		for (int j=0; j<(M[i].size()/2); j++)
		{
			temp=M[i][j];
			M[i][j]=M[i][(M[i].size())-1-j];
			M[i][(M[i].size())-1-j]=temp;
		}
	}
	for (int i=0; i<(m/2); i++)
	{
		for (int j=0; j<M[i].size(); j++)
		{
			temp=M[i][j];
			M[i][j]=M[m-1-i][j];
			M[m-1-i][j]=temp;
		}
	}
	return M;
}

Matrica OgledaloMatrica(Matrica M)
{
	// Ukoliko je primljena matrica formata 0x0
	if (M.size()==0) return Matrica(0, vector<double>(0));
	int m=M.size();
	// Ukoliko je primljena matrica grbava matrica
	for (int i=0; i<m-1; i++)
		for (int j=i+1; j<m; j++)
			if (M[i].size()!=M[j].size()) throw std::domain_error("Matrica nije korektna");
	// Ukoliko je matrica ispravno formatirana
	int n=M[0].size();
	Matrica finalna_matrica(3*m, vector<double>(3*n));
	Matrica hM=HorizontalnoOgledalo(M);
	Matrica vM=VertikalnoOgledalo(M);
	Matrica hvM=KombinovanoOgledalo(M);
	for (int i=0; i<m; i++)
		for (int j=0; j<n; j++)
			finalna_matrica[i][j]=hvM[i][j];
	for (int i=m; i<2*m; i++)
		for (int j=0; j<n; j++)
			finalna_matrica[i][j]=hM[i-m][j];
	for (int i=2*m; i<3*m; i++)
		for (int j=0; j<n; j++)
			finalna_matrica[i][j]=hvM[i-2*m][j];
	for (int i=0; i<m; i++)
		for (int j=n; j<2*n; j++)
			finalna_matrica[i][j]=vM[i][j-n];
	for (int i=2*m; i<3*m; i++)
		for (int j=2*n; j<3*n; j++)
			finalna_matrica[i][j]=hvM[i-2*m][j-2*n];
	for (int i=m; i<2*m; i++)
		for (int j=2*n; j<3*n; j++)
			finalna_matrica[i][j]=hM[i-m][j-2*n];
	for (int i=0; i<m; i++)
		for (int j=2*n; j<3*n; j++)
			finalna_matrica[i][j]=hvM[i][j-2*n];
	for (int i=m; i<2*m; i++)
		for (int j=n; j<2*n; j++)
			finalna_matrica[i][j]=M[i-m][j-n];
	for (int i=2*m; i<3*m; i++)
		for (int j=n; j<2*n; j++)
			finalna_matrica[i][j]=vM[i-2*m][j-n];
	
	return finalna_matrica;
}

int main ()
{
	int m, n;
	cout << "Unesite dimenzije matrice (m n): ";
	cin >> m >> n;
	if (m<0 or n<0) 
	{
		cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	Matrica M(m, vector<double>(n));
	cout << "Unesite elemente matrice:";
	for (int i=0; i<m; i++)
		for (int j=0; j<n; j++)
			cin >> M[i][j];
	try
	{
		M=OgledaloMatrica(M);
		cout << endl;
		cout << "Rezultantna matrica: " << endl;
		for (int i=0; i<M.size(); i++)
		{
			for (int j=0; j<M[0].size(); j++)
			{
				cout << std::setw(4) << M[i][j];
			}
			cout << endl;
		}
	}
	catch (std::domain_error izuzetak)
	{
		cout << izuzetak.what() << std::endl;
	}
	return 0;
}