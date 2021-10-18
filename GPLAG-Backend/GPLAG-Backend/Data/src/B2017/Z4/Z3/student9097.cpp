/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include<iomanip>
#include <stdexcept>
#include <tuple>
#include <string>
#include <utility>
#include <algorithm>
#include <new>
#include <vector>

class Datum{
    int d, m, g;
    public:
    Datum(int dan, int mjesec, int godina){Postavi(dan, mjesec, godina);}
    void Postavi(int dan, int mjesec, int godina);
    std::tuple<int, int, int> Ocitaj() const;
    void Ispisi() const;
};

void Datum::Postavi(int dan, int mjesec, int godina){
    int br_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina%4==0&&(godina%100!=0||godina%40==0)) br_dana[1]++;
    if(godina<1||dan<1||mjesec<1||mjesec>12||dan>br_dana[mjesec-1]) throw std::domain_error("Neispravan datum!");
    d=dan;
    m=mjesec;
    g=godina;
}
std::tuple<int, int, int> Datum::Ocitaj() const{return std::make_tuple(d,m,g);}
void Datum::Ispisi() const{std::cout<<d<<"/"<<m<<"/"<<g;}

class Vrijeme{
    int sati, minute;
    public:
    Vrijeme(int sati, int minute){Postavi(sati, minute);}
    void Postavi(int sati, int minute);
    std::pair<int, int> Ocitaj () const;
    void Ispisi() const;  
};

void Vrijeme::Postavi(int sati, int minute){
    if(sati>23||sati<0||minute<0||minute>59) throw std::domain_error("Neispravno vrijeme!");
    Vrijeme::sati=sati;
    Vrijeme::minute=minute;
}
std::pair<int, int> Vrijeme::Ocitaj() const{return std::make_pair(sati, minute);}
void Vrijeme::Ispisi() const{
    if(sati<10) std::cout<<"0"<<sati<<":";
    else std::cout<<sati<<":";
    if(minute<10) std::cout<<"0"<<minute;
    else std::cout<<minute;
}

class Pregled{
    std::string ime;
    Datum datum;
    Vrijeme vrijeme;
    public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda):
    datum(datum_pregleda), vrijeme(vrijeme_pregleda) {
        ime=ime_pacijenta; 
    }
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda):
    datum(dan_pregleda, mjesec_pregleda, godina_pregleda), vrijeme(sati_pregleda, minute_pregleda){
        ime=ime_pacijenta;
    }
    void PromijeniPacijenta(const std::string &ime_pacijenta){
        ime=ime_pacijenta;
    }
    void PromijeniDatum(const Datum &novi_datum){
        datum=novi_datum;
    }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme){
        vrijeme=novo_vrijeme;
    }
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImePacijenta() const{return ime;}
    Datum DajDatumPregleda() const{return datum;}
    Vrijeme DajVrijemePregleda() const{return vrijeme;}
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
    void Ispisi() const;  
};

void Pregled::Ispisi() const{
    std::string name=DajImePacijenta();
    std::cout<<std::left<<std::setw(30)<<name;
    datum.Ispisi();
    std::cout<<" ";
    vrijeme.Ispisi();
}

void Pregled::PomjeriDanUnazad(){
        int br_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int dan1(std::get<0>(datum.Ocitaj())), mjesec1(std::get<1>(datum.Ocitaj())), godina1(std::get<2>(datum.Ocitaj()));
        if(std::get<2>(datum.Ocitaj())%4==0&&(std::get<2>(datum.Ocitaj())%100!=0||std::get<2>(datum.Ocitaj())%40==0)) br_dana[1]++;
        if(std::get<0>(datum.Ocitaj())==1){
            mjesec1--;
            if(mjesec1<1){
                mjesec1=12;
                dan1=br_dana[mjesec1-1];
                godina1--;
            }
        }
        else dan1--;
        datum.Postavi(dan1, mjesec1, godina1);
}

