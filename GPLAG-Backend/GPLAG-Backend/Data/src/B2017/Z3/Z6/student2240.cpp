/B2017/2018: Zadaća 3, Zadatak 6
#include <iostream>
#include <string>
#include <stack>
#include <utility>
#include <stdexcept>
#include <map>
#include <memory>


enum class Boje {Pik, Tref, Herc, Karo};


struct Karta
{
  Boje boja;
  std::string vrijednost;
};

struct Cvor
{
    Karta karta;
    std::shared_ptr<Cvor> sljedeci;
};


std::shared_ptr<Cvor> KreirajSpil()
{
    std::shared_ptr<Cvor> pocetak {nullptr};
    std::shared_ptr<Cvor> prethodni;

    for (int i{};i<52;i++)
        {
           std::shared_ptr<Cvor> novi = std::make_shared<Cvor> ();              ///Kreiranje i popunjavanje cvorova.

            if (i == 0 || i == 13 || i == 26 || i == 39)
                novi->karta.vrijednost = "2";
            if (i == 1 || i == 14 || i == 27 || i == 40)
                novi->karta.vrijednost = "3";
            if (i == 2 || i == 15 || i == 28 || i == 41)
                novi->karta.vrijednost = "4";
            if (i == 3 || i == 16 || i == 29 || i == 42)
                novi->karta.vrijednost = "5";
            if (i == 4 || i == 17 || i == 30 || i == 43)
                novi->karta.vrijednost = "6";
            if (i == 5 || i == 18 || i == 31 || i == 44)
                novi->karta.vrijednost = "7";
            if (i == 6 || i == 19 || i == 32 || i == 45)
                novi->karta.vrijednost = "8";
            if (i == 7 || i == 20 || i == 33 || i == 46)
                novi->karta.vrijednost = "9";
            if (i == 8 || i == 21 || i == 34 || i == 47)
                novi->karta.vrijednost = "10";
            if (i == 9 || i == 22 || i == 35 || i == 48)
                novi->karta.vrijednost = "J";
            if (i == 10 || i == 23 || i == 36 || i == 49)
                novi->karta.vrijednost = "Q";
            if (i == 11 || i == 24 || i == 37 || i == 50)
                novi->karta.vrijednost = "K";
            if (i == 12 || i == 25 || i == 38 || i == 51)
                novi->karta.vrijednost = "A";

            if (i>=0 && i<=12)
                novi->karta.boja = Boje::Pik;
            if (i>=13 && i<=25)
                novi->karta.boja = Boje::Tref;
            if (i>=26 && i<=38)
                novi->karta.boja = Boje::Herc;
            if (i>=39 && i<=51)
                novi->karta.boja = Boje::Karo;

            novi->sljedeci = nullptr;

            if (!pocetak)
                pocetak = novi;
            else
                prethodni->sljedeci = novi;

            prethodni = novi;
        }

    prethodni->sljedeci = pocetak;                                              ///Posljednji element pokazuje na prvi.


    return pocetak;
}

int PrebrojiKarte (std::shared_ptr<Cvor> spil)
{
    if (spil == nullptr)
        return 52;

    int brojac{};

    std::shared_ptr<Cvor> p = spil;
    p = p->sljedeci;
    brojac++;

    for (p; p!=spil; p = p->sljedeci)
        brojac++;


    return 52-brojac;
}

