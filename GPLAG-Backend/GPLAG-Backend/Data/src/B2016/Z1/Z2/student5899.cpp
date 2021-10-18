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
	if(br_redova<0 || br_kolona <0) throw std::domain_error("Dimenzije matrice moraju biti nenegativne!");
	return Matrica(br_redova, std::vector<double>(br_kolona));
}

Matrica UnesiMatricu (int br_redova, int br_kolona)
{

	
	auto m(KreirajMatricu(br_redova,br_kolona));
	std::cout << "Unesite elemente matrice: "<<std::endl;
	for(int i=0;i<br_redova;i++)
	for(int j=0;j<br_kolona;j++)
	{
		//std::cout << "Element (" <<i+1<<","<<j+1<<"): ";
		std::cin>>m.at(i).at(j);
	}
	return m;
	}
	

int BrojRedova(Matrica m)
{
	return m.size();
}

int BrojKolona(Matrica m)
{
	if(m.size()==0) return 0;
	return m[0].size();
}

Matrica Horzontalno(Matrica m)
{
	Matrica nova(KreirajMatricu(BrojRedova(m),BrojKolona(m)));
	for(int i=0;i<BrojRedova(m);i++)
	{
		int help(0);
		for(int j=BrojKolona(m)-1;j>=0;j--)
		{
			nova.at(i).at(help++)=m.at(i).at(j); 	//zadnji element matrice ide na prvo mjesto ...
		}
	}
	return nova;
}

Matrica Vertikalno(Matrica m)
{
	Matrica nova;
	for(int i=m.size()-1;i>=0;i--)
	{
		for(int j=m.size()-1;j>=0;j--)
		nova.push_back(m.at(j));				//obrcemo redove
	}
	return nova;
}

Matrica Kombinacija(Matrica m)
{
	auto nova(Vertikalno(Horzontalno(m)));
	return nova;
}

Matrica OgledaloMatrica(Matrica m)
{
	Matrica nova(KreirajMatricu(3*BrojRedova(m),3*BrojKolona(m)));
	auto k(Kombinacija(m));
	auto v(Vertikalno(m));
	auto h(Horzontalno(m));
	
	for(int i=0;i<3*BrojRedova(m);i++)  //ogledalo matrica 3mx3n
	{
	for(int j=0;j<3*BrojKolona(m);j++)
	{//prva dva reda
		if(i>=0 && i<BrojRedova(m))
		{
			if(j>=0 && j<BrojKolona(m)) nova.at(i).at(j)=k.at(i).at(j);   //krajnja lijeva matrica
			else if(j>=BrojKolona(m) && j<2*BrojKolona(m)) nova.at(i).at(j)=v.at(i).at(j-BrojKolona(m)); //matrica u sredini
			else if(j>=2*BrojKolona(m) && j<3*BrojKolona(m)) nova.at(i).at(j)=k.at(i).at(j-2*BrojKolona(m)); //krajnja desna
		}
		//druga dva reda
		if(i>=BrojRedova(m) && i<2*BrojRedova(m))
		{
			if(j>=0 && j<BrojKolona(m)) nova.at(i).at(j)=h.at(i-BrojRedova(m)).at(j);
			else if(j>=BrojKolona(m) && j<2*BrojKolona(m)) nova.at(i).at(j)=m.at(i-BrojRedova(m)).at(j-BrojKolona(m));
			else if(j>=2*BrojKolona(m)&& j<3*BrojKolona(m)) nova.at(i).at(j)=h.at(i-BrojRedova(m)).at(j-2*BrojKolona(m));
		}
		//zadnja dva reda
		if(i>=2*BrojRedova(m) && i<3*BrojRedova(m))
		{
			if(j>=0 && j<BrojKolona(m)) nova.at(i).at(j)=k.at(i-2*BrojRedova(m)).at(j);
			else if(j>=BrojKolona(m)&&j<2*BrojKolona(m)) nova.at(i).at(j)=v.at(i-2*BrojRedova(m)).at(j-BrojKolona(m));
			else if(j>=2*BrojKolona(m) && j<3*BrojKolona(m)) nova.at(i).at(j)=k.at(i-2*BrojRedova(m)).at(j-2*BrojKolona(m));
		}
	}
}
return nova;
}
int main ()
{
	try
	{
	int m,n;

	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin>>m>>n;
	
	auto kupus(UnesiMatricu(m,n));
	Matrica ogledalo;
	ogledalo=(OgledaloMatrica(kupus));
	std::cout << "Rezultantna matrica:" << std::endl;
	for(int i=0;i<BrojRedova(ogledalo);i++)
	{
		for(int j=0;j<BrojKolona(ogledalo);j++)
		std::cout << std::setw(4) <<ogledalo.at(i).at(j);
		std::cout<< std::endl;
	}
	}
	catch(std::domain_error izuzetak)
	{
		std::cout << izuzetak.what() << std::endl;
	}
	
	
	return 0;
}