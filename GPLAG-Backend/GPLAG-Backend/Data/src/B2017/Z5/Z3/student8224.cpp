/B2017/2018: Zadaća 5, Zadatak 3
#include <iostream>
#include <stdexcept>


class Datum
{
    int dan, mjesec, godina;

    public:
    enum Mjeseci {Januar = 1, Februar, Mart, April, Maj, Juni, Juli, August, Septembar, Oktobar, Novembar, Decembar};
    enum Dani {Ponedjeljak = 1, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja};
    Datum (int dan, int mjesec, int godina)
    {
        if (dan > 31 || dan <= 0 || mjesec > 12 || mjesec <= 0 || godina < 1800) throw std::domain_error("Nelegalan datum");
        this->dan = dan;
        this->mjesec = mjesec;
        this->godina = godina;
    }
    
    Datum (int dan, Mjeseci mjesec, int godina)
    {
        if (dan > 31 || dan <= 0 || mjesec > 12 || mjesec <= 0 || godina < 1800) throw std::domain_error("Nelegalan datum");
        this->dan = dan;
        this->mjesec = mjesec;
        this->godina = godina;
    }
    
    void Postavi (int dan, int mjesec, int godina)
    {
        if (dan > 31 || dan <= 0 || mjesec > 12 || mjesec <= 0 || godina < 1800) throw std::domain_error ("Nelegalan datum");
        this->dan = dan;
        this->mjesec = mjesec;
        this->godina = godina;
    }
    
    void Postavi (int dan, Mjeseci mjesec, int godina)
    {
        if (dan > 31 || dan <= 0 || mjesec > 12 || mjesec <= 0 || godina < 1800) throw std::domain_error ("Nelegalan datum");
        this->dan = dan;
        this->mjesec = mjesec;
        this->godina = godina;
    }
    
    int DajDan() const { return dan; }
    Mjeseci DajMjesec() const { return mjesec; }
    int DajGodinu() const { return godina; }
    

};

char* Datum::DajImeMjeseca() const
{
    
}
int main ()
{
    Datum d(27,05,1996);
    
    
	return 0;
}
