/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stdexcept>
#include <algorithm>
#include <utility>
#include <iterator>
std::map<std::string, std::set<int>>KreirajIndeksPojmova(std::string tekst){
    std::map<std::string, std::set<int>> mapa;
    for(int i=0; i<tekst.length(); i++){
        if(tekst[i]>='A' && tekst[i]<='Z') tekst[i]+=32;
    }
    for(int i=0; i<tekst.length(); i++){
        std::string temp;
        bool found(false);
        if((tekst[i]>='a' && tekst[i]<='z') || (tekst[i]>='0' && tekst[i]<='9')) found=true;
        if(found){
            while(((tekst[i]>='a' && tekst[i]<='z') || (tekst[i]>='0' && tekst[i]<='9')) && i<tekst.size()){
            temp+=tekst[i];
            i++;
            }
            auto it(mapa.find(temp));
            std::set<int> help;
            help.insert(i-temp.length());
            if(it==mapa.end()) mapa.insert(std::make_pair(temp, help));
            else (it->second).insert(i-temp.length());
        }
    }
    return mapa;
}
std::set<int> PretraziIndeksPojmova(std::string rijec, std::map<std::string, std::set<int>> indexi){
    for(auto it=indexi.begin(); it!=indexi.end(); it++) if(rijec==it->first) return it->second;
    throw std::logic_error("Pojam nije nadjen");
}
void IspisiIndeksPojmova(std::map<std::string, std::set<int>> indexi){
    for(auto i=indexi.begin(); i!=indexi.end(); i++){
        std::cout<<i->first<<": ";
        int br(0);
        for(auto j=(i->second).begin(); j!=(i->second).end(); j++){
            br++;
            if(br==std::distance((i->second).begin(), (i->second).end())) std::cout<<*j;
            else std::cout<<*j<<",";
        }
        std::cout<<std::endl;
    }
}
int main ()
{
    try{
        std::cout<<"Unesite tekst: ";
        std::string tekst;
        std::getline(std::cin, tekst);
        auto mapa(KreirajIndeksPojmova(tekst));
        IspisiIndeksPojmova(mapa);
        for(;;){
            std::cout<<"Unesite rijec: ";
            std::string rijec;
            std::getline(std::cin, rijec);
            if(rijec[0]=='.') break;
            try{
                auto me_likey(PretraziIndeksPojmova(rijec, mapa));
                for(auto i: me_likey) std::cout<<i<<" ";
            }
            catch(...){
                std::cout<<"Unesena rijec nije nadjena!";
            }
            std::cout<<std::endl;
        }
    }
    catch(std::domain_error iz){
        std::cout<<iz.what();
    }
    catch(std::logic_error help){
        std::cout<<help.what();
    }
	return 0;
}