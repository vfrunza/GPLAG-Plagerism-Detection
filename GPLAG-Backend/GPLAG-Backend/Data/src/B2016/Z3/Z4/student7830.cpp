/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <string>
#include <stdexcept>

std::vector<std::set<std::string>> Razvrstaj(std::vector<std::string> djeca, int brojtimova)
{
    if(brojtimova < 1 || brojtimova > djeca.size())
        throw std::logic_error("Razvrstavanje nemoguce");
    std::list<std::string> listadjece;
    std::vector<std::set<std::string>> vektimova(brojtimova);
    for(int i = 0; i < djeca.size(); i++)
        listadjece.push_back(djeca[i]);
    std::list<std::string>::iterator it(listadjece.begin()), it2(listadjece.begin());
    int br(djeca.size()/brojtimova);
    std::vector<int> brojutimu(brojtimova, br);
    int trenutnapodjela(brojtimova*br);
    for(int i = 0; i < brojutimu.size(); i++)
    {
        if((djeca.size() - trenutnapodjela) != 0)
        {
            brojutimu[i]++;
            trenutnapodjela++;
        }
        else
            break;
    }
    int trenutnitim(0), brojslova(0), brojpodijeljenih(0);
    while(listadjece.size() > 0)
    {
        std::string tempstr;
        tempstr = *it;
        brojslova = tempstr.size();
        for(int i = 0; i < tempstr.size(); i++)
            if((tempstr[i] < 'a' || tempstr[i] > 'z') && (tempstr[i] < 'A' || tempstr[i] > 'Z') && (tempstr[i] < '0' || tempstr[i] > '9'))
                brojslova--;
        vektimova[trenutnitim].insert(*it);
        brojpodijeljenih++;
        if(brojpodijeljenih == brojutimu[trenutnitim])
        {
            trenutnitim++;
            brojpodijeljenih = 0;
        }
        it = listadjece.erase(it);
        if(it == listadjece.end())
            it = it2;
        it2 = listadjece.begin();
        if(listadjece.size() == 0)
            break;
        for(int i = 1; i < brojslova; i++)
        {
            it++;
            if(it == listadjece.end())
                it = it2;
            
        }
    }
    return vektimova;
}

int main ()
{
    int brojdjece;
    std::cout<<"Unesite broj djece: ";
    std::cin>>brojdjece;
    std::vector<std::string> djeca(brojdjece);
    std::cin.ignore(10000, '\n');
    std::cout<<"Unesite imena djece: ";
    for(int i = 0; i < brojdjece; i++)
        std::getline(std::cin, djeca[i]);
    std::cout<<std::endl<<"Unesite broj timova: ";
    int brojtimova;
    std::cin>>brojtimova;
    try{
    std::vector<std::set<std::string>> timovi(Razvrstaj(djeca, brojtimova));
    for(int i = 0; i < timovi.size(); i++)
    {
        std::cout<<"Tim "<<i+1<<": ";
        int vel(timovi[i].size()), trvel(1);
        for(auto x : timovi[i])
        {
            if(trvel == vel)
                std::cout<<x;
            else
            {
                std::cout<<x<<", ";
                trvel++;
            }
        }
        std::cout<<std::endl;
    }
    }
    catch(std::logic_error x)
    {
        std::cout<<"Izuzetak: "<<x.what();
    }
	return 0;
}