#include <iostream>
#include <string>
#include <vector>

std::string Obrni (std::string s)
{
	std::string obrnuta;
	
	int duzina_strnga=0;
	for (int i=0; i<s.size(); i++) duzina_strnga++;
	
	for (int i=duzina_strnga-1; i>=0 ; i--)
	{
		obrnuta.push_back(s.at(i));
	}
	
	return obrnuta;
}

std::string NapraviPalindrom (std::string s, std::vector<std::string> v)
{
	
	for (int i=0; i < s.size(); i++)
	{
	
		while (s.at(i)==' ')
		{
			s.erase(s.begin()+i);
		}
	}
	
	for (i=0; i<s.size(); i++)
	{
		std::string pomocna;
		int duzina_rijeci=0;
		while (s.at(i)!=' ')
		{
			duzina_rijeci++;
		}
		pomocna=std::substr(i,duzina_rijeci);
		for (int j=0; i<v.size(); j++)
		{
			if (pomocna==v.at(j))
			{
				
			}
		}
	}
}

int main ()
{
	std::string s="abcd";
	
	std::cout << Obrni(s);
	
	return 0;
}