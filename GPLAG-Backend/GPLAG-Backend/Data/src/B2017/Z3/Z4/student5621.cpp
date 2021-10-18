/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <map>
#include <utility>
#include <stdexcept>
#include <queue>
#include <iomanip>
#include <algorithm>

enum class Boje
{
    Pik, Tref, Herc, Karo
};

const char* VrijednostKarte[13] {
    "2","3","4","5","6","7","8","9","10","J","Q","K","A"
};

const char* BojaKarte[4] {
    "Pik","Tref","Herc","Karo"
};

typedef std::list<std::pair<Boje,std::string>> lista;
typedef std::multimap<Boje, std::string> multimapa;

void edvens( lista &spil,lista::iterator &it, int n);

int broj_elem(const lista &spil);

void is_list_okay(const lista &);

bool pair_compare(std::pair<Boje, std::string> &p1,std::pair<Boje, std::string> &p );

lista KreirajSpil(void);
void IzbaciKarte(lista &l, multimapa &m);
std::queue<std::pair<std::string,std::string>> IzbaciKarteRazbrajanjem(lista &,const short int &, const int &);
void VratiPrvihNKarata(lista &spil, std::queue<std::pair<std::string,std::string>> &red, int n);

int main ()
{

  
    try {
        std::cout<<"Unesite korak razbrajanja: ";
        short int r;
        std::cin>>r;
        std::cout<<"Unesite broj karata koje zelite izbaciti: ";
        int b;
        std::cin>>b;
        auto spil(KreirajSpil());
        auto za_kasnije( IzbaciKarteRazbrajanjem(spil,r,b));
        std::cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to:";
        for(int i=0;i<4;i++)
        {
            std::cout<<std::endl<<BojaKarte[i]<<": ";
            std::pair<Boje,std::string> a (Boje(i), "");
            
          for(auto it = spil.begin();it != spil.end();it++   )
            {
                if(it->first == Boje(i) )std::cout<<it->second<<" ";
            }
        }

        std::cout<<"\nUnesite broj karata koje zelite vratiti u spil: ";
        int n;
        std::cin>>n;
        VratiPrvihNKarata(spil,za_kasnije,n);
        std::cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to:";
        for(int i=0;i<4;i++)
        {
            std::cout<<std::endl<<BojaKarte[i]<<": ";
           
            
            for(auto it = spil.begin();it != spil.end();it++   )
            {
                if(it->first == Boje(i) )std::cout<<it->second<<" ";
            }
        }
   
    }
    catch(std::domain_error izuzetak)
    {
        std::cout <<"Izuzetak: "<< izuzetak.what();
    }
    catch(std::range_error izuzetak)
    {
        std::cout << "Izuzetak: " <<izuzetak.what();
    }
    catch( std::logic_error izuzetak)
    {
        std::cout << "Izuzetak: " <<izuzetak.what();
    }

    return 0;
}

void VratiPrvihNKarata(lista &spil, std::queue<std::pair<std::string,std::string>> &red, int n)
{
    if(n<0)throw std::domain_error("Broj n je besmislen!");
    if(n>static_cast<int>(red.size()))throw std::range_error("Nedovoljno karata u redu!");
    {
        auto kraj=spil.end();
        kraj--;
        int k(0);
        auto it2(spil.begin());
        for( auto it=spil.begin(); it != kraj; it++) {
            it2++;
            k++;
            bool ne_valja(true);
            for(int i=0; i<13; i++) {
                for(int j = 0; j<13; j++) {
                    if(it->second == std::string(VrijednostKarte[i]) && it2->second == std::string(VrijednostKarte[j])) {
                        ne_valja=false;
                    }
                }
            }
            if(ne_valja)throw std::logic_error("Neispravna lista!");
        }
    }
    is_list_okay(spil);
//ovdje treba provjera reda
    if(!red.empty())
    {
        bool ne_valja=true;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<13;j++)
            {
                if(red.front().first == BojaKarte[i] && red.front().second == VrijednostKarte[j])
                {
                    ne_valja=false;
                    break;
                }
            }
        }
        if(ne_valja)throw std::logic_error("Neispravne karte!");
        auto temp(red.front());
        red.push(red.front());
        red.pop();
    }
    for(auto temp(red.back());red.front()!=temp && !red.empty();)
    {
        bool ne_valja=true;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<13;j++)
            {
                if(red.front().first == BojaKarte[i] && red.front().second == VrijednostKarte[j])
                {
                    ne_valja=false;
                    break;
                }
            }
        }
        if(ne_valja)throw std::logic_error("Neispravne karte!");
        red.push(red.front());
        red.pop();
    }
   
