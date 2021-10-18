#include <iostream>
#include <string>
#include <map>
#include <set>

void VelikaUMala(std::string &s){
    for(int i=0; i<s.size(); i++)
        if(s[i]>='A' && s[i]<='Z')
            s[i]=s[i]+('a'-'A');
}
std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s){
    std::map<std::string, std::set<int>> vr;
    std::string t;
    int i(0);
    while(1){
        t.resize(0);
        while(i<s.length()){
            if((s[i]>='a'&& s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')){
                t.push_back(s[i]); i++;
            }else{i++; break;}
        }
        if(t.size()){
            int k(1); if(i==s.length()) k=0;
            VelikaUMala(t);
            auto it(vr.find(t));
            if(it!=vr.end()) it->second.insert(i-k-t.size());
            else vr[t].insert(i-k-t.size());
        }
        if(i==s.length()) break;
    }
    return vr;
}
std::set<int> PretraziIndeksPojmova(std::string rijec, std::map<std::string, std::set<int>> ipojm){
    if(ipojm.count(rijec)){
        return ipojm[rijec];
    }else throw std::logic_error("Pojam nije nadjen");
}
void IspisiIndeksPojmova(std::map<std::string, std::set<int>> ipojm){
    for(auto x : ipojm){
        std::cout<<x.first<<": ";
        for(auto y : x.second){
            int trigger(false);
            if(y==*(x.second.rbegin())){
                std::cout<<y<<std::endl; trigger=true;
            }
            if(!trigger) std::cout<<y<<",";
        }
    }
}

int main (){
    std::cout<<"Unesite tekst: ";
    std::string tekst;
    std::getline(std::cin, tekst);
    auto ipojm(KreirajIndeksPojmova(tekst));
    IspisiIndeksPojmova(ipojm);
    std::string unos;
    do{
        std::cout<<"Unesite rijec: ";
        std::getline(std::cin, unos);
        if(unos!="."){
            try{
                auto set(PretraziIndeksPojmova(unos, ipojm));
                for(auto x : set)
                    std::cout<<x<<" ";
                std::cout<<std::endl;
            }catch(...){
                std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
            }
        }
    }while(unos!=".");
	return 0;
}