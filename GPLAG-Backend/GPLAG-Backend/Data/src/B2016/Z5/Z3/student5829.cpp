/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <functional>
#include <climits>
using namespace std;


class Razlomak{
  
  long long int brojnik, nazivnik;
public:

    Razlomak(long long int br=0, long long int naz=1):
    brojnik(br),nazivnik(naz)
    {
        if(naz==0)throw logic_error("Nekorektan razlomak");
        int djelilac; 
       // cout<<br<<" "<<naz<<endl;
        djelilac=nzd(br,naz);
        brojnik=br/djelilac;
        nazivnik=naz/djelilac;
        if(brojnik>0 && nazivnik<0){brojnik=brojnik*(-1); nazivnik=nazivnik*(-1);}
        
    }
    long long int DajBrojnik() const{return brojnik;}
    long long int DajNazivnik() const{return nazivnik;}
 

static  int nzd(long long int  brojnik, long long int nazivnik)
 {   
     
     if(nazivnik==0){return brojnik;}
        else
            return nzd(nazivnik,brojnik%nazivnik);
 }
 
 friend ostream &operator<<(ostream &cout, const Razlomak &v);
 friend istream &operator>>(istream &cin, Razlomak &v);
 friend Razlomak operator+(const Razlomak &a, const Razlomak &b);
 friend Razlomak operator-(const Razlomak &a, const Razlomak &b);
 friend Razlomak operator* (const Razlomak &v1,const Razlomak &v2);
 friend Razlomak operator /(const Razlomak &v1,const Razlomak &v2);
 Razlomak &operator +=(const Razlomak &v);
 Razlomak &operator -=(const Razlomak &v);
 Razlomak &operator *=(const Razlomak &v);
 Razlomak &operator /=(const Razlomak &v);
 Razlomak operator-() const {return {-brojnik,-nazivnik};} 
 Razlomak operator+(Razlomak &v);
 friend Razlomak &operator++ (Razlomak &v);
 friend Razlomak operator ++(Razlomak &v,int);
 friend Razlomak &operator-- (Razlomak &v);
 friend Razlomak operator --(Razlomak &v,int);
 friend bool operator ==(const Razlomak &v1, const Razlomak &v2);
 friend bool operator <=(const Razlomak &v1, const Razlomak &v2);
 friend bool operator >=(const Razlomak &v1, const Razlomak &v2);
 friend bool operator <(const Razlomak &v1, const Razlomak &v2);
 friend bool operator >(const Razlomak &v1, const Razlomak &v2);
 
 operator long double() const;
 
