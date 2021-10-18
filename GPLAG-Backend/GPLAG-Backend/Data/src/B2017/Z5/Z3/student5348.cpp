/B2017/2018: Zadaća 5, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <string.h>
using namespace std;

bool Provjera(int dan,int mjesec,int god){
      
      int dani[]{31,28,31,30,31,30,31,31,30,31,30,31};
      if(god%4==0){
          dani[1]++;
          if(god%100==0 )dani[1]--;
          
      }
      if(mjesec<=0 ||mjesec>12){cout<<dan<<" "<<mjesec<<" "<<god<<endl; throw domain_error("Nelegalan datum");}
      if(dan<=0 || dan>dani[mjesec-1]  || god<1800) throw domain_error("Nelegalan datum");
      return true;
  }
  
int Velicina(int mjesec,int god){
    int dani[]{31,28,31,30,31,30,31,31,30,31,30,31};
    
      if(god%4==0){
          dani[1]++;
          if(god%100==0)
          dani[1]--;
          
      }
      
      return dani[mjesec-1];
}

void Uvecaj(int &dan,int &mjesec,int &god){
    
    
    if(++dan>Velicina(mjesec,god)){
        dan=0;
        if(++mjesec>12){mjesec=0;god++;}
    }
    
}

int DajDane(int dan,int mjesec,int god){
    
    Provjera(dan,mjesec,god);
    
    int dani1=0;
    dani1=(god-1)*365+dan-1;
    
    for(int i=1;i<mjesec;i++)
        dani1+=Velicina(i,god);
    
   dani1+=(god-1)/4-(god-1)/100+(god-1)/400;
    
    return dani1;
}

int Umanji(int &dan,int &mjesec,int &god){
    
   
    if(--dan<=0){
        if(--mjesec<=0){mjesec=12;god--;}
        dan=Velicina(mjesec,god);
    }
    
}

class Datum{
  
  int dan,mjesec,god;
  
