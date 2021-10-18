#include <iostream>
#include <map>
#include <set>
#include <tuple>
#include <vector>
#include <stdexcept>

std::map<std::string,std::set<std::tuple<std::string,int,int>>> KreirajIndeksPojmova
     (std::map<std::string,std::vector<std::string>>Knjiga){
         
         for(auto it(Knjiga.begin());it!=Knjiga.end();it++){
             
         }
     }
std::map<std::string,std::set<std::tuple<std::string,int,int>>> KreirajIndeksPojmova
     (std::map<std::string,std::vector<std::string>> Knjiga){
         std::map<std::string,std::set<std::tuple<std::string,int,int>>> mapa;
         int br_stranice(0);
         for(auto it(Knjiga.begin());it!=Knjiga.end();it++){
             br_stranice++;
             std::vector<std::string> v1(it->second);
             int razmak(0),brojac(0),brojac1(0);
             for(int i(0);i<v1.size();i++){
                 std::string s(v1[i]);
                 for(int j(0);j<s.length();j++){
                 if(s[j]==' '){
                     razmak=0;
                     //std::set<std::tuple<std::string,int,int>> skup;
                     //skup.insert(std::tie(it->first,br_stranice,brojac));
                     if(br==0){
                     std::string s1(s.substr(brojac,brojac1));
                     for(int k(0);k<s1.length();k++){
                         if(s1[k]>='A' && s1[k]<='Z')
                         s1[k]=s1[k]+32;
                     }
                     }
                     //for(auto it1=mapa.begin();it1!=mapa.end();it1++){
                       //  if(mapa.count(s1)){
                             
                        // }
                     //}
                     //mapa.insert(std::make_pair(s1,skup));
                     br+=1;
                     }else if(s[j]!=' ' && razmak==1){
                     razmak=0;
                     brojac=brojac1;
                 }
                 brojac1++;
            }
        }
    }
    return mapa;
}

std::set<std::tuple<std::string,int,int>> PretraziIndeksPojmova(std::string s,std::map<std::string,std::set<std::tuple<std::string,int,int>>> Indeks_p){
    std::set<std::tuple<std::string,int,int>> t;
    if(Indeks_p.count(s)){
        t=Indeks_p[s];
    }else{
        throw std::logic_error("Pojam nije nadjen");
    }
    return t;
}

void IspisiIndeksPojmova(std::map<std::string,std::set<std::tuple<std::string,int,int>>> Indeks_p){
    
    std::vector<std::string> v;
    for(auto it(Indeks_p.begin());it!=Indeks_p.end();it++){
        int br(0);
        int a(1);
        for(int i(0);i<v.size();i++){
            if(it->first==v[i]){
                a=0;
            }
        }
        if(a){
        for(auto it1(Indeks_p.begin());it1!=Indeks_p.end();it1++){
            br=0;
            std::set<std::tuple<std::string,int,int>> t;
            if(it==it1 && br==0){
                t=Indeks_p[it1->first];
                std::cout<<it->first<<": ";
                for(auto x: t){
                std::cout<<std::get<0>(x)<<"/"<<std::get<1>(x)<<"/"<<std::get<2>(x);
                }
                br+=1;
            }else if(it==it1 && br>0){
                t=Indeks_p[it1->first];
                for(auto x: t){
                std::cout<<","<<std::get<0>(x)<<"/"<<std::get<1>(x)<<"/"<<std::get<2>(x);
                std::cout<<std::endl;
                }
            }
        }
        v.push_back(it->first);
      }
        
    }
}

int main(){
    std::string naziv_p,sadrzaj_stranice,tr_rijec;
    std::vector<std::string> v1;
    std::map<std::string,std::vector<std::string>>mapa;
    int i(1);
    std::cout<<"Unesite naziv poglavlja: ";
    std::getline(std::cin,naziv_p);
    std::cout<<"Unesite sadrzaj stranice 1:";
    std::getline(std::cin,sadrzaj_stranice);
    v1.push_back(sadrzaj_stranice);
    while(sadrzaj_stranice!="."){
    std::cout<<"Unesite sadrzaj stranice "<<i+1<<":";
    std::getline(std::cin,sadrzaj_stranice);
    v1.push_back(sadrzaj_stranice);
    mapa.insert(std::make_pair(naziv_p,v1));
    i++;
    }
    while(v1.size()!=0){
        v1.erase(v1.begin()+0);
    }
    for(; ;){
        std::cout<<"Unesite naziv poglavalja: ";
        std::getline(std::cin,naziv_p);
        if(naziv_p==".")break;
        std::cout<<"Unesite sadrzaj stranice: "<<i+1<<":";
        std::getline(std::cin,sadrzaj_stranice);
        while(sadrzaj_stranice!="."){
            std::cout<<"Unesite sadrzaj stranice "<<i+1<<":";
            std::getline(std::cin,sadrzaj_stranice);
            v1.push_back(sadrzaj_stranice);
            i++;
        }
        mapa.insert(std::make_pair(naziv_p,v1));
        while(v1.size()!=0){
            v1.erase(v1.begin()+0);
        }
        i++;
    }
    std::map<std::string,std::set<std::tuple<std::string,int,int>>>mapa1(KreirajIndeksPojmova(mapa));
    IspisiIndeksPojmova(mapa1);
    std::cout<<"Unesite rijec: ";
    std::getline(std::cin,tr_rijec);
    if(tr_rijec=="."){
        return 0;
    }
    while(tr_rijec!="."){
        std::set<std::tuple<std::string,int,int>>skup(PretraziIndeksPojmova(tr_rijec,mapa1));
        for(auto x: skup){
            std::cout<<std::get<0>(x)<<"/"<<std::get<1>(x)<<"/"<<std::get<2>(x);
        }
        std::cout<<std::endl;
        std::cout<<"Unesite rijec: ";
        std::getline(std::cin,tr_rijec);
    }
    return 0;
}