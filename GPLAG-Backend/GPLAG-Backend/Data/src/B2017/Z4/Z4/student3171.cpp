/B2017/2018: Zadaća 4, Zadatak 4
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <iomanip>
#include <utility>
#include <string>
#include <initializer_list>
#include <algorithm>
#include <functional>
#include <memory>
#include <vector>

constexpr int month[13]{0,31,28,31,30,31,30,31,31,30,31,30,31};
class Datum 
{
  int d,m,g;
  public:
    Datum(int dan=1, int mjesec=1, int godina=1)
    {
        if(!(godina>0 && mjesec >0 && mjesec<13 && dan<=(month[mjesec]+((godina%400==0 || (godina%4==0 && godina%100!=0))&&mjesec==2)) && dan>0 ))throw std::domain_error("Neispravan datum");
        d=dan;
        m=mjesec;
        g=godina;
    }
    void Postavi(int dan, int mjesec, int godina)
    {
        if(!(godina>0 && mjesec >0 && mjesec<13 && dan<=(month[mjesec]+((godina%400==0 || (godina%4==0 && godina%100!=0)) && mjesec==2)) && dan>0 ))throw std::domain_error("Neispravan datum");
        d=dan;
        m=mjesec;
        g=godina;
    }
    std::tuple<int, int, int> Ocitaj() const
    {
        return std::tuple<int,int,int>(d,m,g);
    }
    void Ispisi() const
    {
        std::cout<<d<<"/"<<m<<"/"<<g;
    }
};

class Vrijeme
{
    int h,m;
  public:
    Vrijeme(int sati=0, int minute=0)
    {
        if(!(sati>=0 && sati <24 && minute>=0 && minute < 60))throw std::domain_error("Neispravno vrijeme");
        h=sati;
        m=minute;
    }
    void Postavi(int sati, int minute)
    {
        if(!(sati>=0 && sati <24 && minute>=0 && minute < 60))throw std::domain_error("Neispravno vrijeme");
        h=sati;
        m=minute;
    }
    std::pair<int, int> Ocitaj () const
    {
        return std::pair<int,int>(h,m);
    }
    void Ispisi() const
    {
        std::cout.fill('0');
        std::cout<<std::setw(2)<<std::fixed<<std::right<<h<<":"<<std::setw(2)<<std::fixed<<m;
    }
};

class Pregled
{
    std::string name;
    Datum dp;
    Vrijeme vp;
  public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda,
    const Vrijeme &vrijeme_pregleda)
    {
        name=ime_pacijenta;
        int d,m,g;
        std::tie(d,m,g)=datum_pregleda.Ocitaj();
        dp.Postavi(d,m,g);
        int h,min;
        std::tie(h,min)=vrijeme_pregleda.Ocitaj();
        vp.Postavi(h,min);
    }
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,
    int godina_pregleda, int sati_pregleda, int minute_pregleda)
    {
        name=ime_pacijenta;
        dp.Postavi(dan_pregleda,mjesec_pregleda,godina_pregleda);
        vp.Postavi(sati_pregleda,minute_pregleda);
    }
    void PromijeniPacijenta(const std::string &ime_pacijenta)
    {
        name=ime_pacijenta;
    }
    void PromijeniDatum(const Datum &novi_datum)
    {
        int d,m,g;
        std::tie(d,m,g)=novi_datum.Ocitaj();
        dp.Postavi(d,m,g);
    }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme)
    {
        int h,m;
        std::tie(h,m)=novo_vrijeme.Ocitaj();
        vp.Postavi(h,m);
    }
    void PomjeriDanUnaprijed()
    {
        int d,m,g;
        std::tie(d,m,g)=dp.Ocitaj();
        d++;
        if(d>month[m]+ ((g%400==0 || (g%4==0 && g%100!=0)) && m==2) )
        {
            d=1;
            m++;
            if(m>12)
            {
                g++;
                m=1;
            }
        }
        dp.Postavi(d,m,g);
    }
    void PomjeriDanUnazad()
    {
        int d,m,g;
        std::tie(d,m,g)=dp.Ocitaj();
        d--;
        if(d==0)
        {
            m--;
            if(m==0)
            {
                m=12;
                g--;
            }
            d=month[m]+(m==2 &&( g%400==0 || (g%4==0 && g%100!=0) ));
        }
        dp.Postavi(d,m,g);
    }
    std::string DajImePacijenta() const
    {
        return name;
    }
    Datum DajDatumPregleda() const
    {
        return dp;
    }
    Vrijeme DajVrijemePregleda() const
    {
        return vp;
    }
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2)
    {
        int d,m,g;
        std::tie(d,m,g)=p1.DajDatumPregleda().Ocitaj();
        int x,y,z;
        std::tie(x,y,z)=p2.DajDatumPregleda().Ocitaj();
        int s,t;
        std::tie(s,t)=p1.DajVrijemePregleda().Ocitaj();
        int u,v;
        std::tie(u,v)=p2.DajVrijemePregleda().Ocitaj();
        if(g==z)
        {
            if(m==y)
            {
                if(d==x)
                {
                    if(s==u)
                    {
                        return t<v;
                    }
                    return s<u;
                }
                return d<x;
            }
            return m<y;
        }
        return g<z;
    }
    void Ispisi() const
    {
        std::cout.fill(' ');
        std::cout<<std::setw(30)<<std::left<<name;
        dp.Ispisi();
        std::cout<<" ";
        vp.Ispisi();
        std::cout<<std::endl;
    }

};