void Pregled::PomjeriDanUnaprijed(){
    int br_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dan1(std::get<0>(datum.Ocitaj())), mjesec1(std::get<1>(datum.Ocitaj())), godina1(std::get<2>(datum.Ocitaj()));
    if(std::get<2>(datum.Ocitaj())%4==0&&(std::get<2>(datum.Ocitaj())%100!=0||std::get<2>(datum.Ocitaj())%40==0)) br_dana[1]++;
    dan1++;
    if(dan1>br_dana[mjesec1-1]){
        dan1=1;
        mjesec1++;
        if(mjesec1>12){
            mjesec1=1;
            godina1++;
        }
    }
    datum.Postavi(dan1, mjesec1, godina1);
}

bool Pregled::DolaziPrije(const Pregled &p1, const Pregled &p2){
        Datum prvi(p1.DajDatumPregleda()), drugi(p2.DajDatumPregleda());
        Vrijeme prvi_vr(p1.DajVrijemePregleda()), drugi_vr(p2.DajVrijemePregleda());
        int dan1(std::get<0>(prvi.Ocitaj())), mjesec1(std::get<1>(prvi.Ocitaj())), godina1(std::get<2>(prvi.Ocitaj()));
        int dan2(std::get<0>(drugi.Ocitaj())), mjesec2(std::get<1>(drugi.Ocitaj())), godina2(std::get<2>(drugi.Ocitaj()));
        int sati1(std::get<0>(prvi_vr.Ocitaj())), minute1(std::get<1>(prvi_vr.Ocitaj()));
        int sati2(std::get<0>(drugi_vr.Ocitaj())), minute2(std::get<1>(drugi_vr.Ocitaj()));
        if(godina1<godina2) return true;
        else if(godina1>godina2) return false;
        if(mjesec1<mjesec2) return true;
        else if(mjesec1>mjesec2) return false;
        if(dan1<dan2) return true;
        else if(dan1>dan2) return false;
        if(minute1<minute2) return true;
        else if(minute1>minute2) return false;
        if(sati1<sati2) return true;
        return false;
    }
    
class Pregledi{
    int max_br, trenutno;
    Pregled**p;
    public:
    explicit Pregledi(int max_broj_pregleda): max_br(max_broj_pregleda), trenutno(0), p(new Pregled*[max_broj_pregleda]){}
    Pregledi(std::initializer_list<Pregled> spisak_pregleda){
        trenutno=spisak_pregleda.size();
        p=new Pregled*[spisak_pregleda.size()];
        std::copy(spisak_pregleda.begin(), spisak_pregleda.end(), p[0]);
    }
    ~Pregledi();
    Pregledi(const Pregledi &pregledi):  max_br(pregledi.max_br), trenutno(pregledi.trenutno){
       auto p2=pregledi.p;
       p=new Pregled*[max_br];
       for(int i=0; i<trenutno; i++)
       *p[i]=*p2[i];
   }
    Pregledi(Pregledi &&pregledi)=default;
    Pregledi &operator =(const Pregledi &pregledi){
        trenutno=pregledi.trenutno;
        for(int i=0; i<trenutno; i++){
            p[i]=pregledi.p[i];
        }
        return *this;
    }
    Pregledi &operator =(Pregledi &&pregledi)=default;
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void RegistrirajPregled(Pregled *pregled);
    int DajBrojPregleda() const{return trenutno;}
    int DajBrojPregledaNaDatum(const Datum &datum) const;
    Pregled &DajNajranijiPregled(){
        if(trenutno==0) throw std::domain_error("Nema registriranih pregleda");
        auto pok=std::min_element(p[0], p[trenutno], [](Pregled p1, Pregled p2){
           if(std::get<2>((p1.DajDatumPregleda()).Ocitaj())>std::get<2>((p1.DajDatumPregleda()).Ocitaj())) return true;
           else if(std::get<0>((p1.DajDatumPregleda()).Ocitaj())<std::get<0>((p1.DajDatumPregleda()).Ocitaj())) return false;
           if(std::get<1>((p1.DajDatumPregleda()).Ocitaj())>std::get<1>((p1.DajDatumPregleda()).Ocitaj())) return true;
           else if(std::get<1>((p1.DajDatumPregleda()).Ocitaj())<std::get<1>((p1.DajDatumPregleda()).Ocitaj())) return false;
           if(std::get<0>((p1.DajDatumPregleda()).Ocitaj())>std::get<0>((p1.DajDatumPregleda()).Ocitaj())) return true;
           else if(std::get<0>((p1.DajDatumPregleda()).Ocitaj())<std::get<0>((p1.DajDatumPregleda()).Ocitaj())) return false;
            if(std::get<0>((p1.DajVrijemePregleda()).Ocitaj())>std::get<0>((p1.DajVrijemePregleda()).Ocitaj())) return true;
           else if(std::get<0>((p1.DajVrijemePregleda()).Ocitaj())<std::get<0>((p1.DajVrijemePregleda()).Ocitaj())) return false;
            if(std::get<1>((p1.DajVrijemePregleda()).Ocitaj())>std::get<1>((p1.DajVrijemePregleda()).Ocitaj())) return true;
           else if(std::get<1>((p1.DajVrijemePregleda()).Ocitaj())<std::get<1>((p1.DajVrijemePregleda()).Ocitaj())) return false;
           return false;
        });
        return *pok;
    }
    Pregled DajNajranijiPregled() const;
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum(const Datum &datum) const;
    void IspisiSvePreglede() const;
};

