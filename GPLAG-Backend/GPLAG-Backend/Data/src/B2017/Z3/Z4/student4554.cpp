/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <utility>
#include <string>
#include <list>
#include <map>
#include <stdexcept>
#include <queue>
#include <iterator>
#include <sstream>

enum class Boje
{
    Pik, Tref, Herc, Karo
};

typedef std::pair<Boje, std::string> Karta;
typedef std::list<std::pair<Boje, std::string>> Spil;
typedef std::multimap<Boje, std::string> Multimapa;
typedef std::queue<Karta> Red;

// funkcija iz predavanja 3_b
template<typename Tip> std::string PretvoriUString(Tip x)
{
    std::ostringstream s;
    s<<x;
    return s.str();
}
int VratiBoju(const Karta &karta)
{
    if((int) (karta.first) == 0) return 0;
    if((int) (karta.first) == 1) return 1;
    if((int) (karta.first) == 2) return 2;
    if((int) (karta.first) == 3) return 3;
    return 4;//neispravna
}

int VratiVrijednost(const Karta &karta)
{
    if(karta.second == "2") return 2;
    if(karta.second == "3") return 3;
    if(karta.second == "4") return 4;
    if(karta.second == "5") return 5;
    if(karta.second == "6") return 6;
    if(karta.second == "7") return 7;
    if(karta.second == "8") return 8;
    if(karta.second == "9") return 9;
    if(karta.second == "10") return 10;
    if(karta.second == "J") return 11;
    if(karta.second == "Q") return 12;
    if(karta.second == "K") return 13;
    if(karta.second == "A") return 14;
    return 0;//neispravna


}
Spil KreirajSpil()
{

    return { {Boje::Pik, "2"}, {Boje::Pik, "3"}, {Boje::Pik, "4"}, {Boje::Pik, "5"},{Boje::Pik, "6"},{Boje::Pik, "7"},{Boje::Pik, "8"},{Boje::Pik, "9"},{Boje::Pik, "10"},{Boje::Pik, "J"},{Boje::Pik, "Q"},{Boje::Pik, "K"},{Boje::Pik, "A"},
        {Boje::Tref, "2"},{Boje::Tref, "3"},{Boje::Tref, "4"},{Boje::Tref, "5"},{Boje::Tref, "6"},{Boje::Tref, "7"},{Boje::Tref, "8"},{Boje::Tref, "9"},{Boje::Tref, "10"},{Boje::Tref, "J"},{Boje::Tref, "Q"},{Boje::Tref, "K"},{Boje::Tref, "A"},
        {Boje::Herc, "2"},{Boje::Herc, "3"},{Boje::Herc, "4"},{Boje::Herc, "5"},{Boje::Herc, "6"},{Boje::Herc, "7"},{Boje::Herc, "8"},{Boje::Herc, "9"},{Boje::Herc, "10"},{Boje::Herc, "J"},{Boje::Herc, "Q"},{Boje::Herc, "K"},{Boje::Herc, "A"},
        {Boje::Karo, "2"},{Boje::Karo, "3"},{Boje::Karo, "4"},{Boje::Karo, "5"},{Boje::Karo, "6"},{Boje::Karo, "7"},{Boje::Karo, "8"},{Boje::Karo, "9"},{Boje::Karo, "10"},{Boje::Karo, "J"},{Boje::Karo, "Q"},{Boje::Karo, "K"},{Boje::Karo, "A"}
    };
}



void IzbaciKarte (Spil &spil, Multimapa &multimapa)
{
    if(spil.size() > 52) throw std::logic_error("Neispravna lista!");
     
    for(auto m:multimapa) {
        Spil::iterator pozicija_s = spil.begin(); //pozicija karte
        for(auto j = spil.begin(); j != spil.end(); j++) {
            if((m.first == j->first) && (m.second == j->second)) {
                j=spil.erase(j);
                j--;
            }
        }

    }
}



