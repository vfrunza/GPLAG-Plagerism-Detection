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
#include<algorithm>
#include<string>
#include<vector>

int PronadjiPoklapanje (const std::string &s,const std::string &trazeni) {
	int brojac(0);
	for(int i(0);i<s.length();i++) {
		brojac=0 ;
		if(s.at(0) == trazeni.at(0) || (s.at(i)==trazeni.at(0) && s.at(i-1)==' '))
		{
			for(int j(i), k(0);k < trazeni.length();j++, k++) {
				if(j >= s.length()) break;
				if(j+1 < s.length() && s.at(j) == s.at(j + 1)) brojac++;
				if(s.at(j)==trazeni.at(k)) brojac++;
				if(brojac == trazeni.length() && (j+1 != s.length() && s.at(j+1) != ' ' && s.at(j+1) != ',' && s.at(j+1) != '.'&& s.at(j+1) != ';'
				&& s.at(j+1) != ':' && s.at(j+1) != '"')) brojac++;
                if(s.at(j)!=trazeni.at(k)) break;
		}
			if(brojac == trazeni.length()) return i;
		}
	}
	return s.length();
}
std::string OkreniString(const std::string &s)
{
	std::string pomocni;
	for(int i(s.length()-1); i >= 0; i--) pomocni += s.at(i);
	return pomocni;
}
std::string PrviDio(const std::string &s, int pozicija)
{
	std::string pomocni;
	for(int i(0); i < pozicija; i++) pomocni += s.at(i);
	return pomocni;
}
std::string DrugiDio(const std::string &s, int drugapozicija)
{
	std::string pomocni;
	for(int i(drugapozicija); i < s.length(); i++) pomocni += s.at(i);
	return pomocni;
}
bool ImaLiPoklapanja(const std::string &s, std::vector<std::string> v)
{
    int brojac(0);
	for(int i(0); i < v.size(); i++)
	{
		std::string pomocni(v.at(i));
		int pomocna(PronadjiPoklapanje(s, pomocni));
		if(pomocna == s.length()) brojac++;
	}
	if (brojac == v.size()) return false;
	return true;
}
std::string NapraviPalindrom(const std::string &s, std::vector<std::string> v)
{
	std::string povratni(s);
	if(v.size() == 0) return s;
	if(!ImaLiPoklapanja(s, v)) return s;
	for(int i(0); i < v.size(); i++)
	{
		std::string trazeni(v.at(i));
		int pomocni(PronadjiPoklapanje(povratni, trazeni));
		if(pomocni == povratni.length()) continue;
		else
		{
			std::string okrenuti(OkreniString(trazeni));
			povratni = PrviDio(povratni, pomocni) + trazeni + okrenuti + DrugiDio(povratni, pomocni + trazeni.length());
			i--;
		}
	}
	return povratni;
}
std::string NapraviPoluPalindrom(const std::string &s, std::vector<std::string> v)
{
	std::string povratni(s);
	if(v.size() == 0) return s;
	if(!ImaLiPoklapanja(s, v)) return s;
	for(int i(0); i < v.size(); i++)
	{
		std::string trazeni(v.at(i));
		int pomocni(PronadjiPoklapanje(povratni, trazeni));
		if(pomocni == povratni.length()) continue;
		else
		{
			std::string modifikovani;
			for(int i(0); i < trazeni.length()/2; i++) modifikovani.push_back(trazeni.at(i));

			std::string okrenuti(OkreniString(modifikovani));
			if(trazeni.length()%2 != 0)
            povratni = PrviDio(povratni, pomocni) + modifikovani +trazeni.at(trazeni.length()/2) + okrenuti + DrugiDio(povratni, pomocni + trazeni.length());
			else povratni = PrviDio(povratni, pomocni) + modifikovani + okrenuti + DrugiDio(povratni, pomocni + trazeni.length());
			i--;
		}
	}
	return povratni;
}

int main ()
{
	std::string n ;
	std::cout<<"Unesite recenicu: " ;
	std::getline(std::cin,n);
	std::cout<<"Unesite fraze: " ;
	std::vector<std::string> s;

	do {
		std::string d;
		std::getline(std::cin,d) ;
		if(d.length() == 0) break ;
		if (d.length() != 0) s.push_back(d);

	} while(1) ;

	std::cout<<"Recenica nakon Palindrom transformacije: "<<NapraviPalindrom(n,s)<<"\n";
	std::cout<<"Recenica nakon PoluPalindrom transformacije: "<<NapraviPoluPalindrom(n,s) ;
	return 0;
}


