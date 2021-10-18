/B2017/2018: Zadaća 5, Zadatak 3

#include <iostream>
#include <cmath>
#include <stdexcept>

class Datum {
    int dan,mjesec,godina;
    
    public:
    enum Mjeseci{Januar=1,Februar,Mart,April,Maj,Juni,Juli,August,Septembar,Oktobar,Novembar,Decembar};
    enum Dani{Ponedjeljak=1,Utorak,Srijeda,Cetvrtak,Petak,Subota,Nedjelja};
    void IspravnostDatuma(int dan,int mjesec,int godina);
    
    Datum(int dan,int mjesec,int godina);
    Datum(int dan,Mjeseci mjesec,int godina);
    void Postavi(int dan,int mjesec,int godina);
    void Postavi(int dan,Mjeseci mjesec,int godina);
    int DajDan() const { return dan; }
    Mjeseci DajMjesec() const { return Mjeseci(mjesec); }
    int DajGodinu() const { return godina; }
    char *DajImeMjeseca() const;
    Dani DanUSedmici() const;
    char *DajImeDanaUSedmici() const;
/*    Datum operator ++(Datum &d);
    Datum operator +(const Datum &d,int n);
    Datum operator ++(Datum &d,int);
    Datum operator --(Datum &d,int);
    Datum operator --(Datum &d);
    Datum operator +=(Datum &d,int n);
    Datum operator -=(Datum &d,int n);
    bool operator ==(const Datum &d1,const Datum &d2);
    bool operator !=(const Datum &d1,const Datum &d2);
    bool operator >(const Datum &d1,const Datum &d2);
    bool operator <(const Datum &d1,const Datum &d2);
    bool operator >=(const Datum &d1,const Datum &d2);
    bool operator <=(const Datum &d1,const Datum &d2);
    std::ostream &operator <<(std::ostream &tok,const Datum &d);
    std::istream &operator >>(std::istream &tok,const Datum &d);
    int operator -(const Datum &d1,const Datum &d2);
    */
};
void Datum::IspravnostDatuma(int dan,int mjesec,int godina){
    int mjeseci[] {31,28,31,30,31,30,31,31,30,31,30,31};
    if((godina%4==0 && godina%100!=0) || godina%400==0) mjeseci[1]++;
    if(godina<1800 || mjesec<1 || mjesec>12 || dan<1 || dan>mjeseci[mjesec-1])
         throw std::domain_error("Nelegalan datum");
}
Datum::Datum(int dan,int mjesec,int godina){
    IspravnostDatuma(dan,mjesec,godina);
    Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
}
Datum::Datum(int dan,Mjeseci mjesec,int godina){
    int mjesec1=mjesec;
    IspravnostDatuma(dan,mjesec1,godina);
    Datum::dan=dan; Datum::mjesec=mjesec1; Datum::godina=godina;
}
void Datum::Postavi(int dan,int mjesec,int godina){
    IspravnostDatuma(dan,mjesec,godina);
    Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
}
void Datum::Postavi(int dan,Mjeseci mjesec,int godina){
    int mjesec1=mjesec;
    IspravnostDatuma(dan,mjesec1,godina);
    Datum::dan=dan; Datum::mjesec=mjesec1; Datum::godina=godina;
}
char *Datum::DajImeMjeseca() const{
    char *ime_mjeseca[12]={"Januar","Februar","Mart","April","Maj","Juni","Juli","August","Septembar","Oktobar","Novembar","Decembar"};
    return ime_mjeseca[mjesec-1];
}
int Datum::KolikoDana(int dan,int mjesec,int godina) {
    int koliko_dana(0);
}
Datum::Dani Datum::DanUSedmici() const{
    
}
//char *Datum::DajImeDanaUSedmici() const;


int main () {
    Datum d1(18,01,1997);
    Datum d2(15,11,1997);
    std::cout<<d1.DajImeMjeseca()<<std::endl;
	return 0;
}
