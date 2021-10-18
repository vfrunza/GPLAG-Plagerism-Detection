/B2017/2018: Zadaća 4, Zadatak 4
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <memory>

class Datum{
  int dan,mjesec,godina;
  friend bool operator <(const Datum &d1, const Datum &d2);
  public:
  Datum(int dan, int mjeces, int godina);
  void Postavi(int dan, int mjesec, int godina);
  std::tuple<int,int,int> Ocitaj() const {return std::make_tuple(this->dan,this->mjesec,this->godina);}
  void Ispisi() const{std::cout<<dan<<"/"<<mjesec<<"/"<<godina;}
};
bool operator <(const Datum &d1, const Datum &d2){
    if(d1.godina>d2.godina) return false;
    else if(d1.godina==d2.godina && d1.mjesec>d2.mjesec) return false;
    else if(d1.godina==d2.godina && d1.mjesec==d2.mjesec && d1.dan>d2.dan) return false;
    else if(d1.godina<=d2.godina){
        if(d1.mjesec<=d2.mjesec && d1.dan<d2.dan) return true;
    }
    return true;
}
Datum::Datum(int dan,int mjesec, int godina){
    if(dan<1 || dan>31 || mjesec<1 || mjesec>12) throw std::domain_error("Neispravan datum");
    Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina;
}
void Datum::Postavi(int dan,int mjesec,int godina){
    int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if(godina%4==0 && (godina%100 !=0 || godina%400 ==0 )) broj_dana[1]++;
    if(godina <1 || dan<1 || dan>broj_dana[mjesec-1] || mjesec<1 || mjesec>12) 
        throw std::domain_error("Neispravan datum");
    Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina;
}
class Vrijeme{
    int sati, minute;
    public: 
    Vrijeme(int sati, int minute);
    void Postavi(int sati, int minute);
    std::pair<int,int> Ocitaj() const {return std::make_pair(this->sati,this->minute);}
    void Ispisi() const{if(sati<10)std::cout<<"0"; std::cout<<sati<<":"; if(minute<10) std::cout<<"0"; std::cout<<minute;}
    
};
Vrijeme::Vrijeme(int sati, int minute){
    if(sati<0 || sati>23 || minute<0 || minute>59) throw std::domain_error("Neispravno vrijeme");
    Vrijeme::sati = sati; Vrijeme ::minute = minute;
}
void Vrijeme::Postavi(int sati, int minute){
    if(sati<0 || sati>23 || minute<0 || minute>59) throw std::domain_error("Neispravno vrijeme");
    Vrijeme::sati = sati; Vrijeme ::minute = minute;
}
class Pregled{
  std::string ime_pacijenta;
  Datum datum_pregleda;
  Vrijeme vrijeme_pregleda;
  friend bool operator ==(const Pregled &p1, const Pregled &p2);
  public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda,const Vrijeme &vrijeme_pregleda);
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,int godina_pregleda, 
          int sati_pregleda, int minute_pregleda);
    void PromijeniPacijenta(const std::string &ime_pacijenta);
    void PromijeniDatum(const Datum &novi_datum);
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme);
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImePacijenta() const;
    Datum DajDatumPregleda() const;
    Vrijeme DajVrijemePregleda() const;
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
    void Ispisi() const;
};
bool operator ==(const Pregled &p1, const Pregled &p2){
    if(p1.ime_pacijenta==p2.ime_pacijenta && p1.datum_pregleda.Ocitaj()==p2.datum_pregleda.Ocitaj() &&
        p1.vrijeme_pregleda.Ocitaj()==p2.vrijeme_pregleda.Ocitaj()) return true;
    return false;
}
Pregled::Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda,const Vrijeme &vrijeme_pregleda):
ime_pacijenta(ime_pacijenta),datum_pregleda(datum_pregleda), vrijeme_pregleda(vrijeme_pregleda){}
void Pregled::PromijeniPacijenta(const std::string &ime_pacijenta){
    Pregled::ime_pacijenta = ime_pacijenta;
}
void Pregled::PomjeriDanUnazad(){
    int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    auto pomjeranje(datum_pregleda.Ocitaj());
    if(std::get<2>(pomjeranje)%4==0 && (std::get<2>(pomjeranje)%100 !=0 || std::get<2>(pomjeranje)%400 ==0 )) broj_dana[1]++;
    if(std::get<0>(pomjeranje)==1){
        if(std::get<1>(pomjeranje)==1){
            std::get<1>(pomjeranje)=12;
            std::get<2>(pomjeranje) -=1;
            std::get<0>(pomjeranje)=broj_dana[std::get<1>(pomjeranje)-1];
        }else{
            std::get<1>(pomjeranje)--;
            std::get<0>(pomjeranje)=broj_dana[std::get<1>(pomjeranje)-1];
        }
    }else std::get<0>(pomjeranje)--;
}
void Pregled::PomjeriDanUnaprijed(){
    int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    auto pomjeranje(datum_pregleda.Ocitaj());
    if(std::get<2>(pomjeranje)%4==0 && (std::get<2>(pomjeranje)%100 !=0 || std::get<2>(pomjeranje)%400 ==0 )) broj_dana[1]++;
    if(std::get<0>(pomjeranje)==31 && std::get<1>(pomjeranje)==12){
        std::get<2>(pomjeranje)++;
        std::get<1>(pomjeranje)=1;
        std::get<0>(pomjeranje)=1;
    }else if(std::get<0>(pomjeranje)==31 && (std::get<1>(pomjeranje)==1 || std::get<1>(pomjeranje)==3 ||std::get<1>(pomjeranje)==5
        || std::get<1>(pomjeranje)==7 || std::get<1>(pomjeranje)==8 || std::get<1>(pomjeranje)==10)){
            std::get<0>(pomjeranje)=1;
            std::get<1>(pomjeranje)++;
    }else if(std::get<0>(pomjeranje)==30 && (std::get<1>(pomjeranje)==4 || std::get<1>(pomjeranje)==6 || std::get<1>(pomjeranje)==11
        || std::get<1>(pomjeranje)==9)){
            std::get<0>(pomjeranje)=1;
            std::get<1>(pomjeranje)++;
    }else if(std::get<1>(pomjeranje)==2 && std::get<0>(pomjeranje) == broj_dana[1]){
        std::get<1>(pomjeranje)++;
        std::get<0>(pomjeranje) = 1;
    }else std::get<0>(pomjeranje)++;
}
void Pregled::PromijeniDatum(const Datum &novi_datum){
    Pregled::datum_pregleda = novi_datum;
}
void Pregled::PromijeniVrijeme(const Vrijeme &novo_vrijeme){
    Pregled::vrijeme_pregleda = novo_vrijeme;
}
std::string Pregled::DajImePacijenta() const{
    return this->ime_pacijenta;
}
Datum Pregled::DajDatumPregleda() const{
    return this->datum_pregleda;
}
Vrijeme Pregled::DajVrijemePregleda() const{
    return this->vrijeme_pregleda;
}
void Pregled::Ispisi() const{
    std::cout<<std::setw(30)<<std::left<<Pregled::ime_pacijenta;
    Pregled::datum_pregleda.Ispisi();
    std::cout<<" ";
    Pregled::vrijeme_pregleda.Ispisi();
    std::cout<<std::endl;
}
bool Pregled::DolaziPrije(const Pregled &p1, const Pregled &p2){
    std::tuple<int,int,int> d1(p1.datum_pregleda.Ocitaj()),d2(p2.datum_pregleda.Ocitaj());
    std::pair<int,int> v1(p1.vrijeme_pregleda.Ocitaj()),v2(p2.vrijeme_pregleda.Ocitaj());
    
    if(std::get<2>(d1)<=std::get<2>(d2) && std::get<1>(d1)<=std::get<1>(d2) 
        && std::get<0>(d1)<=std::get<0>(d2) && std::get<0>(v1)<=std::get<0>(v2) && std::get<1>(v1)<std::get<1>(v2))return true;
    return false;
}

