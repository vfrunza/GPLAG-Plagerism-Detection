/*B 2017/2018, ===TITLE===
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: student3542@etf.unsa.ba.	
*/

#include <iostream>
#include <string>
#include <vector>

std::string Obrni (std::string s)
{
    for (unsigned int i{0}; i < (s.length() + 1) / 2; i++)
        std::swap(s.at(i), s.at(s.length() - i - 1));
    return s;
}

std::string IzmijeniRijec1 (std::string s) { return s + Obrni(s); }

std::string IzmijeniRijec2 (std::string s) 
{ 
    for (unsigned int i{0}; i < (s.length() + 1) / 2; i++)
         s.at(int(s.length()) - i - 1) = s.at(i);
    return s;
}

bool JelSlovo (char slovo) { return !(slovo < 'A' || (slovo > 'Z' && slovo < 'a') || slovo > 'z'); }

std::string NapraviPalindrom (std::string recenica, std::vector<std::string> rijeci)
{
	if (recenica.empty() || rijeci.empty())
        return recenica;
        
    for (const std::string& rijec : rijeci)
       	if (rijec.length())
            for(int j{0}; j < recenica.length() - rijec.length() + 1 && rijec.length() <= recenica.length(); j++)
                if(recenica.substr(j, rijec.length()) == rijec)
                    if ((!j || !JelSlovo(recenica.at(j-1))) && (rijec.length() + j == recenica.length()  ||  !JelSlovo(recenica.at(rijec.length() + j))))
                    {
                        recenica = recenica.substr(0, j) + IzmijeniRijec1(rijec) + recenica.substr(j + rijec.length());
                        j+=2;
                        while ((j < recenica.size()) && !JelSlovo(recenica.at(j)))
                            j++;
                    }
    return recenica;
}

std::string NapraviPoluPalindrom (std::string recenica, std::vector<std::string> rijeci)
{
	if (recenica.empty() || rijeci.empty())
        return recenica;
        
    for (const std::string& rijec : rijeci)
       	if (rijec.length())
            for(int j{0}; j < recenica.length() - rijec.length() + 1 && rijec.length() <= recenica.length(); j++)
                if(recenica.substr(j, rijec.length()) == rijec)
                    if ((!j || !JelSlovo(recenica.at(j-1))) && (rijec.length() + j == recenica.length()  ||  !JelSlovo(recenica.at(rijec.length() + j))))
                    {
                        recenica = recenica.substr(0, j) + IzmijeniRijec2(rijec) + recenica.substr(j + rijec.length());
                        j+=2;
                        while ((j < recenica.size()) && !JelSlovo(recenica.at(j)))
                            j++;
                    }
    return recenica;
}

int _main()
{
    std::string s;
    std::vector<std::string> v;
     
    std::cout<<"Unesite recenicu: ";
    std::getline(std::cin,s);
     
    std::cout<<"Unesite fraze: ";
    while(7)
    {
        std::string ubaci;
        std::getline(std::cin,ubaci);
        if (!ubaci.length()) 
        	break;
        v.push_back(ubaci);
    }
     
  	std::cout << "Recenica nakon Palindrom transformacije: " << NapraviPalindrom(s,v) << std::endl;
    std::cout << "Recenica nakon PoluPalindrom transformacije: " << NapraviPoluPalindrom(s,v) << std::endl;
    
    return 0;
}

int main()
{
    std::string s{"oko sokolovo"};
    std::vector<std::string> v{"oko sokolovo", "oko", "ok"};
     
  	std::cout << NapraviPalindrom(s,v) << std::endl;
    std::cout << NapraviPoluPalindrom(s,v) << std::endl;
    
    return 0;
}