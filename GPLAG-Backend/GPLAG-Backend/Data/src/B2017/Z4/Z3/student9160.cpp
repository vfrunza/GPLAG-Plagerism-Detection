/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <tuple>
#include <iomanip>
#include <string>
#include <algorithm>
class Datum{
    int dan,mjesec,godina;
    public:
    Datum(int dan, int mjesec, int godina){ Postavi(dan,mjesec,godina); }
    void Postavi(int dan, int mjesec, int godina);
    std::tuple<int,int,int> Ocitaj() const;
    void Ispisi() const;
    friend class Pregled;
};
void Datum::Postavi(int dan, int mjesec, int godina){
    int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if((godina%4 == 0 && godina%100 == 0) || godina%400 == 0)broj_dana[1]++;
    if(godina<1 || mjesec<1 || dan<1 || dan>broj_dana[mjesec-1] || mjesec>12)
        throw std::domain_error("Neispravan datum");
    Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina;    
}
std::tuple<int,int,int> Datum::Ocitaj() const {
    return std::make_tuple(dan,mjesec,godina);
}
void Datum::Ispisi() const {
    std::cout<<dan<<"/"<<mjesec<<"/"<<godina;
}

class Vrijeme{
    int sati,minute;
    public:
    Vrijeme(int sati, int minute){ Postavi(sati,minute); }
    void Postavi(int sati, int minute);
    std::pair<int,int> Ocitaj() const;
    void Ispisi() const;
    friend class Pregled;
};
void Vrijeme::Postavi(int sati,int minute){
    if(sati<0 || sati>23 || minute<0 || minute>59)
        throw std::domain_error("Neispravno vrijeme");
    Vrijeme::sati = sati; Vrijeme::minute = minute;    
}
std::pair<int,int> Vrijeme::Ocitaj() const {
    return std::make_pair(sati,minute);
}
void Vrijeme::Ispisi() const {
    std::cout<<std::setw(2)<<std::setfill('0')<<sati<<":"
             <<std::setw(2)<<std::setfill('0')<<minute;
}

class Pregled{
    std::string ime_pacijenta;
    Datum dan_pregleda;
    Vrijeme vrijeme_pregleda;
    
    public:
    