class Pregledi{
    std::vector<std::shared_ptr<Pregled>> epregledi;
    std::vector<std::shared_ptr<Pregled>> SortirajSvePreglede(std::vector<std::shared_ptr<Pregled>> epregledi);
    static bool DatumPrije(std::shared_ptr<Pregled> p1, std::shared_ptr<Pregled> p2){
        return p1->DajDatumPregleda()<p2->DajDatumPregleda();
    }
    public:
    explicit Pregledi() = default;
    Pregledi(std::initializer_list<Pregled> spisak_pregleda);
    Pregledi(const Pregledi &pregledi);
    Pregledi(Pregledi &&pregledi) = default;
    Pregledi &operator =(const Pregledi &pregledi);
    Pregledi &operator =(Pregledi &&pregledi) = default;
    void RegistrirajPregled(const std::string &ime_pacijenta,
    const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,
    int mjesec_pregleda, int godina_pregleda, int sati_pregleda,
    int minute_pregleda);
    void RegistrirajPregled(std::shared_ptr<Pregled> *pregled);
    int DajBrojPregleda() const;
    int DajBrojPregledaNaDatum(const Datum &datum) const;
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum(const Datum &datum) const;
    void IspisiSvePreglede() const;
};

Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda){
    epregledi.resize(spisak_pregleda.size());
    for(int i=0;i<spisak_pregleda.size();i++) 
        epregledi[i] = std::make_shared<Pregled>(*(spisak_pregleda.begin()+i));
    epregledi = SortirajSvePreglede(epregledi);
}

