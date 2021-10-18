/B2017/2018: Zadaća 4, Zadatak 4
#include <iostream>
#include <utility>
#include <cmath>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <memory>
#include <iomanip>
#include <string>
#include <initializer_list>

class Datum{
    int dan, mjesec, godina;

    public:
    Datum(int dan, int mjesec, int godina){
        int brDana[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
       if((godina % 4==0 && godina % 100!=0) || godina % 400==0) brDana[2]++;
       if(godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>brDana[mjesec])
       throw std::domain_error("Neispravan datum!");
        Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina;
    }
    void Postavi(int dan, int mjesec, int godina);
    std::tuple<int, int, int> Ocitaj() const;
    void Ispisi() const;
   
};

void Datum::Postavi(int dan, int mjesec, int godina){
    int brDana[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina % 4==0 && godina % 100!=0) || godina % 400==0) brDana[2]++;
    if(godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>brDana[mjesec])
    throw std::domain_error("Neispravan datum!");
    Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina;
}

std::tuple<int, int, int> Datum::Ocitaj() const{
    std::tuple<int, int, int> povratni;
    povratni=std::make_tuple(dan, mjesec, godina);
    return povratni;
}
void Datum::Ispisi() const{
    std::cout<<Datum::dan<<"/"<<Datum::mjesec<<"/"<<Datum::godina;
}

// Vrijeme 

class Vrijeme{
    int sati, minute;
    public:
    Vrijeme(int sati, int minute){
        if(sati<0 || sati>23 || minute<0 || minute>59) throw std::domain_error("Neispravno vrijeme");
        Vrijeme::sati=sati;
        Vrijeme::minute=minute;
    }
    void Postavi(int sati, int minute);
    std::pair<int, int> Ocitaj () const;
    void Ispisi() const;

};
void Vrijeme::Postavi(int sati, int minute){
    if(sati<0 || sati>23 || minute<0 || minute>59) throw std::domain_error("Neispravno vrijeme");
    Vrijeme::sati=sati;
    Vrijeme::minute=minute;
}
std::pair<int, int> Vrijeme::Ocitaj() const{
    std::pair<int, int> povratni;
    povratni.first=Vrijeme::sati;
    povratni.second=Vrijeme::minute;
    return povratni;
}
void Vrijeme::Ispisi() const{
    std::cout<<std::setw(2)<<std::setfill('0')<<std::right<<Vrijeme::sati<<":"<<std::setw(2)<<std::setfill('0')<<Vrijeme::minute;
}

// Pregled

