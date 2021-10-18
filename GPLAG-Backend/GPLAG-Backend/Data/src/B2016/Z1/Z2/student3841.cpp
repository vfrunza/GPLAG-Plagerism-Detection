/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
	
	okiiii
*/
#include<iostream>
#include<vector>
#include<stdexcept>
#include<iomanip>

typedef std::vector<std::vector<double>> Matrica;

Matrica OgledaloMatrica(Matrica originalna)
{
	Matrica nova;
	int n(0);
	
	for(int i = 0; i < originalna.size(); i++)
			if(originalna.at(i).size() != originalna.at(0).size())
				throw std::domain_error("Matrica nije korektna");
	
	
	nova.resize(3 * originalna.size());
	for(int i = 0; i < (originalna.size() * 3); i++)
	{
		nova.at(i).resize(3 * originalna.at(0).size());
		n = originalna.at(0).size();
	}
		
	int m = originalna.size();
	
	
	//centar
	for(int i = m; i < 2 * m; i++)
		for(int j = n; j < 2 * n; j++)
			nova.at(i).at(j) = originalna.at(i - m).at(j - n);
	
	//gornji lijevi
	for(int i = m - 1; i >= 0; i--)
		for(int j = n - 1; j >= 0; j--)
				nova.at(m - i - 1).at(n - j - 1) = originalna.at(i).at(j);
				
	//gornji sredina		
	for(int i = m - 1; i >= 0; i--)
		for(int j = 0; j < n; j++)
			nova.at(m - i - 1).at(n + j) = originalna.at(i).at(j);
				
	//gornji desni
	for(int i = m - 1; i >= 0; i--)
		for(int j = n - 1; j >= 0; j--)
			nova.at(m - i - 1).at(3 * n - j - 1) = originalna.at(i).at(j);
	
	//sredina lijevi
	for(int i = m; i < 2 * m; i++)
		for(int j = 0; j < n; j++)
			nova.at(i).at(j) = originalna.at(i - m).at(n - j - 1);
			
	//sredina desno
	for(int i = m; i < 2 * m; i++)
		for(int j = 3 * n - 1; j >= 2 * n; j--)
			nova.at(i).at(j) = originalna.at(i - m).at(3 * n - j - 1);
		
	//donji lijevi
	for(int i = m - 1; i >= 0; i--)
		for(int j = n - 1; j >= 0; j--)
				nova.at(3 * m - i - 1).at(n - j - 1) = originalna.at(i).at(j);
				
	//donji sredina
	for(int i = m - 1; i >= 0; i--)
		for(int j = 0; j < n; j++)
			nova.at(3 * m - i - 1).at(n + j) = originalna.at(i).at(j);
			
	//donji desno
	for(int i = m - 1; i >= 0; i--)
		for(int j = 0; j < n; j++)
			nova.at(3 * m - i - 1).at(3 * n - j - 1) = originalna.at(i).at(j);
	
	return nova;
}
int main ()
{
	int m, n;
	
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> m >> n;
	
	if(m < 0 || n < 0)
	{
		std::cout << "Dimenzije matrice moraju biti nenegativne!" << std::endl;
		return 0;
	}
	try
	{
		Matrica a;
	
		a.resize(m);
		for(int i = 0; i < m; i++)
			a.at(i).resize(n);
	
		std::cout << "Unesite elemente matrice: ";
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++)
				std::cin >> a.at(i).at(j);
	
		Matrica nova(OgledaloMatrica(a));
	
		std::cout << "\nRezultantna matrica: " << std::endl;
	
		for(int i = 0; i < 3*m; i++)
		{
			for(int j = 0; j < 3*n; j++)
				std::cout << std::setw(4) << std::right << nova.at(i).at(j);
			
			std::cout << std::endl;
		}
		
	}
	
	catch(...)
	{
		std::cout << "Matrica nije korektna";
	}
	
	
	return 0;
}