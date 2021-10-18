/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <tuple>
#include <stdexcept>
#include <iomanip>
#include <initializer_list>
#include <algorithm>
#include <vector>

int broj(0);
class Datum
{
    int d, m, g;
public:
    Datum(int dan, int mjesec, int godina) {
        Postavi(dan, mjesec, godina);
    }
    void Postavi(int dan, int mjesec, int godina) {
        int broj_dana[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0) broj_dana[1]++;
        if(godina < 1 || mjesec < 1 || dan < 1 || mjesec > 12 || dan > broj_dana[mjesec-1]) throw std::domain_error("Neispravan datum");
        d=dan;
        m=mjesec;
        g=godina;
    }
    std::tuple<int, int, int> Ocitaj() const {
        return std::make_tuple(d, m, g);
    }
    void Ispisi() const {
        std::tuple<int, int, int> datum(Ocitaj());
        int dan, mjesec, godina;
        std::tie(dan, mjesec, godina) = datum;
        std::cout<<dan<<"/"<<mjesec<<"/"<<godina;
    }
};

class Vrijeme
{
    int h, m;
public:
    Vrijeme(int sati, int minute) {
        Postavi(sati, minute);
    }
    void Postavi(int sati, int minute) {
        if(sati > 23 || sati < 0 || minute > 59 || minute < 0) throw std::domain_error("Neispravno vrijeme");
        h = sati;
        m = minute;
    }
    std::pair<int, int> Ocitaj() const {
        return std::make_pair(h, m);
    }
    void Ispisi() const {
        if(h < 10) std::cout<<"0"<<h<<":";
        else std::cout<<h<<":";
        if(m < 10) std::cout<<"0"<<m;
        else std::cout<<m;
    }
};

