/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <stdexcept>
#include <set>
#include <memory>
struct Dijete{
    std::string ime;
    std::shared_ptr<Dijete> sljedeci;
};
int Prebroji(std::string s){
    int br(0);
    for(int i=0; i<s.length(); i++){
        if( (s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9') ) br++;
    }
    return br;
}
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> matrica, int broj_timova){
    if(broj_timova<1 || broj_timova>matrica.size()) throw std::logic_error("Razvrstavanje nemoguce");
    std::vector<std::set<std::string>> skup(broj_timova);
    std::shared_ptr<Dijete> pocetak(nullptr);
    std::shared_ptr<Dijete> prethodni;
    //kreiranje povezane liste cvorova
    int brojac(0);
    try{
    for(int i=0; i<matrica.size(); i++){
        std::shared_ptr<Dijete> novi(new Dijete);
        novi->ime=matrica[i];
        novi->sljedeci=nullptr;
        if(!pocetak) pocetak=novi;
        else prethodni->sljedeci=novi;
        prethodni=novi;
        if(i==matrica.size()-1) {     //ukoliko se radi o posljednjem elementu, tada:
            prethodni->sljedeci=pocetak; //on treba pokazivati na prvi element u ovoj kruznoj listi
        }
        brojac++;
    } }
    catch(std::bad_alloc e){ //dealociranje elemenata u slucaju da nema dovoljno memorije tj dodje do bacanja izuzetka
    if(brojac==0) throw;
        while(pocetak!=nullptr){
            std::shared_ptr<Dijete> pomocni(pocetak);
            pocetak=pocetak->sljedeci;
            pomocni->sljedeci=nullptr;
            pomocni=nullptr;
        }
        throw;
    }
    int broj_vecih(matrica.size()%broj_timova), broj_djece(matrica.size()),velicina_tima(broj_djece/broj_timova);
    int br(0),vel(0), i(0);
    //while-petlja u kojoj formiramo timove
    while(broj_djece>0){
        if(broj_djece!=1){
            if(broj_vecih>0 && i==velicina_tima+1) {broj_vecih--;br++; i=0; }
            else if(broj_vecih==0 && i==velicina_tima) {br++; i=0;}
            skup[br].insert(pocetak->ime);
            vel=Prebroji(pocetak->ime)-1;
            std::shared_ptr<Dijete> pomocni(pocetak);
            pocetak=pocetak->sljedeci; //ovime prelazimo na sljedeci element u kruznoj listi
            prethodni->sljedeci=pocetak; //pokazivac koji je pokazivao na ovo dijete preusmjeravamo na sljedeće dijete
            pomocni->sljedeci=nullptr; pomocni=nullptr;//dealociranje cvora koji je ispao iz liste
            broj_djece--;
            i++;
            while(vel>0){ //blok naredbi kojim pomjeramo pokazivac za onoliko mjesta kolika je duzina izbacenog imena
                pocetak=pocetak->sljedeci;
                prethodni=prethodni->sljedeci;
                vel--;
            }
        }
        else{ //poseban uslov ako je riječ o posljednjem preostalom djetetu, nešto jednostavniji postupak
            if(broj_vecih>0 && i==velicina_tima+1) {broj_vecih--;br++; i=0; }
            else if(broj_vecih==0 && i==velicina_tima) {br++; i=0;}
            skup[br].insert(pocetak->ime);//ubacivanje imena u skup
            pocetak->sljedeci=nullptr;
            pocetak=nullptr; //dealociranje tog elementa
            broj_djece--;
            i++;
        }
    }
    return skup;
}
int main ()
{
    int n;
    std::cout<<"Unesite broj djece: ";
    std::cin>>n;
    std::vector<std::string> matrica(n);
    std::cout<<"Unesite imena djece: "<<std::endl;
    std::cin.ignore(10000,'\n');
    for(int i=0; i<n; i++)
        std::getline(std::cin, matrica[i]);
    std::cout<<"Unesite broj timova: ";
    int tim;
    std::cin>>tim;
    try{
        auto skup(Razvrstavanje(matrica, tim));
        for(int i=0; i<skup.size(); i++){
            std::cout<<"Tim "<<i+1<<": ";
            for(auto it=skup[i].begin(); it!=skup[i].end(); it++){
                if(it==--skup[i].end()) std::cout<<*it;
                else std::cout<<*it<<", ";
            }
            std::cout<<std::endl;
        }
    }
    catch(std::logic_error e){
        std::cout<<"Izuzetak: "<<e.what();
    }
    catch(std::bad_alloc e){
        std::cout<<"Nedovoljno memorije";
    }
	return 0;
}