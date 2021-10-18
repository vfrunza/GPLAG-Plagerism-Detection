/B2017/2018: Zadaća 3, Zadatak 5
#include <iostream>
#include <string>
#include <stdexcept>
#include <map>

enum class Boje {Pik, Tref, Herc, Karo};

struct Karta {
    Boje boja;
    std::string vrijednost;
};

struct Cvor {
    Karta karta;
    Cvor *sljedeci;
};

std::string PostaviVrijednost(int i) {
    std::string s;
    if(i>13) {
        do {
            i-=13;
        } while(i>13);
    }
        if(i%13>=1 && i%13<=9) s=std::to_string(i+1);
        else if(i%13==10) s="J";
        else if(i%13==11) s="Q";
        else if(i%13==12) s="K";
        else s="A";
        return s;
}

Cvor *KreirajSpil() {
    Karta x;
    Cvor *pocetak(nullptr), *prethodni;
    for(int i=1; i<=52; i++) {
        if(i>=1 && i<=13) {
            x.boja=Boje::Pik;
            x.vrijednost=PostaviVrijednost(i);
        }
        else if(i>=14 && i<=26) {
            x.boja=Boje::Tref;
            x.vrijednost=PostaviVrijednost(i);
        }
        else if(i>=27 && i<=39) {
            x.boja=Boje::Herc;
            x.vrijednost=PostaviVrijednost(i);
        }
        else {
            x.boja=Boje::Karo;
            x.vrijednost=PostaviVrijednost(i);
        }
    Cvor *novi(new Cvor{x, nullptr});
    if(!pocetak) pocetak=novi;
    else prethodni->sljedeci=novi;
    prethodni=novi;
    }
    prethodni->sljedeci=pocetak;
    
    return pocetak;
}

bool TestirajSpil(Cvor *pocetak) {
    Cvor *p=pocetak;
    int i(0);
    do {
        p=p->sljedeci;
        i++;
    }while(p!=pocetak && p!=nullptr);
    if(i>52) return false;
    p=pocetak;
    do {
        if(!((p->karta).boja==Boje::Pik || (p->karta).boja==Boje::Tref || (p->karta).boja==Boje::Herc || (p->karta).boja==Boje::Karo)) return false;
        if(!((p->karta).vrijednost=="2" || (p->karta).vrijednost=="3" || (p->karta).vrijednost=="4" ||
        (p->karta).vrijednost=="5" || (p->karta).vrijednost=="6" || (p->karta).vrijednost=="7" || (p->karta).vrijednost=="8" ||
        (p->karta).vrijednost=="9" || (p->karta).vrijednost=="10" || (p->karta).vrijednost=="J" ||
        (p->karta).vrijednost=="Q" ||(p->karta).vrijednost=="K" || (p->karta).vrijednost=="A")) return false;
        p=p->sljedeci;
    }while(p!=pocetak);
    
    p=pocetak;
    Cvor *prethodni=pocetak;
    do {
        if((prethodni->karta).boja>(p->karta).boja) return false;
        prethodni=pocetak;
        p=p->sljedeci;
    }while(p!=pocetak);
    
    p=pocetak;
    Karta prethodna_karta=p->karta;
    int vrijednost1;
    if(prethodna_karta.vrijednost=="J") vrijednost1=11;
    else if(prethodna_karta.vrijednost=="Q") vrijednost1=12;
    else if(prethodna_karta.vrijednost=="K") vrijednost1=13;
    else if(prethodna_karta.vrijednost=="A") vrijednost1=14;
    else vrijednost1=std::stoi(prethodna_karta.vrijednost);
    p=p->sljedeci;
    while(p!=pocetak) {
        int vrijednost2;
        if((p->karta).vrijednost=="J") vrijednost2=11;
        else if((p->karta).vrijednost=="Q") vrijednost2=12;
        else if((p->karta).vrijednost=="K") vrijednost2=13;
        else if((p->karta).vrijednost=="A") vrijednost2=14;
        else vrijednost2=std::stoi((p->karta).vrijednost);
        if(prethodna_karta.boja==(p->karta).boja && vrijednost1>=vrijednost2) return false;
        prethodna_karta=p->karta;
        p=p->sljedeci;
    }while(p!=pocetak);
    return true;
    
}

void IzbaciKarte(Cvor *&pocetak, std::multimap<Boje, std::string> &mapa) {
    if(!TestirajSpil(pocetak)) throw std::logic_error("Neispravna lista");
    for(auto it(mapa.begin()); it!=mapa.end(); it++) {
        Boje m_boja=it->first;
        std::string m_vrijednost=it->second;
    Cvor *p=pocetak;
    Cvor *kraj, *temp=pocetak;
    do {
        kraj=temp;
        temp=temp->sljedeci;
    }while(temp!=pocetak);
    
    Cvor* prethodni=pocetak, *brisi=pocetak;
    do {
        if((p->karta).boja==m_boja && (p->karta).vrijednost==m_vrijednost && p==pocetak) {
           pocetak=p->sljedeci;
           delete kraj->sljedeci;
           kraj->sljedeci=pocetak;
           for(auto iter(mapa.begin()); iter!=mapa.end(); iter++) {
               if(iter->first==m_boja && iter->second==m_vrijednost) mapa.erase(iter);
           }
        }
        if((p->karta).boja==m_boja && (p->karta).vrijednost==m_vrijednost && p==kraj) {
            prethodni->sljedeci=pocetak;
            delete brisi->sljedeci;
            for(auto iter(mapa.begin()); iter!=mapa.begin(); iter++) {
                if(iter->first==m_boja && iter->second==m_vrijednost) mapa.erase(iter);
            }
        }
        if((p->karta).boja==m_boja && (p->karta).vrijednost==m_vrijednost) {
            prethodni->sljedeci=p->sljedeci;
            delete brisi->sljedeci;
            for(auto iter(mapa.begin()); iter!=mapa.end(); iter++) {
                if(iter->first==m_boja && iter->second==m_vrijednost) mapa.erase(iter);
            }
        }
        prethodni=p;
        brisi=p;
        p=p->sljedeci;
    }while(p!=pocetak);
    }
}

int main ()
{
    std::multimap<Boje, std::string> mapa {{Boje::Pik, "2"}, {Boje::Herc, "3"}, {Boje::Karo, "A"}};
    Cvor *pocetak=KreirajSpil();
    IzbaciKarte(pocetak, mapa);
    Cvor *p=pocetak;
    do {
        std::cout<<int((p->karta).boja)<<" "<<(p->karta).vrijednost<<std::endl;
        p=p->sljedeci;
    }while(p!=pocetak);
    
	return 0;
}