//bas ovdje iznad
    for(int k=0; k<n && !red.empty(); k++) {
        for(int i=0; i<4; i++) {
            if(static_cast<std::string>(BojaKarte[i]) == red.front().first) {
                //treba provjera
                //yup
                spil.push_back( {Boje(i),red.front().second   }  );
                red.pop();
                break;
            }
        }
    }

    spil.sort(pair_compare);
    spil.unique();


}

bool pair_compare(std::pair<Boje, std::string> &p1,std::pair<Boje, std::string> &p2 )
{
    if( p1.first == p2.first) {
        for(int i=0; i<13; i++) {
            for(int j=0; j<13; j++) {
                if(p1.second==VrijednostKarte[i] && p2.second == VrijednostKarte[j])
                    return i<=j;
            }
        }
    }
    return p1.first < p2.first;
}


void edvens( lista &spil,lista::iterator &it, int n)
{
    for(int i=0; i<n; i++) {
        it++;
        if(it==spil.end())it=spil.begin();
    }

}

int broj_elem(const lista &spil)
{
    int n(0);
    for(auto i=spil.begin(); i!=spil.end(); i++)
        n++;
    return n;
}

std::queue<std::pair<std::string,std::string>> IzbaciKarteRazbrajanjem(lista &spil,const short int &r, const int &b)
{
    std::queue<std::pair<std::string, std::string>> kju;
    //provjera
    if(r>52 || r<1 || b <1)throw std::logic_error("Neispravni elementi za izbacivanje!");
    is_list_okay(spil);
    //zavrsena provjera
    int pomak(r-1);
    auto it(spil.begin());
    for(int i=0; i < b && broj_elem(spil); i++ ) {
        edvens(spil,it,pomak);
        kju.push({BojaKarte[static_cast<int>(it->first)], it->second});
        it=spil.erase(it);
    }
    return kju;
}

void is_list_okay(const lista &l)
{

    auto kraj=l.end();
    kraj--;
    int k(0);
    auto it2(l.begin());
    for(auto it=l.begin(); it != kraj; it++) {
        it2++;
        k++;
        if(static_cast<int>(it->first) > static_cast<int>(it2->first) ||  k>51 )throw std::logic_error("Neispravna lista!");
        bool ne_valja(true);
        for(int i=0; i<13; i++) {
            for(int j=0; j<13; j++) {
                if( it->second == std::string(VrijednostKarte[i])  && it2->second == std::string(VrijednostKarte[j]) ) {
                    if(i>=j && static_cast<int>(it->first) == static_cast<int>(it2->first))throw std::logic_error("Neispravna lista!");
                    ne_valja=false;
                    break;
                }
            }
        }
        if(ne_valja || (*it)==(*it2) )throw std::logic_error("Neispravna lista!");

    }

}

void IzbaciKarte(lista &l, multimapa &m)
{
    is_list_okay(l);

    for(auto it=l.begin(); it!=l.end();) {
        int i(0);
        for(auto it2=m.begin(); it2!=m.end();) {
            if( it2->first == it->first && it2->second == it->second) {
                it2=m.erase(it2);
                it=l.erase(it);
                i=1;
                break;
            } else {
                it2++;
            }
        }
        if(!i)it++;
    }
}


lista KreirajSpil(void)
{
    lista l;

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j<13; j++) {
            l.push_back(std::make_pair<Boje,std::string>(Boje(i),VrijednostKarte[j]));
        }
    }
    return l;
}