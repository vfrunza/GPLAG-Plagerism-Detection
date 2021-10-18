/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <map>
#include <list>
#include <sstream>
#include <utility>
#include <iterator>
#include <queue>
#include <string>
#include <stdexcept>

enum class Boje
{
    Pik, Tref, Herc, Karo
};

template <typename T > std::string PretvoriUString (T x)
{
    std::ostringstream s;
    s << x;
    return s.str();
}

std::list < std::pair < Boje, std::string >> KreirajSpil ()
{
    std::list < std::pair < Boje, std::string >> listaSpila;
    for(int i = 0; i < 4; i++) {
        for(int j = 2; j <= 10; j++) {
            if(i == 0)
                listaSpila.push_back(std::make_pair(Boje::Pik, PretvoriUString(j)));
            else if (i == 1)
                listaSpila.push_back(std::make_pair(Boje::Tref, PretvoriUString(j)));
            else if (i == 2)
                listaSpila.push_back(std::make_pair(Boje::Herc, PretvoriUString(j)));
            else if (i == 3)
                listaSpila.push_back(std::make_pair(Boje::Karo, PretvoriUString(j)));
        }
        if (i == 0) {
            listaSpila.push_back(std::make_pair(Boje::Pik, "J"));
            listaSpila.push_back(std::make_pair(Boje::Pik, "Q"));
            listaSpila.push_back(std::make_pair(Boje::Pik, "K"));
            listaSpila.push_back(std::make_pair(Boje::Pik, "A"));
        } else if (i == 1) {
            listaSpila.push_back(std::make_pair(Boje::Tref, "J"));
            listaSpila.push_back(std::make_pair(Boje::Tref, "Q"));
            listaSpila.push_back(std::make_pair(Boje::Tref, "K"));
            listaSpila.push_back(std::make_pair(Boje::Tref, "A"));
        } else if (i == 2) {
            listaSpila.push_back(std::make_pair(Boje::Herc, "J"));
            listaSpila.push_back(std::make_pair(Boje::Herc, "Q"));
            listaSpila.push_back(std::make_pair(Boje::Herc, "K"));
            listaSpila.push_back(std::make_pair(Boje::Herc, "A"));
        } else if (i == 3) {
            listaSpila.push_back(std::make_pair(Boje::Karo, "J"));
            listaSpila.push_back(std::make_pair(Boje::Karo, "Q"));
            listaSpila.push_back(std::make_pair(Boje::Karo, "K"));
            listaSpila.push_back(std::make_pair(Boje::Karo, "A"));
        }
    }

    return listaSpila;
}

template < class ForwardIterator >
bool is_sorted (ForwardIterator prvi, ForwardIterator last)
{
    if (prvi == last) return true;
    ForwardIterator next = prvi;
    while(++next != last) {
        std::string s1 = (*next).second;
        std::string s2 = (*prvi).second;
        int a(0), b(0);
        for(int i = 0; i < s1.size(); i++) {
            a*=10;
            a+=s1[i] - '0';
        }
        for(int i = 0; i < s2.size(); i++) {
            b*=10;
            b+=s2[i] - '0';
        }
        if (a < b && (int)(*next).first == (int)(*prvi).first) {
            return false;
        } else if (a == b && (int)(*next).first == (int)(*prvi).first) {
            return false;
        }
        if( (int)(*next).first < (int)(*prvi).first) {
            return false;
        }
        ++prvi;
    }
    return true;
}

bool IspravnaListaSpila(std::list < std::pair < Boje, std::string >> &listaSpila)
{
    if(listaSpila.size() > 52) {
        return false;
    }
    for (auto i = listaSpila.begin(); i != listaSpila.end(); i++) {
        if((*i).first != Boje::Pik && (*i).first != Boje::Tref && (*i).first != Boje::Herc  && (*i).first != Boje::Karo) {
            return false;
        }
        if((*i).second != "2" && (*i).second != "3" && (*i).second != "4" && (*i).second != "5" && (*i).second != "6" && (*i).second != "7" && (*i).second != "8" && (*i).second != "9" && (*i).second != "10" && (*i).second != "J" && (*i).second != "Q" && (*i).second != "K" && (*i).second != "A") {
            return false;
        }
    }
    for (auto i = listaSpila.begin(); i != listaSpila.end(); i++) {
       if ((*i).second == "J" ) (*i).second = "11";
       if ((*i).second == "Q" ) (*i).second = "12";
       if ((*i).second == "K" ) (*i).second = "13";
       if ((*i).second == "A" ) (*i).second = "14";
    }

    if(! is_sorted(listaSpila.begin(), listaSpila.end())) {
        for (auto i = listaSpila.begin(); i != listaSpila.end(); i++) {
            if ((*i).second == "11" ) (*i).second = "J";
            if ((*i).second == "12" ) (*i).second = "Q";
           if ((*i).second == "13" ) (*i).second = "K";
           if ((*i).second == "14" ) (*i).second = "A";
        }
        return false;
    }
    for (auto i = listaSpila.begin(); i != listaSpila.end(); i++) {
        if ((*i).second == "11" ) (*i).second = "J";
        if ((*i).second == "12" ) (*i).second = "Q";
        if ((*i).second == "13" ) (*i).second = "K";
        if ((*i).second == "14" ) (*i).second = "A";
    }
    return true;
}

