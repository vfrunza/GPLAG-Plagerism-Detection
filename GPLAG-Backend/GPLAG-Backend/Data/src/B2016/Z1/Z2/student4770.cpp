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

typedef std::vector<std::vector<double>> Matrica;
typedef std::vector<double> vektor;

bool Grbava (Matrica a)
{
	for (int i=0; i<int(a.size())-1; i++)
	{
		if(a[i].size()!=a[i+1].size())
			return true;
	}
	return false;
}
Matrica HorizontalnoOgledalo (Matrica a)
{
	int d(a.size());
	double temp;
	for(int i=0; i<d; i++)
	{
		for(int j=0; j<int(a[i].size()/2); j++)
		{
			temp=a[i][j];
			a[i][j]=a[i][a[i].size()-1-j];
			a[i][a[i].size()-1-j]=temp;
		}
	}
	return a;
}
Matrica VertikalnoOgledalo (Matrica a)
{
	int d(a.size());
	double temp;
	for(int i=0; i<d/2; i++)
	{
		for(int j=0; j<a[i].size(); j++)
		{
			temp=a[i][j];
			a[i][j]=a[d-1-i][j];
			a[d-1-i][j]=temp;
		}
	} return a;
}
Matrica KombinovanoOgledalo (Matrica a)
{
	a=HorizontalnoOgledalo(a);
	a=VertikalnoOgledalo(a);
	return a;
}
Matrica OgledaloMatrica (Matrica a)
{
	if(Grbava(a)) throw std::domain_error("Matrica nije korektna");
	Matrica h(a), v(a), k(a);
	h=HorizontalnoOgledalo(h);
	k=KombinovanoOgledalo(k);
	v=VertikalnoOgledalo(v);
	int row(a.size()), column;
	if(a.size()>0) column=a[0].size();
	else column=0;
	Matrica prvi=k;
	Matrica drugi=h;
	Matrica treci=k;

	for(int i=0; i<row; i++)
	{
		for(int j=0; j<column; j++)
			prvi[i].push_back(v[i][j]);
	}
	for(int i=0; i<row; i++)
	{	
		for(int j=0; j<column; j++)
			prvi[i].push_back(k[i][j]);
	}
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<column; j++)
			drugi[i].push_back(a[i][j]);
	}
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<column; j++)
			drugi[i].push_back(h[i][j]);
	}	
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<column; j++)
			treci[i].push_back(v[i][j]);
	}
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<column; j++)
			treci[i].push_back(k[i][j]);		
	}
	
	for(int i=0; i<int(drugi.size()); i++)
		prvi.push_back(drugi[i]);
	for(int i=0; i<int(treci.size()); i++)
		prvi.push_back(treci[i]);
	return prvi;
}

int main ()
{
	int m, n;

		std::cout<<"Unesite dimenzije matrice (m n): ";
		std::cin>>m>>n;
		if(!std::cin)
		{
			std::cout<<"Neispravan unos!"<<std::endl;
			return 0;

		}
		else if(m<0 || n<0) 
		{
			std::cout<<"Dimenzije matrice moraju biti nenegativne!"<<std::endl;
			return 0;
		}
		else if(std::cin.peek() != '\n')
		{
			std::cout<<"Ostalo je nešto u spremniku!"<<std::endl;
			return 0;
		}
		else if(std::cin) {
	

	Matrica M(m, vektor (n));
	std::cout<<"Unesite elemente matrice: "<<std::endl;
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			std::cin>>M[i][j];
	Matrica a;
	try {
	a=OgledaloMatrica(M);
	std::cout<<"Rezultantna matrica: "<<std::endl;
	for(int i=0;i<a.size(); i++)
	{for(int j=0; j<a[i].size(); j++)
	std::cout<<std::setw(4)<<a[i][j];
	std::cout<<std::endl;}
		}
	
	catch(std::domain_error izuzetak) {
		std::cout<<izuzetak.what();
	} }

	return 0;
}