 static void overflow1(long long int x, long long int y)
 {
  long long int M(9223372036854775807), m(-9223372036854775807);
  if(y>0 && x>M-y)throw overflow_error("Nemoguce dobiti tacan rezultat");
  if(y<0 && x<m-y)throw overflow_error("Nemoguce dobiti tacan rezultat");
 }
 static void overflow2(long long int x, long long int  y)
 {
  long long int M(9223372036854775807), m(-9223372036854775807);
  if(y>0 && x<m+y)throw overflow_error("Nemoguce dobiti tacan rezultat");
  if(y<0 && x>M+y)throw overflow_error("Nemoguce dobiti tacan rezultat");
 }
 static void overflow3(long long int x, long long int y)
 {
  long long int M(9223372036854775807), m;
  m=-M-1;
  if(y>0 && (x<m/y || x>M/y))throw overflow_error("Nemoguce dobiti tacan rezultat");
  if(y<0 && (x==m ||-x>M/(-y) || -x<m/(-y)))throw overflow_error("Nemoguce dobiti tacan rezultat");
 }
};
 Razlomak &operator++ (Razlomak &v){v.brojnik++; v.nazivnik++; return v;}
 Razlomak operator ++(Razlomak &v,int){ Razlomak pomocni(v); v.brojnik++; v.nazivnik++; return pomocni;}
 Razlomak &operator-- (Razlomak &v){ v.brojnik--; v.nazivnik--; return v;}
 Razlomak operator --(Razlomak &v,int){ Razlomak pomocni(v); v.brojnik--; v.nazivnik--; return pomocni;}
 
 Razlomak Razlomak:: operator+(Razlomak &v)
 {
  Razlomak::overflow1(brojnik*v.nazivnik/(Razlomak::nzd(v.brojnik,v.nazivnik))+(v.brojnik*nazivnik/(Razlomak::nzd(v.brojnik,v.nazivnik))),nazivnik*(v.nazivnik/Razlomak::nzd(v.brojnik,v.nazivnik)));
  return {brojnik*v.nazivnik/(Razlomak::nzd(v.brojnik,v.nazivnik))+(v.brojnik*nazivnik/(Razlomak::nzd(v.brojnik,v.nazivnik))),nazivnik*(v.nazivnik/Razlomak::nzd(v.brojnik,v.nazivnik))};
 }
 bool operator ==(const Razlomak &v1, const Razlomak &v2)
 {
   return v1.brojnik==v2.brojnik && v1.nazivnik==v2.nazivnik;
 }
 bool operator <=(const Razlomak &v1, const Razlomak &v2)
 {
  long double a,b;
  a=v1.brojnik; b=v2.brojnik;
  a=a/v1.nazivnik; b=b/v2.nazivnik;
   return a<=b;
 }
 bool operator >=(const Razlomak &v1, const Razlomak &v2)
 {
  long double a,b;
  a=v1.brojnik; b=v2.brojnik;
  a=a/v1.nazivnik; b=b/v2.nazivnik;
   return a>=b;
 }
 bool operator <(const Razlomak &v1, const Razlomak &v2)
 {
  long double a,b;
  a=v1.brojnik; b=v2.brojnik;
  a=a/v1.nazivnik; b=b/v2.nazivnik;
   return a<b;
 }
 bool operator >(const Razlomak &v1, const Razlomak &v2)
 {
  long double a,b;
  a=v1.brojnik; b=v2.brojnik;
  a=a/v1.nazivnik; b=b/v2.nazivnik;
   return a>b;
 }
 
 
 Razlomak &Razlomak::operator +=(const Razlomak &v)
 {
   overflow1(brojnik*v.nazivnik/(Razlomak::nzd(v.brojnik,v.nazivnik)),(v.brojnik*nazivnik/(Razlomak::nzd(v.brojnik,v.nazivnik))));
     brojnik=brojnik*v.nazivnik/(Razlomak::nzd(v.brojnik,v.nazivnik))+(v.brojnik*nazivnik/(Razlomak::nzd(v.brojnik,v.nazivnik)));
     nazivnik=nazivnik*(v.nazivnik/Razlomak::nzd(v.brojnik,v.nazivnik));
     return *this;
 }
 
 Razlomak &Razlomak::operator -=(const Razlomak &v)
 {
   overflow2(brojnik*v.nazivnik/(Razlomak::nzd(v.brojnik,v.nazivnik)),(v.brojnik*nazivnik/(Razlomak::nzd(v.brojnik,v.nazivnik))));
     brojnik=brojnik*v.nazivnik/(Razlomak::nzd(v.brojnik,v.nazivnik))-(v.brojnik*nazivnik/(Razlomak::nzd(v.brojnik,v.nazivnik)));
     nazivnik=nazivnik*(v.nazivnik/Razlomak::nzd(v.brojnik,v.nazivnik));
     return *this;
 }
 Razlomak &Razlomak::operator *=(const Razlomak &v)
 {
 Razlomak::overflow3(brojnik/Razlomak::nzd(brojnik,v.nazivnik),(v.brojnik/Razlomak::nzd(v.brojnik,nazivnik)));
    brojnik=(brojnik/Razlomak::nzd(brojnik,v.nazivnik)*(v.brojnik/Razlomak::nzd(v.brojnik,nazivnik)));
    nazivnik=((nazivnik/Razlomak::nzd(v.brojnik,nazivnik)*(v.nazivnik/Razlomak::nzd(brojnik,v.nazivnik))));
    return *this;
 }
 
 Razlomak &Razlomak::operator /=(const Razlomak &v)
 {
    brojnik=(brojnik/Razlomak::nzd(brojnik,v.brojnik)*(v.nazivnik/(Razlomak::nzd(nazivnik,v.nazivnik))));
    nazivnik=((nazivnik/Razlomak::nzd(nazivnik,v.nazivnik)*(v.brojnik/Razlomak::nzd(brojnik,v.brojnik))));
    return *this;
 }
