#include <iostream>
#include <string>
#include <map>
#include <set>
#include <iterator>
#include <stdexcept>

void IspisiIndeksPojmova(std::map<std::string,std::set<int>> mapa){
    std::map<std::string,std::set<int>>::iterator it;
    for(it=mapa.begin(); it!=mapa.end(); it++){
        std::cout<<it->first<<": ";
        for(auto i=it->second.begin(); i!=it->second.end(); i++){
            auto pomocni=it->second.end();
            pomocni--;
            if(i!=pomocni) std::cout<<*i<<",";
            else std::cout<<*i;
            }
             std::cout<<std::endl;
        }
}
std::string PretvoriUMala(std::string &s){
    for(int i=0; i<s.size(); i++){
        if(s[i]>='A' && s[i]<='Z') s[i]=s[i]+32;
    }
    return s;
}
std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string s){
        std::map<std::string,std::set<int>> mapa;
        std::map<std::string,std::set<int>>::iterator it;
        std::string rijec;
        std::set<int> pozicija;
        int razmak(0),br_slova(0);
        s=PretvoriUMala(s);
        for(int i=0; i<=s.size(); i++){ //izdvajanje rijeci
            if((s[i]>='a' && s[i]<='z') || (s[i]>=48 && s[i]<=57)){
                rijec.push_back(s[i]);
                razmak=1;
                br_slova++;
            }
            else if(razmak==1){ //nadjena riječ, (i-br_slova)->pozicija
                razmak=0;
                it=mapa.find(rijec);
            if(it==mapa.end()){
                pozicija.insert(i-br_slova);
                mapa.insert(std::make_pair(rijec,pozicija));
            } 
            else if(it!=mapa.end()) it->second.insert(i-br_slova);
                br_slova=0;
                rijec.clear();
            }
                pozicija.clear();
        }
        
         return mapa;
}

std::set<int> PretraziIndeksPojmova(std::string s,std::map<std::string,std::set<int>> mapa){
            std::map<std::string,std::set<int>>::iterator it;
            std::set<int>pozicija;
                it=mapa.find(s);
                if(it!=mapa.end()){
                    for(int x: it->second) pozicija.insert(x);
                }
                else if(it==mapa.end()) throw std::logic_error("Unesena rijec nije nadjena!");
        return pozicija;
}
void IspisiSet(std::set<int>set){
    for(auto x: set) std::cout<<x<<" ";
}
//ispis ne radi,
int main (){
    try{
    std::cout<<"Unesite tekst: ";
    std::string s;
    std::string rijec;
    std::getline(std::cin,s);
    std::map<std::string,std::set<int>> mapa;
    mapa=KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(mapa);
    do{ 
        std::cout<<"Unesite rijec: ";
        std::getline(std::cin,rijec);
        if(rijec==".") break;
        IspisiSet(PretraziIndeksPojmova(rijec,mapa));
        std::cout<<std::endl;
    }while(rijec!=".");
    }catch(std::logic_error e){
        std::cout<<e.what()<<std::endl;
        std::cout<<"Unesite rijec: ";
    }
	return 0;
}