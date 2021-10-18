/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>
#include <utility>
#include <stdexcept>
#include <iomanip>

std::vector<std::vector<double>> OgledaloMatrica(std::vector<std::vector<double>> mat)
{
	//Provjera da li je matrica grbava
	for(int i = 0; i < mat.size(); i++)
		if(mat[i].size() != mat[0].size())
			throw std::domain_error("Matrica nije korektna");
			
	std::vector<std::vector<double>> hor(mat), ver(mat), komb(mat);
	//Vertikalno Ogledalo
	for(int i = 0; i < ver.size()/2; i++)
		{
			std::swap(ver[i], ver[ver.size()-i-1]);
		}
		
	//Horizontalno Ogledalo
	for(int i = 0; i < hor.size(); i++)
		for(int j = 0; j < hor[i].size()/2; j++)
			std::swap(hor[i][j], hor[i][hor[j].size()-j-1]);
			
	//Kombinovno Ogledalo
	for(int i = 0; i < komb.size()/2; i++)
	{
		std::swap(komb[i], komb[komb.size()-i-1]);
	} 
	for(int i = 0; i < komb.size(); i++)
		for(int j = 0; j < komb[i].size()/2; j++)
			std::swap(komb[i][j], komb[i][komb[j].size()-j-1]);
	
	//Ogledalo Matrica
	int total(0);		
	std::vector<std::vector<double>> ogledalo(3*mat.size());
	for(int i = 0; i < mat.size(); i++)
	{
		for(int j = 0; j < mat[i].size(); j++)
			ogledalo[i].push_back(komb[i][j]);
		for(int j = 0; j < mat[i].size(); j++)
			ogledalo[i].push_back(ver[i][j]);
		for(int j = 0; j < mat[i].size(); j++)
			ogledalo[i].push_back(komb[i][j]);
		total = i+1;
	}
	int total2(0);
	for(int i = 0; i < mat.size(); i++)
	{
		for(int j = 0; j < mat[i].size(); j++)
			ogledalo[i+total].push_back(hor[i][j]);
		for(int j = 0; j < mat[i].size(); j++)
			ogledalo[i+total].push_back(mat[i][j]);
		for(int j = 0; j < mat[i].size(); j++)
			ogledalo[i+total].push_back(hor[i][j]);
		total2 = i+total+1;
	}
	for(int i = 0; i < mat.size(); i++)
	{
		for(int j = 0; j < mat[i].size(); j++)
			ogledalo[total2+i].push_back(komb[i][j]);
		for(int j = 0; j < mat[i].size(); j++)
			ogledalo[total2+i].push_back(ver[i][j]);
		for(int j = 0; j < mat[i].size(); j++)
			ogledalo[total2+i].push_back(komb[i][j]);
	}
	return ogledalo;
}

int main ()
{
	try{
		std::cout<<"Unesite dimenzije matrice (m n): ";
		int m,n;
		std::cin>>m>>n;
		if(m < 0 || n < 0)
		{
			std::cout<<"Dimenzije matrice moraju biti nenegativne!";
			return 0;
		}
		std::vector<std::vector<double>> mat(m, std::vector<double>(n));
		std::cout<<"Unesite elemente matrice:";
		for(int i = 0; i < mat.size(); i++)
			for(int j = 0; j < mat[i].size(); j++)
				std::cin>>mat[i][j];
		std::vector<std::vector<double>> ogledalo;
		ogledalo = OgledaloMatrica(mat);
		std::cout<<std::endl<<"Rezultantna matrica: "<<std::endl;
		for(int i = 0; i < ogledalo.size(); i++)
		{
			for(int j = 0; j < ogledalo[i].size(); j++)
				std::cout<<std::setw(4)<<ogledalo[i][j];
			std::cout<<std::endl;
		}
	}
	catch(std::domain_error izuzetak)
	{
		std::cout<<izuzetak.what();
	}
	return 0;
}