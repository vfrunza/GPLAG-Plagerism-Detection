/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <tuple>
#include <set>

typedef std::map<std::string, std::vector<std::string>> Knjiga;
typedef std::set<std::tuple<std::string, int, int>> Vek;
typedef std::map<std::string, std::set<std::tuple<std::string, int, int>>> Mapa;

void DajMala(std::string &s){
    for(int i=0; i<s.size(); i++){
        if(s[i]>='A' && s[i]<='Z')
            s[i]+='a'-'A';
    }
}

Mapa KreirajIndeksPojmova(Knjiga k){
    Mapa m;
    for(auto x:k){
        int i(0);
        for(auto y:x.second){
            int br=0;
            int pokazatelj(0);
            auto its(y.begin());
            for(int j=0; j<y.size(); j++){
                std::string s;
                while(*its<'0' || *its>'z'){
                    if(its==y.end())
                        break;
                    its++; 
                    br++;
                }
                if(its<y.end()){
                    while(*its>='0' && *its<='z'){
                        s.push_back(*its);
                        its++;
                        pokazatelj++;
                        if(its==y.end())
                           break;
                    }
                }
                if(s.size()!=0){
                    DajMala(s);
                    auto pok(m.find(s));
                    if(pok==m.end()){
                        Vek vek;
                        vek.insert(std::make_tuple(x.first, i, br));
                        m.insert({s, vek});
                    }
                    else{
                        pok->second.insert(std::make_tuple(x.first, i, br));
                    }    
                }
                br+=pokazatelj;
                pokazatelj=0;
            }
             i++;
        }
    }
    return m;
}

void ProvjeraRijeci(std::string &s){
    for(int i=0; i<s.size(); i++){
        if(s.at(i)<'0' || s.at(i)>'z'){
            s.erase(s.begin()+i);
            i--;
        }
    }
}

Vek PretraziIndeksPojmova(std::string s, Mapa m){
    ProvjeraRijeci(s);
    DajMala(s);
    auto it(m.find(s));
    if(it==m.end())
        throw std::logic_error("Unesena rijec nije nadjena!");
    else return it->second;    
}

void IspisiIndeksPojmova(Mapa m){
    for(auto x:m){
        std::cout << x.first << ": "; 
        int i(0);
        for(auto y :x.second){
            std::cout << std::get<0>(y) << "/" << std::get<1>(y)+1 << "/"
                      << std::get<2>(y);
            if(i!=x.second.size()-1) std::cout << ", ";
            else std::cout << std::endl;
            i++;
        }
    }
}

int main ()
{
    Knjiga k;
    std::string s;
    do{
        std::cout << "Unesite naziv poglavlja: ";
        std::getline(std::cin, s);
        std::vector<std::string> v;
        if(s==".") break;
        int i(0);
        std::string s1;
        do{
            std::cout << "Unesite sadrzaj stranice " << i+1 << ": ";
            std::getline(std::cin, s1);
            if(s1==".") break;
            v.push_back(s1);
            i++;
        } while(s1!=".");
        k.insert({s, v});
    } while(s!=".");
    Mapa m(KreirajIndeksPojmova(k));
    std::cout << "\nKreirani indeks pojmova:\n";
    IspisiIndeksPojmova(m);
    std::string s3;
    do{
        std::cout << "Unesite rijec: ";
        std::getline(std::cin, s3);
        if(s3==".") break;
        try{
        auto vek(PretraziIndeksPojmova(s3, m));
        int i(0);
        for(auto x :vek){
            std::cout << std::get<0>(x) << "/" << std::get<1>(x)+1 << "/"
                      << std::get<2>(x);
            if(i!=vek.size()-1) std::cout << " ";
            else std::cout << std::endl;
            i++;
        }
        }
        catch(std::logic_error izuzetak){
            std::cout << izuzetak.what() << std::endl;
        }
    }while(s3!=".");
    
	return 0;
}

/B2017/2018: Zadaća 3, Zadatak 2
/*#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <tuple>
#include <set>

typedef std::map<std::string, std::vector<std::string>> Knjiga;
typedef std::vector<std::tuple<std::string, int, int>> Vek;
typedef std::map<std::string, std::set<std::tuple<std::string, int, int>>> Mapa;

void DajMala(std::string &s){
    for(int i=0; i<s.size(); i++){
        if(s[i]>='A' && s[i]<='Z')
            s[i]+='a'-'A';
    }
}

Mapa KreirajIndeksPojmova(Knjiga k){
    Mapa m;
    for(auto x:k){
        int i(0);
        for(auto y:x.second){
            int br=0;
            int pokazatelj(0);
            auto its(y.begin());
            for(int j=0; j<y.size(); j++){
                std::string s;
                while(*its<'0' || *its>'z'){
                    if(its==y.end())
                        break;
                    its++; 
                    br++;
                }
                if(its<y.end()){
                    while(*its>='0' && *its<='z'){
                        s.push_back(*its);
                        its++;
                        pokazatelj++;
                        if(its==y.end())
                           break;
                    }
                }
                if(s.size()!=0){
                    DajMala(s);
                    auto pok(m.find(s));
                    if(pok==m.end()){
                        Vek vek;
                        vek.push_back(std::make_tuple(x.first, i, br));
                        m.insert({s, vek});
                    }
                    else{
                        pok->second.push_back(std::make_tuple(x.first, i, br));
                    }    
                }
                br+=pokazatelj;
                pokazatelj=0;
            }
             i++;
        }
    }
    return m;
}

Vek PretraziIndeksPojmova(std::string s, Mapa m){
    DajMala(s);
    auto it(m.find(s));
    if(it==m.end())
        throw std::logic_error("Unesena rijec nije nadjena!");
    else return it->second;    
}

void IspisiIndeksPojmova(Mapa m){
    for(auto x:m){
        std::cout << x.first << ": "; 
        for(int i=0; i<x.second.size(); i++){
            std::cout << std::get<0>(x.second[i]) << "/" << std::get<1>(x.second[i])+1 << "/"
                      << std::get<2>(x.second[i]);
            if(i!=x.second.size()-1) std::cout << ", ";
            else std::cout << std::endl;
        }
    }
}

int main ()
{
    Knjiga k;
    std::string s;
    do{
        std::cout << "Unesite naziv poglavlja: ";
        std::getline(std::cin, s);
        std::vector<std::string> v;
        if(s==".") break;
        int i(0);
        std::string s1;
        do{
            std::cout << "Unesite sadrzaj stranice " << i+1 << ": ";
            std::getline(std::cin, s1);
            if(s1==".") break;
            v.push_back(s1);
            i++;
        } while(s1!=".");
        k.insert({s, v});
    } while(s!=".");
    Mapa m(KreirajIndeksPojmova(k));
    std::cout << "\nKreirani indeks pojmova:\n";
    IspisiIndeksPojmova(m);
    std::string s3;
    do{
        std::cout << "Unesite rijec: ";
        std::getline(std::cin, s3);
        if(s3==".") break;
        try{
        auto vek(PretraziIndeksPojmova(s3, m));
        for(int i=0; i<vek.size(); i++){
            std::cout << std::get<0>(vek[i]) << "/" << std::get<1>(vek[i])+1 << "/"
                      << std::get<2>(vek[i]);
            if(i!=vek.size()-1) std::cout << " ";
            else std::cout << std::endl;
        }
        }
        catch(std::logic_error izuzetak){
            std::cout << izuzetak.what() << std::endl;
        }
    }while(s3!=".");
    
	return 0;
}*/

