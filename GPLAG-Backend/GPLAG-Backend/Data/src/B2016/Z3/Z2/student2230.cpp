/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>

std::string PojediSpaceove(std::string string){
   /* auto pok=string.begin();
    int brojac(0);
    int brojac2(0);
    int a(0);
    auto pok2=string.begin();
    auto pok3=string.end();
    std::string novi;
    while(pok !=pok3 && pok2!=pok3){
        while(*pok2!=' ' && pok2!=pok3){    // ja   sam mala palacink
            brojac++;
            pok2++;
        }
        while(*pok2==' ' && pok2!=pok3){
            pok2++;
            brojac2++;
        }
        pok=pok2;
        novi+=string.substr(a,brojac)+" ";
        a=a+brojac+brojac2;
        brojac=0;
        brojac2=0;
    }*/
    std::string novi=string+" ";
    return novi;
}

std::vector<std::string> IzdvojiRijeciUVektor(std::string string,std::vector<std::set<int>> &sett){
    std::vector<std::string> vektor;
    string=PojediSpaceove(string);
    auto it1=string.begin();
    auto it2=string.end();
    int brojac(0);
    int k(0);
    while(it1!=it2){
        if((*it1>='a' && *it1<='z') || (*it1>='0' && *it1<='9')){
            brojac++;
            if((it1+1)==it2){
                std::string rijec=string.substr(k,brojac);
                vektor.push_back(rijec);
            }
        }
        
        else{
            bool postoji(false);
            int b(0);
            std::string rijec=string.substr(k,brojac);
            if(rijec!=""){
            for(int i(0);i<vektor.size();i++){
                if(rijec==vektor[i]){
                    postoji=true;
                    b=i;
                    break;
                }
            }
            std::set<int> pomocni;
            pomocni.insert(k);
            if(postoji==false) {vektor.push_back(rijec); sett.push_back(pomocni);}
            else{
                sett[b].insert(k);
            }}
            k+=brojac+1;
            brojac=0;
            postoji=false;
            }
        it1++;    
        }
    return vektor;
}

std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string string){
    std::map<std::string,std::set<int>> mapa;
    for(auto &c: string) c=tolower(c);
    std::vector<std::set<int>> sett;
    std::vector<std::string> vektorstringova=IzdvojiRijeciUVektor(string,sett);
    for(int i(0);i<vektorstringova.size();i++){
        mapa[vektorstringova[i]]=sett[i];
    }
    return mapa;
}

std::set<int> PretraziIndeksPojmova(std::string rijec,std::map<std::string,std::set<int>> mapa){
    std::set<int> sett;
    bool postoji(false);
    for(auto it=mapa.begin();it!=mapa.end();it++){
        if(rijec==(it->first)){
            auto x = it->second;
            sett=x;
            postoji=true;
        }
    }
    if(!postoji) throw std::logic_error("Pojam nije nadjen");
    return sett;
}

void IspisiIndeksPojmova(std::map<std::string,std::set<int>> mapica){
    for(auto it=mapica.begin();it!=mapica.end();it++){
        std::cout<<it->first<<": ";
        auto it3=(it->second).begin();
        int brojac(0);
        for(auto it2=(it->second).begin();it2!=(it->second).end();it2++){
            brojac++;
            it3++;
            if(brojac==(it->second).size()) std::cout<<*it2;
            else std::cout<<*it2<<",";
        }
        std::cout<<std::endl;
    }
}


int main ()
{
    std::string s;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin,s);
    std::map<std::string,std::set<int>> mapica;
    mapica=KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(mapica);
    for(;;){
    std::cout<<"Unesite rijec: ";
    std::string rijec;
    std::getline(std::cin,rijec);
    if(rijec==".") break;
    std::set<int> setara;
    try{
    setara=PretraziIndeksPojmova(rijec,mapica);
    for(auto ite=setara.begin();ite!=setara.end();ite++){
        std::cout<<*ite<<" ";
             }
    std::cout<<std::endl;
        }
    catch(...){
        std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
    }}
	return 0;
}