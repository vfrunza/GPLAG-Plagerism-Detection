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
#include <stdexcept>
typedef std::vector<std::string> vektor;
using std::string;

bool slovo(char a)
{
	if((a >= 'A' && a <= 'Z') ||(a >= 'a' && a <= 'z'))
		return true;
	return false;
}

string ObrniFraze (string s, vektor fraze)
{
	int z;
	for(int i=0; i<fraze.size(); i++)
	{
		for(int j=0; j<s.size(); j++)
		{
			if(s.substr(j, fraze[i].size() ) == fraze[i])
				{
					z=j;
					for (int k  = fraze[i].size()-1 ; k >= 0; k--)
					{
						s[j] = fraze[i][k];
						j++;
					}
					j=z;
				}
		}
	} return s;
}
string IzmijeniUPigLatin (string s, vektor rijeci)
{

	for(int i=0; i<rijeci.size(); i++)
	{
		for(int j=0; j<rijeci[i].size(); j++)
		if((rijeci[i][j] > 'Z' && rijeci[i][j] < 'a') || rijeci[i][j] <'A' || rijeci[i][j] > 'z')
			throw std::domain_error("Nekorektan izbor rijeci");
	}
	if(rijeci.size()==0)
	{
		int j(0);
		for(int i = 0; i < s.length(); i++)
		{
			if(!slovo(s[i])) continue;
			while(i < s.length() && !slovo(s[i]))
				i++;
			j = i;
			while(j < s.length() && slovo(s[j]))
				{ j++;}
			char a=s[i];
			int k;
			for(k = i; k < j-1; k++)
				s[k] = s[k+1];
			s[k] = a;
			k++;
			s.insert(s.begin() + k, 'y');
			s.insert(s.begin() + k, 'a');
			i = j+2;
		}
	}
	else
	{
		for (int i=0; i<rijeci.size(); i++)
		{
			for (int j=0; j<s.length(); j++)
			{
				if(s.substr(j, rijeci[i].size()) == rijeci[i] && (rijeci[i].size()+j == s.length() || !slovo(s[rijeci[i].size()+j])) && (j == 0 || !slovo(s[j-1]) ))
				{
					char a=s[j];
					int k;
					for(k=j; k<=j+rijeci[i].size()-2; k++ )
						s[k]=s[k+1];
					s[k]=a;
					k++;
					s.insert(s.begin()+k, 'y');
					s.insert(s.begin()+k, 'a');
				}
			}
		}  
	} return s;
}
int main ()
{
	string s, c;
	vektor v;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin, s);
	std::cout<<"Unesite fraze: ";

	while(1)
	{
		std::getline(std::cin, c);
		if(c.length()<1) break;
		v.push_back(c);
	}
	try {
	std::cout << "Recenica nakon PigLatin transformacije: " << IzmijeniUPigLatin(s, v) << std::endl;
	}
	catch (std::domain_error izuzetak){
		std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
	}
	std::cout << "Recenica nakon obrtanja fraza: " << ObrniFraze(s, v) << std::endl;
}