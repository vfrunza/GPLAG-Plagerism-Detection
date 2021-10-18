/B2017/2018: Zadaća 5, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <ios>

using namespace std;

class Datum
{
    int Dan, Mjesec, Godina;
    void DaLiJeKorektanDatum(int dan, int mjesec, int godina)
    {
        int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0)
            broj_dana[1]++;
        if(dan < 1 || mjesec < 1 || godina < 1800 || dan > broj_dana[mjesec - 1] || mjesec > 12)
            throw domain_error("Nelegalan datum");
    }
    bool DaLiJePrestupna(int godina) const
    {
        return godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0;
    }
    int DajBrojDana(int dan, int mjesec, int godina) const
    {
        int brojDana = 0;
        int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for(int i = 1; i < godina; i++)
        {
            brojDana += 365;
            if(DaLiJePrestupna(i)) 
                brojDana++;
        }
        if(DaLiJePrestupna(godina)) 
            broj_dana[1]++;
        for(int i = 1; i < mjesec; i++) 
            brojDana += broj_dana[i - 1];
        brojDana += dan;
        return brojDana;
    }
public:
    enum Mjeseci {Januar = 1, Februar, Mart, April, Maj, Juni, Juli, August, Septembar, Oktobar, Novembar, Decembar};
    enum Dani {Ponedjeljak = 1, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja};
    Datum(int dan, int mjesec, int godina);
    Datum(int dan, Mjeseci mjesec, int godina);
    void Postavi(int dan, int mjesec, int godina);
    void Postavi(int dan, Mjeseci mjesec, int godina);
    int DajDan() const { return Dan; }
    Mjeseci DajMjesec() const { return Mjeseci(Mjesec); }
    int DajGodinu() const { return Godina; }
    char *DajImeMjeseca() const;
    Dani DanUSedmici() const;
    char *DajImeDanaUSedmici() const;
    friend Datum operator ++(Datum &d);
    friend Datum operator ++(Datum &d, int);
    friend Datum operator --(Datum &d);
    friend Datum operator --(Datum &d, int);
    friend int operator -(const Datum &d1, const Datum &d2);
    friend bool operator ==(const Datum &d1, const Datum &d2);
    friend bool operator !=(const Datum &d1, const Datum &d2);
    friend bool operator <(const Datum &d1, const Datum &d2);
    friend bool operator >(const Datum &d1, const Datum &d2);
    friend bool operator <=(const Datum &d1, const Datum &d2);
    friend bool operator >=(const Datum &d1, const Datum &d2);
    friend ostream &operator <<(ostream &tok, const Datum &d);
    friend istream &operator >>(istream &tok, Datum &d);
};

Datum::Datum(int dan, int mjesec, int godina)
{
    DaLiJeKorektanDatum(dan, mjesec, godina);
    Dan = dan;
    Mjesec = mjesec;
    Godina = godina;
}

Datum::Datum(int dan, Mjeseci mjesec, int godina)
{
    int m = mjesec;
    DaLiJeKorektanDatum(dan, m, godina);
    Dan = dan;
    Mjesec = mjesec;
    Godina = godina;
}

void Datum::Postavi(int dan, int mjesec, int godina)
{
    DaLiJeKorektanDatum(dan, mjesec, godina);
    Dan = dan;
    Mjesec = mjesec;
    Godina = godina;
}

void Datum::Postavi(int dan, Mjeseci mjesec, int godina)
{
    int m = mjesec;
    DaLiJeKorektanDatum(dan, m, godina);
    Dan = dan;
    Mjesec = mjesec;
    Godina = godina;
}

char *Datum::DajImeMjeseca() const
{
    char *imena_mjeseci[12] = {"Januar", "Februar", "Mart", "April", "Maj", "Juni",
     "Juli", "August", "Septembar", "Oktobar", "Novembar", "Decembar"};
     
    return imena_mjeseci[Mjesec - 1];
}

Datum::Dani Datum::DanUSedmici() const
{
    int broj_dana = DajBrojDana(Dan, Mjesec, Godina);
    if(broj_dana % 7 == 0) return Dani(7);
    else return Dani(broj_dana % 7);
}