void Pregledi::ObrisiNajranijiPregled(){
    if(trenutno==0) throw std::range_error("Prazna kolekcija");
    Pregled pr=DajNajranijiPregled();
    int dan1(std::get<0>((pr.DajDatumPregleda()).Ocitaj())), mj1(std::get<1>((pr.DajDatumPregleda()).Ocitaj())), god1(std::get<2>((pr.DajDatumPregleda()).Ocitaj()));
    int sat1(std::get<0>((pr.DajVrijemePregleda()).Ocitaj())), min1(std::get<1>((pr.DajVrijemePregleda()).Ocitaj()));
    for(int i=0; i<trenutno; i++){
        if(p[i]==nullptr) continue;;
        int d(std::get<0>(((*p[i]).DajDatumPregleda()).Ocitaj())); int m(std::get<1>(((*p[i]).DajDatumPregleda()).Ocitaj())); int g(std::get<2>(((*p[i]).DajDatumPregleda()).Ocitaj()));
        int h(std::get<0>(((*p[i]).DajVrijemePregleda()).Ocitaj()));int min(std::get<1>(((*p[i]).DajVrijemePregleda()).Ocitaj())); 
        if(dan1==d&&mj1==m&&god1==g&&h==sat1&&min1==min){
            delete p[i];
            p[i]==nullptr;
            trenutno--;
        }
    }
}

void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta){
    for(int i=0; i<trenutno; i++){
        if(p[i]==nullptr) continue;
        if((*p[i]).DajImePacijenta()==ime_pacijenta){
            delete p[i];
            p[i]=nullptr;
            std::swap(p[i], p[trenutno-1]);
            trenutno--;
        }
    }
}

void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const{
    std::vector<Pregled> v;
    for(int i=0; i<trenutno; i++){
        if(p[i]!=nullptr){
       int d(std::get<0>(((*p[i]).DajDatumPregleda()).Ocitaj())); int m(std::get<1>(((*p[i]).DajDatumPregleda()).Ocitaj())); int g(std::get<2>(((*p[i]).DajDatumPregleda()).Ocitaj()));
        if(d==std::get<0>(datum.Ocitaj())&&m==std::get<1>(datum.Ocitaj())&&g==std::get<2>(datum.Ocitaj()))
        v.push_back((*p[i]));
    }}
    std::sort(v.begin(), v.end(), [](Pregled p1, Pregled p2){
        if(std::get<0>((p1.DajVrijemePregleda()).Ocitaj())<std::get<0>((p2.DajVrijemePregleda()).Ocitaj())) return true;
        else if(std::get<0>((p1.DajVrijemePregleda()).Ocitaj())>std::get<0>((p2.DajVrijemePregleda()).Ocitaj())) return false;
        if(std::get<1>((p1.DajVrijemePregleda()).Ocitaj())<std::get<1>((p2.DajVrijemePregleda()).Ocitaj())) return true;
        else if(std::get<1>((p1.DajVrijemePregleda()).Ocitaj())>std::get<1>((p2.DajVrijemePregleda()).Ocitaj())) return false;
        return false;
    });
    std::for_each(v.begin(), v.end(), [](Pregled p1){
       p1.Ispisi(); 
    });
}