class Pregledi
{
    std::vector<std::shared_ptr<Pregled>> niz;
 
    void sortiraj()
    {
        std::sort(niz.begin(),niz.end(),[](std::shared_ptr<Pregled> a, std::shared_ptr<Pregled> b){ 
        int d,m,g;
        std::tie(d,m,g)=a->DajDatumPregleda().Ocitaj();
        int x,y,z;
        std::tie(x,y,z)=b->DajDatumPregleda().Ocitaj();
        int s,t;
        std::tie(s,t)=a->DajVrijemePregleda().Ocitaj();
        int u,v;
        std::tie(u,v)=b->DajVrijemePregleda().Ocitaj();
        if(g==z)
        {
            if(m==y)
            {
                if(d==x)
                {
                    if(s==u)
                    {
                        return t<v;
                    }
                    return s<u;
                }
                return d<x;
            }
            return m<y;
        }
        return g<z;
        });
    }
  public:
    Pregledi(int broj=0)
    {
        niz.resize(broj);
    }
    Pregledi(std::initializer_list<Pregled> spisak_pregleda)
    {
       
        auto it(spisak_pregleda.begin());
        for(int i=0;i<spisak_pregleda.size();i++,it++)
        {
            niz.push_back(std::make_shared< Pregled>(*it));
        }
        sortiraj();
    }
    ~Pregledi(){
        for(int i=0;i<niz.size();i++)
        {
            niz[i]=nullptr;
        }
    }
    Pregledi(const Pregledi &pregledi)
    {
        for(int i=0;i<pregledi.niz.size();i++)
        {
            niz.push_back( std::make_shared< Pregled>(*(pregledi.niz[i])));
        }
        sortiraj();
    }
    Pregledi(Pregledi &&pregledi)
    {
        niz=pregledi.niz;
       
        for(int i=0;i<pregledi.niz.size();i++)
        {
            pregledi.niz[i]=nullptr;
        }
        sortiraj();
    }
    Pregledi &operator =(const Pregledi &pregledi)
    {
        
        for(int i=0;i<niz.size();i++)
        {
            niz[i]=nullptr;
        }
        niz.resize(0);
        for(int i=0;i<pregledi.niz.size();i++)
        {
            niz.push_back(std::make_shared< Pregled>(*(pregledi.niz[i])));
        }
        sortiraj();
        return *this;
    }
    Pregledi &operator =(Pregledi &&pregledi)
    {
        for(int i=0;i<niz.size();i++)
        {
            niz[i]=nullptr;
        }
        niz=pregledi.niz;
        
        for(int i=0;i<pregledi.niz.size();i++)
        {
            pregledi.niz[i]=nullptr;
        }
        
        sortiraj();
        return *this;
    }
    void RegistrirajPregled(const std::string &ime_pacijenta,
    const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda)
    {
        niz.push_back(std::make_shared<Pregled>(ime_pacijenta,datum_pregleda,vrijeme_pregleda));
        sortiraj();
    }
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,
    int mjesec_pregleda, int godina_pregleda, int sati_pregleda,
    int minute_pregleda)
    {
       
        niz.push_back(std::make_shared<Pregled>(ime_pacijenta,dan_pregleda,mjesec_pregleda,godina_pregleda,sati_pregleda,minute_pregleda));
        
        sortiraj();
    }
    void RegistrirajPregled(std::shared_ptr<Pregled> pregled)
    {
        niz.push_back(pregled);
        sortiraj();
    }
    int DajBrojPregleda() const
    {
        return niz.size();
    }
    int DajBrojPregledaNaDatum(const Datum &datum) const
    {
        int x,y,z;
        std::tie(x,y,z)=datum.Ocitaj();
        int n(std::count_if(niz.begin(),niz.end(),[x,y,z](std::shared_ptr<Pregled> k){ 
        int a,b,c;
            std::tie(a,b,c)=k->DajDatumPregleda().Ocitaj();
            return a==x && b==y && c==z;
        }));
       
        return n;
    }
    Pregled &DajNajranijiPregled()
    {
        if(niz.size()==0)throw std::domain_error("Nema registriranih pregleda");
        return **std::min_element(niz.begin(),niz.end(),
        [](std::shared_ptr<Pregled> a, std::shared_ptr<Pregled> b){ 
            int d,m,g;
            std::tie(d,m,g)=a->DajDatumPregleda().Ocitaj();
            int x,y,z;
            std::tie(x,y,z)=b->DajDatumPregleda().Ocitaj();
            int s,t;
            std::tie(s,t)=a->DajVrijemePregleda().Ocitaj();
            int u,v;
            std::tie(u,v)=b->DajVrijemePregleda().Ocitaj();
            if(g==z)
            {
                if(m==y)
                {
                    if(d==x)
                    {
                        if(s==u)
                        {
                            return t<v;
                        }
                        return s<u;
                    }
                    return d<x;
                }
                return m<y;
            }
            return g<z;
            });
        
    }
    Pregled DajNajranijiPregled() const
    {
        return **std::min_element(niz.begin(),niz.end(),[](std::shared_ptr<Pregled> a, std::shared_ptr<Pregled> b){ 
        int d,m,g;
        std::tie(d,m,g)=a->DajDatumPregleda().Ocitaj();
        int x,y,z;
        std::tie(x,y,z)=b->DajDatumPregleda().Ocitaj();
        int s,t;
        std::tie(s,t)=a->DajVrijemePregleda().Ocitaj();
        int u,v;
        std::tie(u,v)=b->DajVrijemePregleda().Ocitaj();
        if(g==z)
        {
            if(m==y)
            {
                if(d==x)
                {
                    if(s==u)
                    {
                        return t<v;
                    }
                    return s<u;
                }
                return d<x;
            }
            return m<y;
        }
        return g<z;
        });
        
    }
    void IsprazniKolekciju()
    {
        for(int i=0;i<niz.size();i++)
        {
         
            niz[i]=nullptr;
        }
        niz.resize(0);
    }
    void ObrisiNajranijiPregled()
    {
           if(niz.size()==0)throw std::range_error("Prazna kolekcija");
      auto pok=std::min_element(niz.begin(),niz.end(),[](std::shared_ptr<Pregled> a, std::shared_ptr<Pregled> b){ 
        int d,m,g;
        std::tie(d,m,g)=a->DajDatumPregleda().Ocitaj();
        int x,y,z;
        std::tie(x,y,z)=b->DajDatumPregleda().Ocitaj();
        int s,t;
        std::tie(s,t)=a->DajVrijemePregleda().Ocitaj();
        int u,v;
        std::tie(u,v)=b->DajVrijemePregleda().Ocitaj();
        if(g==z)
        {
            if(m==y)
            {
                if(d==x)
                {
                    if(s==u)
                    {
                        return t<v;
                    }
                    return s<u;
                }
                return d<x;
            }
            return m<y;
        }
        return g<z;
        });
        
        niz.erase(pok);
        sortiraj();
    }
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta)
    {
        for(int i=0;i<niz.size();i++)
        {
            if(niz[i]->DajImePacijenta()==ime_pacijenta)
            {
              niz[i]=nullptr;
               for(int j=i;j<niz.size()-1;j++)
               {
                   niz[j]=niz[j+1];
               }
               niz.resize(niz.size()-1);
            }
        }
        sortiraj();
    }
    void IspisiPregledeNaDatum(const Datum &datum) const
    {
        
        int x,y,z;
        std::tie(x,y,z)=datum.Ocitaj();
        int a,b,c;
        for(int i=0;i<niz.size();i++)
        {
            std::tie(a,b,c)=niz[i]->DajDatumPregleda().Ocitaj();
         if(a==x && b==y && c==z)
         {
             niz[i]->Ispisi();
         }   
        }
       
    }
    void IspisiSvePreglede() const
    {
        for(int i=0;i<niz.size();i++)
        {
            niz[i]->Ispisi();
        }
    }

};