    Pregled(const std::string &ime, const Datum &datum, const Vrijeme &vrijeme);//done
    Pregled(const std::string &ime,int dan,int mjesec,int godina,int sati,int minute);//done
    void PromijeniPacijenta(const std::string &ime);//done
    void PromijenuDatum(const Datum &date);//done
    void PromijeniVrijeme(const Vrijeme &vrijeme);//done
    void PomjeriDanUnaprijed();//done
    void PomjeriDanUnazad();//done
    std::string DajImePacijenta() const { return ime_pacijenta; };//done
    Datum DajDatum() const { return dan_pregleda; }//done
    Vrijeme DajVrijeme() const { return vrijeme_pregleda; }//done
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
    void Ispisi() const {
        std::cout<<std::setw(30)<<std::setfill(' ')<<std::left<<DajImePacijenta();
        dan_pregleda.Ispisi();
        std::cout<<" "; vrijeme_pregleda.Ispisi();
        std::cout<<std::endl;
    }
    friend bool operator == (Pregled p1, Pregled p2){
        bool bIme( p1.ime_pacijenta == p2.ime_pacijenta);
        auto d1(p1.DajDatum().Ocitaj());
        auto d2(p2.DajDatum().Ocitaj());
        bool bDatum( std::get<0>(d1) == std::get<0>(d2) 
        && std::get<1>(d1) == std::get<1>(d2)
        && std::get<2>(d1) == std::get<2>(d2));
        auto v1(p1.DajVrijeme().Ocitaj());
        auto v2(p2.DajVrijeme().Ocitaj());
        bool bVrijeme(std::get<0>(v1) == std::get<0>(v2) 
                   && std::get<1>(v1) == std::get<1>(v2) );
        return bIme && bDatum && bVrijeme;           
    }
    
};
void Pregled::PromijeniPacijenta(const std::string &ime){
    ime_pacijenta = ime;
}
void Pregled::PromijenuDatum(const Datum &date){
    dan_pregleda = date;
}
void Pregled::PromijeniVrijeme(const Vrijeme &vrijeme){
    vrijeme_pregleda = vrijeme;
}
Pregled::Pregled(const std::string &ime, const Datum &datum, const Vrijeme &vrijeme):
ime_pacijenta(ime), dan_pregleda(datum), vrijeme_pregleda(vrijeme){}
Pregled::Pregled(const std::string &ime,int dan,int mjesec,int godina,int sati,int minute):
ime_pacijenta(ime), dan_pregleda(dan,mjesec,godina), vrijeme_pregleda(sati,minute){}
void Pregled::PomjeriDanUnazad(){
    int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    auto temp = dan_pregleda.Ocitaj();
    if((std::get<2>(temp)%4 == 0 && std::get<2>(temp)%100 == 0) || std::get<2>(temp)%400 == 0)broj_dana[1]++;
    if(std::get<0>(temp)==1){
        if(std::get<1>(temp)==1){
            std::get<1>(temp)=12;
            std::get<2>(temp)--;
        }else std::get<1>(temp)--;
        std::get<0>(temp) = broj_dana[std::get<1>(temp)-1];
    }else std::get<0>(temp)--;
    dan_pregleda.Postavi(std::get<0>(temp),std::get<1>(temp),std::get<2>(temp));
}
void Pregled::PomjeriDanUnaprijed(){
    int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    auto temp = dan_pregleda.Ocitaj();
    int d(std::get<0>(temp)),m(std::get<1>(temp)),g(std::get<0>(temp));
    if((g%4 == 0 && g%100 == 0) || g%400 == 0)broj_dana[1]++;
    
    if(d == broj_dana[m-1]){
        d=1; m++;
        if(m==13){ m=1;g++; }
    }
    dan_pregleda.Postavi(d,m,g);
}
bool DolaziPrije(const Pregled &p1, const Pregled &p2){
    auto dan1(p1.DajDatum().Ocitaj());
    auto dan2(p2.DajDatum().Ocitaj());
    if(std::get<2>(dan1) < std::get<2>(dan2))return true;
    else if(std::get<2>(dan1) == std::get<2>(dan2)){
        if(std::get<1>(dan1) < std::get<1>(dan2))return true;
        else if(std::get<1>(dan1) == std::get<1>(dan2)){
            if(std::get<0>(dan1) < std::get<0>(dan2))return true;
            else if(std::get<0>(dan1) == std::get<0>(dan2)){
                auto v1(p1.DajVrijeme().Ocitaj());
                auto v2(p2.DajVrijeme().Ocitaj());
                if(v1.first < v2.first)return true;
                else if(v1.first == v2.first){
                    if(v1.second < v2.second)return true;
                    else return false;
                }
            }
        }
    }
    return false;
}

class Pregledi{
    const int max_pregledi;
    mutable int broj_pregleda;
    Pregled **pregledi;
    
    public:
    
    explicit Pregledi(int max_pregleda);//done
    Pregledi(std::initializer_list<Pregled> spisak_pregleda);//done
    ~Pregledi();// done
    Pregledi(const Pregledi &p);//done
    Pregledi(Pregledi &&p);//done
    Pregledi &operator = (const Pregledi &p);//done
    Pregledi &operator = (Pregledi &&p);//done
    void RegistrirajPregled(const std::string &ime, const Datum &d, const Vrijeme &v);
    void RegistrirajPregled(const std::string &ime, int d, int m, int g, int h, int min);
    void RegistrirajPregled(Pregled *p);
    int DajMaxBrojPregleda() const { return max_pregledi; }
    int DajBrojPregleda() const{ return broj_pregleda; };//done
    int DajBrojPregledaNaDatum(const Datum &d) const;//done
    Pregled &DajNajranijiPregled();//done
    Pregled DajNajranijiPregled() const;//done
    void IsprazniKolekciju();//done
    void ObrisiNajranijiPregled();//done
    void ObrisiPregledePacijenta(const std::string &ime);//done
    void IspisiPregledeNaDatum(const Datum &d) const;// done
    void IspisiSvePreglede() const;//done
};

