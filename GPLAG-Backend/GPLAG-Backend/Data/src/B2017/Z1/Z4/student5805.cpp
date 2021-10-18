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
#include <string>
#include<vector>
bool Slovo(const char c)
{
	return ((c>='a' && c<='z')||(c>='A' && c<='Z')); 
}
std::string NapraviPalindrom(std::string s,std::vector<std::string> fraze)
{
	for(int i=0;i<fraze.size();i++)
	{
		int duzina=fraze.at(i).size();
		
		for(int j=0;j<s.length()-1;j++)
		{
			if(j+duzina<=s.length())
			{
			
		if((j==0 || !Slovo(s.at(j-1))) && ((j+duzina)==(s.length()) || !Slovo(s.at(j+duzina))))
				{
				std::string rijec;
				for(int b=j;b<j+duzina;b++)
				rijec+=s.at(b);
				if(rijec==fraze.at(i))
					{
						
						s.resize(s.length()+duzina);
						int kraj=j+duzina;
						
						for(int k=s.length()-1;k>kraj;k--)
						{
						
							s.at(k)=s.at(k-duzina);
						}
						for(int k=0;k<duzina;k++)
						{
							s.at(kraj+k)=s.at(kraj-k-1);
						}
						j=kraj+duzina;
					}
				
				}
			}
		}
	}
	return s;
}
std::string NapraviPoluPalindrom(std::string s, std::vector<std::string>fraze)
{
	for(int i=0;i<fraze.size();i++)
	{
		int duzina=fraze.at(i).size();
		
		for(int j=0;j<s.length()-1;j++)
		{
			if(j+duzina<=s.length())
			{
			
		if((j==0 || !Slovo(s.at(j-1))) && ((j+duzina)==(s.length()) || !Slovo(s.at(j+duzina))))
				{
				std::string rijec;
				for(int b=j;b<j+duzina;b++)
				rijec+=s.at(b);
				if(rijec==fraze.at(i))
					{
						if(duzina%2==0)
						{
						int kraj=j+duzina/2;
						for(int k=0;k<duzina/2;k++)
						{
							s.at(kraj+k)=s.at(kraj-k-1);
						}
						
						}
						else
						{
						int kraj=j+duzina/2;
						for(int k=0;k<duzina/2;k++)
						{
							s.at(kraj+k+1)=s.at(kraj-k-1);
						}
							
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
	std::string recenica;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,recenica);
	std::cout<<"Unesite fraze: ";
	std::vector<std::string> v;
	do{
		std::string unos;
        std::getline(std::cin,unos);
        if(unos=="") break;
        v.push_back(unos);
	}while(1);
	std::string pal=(NapraviPalindrom(recenica,v));
	std::cout<<"Recenica nakon Palindrom transformacije: "<<pal<<std::endl;
	std::string pol=(NapraviPoluPalindrom(recenica,v));
	std::cout<<"Recenica nakon PoluPalindrom transformacije: "<<pol;
	return 0;
}