void Pregledi::IspisiSvePreglede() const{
    std::vector<Pregled> v;
    for(int i=0; i<trenutno; i++){
        if(p[i]!=nullptr) v.push_back(*p[i]);
    } 
    std::sort(v.begin(), v.end(), [](Pregled p1, Pregled p2){
        if(std::get<2>((p1.DajDatumPregleda()).Ocitaj())<std::get<2>((p2.DajDatumPregleda()).Ocitaj())) return true;
        else if(std::get<2>((p1.DajDatumPregleda()).Ocitaj())>std::get<2>((p2.DajDatumPregleda()).Ocitaj())) return false;
        if(std::get<1>((p1.DajDatumPregleda()).Ocitaj())<std::get<1>((p2.DajDatumPregleda()).Ocitaj())) return true;
        else if(std::get<1>((p1.DajDatumPregleda()).Ocitaj())>std::get<1>((p2.DajDatumPregleda()).Ocitaj())) return false;
        if(std::get<0>((p1.DajDatumPregleda()).Ocitaj())<std::get<0>((p2.DajDatumPregleda()).Ocitaj())) return true;
        else if(std::get<0>((p1.DajDatumPregleda()).Ocitaj())>std::get<0>((p2.DajDatumPregleda()).Ocitaj())) return false;
        return false;
        if(std::get<0>((p1.DajVrijemePregleda()).Ocitaj())<std::get<0>((p2.DajVrijemePregleda()).Ocitaj())) return true;
        else if(std::get<0>((p1.DajVrijemePregleda()).Ocitaj())>std::get<0>((p2.DajVrijemePregleda()).Ocitaj())) return false;
        if(std::get<1>((p1.DajVrijemePregleda()).Ocitaj())<std::get<1>((p2.DajVrijemePregleda()).Ocitaj())) return true;
        else if(std::get<1>((p1.DajVrijemePregleda()).Ocitaj())>std::get<1>((p2.DajVrijemePregleda()).Ocitaj())) return false;
        return false;
    });
    std::for_each(v.begin(), v.end(), [](Pregled p1){
       p1.Ispisi();
       std::cout<<std::endl;
    });
}

Pregled Pregledi::DajNajranijiPregled() const{
    if(trenutno==0) throw std::domain_error("Nema registriranih pregleda");
     auto pok=std::min_element(p[0], p[trenutno], [](Pregled p1, Pregled p2){
           if(std::get<2>((p1.DajDatumPregleda()).Ocitaj())>std::get<2>((p1.DajDatumPregleda()).Ocitaj())) return true;
           else if(std::get<0>((p1.DajDatumPregleda()).Ocitaj())<std::get<0>((p1.DajDatumPregleda()).Ocitaj())) return false;
           if(std::get<1>((p1.DajDatumPregleda()).Ocitaj())>std::get<1>((p1.DajDatumPregleda()).Ocitaj())) return true;
           else if(std::get<1>((p1.DajDatumPregleda()).Ocitaj())<std::get<1>((p1.DajDatumPregleda()).Ocitaj())) return false;
           if(std::get<0>((p1.DajDatumPregleda()).Ocitaj())>std::get<0>((p1.DajDatumPregleda()).Ocitaj())) return true;
            else if(std::get<0>((p1.DajDatumPregleda()).Ocitaj())<std::get<0>((p1.DajDatumPregleda()).Ocitaj())) return false;
            if(std::get<0>((p1.DajVrijemePregleda()).Ocitaj())>std::get<0>((p1.DajVrijemePregleda()).Ocitaj())) return true;
           else if(std::get<0>((p1.DajVrijemePregleda()).Ocitaj())<std::get<0>((p1.DajVrijemePregleda()).Ocitaj())) return false;
            if(std::get<1>((p1.DajVrijemePregleda()).Ocitaj())>std::get<1>((p1.DajDatumPregleda()).Ocitaj())) return true;
           else if(std::get<1>((p1.DajVrijemePregleda()).Ocitaj())<std::get<1>((p1.DajVrijemePregleda()).Ocitaj())) return false;
           return false;
        });
        return *pok;
}

