#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <stdexcept>
void Znak(std::string &rijec){
    for(int i=0;i<rijec.size();i++){
        rijec[i]=tolower(rijec[i]);
    }
}
bool ProvjeriZnak(char &znak){
    if((tolower(znak)<='z' && tolower(znak)>='a') || (znak>='0' && znak<='9'))return true;
    return false;
}
bool ProvjeriRijec(std::string recenica,int rd,int p){
    if(p==0 && ProvjeriZnak(recenica[p+rd]) == false)return true;
    else if(p+rd==recenica.size() && ProvjeriZnak(recenica[p-1])==false)return true;
    else if(ProvjeriZnak(recenica[p-1])==false && ProvjeriZnak(recenica[p+rd])==false)return true;
    return false;
}
std::vector<std::string> KreirajVektorRijeci(std::string recenica){
    std::vector<std::string> vrati;
    std::string rijec;
    for(int i=0;i<recenica.size();i++){
        if(ProvjeriZnak(recenica[i])==false){
            continue;
        }
        else{
            while(ProvjeriZnak(recenica[i])==true){
                  rijec.push_back(recenica[i]);
                  i++;
                  }
        }
        bool c(false);
        for(int k=0;k<vrati.size();k++){
            if(vrati[k]==rijec){
                c=true;
            }
        }
        if(c==false){
           vrati.push_back(rijec);
        }
        rijec.resize(0);
    }
    return vrati;
}
std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string recenica){
    std::map<std::string,std::set<int>> vrati;
    Znak(recenica);
    auto vs=KreirajVektorRijeci(recenica);
    for(int i=0;i<vs.size();i++){
        std::set<int> skup;
        for(int j=0;i<recenica.size();j++){
        Znak(vs[i]);
        auto p=recenica.find(vs[i],j);
        j=p;
        if(j>recenica.size())break;
        if(ProvjeriRijec(recenica,vs[i].size(),j))skup.insert(p);
        }
    Znak(vs[i]);
    vrati.insert(std::make_pair(vs[i],skup));
    }
Znak(recenica);
return vrati;
}
std::set<int> PretraziIndeksPojmova(std::string rijec,std::map<std::string,std::set<int>> mapa){
    Znak(rijec);
    std::map<std::string,std::set<int>>::iterator pocetak(mapa.begin());
    while(pocetak!=mapa.end()){
        if(pocetak->first==rijec){
            return pocetak->second;
        }
        pocetak++;
    }
    throw std::logic_error("Pojam nije nadjen");
}
void IspisiIndeksPojmova(std::map<std::string,std::set<int>> mapa){
    std::map<std::string,std::set<int>>::iterator setac(mapa.begin());
    while(setac!=mapa.end()){
    std::cout<<setac->first<<": ";
    auto setac2=setac->second.begin();
        while(setac2!=setac->second.end()){
            std::cout<<*setac2;
            setac2++;
            if(setac2!=setac->second.end())std::cout<<",";
        }std::cout<<std::endl;
    setac++;
    }
}
int main()
{
    std::string recenica;
    std::cout<<"Unesite tekst: ";
    getline(std::cin,recenica,'\n');
    auto mapa(KreirajIndeksPojmova(recenica));
    IspisiIndeksPojmova(mapa);
    std::string zvarsi{"."};
    for(;;){
        std::cout<<"Unesite rijec: ";
        std::string rijec;
        getline(std::cin,rijec,'\n');
        Znak(rijec);
        if(rijec==zvarsi)break;
        try{
            auto p=PretraziIndeksPojmova(rijec,mapa);
            std::set<int>::iterator ispis(p.begin());
            while(ispis!=p.end()){
                std::cout<<*ispis<<" ";
                ispis++;
            }std::cout<<std::endl;
        }
        catch(std::logic_error x){
            std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
        }
    }
   return 0;
}
