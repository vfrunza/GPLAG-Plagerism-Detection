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

std::string Obrni (std::string s)
{
    for (unsigned int i{0}; i < (s.length() + 1) / 2; i++)
        std::swap(s.at(i), s.at(s.length() - i - 1));
    return s;
}

std::string IzmijeniRijec (std::string s) { return s.substr(1) + s.at(0) + "ay"; }
bool JelSlovo (char slovo) { return !(slovo < 'A' || (slovo > 'Z' && slovo < 'a') || slovo > 'z'); }

std::string ObrniFraze(std::string recenica, std::vector<std::string> fraze)
{
    for (const std::string& fraza : fraze)
       for(int j{0}; j < recenica.length() - fraza.length() + 1 && fraza.length() < recenica.length(); j++)
            if(recenica.substr(j, fraza.length()) == fraza)
                for (int k{0}; k < fraza.length(); k++)
                    recenica.at(k + j) = Obrni(fraza).at(k);
    return recenica;
}

std::string IzmijeniUPigLatin(std::string recenica)
{
    for (int i{0}; i < recenica.size(); i++)
    {
        std::string rijec{};
        while ((i < recenica.size()) && !JelSlovo(recenica.at(i)))
            i++;
        while ((i < recenica.size()) && JelSlovo(recenica.at(i)))
            rijec.push_back(recenica.at(i++));
        if (i < recenica.size())
            recenica = recenica.substr(0, i - rijec.size()) + IzmijeniRijec(rijec) + recenica.substr(i);
        i+=2;
    }
    return recenica;
}

std::string IzmijeniUPigLatin(std::string recenica, std::vector<std::string> rijeci)
{
    for (const std::string& s : rijeci)
        for (const char& slovo : s)
            if(!JelSlovo(slovo))
                throw std::domain_error("Neispravne rijeci!");

    for (const std::string& rijec : rijeci)
        for(int j{0}; j < recenica.length() - rijec.length() + 1 && rijec.length() < recenica.length(); j++)
            if(recenica.substr(j, rijec.length()) == rijec)
            {
                recenica = recenica.substr(0, j) + IzmijeniRijec(rijec) + recenica.substr(j + rijec.length());
                j+=2;
                while ((j < recenica.size()) && !JelSlovo(recenica.at(j)))
                    j++;
            }
    return recenica;
}

int main()
{
     std::string s;
     std::vector<std::string> v;
     
     std::cout<<"Unesite recenicu: ";
     std::getline(std::cin,s);
     
     std::cout<<"Unesite fraze: ";
     
     for (int i(0);;i++) {
          std::string ubaci;
          std::getline(std::cin,ubaci);
          if (!ubaci.length()) break;
          v.push_back(ubaci);
     }
     
    std::cout << "Recenica nakon obrtanja fraza: " << ObrniFraze(s,v) << std::endl;
    std::cout << "Recenica nakon PigLatin transformacije: " << IzmijeniUPigLatin(s,v) << std::endl;
    
    /*
    
    try
    {
        std::cout <<  ObrniFraze ("   Danas    je    danas    suncan    jako    lijep    dan    ", {"   Danas    je  ", "dan", "lijep"}) << std::endl;
        std::cout <<  IzmijeniUPigLatin("   Danas    je    danas    suncan    jako    lijep    dan    ") << std::endl;
        std::cout <<  IzmijeniUPigLatin("   Danas    je    danas    suncan    jako    lijep    dan    ", {"danas", "jako", "dan"}) << std::endl;
    }
    catch(std::domain_error e)
    {
        std::cout << e.what();
    }
    */
    return 0;
}