void IzbaciKarte(std::list < std::pair < Boje, std::string >> &listaSpila, std::multimap < Boje, std::string > &multiMapa)
{
    if (! IspravnaListaSpila(listaSpila)) throw std::logic_error ("Neispravna lista!");
ponovo:
    for(auto it = multiMapa.begin(); it != multiMapa.end(); it++) {
        for(auto ot = listaSpila.begin(); ot != listaSpila.end(); ot++) {
            if(it -> first == (*ot).first && it -> second == (*ot).second) {
                listaSpila.erase(ot);
                multiMapa.erase(it);
                goto ponovo;
            }
        }
    }
}

std::queue < std::pair < std::string, std::string >> IzbaciKarteRazbrajanjem(std::list < std::pair < Boje, std::string >> &listaSpila, const short int &r, int &b)
{
    if (!IspravnaListaSpila(listaSpila)) throw std::logic_error ("Neispravna lista!");
    if (r < 1 || r > 52) throw std::logic_error ("Neispravni elementi za izbacivanje!");
    if (b < 1) throw std::logic_error ("Neispravni elementi za izbacivanje!");
    std::queue < std::pair < std::string, std::string >> red;
    int izbaceno(0), element(0);
    for(auto i = listaSpila.begin(); ; i++) {
        if (i == listaSpila.end()) i = listaSpila.begin();
        element++;
        if(element == r) {
            if((int)(*i).first == 0)
                red.push(std::make_pair("Pik", (*i).second));
            else if((int)(*i).first == 1)
                red.push(std::make_pair("Tref", (*i).second));
            else if((int)(*i).first == 2)
                red.push(std::make_pair("Herc", (*i).second));
            else  if((int)(*i).first == 3)
                red.push(std::make_pair("Karo", (*i).second));
            auto m = i;
            m--;
            listaSpila.erase(i);
            i = m;
            izbaceno++;
            if(izbaceno == b || listaSpila.size() == 0) break;
            element = 0;
        }
    }
    return red;
}

