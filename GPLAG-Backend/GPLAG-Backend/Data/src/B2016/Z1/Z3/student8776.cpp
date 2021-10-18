#include <iostream>
#include <vector>

std::vector<std::vector<double>> RastuciPodnizovi (std::vector<double> v)
{
	if (v.size() == 0)
		return std::vector<std::vector<double>> (0, std::vector<double> (0));
		
		
	std::vector<std::vector<double>> rezultat;
	
	if (v.size() == 1)
		{
			std::vector<double> pomocni;
			pomocni.push_back(v[0]);
			rezultat.push_back(pomocni);
			return rezultat;
		}
	
	for (int i{1};i<v.size();i++)
		{
			
			if (v[i] >= v[i-1])
				{
					std::vector<double> pomocni;
					pomocni.push_back(v[i-1]);
					int j{i};
					for (j;j<v.size();j++)
						{
							if (v[j] >= v[j-1])
								pomocni.push_back(v[j]);
							else
								break;
						}
						
					i = j-1;
					
					rezultat.push_back(pomocni);
				}
		}
	
	
	
	
	return rezultat;
}


std::vector<std::vector<double>> OpadajuciPodnizovi (std::vector<double> v)
{
	if (v.size() == 0)
		return std::vector<std::vector<double>> (0, std::vector<double> (0));
		
		
	std::vector<std::vector<double>> rezultat;
	
	if (v.size() == 1)
		{
			std::vector<double> pomocni;
			pomocni.push_back(v[0]);
			rezultat.push_back(pomocni);
			return rezultat;
		}
	
	for (int i{1};i<v.size();i++)
		{
			
			if (v[i] <= v[i-1])
				{
					std::vector<double> pomocni;
					pomocni.push_back(v[i-1]);
					int j{i};
					for (j;j<v.size();j++)
						{
							if (v[j] <= v[j-1])
								pomocni.push_back(v[j]);
							else
								break;
						}
						
					i = j-1;
					
					rezultat.push_back(pomocni);
				}
		}
	
	
	
	
	return rezultat;
}

int main ()
{
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	
	std::cout<<"Unesite elemente vektora: ";
	std::vector<double> v;
	
	for (int i{};i<n;i++)
		{
			double x;
			std::cin>>x;
			v.push_back(x);
		}
	
	std::cout<<"Maksimalni rastuci podnizovi: ";
	std::cout<<std::endl;
	
	int maksimalna_sirina{};
	std::vector<std::vector<double>> rastuci = RastuciPodnizovi(v);
	for (int i{};i<rastuci.size();i++)
		{
			if (rastuci[i].size() > maksimalna_sirina)
				maksimalna_sirina = rastuci[i].size();
		}
	
	for (int i{};i<rastuci.size();i++)
		{
			bool novi_red {false};
			for (int j{};j<rastuci[i].size();j++)
				{
					if (rastuci[i].size() == maksimalna_sirina)
						{
							novi_red = true;
							std::cout<<rastuci[i][j]<<" ";
						}
				}
			if (novi_red == true)
				std::cout<<std::endl;
		}
		
		std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
		
		maksimalna_sirina = 0;
		std::vector<std::vector<double>> opadajuci = OpadajuciPodnizovi(v);
		for (int i{};i<opadajuci.size();i++)
			{
				if (opadajuci[i].size() > maksimalna_sirina)
					maksimalna_sirina = opadajuci[i].size();
			}
	
		for (int i{};i<opadajuci.size();i++)
			{
				bool novi_red {false};
				for (int j{};j<opadajuci[i].size();j++)
					{
						if (opadajuci[i].size() == maksimalna_sirina)
							{
								novi_red = true;
								std::cout<<opadajuci[i][j]<<" ";
							}
					}
				if (novi_red == true)
					std::cout<<std::endl;
			}
	
	return 0;
}