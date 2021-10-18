#include <iostream>
#include <tuple>
#include <utility>
#include <stdexcept>
#include <algorithm>
#include <string>
#include <iomanip>
#include <initializer_list>
#include <vector>

class Datum{
    int d, m, g;
    public:
    Datum(int dan, int mjesec, int godina) {Postavi(dan, mjesec, godina);}
    void Postavi(int dan, int mjesec, int godina);
    std::tuple<int, int, int> Ocitaj() const {return std::make_tuple(d, m, g);}
    void Ispisi() const {std::cout << d << "/" << m << "/" << g;}
};

void Datum::Postavi(int dan, int mjesec, int godina){
    int b_d[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina%4==0 && godina%100!=0) || godina%400==0) b_d[1]++;
    if(dan<1 || mjesec<1 || godina<1 || mjesec>12 || dan>b_d[mjesec-1])
        throw std::domain_error("Neispravan datum");
    d=dan; m=mjesec; g=godina;    
}

class Vrijeme{
    int h, min;
    public:
    Vrijeme(int sati, int minute) {Postavi(sati, minute);}
    void Postavi(int sati, int minute);
    std::pair<int, int> Ocitaj() const {return {h, min};}
    void Ispisi() const {
        if(h<10) std::cout << "0"; std::cout << h << ":";
        if(min<10) std::cout << "0"; std::cout << min; 
    }
};

void Vrijeme::Postavi(int sati, int minute){
    if(sati<0 || sati>23 || minute<0 || minute>59)
        throw std::domain_error("Neispravno vrijeme");
    h=sati; min=minute;    
}

class Pregled{
    std::string ime; 
    Datum dat;
    Vrijeme tajm;
    static std::tuple<int, int, int> KorigujDatum(int da, int mj, int go);
    public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda): 
    ime(ime_pacijenta), dat(0, 0, 0), tajm(0, 0) {
        auto t(datum_pregleda.Ocitaj()); auto p(vrijeme_pregleda.Ocitaj());
        dat.Postavi(std::get<0>(t), std::get<1>(t), std::get<2>(t));
        tajm.Postavi(p.first, p.second);
    }
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda):
    ime(ime_pacijenta), dat(dan_pregleda, mjesec_pregleda, godina_pregleda), tajm(sati_pregleda, minute_pregleda) {}
    void PromijeniPacijenta(const std::string &ime_pacijenta){
        ime=ime_pacijenta;
    }
    void PromijeniDatum(const Datum &novi_datum){
        auto t(novi_datum.Ocitaj());
        dat.Postavi(std::get<0>(t), std::get<1>(t), std::get<2>(t));
    }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme){
        auto p(novo_vrijeme.Ocitaj());
        tajm.Postavi(p.first, p.second);
    }
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImePacijenta() const {return ime;}
    Datum DajDatumPregleda() const {return dat;}
    Vrijeme DajVrijemePregleda() const {return tajm;}
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
    void Ispisi() const{
        std::cout << std::left << std::setw(30) << ime;
        dat.Ispisi(); std::cout << " "; tajm.Ispisi(); std::cout << std::endl;
    }
};

