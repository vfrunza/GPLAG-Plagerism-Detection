/B2017/2018: Zadaća 5, Zadatak 3
#include <iostream>
#include <stdexcept>

class Datum
{
    int dan, mjesec, godina;
    public:
    enum Mjeseci {Januar = 1, Februar, Mart, April, Maj, Juni, Juli, August, Septembar, Oktobar, Novembar, Decembar};
    enum Dani {Ponedjeljak = 1, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja};
    Datum (int dan, int mjesec, int godina) : dan(0), mjesec(0), godina(0)
    {
        dan = dan; mjesec = mjesec; godina = godina;
        
        if (dan < 1 || dan > 31 || mjesec < 1 || mjesec > 12 || godina < 1800) throw std::domain_error ("Nelegalan datum");
    }
    Datum (int dan, Mjeseci mjesec, int godina) : dan(dan), mjesec(mjesec), godina(godina)
    {
        if (dan < 1 || dan > 31 || mjesec < 1 || mjesec > 12 || godina < 1800) throw std::domain_error ("Nelegalan datum");
    }
    void Postavi(int dan, int mjesec, int godina);
    void Postavi(int dan, Mjeseci mjesec, int godina);
    int DajDan() const {return dan;}
    Mjeseci DajMjesec() const {Mjeseci mjesec; return mjesec; }
    int DajGodinu() const {return godina;}
    Mjeseci *DajImeMjeseca(Mjeseci *mjesec) { return mjesec;}
    Dani DanUSedmici() const {Dani dan; return dan;}
    Dani *DajImeDanaUSedmici (Dani *dan){return dan;}
    
    
};
void Datum::Postavi(int dan, int mjesec, int godina)
{
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0) broj_dana[1]++;
    if(godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > broj_dana[mjesec - 1])
        throw std::domain_error ("Nesipravan datum");
    this->dan = dan; this->mjesec = mjesec; this->godina = godina;
}

void Datum::Postavi(int dan, Mjeseci mjesec, int godina)
{
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0) broj_dana[1]++;
    if(godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > broj_dana[mjesec - 1])
        throw std::domain_error ("Nesipravan datum");
    this->dan = dan; this->mjesec = mjesec; this->godina = godina;
}

int main ()
{
	return 0;
}
