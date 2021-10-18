/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>

class Datum
{
    private:
    int d;
    int m;
    int g;
    public:
    Datum(int dan, int mjesec, int godina)
    {
        Postavi(dan,mjesec,godina);
    }
    void Postavi(int dan, int mjesec, int godina)
    {
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
};

int main ()
{
	return 0;
}