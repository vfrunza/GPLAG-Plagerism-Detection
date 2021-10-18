/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <stdexcept>

bool slovo_je( char c) {
    if(((c>='0' && c<='9') ||(c>='A' && c<='Z') || (c>='a' && c<='z') ) || c==' ' ) return true;
    return false;
}
std::map<std::string, std::set<int> > KreirajIndeksPojmova(std::string s)  {
    for(int i=0;i<s.length();i++){
        if(s[i]>='A' && s[i]<='Z') s[i]+=32;
    }
    std::map<std::string,std::set<int> > mapa;
    for(int i=0; i<s.length(); i++) {
        std::string pomocni;
        std::set<int> skup;

        while(s[i]!=' ' && slovo_je(s[i])  && i<s.length() ) {
                if(s[i]==' ') break;
            pomocni.push_back(s[i]);
            i++;
        }
        auto p(mapa.find(pomocni));
        if(p!=mapa.end()) p->second.insert(i-pomocni.size());
        else {
            skup.insert(i-pomocni.size());
            mapa.insert(std::pair<std::string,std::set<int> > (pomocni,skup));
        }
    }
    
    auto q(mapa.find(""));
    if (q!=mapa.end()) mapa.erase(q->first);

    return mapa;
}

std::set<int> PretraziIndeksPojmova(const std::string &s,std::map <std::string,std::set<int>> mapa ) {
    auto p(mapa.find(s));
    if(p==mapa.end()) throw std::logic_error("Pojam nije nadjen");
    return p->second;
}

void IspisiIndeksPojmova(std::map<std::string,std::set<int> >mapa ){

    for(auto p(mapa.begin()); p!=mapa.end(); p++) {
        std::cout<<p->first<<": ";
        int i(0);
        for(auto it(p->second.begin()); it!=p->second.end(); it++) {
            std::cout<<*it;
            if(i!=int(p->second.size()-1)) std::cout<<",";
            i++;
         }
        std::cout<<std::endl;
    }
}

int main (){

    std::string s;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin,s);
    for(int i=0; i<s.length(); i++) {
        if(s[i]>='A' && s[i]<='Z') s[i]+=32;
    }
    
    IspisiIndeksPojmova(KreirajIndeksPojmova(s));
    auto mapa (KreirajIndeksPojmova(s));
    
    for(;;) {
        std::string s;
        std::cout<<"Unesite rijec: ";
        std::getline(std::cin,s);

        for(int i=0; i<s.length(); i++) {
            if(s[i]>='A' && s[i]<='Z') s[i]+=32;
        }
        if(s==".") break;
        try {
          auto skup(PretraziIndeksPojmova(s,mapa));
          for(auto p(skup.begin()); p!=skup.end(); p++)  std::cout<<*p<<" ";
        } 
        catch(...) {
            std::cout<<"Unesena rijec nije nadjena!";
        }
        std::cout<<std::endl;
    }

    return 0;
}