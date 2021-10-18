/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <utility>
#include <stdexcept>

std::string PretvoriUMala(std::string s)
{
    std::string novi;
    for(int i=0; i<s.length(); i++) {
        if(s[i]>='A' && s[i]<='Z') {
            novi.push_back(std::tolower(s[i]));
        } else {
            novi.push_back(s[i]);
        }
    }
    return novi;
}


std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string s1)
{
    std::map<std::string,std::set<int>> mapa;
    std::string s=PretvoriUMala(s1);
    std::string rijeci="";
    int brojac(0);
    int gdje;
    bool razmak(false);
    std::set<int>skup;
    std::set<int>skup1;
    for(int i=0; i<s.length(); i++) {
        brojac++;
    }
    for(int i=0; i<s.length(); i++) {
        if(s[i]==' ' || (s[i]>='!' && s[i]<='/') || (s[i]>=':' && s[i]<='@') || (s[i]>='[' && s[i]<='_') ||(s[i]>='{' && s[i]<='~')) {
            razmak=true;
        } else if((s[i]!=' ' && razmak==false) || (((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) && razmak==false)) {
            rijeci+=s[i];
        } else {
                for(int i=0; i<brojac; i++) {
                    gdje=s.find(rijeci,i);
                    //std::cout<<"Gdje je: "<<gdje<<std::endl;
                    auto it2=s.begin();
                    int brojac2(0);
                    if(gdje!=-1) {
                        while(brojac2!=gdje) {
                            it2++;
                            brojac2++;
                        }
                        if(i!=0) {
                        it2--;
                        }
                        //std::cout<<"It2 je "<<*it2<<std::endl;
                        if(gdje!=0) {
                        if(*it2==' ' || (*it2>='!' && *it2<='/') || (*it2>=':' && *it2<='@'))  {
                            skup.insert(gdje);
                        }
                        }
                        else {
                            skup.insert(gdje);
                        }
                        brojac2=0;
                    
            

                    }
    }

            mapa.insert(std::pair<std::string,std::set<int>>(rijeci,skup));
            skup.clear();
            skup1.clear();
            std::string pomocna_rijec=rijeci;
            rijeci="";
            rijeci+=s[i];
            razmak=false;

        }

    }



  for(int i=0; i<brojac; i++) {
                    gdje=s.find(rijeci,i);
                    auto it2=s.begin();
                    int brojac2(0);
                    if(gdje!=-1) {
                        while(brojac2!=gdje) {
                            it2++;
                            brojac2++;
                        }
                        if(i!=0) {
                        it2--;
                        }
                        //std::cout<<"It2 je "<<*it2<<std::endl;
                        if(gdje!=0) {
                        if(*it2==' ' || (*it2>='!' && *it2<='/') || (*it2>=':' && *it2<='@'))  {
                            skup.insert(gdje);
                        }
                        }
                        else {
                            skup.insert(gdje);
                        }
                        brojac2=0;
                    
            

                    }
    }
                        
                    
    mapa.insert(std::pair<std::string,std::set<int>>(rijeci,skup));


    return mapa;
}

std::set<int> PretraziIndeksPojmova(std::string rijec,std::map<std::string,std::set<int>> mapa)
{
    std::set<int> skup;
    auto it(mapa.find(rijec));
    if(it==mapa.end()) {
        throw std::logic_error ("Unesena rijec nije nadjena!");
    }
    return it->second;
}

void IspisiIndeksPojmova(std::map<std::string,std::set<int>> mapa)
{
    auto it=mapa.begin();
    while(it!=mapa.end()) {
        std::cout<<it->first<<": ";
        int brojac_neki_novi(0);
        for(auto it1(it->second.begin()); it1!=it->second.end(); it1++,brojac_neki_novi++) {
            std::cout<<*it1;
            if(brojac_neki_novi!=it->second.size()-1) {
                std::cout<<",";
            }
    }
        std::cout<<std::endl;
        it++;
    }
}



int main ()
{
//std::cout<<KojaMuJePozicija("lije kisa","ok");
//return 0;
//std::string s("abc qwe stsda abc abc dhi qwe hrkw dhi");
   std::string s;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin,s);
    std::map<std::string,std::set<int>>mapa=KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(mapa);
    std::string rijec;
    while(rijec!=".") {
        if(rijec==".") {
            return 0;
        }
        try {
            std::cout<<"Unesite rijec: ";
            std::cin>>rijec;
            if(rijec==".") {
                return 0;
            }
            auto s=PretraziIndeksPojmova(rijec,mapa);
            for(int x: s) std::cout<<x<<" ";
            std::cout<<std::endl;
        } catch(std::logic_error izuzetak) {
            std::cout<<izuzetak.what()<<std::endl;

        }
    }







    return 0;
}