int main ()
{
   
    std::string name;
    int d,m,g;
    int sati,minute;
    Pregledi dnevnik(0);
    for(;;)
    {
        std::cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        std::cin>>name;
        if(name=="kraj")break;
        std::cout<<"Unesite dan mjesec i godinu pregleda: ";
        std::cin>>d>>m>>g;
        std::cout<<"Unesite sate i minute pregleda: ";
        std::cin>>sati>>minute;
        dnevnik.RegistrirajPregled(name,d,m,g,sati,minute);
    }
    std::cout<<"Trenutno su registrovani sljedeci pregledi\n";
    dnevnik.IspisiSvePreglede();
    for(bool terminator(true);terminator;){
    std::cout<<"\nOdaberite jednu od sljedecih opcija\n"
             <<"1 - Broj pregleda na datum\n"
             <<"2 - Najraniji pregled\n"
             <<"3 - Obrisi pregled pacijenta\n"
             <<"4 - Obrisi najraniji pregled\n"
             <<"5 - Ispisi sve pregleda na datum\n"
             <<"6 - Ispisi sve preglede\n"
             <<"7 - Kraj programa\n";
    
    int opcija;
    std::cin>>opcija;
    switch(opcija)
    {
        case 1:
        {
            std::cout<<"Unesite dan mjesec i godinu : ";
            std::cin>>d>>m>>g;
            Datum x(d,m,g);
            std::cout<<"Broj pregleda na datum "<<d<<" "<<m<<" "<<g<<" je: "
                     <<dnevnik.DajBrojPregledaNaDatum(x)<<std::endl;
            break;
        }
        case 2:
        {
            std::cout<<"Najraniji pregled je:\n";
            dnevnik.DajNajranijiPregled().Ispisi();
            std::cout<<std::endl;
            break;
        }
        case 3:
        {
            std::cout<<"Unesite ime pacijenta: ";
            std::cin>>name;
            int num(dnevnik.DajBrojPregleda());
            dnevnik.ObrisiPregledePacijenta(name);
            std::cout<<"Uspjesno obrisano "<<num-dnevnik.DajBrojPregleda()<<" pregleda";
            break;
        }
        case 4:
        {
            dnevnik.ObrisiNajranijiPregled();
            std::cout<<"Najraniji pregled uspjesno obrisan\n";
            break;
        }
        case 5:
        {
            std::cout<<"Unesite dan mjesec i godinu : ";
            std::cin>>d>>m>>g;
            std::cout<<"Pregledi na datum "<<d<<" "<<m<<" "<<g<<" su:\n";
            dnevnik.IspisiPregledeNaDatum(Datum(d,m,g));
            break;
        }
        case 6:
        {
            dnevnik.IspisiSvePreglede();
            break;
        }
        case 7:
        {
            terminator=false;
            break;
        }
        default:
        {
            std::cout<<"Ne postoji opcija";
        }
    }
    }
	return 0;
}
