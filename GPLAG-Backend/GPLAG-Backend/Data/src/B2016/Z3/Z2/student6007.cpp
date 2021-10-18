/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>

void IspisiIndeksPojmova (std::map<std::string,std::set<int>> MAPA){
    for (auto it=MAPA.begin(); it!= MAPA.end(); it++){
        std::cout<<it->first<<": ";
        auto it3=(it->second).begin();
        int brojac = 0;
        for(auto it2=(it->second).begin(); it2!=(it->second).end(); it2++){
            brojac++;
            it3++;
            if(brojac==(it->second).size())
                std::cout<<*it2;
                else 
                    std::cout<<*it2<<",";
        }
        std::cout<<std::endl;
    }
}

char Pretvori (char car){
    char c = car;
    if(c >= 'A' && c <= 'Z')
        c+=32;
return c;
}

std::map<std::string, std::set<int>> KreirajIndeksPojmova (std::string s){
    std::map<std::string, std::set<int>> vracam;
    for(int i = 0; i<s.length(); ++i){
        if(s[i]>='A' && s[i]<='Z')
            s[i]+=32;
    }
    std::string novi1;
    bool ima_razmak = true;
    int velicina = s.length();
    int x = 0;
    int novo;
    while( x < velicina){
        if(!((s[x]>='A' && s[x]<='Z') || (s[x]>='a' && s[x]<='z') || (s[x]>='0' && s[x]<='9')))
            ima_razmak = true;
        else if (ima_razmak) {
            ima_razmak = false;
            novo = x;
            Pretvori(s[x]);
            while(novo< velicina && ((s[novo]>='A' && s[novo]<='Z') || (s[novo]>='a' && s[novo]<='z') || (s[novo]>='0' && s[novo]<='9'))){
                Pretvori(s[novo]);
                novo++;
            }
            novi1 = s.substr(x, novo - x);
            vracam[novi1].insert(x);
        }
        x++;
    }
    return vracam;
}

std::set<int> PretraziIndeksPojmova(std::string s, std::map<std::string,std::set<int>> MAPA){
    bool ima;
    std::set<int> vracam;
    ima = false;
    
    for(auto it = MAPA.begin(); it != MAPA.end(); ++it){
        if(s == (it->first)){
            auto x = it->second;
            vracam=x;
            ima=true;
        }
    }
    if(!(ima))
        throw std::logic_error("Pojam nije nadjen");
    return vracam;
}

int main (){
    //try{
    std::string rijec, rijec1;
    std::map<std::string, std::set<int>> funkcija;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin, rijec);
    funkcija = KreirajIndeksPojmova(rijec);
    IspisiIndeksPojmova(funkcija);
    std::set<int> s;
    
    for(;;){
            std::cout<<std::endl;
            std::cout<<"Unesite rijec: ";
            std::getline(std::cin, rijec1);
          //  for(int i =0; i<rijec1.length(); ++i){
        /*if(rijec1[i]>='A' && rijec1[i]<='Z'){
            rijec1[i]+=32;
        }
    }*/
            if (rijec1==".") break;
            try{
            std::set<int> s = PretraziIndeksPojmova(rijec1, funkcija);
            for(auto i = s.begin(); i!=s.end();i++){
                std::cout<<*i<< " ";
                //i++;
                }
                std::cout<<std::endl;
        }
        catch(std::logic_error){
            std::cout<<"Unesena rijec nije nadjena!";
        }
    }
	return 0;
}