Razlomak  operator+(const Razlomak &a,const Razlomak &b)
 {
     long long int br,raz;
    Razlomak::overflow1(a.brojnik*b.nazivnik/(Razlomak::nzd(b.brojnik,b.nazivnik)),(b.brojnik*a.nazivnik/(Razlomak::nzd(b.brojnik,b.nazivnik))));
     br=(a.brojnik*b.nazivnik/(Razlomak::nzd(b.brojnik,b.nazivnik))+(b.brojnik*a.nazivnik/(Razlomak::nzd(b.brojnik,b.nazivnik))));
     raz=(a.nazivnik*(b.nazivnik/Razlomak::nzd(b.brojnik,b.nazivnik)));
     Razlomak c(br,raz);
     return c;
 }
 
 Razlomak  operator-(const Razlomak &a,const Razlomak &b)
 {
  Razlomak::overflow2(a.brojnik*b.nazivnik/(Razlomak::nzd(b.brojnik,b.nazivnik)),(b.brojnik*a.nazivnik/(Razlomak::nzd(b.brojnik,b.nazivnik))));
     long long int br,raz;
     br=(a.brojnik*b.nazivnik/(Razlomak::nzd(b.brojnik,b.nazivnik))-(b.brojnik*a.nazivnik/(Razlomak::nzd(b.brojnik,b.nazivnik))));
     raz=(a.nazivnik*(b.nazivnik/Razlomak::nzd(b.brojnik,b.nazivnik)));
     Razlomak c(br,raz);
     return c;
 }
 Razlomak operator*(const Razlomak &v1, const Razlomak &v2) 
{
    Razlomak::overflow3(v1.brojnik/Razlomak::nzd(v1.brojnik,v2.nazivnik),(v2.brojnik/Razlomak::nzd(v2.brojnik,v1.nazivnik)));
    int br, naz;
    br=(v1.brojnik/Razlomak::nzd(v1.brojnik,v2.nazivnik)*(v2.brojnik/Razlomak::nzd(v2.brojnik,v1.nazivnik)));
    naz=((v1.nazivnik/Razlomak::nzd(v2.brojnik,v1.nazivnik)*(v2.nazivnik/Razlomak::nzd(v1.brojnik,v2.nazivnik))));
    Razlomak v(br,naz);
    
    return v;
}

Razlomak operator /(const Razlomak &v1,const Razlomak &v2)
{
    int br, naz;
    
    br=(v1.brojnik/Razlomak::nzd(v1.brojnik,v2.brojnik)*(v2.nazivnik/(Razlomak::nzd(v1.nazivnik,v2.nazivnik))));
    naz=((v1.nazivnik/Razlomak::nzd(v1.nazivnik,v2.nazivnik)*(v2.brojnik/Razlomak::nzd(v1.brojnik,v2.brojnik))));
    Razlomak v(br,naz);
   // cout<<v.brojnik<<" "<<v.nazivnik<<endl;
    return v;
}
 ostream &operator<<(ostream &cout, const Razlomak &v)
 {
     if(v.nazivnik==1)cout<<v.brojnik;
     else 
     cout<<v.brojnik<<"/"<<v.nazivnik;
     return cout;
 }

istream &operator>>(istream &cin, Razlomak &v)
 {
     
     v.nazivnik=1;
     char znak;
     cin>>ws;
     if(cin.peek()!='\n' || cin.peek()!='\r' || cin.peek()!='\f' || cin.peek()!= '\v' ||  cin.peek()!='\t' || cin.peek()!=' ') 
     { cin>>ws;
        cin>>v.brojnik;
        
        if(cin.peek()=='/')
        {
            
        cin>>znak>>v.nazivnik;
        
        if(cin.peek()!='\n' && cin.peek()!='\r' && cin.peek()!='\f' && cin.peek()!= '\v' &&  cin.peek()!='\t' && cin.peek()!=' ')
         cin.setstate(ios::failbit);
            
        }
        
     }
     else
     {
         cin.setstate(ios::failbit);
         
     }
     
     int a;
     
     a=Razlomak::nzd(v.brojnik,v.nazivnik);
     v.brojnik=v.brojnik/a;
     v.nazivnik=v.nazivnik/a;
     return cin;
 }
 Razlomak:: operator long double() const
 {
     long double a;
     a=brojnik;
     a=a/nazivnik;
     return a;
 }

 //da se malo igramo, da razlomke zadajemo u formatu: a / b.
//da bude moguce 'Razlomak r = a / b', gdje su 'a' i 'b' specijalni 'brojevi'
//mozemo nauciti 'user-defined' literale iako se na predavanjima ne rade
/*struct RazlomakBroj {
long long int x; 
RazlomakBroj (long long int x) : x(x) {}
    };
Razlomak operator / (const RazlomakBroj &b, const RazlomakBroj &n) { return {b.x, n.x};}
RazlomakBroj operator "" _r (unsigned long long int x) { return RazlomakBroj(x);}
*/
int main ()
{
   Razlomak r, q(10,7),c(98),t;
   cin>>r;
   try
   {
    cout<<r<<endl;
    c=r+q;
    cout<<c<<endl;
    r=c-q;
    q*=c;
    cout<< c<<" "<<q<<" "<<r<<endl;
    c+=2;
    t=r/c;
    t-=2;
    cout<<++r<<" "<< c++<<" "<<--t<<" "<< q--<<endl;
    cout<<static_cast <long double>(q)<<endl;
    cout<<r+t<<" "<< t-c<<endl;
   }
   catch(overflow_error e)
   {
    cout<<e.what()<<endl;
   }
        
    
	return 0;
}