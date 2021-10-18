#include <new>
#include <memory>
#include <iomanip>
#include <string>
#include <vector>
#include <tuple>
#include <stdexcept>
#include <iostream>

class Datum {
    int dan, mjesec, godina;
    public:
    Datum (int dan, int mjesec, int godina) {
        if (ValjaLiDatum(dan, mjesec, godina)==0) throw std::domain_error("Neispravan datum");
        Datum::dan=dan;
        Datum::mjesec=mjesec;
        Datum::godina=godina;
    }
    void Postavi (int dan, int mjesec, int godina) {
        if (ValjaLiDatum(dan, mjesec, godina)==0) throw std::domain_error("Neispravan datum");
        Datum::dan=dan;
        Datum::mjesec=mjesec;
        Datum::godina=godina;
    }
    std::tuple<int, int, int> Ocitaj() const {
        return std::make_tuple(Datum::dan, Datum::mjesec, Datum::godina);
    }
    void Ispisi() const {
        std::cout << dan << "/" << mjesec << "/" << godina;
    }
    bool ValjaLiDatum(int d, int m, int g) {
        int broj_dana[12] { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if ((g%4==0 and g%100!=0) or g%400==0) broj_dana[1]++;
        if (g<1 or d<1 or m<1 or m>12 or d>broj_dana[m-1]) return false;
        return true;
    }
};

class Vrijeme {
    int sati, minute;
    public:
    Vrijeme (int sati, int minute) {
        if (ValjaLiVrijeme(sati, minute)==0) throw std::domain_error("Neispravno vrijeme");
        Vrijeme::sati=sati;
        Vrijeme::minute=minute;
    }
    void Postavi(int sati, int minute) {
        if (ValjaLiVrijeme(sati, minute)==0) throw std::domain_error("Neispravno vrijeme");
        Vrijeme::sati=sati;
        Vrijeme::minute=minute;
    }
    std::pair<int, int> Ocitaj() const {
        return std::make_pair(Vrijeme::sati, Vrijeme::minute);
    }
    void Ispisi() const {
        std::cout << std::setw(2) << std::setfill('0') << sati << ":" << std::setw(2) << std::setfill('0') << minute;
    }
    bool ValjaLiVrijeme(int s, int m) {
        if (s<0 or s>23 or m<0 or m>59) return false;
        return true;
    }
};

class Pregled {
    std::string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;
    int dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda;
    public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) : datum_pregleda(dan_pregleda, mjesec_pregleda, godina_pregleda), vrijeme_pregleda(sati_pregleda, minute_pregleda) {
        Pregled::ime_pacijenta=ime_pacijenta;
        Pregled::datum_pregleda=datum_pregleda;
        Pregled::vrijeme_pregleda=vrijeme_pregleda;
    }
    Pregled (const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) : datum_pregleda(dan_pregleda, mjesec_pregleda, godina_pregleda), vrijeme_pregleda(sati_pregleda, minute_pregleda) {
        Pregled::ime_pacijenta=ime_pacijenta;
        Pregled::dan_pregleda=dan_pregleda;
        Pregled::mjesec_pregleda=mjesec_pregleda;
        Pregled::godina_pregleda=godina_pregleda;
        Pregled::sati_pregleda=sati_pregleda;
        Pregled::minute_pregleda=minute_pregleda;
    }
    void PromijeniPacijenta(const std::string &ime_pacijenta) {
        Pregled::ime_pacijenta=ime_pacijenta;
    }
    void PromijeniDatum(const Datum &novi_datum) {
        Pregled::datum_pregleda=novi_datum;
    }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme) {
        Pregled::vrijeme_pregleda=novo_vrijeme;
    }
    void PomjeriDanUnaprijed() {
        Pregled::dan_pregleda++;
    }
    void PomjeriDanUnazad() {
        Pregled::dan_pregleda--;
    }
    std::string DajImePacijenta() const {
        return ime_pacijenta;
    }
    Datum DajDatumPregleda() const {
        return datum_pregleda;
    }
    Vrijeme DajVrijemePregleda() const {
        return vrijeme_pregleda;
    }
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2) {
        if (p1.godina_pregleda < p2.godina_pregleda) return false;
        else if (p1.godina_pregleda > p2.godina_pregleda) return true;
        else {
            if (p1.mjesec_pregleda < p2.mjesec_pregleda) return false;
            else if (p1.mjesec_pregleda > p2.mjesec_pregleda) return true;
            else {
                if (p1.dan_pregleda < p2.dan_pregleda) return false;
                else if (p1.dan_pregleda > p2.dan_pregleda) return true;
                else {
                    if (p1.sati_pregleda < p2.sati_pregleda) return false;
                    else if (p1.sati_pregleda > p2.sati_pregleda) return true;
                    else {
                        if (p1.minute_pregleda < p2.minute_pregleda) return false;
                        else if (p1.minute_pregleda > p2.minute_pregleda) return true;
                        else return false;
                    }
                }
            }
        }
    }
    void Ispisi() const {
        std::cout << std::left << std::setw(30) << ime_pacijenta << " " << dan_pregleda << "/" << mjesec_pregleda << "/" << godina_pregleda << " " << std::setw(2) << std::setfill('0') << sati_pregleda << ":" << std::setw(2) << std::setfill('0') << minute_pregleda;
    }
};

class Pregledi {
    Pregled* pok;
    Pregled pregled;
    int d, m, g;
    std::string ime_pacijenta;
    Datum datum_pregleda, datum;
    Vrijeme vrijeme_pregleda;
    public:
    explicit Pregledi(int max_broj_pregleda);
    Pregledi(std::initializer_list<Pregled> spisak_pregleda);
    ~Pregledi();
    Pregledi(const Pregledi &pregledi);
    Pregledi(Pregledi &&pregledi);
    Pregledi &operator=(const Pregledi &pregledi);
    Pregledi &operator=(Pregledi &&pregledi);
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void RegistrirajPregled(Pregled *pregled);
    int DajBrojPregleda() const;
    int DajBrojPregledaNaDatum (const Datum &datum) const;
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenata(const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum(const Datum &datum) const;
    void IspisiSvePreglede() const;
};

int main ()
{
    try {
        int max, sati, minute, dan, mjesec, godina;
        std::string ime;
        std::cout << "Unesite maksimalan broj pregleda: ";
        std::cin >> max;
        int i=0;
        for (;;) {
            std::cout << "Unesite ime novog pacijenta ili " << "'kraj'" << " za zavrsetak unosa: ";
            std::cin.ignore(10000, '\n');
            std::getline(std::cin, ime);
            if (ime=="kraj") break;
            std::cout << "Unesite dan mjesec i godinu pregleda: ";
            std::cin >> dan >> mjesec >> godina;
            std::cout << "Unesite sate i minute pregleda: ";
            std::cin >> sati >> minute;
            Pregled p(ime, dan, mjesec, godina, sati, minute);
            i++;
            if (i==max) break;
        }
        if (i!=0) std::cout << "Trenutno su registrovani sljedeci pregledi " << std::endl;
    }
    catch (std::domain_error izuzetak) {
        std::cout << izuzetak.what() << std::endl;
    }
	return 0;
}
