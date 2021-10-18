/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include<map>
#include<string>
#include<vector>
#include<tuple>
#include<set>
std::string mala(std::string s)
{
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='A' && s[i]<='Z') s[i]=s[i]-('A'-'a');
    }
    return s;
}
typedef std::map<std::string, std::vector<std:: string>> Knjiga;
std::map<std::string,std::set<std::tuple<std::string,int,int>>>KreirajIndeksPojmova(Knjiga k)
{
    std::map<std::string,std::set<std::tuple<std::string,int,int>>> mapa;
    std::vector<std::tuple<std::string,std::string,int,int>> v;
    int vel=0;
    for(auto x:k) {
        auto p=x.second.begin();
        int stranica=1;
        while(p!=x.second.end()) {
            for(int i=0; i<(*p).size(); i++) {
                int u=i;
                if(((*p)[i]>='a' && (*p)[i]<='z') or ((*p)[i]>='A' && (*p)[i]<='Z') or ((*p)[i]>='0' && (*p)[i]<='9')) {
                    std::string rijec;
                    for( u=i; u<(*p).size(); u++) {
                        if(((*p)[u]>='a' && (*p)[u]<='z') or ((*p)[u]>='A' && (*p)[u]<='Z') or ((*p)[u]>='0' && (*p)[u]<='9')) {
                            rijec.push_back((*p)[u]);
                        } else break;
                        
                    }
                    vel++;
                    v.resize(vel);
                    v[vel-1]=std::make_tuple(mala(rijec),x.first,stranica,i);
                    
                    i=u;
                }

            }
            p++;
            stranica++;
        }

    }
   
    for(int i=0; i<v.size(); i++) {
        std::tuple<std::string,int,int> t;
        if(std::get<0>(v[i])!="gotovo") {
            t=std::make_tuple(std::get<1>(v[i]),std::get<2>(v[i]),std::get<3>(v[i]));
            mapa[std::get<0>(v[i])].insert(t);
            for(int j=i+1; j<v.size(); j++) {
                if(mala(std::get<0>(v[j]))==mala(std::get<0>(v[i]))) {
                    t=std::make_tuple(std::get<1>(v[j]),std::get<2>(v[j]),std::get<3>(v[j]));
                    mapa[mala(std::get<0>(v[i]))].insert(t);
                    std::get<0>(v[j])="gotovo";
                }
            }
        }
    }

    return mapa;
}
std::set<std::tuple<std::string,int,int>> PretraziIndeksPojmova(std::string rijec,std::map<std::string,std::set<std::tuple<std::string,int,int>>> mapa)
{
    std::set<std::tuple<std::string,int,int>> c;
    for(auto x: mapa) {if(rijec==x.first) return x.second;}
    return c;
}
void IspisiIndeksPojmova(std::map<std::string,std::set<std::tuple<std::string,int,int>>> indeks){
    auto p=indeks.begin();
    while(p!=indeks.end()){
        std::cout<<std::endl<<(*p).first<<": ";
        auto p2((*p).second.begin());
        int br=0;
        while(p2!=(*p).second.end())
        {
            if(br+1!=(*p).second.size())
            std::cout<<std::get<0>(*(p2))<<"/"<<std::get<1>(*(p2))<<"/"<<std::get<2>(*(p2))<<", ";
            else
            std::cout<<std::get<0>(*(p2))<<"/"<<std::get<1>(*(p2))<<"/"<<std::get<2>(*(p2));
            p2++;
            br++;
        }
        
        p++;
    }
}
int main ()
{
    Knjiga k;
    do{
    int i=1;
    
    std::cout<<"Unesite naziv poglavlja: ";
    std::string prostor;
        
        std::getline(std::cin,prostor);
        if(prostor==".") break;
        
    do{
         std::string prostor2;
        std::cout<<"Unesite sadrzaj stranice "<<i<<": ";
        
        std::getline(std::cin,prostor2);
       
        if(prostor2==".") break;
        k[prostor].push_back(prostor2);
        i++;
    }while(1==1);
    }while(1==1);
    std::cout<<"\nKreirani indeks pojmova:";
    auto indeks=KreirajIndeksPojmova(k);
    IspisiIndeksPojmova(indeks);
   do{
    std::cout<<"\nUnesite rijec: ";
    std::string r;
    std::getline(std::cin,r);
    if(r==".") break;
    auto d=PretraziIndeksPojmova(r,indeks);
   if(d.size()==0) std::cout<<"Unesena rijec nije nadjena!";
   else{
    auto p2=d.begin();
        while(p2!=d.end())
        {
           
            std::cout<<std::get<0>(*(p2))<<"/"<<std::get<1>(*(p2))<<"/"<<std::get<2>(*(p2))<<" ";
            
            p2++;
          
        }
   }
   }while (true);
      
   
    return 0;
}
