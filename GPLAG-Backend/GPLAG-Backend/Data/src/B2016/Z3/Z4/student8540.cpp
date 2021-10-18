/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <string>
#include <stdexcept>

int BrojSlovaImena(std::string Ime){
    int a(Ime.size());
    for(int i=0;i<Ime.size();i++){
        if(Ime[i]<'0' || (Ime[i]>'9' && Ime[i]<'A') ||  (Ime[i]>'Z' && Ime[i]<'a') ||  Ime[i]>'z' ) a--;
    }
    return a;
}
std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> Imena, int broj)
{
    int n=Imena.size();
    if(broj<1 || broj>n) throw std::logic_error("Razvrstavanje nemoguce");
    std::list<std::string> Lista;
    for(int i=0; i<n; i++) {
        Lista.push_back(Imena[i]);
    }
    int brojac=0;
    int vecegrupe=n%broj;
    std::vector<std::set<std::string>> finalni(broj);

    int pomjeranje=0;
    std::string rijecliste;
    std::list<std::string>::iterator it(Lista.begin());
    while(Lista.size()!=0) {
        if(Lista.size()==0) break;
        rijecliste=*it;
        pomjeranje=BrojSlovaImena(rijecliste);
        it=Lista.erase(it);
        if(it==Lista.end()) it=Lista.begin();
        if(brojac<vecegrupe && finalni[brojac].size()<(n/broj+1)) {
            finalni[brojac].insert(rijecliste);
        } else if(brojac<vecegrupe && finalni[brojac].size()==(n/broj+1)) {
            brojac++;
            finalni[brojac].insert(rijecliste);
        } else if(brojac>=vecegrupe && finalni[brojac].size()<(n/broj) &&brojac<broj) {
            finalni[brojac].insert(rijecliste);
        } else if(brojac>=vecegrupe && finalni[brojac].size()==(n/broj) && brojac<broj) {
            brojac++;
            finalni[brojac].insert(rijecliste);
        }
        for(int i=1; i<pomjeranje; i++) {
            if(it==Lista.end()) it=Lista.begin();
            it++;
        }
        if(it==Lista.end()) it=Lista.begin();
    }
    return finalni;
}
int main ()
{   
    std::cout<<"Unesite broj djece: ";
    int broj;
    std::cin>>broj;
    std::cout<<"Unesite imena djece: \n";
    std::vector<std::string> VektorImena;
    std::string Ime;
    std::cin.ignore(10000, '\n');
    while(VektorImena.size()<broj) {

        std::getline(std::cin, Ime);
        VektorImena.push_back(Ime);
    }
    std::cout<<"Unesite broj timova: ";
    int n;
    std::cin>>n;
    try {
        std::vector<std::set<std::string>> Konacni;
        Konacni=Razvrstavanje(VektorImena, n);
        std::set<std::string>::iterator it;
        for(int i=0; i<Konacni.size(); i++) {
            std::cout<<"Tim "<<i+1<<": ";
            it=Konacni[i].begin();
            for(int j=0; j<Konacni[i].size(); j++) {
               if(j!=Konacni[i].size()-1) std::cout<<(*it)<<", ";
               else std::cout<<(*it);
                it++;
            }
            std::cout<<"\n";
        }
    } catch(std::logic_error izuzetak) {
        std::cout<<"Izuzetak: "<<izuzetak.what();
    }
    return 0;
}