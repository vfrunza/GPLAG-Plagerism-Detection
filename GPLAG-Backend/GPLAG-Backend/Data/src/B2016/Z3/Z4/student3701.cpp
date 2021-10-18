/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <stdexcept>
#include <algorithm>
//funkcija provjerava da li je znak dio imena djeteta
bool Slovo_ili_broj (char a) {
    if (a>='0' && a<='9') return true; 
    if ((a>='A' && a<='Z') || (a>='a' && a<='z')) return true;
    return false;
}
//FUNKCIJA RAZVRSTAVA DJECU U TIMOVE
std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> djeca, int br_timova) {
    if (br_timova<1 || br_timova>djeca.size()) throw std::logic_error("Razvrstavanje nemoguce");
    std::list<std::string> spisak_djece;
    std::vector<std::set<std::string>> tim(br_timova);
    for (int i=0; i<djeca.size(); i++)      //popunjavam listu sa imenima djece
        spisak_djece.push_back(djeca[i]);
    int tim_plus=djeca.size()%br_timova;    //koliko timova ce imavi za 1 clan vise
    int clanovi=djeca.size()/br_timova;     //koliko ce biti clanova u timovima
    std::string pom=djeca[0];
    int prvi_clan=1;
    auto it=spisak_djece.begin();
    for (int t=0; t<br_timova; t++) {       //petljom prolazim kroz timove i svaki popunjavam odg imenima
        int br_c=0;
        if (t<tim_plus) br_c=clanovi+1;
        else br_c=clanovi;
//std::cout<<br_c<<" broj clanova ";
//        tim[0].insert(pom);
//        spisak_djece.erase(it);
        for (int tp=0; tp<br_c; tp++) {         //petlja koja broji koliko djece je u odredjenom timu
            int brojac=0;
            for (int i=0; i<pom.size(); i++) {
                if (Slovo_ili_broj(pom[i])) brojac++;       //koliko puta cu ici eci peci pec, tj brojim slova imena zadnjeg unesenog clana
//std::cout<<pom[i]<<" slova ";
            }
//std::cout<<std::endl;
            for (int i=0; i<brojac; i++,it++) {
                if (it==spisak_djece.end()) it=spisak_djece.begin();//kruzna lista
                if (i==brojac-1 || prvi_clan==1) {              //ime smijestam u tim, postavljam pom na to ime i brisem to ime
                    tim[t].insert(*it);
                    pom=*it;
                    it=spisak_djece.erase(it);
                    it--;
                    if (prvi_clan==1) {prvi_clan=0; i=brojac;}
                }
            }
        }
    }
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
                if (pom==0) {std::cout<<x; pom=1;}
                else std::cout<<", "<<x;
            }
            std::cout<<std::endl;
        }
    }
    catch (std::logic_error a) {
        std::cout<<"Izuzetak: "<<a.what();
    }
	return 0;
}