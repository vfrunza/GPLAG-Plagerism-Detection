/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <vector> 
#include <set>
#include <stdexcept>
#include <iterator>

//provjeravamo da li je znak slovo ili broj
bool slovo(char s)
{
	if ((s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z') || (s>='0' && s<='9'))
		return true;
	return false;
}

std::string PretvoriUMala(std::string s)
{
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='A' && s[i]<='Z')
            s[i]+=32;
    }
    return s;
}


std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string a)
{
    std::map<std::string,std::set<int>> novo;
    std::set<int> skup;
    std::string help;
    std::string pomoc;
    std::string s(PretvoriUMala(a));
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==' ') continue; //ako je razmak
        else
        {
            if(!slovo(s[i])) continue;
            skup.insert(i);
            while((slovo(s[i])) || s[i]!=' ') //uzimamo rijec
            {
                if(!slovo(s[i]) || s[i]=='\0') break;
                help+=s[i];
                i++;
            }
             for(int j=0;j<s.length();j++) //petlja za pretragu istih rijeci
             {
                if(i==j) continue;
                int k;
                k=j;
                while ((slovo(s[i])) || s[k]!=' ') //uzimamo rijec koju poredimo
                {
                    if(!slovo(s[k]) || s[k]=='\0') break;
                    pomoc+=s[k];
                    k++;
                }
                if(help==pomoc) //ako su isti indeks stavljamo u skup
                {
                    skup.insert(j);
                    pomoc.resize(0);
                    j=k;
                }
                else
                {
                    pomoc.resize(0);
                    j=k;
                    continue;
                }
            }
        }
        novo[help]=skup; //kreiramo par u mapi
        help.resize(0);
        skup.clear();// cistimo skup 
    }
    return novo; 
    
}

std::vector<std::string> NapraviVektorStringova(std::string s)
{
    std::vector<std::string> vektorstringova;
    std::string help;
    for(int i=0;i<s.length();i++)
    {
        while(s[i]!=' ')
        {
            help+=s[i];
            i++;
            if(s[i]=='\0' || s[i]==' ') break;
        }
        if(s[i]==' ' || s[i]=='\0')
            vektorstringova.push_back(help);
        help.resize(0);
    }
    return vektorstringova;
}

std::set<int> PretraziIndeksPojmova(std::string s,std::map<std::string,std::set<int>> mapa)
{
    std::set<int> skup;
    auto v(NapraviVektorStringova(s));
    for(int i=0;i<v.size();i++)
    {
        auto it(mapa.find(v[i])); //trazimo kljucnu rijec
        if(it==mapa.end()) throw std::logic_error ("Pojam nije nadjen");
        else
        {
            skup=mapa[v[i]]; 
        }
    }
    return skup;
}

void IspisiIndeksPojmova(std::map<std::string,std::set<int>> mapa)
{
    for(auto it=mapa.begin();it!=mapa.end();it++)
    {
        std::cout<<it->first<<": ";
        int brojac(0);
        for(auto i=(it->second).begin();i!=(it->second).end();i++)
        {
            brojac++; //brojimo elemente
            if(brojac==std::distance((it->second).begin(),(it->second).end())) std::cout<<*i; //koristimo funkciju distance da saznamo broj elemenata 
                                                                                             //ako je brojac jednak broju elemenata dosli smo na kraj
            else
            std::cout <<*i<<",";
        }
        std::cout <<std::endl;
    }
}
int main()
{
    std::string s;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin,s);
    auto mapa(KreirajIndeksPojmova(s));
    IspisiIndeksPojmova(mapa);
    while (1) 
    {
        std::cout<<"Unesite rijec: ";
        std::string rijec;
        std::getline(std::cin,rijec);
        if(rijec==".") break;
        try
        {
            auto skup(PretraziIndeksPojmova(rijec,mapa)); //moze baciti izuzetak
            for(auto x:skup)
            std::cout<<x<<" ";
        }
        catch(std::logic_error e)
        {
            std::cout<<"Unesena rijec nije nadjena!";
        }
        std::cout<<std::endl;
    }
    
    
    return 0;
}