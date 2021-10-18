/B2017/2018: Zadaća 5, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

class Datum
{
    int dan, mjesec ,godina;
    void TestirajDatum(int dan, int mjesec, int godina) const;
    int TestirajDatumUpisi(int dan, std::string, int godina)const;
    const char *imena_mjeseci[12] {"Januar", "Februar", "Mart", "April", "Maj",
                                   "Juni", "Juli", "August", "Septembar", "Oktobar", "Novembar", "Decembar"
                                  };
    const char *imena_dana[7] {
        "Ponedjeljak", "Utorak", "Srijeda", "Cetvrtak", "Petak", "Subota", "Nedjelja"
    };
    bool Ispravi(int &dan, int &mjesec, int &godina);

    int DanaProslo() const;

public:

    enum Mjeseci {
        Januar = 1, Februar, Mart, April, Maj, Juni, Juli, August, Septembar, Oktobar, Novembar, Decembar
    };

    enum Dani {
        Ponedjeljak = 1, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja
    };

    Datum(int dan, int mjesec, int godina) {
        Postavi(dan, mjesec, godina);
    }
    Datum(int dan, std::string mjesec, int godina) {
        Postavi(dan,mjesec,godina);
    }

    void Postavi(int dan, int mjesec, int godina);
    void Postavi(int dan, std::string mjesec, int godina);

    int DajDan()const {
        return dan;
    }
    Mjeseci DajMjesec() const {
        return static_cast<Mjeseci> (mjesec);
    }
    int DajGodinu() const {
        return godina;
    }
    const char* DajImeMjeseca()const {
        return imena_mjeseci[mjesec - 1];
    }
    Dani DanUSedmici() const {

        return static_cast<Dani> ((DanaProslo())% 7);
    };
    const char* DajImeDanaUSedmici() const {
        return imena_dana[static_cast<int> (DanUSedmici())];
    }

    Datum &operator ++();
    Datum operator ++(int);
    Datum &operator --();
    Datum operator --(int);

    friend Datum operator -(const Datum &prvi, int broj);
    friend Datum operator + (const Datum &prvi, int broj);

    Datum &operator +=(int broj);
    Datum &operator -=(int broj);
    operator std::string() const;

    friend int operator -(const Datum &prvi, const Datum &drugi);
    friend std::ostream &operator << (std::ostream &mecanje,  Datum a);
};

void Datum::TestirajDatum(int dan, int mjesec, int godina) const
{
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0) broj_dana[1]++;
    if(godina < 1800 || mjesec < 1 || mjesec > 12 || dan < 1 || dan > broj_dana[mjesec-1])

        throw std::domain_error("Nelegalan datum");
}

int Datum::TestirajDatumUpisi(int dan, std::string mjesec, int godina) const
{
    std::vector<std::string> imena_mjeseci {"Januar", "Februar", "Mart", "April", "Maj", "Juni", "Juli", "August", "Septembar",
                                            "Oktobar", "Novembar", "Decembar"
                                           };
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    auto pok (std::find(imena_mjeseci.begin(), imena_mjeseci.end(), mjesec));
    if (pok == imena_mjeseci.end()) throw std::domain_error("Nelegalan datum");
    auto mj = broj_dana[pok - imena_mjeseci.begin() + 1];

    if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0)   broj_dana[1]++;
    if(godina < 1800 || dan < 1 || dan > broj_dana[mj-1])
        throw std::domain_error("Nelegalan datum");

    return mj;
}



void Datum::Postavi(int dan, int mjesec, int godina)
{
    TestirajDatum(dan, mjesec, godina);

    Datum::dan = dan;
    Datum::mjesec = mjesec;
    Datum::godina = godina;
}
void Datum::Postavi(int dan, std::string mjesec, int godina)
{
    auto mjesec_broj(TestirajDatumUpisi(dan, mjesec, godina));
    Datum::dan = dan;
    Datum::mjesec = mjesec_broj;
    Datum::godina = godina;
}

int Datum::DanaProslo() const
{
    int dodatne_prestupne(0);
    int dodatni_mjeseci(0);
    int rezultat(0);

    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for(int i = 1800; i < godina; i++)
        if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0) dodatne_prestupne++;

    rezultat = (godina - 1800)*365 + dodatne_prestupne;
    for(int i = 0 ; i < mjesec; i++)
        dodatni_mjeseci+= broj_dana[i];

    rezultat+= dodatni_mjeseci + dan;

    return rezultat;

}


