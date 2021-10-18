/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <set>
#include <cctype>
#include <utility>
#include <algorithm>
#include <stdexcept>

std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string s)
{

    std::map<std::string,std::set<int>> kreirana_mapa;
    int pocetak;
    bool pronadjena;
    for(int i=0; i<s.size(); i++) {

        pronadjena=false;
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')) {
            pronadjena=true;
            pocetak=i;
            i++;
        }

        if(pronadjena) {
            while((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9'))
                i++;

            std::string ubaci_rijec;
            ubaci_rijec=s.substr(pocetak,i-pocetak);

            for(int i=0; i<ubaci_rijec.size(); i++) {
                if(ubaci_rijec[i]>='A' && ubaci_rijec[i]<='Z')  ubaci_rijec[i]=tolower(ubaci_rijec[i]);
            }
           
            if(kreirana_mapa.count(ubaci_rijec)>0)    continue;

            std::set<int> skup;
            skup.insert(pocetak);

            int pomoc=i;
            while(pomoc<s.size()) {

                if(((s[pomoc]>='a' && s[pomoc]<='z') || (s[pomoc]>='A' && s[pomoc]<='Z') || (s[pomoc]>='0' && s[pomoc]<='9')) && ((!((s[pomoc-1]>='A' && s[pomoc-1]<='Z') || (s[pomoc-1]>='0'&& s[pomoc-1]<='9') || (s[pomoc-1]>='a' && s[pomoc-1]<='z') )) || pomoc==0 ) && ((pomoc==s.size()-1 ||  (!((s[pomoc-1]>='A' && s[pomoc-1]<='Z') || (s[pomoc-1]>='0'&& s[pomoc-1]<='9') || (s[pomoc-1]>='a' && s[pomoc-1]<='z') ) )))) {
                    int poc=pomoc;
                    int cuvaj=poc;

                    while((s[cuvaj]>='a' && s[cuvaj]<='z') || (s[cuvaj]>='A' && s[cuvaj]<='Z') || (s[cuvaj]>='0' && s[cuvaj]<='9'))
                        cuvaj++;
                    std::string rijec;
                    rijec=s.substr(poc,cuvaj-poc);

                    for(int i=0; i<rijec.size(); i++) {
                        if(rijec[i]>='A' && rijec[i]<='Z')   rijec[i]=tolower(rijec[i]);
                    }


                    if(rijec==ubaci_rijec)
                        skup.insert(poc);
                }

                pomoc++;
            }

            kreirana_mapa.insert(std::make_pair(ubaci_rijec,skup));
            
        }
    }

    return kreirana_mapa;

}

std::set<int> PretraziIndeksPojmova(std::string rijec,std::map<std::string,std::set<int>> mapa)
{

    std::set<int> skup;

{
        for(int i=0;i<rijec.size();i++) {
        if(rijec[i]>='A' && rijec[i]<='Z')  
                rijec[i]=tolower(rijec[i]);}
        
        auto ima_li_ga(mapa.find(rijec));
        if(ima_li_ga==mapa.end()) {
            throw std::logic_error("Pojam nije nadjen");
        }

        auto it(mapa.begin());

        for(auto itt=ima_li_ga->second.begin(); itt!=ima_li_ga->second.end(); itt++)
            skup.insert(*(itt));
    }
    
    return skup;

}

void IspisiIndeksPojmova(std::map<std::string,std::set<int>> mapa)
{

    for(auto it=mapa.begin(); it!=mapa.end(); it++) {
        std::cout<<it->first<<": ";
        int nije_kraj(0);

        for(auto it_skup=it->second.begin(); it_skup!=it->second.end(); it_skup++)  {
            nije_kraj++;
            if(nije_kraj==it->second.size()) std::cout<<*(it_skup);
            else
                std::cout<<*(it_skup)<<",";
        }
        std::cout<<std::endl;

    }

}


int main ()
{

    std::cout<<"Unesite tekst: ";
    std::string s;

    std::getline(std::cin,s);

    std::map<std::string,std::set<int>> moja_mapa=KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(moja_mapa);


    try {
        for(;;) {
            std::string r;
            std::cout<<"Unesite rijec: ";
            std::getline(std::cin,r);
            if(r[0]=='.')
                break;
            
            for(int i=0;i<r.size();i++) {
                if(r[i]>='A' && r[i]<='Z')  
                    r[i]=tolower(r[i]);} 
            auto it=moja_mapa.find(r);
            if(it==moja_mapa.end()) {
                std::cout<<"Unesena rijec nije nadjena!";
                std::cout<<std::endl;
                continue;
            }
            std::set<int> skup_pozicija=PretraziIndeksPojmova(r,moja_mapa);
            auto it_skup=skup_pozicija.begin(); 
            while(it_skup!=skup_pozicija.end()){
                std::cout<<*(it_skup)<<" ";
                it_skup++;
            }
            std::cout<<std::endl;
  
        }
    }

    catch(std::logic_error izuzetak ) {
        std::cout<<izuzetak.what();
    }

    return 0;
}