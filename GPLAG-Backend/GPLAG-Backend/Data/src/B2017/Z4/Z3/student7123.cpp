#include <iostream>
#include <stdexcept>
#include <tuple>
#include <string>
#include <iomanip>
#include <initializer_list>
#include <iterator>
#include <algorithm>

class Datum{
    int dan,mjesec,godina;
    static void TestirajDatum(int d, int m, int g){
        int broj_dana[]{31,28,31,30,31,30,31,31,30,31,30,31};
        if((g%4==0 && g%100!=0) || g%400==0) broj_dana[1]++;
        if(g<1 || m<1 || m>12 || d<1 || d>broj_dana[m-1]) throw std::domain_error("Nesipravan datum");
    }
    public:
    Datum(int dan, int mjesec, int godina);
    void Postavi(int dan, int mjesec, int godina);
    std::tuple<int, int, int> Ocitaj() const{ return std::make_tuple(dan,mjesec,godina);}
    void Ispisi() const{ std::cout<<dan<<"/"<<mjesec<<"/"<<godina;}
};

Datum::Datum(int dan, int mjesec, int godina){
    TestirajDatum(dan,mjesec,godina);
    this->dan=dan;
    this->mjesec=mjesec;
    this->godina=godina;
}

void Datum::Postavi(int dan, int mjesec, int godina){
    TestirajDatum(dan,mjesec,godina);
    this->dan=dan;
    this->mjesec=mjesec;
    this->godina=godina;
}

class Vrijeme{
    int sati,minute;
    static void TestirajVrijeme(int s, int m){
        if(s<0 || s>23 || m<0 || m>59) throw std::domain_error("Neispravno vrijeme");
    }
    void RegulisiVrijeme(){
        while(sati>24) sati-=24;
        while(minute>59) minute-=60;
    }
    public:
    Vrijeme(int sati, int minute){ TestirajVrijeme(sati,minute); this->sati=sati; this->minute=minute; RegulisiVrijeme();}
    void Postavi(int sati, int minute){ TestirajVrijeme(sati,minute); this->sati=sati; this->minute=minute; RegulisiVrijeme();}
    std::pair<int, int> Ocitaj () const{ return std::make_pair(sati,minute);}
    void Ispisi() const;
};

void Vrijeme::Ispisi() const{
    if(sati<10) std::cout<<"0"<<sati;
    else std::cout<<sati;
    std::cout<<":";
    if(minute<10) std::cout<<"0"<<minute;
    else std::cout<<minute;
    std::cout<<std::endl;
}

class Pregled{
    std::string ime;
    Datum datum;
    Vrijeme vrijeme;
    public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda,
    const Vrijeme &vrijeme_pregleda);
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,
    int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void PromijeniPacijenta(const std::string &ime_pacijenta){ ime=ime_pacijenta;}
    void PromijeniDatum(const Datum &novi_datum);
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme);
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImePacijenta() const{ return ime;}
    Datum DajDatumPregleda() const{ return datum;}
    Vrijeme DajVrijemePregleda() const{ return vrijeme;}
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
    void Ispisi() const;
};

Pregled::Pregled(const std::string &ime_pacijenta, const Datum &dan_pregleda, const Vrijeme &vrijeme_pregleda):datum(std::get<0>(dan_pregleda.Ocitaj()), std::get<1>(dan_pregleda.Ocitaj()), std::get<2>(dan_pregleda.Ocitaj())), 
vrijeme(std::get<0>(vrijeme_pregleda.Ocitaj()), std::get<1>(vrijeme_pregleda.Ocitaj())){
    ime=ime_pacijenta;
}

Pregled::Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,int godina_pregleda, int sati_pregleda, int minute_pregleda): datum(dan_pregleda,mjesec_pregleda,godina_pregleda), 
vrijeme(sati_pregleda,minute_pregleda){
        ime=ime_pacijenta;
}