Pregledi::Pregledi(int max_pregleda):max_pregledi(max_pregleda),broj_pregleda(0){
    pregledi = new Pregled*[max_pregleda];
    for(int i(0);i<max_pregleda;i++)pregledi[i] = nullptr;
}

Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda):
max_pregledi(spisak_pregleda.size()), broj_pregleda(spisak_pregleda.size()){
    pregledi = new Pregled*[spisak_pregleda.size()];
    auto it(spisak_pregleda.begin());
    for(int i(0);i<spisak_pregleda.size();i++){
        pregledi[i] = new Pregled(*it);
        it++;
    }
}

Pregledi::Pregledi(const Pregledi &p):max_pregledi(p.max_pregledi){
    broj_pregleda = p.broj_pregleda;
    pregledi = new Pregled*[p.max_pregledi];
    for(int i(0);i<p.DajBrojPregleda();i++)
        pregledi[i] = new Pregled(*p.pregledi[i]);
}

Pregledi &Pregledi::operator = (const Pregledi &p){
    // radi sve sta adi destruktor
    if(max_pregledi != p.max_pregledi)
        throw std::domain_error("Nesaglasni max_pregledi");
    if(&p == this) return *this;
    for(int i(0);i<DajBrojPregleda();i++)
        delete pregledi[i];
    delete [] pregledi;
    // radi sve sta radi kopirajuci konstuktor
    pregledi = new Pregled*[p.max_pregledi];
    for(int i(0);i<p.DajBrojPregleda();i++)
        pregledi[i] = new Pregled(*p.pregledi[i]);
    return *this;
}

Pregledi &Pregledi::operator =(Pregledi &&p){
    if(max_pregledi != p.max_pregledi)
        throw std::domain_error("Nesaglasni max_pregledi");
    std::swap(pregledi,p.pregledi);
    std::swap(broj_pregleda,p.broj_pregleda);
    return *this;
}

Pregledi::Pregledi(Pregledi &&p):max_pregledi(p.max_pregledi),broj_pregleda(p.broj_pregleda){
    std::swap(pregledi,p.pregledi);
}

Pregledi::~Pregledi(){
    for(int i(0);i<broj_pregleda;i++)
        delete pregledi[i];
    delete [] pregledi;    
}

void Pregledi::RegistrirajPregled(const std::string &ime, const Datum &d, const Vrijeme &v){
    if(broj_pregleda == max_pregledi)
        throw std::range_error("Dostignut maksimalni broj pregleda");
    pregledi[broj_pregleda] = new Pregled(ime,d,v);  
    broj_pregleda++;
}

void Pregledi::RegistrirajPregled(const std::string &ime, int d, int m, int g, int h, int min){
    if(broj_pregleda == max_pregledi)
        throw std::range_error("Dostignut maksimalni broj pregleda");
        try{
            pregledi[broj_pregleda] = new Pregled(ime,d,m,g,h,min);
        } catch(...){
            std::cout<<"Problemi s memorijom";
        }
    broj_pregleda++;
}

void Pregledi::RegistrirajPregled(Pregled *p){
    if(broj_pregleda == max_pregledi)
        throw std::range_error("Dostignut maksimalni broj pregleda");
        
    pregledi[broj_pregleda] = new Pregled(*p);    
    broj_pregleda++;
}

