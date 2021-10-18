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


Matrica Horizontalna(Matrica mat)
{
	int m,n;
	m=int(mat.size());
	n=int(mat.at(0).size());
	Matrica rez(m, std::vector<double> (n));
	for(int i(0); i<m; i++)
	{
		int k(n-1);
		for(int j(0); j<n; j++)
		{
			rez.at(i).at(j)=mat.at(i).at(k);
			k--;
		}
	}
	return rez;
}

Matrica Vertikalna(Matrica mat)
{
	
	Matrica rez(mat.size(), std::vector<double> (mat[0].size()));
	int k(int(mat.size())-1);
	for(int i(0); i<mat.size(); i++)
	{
		for(int j(0); j<mat.at(0).size(); j++)
		{
			rez.at(i).at(j)=mat.at(k).at(j);
		}
		k--;
	}
	return rez;
}

Matrica OgledaloMatrica(Matrica mat)
{
	int redovi,kolone;
	
	redovi=int(mat.size());
	if(redovi==0) return std::vector<std::vector<double>> (0, std::vector<double> (0));
	
	kolone=int(mat.at(0).size()); 
	if(kolone==0) return std::vector<std::vector<double>> (3*redovi, std::vector<double> (0));
	
    for(int i(0); i<mat.size(); i++)
    {
    	if(mat.at(i).size()!=mat.at(0).size())
    	throw std::domain_error("Matrica nije korektna");
    }
    
	Matrica rez(3*redovi, std::vector<double> (3*kolone));
	
	Matrica hor_mat(redovi, std::vector<double> (kolone));
	hor_mat=Horizontalna(mat);
	
	Matrica vert_mat(redovi, std::vector<double> (kolone));
	vert_mat=Vertikalna(mat);
	
	Matrica komb_mat(redovi, std::vector<double> (kolone));
	komb_mat=Horizontalna(vert_mat);

	for(int i(0); i<3*redovi; i++)    // upisujemo horizontalne
	{
		int prvi(0), drugi(0), treci(0);
		for(int j(0); j<3*kolone; j++)
		{
			if(i>=redovi && i<redovi*2 && j>=0 && j<kolone)   // lijevo horizontalna matrica
			{
				rez.at(i).at(j)=hor_mat.at(i-redovi).at(prvi);
				prvi++;
			}
			else if(i>=redovi && i<redovi*2 && j>=kolone && j<kolone*2)
			{
			    rez.at(i).at(j)=mat[i-redovi][drugi];            // u sredini pocetna matrica
				drugi++;
			}
			else if(i>=redovi && i<redovi*2 && j>=kolone*2 && j<kolone*3)    // desno horizontalna matrica
			{
				rez.at(i).at(j)=hor_mat.at(i-redovi).at(treci);
				treci++;
			}
			else if(i>=0 && i<redovi && j>=kolone && j<kolone*2)
			{
				rez.at(i).at(j)=vert_mat.at(i).at(drugi);
				drugi++;
			}
			else if(i>=redovi*2 && i<redovi*3 && j>=kolone && j<kolone*2)
			{
				rez.at(i).at(j)=vert_mat.at(i-redovi*2).at(drugi);
				drugi++;
			}
			else if(i>=0 && i<redovi && j>=0 && j<kolone)
			{
				rez.at(i).at(j)=komb_mat.at(i).at(prvi);
				prvi++;
			}
			else if(i>=0 && i<redovi && j>=kolone*2 && j<kolone*3)
			{
			    rez.at(i).at(j)=komb_mat.at(i).at(treci);
				treci++;
			}
			else if(i>=redovi*2 && i<redovi*3 && j>=0 && j<kolone)
			{
				rez.at(i).at(j)=komb_mat.at(i-redovi*2).at(prvi);
				prvi++;
			}
			else if(i>=redovi*2 && i<redovi*3 && j>=kolone*2 && j<kolone*3)
			{
				rez.at(i).at(j)=komb_mat.at(i-redovi*2).at(treci);
				treci++;
			}
		}
	}
	return rez;
}

int main ()
{
	try
	{
		int m,n;
	    std::cout << "Unesite dimenzije matrice (m n): ";
	    std::cin >> m >> n;
	    if(m<0 || n<0)
	    {
	    	
		    std::cout << "Dimenzije matrice moraju biti nenegativne!";
		    return 0;
	    }
	    std::cout << "Unesite elemente matrice: ";
	    Matrica rez_mat(m, std::vector<double> (n));
	    for(int i(0); i<m; i++)
	    {
	    	for(int j(0); j<n; j++)
		    {
		    	std::cin >> rez_mat.at(i).at(j);
		    }
	    }
	    std::cout << std::endl << "Rezultantna matrica: " << std::endl;
	    rez_mat=OgledaloMatrica(rez_mat);
	    for(int i(0); i<3*m; i++)
	    {
		    for(int j(0); j<3*n; j++)
		    {
			    std::cout << std::setw(4) << rez_mat.at(i).at(j);
		    }
		std::cout << std::endl;
	    }
	    return 0;
	}
	catch(std::domain_error izuzetak)
	{
		std::cout << izuzetak.what();
	}
}