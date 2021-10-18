/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <tuple>
#include <string>
#include <initializer_list>
#include <iomanip>
#include <stdexcept>
#include <algorithm>
typedef std::tuple<int,int,int> dat;
typedef std::pair<int,int> vrijeme;
class Datum{
    int dan,mjesec,godina;
  public:
  Datum(int dan, int mjesec, int godina){ Postavi(dan,mjesec,godina);}
  void Postavi(int dan, int mjesec, int godina);
  std::tuple<int, int, int> Ocitaj() const;
  void Ispisi() const{
      std::cout<<Datum::dan<<"/"<<Datum::mjesec<<"/"<<Datum::godina;
  }
};

void Datum::Postavi(int dan, int mjesec, int godina){
    int broj_dana[]{31,28,31,30,31,30,31,31,30,31,30,31};
    if(godina%4==0 && godina%100!=0 || godina%400==0) broj_dana[1]++;
    if(godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>broj_dana[mjesec-1]) 
    throw std::domain_error("Neispravan datum");
    Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
}
std::tuple<int, int, int> Datum::Ocitaj() const{
    dat d;
    d=std::make_tuple(Datum::dan,Datum::mjesec,Datum::godina);
    return d;
}
class Vrijeme{
    int sati,minute;
    public:
    Vrijeme(int sati, int minute){ Postavi(sati,minute);}
    void Postavi(int sati, int minute);
    std::pair<int, int> Ocitaj() const;
    void Ispisi() const{
        std::cout<<std::setw(2)<<std::setfill('0')<<Vrijeme::sati<<":"<<std::setw(2)<<std::setfill('0')<<Vrijeme::minute;
    }
};
void Vrijeme::Postavi(int sati, int minute){
    if(sati<0 || sati>23 || minute<0 || minute>59) throw std::domain_error("Neispravno vrijeme");
    else{ Vrijeme::sati=sati; Vrijeme::minute=minute;}
}
std::pair<int, int> Vrijeme::Ocitaj() const{
    vrijeme v;
    v=std::make_pair(Vrijeme::sati,Vrijeme::minute);
    return v;
}
class Pregled{
    Datum dan;
    Vrijeme v;
    std::string ime_pacijenta;
    Pregled() = default;
    
    public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda,const Vrijeme &vrijeme_pregleda);
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda,int minute_pregleda);
    void PromijeniPacijenta(const std::string &ime_pacijenta);
    void PromijeniDatum(const Datum &novi_datum);
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme);
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImePacijenta() const{ return this->ime_pacijenta;}
    Datum DajDatumPregleda() const{ return this->dan;}
    Vrijeme DajVrijemePregleda() const{ return this->v;}
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
    void Ispisi() const{
        std::cout<<std::setw(30)<<std::setfill(' ')<<std::left<<ime_pacijenta; dan.Ispisi(); std::cout<<" "; v.Ispisi();
        std::cout<<std::endl;
    }
};

Pregled::Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda,const Vrijeme &vrijeme_pregleda):
    dan(datum_pregleda),v(vrijeme_pregleda), ime_pacijenta(ime_pacijenta){}
Pregled::Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda,int minute_pregleda):
    dan(dan_pregleda,mjesec_pregleda,godina_pregleda),v(sati_pregleda,minute_pregleda),ime_pacijenta(ime_pacijenta){}
void Pregled::PromijeniPacijenta(const std::string &ime_pacijenta){
    this->ime_pacijenta=ime_pacijenta;
}
void Pregled::PromijeniDatum(const Datum &novi_datum){
    dat d=novi_datum.Ocitaj();
    this->dan.Postavi(std::get<0>(d), std::get<1>(d), std::get<2>(d));
}
void Pregled::PromijeniVrijeme(const Vrijeme &novo_vrijeme){
    vrijeme vr=novo_vrijeme.Ocitaj();
    this->v.Postavi(vr.first, vr.second);
}
void Pregled::PomjeriDanUnaprijed(){
    dat d=dan.Ocitaj();
    int novi_dan=std::get<0>(d)+1;
    this->dan.Postavi(novi_dan,std::get<1>(d),std::get<2>(d));
}
void Pregled::PomjeriDanUnazad(){
    dat d=dan.Ocitaj();
    int novi_dan=std::get<0>(d)-1;
    this->dan.Postavi(novi_dan,std::get<1>(d), std::get<2>(d));
}
bool DolaziPrije(const Pregled &p1, const Pregled &p2){
    dat d1=p1.DajDatumPregleda().Ocitaj();
    dat d2=p2.DajDatumPregleda().Ocitaj();
    vrijeme v1=p1.DajVrijemePregleda().Ocitaj();
    vrijeme v2=p2.DajVrijemePregleda().Ocitaj();
    bool isti(false);
    for(int i(0); i<1; i++){
    if(std::get<2>(d1) < std::get<2>(d2)) {isti=true; break;}
    if(std::get<1>(d1) < std::get<1>(d2)) {isti=true; break;}
    if(std::get<0>(d1) < std::get<0>(d2)) {isti=true; break;}
    if(v1.first < v2.first) {isti=true; break;}
    if(v1.second < v2.second) {isti=true; break;}
    }
    return isti;
}

