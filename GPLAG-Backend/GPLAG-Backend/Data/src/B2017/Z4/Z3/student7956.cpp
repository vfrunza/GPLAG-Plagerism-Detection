/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <memory>
#include <tuple>
#include <utility>
#include <iomanip>
using namespace std;

class Datum
{
    int dan, mjesec, godina;
public:
    Datum(int dan, int mjesec, int godina)
    {
        if (dan < 1 || dan > 31 || mjesec < 1 || mjesec > 12 || godina < 0) throw domain_error ("Neispravan datum");
        this->dan = dan;
        this->mjesec = mjesec;
        this->godina = godina;
    }
    void Postavi(int dan, int mjesec, int godina)
    {
        this->dan = dan;
        this->mjesec = mjesec;
        this->godina = godina;
    }
    std::tuple<int, int, int> Ocitaj() const
    {
        return make_tuple(dan, mjesec, godina);
    }
    void Ispisi() const
    {
        cout << dan << "/" << mjesec << "/" << godina;
    }
};
class Vrijeme
{
    int sati, minute;
public:
    Vrijeme(int sati, int minute)
    {
        if (sati < 0 || sati > 23 || minute < 0 || minute > 59) throw domain_error ("Neispravno vrijeme");
        this->sati = sati;
        this->minute = minute;
    }
    void Postavi(int sati, int minute)
    {
        this->sati = sati;
        this->minute = minute;
    }
    std::pair<int, int> Ocitaj () const
    {
        return {sati, minute};
    }
    void Ispisi() const
    {
        cout << sati << ":" << minute << endl;
    }
};

class Pregled
{
    string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;
public:
    
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda,
        const Vrijeme &vrijeme_pregleda) : datum_pregleda(datum_pregleda),
        vrijeme_pregleda(vrijeme_pregleda)
    {
        this-> ime_pacijenta = ime_pacijenta;
    }
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,
        int godina_pregleda, int sati_pregleda, int minute_pregleda) :
            datum_pregleda(dan_pregleda, mjesec_pregleda, godina_pregleda), 
            vrijeme_pregleda(sati_pregleda, minute_pregleda)
    {
        this->ime_pacijenta = ime_pacijenta;
    }
    void PromijeniPacijenta(const std::string &ime_pacijenta)
    {
        this-> ime_pacijenta = ime_pacijenta;
    }
    void PromijeniDatum(const Datum &novi_datum)
    {
        datum_pregleda = novi_datum;
    }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme)
    {
        vrijeme_pregleda = novo_vrijeme;
    }
    void PomjeriDanUnaprijed()
    {
        auto trenutno (datum_pregleda.Ocitaj());
        int d = get<0>(trenutno);
        int m = get<1>(trenutno);
        int g = get<2>(trenutno);
        d++;
        if (d == 32)
            {
                    m++;
                    if(m == 13)
                        {
                            g++;
                            m = 1;
                        }
                d = 1;
            }
        datum_pregleda.Postavi(d, m, g);
    }
    void PomjeriDanUnazad()
    {
       auto trenutno (datum_pregleda.Ocitaj());
        int d = get<0>(trenutno);
        int m = get<1>(trenutno);
        int g = get<2>(trenutno);
        if (d == 0)
            {
               m--;
                    if(m == 0)
                        {
                            g--;
                            m = 31;
                        }
                d = 31;
            }
        datum_pregleda.Postavi(d, m, g);
    }
    std::string DajImePacijenta() const
    {
        return ime_pacijenta;
    }
    Datum DajDatumPregleda() const
    {
        return datum_pregleda;
    }
    Vrijeme DajVrijemePregleda() const
    {
        return vrijeme_pregleda;
    }
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2)
    {
        auto dat1 (p1.DajDatumPregleda().Ocitaj());
        int d1 = get<0>(dat1);
        int m1 = get<1>(dat1);
        int g1 = get<2>(dat1);
        auto vr1 (p1.DajVrijemePregleda().Ocitaj());
        int s1 = vr1.first;
        int min1 = vr1.second;
        
        auto dat2 (p2.DajDatumPregleda().Ocitaj());
        int d2 = get<0>(dat2);
        int m2 = get<1>(dat2);
        int g2 = get<2>(dat2);
        auto vr2 (p2.DajVrijemePregleda().Ocitaj());
        int s2 = vr2.first;
        int min2 = vr2.second;
        
        if (g1 < g2) return true;
        if (m1 < m2) return true;
        if (d1 < d2) return true;
        if (s1 < s2) return true;
        if (min1 < min2) return true;
        return false;
    }
    void Ispisi() const
    {
        cout << setw(30) << left << ime_pacijenta;
        datum_pregleda.Ispisi();
        cout << " ";
        vrijeme_pregleda.Ispisi();
        cout << endl; 
    }
};

int main ()
{
    cout << "a";
	return 0;
}
