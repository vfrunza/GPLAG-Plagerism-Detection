/B2017/2018: Zadaća 4, Zadatak 4
#include <iostream> 
#include <tuple>
#include <stdexcept> 
#include <iomanip> 
#include <utility> 
#include <string>
#include <algorithm>
#include <initializer_list>
#include <vector>
#include <memory>
class Datum {
    int d, m, g;
    void PomjeriUnaprijed();
    void PomjeriUnazad();
public:
    Datum(int dan, int mjesec, int godina);
    void Postavi(int dan, int mjesec, int godina);
    std::tuple < int, int, int > Ocitaj() const;
    void Ispisi() const;
    friend class Pregled;
};

class Vrijeme {
    int h, min;
public:
    Vrijeme(int sati, int minute);
    void Postavi(int sati, int minute);
    std::pair < int, int > Ocitaj() const;
    void Ispisi() const;
};

class Pregled {
    Datum datum_pregleda;
    std::string ime_pacijenta;
    Vrijeme vrijeme_pregleda;
public: 
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) : ime_pacijenta(ime_pacijenta), datum_pregleda(datum_pregleda), vrijeme_pregleda(vrijeme_pregleda) {}
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) : ime_pacijenta(ime_pacijenta), datum_pregleda(dan_pregleda,mjesec_pregleda,godina_pregleda), vrijeme_pregleda(sati_pregleda,minute_pregleda) {}
    void PromijeniPacijenta(const std::string &ime_pacijenta) { Pregled::ime_pacijenta=ime_pacijenta; }
    void PromijeniDatum(const Datum &novi_datum) { Pregled::datum_pregleda=novi_datum; }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme) { vrijeme_pregleda=novo_vrijeme; }
    void PomjeriDanUnaprijed() { datum_pregleda.PomjeriUnaprijed(); }
    void PomjeriDanUnazad() { datum_pregleda.PomjeriUnazad(); }
    std::string DajImePacijenta() const { return ime_pacijenta; }
    Datum DajDatumPregleda() const { return datum_pregleda; }
    Vrijeme DajVrijemePregleda() const { return vrijeme_pregleda; }
    static bool DolaziPrije(const Pregled &pl, const Pregled &p2);
    void Ispisi() const;
};

