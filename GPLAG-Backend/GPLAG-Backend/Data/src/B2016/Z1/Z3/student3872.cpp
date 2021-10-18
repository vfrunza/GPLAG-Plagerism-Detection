/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
using namespace std;
typedef std::vector<std::vector<double>> Matrica;



void Obrisi(std::vector <double> &v)
{
    for(int i=0;i<v.size();i++)
    {
        v.erase(v.begin()+i);
        i--;
    }
}
void IspisiMatricu(Matrica m)
{
	for(int i=0;i<m.size();i++)
	{
		for(int j=0;j<m[i].size();j++)
		{
			std::cout<<m[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
}
Matrica RastuciPodnizovi(std::vector<double> v)
{
	Matrica m;
	std::vector<double> Pomocni;
	if(v.size()<1) return m;
	for(unsigned int i(0);i<v.size();i++)
	{
		if(i==int(v.size())-1)
		break;
		if(v.at(i)<=v.at(i+1))
		{
			int j(i);
			Pomocni.push_back(v.at(j));
			for(;i<int(v.size())-1 && v.at(i)<=v.at(i+1);i++)
			Pomocni.push_back(v.at(i+1));
		}
		if(!Pomocni.empty())
		{
			m.push_back(Pomocni);
		}
		Obrisi(Pomocni);
		Pomocni.resize(0);
	}
	return m;
}
Matrica OpadajuciPodnizovi(std::vector<double> v)
{
	Matrica m;
	std::vector<double> Pomocni;
	if(v.size()<1) return m;
	for(unsigned int i(0);i<v.size();i++)
	{
		if(i==int(v.size())-1)
		break;
		if(v.at(i)>=v.at(i+1))
		{
			int j(i);
			Pomocni.push_back(v.at(j));
			for(;i<int(v.size())-1 && v.at(i)>=v.at(i+1);i++)
			Pomocni.push_back(v.at(i+1));
		}
		if(!Pomocni.empty())
		m.push_back(Pomocni);
		Obrisi(Pomocni);
		Pomocni.resize(0);
	}
	return m;
}
int main ()
{
	std::vector<double> Vektor;
	int broj_elemenata;
	Matrica Opadajucih;
	Matrica Rastucih;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>broj_elemenata;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0;i<broj_elemenata;i++)
	{
		double  broj;
		std::cin>>broj;
		Vektor.push_back(broj);
	}
	Opadajucih=OpadajuciPodnizovi(Vektor);
	Rastucih=RastuciPodnizovi(Vektor);
	std::cout<<"Maksimalni rastuci podnizovi: ";
	std::cout<<std::endl;
	IspisiMatricu(Rastucih);
	
	std::cout<<"Maksimalni opadajuci podnizovi: ";
	std::cout<<std::endl;
	IspisiMatricu(Opadajucih);
	return 0;
}