std::tuple<int, int, int> Pregled::KorigujDatum(int da, int mj, int go){
    int b_d[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((go%4==0 && go%100!=0) || go%400==0) b_d[1]++;
    if(da>b_d[mj-1]){
        mj++; da=1;
        if(mj>12){ mj=1; go++;}
    }
    else if(da<1){
         mj--; da=b_d[mj-1];
        if(mj<1){ mj=12; go--; da=b_d[mj-1];}
    }
    return std::make_tuple(da, mj, go);
}

void Pregled::PomjeriDanUnaprijed(){
    auto t(this->dat.Ocitaj());
    auto t1(Pregled::KorigujDatum(std::get<0>(t)++, std::get<1>(t), std::get<2>(t)));
    this->dat.Postavi(std::get<0>(t1), std::get<1>(t1), std::get<2>(t1));
}

void Pregled::PomjeriDanUnazad(){
    auto t(this->dat.Ocitaj());
    auto t1(Pregled::KorigujDatum(std::get<0>(t)--, std::get<1>(t), std::get<2>(t)));
    this->dat.Postavi(std::get<0>(t1), std::get<1>(t1), std::get<2>(t1));
}

bool Pregled::DolaziPrije(const Pregled &p1, const Pregled &p2){
    auto t1(p1.dat.Ocitaj()); auto t2(p2.dat.Ocitaj());
    if(std::get<2>(t1)<std::get<2>(t2)) return true;
    else if(std::get<1>(t1)<std::get<1>(t2) && std::get<2>(t1)==std::get<2>(t2))
        return true;
    else if(std::get<0>(t1)<std::get<0>(t2) && std::get<2>(t1)==std::get<2>(t2) && std::get<1>(t1)==std::get<1>(t2))
        return true; 
    else if(std::get<0>(t1)==std::get<0>(t2) && std::get<2>(t1)==std::get<2>(t2) && std::get<1>(t1)==std::get<1>(t2)){
        auto par1(p1.tajm.Ocitaj()); auto par2(p2.tajm.Ocitaj());
        if(par1.first<par2.first)
            return true; 
        else if(par1.first==par2.first && par1.second<par2.second)
            return true; 
    } 
    return false;
}

class Pregledi{
    int evidentirani, velicina_niza;
    Pregled **pok;
    public:
    explicit Pregledi(int max_broj_pregleda): evidentirani(0), velicina_niza(max_broj_pregleda),
                     pok(new Pregled*[max_broj_pregleda]{})  {}
    Pregledi(std::initializer_list<Pregled> spisak_pregleda): evidentirani(spisak_pregleda.size()), velicina_niza(spisak_pregleda.size()),
             pok(new Pregled*[evidentirani]) {
                 try{
                 auto it(spisak_pregleda.begin());
                 for(int i=0; i<velicina_niza; i++){
                     pok[i]=new Pregled(it->DajImePacijenta(), it->DajDatumPregleda(), it->DajVrijemePregleda());
                     it++;
                 }}
                 catch(...){
                     throw;
                 }
    }
    ~Pregledi(){
        if(pok!=nullptr)
        for(int i=0; i<evidentirani; i++)
            delete pok[i];
        delete [] pok;   
    }
    Pregledi(const Pregledi &pregledi);
    Pregledi(Pregledi &&pregledi);
    Pregledi &operator =(const Pregledi &pregledi);
    Pregledi &operator =(Pregledi &&pregledi);
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);                 
    void RegistrirajPregled(Pregled *pregled);
    int DajBrojPregleda() const {
        if(evidentirani==0)
            throw std::domain_error("Nema registriranih pregleda");
        return evidentirani;}
    int DajBrojPregledaNaDatum(const Datum &datum) const{
        if(evidentirani==0)
            throw std::domain_error("Nema registriranih pregleda");
        auto n(datum.Ocitaj());    
        return std::count_if(pok, pok+evidentirani, [n](Pregled *p){
            auto t(p->DajDatumPregleda().Ocitaj());
            return (std::get<0>(t)==std::get<0>(n) && std::get<1>(t)==std::get<1>(n) && std::get<2>(t)==std::get<2>(n));
        });    
    }
    Pregled &DajNajranijiPregled(){
        if(evidentirani==0)
            throw std::domain_error("Nema registriranih pregleda");
        return **std::min_element(pok, pok+evidentirani, [](Pregled *p1, Pregled *p2){
            return Pregled::DolaziPrije(*p1, *p2);
        });    
    }
    Pregled DajNajranijiPregled() const{
        if(evidentirani==0)
            throw std::domain_error("Nema registriranih pregleda");
        return **std::min_element(pok, pok+evidentirani, [](Pregled *p1, Pregled *p2){
            return Pregled::DolaziPrije(*p1, *p2);
        });    
    }
    void IsprazniKolekciju(){
        if(evidentirani==0)
            throw std::range_error("Prazna kolekcija");
        for(int i=0; i<evidentirani; i++)
            {delete pok[i]; pok[i]=nullptr;}
    }
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta){
        auto it(pok[0]);
        for(int i=0; i<evidentirani; i++){
            if(it->DajImePacijenta()==ime_pacijenta){
                delete pok[i]; pok[i]=pok[evidentirani-1]; evidentirani--;
            }
            it=pok[i+1];
        }
    }
    void IspisiPregledeNaDatum(const Datum &datum) const;
    void IspisiSvePreglede() const;
};