void VratiPrvihNKarata(std::list < std::pair < Boje, std::string >> &listaSpila,std::queue < std::pair < std::string, std::string >>& red, int n)
{
    if (n < 0) throw std::domain_error ("Broj n je besmislen!");
    if (n > red.size()) throw std::range_error ("Nedovoljno karata u redu!");
    for(int k = 0; k < red.size(); k++) {
        std::string a1, a2;
        a1 = red.front().first;
        a2 = red.front().second;
        if(a1 != "Pik" && a1 != "Tref" && a1 != "Herc" && a1 != "Karo") throw std::logic_error ("Neispravne karte!");
        if(a2 != "2" && a2 != "3" && a2 != "4" && a2 != "5" && a2 != "6" && a2 != "7" && a2 != "8" && a2 != "9" && a2 != "10"
                && a2 != "J" && a2 != "Q" && a2 != "K" && a2 != "A") throw std::logic_error ("Neispravne karte!");
        red.push(red.front());
        red.pop();
    }
    if (!IspravnaListaSpila(listaSpila)) throw std::logic_error ("Neispravna lista!");
    for (int l = 0; l < n; l++) 
    {
        bool nemaKartiTogZnakaUspilu=true;
        for (auto it = listaSpila.begin(); it != listaSpila.end(); it++) 
        {
            bool PrekiniRad = false;
            std::string znak;
            if((int)(*it).first == 0) {
                znak = "Pik";
            }
            if((int)(*it).first == 1) {
                znak = "Tref";
            }
            if((int)(*it).first == 2) {
                znak = "Herc";
            }
            if((int)(*it).first == 3) {
                znak = "Karo";
            }
            if(znak == red.front().first) 
            {
                nemaKartiTogZnakaUspilu=false;
                bool najveciUznaku=false;
                while (znak == red.front().first && it != listaSpila.end()) 
                {
                    std::string s1 = (*it).second;
                    std::string s2 = red.front().second;
                    int a(0), b(0);
                    if((s1[0] >= '0' && s1[0] <= '9') && (s2[0] >= '0' && s2[0] <= '9')) 
                    {
                        for(int i = 0; i < s1.size(); i++) 
                        {
                            a*=10;
                            a+=s1[i] - '0';
                        }
                        for(int i = 0; i < s2.size(); i++) {
                            b*=10;
                            b+=s2[i] - '0';
                        }
                    } 
                    else 
                    {
                        if (s1 == "J" ) a= 11;
                        else if (s1 == "Q" ) a = 12;
                        else if (s1 == "K" ) a = 13;
                        else if(s1 == "A" ) a = 14;
                        if (s2 == "J" ) b = 11;
                        else if (s2== "Q" ) b = 12;
                        else if (s2 == "K" ) b = 13;
                        else if(s2 == "A" ) b = 14;
                    }
                    if (b == a) 
                    {
                        najveciUznaku=false;
                        PrekiniRad = true;
                    } 
                    else if (b < a) 
                    {
                        najveciUznaku=false;
                        if (znak == "Pik")
                            listaSpila.insert(it, std::make_pair(Boje::Pik,red.front().second));
                        if (znak == "Tref")
                            listaSpila.insert(it, std::make_pair(Boje::Tref,red.front().second));
                        if (znak == "Herc")
                            listaSpila.insert(it, std::make_pair(Boje::Herc,red.front().second));
                        if (znak == "Karo")
                            listaSpila.insert(it, std::make_pair(Boje::Karo,red.front().second));
                        red.pop();
                        PrekiniRad = true;
                    }
                    else if(b>a)
                    {
                        najveciUznaku=true;
                    }
                    it++;
                    if((int)(*it).first == 0) {
                        znak = "Pik";
                    }
                    if((int)(*it).first == 1) {
                        znak = "Tref";
                    }
                    if((int)(*it).first == 2) {
                        znak = "Herc";
                    }
                    if((int)(*it).first == 3) {
                        znak = "Karo";
                    }
                    if(PrekiniRad) break;
                }
                if(najveciUznaku)
                {
                    if (red.front().first == "Pik")
                            listaSpila.insert(it, std::make_pair(Boje::Pik,red.front().second));
                    if (red.front().first == "Tref")
                        listaSpila.insert(it, std::make_pair(Boje::Tref,red.front().second));
                    if (red.front().first == "Herc")
                        listaSpila.insert(it, std::make_pair(Boje::Herc,red.front().second));
                    if (red.front().first == "Karo")
                        listaSpila.insert(it, std::make_pair(Boje::Karo,red.front().second));
                    red.pop();
                    PrekiniRad = true;
                }
                it--;
            }
            else
            {
                nemaKartiTogZnakaUspilu=true;
            }
            if(PrekiniRad) break;
        }
        if(nemaKartiTogZnakaUspilu)
        {
            if(red.front().first=="Pik")
            {
                auto it=listaSpila.begin();
                for (;it!=listaSpila.end();it++) 
                {
                    if((int)(*it).first==1)
                        break;
                }
                if(it==listaSpila.end()) it=listaSpila.begin();
                listaSpila.insert(it, std::make_pair(Boje::Pik,red.front().second));
                red.pop();
            }
            else if(red.front().first=="Tref")
            {
                auto it=listaSpila.begin();
                for (;it!=listaSpila.end();it++) 
                {
                    if((int)(*it).first==2)
                        break;
                }
                if(it==listaSpila.end())
                {
                    it=listaSpila.begin();
                    while ((int)(*it).first==0 && it!=listaSpila.end()) 
                    {
                        it++;
                    }
                }
                listaSpila.insert(it, std::make_pair(Boje::Tref,red.front().second));
                red.pop();
            }
            else if(red.front().first=="Herc")
            {
                auto it=listaSpila.begin();
                for (;it!=listaSpila.end();it++) 
                {
                    if((int)(*it).first==3)
                        break;
                }
                if(it==listaSpila.end()) 
                    listaSpila.push_back(std::make_pair(Boje::Herc,red.front().second));
                else listaSpila.insert(it, std::make_pair(Boje::Herc,red.front().second));
                red.pop();
            }
            else if(red.front().first=="Karo")
            {
                listaSpila.push_back(std::make_pair(Boje::Karo,red.front().second));
                red.pop();
            }
        }
    }
}

