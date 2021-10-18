/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <set>
#include <list>

int OdrediDuzinu(const std::string &s){
    int duzina(0);
    for(int i=0;i<s.size();i++){
        if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z')||(s[i]>='0' && s[i]<='9')) duzina++;
    }
    return duzina;
}

std::vector<int> OdrediKapacitet(int broj_djece, int broj_timova){
    std::vector<int> v;
    int def(broj_djece/broj_timova);
    int mod(broj_djece%broj_timova);
    int i;
    for(i=0;i<broj_timova;i++){
        v.push_back(def);
    }
    i=0;
    while(mod>0){
        v[i]=v[i]+1;
        mod--;
        i++;
    }
    return v;
}

std::list<std::string>::iterator NoviClan(std::list<std::string> &l, std::list<std::string>::iterator lista, int broj_iteracija){
    auto iterator=lista;

    
    for(int i=0;i<broj_iteracija-1;i++){
        iterator++;
        if(iterator==l.end()) iterator=l.begin();
    }
    
    return iterator;
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v, int n){
    if(n<1 || v.size()<n) throw std::logic_error("Razvrstavanje nemoguce");
    std::list<std::string> kids;
    for(int i=0;i<v.size();i++){
        kids.push_back(v[i]);
    }
//    std::vector<std::set<std::string>> rez(n,std::set<std::string>{});
    std::vector<std::set<std::string>> rez;
    std::vector<int> kapaciteti;
    kapaciteti=OdrediKapacitet(v.size(),n);
    std::list<std::string>::iterator iterator(kids.begin());
    
    for(int i=0;i<n;i++){
        int broj_clanova=kapaciteti[i];
        std::set<std::string> skup;
        for(int j=0;j<broj_clanova;j++){
            skup.insert(*iterator);
            int move=OdrediDuzinu(*iterator);
            iterator=kids.erase(iterator);
            if(iterator==kids.end()) iterator=kids.begin();
            iterator=NoviClan(kids, iterator, move);
        }
        rez.push_back(skup);
    }
    return rez;
}

int main(){
    std::cout<<"Unesite broj djece: ";
    int n;
    std::cin>>n;
    std::cout<<"Unesite imena djece: "<<std::endl;
    std::vector<std::string> v;
    std::cin.ignore(1000,'\n');
    for(int i=0;i<n;i++){
        std::string ime;
        std::getline(std::cin, ime);
        v.push_back(ime);
    }
    std::cout<<"Unesite broj timova: ";
    int broj_timova;
    std::cin>>broj_timova;
    std::vector<std::set<std::string>> rez;
    try{
    rez=Razvrstavanje(v, broj_timova);
    for(int i=0;i<rez.size();i++){
        std::cout<<"Tim "<<i+1<<": ";
        auto end(rez[i].end());
        end--;
        for(auto it=rez[i].begin();it!=rez[i].end();it++){
            std::cout<<*it;
            if(it!=end) std::cout<<", ";
        }
        std::cout<<std::endl;
    }
    }
    catch(std::logic_error msg){
        std::cout<<"Izuzetak: "<<msg.what();
    }
    return 0;
}

int main2 ()
{
    int bd(10),bt(3);
    std::vector<int> vex;
    vex=OdrediKapacitet(bd,bt);
    for(auto x:vex){
        std::cout<<x<<" ";
    }
    
	return 0;
}