void Pregled::PromijeniDatum(const Datum &novi_datum){
    datum.Postavi(std::get<0>(novi_datum.Ocitaj()), std::get<1>(novi_datum.Ocitaj()), std::get<2>(novi_datum.Ocitaj()));
}

void Pregled::PromijeniVrijeme(const Vrijeme &novo_vrijeme){
    vrijeme.Postavi(std::get<0>(novo_vrijeme.Ocitaj()), std::get<1>(novo_vrijeme.Ocitaj()));
}

void Pregled::PomjeriDanUnaprijed(){
    int dani[]{31,28,31,30,31,30,31,31,30,31,30,31};
    int d(std::get<0>(datum.Ocitaj())), m(std::get<1>(datum.Ocitaj())), g(std::get<2>(datum.Ocitaj()));
    if((g%4==0 && g%100!=0) || g%400==0) dani[1]++;
    d++;
    if(d > dani[m-1]){
        d-=dani[m-1];
        m++;
        if(m>12){
            g++;
            m-=12;
        }
    }
    datum.Postavi(d,m,g);
    
}

void Pregled::PomjeriDanUnazad(){
    int dani[]{31,28,31,30,31,30,31,31,30,31,30,31};
    int d,m,g;
    std::tie(d,m,g)=datum.Ocitaj();
    if((g%4==0 && g%100!=0) || g%400==0) dani[1]++;
    d--;
    if(d<=0){
        m--;
        if(m<=0){
            g--;
            m+=12;
            d+=dani[m-1];
        }
    }
    datum.Postavi(d,m,g);
}

bool Pregled::DolaziPrije(const Pregled &p1, const Pregled &p2){
    
    int d1,m1,g1,d2,m2,g2,s1,mi1,s2,mi2;
    std::tie(d1,m1,g1)=p1.DajDatumPregleda().Ocitaj();
    std::tie(d2,m2,g2)=p2.DajDatumPregleda().Ocitaj();
    std::tie(s1,mi1)=p1.DajVrijemePregleda().Ocitaj();
    std::tie(s2,mi2)=p2.DajVrijemePregleda().Ocitaj();
    if(g1<g2) return true;
    if(g1==g2){
        if(m1<m2) return true;
        if(m1==m2){
            if(d1<d2) return true;
            if(d1==d2){
                if(s1<s2) return true;
                if(s1==s2){
                    if(mi1<mi2) return true;
                    
                }
            }
        }
    }
    return false;

}

void Pregled::Ispisi() const{
    std::cout<<std::left<<std::setw(30)<<ime;
    datum.Ispisi();
    int d,m,g;
    std::tie(d,m,g)=datum.Ocitaj();
    std::cout<<" ";
    vrijeme.Ispisi();
}

class Pregledi{
    int kapacitet;
    int registrovanih;
    Pregled **p_n_p;    //POKAZIVAC NA PREGLEDE
    public:
    explicit Pregledi(int max_broj_pregleda):kapacitet(max_broj_pregleda), registrovanih(0), p_n_p(new Pregled*[kapacitet]{}){}
    Pregledi(std::initializer_list<Pregled> spisak_pregleda);
    ~Pregledi();
    Pregledi(const Pregledi &pregledi);
    Pregledi(Pregledi &&pregledi);
    Pregledi &operator =(const Pregledi &pregledi);
    Pregledi &operator =(Pregledi &&pregledi);
    void RegistrirajPregled(const std::string &ime_pacijenta,
        const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,
        int mjesec_pregleda, int godina_pregleda, int sati_pregleda,
        int minute_pregleda);
    void RegistrirajPregled(Pregled *pregled);
    int DajBrojPregleda() const{if(registrovanih==0) throw std::domain_error("Nema registriranih pregleda"); return registrovanih;}
    int DajBrojPregledaNaDatum(const Datum &datum) const;
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum(const Datum &datum) const;
    void IspisiSvePreglede() const;
};

Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda): kapacitet(spisak_pregleda.size()),registrovanih(0), p_n_p(new Pregled*[kapacitet]){
    auto *it(spisak_pregleda.begin());
    for(int i=0;i<kapacitet;i++) p_n_p[i]=nullptr;
    try{
        for(int i=0;i<spisak_pregleda.size();i++){
            p_n_p[i]=new Pregled(it->DajImePacijenta(), it->DajDatumPregleda(), it->DajVrijemePregleda());
            it++;
            registrovanih++;
        }
    }
    catch(...){
        for(int i=0;i<spisak_pregleda.size();i++){ 
            delete p_n_p[i];
            registrovanih--;
        }
        delete[] p_n_p;
    }
}

