/B2017/2018: Zadaća 4, Zadatak 4

// Kopirao sam kod iz zadatka 3 u zadatak 4
#include <iostream>
#include <tuple>
#include <stdexcept>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <memory>

typedef std::tuple <int,int,int> TaplIntova;
typedef std::pair <int,int> ParIntova;

class Datum
{
    friend class Pregled;
    friend class Pregledi;
    int dan,mjesec,godina;
    static void Izuzetak(int dan, int mjesec, int godina) {
        int broj_dana [] {31,28,31,30,31,30,31,31,30,31,30,31};
        if ((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0) broj_dana[1]++;
        if (godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>broj_dana[mjesec-1]) throw std::domain_error ("Neispravan datum");
    }
    
    int DajDan() const {
        return dan;
    }
    int DajMjesec() const {
        return mjesec;
    }
    int DajGodinu() const {
        return godina;
    }
    
    Datum &PostaviDan (int dan) {
        int broj_dana [] {31,28,31,30,31,30,31,31,30,31,30,31};
        if ((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0) broj_dana[1]++; // za prestupne godine

        if (dan>broj_dana[mjesec-1]) {
            if (mjesec==12) { // u slucaju da treba preci na sljedecu godinu
                godina++;
                mjesec=0;
            }
            dan=1;
            mjesec++;
        } // prelaz u mjesec+1

        else if (dan==0) {
            if (mjesec==1) {  // u slucaju da treba preci na sljedecu godinu
                godina--;
                mjesec=13;  // posto ce ga umanjiti u daljem dijelu koda
            }
            mjesec--;
            dan=broj_dana[mjesec-1];
        }  // prelaz u mjesec - 1

        Datum::dan=dan;
        Izuzetak(dan,mjesec,godina);
        return *this;
    }
public:
    Datum (int dan, int mjesec, int godina) {
        Izuzetak(dan,mjesec,godina);
        Datum::dan=dan;
        Datum::mjesec=mjesec;
        Datum::godina=godina;
    }

    void Postavi (int dan, int mjesec, int godina) {
        Izuzetak(dan,mjesec,godina);
        Datum::dan=dan;
        Datum::mjesec=mjesec;
        Datum::godina=godina;
    }

    TaplIntova Ocitaj () const {
        return std::tie(dan,mjesec,godina);
    }

    void Ispisi () const {
        std::cout<<dan<<"/"<<mjesec<<"/"<<godina;
    }
};

class Vrijeme
{
    friend class Pregled;
    friend class Pregledi;
    int sati, minute;
    static void Izuzetak (int sati, int minute) {
        if (sati<0 || sati>23 || minute<0 || minute > 59) throw std::domain_error ("Neispravno vrijeme");
    }
    int DajSate() const {
        return sati;
    }
    int DajMinute() const {
        return minute;
    }
public:
    Vrijeme (int sati, int minute) {
        Izuzetak(sati,minute);
        Vrijeme::sati=sati;
        Vrijeme::minute=minute;
    }

    void Postavi (int sati, int minute) {
        Vrijeme(sati,minute);
    }

    ParIntova Ocitaj () const{
        return std::make_pair(sati,minute);
    }

    void Ispisi() const {
        if (sati<10 && minute<10) std::cout<<"0"<<sati<<":0"<<minute;
        else if (sati<10 && minute>10) std::cout<<"0"<<sati<<":"<<minute;
        else if (sati>10 && minute<10) std::cout<<sati<<":0"<<minute;
        else std::cout<<sati<<":"<<minute;
    }
};

class Pregled
{
    std::string ime_pacijenta;
    Datum datum;
    Vrijeme vrijeme;
public:
    // Konstruktor
    Pregled ( const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda ) :
        ime_pacijenta (ime_pacijenta), datum(datum_pregleda), vrijeme(vrijeme_pregleda) {}

    Pregled (const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda,
             int minute_pregleda) : ime_pacijenta(ime_pacijenta), datum(dan_pregleda,mjesec_pregleda,godina_pregleda), vrijeme(sati_pregleda,minute_pregleda) {}

    void PromijeniPacijenta (const std::string &ime_pacijenta) {
        Pregled::ime_pacijenta=ime_pacijenta;
    }

    void PromijeniDatum (const Datum &novi_datum) {
        Pregled::datum=novi_datum;
    }

    void PromijeniVrijeme (const Vrijeme &novo_vrijeme) {
        Pregled::vrijeme=novo_vrijeme;
    }

    void PomjeriDanUnaprijed () {
        Pregled::datum.PostaviDan(Pregled::datum.DajDan()+1);
    }

    void PomjeriDanUnazad () {
        Pregled::datum.PostaviDan(Pregled::datum.DajDan()-1);
    }

    std::string DajImePacijenta () const {
        return ime_pacijenta;
    }

    Datum DajDatumPregleda () const {
        return datum;
    }

    Vrijeme DajVrijemePregleda () const {
        return vrijeme;
    }

    static bool DolaziPrije (const Pregled &p1, const Pregled &p2) {
        if (p1.DajDatumPregleda().DajGodinu()<p2.DajDatumPregleda().DajGodinu()) return true;
        else if (p1.DajDatumPregleda().DajGodinu()>p2.DajDatumPregleda().DajGodinu()) return false;
        else {
            if (p1.DajDatumPregleda().DajMjesec()<p2.DajDatumPregleda().DajMjesec()) return true;
            else if (p1.DajDatumPregleda().DajMjesec()>p2.DajDatumPregleda().DajMjesec()) return false;
            else {
                if (p1.DajDatumPregleda().DajDan()<p2.DajDatumPregleda().DajDan()) return true;
                else if (p1.DajDatumPregleda().DajDan()>p2.DajDatumPregleda().DajDan()) return false;
                else {
                    if (p1.DajVrijemePregleda().DajSate()<p2.DajVrijemePregleda().DajSate()) return true;
                    else if (p1.DajVrijemePregleda().DajSate()>p2.DajVrijemePregleda().DajSate()) return false;
                    else {
                        if (p1.DajVrijemePregleda().DajMinute()<p2.DajVrijemePregleda().DajMinute()) return true;
                    }
                }
            }
        }
        return false;
    }

    void Ispisi () const {
        std::cout<<std::left<<std::setw(30)<<ime_pacijenta;
        Pregled::datum.Ispisi();
        std::cout<<" ";
        Pregled::vrijeme.Ispisi();
        std::cout<<std::endl;
    }
};

typedef std::vector<std::shared_ptr<Pregled>> VektorPametnihPregleda;
typedef std::shared_ptr<Pregled> PametniPregled;

class Pregledi
{
    VektorPametnihPregleda pregledi;
public:

    explicit Pregledi ():  pregledi(0,nullptr) {}

    Pregledi (std::initializer_list <Pregled> spisak_pregleda) : pregledi (0,nullptr) {
        for (int i = 0; i<spisak_pregleda.size(); i++) {
            PametniPregled pregled (new Pregled (*(spisak_pregleda.begin()+i)));
            pregledi.push_back(pregled);
        }
    }
    
    Pregledi (const Pregledi &pregledi) {
        for (int i = 0; i<pregledi.pregledi.size(); i++) {
            PametniPregled pregled(new Pregled(*pregledi.pregledi.at(i)));
            Pregledi::pregledi.push_back(pregled);
        }
    }
// Pomjerajuci konstruktor
    Pregledi (Pregledi &&pregledi) : pregledi(pregledi.pregledi) {
        pregledi.pregledi.resize(0);
    }

    Pregledi &operator = (const Pregledi &pregledi);

    Pregledi &operator = (Pregledi &&pregledi);

    void RegistrirajPregled (const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);

    void RegistrirajPregled (const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda,
                             int sati_pregleda, int minute_pregleda);

    void RegistrirajPregled (PametniPregled pregled);

    int DajBrojPregleda () const {
        return pregledi.size();
    }

    int DajBrojPregledaNaDatum (const Datum &datum) const {
        return std::count_if (pregledi.begin(), pregledi.end(), [datum](PametniPregled pregled) {
            return (pregled->DajDatumPregleda().DajGodinu()==datum.DajGodinu() && pregled->DajDatumPregleda().DajMjesec()==datum.DajMjesec() &&
                    pregled->DajDatumPregleda().DajDan()==datum.DajDan());
        });
    }

    Pregled &DajNajranijiPregled () {
        if (pregledi.size()==0) throw std::domain_error ("Nema registriranih pregleda");
        auto it=std::min_element (pregledi.begin(), pregledi.end(), [] (PametniPregled pregled1, PametniPregled pregled2) {
            return Pregled::DolaziPrije(*pregled1, *pregled2);
        });
        return (**it);
    }
    
    Pregled DajNajranijiPregled() const {
        if (pregledi.size()==0) throw std::domain_error ("Nema registriranih pregleda");
        auto it=std::min_element (pregledi.begin(), pregledi.end(), [] (PametniPregled pregled1, PametniPregled pregled2) {
            return Pregled::DolaziPrije(*pregled1, *pregled2);
        });
        return (**it);
    }

    void IsprazniKolekciju () {
        pregledi.resize(0);
    } 

    void ObrisiNajranijiPregled ();

    void ObrisiPregledePacijenta (const std::string &ime_pacijenta);

    void IspisiPregledeNaDatum (const Datum &datum) const {
        for (int i = 0; i<pregledi.size(); i++)
            if (pregledi[i]->DajDatumPregleda().DajGodinu()==datum.DajGodinu() && pregledi[i]->DajDatumPregleda().DajMjesec()==datum.DajMjesec() &&
                    pregledi[i]->DajDatumPregleda().DajDan()==datum.DajDan()) pregledi[i]->Ispisi();
    }
    
    void IspisiSvePreglede() const;
};
    
void Pregledi::IspisiSvePreglede () const {
        if (pregledi.size()==0) return;
        std::vector<int> VektorUspjesnih(pregledi.size());
        for (int j = 0; j<pregledi.size(); j++) {
            int redni_broj(0);   // redni broj j-tog pregleda kojeg treba ispisati
            for (int i = 0; i<pregledi.size(); i++) {
                if (i==j) continue;
                if (!Pregled::DolaziPrije(*pregledi[j], *pregledi[i])) {
                    redni_broj++;
                }
            }
            VektorUspjesnih.at(redni_broj)=j;  // ubacujem u redni broh mjesto j (redni broj j-tog pregleda)
        }
        for (int i = 0; i<pregledi.size(); i++)
            pregledi[VektorUspjesnih.at(i)]->Ispisi();
    }


Pregledi &Pregledi::operator = (const Pregledi &pregledi)
{
    Pregledi::pregledi.resize(0);
    for (int i = 0; i<pregledi.pregledi.size(); i++)
    Pregledi::pregledi.push_back(pregledi.pregledi.at(i));
    return *this;
}

Pregledi &Pregledi::operator =(Pregledi &&pregledi)
{
    Pregledi::pregledi.resize(0);
    for (int i = 0; i<pregledi.pregledi.size(); i++)
    Pregledi::pregledi.push_back(pregledi.pregledi.at(i));
    pregledi.pregledi.resize(0);
    return *this;
}

void Pregledi::RegistrirajPregled (const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda)
{
    PametniPregled pregled (new Pregled (ime_pacijenta,datum_pregleda,vrijeme_pregleda));
    pregledi.push_back(pregled);
}

void Pregledi::RegistrirajPregled (const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda,
                                   int sati_pregleda, int minute_pregleda)
{
    PametniPregled pregled (new Pregled (ime_pacijenta,{dan_pregleda,mjesec_pregleda,godina_pregleda},{sati_pregleda,minute_pregleda}));
    pregledi.push_back(pregled);
}

void Pregledi::RegistrirajPregled (PametniPregled pregled)
{
    pregledi.push_back(pregled);
}

void Pregledi::ObrisiPregledePacijenta (const std::string &ime_pacijenta)
{
    for (int i = 0; i<pregledi.size(); i++) 
        if (pregledi.at(i)->DajImePacijenta()==ime_pacijenta) {
            pregledi.erase(pregledi.begin()+i);
            i--;
        }
}

void Pregledi::ObrisiNajranijiPregled ()
{
    if (!pregledi.size()) throw std::range_error ("Prazna kolekcija");
    Pregled pregled(DajNajranijiPregled());
    for (int i = 0; i<pregledi.size(); i++) 
        if (pregledi[i]->DajDatumPregleda().DajGodinu()==pregled.DajDatumPregleda().DajGodinu() && pregledi[i]->DajDatumPregleda().DajMjesec()==pregled.DajDatumPregleda().DajMjesec() &&
                pregledi[i]->DajDatumPregleda().DajDan()==pregled.DajDatumPregleda().DajDan()) {
            pregledi.erase(pregledi.begin()+i);
            break;
        }
}

int main ()
{
    try {
        Pregledi pregledi;
        while(1) {
            std::cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
            std::string ime_pacijenta;
            std::getline(std::cin, ime_pacijenta);
            if (ime_pacijenta=="kraj") break;
            int dan, mjesec, godina, sati, minute;
            std::cout<<"Unesite dan mjesec i godinu pregleda: ";
            std::cin>>dan>>mjesec>>godina;
            std::cout<<"Unesite sate i minute pregleda: ";
            std::cin>>sati>>minute;
            pregledi.RegistrirajPregled(ime_pacijenta,dan,mjesec,godina,sati,minute);
            std::cin.ignore(10000,'\n');
        }
        std::cout<<"Trenutno su registrovani sljedeci pregledi "<<std::endl;
        pregledi.IspisiSvePreglede();
        std::cout<<std::endl;
        while (1) { // popraviti 5-icu
            std::cout<<"Odaberite jednu od sljedecih opcija"<<std::endl<<"1 - Broj pregleda na datum"<<std::endl<<"2 - Najraniji pregled"<<
                     std::endl<<"3 - Obrisi pregled pacijenta"<<std::endl<<"4 - Obrisi najraniji pregled"<<std::endl<<"5 - Ispisi sve pregleda na datum"<<
                     std::endl<<"6 - Ispisi sve preglede"<<std::endl<<"7 - Kraj programa"<<std::endl;
            int kod;
            std::cin>>kod;
            if (kod==7) return 0;
            else if (kod==6) pregledi.IspisiSvePreglede();
            else if (kod==1) {
                std::cout<<"Unesite dan mjesec i godinu : ";
                int dan,mjesec,godina;
                std::cin>>dan>>mjesec>>godina;
                std::cout<<"Broj pregleda na datum "<<dan<<" "<<mjesec<<" "<<godina<<" je: "<<pregledi.DajBrojPregledaNaDatum({dan,mjesec,godina})<<std::endl;
            } else if (kod==4) {
                pregledi.ObrisiNajranijiPregled();
                std::cout<<"Najraniji pregled uspjesno obrisan"<<std::endl;
            } else if (kod == 3) {
                std::cout<<"Unesite ime pacijenta: ";
                std::cin.ignore(10000,'\n');
                std::string ime_pacijenta;
                std::getline(std::cin,ime_pacijenta);
                int prije(pregledi.DajBrojPregleda());
                pregledi.ObrisiPregledePacijenta(ime_pacijenta);
                std::cout<<"Uspjesno obrisano "<<prije-pregledi.DajBrojPregleda()<<" pregleda"<<std::endl;
            } else if (kod==2) {
                std::cout<<"Najraniji pregled je: "<<std::endl;
                pregledi.DajNajranijiPregled().Ispisi();
                std::cout<<std::endl;
            } else if (kod==5) {
                std::cout<<"Unesite dan mjesec i godinu : ";
                int dan,mjesec,godina;
                std::cin>>dan>>mjesec>>godina;
                std::cout<<"Pregledi na datum "<<dan<<" "<<mjesec<<" "<<godina<<" su:"<<std::endl;
                pregledi.IspisiPregledeNaDatum({dan,mjesec,godina});
                std::cout<<std::endl;
            } else std::cout<<"Pogresan kod"<<std::endl;
            std::cout<<std::endl;
        }
        /*
        Datum datum(12,12,2013);
        Vrijeme vrijeme (12,12);
        Pregled pregled("Nikola",datum,vrijeme);
        Pregledi lista{pregled,{"Albert",{12,10,1998},{15,15}}};
        
        Pregledi pregledi1(lista),pregledi2;
        
        //pregledi2=(std::move(pregledi1));
        pregledi2=pregledi1;
        
        pregledi2.IspisiSvePreglede();
        pregledi1.IspisiSvePreglede();
        
        pregledi2.IsprazniKolekciju();
        pregledi2.IspisiSvePreglede();
        */
    } catch (std::domain_error izuzetak) {
        std::cout<<izuzetak.what();
    } catch (std::logic_error izuzetak) {
      std::cout<<izuzetak.what();
    } catch (std::range_error izuzetak) {
      std::cout<<izuzetak.what();
    }
    return 0;
}
