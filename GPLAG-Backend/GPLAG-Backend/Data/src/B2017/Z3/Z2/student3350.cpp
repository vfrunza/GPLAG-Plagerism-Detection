/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
typedef std::map<std::string,std::vector<std::string>> Knjiga;
std::string PretvoriUMala(std::string s)
{
    for(int i(0); i<s.length(); i++) {
        if(s[i]>='A'&&s[i]<='Z') s[i]+='a'-'A';
    }
    return s;
}
std::string IzbaciVisak(std::string s)
{
    s=PretvoriUMala(s);
    for(int i(0); i<s.length(); i++) {
        if((s.at(i)<'0'||s[i]>'9')&&(s[i]<'a'||s[i]>'z'))  {
            s.erase(s.begin()+i);
            if(i>0) s.insert(s.begin()+i,' ');
        }
    }
    return s;
}
std::vector<std::string> IzbaciDuple(std::string s,std::multimap<std::string,int>&ma)
{
    std::vector<std::string>v;
    std::vector<int>brojac ;
    s=IzbaciVisak(s);
    s.insert(s.begin()+s.length(),' ');
    std::string s1;
    bool t(false),first_time(true);
    int j(0),br(0);
    for(int i(0); i<s.length(); i++) {
        if(s[i]!=' ') {
            if(first_time) brojac.push_back(br);
            s1.push_back(s[i]);
            j++;
            t=true;
            first_time=false;
            br++;
        }
        if(s[i]==' '&&t==true) {
            first_time=true;
            br++;
            v.push_back(s1);
            s1.resize(0);
            j=0;
            t=false;
        }
    }
    for(int i(0); i<brojac.size(); i++)
        ma.insert({v[i],brojac[i]});
    for(int i(0); i<v.size(); i++)
        for(int j(i+1); j<v.size(); j++)
            if(v.at(i)==v.at(j)) v.erase(v.begin()+j), j--;
    std::sort(v.begin(),v.end());
    return v;
}
std::map<std::string,std::set<std::tuple<std::string,int,int>>> KreirajIndeksPojmova(Knjiga k)
{
    std::multimap<std::string,std::set<std::tuple<std::string,int,int>>>Mapa;
    std::set<std::tuple<std::string,int,int>> skup,pocetni {};
    std::multimap<std::string,int>ma,po_ma {};
    std::tuple<std::string,int,int>t;
    std::vector<std::string>v,v1,v3;
    std::vector<int>v2;
    std::string s,s1;
    for(auto it=k.begin(); it!=k.end(); it++) 
    {
        v=it->second;
   
        for(int i(0);i<v.size();i++)
        {
         s=v[i];
            v1=IzbaciDuple(s,ma);
            for(auto it1=ma.begin(); it1!=ma.end(); it1++) {
                v3.push_back(it1->first);
                v2.push_back(it1->second);
            }
            int isti,isti1(0),pom(0);
            for(int j(0); j<v1.size(); j++) {
                isti=(std::count(v3.begin(),v3.end(),v1[j]));
                for(int l=isti1; l<isti+isti1; l++) {
                    t=std::make_tuple(it->first,i+1,v2[l]);
                    skup.insert(t);
                    pom=l;
                }
                isti1=pom+1;
                Mapa.insert({v1[j],skup});
                skup=pocetni;
            }
            ma=po_ma;
            isti1=0;
            v3.resize(0);
            v2.resize(0);
        }
    } 
    std::map<std::string,std::set<std::tuple<std::string,int,int>>>Nova ;
    bool da(false);
    auto ite(Mapa.begin()),ite1(ite);
    while (ite!=Mapa.end()) {
        std::string s;
        s=ite->first;
        {
        std::set<std::tuple<std::string,int,int>>skup ;
        //for(auto it1=it;it1!=Mapa.end();it1++)
        while (ite1!=Mapa.end()) {
            if(ite1->first==ite->first)
                for(auto x: ite1->second) 
                    skup.insert(x);
            else { da=true; ite=ite1; break; }        
                ite1++;

        }
        if(da) da=false,ite--;
        ite++;
        Nova.insert({s,skup});
        }
    }
    return Nova; 
}
void IspisiIndeksPojmova(std::map<std::string,std::set<std::tuple<std::string,int,int>>> Mapa)
{
        std::tuple<std::string,int,int>zadnji ;
    for(auto it=Mapa.begin();it!=Mapa.end();it++)
    {
        for(auto x:it->second) zadnji=x;
        std::cout << it->first <<": ";
        for(auto x: it->second) 
        {
            std::cout<<std::get<0>(x) <<"/"<<std::get<1>(x)<<"/"<<std::get<2>(x);
            if(x!=zadnji) std::cout << ", ";
        }    
        std::cout  << std::endl;
    }
}

int main ()
{
    std::string stranica,s1("abc qwe stsda abc abc dhi qwe hrkw dhi"),poglavlje;
    Knjiga k;
    std::vector<std::string>v ;
    int i(1);
    do {
        std::cout << "Unesite naziv poglavlja: ";
        std::cin >> poglavlje;
        std::cin.ignore(1000,'\n');
        if(poglavlje==".") break;
        do {
            std::cout << "Unesite sadrzaj stranice "<<i<<": ";
            std::getline(std::cin,stranica);
            if(stranica==".") break;
            v.push_back(stranica);
            i++;
        } while(stranica!=".");
        i=1;
    k.insert({poglavlje,v});
    v.resize(0);
    } while(poglavlje!="."); 
    auto rez=KreirajIndeksPojmova(k);
    std::cout << "\nKreirani indeks pojmova:"<<std::endl;
    IspisiIndeksPojmova(rez);
    std::string rijec;
    std::set<std::tuple<std::string,int,int>>skup ;
    do
    {
        std::cout << "Unesite rijec: ";
        std::getline(std::cin,rijec);
        auto it(rez.find(rijec));
        if(it!=rez.end()&&rijec!=".")
        {
            for(auto x:it->second)
            std::cout << std::get<0>(x)<<"/"<<std::get<1>(x)<<"/"<<std::get<2>(x) <<" ";
            std::cout  << std::endl;
        } 
         if(it==rez.end()&&rijec!=".") std::cout << "Unesena rijec nije nadjena!" << std::endl;
    }
    while (rijec!=".");

    return 0;
}
