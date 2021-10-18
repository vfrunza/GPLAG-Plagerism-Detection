#include <iostream>
#include <stdexcept>
#include <string>

class Datum
{
    int d, m, g;
    public:
    Datum(int dan, int mjesec, int godina)
    {
        int broj[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0)
            broj[1]++;
        if(dan < 1 || dan > broj[mjesec-1] || mjesec < 1 || mjesec > 12 || godina < 1)
            throw std::domain_error("Neispravan datum");
        d = dan;
        m = mjesec;
        g = godina;
    }
    void Postavi(int dan, int mjesec, int godina)
    {
        int broj[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0)
            broj[1]++;
        if(dan < 1 || dan > broj[mjesec-1] || mjesec < 1 || mjesec > 12 || godina < 1)
            throw std::domain_error("Neispravan datum");
        d = dan;
        m = mjesec;
        g = godina;
    }
    int DajDan() const
    {
        return d;
    }
    int DajMjesec() const
    {
        return m;
    }
    int DajGodinu() const
    {
        return g;
    }
    void Ispisi() const
    {
        std::cout<<DajDan()<<"/"<<DajMjesec()<<"/"<<DajGodinu();
    }
};


int main ()
{
	return 0;
}