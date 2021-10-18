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
#include <vector>
std::string Obrnuto(std::string rijec)
{
	std::string vrati;
	for(int i=rijec.length()-1;i>=0;i--)
	{
		vrati.push_back(rijec.at(i));
	}
	return vrati;
}
std::string Pola_obrnuto(std::string rijec)
{
	std::string vrati;
	for(int i=(rijec.length()-1)/2;i>=0;i--)
	{
		vrati.push_back(rijec.at(i));
	}
	return vrati;
}
std::string NapraviPalindrom(std::string recenica,std::vector<std::string> rijeci)
{
	std::string rijec;
	for(int i=0;i<rijeci.size();i++)
	{
		rijec=rijeci.at(i);
		for(int j=0;j<recenica.length();j++)
		{
			int brojac(0),k(0),brojac2(0);
			while(brojac<rijec.length() && (j+k)<recenica.length())
			{
				if(recenica.at(j+k)!=rijec.at(brojac))	break;
				k++;brojac++;brojac2++;
			}
			if(brojac2==rijec.length())
			{
				recenica=recenica.substr(0,j+k) + Obrnuto(rijec) + recenica.substr(j+k,recenica.length());
			}
		}
	}
	return recenica;
}
std::string NapraviPoluPalindrom(std::string recenica,std::vector<std::string> rijeci)
{
	std::string rijec;
	for(int i=0;i<rijeci.size();i++)
	{
		rijec=rijeci.at(i);
		for(int j=0;j<recenica.length();j++)
		{
			int brojac(0),k(0),brojac2(0);
			while(brojac<rijec.length() && (j+k)<recenica.length())
			{
				if(recenica.at(j+k)!=rijec.at(brojac))	break;
				k++;brojac++;brojac2++;
			}
			if(brojac2==rijec.length())
			{
				if(rijec.length()%2==1)
				recenica=recenica.substr(0,j)+recenica.substr(j,(k-1)/2)+ Pola_obrnuto(rijec)+recenica.substr(j+k,recenica.length());
				else
				recenica=recenica.substr(0,j)+recenica.substr(j,(k)/2)+ Pola_obrnuto(rijec)+recenica.substr(j+k,recenica.length());
			}
		}
	}
	return recenica;
}
int main ()
{
	std::string recenica,rijec;
	std::vector<std::string> rijeci;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,recenica);
	std::cout<<"Unesite fraze: ";
	do
	{
		std::getline(std::cin,rijec);
		if(rijec!="")	rijeci.push_back(rijec);
	}while(rijec!="");
	std::cout<<"Recenica nakon Palindrom transformacije: "<<NapraviPalindrom(recenica,rijeci)<<std::endl;
	std::cout<<"Recenica nakon PoluPalindrom transformacije: "<<NapraviPoluPalindrom(recenica,rijeci);
	return 0;
}