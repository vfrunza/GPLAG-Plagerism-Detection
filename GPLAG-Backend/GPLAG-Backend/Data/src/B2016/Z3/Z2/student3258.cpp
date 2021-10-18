/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <utility>
#include <set>
#include <iterator>
#include <map>
#include <stdexcept>

bool JeSlovo(char c)
{
    return (c<='z' && c>='a');
}

bool JeBroj(char c)
{
    return (c<='9' && c>='0');
}

bool NeSmije(char c) 
{
    return (c>='/' && c<='!');
}

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s)
{
    std::map<std::string, std::set<int>> indeks_pojmova;
    int i(0);
    while(i<s.length())
    {
        if(s[i]<='Z' && s[i]>='A') s[i]=s[i]+32;
        i++;
    }
    
    int j(0);
    while(j<s.length()) 
    {
        std::set<int> skup;
        while(s[j]==' ' || s[j]=='\t' || (!JeBroj(s[j]) && !JeSlovo(s[j]))) j++;
        int k(j), br_slova(0);
        skup.insert(j);
        while(JeSlovo(s[k]) || JeBroj(s[k])) {
            k++;
            br_slova++;
        }
        
        int q(k-1);
        while(q<s.length()) {
            int p(j);
            int pamti(j), brojac(0);
            if(s[q]==s[p] && (JeSlovo(s[q]) || JeBroj(s[q])) && (JeSlovo(s[p]) || JeBroj(s[p])) && !NeSmije(s[q]) && !NeSmije(s[p]))
            {
                pamti=q;
                while(s[q]==s[p] && (JeSlovo(s[q]) || JeBroj(s[q])) && !NeSmije(s[p]) && !NeSmije(s[q])  &&(JeSlovo(s[p]) || JeBroj(s[p]))) {
                    brojac++;
                    p++; q++;
                }
            }
            if(j!=0){
            if(brojac==br_slova && !JeSlovo(s[q]) && !JeBroj(s[q]) && (JeSlovo(s[q-1]) || JeBroj(s[q-1])) && !JeSlovo(s[j-1]) && 
            !JeBroj(s[j-1]) && !JeSlovo(s[pamti-1]) && !JeBroj(s[pamti-1])) 
                    skup.insert(pamti);}
            else {
                if(brojac==br_slova && !JeSlovo(s[q]) && !JeBroj(s[q])) skup.insert(pamti);
            }
            q++;
        }
        if(!indeks_pojmova.count(s.substr(j, j+br_slova)))
        indeks_pojmova.insert(std::make_pair(s.substr(j, br_slova), skup));
        while(JeSlovo(s[j]) || JeBroj(s[j])) j++;
        j++;
    }
   
    return indeks_pojmova;
}

std::set<int> PretraziIndeksPojmova(std::string rijec, std::map<std::string, std::set<int>> indeks_pojmova)
{
    auto it(indeks_pojmova.find(rijec));
    if(it==indeks_pojmova.end()) throw std::logic_error("Unesena rijec nije nadjena!");
    else return it->second;
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> indeks_pojmova)
{
    for(auto it=indeks_pojmova.begin(); it!=indeks_pojmova.end(); it++)
    {   
       std::cout << it->first << ": ";
       std::set<int>skup(it->second);
       for(auto it1=skup.begin(); it1!=skup.end(); it1++) {
           auto it2(skup.end());
           it2--;
           std::cout << *it1;
           if(it2!=it1) std::cout << ",";
       }
       std::cout << std::endl;
    }
}

int main ()
{
    std::string tekst;
    std::cout<< "Unesite tekst: ";
    std::getline(std::cin, tekst);
    std::map<std::string, std::set<int>> indeks_pojmova(KreirajIndeksPojmova(tekst));
    IspisiIndeksPojmova(indeks_pojmova);
    std::string rijec;
    std::cout << "Unesite rijec: ";
    std::getline(std::cin, rijec);
    while(rijec!=".")
    {
        try{
        std::set<int>skup(PretraziIndeksPojmova(rijec, indeks_pojmova));
        for(int x : skup) std::cout << x << " ";
        std::cout <<std::endl;
        }
        catch(std::logic_error tekst)
        {
            std::cout << tekst.what() << std::endl;
        }
        std::cout << "Unesite rijec: ";
        std::getline(std::cin, rijec);
    }
	return 0;
}