Red IzbaciKarteRazbrajanjem(Spil &spil, const short int &r, const int &b)
{
    if((r<1 || r> 52) || b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    if(spil.size() > 52 )throw std::logic_error("Neispravna lista!");

    /*   Spil::iterator prethodna = spil.begin();//iterator na prethodnu
       Spil::iterator k=prethodna++;
       for(auto i=k; i!=spil.end(); i++){
           if((int)(prethodna->first) > (int)(i->first))
               throw std::logic_error("Neispravna lista!");
           if((prethodna->second > i->second) && (prethodna->first >= i->first))

           std::cout<<prethodna->second <<" "<< i->second<< " "<<(int)(prethodna->first)<<" "<<(int) (i->first)<<std::endl;
               throw std::logic_error("Neispravna lista!");

       }*/

    Red red;
    int brojac = r-1, brisanje = 0;
    for (auto i=spil.begin(); i!=spil.end(); i++) {
        if(brisanje==b) break;
        for(int j=1; j<=brojac; j++) {
            if(i==spil.end()) {
                i=spil.begin();
            }
            i++;
        }
        if(i == spil.end()) {
            i = spil.begin();
        }
        red.push((*i));
        i = spil.erase(i);
        brisanje++;
        i--;
        brojac = r-1;
    }
    return red;
}



void VratiPrvihNKarata(Spil &spil, Red &red, int n)
{
    int velicina = red.size();

    if(n > velicina) throw std::range_error("Nedovoljno karata u redu!");
    if(n < 0) throw std::domain_error("Broj n je besmislen!");

    int za_izbacanje(n);
    for(int i=1; i<=za_izbacanje; i++) {
        Karta karta = red.front();
        spil.push_back(karta);
        red.pop();
    }



    spil.sort([](const Karta &karta_1, const Karta &karta_2) {
        if(VratiBoju(karta_1)>VratiBoju(karta_2)) return false;
        if(VratiVrijednost(karta_1)>VratiVrijednost(karta_2) && VratiBoju(karta_1)>=VratiBoju(karta_2))
            return false;
        return true;
    });



    /*
        for(int i=0; i<velicina; i++) {
            Karta temp = red.front();
            bool ispravna = false;
    */
    //  if((int)(temp.first) < 0 || (int)(temp.first) > 3) throw std::logic_error("Neispravne karte!");
    /*
            for(int j=2; j <= 10; j++) {
                if(temp.second == PretvoriUString(j)) ispravna = true;
            }
            if(temp.second == "J" || temp.second == "Q" || temp.second == "K" || temp.second == "A") ispravna = true;
            if(ispravna == false) throw std::logic_error("Neispravne karte!");
            red.pop();
            red.push(temp);
        }

        for(int i = 0; i<n; i++) {
            Karta k_red = red.front();
            int boja_k_red = VratiBoju(k_red);
            int vrijednost_k_red = VratiVrijednost(k_red);

            for(auto i=spil.begin(); i != spil.end(); i++) {
                Karta k_spil = *i;
                int boja_k_spil = VratiBoju(k_spil);
                int vrijednost_k_spil = VratiVrijednost(k_spil);
                if(boja_k_red > boja_k_spil)
                    continue;
                if((vrijednost_k_red > vrijednost_k_spil) && (boja_k_red >= boja_k_spil))
                    continue;

                spil.insert(i, k_red);
            }
            red.pop();
        }
         for(int i=0; i < velicina-n; i++) {
             red.pop();
         }
         velicina = red.size();  
    
        int pik_brojac=0, tref_brojac=0, herc_brojac=0, karo_brojac=0;
        for(int i=0; i<velicina; i++) {
            Karta temp = red.front();

            if((int)(temp.first) == 0) pik_brojac++;
            if((int)(temp.first) == 1) tref_brojac++;
            if((int)(temp.first) == 2) herc_brojac++;
            if((int)(temp.first) == 3) karo_brojac++;

            red.pop();
            red.push(temp);
        }*/

    /* while(!red.empty()) {
         Karta temp = red.front();
         for (auto i=spil.begin(); i!=spil.end(); i++) {
             if(((int)(temp.first) > (int)(i->first)))
                 continue;
             if(((temp.second > i->second) && ((int)(temp.first) >=(int)(i->first))))
                 continue;

             spil.insert(i,temp);
             red.pop();
         }
     }*/

}

int main ()
{
    Spil spil_karata;

    int korak_r, za_izbacanje;
    std::cout<<"Unesite korak razbrajanja: ";
    std::cin>>korak_r;

    std::cout<<"Unesite broj karata koje zelite izbaciti: ";
    std::cin>>za_izbacanje;
 try {
    spil_karata = KreirajSpil();


    Red red = IzbaciKarteRazbrajanjem(spil_karata,korak_r,za_izbacanje);
    std::cout<<"U spilu trenutno ima "<<spil_karata.size()<<" karata, i to: ";

    int pik_brojac=0, tref_brojac=0, herc_brojac=0, karo_brojac=0;

    for(auto i = spil_karata.begin(); i != spil_karata.end(); i++) {
        if((int)((*i).first) == 0) pik_brojac++;
        if((int)((*i).first) == 1) tref_brojac++;
        if((int)((*i).first) == 2) herc_brojac++;
        if((int)((*i).first) == 3) karo_brojac++;
    }


    int pocetak_pik=0, pocetak_tref=pik_brojac,  pocetak_herc=pik_brojac+tref_brojac,  pocetak_karo=pik_brojac+tref_brojac+herc_brojac;
    int ispisao_pik = false, ispisao_tref = false, ispisao_herc = false, ispisao_karo = false;
    int brojac_ispisa = 0;

    for(auto i = spil_karata.begin(); i != spil_karata.end(); i++) {
        if(ispisao_pik == false && brojac_ispisa == pocetak_pik) {
            ispisao_pik = true;
            std::cout<<std::endl<<"Pik: ";
        }
        //     std::cout<<(int)((*i).first)<<" "<<(*i).second<<std::endl;
        if(ispisao_tref == false && brojac_ispisa == pocetak_tref) {
            ispisao_tref = true;
            std::cout<<std::endl<<"Tref: ";
        }
        if(ispisao_herc == false && brojac_ispisa == pocetak_herc) {
            ispisao_herc = true;
            std::cout<<std::endl<<"Herc: ";
        }
        if(ispisao_karo == false && brojac_ispisa == pocetak_karo) {
            ispisao_karo = true;
            std::cout<<std::endl<<"Karo: ";
        }
        std::cout<<(*i).second<<" ";
        brojac_ispisa++;
    }
        int za_vracanje;
        std::cout<<"\nUnesite broj karata koje zelite vratiti u spil: ";
        std::cin>>za_vracanje;



        VratiPrvihNKarata(spil_karata, red, za_vracanje);

        std::cout<<"U spilu trenutno ima "<<spil_karata.size()<<" karata, i to: ";

        pik_brojac=0;
        tref_brojac=0;
        herc_brojac=0;
        karo_brojac=0;
        ispisao_pik = false;
        ispisao_tref = false;
        ispisao_herc = false;
        ispisao_karo = false;
        brojac_ispisa=0;

        for(auto i = spil_karata.begin(); i != spil_karata.end(); i++) {
            if((int)((*i).first) == 0) pik_brojac++;
            if((int)((*i).first) == 1) tref_brojac++;
            if((int)((*i).first) == 2) herc_brojac++;
            if((int)((*i).first) == 3) karo_brojac++;
        }
        pocetak_pik=0;
        pocetak_tref=pik_brojac;
        pocetak_herc=pik_brojac+tref_brojac;
        pocetak_karo=pik_brojac+tref_brojac+herc_brojac;

        for(auto i = spil_karata.begin(); i != spil_karata.end(); i++) {
            if(ispisao_pik == false && brojac_ispisa == pocetak_pik) {
                ispisao_pik = true;
                std::cout<<std::endl<<"Pik: ";
            }
            if(ispisao_tref == false && brojac_ispisa == pocetak_tref) {
                ispisao_tref = true;
                std::cout<<std::endl<<"Tref: ";
            }
            if(ispisao_herc == false && brojac_ispisa == pocetak_herc) {
                ispisao_herc = true;
                std::cout<<std::endl<<"Herc: ";
            }
            if(ispisao_karo == false && brojac_ispisa == pocetak_karo) {
                ispisao_karo = true;
                std::cout<<std::endl<<"Karo: ";
            }
            std::cout<<(*i).second<<" ";
            brojac_ispisa++;
        }
    } catch(std::domain_error izuzetak) {
        std::cout << "Izuzetak: "<<izuzetak.what();


    }  catch(std::logic_error izuzetak) {
        std::cout << "Izuzetak: "<<izuzetak.what();
    }  catch(std::range_error izuzetak) {
        std::cout << "Izuzetak: "<<izuzetak.what();
    }
        return 0;
    }
