/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>

class Datum{
    int dan, mjesec, godina;
    void Test(int d, int m, int g){
        int broj_dana[]={31,28,31,30,31,30,31,31,30,31};
        if((g%4==0 && g%100!=0) || g%400==0) broj_dana[1]++;
        if(g<1 || d<1 || m<1 || m>12 || d>broj_dana[m-1])
        throw std::domain_error("Neispravan datum");
    }
    public:
    Datum(int dan, int mjesec, int godina){Postavi(dan, mjesec, godina);}
    void Postavi(int dan, int mjesec, int godina){
        Test(dan,mjesec, godina);
        Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
    }
    int DajDan()const{return dan;}
    int DajMjesec()const{return mjesec;}
    int DajGodinu()const{return godina;}
    void Ispisi()const{std::cout<<dan<<"/"<<mjesec<<"/"<<godina;}

};
int main ()
{
	return 0;
}