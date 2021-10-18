/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <stdexcept>
#include <list>
#include <set>
#include <queue>
#include <utility>
#include <map>

enum class Boje
{
    Pik, Tref, Herc, Karo
};


int PrebrojiKarte (const std::list<std::set<Boje>> &spil)
{
    int broj_setova {};
    for (auto it = spil.begin(); it != spil.end(); it++)
        broj_setova++;

    if (broj_setova!=13)
        throw std::logic_error ("Neispravna lista!");



    int brojac {};

    for (auto it = spil.begin(); it!=spil.end(); it++)
    {
        if (it->count(Boje::Herc) == 1)
            brojac++;

        if (it->count(Boje::Karo) == 1)
            brojac++;

        if (it->count(Boje::Pik) == 1)
            brojac++;

        if (it->count(Boje::Tref) == 1)
            brojac++;
    }


    return 52-brojac;

}


void Ispis_svih_karata (const std::list<std::set<Boje>> &spil)
{
    std::cout<<std::endl<<"Pik: ";
        int brojac {};
        for (auto it = spil.begin(); it!=spil.end(); it++)
        {
            if (it->count(Boje::Pik) == 1)
            {
                if (brojac == 0)
                    std::cout<<"2 ";
                if (brojac == 1)
                    std::cout<<"3 ";
                if (brojac == 2)
                    std::cout<<"4 ";
                if (brojac == 3)
                    std::cout<<"5 ";
                if (brojac == 4)
                    std::cout<<"6 ";
                if (brojac == 5)
                    std::cout<<"7 ";
                if (brojac == 6)
                    std::cout<<"8 ";
                if (brojac == 7)
                    std::cout<<"9 ";
                if (brojac == 8)
                    std::cout<<"10 ";
                if (brojac == 9)
                    std::cout<<"J ";
                if (brojac == 10)
                    std::cout<<"Q ";
                if (brojac == 11)
                    std::cout<<"K ";
                if (brojac == 12)
                    std::cout<<"A ";
            }

            brojac++;
        }
        
        std::cout<<std::endl<<"Tref: ";
        brojac = 0;
        for (auto it = spil.begin(); it!=spil.end(); it++)
        {
            if (it->count(Boje::Tref) == 1)
            {
                if (brojac == 0)
                    std::cout<<"2 ";
                if (brojac == 1)
                    std::cout<<"3 ";
                if (brojac == 2)
                    std::cout<<"4 ";
                if (brojac == 3)
                    std::cout<<"5 ";
                if (brojac == 4)
                    std::cout<<"6 ";
                if (brojac == 5)
                    std::cout<<"7 ";
                if (brojac == 6)
                    std::cout<<"8 ";
                if (brojac == 7)
                    std::cout<<"9 ";
                if (brojac == 8)
                    std::cout<<"10 ";
                if (brojac == 9)
                    std::cout<<"J ";
                if (brojac == 10)
                    std::cout<<"Q ";
                if (brojac == 11)
                    std::cout<<"K ";
                if (brojac == 12)
                    std::cout<<"A ";
            }

            brojac++;
        }

        
        std::cout<<std::endl<<"Herc: ";

        brojac = 0;
        for (auto it = spil.begin(); it!=spil.end(); it++)
        {
            if (it->count(Boje::Herc) == 1)
            {
                if (brojac == 0)
                    std::cout<<"2 ";
                if (brojac == 1)
                    std::cout<<"3 ";
                if (brojac == 2)
                    std::cout<<"4 ";
                if (brojac == 3)
                    std::cout<<"5 ";
                if (brojac == 4)
                    std::cout<<"6 ";
                if (brojac == 5)
                    std::cout<<"7 ";
                if (brojac == 6)
                    std::cout<<"8 ";
                if (brojac == 7)
                    std::cout<<"9 ";
                if (brojac == 8)
                    std::cout<<"10 ";
                if (brojac == 9)
                    std::cout<<"J ";
                if (brojac == 10)
                    std::cout<<"Q ";
                if (brojac == 11)
                    std::cout<<"K ";
                if (brojac == 12)
                    std::cout<<"A ";
            }

            brojac++;
        }

        std::cout<<std::endl<<"Karo: ";
        brojac = 0;
        for (auto it = spil.begin(); it!=spil.end(); it++)
        {
            if (it->count(Boje::Karo) == 1)
            {
                if (brojac == 0)
                    std::cout<<"2 ";
                if (brojac == 1)
                    std::cout<<"3 ";
                if (brojac == 2)
                    std::cout<<"4 ";
                if (brojac == 3)
                    std::cout<<"5 ";
                if (brojac == 4)
                    std::cout<<"6 ";
                if (brojac == 5)
                    std::cout<<"7 ";
                if (brojac == 6)
                    std::cout<<"8 ";
                if (brojac == 7)
                    std::cout<<"9 ";
                if (brojac == 8)
                    std::cout<<"10 ";
                if (brojac == 9)
                    std::cout<<"J ";
                if (brojac == 10)
                    std::cout<<"Q ";
                if (brojac == 11)
                    std::cout<<"K ";
                if (brojac == 12)
                    std::cout<<"A ";
            }

            brojac++;
        }

        
}