int Pregledi::DajBrojPregledaNaDatum(const Datum &d) const {
    return std::count_if(pregledi, pregledi + broj_pregleda, [d](Pregled *p){
        Datum dat(p->DajDatum());
        auto d1 = d.Ocitaj();
        auto d2 = dat.Ocitaj();
        if(std::get<0>(d1) == std::get<0>(d2) 
        && std::get<1>(d1) == std::get<1>(d2)
        && std::get<2>(d1) == std::get<2>(d2))
            return true;
        return false;    
    });
}

Pregled Pregledi::DajNajranijiPregled() const{
    auto p = std::min_element(pregledi,pregledi+broj_pregleda,
        [](Pregled *p1,Pregled *p2){
            auto d1 = p1->DajDatum().Ocitaj();
            auto d2 = p2->DajDatum().Ocitaj();
            if(std::get<2>(d1) < std::get<2>(d2))return true;
            else if(std::get<2>(d1) == std::get<2>(d2)){
                if(std::get<1>(d1) < std::get<1>(d2))return true;
                else if(std::get<1>(d1) == std::get<1>(d2)){
                    if(std::get<0>(d1) < std::get<0>(d2))return true;
                }
            }
        return false;
    });
    if(*p == nullptr) throw std::domain_error("Nema registriranih pregleda");
    return **p;
}

Pregled &Pregledi::DajNajranijiPregled(){
    auto p = std::min_element(pregledi,pregledi+broj_pregleda,
        [](Pregled *p1,Pregled *p2){
            auto d1 = p1->DajDatum().Ocitaj();
            auto d2 = p2->DajDatum().Ocitaj();
            if(std::get<2>(d1) < std::get<2>(d2))return true;
            else if(std::get<2>(d1) == std::get<2>(d2)){
                if(std::get<1>(d1) < std::get<1>(d2))return true;
                else if(std::get<1>(d1) == std::get<1>(d2)){
                    if(std::get<0>(d1) < std::get<0>(d2))return true;
            }
        }
        return false;
    });
    if(*p == nullptr) throw std::domain_error("Nema registriranih pregleda");
    return **p;
}

void Pregledi::IsprazniKolekciju() {
    for(int i(0);i<broj_pregleda;i++)delete pregledi[i];
    delete [] pregledi;
    pregledi = nullptr;
}

void Pregledi::ObrisiNajranijiPregled () {
    try{
        Pregled p = DajNajranijiPregled();
        int index(0);
        for(int i(0);i<broj_pregleda;i++){
            if(*pregledi[i] == p){
                index = i;
                break;
            }
        }
        for(int i(index);i<broj_pregleda-1;i++)
            pregledi[i] = pregledi[i+1];
        delete pregledi[broj_pregleda-1];
        broj_pregleda--;
    } catch (std::domain_error){
        throw std::range_error("Prazna kolekcija");
    }
}

void Pregledi::ObrisiPregledePacijenta(const std::string &ime){
    for(int i(0);i<broj_pregleda;i++){
        if(ime == pregledi[i]->DajImePacijenta()){
            for(int j(i);j<broj_pregleda-1;j++)
                pregledi[j] = pregledi[j+1];
            delete pregledi[broj_pregleda-1];
            broj_pregleda--;
        }
    }
}

void Pregledi::IspisiPregledeNaDatum(const Datum &d) const {
    std::sort(pregledi,pregledi+broj_pregleda,
        [](Pregled *p1, Pregled *p2){
            return DolaziPrije(*p1,*p2);
    });
    for(int i(0);i<broj_pregleda;i++){
        Datum dat(pregledi[i]->DajDatum());
        auto d1 = d.Ocitaj();
        auto d2 = dat.Ocitaj();
        if(std::get<0>(d1) == std::get<0>(d2) 
        && std::get<1>(d1) == std::get<1>(d2)
        && std::get<2>(d1) == std::get<2>(d2))
            pregledi[i]->Ispisi();
    }
}

