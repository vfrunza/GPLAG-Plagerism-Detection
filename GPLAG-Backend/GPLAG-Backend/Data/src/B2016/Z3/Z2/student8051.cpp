/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cctype>
#include <stdexcept>
#include <algorithm>
bool ws(char s){        //  Funkcija koja vraca true ukoliko je znak slovo ili broj.
    if((s>='a'&&s<='z')||(s>='A'&&s<='Z')||(s>='0'&&s<='9')) return true;
    return false;
}
std::map<std::string,std::set<int>>KreirajIndeksPojmova(std::string s)
{
    std::map<std::string,std::set<int>> p;
    for(int i=0;i<s.length();i++){
        if(ws(s[i]))
        {
            std::string word;       //  U "word" vadimo rijeci iz stringa s.
            for(int j=i;j<s.length();j++){
                if(ws(s[j]))
                    word+=std::tolower(s[j]);       //  U "word" ubacujemo mala slova stringa s. 
                if(!ws(s[j])||j==s.length()-1)
                {
                    p[word].insert(i);      //  Nakon sto smo povadili rijec iz stringa s, ubacujemo je u mapu (i poziciju).
                    i=j;
                    break;
                }
            }
        }
    }
    return p;
}
void IspisiIndeksPojmova(std::map<std::string, std::set<int>> m){
    for(auto i=m.begin();i!=m.end();i++)        //  Obicno ispisivanje.
    {
        std::cout<<i->first<<": ";
        for(auto j=i->second.begin();j!=i->second.end();j++)
        {
            if(j==i->second.begin())  std::cout<<*j;
            else
                std::cout<<","<<*j;
        }
        std::cout<<std::endl;
    }
}
std::set<int>PretraziIndeksPojmova(std::string word, std::map<std::string,std::set<int>> m){
    std::transform(word.begin(),word.end(),word.begin(),::tolower);
    auto it(m.find(word));      //  Trazimo datu rijec u mapu. Ako je nadjemo, onda vracamo taj skup, ako ne onda bacamo izuzetak.
    if(it==m.end())
        throw std::logic_error("Pojam nije nadjen");
    else return it->second;
}

int main ()
{                                   //  Obicni main za unos i ispis.
    std::cout<<"Unesite tekst: ";
    std::string s;
    std::getline(std::cin,s);
    auto q(KreirajIndeksPojmova(s));
    IspisiIndeksPojmova(q);
    std::string p;
    while(p!="."){
        p.clear();
        std::cout<<"Unesite rijec: ";
        std::getline(std::cin,p);
        if(p==".")  break;
        try{
            auto skup(PretraziIndeksPojmova(p,q));
            for(auto it=skup.begin();it!=skup.end();it++)
                std::cout<<*it<<" ";
            std::cout<<std::endl;
        }
        catch(std::logic_error izuzetak)
        {
            std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
        }
    }
	return 0;
}