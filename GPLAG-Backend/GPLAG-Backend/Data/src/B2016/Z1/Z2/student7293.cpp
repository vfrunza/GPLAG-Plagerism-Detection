#include <iostream>
#include <vector>
#include <iomanip>
#include <iomanip>
#include <stdexcept>

typedef std::vector<std::vector<double>> Matrica;


int BrojRedova (Matrica m)
{
	return m.size();
}

int BrojKolona (Matrica m)
{
	if (m.size() == 0)
	{
		return 0;
	}
	return m[0].size();
}


Matrica Horizontalna (Matrica m) //obrnemo redoslijed kolona u matrici
{
	int r = BrojRedova(m);
	int k = BrojKolona(m);
	double temp;
	
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < k/2; j++)
		{
			temp = m[i][j];
			m[i][j] = m[i][k-j-1];
			m[i][k-j-1] = temp;
		}
	}
	return m;
}

Matrica Vertikalna (Matrica m) //obrnemo redoslijed redova u matrici
{
	int r = BrojRedova(m);
	int k = BrojKolona(m);
	double temp;
	
	for (int i = 0; i < r/2; i++)
	{
		for (int j = 0; j < k; j++)
		{
			temp = m[i][j];
			m[i][j] = m[r-i-1][j];
			m[r-i-1][j] = temp;
		}
	}
	return m;
}

Matrica Kombinovana (Matrica m) //obrnut redoslijed kolona i redoslijed redova 
{
	int r = BrojRedova(m);
	int k = BrojKolona(m);
	double temp;
	
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < k/2; j++)
		{
			temp = m[i][j];
			m[i][j] = m[i][k-j-1];
			m[i][k-j-1] = temp;
		}
	}
	
	for (int i = 0; i < r/2; i++)
	{
		for (int j = 0; j < k; j++)
		{
			temp = m[i][j];
			m[i][j] = m[r-i-1][j];
			m[r-i-1][j] = temp;
		}
	}
	
	return m;
}


Matrica OgledaloMatrica (Matrica m)
{
	int r = BrojRedova(m);
	int k = BrojKolona(m);
	
	//ISPITUJE DA LI JE MATRICA GRBAVA
	bool p{true};
	for (int i=0; i<r; i++)
	{
		unsigned int temp;
		if (p)
		{
			temp = m[i].size();
			p = false;
		}
		
		if (m[i].size() != temp)
		{
			throw std::domain_error ("Matrica nije korektna");
		}
	}
	
	Matrica nova(3*r);
	
	for (int i=0; i<3*r; i++)
	{
		nova[i].resize(3*k);
		
		for (int j=0; j<3*k; j++)
		{
			if (i<r && j<k)
			{
				Matrica m1 = Kombinovana(m);
				nova[i][j] = m1[i][j];
			}
			else if (i<r && j>=k && j<2*k)
			{
				Matrica m2 = Vertikalna(m);
				nova[i][j] = m2[i][j-k];
			}
			else if (i<r && j>=2*k )
			{
				Matrica m3 = Kombinovana(m);
				nova[i][j] = m3[i][j-2*k];
			}
			else if (i>=r && i<2*r && j<k)
			{
				Matrica m4 = Horizontalna(m);
				nova[i][j] = m4[i-r][j];
			}
			else if (i>=r && i<2*r && j>=k && j<2*k)
			{
				nova[i][j] = m[i-r][j-k];
			}
			else if (i>=r && i<2*r && j>=2*k )
			{
				Matrica m5 = Horizontalna(m);
				nova[i][j] = m5[i-r][j-2*k];
			}
			else if (i>=2*r && j<k)
			{
				Matrica m6 = Kombinovana(m);
				nova[i][j] = m6[i-2*r][j];
			}
			else if (i>=2*r && j>=k && j<2*k)
			{
				Matrica m7 = Vertikalna(m);
				nova[i][j] = m7[i-2*r][j-k];
			}
			else if (i>=2*r  && j>=2*k )
			{
				Matrica m8 = Kombinovana(m);
				nova[i][j] = m8[i-2*r][j-2*k];
			}
		}
	}
	return nova;
}


int main ()
{
	int m,n;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin >> m >> n;
		
	if (m<0 || n<0)
	{
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
		
	//UNOS MATRICE
	Matrica MAT (m, std::vector<double> (n) );
	std::cout<<"Unesite elemente matrice: ";
	for (int i=0; i<m; i++)
	{
		for (int j=0; j<n; j++)
		{
			std::cin >> MAT [i][j];
		}
	}
	try {
		
		Matrica NovaMAT = OgledaloMatrica(MAT);
		
		//ISPIS MATRICE
		std::cout<<"\nRezultantna matrica: ";
		std::cout << std::endl;
		for (int i=0; i<3*m; i++)
		{
			for (int j=0; j<3*n; j++)
			{
				std::cout << std::setw(4) << NovaMAT[i][j];
			}
			std::cout << std::endl;
		}
	}

	catch (std::domain_error izuzetak) {
		std::cout << izuzetak.what() << std::endl;
	}
	
	return 0;
}