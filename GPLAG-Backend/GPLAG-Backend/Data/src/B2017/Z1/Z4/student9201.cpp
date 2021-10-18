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

bool Pronalazak_stringa (std::string recenica, int indeks, std::string rijec)
{
	int k = indeks, l = 0;
	
	while (true)																///Provjera istih znakova.
	{
		if (k == recenica.length() || l == rijec.length())
			break;
			
		if (recenica.at(k) != rijec.at(l))
			return false;
			
		k++;
		l++;
	}
	
	if (l < rijec.length())														///Ako je kraj recenice, do nekog dijela prekinuta rijec u recenici.
		return false;
		
	
	k = indeks;																	///Testiranje da li je podstring.
	l = 0;
	
	if (k != 0)
	{
		if (recenica.at(k-1)>='A' && recenica.at(k-1)<='Z')
			return false;
			
		if (recenica.at(k-1)>='a' && recenica.at(k-1)<='z')
			return false;
	}
	
	
	k += rijec.length() - 1;
	
	if (k != recenica.length()-1)
	{
		if (recenica.at(k+1)>='A' && recenica.at(k+1)<='Z')
			return false;
			
		if (recenica.at(k+1)>='a' && recenica.at(k+1)<='z')
			return false;
	}
	
	return true;
}


std::string NapraviPalindrom (std::string recenica, std::vector<std::string> fraze)
{
	
	for (int i{}; i < fraze.size(); i++)
	{
		std::vector<int> pozicije;
		std::string rijec = fraze.at(i);
		int indeks = 0;	
		
		while (indeks < recenica.length())
		{
			if (Pronalazak_stringa(recenica,indeks,rijec) == true)
				pozicije.push_back(indeks);
				
			indeks++;
		}
		
		std::string naopak;
		for (int j{rijec.length()-1}; j>=0; j--)
			naopak.push_back(rijec.at(j));
			
		for (int j{pozicije.size()-1}; j>=0; j--)
			recenica.insert(pozicije.at(j)+rijec.length(), naopak);
		
	}
	
	
	
	return recenica;
}


std::string NapraviPoluPalindrom (std::string recenica, std::vector<std::string> fraze)
{
	for (int i{}; i < fraze.size(); i++)
	{
		std::vector<int> pozicije;
		std::string rijec = fraze.at(i);
		int indeks = 0;	
		
		while (indeks < recenica.length())
		{
			if (Pronalazak_stringa(recenica,indeks,rijec) == true)
				pozicije.push_back(indeks);
				
			indeks++;
		}
		
		
		std::string s;
		
		indeks = rijec.length()/2;
		
		int k = indeks - 1;	
		for (int j{}; j<indeks;j++)
			s.push_back(rijec.at(k--));
			
		for (int j{pozicije.size()-1}; j>=0; j--)
			{
				if (rijec.length()%2 == 0)
					recenica.replace(pozicije.at(j)+indeks,s.length(),s);
				else
					recenica.replace(pozicije.at(j)+indeks+1,s.length(),s);
			}
	}
	
	
	return recenica;
}







int main ()
{
	std::cout<<"Unesite recenicu: ";
	std::string recenica;
	std::getline(std::cin, recenica);
	
	std::cout<<"Unesite fraze: ";
	std::vector<std::string> fraze;
	
	while (true)
	{
		std::string s;
		std::getline(std::cin, s);
		
		if (s.length() == 0)
			break;
			
		fraze.push_back(s);
	}
	
	std::cout<<"Recenica nakon Palindrom transformacije: "<<NapraviPalindrom(recenica,fraze)<<std::endl;
	std::cout<<"Recenica nakon PoluPalindrom transformacije: "<<NapraviPoluPalindrom(recenica,fraze);
	
	
	
	
	
	
	
	return 0;
}