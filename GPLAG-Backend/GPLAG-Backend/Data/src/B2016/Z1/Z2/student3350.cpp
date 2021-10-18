#include<iostream>
#include<vector>
#include<iomanip>
typedef std::vector<std::vector<int>> Matrica ;
Matrica kreirajMATRICU(int br_REDOVA,int br_KOLONA)
	{
	return Matrica( br_REDOVA,std::vector<int>(br_KOLONA));
	}
int brojREDOVA(Matrica m)
	{
		return m.size();
	}
int brojKOLONA(Matrica m)
	{
		return m[0].size();
	}
Matrica unesiMATRICU(int br_REDOVA,int br_KOLONA)
	{
		auto m(kreirajMATRICU(br_REDOVA,br_KOLONA));
		for(int i=0;i<br_REDOVA;i++)
			for(int j=0;j<br_KOLONA;j++)
				std::cin >>m[i][j];
		return m;		
	}
void ispisiMATRICU(Matrica m)
	{
		for(int i=0;i<brojREDOVA(m);i++)
		{
			for(int j=0;j<brojKOLONA(m);j++)
			std::cout << std::setw(4)<<m[i][j];
			std::cout<< std::endl;
		}
	}
Matrica hm(Matrica m1)
	{
		auto hmatrica(kreirajMATRICU(brojREDOVA(m1),brojKOLONA(m1)));
		for(int i=0;i<brojREDOVA(m1);i++)
		{
			int k(0);
			for(int j=(brojKOLONA(m1)-1);j>=0;j--)
			{
				hmatrica[i][k]=m1[i][j];
				k++;
			}
		}
	return hmatrica;	
	}
Matrica vm(Matrica m1)
	{
		int k(0);
		auto vmatrica(kreirajMATRICU(brojREDOVA(m1),brojKOLONA(m1)));
		for(int i=(brojREDOVA(m1)-1);i>=0;i--)
		{
			for(int j=0;j<brojKOLONA(m1);j++)
			{
			vmatrica[k][j]=m1[i][j];
			}
		k++;
		}
	return vmatrica;
	}
Matrica hv(Matrica m1)
	{
		int k(0);
		auto hvmatrica(kreirajMATRICU(brojREDOVA(m1),brojKOLONA(m1)));
		for(int i=(brojREDOVA(m1)-1);i>=0;i--)
		{
			int l(0);
			for(int j=(brojKOLONA(m1)-1);j>=0;j--)
			{
				hvmatrica[k][l]=m1[i][j];
				l++;
			}
			k++;
		}
	return hvmatrica;	
	}
Matrica OgledaloMatrica(Matrica x)
{
	Matrica horz=hm(x);
	Matrica ver=vm(x);
	Matrica komb=hv(x);
	Matrica y=kreirajMATRICU(3*brojREDOVA(x),3*brojKOLONA(x));
	for(int i=0;i<3*brojREDOVA(x);i++)
	{
		for(int j=0;j<3*brojKOLONA(x);j++)
		{
			if(i<=brojREDOVA(x)-1)
			{
				if(j<=brojKOLONA(x)-1) { y[i][j]=komb[i][j]; }
				if(j>=brojKOLONA(x) && j<=2*brojKOLONA(x)-1) { y[i][j]=ver[i][j-brojKOLONA(x)];}
				if(j>=2*brojKOLONA(x)) { y[i][j]=komb[i][j-2*brojKOLONA(x)]; }
				
			}
			if(i>=brojREDOVA(x) &&i<=2*brojREDOVA(x)-1)
			{
				if(j<=brojKOLONA(x)-1) { y[i][j]=horz[i-brojREDOVA(x)][j]; }
				if(j>=brojKOLONA(x) && j<=2*brojKOLONA(x)-1) { y[i][j]=x[i-brojREDOVA(x)][j-brojKOLONA(x)];}
				if(j>=2*brojKOLONA(x)) { y[i][j]=horz[i-brojREDOVA(x)][j-2*brojKOLONA(x)]; }
				
			}
			if(i>=2*brojREDOVA(x))
			{
				if(j<=brojKOLONA(x)-1) { y[i][j]=komb[i-2*brojREDOVA(x)][j]; }
				if(j>=brojKOLONA(x) && j<=2*brojKOLONA(x)-1) { y[i][j]=ver[i-2*brojREDOVA(x)][j-brojKOLONA(x)];}
				if(j>=2*brojKOLONA(x)) { y[i][j]=komb[i-2*brojREDOVA(x)][j-2*brojKOLONA(x)]; }
				
			}
		}
	}
	return y;
}
int main ()
{
	int m1,n1;
	Matrica z;
	std::cout <<"Unesite dimenzije matrice (m n): ";
	std::cin >> m1>>n1;
	if(m1<0||n1<0) { std::cout <<"Dimenzije matrice moraju biti nenegativne!"<< std::endl; return 0; }
	std::cout <<"Unesite elemente matrice: "<< std::endl;
	auto A(unesiMATRICU(m1,n1));
	std::vector<std::vector<int>> x1 = hm(A);
	std::vector<std::vector<int>> x2 = vm(A);
	std::vector<std::vector<int>> x3 = hv(A);
	z=OgledaloMatrica(A);
	std::cout <<"Rezultantna matrica: "<< std::endl;
	ispisiMATRICU(z);
	
	
	return 0;
}