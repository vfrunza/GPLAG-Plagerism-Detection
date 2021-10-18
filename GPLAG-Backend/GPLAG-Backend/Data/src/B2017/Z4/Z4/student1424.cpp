/B2017/2018: Zadaća 4, Zadatak 4
#include <iostream>
#include <tuple>
#include <utility>
#include <iomanip>
#include <initializer_list>
#include <new>
#include <iterator>
#include <algorithm>
#include <string>
#include <memory>
#include <vector>

class Datum
{
    int dan, mjesec, godina;
public:
    Datum(int dan, int mjesec, int godina) {
        Postavi(dan,mjesec,godina);
    }
    void Postavi(int dan, int mjesec, int godina);
    std::tuple<int, int , int> Ocitaj() const {
        return std::make_tuple(dan,mjesec,godina);
    }
    void Ispisi() const {
        std::cout<<dan<<"/"<<mjesec<<"/"<<godina;
    }
};
void Datum::Postavi(int dan, int mjesec, int godina)
{
    int dani[] {31,28,31,30,31,30,31,31,30,31,30,31};
    if((godina%4==0 && godina%100!=0) || godina%400==0) dani[1]++;
    if(godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>dani[mjesec-1]) throw std::domain_error("Neispravan datum");
    Datum::dan=dan;
    Datum::mjesec=mjesec;
    Datum::godina=godina;
}

class Vrijeme
{
    int sati, minute;
public:
    Vrijeme(int sati, int minute) {
        Postavi(sati,minute);
    }
    void Postavi(int sati, int minute);
    std::pair<int, int> Ocitaj() const {
        return std::make_pair(sati, minute);
    }
    void Ispisi() const {
        std::cout<<std::right<<std::setw(2)<<std::setfill('0')<<sati<<":"<<std::setw(2)<<minute;
    }
};

void Vrijeme::Postavi(int sati, int minute)
{
    if(sati<0 || sati>23 || minute<0 || minute>59) throw std::domain_error("Neispravno vrijeme");
    Vrijeme::sati=sati;
    Vrijeme::minute=minute;
}

class Pregled
{
    std::string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;
public:
    Pregled (const std::string &ime_pacijenta, const Datum& datum_pregleda, const Vrijeme &vrijeme_pregleda):
        ime_pacijenta(ime_pacijenta), datum_pregleda(datum_pregleda), vrijeme_pregleda(vrijeme_pregleda) {}
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda,
            int sati_pregleda, int minute_pregleda): ime_pacijenta(ime_pacijenta), datum_pregleda(dan_pregleda, mjesec_pregleda, godina_pregleda),
        vrijeme_pregleda(sati_pregleda,minute_pregleda) {}
    void PromijeniPacijenta(const std::string &ime_pacijenta) {
        Pregled::ime_pacijenta=ime_pacijenta;
    }
    void PromijeniDatum(const Datum &novi_datum) {
        datum_pregleda=novi_datum;
    }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme) {
        vrijeme_pregleda=novo_vrijeme;
    }
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImePacijenta() const {
        return ime_pacijenta;
    }
    Datum DajDatumPregleda() const {
        return datum_pregleda;
    }
    Vrijeme DajVrijemePregleda() const {
        return vrijeme_pregleda;
    }
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
    void Ispisi() const {
        std::cout<<std::left<<std::setw(30)<<std::setfill(' ')<<ime_pacijenta;
        datum_pregleda.Ispisi();
        std::cout<<" ";
        vrijeme_pregleda.Ispisi();
        std::cout<<std::endl;
    }

};

void Pregled::PomjeriDanUnaprijed()
{
    int dani[] {31,28,31,30,31,30,31,31,30,31,30,31};
    int dan, mjesec, godina;
    std::tie(dan, mjesec, godina)=datum_pregleda.Ocitaj();
    if((godina%4==0 && godina%100!=0) || godina%400==0) dani[1]++;

    dan++;
    if(dan>dani[mjesec-1]) {
        dan=1;
        mjesec++;
    }
    if(mjesec>12) {
        mjesec=1;
        godina++;
    }
    datum_pregleda.Postavi(dan, mjesec, godina);
}
void Pregled::PomjeriDanUnazad()
{
    int dani[] {31,28,31,30,31,30,31,31,30,31,30,31};
    int dan, mjesec, godina;
    std::tie(dan, mjesec, godina)=datum_pregleda.Ocitaj();
    if((godina%4==0 && godina%100!=0) || godina%400==0) dani[1]++;

    dan--;
    if(dan<1) {
        if(mjesec>=2) {
            dan=dani[mjesec-2];
            mjesec--;
        } else {
            dan=31;
            mjesec=12;
            godina--;
        }
    }
    datum_pregleda.Postavi(dan, mjesec, godina);

}