  char imena_dana[7][15]{"Ponedeljak","Utorak","Srijeda","Cetvrtak","Petak","Subota","Nedelja"};
  char imena_mjeseci[12][15]{"Januar","Februar","Mart","April","Maj","Juni","Juli","August","Septembar","Oktobar","Novembar","Decembar"};
  
  
  public:
  enum Mjeseci {Januar = 1, Februar, Mart, April, Maj, Juni, Juli, August, Septembar, Oktobar, Novembar, Decembar};
enum Dani {Ponedjeljak = 1, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja};

Datum(int dan,int mjesec,int god):dan(dan),mjesec(mjesec),god(god){
    
    Provjera(dan,mjesec,god);
}

Datum(Dani dan,Mjeseci mjesec,int god):dan(Dani(dan)),mjesec(Mjeseci(mjesec)),god(god){
    
    Provjera(Dani(dan),Mjeseci(mjesec),god);
    
}

Datum Postavi(int dan,int mjesec,int god){
    
    Provjera(dan,mjesec,god);
    
    this->dan=dan;
    this->mjesec=mjesec;
    this->god=god;
    return *this;
    
}

Datum Postavi(Dani dan,Mjeseci mjesec,int god){
    
    Provjera(Dani(dan),Mjeseci(mjesec),god);
    
    this->dan=Dani(dan);
    this->mjesec=Mjeseci(mjesec);
    this->god=god;
    return *this;
}

int DajDan()const{return dan;}

int DajGodinu()const{return god;}

Mjeseci DajMjesec()const{return Mjeseci(mjesec);}

char* DajImeMjeseca(){
    
  return imena_mjeseci[this->mjesec-1];
    
}

char *DajImeDanaUSedmici(){
    
    return imena_dana[(2+int(*this))%7];
}

Dani DanUSedmici()const{return Dani(dan);}

Datum &operator ++(){
    
    Uvecaj(dan,mjesec,god);
    return *this;
    
}

Datum &operator ++(int){
    Datum d(*this);
    ++(*this);
    return d;
    
}

Datum &operator --(){
    
    Umanji(dan,mjesec,god);
    return *this;
    
}

Datum &operator --(int){
    Datum d(*this);
    --(*this);
    return d;
    
}

Datum operator +(int i){
    Datum d(*this);
    int temp(i);
    if(i<0)temp*=-1;
    
    for(int j=0;j<temp;j++){
        
        if(i<0) Umanji(d.dan,d.mjesec,d.god);
        else Uvecaj(d.dan,d.mjesec,d.god);
        
    }
    return d;
    
}

Datum operator -(int i){
    Datum d(*this);
    int temp(i);
    if(i<0)temp*=-1;
    
    for(int j=0;j<temp;j++){
        
        if(i<0) Uvecaj(d.dan,d.mjesec,d.god);
        else Umanji(d.dan,d.mjesec,d.god);
        
    }
    return d;
    
}

Datum &operator +=(int i){
    *this=*this+i;
    return *this;
}

Datum &operator -=(int i){
    *this=*this-i;
    return *this;
}

int operator-(Datum &d1){
    
    int dani1=0,dani2=0;
    
   dani1=DajDane(this->dan,this->mjesec,this->god);
   
   dani2=DajDane(d1.dan,d1.mjesec,d1.god);
   
   return abs(dani1-dani2);
   
}

bool operator==(Datum &d1){
    return(this->dan==d1.dan && this->mjesec==d1.mjesec && this->god==d1.god);
    
}

bool operator !=(Datum &d1){
 return(this->dan!=d1.dan || this->mjesec!=d1.mjesec ||this->god!=d1.god);
    
}

bool operator <(Datum &d1){
    
    return(DajDane(this->dan,this->mjesec,this->god)<DajDane(d1.dan,d1.mjesec,d1.god));
    
}

bool operator <=(Datum &d1){
    
     return(DajDane(this->dan,this->mjesec,this->god)<=DajDane(d1.dan,d1.mjesec,d1.god));
    
}

bool operator >(Datum &d1){
    
     return(DajDane(this->dan,this->mjesec,this->god)>DajDane(d1.dan,d1.mjesec,d1.god));
    
}

bool operator >=(Datum &d1){
   
   return(DajDane(this->dan,this->mjesec,this->god)>=DajDane(d1.dan,d1.mjesec,d1.god));
    
}

friend ostream &operator<<(ostream &tok,Datum &d1){
    
    tok<<d1.DajDan()<<". "<<d1.DajImeMjeseca()<<" "<<d1.DajGodinu()<<". ("<<d1.DajImeDanaUSedmici()<<")"<<endl;
    return tok;
    
}

friend istream &operator>>(istream &tok,Datum &d1){
    
    int d,g,m;
    char c1,c2;
    tok>>d>>c1>>m>>c2>>g;
        
        if(!tok || Provjera(d,m,g)==false || c1!='/' || c2!='/'){
            tok.clear();
            tok.ignore(10000,'\n');
            tok.setstate(ios_base::failbit);
        }
    return tok;
    
    
}

operator string(){
    
    
    return to_string(this->DajDan())+". "+this->DajImeMjeseca()+" "+to_string(this->DajGodinu())+". ("+this->DajImeDanaUSedmici()+")";
  
    
}

explicit operator int(){
    
    
    return DajDane(this->dan,this->mjesec,this->god)-DajDane(1,1,1800);
    
}


};

int main ()
{
    
  /*  Datum d1(15,2,2018);
    
    string s=d1;
    cout<<s;*/
    Datum d1(1,1,1800);
    d1+=20;
    d1+=-20;
    string s=d1;
    s+="hi";
    cout<<s<<endl;
   // cout<<DajDane(25,5,1766);
    //cout<<int(d1)<<endl;
    cout<<d1<<" "<<d1.DajImeDanaUSedmici();




return 0;
}