class Pregledi{
    int broj_pregleda;
    int max_br_pregleda;
    Pregled **pregledii;
    public:
    explicit Pregledi(int max_br_pregleda):broj_pregleda(0),max_br_pregleda(max_br_pregleda),pregledii(new Pregled*[max_br_pregleda]){}
    Pregledi(std::initializer_list<Pregled> spisak_pregleda);
    ~Pregledi(){ 
        for(int i(0); i<broj_pregleda; i++)
        delete pregledii[i];
        delete [] pregledii;
    }
    Pregledi(const Pregledi &pregledi);
    Pregledi(Pregledi &&pregledi);
    Pregledi &operator=(const Pregledi &pregledi);
    Pregledi &operator=(Pregledi &&Pregledi);
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void RegistrirajPregled(Pregled *pregled);
    int DajBrojPregleda() const{ return broj_pregleda;}
    int DajBrojPregledaNaDatum(const Datum &datum) const;
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled () const;
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenata(const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum(const Datum &datum) const;
    void IspisiSvePreglede() const;
};
Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda):broj_pregleda(spisak_pregleda.size()),max_br_pregleda(spisak_pregleda.size()),
    pregledii(new Pregled*[max_br_pregleda]){
    int brojac(0);
    try{
        for(auto x:spisak_pregleda) pregledii[brojac++]=new Pregled(x);
    }catch(...){
        for(int i(0); i<brojac; i++)
        delete pregledii [i];
        throw;
    }
}
Pregledi::Pregledi(const Pregledi &pregledi):broj_pregleda(pregledi.broj_pregleda),max_br_pregleda(pregledi.max_br_pregleda),
    pregledii(new Pregled*[pregledi.max_br_pregleda]{}){
    try{
        for(int i(0);i<broj_pregleda; i++)
        pregledii[i]=new Pregled(*pregledi.pregledii[i]);
    }catch(...){
        if(pregledii==nullptr) return;
        for(int i(0); i<broj_pregleda; i++)
        delete pregledii[i];
        delete [] pregledii;
    }
}
Pregledi::Pregledi(Pregledi &&pregledi):broj_pregleda(pregledi.broj_pregleda),max_br_pregleda(pregledi.max_br_pregleda){
    if(&pregledi!=this){
        for(int i=0; i<max_br_pregleda; i++)
        delete pregledii[i];
        delete [] pregledii;
        pregledii=pregledi.pregledii;
        pregledi.pregledii=nullptr;
    }
}
Pregledi &Pregledi::operator=(const Pregledi &pregledi){
    if(&pregledi==this) return *this;
    for(int i(0); i<broj_pregleda; i++) delete pregledii[i];
    broj_pregleda=pregledi.broj_pregleda;
    try{
        for(int i(0); i<broj_pregleda; i++)
        pregledii[i]=new Pregled(*pregledi.pregledii[i]);
    }catch(...){
        //if(pregledii==nullptr) return;
        for(int i(0); i<broj_pregleda; i++)
        delete pregledii[i];
        delete [] pregledii;
        throw;
    }
    return *this;
}
Pregledi &Pregledi::operator=(Pregledi &&pregledi){
    if(&pregledi==this) return *this;
    pregledii=pregledi.pregledii;
    broj_pregleda=pregledi.broj_pregleda;
    pregledi.pregledii=nullptr;
    return *this;
}
void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda){
    if(broj_pregleda+1>max_br_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
    Pregled *pregled(new Pregled(ime_pacijenta, datum_pregleda,vrijeme_pregleda));
    pregledii[broj_pregleda]=pregled; 
    broj_pregleda++;
}
void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda){
    if(broj_pregleda+1>max_br_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
    Pregled *pregled(new Pregled(ime_pacijenta,dan_pregleda,mjesec_pregleda,godina_pregleda,sati_pregleda,minute_pregleda));
    pregledii[broj_pregleda]=pregled;
    broj_pregleda++;
}
void Pregledi::RegistrirajPregled(Pregled *pregled){
    if(broj_pregleda+1>max_br_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
    pregledii[broj_pregleda]=pregled; 
    broj_pregleda++;
}
int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const{
    if(broj_pregleda==0) throw std::domain_error("Nema registriranih pregleda");
    int brojac(0);
    brojac=std::count_if(pregledii, pregledii+broj_pregleda,[&datum](Pregled *pregled)->bool{
        dat d1=datum.Ocitaj();
        dat d2=pregled->DajDatumPregleda().Ocitaj();
        return (d1==d2);       
    });
    return brojac;
}
Pregled &Pregledi::DajNajranijiPregled(){
    if(broj_pregleda==0) throw std::domain_error("Nema registriranih pregleda");
    auto p=std::min_element(pregledii,pregledii+broj_pregleda, [](Pregled* p1, Pregled *p2)->bool{
        dat d1=p1->DajDatumPregleda().Ocitaj();
        dat d2=p2->DajDatumPregleda().Ocitaj();
        vrijeme v1=p1->DajVrijemePregleda().Ocitaj();
        vrijeme v2=p2->DajVrijemePregleda().Ocitaj();
        if(std::get<2>(d1) < std::get<2>(d2)) return true;
        else if(std::get<1>(d1) < std::get<1>(d2)) return true;
        else if(std::get<0>(d1) < std::get<0>(d2)) return true;
        else if(v1.first < v2.first) return true;
        else if(v1.second < v2.second) return true;
        return false;
    });
    return **p;
}
Pregled Pregledi::DajNajranijiPregled() const{
    if(broj_pregleda==0) throw std::domain_error("Nema registriranih pregleda");
    auto p=std::min_element(pregledii,pregledii+broj_pregleda, [](Pregled* p1, Pregled *p2)->bool{
        dat d1=p1->DajDatumPregleda().Ocitaj();
        dat d2=p2->DajDatumPregleda().Ocitaj();
        vrijeme v1=p1->DajVrijemePregleda().Ocitaj();
        vrijeme v2=p2->DajVrijemePregleda().Ocitaj();
        if(std::get<2>(d1) < std::get<2>(d2)) return true;
        if(std::get<1>(d1) < std::get<1>(d2)) return true;
        if(std::get<0>(d1) < std::get<0>(d2)) return true;
        if(v1.first < v2.first) return true;
        if(v1.second < v2.second) return true;
        return false;
    });
    return **p;
}
void Pregledi::IsprazniKolekciju(){
    for(int i(0); i<broj_pregleda; i++)
    delete pregledii[i];
    broj_pregleda=0;
}

//nije dobro
void Pregledi::IspisiSvePreglede() const{
   Pregledi pom=Pregledi(broj_pregleda);
   std::copy(pregledii,pregledii+broj_pregleda,pom.pregledii);
    std::sort(pom.pregledii,pom.pregledii+broj_pregleda,[](Pregled* p1, Pregled* p2){ 
        dat d1=p1->DajDatumPregleda().Ocitaj();
        dat d2=p2->DajDatumPregleda().Ocitaj();
        vrijeme v1=p1->DajVrijemePregleda().Ocitaj();
        vrijeme v2=p2->DajVrijemePregleda().Ocitaj();
        if(std::get<2>(d1) < std::get<2>(d2)) return true;
        if(std::get<1>(d1) < std::get<1>(d2)) return true;
        if(std::get<0>(d1) < std::get<0>(d2)) return true;
        if(v1.first < v2.first) return true;
        if(v1.second < v2.second) return true;
        return false;});
    
    //std::for_each(pom.pregledii, pom.pregledii+broj_pregleda,[](Pregled *p)->void{p->Ispisi();});
    std::for_each(pregledii,pregledii+broj_pregleda,[](Pregled*p)->void{p->Ispisi();});
}
void Pregledi::ObrisiNajranijiPregled(){
    if(broj_pregleda==0) throw std::range_error("Prazna kolekcija");
}
 /*   Pregled pregled=Pregledi::DajNajranijiPregled();
    Pregledi temp_pregledi=Pregledi(broj_pregleda);
    int l=0;
    for(int i=0; i<broj_pregleda; i++){
        auto a=pregledii[i];
        if(a->DajImePacijenta()==pregled->DajImePacijenta() && a->DajDatumPregleda().Ocitaj()==pregled->DajDatumPregleda().Ocitaj() &&
        a->DajVrijemePregleda().Ocitaj()==pregled->DajVrijemePregleda().Ocitaj()) continue;
        temp_pregledi.pregledii[l++]=pregledii[i];
    }
    std::copy(temp_pregledi.pregledii,temp_pregledi.pregledii+broj_pregleda, pregled);
    broj_pregleda--;
}*/
void Pregledi::ObrisiPregledePacijenata(const std::string &ime_pacijenta){
    if(broj_pregleda>0){
        Pregledi temp_pregledi=Pregledi(broj_pregleda);
        int l=0;
        for(int i=0; i<broj_pregleda; i++){
            if(pregledii[i]->DajImePacijenta()==ime_pacijenta) continue;
            temp_pregledi.pregledii[l++]=pregledii[i];
        }
        broj_pregleda=l;
        std::copy(temp_pregledi.pregledii,temp_pregledi.pregledii+broj_pregleda,pregledii);
    }
}
void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const{
    int brojac=0;
    /*Pregled temp_pregledi=Pregled(broj_pregleda);
    for(int i=0; i<broj_pregleda; i++){
        if(pregledii[i]->DajDatumPregleda().Ocitaj()==datum.Ocitaj())
        temp_pregledi.pregledii[brojac++]=pregledii[i];
        else continue;
    }
    std::sort(temp_pregledi.pregledii,temp_pregledi.pregledii+brojac,[](Pregled a, Pregled b){
        return DolaziPrije(a,b);});
    for(int i(0); i<brojac; i++) pregledii[i]->Ispisi();*/
}
int main ()
{
    int max_br_pregleda;
    std::cout<<"Unesite maksimalan broj pregleda: ";
    std::cin>>max_br_pregleda;
    Pregledi pregledi(max_br_pregleda);
    int br(0);
    for(int i(0); i<max_br_pregleda; i++){
        std::string ime_pacijenta;
        std::cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        std::cin>>ime_pacijenta;
        if(ime_pacijenta=="kraj") break;
        int dan,mj,god;
        std::cout<<"Unesite dan mjesec i godinu pregleda: ";
        std::cin>>dan>>mj>>god;
        Datum datum_pregleda(dan,mj,god);
        int sat,min;
        std::cout<<"Unesite sate i minute pregleda: ";
        std::cin>>sat>>min;
        Vrijeme vrijeme_pregleda(sat,min);
        pregledi.RegistrirajPregled(ime_pacijenta,datum_pregleda,vrijeme_pregleda);
        br++;
    }
    std::cout<<"Trenutno su registrovani sljedeci pregledi\n";
    //for(int i(0); i<br; i++)
    pregledi.IspisiSvePreglede();
    int izbor;
    do{
        std::cout<<"Odaberite jednu od sljedecih opcija\n";
        std::cout<<"1 - Broj pregleda na datum\n";
        std::cout<<"2 - Najraniji pregled\n";
        std::cout<<"3 - Obrisi pregled pacijenta\n";
        std::cout<<"4 - Obrisi najraniji pregled\n";
        std::cout<<"5 - Ispisi sve pregleda na datum\n";
        std::cout<<"6 - Ispisi sve preglede\n";
        std::cout<<"7 - Kraj programa\n";
        std::cin>>izbor;
        if(izbor==1){ 
            int dan,mjes,god;
            std::cout<<"Unesite dan mjesec i godinu :";
            std::cin>>dan>>mjes>>god;
            Datum d(dan,mjes,god);
            std::cout<<"Broj pregleda na datum "<<dan<<" "<<mjes<<" "<<god<<" je : "<<pregledi.DajBrojPregledaNaDatum(d)<<"\n";
        }
        if(izbor==2){
            std::cout<<"Najraniji pregled: ";
            try{
                pregledi.DajNajranijiPregled().Ispisi();
                std::cout<<std::endl;
            }catch(std::domain_error izuzetak){
                std::cout<<izuzetak.what();
            }
        }
        if(izbor==3){
            std::string ime_pacijenta;
            std::cout<<"Unesite ime pacijenta: ";
            pregledi.ObrisiPregledePacijenata(ime_pacijenta);
            std::cout<<"Uspjesno obrisano 1 pregleda";
            std::cout<<std::endl;
        }
        if(izbor==4){
            try{
                pregledi.ObrisiNajranijiPregled();
                std::cout<<"Najraniji pregled uspjesno obrisan\n";
            }catch(std::range_error izuzetak){
                std::cout<<izuzetak.what();
            }
        }
        if(izbor==5){
            int dan,mj,god;
            std::cout<<"Unesite dan mjesec i godinu: ";
            std::cin>>dan>>mj>>god;
            Datum d(dan,mj,god);
            std::cout<<"Pregledi na datum "<<dan<<" "<<mj<<" "<<god<<"su:\n";
            pregledi.IspisiPregledeNaDatum(d);
            std::cout<<std::endl;
        }
        if(izbor==6){
            pregledi.IspisiSvePreglede();
            std::cout<<std::endl;
        }
        if(izbor==7) break;
        std::cout<<std::endl;
    }while(izbor!=7);
	return 0;
}