Pregledi::~Pregledi(){
    for(int i=0;i<registrovanih;i++){ 
        delete p_n_p[i];
    }
    delete[] p_n_p;
}

Pregledi::Pregledi (const Pregledi &pregledi): kapacitet(pregledi.kapacitet), registrovanih(pregledi.registrovanih), p_n_p(new Pregled*[kapacitet]{}){
    for(int i=0;i<kapacitet;i++) p_n_p[i]=nullptr;
    try{
        for(int i=0;i<registrovanih;i++) p_n_p[i]=new Pregled(pregledi.p_n_p[i]->DajImePacijenta(), pregledi.p_n_p[i]->DajDatumPregleda(), pregledi.p_n_p[i]->DajVrijemePregleda());
    }
    catch (std::bad_alloc){
        for(int i=0;i<kapacitet;i++) delete p_n_p[i];
        delete p_n_p;
        throw;
    }
}

Pregledi::Pregledi (Pregledi &&pregledi): kapacitet(pregledi.kapacitet), registrovanih(pregledi.registrovanih), p_n_p(pregledi.p_n_p){
    pregledi.p_n_p=nullptr;
}

Pregledi &Pregledi::operator=(const Pregledi &pregledi){
    Pregled **novi(new Pregled*[pregledi.kapacitet]);
    for(int i=0;i<pregledi.kapacitet;i++) novi[i]=nullptr;
    try{
        for(int i=0;i<pregledi.registrovanih;i++) novi[i]=new Pregled(pregledi.p_n_p[i]->DajImePacijenta(),pregledi.p_n_p[i]->DajDatumPregleda(),pregledi.p_n_p[i]->DajVrijemePregleda());
    }
    catch(std::bad_alloc){
        for(int j=0;j<pregledi.kapacitet;j++) delete novi[j];
        delete novi;
        throw;
    }
    for(int i=0;i<kapacitet;i++) delete p_n_p[i];
    delete[] p_n_p;
    kapacitet=pregledi.kapacitet;
    registrovanih=pregledi.registrovanih;
    p_n_p=novi;
    return *this;
}

Pregledi &Pregledi::operator =(Pregledi &&pregledi){
    for(int i=0;i<kapacitet;i++) delete p_n_p[i];
    delete[] p_n_p;
    kapacitet=pregledi.kapacitet;
    p_n_p=pregledi.p_n_p;
    pregledi.p_n_p=nullptr;
    registrovanih=pregledi.registrovanih;
    return *this;
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda){
    if(registrovanih==kapacitet) throw std::range_error("Dostignut maksimalni broj pregleda");
    for(int i=0;i<kapacitet;i++){
        if(p_n_p[i]==nullptr){
            try{
                p_n_p[i]=new Pregled(ime_pacijenta,datum_pregleda,vrijeme_pregleda);
            }
            catch(...){
                std::cout<<"Problemi sa memorijom";
            }
            registrovanih++;
            break;
        }
    }
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,
    int godina_pregleda, int sati_pregleda, int minute_pregleda){
        if(registrovanih==kapacitet) throw std::domain_error("Dostignut maksimalni broj pregleda");
        for(int i=0;i<kapacitet;i++){
            if(p_n_p[i]==nullptr){
                p_n_p[i]=new Pregled(ime_pacijenta,dan_pregleda,mjesec_pregleda,godina_pregleda,sati_pregleda,minute_pregleda);
                registrovanih++;
                break;
            }
        }
}

