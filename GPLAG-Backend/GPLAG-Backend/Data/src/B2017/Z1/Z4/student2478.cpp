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

std::string NapraviPalindrom (std::string s, const std::vector<std::string> &v)
{
	for (const auto &f : v) 
	{
		size_t pos = 0;
		while (pos = s.find(f, pos), pos != std::string::npos)
		{
			auto sub = s.substr(pos, f.size());
			for (int k = 0; k < sub.size() / 2; ++k)
				std::swap(sub.at(k), sub.at(sub.size() - 1 - k));
			s.insert(pos + f.size(), sub);
			std::cout << "sub: '" << sub << "'\n";
			pos += f.size() * 2;;
		}
	}
	return s;
}
std::string NapraviPoluPalindrom (std::string s, const std::vector<std::string> &v)
{
	for (const auto &f : v) 
	{
		size_t pos = 0;
		while (pos = s.find(f, pos), pos != std::string::npos)
		{
			auto sub = s.substr(pos, f.size());
			auto subsub = sub.substr(0, (sub.size() + 1) / 2);
			for (int k = 0; k < subsub.size() / 2; ++k)
				std::swap(subsub.at(k), subsub.at(subsub.size() - 1 - k));
			std::cout << "subsub.size " << subsub.size() << std::endl;
			s.replace (pos + subsub.size(), subsub.size(), subsub);
			
			pos += subsub.size();
		} 
	}
	return s;
}
int main ()
{
	std::cout << NapraviPoluPalindrom("Izasla je prva zadaca iz predmeta Tehnike programiranja, a ovih dana ocekujemo i jos zadaca iz drugih predmeta",
	{"zadaca", "Tehnike programiranja", "drugih predmeta"});
}