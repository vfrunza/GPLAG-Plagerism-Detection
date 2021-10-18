//q:~WHY DO JAVA PROGRAMMERS HAVE TO WEAR GLASSES?
//a:~BECAUSE THEY DON'T C#.

#include <iostream>
#include <vector>

std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> vec)
{
	bool novi{true};
	std::vector<std::vector<double>> podnizovi(1,std::vector<double>(0));
	int i{0};
	if(vec.size()==0)
		return std::vector<std::vector<double>>(0);
	for(int j=0;j<vec.size()-1;j++)
	{
		if(novi==false)
		{
//provjera redom po rastu
			if(vec.at(j)<=vec.at(j+1))
				podnizovi[i].push_back(vec.at(j));
			else
			{
//provjera da li je "ispitanik" pogodan da se doda u niz rastucih, jer je prekid niza
				if(vec.at(j)>=podnizovi[i].at(podnizovi[i].size()-1))
					podnizovi[i].push_back(vec.at(j));
				i++;
				podnizovi.resize(podnizovi.size()+1);
				novi=true;
			}
		}
		else
		{
//takodjer dodatna provjera
			if(vec.at(j)<=vec.at(j+1))
			{
				podnizovi[i].push_back(vec.at(j));
				novi=false;
			}
			else continue;
		}
	}	
	if(podnizovi[podnizovi.size()-1].size()==0)
		podnizovi.resize(podnizovi.size()-1);
//provjera zadnjih clanova, da li je vec(clan) pogodan za niz rastucih
	if(podnizovi.size()>0 && vec.size()>0)
	{
		if(vec.at(vec.size()-1)>=podnizovi[podnizovi.size()-1].at(podnizovi[podnizovi.size()-1].size()-1))
			podnizovi[i].push_back(vec.at(vec.size()-1));
	}
	return podnizovi;
}

std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> vec)
{
	bool novi=true;
	std::vector<std::vector<double>> podnizovi(1,std::vector<double>(0));
	int i{0};
	if(vec.size()==0)
		return std::vector<std::vector<double>>(0);
	for(int j=0;j<vec.size()-1;j++)
	{
		if(novi==false)
		{
//provjera redom po opadanosti
			if(vec.at(j)>=vec.at(j+1))
				podnizovi[i].push_back(vec.at(j));
			else
			{
//provjera da li je "ispitanik" pogodan da se doda u niz opadajucih, jer je prekid niza
				if(vec.at(j)<=podnizovi[i].at(podnizovi[i].size()-1))
					podnizovi[i].push_back(vec.at(j));
				i++;
				podnizovi.resize(podnizovi.size()+1);
				novi=true;
			}
		}
		else
		{
//takodjer dodatna provjera
			if(vec.at(j)>=vec.at(j+1))
			{
				podnizovi[i].push_back(vec.at(j));
				novi=false;
			}
			else continue;
		}
	}
	if(podnizovi[podnizovi.size()-1].size()==0)
		podnizovi.resize(podnizovi.size()-1);
//provjera zadnjih clanova, da li je vec(clan) pogodan za niz opadajucih
	if(podnizovi.size()>0 && vec.size()>0)
	{
		if(vec.at(vec.size()-1)<=podnizovi[podnizovi.size()-1].at(podnizovi[podnizovi.size()-1].size()-1))
			podnizovi[i].push_back(vec.at(vec.size()-1));
	}
	return podnizovi;
}

int main()
{
	int n;
//kreiranje vektora
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	std::vector<double> konstrukt(n);
	for(double &x:konstrukt)
		std::cin>>x;
//maksimalni rastuci
	std::vector<std::vector<double>> max_rastuci{RastuciPodnizovi(konstrukt)};
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	for (const auto &red:max_rastuci)
	{
		for (const auto &i:red)
			std::cout<<i<<" ";
		std::cout << std::endl;
	}
//maksimalni opadajuci
	std::vector<std::vector<double>> max_opadajuci{OpadajuciPodnizovi(konstrukt)};
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for (const auto &red:max_opadajuci)
	{
		for (const auto &i:red)
			std::cout<<i<<" ";
		std::cout << std::endl;
	}
	return 0;
}