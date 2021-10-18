/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stdexcept>
struct Dijete{
    std::string ime;
    Dijete *sljedeci;
};
int DuzinaImena(std::string ime){
    int duzina(0);
    for(int i=0; i<ime.size(); i++) if(ime[i]>='0' && ime[i]<='9' || ime[i]<='z' && ime[i]>='a' || ime[i]<='Z' && ime[i]>='A') duzina++;
    return duzina;
}
std::vector<std::set<std::string>>Razvrstavanje(std::vector<std::string> djeca, int br_timova){
    if(br_timova<1 || br_timova>djeca.size()) throw std::logic_error("Razvrstavanje nemoguce");
    std::vector<std::set<std::string>> timovi(br_timova);
    Dijete *l(nullptr), *help;
    int brojac(0);
        for(;;){
        if(brojac==djeca.size()){
            help->sljedeci=l;
            break;
        }
        Dijete *novo(new Dijete);
        novo->ime=djeca[brojac];
        novo->sljedeci=nullptr;
        if(!l) l=novo;
        else help->sljedeci=novo;
        help=novo;
        brojac++;
        }
    
    std::vector<int> velicine(br_timova);
    if(!(djeca.size()%br_timova))
        for(int i=0; i<br_timova; i++) velicine[i]=djeca.size()/br_timova;
    else{
        for(int i=0; i<djeca.size()%br_timova; i++) velicine[i]=(djeca.size()/br_timova)+1;
        for(int i=djeca.size()%br_timova; i<br_timova; i++) velicine[i]=djeca.size()/br_timova;
    }
    brojac=0;
    int vel_liste(djeca.size());
    auto it(velicine.begin());
    while(vel_liste!=0){
        while(brojac<br_timova){
            int j(0);
            while(j<*it){
                timovi[brojac].insert(l->ime);
                int duzina_imena(DuzinaImena(l->ime)-1);
                auto pok(l);
                l=l->sljedeci;
                help->sljedeci=l;
                delete pok;
                vel_liste--;
                if(!vel_liste) break;
                while(duzina_imena>0){
                    help=l;
                    l=l->sljedeci;
                    duzina_imena--;
                }
                j++;
            }
            if(!vel_liste) break;
            brojac++;
            it++;
        }
    }
    return timovi;
}
int main ()
{
    try{
        std::cout<<"Unesite broj djece: ";
        int n;
        std::cin>>n;
        std::cin.ignore(1000, '\n');
        std::cout<<"Unesite imena djece: ";
        std::vector<std::string> djeca;
        for(int i=0; i<n; i++){
            std::string ime;
            std::getline(std::cin, ime);
            djeca.push_back(ime);
        }
        std::cout<<std::endl<<"Unesite broj timova: ";
        int br_tim;
        std::cin>>br_tim;
        auto timovi(Razvrstavanje(djeca, br_tim));
        for(int i=0; i<timovi.size(); i++){
            std::cout<<"Tim "<<i+1<<": ";
            int br(0);
            for(auto j=timovi[i].begin(); j!=timovi[i].end(); j++){
                br++;
                if(br==timovi[i].size()) std::cout<<*j;
                else std::cout<<*j<<", ";
            }
            std::cout<<std::endl;
        }
    }
    catch(std::logic_error w){
        std::cout<<"Izuzetak: "<<w.what();
    }
    return 0;
}