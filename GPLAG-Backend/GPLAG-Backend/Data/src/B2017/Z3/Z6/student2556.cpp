/B2017/2018: Zadaća 3, Zadatak 6
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <memory>

enum class Boje
{
    Pik, Tref, Herc, Karo
};

struct Karta {
    Boje boja;
    std::string vrijednost;
};

struct Cvor {
    Karta karta;
    std::shared_ptr<Cvor> sljedeci;
};

int PrebrojiKarte(std::shared_ptr<Cvor> &spil)
{
    int i(0);
    std::shared_ptr<Cvor> pok(spil);
    pok=pok->sljedeci;
    while(pok!=spil) {
        pok=pok->sljedeci;
        i++;
    }
    return ++i;
}

void IspisiSpil(std::shared_ptr<Cvor> &poc)
{
    for(int i=1; i<=4; i++) {
        if(i==1) std::cout<<"Pik: ";
        else if(i==2) std::cout<<"Tref: ";
        else if(i==3) std::cout<<"Herc: ";
        else if(i==4) std::cout<<"Karo: ";
        while((poc->karta).boja == Boje(i-1)) {
            std::cout<<(poc->karta).vrijednost<<" ";
            poc=poc->sljedeci;
        }
        std::cout<<std::endl;
    }
    //  UnistiSpil(poc);
}
std::shared_ptr<Cvor> KreirajSpil()
{
    std::shared_ptr<Cvor> pocetak(nullptr), prethodni;
    int i(0);
    std::vector<std::string> vrijednosti {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    for(;;) {
        Karta tekuca;
        if(i<13) tekuca.boja = Boje(0);
        else if(i<26) tekuca.boja = Boje(1);
        else if(i<39) tekuca.boja = Boje(2);
        else if(i<52) tekuca.boja = Boje(3);
        tekuca.vrijednost = vrijednosti[i%13];
        if(i==52) break;
        std::shared_ptr<Cvor> novi(new Cvor({tekuca, nullptr}));
        if(!pocetak) pocetak = novi;
        else prethodni->sljedeci=novi;
        prethodni=novi;
        i++;
    }
    prethodni->sljedeci=pocetak;
    return pocetak;
}
void ObrisiElement(std::shared_ptr<Cvor> &prije, std::shared_ptr<Cvor> &poslije)
{
    prije=prije->sljedeci;
    auto brisi(poslije->sljedeci);
    poslije->sljedeci=prije;
}

void IzbaciKarte(std::shared_ptr<Cvor> &pok, std::multimap<Boje, std::string> &multimapa)
{
    std::shared_ptr<Cvor> trenutni(pok), posljednji(pok);
    trenutni=trenutni->sljedeci;
    std::multimap<Boje, std::string>::iterator it_m;
    for(it_m=multimapa.begin(); it_m!=multimapa.end(); it_m++) {
        std::shared_ptr<Cvor> p(pok);
        int i(0);
        trenutni=pok;
        posljednji=pok;
        trenutni=trenutni->sljedeci;
        while(trenutni!=p) {
            if(std::get<0>(*it_m) == (trenutni->karta).boja && std::get<1>(*it_m) == (trenutni->karta).vrijednost) {
                ObrisiElement(trenutni, posljednji);
            }
            trenutni=trenutni->sljedeci;
            posljednji=posljednji->sljedeci;
            i++;

            //   if(i>52) throw std::logic_error("Neispravna lista!");

        }
    }
}



std::stack<std::pair<Boje, std::string>> IzbaciKarteRazbrajanjem(std::shared_ptr<Cvor> &pok, const short int r, const int b)
{

    if(r<1 || r>52 || b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    int broj_el(PrebrojiKarte(pok));
     if(broj_el>52) throw std::logic_error("Neispravna lista!");

    std::stack<std::pair<Boje, std::string>> stek;
    std::multimap<Boje, std::string> multimapa;
    int izbaceni(0), prolazi(1);
    auto p(pok), p_1(pok);

    while(izbaceni!=b) {

        bool prekini(false);
        for(auto it_m(multimapa.begin()); it_m!= multimapa.end(); it_m++) {
            if((p->karta).vrijednost == it_m->second && (p->karta).boja == it_m->first) {
                p=p->sljedeci;
                prekini=true;
                break;
            }
        }
        if(prolazi%r==0) {
            if(prekini) continue;
            stek.push(std::make_pair((p->karta).boja, (p->karta).vrijednost));
            multimapa.insert(std::make_pair((p->karta).boja, (p->karta).vrijednost));
            izbaceni++;
            if(izbaceni==b) break;
        }

        //  if(p_1 == pok && prolazi>52 && prolazi<104) throw std::logic_error("Neispravna lista!");
        prolazi++;
        p=p->sljedeci;
    }
    IzbaciKarte(pok, multimapa);
    return stek;
}

bool JeLi(std::string a, std::string b){
    std::vector<std::string> znak {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    int i, j;
    for(i=0;i<znak.size();i++) {
        if(znak[i]==a) break;
    }
    for(j=0;j<znak.size();j++){
        if(znak[j]==b) break;
    }
    return j<i;
}
void VratiPosljednjihNKarata(std::shared_ptr<Cvor> &pok, std::stack<std::pair<Boje, std::string>> stek, int n)
{

    if(n<0) throw std::domain_error("Broj n je besmislen!");
    if(stek.size()<n) throw std::range_error("Nedovoljno karata u redu!");

    auto it(pok), pit(pok);
    pit=pit->sljedeci;
    for(;pit->sljedeci!=pok;pit=pit->sljedeci);
    auto temp(it);
    auto temp2(pit);
    
    /*for(auto pok2(pok); pok2!=it; pok2=pok2->sljedeci){
        throw std::logic_error("Nelegalne karte!");
    }*/

    for(int i=0;i<n;i++){
        it=temp;
        pit=temp2;
        while(stek.top().first > it->karta.boja) {
            it=it->sljedeci;
            pit=pit->sljedeci;
        }
        while(JeLi(stek.top().second, it->karta.vrijednost)){
            it=it->sljedeci;
            pit=pit->sljedeci;
        }
        std::shared_ptr<Cvor> novi(new Cvor{{stek.top().first, stek.top().second}, nullptr});
        novi->sljedeci=it;
        pit->sljedeci=novi;
        stek.pop();
    }

}

int main ()
{
    std::shared_ptr<Cvor> spil;
    try {
        spil=KreirajSpil();
        int r, b;
        std::cout<<"Unesite korak razbrajanja: ";
        std::cin>>r;
        std::cout<<"Unesite broj karata koje zelite izbaciti: ";
        std::cin>>b;
        std::stack<std::pair<Boje, std::string>> stek(IzbaciKarteRazbrajanjem(spil, r, b));
        int razlika(PrebrojiKarte(spil));
        std::cout<<"U spilu trenutno ima "<<razlika<<" karata, i to: "<<std::endl;
        IspisiSpil(spil);

        std::cout<<"Unesite broj karata koje zelite vratiti u spil: ";
        int n;
        std::cin>>n;
        VratiPosljednjihNKarata(spil, stek, n);
        int razlika2(PrebrojiKarte(spil));
        std::cout<<"U spilu trenutno ima "<<razlika2<<" karata, i to: "<<std::endl;
        IspisiSpil(spil);

    } catch(std::logic_error izuzetak) {
        std::cout<<"Izuzetak: "<<izuzetak.what();
    } catch(std::range_error izuzetak2) {
        std::cout<<"Izuzetak: "<<izuzetak2.what();
    } catch(std::domain_error izuzetak3) {
        std::cout<<"Izuzetak: "<<izuzetak3.what();
    } catch(...) {
    }
    spil->sljedeci=nullptr;
    
    return 0;
}
