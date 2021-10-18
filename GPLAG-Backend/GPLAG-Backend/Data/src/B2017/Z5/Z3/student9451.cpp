/B2017/2018: Zadaća 5, Zadatak 3
#include <iostream>

using namespace std;

enum Mjeseci {Januar = 1, Februar, Mart, April, Maj, Juni, Juli, August,
              Septembar, Oktobar, Novembar, Decembar};

enum Dani {Ponedjeljak = 1, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja);

class Datum
{
    int d;
    
    public:
   
    enum Mjeseci {Januar = 1, Februar, Mart, April, Maj, Juni, Juli, August,
              Septembar, Oktobar, Novembar, Decembar};

    enum Dani {Ponedjeljak = 1, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja);

    Datum(int ,int ,int );
    Datum(Dani,Mjeseci,int );
    void Postavi(int ,int ,int );
    void Postavi(Dani,Mjeseci,int );
    int DajDan() const; 
    Mjeseci DajMjesec() const;
    int DajGodinu() const;
    char *DajImeMjeseca() const;
    Dani DanUSedmici() const;
    char *DajImeDanaUSedmici() const;
    /*
        operatori ++,--,+,-,+=,-=,==,!=,<,>,<=,>=,<<(23.Maj 2012.(Srijeda)),>>(23/5/2012)
        operator konverzije u string
        operator konverzije u int
        
    */
}

int main ()
{
	return 0;
}
