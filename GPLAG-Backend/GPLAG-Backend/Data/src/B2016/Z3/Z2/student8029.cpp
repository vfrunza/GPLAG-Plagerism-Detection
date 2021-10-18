/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include<string>
#include <vector>
#include <set>
#include <map>

bool da_li_je_slovo(char a)
{
    if(a>='a' && a<='z')
    return true;
    if(a>='A' && a<='Z')
    return true;
    if(a>='0' && a<='9')
    return true;
    
    return false;
    
}

bool da_li_su_iste_rijeci(std::string a,std::string b);

bool prava_rijec(std::string ulaz,int index,std::string popis_rijeci)
{
    std::string temp;
    while (index<ulaz.size() && da_li_je_slovo(ulaz[index])==true ) {
        temp.push_back(ulaz[index]);
        index++;
    }
    return da_li_su_iste_rijeci(temp,popis_rijeci);
}

bool da_li_su_iste_rijeci(std::string a,std::string b)
{
    for(int i=0;i<a.size();i++)
    {
        if(a[i]>='A' && a[i]<='Z')
        {
            a[i]=a[i]+32;
        }
    
    }
    for(int i=0;i<b.size();i++)
    {
        if(b[i]>='A' && b[i]<='Z')
        b[i]=b[i]+32;
    }
    if(a==b)
    return true;
    return false;
}


std::vector<std::string> VratiRijeci(std::string s)
{
     std::vector<std::string> vrati;
     std::string temp;
    for(int i=0;i<s.size();i++)
    {
        
        temp.resize(0);
        while (da_li_je_slovo(s[i])==true && i<s.size()) {
            temp.push_back(s[i]);
            i++;
            
        }
        if(temp.size()!=0)
        vrati.push_back(temp);
        while (da_li_je_slovo(s[i])==false && i<s.size()) {
            i++;
        }
        i--;
        if(i>=s.size())
        return vrati;
    }
    return vrati;
}

bool da_li_je_vec_razmatrana(std::vector<std::string> v,int index)
{
    for(int i=0;i<index;i++)
    {
        if(v[i]==v[index])
        return true;
    }
    return false;
}

std::map<std::string,std::set<int>>KreirajIndeksPojmova(std::string s)
{
    std::map<std::string,std::set<int>> vrati;
    auto popis=VratiRijeci(s);
    for(int i=0;i<popis.size();i++)
    {
        auto razmatrana=da_li_je_vec_razmatrana(popis,i);
        if(razmatrana==false)
        {
            std::set<int>skup;
            for(int j=0;j<s.size();j++)
            {
                if(s[j]==popis[i][0] && (j==0 || da_li_je_slovo(s[j-1])==false))
                {
                    auto temp=prava_rijec(s,j,popis[i]);
                    if(temp==true)
                    {
                        
                        skup.insert(j);
                    }
                }
            }
            vrati.insert(std::make_pair(popis[i],skup));
        }
    }
    return vrati;
}

std::set<int>PretraziIndeksPojmova(std::string ulaz,std::map<std::string,std::set<int>> index_pojmova)
{
    auto it=index_pojmova.find(ulaz);
    if(it==index_pojmova.end())
    throw std::logic_error("Pojam nije nadjen");
    auto vrati=it->second;
    return vrati;
}

void IspisiIndeksPojmova(std::map<std::string,std::set<int>> ulaz)
{
    for(auto it=ulaz.begin();it!=ulaz.end();it++)
    {
        
        auto ime=it->first;
        std::cout<<ime<<": ";
        auto skup=it->second;
        auto i=skup.begin();
        auto kraj=skup.end();
       kraj--;
        for(i=skup.begin();i!=kraj;i++)
        {
            std::cout<<*i<<",";
           
        }
        std::cout<<*i;
        std::cout<<"\n";
    }
    
    
}

int main ()
{
    std::cout<<"Unesite tekst: ";
    std::string recencia;
    std::getline(std::cin,recencia);
    auto ispis=KreirajIndeksPojmova(recencia);
    IspisiIndeksPojmova(ispis);
    while (1) {
        std::cout<<"Unesite rijec: ";
        std::string temp;
        std::getline(std::cin,temp);
        if(temp==".")
        return 0;
        try{
            auto rijec=PretraziIndeksPojmova(temp,ispis);
            for(auto x:rijec )
            std::cout<<x<<" ";
            std::cout<<"\n";
        }
        catch(std::logic_error izuzetak)
        {
            std::cout<<"Unesena rijec nije nadjena!"<<"\n";
        }
    
        
        
    }
	return 0;
}