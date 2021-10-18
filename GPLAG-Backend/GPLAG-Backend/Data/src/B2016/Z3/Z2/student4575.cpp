/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cstring>

using std::cout;
using std::cin;

std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string tekst){
    std::map<std::string,std::set<int>> povratna_mapa;
    //std::set<int> set;
    for(int i=0;i<tekst.length();i++){
        std::set<int> set;
        std::string pomocni{};
        if(tekst[i]>='A' and tekst[i]<='Z') tekst[i]=tekst[i]+32;
        while(!((tekst[i]>='0' and tekst[i]<='9') or (tekst[i]>='a' and tekst[i]<='z'))){
            i++;
        }
        while((tekst[i]>='0' and tekst[i]<='9') or (tekst[i]>='a' and tekst[i]<='z')){
            pomocni.push_back(tekst[i]);
            i++;
        }
        for(int i=0;i<tekst.length();i++){
            std::string pomocni1;
            while(!((tekst[i]>='0' and tekst[i]<='9') or (tekst[i]>='a' and tekst[i]<='z'))){
                i++;
            }
            int zapamti(i);
            while((tekst[i]>='0' and tekst[i]<='9') or (tekst[i]>='a' and tekst[i]<='z')){
                pomocni1.push_back(tekst[i]);
                i++;
            }
            if(pomocni==pomocni1) set.insert(zapamti);
        }
            if(povratna_mapa.count(pomocni)==0) povratna_mapa.insert({pomocni,set});
        
    }
    return povratna_mapa;
}
std::set<int> PretraziIndeksPojmova(std::string word,std::map<std::string,std::set<int>> mapa){
    if(mapa.count(word)==0) throw std::logic_error("Unesena rijec nije nadjena!");
    auto it(mapa.find(word));
    return it->second;
}

void IspisiIndeksPojmova(std::map<std::string,std::set<int>>mapa){
    for(auto it=mapa.begin();it!=mapa.end();it++){
        cout<<it->first<<": ";
        int najveci(0);
        for(auto x: it->second){
            if(x>najveci) najveci=x;
        }
        for(auto x: it->second){
          if(x==najveci) cout<<x;
          else{
            cout<<x<<",";
        }
    } cout<<std::endl;
}
}

int main ()
{   
    std::string tekst;
    cout<<"Unesite tekst: ";
    std::getline(cin,tekst);
    std::string rijec;
    std::map<std::string,std::set<int>> kreiraj;
    kreiraj=KreirajIndeksPojmova(tekst);
    IspisiIndeksPojmova(kreiraj);
    while(1){
    cout<<"Unesite rijec: ";
    cin>>rijec;
    if(rijec==".") break;
    std::set<int> skupich;
    try{
    skupich=PretraziIndeksPojmova(rijec,kreiraj);
    }
    catch(std::logic_error izuzetak){
        cout<<izuzetak.what();
    }
    for(auto x: skupich) cout<<x << " ";
    cout<<std::endl;
    }
	return 0;
}