std::stack<std::pair<std::string,std::string>> IzbaciKarteRazbrajanjem (std::shared_ptr<Cvor> &spil, const int &x, const int &b)
{
    std::pair<int,int> izbacivanje (x,b);
    
    if (izbacivanje.first<1 || izbacivanje.first>52)
        throw std::logic_error ("Neispravni elementi za izbacivanje!");

    if (izbacivanje.second<1)
        throw std::logic_error ("Neispravni elementi za izbacivanje!");

    std::shared_ptr<Cvor> p = spil;                                                             ///Pronalazenje broja elemenata u spilu.
    p = p->sljedeci;
    int n{1};
    for (p ; p!=spil; p = p->sljedeci)
        n++;

    std::stack<std::pair<std::string,std::string>> rezultat;

    int r{};
    int trenutno_izbaceni{};

    r+=izbacivanje.first;

    p = spil;

    while(true)
        {
            if (n == trenutno_izbaceni)
                break;

            std::shared_ptr<Cvor> pomocni;
            for (int j{1};j<r;j++)
                {
                    if (j == r-1)
                        pomocni = p;

                    p = p->sljedeci;
                }

            if (r == 1)
                {
                    pomocni = p;
                    p = p->sljedeci;
                }



            std::shared_ptr<Cvor> brisanje = p;
            p = p->sljedeci;

            if (brisanje == pomocni)                                            ///Ako je ostao samo jedan element u spilu.
                {
                    std::string s1,s2;
                    int broj;
                    broj = (int)brisanje->karta.boja;
                    if (broj == 0)
                        s1 = "Pik";
                    if (broj == 1)
                        s1 = "Tref";
                    if (broj == 2)
                        s1 = "Herc";
                    if (broj == 3)
                        s1 = "Karo";

                    s2 = brisanje->karta.vrijednost;
                    std::pair<std::string,std::string> upis = std::make_pair(s1,s2);
                    rezultat.push(upis);

                    brisanje->sljedeci = nullptr;
                    brisanje = nullptr;
                    pomocni->sljedeci = nullptr;
                    pomocni = nullptr;
                    spil->sljedeci = nullptr;
                    spil = nullptr;
                    break;
                }

            pomocni->sljedeci = p;

            std::string s1,s2;                                                  ///Upis u red.
            int broj;
            broj = (int)brisanje->karta.boja;
            if (broj == 0)
                s1 = "Pik";
            if (broj == 1)
                s1 = "Tref";
            if (broj == 2)
                s1 = "Herc";
            if (broj == 3)
                s1 = "Karo";

            s2 = brisanje->karta.vrijednost;
            std::pair<std::string,std::string> upis = std::make_pair(s1,s2);

            rezultat.push(upis);

            if (brisanje == spil)                                               ///Ako je element koji se brise prvi, on postaje slijedeci.
                spil = p;

            brisanje->sljedeci = nullptr;
            brisanje = nullptr;

            trenutno_izbaceni++;
            if (trenutno_izbaceni == izbacivanje.second)
                break;

        }

    return rezultat;
}

void IzbaciKarte (std::shared_ptr<Cvor> &spil, std::multimap<Boje, std::string> &mapa)
{
    if (PrebrojiKarte(spil) < 0)
        throw std::logic_error ("Neispravna lista!");
    
    auto it_mape = mapa.begin();    
    while (it_mape != mapa.end())
    {
        Boje boja = it_mape->first;
        std::string znak = it_mape->second;
        
        int broj_karte;
        if (znak == "2")
            broj_karte = 0;
        if (znak == "3")
            broj_karte = 1;
        if (znak == "4")
            broj_karte = 2;
        if (znak == "5")
            broj_karte = 3;
        if (znak == "6")
            broj_karte = 4;
        if (znak == "7")
            broj_karte = 5;
        if (znak == "8")
            broj_karte = 6;
        if (znak == "9")
            broj_karte = 7;
        if (znak == "10")
            broj_karte = 8;
        if (znak == "J")
            broj_karte = 9;
        if (znak == "Q")
            broj_karte = 10;
        if (znak == "K")
            broj_karte = 11;
        if (znak == "A")
            broj_karte = 12;
        
        
        int brojac = 1;
        bool pocetak = false;
        
        std::shared_ptr<Cvor> it = spil;
        it = it->sljedeci;
        brojac++;
        for (it; it!=spil; it = it->sljedeci)
        {
            if (it->karta.boja == boja && it->karta.vrijednost == znak)
            {
                pocetak = true;
                IzbaciKarteRazbrajanjem(spil,brojac,1);
                mapa.erase(it_mape);
                break;
            }
            
            brojac++;
        }
        
        if (pocetak == true)
        {
            it_mape = mapa.begin();
            continue;
        }
        
        
        
        it_mape++;
    }
    
}