void Pregledi::ObrisiNajranijiPregled(){
        if(evidentirani==0)
            throw std::range_error("Prazna kolekcija");
        auto p(DajNajranijiPregled());
         auto p1(pok[0]);
        for(int i=0; i<evidentirani; i++){
            if(p.DajImePacijenta()==p1->DajImePacijenta()){
                   auto t1(p.DajDatumPregleda().Ocitaj()); auto t2(p1->DajDatumPregleda().Ocitaj());
                   if(std::get<0>(t1)==std::get<0>(t2) && std::get<1>(t1)==std::get<1>(t2) && std::get<2>(t1)==std::get<2>(t2)){
                       auto v1(p.DajVrijemePregleda().Ocitaj()); auto v2(p1->DajVrijemePregleda().Ocitaj());
                       if(v1.first==v2.first && v1.second==v2.second)
                           {delete pok[i]; pok[i]=pok[evidentirani-1]; evidentirani--; break;}
                   }
               }
            p1=pok[i+1];
        }
    }

Pregledi::Pregledi(const Pregledi &pregledi){
    try{
        pok=new Pregled*[pregledi.velicina_niza]{};
        velicina_niza=pregledi.velicina_niza; evidentirani=pregledi.evidentirani;
        for(int i=0; i<evidentirani; i++)
            pok[i]=new Pregled(pregledi.pok[i]->DajImePacijenta(), pregledi.pok[i]->DajDatumPregleda(), pregledi.pok[i]->DajVrijemePregleda());
    }
    catch(...){
        throw;
    }
}

Pregledi::Pregledi(Pregledi &&pregledi){
    pok=pregledi.pok; pregledi.pok=nullptr;
    velicina_niza=pregledi.velicina_niza; evidentirani=pregledi.evidentirani;
}

Pregledi &Pregledi::operator =(const Pregledi &pregledi){
    if(velicina_niza<pregledi.velicina_niza){
           for(int i=0; i<evidentirani; i++)
            {delete pok[i]; pok[i]=nullptr;}
        delete [] pok; 
        pok=new Pregled*[pregledi.velicina_niza]{};
        for(int i=0; i<pregledi.evidentirani; i++)
            pok[i]=new Pregled(pregledi.pok[i]->DajImePacijenta(), pregledi.pok[i]->DajDatumPregleda(), pregledi.pok[i]->DajVrijemePregleda());
    }
    else
       std::copy(pregledi.pok, pregledi.pok+pregledi.velicina_niza, pok); 
    velicina_niza=pregledi.velicina_niza; evidentirani=pregledi.evidentirani;
    return *this;
}

Pregledi &Pregledi::operator =(Pregledi &&pregledi){
    for(int i=0; i<evidentirani; i++)
            {delete pok[i]; pok[i]=nullptr;}
    delete [] pok; 
    pok=pregledi.pok; pregledi.pok=nullptr; 
    velicina_niza=pregledi.velicina_niza; evidentirani=pregledi.evidentirani;
    return *this;
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda){
    if(evidentirani==velicina_niza)
        throw std::range_error("Dostignut maksimalni broj pregleda");
    pok[evidentirani++]=new Pregled(ime_pacijenta, datum_pregleda, vrijeme_pregleda);
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda){
    if(evidentirani==velicina_niza)
        throw std::range_error("Dostignut maksimalni broj pregleda");
    pok[evidentirani++]=new Pregled(ime_pacijenta, dan_pregleda, mjesec_pregleda, 
                      godina_pregleda, sati_pregleda, minute_pregleda);
}

void Pregledi::RegistrirajPregled(Pregled *pregled){
    if(evidentirani==velicina_niza)
        throw std::range_error("Dostignut maksimalni broj pregleda");
    pok[evidentirani++]=pregled; pregled=nullptr;    
}