std::list<std::set<Boje>> KreirajSpil ()
{
    std::set<Boje> dva {Boje::Pik, Boje::Tref, Boje::Herc, Boje::Karo};         ///Kreiranje 13 vrsti karata sa svim bojama.
    std::set<Boje> tri {Boje::Pik, Boje::Tref, Boje::Herc, Boje::Karo}; 
    std::set<Boje> cetiri {Boje::Pik, Boje::Tref, Boje::Herc, Boje::Karo}; 
    std::set<Boje> pet {Boje::Pik, Boje::Tref, Boje::Herc, Boje::Karo}; 
    std::set<Boje> sest {Boje::Pik, Boje::Tref, Boje::Herc, Boje::Karo}; 
    std::set<Boje> sedam {Boje::Pik, Boje::Tref, Boje::Herc, Boje::Karo}; 
    std::set<Boje> osam {Boje::Pik, Boje::Tref, Boje::Herc, Boje::Karo}; 
    std::set<Boje> devet {Boje::Pik, Boje::Tref, Boje::Herc, Boje::Karo}; 
    std::set<Boje> deset {Boje::Pik, Boje::Tref, Boje::Herc, Boje::Karo}; 
    std::set<Boje> zandar {Boje::Pik, Boje::Tref, Boje::Herc, Boje::Karo}; 
    std::set<Boje> dama {Boje::Pik, Boje::Tref, Boje::Herc, Boje::Karo}; 
    std::set<Boje> kralj {Boje::Pik, Boje::Tref, Boje::Herc, Boje::Karo}; 
    std::set<Boje> as {Boje::Pik, Boje::Tref, Boje::Herc, Boje::Karo};


    std::list<std::set<Boje>> l;                                                ///Kreiranje i popunjavanje liste sa elementima.
    l.push_back(dva);
    l.push_back(tri);
    l.push_back(cetiri);
    l.push_back(pet);
    l.push_back(sest);
    l.push_back(sedam);
    l.push_back(osam);
    l.push_back(devet);
    l.push_back(deset);
    l.push_back(zandar);
    l.push_back(dama);
    l.push_back(kralj);
    l.push_back(as);



    return l;
}