void VratiPosljednjihNKarata (std::shared_ptr<Cvor> &spil, std::stack<std::pair<std::string,std::string>> &ubacivanje, int n)
{
    if (n < 0)
        throw std::range_error ("Broj n je besmislen!");

    if (n > ubacivanje.size())
        throw std::range_error ("Nedovoljno karata u redu!");

    std::stack<std::pair<std::string,std::string>> kopija = ubacivanje;

    while (!kopija.empty())
        {
            std::pair<std::string,std::string> element = kopija.top();

            if (element.first!="Herc" && element.first!="Karo" && element.first!="Pik" && element.first!="Tref")
                throw std::range_error ("Neispravne karte!");

            if (element.second!="2" && element.second!="3" && element.second!="4" && element.second!="5" && element.second!="6" &&
            element.second!="7" && element.second!="8" && element.second!="9" && element.second!="10" && element.second!="J" &&
            element.second!="Q" && element.second!="K" && element.second!="A")
                throw std::range_error ("Neispravne karte!");


            kopija.pop();
        }


    int broj_ubacenih{};

    while(true)
        {
            if (n == broj_ubacenih)
                break;

            std::pair<std::string,std::string> element = ubacivanje.top();
            int broj;
            if (element.first == "Pik")
                broj = 0;
            if (element.first == "Tref")
                broj = 1;
            if (element.first == "Herc")
                broj = 2;
            if (element.first == "Karo")
                broj = 3;


            int broj_karte{};
            if (element.second == "2")
                broj_karte = 0;
            if (element.second == "3")
                broj_karte = 1;
            if (element.second == "4")
                broj_karte = 2;
            if (element.second == "5")
                broj_karte = 3;
            if (element.second == "6")
                broj_karte = 4;
            if (element.second == "7")
                broj_karte = 5;
            if (element.second == "8")
                broj_karte = 6;
            if (element.second == "9")
                broj_karte = 7;
            if (element.second == "10")
                broj_karte = 8;
            if (element.second == "J")
                broj_karte = 9;
            if (element.second == "Q")
                broj_karte = 10;
            if (element.second == "K")
                broj_karte = 11;
            if (element.second == "A")
                broj_karte = 12;


            std::shared_ptr<Cvor> p = spil;

            if (spil == nullptr)                                                ///Ako je spil bio prazan.
                {
                            std::shared_ptr<Cvor> upis = std::make_shared<Cvor> ();
                            if (broj == 0)
                                upis->karta.boja = Boje::Pik;
                            if (broj == 1)
                                upis->karta.boja = Boje::Tref;
                            if (broj == 2)
                                upis->karta.boja = Boje::Herc;
                            if (broj == 3)
                                upis->karta.boja = Boje::Karo;

                            if (broj_karte == 0)
                                upis->karta.vrijednost = "2";
                            if (broj_karte == 1)
                                upis->karta.vrijednost = "3";
                            if (broj_karte == 2)
                                upis->karta.vrijednost = "4";
                            if (broj_karte == 3)
                                upis->karta.vrijednost = "5";
                            if (broj_karte == 4)
                                upis->karta.vrijednost = "6";
                            if (broj_karte == 5)
                                upis->karta.vrijednost = "7";
                            if (broj_karte == 6)
                                upis->karta.vrijednost = "8";
                            if (broj_karte == 7)
                                upis->karta.vrijednost = "9";
                            if (broj_karte == 8)
                                upis->karta.vrijednost = "10";
                            if (broj_karte == 9)
                                upis->karta.vrijednost = "J";
                            if (broj_karte == 10)
                                upis->karta.vrijednost = "Q";
                            if (broj_karte == 11)
                                upis->karta.vrijednost = "K";
                            if (broj_karte == 12)
                                upis->karta.vrijednost = "A";

                            spil = upis;
                            spil->sljedeci = spil;
                            ubacivanje.pop();
                            broj_ubacenih++;
                            continue;
                }

            if (broj == 0 && broj_karte == 0)                                   ///Testiranje upisa za prvi element.
                {
                    if ((int)spil->karta.boja == 0 && spil->karta.vrijednost == "2")
                        {
                            ubacivanje.pop();
                            broj_ubacenih++;
                            continue;
                        }

                        std::shared_ptr<Cvor> upis = std::make_shared<Cvor> ();
                        upis->karta.boja = Boje::Pik;
                        upis->karta.vrijednost = "2";
                        std::shared_ptr<Cvor> pomocni = spil;
                        pomocni = pomocni->sljedeci;
                        spil = upis;
                        spil->sljedeci = pomocni;

                        ubacivanje.pop();
                        broj_ubacenih++;
                        continue;

                }
            std::shared_ptr<Cvor> prethodni;
            prethodni = spil;
            p = p->sljedeci;

            while(true)                                                         ///Testiranje bilo koje karte.
                {
                    int a = (int)p->karta.boja;
                    int b;
                    if (p->karta.vrijednost == "2")
                        b = 0;
                    if (p->karta.vrijednost == "3")
                        b = 1;
                    if (p->karta.vrijednost == "4")
                        b = 2;
                    if (p->karta.vrijednost == "5")
                        b = 3;
                    if (p->karta.vrijednost == "6")
                        b = 4;
                    if (p->karta.vrijednost == "7")
                        b = 5;
                    if (p->karta.vrijednost == "8")
                        b = 6;
                    if (p->karta.vrijednost == "9")
                        b = 7;
                    if (p->karta.vrijednost == "10")
                        b = 8;
                    if (p->karta.vrijednost == "J")
                        b = 9;
                    if (p->karta.vrijednost == "Q")
                        b = 10;
                    if (p->karta.vrijednost == "K")
                        b = 11;
                    if (p->karta.vrijednost == "A")
                        b = 12;

                    if (broj == a && broj_karte == b)
                        {
                            broj_ubacenih++;
                            break;
                        }
                        
                    if (broj == a && broj_karte == 12)                          ///Testiranje upisa slova A na kraju svake vrste karata.
                    {
                            std::shared_ptr<Cvor> upis = std::make_shared<Cvor> ();
                            if (broj == 0)
                                upis->karta.boja = Boje::Pik;
                            if (broj == 1)
                                upis->karta.boja = Boje::Tref;
                            if (broj == 2)
                                upis->karta.boja = Boje::Herc;
                            if (broj == 3)
                                upis->karta.boja = Boje::Karo;
                                
                            upis->karta.vrijednost = "A";
                            
                            prethodni->sljedeci = upis;
                            upis->sljedeci = p;

                            broj_ubacenih++;
                            break;
                        
                    }

                    if (broj == a && b > broj_karte)
                        {
                            std::shared_ptr<Cvor> upis = std::make_shared<Cvor> ();
                            if (broj == 0)
                                upis->karta.boja = Boje::Pik;
                            if (broj == 1)
                                upis->karta.boja = Boje::Tref;
                            if (broj == 2)
                                upis->karta.boja = Boje::Herc;
                            if (broj == 3)
                                upis->karta.boja = Boje::Karo;

                            if (broj_karte == 0)
                                upis->karta.vrijednost = "2";
                            if (broj_karte == 1)
                                upis->karta.vrijednost = "3";
                            if (broj_karte == 2)
                                upis->karta.vrijednost = "4";
                            if (broj_karte == 3)
                                upis->karta.vrijednost = "5";
                            if (broj_karte == 4)
                                upis->karta.vrijednost = "6";
                            if (broj_karte == 5)
                                upis->karta.vrijednost = "7";
                            if (broj_karte == 6)
                                upis->karta.vrijednost = "8";
                            if (broj_karte == 7)
                                upis->karta.vrijednost = "9";
                            if (broj_karte == 8)
                                upis->karta.vrijednost = "10";
                            if (broj_karte == 9)
                                upis->karta.vrijednost = "J";
                            if (broj_karte == 10)
                                upis->karta.vrijednost = "Q";
                            if (broj_karte == 11)
                                upis->karta.vrijednost = "K";
                            if (broj_karte == 12)
                                upis->karta.vrijednost = "A";

                            prethodni->sljedeci = upis;
                            upis->sljedeci = p;

                            broj_ubacenih++;
                            break;
                        }

                    if (a>broj)
                        {
                            std::shared_ptr<Cvor> upis = std::make_shared<Cvor> ();
                            if (broj == 0)
                                upis->karta.boja = Boje::Pik;
                            if (broj == 1)
                                upis->karta.boja = Boje::Tref;
                            if (broj == 2)
                                upis->karta.boja = Boje::Herc;
                            if (broj == 3)
                                upis->karta.boja = Boje::Karo;

                            if (broj_karte == 0)
                                upis->karta.vrijednost = "2";
                            if (broj_karte == 1)
                                upis->karta.vrijednost = "3";
                            if (broj_karte == 2)
                                upis->karta.vrijednost = "4";
                            if (broj_karte == 3)
                                upis->karta.vrijednost = "5";
                            if (broj_karte == 4)
                                upis->karta.vrijednost = "6";
                            if (broj_karte == 5)
                                upis->karta.vrijednost = "7";
                            if (broj_karte == 6)
                                upis->karta.vrijednost = "8";
                            if (broj_karte == 7)
                                upis->karta.vrijednost = "9";
                            if (broj_karte == 8)
                                upis->karta.vrijednost = "10";
                            if (broj_karte == 9)
                                upis->karta.vrijednost = "J";
                            if (broj_karte == 10)
                                upis->karta.vrijednost = "Q";
                            if (broj_karte == 11)
                                upis->karta.vrijednost = "K";
                            if (broj_karte == 12)
                                upis->karta.vrijednost = "A";

                            prethodni->sljedeci = upis;
                            upis->sljedeci = p;

                            broj_ubacenih++;
                            break;
                        }


                    p = p->sljedeci;
                    prethodni = prethodni->sljedeci;
                }


            ubacivanje.pop();
        }


}









