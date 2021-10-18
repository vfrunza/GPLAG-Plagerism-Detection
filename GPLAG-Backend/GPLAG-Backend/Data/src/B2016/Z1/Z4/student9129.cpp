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

std::string ObrniFraze(std::string recenica, std::vector<std::string> fraze)
{
    for (const std::string& fraza : fraze)
       for(int j{0}; j < recenica.length() - fraza.length() + 1 && fraza.length() < recenica.length(); j++)
            if(recenica.substr(j, fraza.length()) == fraza)
                for (int k{0}; k < fraza.length(); k++)
                    recenica.at(k + j) = Obrni(fraza).at(k);
                    
    return recenica;
}

bool JelSlovo (char slovo) { return !(slovo < 'A' || (slovo > 'Z' && slovo < 'a') || slovo > 'z'); }
std::string IzmijeniUPigLatinSve (std::string recenica)
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
                throw std::domain_error("Nekorektan izbor rijeci");
    
    if (recenica.empty())
        return recenica;
        
    if (rijeci.empty())
        return IzmijeniUPigLatinSve(recenica);
        
    for (const std::string& rijec : rijeci)
        if (rijec.length())
            for(int j{0}; j < recenica.length() - rijec.length() + 1 && rijec.length() < recenica.length(); j++)
                if(recenica.substr(j, rijec.length()) == rijec)
                    if ((!j || !JelSlovo(recenica.at(j-1))) && (rijec.length() + j == recenica.length()  ||  !JelSlovo(recenica.at(rijec.length() + j))))
                    {
                        recenica = recenica.substr(0, j) + IzmijeniRijec(rijec) + recenica.substr(j + rijec.length());
                        j+=2;
                        while ((j < recenica.size()) && !JelSlovo(recenica.at(j)))
                            j++;
                    }
    return recenica;
}

#include <exception>

namespace std {
class ZbiiException : public std::exception {
  private:
    std::string err_msg;

  public:
    ZbiiException(const char *msg) : err_msg(msg) {};
    ~ZbiiException() throw() {};
    const char *what() const throw() { return "IZUZETAK"; };
};
}

#define domain_error ZbiiException

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
     
     try{
     
    std::cout << "Recenica nakon PigLatin transformacije: " << IzmijeniUPigLatin(s,v) << std::endl;
     }
     catch(std::domain_error e)
     {
         std::cout << "Izuzetak: " << e.what() << std::endl;
         
     }
    std::cout << "Recenica nakon obrtanja fraza: " << ObrniFraze(s,v) << std::endl;
    
    return 0;
}