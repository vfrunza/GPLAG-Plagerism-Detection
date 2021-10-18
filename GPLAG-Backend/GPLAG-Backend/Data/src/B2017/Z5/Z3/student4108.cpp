/B2017/2018: Zadaća 5, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <cstring>



class Datum{
    int dan, mjesec, godina;
    
    public:
    enum Mjeseci {Januar = 1, Februar, Mart, April, Maj, Juni, Juli, August, Septembar, Oktobar, Novembar, Decembar};
    enum Dani {Ponedjeljak = 1, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja};
    
     Datum(int dan, int mjesec, int godina){
        if(godina<1800) throw std::domain_error("Nelegalan datum");
        int brDana[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if((godina % 4==0 && godina % 100!=0) || godina % 400==0) brDana[2]++;
        if(godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>brDana[mjesec])
        throw std::domain_error("Nelegalan datum");
        
        Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina;
    }
    
     Datum(int dan, Mjeseci mjesec, int godina){
        int mj=int(mjesec);
        if(godina<1800) throw std::domain_error("Nelegalan datum");
        int brDana[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if((godina % 4==0 && godina % 100!=0) || godina % 400==0) brDana[2]++;
        if(godina<1 || dan<1 || mj<1 || mj>12 || dan>brDana[mj])
        throw std::domain_error("Nelegalan datum");
        
        Datum::dan = dan; Datum::mjesec = mj; Datum::godina = godina;
    }
    void Postavi(int dan, int mjesec, int godina);
    void Postavi(int dan, Mjeseci mjesec, int godina);
    int DajDan() const;
    int DajGodinu() const;
    Mjeseci DajMjesec() const;
    char *DajImeMjeseca() const;
    Dani DanUSedmici() const;
    char *DajImeDanaUSedmici() const;
    friend Datum operator--(Datum &a, int);
    friend Datum operator--(Datum &a);
    friend Datum operator++(Datum &a, int);
    friend Datum operator++(Datum &a);
    friend bool operator ==(Datum &a, Datum &b);
    friend bool operator !=(Datum &a, Datum &b);
    friend bool operator <(Datum &a, Datum &b);
    friend bool operator >(Datum &a, Datum &b);
    friend bool operator >=(Datum &a, Datum &b);
    friend bool operator <=(Datum &a, Datum &b);
};

void Datum::Postavi(int dan, int mjesec, int godina){
    if(godina<1800) throw std::domain_error("Nelegalan datum");
    int brDana[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina % 4==0 && godina % 100!=0) || godina % 400==0) brDana[2]++;
    if(godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>brDana[mjesec])
    throw std::domain_error("Nelegalan datum");
    Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina;
}
void Datum::Postavi(int dan, Mjeseci mjesec, int godina){
    int mj=int(mjesec);
    if(godina<1800) throw std::domain_error("Nelegalan datum");
    int brDana[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina % 4==0 && godina % 100!=0) || godina % 400==0) brDana[2]++;
    if(godina<1 || dan<1 || mj<1 || mj>12 || dan>brDana[mj])
    throw std::domain_error("Nelegalan datum");
    Datum::dan = dan; Datum::mjesec = mj; Datum::godina = godina;
}

int Datum::DajDan() const{
    return dan; 
}
int Datum::DajGodinu() const{
    return godina;
}
Datum::Mjeseci Datum::DajMjesec() const{
    return Mjeseci(mjesec);
}
char *Datum::DajImeMjeseca() const{
    char *imena[12]{"Januar", "Februar", "Mart", "April", "Maj", "Juni", "Juli", "August", "Septembar", "Oktobar", "Novembar", "Decembar"};
    for(int i=0; i<12; i++)
        if(mjesec==i) return imena[i];
}

