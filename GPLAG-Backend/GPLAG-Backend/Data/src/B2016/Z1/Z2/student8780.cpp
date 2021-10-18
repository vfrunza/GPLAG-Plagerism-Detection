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

typedef std::vector<std::vector<double>>  Matrica;


Matrica HorizontalnoOgledalo (Matrica matrica,int m,int n)
{
	double tmp;
	int broj;


	for (int i=0; i<m; i++)	{
		if (n%2!=0) broj=((n/2)+1);
		else broj=n/2;
		for (int j=0; j<broj; j++) {
			tmp=matrica[i][j];
			matrica[i][j]=matrica[i][n-1-j];
			matrica[i][n-1-j]=tmp;
		}


	}

	return matrica;
}
Matrica VertikalnoOgledalo (Matrica matrica,int m,int n)
{

	Matrica tmp(m,std::vector<double> (n));

	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			tmp [i][j]=matrica[m-1-i][j];

		}
	}
	return tmp;
}

Matrica HorizontalnoVertikalnoOgledalo (Matrica matrica,int m,int n)
{
	Matrica ogledalo (HorizontalnoOgledalo(matrica,m,n));
	Matrica konacno  (VertikalnoOgledalo(ogledalo,m,n));

	return konacno;
}

Matrica OgledaloMatrica (Matrica matrica)
{
  
	if (matrica.size()==0) return matrica;
	if (matrica.size()>1 && matrica[0].size()!=matrica[1].size()) throw std::domain_error ("Matrica nije korektna");
	
	int m(matrica.size());
	int n(matrica[0].size());
   	

	
	Matrica k_matrica(m*3,std::vector<double>(n*3));
	Matrica hv(HorizontalnoVertikalnoOgledalo(matrica,m,n));
	Matrica v (VertikalnoOgledalo(matrica,m,n));
	Matrica h (HorizontalnoOgledalo(matrica,m,n));


	for (int i=0; i<m*3; i++) {
		for (int j=0; j<n*3; j++) {
			if ((i==0 && j==((n*3)-n)) || (i==((m*3)-m) && j==0) || (i==0 && j==0) || (i==((m*3)-m) && j==((n*3)-n))) {
				for (int k=0; k<m; k++) {
					for (int l=0; l<n; l++) {
						k_matrica[i+k][j+l]=hv[k][l];
					}
				}


			}




			if ((i==0 && j==(n)) || (i==((m*3)-m) && j==(n))) {

				for (int k=0; k<m; k++) {
					for (int l=0; l<n; l++) {
						k_matrica[i+k][j+l]=v[k][l];
					}
				}
			}

			if ( (i==m && j==0)||(i==m && (j==(n*3)-n))) {

				for (int k=0; k<m; k++) {
					for (int l=0; l<n; l++) {
						k_matrica[i+k][j+l]=h[k][l];
					}
				}
			}


			if (i==m && j==n) {
				for (int k=0; k<m; k++) {
					for (int l=0; l<n; l++) {
						k_matrica[i+k][j+l]=matrica[k][l];
					}
				}
			}




		}
	}
	return k_matrica;
}

int main ()
{
	int m,n;

	std::cout << "Unesite dimenzije matrice (m n): ";

	std::cin>> m;
	std::cin >>n;
	if (m<0)
	{
	
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	
	int m3,n3;
	m3=m*3;
	n3=n*3;
	Matrica hv (m,std::vector<double>(n));
	Matrica h (m,std::vector<double> (n));
	Matrica v (m,std::vector<double> (n));
	Matrica matrica(m,std::vector<double> (n));
	Matrica konacna_matrica (m3,std::vector<double>(n3));

	std::cout << "Unesite elemente matrice: ";

	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			std::cin >> matrica[i][j];
		}

	}
   
   try
   {
	konacna_matrica=OgledaloMatrica(matrica);
	
   std::cout << std::endl<<"Rezultantna matrica:"<<std::endl;
	for (std::vector<double> x : konacna_matrica)
	{
		for (double v : x) {
			std::cout <<std::setw(4)<< v ;
		}
		std::cout << std::endl;
	}
   }
   catch (std::domain_error izuzetak)
   {
   	 std::cout << izuzetak.what() << std::endl;
   }
    
   





	return 0;
}