void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const{
    std::vector<Pregled> v; 
    auto it(pok[0]); auto dat(datum.Ocitaj());
    for(int i=0; i<evidentirani; i++){
        auto t(it->DajDatumPregleda().Ocitaj());
        if(std::get<0>(t)==std::get<0>(dat) && std::get<1>(t)==std::get<1>(dat) 
           && std::get<2>(t)==std::get<2>(dat))
            v.push_back(*it);
        it=pok[i+1];    
    }       
    std::sort(v.begin(), v.end(), [](Pregled p1, Pregled p2){
        auto t1(p1.DajVrijemePregleda().Ocitaj()); auto t2(p2.DajVrijemePregleda().Ocitaj());   
        if(t1.first<t2.first)
            return true;
        else if(t1.first==t2.first && t1.second<t2.second)
            return true;
        return false;    
    });       
    for(int i=0; i<v.size(); i++)
        v.at(i).Ispisi();
}

void Pregledi::IspisiSvePreglede() const{
    std::vector<Pregled> v;
    std::for_each(pok, pok+evidentirani, [&v](Pregled *p){
            v.push_back(*p); 
    });
    std::sort(v.begin(), v.end(), [](Pregled p1, Pregled p2){
            return Pregled::DolaziPrije(p1, p2);
    });
    std::for_each(v.begin(), v.end(), [](Pregled p){
            p.Ispisi(); 
    });
}

int main(){
    std::cout << "Unesite maksimalan broj pregleda: ";
    int bp;
    std::cin >> bp;
    Pregledi pregledi(bp); int evid(0);
    for(int i=0; i<bp; i++){
        std::cin.ignore(1000, '\n');
        std::cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        std::string s;
        std::getline(std::cin, s);
        if(s=="kraj") break;
        std::cout << "Unesite dan mjesec i godinu pregleda: ";
        int d, m, g;
        std::cin >> d >> m >> g;
        std::cout << "Unesite sate i minute pregleda: ";
        int h, min;
        std::cin >> h >> min;
        pregledi.RegistrirajPregled(s, d, m, g, h, min);
        evid++;
    }
    std::cout << "Trenutno su registrovani sljedeci pregledi\n";
    pregledi.IspisiSvePreglede();
    int kraj(1); while(kraj){
    std::cout << "\nOdaberite jednu od sljedecih opcija \n"
              << "1 - Broj pregleda na datum\n"
              << "2 - Najraniji pregled\n"
              << "3 - Obrisi pregled pacijenta\n"
              << "4 - Obrisi najraniji pregled\n"
              << "5 - Ispisi sve pregleda na datum\n"
              << "6 - Ispisi sve preglede\n"
              << "7 - Kraj programa\n";
    int opcija;
    std::cin >> opcija; int dan, mjes, god;
    switch (opcija){
        case 1:{
        std::cout << "Unesite dan mjesec i godinu : ";
        std::cin >> dan >> mjes >> god;
        Datum dat(dan, mjes, god);
        std::cout << "Broj pregleda na datum " << dan << " " << mjes << " " 
                 << god << " je: " << pregledi.DajBrojPregledaNaDatum(dat) << std::endl;
        break;}
        
        case 2:
        std::cout << "Najraniji pregled je:\n";
        pregledi.DajNajranijiPregled().Ispisi();
        break;
        
        case 3:{
        std::string imeee;
        std::cout << "Unesite ime pacijenta: ";
        std::cin.ignore(1000, '\n'); std::getline(std::cin, imeee);
        pregledi.ObrisiPregledePacijenta(imeee); 
        std::cout << "Uspjesno obrisano " << evid-pregledi.DajBrojPregleda() << " pregleda\n";
        break;}
        
        case 4:
        pregledi.ObrisiNajranijiPregled();
        std::cout << "Najraniji pregled uspjesno obrisan\n";
        break;
        
        case 5:{
        std::cout << "Unesite dan mjesec i godinu : ";
        std::cin >> dan >> mjes >> god;
        std::cout << "Pregledi na datum " << dan << " " << mjes << " " << god << " su:\n";
        Datum dat(dan, mjes, god);
        pregledi.IspisiPregledeNaDatum(dat);
        break;}
        
        case 6:
        pregledi.IspisiSvePreglede();
        break;
        
        case 7:
        kraj=0;
    }}
    
    return 0;
}