/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <iterator>
#include <stdexcept>

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string tekst){
    std::map<std::string, std::set<int>> mapa;
    for(int i=0;i<tekst.length();i++){
        if(tekst[i]>='A' && tekst[i]<='Z') tekst[i]=std::tolower(tekst[i]);   //pretvaranje cijelog teksta u mala slova
        
    }
    for(int i=0;i<tekst.length();i++){
        std::string rijec;
        while((tekst[i]<'0') || (tekst[i]>'9' && tekst[i]<'a') || tekst[i]>'z') i++;
        if((tekst[i]>='0' && tekst[i]<='9') || (tekst[i]>='a' && tekst[i]<='z')){
            int pozicija=i;
            std::set<int> skup;
            while(((tekst[i]>='a' && tekst[i]<='z') || (tekst[i]>='0' && tekst[i]<='9')) && i<tekst.length()){   //izdvajanje rijeci-rijec je slijed cifara i slova
                rijec.push_back(tekst[i]);                                   
                i++;
            }
            skup.insert(pozicija);           //prvo pojavljivanje rijeci
            mapa.insert(std::make_pair(rijec,skup));      //par u mapi-rijec i pocetna pozicija; kasnije ce biti dodana ostala pojavljivanja rijeci
            for(auto it=mapa.begin();it!=mapa.end();it++){
                if(it->first==rijec) {
                    it->second.insert(i-rijec.length());        //nova pojavljivanja rijeci-dodavanje u skup
                }
            }
        }
    }
    return mapa;
}

std::set<int> PretraziIndeksPojmova(std::string rijec, std::map<std::string, std::set<int>> mapa){
    std::set<int> skup;
    bool postoji(false);
    for(int i=0;i<rijec.size();i++){
        if(rijec[i]>='A' && rijec[i]<='Z') rijec[i]=std::tolower(rijec[i]);
    }
    for(auto it=mapa.begin();it!=mapa.end();it++){
        if(rijec==it->first) {                    //ako je rijec jednaka prvoj iz jednog para mape, mijenja je sa drugom iz istog tog para
            postoji=true;
            skup=it->second;
            break;
        }
    }
    if(postoji==false) throw std::logic_error("Unesena rijec nije nadjena!");
    return skup;
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> mapa){
    for(auto it=mapa.begin();it!=mapa.end();it++){
        std::cout<<it->first<<": ";
        for(auto it1=it->second.begin(); it1!=it->second.end(); it1++){
            if(it1==(--it->second.end())) std::cout<<*it1;          //provjera za posljednji clan
            else std::cout<<*it1<<",";
        }
        std::cout<<std::endl;
    }
}


int main ()
{   std::string tekst;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin, tekst);
    std::map<std::string, std::set<int>> mapa;
    mapa=KreirajIndeksPojmova(tekst);
    IspisiIndeksPojmova(mapa);
    std::set<int> skup;
    std::string rijec;
    while(rijec!="."){
    std::cout<<"Unesite rijec: ";
    std::getline(std::cin,rijec);
    if(rijec==".") break;
        try{
            skup=PretraziIndeksPojmova(rijec,mapa);
            for(auto x: skup){
                std::cout<<x<<" ";
            }
        }
        catch(std::logic_error izuzetak){
            std::cout<<izuzetak.what();
        }
    std::cout<<std::endl;
    }
	return 0;
}