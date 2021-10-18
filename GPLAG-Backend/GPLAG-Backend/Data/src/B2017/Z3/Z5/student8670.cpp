/B2017/2018: Zadaća 3, Zadatak 5
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <stack> 
enum class Boje{Pik,Tref,Herc,Karo};
struct Karta
{
    Boje boja;
    std::string vrijednost;
};
struct Cvor
{
    Karta karta;
    Cvor *sljedeci;
};
template <typename T > std::string PretvoriUString (T x)
{
    std::ostringstream s;
    s << x;
    return s.str();
}
Cvor* KreirajSpil()
{
    Cvor *pocetak(nullptr),*prethodni;
    for(int i=0;i<4;i++)
    {
        for(int j=2;j<=14;j++)
        {
            Cvor *novi(new Cvor);
            Karta karta;
            if(j<=10)
                karta.vrijednost=PretvoriUString(j);
            else
            {
                if(j==11)
                    karta.vrijednost="J";
                else if(j==12)
                    karta.vrijednost="Q";
                else if(j==13)
                    karta.vrijednost="K";
                else if(j==14)
                    karta.vrijednost="A";
            }
            if(i==0)
                karta.boja=Boje::Pik;
            else if(i==1)
                karta.boja=Boje::Tref;
            else if(i==2)
                karta.boja=Boje::Herc;
            else if(i==3)
                karta.boja=Boje::Karo;
            novi->karta=karta;
            novi->sljedeci=nullptr;
            if(!pocetak) pocetak=novi;
            else prethodni->sljedeci=novi;
            prethodni=novi;
        }
    }
    prethodni->sljedeci=pocetak;
    return pocetak;
}

bool IspravnaListaSpila(Cvor*& listaSpila)
{
    int brojac=0;
    for(Cvor* p=listaSpila->sljedeci;p!=listaSpila;p=p->sljedeci)
    {
        brojac++;
    }
    if(brojac+1>52) return false;
    for(Cvor* i=listaSpila->sljedeci;i!=listaSpila;i=i->sljedeci)
    {
        if((*i).karta.boja != Boje::Pik && (*i).karta.boja != Boje::Tref && (*i).karta.boja != Boje::Herc  && (*i).karta.boja != Boje::Karo) {
            return false;
        }
        if((*i).karta.vrijednost != "2" && (*i).karta.vrijednost != "3" && (*i).karta.vrijednost != "4" && 
        (*i).karta.vrijednost != "5" && (*i).karta.vrijednost != "6" && (*i).karta.vrijednost != "7" && 
        (*i).karta.vrijednost != "8" && (*i).karta.vrijednost != "9" && (*i).karta.vrijednost != "10" && 
        (*i).karta.vrijednost != "J" && (*i).karta.vrijednost != "Q" && (*i).karta.vrijednost != "K" && (*i).karta.vrijednost != "A") {
            return false;
        }
    }
    return true;
}

