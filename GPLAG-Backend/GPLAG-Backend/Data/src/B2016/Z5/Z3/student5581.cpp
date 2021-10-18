/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <limits>

class Razlomak{
    private:
        long long int brojnik;
        long long int nazivnik;
        friend long long int nzd(long long int a, long long int b);
        
    public:
        Razlomak(long long int b=0, long long int n=1);
        long long int DajNazivnik() const {return nazivnik;}
        long long int DajBrojnik() const {return brojnik;}
        friend std::ostream& operator <<(std::ostream &tok, Razlomak r);
        friend std::istream& operator >>(std::istream &tok, Razlomak &r);
        friend Razlomak operator+ (const Razlomak &r1, const Razlomak &r2);
        friend Razlomak operator- (const Razlomak &r1, const Razlomak &r2);
        friend Razlomak operator* (const Razlomak &r1, const Razlomak &r2);
        friend Razlomak operator/ (const Razlomak &r1, const Razlomak &r2);
        Razlomak operator +() const {return *this;}
        Razlomak operator -() const {return Razlomak(-DajBrojnik(),DajNazivnik());}
        operator long double () const {return (long double)DajBrojnik()/DajNazivnik();}
        Razlomak &operator +=(const Razlomak &r){return *this=*this+r;}
        Razlomak &operator -=(const Razlomak &r){return *this=*this-r;}
        Razlomak &operator *=(const Razlomak &r){return *this=*this*r;}
        Razlomak &operator /=(const Razlomak &r){return *this=*this/r;}
        friend bool operator ==(const Razlomak &r1, const Razlomak &r2);
        friend bool operator !=(const Razlomak &r1, const Razlomak &r2);
        friend Razlomak &operator++(Razlomak &r){r+=Razlomak(1);
            return r;
        }
        friend Razlomak &operator--(Razlomak &r){
            r-=Razlomak(1); return r;
        }
        friend Razlomak operator--(Razlomak &r, int);
        friend Razlomak operator++(Razlomak &r, int);
        friend bool operator <(const Razlomak &r1, const Razlomak &r2);
        friend bool operator <=(const Razlomak &r1, const Razlomak &r2);
        friend bool operator >(const Razlomak &r1, const Razlomak &r2);
        friend bool operator >=(const Razlomak &r1, const Razlomak &r2);
};
bool operator <(const Razlomak &r1, const Razlomak &r2){
    return (long double)r1<(long double)r2;
}
bool operator >(const Razlomak &r1, const Razlomak &r2){
    return (long double)r1>(long double)r2;
}
bool operator <=(const Razlomak &r1, const Razlomak &r2){
    return (long double)r1<=(long double)r2;
}
bool operator >=(const Razlomak &r1, const Razlomak &r2){
    return (long double)r1>=(long double)r2;
}
long long int nzd(long long int a, long long int b){
    if(b==0) return a;
    else return nzd(b,a%b);
}
Razlomak::Razlomak(long long int b, long long int n){
    if(n==0)
        throw std::logic_error("Nekorektan razlomak");
    long long int nzdd=nzd(b,n);
    b/=nzdd; n/=nzdd;
    if((b<0 && n<0)||(b>0 && n<0)) 
        b*=-1,n*=-1;
    brojnik=b; nazivnik=n;
}
bool Bjelina(char a){
    if(a==' ' || a=='\n' || a=='\f' || a=='\v' || a=='\t' || a=='\r')
        return true;
    return false;
}
void PreskociBjeline(){
    while(Bjelina(std::cin.peek()) && std::cin.peek()!='\n')
        std::cin.get();
}
bool Cifra(char a){
    return a>='0'&&a<='9';
}
Razlomak operator ++(Razlomak &r,int){
    Razlomak pom=r;
    r+=Razlomak(1);
    return pom;
}
Razlomak operator--(Razlomak &r,int){
    Razlomak pom=r;
    r+=Razlomak(1);
    return pom;
}
std::ostream& operator <<(std::ostream &tok, Razlomak r){
    if(r.DajBrojnik()==0 || r.DajNazivnik()==1) return tok<<r.DajBrojnik();
    else 
    tok<<r.DajBrojnik()<<"/"<<r.DajNazivnik();
    return tok;
}
std::istream& operator >>(std::istream &tok, Razlomak &r){
    long long int brojnik=0,nazivnik=1;
    while(Bjelina(tok.peek())) tok.get();
    tok>>brojnik;
    if(!tok)return tok;
    if(tok.peek()=='/'){
        char znak;
        tok>>znak;
        tok>>nazivnik;
        if(!tok) return tok;
        if(Bjelina(tok.peek())||tok.peek()==EOF){
            r=Razlomak(brojnik,nazivnik);
            return tok;
        }
        else{tok.setstate(std::ios::failbit);}
    }
    else{
        if(tok.peek()==EOF ||Bjelina(tok.peek())) {
            r=Razlomak(brojnik,1);
            return tok;
        }
        else tok.setstate(std::ios::failbit);
    }
    r=Razlomak(brojnik,nazivnik);
    return tok;
}
void IspitajPrekoracenje(long long int x, long long int y, char o){
    
    long long int m=std::numeric_limits<long long int>::min();
    long long int M=std::numeric_limits<long long int>::max();
    
    if(o=='+'){
        if((y>0 && x>M-y) || (y<0 && x<m-y))
            throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    }
    if(o=='-'){
        if((y<0 && x>M+y) || (y>0 && x<m+y))
            throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    }
    if(o=='*'){
        if(y>0)
            if(x<m/y || x>M/y)
                throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        if(y<0)
            if(x==m || -x>M/(-y) || -x<m/(-y))
                throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    }
}
Razlomak operator+ (const Razlomak &r1, const Razlomak &r2){
    Razlomak pom1=r1, pom2=r2;
    long long int r;
    r=nzd(pom1.DajNazivnik(),pom2.DajNazivnik());
    IspitajPrekoracenje(r1.DajNazivnik(),r2.DajNazivnik()/r,'*');
    IspitajPrekoracenje(r1.DajBrojnik(),r2.DajNazivnik()/r,'*');
    IspitajPrekoracenje(r2.DajBrojnik(),r1.DajNazivnik()/r,'*');
    long long int naz=r1.DajNazivnik()*(r2.DajNazivnik()/r);
    long long int s1=r1.DajBrojnik()*(r2.DajNazivnik()/r);
    long long int s2=r2.DajBrojnik()*(r1.DajNazivnik()/r);
    IspitajPrekoracenje(s1,s2,'+');
    return Razlomak(s1+s2,naz);
}
Razlomak operator- (const Razlomak &r1, const Razlomak &r2){
    Razlomak pom1=r1,pom2=r2;
    long long int r=nzd(pom1.DajNazivnik(),pom2.DajNazivnik());
    IspitajPrekoracenje(r1.DajNazivnik(),r2.DajNazivnik()/r,'*');
    IspitajPrekoracenje(r1.DajBrojnik(),r2.DajNazivnik()/r,'*');
    IspitajPrekoracenje(r2.DajBrojnik(),r1.DajNazivnik()/r,'*');
    long long int naz=r1.DajNazivnik()*(r2.DajNazivnik()/r);
    long long int s1=r1.DajBrojnik()*(r2.DajNazivnik()/r);
    long long int s2=r2.DajBrojnik()*(r1.DajNazivnik()/r);
    IspitajPrekoracenje(s1,s2,'-');
    return Razlomak(s1-s2,naz);
    
    
}
Razlomak operator* (const Razlomak &r1, const Razlomak &r2){
    long long int s=nzd(r1.DajBrojnik(),r2.DajNazivnik());
    long long int t=nzd(r2.DajBrojnik(),r1.DajNazivnik());
    long long int x1=r1.DajBrojnik()/s,x2=r2.DajBrojnik()/t;
    long long int x3=r1.DajNazivnik()/t,x4=r2.DajNazivnik()/s;
    IspitajPrekoracenje(x1,x2,'*');
    IspitajPrekoracenje(x3,x4,'*');
    return Razlomak(x1*x2,x3*x4);
}
Razlomak operator/ (const Razlomak &r1, const Razlomak &r2){
    return r1*Razlomak(r2.DajNazivnik(),r2.DajBrojnik());
}
bool operator == (const Razlomak &r1, const Razlomak &r2){
    return (long double)r1==(long double)r2;
}
bool operator !=(const Razlomak &r1, const Razlomak &r2){
    return !(r1==r2);
}

int main ()
{
    Razlomak r1(5,8),r2(7,9),r3(16,31);
    std::cout<<r1+r2<<std::endl;
    Razlomak r4;
    r4=r1*r2*r3;
    std::cout<<r4<<std::endl;
    r2+=r3;
    r3++;
    ++r4;
    std::cout<<r4<<std::endl;
    r4*=++r2;
    r1=r2-r3;
    std::cout<<r1<<std::endl;
	return 0;
}