class Pregled
{
    std::string ime;
    Datum datum;
    Vrijeme vrijeme;
public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda): datum(datum_pregleda), vrijeme(vrijeme_pregleda) {
        //   ime=ime_pacijenta; datum=datum_pregleda; vrijeme=vrijeme_pregleda;
    }
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda):
        datum(dan_pregleda, mjesec_pregleda, godina_pregleda), vrijeme(sati_pregleda, minute_pregleda) {
        ime=ime_pacijenta;
        //   datum.Postavi(dan_pregleda, mjesec_pregleda, godina_pregleda);
        //  vrijeme.Postavi(sati_pregleda, minute_pregleda);
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
        std::tuple<int, int, int> tuple(datum.Ocitaj());
        int dan = std::get<0>(tuple);
        dan++;
        int mjesec = std::get<1>(tuple);
        int godina = std::get<2>(tuple);
        int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0) broj_dana[1]++;
        if(dan > broj_dana[mjesec-1]) {
            dan = broj_dana[mjesec-1]-dan;
            mjesec++;
        }
        if(mjesec > 12) {
            mjesec=1;
            dan=1;
            godina++;
        }
        datum.Postavi(dan, mjesec, godina);
    }
    void PomjeriDanUnazad() {

        std::tuple<int, int, int> tuple(datum.Ocitaj());
        int dan = std::get<0>(tuple);
        dan++;
        int mjesec = std::get<1>(tuple);
        int godina = std::get<2>(tuple);
        int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0) broj_dana[1]++;
        if(dan < 1) {
            mjesec--;
            if(mjesec < 1) {
                mjesec = 12;
                godina--;
            }
            dan = broj_dana[mjesec-1];
        }
        datum.Postavi(dan, mjesec, godina);
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
        std::tuple<int, int, int> tuple1(p1.DajDatumPregleda().Ocitaj());
        std::tuple<int, int, int> tuple2(p2.DajDatumPregleda().Ocitaj());
        std::pair<int, int> vrijeme1(p1.DajVrijemePregleda().Ocitaj());
        std::pair<int, int> vrijeme2(p2.DajVrijemePregleda().Ocitaj());
        int sati1, minute1, sati2, minute2;
        sati1 = vrijeme1.first;
        sati2 = vrijeme2.first;
        minute1 = vrijeme1.second;
        minute2 = vrijeme2.second;
        int dan1, mjesec1, godina1, dan2, mjesec2, godina2;
        std::tie(dan1, mjesec1, godina1) = tuple1;
        std::tie(dan2, mjesec2, godina2) = tuple2;
        if(godina1 < godina2) return true;
        else if(godina1 == godina2) {
            if(mjesec1 < mjesec2) return true;
            else if(mjesec1 == mjesec2) {
                if(dan1 < dan2) return true;
                else if(dan1 == dan2) {
                    if(sati1 < sati2) return true;
                    else if (sati1 == sati2) {
                        if(minute1 < minute2) return true;
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }
    void Ispisi() const {
        std::cout<<std::setw(29)<<ime<<" ";
        datum.Ispisi();
        std::cout<<" ";
        vrijeme.Ispisi();
        std::cout<<std::endl;
    }
};

class Pregledi
{
    int dimenzija;
    int zakazani;
    Pregled **dinamicki_niz_pregleda;
    Pregled **begin() const {
        return dinamicki_niz_pregleda;
    }
    Pregled **end() const {
        return dinamicki_niz_pregleda+dimenzija;
    }
public:
    explicit Pregledi(int max_broj_pregleda): dimenzija(max_broj_pregleda), zakazani(0), dinamicki_niz_pregleda(new Pregled*[dimenzija] {}) {
        std::fill(dinamicki_niz_pregleda, dinamicki_niz_pregleda+dimenzija, nullptr);
    }
    Pregledi(std::initializer_list<Pregled> spisak_pregleda) :
        dimenzija(spisak_pregleda.size()), zakazani(spisak_pregleda.size()), dinamicki_niz_pregleda(new Pregled*[spisak_pregleda.size()] {}) {
        std::initializer_list<Pregled>::iterator it(spisak_pregleda.begin());
        for(int i=0; i<zakazani; i++) {
            try {
                dinamicki_niz_pregleda[i] = new Pregled(*it);
            } catch(...) {
                throw;
            }
            it++;
        }
    }
    ~Pregledi() {
        for(int i=0; i<dimenzija; i++){ delete dinamicki_niz_pregleda[i];
            dinamicki_niz_pregleda[i] = nullptr;
        }
        delete[] dinamicki_niz_pregleda;
    }
    /*Pregledi(const Pregled &pregledi): dimenzija(pregledi.dimenzija), dinamicki_niz_pregleda(new Pregled[pregledi.dimenzija]) {
        std::copy(pregledi.dinamicki_niz_pregleda, pregledi.dinamicki_niz_pregleda + pregledi.dimenzija, dinamicki_niz_pregleda);
    }*/
    Pregledi(const Pregledi &pregledi): dimenzija(pregledi.dimenzija), zakazani(pregledi.zakazani) {
        try {
            dinamicki_niz_pregleda = new Pregled*[dimenzija] {};
            try {
                for(int i=0; i<dimenzija; i++) {
                    if(pregledi.dinamicki_niz_pregleda[i] == nullptr) continue;
                    dinamicki_niz_pregleda[i] = new Pregled (*pregledi.dinamicki_niz_pregleda[i]);
                }
            } catch(...) {
                for(int i=0; i<dimenzija; i++)
                    delete dinamicki_niz_pregleda[i];
                delete[] dinamicki_niz_pregleda;
                throw;
            }
        } catch(...) {
            throw;
        }
    } // kopirajuci konstruktor
    Pregledi(Pregledi &&pregledi): dimenzija(pregledi.dimenzija), zakazani(pregledi.zakazani), dinamicki_niz_pregleda(pregledi.dinamicki_niz_pregleda) {
        pregledi.zakazani = 0;
        pregledi.dinamicki_niz_pregleda = nullptr;
        pregledi.dimenzija=0;
    } // pomjerajuci konstruktor
    Pregledi &operator =(const Pregledi &pregledi) {
        if(this != &pregledi) {
            if(pregledi.dimenzija == dimenzija) {
                for(int i=0; i<dimenzija; i++) {
                    delete dinamicki_niz_pregleda[i];
                    dinamicki_niz_pregleda[i] = nullptr;
                }
                zakazani = pregledi.zakazani;
            } else {
                for(int i=0; i<dimenzija; i++) {
                    delete dinamicki_niz_pregleda[i];
                    dinamicki_niz_pregleda[i] = nullptr;
                }
                delete[] dinamicki_niz_pregleda;
                try {
                    dinamicki_niz_pregleda = new Pregled*[pregledi.dimenzija] {};
                } catch(...) {
                    dinamicki_niz_pregleda = nullptr;
                    throw;
                }
                dimenzija = pregledi.dimenzija;
                zakazani = pregledi.zakazani;

            }
            try {
                for(int i=0; i<pregledi.dimenzija; i++) {
                    if(pregledi.dinamicki_niz_pregleda[i] == nullptr) continue;
                    dinamicki_niz_pregleda[i] = new Pregled(*pregledi.dinamicki_niz_pregleda[i]);
                }
            } catch(...) {
                if(dinamicki_niz_pregleda!=nullptr) {
                    for(int i=0; i<pregledi.dimenzija; i++) delete dinamicki_niz_pregleda[i];
                    delete[] dinamicki_niz_pregleda;
                }
                throw;
            }
        }
        return *this;
    }//kopirajuci operator dodjele
    Pregledi &operator =(Pregledi &&pregledi) {
        if(&pregledi != this) {
            std::swap(zakazani, pregledi.zakazani);
            std::swap(dimenzija, pregledi.dimenzija);
            std::swap(dinamicki_niz_pregleda, pregledi.dinamicki_niz_pregleda);
        }
        return *this;
    }//pomjerajuci operator dodjele
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) {
        Pregled pregled(ime_pacijenta, datum_pregleda, vrijeme_pregleda);
        for(int i=0; i<dimenzija; i++) {
            if(dinamicki_niz_pregleda[i] == nullptr) {
                try {
                    zakazani++;
                    dinamicki_niz_pregleda[i] = new Pregled(pregled);
                    break;
                } catch(...) {
                    throw;
                }
            }
        }
    }

    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) {

        Pregled pregled(ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda);
        for(int i=0; i<dimenzija; i++) {
            if(dinamicki_niz_pregleda[i] == nullptr) {
                try {
                    zakazani++;
                    dinamicki_niz_pregleda[i] = new Pregled(pregled);
                    break;
                } catch(...) {
                    throw;
                }
            }
        }
    }
    void RegistrirajPregled(Pregled *pregled) {
        for(int i=0; i<dimenzija; i++) {
            if(dinamicki_niz_pregleda[i] == nullptr) {
            zakazani++;
                dinamicki_niz_pregleda[i] = pregled;
                break;
            }
        }
    }
    int DajBrojPregleda() const {
        return zakazani;
    }
    int DajBrojPregledaNaDatum(const Datum &datum) const {
        return std::count_if(dinamicki_niz_pregleda, dinamicki_niz_pregleda+dimenzija, [datum] (Pregled *pregledi) {
            if(pregledi != nullptr) {
                int dan, mjesec, godina;
                int dan_p, mjesec_p, godina_p;
                std::tuple<int, int, int> d(datum.Ocitaj());
                std::tuple<int, int, int> p((pregledi->DajDatumPregleda()).Ocitaj());
                std::tie(dan, mjesec, godina) = d;
                std::tie(dan_p, mjesec_p, godina_p) = p;
                if(dan == dan_p && mjesec_p == mjesec && godina_p == godina) return true;
            }
            return false;
        });
    }
    Pregled &DajNajranijiPregled() {
        return **std::min_element(dinamicki_niz_pregleda, dinamicki_niz_pregleda+dimenzija, [this] (Pregled *a, Pregled *b) -> bool {
            if(a!=nullptr && b!= nullptr && Pregled::DolaziPrije(*a, *b)) return true;
            return false;
        });
    }
    Pregled DajNajranijiPregled() const {
        return **std::min_element(dinamicki_niz_pregleda, dinamicki_niz_pregleda+dimenzija, [this] (Pregled *a, Pregled *b) -> bool {
            if(a!=nullptr && b!=nullptr && Pregled::DolaziPrije(*a, *b)) return true;
            return false;
        });
    }
    void IsprazniKolekciju() {
        for(int i=0; i<dimenzija; i++) {
            delete dinamicki_niz_pregleda[i];
            dinamicki_niz_pregleda[i] = nullptr;
        }
        zakazani = 0;
    }
    void ObrisiNajranijiPregled() {
        Pregled najraniji(DajNajranijiPregled());
        std::tuple<int,int, int> d(najraniji.DajDatumPregleda().Ocitaj());
        int dan, mjesec, godina;
        std::tie(dan, mjesec, godina) = d;
        std::pair<int, int> v(najraniji.DajVrijemePregleda().Ocitaj());
        int sati, minute;
        sati = v.first;
        minute = v.second;
        for(int i=0; i<dimenzija; i++) {
            if(dinamicki_niz_pregleda[i] != nullptr) {
                if(dinamicki_niz_pregleda[i]->DajImePacijenta() == najraniji.DajImePacijenta()) {
                    int dan_d = std::get<0>(dinamicki_niz_pregleda[i]->DajDatumPregleda().Ocitaj());
                    int mjesec_d = std::get<1>(dinamicki_niz_pregleda[i]->DajDatumPregleda().Ocitaj());
                    int godina_d = std::get<2>(dinamicki_niz_pregleda[i]->DajDatumPregleda().Ocitaj());
                    int sati_d = std::get<0>(dinamicki_niz_pregleda[i]->DajVrijemePregleda().Ocitaj());
                    int minute_d = std::get<1>(dinamicki_niz_pregleda[i]->DajVrijemePregleda().Ocitaj());
                    if(dan_d == dan && mjesec_d == mjesec && godina_d == godina && sati_d == sati && minute_d == minute) {
                        delete dinamicki_niz_pregleda[i];
                        dinamicki_niz_pregleda[i] = nullptr;
                    }
                }
            }
        }
    }
    void ObrisiPregledePacijenata(const std::string &ime_pacijenta) {
        //  for(int i=0; i<dimenzija; i++) {
        broj=0;
        for(int i=0; i<zakazani; i++) {
            if(dinamicki_niz_pregleda[i] != nullptr && ime_pacijenta == dinamicki_niz_pregleda[i]->DajImePacijenta()) {
                broj++;
                delete dinamicki_niz_pregleda[i];
                dinamicki_niz_pregleda[i]=nullptr;
            }
        }
    }
    void IspisiPregledeNaDatum(const Datum &datum) const {
        std::vector<Pregled> pregledi;
        std::tuple<int, int, int> d(datum.Ocitaj());
        int godina(std::get<2>(d)), mjesec(std::get<1>(d)), dan(std::get<0>(d));
        int i(0);
        for(i=0; i<dimenzija; i++) {
            if(dinamicki_niz_pregleda[i]!=nullptr) {
                if(godina == std::get<2>(dinamicki_niz_pregleda[i]->DajDatumPregleda().Ocitaj()) &&
                        mjesec == std::get<1>(dinamicki_niz_pregleda[i]->DajDatumPregleda().Ocitaj()) &&
                        dan == std::get<0>(dinamicki_niz_pregleda[i]->DajDatumPregleda().Ocitaj()))
                    pregledi.push_back(*dinamicki_niz_pregleda[i]);
            }
        }
        std::sort(pregledi.begin(), pregledi.end(), [](Pregled a, Pregled b) {
            if(a.DajVrijemePregleda().Ocitaj().first < b.DajVrijemePregleda().Ocitaj().first) return true;
            else if(a.DajVrijemePregleda().Ocitaj().first == b.DajVrijemePregleda().Ocitaj().first) {
                if(a.DajVrijemePregleda().Ocitaj().second < b.DajVrijemePregleda().Ocitaj().second) return true;
                return false;
            }
            return false;
        });
        std::for_each(pregledi.begin(), pregledi.end(), [&pregledi](Pregled poc) {
            poc.Ispisi();
        });
    }
    void IspisiSvePreglede() const {
        std::vector<Pregled> pregledi;
        for(int i=0; i<dimenzija; i++) {
            if(dinamicki_niz_pregleda[i]!=nullptr) {
                pregledi.push_back(*dinamicki_niz_pregleda[i]);
            }
        }
        std::sort(pregledi.begin(), pregledi.end(), [](Pregled a, Pregled b) {
            if(std::get<2>(a.DajDatumPregleda().Ocitaj()) < std::get<2>(b.DajDatumPregleda().Ocitaj())) return true;
            else if(std::get<2>(a.DajDatumPregleda().Ocitaj()) == std::get<2>(b.DajDatumPregleda().Ocitaj())) {
                if(std::get<1>(a.DajDatumPregleda().Ocitaj()) < std::get<1>(b.DajDatumPregleda().Ocitaj())) return true;
                else if(std::get<1>(a.DajDatumPregleda().Ocitaj()) == std::get<1>(b.DajDatumPregleda().Ocitaj())) {
                    if(std::get<0>(a.DajDatumPregleda().Ocitaj()) < std::get<0>(b.DajDatumPregleda().Ocitaj())) return true;
                    else if(std::get<0>(a.DajDatumPregleda().Ocitaj()) == std::get<0>(b.DajDatumPregleda().Ocitaj())) {
                        if(a.DajVrijemePregleda().Ocitaj().first < b.DajVrijemePregleda().Ocitaj().first) return true;
                        else if(a.DajVrijemePregleda().Ocitaj().first == b.DajVrijemePregleda().Ocitaj().first) {
                            if(a.DajVrijemePregleda().Ocitaj().second < b.DajVrijemePregleda().Ocitaj().second) return true;
                            return false;
                        }
                        return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }

    );
    std::for_each(pregledi.begin(), pregledi.end(),  [](Pregled poc) {
       std::cout<<std::left<<std::setw(20);
        poc.Ispisi();
    });

}

};

/*
Pregled &DajNajranijiPregled() {

}*/

int main ()
{
    try {
        int max_br;
        std::cout<<"Unesite maksimalan broj pregleda: ";
        std::cin>>max_br;

        Pregledi pregledi(max_br);
        int br(0);
        while(br!=max_br) {
            std::cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
            std::string ime;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::getline(std::cin, ime);
            if(ime == "kraj") break;
            std::cout<<"Unesite dan mjesec i godinu pregleda: ";
            int dan, mjesec, godina;
            //char znak;
            std::cin>>dan>>mjesec>>godina;
            std::cout<<"Unesite sate i minute pregleda: ";
            int sati, minute;
            std::cin>>sati>>minute;
            pregledi.RegistrirajPregled(ime, dan, mjesec, godina, sati, minute);
            br++;
        }
        std::cout<<"Trenutno su registrovani sljedeci pregledi"<<std::endl;
        pregledi.IspisiSvePreglede();
        std::cout<<std::endl;
        int opcija(0);
        while(opcija!=7) {
            std::cout<<"Odaberite jednu od sljedecih opcija"<<std::endl<<
                     "1 - Broj pregleda na datum"<<std::endl<<
                     "2 - Najraniji pregled"<<std::endl<<
                     "3 - Obrisi pregled pacijenta"<<std::endl<<
                     "4 - Obrisi najraniji pregled"<<std::endl<<
                     "5 - Ispisi sve pregleda na datum"<<std::endl<<
                     "6 - Ispisi sve preglede"<<std::endl<<
                     "7 - Kraj programa"<<std::endl;
            std::cin>>opcija;
            if(opcija==1) {
                std::cout<<"Unesite dan mjesec i godinu : ";
                int dan, mjesec, godina;
                //char znak;
                std::cin>>dan>>mjesec>>godina;
                Datum datum(dan, mjesec, godina);
                std::cout<<"Broj pregleda na datum "<<dan<<" "<<mjesec<<" "<<godina<<" je: "<<pregledi.DajBrojPregledaNaDatum(datum)<<std::endl;
            } else if(opcija==2) {
                std::cout<<"Najraniji pregled je:"<<std::endl;
                pregledi.DajNajranijiPregled().Ispisi();
            } else if(opcija==3) {
                std::cout<<"Unesite ime pacijenta: ";
                std::string ime;
                std::cin.clear();
                std::cin.ignore(10000,'\n');
                std::getline(std::cin, ime);
                pregledi.ObrisiPregledePacijenata(ime);
                std::cout<<"Uspjesno obrisano "<<broj<<" pregleda";
            } else if(opcija==4) {
                pregledi.ObrisiNajranijiPregled();
                std::cout<<"Najraniji pregled uspjesno obrisan"<<std::endl;
            } else if(opcija==5) {
                std::cout<<"Unesite dan mjesec i godinu : ";
                int dan, mjesec, godina;
                // char znak;
                std::cin>>dan>>mjesec>>godina;
                Datum datum(dan, mjesec, godina);
                std::cout<<"Pregledi na datum "<<dan<<" "<<mjesec<<" "<<godina<<" su:"<<std::endl;
                pregledi.IspisiPregledeNaDatum(datum);
            } else if(opcija==6) {
                pregledi.IspisiSvePreglede();
            }
            std::cout<<std::endl;
           // pregledi.IspisiSvePreglede();
        }
    } catch(std::domain_error izuzetak) {
        std::cout<<izuzetak.what();
    } catch(...) {

    }
    return 0;
}
