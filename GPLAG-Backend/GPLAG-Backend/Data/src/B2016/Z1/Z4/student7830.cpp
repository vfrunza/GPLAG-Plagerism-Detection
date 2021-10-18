/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>
#include <string>

void ObrniFraze(std::string &s, std::vector<std::string> rijeci)
{
	for(int i = 0;  i < rijeci.size(); i++)
	{
		int indexp, indexk;
		bool isti(false);
		for(int j = 0; j < s.size(); j++)
		{
			if(s[j] == rijeci[i][0])
			{
				isti = true;
				indexp = j;
				for(int k = 0; k < rijeci[i].size(); k++)
				{
					if(s[indexp+k] != rijeci[i][k])
						isti = false;
					if(k == rijeci[i].size()-1 && isti == true)
						indexk = indexp+k;
				}
			}
			j = indexk;
			int l(0);
			for(int n = indexp; n <= indexk/2; n++)
			{
				std::swap(s[n], s[s.size()-l]);
				l++;
			}
		}
	}
}

int main ()
{
	std::string s("ovo je string :D");
	std::vector<std::string> niz;
	std::string k;
	std::cin>>k;
	niz.push_back(k);
	ObrniFraze(s, niz);
	std::cout<<s;
	return 0;
}