Datum::Dani Datum::DanUSedmici() const{
    int bdum[13]{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if( (godina%4==0 && godina%100!=0) || godina%400==0) bdum[2]++;
    int ukupno(0);
    for(int i=1800; i<godina; i++){
        ukupno+=365;
        if( (i%4==0 && i%100!=0) || i%400==0) ukupno++;
    }
    
    for(int i=1; i<mjesec; i++)
        ukupno+=bdum[i];
    ukupno+=dan;
    
    int kojiDan=ukupno%7;
    return Dani(kojiDan);
}

char *Datum::DajImeDanaUSedmici() const{
     int bdum[13]{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if( (godina%4==0 && godina%100!=0) || godina%400==0) bdum[2]++;
    int ukupno(0);
    for(int i=1800; i<godina; i++){
        ukupno+=365;
        if( (i%4==0 && i%100!=0) || i%400==0) ukupno++;
    }
    
    for(int i=1; i<mjesec; i++)
        ukupno+=bdum[i];
    ukupno+=dan;
    
    int kojiDan=ukupno%7;
    char *imena[7]{"Ponedjeljak", "Utorak", "Srijeda", "Cetvrtak", "Petak", "Subota", "Nedjelja"};
    return imena[kojiDan];
}

Datum operator--(Datum &a, int){
    if(a.dan==1 && a.mjesec==1 && a.godina==1800) throw std::domain_error("Nelegalan datum");
    Datum pomocni(a.dan, a.mjesec, a.godina);
    int brDana[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((a.godina%4==0 && a.godina%100!=0) || a.godina%400==0) brDana[2]++;
    a.dan--;
    if(a.dan==0 && a.mjesec!=1) {
        a.dan=brDana[a.mjesec-1];
        a.mjesec--;
    }
    else if(a.dan==0 && a.mjesec==1){
        a.dan=31;
        a.mjesec=12;
        a.godina--;
    }
    return pomocni;
}

Datum operator--(Datum &a){
    if(a.dan==1 && a.mjesec==1 && a.godina==1800) throw std::domain_error("Nelegalan datum");
    int brDana[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((a.godina%4==0 && a.godina%100!=0) || a.godina%400==0) brDana[2]++;
    a.dan--;
    if(a.dan==0 && a.mjesec!=1) {
        a.dan=brDana[a.mjesec-1];
        a.mjesec--;
    }
    else if(a.dan==0 && a.mjesec==1){
        a.dan=31;
        a.mjesec=12;
        a.godina--;
    }
    return a;
}

Datum operator++(Datum &a, int){
    Datum pomocni(a.dan, a.mjesec, a.godina);
    int brDana[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((a.godina%4==0 && a.godina%100!=0) || a.godina%400==0) brDana[2]++;
    a.dan++;
    if(a.dan>brDana[a.mjesec]){
        a.dan=1;
        a.mjesec++;
        if(a.mjesec==13){
            a.mjesec=1;
            a.godina++;
        }
    }
    return a;
}

bool operator ==(Datum &a, Datum &b){
    if(a.dan==b.dan && a.mjesec==b.mjesec && a.godina==b.godina) return true;
    return false;
}

bool operator !=(Datum &a, Datum &b){
    if(a.dan!=b.dan || a.mjesec!=b.mjesec || a.godina!=b.godina) return true;
    return false;
}

bool operator <(Datum &a, Datum &b){
    if(a.godina<b.godina) return true;
    else if(a.godina==b.godina && a.mjesec<b.mjesec) return true;
    else if(a.godina==b.godina && a.mjesec==b.mjesec && a.dan<b.dan) return true;
    return false;
}

bool operator >(Datum &a, Datum &b){
    if(a.godina>b.godina) return true;
    else if(a.godina==b.godina && a.mjesec>b.mjesec) return true;
    else if(a.godina==b.godina && a.mjesec==b.mjesec && a.dan>b.dan) return true;
    return false;
}

bool operator <=(Datum &a, Datum &b){
    if(a.dan==b.dan && a.mjesec==b.mjesec && a.godina==b.godina) return true;
    if(a.godina<b.godina) return true;
    else if(a.godina==b.godina && a.mjesec<b.mjesec) return true;
    else if(a.godina==b.godina && a.mjesec==b.mjesec && a.dan<b.dan) return true;
    return false;
}

bool operator >=(Datum &a, Datum &b){
    if(a.dan==b.dan && a.mjesec==b.mjesec && a.godina==b.godina) return true;
    if(a.godina>b.godina) return true;
    else if(a.godina==b.godina && a.mjesec>b.mjesec) return true;
    else if(a.godina==b.godina && a.mjesec==b.mjesec && a.dan>b.dan) return true;
    return false;
}




int main ()
{
    
    Datum armin(5, 1, 1999);
    
    std::cout<<armin.DajImeDanaUSedmici();
	return 0;
}
