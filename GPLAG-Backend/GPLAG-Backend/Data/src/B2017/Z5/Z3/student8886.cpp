/B2017/2018: Zadaća 5, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <string>
class Datum{
    int dan, mjesec, godina;
    public:
    enum Mjeseci {Januar = 1, Februar, Mart, April, Maj, Juni, Juli, August,Septembar, Oktobar, Novembar, Decembar};  
    enum Dani {Ponedjeljak = 1, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja};
    Datum(int dan, int mjesec, int godina);
    Datum(int dan, Mjeseci mjesec, int godina);
    void Postavi(int dan, int mjesec, int godina);
    void Postavi(int dan, Mjeseci mjesec, int godina);
    int DajDan()const;
    Mjeseci DajMjesec()const;
    int DajGodinu()const;
    const char *DajImeMjeseca()const;
    Dani DanUSedmici()const;
    const char *DajImeDanaUSedmici()const;
    friend Datum &operator++ (Datum &datum);
    friend Datum &operator-- (Datum &datum);
    friend Datum operator++ (Datum &datum, int);
    friend Datum operator-- (Datum &datum, int);
    friend Datum operator +(const Datum &datum, int broj);
    friend Datum operator -(const Datum &datum, int broj);
    friend Datum operator +=(Datum &datum, int broj);
    friend Datum operator -=(Datum &datum, int broj);
    friend int operator -(const Datum &datum1, const Datum &datum2);
    friend bool operator ==(const Datum &datum1, const Datum &datum2);
    friend bool operator !=(const Datum &datum1, const Datum &datum2);
    friend bool operator <(const Datum &datum1, const Datum &datum2);
    friend bool operator >(const Datum &datum1, const Datum &datum2);
    friend bool operator <=(const Datum &datum1, const Datum &datum2);
    friend bool operator >=(const Datum &datum1, const Datum &datum2);
    friend std::ostream &operator <<(std::ostream &tok, const Datum &datum);
    friend std::istream &operator >>(std::istream &tok, Datum &datum);
    operator std::string();
    operator int();
};
    Datum::Datum(int dan, int mjesec, int godina){
        int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
        if((godina%4 == 0 && godina%100 != 0) || godina%400 == 0) broj_dana[1]++;
        if(godina<1800 || dan < 1 || mjesec < 1 || mjesec > 12 || dan>broj_dana[mjesec-1]) throw std::domain_error("Nelegalan datum");
        Datum::dan=dan;
        Datum::mjesec=mjesec;
        Datum::godina=godina;
    }
    Datum::Datum(int dan, Mjeseci mjesec, int godina){
        int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
        if((godina%4 == 0 && godina%100 != 0) || godina%400 == 0) broj_dana[1]++;
        if(godina<1800 || dan < 1 || mjesec < 1 || mjesec > 12 || dan>broj_dana[mjesec-1]) throw std::domain_error("Nelegalan datum");
        Datum::dan=dan;
        Datum::mjesec=mjesec;
        Datum::godina=godina;
    }
    void Datum::Postavi(int dan, int mjesec, int godina){
        int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
        if((godina%4 == 0 && godina%100 != 0) || godina%400 == 0) broj_dana[1]++;
        if(godina<1800 || dan < 1 || mjesec < 1 || mjesec > 12 || dan>broj_dana[mjesec-1]) throw std::domain_error("Nelegalan datum");
        Datum::dan=dan;
        Datum::mjesec=mjesec;
        Datum::godina=godina;
    }
    void Datum::Postavi(int dan, Mjeseci mjesec, int godina){
        int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
        if((godina%4 == 0 && godina%100 != 0) || godina%400 == 0) broj_dana[1]++;
        if(godina<1800 || dan < 1 || mjesec < 1 || mjesec > 12 || dan>broj_dana[mjesec-1]) throw std::domain_error("Nelegalan datum");
        Datum::dan=dan;
        Datum::mjesec=mjesec;
        Datum::godina=godina;
    }
    int Datum::DajDan()const{
        return dan;
    }
    Datum::Mjeseci Datum::DajMjesec()const{
        return Mjeseci(mjesec);
    }
    int Datum::DajGodinu()const{
        return godina;
    }
    const char *Datum::DajImeMjeseca()const{
        if(mjesec==1) return "Januar";
        else if(mjesec==2) return "Februar";
        else if(mjesec==3) return "Mart";
        else if(mjesec==4) return "April";
        else if(mjesec==5) return "Maj";
        else if(mjesec==6) return "Juni";
        else if(mjesec==7) return "Juli";
        else if(mjesec==8) return "August";
        else if(mjesec==9) return "Septembar";
        else if(mjesec==10) return "Oktobar";
        else if(mjesec==11) return "Novembar";
        else if(mjesec==12) return "Decembar";
        return "";
    }
    Datum::Dani Datum::DanUSedmici()const{
        int x=(14-mjesec)/12;
        int g=godina-x;
        int m=mjesec-2+12*x;
        int T=dan+31*m/12+g+g/4-g/100+g/400;
        int temp=T%7;
        return Dani(temp);
    }
    const char *Datum::DajImeDanaUSedmici()const{
        int x=(14-mjesec)/12;
        int g=godina-x;
        int m=mjesec-2+12*x;
        int T=dan+31*m/12+g+g/4-g/100+g/400;
        int temp=T%7;
        if(temp==1) return "Ponedjeljak";
        else if(temp==2) return "Utorak";
        else if(temp==3) return "Srijeda";
        else if(temp==4) return "Cetvrtak";
        else if(temp==5) return "Petak";
        else if(temp==6) return "Subota";
        else if(temp==0) return "Nedjelja";
        return "";
    }
    Datum &operator ++(Datum &datum){
        int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
        if((datum.godina%4 == 0 && datum.godina%100 != 0) || datum.godina%400 == 0) broj_dana[1]++;
        datum.dan++;
        if(datum.dan==broj_dana[datum.mjesec-1]+1){
            datum.dan=1;
            datum.mjesec++;
        }
        if(datum.mjesec==13){
            datum.mjesec=1;
            datum.godina++;
        }
        return datum;
    }
    Datum &operator --(Datum &datum){
        int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
        if((datum.godina%4 == 0 && datum.godina%100 != 0) || datum.godina%400 == 0) broj_dana[1]++;
        datum.dan--;
        if(datum.dan==0 && datum.mjesec==1) datum.godina--, datum.mjesec=12, datum.dan=broj_dana[datum.mjesec-1];
        if(datum.dan==0 && datum.mjesec!=1) datum.mjesec=12, datum.dan=broj_dana[datum.mjesec-1];
        if(datum.godina < 1800) throw std::domain_error("Nelegalan datum");
        return datum;
    }
    Datum operator ++(Datum &datum,int){
        Datum pomocni(datum);
        ++datum;
        return pomocni;
    }
    Datum operator --(Datum &datum, int){
        Datum pomocni(datum);
        --datum;
        return pomocni;
    }
    Datum operator +(const Datum &datum, int broj){
        Datum dat(datum);
        for(int i=0; i<broj; i++) ++dat.dan;
        return dat;
    }
    Datum operator -(const Datum &datum, int broj){
        Datum dat(datum);
        for(int i=0; i<broj; i++) --dat.dan;
        return dat;
    }
    Datum operator +=(Datum &datum, int broj){
        return datum=datum+broj;
    }
    Datum operator -=(Datum &datum, int broj){
        return datum=datum-broj;
    }
    int operator -(const Datum &datum1, const Datum &datum2){
        int broj_proteklih_dana1(0), broj_proteklih_dana2(0);
        int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
        for(int i=1800; i<datum1.DajGodinu(); i++){
            broj_proteklih_dana1+=365;
            if((i%4 == 0 && i%100 != 0) || i%400 == 0) broj_proteklih_dana1++;
        }
        for(int i=1800; i<datum2.DajGodinu(); i++){
            broj_proteklih_dana2+=365;
            if((i%4 == 0 && i%100 != 0) || i%400 == 0) broj_proteklih_dana2++;
        }
        for(int i=1; i<datum1.DajMjesec(); i++){
            broj_proteklih_dana1+=broj_dana[i-1];
            if((datum1.DajGodinu()%4 == 0 && datum1.DajGodinu()%100 != 0) || datum1.DajGodinu()%400 == 0) broj_proteklih_dana1++;
        }
        for(int i=1; i<datum2.DajMjesec(); i++){
            broj_proteklih_dana2+=broj_dana[i-1];
            if((datum2.DajGodinu()%4 == 0 && datum2.DajGodinu()%100 != 0) || datum2.DajGodinu()%400 == 0) broj_proteklih_dana2++;
        }
        for(int i=1; i<datum1.DajDan(); i++){
            broj_proteklih_dana1++;
        }
        for(int i=1; i<datum2.DajDan(); i++){
            broj_proteklih_dana2++;
        }
        return std::abs(broj_proteklih_dana2-broj_proteklih_dana1); //Ispraviti
    }
    bool operator ==(const Datum &datum1, const Datum &datum2){
        return (datum1.dan==datum2.dan && datum1.mjesec==datum2.mjesec && datum1.godina==datum2.godina);
    }
    bool operator !=(const Datum &datum1, const Datum &datum2){
        return !(datum1.dan==datum2.dan && datum1.mjesec==datum2.mjesec && datum1.godina==datum2.godina);
    }
    bool operator >(const Datum &datum1, const Datum &datum2){
        if(datum1.godina > datum2.godina) return true;
        if(datum1.godina < datum2.godina) return false;
        if(datum1.godina == datum2.godina){
            if(datum1.mjesec > datum2.mjesec) return true;
            if(datum1.mjesec < datum2.mjesec) return false;
            if(datum1.mjesec == datum2.mjesec){
                if(datum1.dan > datum2.dan) return true;
                if(datum1.dan <= datum2.dan) return false;
            }
        }
        return false;
    }
    bool operator <(const Datum &datum1, const Datum &datum2){
        if(datum1.godina < datum2.godina) return true;
        if(datum1.godina > datum2.godina) return false;
        if(datum1.godina == datum2.godina){
            if(datum1.mjesec < datum2.mjesec) return true;
            if(datum1.mjesec > datum2.mjesec) return false;
            if(datum1.mjesec == datum2.mjesec){
                if(datum1.dan < datum2.dan) return true;
                if(datum1.dan >= datum2.dan) return false;
            }
        }
        return false;
    }
    bool operator >=(const Datum &datum1, const Datum &datum2){
        if(datum1.godina >= datum2.godina) return true;
        if(datum1.godina < datum2.godina){
            if(datum1.mjesec >= datum2.mjesec) return true;
            if(datum1.mjesec < datum2.mjesec){
                if(datum1.dan >= datum2.dan) return true;
                if(datum1.dan < datum2.dan) return false;
            }
        }
        return false;
    }
    bool operator <=(const Datum &datum1, const Datum &datum2){
        if(datum1.godina <= datum2.godina) return true;
        if(datum1.godina > datum2.godina){
            if(datum1.mjesec <= datum2.mjesec) return true;
            if(datum1.mjesec > datum2.mjesec){
                if(datum1.dan <= datum2.dan) return true;
                if(datum1.dan > datum2.dan) return false;
            }
        }
        return false;
    }
    std::ostream &operator <<(std::ostream &tok, const Datum &datum){
        tok<<datum.DajDan()<<". "<<datum.DajImeMjeseca()<<" "<<datum.DajGodinu()<<". ("<<datum.DajImeDanaUSedmici()<<")";
        return tok;
    }
    std::istream &operator >>(std::istream &tok, Datum &datum){
        char znak1, znak2;
        tok>>datum.dan>>znak1>>datum.mjesec>>znak2>>datum.godina;
        int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
        if((datum.godina%4 == 0 && datum.godina%100 != 0) || datum.godina%400 == 0) broj_dana[1]++;
        if(znak1!='/' || znak2!='/' || datum.godina < 1800 || datum.mjesec < 1 || datum.mjesec > 12 || datum.dan < 1 || datum.dan > broj_dana[datum.mjesec-1]) tok.setstate(std::ios::failbit);
        return tok;
    }
    Datum::operator std::string(){
        std::string s;
        s=std::to_string(DajDan());
        s+=" ";
        s+=DajImeMjeseca();
        s+=" ";
        s+=std::to_string(DajGodinu());
        s+=". (";
        s+=DajImeDanaUSedmici();
        s+=")";
        return s;
    }
    Datum::operator int(){
        int broj_proteklih_dana(0);
        int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
        for(int i=1800; i<DajGodinu(); i++){
            broj_proteklih_dana+=365;
            if((i%4 == 0 && i%100 != 0) || i%400 == 0) broj_proteklih_dana++;
        }
        for(int i=1; i<DajMjesec(); i++){
            broj_proteklih_dana+=broj_dana[i-1];
            if((DajGodinu()%4 == 0 && DajGodinu()%100 != 0) || DajGodinu()%400 == 0) broj_proteklih_dana++;
        }
        for(int i=1; i<DajDan(); i++){
            broj_proteklih_dana++;
        }
        return broj_proteklih_dana;
    }
    int BrojProteklihDana(Datum &datum){
        int broj_proteklih_dana(0);
        int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
        for(int i=1800; i<datum.DajGodinu(); i++){
            broj_proteklih_dana+=365;
            if((i%4 == 0 && i%100 != 0) || i%400 == 0) broj_proteklih_dana++;
        }
        for(int i=1; i<datum.DajMjesec(); i++){
            broj_proteklih_dana+=broj_dana[i-1];
            if((datum.DajGodinu()%4 == 0 && datum.DajGodinu()%100 != 0) || datum.DajGodinu()%400 == 0) broj_proteklih_dana++;
        }
        for(int i=1; i<datum.DajDan(); i++){
            broj_proteklih_dana++;
        }
        return broj_proteklih_dana;
    }
int main ()
{
    Datum dat1(10,2,1800);
    Datum dat2(17,6,2018);
    //std::cout<<(dat1-dat2);
    //dat1++;
    //std::string s=dat2;
    //s*dat2;
    std::cout<<dat1-dat2;
	return 0;
}