bool Pregled::DolaziPrije(const Pregled &p1, const Pregled &p2)
{
    int dan1, mjesec1, godina1, dan2, mjesec2, godina2;
    std::tie(dan1, mjesec1, godina1)=p1.datum_pregleda.Ocitaj();
    std::tie(dan2, mjesec2, godina2)=p2.datum_pregleda.Ocitaj();
    if(godina1<godina2) return true;
    if(godina1>godina2) return false;
    if(mjesec1<mjesec2) return true;
    if(mjesec1>mjesec2) return false;
    int sati1,minute1, sati2, minute2;
    std::tie(sati1,minute1)=p1.vrijeme_pregleda.Ocitaj();
    std::tie(sati2,minute2)=p2.vrijeme_pregleda.Ocitaj();
    if(dan1<dan2) return true;
    if(dan1>dan2) return false;
    if(sati1<sati2) return true;
    if(sati1>sati2) return false;
    if(minute1<minute2) return true;
    return false;
}
typedef std::shared_ptr<Pregled> Pametni;
 void  sortiraj(std::vector<Pametni> &pregledi)  {
        std::sort(pregledi.begin(), pregledi.end(), [](Pametni p1, Pametni p2)->bool {return Pregled::DolaziPrije(*p1, *p2);});
    }
class Pregledi
{
    std::vector<Pametni> pregledi;
    void Obrisi();
    // void Brisanje (Pregled**it);
    Pametni Najraniji_pregled() const {
        auto it=(std::min_element(pregledi.begin(), pregledi.end(), [](Pametni p,Pametni p1)->bool {
            return Pregled::DolaziPrije(*p,*p1);
        }));
        if(it==pregledi.end())
            throw std::domain_error("Nema registriranih pregleda");


        return *it;

    }
   
public:
    explicit Pregledi()=default;
    Pregledi(std::initializer_list<Pregled> spisak_pregleda);
    ~Pregledi();
    Pregledi(const Pregledi &pregledi);
    Pregledi (Pregledi && pregledi);
    Pregledi &operator = (const Pregledi &pregledi);
    Pregledi &operator = (Pregledi &&pregledi);
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme& vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda,
                            int sati_pregleda, int minute_pregleda);
    void RegistrirajPregled(Pametni pregled);
    int DajBrojPregleda() const {
        return pregledi.size();
    }
    int DajBrojPregledaNaDatum(const Datum &datum) const;

    Pregled& DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum (const Datum &datum) const;
    void IspisiSvePreglede () const;

};
bool Uporedi(const Datum &datum, Pametni p)
{
    int mjesec1,dan1,godina1,mjesec2,godina2,dan2;
    std::tie(dan1,mjesec1,godina1)=p->DajDatumPregleda().Ocitaj();
    std::tie(dan2,mjesec2,godina2)=datum.Ocitaj();
    return dan1==dan2 && mjesec1==mjesec2 && godina1==godina2;

}
int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const
{
    return std::count_if(pregledi.begin(), pregledi.end(), [datum](Pametni p)-> bool {
        /*int mjesec1,dan1,godina1,mjesec2,godina2,dan2;
        std::tie(dan1,mjesec1,godina1)=p->DajDatumPregleda().Ocitaj();
        std::tie(dan2,mjesec2,godina2)=datum.Ocitaj();
        return dan1==dan2 && mjesec1==mjesec2 && godina1==godina2;*/
        return Uporedi(datum, p);
    });
}
Pregled& Pregledi:: DajNajranijiPregled()
{
    //provjeriti moze li za non const
    return *Najraniji_pregled();
}
Pregled Pregledi:: DajNajranijiPregled() const
{
    return *Najraniji_pregled();
}

Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda): pregledi(spisak_pregleda.size())
{

    try {
        int i(0);
        for( std::initializer_list<Pregled>::iterator it=spisak_pregleda.begin(); it!=spisak_pregleda.end(); it++) {
            pregledi[i]=std::make_shared<Pregled>(it[i]);
            i++;
        }
    } catch (std::bad_alloc) {
        for(int j=0; j<spisak_pregleda.size(); j++) {
            /* delete pregledi[j];*/
            pregledi[j]=nullptr;
        }
        // delete[] pregledi;
        pregledi.resize(0);
        //provjeriti je li treba baciti izuzteak pri losoj konstrukciji!!!!!
        throw;
    }
}