void IzbaciKarte (std::list<std::set<Boje>> &spil, std::multimap<Boje, std::string> &mapa)
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
        
        
        int brojac = 0;
        bool pocetak = false;
        for (auto it = spil.begin(); it!=spil.end(); it++)
        {
            if (brojac == broj_karte)
            {
                if (it->count(boja) == 1)
                {
                    it->erase(boja);
                    mapa.erase(it_mape);
                    pocetak = true;
                    break;
                }
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


std::queue<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem (std::list<std::set<Boje>> &spil, const short int &x, const int &b)
{
    if (x<1 || x>52)
        throw std::logic_error ("Neispravni elementi za izbacivanje!");
    if (b < 1)
        throw std::logic_error ("Neispravni elementi za izbacivanje!");

    int broj_setova {};
    for (auto it = spil.begin(); it != spil.end(); it++)
        broj_setova++;

    if (broj_setova!=13)
        throw std::logic_error ("Neispravna lista!");


    int r {};
    bool upisan = false;
    std::queue<std::pair<std::string, std::string>> rezultat;

    int n {};

    for (auto it = spil.begin(); it!=spil.end(); it++)
    {
        if (it->count(Boje::Herc) == 1)
            n++;

        if (it->count(Boje::Karo) == 1)
            n++;

        if (it->count(Boje::Pik) == 1)
            n++;

        if (it->count(Boje::Tref) == 1)
            n++;
    }


    int i {};
    int brojac {};
    int tacan_element {};
    int trenutno_izbaceni {};
    r+=x;
    bool izlaz {false};
    while(true)
    {
        if (n == trenutno_izbaceni)
            break;

        if (r>52)
        {
            r-=52;
            brojac-=52;
        }


        

        tacan_element = 0;
        for (auto it = spil.begin(); it!=spil.end(); it++)                            ///Prolazak za pik.
        {
            brojac++;
            tacan_element++;
            if (brojac<r)                                   ///Ako neki element je izbacen, preskace se brojanje.
            {
                if (it->count(Boje::Pik) == 0)
                    r++;
            }

            if (brojac == r && it->count(Boje::Pik) == 0)
            {
                r++;
                brojac++;
                tacan_element++;
                it++;
                if (it == spil.end())
                    brojac--;
            }

            if (brojac == r)
            {
                if (it->count(Boje::Pik) == 1)
                {
                    it->erase(Boje::Pik);
                    upisan = true;

                    std::pair<std::string, std::string> upis;
                    std::string s;

                    if (tacan_element == 10)
                        s = "J";
                    else if (tacan_element == 11)
                        s = "Q";
                    else if (tacan_element == 12)
                        s = "K";
                    else if (tacan_element == 13)
                        s = "A";
                    else
                    {
                        if (tacan_element == 9)
                            s = "10";
                        else
                            s = char(tacan_element+1+48);
                    }

                    upis = std::make_pair(std::string("Pik"),s);

                    rezultat.push(upis);
                    trenutno_izbaceni++;
                    i++;
                    r+=x;
                    if (i == b)
                        izlaz = true;
                }
            }

            if (izlaz == true)
                break;
        }

        if (izlaz == true)
            break;

        if (r>52)
        {
            r-=52;
            brojac-=52;
        }

        tacan_element = 0;
        for (auto it = spil.begin(); it!=spil.end(); it++)                            ///Prolazak za tref.
        {
            brojac++;
            tacan_element++;
            if (brojac<r)                                   ///Ako neki element je izbacen, preskace se brojanje.
            {
                if (it->count(Boje::Tref) == 0)
                    r++;
            }

            if (brojac == r && it->count(Boje::Tref) == 0)
            {
                r++;
                brojac++;
                tacan_element++;
                it++;
                if (it == spil.end())
                    brojac--;
            }

            if (brojac == r)
            {
                if (it->count(Boje::Tref) == 1)
                {
                    it->erase(Boje::Tref);
                    upisan = true;

                    std::pair<std::string, std::string> upis;
                    std::string s;

                    if (tacan_element == 10)
                        s = "J";
                    else if (tacan_element == 11)
                        s = "Q";
                    else if (tacan_element == 12)
                        s = "K";
                    else if (tacan_element == 13)
                        s = "A";
                    else
                    {
                        if (tacan_element == 9)
                            s = "10";
                        else
                            s = char(tacan_element+1+48);
                    }

                    upis = std::make_pair(std::string("Tref"),s);

                    rezultat.push(upis);
                    trenutno_izbaceni++;
                    i++;
                    r+=x;
                    if (i == b)
                        izlaz = true;
                }
            }

            if (izlaz == true)
                break;

        }

        if (izlaz == true)
            break;

        if (r>52)
        {
            r-=52;
            brojac-=52;
        }

    tacan_element = 0;
        for (auto it = spil.begin(); it!=spil.end(); it++)                            ///Prolazak za herc.
        {
            brojac++;
            tacan_element++;
            if (brojac<r)                                   ///Ako neki element je izbacen, preskace se brojanje.
            {
                if (it->count(Boje::Herc) == 0)
                    r++;
            }

            if (brojac == r && it->count(Boje::Herc) == 0)
            {
                r++;
                brojac++;
                tacan_element++;
                it++;
                if (it == spil.end())
                    brojac--;
            }

            if (brojac == r)
            {
                if (it->count(Boje::Herc) == 1)
                {
                    it->erase(Boje::Herc);

                    std::pair<std::string, std::string> upis;
                    std::string s;

                    if (tacan_element == 10)
                        s = "J";
                    else if (tacan_element == 11)
                        s = "Q";
                    else if (tacan_element == 12)
                        s = "K";
                    else if (tacan_element == 13)
                        s = "A";
                    else
                    {
                        if (tacan_element == 9)
                            s = "10";
                        else
                            s = char(tacan_element+1+48);
                    }

                    upis = std::make_pair(std::string("Herc"),s);

                    rezultat.push(upis);

                    trenutno_izbaceni++;
                    i++;
                    r+=x;
                    if (i == b)
                        izlaz = true;
                }
            }

            if (izlaz == true)
                break;

        }

        if (izlaz == true)
            break;

        if (r>52)
        {
            r-=52;
            brojac-=52;
        }

        tacan_element = 0;
        for (auto it = spil.begin(); it!=spil.end(); it++)                            ///Prolazak za karo.
        {
            brojac++;
            tacan_element++;
            if (brojac<r)                                   ///Ako neki element je izbacen, preskace se brojanje.
            {
                if (it->count(Boje::Karo) == 0)
                    r++;
            }

            if (brojac == r && it->count(Boje::Karo) == 0)
            {
                r++;
                brojac++;
                tacan_element++;
                it++;
                if (it == spil.end())
                    brojac--;
            }

            if (brojac == r)
            {
                if (it->count(Boje::Karo) == 1)
                {
                    it->erase(Boje::Karo);
                    upisan = true;

                    std::pair<std::string, std::string> upis;
                    std::string s;

                    if (tacan_element == 10)
                        s = "J";
                    else if (tacan_element == 11)
                        s = "Q";
                    else if (tacan_element == 12)
                        s = "K";
                    else if (tacan_element == 13)
                        s = "A";
                    else
                    {
                        if (tacan_element == 9)
                            s = "10";
                        else
                            s = char(tacan_element+1+48);
                    }

                    upis = std::make_pair(std::string("Karo"),s);

                    rezultat.push(upis);
                    trenutno_izbaceni++;
                    i++;
                    r+=x;
                    if (i == b)
                        izlaz = true;
                }
            }

            if (izlaz == true)
                break;

        }

        if (izlaz == true)
            break;

        if (r>52)
        {
            r-=52;
            brojac-=52;
        }
    }


    return rezultat;

}

void VratiPosljednjihNKarata (std::list<std::set<Boje>> &spil, std::queue<std::pair<std::string, std::string>> &izbacene_karte, int n)
{
    if (n < 0)
        throw std::range_error ("Broj n je besmislen!");
    
    if (n > izbacene_karte.size())
        throw std::range_error ("Nedovoljno karata u redu!");

    std::queue<std::pair<std::string, std::string>> kopija = izbacene_karte;

    while(!kopija.empty())
    {
        std::pair<std::string, std::string> test = kopija.front();

        if (test.first!="Herc" && test.first!="Karo" && test.first!="Pik" && test.first!="Tref")
            throw std::logic_error ("Neispravne karte!");

        if (test.second!="2" && test.second!="3" && test.second!="4" && test.second!="5" && test.second!="6" && test.second!="7" &&
                test.second!="8" && test.second!="9" && test.second!="10" && test.second!="J" && test.second!="Q" && test.second!="K" &&
                test.second!="A")
            throw std::logic_error ("Neispravne karte!");


        kopija.pop();
    }

    int broj_setova {};
    for (auto it = spil.begin(); it != spil.end(); it++)
        broj_setova++;

    if (broj_setova!=13)
        throw std::logic_error ("Neispravna lista!");


    int izbaceni {};

    while(true)
    {
        if (izbaceni == n)
            break;

        std::pair<std::string, std::string> element = izbacene_karte.front();

        int broj_stacka {};

        int broj_karte;

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

        for (auto it = spil.begin(); it != spil.end(); it++)
        {

            if (broj_stacka == broj_karte)
            {
                if (element.first == "Pik")
                {
                    if (it->count(Boje::Pik) == 0)
                        it->insert(Boje::Pik);
                }
                if (element.first == "Tref")
                {
                    if (it->count(Boje::Tref) == 0)
                        it->insert(Boje::Tref);
                }
                if (element.first == "Herc")
                {
                    if (it->count(Boje::Herc) == 0)
                        it->insert(Boje::Herc);
                }
                if (element.first == "Karo")
                {
                    if (it->count(Boje::Karo) == 0)
                        it->insert(Boje::Karo);
                }
                

                izbaceni++;
            }

            broj_stacka++;
        }




        izbacene_karte.pop();

    }

}






int main()
{


    try
    {
        std::cout<<"Unesite korak razbrajanja: ";
        short int prvi;
        std::cin>>prvi;

        std::cout<<"Unesite broj karata koje zelite izbaciti: ";
        int drugi;
        std::cin>>std::ws>>drugi;

        std::list<std::set<Boje>> spil = KreirajSpil();


        std::queue<std::pair<std::string, std::string>> izbacene_karte = IzbaciKarteRazbrajanjem(spil,prvi,drugi);

        int ostatak_karata = 52-PrebrojiKarte(spil);
        
        std::cout<<"U spilu trenutno ima "<<ostatak_karata<<" karata, i to:";
        Ispis_svih_karata(spil);

        std::cout<<std::endl<<"Unesite broj karata koje zelite vratiti u spil: ";
        int n;
        std::cin>>std::ws>>n;

        VratiPosljednjihNKarata(spil,izbacene_karte,n);
        
        ostatak_karata = 52-PrebrojiKarte(spil);
        std::cout<<"U spilu trenutno ima "<<ostatak_karata<<" karata, i to:";
        Ispis_svih_karata(spil);
    }
    catch (std::logic_error greska)
    {
        std::cout<<"Izuzetak: "<<greska.what();
    }
    catch(std::range_error g2)
    {
        std::cout<<"Izuzetak: "<<g2.what();
    }




    return 0;
}

