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
#include <cmath>
#include <iomanip>
#include <stdexcept>



double MaxEl (std::vector<std::vector<double>> v)
{
	//Funkcija vraca najveci elemenat u matrici, tj.prvi na koji naidje ako ih ima vise
	std::vector<double> temp(v.size()*v.at(0).size());
	for (int i=0;i<v.size();i++)
	{
		for (int j=0;j<v.at(i).size();j++)
		{
			temp.at(i*v.at(i).size()+j)=v.at(i).at(j);
		}
	}
	double maxe(temp.at(0));
	for (int i=0;i<temp.size();i++)
	{
		if (temp.at(i)>maxe)
			maxe=temp.at(i);
	}
	return maxe;
}

bool JesuLiJednaki (double a, double b,double eps=1e-10)
{
	//Ispitivanje jednakosti i nejednakosti za realne brojeve
	if ((a<0 &&b>0) || (a>0 &&b<0))
		return false;
	return std::fabs(a-b)<=eps*(std::fabs(a)+std::fabs(b));
}

std::vector<std::vector<double>> NajvecaPlaninaMatrice (std::vector<std::vector<double>> mat)
{
	//Ispitujemo da li matrica ima razlicit broj kolona, i u tom slucaju bacamo izuzetak
	for (int i=0;i<mat.size();i++)
	{
		for (int j=i+1;j<mat.size();j++)
		{
			if (mat.at(i).size()!=mat.at(j).size())
				throw std::domain_error("Matrica nije korektna");
		}
	}
	std::vector<std::vector<double>> maxi;
	double najv;
	bool nema_vrha(true);
	bool dim(false);
	for (int i=0;i<mat.size();i++)
	{
		for (int j=0;j<mat.at(i).size();j++)
		{
			long double pom(mat.at(i).at(j));
			int redl(i),redd(i),kolonal(j),kolonad(j);
			bool planina(true);
			najv=MaxEl(mat);
			dim=true;
			//Cim pronadjemo element u cijoj okolini se nalazi makar jedan koncentricni kvadrat racunamo sumu elemenata tog kvadrata
			if	(redl>=1 && kolonal>=1 && kolonad<mat.at(i).size()-1 && redd<mat.size()-1)
			{	
				while (redl>=1 && kolonal>=1 && kolonad<mat.at(i).size()-1 && redd<mat.size()-1)
				{
				long double suma(0);
				int indeks(0);
				std::vector<std::vector<double>> temp;
				for (int k=redl-1;k<=redd+1;k++)
				{
					temp.resize(indeks+1);
					for (int l=kolonal-1;l<=kolonad+1;l++)
					{
						temp.at(indeks).push_back(mat.at(k).at(l));
						if (k==redl-1 || k==redd+1 || l==kolonal-1 || l==kolonad+1)
						suma+=mat.at(k).at(l);
					}
					indeks++;
				}
				if (suma>pom || JesuLiJednaki(suma,pom))
				planina=false;
				//Ako je veca od prethodne ili veca od vrha, petlja se prekida
				//Konstno sirimo opseg od pronadjenog elementa,sve dok smo unutar dimenzija matrice
				redl--;
				kolonal--;
				redd++;
				kolonad++;
				if (!planina)
					 break;
				else if (planina && temp.size()!=0){
					pom=suma;
					nema_vrha=false;
				if (temp.size()>maxi.size())
				   maxi=std::move(temp); 
				else if (temp.size()==maxi.size() && MaxEl(temp)>MaxEl(maxi) && !JesuLiJednaki(MaxEl(maxi),MaxEl(temp)))
					maxi=std::move(temp); 
				}
			}
			}
		}
	}
	if (nema_vrha && dim)
	{
		maxi.resize(1);
		maxi.at(0).push_back(najv);
	}

	return maxi;
}

int main ()
{
	//Hvatanje izuzetka u mainu
	try{
	int m,n;
	std::cout<<"Unesite dimenzije matrice (m i n): ";
	std::cin>>m>>n;
	if (m<0 || n<0)
	std::cout<<"Dimenzije matrice moraju biti nenegativne!";
	else
	{
		double unos;
		std::vector<std::vector<double>> mat(m);
		std::cout<<"Unesite elemente matrice: ";
		for (int i=0;i<m;i++)
		{
			for (int j=0;j<n;j++)
			{
				std::cin>>unos;
				mat.at(i).push_back(unos);
			}
		}

		auto m(NajvecaPlaninaMatrice(mat));
		std::cout<<"\nNajveca planina unesene matrice je: "<<std::endl;
		for (std::vector<double> y: m)
		{
			for (double x: y)
				std::cout<<std::setw(6)<<x;
			std::cout<<"\n";
		}
	}}
	catch (std::domain_error izuzetak){
		std::cout<<izuzetak.what()<<std::endl;
	}
	return 0;
}