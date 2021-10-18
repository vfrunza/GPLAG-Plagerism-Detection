//q:~WHY DO ASIAN PEOPLE DON'T TAKE C/C++ PROGRAMMING COURSES?
//a:~BECAUSE THEIR PARENTS HAVEN'T RAISED THEM TO BE CSIAN.

#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

//dodatna funkcija unos sa provjerom unosa
void Unos(int &m, int &n)
{
	std::cin>>m>>n;
	if(m<0 || n<0)
		throw std::domain_error("Dimenzije matrice moraju biti nenegativne!");
}

std::vector<std::vector<double>> OgledaloMatrica(std::vector<std::vector<double>> matrica)
{
	std::vector<std::vector<double>> ogledalo;
	if(matrica.size()==0)
		return ogledalo;
//test grbavosti matrice
	for(int i=1;i<matrica.size();i++)
		if(matrica[0].size()!=matrica[i].size())
			throw std::domain_error("Matrica nije korektna");
	ogledalo.resize(matrica.size()*3);
	std::vector<std::vector<double>> v(matrica.size()),hv(matrica.size());
	
//kreiranje gornje srednje podmatrice dimenzija unesene matrice
	for(int i=matrica.size()-1;i>=0;i--)
		for(int j=0;j<matrica[0].size();j++)
			v[i].push_back(matrica[i].at(j));
//kreiranje desne/lijeve gornje podmatrice uz pomoc prethodne, te istih dimenzija
	for(int i=0;i<v.size();i++)
		for(int j=v[0].size()-1;j>=0;j--)
			hv[i].push_back(v[i].at(j));
			
//kreiranje ATRIX cijele gornje podmatrice dimnezija 3*kolona unesene matrice i isti broj redova
//kreiranje uz pomoc predthodne dvije kreirane podmatrice
	std::vector<std::vector<double>> atrix(matrica.size());
	for(int i=0;i<matrica.size();i++)
		for(int j=0;j<matrica[0].size();j++)
			atrix[i].push_back(hv[i].at(j));
	for(int i=0;i<matrica.size();i++)
		for(int j=0;j<matrica[0].size();j++)
			atrix[i].push_back(v[i].at(j));
	for(int i=0;i<matrica.size();i++)
		for(int j=0;j<matrica[0].size();j++)
			atrix[i].push_back(hv[i].at(j));
			
//kreiranje ogledalo matrice
	int i{0};
//gornja ATRIX podmatrica
	for(int k=matrica.size()-1;k>=0;k--)
	{
		for(int j=0;j<atrix[0].size();j++)
			ogledalo[i].push_back(atrix[k].at(j));
		i++;
	}
//srednja ogledalo ATRIX podmatrica
	for(int k=0;k<matrica.size();k++)
	{
		for(int j=0;j<atrix[0].size();j++)
			ogledalo[i].push_back(atrix[k].at(j));
		i++;
	}
//donja ATRIX podmatrica
	for(int k=matrica.size()-1;k>=0;k--)
	{
		for(int j=0;j<atrix[0].size();j++)
			ogledalo[i].push_back(atrix[k].at(j));
		i++;
	}
	return ogledalo;
}

int main()
{
	int m,n;
//try-unos
	try
	{
		std::cout<<"Unesite dimenzije matrice (m n): ";
		Unos(m,n);
	}
	catch(std::domain_error dimenzije)
   	{
      std::cout<<dimenzije.what()<<std::endl;
      return 0;
   	}
//unos elemenata u matricu
	std::cout<<"Unesite elemente matrice: ";
	std::vector<std::vector<double>> mat(m, std::vector<double>(n));
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			std::cin>>mat[i][j];
//try za funkciju ogledala sa ispisom
	try
	{
		std::vector<std::vector<double>> ogledalo;
		ogledalo=OgledaloMatrica(mat);
		std::cout<<std::endl<<"Rezultantna matrica: ";
		std::cout<<std::endl;
		for (const auto &red:ogledalo)
		{
			for (const auto &i:red)
				std::cout<<std::right<<std::setw(4)<<i;
			std::cout << std::endl;
		}
	}
	catch(std::domain_error grbava)
   	{
      std::cout<<grbava.what()<<std::endl;
   	}
	return 0;
}