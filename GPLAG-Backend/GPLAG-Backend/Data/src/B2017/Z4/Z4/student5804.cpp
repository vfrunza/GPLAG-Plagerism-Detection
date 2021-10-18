#include <iostream>
#include <tuple>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>
#include <iomanip>
#include <string>
#include <new>

class Datum
{
    int dan,mjesec,godina;
public:
    Datum(int dan, int mjesec, int godina) {
        int dani_u_mjesecu [12] {31,28,31,30,31,30,31,31,30,31,30,31};
        if (godina%4==0 && (godina%100==0 && godina%400==0)) dani_u_mjesecu[1]++;
        if (mjesec<0 || mjesec>12 || godina<0 || dan<0 || dan>dani_u_mjesecu[mjesec-1]) throw std::domain_error ("Neispravan datum");
        Datum::dan=dan;
        Datum::mjesec=mjesec;
        Datum::godina=godina;
    }
    void Postavi(int dan, int mjesec, int godina) {
        int dani_u_mjesecu [12] {31,28,31,30,31,30,31,31,30,31,30,31};
        if (godina%4==0 && (godina%100==0 && godina%400==0)) dani_u_mjesecu[1]++;
        if (mjesec<0 || mjesec>12 || godina<0 || dan<0 || dan>dani_u_mjesecu[mjesec-1]) throw std::domain_error ("Neispravan datum");
        Datum::dan=dan;
        Datum::mjesec=mjesec;
        Datum::godina=godina;
    }
    std::tuple<int, int, int> Ocitaj() const {
        auto pom (std::make_tuple(dan,mjesec,godina));
        return pom;
    }
    void Ispisi() const {
        std::cout<<dan<<"/"<<mjesec<<"/"<<godina;
    }
};

class Vrijeme
{
    int sati,minute;
public:
    Vrijeme(int sati, int minute) {
        if (sati<0 || sati>23 || minute<0 || minute>59) throw std::domain_error ("Neispravno vrijeme");
        Vrijeme::sati=sati;
        Vrijeme::minute=minute;
    }
    void Postavi(int sati, int minute) {
        if (sati<0 || sati>23 || minute<0 || minute>59) throw std::domain_error ("Neispravno vrijeme");
        Vrijeme::sati=sati;
        Vrijeme::minute=minute;
    }
    std::pair<int, int> Ocitaj () const {
        auto pom (std::make_pair(sati,minute));
        return pom;
    }
    void Ispisi() const {
        std::cout<<std::setw(2)<<std::right<<std::setfill('0')<<sati<<":"<<std::setw(2)<<minute<<std::setfill(' ');
    }
};

class Pregled
{
    std::string ime;
    Datum datum;
    Vrijeme vrijeme;
public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) : datum(datum_pregleda),vrijeme(vrijeme_pregleda) {
        ime=ime_pacijenta;
    }
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) : datum(dan_pregleda,mjesec_pregleda,godina_pregleda), vrijeme(sati_pregleda,minute_pregleda) {
        ime=ime_pacijenta;
    }
    void PromijeniPacijenta(const std::string &ime_pacijenta) {
        ime=ime_pacijenta;
    }
    void PromijeniDatum(const Datum &novi_datum) {
        datum=novi_datum;
    }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme) {
        vrijeme=novo_vrijeme;
    }
    void PomjeriDanUnaprijed() {
        auto pom=datum.Ocitaj();
        std::get<0>(pom)++;
        datum.Postavi(std::get<0>(pom),std::get<1>(pom),std::get<2>(pom));
    }
    void PomjeriDanUnazad() {
        auto pom=datum.Ocitaj();
        std::get<0>(pom)--;
        datum.Postavi(std::get<0>(pom),std::get<1>(pom),std::get<2>(pom));
    }
    std::string DajImePacijenta() const {
        return ime;
    }
    Datum DajDatumPregleda() const {
        return datum;
    }
    Vrijeme DajVrijemePregleda() const {
        return vrijeme;
    }
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2) {
        auto pom1=p1.datum.Ocitaj();
        auto pom2=p2.datum.Ocitaj();
        if (std::get<2>(pom1)<std::get<2>(pom2)) return true;
        if (std::get<2>(pom1)==std::get<2>(pom2)) {
            if (std::get<1>(pom1)<std::get<1>(pom2)) return true;
        }
        if (std::get<2>(pom1)==std::get<2>(pom2) && std::get<1>(pom1)==std::get<1>(pom2)) {
            if (std::get<0>(pom1)<std::get<0>(pom2)) return true;
        }
        if (std::get<2>(pom1)==std::get<2>(pom2) && std::get<1>(pom1)==std::get<1>(pom2) && std::get<0>(pom1)==std::get<0>(pom2)) {
            auto tom1=p1.vrijeme.Ocitaj();
            auto tom2=p2.vrijeme.Ocitaj();
            if (tom1.first<tom2.first) return true;
            if (tom1.first==tom2.first) {
                if (tom1.second<tom2.second) return true;
            }
        }
        return false;
    }
    void Ispisi() const {
        std::cout<<std::left<<std::setw(30)<<ime;
        datum.Ispisi();
        std::cout<<" ";
        vrijeme.Ispisi();
        std::cout<<std::endl;
    }
};

