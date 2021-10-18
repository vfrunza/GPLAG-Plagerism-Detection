#include <iostream>
#include<stdexcept>
#include <cmath>

int BrojDana(int mjesec, int godina) {
int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
if(godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0)
broj_dana[1]++;
return broj_dana[mjesec - 1];
}
int razmak(int dan,int mjesec,int godina){
   int first_date_month=1;
int first_date_days=1;
int first_date_year=1800;
int second_date_month=mjesec;
int second_date_days=dan;
int second_date_year=godina;
int days=0;

int month_days[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if(first_date_year == second_date_year)
    {
        if(first_date_month == second_date_month)
            days = second_date_days - first_date_days;
        else
        {
            for(int i = first_date_month; i < second_date_month-1;i++)
                days += month_days[i];
            days += month_days[first_date_month-1] - first_date_days + second_date_days;
        }
    }
    else
    {
        for(int i = 0; i < second_date_month-1; i++)
            days += month_days[i];
        for(int i = first_date_month; i < 12; i++)
            days += month_days[i];
        if(second_date_year - first_date_year >= 0)
        days += (second_date_year - first_date_year - 1)*365 + 
            month_days[first_date_month-1] - first_date_days + second_date_days;
    }

  return days;

}
int razmak1(int dan1,int mjesec1,int godina1,int dan2,int mjesec2,int godina2){
   int first_date_month=mjesec1;
int first_date_days=dan1;
int first_date_year=godina1;
int second_date_month=mjesec2;
int second_date_days=dan2;
int second_date_year=godina2;
int days=0;

int month_days[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if(first_date_year == second_date_year)
    {
        if(first_date_month == second_date_month)
            days = second_date_days - first_date_days;
        else
        {
            for(int i = first_date_month; i < second_date_month-1;i++)
                days += month_days[i];
            days += month_days[first_date_month-1] - first_date_days + second_date_days;
        }
    }
    else
    {
        for(int i = 0; i < second_date_month-1; i++)
            days += month_days[i];
        for(int i = first_date_month; i < 12; i++)
            days += month_days[i];
        if(second_date_year - first_date_year >= 0)
        days += (second_date_year - first_date_year - 1)*365 + 
            month_days[first_date_month-1] - first_date_days + second_date_days;
    }

  return days;

}
enum Mjeseci {Januar = 1, Februar, Mart, April, Maj, Juni, Juli, August,Septembar, Oktobar, Novembar, Decembar};
    enum Dani {Ponedjeljak = 1, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja};
char m[][15]={"Januar","Februar","Mart","April","Maj","Juni","Juli","August","Septembar","Oktobar","Novembar","Decembar"};

class Datum{
    int day,month,year;
    public:
    
    Datum(){}
    Datum (int dan,Mjeseci mjesec,int godina){ if(godina < 1800 || dan < 1 || mjesec < 1 || mjesec > 12|| dan > BrojDana(mjesec, godina)) throw std::domain_error("Neispravan datum!"); day=dan;month=mjesec;year=godina;
    }
    Datum(int dan,int mjesec,int godina){  if(godina < 1800 || dan < 1 || mjesec < 1 || mjesec > 12|| dan > BrojDana(mjesec, godina)) throw std::domain_error("Neispravan datum!"); day=dan;month=mjesec;year=godina;
    }
    void Postavi(int dan,Mjeseci mjesec,int godina){ if(godina < 1800 || dan < 1 || mjesec < 1 || mjesec > 12|| dan > BrojDana(mjesec, godina))throw std::domain_error("Neispravan datum!");   day=dan;month=mjesec;year=godina;
    }
    void Postavi(int dan,int mjesec,int godina){
    if(godina < 1800 || dan < 1 || mjesec < 1 || mjesec > 12|| dan > BrojDana(mjesec, godina))  throw std::domain_error("Neispravan datum!"); day=dan;month=mjesec;year=godina;
    }
    int DajDan()const{return day;}
    Mjeseci DajMjesec()const;
    int DajGodinu()const{return year;}
    char *DajImeMjeseca()const{
        return m[month-1];
    }
    Datum &operator ++(int);
    Datum &operator ++();
     Datum &operator --(int);
    Datum &operator --();
    Datum &operator -(int);
    Datum &operator +(int);
     Datum &operator -=(int);
    Datum &operator +=(int);
    int  operator -(Datum d);
    bool operator <(Datum);
    bool operator >(Datum);
    bool operator <=(Datum);
    bool operator >=(Datum);
    bool operator !=(Datum);
    bool operator ==(Datum);
   void operator =(std::string&s);
    operator int(){
       return razmak(day,month,year);
   }
  
    friend std::ostream &operator <<(std::ostream &tok,const Datum &d);
     friend std::istream &operator >>(std::istream &tok, Datum &d);
    Dani DanUSedmici()const;
};
Mjeseci Datum::DajMjesec()const{
      if(month==1)return Januar;
        if(month==2)return Februar;
        if(month==3)return Mart;
        if(month==4)return April;
        if(month==5)return Maj;
        if(month==6)return Juni;
        if(month==7)return Juli;
        if(month==8)return August;
        if(month==9)return Septembar;
        if(month==10)return Oktobar;
        if(month==11)return Novembar;
        if(month==12)return Decembar;
}
Dani Datum::DanUSedmici()const{
    int dan;
    dan=razmak(day,month,year)%7;
    if(dan==1)return Ponedjeljak;
     if(dan==2)return Utorak;
      if(dan==3)return Srijeda;
       if(dan==4)return Cetvrtak;
        if(dan==5)return Petak;
         if(dan==6)return Subota;
          if(dan==0)return Nedjelja;
    
}
Datum &Datum::operator ++(int){
    if(day+1>BrojDana(month,year)){
        day=1;
        month++;
    if(month>12){month=1;year++;}
    }day++;
    return *this;
}
Datum &Datum::operator ++(){
    if(day+1>BrojDana(month,year)){
        day=1;
        month++;
    if(month>12){month=1;year++;}
    }day++;
    return *this;
}
Datum &Datum::operator --(int){
    if(day==1&&month==1&&year==1800)throw std::domain_error {"Nelegalan datum"};
     if(day-1<1){
        if(month!=1)day=BrojDana(month--,year);
        else {
            month=12;
            year--;
            day=31;
        }
    if(month>12){month=1;year++;}
    }day--;
    return *this;
}
Datum &Datum::operator --(){
    if(day==1&&month==1&&year==1800)throw std::domain_error {"Nelegalan datum"};
    if(day-1<1){
        if(month!=1)day=BrojDana(month--,year);
        else {
            month=12;
            year--;
            day=31;
        }
    if(month>12){month=1;year++;}
    }day--;
    return *this;
}
Datum &Datum::operator +(int a){
    if(a<0&&razmak(day,month,year)<fabs(a))throw std::domain_error {"Nelegalan datum"};
    for(int i=0;i<a;i++){
        (*this)++;
    }
    return *this;
}
Datum &Datum::operator -(int a){
    if(a>0&&razmak(day,month,year)<fabs(a))throw std::domain_error {"Nelegalan datum"};
    for(int i=0;i<a;i++){
        (*this)--;
    }
    return *this;
}
Datum &Datum::operator +=(int a){
    if(a<0&&razmak(day,month,year)<fabs(a))throw std::domain_error {"Nelegalan datum"};
    for(int i=0;i<a;i++){
        (*this)++;
    }
    return *this;
}
Datum &Datum::operator -=(int a){
    if(a>0&&razmak(day,month,year)<fabs(a))throw std::domain_error {"Nelegalan datum"};
    for(int i=0;i<a;i++){
        (*this)--;
    }
    return *this;
}
int  Datum::operator -(Datum d){
   return fabs(razmak1(day,month,year,d.day,d.month,d.year));
}
bool Datum::operator <(Datum d){
    if(year<d.year)return true;if(year>d.year)return false;
    if(month<d.month)return true;if(month>d.month)return false;
    if(day<d.day)return true;if(day>d.day)return false;
    return false;
}
bool Datum::operator >(Datum d){
    if(year<d.year)return false;if(year>d.year)return true;
    if(month<d.month)return false;if(month>d.month)return true;
    if(day<d.day)return false;if(day>d.day)return true;
    return false;
}
bool Datum::operator <=(Datum d){
    if(year<d.year)return true;if(year>d.year)return false;
    if(month<d.month)return true;if(month>d.month)return false;
    if(day<d.day)return true;if(day>d.day)return false;
    return true;
}
bool Datum::operator >=(Datum d){
    if(year<d.year)return false;if(year>d.year)return true;
    if(month<d.month)return false;if(month>d.month)return true;
    if(day<d.day)return false;if(day>d.day)return true;
    return true;
}
bool Datum::operator ==(Datum d){
   if(day==d.day&&month==d.month&&year==d.year)return true;
   return false;
}
bool Datum::operator !=(Datum d){
   if(day!=d.day||month!=d.month||year!=d.year)return true;
   return false;
}

std::ostream &operator <<(std::ostream &tok,const Datum &d){
    tok<<d.DajDan()<<"."<<d.DajImeMjeseca()<<" "<<d.DajGodinu()<<".(";
    int dan;
  dan=razmak(d.day,d.month,d.year)%7;
    if(dan==1)std::cout<< "Ponedjeljak)";
     if(dan==2)std::cout<< "Utorak)";
     if(dan==3)std::cout<< "Srijeda)";
     if(dan==4)std::cout<< "Cetvrtak)";
     if(dan==5)std::cout<< "Petak)";
     if(dan==6)std::cout<< "Subota)";
     if(dan==0)std::cout<< "Nedjelja)";
     std::cout  << std::endl;
     
    return tok;
}
std::istream &operator >>(std::istream &tok, Datum &da){
   int d,m,y;
   char c;
   std::cin>>d;
   std::cin>>c;
   std::cin>>m;
   std::cin>>c;
   std::cin>>y;
   Datum s(d,m,y);
   da=s;
    return tok;
}
void Datum::operator =(std::string &s){
    s.resize(0);
    s+=std::to_string(this->DajDan());
    if(this->DajMjesec()==1)s+=std::string(".Januar ");
    if(this->DajMjesec()==2)s+=std::string(".Februar ");
    if(this->DajMjesec()==3)s+=std::string(".Mart ");
    if(this->DajMjesec()==4)s+=std::string(".April ");
    if(this->DajMjesec()==5)s+=std::string(".Maj ");
    if(this->DajMjesec()==6)s+=std::string(".Juni ");
    if(this->DajMjesec()==7)s+=std::string(".Juli ");
    if(this->DajMjesec()==8)s+=std::string(".August ");
    if(this->DajMjesec()==9)s+=std::string(".Septembar ");
    if(this->DajMjesec()==10)s+=std::string(".Oktobar ");
    if(this->DajMjesec()==11)s+=std::string(".Novembar ");
    if(this->DajMjesec()==12)s+=std::string(".Decembar ");
    s+=std::to_string(this->DajGodinu());
     int dan;
  dan=razmak(this->day,this->month,this->year)%7;
    if(dan==1)".(Ponedjeljak)";
     if(dan==2)s+=  ".(Utorak)";
     if(dan==3)s+=  ".(Srijeda)";
     if(dan==4)s+=  ".(Cetvrtak)";
     if(dan==5)s+=  ".(Petak)";
     if(dan==6)s+=  ".(Subota)";
     if(dan==0)s+=  ".(Nedjelja)";
}

int main ()
{Datum d;
try{
std::cout << "Unesite prvi datum " << std::endl;
std::cin >> d;
std::cout << "Vas datum je udaljen "<<int(d)<<" dana od referentnog datuma 1/1/1800 i ovo je uradjeno preko int() konverzije" << std::endl;
std::cout << "Prvi datum " << std::endl;
     std::cout << d;
     d++;
     std::cout << "datum ++" << std::endl;
     std::cout << d;
     d+=5;
     std::cout << "datum +5" << std::endl;
     std::cout << d << std::endl;
     
     d--;
     std::cout << "datum  --" << std::endl;
     std::cout << d;
     d-=5;
     std::cout << "datum -5 " << std::endl;
     std::cout << d;
     std::cout << "Unesite drugi datum " << std::endl;
     Datum d2;
     std::cin>>d2;
     std::cout << "Drugi datum " << std::endl;
     std::cout<<d2;
     std::string s;
     std::cout << "Ovo je zapravo string a ne datum na ekranu" << std::endl;
     d=s;
     std::cout << s << std::endl;
     std::cout << "Razlika prvog i drugog datuma" << std::endl;
    std::cout << d-d2 << std::endl;
}catch(std::domain_error er){
    std::cout << er.what() << std::endl;
}
	return 0;
}