int main() {

    std::shared_ptr<Cvor> spil = nullptr;
    try
    {
        std::cout<<"Unesite korak razbrajanja: ";
        int prvi;
        std::cin>>prvi;

        std::cout<<"Unesite broj karata koje zelite izbaciti: ";
        int drugi;
        std::cin>>std::ws>>drugi;

        spil = KreirajSpil();

        std::stack<std::pair<std::string, std::string>> izbacene_karte = IzbaciKarteRazbrajanjem(spil,prvi,drugi);

        int ostatak_karata = 52-PrebrojiKarte(spil);

        std::cout<<"U spilu trenutno ima "<<ostatak_karata<<" karata, i to:";
        std::shared_ptr<Cvor> ispis = spil;

        std::cout<<std::endl<<"Pik: ";
        while(true)
            {
                if (ispis->karta.boja == Boje::Pik)
                    {
                        if (ispis->karta.vrijednost == "A")
                            std::cout<<ispis->karta.vrijednost;
                        else
                            std::cout<<ispis->karta.vrijednost<<" ";
                    }
                else
                    break;

                ispis = ispis->sljedeci;

            }

        std::cout<<std::endl<<"Tref: ";
        while(true)
            {
                if (ispis->karta.boja == Boje::Tref)
                    {
                        if (ispis->karta.vrijednost == "A")
                            std::cout<<ispis->karta.vrijednost;
                        else
                            std::cout<<ispis->karta.vrijednost<<" ";
                    }
                else
                    break;

                ispis = ispis->sljedeci;

            }

        std::cout<<std::endl<<"Herc: ";
        while(true)
            {
                if (ispis->karta.boja == Boje::Herc)
                    {
                        if (ispis->karta.vrijednost == "A")
                            std::cout<<ispis->karta.vrijednost;
                        else
                            std::cout<<ispis->karta.vrijednost<<" ";
                    }
                else
                    break;

                ispis = ispis->sljedeci;

            }

        std::cout<<std::endl<<"Karo: ";
        while(true)
            {
                if (ispis->karta.boja == Boje::Karo)
                    {
                        if (ispis->karta.vrijednost == "A")
                            std::cout<<ispis->karta.vrijednost;
                        else
                            std::cout<<ispis->karta.vrijednost<<" ";
                    }
                else
                    break;

                ispis = ispis->sljedeci;

            }

        std::cout<<std::endl<<"Unesite broj karata koje zelite vratiti u spil: ";
        int n;
        std::cin>>std::ws>>n;

        VratiPosljednjihNKarata(spil,izbacene_karte,n);

        ostatak_karata = 52-PrebrojiKarte(spil);
        std::cout<<"U spilu trenutno ima "<<ostatak_karata<<" karata, i to:";
        
        std::cout<<std::endl<<"Pik: ";
        while(true)
            {
                if (ispis->karta.boja == Boje::Pik)
                    {
                        if (ispis->karta.vrijednost == "A")
                            std::cout<<ispis->karta.vrijednost;
                        else
                            std::cout<<ispis->karta.vrijednost<<" ";
                    }
                else
                    break;

                ispis = ispis->sljedeci;

            }

        std::cout<<std::endl<<"Tref: ";
        while(true)
            {
                if (ispis->karta.boja == Boje::Tref)
                    {
                        if (ispis->karta.vrijednost == "A")
                            std::cout<<ispis->karta.vrijednost;
                        else
                            std::cout<<ispis->karta.vrijednost<<" ";
                    }
                else
                    break;

                ispis = ispis->sljedeci;

            }

        std::cout<<std::endl<<"Herc: ";
        while(true)
            {
                if (ispis->karta.boja == Boje::Herc)
                    {
                        if (ispis->karta.vrijednost == "A")
                            std::cout<<ispis->karta.vrijednost;
                        else
                            std::cout<<ispis->karta.vrijednost<<" ";
                    }
                else
                    break;

                ispis = ispis->sljedeci;

            }

        std::cout<<std::endl<<"Karo: ";
        while(true)
            {
                if (ispis->karta.boja == Boje::Karo)
                    {
                        if (ispis->karta.vrijednost == "A")
                            std::cout<<ispis->karta.vrijednost;
                        else
                            std::cout<<ispis->karta.vrijednost<<" ";
                    }
                else
                    break;

                ispis = ispis->sljedeci;

            }

    }
    catch (std::logic_error g1)
    {
        std::cout<<"Izuzetak: "<<g1.what();
    }
    catch (std::range_error g2)
    {
        std::cout<<"Izuzetak: "<<g2.what();
    }
    
    if (spil == nullptr)
            return 0;

        std::shared_ptr<Cvor> brisanje = spil;
        brisanje = brisanje->sljedeci;
        spil->sljedeci = nullptr;
        spil = nullptr;

        while(true)
            {
                if (brisanje == nullptr)
                    break;
                std::shared_ptr<Cvor> b2 = brisanje;
                brisanje = brisanje->sljedeci;
                b2 = nullptr;
            }



    return 0;
}