int main ()
{
    std::list < std::pair < Boje, std::string >> listaSpila = KreirajSpil();
    int korakRazbrajanja;
    std::cout << "Unesite korak razbrajanja: ";
    std::cin >> korakRazbrajanja;
    int brojIzbacenihKarata;
    std::cout << "Unesite broj karata koje zelite izbaciti: ";
    std::cin >> brojIzbacenihKarata;
    std::queue < std::pair < std::string, std::string >> redIzbacenih;
    try 
    {
        redIzbacenih = IzbaciKarteRazbrajanjem(listaSpila, korakRazbrajanja, brojIzbacenihKarata);
    }
    catch(std::logic_error c)
    {
        std::cout <<"Izuzetak: "<< c.what();
        return 0;
    }
    std::cout << "U spilu trenutno ima " << listaSpila.size() << " karata, i to: " << std::endl;
    if(listaSpila.size()==0)
    {
        std::cout << "Pik:\nTref:\nHerc:\nKaro:";
    }
    for (auto x = listaSpila.begin(); x != listaSpila.end(); x++)
    {
        std::cout << "Pik: ";
        if((*x).first == Boje::Pik)
        {
            while ((*x).first == Boje::Pik && x != listaSpila.end())
            {
                std::cout << (*x).second << " ";
                x++;
            }
            if(x==listaSpila.end()) x--;
        }
        std::cout << "\nTref: ";
        if((*x).first == Boje::Tref)
        {
            while ((*x).first == Boje::Tref && x != listaSpila.end())
            {
                std::cout << (*x).second << " ";
                x++;
            }
            if(x==listaSpila.end()) x--;
        }
        std::cout << "\nHerc: ";
        if((*x).first == Boje::Herc)
        {
            while ((*x).first == Boje::Herc && x != listaSpila.end())
            {
                std::cout << (*x).second << " ";
                x++;
            }
            if(x==listaSpila.end()) x--;
        }
        std::cout << "\nKaro: ";
        if((*x).first == Boje::Karo)
        {
            while ((*x).first == Boje::Karo && x != listaSpila.end())
            {
                std::cout << (*x).second << " ";
                x++;
            }
            if(x==listaSpila.end()) x--;
        }
    }
        std::cout << "\nUnesite broj karata koje zelite vratiti u spil: ";
        int n;
        std::cin >> n;
        try
        {
            VratiPrvihNKarata(listaSpila, redIzbacenih, n);
        }
        catch (std::exception& c)
        {
            std::cout<<"Izuzetak: " << c.what();
            return 0;
        }
        
        std::cout << "U spilu trenutno ima " << listaSpila.size() << " karata, i to: " << std::endl;
        if(listaSpila.size()==0)
        {
            std::cout << "Pik:\nTref:\nHerc:\nKaro:";
        }
        for (auto x = listaSpila.begin(); x != listaSpila.end(); x++)
        {
            std::cout << "Pik: ";
            if((*x).first == Boje::Pik)
            {
                while ((*x).first == Boje::Pik && x != listaSpila.end())
                {
                    std::cout << (*x).second << " ";
                    x++;
                }
                if(x==listaSpila.end()) x--;
            }
            std::cout << "\nTref: ";
            if((*x).first == Boje::Tref)
            {
                while ((*x).first == Boje::Tref && x != listaSpila.end())
                {
                    std::cout << (*x).second << " ";
                    x++;
                }
                if(x==listaSpila.end()) x--;
            }
            std::cout << "\nHerc: ";
            if((*x).first == Boje::Herc)
            {
                while ((*x).first == Boje::Herc && x != listaSpila.end())
                {
                    std::cout << (*x).second << " ";
                    x++;
                }
                if(x==listaSpila.end()) x--;
            }
            std::cout << "\nKaro: ";
            if((*x).first == Boje::Karo)
            {
                while ((*x).first == Boje::Karo && x != listaSpila.end())
                {
                    std::cout << (*x).second << " ";
                    x++;
                }
                if(x==listaSpila.end()) x--;
            }
        }
    return 0;
}