void Pregledi::IspisiSvePreglede () const {
    std::sort(pregledi,pregledi+broj_pregleda,
        [](Pregled *p1, Pregled *p2){
            return DolaziPrije(*p1,*p2);
    });
    for(int i(0);i<broj_pregleda;i++)
        pregledi[i] -> Ispisi();
}

int main ()
{
    
    std::cout<<"Unesite maksimalan broj pregleda: ";
    int n;
    std::cin>>n;
    Pregledi pregledi(n);
    while(1){
        std::cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        std::string ime;
        std::cin.ignore(1000,'\n');
        std::getline(std::cin, ime);
        if(ime == "kraj")break;
        std::cout<<"Unesite dan mjesec i godinu pregleda: ";
        int d,m,g;
        std::cin>>d>>m>>g;
        std::cout<<"Unesite sate i minute pregleda: ";
        int h,min;
        std::cin>>h>>min;
        pregledi.RegistrirajPregled(ime,d,m,g,h,min);
        if(pregledi.DajBrojPregleda() == pregledi.DajMaxBrojPregleda())break;
    }
    std::cout<<"Trenutno su registrovani sljedeci pregledi"<<std::endl;
    pregledi.IspisiSvePreglede();
    
    while(1){
        int opcija;
        std::cout<<std::endl;
        std::cout<<"Odaberite jednu od sljedecih opcija"<<std::endl;
        std::cout<<"1 - Broj pregleda na datum"<<std::endl;
        std::cout<<"2 - Najraniji pregled"<<std::endl;
        std::cout<<"3 - Obrisi pregled pacijenta"<<std::endl;
        std::cout<<"4 - Obrisi najraniji pregled"<<std::endl;
        std::cout<<"5 - Ispisi sve pregleda na datum"<<std::endl;
        std::cout<<"6 - Ispisi sve preglede"<<std::endl;
        std::cout<<"7 - Kraj programa"<<std::endl;
        std::cout<<std::endl;
        std::cin>>opcija;
        
        if(opcija == 1){
                std::cout<<"Unesite dan mjesec i godinu : ";
                int d1,m1,g1;
                std::cin>>d1>>m1>>g1;
                Datum d(d1,m1,g1);
                int bd(pregledi.DajBrojPregledaNaDatum(d));
                std::cout<<"Broj pregleda na datum "<<d1<<" "<<m1<<" "<<g1<<" je: "<<bd;
        }
        if(opcija == 2){
            std::cout<<"Najraniji pregled je:"<<std::endl;
            Pregled p(pregledi.DajNajranijiPregled());
            p.Ispisi();
        }
        if(opcija == 3){
            // obrisi pregled pacijenta
            int n1(pregledi.DajBrojPregleda());
            std::cout<<"Unesite ime pacijenta: ";
            std::string ime_pacijenta;
            std::cin.ignore(1,'\n');
            std::getline(std::cin,ime_pacijenta);
            pregledi.ObrisiPregledePacijenta(ime_pacijenta);
            std::cout<<"Uspjensno obrisano "<<n1-pregledi.DajBrojPregleda()<<" pregleda";
        }
        if(opcija == 4){
            try{
                pregledi.ObrisiNajranijiPregled();
            }catch(std::range_error e){
                std::cout<< e.what()<<std::endl;
            }
            std::cout<<"Najraniji pregled uspjesno obrisan"<<std::endl;
        }
        if(opcija == 5){
            std::cout<<"Unesite dan mjesec i godinu: ";
            int d1,m1,g1;
            std::cin>>d1>>m1>>g1;
            Datum d(d1,m1,g1);
            std::cout<<"Pregledi na datum "<<d1<<" "<<m1<<" "<<g1<<" su:"<<std::endl;
            pregledi.IspisiPregledeNaDatum(d);
        }
        if(opcija == 6) pregledi.IspisiSvePreglede();
        if(opcija == 7) return 0;
    }
	return 0;
}
