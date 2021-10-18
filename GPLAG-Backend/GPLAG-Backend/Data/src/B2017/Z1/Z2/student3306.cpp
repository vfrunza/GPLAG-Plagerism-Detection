/*B 2017/2018, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::setw;
typedef  vector<vector <double>> Matrica;
Matrica KreirajMatricu (int br_redova, int br_kolona)
{
	return Matrica (br_redova, vector<double> (br_kolona));
}
int BrojRedova (Matrica m)
{
	return m.size();
}
int BrojKolona (Matrica m)
{
	return m[0].size();
}

Matrica NajvecaPlaninaMatrice (Matrica m)
{
	if (BrojKolona(m)==0 ||BrojRedova(m)==0)
	return Matrica (0, vector<double>(0));
	
	Matrica m1;
	int k;
	int npmax=0, ip=0, jp=0, ipmax=0, jpmax=0, np=0;
	int minsuma=0;
	for (int i=1; i<BrojRedova(m)-1; i++)
	{
		for (int j=1; j<BrojKolona(m)-1; j++)
		{
			k=1;
			int suma(m[i][j]);
			while (k<=i && k<=j && k<BrojRedova(m)-j && k<BrojKolona(m)-i)
			{
			for (int p=j-k; p<j+k; p++)
			{
				minsuma=minsuma+m[i-k][p];
				minsuma=minsuma+m[i+k][p];
			}
			for (int q=i-k+1; q<i+k; q++)
			{
				minsuma=minsuma+m[q][j-k];
				minsuma=minsuma+m[q][j+k];
			}
			if (minsuma<suma)
			{
				suma=minsuma;
				minsuma=0;
				ip=i;
				jp=j;
				np=2*k+1;
				k++;
			}
			else
			{
				minsuma=0;
				break;
			}
		    }
		
		if (np>npmax)
		{
			npmax=np;
			ipmax=ip;
			jpmax=jp;
		}
		if (np==npmax && m[ip][jp]>m[ipmax][jpmax])
		{
			ipmax=ip;
			jpmax=jp;
		}
		if (np==npmax && m[ip][jp]==m[ipmax][jpmax] && ip<ipmax)
		{
			ipmax=ip;
			jpmax=jp;
		}
		if (np==npmax && m[ip][jp]==m[ipmax][jpmax] && ip==ipmax && jp<jpmax)
		{
			ipmax=ip;
			jpmax=jp;
		}
		
	}
	}
	
	m1=KreirajMatricu(npmax, npmax);
	int a(0);
	k=(npmax-1)/2;
	while (a<npmax)
	{
		for (int c=ipmax-k; c<=ipmax+k; c++)
		{
			int b;
			b=0;
			while (b<npmax)
			{
				for (int d=jpmax-k; d<=jpmax+k; d++)
				{
					m1[a][b]=m[c][d];
					b++;
				}
			}
			a++;
		}
	}
	return m1;
}




int main ()
{
	
	cout<<"Unesite dimenzije matrice (m i n): ";
	int br_redova, br_kolona;
	do
	{
	 cin>>br_redova>>br_kolona;
	 cout<<"Dimenzije matrice moraju biti nenegativne!";
	}
	while (br_redova<0 || br_kolona<0)
	Matrica m;
	cout<<"Unesite elemente matrice: ";
	m=KreirajMatricu(br_redova, br_kolona);
	
	for (int i=0; i<br_redova; i++)
	{
		for (int j=0; j<br_kolona; j++)
		{
			cin>>m[i][j];
		}
	}
	cout<<endl;
	
	cout<<"Najveca planina unesene matrice je: "<<endl;
	Matrica m2;
	m2=NajvecaPlaninaMatrice(m);
	for (int i=0; i<BrojRedova(m2); i++)
	{
		for (int j=0; j<BrojKolona(m2); j++)
		{
			cout<<setw(6)<<m2[i][j];
		}
		cout<<endl;
	}
	
	return 0;
}