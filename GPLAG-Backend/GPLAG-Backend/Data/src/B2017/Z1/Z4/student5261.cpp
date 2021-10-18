/*B 2017/2018, Zadaća 1, Zadatak 4
	
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
#include <string>

bool JeLiSlovo(char s)
{
	if((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z')) return true; 
	return false;
}

std::string IzvrniRijec(std::string s)
{
	std::string obrnut;
	for(int i=s.length()-1; i>=0; i--)
	{
		obrnut.push_back(s.at(i));
	}
	return obrnut;
}

std::string NapraviPalindrom(std::string s1, std::vector<std::string> s2)
{
	std::vector<std::string> obrnut;
	obrnut = s2;
	for(int i=0; i<obrnut.size(); i++)
	{
		obrnut.at(i) = IzvrniRijec(obrnut.at(i));
	}
	for(int i=0; i<s2.size(); i++)
	{
		for(int j=0; j<s1.length(); j++)
		{
			if(s2.at(i) == s1.substr(j, s2.at(i).size())&& ((j+s2.at(i).size()<s1.length() && !JeLiSlovo(s1.at(j+s2.at(i).size()))) || (j+s2.at(i).size()==s1.length())) )
			{ 
				int z(j+s2.at(i).size());
				for(int k=0; k<s2.at(i).size(); k++)
				{
					s1 =  s1.substr(0, z) + obrnut.at(i).at(k) + s1.substr(z, s1.size());
					z++;
				}
			}
		}
	}
	return s1;
}

std::string NapraviPoluPalindrom(std::string s1, std::vector<std::string> s2)
{
	for(int i=0; i<s2.size(); i++)
	{
		for(int j=0; j<s1.length(); j++)
		{
			if(s2.at(i) == s1.substr(j, s2.at(i).size())&& ((j+s2.at(i).size()<s1.length() && !JeLiSlovo(s1.at(j+s2.at(i).size()))) || (j+s2.at(i).size()==s1.length())))
			{
				int z(j+s2.at(i).size()/2);
				int k;
				if(s2.at(i).length() % 2 == 0) k=s2.at(i).size()/2-1;
				else k = s2.at(i).size()/2;
				for(; k>=0; k--)
				{
					s1.at(z) = s2.at(i).at(k);
					z++;
				}
			}
		}
	}
	return s1;
}

int main()
{
	std::string s;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, s);
	std::cout << "Unesite fraze: ";
	std::string fraza;
	std::vector<std::string> vektor_fraza;
	do
	{
		std::getline(std::cin, fraza);
		if(fraza.size() == 0) break;
		vektor_fraza.push_back(fraza);
	}while(1);
	std::cout << "Recenica nakon Palindrom transformacije: " << NapraviPalindrom(s, vektor_fraza) << std::endl;
	std::cout << "Recenica nakon PoluPalindrom transformacije: " << NapraviPoluPalindrom(s, vektor_fraza) << std::endl;
	return 0;
}