int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const{
    return std::count_if(p[0], p[trenutno], [&datum](Pregled p1){
    return(std::get<0>(datum.Ocitaj())==std::get<0>((p1.DajDatumPregleda()).Ocitaj())&&std::get<1>(datum.Ocitaj())==std::get<1>((p1.DajDatumPregleda()).Ocitaj())&&std::get<2>(datum.Ocitaj())==std::get<2>((p1.DajDatumPregleda()).Ocitaj()));});
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda){
    if(trenutno>=max_br) throw std::range_error("Dostignut maksimalni broj pregleda");
        p[trenutno++]=new Pregled(ime_pacijenta, datum_pregleda, vrijeme_pregleda);
    }
void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda){
        if(trenutno>=max_br) throw std::range_error("Dostignut maksimalni broj pregleda");
        p[trenutno++]=new Pregled(ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda);
    }
  
void Pregledi::RegistrirajPregled(Pregled *pregled){
    if(trenutno>=max_br)
    throw std::range_error ("Dostignut maksimalni broj pregleda");
    p[trenutno++]=pregled;
}

void Pregledi::IsprazniKolekciju(){
    trenutno=0;
    for(int i=0; i<max_br; i++) delete p[i];
    delete[] p;
    p=nullptr;
}

Pregledi::~Pregledi(){
     for(int i=0; i<max_br; i++) delete p[i];
    delete[] p;
    p=nullptr;
}

int main(){
    try{
    std::cout<<"Unesite maksimalan broj pregleda: ";
    int max_broj;
    std::cin>>max_broj;
    Pregledi pregledi(max_broj);
    int a(max_broj), l(0);
    while(a!=0){
        std::cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        std::string s;
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::getline(std::cin, s);
        if(s=="kraj") break;
        else{
            l++;
            std::cout<<"Unesite dan, mjesec i godinu pregleda: ";
            int dan, mjesec, godina;
            std::cin>>dan>>mjesec>>godina;
            Datum dat(dan, mjesec, godina);
            std::cout<<"Unesite sate i minute pregleda: ";
            int h, m;
            std::cin>>h>>m;
            Vrijeme vr(h, m);
            pregledi.RegistrirajPregled(s, dat, vr);
        }
        a--;
    }
        std::cout<<"Trenutno su registrovani sljedeci pregledi"<<std::endl;
        pregledi.IspisiSvePreglede();
        while(1){
            int br;
    std::cout<<"Odaberite jednu od sljedecih opcija"<<std::endl;
    std::cout<<"1 - Broj pregleda na datum"<<std::endl<<"2 - Najraniji pregled"<<std::endl<<"3 - Obrisi pregled pacijenta"<<std::endl;
    std::cout<<"4 - Obrisi najraniji pregled"<<std::endl<<"5 - Ispisi sve pregleda na datum"<<std::endl<<"6 - Ispisi sve preglede"<<std::endl<<"7 - Kraj programa";
    std::cout<<std::endl;
      std::cin>>br;
    if(br!=3&&br!=1) break;
    if(br==3) {
        std::string s1;
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout<<"Unesite ime pacijenta: ";
        std::getline(std::cin, s1);
        pregledi.ObrisiPregledePacijenta(s1);
        std::cout<<"Uspjesno obrisano "<<l-pregledi.DajBrojPregleda()<<" pregleda"<<std::endl;
        l=pregledi.DajBrojPregleda();
    }
    if(br==1){
        std::cin.clear();
        std::cout<<"Unesite dan mjesec i godinu : ";
        int day, month, year;
        std::cin>>day>>month>>year;
        Datum date(day, month, year);
        int br_preg=pregledi.DajBrojPregledaNaDatum(date);
        std::cout<<"Broj pregleda na datum "<<day<<" "<<month<<" "<<year<<" je "<<br_preg;
    }
        }
        
    }
    catch(...){
        std::cout<<"AAA";
    }
    return 0;
}
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        