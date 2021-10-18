/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <string>
#include <vector>
#include <iostream>
#include <cctype>
#include <stdexcept>

void IzvrniString( char* pocetak, char* kraj)
{
	for(; pocetak < kraj; ++pocetak, --kraj)
		std::swap(*pocetak, *kraj);
}

std::string ObrniFraze( std::string recenica, std::vector<std::string> fraze)
{
	for( int i = 0; i < int(fraze.size()); ++i)
	{
		int len = fraze[i].size();
		for( int j = 0; j <=int( recenica.size() ) - len; ++j)
			if( recenica[j] == fraze[i][0] && recenica.substr(j, len) == fraze[i])
			{
				IzvrniString(&recenica[j], &recenica[j + len - 1]);
				j += len - 1;
			}
	}
	return recenica;
}

bool jel_slovo( char s )
{
	return std::tolower(s) >= 'a' && std::tolower(s) <= 'z';
}

void provjera_ispravnosti_rijeci( std::vector<std::string> rijeci)
{
	for( int i = 0; i < int(rijeci.size()); ++i)
		for(int j = 0; j < int(rijeci[i].size()); ++j)
			if( !jel_slovo(rijeci[i][j]) )
				throw std::domain_error("Nekorektan izbor rijeci");
}

std::string IzmijeniUPigLatin( std::string recenica,  std::vector<std::string> rijeci)
{
	provjera_ispravnosti_rijeci(rijeci);
	auto prazan = (rijeci.size() == 0U);
	for( int j = 0; j < int(rijeci.size()) || prazan; ++j )
	{
		for(int i = 0; i < int(recenica.size()); ++i)
		{
			bool razmak = true;
			if(!jel_slovo(recenica[i]))
				razmak = true;
			else if( razmak )
			{
				razmak = false;
				int pocetak = i;
				while (i < int(recenica.size()) && jel_slovo(recenica[i]))
					++i;
				if(prazan || recenica.substr(pocetak, i - pocetak) == rijeci[j])
				{
					auto tmp = recenica.substr( pocetak + 1, i - pocetak - 1 ) + recenica[pocetak] + "ay";
					recenica.replace(pocetak, i - pocetak, tmp);
				}
			}
		}
		prazan = false;
	}
	return recenica;
}

int main ()
{
	std::cout << "Unesite recenicu: ";
	std::string s;
	std::getline(std::cin, s);
	std::cout << "Unesite fraze: ";
	std::vector<std::string> rijeci;
	while(true)
	{
		std::string rijec;
		std::getline(std::cin, rijec);
		if(rijec.size() == 0U)
			break;
		rijeci.push_back(rijec);
	}
	try{
		auto str = IzmijeniUPigLatin(s, rijeci);
		std::cout << "Recenica nakon PigLatin transformacije: " << str << '\n';
	}catch(std::domain_error e)
	{
		std::cout << e.what();
	}
	std::cout << "Recenica nakon obrtanja fraza: " << ObrniFraze(s, rijeci);
	return 0;
}