class Pregledi
{
    std::vector<std::shared_ptr<Pregled>> pregled;
public:


    explicit Pregledi() : pregled() {}

    Pregledi(std::initializer_list<Pregled> spisak_pregleda) : pregled(spisak_pregleda.size()) {
        auto it(spisak_pregleda.begin());
        for(int i=0; i<int(spisak_pregleda.size()); i++) pregled.at(i)=std::make_shared<Pregled>(*it++);
    }


    Pregledi(const Pregledi &pregledi) : pregled(pregledi.pregled.size()) {
        for (int i=0; i<pregled.size(); i++) pregled.at(i)=std::make_shared<Pregled>(*pregledi.pregled.at(i));
    }

    Pregledi(Pregledi &&pregledi) : pregled(pregledi.pregled.size()) {
        std::swap(pregled,pregledi.pregled);
        pregledi.pregled.resize(0);
    }


    Pregledi &operator =(const Pregledi &pregledi) {
        if (&pregledi!=this) {
            if(pregled.size()<pregledi.pregled.size()) {
                for(int i(pregled.size()); i<pregledi.pregled.size(); i++) pregled.push_back(std::make_shared<Pregled>(*pregledi.pregled.at(i)));
            }
            pregled.resize(pregledi.pregled.size());
            for(int i(0); i<pregled.size(); i++)
                *pregled.at(i)=*pregledi.pregled.at(i);
        }
        return *this;
    }

    Pregledi &operator =(Pregledi &&pregledi) {
        std::swap(pregled,pregledi.pregled);
        pregledi.pregled.resize(0);
        return *this;
    }


    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) {
        pregled.push_back(std::make_shared<Pregled>(ime_pacijenta,datum_pregleda,vrijeme_pregleda));
    }


    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) {
        pregled.push_back(std::make_shared<Pregled>(ime_pacijenta,dan_pregleda,mjesec_pregleda,godina_pregleda,sati_pregleda,minute_pregleda));
    }


    void RegistrirajPregled(std::shared_ptr<Pregled> pok_pregled) {
        pregled.push_back(std::make_shared<Pregled>(pok_pregled->DajImePacijenta(),pok_pregled->DajDatumPregleda(),pok_pregled->DajVrijemePregleda()));
    }


    int DajBrojPregleda() const {
        return pregled.size();
    }

    void IspisiSvePreglede() {
        std::sort (pregled.begin(),pregled.end(),[] (std::shared_ptr<Pregled> p1,std::shared_ptr<Pregled> p2) {
            return Pregled::DolaziPrije(*p1,*p2);
        });
        for (int i(0); i<pregled.size(); i++) pregled.at(i)->Ispisi();
    }


    void IspisiPregledeNaDatum(const Datum &datum) {
        std::sort (pregled.begin(),pregled.end(),[datum] (std::shared_ptr<Pregled> p1,std::shared_ptr<Pregled> p2) {
            return Pregled::DolaziPrije(*p1,*p2);
        });
        for (int i(0); i<pregled.size(); i++)
            if (pregled.at(i)->DajDatumPregleda().Ocitaj()==datum.Ocitaj()) pregled.at(i)->Ispisi();
    }


    Pregled &DajNajranijiPregled() const {
        auto min=*std::min_element (pregled.begin(),pregled.end(),[] (std::shared_ptr<Pregled> p1, std::shared_ptr<Pregled> p2)  {
            if (Pregled::DolaziPrije(*p1,*p2)) return true;
            return false;
        });
        if (min==0) throw std::domain_error ("Nema registriranih pregleda");
        return *min;
    }


    Pregled DajNajranijiPregled() {
        auto min=*std::min_element(pregled.begin(),pregled.end(),[] (std::shared_ptr<Pregled> p1, std::shared_ptr<Pregled> p2) {
            if (Pregled::DolaziPrije(*p1,*p2)) return true;
            return false;
        });
        if (min==0) throw std::domain_error ("Nema registriranih pregleda");
        return *min;
    }


    void IsprazniKolekciju() {
        for(int i(0); i<pregled.size(); i++) pregled.at(i)=nullptr;
        pregled.resize(0);
    }


    void ObrisiNajranijiPregled() {
        auto min=DajNajranijiPregled();
        if (pregled.size()==0) throw std::range_error ("Prazna kolekcija");
        int a(pregled.size());
        for (int i(0); i<a; i++) {
            if (pregled.at(i)->DajDatumPregleda().Ocitaj()==min.DajDatumPregleda().Ocitaj()) {
                for (int j(i); j<a-1; j++) {
                    *pregled.at(j)=*pregled.at(j+1);
                }
                pregled.at(a-1)=nullptr;
                pregled.resize(a-1);
                break;
            }
        }
    }


    void ObrisiPregledePacijenta(std::string ime_pacijenta) {
        int a(pregled.size());
        for (int i(0); i<a; i++) {
            if (pregled.at(i)->DajImePacijenta()==ime_pacijenta) {
                for (int j(i); j<a-1; j++) {
                    *pregled.at(j)=*pregled.at(j+1);
                }
                pregled.at(a-1)=nullptr;
                i--;
                a--;
                pregled.resize(a);
            }
        }
    }


    int DajBrojPregledaNaDatum(const Datum &datum) {
        int broj=std::count_if (pregled.begin(),pregled.end(),[&datum] (std::shared_ptr<Pregled> p) {
            if (p->DajDatumPregleda().Ocitaj()==datum.Ocitaj()) return true;
            return false;
        });
        return broj;
    }




};