char *Datum::DajImeDanaUSedmici() const
{
    char *imena_dana[] = {"Nedjelja", "Ponedjeljak", "Utorak", "Srijeda", "Cetvrtak", "Petak", "Subota"};
    if(DanUSedmici() == 7) return imena_dana[0];
    return imena_dana[DanUSedmici()];
}

Datum operator ++(Datum &d)
{
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(d.Godina % 4 == 0 && d.Godina % 100 != 0 || d.Godina % 400 == 0)
            broj_dana[1]++;
    d.Dan++;
    if(d.Dan == broj_dana[d.Mjesec - 1] + 1) 
    {
        d.Dan = 1;
        d.Mjesec++;
    }
    if(d.Mjesec == 13)
    {
        d.Mjesec = 1;
        d.Godina++;
    }
    
    return d;
}

Datum operator ++(Datum &d, int)
{
    Datum temp(d.Dan, d.Mjesec, d.Godina);
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(d.Godina % 4 == 0 && d.Godina % 100 != 0 || d.Godina % 400 == 0)
            broj_dana[1]++;
    d.Dan++;
    if(d.Dan == broj_dana[d.Mjesec - 1] + 1)
    {
        d.Dan = 1;
        d.Mjesec++;
    }
    if(d.Mjesec == 13)
    {
        d.Mjesec = 1;
        d.Godina++;
    }
    
    return temp;
}

Datum operator --(Datum &d)
{
    Datum test(d.Dan, d.Mjesec, d.Godina);
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(test.Godina % 4 == 0 && test.Godina % 100 != 0 || test.Godina % 400 == 0)
            broj_dana[1]++;
    test.Dan--;
    if(test.Dan == 0)
    {
        if(test.Mjesec == 1)
        {
            test.Mjesec == 12;
            test.Godina--;
        }
        else test.Mjesec--;
        test.Dan = broj_dana[test.Mjesec - 1];
    }
    if(test.Godina < 1800) throw domain_error("Nelegalan datum");
    d.Dan = test.Dan;
    d.Mjesec = test.Mjesec;
    d.Godina = test.Godina;
    
    return d;
}

Datum operator --(Datum &d, int)
{   
    Datum temp(d.Dan, d.Mjesec, d.Godina);
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(d.Godina % 4 == 0 && d.Godina % 100 != 0 || d.Godina % 400 == 0)
            broj_dana[1]++;
    d.Dan--;
    if(d.Dan == 0)
    {
        if(d.Mjesec == 1)
        {
            d.Mjesec == 12;
            d.Godina--;
        }
        else d.Mjesec--;
        d.Dan = broj_dana[d.Mjesec - 1];
    }
    
    if(d.Godina < 1800)
    {
        d.Dan = temp.Dan;
        d.Mjesec = temp.Mjesec;
        d.Godina = temp.Godina;
        throw domain_error("Nelegalan datum");
    }
    
    return temp;
}

int operator -(const Datum &d1, const Datum &d2)
{
    int brojDana = fabs(d1.DajBrojDana(d1.Dan, d1.Mjesec, d1.Godina) - d1.DajBrojDana(d2.Dan, d2.Mjesec, d2.Godina));
    return brojDana;
}

bool operator ==(const Datum &d1, const Datum &d2)
{
    int brojDana1 = d1.DajBrojDana(d1.Dan, d1.Mjesec, d1.Godina);
    int brojDana2 = d2.DajBrojDana(d2.Dan, d2.Mjesec, d2.Godina);
    
    return brojDana1 == brojDana2;
}

bool operator !=(const Datum &d1, const Datum &d2)
{
    return !(d1 == d2);
}

bool operator <(const Datum &d1, const Datum &d2)
{
    int brojDana1 = d1.DajBrojDana(d1.Dan, d1.Mjesec, d1.Godina);
    int brojDana2 = d2.DajBrojDana(d2.Dan, d2.Mjesec, d2.Godina);
    
    return brojDana1 < brojDana2;
}

