#include <iostream>
#include <iomanip>
#include <vector>	
#include <stdexcept>	//	Zbog izuzetaka.
#include <utility>		//	Zbog move semantike.

typedef std::vector<std::vector<double>> Matrica;
typedef std::vector<double> vektor;

bool Grbava(Matrica v){		//	Funkcija ispituje da li je matrica koja je poslana u funkciji Ogledalo Matrica grbava. Ako jest, onda vraca true, u suprotnom false.
	for(int i=1;i<v.size();i++)
		if(v.at(i).size()!=v.at(i-1).size())
			return true;
	return false;
}

Matrica h(Matrica v){		//	Funkcija koja vraca horizontalnu matricu.
	double p;
	for(int i=0;i<v.size();i++)
	{
		for(int j=0;j<v.at(i).size()/2;j++)
		{
			int n=v.at(0).size();
			p=v.at(i).at(j);
			v.at(i).at(j)=v.at(i).at(n-1-j);
			v.at(i).at(n-1-j)=p;
		}
	}
	return v;
}
Matrica vr(Matrica v){ 		//	Funckija vraca vertikalnu matricu.
	double p;
	for(int i=0;i<v.size()/2;i++)
	{
		for(int j=0;j<v.at(i).size();j++)
		{
			int n=v.size();
			p=v.at(i).at(j);
			v.at(i).at(j)=v.at(n-i-1).at(j);
			v.at(n-1-i).at(j)=p;
		}
	}
	return v;
}
Matrica hv(Matrica v){		//	Funkcija vraca horizontalnu-vertikalnu matricu.
	v=h(v);
	v=vr(v);
	return v;
}

Matrica OgledaloMatrica (Matrica v)
{
	if(Grbava(v))
		throw std::domain_error ("Matrica nije korektna");		//	Bacamo izuzetak...
	if(v.empty())												//	Provjeravamo je li matrica prazna. Ako jest, da je odmah vrati (ovo sa nula redova). 
		return Matrica (0,vektor (0));
	Matrica w(3*v.size(),vektor (3*v.at(0).size()));
	Matrica mh=std::move(h(v)), mvr=std::move(vr(v)), mhv=std::move(hv(v));		//	Uzimamo odmah matrice horizontalne, vertkalne i "mix".
	int m=v.size(), n=v.at(0).size();							// Da se ne bi stalno pisalo v.size() ili v.at(0).size(), ljepse je ovako. 
	for(int i=0;i<m;i++)										// Popunjavamo matricu...
	{															// Izvinite sto ovako neefikasno...
		for(int j=0;j<n;j++)
		{
			w.at(i).at(j)=mhv.at(i).at(j);
			w.at(i).at(j+n)=mvr.at(i).at(j);
			w.at(i).at(j+2*n)=mhv.at(i).at(j);
			w.at(i+m).at(j)=mh.at(i%m).at(j);
			w.at(i+m).at(j+n)=v.at(i%m).at(j);
			w.at(i+m).at(j+2*n)=mh.at(i%m).at(j);
			w.at(i+2*m).at(j)=mhv.at(i).at(j);
			w.at(i+2*m).at(j+n)=mvr.at(i).at(j);
			w.at(i+2*m).at(j+2*n)=mhv.at(i).at(j);
		}
	}
	
	return w;
}

int main ()				// Main u kojem se vrsi unos matrice, try i catch, te ispis. 
{
	std::cout<<"Unesite dimenzije matrice (m n): ";
	int m,n;
	std::cin>>m>>n;
	if(m<0||n<0)
	{
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::cout<<"Unesite elemente matrice:";
	Matrica v(m,vektor (n));
	double k;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
		{
			std::cin>>k;
			v.at(i).at(j)=k;
		}
	try{
	v=std::move(OgledaloMatrica(v));
	std::cout<<std::endl<<"Rezultantna matrica:"<<std::endl;
	for(auto i:v)
	{
		for(auto j:i)
			std::cout<<std::setw(4)<<j;
			
		std::cout<<std::endl;
	}
	}
	catch(std::domain_error izuzetak)
	{
		std::cout<<izuzetak.what();
	}
	return 0;
}