/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cctype>
#include <stdexcept>
#include <memory>
struct Dijete{
    std::string ime;
    std::shared_ptr<Dijete> sljedeci;
};
int DuzinaImena(const std::string &Ime){
    int Duzina(0);
    for(auto x: Ime) if((toupper(x)>='A' && toupper(x)<='Z') || (x>='0' && x<='9') ) Duzina++;
    return Duzina;
}
std::vector<std::set<std::string>>Razvrstavanje (std::vector<std::string> VektorImena, int BrojTimova){
    int BrojImena(VektorImena.size());
    if(BrojTimova<1 || BrojTimova>BrojImena) throw std::logic_error("Izuzetak: Razvrstavanje nemoguce");
    std::shared_ptr<Dijete> PocetakListe(nullptr), Prethodno(nullptr);
    for(int i=0;i<VektorImena.size();i++){
        std::shared_ptr<Dijete> Novo(new Dijete);
        Novo->ime=VektorImena[i];
        Novo->sljedeci=PocetakListe;
        if(i==0){
            PocetakListe=Novo;
            Prethodno=Novo;
            continue;
        }
        Prethodno->sljedeci=Novo;
        Prethodno=Novo;
    }
    Prethodno=nullptr;
    std::vector<std::set<std::string>> Timovi(BrojTimova);
    auto It(PocetakListe);
    for(int i=0;i<(BrojImena%BrojTimova);i++){
        int BrojClanova(BrojImena/BrojTimova+1),j(0);
        while(j<BrojClanova){
           // std::cout<<"\n NA IMENU SAM:::: "<<It->ime;
            Timovi[i].insert(It->ime);
            int Korak(DuzinaImena(It->ime));
            auto PomocniPokazivac(It);
            if(j==BrojClanova-1 && i==BrojTimova-1){
                PomocniPokazivac->sljedeci=nullptr;
                PomocniPokazivac=nullptr;
                break;
            }
            while(It->sljedeci!=PomocniPokazivac) It=It->sljedeci;
            It->sljedeci=PomocniPokazivac->sljedeci;
            PomocniPokazivac=nullptr;
            int k(0);
            while(k<Korak){
                It=It->sljedeci;
                k++;
            }
            j++;
        }
    }
    for(int i=(BrojImena%BrojTimova);i<BrojTimova;i++){
        int BrojClanova(BrojImena/BrojTimova),j(0);
        while(j<BrojClanova){
            //std::cout<<"\n NA IMENU SAM:::: "<<It->ime;
            Timovi[i].insert(It->ime);
            int Korak(DuzinaImena(It->ime));
            auto PomocniPokazivac(It);
            if(j==BrojClanova-1 && i==BrojTimova-1){
                PomocniPokazivac->sljedeci=nullptr;
                PomocniPokazivac=nullptr;
                break;
            }
            while(It->sljedeci!=PomocniPokazivac) It=It->sljedeci;
            It->sljedeci=PomocniPokazivac->sljedeci;
            PomocniPokazivac=nullptr;
            int k(0);
            while(k<Korak){
                It=It->sljedeci;
                k++;
            }
            j++;
        }
    }
    PocetakListe=nullptr;
    return Timovi;
}
int main(){
    std::cout<<"Unesite broj djece: ";
    int BrojDjece;
    std::cin>>BrojDjece;
    std::vector<std::string> ImenaDjece;
    std::cin.ignore(10000,'\n');
    std::cout<<"Unesite imena djece: ";
    for(int i=0;i<BrojDjece;i++){
        std::string Ime;
        std::getline(std::cin,Ime);
        ImenaDjece.push_back(Ime);
    }
    std::cout<<"\nUnesite broj timova: ";
    int BrojTimova;
    std::cin>>BrojTimova;
    try{
        auto Timovi(Razvrstavanje(ImenaDjece,BrojTimova));
        for(int i=0;i<Timovi.size();i++){
            std::cout<<"Tim "<<i+1<<": ";
            for(auto it=Timovi[i].begin();it!=Timovi[i].end();it++){
                std::cout<<*it;
                if(std::distance(it,Timovi[i].end())!=1) std::cout<<", ";
            }
            std::cout<<std::endl;
        }
    }catch(std::logic_error izuzetak){
        std::cout<<izuzetak.what();
    }
    return 0;
}