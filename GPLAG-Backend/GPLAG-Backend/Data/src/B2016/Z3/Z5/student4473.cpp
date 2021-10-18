/B2016/2017: Zadaća 3, Zadatak 5
/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <set>
#include <stdexcept>
#include <iterator>
#include <string>
bool DaLiJeSlovo(char c){
    if((c>='A' and c<='Z') or (c>='0' and c<='9') or (c>='a' and c<='z'))
        return 1;
    else return 0;
}
struct Dijete {
    std::string ime;
    Dijete *sljedeci;
};
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> osobe, int n){
    std::vector<std::set<std::string>> glavni(n);
    if(n<1 or n>osobe.size()) throw std::logic_error("Razvrstavanje nemoguce");
    //racunanje osoba u timovima
    int m(osobe.size()/n);
    //std::cout<<m;
    int mm(osobe.size()%n);
    std::vector<int> timovi(n);
    for(int i=0;i<n;i++){
        if(i<mm) timovi[i]=m+1;
        else timovi[i]=m;
    }
    Dijete* pocetak(nullptr),*prethodni;
    for(int i=0;i<osobe.size();i++){
        Dijete *novi(new Dijete);
        novi->ime=osobe[i];
        novi->sljedeci=nullptr;
        if(!pocetak) pocetak=novi;
        else prethodni->sljedeci=novi;
        prethodni=novi;
    }
    prethodni->sljedeci=pocetak;
    int br(0),j(0);
    auto it(pocetak);
    while(j!=n-1){ 
        glavni[j].insert(it->ime);
        br++;
        if(br==timovi[j]) {j++;br=0;}
        int duzina=0;
        for(int k=0;k<(it->ime).size();k++){
            if(DaLiJeSlovo((it->ime)[k])) duzina++;
        }
        auto imam(it);
        it=it->sljedeci;
        prethodni->sljedeci=it;
        delete imam;
        for(int i=0;i<duzina-1;i++){
            it=it->sljedeci;
            prethodni=prethodni->sljedeci;
        }
    }
     for(int i=0;i<timovi[j];i++){
         glavni[j].insert(it->ime);
         if(j==timovi[j]-1){ delete it;continue;}
         auto imam(it);
         it=it->sljedeci;
         delete imam;
     }   
    return glavni;
}
int main ()
{   std::cout << "Unesite broj djece: " ;
    int n;
    std::cin >> n;
    std::cin.ignore(1000, '\n');
    std::cout << "Unesite imena djece: " << std::endl;
    std::vector<std::string> djeca(n);
    for(int i=0;i<n;i++) std::getline(std::cin, djeca[i]);
    std::cout << "Unesite broj timova: " ;
    int brtimova;
    std::cin >> brtimova;
    std::vector<std::set<std::string>> rjesenje;
    
    try{
        rjesenje=(Razvrstavanje(djeca,brtimova));
    }
    catch(std::logic_error err){
        std::cout<<"Izuzetak: "<<err.what();
    }
    for(int i=0; i<rjesenje.size(); i++){
        std::cout<<"Tim "<<i+1<<": ";
        int br(0);
        for(auto x: rjesenje[i]) {
            if(br==rjesenje[i].size()-1){ std::cout<<x; break;}
            std::cout << x << ", ";
            br++;}
    std::cout << std::endl;
    }
	return 0;
}