Pregledi::Pregledi(const Pregledi &pregledi){
    for(int i=0;i<pregledi.epregledi.size();i++)
        epregledi.push_back(std::make_shared<Pregled>(*pregledi.epregledi[i]));
}

Pregledi &Pregledi::operator=(const Pregledi &pregledi){
    epregledi = pregledi.epregledi;
    return *this;
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta,const Datum &datum_pregleda,const Vrijeme &vrijeme_pregleda){
    
    auto novi_pregled = std::make_shared<Pregled>(ime_pacijenta,datum_pregleda,vrijeme_pregleda);
    epregledi.push_back(novi_pregled);
    epregledi = SortirajSvePreglede(this->epregledi);
    
}
void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,
    int mjesec_pregleda, int godina_pregleda, int sati_pregleda,
    int minute_pregleda){
    
        Datum datum_pregleda(dan_pregleda,mjesec_pregleda,godina_pregleda);
        Vrijeme vrijeme_pregleda(sati_pregleda,minute_pregleda);
        auto novi_pregled = std::make_shared<Pregled>(ime_pacijenta,datum_pregleda,vrijeme_pregleda);
        epregledi.push_back(novi_pregled);
        
    epregledi = SortirajSvePreglede(this->epregledi);
        
}
void Pregledi::RegistrirajPregled(std::shared_ptr<Pregled> *pregled){
    epregledi.push_back(*pregled);
    epregledi = SortirajSvePreglede(this->epregledi);
}
int Pregledi::DajBrojPregleda() const{
    return this->epregledi.size();
}   
int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const{
    int a(std::count_if(this->epregledi.begin(),this->epregledi.begin()+epregledi.size(),[datum](std::shared_ptr<Pregled> pregled){
        auto d1(pregled->DajDatumPregleda());
        if(d1.Ocitaj()==datum.Ocitaj()) return true;
        return  false;
    }));
    return a;
}
Pregled &Pregledi::DajNajranijiPregled(){
    if(epregledi.size()==0) throw std::domain_error("Nema registriranih pregleda");
    return *(*(std::min_element(this->epregledi.begin(),this->epregledi.begin()+epregledi.size(),[](std::shared_ptr<Pregled> pregled1,std::shared_ptr<Pregled> pregled2){
        return pregled1->DajDatumPregleda()<pregled2->DajDatumPregleda();
    })));
    
}
Pregled Pregledi::DajNajranijiPregled() const{
    if(epregledi.size()==0) throw std::domain_error("Nema registriranih pregleda");
    auto prgl(std::min_element(this->epregledi.begin(),this->epregledi.begin()+epregledi.size(),[](std::shared_ptr<Pregled> pregled1,std::shared_ptr<Pregled> pregled2){
        return pregled1->DajDatumPregleda()<pregled2->DajDatumPregleda();
    }));
    return *(*prgl);
}
std::vector<std::shared_ptr<Pregled>> Pregledi::SortirajSvePreglede(std::vector<std::shared_ptr<Pregled>> epregledi){
    std::sort(epregledi.begin(),epregledi.begin()+epregledi.size(),DatumPrije);
    return epregledi;
}
void Pregledi::ObrisiNajranijiPregled(){
    auto PregledZaObrisati(DajNajranijiPregled());
    for(int i=0;i<epregledi.size();i++){
        if(*(epregledi[i])==PregledZaObrisati){
            epregledi.erase(epregledi.begin()+i);
            std::cout<<"Najraniji pregled uspjesno obrisan"<<std::endl;
            
        }
    }
}
void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta){
    int brojac(0);
    for(int i=0;i<epregledi.size();i++){
        if(epregledi[i]->DajImePacijenta()==ime_pacijenta){
            epregledi.erase(epregledi.begin()+i);
            brojac++;
        }
    }
    std::cout<<"Uspjesno obrisano "<<brojac<<" pregleda"<<std::endl;
}
void Pregledi::IsprazniKolekciju(){
    epregledi.resize(0);
}
void Pregledi::IspisiSvePreglede() const{
    for(int i=0;i<epregledi.size();i++){
            epregledi[i]->Ispisi();
    }
}
void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const{
    for(int i=0;i<epregledi.size();i++){
            Datum d(epregledi[i]->DajDatumPregleda());
            if(d.Ocitaj()==datum.Ocitaj())
              epregledi[i]->Ispisi();
    }
}

        
int main ()
{
    
    Pregledi pregledi;
    try{
        while(1){
            std::cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
            std::string pacijent;
            std::getline(std::cin,pacijent);
            if(pacijent=="kraj") break;
            std::cout<<"Unesite dan mjesec i godinu pregleda: ";
            int dan,mjesec,godina;
            std::cin>>dan>>mjesec>>godina;
            std::cout<<"Unesite sate i minute pregleda: ";
            int sati,minute;
            std::cin>>sati>>minute;
            pregledi.RegistrirajPregled(pacijent,dan,mjesec,godina,sati,minute);
            std::cin.ignore(10000,'\n');
        }
    }catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what();
        return 0;
    }catch(std::range_error izuzetak){
        std::cout<<izuzetak.what();
        return 0;
    }
    std::cout<<"Trenutno su registrovani sljedeci pregledi"<<std::endl;
    pregledi.IspisiSvePreglede();
    for(;;){
        std::cout<<std::endl<<"Odaberite jednu od sljedecih opcija"<<std::endl<<"1 - Broj pregleda na datum"
        <<std::endl<<"2 - Najraniji pregled"<<std::endl<<"3 - Obrisi pregled pacijenta"<<std::endl
        <<"4 - Obrisi najraniji pregled"<<std::endl<<"5 - Ispisi sve pregleda na datum"<<std::endl<<
        "6 - Ispisi sve preglede"<<std::endl<<"7 - Kraj programa"<<std::endl;
        int n;
        std::cin>>n;
        if(n==7) break;
        else if(n==1){
            std::cout<<"Unesite dan mjesec i godinu : ";
            int d,m,g;
            std::cin>>d>>m>>g;
            Datum d1(d,m,g);
            std::cout<<"Broj pregleda na datum "<<d<<" "<<m<<" "<<g<<" "<<"je: "<<pregledi.DajBrojPregledaNaDatum(d1)<<std::endl;
        }else if(n==2){
            std::cout<<"Najraniji pregled je:"<<std::endl;
            auto abc = pregledi.DajNajranijiPregled();
            abc.Ispisi();
        }else if(n==3){
            std::cout<<"Unesite ime pacijenta: ";
            std::string pacijent;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::getline(std::cin,pacijent);
            pregledi.ObrisiPregledePacijenta(pacijent);
        }else if(n==4) pregledi.ObrisiNajranijiPregled();
        else if(n==5){
            std::cout<<"Unesite dan mjesec i godinu : ";
            int d,m,g;
            std::cin>>d>>m>>g;
            Datum d1(d,m,g);
            std::cout<<"Pregledi na datum "<<d<<" "<<m<<" "<<g<<" "<<"su:"<<std::endl;
            pregledi.IspisiPregledeNaDatum(d1);
        }else if(n==6) pregledi.IspisiSvePreglede();
        else break;
        
    }
    
    
	return 0;
}
