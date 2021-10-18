/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stdexcept>
#include <algorithm>

struct Dijete {
    std::string ime;
    Dijete* sljedeci;
};

void UnistiListu (Dijete *pocetak) {
    Dijete *sadasnji=pocetak, *sljedeci=pocetak;
    while (sljedeci!=nullptr) {
        sljedeci=sadasnji->sljedeci;
        delete sadasnji;
        sadasnji=sljedeci;
    }
}

Dijete* Kreiraj_listu_cvorova (std::vector<std::string> djeca) {
    Dijete* pocetak=nullptr, *prethodni;
    for (int i=0; i<djeca.size(); i++) {
        Dijete* novi=new Dijete;
        novi->ime=djeca[i];
        novi->sljedeci=nullptr;
        if (!pocetak) pocetak=novi;
        else prethodni->sljedeci=novi;
        prethodni=novi;
    }
    return pocetak;
}

bool Slovo_ili_broj(char a) {
    if (a>='0' && a<='9') return true;
    if ((a>='A' && a<='Z') || (a>='a' && a<='z')) return true;
    return false;
}

std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> djeca, int br_timova) {
    if (br_timova<1 || br_timova>djeca.size()) throw std::logic_error("Razvrstavanje nemoguce");
    Dijete* prvi=nullptr;
    try { prvi=Kreiraj_listu_cvorova(djeca); }
    catch (...) {
        UnistiListu(prvi);
        throw;
    }
//for (auto p=pocetak; p!=nullptr; p=p->sljedeci) std::cout<<"ime:"<<p->ime<<"\n";
    std::vector<std::set<std::string>> tim(br_timova);
    int tim_plus=djeca.size()%br_timova;
    int clanovi=djeca.size()/br_timova;
    std::string pom=djeca[0];
    int prvi_clan=1;
    Dijete* pt;
    for (pt=prvi; pt->sljedeci!=nullptr; pt=pt->sljedeci)
        if (pt==nullptr) {pt->sljedeci=prvi; break;}
//std::cout<<"ime: "<<pt->ime;
//return tim;
    //Dijete* it=pocetak;
    for (int t=0; t<br_timova; t++) {
        int br_c=0;
        if (t<tim_plus) br_c=clanovi+1;
        else br_c=clanovi;
        
        for (int tp=0; tp<br_c; tp++) {
            int brojac=0;
            for (int i=0; i<pom.size(); i++)
                if (Slovo_ili_broj(pom[i])) brojac++;
//std::cout<<"ime: "<<pom<<" "<<brojac<<" br \n";

            for (int i=1; i<brojac; i++) {
 //   std::cout<<"imena: "<<sljedeci->ime<<" \n";
            //    if (sljedeci==nullptr) { sljedeci=pocetak; it=nullptr; }
            //    else if (it==nullptr && prvi_clan!=1) {it=pocetak; sljedeci=pocetak->sljedeci;}
            //    else if (prvi_clan!=1) { it=it->sljedeci; sljedeci=it->sljedeci; }
                if (prvi_clan==1 || i==brojac-1) {
                    tim[t].insert(prvi->ime);
                    pom=prvi->ime;
                    if (pt==prvi) {delete prvi;pt=nullptr;prvi=nullptr; break;}
                    else { 
                        pt->sljedeci=prvi->sljedeci;
                        delete prvi;
                        prvi=pt->sljedeci;
                        if (prvi_clan==1) {
                            prvi_clan=0;
                            i=brojac;
                        }
                    }
                }
                prvi=prvi->sljedeci;
                pt=pt->sljedeci;
//std::cout<<"imena: "<<sljedeci->ime<<" \n";
            }
        }
    }
  //  UnistiListu(pocetak);
    return tim;
}

int main ()
{
    int br_djece;
    std::cout<<"Unesite broj djece: ";
    std::cin>>br_djece;
    std::vector<std::string> djeca(0);
    std::cout<<"Unesite imena djece:\n";
    std::cin.ignore(1000,'\n');
    for (int i=0; i<br_djece; i++) {
        std::string ime;
        std::getline(std::cin,ime);
        djeca.push_back(ime);
    }
    int br_timova;
    std::cout<<"Unesite broj timova: ";
    std::cin>>br_timova;
    try {
        auto timovi=Razvrstavanje(djeca,br_timova);
        for (int i=0; i<timovi.size(); i++) {
            std::cout<<"Tim "<<i+1<<": ";
            int pom=0;
            for (auto x : timovi[i]) {
                if (pom==0) { std::cout<<x; pom=1; }
                else std::cout<<", "<<x;
            }
            std::cout<<std::endl;
        }
    }
    catch (std::logic_error a) {
        std::cout<<"Izuzetak: "<<a.what();
    }
    catch (...) {
        std::cout<<"Neuspjela alokacija!";
    }
	return 0;
}