void Pregledi::RegistrirajPregled(Pregled *pregled){
    if(registrovanih==kapacitet) throw std::domain_error("Dostignut maksimalni broj pregleda");
    for(int i=0;i<kapacitet;i++){
        if(p_n_p[i]==nullptr){
            p_n_p[i]=new Pregled(*pregled);
            registrovanih++;
            break;
        }
    }
}



int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const{
    int brojac(0);
    if(registrovanih==0) throw std::domain_error("Nema registriranih pregleda");
    brojac=std::count_if(p_n_p, p_n_p+registrovanih, [&datum](Pregled *pregled){if(pregled==nullptr) return false; if(datum.Ocitaj() == pregled->DajDatumPregleda().Ocitaj()) return true; else return false;});
    return brojac;
}

Pregled &Pregledi::DajNajranijiPregled(){
   return **(std::min_element(p_n_p, p_n_p+registrovanih, [](Pregled *pregled, Pregled *pregled1){if(Pregled::DolaziPrije(*pregled,*pregled1)) return true; else return false;}));
}

Pregled Pregledi::DajNajranijiPregled() const {
   return **(std::min_element(p_n_p, p_n_p+registrovanih, [](Pregled *pregled, Pregled *pregled1){if(Pregled::DolaziPrije(*pregled,*pregled1)) return true; else return false;}));
}

void Pregledi::IsprazniKolekciju(){
    for(int i=0;i<kapacitet;i++){ 
        delete p_n_p[i];
        p_n_p[i]=nullptr;   //Zbog pokusaja dvostrukog brisanja 
    }
    registrovanih=0;
}

void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta){
    if(registrovanih==0) throw std::range_error("Prazna kolekcija");
    for(int i=0;i<registrovanih;i++){
        if(p_n_p[i]->DajImePacijenta()==ime_pacijenta){
            delete p_n_p[i];
            for(int j=i;j<registrovanih-1;j++){
                p_n_p[j]=p_n_p[j+1];
            }
            i--;
            registrovanih--;
        }
    }
}

void Pregledi::ObrisiNajranijiPregled(){
    if(registrovanih==0) throw std::range_error("Prazna kolekcija");
    Pregled *p1(&Pregledi::DajNajranijiPregled());
    for(int i=0;i<registrovanih;i++){
        if(p1==p_n_p[i]){
            delete p_n_p[i];
            for(int j=i;j<registrovanih-1;j++){
                p_n_p[j]=p_n_p[j+1];
            }
            i--;
            registrovanih--;
        }
    }
}

void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const{
    Pregled **novi(new Pregled* [kapacitet]);
    for(int i=0;i<kapacitet;i++) novi[i]=p_n_p[i];
    std::sort(novi, novi+registrovanih, [](Pregled *pregled, Pregled *pregled1){if(pregled==nullptr || pregled1==nullptr) return false; if(Pregled::DolaziPrije(*pregled,*pregled1)) return true; else return false;});
    for(int i=0;i<registrovanih;i++){
        if(novi[i]==nullptr) continue;
        if(datum.Ocitaj()==novi[i]->DajDatumPregleda().Ocitaj()) novi[i]->Ispisi();
    }
    delete[] novi;
}