/*void Pregledi::Obrisi()
{
    for(int i=0; i<broj_pregleda; i++) {
        delete pregledi[i];
        pregledi[i]=nullptr;
    }
    delete[] pregledi;
    pregledi=nullptr;
}*/
Pregledi::~Pregledi()=default;


Pregledi::Pregledi (const Pregledi &pregledi):
    pregledi(pregledi.pregledi.size())
{
    try {
        for(int i=0; i<pregledi.pregledi.size(); i++) {
            Pregledi::pregledi[i]=std::make_shared<Pregled> (*(pregledi.pregledi[i]));
        }
    } catch(...) {//provjeriti je li brise fino
        for(int i=0; i<Pregledi::pregledi.size(); i++)  Pregledi::pregledi[i]=nullptr;



    }
}
Pregledi::Pregledi(Pregledi && pregledi) : pregledi(std::move(pregledi.pregledi)) {}
Pregledi& Pregledi :: operator= (const Pregledi & pregledi)
{

    int velicina=(*this).pregledi.size();
    if((*this).pregledi.size()<pregledi.pregledi.size()) {

        try {
            for(int i=(*this).pregledi.size(); i<pregledi.pregledi.size(); i++) {
                Pregledi::pregledi.push_back(std::make_shared<Pregled>(*(pregledi.pregledi[i])));
            }
        } catch(...) {
            for(int i=velicina; i<pregledi.pregledi.size(); i++) {
                Pregledi::pregledi[i]=nullptr;
            }
            throw;
        }
    } else {
        for(int i=pregledi.pregledi.size(); i<velicina; i++) {
            Pregledi::pregledi[i]=nullptr;
        }
        (*this).pregledi.resize(pregledi.pregledi.size());
    }

    for(int i=0; i<Pregledi::pregledi.size(); i++) {
        *(Pregledi::pregledi[i])=*(pregledi.pregledi[i]);
    }
    return *this;
}
Pregledi& Pregledi:: operator = (Pregledi && pregledi)
{

    if(&pregledi!=this) {
        Pregledi::pregledi=std::move(pregledi.pregledi);
    }
    return *this;

}
void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme& vrijeme_pregleda)
{

    try {
        pregledi.push_back(std::make_shared <Pregled>(ime_pacijenta, datum_pregleda, vrijeme_pregleda));

    }
    //provjeriti za izuzetke sta treba
    catch(...) {

        throw;
    }
}
void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda,
                                  int sati_pregleda, int minute_pregleda)
{

    try {
        Pregledi::pregledi.push_back(std::make_shared<Pregled>(ime_pacijenta, dan_pregleda,mjesec_pregleda,godina_pregleda, sati_pregleda,minute_pregleda));

    }
    //provjeriti za izuzetke sta treba
    catch(...) {
        throw;
    }
}
void Pregledi::RegistrirajPregled(Pametni pregled)
{

    pregledi.push_back(pregled);
}
void Pregledi::IsprazniKolekciju()
{
    for(int i=0; i<pregledi.size(); i++) {
        pregledi[i]=nullptr;
    }
    pregledi.resize(0);
}
void Pregledi::ObrisiNajranijiPregled()
{
    
    auto it=(std::min_element(pregledi.begin(), pregledi.end(), [](Pametni p,Pametni p1)->bool {
        return Pregled::DolaziPrije(*p,*p1);
    }));

    if(it==pregledi.end()) throw std::range_error("Prazna kolekcija");
    pregledi.erase(it);
  

}

void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta)
{
    do {

        auto it=std::find_if(pregledi.begin(), pregledi.end(), [ime_pacijenta](Pametni p1)->bool {
            return p1->DajImePacijenta()==ime_pacijenta;
        });
        if(it==pregledi.end()) break;
        

        pregledi.erase(it);

    } while(true);
}
void Pregledi::IspisiPregledeNaDatum(const Datum&datum) const
{
  std::vector<Pametni>novi(this->pregledi);
    sortiraj(novi);
    std::for_each(novi.begin(), novi.end(), [datum](Pametni p)->void {
        if(Uporedi(datum, p)) p->Ispisi();
    });
}