bool operator >(const Datum &d1, const Datum &d2)
{
    int brojDana1 = d1.DajBrojDana(d1.Dan, d1.Mjesec, d1.Godina);
    int brojDana2 = d2.DajBrojDana(d2.Dan, d2.Mjesec, d2.Godina);
    
    return brojDana1 > brojDana2;
}

bool operator <=(const Datum &d1, const Datum &d2)
{
    int brojDana1 = d1.DajBrojDana(d1.Dan, d1.Mjesec, d1.Godina);
    int brojDana2 = d2.DajBrojDana(d2.Dan, d2.Mjesec, d2.Godina);
    
    return brojDana1 <= brojDana2;
}

bool operator >=(const Datum &d1, const Datum &d2)
{
    int brojDana1 = d1.DajBrojDana(d1.Dan, d1.Mjesec, d1.Godina);
    int brojDana2 = d2.DajBrojDana(d2.Dan, d2.Mjesec, d2.Godina);
    
    return brojDana1 >= brojDana2;
}

ostream &operator <<(ostream &tok, const Datum &d)
{
    tok << d.DajDan() << "." << d.DajImeMjeseca() << " " << d.DajGodinu() << ". (" << d.DajImeDanaUSedmici() << ")";
    return tok;
}

istream &operator >>(istream &tok, Datum &d)
{
    char z1, z2;
    tok >> d.Dan >> z1 >> d.Mjesec >> z2 >> d.Godina;
    if(z1 != '/' || z2 != '/' || isalpha(d.Dan) || isalpha(d.Mjesec) || isalpha(d.Godina))
    {
        tok.setstate(ios::failbit);
    }
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(d.DaLiJePrestupna(d.Godina)) 
        broj_dana[1]++;
    if(d.Dan < 1 || d.Mjesec < 1 || d.Godina < 1800 || d.Dan > broj_dana[d.Mjesec - 1] || d.Mjesec > 12)
    {    
        tok.setstate(ios::failbit);
    }
    
    return tok;
}

int main ()
{
    Datum d(11, 6, 2018);
    Datum d1(20, 6, 2018);
    Datum d2(11,6,2018);
    string dan;
    try
    {
        //dan = d1;
        cout << dan << endl;
        cout << d.DajDan() << " " << d.DajMjesec() <<  " (" << d.DajImeMjeseca() << ") " << d.DajGodinu() << ", " << d.DajImeDanaUSedmici() << endl;
        ++d;
        cout << d.DajDan() << " " << d.DajMjesec() <<  " (" << d.DajImeMjeseca() << ") " << d.DajGodinu() << ", " << d.DajImeDanaUSedmici() << endl;
        d++;
        cout << d.DajDan() << " " << d.DajMjesec() <<  " (" << d.DajImeMjeseca() << ") " << d.DajGodinu() << ", " << d.DajImeDanaUSedmici() << endl;
        --d;
        cout << d.DajDan() << " " << d.DajMjesec() <<  " (" << d.DajImeMjeseca() << ") " << d.DajGodinu() << ", " << d.DajImeDanaUSedmici() << endl;
        d--;
        cout << d.DajDan() << " " << d.DajMjesec() <<  " (" << d.DajImeMjeseca() << ") " << d.DajGodinu() << ", " << d.DajImeDanaUSedmici() << endl;
        cout << d.DajDan() << " " << d.DajMjesec() <<  " (" << d.DajImeMjeseca() << ") " << d.DajGodinu() << ", " << d.DajImeDanaUSedmici() << endl;
        cout << d - d1 << endl;
        if(d != d1) cout << "Razliciti" << endl;
        else cout << "Isti" << endl;
        cout << d1;
        cout << "\nUnesite datum: ";
        cin >> d2;
        cout << d2;
        if(d > d2) cout << "\nVeci" << endl;
        if(d < d2) cout << "\nManji" << endl;
        else cout << "OK";
    }
    catch(domain_error e)
    {
        cout << e.what() << endl;
    }
	return 0;
}