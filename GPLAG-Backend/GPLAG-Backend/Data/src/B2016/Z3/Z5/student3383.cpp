/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <set>

struct Dijete{
    std::string ime;
    Dijete *sljedeci;
};

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> Imena, int broj_timova){
    if(broj_timova<1 || broj_timova>Imena.size()) throw std::logic_error("Razvrstavanje nemoguce");
    Dijete *pocetak{nullptr}, *prethodni{nullptr}, *dijete{nullptr};
    try{
        for(int i{0}; i<Imena.size(); i++){
            dijete=new Dijete;
            dijete->ime=Imena[i];
            dijete->sljedeci=nullptr;
            if(!pocetak) pocetak=dijete;
            dijete->sljedeci=pocetak;
            if(i!=0)prethodni->sljedeci=dijete;
            prethodni=dijete;
        }
    }
    catch(...){
        Dijete *pomoc{pocetak};
        while(pomoc != prethodni){
            pomoc=pomoc->sljedeci;
            delete pomoc;
        }
        delete pocetak;
        throw;
    }
    int enplusjedan, br_dj_po_timu;
    br_dj_po_timu=Imena.size()/broj_timova;
    enplusjedan=br_dj_po_timu*broj_timova;
    enplusjedan=Imena.size() - enplusjedan;
    int preskoci{0}, j{1};
    Dijete *kreci{pocetak}, *poslije;
    std::vector<std::set<std::string>> vrati(broj_timova);
    for(int i{0}; i<broj_timova; i++){
        if(i==0) j=0;
        if(i<enplusjedan){
            int brojac{0};
            for(;;){
                if(j == preskoci){
                    vrati[i].insert(kreci->ime);
                    int duzina{0};
                    for(int h{0}; h<(kreci->ime).size(); h++) if(((kreci->ime)[h]>='0' && (kreci->ime)[h]<='9') || 
                                    ((kreci->ime)[h]>='A' && (kreci->ime)[h]<='Z') || ((kreci->ime)[h]>='a' && (kreci->ime)[h]<='z')) duzina++;
                    preskoci=duzina;
                    prethodni->sljedeci=kreci->sljedeci;
                    poslije=kreci->sljedeci;
                    delete kreci;
                    kreci=poslije;
                    brojac++;
                    j=0;
                }
                else{
                    kreci=kreci->sljedeci;
                    prethodni=prethodni->sljedeci;
                }
                j++;
                if(brojac==br_dj_po_timu+1) break;
            }
        }
        else{
            int brojac{0};
            for(;;){
                if(j==preskoci){
                    vrati[i].insert(kreci->ime);
                    int duzina{0};
                    for(int h{0}; h<(kreci->ime).size(); h++) if(((kreci->ime)[h]>='0' && (kreci->ime)[h]<='9') ||
                                    ((kreci->ime)[h]>='A' && (kreci->ime)[h]<='Z') || ((kreci->ime)[h]>='a' && (kreci->ime)[h]<='z')) duzina++;
                    preskoci=duzina;
                    prethodni->sljedeci=kreci->sljedeci;
                    poslije=kreci->sljedeci;
                    delete kreci;
                    kreci=poslije;
                    brojac++;
                    j=0;
                }
                else {
                    kreci=kreci->sljedeci;
                    prethodni=prethodni->sljedeci;
                }
                j++;
                if(brojac==br_dj_po_timu) break;
            }
        }
    }
    return vrati;
}

int main (){
    std::cout << "Unesite broj djece: ";
    int n;
    std::cin >> n;
    std::cin.ignore(10000, '\n');
    std::cout << "Unesite imena djece: ";
    std::vector<std::string> Imena(n);
    for(int i{0}; i<n; i++){
        std::getline(std::cin, Imena[i]);
    }
    std::cout << "\nUnesite broj timova: ";
    int timovi;
    std::cin >> timovi;
    try{
        auto pisi(Razvrstavanje(Imena, timovi));
        for(int i{0}; i<timovi; i++){
            std::cout << "Tim " << i+1 << ": ";
            std::set<std::string>::iterator it{pisi[i].begin()};
            while(it != pisi[i].end()){
                std::cout << *it;
                it++;
                if(it != pisi[i].end()) std::cout << ", ";
            }
            std::cout << std::endl;
        }
    }
    catch(std::logic_error izuzetak){
        std::cout << "Izuzetak: " << izuzetak.what();
    }
    catch(...){
        std::cout << "Izuzetak";
    }
	return 0;
}