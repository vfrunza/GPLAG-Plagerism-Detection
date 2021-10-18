/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <set>
#include <stdexcept>
bool nije_slovo(char c){
    if((c>='0'&& c<='9') || (c>='A' && c<='Z' ) || (c>='a' && c<='z') ) return false;
    return true;
}
int BrojSlova(std::string s){
    int br(s.length());
    for(int i=0; i<s.length(); i++) {
        if(nije_slovo(s[i])) br--;
    }
    return br;
}
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string>&imena ,int br_timova){
    
    if(br_timova<1 || br_timova>int(imena.size())) throw std::logic_error("Razvrstavanje nemoguce");

    std::list<std::string>lista;
    std::vector<std::set<std::string>>timovi(br_timova);
    int n(int(imena.size()));
    int ostatak(n%br_timova);
    for(int i=0; i<imena.size(); i++) lista.push_back(imena[i]);
    auto it(lista.begin());
    int i(0);
    int brojac(0);
    int brojdjece(0);
        while(!lista.empty()){
          
    return timovi;
}

int main (){

    int n;
    std::cout<<"Unesite broj djece: ";
    std::cin>>n;
    std::cout<<"Unesite imena djece: "<<std::endl;
    std::vector<std::string>imena;
    std::cin.ignore(1000000,'\n');
    for(int i=0; i<n; i++) {
        std::string s;
        std::getline(std::cin,s);
        imena.push_back(s);
    }
    int br_timova;
    std::cout<<"Unesite broj timova: ";
    std::cin>>br_timova;
    try {
        auto timovi(Razvrstavanje(imena,br_timova));
         for(int i=0; i<br_timova; i++) {
            std::cout<<"Tim "<<i+1<<": ";
            for(auto x:timovi[i]) {
                if
                std::cout<<x<<", ";
            std::cout<<std::endl;
        }
    } 
    catch(std::logic_error e) {
        std::cout<<"Izuzetak: "<<e.what();
    }
    return 0;
}