/*B 2017/2018, Zadaća 2, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <type_traits>

enum class SmjerKretanja {NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo};

template<typename kont>

kont PjescaniSat(kont a, SmjerKretanja smjer)
{
	for(int i(0);i<a.size();i++)
	{
		for(int j(0);j<a.at(i).size();j++)
		{
				if(a.at(i).size()!=a.at(i).at(j).size())throw std::domain_error("3D matrica nema oblik kocke");
				if(a.at(0).size()!=a.at(i).size())throw std::domain_error("3D matrica nema oblik kocke");
				if(a.size()!=a.at(0).size())throw std::domain_error("3D matrica nema oblik kocke");
		}
	}
	
	if(a.size()%2==0 && a.size()!=0)throw std::length_error("3D kontejner ne zadovoljava uvjet neparnosti");
	if(a.size()==0)return {};
	typename std::remove_reference<decltype(a.at(0))>::type Matrica(a.size());
//	kont v(a.size(),decltype(Matrica)(a.size()));
kont v;
for(int i(0);i<a.size();i++)
{
	v.push_back(Matrica);
}



	//Gore Dolje
	if(a.size()==1)return a;
	if(smjer==SmjerKretanja::GoreDolje)
	{	
		for(int i(0);i<a.size();i++)
		{
			for(int j(0);j<=a.at(i).size()/2;j++)
			{
				for(int k(0);k<a.at(i).size();k++)
				{
					if(k>=j && k<a.size()-j)v.at(i).at(j).push_back(a.at(i).at(j).at(k));
				}
			}
			int A(a.at(i).size()/2);
			int E(1);
			for(int j(a.at(i).size()/2+1);j<a.at(i).size();j++)
			{
				for(int k(0);k<a.at(i).size();k++)
				{
					if(k>=A-E && k<=A+E)v.at(i).at(j).push_back(a.at(i).at(j).at(k));
				}
				E++;
			}
		}
	}
	//Dolje Gore
	if(smjer==SmjerKretanja::DoljeGore)
	{	
		for(int i(0);i<a.size();i++)
		{
			int j(0);
			for(int p(a.at(i).size()-1);p>=a.at(i).size()/2;p--)
			{
				for(int k(0);k<a.at(i).size();k++)
				{
					if(k>=j && k<a.size()-j)v.at(i).at(j).push_back(a.at(i).at(p).at(k));
				}
				j++;
			}
			int A(a.at(i).size()/2);
			int E(1);
			for(int p(a.at(i).size()/2-1);p>=0;p--)
			{
				for(int k(0);k<a.at(i).size();k++)
				{
					if(k>=A-E && k<=A+E)v.at(i).at(j).push_back(a.at(i).at(p).at(k));
				}
				E++;
				j++;
			}
		}
	}
	//Desno Lijevo
	if(smjer==SmjerKretanja::DesnoLijevo)
	{	
		for(int i(0);i<a.size();i++)
		{
			int sklj(0);
			for(int j(0);j<a.at(i).size();j++)
			{
				if(sklj==a.at(i).size())break;
				for(int k(a.at(i).size()-1);k>=0;k--)
				{
					if(k!=a.at(i).size()-1-sklj)continue;
					while(j<a.at(i).size())
					{
						if((j>=sklj && j<a.size()-sklj) || (j>=0+(a.size()-sklj-1) && j<=sklj && sklj>a.size()/2))v.at(i).at(sklj).push_back(a.at(i).at(j).at(k));
						j++;
					}
				}
				j=-1;
				sklj++;
			}
		}
	}
	
	//Lijevo Desno
	if(smjer==SmjerKretanja::LijevoDesno)
	{	
		for(int i(0);i<a.size();i++)
		{
			int sklj(0);
			for(int j(0);j<a.at(i).size();j++)
			{
				if(sklj==a.at(i).size())break;
				for(int k(0);k<a.at(i).size();k++)
				{
					if(k!=0+sklj)continue;
					while(j<a.at(i).size())
					{
						if((j>=sklj && j<a.size()-sklj) || (j>=0+(a.size()-sklj-1) && j<=sklj && sklj>a.size()/2))v.at(i).at(sklj).push_back(a.at(i).at(j).at(k));
						j++;
					}
				}
				j=-1;
				sklj++;
			}
		}
	}
	//Naprijed Nazad
	if(smjer==SmjerKretanja::NaprijedNazad)
	{
		int sklj(0);
		for(int i(0);i<a.size();i++)
		{
			if(sklj==a.size())break;
			for(int j(0);j<a.size();j++)
			{
				if(j!=i)continue;
				while(i<a.size())
				{
					for(int k(0);k<a.at(i).size();k++)
					{
						if((k>=i && k<a.size()-i) || (k>=0+(a.size()-i-1) && k<=i))v.at(sklj).at(i).push_back(a.at(i).at(sklj).at(k));
					}
					i++;
				}
			}
			i=-1;
			sklj++;
		}
	}
	
	//Nazad Naprijed
	if(smjer==SmjerKretanja::NazadNaprijed)
	{
		int sklj(0);
		for(int i(a.size()-1);i>=0;i--)
		{
			if(sklj==a.size())break;
			for(int j(0);j<a.size();j++)
			{
				if(j!=sklj)continue;
				int red(0);
				while(i>=0)
				{
					for(int k(0);k<a.size();k++)
					{
						if((k>=i && k<a.size()-i) || (k>=0+(a.size()-i-1) && k<=i))v.at(sklj).at(red).push_back(a.at(i).at(j).at(k));
					}
					i--;
					red++;
				}
			}
			i=a.size();
			sklj++;
		}
	}
	
	
	
	return v;
}

int main ()
{
	try
	{
		std::cout<<"Unesite dimenziju (x/y/z): ";
		int x;
		std::cin>>x;
		while(x<0)
		{
			std::cout<<"Dimenzija nije ispravna, unesite opet: ";
			std::cin>>x;
		}
		std::vector<std::deque<std::deque<int>>>v(x, std::deque<std::deque<int>>(x));
		std::cout<<"Unesite elemente kontejnera: ";
		for(int i(0);i<v.size();i++)
		{
			for(int j(0);j<v.at(i).size();j++)
			{
				for(int k(0);k<v.size();k++)
				{
					int n;
					std::cin>>n;
					v.at(i).at(j).push_back(n);
				}
			}
		}
		std::cout<<"Unesite smjer kretanja [0 - 5]: ";
		int smjer;
		std::cin>>smjer;
		while(smjer<0 || smjer>5)
		{
			std::cout<<"Smjer nije ispravan, unesite opet: ";
			std::cin>>smjer;
		}
		std::cout<<std::endl;
		if(v.size()%2==0 && v.size()!=0)throw std::length_error("3D kontejner ne zadovoljava uvjet neparnosti");
		auto a(PjescaniSat(v,SmjerKretanja(smjer)));
		std::cout<<"Pjescani sat unesene matrice je:"<<std::endl;
		std::cout<<std::endl;
		for(int i(0);i<a.size();i++)
		{
			for(int j(0);j<a.at(i).size();j++)
			{
				for(int k(0);k<a.at(i).at(j).size();k++)
				{
					if(j<=a.size()/2)
					{
						if((k==0 || k==a.at(i).at(j).size()) && j!=a.at(i).size()-1)std::cout<<std::setw(4*(j+1))<<a.at(i).at(j).at(k);
						else std::cout<<std::setw(4)<<a.at(i).at(j).at(k);
					}
					else
					{
						if((k==0 || k==a.at(i).at(j).size()) && j!=a.at(i).size()-1)std::cout<<std::setw(4*(a.size()-j))<<a.at(i).at(j).at(k);
						else std::cout<<std::setw(4)<<a.at(i).at(j).at(k);
					}
				}
				std::cout<<std::endl;
			}
			std::cout<<std::endl;
		}
		
		
	}
	catch(std::length_error Izuzetak)
	{
		std::cout<<"Izuzetak: "<<Izuzetak.what();
	}
	catch(std::domain_error Izuzetak)
	{
		std::cout<<"Izuzetak: "<<Izuzetak.what();
	}
	
	
	return 0;
}