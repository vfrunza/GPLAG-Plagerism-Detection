/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <tuple>
#include<iomanip>
#include<string>
#include <vector>
#include <memory>
#include <algorithm>

class Datum
{
    int d,m,g;
public:
    Datum(int dan, int mjesec, int godina) {

        Postavi(dan,mjesec,godina);
    }
    void Postavi(int dan, int mjesec, int godina) {
        if(dan<1 || dan>31 || mjesec>12 || mjesec<1) {
            std::cout<<dan<<" "<<mjesec<<" "<<godina<<std::endl;
            throw std::domain_error("Neispravan datum\n");
        }
        d=dan;
        m=mjesec;
        g=godina;
    }
    std::tuple<int, int, int> Ocitaj() const {
        return std::make_tuple(d,m,g);
    }
    void Ispisi() const {
        std::cout<<d<<"/"<<m<<"/"<<g;
    }

};

class Vrijeme
{
    int h, min;
public:
    Vrijeme(int sati, int minute) {
        h=0;
        min=0;
        Postavi(sati,minute);
    }
    void Postavi(int sati, int minute) {
        if(sati<0 || sati>23 || minute<0 || minute>59)
            throw std::domain_error("Neispravno vrijeme\n");
        h=sati;
        min=minute;
    }
    std::pair<int, int> Ocitaj () const {
        return std::make_pair(h,min);
    }
    void Ispisi() const {
        std::cout<<std::setw(2)<<std::setfill('0')<<h<<":"<<std::setw(2)<<std::setfill('0')<<min<<std::setfill(' ');
    }
};


class Pregled
{
    std::string ime;
    Datum D;
    Vrijeme V;
public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda):D(datum_pregleda),V(vrijeme_pregleda) {
        ime=ime_pacijenta;
    }
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda)
        :D(dan_pregleda,mjesec_pregleda,godina_pregleda),V(sati_pregleda,minute_pregleda) {
        ime=ime_pacijenta;
    }
    void PromijeniDatum(const Datum &novi_datum) {
        D=novi_datum;
    }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme) {
        V=novo_vrijeme;
    }
    void PomjeriDanUnaprijed() {
        auto k=D.Ocitaj();
        std::get<0>(k)+=1;
    }
    void PomjeriDanUnazad() {
        auto k=D.Ocitaj();
        std::get<0>(k)-=1;
    }
    std::string DajImePacijenta() const {
        return ime;
    }
    Datum DajDatumPregleda() const {
        return D;
    }
    Vrijeme DajVrijemePregleda() const {
        return V;
    }
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2) {
        auto prvi=p1.D.Ocitaj();
        auto drugi=p2.D.Ocitaj();
        double dan1=std::get<0>(prvi);
        double mjesec1=std::get<1>(prvi);
        double godina1=std::get<2>(prvi);
        double dan2=std::get<0>(drugi);
        double mjesec2=std::get<1>(drugi);
        double godina2=std::get<2>(drugi);

        auto prvo=p1.V.Ocitaj();
        auto drugo=p2.V.Ocitaj();
        double h1=prvo.first;
        double min1=prvo.second;
        double h2=drugo.first;
        double min2=drugo.second;

        if(godina1<godina2)
            return true;
        else if(godina1==godina2 && mjesec1<mjesec2)
            return true;
        else if(godina1==godina2 && mjesec1==mjesec2 && dan1<dan2)
            return true;
        else if(godina1==godina2 && mjesec1==mjesec2 && dan1==dan2 && h1<h2)
            return true;
        else if(godina1==godina2 && mjesec1==mjesec2 && dan1==dan2 && h1==h2 && min1<min2)
            return true;

        return false;

    }
    void Ispisi() const {
        std::cout<<std::endl;
        std::cout<<std::left<<std::setw(30)<<ime;
        D.Ispisi();
        std::cout<<" ";
        V.Ispisi();

    }
};

/*class Pregledi
{
    Pregled p;
public:
    explicit Pregledi(int max_broj_pregleda);
    Pregledi(std::initializer_list<Pregled> spisak_pregleda);
    ~Pregledi();
    Pregledi(const Pregledi &pregledi);
    Pregledi(Pregledi &&pregledi);
    Pregledi &operator =(const Pregledi &pregledi);
    Pregledi &operator =(Pregledi &&pregledi);
    void RegistrirajPregled(const std::string &ime_pacijenta,
                            const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,
                            int mjesec_pregleda, int godina_pregleda, int sati_pregleda,
                            int minute_pregleda);
    void RegistrirajPregled(Pregled *pregled);
    int DajBrojPregleda() const;
    int DajBrojPregledaNaDatum(const Datum &datum) const;
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum(const Datum &datum) const;
    void IspisiSvePreglede() const;


};*/
int main ()
{
    int brPregleda;
    std::cout<<"Unesite maksimalan broj pregleda: ";
    std::cin>>brPregleda;
    std::vector<std::shared_ptr<Pregled>> v;
    for(int i(0); i<brPregleda; i++) {
        std::string ime;
        std::cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        std::cin>>ime;
        if(ime=="kraj")
            break;
        std::cout<<"Unesite dan mjesec i godinu pregleda: ";
        int d,m,g;
        std::cin>>d>>m>>g;
        std::cout<<"Unesite sate i minute pregleda: ";
        int h,min;
        std::cin>>h>>min;
        auto k(std::make_shared<Pregled>(ime,d,m,g,h,min));
        v.push_back(k);
    }
    std::cout<<"Trenutno su registrovani sljedeci pregledi"<<std::endl;
    std::for_each(v.begin(),v.end(),[](std::shared_ptr<Pregled>p) {
        (*p).Ispisi();
    });
    std::cout<<"\nOdaberite jednu od sljedecih opcija";
             return 0;
}