Datum &Datum::operator ++()
{

    int  dan_pregleda = dan;
    int mjesec_pregleda = mjesec;
    int godina_pregleda = godina;

    if(Ispravi(++dan_pregleda, mjesec_pregleda, godina_pregleda)) {
        dan_pregleda = 1;
        if(mjesec_pregleda < 12) {
            mjesec_pregleda++;
            while (Ispravi(dan_pregleda, mjesec_pregleda, godina_pregleda)) {
                dan_pregleda++;
                if(Ispravi(dan_pregleda, mjesec_pregleda, godina_pregleda) {
                dan_pregleda = 1,  mjesec_pregleda++
                if(Ispravi(dan_pregleda.mjesec_pregleda,godina_pregleda)) {
                        dan_pregleda = 1;
                        mjesec_pregleda = 1;
                        godina_pregleda++;
                    }
                }

            }
        } else {
            mjesec_pregleda = 1;
            godina_pregleda++;
        }
        while(Ispravi(dan_pregleda, mjesec_pregleda, godina_pregleda)) dan_pregleda++;
    }
    dan = dan_pregleda;
    mjesec = mjesec_pregleda;
    godina = godina_pregleda;

    return  *this;
}

Datum  Datum::operator ++(int)
{
    Datum pomocni(dan, mjesec, godina);
    ++*this;
    return pomocni;
}

Datum &Datum::operator --()
{

    int dan_pregleda = dan;
    int mjesec_pregleda = mjesec;
    int godina_pregleda = godina;

    if(Ispravi(--dan_pregleda, mjesec_pregleda, godina_pregleda)) {
        dan_pregleda = 31;
        if(mjesec_pregleda > 1) {
            mjesec_pregleda--;
            while (Ispravi(dan_pregleda, mjesec_pregleda, godina_pregleda)) dan_pregleda--;
        } else {
            mjesec_pregleda = 12;
            godina_pregleda--;
            if(godina_pregleda < 1800) throw std::domain_error("Nelegalan datum");
        }
        while (Ispravi(dan_pregleda, mjesec_pregleda, godina_pregleda)) dan_pregleda--;
    }
    dan = dan_pregleda;
    mjesec = mjesec_pregleda;
    godina = godina_pregleda;

    return  *this;

}

Datum Datum::operator --(int)
{
    Datum pomocni(dan, mjesec, godina);
    --*this;
    return pomocni;
}


bool Datum::Ispravi(int &dan, int &mjesec, int &godina)
{
    int broj_dana[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0) broj_dana[1]++;
    return (godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > broj_dana[mjesec - 1]);

}
Datum operator -(const Datum &prvi, int broj)
{
    Datum pomocni(prvi.dan, prvi.mjesec, prvi.godina);
    if(broj >= 0) for(int i = 0; i < broj; i++)
            --pomocni;
    else {
        broj *= -1;
        for(int i = 0; i < broj; i++)
            ++pomocni;
    }
    return pomocni;

}
Datum operator + (const Datum &prvi, int broj)
{
    Datum pomocni(prvi.dan, prvi.mjesec, prvi.godina);
    broj *= -1;
    return pomocni - broj;

}
Datum &Datum::operator +=(int broj)
{
    Datum pomocni(dan, mjesec, godina);
    *this = *this + broj;
    return *this;
}
Datum &Datum::operator -=(int broj)
{
    Datum pomocni(dan, mjesec, godina);
    *this = *this + broj;
    return *this;
}

int operator -(const Datum &prvi, const Datum &drugi)
{
    return std::abs(prvi.DanaProslo() - drugi.DanaProslo());
}
std::ostream &operator << (std::ostream &mecanje,  Datum a)
{

    std::cout<< a.DajDan() << ". ";
    std::cout<< a.DajImeMjeseca() << " " << a.DajGodinu() << "." << "(" << a.DajImeDanaUSedmici() << ")";
    return mecanje;

}



int main ()

{
    //AT1 konstruktor (javni)
    {
        //AT3 (javni) ++ -- += operatori, DajImeMjeseca, DajImeDanaUSedmici
        Datum d(3,1,2010);
        d++;
        std::cout<<d.DajDan()<<" "<<d.DajImeMjeseca()<<" "<<d.DajGodinu()<<" "<<d.DajImeDanaUSedmici()<<" ";
        d+=4;
        std::cout<<d.DajDan()<<" "<<d.DajImeMjeseca()<<" "<<d.DajGodinu()<<" "<<d.DajImeDanaUSedmici()<<" ";
        d--;
        --d;
        std::cout<<d.DajDan()<<" "<<d.DajImeMjeseca()<<" "<<d.DajGodinu()<<" "<<d.DajImeDanaUSedmici() << std::endl;
    }

    return 0;
}
