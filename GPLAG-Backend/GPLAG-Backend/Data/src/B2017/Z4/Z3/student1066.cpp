/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <tuple>
#include <stdexcept>
#include <iomanip>
#include <algorithm>
#include <vector>

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

    ParIntova Ocitaj () const {
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

class Pregledi
{
    const int max_broj_pregleda;
    int broj_pregleda;
    Pregled **pregledi;

public:

    explicit Pregledi (int max_broj_pregleda): max_broj_pregleda(max_broj_pregleda), broj_pregleda(0), pregledi(new Pregled *[max_broj_pregleda] {}) {}

    Pregledi (std::initializer_list <Pregled> spisak_pregleda) : max_broj_pregleda(spisak_pregleda.size()), broj_pregleda(spisak_pregleda.size()),
        pregledi (new Pregled *[spisak_pregleda.size()] {}) {
        for (int i = 0; i<spisak_pregleda.size(); i++) {
            Pregled *pregled (new Pregled (*(spisak_pregleda.begin()+i)));  // dobijem i-ti pregled unutar liste
            pregledi[i]=pregled;  // i-ti pregled = i-ti pregled sa liste
        }
    }

    ~Pregledi() {
        for (int i = 0; i<broj_pregleda; i++) delete pregledi[i];
        delete [] pregledi;
    }
// Kopirajuci konstruktor
    Pregledi (const Pregledi &pregledi) : max_broj_pregleda(pregledi.max_broj_pregleda), broj_pregleda(pregledi.broj_pregleda),
        pregledi (new Pregled*[pregledi.max_broj_pregleda] {}) {
        for (int i = 0; i<pregledi.broj_pregleda; i++) {
            Pregled *pregled(new Pregled (**(pregledi.pregledi+i)));
            Pregledi::pregledi[i]=pregled;
        }
    }
// Pomjerajuci konstruktor
    Pregledi (Pregledi &&pregledi) : max_broj_pregleda(pregledi.max_broj_pregleda), broj_pregleda(pregledi.broj_pregleda), 
    pregledi(pregledi.pregledi) {
        pregledi.pregledi=nullptr;
        pregledi.broj_pregleda=0;
    }

    Pregledi &operator = (const Pregledi &pregledi);

    Pregledi &operator = (Pregledi &&pregledi);

    void RegistrirajPregled (const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);

    void RegistrirajPregled (const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda,
                             int sati_pregleda, int minute_pregleda);

    void RegistrirajPregled (Pregled *pregled);

    int DajBrojPregleda () const {
        return broj_pregleda;
    }

    int DajBrojPregledaNaDatum (const Datum &datum) const {
        return std::count_if (pregledi, pregledi+broj_pregleda, [datum](Pregled *pregled) {
            return (pregled->DajDatumPregleda().DajGodinu()==datum.DajGodinu() && pregled->DajDatumPregleda().DajMjesec()==datum.DajMjesec() &&
                    pregled->DajDatumPregleda().DajDan()==datum.DajDan());
        });
    }

    Pregled &DajNajranijiPregled () {
        if (!broj_pregleda) throw std::domain_error ("Nema registriranih pregleda");
        auto it=std::min_element (pregledi, pregledi+broj_pregleda, [] (Pregled *pregled1, Pregled *pregled2) {
            return Pregled::DolaziPrije(*pregled1, *pregled2);
        });
        return (**it);
    }
    
    Pregled DajNajranijiPregled() const {
        if (!broj_pregleda) throw std::domain_error ("Nema registriranih pregleda");
        auto it=std::min_element (pregledi, pregledi+broj_pregleda, [] (Pregled *pregled1, Pregled *pregled2) {
            return Pregled::DolaziPrije(*pregled1, *pregled2);
        });
        return (**it);
    }

    void IsprazniKolekciju () {
        if (!broj_pregleda) return; // u slucaju da je vec prazna kolekcija
        for (int i = 0; i<broj_pregleda; i++) {
            delete pregledi[i];
            pregledi[i]=nullptr;
        }
        delete [] pregledi;
        pregledi = nullptr;
        broj_pregleda=0;
    } 

    void ObrisiNajranijiPregled ();

    void ObrisiPregledePacijenta (const std::string &ime_pacijenta);

    void IspisiPregledeNaDatum (const Datum &datum) const {
        for (int i = 0; i<broj_pregleda; i++)
            if (pregledi[i]->DajDatumPregleda().DajGodinu()==datum.DajGodinu() && pregledi[i]->DajDatumPregleda().DajMjesec()==datum.DajMjesec() &&
                    pregledi[i]->DajDatumPregleda().DajDan()==datum.DajDan()) pregledi[i]->Ispisi();
    }
    
    void IspisiSvePreglede() const;
}; 

void Pregledi::IspisiSvePreglede () const {
        if (broj_pregleda==0) return;
        std::vector<int> VektorUspjesnih(broj_pregleda);
        for (int j = 0; j<broj_pregleda; j++) {
            int redni_broj(0);   // redni broj j-tog pregleda kojeg treba ispisati
            for (int i = 0; i<broj_pregleda; i++) {
                if (i==j) continue;
                if (!Pregled::DolaziPrije(*pregledi[j], *pregledi[i])) {
                    redni_broj++;
                }
            }
            VektorUspjesnih.at(redni_broj)=j;  // ubacujem u redni broh mjesto j (redni broj j-tog pregleda)
        }
        for (int i = 0; i<broj_pregleda; i++)
            pregledi[VektorUspjesnih.at(i)]->Ispisi();
    }

Pregledi &Pregledi::operator = (const Pregledi &pregledi)
{
    Pregled **novi_pregledi(new Pregled *[pregledi.max_broj_pregleda]);
    for (int i = 0; i<pregledi.broj_pregleda; i++) {
        Pregled *pregled (new Pregled (**(pregledi.pregledi+i)));
        novi_pregledi[i]=pregled;
    }
    for (int i=0; i<broj_pregleda; i++) delete Pregledi::pregledi[i];
    delete [] Pregledi::pregledi;
    Pregledi::pregledi=novi_pregledi;
    broj_pregleda=pregledi.broj_pregleda;
    Pregledi::pregledi=novi_pregledi;
    return *this;
}

Pregledi &Pregledi::operator =(Pregledi &&pregledi)
{
    std::swap (broj_pregleda, pregledi.broj_pregleda);
    std::swap (Pregledi::pregledi, pregledi.pregledi);
    return *this;
}

void Pregledi::RegistrirajPregled (const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda)
{
    if (broj_pregleda>=max_broj_pregleda) throw std::range_error ("Dostignut maksimalan broj pregleda");
    Pregled *pregled(nullptr);
    pregled = new Pregled (ime_pacijenta,datum_pregleda,vrijeme_pregleda);
    pregledi[broj_pregleda++]=pregled;
}

void Pregledi::RegistrirajPregled (const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda,
                                   int sati_pregleda, int minute_pregleda)
{
    if (broj_pregleda>=max_broj_pregleda) throw std::range_error ("Dostignut maksimalan broj pregleda");
    Pregled *pregled(nullptr);
    Datum datum(dan_pregleda,mjesec_pregleda,godina_pregleda);
    Vrijeme vrijeme (sati_pregleda,minute_pregleda);
    pregled = new Pregled (ime_pacijenta,datum,vrijeme);
    pregledi[broj_pregleda++]=pregled;
}

void Pregledi::RegistrirajPregled (Pregled *pregled)
{
    if (broj_pregleda>=max_broj_pregleda) throw std::range_error ("Dostignut maksimalan broj pregleda");
    pregledi[broj_pregleda++]=pregled;
}

void Pregledi::ObrisiPregledePacijenta (const std::string &ime_pacijenta)
{
    for (int i = 0; i<broj_pregleda; i++) 
        if (pregledi[i]->DajImePacijenta()==ime_pacijenta) {
            delete pregledi[i];
            pregledi[i]=nullptr;
            for (int k = i+1; k<broj_pregleda; k++) {
                pregledi[k-1]=pregledi[k];
                pregledi[k]=nullptr;
            }
            delete pregledi[broj_pregleda-1];
            pregledi[broj_pregleda-1]=nullptr;
            broj_pregleda--;
            i--;
        }
}

void Pregledi::ObrisiNajranijiPregled ()
{   
    if (!broj_pregleda) throw std::range_error ("Prazna kolekcija");
    Pregled pregled(DajNajranijiPregled());
    for (int i = 0; i<broj_pregleda; i++) 
        if (pregledi[i]->DajDatumPregleda().DajGodinu()==pregled.DajDatumPregleda().DajGodinu() && pregledi[i]->DajDatumPregleda().DajMjesec()==pregled.DajDatumPregleda().DajMjesec() &&
                pregledi[i]->DajDatumPregleda().DajDan()==pregled.DajDatumPregleda().DajDan()) {
            delete pregledi[i];
            pregledi[i]=nullptr;

            for (int k = i+1; k<broj_pregleda; k++) {
                pregledi[k-1]=pregledi[k];
                pregledi[k]=nullptr;
            }
            delete pregledi[broj_pregleda-1];
            pregledi[broj_pregleda-1]=nullptr;
            broj_pregleda--;
            break;
        }
}

int main ()
{
    try {
        int max;
        std::cout<<"Unesite maksimalan broj pregleda: ";
        std::cin>>max;
        Pregledi pregledi(max);
        for (int i = 0; i<max; i++) {
            std::cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
            std::string ime_pacijenta;
            std::cin.ignore(10000, '\n');
            std::getline(std::cin, ime_pacijenta);
            if (ime_pacijenta=="kraj") break;
            int dan, mjesec, godina, sati, minute;
            std::cout<<"Unesite dan mjesec i godinu pregleda: ";
            std::cin>>dan>>mjesec>>godina;
            std::cout<<"Unesite sate i minute pregleda: ";
            std::cin>>sati>>minute;
            pregledi.RegistrirajPregled(ime_pacijenta,dan,mjesec,godina,sati,minute);
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
        
    } catch (std::domain_error izuzetak) {
        std::cout<<izuzetak.what();
    } catch (std::logic_error izuzetak) {
      std::cout<<izuzetak.what();
    } catch (std::range_error izuzetak) {
      std::cout<<izuzetak.what();
    }
    return 0;
}
