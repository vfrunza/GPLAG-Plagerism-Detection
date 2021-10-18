/B 2016/2017, Zadaća 4, Zadatak 4
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <memory>
using namespace std;
class Datum {
    int dan,mjesec,godina;
    public:
    Datum(int dan,int mjesec,int godina){
        int niz[12]={31,28,31,30,31,30,30,31,30,31,30,31};
        if(godina % 4==0 && godina %100!=0 && godina %400==0)niz[1]+=1;
        if(dan>niz[mjesec-1]||mjesec<0 || mjesec>12||dan<0)throw domain_error("Neispravan datum");
        Datum::dan=dan;
        Datum::mjesec=mjesec;
        Datum::godina=godina;
    }
    void Postavi(int dan,int mjesec,int godina){
        int niz [12] = {31,28,31,30,31,30,30,31,30,31,30,31};
        if(godina % 4==0 && godina %100!=0 && godina %400==0)niz[1]+=1;
        if(dan>niz[mjesec-1]||mjesec<0 || mjesec>12||dan<0)throw domain_error("Neispravan datum");
        Datum::dan=dan;
        Datum::mjesec=mjesec;
        Datum::godina=godina;
    }
    int DajDan()const{return dan;}
    int DajMjesec()const {return mjesec;}
    int DajGodinu()const {return godina;}
    void Ispisi()const{
        cout<<dan<<"/"<<mjesec<<"/"<<godina;
    }
};
class Kupac{
    string ime;
    Datum datum;
    char ToUpper(char s){
        if(s>='a' && s<='z') s-=32;
    }
}
int main ()
{
	return 0;
}