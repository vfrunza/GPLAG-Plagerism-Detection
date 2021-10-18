/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <string>
#include <vector>

std::string ObrniFraze (std::string s, std::vector<std::string>v)
{
	if(s.lenth()==0)
		return s;
	std::string pom;
	int poc, kra;
	for(int i = 0; i < v.size(); i++)
	{
		pom = v[i];
		//std::cout<<pom;
		for(int j = 0; j < s.length(); j++)
		{
			//std::cout<<j<<" ";
			for(int k = 0; k < pom.length(); k++)
			{
				if(s[j] == pom[k] && (s[j] == s[0] || (s[j-1] == ' ')))
				{
					poc = j;
					//std::cout<<poc;
					while(s[j] == pom[k] && (k != pom.length() && s[j] != ' '))
					{
						j++;
						k++;
						//std::cout<<j<<" "<<k<<" ";
					}
					//std::cout<<j<<" "<<k;
					if(k == pom.length() || s[j] == ' ' || j == s.length())
						kra = j;
						//std::cout<<poc<<" "<<kra;
					for(int g = 0; g < v[i].size()/2; g++)
					{
						char pomocna = pom[g];
						pom[g] = pom[v[i].size() - g - 1];
						pom[v[i].size() - g - 1] = pomocna;
					}
					std::cout<<pom<<" ";
					/*int h = 0;
					for(int g = poc; g < kra; g++)
					{
						//std::cout<<poc<<" "<<kra;
						while(h < pom.size())
						{
							std::cout<<pom[h]<<" ";
							s[g] = pom[h];
							//std::cout<<s[g];
							h++;
							break;
						}
					}*/
				}
			}
			
			//j = kra;
		}
		int h = 0;
			//std::cout<<s<<" "<<pom<<" ";
			for(int g = poc; g < kra; g++)
			{
				while(h < v[i].size())
				{
					s[g] = pom[h];
					h++;
					break;
				}
			}
	}
	return s;
}
int main ()
{
	std::string s("Danas je lijep i suncan dan");
	std::string s1;
	std::vector<std::string>v{"danas", "lijep", "suncan"};
	s1 = ObrniFraze(s, v);
	std::cout<<s1;
	return 0;
}