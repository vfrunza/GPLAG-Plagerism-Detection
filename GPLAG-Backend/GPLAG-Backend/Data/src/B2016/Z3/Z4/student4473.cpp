/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <stdexcept>
#include <iterator>
#include <string>
bool DaLiJeSlovo(char c){
    if((c>='A' and c<='Z') or (c>='0' and c<='9') or (c>='a' and c<='z'))
        return 1;
    else return 0;
}
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> osobe, int n){
    std::vector<std::set<std::string>> glavni(n);
    std::list<std::string> kopija;
    for(int i=0;i<osobe.size();i++){
        kopija.push_back(osobe[i]);
    }
    if(n<1 or n>osobe.size()) throw std::logic_error("Razvrstavanje nemoguce");
    //racunanje osoba u timovima
    int m(osobe.size()/n);
    //std::cout<<m;
    int brojac(0);
    int ubaceni(0);
    auto it=kopija.begin();
    //prvo dijete
    int duzina(0);
    for(int k=0;k<(*it).size();k++){
            if(DaLiJeSlovo((*it)[k])) duzina++;}
    glavni[brojac].insert(*it);
    ubaceni++;
    do{ 
        it=kopija.erase(it);
        if(it==kopija.end()) it=kopija.begin();
        for(int i=0;i<duzina-1;i++) {
            it++;
            if(it==kopija.end())
                it=kopija.begin();
        }
        duzina=0;
        for(int k=0;k<(*it).size();k++){
            if(DaLiJeSlovo((*it)[k])) duzina++;
        }
        if(brojac<osobe.size()%n){
            if(ubaceni==m+1){
                brojac++;
                ubaceni=0;
            }
        }
        else{
            if(ubaceni==m){
                brojac++;
                ubaceni=0;
            }
        }
        glavni[brojac].insert(*it);
        ubaceni++;
        if(kopija.size()==1) break;
    
    }
    while(it!=kopija.end());
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