class Pregled{
    std::string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
    public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda):ime_pacijenta(ime_pacijenta), datum_pregleda(datum_pregleda), vrijeme_pregleda(vrijeme_pregleda){}
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda): ime_pacijenta(ime_pacijenta), datum_pregleda(dan_pregleda, mjesec_pregleda, godina_pregleda), vrijeme_pregleda(sati_pregleda, minute_pregleda){}
    void PromijeniPacijenta(const std::string &ime_pacijenta);
    void PromijeniDatum(const Datum &novi_datum);
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme);
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImePacijenta() const;
    Datum DajDatumPregleda() const;
    Vrijeme DajVrijemePregleda() const;
    
    void Ispisi() const;

};
void Pregled::PromijeniPacijenta(const std::string &ime_pacijenta){
    Pregled::ime_pacijenta=ime_pacijenta;
}
void Pregled::PromijeniDatum(const Datum &novi_datum){
    Pregled::datum_pregleda=novi_datum;
}
void Pregled::PromijeniVrijeme(const Vrijeme &novo_vrijeme){
    Pregled::vrijeme_pregleda=novo_vrijeme;
}
void Pregled::PomjeriDanUnaprijed(){
    std::tuple<int, int, int> pomjeri;
    pomjeri=datum_pregleda.Ocitaj();
    int kojiDan(0), kojiMjesec(0), kojaGodina(0);
    kojiDan=std::get<0>(pomjeri);
    kojiMjesec=std::get<1>(pomjeri);
    kojaGodina=std::get<2>(pomjeri);
    int brDana[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool prestupna(false);
    if((kojaGodina % 4==0 && kojaGodina % 100!=0) || kojaGodina % 400==0) {brDana[2]++; prestupna=true;}
    
    
    //februar
    if(kojiMjesec==2 && prestupna){
        kojiDan++;
        if(kojiDan==30){
            kojiDan=1;
            kojiMjesec=3;
            datum_pregleda.Postavi(kojiDan, kojiMjesec, kojaGodina);
            return;
        }
        datum_pregleda.Postavi(kojiDan, kojiMjesec, kojaGodina);
        return;
    }
    else if(kojiMjesec==2 && !prestupna){
        kojiDan++;
        if(kojiDan==29){
            kojiDan=1;
            kojiMjesec=3;
            datum_pregleda.Postavi(kojiDan, kojiMjesec, kojaGodina);
            return;
        }
        datum_pregleda.Postavi(kojiDan, kojiMjesec, kojaGodina);
        return;
    }
    //30 dana
    if(brDana[kojiMjesec]==30){
        kojiDan++;
        if(kojiDan==31){
            kojiDan=1;
            kojiMjesec++;
            if(kojiMjesec==13) {kojaGodina++; kojiMjesec=1;}
            datum_pregleda.Postavi(kojiDan, kojiMjesec, kojaGodina);
            return;
        }
        datum_pregleda.Postavi(kojiDan, kojiMjesec, kojaGodina);
    }
    //31 dan
    if(brDana[kojiMjesec]==31){
        kojiDan++;
        if(kojiDan==32){
            kojiDan=1;
            kojiMjesec++;
            if(kojiMjesec==13) { kojaGodina++; kojiMjesec=1;}
            datum_pregleda.Postavi(kojiDan, kojiMjesec, kojaGodina);
            return;
        }
        datum_pregleda.Postavi(kojiDan, kojiMjesec, kojaGodina);
        return;
    }
    
}
void Pregled::PomjeriDanUnazad(){
    
    std::tuple<int, int, int> pomjeri;
    pomjeri=datum_pregleda.Ocitaj();
    int kojiDan(0), kojiMjesec(0), kojaGodina(0);
    kojiDan=std::get<0>(pomjeri);
    kojiMjesec=std::get<1>(pomjeri);
    kojaGodina=std::get<2>(pomjeri);
    int brDana[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool prestupna(false);
    if((kojaGodina % 4==0 && kojaGodina % 100!=0) || kojaGodina % 400==0) {brDana[2]++; prestupna=true;}
    
    //mart
    if(kojiMjesec==3 && prestupna){
        kojiDan--;
        if(kojiDan==0){
            kojiMjesec=2;
            kojiDan=29;
        }
        datum_pregleda.Postavi(kojiDan, kojiMjesec, kojaGodina);
        return;
    }
    if(kojiMjesec==3 && !prestupna){
        kojiDan--;
        if(kojiDan==0){
            kojiMjesec=2;
            kojiDan=28;
        }
        datum_pregleda.Postavi(kojiDan, kojiMjesec, kojaGodina);
        return;
    }
    //august
    if(kojiMjesec==8){
        kojiDan--;
        if(kojiDan==0){
            kojiMjesec--;
            kojiDan=31;
        }
        datum_pregleda.Postavi(kojiDan, kojiMjesec, kojaGodina);
        return;
    }
    //30 dana
    if(brDana[kojiMjesec]==30 || kojiMjesec==2){
        kojiDan--;
        if(kojiDan==0){
            kojiMjesec--;
            kojiDan=31;
        }
        datum_pregleda.Postavi(kojiDan, kojiMjesec, kojaGodina);
        return;
    }
    
    //31 dana
    if(brDana[kojiMjesec]==31){
        kojiDan--;
        if(kojiDan==0){
            kojiMjesec--;
            kojiDan=30;
        }
        if(kojiMjesec==0){
            kojiMjesec=12;
            kojaGodina--;
            kojiDan=31;
        }
        datum_pregleda.Postavi(kojiDan, kojiMjesec, kojaGodina);
        return;
    }
        
}
std::string Pregled::DajImePacijenta() const{
    return ime_pacijenta;
}

Datum Pregled::DajDatumPregleda() const{
    return this->datum_pregleda;
}

Vrijeme Pregled::DajVrijemePregleda() const{
    return vrijeme_pregleda;
}

bool DolaziPrije(const Pregled &p1, const Pregled &p2){
    std::tuple<int, int, int> pomocni;
    std::pair<int, int> kad;
    int dan1(0), dan2(0), mjesec1(0), mjesec2(0), godina1(0), godina2(0), sat1(0), sat2(0), min1(0), min2(0);
    // p1
    pomocni=p1.DajDatumPregleda().Ocitaj();
    kad=p1.DajVrijemePregleda().Ocitaj();
    
    dan1=std::get<0>(pomocni);
    mjesec1=std::get<1>(pomocni);
    godina1=std::get<2>(pomocni);
    
    sat1=kad.first;
    min1=kad.second;
    
    // p2
    pomocni=p2.DajDatumPregleda().Ocitaj();
    kad=p2.DajVrijemePregleda().Ocitaj();
    
    dan2=std::get<0>(pomocni);
    mjesec2=std::get<1>(pomocni);
    godina2=std::get<2>(pomocni);
    
    sat2=kad.first;
    min2=kad.second;
    
    if(godina1<godina2) return true;
    if(godina1==godina2 && mjesec1<mjesec2) return true;
    if(godina1==godina2 && mjesec1==mjesec2 && dan1<dan2) return true;
    if(godina1==godina2 && mjesec1==mjesec2 && dan1==dan2 && sat1<sat2) return true;
    if(godina1==godina2 && mjesec1==mjesec2 && dan1==dan2 && sat1==sat2 && min1<min2) return true;
    return false;
    
}
void Pregled::Ispisi() const{
    std::cout<<std::setw(30)<<std::setfill(' ')<<std::left<<ime_pacijenta;
    datum_pregleda.Ispisi();
    std::cout<<" ";
    vrijeme_pregleda.Ispisi();
    std::cout<<std::endl;
}


class Pregledi{
    std::vector<std::shared_ptr<Pregled>> preg;
    
    public:
    
    explicit Pregledi();
    Pregledi(std::initializer_list<Pregled> spisak_pregleda);
    Pregledi(const Pregledi &pregledi);
    Pregledi(Pregledi &&pregledi);
    Pregledi &operator =(const Pregledi &pregledi);
    Pregledi &operator =(Pregledi &&pregledi);
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void RegistrirajPregled(std::shared_ptr<Pregled> pregled);
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

Pregledi::Pregledi(){}

Pregledi::Pregledi(const Pregledi &pregledi){
    for(int i=0; i<pregledi.preg.size(); i++){
        std::shared_ptr<Pregled> pomocni;
        pomocni=std::make_shared<Pregled> (*pregledi.preg[i]);
        preg.push_back(pomocni);
    }
       
}

Pregledi::Pregledi(Pregledi &&pregledi){
    for(int i=0; i<pregledi.preg.size(); i++)
        preg.push_back(pregledi.preg[i]);
}

Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda){
	
	int i=0;
	for(auto it=spisak_pregleda.begin(); it!=spisak_pregleda.end(); it++){
	    std::shared_ptr<Pregled> pomocni;
	    pomocni=std::make_shared<Pregled>(*it);
	    preg.push_back(pomocni);
	    i++;
	}
}

Pregledi &Pregledi::operator =(const Pregledi &pregledi){
    
    if(&pregledi!=this){
        preg.resize(0);
        for(int i=0; i<pregledi.preg.size(); i++){
            std::shared_ptr<Pregled> pomocni;
            pomocni=std::make_shared<Pregled> (*pregledi.preg[i]);
            preg.push_back(pomocni);
        }
    }
    return *this;
}

Pregledi &Pregledi::operator =(Pregledi &&pregledi){
    if(&pregledi!=this){
        for(int i=0; i<pregledi.preg.size(); i++)
            preg.push_back(pregledi.preg[i]);
    }
    return *this;
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda){
    Pregled pomocni(ime_pacijenta, datum_pregleda, vrijeme_pregleda);
    preg.push_back(std::make_shared<Pregled>(pomocni));
   
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda){
    Pregled pomocni(ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda);
    std::shared_ptr<Pregled> povratni=std::make_shared<Pregled>(pomocni);
    preg.push_back(povratni);
    
}

void Pregledi::RegistrirajPregled(std::shared_ptr<Pregled> pregled){
    std::shared_ptr<Pregled> pomocni;
    pomocni=std::make_shared<Pregled>(*pregled);
    preg.push_back(pomocni);

}

int Pregledi::DajBrojPregleda() const{
    return preg.size();
}

int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const{
    
    std::tuple<int, int, int> kojiDatum;
    kojiDatum=datum.Ocitaj();
    int dan1(0), mjesec1(0), godina1(0);
    dan1=std::get<0>(kojiDatum);
    mjesec1=std::get<1>(kojiDatum);
    godina1=std::get<2>(kojiDatum);
    
     return std::count_if(preg.begin(), preg.end(), [dan1, mjesec1, godina1](std::shared_ptr<Pregled> pomocni){
        Datum pomocniDat=pomocni->DajDatumPregleda();
        std::tuple<int, int, int> nesto;
        nesto=pomocniDat.Ocitaj();
        int dan2(0), mjesec2(0), godina2(0);
        dan2=std::get<0>(nesto);
        mjesec2=std::get<1>(nesto);
        godina2=std::get<2>(nesto);
        if(dan1==dan2 && mjesec1==mjesec2 && godina1==godina2) return true;
        else return false;
        
    });
    
}

Pregled &Pregledi::DajNajranijiPregled(){
    if(preg.size()==0) throw std::domain_error("Nema registriranih pregleda");
    auto koji=std::min_element(preg.begin(), preg.end(), [](std::shared_ptr<Pregled> pomocni1, std::shared_ptr<Pregled> pomocni2){
         if(DolaziPrije(*pomocni1, *pomocni2)) return true;
         return false;
    });
    return **koji;
}

Pregled Pregledi::DajNajranijiPregled() const{
    if(preg.size()==0) throw std::domain_error("Nema registriranih pregleda");
    auto koji=std::min_element(preg.begin(), preg.end(), [](std::shared_ptr<Pregled> pomocni1, std::shared_ptr<Pregled> pomocni2){
         if(DolaziPrije(*pomocni1, *pomocni2)) return true;
         return false;
    });
    return **koji;
}
void Pregledi::IsprazniKolekciju(){
    for(int i=0; i<preg.size(); i++) preg[i]=nullptr;
    preg.resize(0);
}

void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta){
    if(preg.size()==0) throw std::range_error("Prazna kolekcija");
    
    std::string poredim=ime_pacijenta;
    int koliko=preg.size();
    for(int i=0; i<koliko; i++){
        std::string saCim;
        saCim=preg[i]->DajImePacijenta();
        if(poredim==saCim){
            preg[i]=nullptr;
            for(int j=i; j<koliko-1; j++){
                preg[j]=preg[j+1];
            }
            preg.resize(koliko-1);
            i--;
            koliko--;
        }
    }
}

void Pregledi::ObrisiNajranijiPregled(){
    if(preg.size()==0) throw std::range_error("Prazna kolekcija");
    Pregled koji(DajNajranijiPregled());
    int dan1(0), mjesec1(0), godina1(0), sat1(0), min1(0);
    Datum kojiDatum=koji.DajDatumPregleda();
    std::tuple<int, int, int> pomocni=kojiDatum.Ocitaj();
    dan1=std::get<0>(pomocni);
    mjesec1=std::get<1>(pomocni);
    godina1=std::get<2>(pomocni);
    
    Vrijeme pomocnoVrijeme=koji.DajVrijemePregleda();
    std::pair<int, int> pomVri=pomocnoVrijeme.Ocitaj();
    sat1=pomVri.first;
    min1=pomVri.second;
    int koliko=preg.size();
     for(int i=0; i<koliko; i++){
        
        int dan2(0), mjesec2(0), godina2(0), sat2(0), min2(0);
        Datum kadaDatum=preg[i]->DajDatumPregleda();
        std::tuple<int, int, int> pomocniTuple=kadaDatum.Ocitaj();
        dan2=std::get<0>(pomocniTuple);
        mjesec2=std::get<1>(pomocniTuple);
        godina2=std::get<2>(pomocniTuple);
        
        Vrijeme pomVrijeme=preg[i]->DajVrijemePregleda();
        std::pair<int, int> pom=pomVrijeme.Ocitaj();
        sat2=pom.first;
        min2=pom.second;
        
        if(dan1==dan2 && mjesec1==mjesec2 && godina1==godina2 && sat1==sat2 && min1==min2){
            preg[i]=nullptr;
            for(int j=i; j<koliko-1; j++){
                preg[j]=preg[j+1];
            }
            
            preg.resize(koliko-1);
    
            return;
        }
        
    }
}

void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const{
    std::vector<std::shared_ptr<Pregled>> pokazivaci(preg.size());
    
    for(int i=0; i<preg.size(); i++){
        pokazivaci[i]=preg[i];
    }
    
    std::sort(pokazivaci.begin(), pokazivaci.end(), [](std::shared_ptr<Pregled> prvi,std::shared_ptr<Pregled> drugi){
            if(DolaziPrije(*prvi, *drugi)) return true;
            return false;
    });
    for(int i=0; i<preg.size(); i++){
    
        if( pokazivaci[i]->DajDatumPregleda().Ocitaj()==datum.Ocitaj()) pokazivaci[i]->Ispisi();
         
    }
}

void Pregledi::IspisiSvePreglede() const{
    std::vector<std::shared_ptr<Pregled>> pokazivaci(preg.size());
    for(int i=0; i<preg.size(); i++){
        pokazivaci[i]=preg[i];
    }
    
    std::sort(pokazivaci.begin(), pokazivaci.end(), [](std::shared_ptr<Pregled> prvi, std::shared_ptr<Pregled> drugi){
            if(DolaziPrije(*prvi, *drugi)) return true;
            return false;
    });
    for(int i=0; i<preg.size(); i++){
         pokazivaci[i]->Ispisi();
        
    }
}
int main(){
    
    
    Pregledi pacijenti;
    
   
    while(true){
    
        std::cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        std::string imePacijenta;
        std::getline(std::cin, imePacijenta);
        
        if(imePacijenta=="kraj") break;
    
        std::cout<<"Unesite dan mjesec i godinu pregleda: ";
        int unosDan(0), unosMjesec(0), unosGodina(0);
        std::cin>>unosDan>> unosMjesec >>unosGodina;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        try{
            Datum dat(unosDan, unosMjesec, unosGodina);
        }
        catch(std::domain_error e){
            std::cout<<e.what();
            return 0;
        }
        std::cout<<"Unesite sate i minute pregleda: ";
       
        int unosSat(0), unosMin(0);
        std::cin>>unosSat>>unosMin;
        try{
            Vrijeme vri(unosSat, unosMin);
        }
        catch(std::domain_error e){
            std::cout<<e.what();
            return 0;
        }
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        pacijenti.RegistrirajPregled(imePacijenta, unosDan, unosMjesec, unosGodina, unosSat, unosMin);
    
        
    }
    
    
    
     std::cout<<"Trenutno su registrovani sljedeci pregledi\n";
    pacijenti.IspisiSvePreglede();
    int opcija(0);
    
   
    
    while(opcija!=7){
        std::cout<<"\nOdaberite jednu od sljedecih opcija\n";
        std::cout<<"1 - Broj pregleda na datum\n";
        std::cout<<"2 - Najraniji pregled\n";
        std::cout<<"3 - Obrisi pregled pacijenta\n";
        std::cout<<"4 - Obrisi najraniji pregled\n";
        std::cout<<"5 - Ispisi sve pregleda na datum\n";
        std::cout<<"6 - Ispisi sve preglede\n";
        std::cout<<"7 - Kraj programa\n";
        
        std::cin>>opcija;
        
        if(opcija==1){
            std::cout<<"Unesite dan mjesec i godinu : ";
            int izaberiDan(0), izaberiMjesec(0), izaberiGodinu(0);
            std::cin>>izaberiDan>>izaberiMjesec>>izaberiGodinu;
            try{
                Datum pomocni(izaberiDan, izaberiMjesec, izaberiGodinu);
                std::cout<<"Broj pregleda na datum "<<izaberiDan<<" "<<izaberiMjesec<<" "<<izaberiGodinu<<" je: ";
                std::cout<<pacijenti.DajBrojPregledaNaDatum(pomocni);
                std::cout<<std::endl;
            }
            catch(std::domain_error e){
                std::cout<<e.what();
            }
        }
        
        if(opcija==2){
            try{
                Pregled ranoNekad=pacijenti.DajNajranijiPregled();
                std::cout<<"Najraniji pregled je:\n";
                ranoNekad.Ispisi();
            }
            catch(std::range_error e){
                std::cout<<e.what();
            }
        }
        
        if(opcija==3){
            try{
                int prije=pacijenti.DajBrojPregleda();
                std::cout<<"Unesite ime pacijenta: ";
                std::string ime;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::getline(std::cin, ime);
                pacijenti.ObrisiPregledePacijenta(ime);
                if(pacijenti.DajBrojPregleda()!=prije) std::cout<<"Uspjesno obrisano "<<prije-pacijenti.DajBrojPregleda()<<" pregleda\n";
            }
            catch(std::range_error e){
                std::cout<<e.what();
            }
        }
        
        if(opcija==4){
            try{
                pacijenti.ObrisiNajranijiPregled();
                std::cout<<"Najraniji pregled uspjesno obrisan\n";
            }
            catch(std::range_error e){
                std::cout<<e.what();
            }
        }
        if(opcija==5){
            try{
                std::cout<<"Unesite dan mjesec i godinu : ";
                int dan1(0), mjesec1(0), godina1(0);
                std::cin>>dan1>>mjesec1>>godina1;
                Datum koji(dan1, mjesec1, godina1);
                std::cout<<"Pregledi na datum 18 12 2018 su:\n";
                pacijenti.IspisiPregledeNaDatum(koji);
            }
            catch(std::domain_error e){
                std::cout<<e.what();
            }
        }
        if(opcija==6){
            pacijenti.IspisiSvePreglede();
        }
        if(opcija==7) break;
    }
    
    
    return 0;
}