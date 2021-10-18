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

typedef std::vector<std::vector<double>> Matrica;

Matrica KreirajMatricu(int br_redova, int br_kolona)
{
	return Matrica(br_redova, std::vector<double>(br_kolona));
}

Matrica OgledaloMatrica(const Matrica &mat)
{
	if(mat.size()==0) return mat;
	Matrica prosirena=KreirajMatricu(mat.size()*3,mat[0].size()*3);
	for(int i=1;i<mat.size();i++)
	{
		if(mat[0].size()!=mat[i].size()) throw std::domain_error("Matrica nije korektna");
	}
	for(int i=0;i<mat.size();i++) //upisuje brojeve iz matrice koja je provjerena u matricu tri puta vecih dimenzija
	{
		for(int j=0;j<mat[0].size();j++)
		{	
			prosirena[i+mat.size()][j+mat[0].size()]=mat[i][j];							//popunjava srednju matricu
			prosirena[i+mat.size()][mat[0].size()-1-j]=mat[i][j];						//popunjava srednju lijevu matricu
			prosirena[i+mat.size()][3*mat[0].size()-1-j]=mat[i][j];						//popunjava srednju desnu matricu
			prosirena[mat.size()-1-i][j+mat[0].size()]=mat[i][j];						//popunjava srednju gornju matricu
			prosirena[3*mat.size()-1-i][j+mat[0].size()]=mat[i][j];						//popunjava srednju donju matricu
			prosirena[mat.size()-1-i][mat[0].size()-1-j]=mat[i][j];						//popunjava gornju lijevu matricu
			prosirena[mat.size()-1-i][3*mat[0].size()-1-j]=mat[i][j];					//popunjava gornju desnu matricu
			prosirena[3*mat.size()-1-i][mat[0].size()-1-j]=mat[i][j];					//popunjava donju lijevu matricu
			prosirena[3*mat.size()-1-i][3*mat[0].size()-1-j]=mat[i][j];					//popunjava donju desnu matricu
		}
	}
	return prosirena;
}

int main ()
{
	std::cout << "Unesite dimenzije matrice (m n): ";
	int m,n;
	std::cin >> m >> n;
	if(m<0||n<0)
	{
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::cout << "Unesite elemente matrice:\n";
	Matrica mat=KreirajMatricu(m,n);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			std::cin >> mat[i][j];
		}
	}
	try
	{
		Matrica x=OgledaloMatrica(mat);
		std::cout << "Rezultantna matrica:\n";
		for(std::vector<double> a:x)
		{
			for(double b:a)
			{
				std::cout << std::setw(4)<< b ;
			}
			std::cout << "\n";
		}
	}
	catch(std::domain_error greska)
	{
		std::cout << greska.what() << "\n";
	}
	return 0;
}