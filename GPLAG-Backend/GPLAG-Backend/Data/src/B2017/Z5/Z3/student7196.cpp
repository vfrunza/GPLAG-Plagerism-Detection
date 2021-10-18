/B2017/2018: Zadaća 5, Zadatak 3
#include <iostream>
#include <stdexcept>

class Datum {
    int dan, mjesec, godina;
    static int BrojDana(int mjesec, int godina);
public:
    enum Mjeseci {
        Januar=1, Februar, Mart, April, Maj, Juni, Juli, August, Septembar, Oktobar, Novembar, Decembar
    };
    enum Dani {
        Ponedjeljak=1, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja
    };
    Datum(int dan, int mjesec, int godina) {
        Postavi(dan, mjesec, godina);
    }
    Datum(int dan, Mjeseci mjesec, int godina) {
        Postavi(dan, mjesec, godina);
    }
    void Postavi(int dan, int mjesec, int godina);
    void Postavi(int dan, Mjeseci mjesec, int godina);
    int DajDan() const {
        return dan;
    }
    int DajGodinu() const {
        return godina;
    }
    Mjeseci DajMjesec() const {
        return Mjeseci(mjesec);
    }
};

int Datum::BrojDana(int mjesec, int godina) {
    int broj_dana_u_mjesecu[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (godina%4==0 && godina%100!=0 || godina%400==0) broj_dana_u_mjesecu[1]=29;
    return broj_dana_u_mjesecu[mjesec-1];
}

void Datum::Postavi(int dan, int mjesec, int godina) {
    if (dan<1 || mjesec<1 || godina<1800 || mjesec>12 || dan>BrojDana(mjesec, godina))
        throw std::domain_error("Nelegalan datum");
    Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
}

void Datum::Postavi(int dan, Mjeseci mjesec, int godina) {
    int mj;
    mj=int(mjesec);
    if (dan<1 || mj<1 || godina<1800 || mj>12 || dan>BrojDana(mj, godina))
        throw std::domain_error("Nelegalan datum");
    Datum::dan=dan; Datum::mjesec=mj; Datum::godina=godina;
}

int main ()
{
    
	return 0;
}