void Pregledi::IspisiSvePreglede() const{
    Pregled **novi(new Pregled* [kapacitet]);
    for(int i=0;i<kapacitet;i++) novi[i]=p_n_p[i];
    std::sort(novi,novi+registrovanih, [](Pregled *pregled, Pregled *pregled1) {if(pregled==nullptr || pregled1==nullptr) return false; if(Pregled::DolaziPrije(*pregled,*pregled1)) return true; else return false;});
    for(int i=0;i<registrovanih;i++){
        if(novi[i]==nullptr) continue;
        novi[i]->Ispisi();
    }
    delete[] novi;
} 
int main ()
{   
    int max_br;
    std::cout<<"Unesite maksimalan broj pregleda: ";
    std::cin>>max_br;
    std::cin.ignore(1000,'\n');
    int i=0;
    Pregledi pr(max_br);
    while(i<max_br){

        std::cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        std::string ime;
        std::getline(std::cin,ime);
        std::string kraj("kraj");
        if(ime.compare(kraj)==0) break;
        int dan,mjesec,godina;
        std::cout<<"Unesite dan mjesec i godinu pregleda: ";
        std::cin>>dan;
        std::cin>>mjesec;
        std::cin>>godina;
        std::cin.get();
        Datum d(dan,mjesec,godina);
        std::cout<<"Unesite sate i minute pregleda: ";
        int sati, minute;
        std::cin>>sati;
        std::cin>>minute;
        Vrijeme v(sati,minute);
        Pregled p(ime,d,v);
        pr.RegistrirajPregled(&p);
        i++;
        std::cin.ignore(1000,'\n');
    }
    
    std::cout<<"Trenutno su registrovani sljedeci pregledi\n";
    pr.IspisiSvePreglede();
    std::cout<<std::endl;
    while(1){
        std::cout<<"Odaberite jednu od sljedecih opcija"<<std::endl;
        std::cout<<"1 - Broj pregleda na datum"<<std::endl;
        std::cout<<"2 - Najraniji pregled"<<std::endl;
        std::cout<<"3 - Obrisi pregled pacijenta"<<std::endl;
        std::cout<<"4 - Obrisi najraniji pregled"<<std::endl;
        std::cout<<"5 - Ispisi sve pregleda na datum"<<std::endl;
        std::cout<<"6 - Ispisi sve preglede"<<std::endl;
        std::cout<<"7 - Kraj programa"<<std::endl;
        int n;
        std::cin>>n;
        std::string ime;
        switch(n){
            case 1:
                std::cout<<"Unesite dan mjesec i godinu : ";
                int dan,mjesec,godina;
                std::cin>>dan>>mjesec>>godina;
                std::cout<<"Broj pregleda na datum "<<dan<<" "<<mjesec<<" "<<godina<<" je: "<<pr.DajBrojPregledaNaDatum({dan,mjesec,godina})<<std::endl;
                std::cout<<std::endl;
                break;
                
            case 2:
                std::cout<<"Najraniji pregled je:\n";
                pr.DajNajranijiPregled().Ispisi();
                std::cout<<std::endl;
                break;
                
            case 3:
                std::cout<<"Unesite ime pacijenta: ";
                std::cin.ignore(1000,'\n');
                std::getline(std::cin, ime);
                int prije, poslije;
                prije=pr.DajBrojPregleda();
                pr.ObrisiPregledePacijenta(ime);
                poslije=pr.DajBrojPregleda();
                std::cout<<"Uspjesno obrisano "<<prije-poslije<<" pregleda"<<std::endl;
                std::cout<<std::endl;
                break;
                
            case 4:
                prije=pr.DajBrojPregleda();
                pr.ObrisiNajranijiPregled();
                poslije=pr.DajBrojPregleda();
                if(prije!=poslije) std::cout<<"Najraniji pregled uspjesno obrisan"<<std::endl;
                std::cout<<std::endl;
                break;
                
            case 5:
                std::cout<<"Unesite dan mjesec i godinu : ";
                std::cin>>dan>>mjesec>>godina;
                std::cout<<"Pregledi na datum "<<dan<<" "<<mjesec<<" "<<godina<<" su:"<<std::endl;
                pr.IspisiPregledeNaDatum({dan,mjesec,godina});
                std::cout<<std::endl;
                break;
                
            case 6: 
                pr.IspisiSvePreglede();
                std::cout<<std::endl;
                break;
                
            case 7:
                return 0;
                
                
        }
    }
    
	return 0;
}
