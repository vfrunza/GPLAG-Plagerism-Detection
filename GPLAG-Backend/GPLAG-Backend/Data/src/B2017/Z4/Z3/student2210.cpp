/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <tuple>
using namespace std;
class Datum{
    private:
    int dan,mjesec,godina;
    public:
    Datum(int dan,int mjesec,int godina){ 
        int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
        if(godina%4==0 && (godina%100!=0 || godina%400==0)) broj_dana[1]++;
        if(godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>broj_dana[mjesec-1]) throw domain_error("Neispravan datum");
        Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
    }
    void Postavi(int dan,int mjesec,int godina){
        int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
        if(godina%4==0 && (godina%100!=0 || godina%400==0)) broj_dana[1]++;
        if(godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>broj_dana[mjesec-1]) throw domain_error("Neispravan datum");
        Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
    }
    tuple<int,int,int>Ocitaj() const{ return make_tuple(Datum::dan,Datum::mjesec,Datum::godina);}
    void Ispisi() const{ cout<<Datum::dan<<"/"<<Datum::mjesec<<"/"<<Datum::godina;}
};
class Vrijeme{
    private:
    int sati,minute;
    public:
    Vrijeme(int sati,int minute){
        if(sati<0 || sati>23 || minute<0 || minute>59) throw domain_error("Neispravno vrijeme");
        Vrijeme::sati=sati; Vrijeme::minute=minute;
    }
    void Postavi(int sati,int minute){
        if(sati<0 || sati>23 || minute<0 || minute>59) throw domain_error("Neispravno vrijeme");
        Vrijeme::sati=sati; Vrijeme::minute=minute;
    }
    pair<int,int>Ocitaj() const { return make_pair(Vrijeme::sati,Vrijeme::minute);}
    void Ispisi() const { cout<<Vrijeme::sati<<":"<<Vrijeme::minute;}
};
class Pregled{
    private:
    string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;
    public:
    Pregled(const string &ime_pacijenta,const Datum &datum_pregleda,const Vrijeme &vrijeme_pregleda){
        Pregled::ime_pacijenta=ime_pacijenta;
        Pregled::datum_pregleda=datum_pregleda;
        Pregled::vrijeme_pregleda=vrijeme_pregleda;
    }
    
};
int main ()
{
	return 0;
}
