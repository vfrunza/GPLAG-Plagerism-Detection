/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <iterator>
#include <stdexcept>
#include <memory>

struct Dijete{
    std::string ime;
    std::shared_ptr<Dijete> sljedeci;
};

int BrojSlovaIBrojeva(std::string ime){
    int brojac(0);
    for(int i=0; i<ime.size(); i++){
        if((ime[i]>='a' && ime[i]<='z') || (ime[i]>='A' && ime[i]<='Z') || (ime[i]>='0' && ime[i]<='9'))brojac++;
    }
    return brojac;
}

std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> ImenaDjece, int BrojTimova){
    if(BrojTimova<1 || BrojTimova>ImenaDjece.size())throw std::logic_error("Razvrstavanje nemoguce");
    std::vector<std::set<std::string>> timovi;
    
    std::shared_ptr<Dijete> pocetak(nullptr), prethodni;
    for(int i=0; i<ImenaDjece.size(); i++){
        std::shared_ptr<Dijete> novo (new Dijete);
        novo->ime=ImenaDjece[i]; novo->sljedeci=nullptr;
        if(!pocetak) pocetak=novo;
        else prethodni->sljedeci=novo;
        prethodni=novo;
    }
    prethodni->sljedeci=pocetak;
    
    std::shared_ptr<Dijete> p=pocetak;
    pocetak=nullptr;
    int BrojKoraka(BrojSlovaIBrojeva(p->ime));
    for(int i=0; i<BrojTimova; i++){
        int VelicinaTima(int(ImenaDjece.size()/BrojTimova));
        if(i<ImenaDjece.size()%BrojTimova)VelicinaTima++;
        std::set<std::string> tim;
        while(tim.size()<VelicinaTima){
            tim.insert(p->ime);
            prethodni->sljedeci=p->sljedeci;
            //Dijete *privremeni=p;
            //p=p->sljedeci;                                              //ZAMJENIO SAM IM MJESTA
            //delete privremeni;
            if(tim.size()==VelicinaTima && p==prethodni){
                p->sljedeci=nullptr; prethodni=nullptr; p=nullptr; 
                break;
            }
            p=p->sljedeci;                                                // I PRORADILO JE, PITAT PROFESORA
            //privremeni=nullptr;
            while(BrojKoraka-1>0){
                p=p->sljedeci;
                prethodni=prethodni->sljedeci;
                BrojKoraka--;
            }
            BrojKoraka=BrojSlovaIBrojeva(p->ime);
        }
        timovi.push_back(tim);
    }
    return timovi;
}

int main ()
{
    int n;
    std::cout << "Unesite broj djece: ";
    std::cin >> n;
    std::cout << "Unesite imena djece: ";
    std::vector<std::string> imena;
    std::cin.ignore(10000, '\n');
    for(int i=0; i<n; i++){
        std::string ime;
        std::getline(std::cin, ime);
        imena.push_back(ime);
    }
    std::cout << "\nUnesite broj timova: ";
    std::cin >> n;
    try{
        std::vector<std::set<std::string>> timovi (Razvrstavanje(imena, n));
        for(int i=0; i<timovi.size(); i++){
            std::cout << "Tim " << i+1 << ": ";
            for(auto x : timovi[i]){
                if(timovi[i].find(x)==--(timovi[i].end())) std::cout << x;
                else std::cout << x << ", ";
            }
            std::cout << "\n";
        }
    } catch (const std::logic_error& e){
        std::cout << "Izuzetak: " << e.what();
    }
	return 0;
}