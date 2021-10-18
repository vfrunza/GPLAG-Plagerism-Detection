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
#include <cmath>

struct Planina
{
	int i;
	int j;
	double vrh;
	int dimenzija;
};

bool Jeligrbava(std::vector<std::vector<double>> matrica);

std::vector<Planina> FindPlanine(std::vector<std::vector<double>> matrica);

std::vector<std::vector<double>> NajvecaPlaninaMatrice(std::vector<std::vector<double>> matrica);

int main ()
{
	std::cout<<"Unesite dimenzije matrice (m i n): ";
	int m,n;
	try
	{
		std::cin>>m>>n;
		if(m<0 || n<0) throw std::string("Dimenzije matrice moraju biti nenegativne!");
		std::cout<<"Unesite elemente matrice:";
		std::vector<double> test;
		std::vector<std::vector<double>> matrica;


		for(int i=0,x; i<m; i++)
		{
			for(int j=0; j<n; j++)
			{

				std::cin>>x;
				test.push_back(x);

			}
			matrica.push_back(test);
			test.resize(0);
		}
		matrica= NajvecaPlaninaMatrice(matrica);
		std::cout<<"\nNajveca planina unesene matrice je:\n";
		for(auto veca : matrica)
		{
			for(auto x : veca)
			{
				std::cout<<std::setw(6)<<std::right<<x;
			}
			std::cout<<std::endl;
		}
	}
	catch(std::domain_error izuzetak)
	{
		std::cout<<izuzetak.what();
	}
	catch(std::string izuzetak)
	{
		std::cout<<izuzetak;
	}

	return 0;
}


std::vector<std::vector<double>> NajvecaPlaninaMatrice(std::vector<std::vector<double>> matrica)
{
	try
	{
		if(Jeligrbava(matrica))throw std::domain_error("Matrica nije korektna");
	}
	catch(int a)
	{
		return std::vector<std::vector<double>> (0);
	}

	std::vector<Planina> planine(FindPlanine(matrica));
	int naj=0;
	///pronadji planinu najvece dimenzije
	for(auto x : planine)
	{
		naj=(x.dimenzija>naj)? x.dimenzija:naj;
	}
	///sve manje izbaci
	//std::cout<<"proso1...."<<planine.size()<<".....\n";
	for(int i=0; i<planine.size(); i++)
	{
		if(naj!=planine.at(i).dimenzija)
		{
			planine.erase(planine.begin()+i);
			i--;
		}
	}
	//std::cout<<"proso2........"<<planine.size()<<" .....";
	if(planine.size()>1)
	{

		constexpr double e=0.000000000000001;
		///pronadji najveci vrh medju preostalim
		double drugi=planine.at(0).vrh;
		for(auto x : planine)
		{
			if(x.vrh>drugi)drugi=x.vrh;
		}
		///izbaci s manjim vrhovima
		for(int i=0; i<planine.size(); i++)
		{
			if(!(std::fabs(drugi-planine.at(i).vrh)<e))
			{
				planine.erase(planine.begin()+i);
				i--;
			}
			if(planine.size()-1==i)break;
		}
		//std::cout<<"proso3";

	}
	if(planine.size()>1)
	{


		///pronadji sa najmanjom i koordinatom
		int prva=planine.at(0).i;
		for(auto x : planine)
		{
			if(prva>x.i)prva=x.i;
		}

		///izbaci sve s vecom i koordinatom
		for (int i = 0; i < planine.size(); i++)
		{
			if(prva!=planine.at(i).i)
			{
				planine.erase(planine.begin()+i);
				i--;
			}
			if(planine.size()-1==i)break;
		}
		//std::cout<<"proso4";
	}

	if(planine.size()>1)
	{
		//pronadji sa najmanjom j koordinatom
		int prvaj=planine.at(0).j;
		for(auto x : planine)
		{
			if(x.j<prvaj)prvaj=x.j;
		}

		///izbaci sve sa vecom j koordinatom

		for(int i=0; i<planine.size(); i++)
		{
			if(prvaj!=planine.at(i).j)
			{
				planine.erase(planine.begin()+i);
				i--;
			}
			if(planine.size()-1==i)break;
		}
		//std::cout<<"proso5";
	}

std::vector<std::vector<double>> rjesenje;
std::vector<double> temp;

for(int i=planine.at(0).i-(planine.at(0).dimenzija-1);i<planine.at(0).i+(planine.at(0).dimenzija);i++)
{
	for(int j= planine.at(0).j-(planine.at(0).dimenzija-1); j<planine.at(0).j+(planine.at(0).dimenzija);j++)
	{
		temp.push_back(matrica.at(i).at(j));
	}
	rjesenje.push_back(temp);
	temp.resize(0);
}
	return rjesenje;
}

std::vector<Planina> FindPlanine(std::vector<std::vector<double>> matrica)
{
	std::vector<Planina> planine;
	Planina temp;
	constexpr double e=0.00000000000001;
	for(int i=0; i<matrica.size(); i++)
	{
		for(int j=0; j<matrica.at(i).size(); j++)
		{
			double vrh = matrica.at(i).at(j);

			for(int k=1; k<=matrica.size(); k++)
			{
				if(i+k >= matrica.size() || i-k < 0 || j+k >= matrica.at(i).size() || j-k < 0 )
				{
					temp.i=i;
					temp.j=j;
					temp.dimenzija=k;
					temp.vrh=matrica.at(i).at(j);
				//	std::cout<<"\n was in the right place \n";
					planine.push_back(temp);
					break;
				}
				else
				{
					double suma {0};
					for(int q=-k; q<=k; q++)
					{
						suma += matrica.at(i-k).at(j+q);
						suma += matrica.at(i+k).at(j+q);
						suma += matrica.at(i+q).at(j+k);
						suma += matrica.at(i+q).at(j-k);
					}
					suma -= matrica.at(i+k).at(j+k);
					suma -= matrica.at(i+k).at(j-k);
					suma -= matrica.at(i-k).at(j+k);
					suma -= matrica.at(i-k).at(j-k);

					if(suma>vrh || std::fabs(suma-vrh)<e)
					{
						temp.i=i;
						temp.j=j;
						temp.dimenzija=k;
						temp.vrh=matrica.at(i).at(j);
						planine.push_back(temp);
						break;
					}
					else
					{
						vrh=suma;
					}

				}
			}
			if(j==matrica.at(i).size()-1)break;
		}
		if(i==matrica.size()-1)break;
	}


	return planine;
}

bool Jeligrbava(std::vector<std::vector<double> > matrica)
{
	if(matrica.size()==0)throw 1;
	auto vel=matrica.at(0).size();

	for(auto veca : matrica)
	{
		if((veca.size())!=vel)return true;
	}
	if(vel==0)throw 1;
	return false;
}