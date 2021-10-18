#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stdexcept>
#include <set>
#include <cstring>
using namespace std;

typedef std::map<std::string, std::vector<std::string>> Knjiga;



std::map<std::string,set<tuple<string, int, int>>> KreirajIndeksPojmova (Knjiga k){
     
     
}

std::vector<string> PretraziIndeksPojmova(string s, Knjiga k){
     string s1;
        for(int i(0);i<s.length();i++)
            s1.push_back(std::tolower(s[i]));
        auto it(k.find(s1));
        if(it==k.end()) throw std::logic_error ("Pojam nije nadjen");
        else return it->second;
     
}
template <typename NekiTip>
void IspisiSet(NekiTip a){
    int br(0);
    for(auto i(a.begin());i!=a.end();i++){
        if(br==(a.size())-1) cout<<*i;
        else
        cout<<*i<<",";
        br++;
    }
}

void IspisiIndeksPojmova(Knjiga k){
     for( auto it = k.begin(); it != k.end(); it++){
         cout << it->first << ": "; 
         IspisiSet(it->second);
         cout<<endl;
    }
}


int main ()
{ Knjiga knjiga;
    
    for(;;) {
        std::cout<<"Unesite naziv poglavlja: ";
        std::string naziv_poglavlja;
        std::getline(std::cin,naziv_poglavlja);
        if(naziv_poglavlja==".") break;
        
        std::vector<std::string> v_stranicaa;
        
        for(int i(0);;i++) {
            std::cout<<"Unesite sadrzaj stranice "<<i+1<<": ";
            std::string stranica;
            std::getline(std::cin,stranica);
            if(stranica==".") break;
            v_stranicaa.push_back(stranica);
        }
        
        std::pair<std::string,std::vector<std::string>> par;
        par.first=naziv_poglavlja;
        par.second=v_stranicaa;
        
        knjiga.insert(par);
    }
   
    KreirajIndeksPojmova(knjiga);
    
        return 0;
}

