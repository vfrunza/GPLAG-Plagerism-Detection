/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <stdexcept>
#include <list>
#include <vector>
#include <set>
#include <iterator>

bool JeSlovo(char c)
{
    return ((c<='Z' && c>='A') || (c<='z' && c>='a'));
}

bool JeBroj(char c)
{
    return(c<='9' && c>='0');
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> imena, int br_timova)
{
    std::list<std::string> lista_imena;
    for(int i=0; i<imena.size(); i++) lista_imena.push_back(imena[i]);
    std::vector<std::set<std::string>> vektor_timova;
    int br_djece(imena.size());
    int clanovi(br_djece/br_timova), koliko_prvih(br_djece%br_timova);
    auto it(lista_imena.begin());
    
    for(int i=0; i<br_timova; i++) {
        std::set<std::string> skup;
        int br_slova(0);
        std::string ime(*it);
        int br_clanova(0);
        
        if(i<koliko_prvih) {
            while(br_clanova<clanovi+1) {
                ime=*it;
                skup.insert(ime);
                br_slova=0;
                it=lista_imena.erase(it);
                if(it==lista_imena.end()) it=lista_imena.begin();
                br_clanova++;
                for(int j=0; j<ime.length(); j++)
                {
                    if(ime[j]!='-' && ime[j]!=' ')  br_slova++;
                }
                for(int broj=1; broj<br_slova; broj++) {
                    it++;
                    if(it==lista_imena.end())  it=lista_imena.begin(); 
                }
            }
        }
        else {
            while(br_clanova<clanovi) {
                ime=*it;
                skup.insert(ime);
                br_slova=0;
                br_clanova++;
                it=lista_imena.erase(it);
                if(it==lista_imena.end()) it=lista_imena.begin();
                for(int j=0; j<ime.length(); j++)
                {
                    if(ime[j]!='-' && ime[j]!=' ') br_slova++;
                }
                for(int broj=1; broj<br_slova; broj++) {
                    it++;
                    if(it==lista_imena.end()) it=lista_imena.begin();
                }
            }
        }
        vektor_timova.push_back(skup);
    }
    return vektor_timova;
}

int main ()
{
    try{
    int broj_djece;
    std::cout << "Unesite broj djece: ";
    std::cin >> broj_djece;
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    std::cout << "Unesite imena djece: " << std::endl;
    std::vector<std::string> imena_djece;
    for(int i=0; i<broj_djece; i++)
    {
        std::string rijec;
        std::getline(std::cin, rijec);
        imena_djece.push_back(rijec);
    }
    int broj_timova;
    std::cout << "Unesite broj timova: ";
    std::cin >> broj_timova;
    if(broj_timova<1 || broj_timova>broj_djece) throw std::logic_error("Razvrstavanje nemoguce");
    auto razvrstano(Razvrstavanje(imena_djece, broj_timova));
    for(int i=0; i<razvrstano.size(); i++)
    {
        std::set<std::string> skup(razvrstano[i]);
        std::cout << "Tim " << i+1 << ": ";
        for(auto it1=skup.begin(); it1!=skup.end(); it1++)
        {
            auto it2(skup.end()); it2--;
            std::cout << *it1;
            if(it2!=it1) std::cout << ", ";
        }
        std:: cout << std::endl;
    }
    }
    catch(std::logic_error tekst)
    {
        std::cout << "Izuzetak: " << tekst.what() << std::endl;
    }
	return 0;
}