/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include<string>
#include<map>
#include<set>
bool jeLiBroj(char p)
{
    if(p<='9' && p>='0') return true;
    return false;
}
bool jeLiSlovo(char p)
{
    if(p<='z' && p>='a' || p>='A' && p<='Z') return true;
    return false;
}
std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string pojmovi)
{
    std::map<std::string, std::set<int>> indexPojmova;
    for(int i=0;i<pojmovi.length();i++)
    {
        while(pojmovi[i]==' ' && i<pojmovi.length())
        {
        i++;
        }

        int pocetakPojma=i;
        std::string pojam;
        bool broj=jeLiBroj(pojmovi[i]);
        bool slovo=jeLiSlovo(pojmovi[i]);
        while(broj || slovo)
        {
            if(pojmovi[i]>='A' && pojmovi[i]<='Z')
            pojmovi[i]=pojmovi[i]+'a'-'A';
            pojam+=pojmovi[i];
            i++;
            if(i>=pojmovi.length()) break;
            broj=jeLiBroj(pojmovi[i]);
        slovo=jeLiSlovo(pojmovi[i]);
        }
        if(pojam.length()!=0)
        {
            auto pozicija=indexPojmova.find(pojam);
            //ako ne postoji dodaj ga
            if(pozicija==indexPojmova.end())
            {
                indexPojmova[pojam];
                indexPojmova.at(pojam).insert(pocetakPojma);
            }
            else indexPojmova.at(pojam).insert(pocetakPojma);
        }
    }
    return indexPojmova;
}
std::set<int> PretraziIndeksPojmova(std::string pojam, std::map<std::string, std::set<int>> indexPojmova)
{
    auto pozicija=indexPojmova.begin();
    auto kraj=indexPojmova.end();
    while(pozicija!=kraj)
    {
        if(pojam.compare(pozicija->first)==0)
        {
            return indexPojmova.at(pojam);
        }
        pozicija++;
    }
    throw std::logic_error("Pojam nije nadjen");
}
void IspisiIndeksPojmova(std::map<std::string, std::set<int>> indexPojmova)
{
    auto pozicija=indexPojmova.begin();
    auto kraj=indexPojmova.end();
    while(pozicija!=kraj)
    {
        std::cout<<pozicija->first<<": ";
        auto elementiSkupa=begin(pozicija->second);
        auto krajSkupa=end(pozicija->second);
        int brojElemenata=0;
        while(elementiSkupa!=krajSkupa)
        {
            brojElemenata++;
            elementiSkupa++;
        }
        elementiSkupa=begin(pozicija->second);
        while(brojElemenata!=0)
        {
            if(brojElemenata>1)
            std::cout<<*elementiSkupa++<<",";
            else
            std::cout<<*elementiSkupa;
            brojElemenata--;
        }
        std::cout<<std::endl;
        pozicija++;
    }
}
int main ()
{
    std::cout<<"Unesite tekst: ";
    std::string pojmovi;
    getline(std::cin,pojmovi);
    std::map<std::string, std::set<int>> indexPojmova=KreirajIndeksPojmova(pojmovi);
    IspisiIndeksPojmova(indexPojmova);
    while(true)
    {
        std::cout<<"Unesite rijec: ";
        std::string rijec;
        std::cin>>rijec;
        if(rijec==".") break;
        try {
            auto elementiSkupaPojmova=PretraziIndeksPojmova(rijec, indexPojmova);
            auto pocetak=begin(elementiSkupaPojmova);
            while(pocetak!=end(elementiSkupaPojmova))
             {
                 std::cout<<*pocetak<<" ";
                 pocetak++;
             }

        }
        catch (const std::logic_error e) {
            std::cout <<"Unesena rijec nije nadjena!"<< std::endl;
        }
        std::cout<<std::endl;
    }
	return 0;
}
