#include <iostream>
#include <stdexcept>

class Datum{
    int dan, mjesec, godina;
    int ukupnoDana;
    
    int danaUmjesecu[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31};
    char* imenaMjeseci[12]{
        "Januar", "Februar", "Mart", "April", "Maj", "Juni", "Juli", "August", "Septembar", "Oktobar", "Novembar", "Decembar"
    }
    char* imenaDana[12]{
        "Ponedjeljak", "Utorak", "Srijeda", "Cetvrtak", "Petak", "Subota", "Nedjelja"
    }
    bool Prestupna(int g){
        return (g % 4 == 0 && g % 100 != 0) || g % 400 == 0;
    }
    bool ProvjeriDatum(int dan, int mjesec, int godina){
        return godina >= 1800 && mjesec >= 1 && mjesec <= 12 && dan >= 1 && dan <= (danaUmjesecu[mjesec-1] + Prestupna(godina));
    }
    int DateToDays(int dan, int mjesec, int godina){
        
    }
    
public:
    enum Mjeseci {
        Januar = 1, Februar, Mart, April, Maj, Juni, Juli, August, Septembar, Oktobar, Novembar, Decembar
    };
    enum Dani {
        Ponedjeljak = 1, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja
    };
    
    Datum(int dan, int mjesec, int godina);
    Datum(int dan, Mjeseci mjesec, int godina);
    void Postavi(int dan, int mjesec, int godina);
    void Postavi(int dan, Mjeseci mjesec, int godina);
    
    int DajDan() const { return dan; }
    Mjeseci DajMjesec() const { return Mjeseci(mjesec); }
    int DajGodinu() const { return godina; }
    char* DajImeMjeseca() const { return imenaMjeseci[mjesec-1]; }
    Dani DanUSedmici() const { return Dani(dan); }
    char* DajImeDanaUSedmici() const { return imenaDana[dan-1]; }
};

int main(){
    
    std::cout << "Oke";
    
    return 0;
}

Datum::Datum(int dan, int mjesec, int godina){
    if(!ProvjeriDatum(dan, mjesec, godina))
        throw std::domain_error("Nelegalan datum");
    Datum::dan = dan;
    Datum::mjesec = mjesec;
    Datum::godina = godina;
}

Datum::Datum(int dan, Mjeseci mjesec, int godina){
    if(!ProvjeriDatum(dan, int(mjesec), godina))
        throw std::domain_error("Nelegalan datum");
    Datum::dan = dan;
    Datum::mjesec = int(mjesec);
    Datum::godina = godina;
}

void Datum::Postavi(int dan, int mjesec, int godina){
    if(!ProvjeriDatum(dan, mjesec, godina))
        throw std::domain_error("Nelegalan datum");
    Datum::dan = dan;
    Datum::mjesec = mjesec;
    Datum::godina = godina;
}

void Datum::Postavi(int dan, Mjeseci mjesec, int godina){
    if(!ProvjeriDatum(dan, int(mjesec), godina))
        throw std::domain_error("Nelegalan datum");
    Datum::dan = dan;
    Datum::mjesec = int(mjesec);
    Datum::godina = godina;
}
