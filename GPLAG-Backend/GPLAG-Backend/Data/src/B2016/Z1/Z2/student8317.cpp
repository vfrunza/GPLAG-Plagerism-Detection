/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

typedef vector<vector<double>> Matrica;

Matrica KreirajMatricu(int br_redova, int br_kolona)
{
	return Matrica(br_redova, vector<double>(br_kolona));
}

Matrica UnesiMatricu(int br_redova, int br_kolona)
{
	auto m(KreirajMatricu(br_redova,br_kolona));
	for(int i=0;i<br_redova;i++)
	{
		for(int j=0;j<br_kolona;j++)
		cin>>m[i][j];
	}
	return m;
}



int BrojRedova (Matrica m)
{
	return m.size();
}

//vraca broj kolona zadane matrice

int BrojKolona(Matrica m)
{
	return m[0].size();
}

vector<double> obrni (vector<double> v)
{
	vector<double> novi;
	for(int i= v.size()-1;i>=0;i--)
	{
		novi.push_back(v[i]);
	}
	return novi;
}

Matrica obrnimatricu(Matrica v)
{
	Matrica novi;
	for(int i=BrojRedova(v)-1;i>=0;i--)
	{
		vector<double>m=v[i];
		novi.push_back(m);
	}
	
	return novi;
}

Matrica  OgledaloMatrica(Matrica m)
{
	Matrica h,v,hv,velika;
	h=m;
	v=m;
	
	for(int i=0;i<BrojRedova(h);i++)
	{
		h[i]=obrni(h[i]);
	}
	
	/*for(int i=0;i<BrojRedova(h);i++)
	{
		for(int i=0;i<BrojKolona(h);i++)
		{
			cout<<h[i][j]<<" ";
			
		}
		cout<<endl;
	}*/
	
	v=obrnimatricu(v);
	hv=h;
	hv=obrnimatricu(hv);
	
	vector<double> nez;
	for(int i=0;i<BrojRedova(h);i++)
	{
		for(int j=0;j<BrojKolona(h);j++)
		{
			nez.push_back(hv[i][j]);
		}
			for(int j=0;j<BrojKolona(h);j++)
			{
				nez.push_back(v[i][j]);
			}
			for(int j=0;j<BrojKolona(h);j++)
			{
				nez.push_back(hv[i][j]);
			}
			
			velika.push_back(nez);
			nez.resize(0);
	}
		for(int i=0;i<BrojRedova(h);i++)
	{
		for(int j=0;j<BrojKolona(h);j++)
		{
			nez.push_back(h[i][j]);
		}
			for(int j=0;j<BrojKolona(h);j++)
			{
				nez.push_back(m[i][j]);
			}
			for(int j=0;j<BrojKolona(h);j++)
			{
				nez.push_back(h[i][j]);
			}
			
			velika.push_back(nez);
			nez.resize(0);
	}
	
		for(int i=0;i<BrojRedova(h);i++)
	{
		for(int j=0;j<BrojKolona(h);j++)
		{
			nez.push_back(hv[i][j]);
		}
			for(int j=0;j<BrojKolona(h);j++)
			{
				nez.push_back(v[i][j]);
			}
			for(int j=0;j<BrojKolona(h);j++)
			{
				nez.push_back(hv[i][j]);
			}
			
			velika.push_back(nez);
			nez.resize(0);
	}
	
	for(int i=0;i<BrojRedova(velika);i++)
	{
		for(int j=0;j<BrojKolona(velika);j++)
		{
			cout<<velika[i][j]<<" ";
			
		}
		cout<<endl;
	}
}


int main ()
{
	int m1,n1;
	cout<<"Unesite dimenzije matrice (m n): ";
	cin>>m1>>n1;
	if(m1<0 || n1<0)
	{
		cout<<"Dimenzije matrice moraju biti nenegativne!";
		}
		else
		{
	cout<<"Unesite elemente matrice: ";
	auto  pomocna(UnesiMatricu(m1,n1));
	auto nova(OgledaloMatrica(pomocna));
	
	
cout<<"Rezultntna matrica: ";
for(int i=0;i<BrojRedova(nova);i++)
{
	for(int j=0;j<BrojKolona(nova);j++)
	{
		cout<<setw(10)<<nova[i][j];
	}
	cout<<endl;
} }
	return 0;
}
