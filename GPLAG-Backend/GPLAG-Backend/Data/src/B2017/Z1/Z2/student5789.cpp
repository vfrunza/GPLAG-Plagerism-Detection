/*B 2017/2018, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

std::vector<std::vector<double>> NajvecaPlaninaMatrice(std::vector<std::vector<double>> matrica)
{
	std::vector<std::vector<double>> rez;
	int kolona=matrica.at(0).size(), red=matrica.size();
	if(red!=0)
	{
		kolona=matrica.at(0).size();
		for(int i(1);i<red;i++)
		{
			if(matrica.at(i).size()!=kolona)
			{
				throw std::domain_error("Matrica nije korektna");
			}
		}
		if(kolona==0) return rez;
	}
	else return rez;
	
	if(red==1&&kolona==1) return matrica;
	std::vector<int> koordinate;
	for(int i(1);i<red-1;i++)
	{
		for(int j(1);j<kolona-1;j++)
		{
			if(matrica.at(i-1).at(j)+matrica.at(i-1).at(j+1)+matrica.at(i-1).at(j-1)+matrica.at(i+1).at(j+1)+matrica.at(i+1).at(j)+matrica.at(i+1).at(j-1)+matrica.at(i).at(j-1)+matrica.at(i).at(j+1)<=matrica.at(i).at(j))
			{
				std::vector<std::vector<double>> rez3;
				std::vector<double> v1;
				std::vector<double> v2;
				std::vector<double> v3;
				v1.push_back(matrica.at(i-1).at(j-1));
				v1.push_back(matrica.at(i-1).at(j));
				v1.push_back(matrica.at(i-1).at(j+1));
				v2.push_back(matrica.at(i).at(j-1));
				v2.push_back(matrica.at(i).at(j));
				v2.push_back(matrica.at(i).at(j+1));
				v3.push_back(matrica.at(i+1).at(j-1));
				v3.push_back(matrica.at(i+1).at(j));
				v3.push_back(matrica.at(i+1).at(j+1));
				rez3.push_back(v1);
				rez3.push_back(v2);
				rez3.push_back(v3);
	            return rez3;
			}
		}
	}
	double zbir(0);
	if(red==3&&kolona==3){
	    for(int k(0);k<red;k++)
	    {
	    	for(int l(0);l<kolona;l++)
	    	zbir+=matrica.at(k).at(l);
	    }
	    zbir=zbir-matrica.at(1).at(1);
	    if(matrica.at(1).at(1)>zbir) return matrica;
	}
	if(red==2&&kolona==2){
		double pred=matrica.at(0).at(0);
		for(int k(0);k<red;k++)
		{
			for(int l(0);l<kolona;l++)
			if(matrica.at(k).at(l)>pred) pred=matrica.at(k).at(l);
			
		}
			std::vector<double> rez2;
			std::vector<std::vector<double>> rezM;
	        rez2.push_back(pred);
	        rezM.push_back(rez2);
	        return rezM;
		}
	
	return matrica;
}

int main ()
{
	int m,n;
	std::vector<std::vector<double>> mat;
	std::vector<double> PomVek;
	double unos;
	std::cout<<"Unesite dimenzije matrice (m i n): ";
	std::cin>>m;
	std::cin>>n;
	if(m<0||n<0) std::cout<<"Dimenzije matrice moraju biti nenegativne!";
	else {
	std::cout<<"Unesite elemente matrice: ";
	for(int i(0);i<m;i++)
	{
	   PomVek.clear();
	   for(int j(0);j<n;j++){
	   std::cin>>unos;
	   PomVek.push_back(unos);
	 }
	 mat.push_back(PomVek);
	}
	std::cout<<std::endl;
	std::cout<<"Najveca planina unesene matrice je: ";
	std::cout<<std::endl;
	mat=NajvecaPlaninaMatrice(mat);
	for(int k(0);k<mat.size();k++){
	   for(int l(0);l<mat.at(k).size();l++)
	   std::cout<<std::setw(6)<<mat.at(k).at(l);
	   std::cout<<std::endl;
	}
	}
	return 0;
}