void IzbaciKarte(Cvor *&listaSpila, std::multimap < Boje, std::string > &multiMapa)
{
    if(!IspravnaListaSpila(listaSpila)) throw std::logic_error ("Neispravna lista!");
ponovo:
    for(auto it=multiMapa.begin();it!=multiMapa.end();it++)
    {
        if(listaSpila!=nullptr)
        {
            Cvor* prethodni=nullptr;
            for(Cvor* p=listaSpila->sljedeci;p!=listaSpila;p=p->sljedeci)
            {
                if(it->first==(*p->sljedeci).karta.boja && it->second==(*p->sljedeci).karta.vrijednost)
                {
                    prethodni=p;
                }
                if(it->first==(*p).karta.boja && it->second==(*p).karta.vrijednost)
                {
                    if(prethodni!=nullptr)
                        prethodni->sljedeci=p->sljedeci;
                    else
                        listaSpila->sljedeci=p->sljedeci;
                    if(p==p->sljedeci) listaSpila=nullptr;
                    delete p;
                    multiMapa.erase(it);
                    goto ponovo;
                }
            }
            if(it->first==(*listaSpila).karta.boja && it->second==(*listaSpila).karta.vrijednost)
            {
                if(prethodni!=nullptr)
                    prethodni->sljedeci=listaSpila->sljedeci;
                delete listaSpila;
                if(prethodni!=nullptr)
                    listaSpila=prethodni->sljedeci;
                else listaSpila=nullptr;
                multiMapa.erase(it);
                goto ponovo;
            }
            
        }
    }
}
std::stack< std::pair < std::string, std::string >> IzbaciKarteRazbrajanjem(Cvor*& listaSpila, const short int &r, int &b)
{
    if (!IspravnaListaSpila(listaSpila)) throw std::logic_error ("Neispravna lista!");
    if (r < 1 || r > 52) throw std::logic_error ("Neispravni elementi za izbacivanje!");
    if (b < 1) throw std::logic_error ("Neispravni elementi za izbacivanje!");
    std::stack < std::pair < std::string, std::string >> stek;
    int izbaceno(0), element(0);
    Cvor* prethodni=nullptr;
    for(Cvor* i = listaSpila; ; i=i->sljedeci) 
    {
        element++;
        if(element+1==r) prethodni=i;
        if(element == r) 
        {
            if((int)(*i).karta.boja == 0)
                stek.push(std::make_pair("Pik", (*i).karta.vrijednost));
            else if((int)(*i).karta.boja == 1)
                stek.push(std::make_pair("Tref", (*i).karta.vrijednost));
            else if((int)(*i).karta.boja == 2)
                stek.push(std::make_pair("Herc", (*i).karta.vrijednost));
            else  if((int)(*i).karta.boja == 3)
                stek.push(std::make_pair("Karo", (*i).karta.vrijednost));
            if(prethodni==nullptr)
            {
                for(Cvor* p=listaSpila->sljedeci;p!=listaSpila;p=p->sljedeci)
                    prethodni=p;
                listaSpila=listaSpila->sljedeci;
            }
            if(listaSpila->sljedeci==listaSpila) listaSpila=nullptr;
            else prethodni->sljedeci=i->sljedeci;
            delete i;
            i=prethodni;
            izbaceno++;
            prethodni=nullptr;
            if(izbaceno == b || listaSpila == nullptr) break;
            element = 0;
        }
    }
    return stek;
}
void VratiPosljednjihNKarata(Cvor*& listaSpila,std::stack < std::pair < std::string, std::string >>& red, int n)
{
    if (n < 0) throw std::domain_error ("Broj n je besmislen!");
    if (n > red.size()) throw std::range_error ("Nedovoljno karata u steku!");
    for(int k = 0; k < red.size(); k++) {
        std::string a1, a2;
        a1 = red.top().first;
        a2 = red.top().second;
        if(a1 != "Pik" && a1 != "Tref" && a1 != "Herc" && a1 != "Karo") throw std::logic_error ("Neispravne karte!");
        if(a2 != "2" && a2 != "3" && a2 != "4" && a2 != "5" && a2 != "6" && a2 != "7" && a2 != "8" && a2 != "9" && a2 != "10"
                && a2 != "J" && a2 != "Q" && a2 != "K" && a2 != "A") throw std::logic_error ("Neispravne karte!");
        red.push(red.top());
        red.pop();
    }
    if (!IspravnaListaSpila(listaSpila)) throw std::logic_error ("Neispravna lista!");
}