int main ()
{
    try {
        Pregledi glavni;
        for (;;) {
            std::cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
            std::string ime;
            std::getline(std::cin,ime);
            if (ime=="kraj") break;
            std::cout<<"Unesite dan mjesec i godinu pregleda: ";
            int dan,mjesec,godina;
            std::cin>>dan>>mjesec>>godina;
            Datum datum (dan,mjesec,godina);
            std::cout<<"Unesite sate i minute pregleda: ";
            int sati,minute;
            std::cin>>sati>>minute;
            Vrijeme vrijeme (sati,minute);
            glavni.RegistrirajPregled(ime,datum,vrijeme);
            std::cin.clear();
            std::cin.ignore (1000,'\n');
        }
        std::cout<<"Trenutno su registrovani sljedeci pregledi"<<std::endl;
        glavni.IspisiSvePreglede();
        for (;;) {
            std::cout<<"\nOdaberite jednu od sljedecih opcija"<<std::endl;
            std::cout<<"1 - Broj pregleda na datum"<<std::endl;
            std::cout<<"2 - Najraniji pregled"<<std::endl;
            std::cout<<"3 - Obrisi pregled pacijenta"<<std::endl;
            std::cout<<"4 - Obrisi najraniji pregled"<<std::endl;
            std::cout<<"5 - Ispisi sve pregleda na datum"<<std::endl;
            std::cout<<"6 - Ispisi sve preglede"<<std::endl;
            std::cout<<"7 - Kraj programa"<<std::endl;
            int broj;
            std::cin>>broj;
            if (broj==1) {
                std::cout<<"Unesite dan mjesec i godinu : ";
                int d,m,g;
                std::cin>>d>>m>>g;
                Datum dat (d,m,g);
                int broj_pregleda_na_datum=glavni.DajBrojPregledaNaDatum(dat);
                std::cout<<"Broj pregleda na datum "<<d<<" "<<m<<" "<<g<<" je: "<<broj_pregleda_na_datum<<std::endl;;
            } else if (broj==2) {
                std::cout<<"Najraniji pregled je: "<<std::endl;
                auto min=glavni.DajNajranijiPregled();
                min.Ispisi();
            } else if (broj==3) {
                std::cout<<"Unesite ime pacijenta: ";
                std::cin.clear();
                std::cin.ignore (1000,'\n');
                std::string pacijent;
                std::getline(std::cin,pacijent);
                int brojac(glavni.DajBrojPregleda());
                glavni.ObrisiPregledePacijenta(pacijent);
                brojac-=glavni.DajBrojPregleda();
                std::cout<<"Uspjesno obrisano "<<brojac<<" pregleda"<<std::endl;
            } else if (broj==4) {
                glavni.ObrisiNajranijiPregled();
                std::cout<<"Najraniji pregled uspjesno obrisan"<<std::endl;
            } else if (broj==5) {
                std::cout<<"Unesite dan mjesec i godinu : ";
                int dd,mm,gg;
                std::cin>>dd>>mm>>gg;
                Datum date(dd,mm,gg);
                std::cout<<"Pregledi na datum "<<dd<<" "<<mm<<" "<<gg<<" su:"<<std::endl;
                glavni.IspisiPregledeNaDatum(date);
            } else if (broj==6) {
                glavni.IspisiSvePreglede();
            } else if (broj==7) {
                glavni.IsprazniKolekciju();
                break;
            }
        }
    } catch (std::domain_error d) {
        std::cout<<d.what()<<std::endl;
    } catch (std::range_error r) {
        std::cout<<r.what()<<std::endl;
    }
    return 0;
}