/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <climits>
class Razlomak{
    long long int brojnik,nazivnik;
    static int NZD(long long int p,long long int q){
    while(q!=0){
        long long int c=q;
        q=p%q;
        p=c;
    }
    return p;
}
    public:
     Razlomak(long long int b,long long int n);
    Razlomak(long long int b){
        brojnik=b;
        nazivnik=1;
    }
    Razlomak(){
        brojnik=0;
        nazivnik=1;
    }
    long long int DajBrojnik()const{
        return brojnik;
    }
    long long int DajNazivnik()const{
        return nazivnik;
    }
    friend Razlomak operator +(const Razlomak &a,const Razlomak &b); 
    friend Razlomak operator -(const Razlomak &a,const Razlomak &b);
    friend Razlomak operator *(const Razlomak &a,const Razlomak &b);
    friend Razlomak operator /(const Razlomak &a,const Razlomak &b);
    friend Razlomak operator +(const Razlomak &a);
    friend Razlomak operator -(const Razlomak &a);
    Razlomak &operator +=(const Razlomak &a);
    Razlomak &operator -=(const Razlomak &a);
    Razlomak &operator *=(const Razlomak &a);
    Razlomak &operator /=(const Razlomak &a);
    Razlomak &operator ++();
    Razlomak &operator --();
    Razlomak operator ++(int);
    Razlomak operator --(int);
    operator long double(){
        long double r= (static_cast<long double>(brojnik))/nazivnik;
        return r;
    }
    friend bool operator <(const Razlomak &a,const Razlomak &b);
    friend bool operator >(const Razlomak &a,const Razlomak &b);
    friend bool operator <=(const Razlomak &a,const Razlomak &b);
    friend bool operator >=(const Razlomak &a,const Razlomak &b);
    friend bool operator ==(const Razlomak &a,const Razlomak &b);
    friend bool operator !=(const Razlomak &a,const Razlomak &b);
    friend std::istream &operator >>(std::istream &cin, Razlomak &r);
    friend std::ostream &operator <<(std::ostream &cout,const Razlomak &r);
};
//using namespace std;
std::istream &operator >>(std::istream &cin, Razlomak &r){
    long long int b,n;
    cin>>std::ws;
    cin>>b;
    if(cin.peek()!='/'){
        //cout<<"uuu"<<endl;
        Razlomak a(b);
        r=a;
        return cin;
    }
    char kosa_crta;
    cin>>kosa_crta;
    //std::cin.ignore(1,'\n');
    if(kosa_crta!='/'){cin.setstate(std::ios::failbit);}
     cin>>n;
    if(cin.peek()!='\n' && cin.peek()!='\t' && cin.peek()!='v' && cin.peek()!='f' && cin.peek()!=' '){cin.setstate(std::ios::failbit);}
    Razlomak a(b,n);
    r=a;
    //cout<<"kkk"<<endl;
    return cin;
}
Razlomak operator +(const Razlomak &a,const Razlomak &b){
    return{a.brojnik*(b.nazivnik/Razlomak::NZD(a.nazivnik,b.nazivnik))+b.brojnik*(a.nazivnik/Razlomak::NZD(a.nazivnik,b.nazivnik)),a.nazivnik*(b.nazivnik/Razlomak::NZD(a.nazivnik,b.nazivnik))};
}
std::ostream &operator <<(std::ostream &cout,const Razlomak &r){
    if(r.DajNazivnik()==1)cout<<r.DajBrojnik();
    else
    cout<<r.DajBrojnik()<<"/"<<r.DajNazivnik();
    return cout;
}
Razlomak::Razlomak(long long int b,long long int n){
    if(b>LONG_MAX || b<LONG_MIN || n>LONG_MAX || n<LONG_MIN)throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    if(n==0)throw std::logic_error("Nekorektan razlomak");
    if(b<0 && n<0){
        b*=-1;
        n*=-1;
    }
    else if(b>0 && n<0){
        b*=-1;
        n*=-1;
    }
    int skrati=NZD(b,n);
    brojnik=b/skrati;
    nazivnik=n/skrati;
    //std::cout<<brojnik<<" "<<nazivnik;
}
Razlomak operator -(const Razlomak &a,const Razlomak &b){
    return{a.brojnik*(b.nazivnik/Razlomak::NZD(a.nazivnik,b.nazivnik))-b.brojnik*(a.nazivnik/Razlomak::NZD(a.nazivnik,b.nazivnik)),a.nazivnik*(b.nazivnik/Razlomak::NZD(a.nazivnik,b.nazivnik))};
}
Razlomak operator *(const Razlomak &a,const Razlomak &b){
    int s=Razlomak::NZD(a.brojnik,b.nazivnik);
    int t=Razlomak::NZD(b.brojnik,a.nazivnik);
    return{(a.brojnik/s)*(b.brojnik/t),(a.nazivnik/t)*(b.nazivnik/s)};
}
Razlomak operator /(const Razlomak &a,const Razlomak &b){
    int u=Razlomak::NZD(a.brojnik,b.brojnik);
    int r=Razlomak::NZD(a.nazivnik,b.nazivnik);
    return{(a.brojnik/u)*(b.nazivnik/r),(a.nazivnik/r)*(b.brojnik/u)};
}
Razlomak operator +(const Razlomak &a){
    return {a.brojnik,a.nazivnik};
}
Razlomak operator -(const Razlomak &a){
    return {-a.brojnik,a.nazivnik};
}
Razlomak &Razlomak::operator +=(const Razlomak &a){
        if(brojnik*(a.nazivnik/Razlomak::NZD(nazivnik,a.nazivnik))+a.brojnik*(nazivnik/Razlomak::NZD(nazivnik,a.nazivnik))>LONG_MAX || brojnik*(a.nazivnik/Razlomak::NZD(nazivnik,a.nazivnik))+a.brojnik*(nazivnik/Razlomak::NZD(nazivnik,a.nazivnik))<LONG_MIN || 
        nazivnik*(a.nazivnik/Razlomak::NZD(nazivnik,a.nazivnik))>LONG_MAX || nazivnik*(a.nazivnik/Razlomak::NZD(nazivnik,a.nazivnik))<LONG_MIN)throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        brojnik=brojnik*(a.nazivnik/Razlomak::NZD(nazivnik,a.nazivnik))+a.brojnik*(nazivnik/Razlomak::NZD(nazivnik,a.nazivnik));
        nazivnik=nazivnik*(a.nazivnik/Razlomak::NZD(nazivnik,a.nazivnik));
    return *this;
}
Razlomak &Razlomak::operator -=(const Razlomak &a){
        if(brojnik*(a.nazivnik/Razlomak::NZD(nazivnik,a.nazivnik))-a.brojnik*(nazivnik/Razlomak::NZD(nazivnik,a.nazivnik))>LONG_MAX || brojnik*(a.nazivnik/Razlomak::NZD(nazivnik,a.nazivnik))-a.brojnik*(nazivnik/Razlomak::NZD(nazivnik,a.nazivnik))<LONG_MIN ||
        nazivnik*(a.nazivnik/Razlomak::NZD(nazivnik,a.nazivnik))>LONG_MAX || nazivnik*(a.nazivnik/Razlomak::NZD(nazivnik,a.nazivnik))<LONG_MIN)throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        brojnik=brojnik*(a.nazivnik/Razlomak::NZD(nazivnik,a.nazivnik))-a.brojnik*(nazivnik/Razlomak::NZD(nazivnik,a.nazivnik));
        nazivnik=nazivnik*(a.nazivnik/Razlomak::NZD(nazivnik,a.nazivnik));
    return *this;
}
Razlomak &Razlomak::operator *=(const Razlomak &a){
        int s=Razlomak::NZD(brojnik,a.nazivnik);
        int t=Razlomak::NZD(a.brojnik,nazivnik);
        //return{(a.brojnik/s)*(b.brojnik/t),(a.nazivnik/t)*(b.nazivnik/s)};
        if((brojnik/s)*(a.brojnik/t)>LONG_MAX || (brojnik/s)*(a.brojnik/t)<LONG_MIN ||
        (nazivnik/t)*(a.nazivnik/s)>LONG_MAX || (nazivnik/t)*(a.nazivnik/s)<LONG_MIN)throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        brojnik=(brojnik/s)*(a.brojnik/t);
        nazivnik=(nazivnik/t)*(a.nazivnik/s);
        return *this;
}
Razlomak &Razlomak::operator /=(const Razlomak &a){
    int u=Razlomak::NZD(brojnik,a.brojnik);
    int r=Razlomak::NZD(nazivnik,a.nazivnik);
    if((brojnik/u)*(a.nazivnik/r)>LONG_MAX || (brojnik/u)*(a.nazivnik/r)<LONG_MIN ||
    (nazivnik/r)*(a.brojnik/u)>LONG_MAX || (nazivnik/r)*(a.brojnik/u)<LONG_MIN)throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    brojnik=(brojnik/u)*(a.nazivnik/r);
    nazivnik=(nazivnik/r)*(a.brojnik/u);
    return *this;
}
Razlomak &Razlomak::operator ++(){
    *this=Razlomak::operator +=({1,1});
    return *this;
}
Razlomak &Razlomak::operator --(){
    *this=Razlomak::operator -=({1,1});
    return *this;
}
Razlomak Razlomak::operator ++(int){
    Razlomak pom(*this);
    *this=Razlomak::operator +=({1,1});
    return *this;
    return pom;
}
Razlomak Razlomak::operator --(int){
    Razlomak pom(*this);
    *this=Razlomak::operator -=({1,1});
    return *this;
    return pom;
}
 bool operator <(const Razlomak &a,const Razlomak &b){
     int r=Razlomak::NZD(a.brojnik,b.brojnik);
     int s=Razlomak::NZD(a.nazivnik,b.nazivnik);
     return (a.brojnik/r)*(b.nazivnik/s)<(b.brojnik/r)*(a.nazivnik/s);
 }
 bool operator >(const Razlomak &a,const Razlomak &b){
     int r=Razlomak::NZD(a.brojnik,b.brojnik);
     int s=Razlomak::NZD(a.nazivnik,b.nazivnik);
     return (a.brojnik/r)*(b.nazivnik/s)>(b.brojnik/r)*(a.nazivnik/s);
 }
 bool operator <=(const Razlomak &a,const Razlomak &b){
     int r=Razlomak::NZD(a.brojnik,b.brojnik);
     int s=Razlomak::NZD(a.nazivnik,b.nazivnik);
     return (a.brojnik/r)*(b.nazivnik/s)>(b.brojnik/r)*(a.nazivnik/s);
 }
 bool operator >=(const Razlomak &a,const Razlomak &b){
     int r=Razlomak::NZD(a.brojnik,b.brojnik);
     int s=Razlomak::NZD(a.nazivnik,b.nazivnik);
     return (a.brojnik/r)*(b.nazivnik/s)>(b.brojnik/r)*(a.nazivnik/s);
 }
 bool operator ==(const Razlomak &a,const Razlomak &b){
     int r=Razlomak::NZD(a.brojnik,b.brojnik);
     int s=Razlomak::NZD(a.nazivnik,b.nazivnik);
     return (a.brojnik/r)*(b.nazivnik/s)==(b.brojnik/r)*(a.nazivnik/s);
 }
 bool operator !=(const Razlomak &a,const Razlomak &b){
     int r=Razlomak::NZD(a.brojnik,b.brojnik);
     int s=Razlomak::NZD(a.nazivnik,b.nazivnik);
     if((a.brojnik/r)*(b.nazivnik/s)==(b.brojnik/r)*(a.nazivnik/s))return false;
     return true;
 }
int main ()
{
    Razlomak a;
    std::cin>>a;
    std::cout<<a;
	return 0;
}
