/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <set>
#include <iterator>
#include <stdexcept>
int brojanje(std::string ime) {
    int rezultat(0);
    for(int i=0; i<ime.size(); i++) if((ime[i]>='0' && ime[i]<='9') || (ime[i]>='A' && ime[i]<='Z') || (ime[i]>='a' && ime[i]<='z')) rezultat++;
    return rezultat;
}
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> imena, int broj_timova) {
    if(broj_timova<1 || broj_timova>imena.size()) throw std::logic_error("Izuzetak: Razvrstavanje nemoguce");
    std::list<std::string> djeca;
    std::vector<std::set<std::string>> timovi(broj_timova);
    std::vector<std::string> redoslijed={imena[0]};
            std::string ispaola=imena[0];
            auto it=djeca.begin();
    for(int i=1; i<imena.size(); i++) djeca.push_back(imena[i]);
        for(int i=0; i<imena.size()-1; i++) {
        int zamjena=brojanje(ispaola);
        if(i!=0) it--;
        while(zamjena>=0){
                       it++;
                 if(it==djeca.end()) it=djeca.begin();
                  zamjena--;
            if(zamjena==0){
                redoslijed.push_back(*it);
                ispaola=*it;
                it=djeca.erase(it);
                break;}
               
            }}
    if(imena.size()%broj_timova==0) {
        int velicina=imena.size()/broj_timova;
        for(int i=0; i<broj_timova; i++) {
            int zamjena=0;
            while(zamjena<velicina) {
                timovi[i].insert(redoslijed[zamjena]);
                zamjena++;
            }
            int brojac(0);
            while(brojac<velicina) {
                redoslijed.erase(redoslijed.begin());
                brojac++;
            }}}
    else if(imena.size()%broj_timova!=0) {
        int velicina=(int)(imena.size()/broj_timova);
        for(int i=0; i<broj_timova; i++) {
            if(i<imena.size()%broj_timova) {
                for(int j=0; j<velicina+1; j++) {
                    (timovi[i]).insert(redoslijed[j]);
                } int brojac(0);
                while(brojac<velicina+1) {
                    redoslijed.erase(redoslijed.begin());
                    brojac++;}
            } else{
                for(int j=0; j<velicina; j++) timovi[i].insert(redoslijed[j]);
                int brojac(0);
                while(brojac<velicina){
                    redoslijed.erase(redoslijed.begin());
                    brojac++;
                }
            }
        }
    }
     return timovi;
}

int main ()
{
    std::vector<std::string> imena;
    int brojdjece, broj_timova;
    std::cout<<"Unesite broj djece: ";
    std::cin>>brojdjece;
    imena.resize(brojdjece);
    std::cout<<"Unesite imena djece: \n";
            std::string dijete;
    for(int i=0; i<=brojdjece; i++) {
std::getline(std::cin, dijete);
       if(i!=0) imena[i-1]=dijete;
    }
    std::cout<<"Unesite broj timova: ";
    std::cin>>broj_timova;
   try{ auto f=Razvrstavanje(imena, broj_timova);
    for(int i=0; i<f.size(); i++) {
        std::cout<<"Tim "<<i+1<<": ";
       auto t(f[i].begin()), v(f[i].end());
       auto zamjena=t;
       for(int i=0; i<distance(t,v); i++) {if(i!=distance(t,v)-1) std::cout<<*zamjena++<<", ";
       else std::cout<<*zamjena;}
        std::cout<<std::endl;
    }} catch(std::logic_error e) {std::cout<<e.what();}
	return 0;
}