void Pregledi::IspisiSvePreglede() const
{
    std::vector<Pametni>novi(this->pregledi);
   sortiraj(novi);

    std::for_each(novi.begin(), novi.end(), [](Pametni p) {
        p->Ispisi();
    });
}


int main ()
{
    try {

        std::string ime;
        Pregledi bolnica;
        do {

            std::cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";



            std::getline(std::cin, ime);
            if(ime==std::string("kraj"))  break;
            std::cout<<"Unesite dan mjesec i godinu pregleda: ";
            int dan, mjesec, godina;
            std::cin>>dan>>mjesec>>godina;
            std::cout<<"Unesite sate i minute pregleda: ";
            int sati, minute;
            std::cin>>sati>>minute;
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            try {
                bolnica.RegistrirajPregled(ime, dan, mjesec, godina, sati, minute);

            } catch(std::domain_error iz) {
                std::cout<<iz.what()<<std::endl;
            } catch(std::logic_error iz) {
                std::cout<<iz.what()<<std::endl;
            } catch(std::range_error iz) {
                std::cout<<iz.what()<<std::endl;
                break;
            }

        } while(true);
        std::cout<<"Trenutno su registrovani sljedeci pregledi"<<std::endl;
        bolnica.IspisiSvePreglede();
        int opcija;
        do {
            std::cout<<std::endl<<"Odaberite jednu od sljedecih opcija"<<std::endl
                     <<"1 - Broj pregleda na datum"<<std::endl
                     <<"2 - Najraniji pregled"<<std::endl
                     <<"3 - Obrisi pregled pacijenta"<<std::endl
                     <<"4 - Obrisi najraniji pregled"<<std::endl
                     <<"5 - Ispisi sve pregleda na datum"<<std::endl
                     <<"6 - Ispisi sve preglede"<<std::endl
                     <<"7 - Kraj programa"<<std::endl;


            std::cin>>opcija;
            std::cin.clear();
            std::cin.ignore(1000,'\n');

            if(opcija==1 || opcija==5) {
                std::cout<<"Unesite dan mjesec i godinu : ";
                int dan, mjesec, godina;
                std::cin>>dan;
                std::cin>>mjesec;
                std::cin>>godina;

                std::cin.clear();
                std::cin.ignore(1000,'\n');

                Datum d(dan,mjesec,godina);
                //provjeriti je li treba provjera
                if(opcija==1) {
                    std::cout<<"Broj pregleda na datum "<<dan<<" "<<mjesec<<" "<<godina<<" je: "
                             <<bolnica.DajBrojPregledaNaDatum(d);
                    std::cout<<std::endl;
                } else if(opcija==5) {
                    std::cout<<"Pregledi na datum "
                             <<dan<<" "<<mjesec<<" "<<godina<<" su:"<<std::endl;
                    bolnica.IspisiPregledeNaDatum(d);
                }
            } else if(opcija==2) {
                std::cout<<"Najraniji pregled je: "<<std::endl;
                bolnica.DajNajranijiPregled().Ispisi();
            } else if(opcija==3) {
                std::cout<<"Unesite ime pacijenta: ";
                //  std::cin.clear();std::cin.ignore(1000,'\n');

                std::string ime1;
                std::getline(std::cin, ime1);
                int broj=bolnica.DajBrojPregleda();
                bolnica.ObrisiPregledePacijenta(ime1);
                if(broj>bolnica.DajBrojPregleda())  std::cout<<"Uspjesno obrisano "<<broj-bolnica.DajBrojPregleda()<<" pregleda"<<std::endl;
            } else if(opcija==4) {
                try {
                    bolnica.ObrisiNajranijiPregled();
                    std::cout<<"Najraniji pregled uspjesno obrisan"<<std::endl;
                } catch(std::range_error iz) {
                    std::cout<<iz.what()<<std::endl;
                }
            } else if(opcija==6) {
                bolnica.IspisiSvePreglede();
            } else if(opcija==7) break;

        } while(opcija!=7);


    } catch(std::domain_error iz) {
        std::cout<<iz.what();
    }
    return 0;
}