class Pregledi {
    std::vector<std::shared_ptr<Pregled>> nizpregleda;
public:
    explicit Pregledi() {}
    Pregledi(std::initializer_list<Pregled> spisak_pregleda);
    ~Pregledi() { for (int i=0;i<nizpregleda.size();i++) nizpregleda[i]=nullptr; }
    Pregledi(const Pregledi &pregledi);
    Pregledi(Pregledi &&pregledi);
    Pregledi &operator =(const Pregledi &pregledi);
    Pregledi &operator =(Pregledi &&pregledi);
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void RegistrirajPregled(std::shared_ptr<Pregled> pregled);
    int DajBrojPregleda() const { return nizpregleda.size(); };
    int DajBrojPregledaNaDatum(const Datum &datum) const;
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledPacijenta(const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum(const Datum &datum) const;
    void IspisiSvePreglede() const;
};
int main()
{
    Pregledi pregledi;
    for (;;) {
        std::cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        std::string s;
        std::getline(std::cin,s);
        if (s=="kraj") break;
        std::cout<<"Unesite dan mjesec i godinu pregleda: ";
        int dan,mjesec,godina, sati, minute;
        std::cin>>dan>>mjesec>>godina;
        std::cout<<"Unesite sate i minute pregleda: ";
        std::cin>>sati>>minute;
        pregledi.RegistrirajPregled(s,dan,mjesec,godina,sati,minute);
        std::cin.ignore(100,'\n');
    }
    std::cout<<"Trenutno su registrovani sljedeci pregledi"<<std::endl;
    pregledi.IspisiSvePreglede();
    for (;;) {
        std::cout<<std::endl<<"Odaberite jednu od sljedecih opcija"<<std::endl<<"1 - Broj pregleda na datum"<<std::endl<<"2 - Najraniji pregled"<<std::endl<<"3 - Obrisi pregled pacijenta"<<std::endl<<"4 - Obrisi najraniji pregled"<<std::endl<<"5 - Ispisi sve pregleda na datum"<<std::endl<<"6 - Ispisi sve preglede"<<std::endl<<"7 - Kraj programa";
        int opcija;
        std::cin>>opcija;
        try {
            if (opcija==1) { std::cout<<std::endl<<"Unesite dan mjesec i godinu : ";
                    int dan2,mjesec2,godina2;
                    std::cin>>dan2>>mjesec2>>godina2;
                    std::cout<<"Broj pregleda na datum "<<dan2<<" "<<mjesec2<<" "<<godina2<<" je: "<<pregledi.DajBrojPregledaNaDatum(Datum(dan2,mjesec2,godina2));
            }
            else if (opcija==2) { Pregled najraniji(pregledi.DajNajranijiPregled());
                    std::cout<<std::endl<<"Najraniji pregled je: "<<std::endl;
                    najraniji.Ispisi();
            }
            else if (opcija==3) { std::cout<<std::endl<<"Unesite ime pacijenta: ";
                    std::cin.ignore(50,'\n');
                    std::string s2;
                    int brojprije=pregledi.DajBrojPregleda();
                    std::getline(std::cin,s2);
                    pregledi.ObrisiPregledPacijenta(s2);
                    std::cout<<"Uspjesno obrisano "<<brojprije-pregledi.DajBrojPregleda()<<" pregleda";
            }
            else if (opcija==4) { pregledi.ObrisiNajranijiPregled(); std::cout<<std::endl<<"Najraniji pregled uspjesno obrisan"; }
            else if (opcija==5) { std::cout<<std::endl<<"Unesite dan mjesec i godinu : ";
                    int dan3,mjesec3,godina3;
                    std::cin>>dan3>>mjesec3>>godina3;
                    std::cout<<"Pregledi na datum "<<dan3<<" "<<mjesec3<<" "<<godina3<<" su: "<<std::endl;
                    pregledi.IspisiPregledeNaDatum(Datum(dan3,mjesec3,godina3)); }
            else if (opcija==6) { std::cout<<std::endl; pregledi.IspisiSvePreglede(); }
            else { return 0; }
            std::cout<<std::endl;
        }
        catch(std::exception &e) {
            std::cout<<e.what()<<std::endl;
        }
    }
    return 0;
}



// DATUM IMPLEMENTACIJA----------------------------------------------------------------------------------------------------------------------
Datum::Datum(int dan, int mjesec, int godina) {
    Postavi(dan, mjesec, godina);
}
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
void Datum::Postavi(int dan, int mjesec, int godina) {
    int broj_dana[12] {
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };
    if (godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0) broj_dana[1]++;
    if (godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > broj_dana[mjesec - 1])
        throw std::domain_error("Neispravan datum");
    d = dan;
    m = mjesec;
    g = godina;
}
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
std::tuple < int, int, int > Datum::Ocitaj() const {
    return std::make_tuple(d, m, g);
}
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
void Datum::Ispisi() const {
    std::cout << d << "/" << m << "/" << g;
}
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
void Datum::PomjeriUnaprijed() {
    int broj_dana[12] { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (g % 4 == 0 && g % 100 != 0 || g % 400 == 0) broj_dana[1]++;
    d++;
    if (d>broj_dana[m-1]){ d=1; m++; }
    if (m>12) { m=1; g++; }
}
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
void Datum::PomjeriUnazad() {
    int broj_dana[12] { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (g % 4 == 0 && g % 100 != 0 || g % 400 == 0) broj_dana[1]++;
    d--;
    if (d<1) { 
        if (m==1){ d=broj_dana[11]; m=12; g--; }
        else { d=broj_dana[m-2]; m--; }
    }
}



// VRIJEME IMPLEMENTACIJA------------------------------------------------------------------------------------------------------------------------------
Vrijeme::Vrijeme(int sati, int minute) {
    Postavi(sati, minute);
}
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
void Vrijeme::Postavi(int sati, int minute) {
    if (sati < 0 || sati > 23 || minute < 0 || minute > 59) throw std::domain_error("Neispravno vrijeme");
    h = sati;
    min = minute;
}
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
std::pair < int, int > Vrijeme::Ocitaj() const {
    return std::make_pair(h, min);
}
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
void Vrijeme::Ispisi() const {
    std::cout << std::setw(2) << std::setfill('0')<<std::right << h << ":" << std::setw(2) << min<<std::setfill(' ');
}





// PREGLED IMPLEMENTACIJA ----------------------------------------------------------------------------------------------------------------------------
void Pregled::Ispisi() const { 
    std::cout<<std::setw(30)<<std::left<<ime_pacijenta;
    datum_pregleda.Ispisi();
    std::cout<<" ";
    vrijeme_pregleda.Ispisi();
    std::cout<<std::endl;
}
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
bool Pregled::DolaziPrije(const Pregled &p1, const Pregled &p2) {
    auto tapl1(p1.datum_pregleda.Ocitaj());
    auto tapl2(p2.datum_pregleda.Ocitaj());
    if (std::get<2>(tapl1)<std::get<2>(tapl2)) return true;
    if (std::get<2>(tapl1)==std::get<2>(tapl2)) {
        if (std::get<1>(tapl1)<std::get<1>(tapl2)) return true;
        if (std::get<1>(tapl1)==std::get<1>(tapl2)) {
            if (std::get<0>(tapl1)<std::get<0>(tapl2)) return true;
            if (std::get<0>(tapl1)==std::get<0>(tapl2)) {
                auto par1(p1.vrijeme_pregleda.Ocitaj());
                auto par2(p2.vrijeme_pregleda.Ocitaj());
                if (par1.first<par2.first) return true;
                if (par1.first==par2.first) {
                    if (par1.second<par2.second) return true;
                }
            }
        }
    }
    return false;
}




// PREGLEDI IMPLEMENTACIJA----------------------------------------------------------------------------------------------------------------------------
Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda) {
	for (auto &pregled: spisak_pregleda)
	    nizpregleda.push_back(std::make_shared<Pregled>(pregled));
}
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
Pregledi::Pregledi(const Pregledi &pregledi) { 
	for (int i=0;i<pregledi.nizpregleda.size();i++)
	    nizpregleda.push_back(std::make_shared<Pregled>(*pregledi.nizpregleda[i]));
}
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
Pregledi::Pregledi(Pregledi &&pregledi) : nizpregleda(std::move(pregledi.nizpregleda)) {}
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
Pregledi& Pregledi::operator =(const Pregledi &pregledi) {
	if (&pregledi!=this) {
	    nizpregleda.resize(0);
	    for (int i=0;i<pregledi.nizpregleda.size();i++)
	        nizpregleda.push_back(std::make_shared<Pregled>(*pregledi.nizpregleda[i]));
	}
	return *this;
}
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
Pregledi& Pregledi::operator =(Pregledi &&pregledi) {
    nizpregleda=std::move(pregledi.nizpregleda);
	return *this;
}
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) {
    Pregled pregled(ime_pacijenta,datum_pregleda,vrijeme_pregleda);
    nizpregleda.push_back(std::make_shared<Pregled>(pregled));
}
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) {
    Pregled pregled(ime_pacijenta,dan_pregleda,mjesec_pregleda,godina_pregleda,sati_pregleda,minute_pregleda);
    nizpregleda.push_back(std::make_shared<Pregled>(pregled));
}
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
void Pregledi::RegistrirajPregled(std::shared_ptr<Pregled> pregled) {
    nizpregleda.push_back(pregled);
}
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const {
    return std::count_if(nizpregleda.begin(),nizpregleda.end(),[=](std::shared_ptr<Pregled> pregled) { return pregled->DajDatumPregleda().Ocitaj()==datum.Ocitaj(); });
}
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
Pregled& Pregledi::DajNajranijiPregled() {
    if (!nizpregleda.size()) throw std::domain_error("Nema registriranih pregleda");
    auto pok=std::min_element(nizpregleda.begin(),nizpregleda.end(),[=](std::shared_ptr<Pregled> pregled1, std::shared_ptr<Pregled> pregled2) {
        return Pregled::DolaziPrije(*pregled1, *pregled2);
    });
    return **pok;
}
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
Pregled Pregledi::DajNajranijiPregled() const {
    if (!nizpregleda.size()) throw std::domain_error("Nema registriranih pregleda");
    auto pok=std::min_element(nizpregleda.begin(),nizpregleda.end(),[=](std::shared_ptr<Pregled> pregled1, std::shared_ptr<Pregled> pregled2) {
        return Pregled::DolaziPrije(*pregled1, *pregled2);
    });
    return **pok;
}
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
void Pregledi::IsprazniKolekciju() {
    nizpregleda.resize(0);
}
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
void Pregledi::ObrisiNajranijiPregled() {
    if (!nizpregleda.size()) throw std::range_error("Prazna kolekcija");
    auto pok=std::min_element(nizpregleda.begin(),nizpregleda.end(),[=](std::shared_ptr<Pregled> pregled1, std::shared_ptr<Pregled> pregled2) {
        return Pregled::DolaziPrije(*pregled1, *pregled2);
    });
    nizpregleda.erase(pok);
}
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
void Pregledi::ObrisiPregledPacijenta(const std::string &ime_pacijenta) {
    while (std::count_if(nizpregleda.begin(),nizpregleda.end(),[=](std::shared_ptr<Pregled> pregled) {
       return pregled->DajImePacijenta()==ime_pacijenta; 
    })) {
    auto pok=std::find_if(nizpregleda.begin(),nizpregleda.end(),[=](std::shared_ptr<Pregled> pregled) {
       return pregled->DajImePacijenta()==ime_pacijenta; 
    });
    nizpregleda.erase(pok);
    }
}
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const {
    std::vector<std::shared_ptr<Pregled>> pomocni(DajBrojPregledaNaDatum(datum));
    std::copy_if(nizpregleda.begin(),nizpregleda.end(),pomocni.begin(),[=](std::shared_ptr<Pregled> pregled) { return pregled->DajDatumPregleda().Ocitaj()==datum.Ocitaj();});
    std::sort(pomocni.begin(),pomocni.end(),[](std::shared_ptr<Pregled> pregled1, std::shared_ptr<Pregled> pregled2) { return Pregled::DolaziPrije(*pregled1,*pregled2);});
    std::for_each(pomocni.begin(),pomocni.end(),[](std::shared_ptr<Pregled> pregled){ pregled->Ispisi();});
}
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
void Pregledi::IspisiSvePreglede() const {
    std::vector<std::shared_ptr<Pregled>> pomocni(nizpregleda.size());
    std::copy(nizpregleda.begin(),nizpregleda.end(),pomocni.begin());
    std::sort(pomocni.begin(),pomocni.end(),[](std::shared_ptr<Pregled> pregled1, std::shared_ptr<Pregled> pregled2) { return Pregled::DolaziPrije(*pregled1,*pregled2);});
    std::for_each(pomocni.begin(),pomocni.end(),[](std::shared_ptr<Pregled> pregled){ pregled->Ispisi();});
}