void UnistiSpil(Cvor*& listaSpila)
{
    if(listaSpila==nullptr) return;
    for(Cvor* p=listaSpila->sljedeci;p!=listaSpila;)
    {
        Cvor* pom=p->sljedeci;
        delete p;
        p=pom;
    }
    delete listaSpila;
    
}
int main ()
{
	Cvor* listaSpila = KreirajSpil();
    int korakRazbrajanja;
    std::cout << "Unesite korak razbrajanja: ";
    std::cin >> korakRazbrajanja;
    int brojIzbacenihKarata;
    std::cout << "Unesite broj karata koje zelite izbaciti: ";
    std::cin >> brojIzbacenihKarata;
    std::stack < std::pair < std::string, std::string >> redIzbacenih;
    try 
    {
        redIzbacenih = IzbaciKarteRazbrajanjem(listaSpila, korakRazbrajanja, brojIzbacenihKarata);
    }
    catch(std::logic_error c)
    {
        std::cout <<"Izuzetak: "<< c.what();
        UnistiSpil(listaSpila);
        return 0;
    }
    int brojKarata=0;
    if(listaSpila!=nullptr)
    {
        for(Cvor* i=listaSpila->sljedeci;i!=listaSpila;i=i->sljedeci) brojKarata++;
        std::cout << "U spilu trenutno ima " << brojKarata+1 << " karata, i to: " << std::endl;
    }
    else
    {
        std::cout << "U spilu trenutno ima " << brojKarata << " karata, i to: " << std::endl;
        std::cout << "Pik:\nTref:\nHerc:\nKaro:";
    }
    if(listaSpila!=nullptr)
    {
        if(listaSpila==listaSpila->sljedeci)
        {
            if((int)(*listaSpila).karta.boja==0)
            {
                std::cout<<"Pik: "<<(*listaSpila).karta.vrijednost;
            }
            else if((int)(*listaSpila).karta.boja==1)
            {
                std::cout<<"Pik:\nTref: "<<(*listaSpila).karta.vrijednost;
            }
            else if((int)(*listaSpila).karta.boja==2)
            {
                std::cout<<"Pik:\nTref:\nHerc: "<<(*listaSpila).karta.vrijednost;
            }
            else if((int)(*listaSpila).karta.boja==3)
            {
                std::cout<<"Pik:\nTref:\nHerc:\nKaro: "<<(*listaSpila).karta.vrijednost;
            }
        }
        for (Cvor* x = listaSpila; x->sljedeci != listaSpila; x=x->sljedeci)
        {
            std::cout << "Pik: ";
            if((*x).karta.boja == Boje::Pik)
            {
                
                while ((*x).karta.boja == Boje::Pik && x->sljedeci != listaSpila)
                {
                    std::cout << (*x).karta.vrijednost << " ";
                    
                    x=x->sljedeci;
                }
                
            }
            std::cout << "\nTref: ";
            if((*x).karta.boja == Boje::Tref)
            {
                
                while ((*x).karta.boja == Boje::Tref && x->sljedeci != listaSpila)
                {
                    std::cout << (*x).karta.vrijednost << " ";
                    
                    x=x->sljedeci;
                }
               
            }
            std::cout << "\nHerc: ";
            if((*x).karta.boja == Boje::Herc)
            {
               
                while ((*x).karta.boja == Boje::Herc && x->sljedeci != listaSpila)
                {
                    std::cout << (*x).karta.vrijednost << " ";
                    
                    x=x->sljedeci;
                }
                
            }
            std::cout << "\nKaro: ";
            if((*x).karta.boja == Boje::Karo)
            {
                
                while ((*x).karta.boja == Boje::Karo && x->sljedeci != listaSpila)
                {
                    std::cout << (*x).karta.vrijednost << " ";
                    
                    x=x->sljedeci;
                }
                if(x->sljedeci==listaSpila && (*x).karta.boja == Boje::Karo) 
                    std::cout<<(*x).karta.vrijednost << "\n";
                break;
            }
        }
        std::cout << "\nUnesite broj karata koje zelite vratiti u spil: ";
        int n;
        std::cin >> n;
        try
        {
            VratiPosljednjihNKarata(listaSpila, redIzbacenih, n);
        }
        catch (std::exception& c)
        {
            std::cout<<"Izuzetak: " << c.what();
            UnistiSpil(listaSpila);
            return 0;
        }
        
        int brojKarata=0;
        if(listaSpila!=nullptr)
        {
            for(Cvor* i=listaSpila->sljedeci;i!=listaSpila;i=i->sljedeci) brojKarata++;
            std::cout << "U spilu trenutno ima " << brojKarata+1 << " karata, i to: " << std::endl;
        }
        else
        {
            std::cout << "U spilu trenutno ima " << brojKarata << " karata, i to: " << std::endl;
            std::cout << "Pik:\nTref:\nHerc:\nKaro:";
        }
        if(listaSpila==listaSpila->sljedeci)
        {
            if((int)(*listaSpila).karta.boja==0)
            {
                std::cout<<"Pik: "<<(*listaSpila).karta.vrijednost;
            }
            else if((int)(*listaSpila).karta.boja==1)
            {
                std::cout<<"Pik:\nTref: "<<(*listaSpila).karta.vrijednost;
            }
            else if((int)(*listaSpila).karta.boja==2)
            {
                std::cout<<"Pik:\nTref:\nHerc: "<<(*listaSpila).karta.vrijednost;
            }
            else if((int)(*listaSpila).karta.boja==3)
            {
                std::cout<<"Pik:\nTref:\nHerc:\nKaro: "<<(*listaSpila).karta.vrijednost;
            }
        }
        for (Cvor* x = listaSpila; x->sljedeci != listaSpila; x=x->sljedeci)
        {
            std::cout << "Pik: ";
            if((*x).karta.boja == Boje::Pik)
            {
                
                while ((*x).karta.boja == Boje::Pik && x->sljedeci != listaSpila)
                {
                    std::cout << (*x).karta.vrijednost << " ";
                    
                    x=x->sljedeci;
                }
                
            }
            std::cout << "\nTref: ";
            if((*x).karta.boja == Boje::Tref)
            {
                
                while ((*x).karta.boja == Boje::Tref && x->sljedeci != listaSpila)
                {
                    std::cout << (*x).karta.vrijednost << " ";
                    
                    x=x->sljedeci;
                }
               
            }
            std::cout << "\nHerc: ";
            if((*x).karta.boja == Boje::Herc)
            {
               
                while ((*x).karta.boja == Boje::Herc && x->sljedeci != listaSpila)
                {
                    std::cout << (*x).karta.vrijednost << " ";
                    
                    x=x->sljedeci;
                }
                
            }
            std::cout << "\nKaro: ";
            if((*x).karta.boja == Boje::Karo)
            {
                
                while ((*x).karta.boja == Boje::Karo && x->sljedeci != listaSpila)
                {
                    std::cout << (*x).karta.vrijednost << " ";
                    
                    x=x->sljedeci;
                }
                if(x->sljedeci==listaSpila && (*x).karta.boja == Boje::Karo) 
                    std::cout<<(*x).karta.vrijednost << "\n";
                break;
            }
        }
        UnistiSpil(listaSpila);
    }
    
        
    return 0;
}
