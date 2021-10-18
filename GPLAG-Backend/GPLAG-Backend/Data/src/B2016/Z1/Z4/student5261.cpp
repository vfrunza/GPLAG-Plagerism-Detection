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

std::string ObrniFraze(std::string s, std::vector<std::string> rijeci)
{
	for(int i=0; i<s.length(); i++)
	{
		if((s[i] >= 'a' || s[i] <= 'z') && (s[i] >= 'A' || s[i] <= 'Z'))
		{
			int p=i;
			while(s[i] != ' ' && i<s.length())
			{
				int k = s[i];
				std::string pomocni = s.substr(p, p-k);
				bool ima = false;
				for(int j=0; j<rijeci.size(); j++)
				{
					if(rijeci[i] == pomocni) pomocni = true;
					if(ima)
					{
						k--;
						while(p < k)
						{
							char m = s[p];
							s[p] = s[k];
							s[k] = m;
							k--;
							p++;
						}
					}
				}
			}	
		}
	}
	return s;
}

int main ()
{
	std::vector<std::string> rijeci;
	std::string fr;
	std::cout << "Unesite recenicu: ";
	std::cin >> fr;
	std::cout << "Unesite fraze: ";
	while(true)
  	{
  	  std::cin.ignore(10000, '\n');
      std::getline(std::cin, fr);
      if(std::cin.peek() == '\n')
        break;
        rijeci.push_back(fr);
  	}
	std::string str = ObrniFraze(fr, rijeci);
	std::cout << "Recenica nakon obrtanja fraza: ";
	for(int i=0; i<str.size(); i++)
	{
		std::cout << str[i] << std::endl;
	}
	
	return 0;
}