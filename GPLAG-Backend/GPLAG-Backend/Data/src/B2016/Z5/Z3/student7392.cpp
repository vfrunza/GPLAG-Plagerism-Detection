/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <sstream>
#include <limits>

const long long int M=std::numeric_limits<long long int>::max();
const long long int m=std::numeric_limits<long long int>::lowest();

long long int saberi(long long int a, long long int b){
    if(b>0)if(a>M-b)throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    if(b<0)if(a<m-b)throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    return a+b;
}

long long int invert(long long int a){
    if(a==m)throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    return -a;
}

long long int pomnozi(long long int a, long long int b){
    if(b>0)if(a<m/b || a>M/b)throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    if(b<0)if(invert(a)>M/invert(b) || invert(a)<m/invert(b))throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    return a*b;
}

long long int podijeli(long long int a, long long int b){
    if(a==m && b==-1)throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    return a/b;
}

long long int abs(long long int a){
    if(a<0)return invert(a);
    return a;
}

class Razlomak{
    long long int brojnik, nazivnik;
    static long long int nzd(long long int a, long long int b){
        if(b==0)return a;
        return nzd(b, a%b);
    }
public:
    Razlomak(long long int brojnik=0, long long int nazivnik=1);
    const long long int DajNazivnik() const{return nazivnik;}
    const long long int DajBrojnik() const{return brojnik;}
    Razlomak operator +(const Razlomak &r1) const;
    Razlomak operator -(const Razlomak &r1) const;
    Razlomak operator *(const Razlomak &r1) const;
    Razlomak operator /(const Razlomak &r1) const;
    Razlomak operator -() const;
    Razlomak operator +() const;
    Razlomak& operator +=(const Razlomak &r1);
    Razlomak& operator -=(const Razlomak &r1);
    Razlomak& operator *=(const Razlomak &r1);
    Razlomak& operator /=(const Razlomak &r1);
    Razlomak& operator ++();
    Razlomak operator ++(int);
    Razlomak& operator --();
    Razlomak operator --(int); 
    bool operator <(const Razlomak &r2) const;
    bool operator <=(const Razlomak &r2) const;
    bool operator >(const Razlomak &r2) const;
    bool operator >=(const Razlomak &r2) const;
    bool operator ==(const Razlomak &r2) const;
    bool operator !=(const Razlomak &r2) const;
    operator long double() const;
    friend std::ostream& operator <<(std::ostream& fout, const Razlomak &r2);
    friend std::istream& operator >>(std::istream& fin, Razlomak &r2);
};

Razlomak::Razlomak(long long int brojnik, long long int nazivnik){
    if(nazivnik==0)throw std::logic_error("Nekorektan razlomak");
    long long int n=nzd(abs(brojnik), abs(nazivnik));
    brojnik/=n;
    nazivnik/=n;
    if(nazivnik<0){
        nazivnik=-nazivnik;
        brojnik=-brojnik;
    }
    this->brojnik=brojnik;
    this->nazivnik=nazivnik;
}
Razlomak Razlomak::operator +(const Razlomak &r2) const{
    long long int r=nzd(abs(nazivnik), abs(r2.nazivnik));
    return Razlomak(saberi(pomnozi(brojnik, r2.nazivnik/r), pomnozi(r2.brojnik, nazivnik/r)), pomnozi(nazivnik, r2.nazivnik/r));
}
Razlomak Razlomak::operator -(const Razlomak &r2) const{
    long long int r=nzd(abs(nazivnik), abs(r2.nazivnik));
    return Razlomak(saberi(pomnozi(brojnik, r2.nazivnik/r), invert(pomnozi(r2.brojnik, nazivnik/r))), pomnozi(nazivnik, r2.nazivnik/r));
}
Razlomak Razlomak::operator *(const Razlomak &r2) const{
    long long int s=nzd(abs(brojnik), abs(r2.nazivnik));
    long long int t=nzd(abs(r2.brojnik), abs(nazivnik));
    return Razlomak(pomnozi(brojnik/s, r2.brojnik/t), pomnozi(nazivnik/t, r2.nazivnik/s));
}
Razlomak Razlomak::operator /(const Razlomak &r2) const{
    return *this*Razlomak(r2.nazivnik, r2.brojnik);
}
Razlomak Razlomak::operator -() const{
    return Razlomak(invert(brojnik), nazivnik);
}
Razlomak Razlomak::operator +() const{
    return *this;
}
Razlomak& Razlomak::operator +=(const Razlomak &r2){
    *this=*this+r2;
    return *this;
}
Razlomak& Razlomak::operator -=(const Razlomak &r2){
    *this=*this-r2;
    return *this;
}
Razlomak& Razlomak::operator *=(const Razlomak &r2){
    *this=*this*r2;
    return *this;
}
Razlomak& Razlomak::operator /=(const Razlomak &r2){
    *this=*this/r2;
    return *this;
}
Razlomak& Razlomak::operator ++(){
    *this=*this+Razlomak(1);
    return *this;
}
Razlomak Razlomak::operator ++(int){
    Razlomak pomocni(this->DajBrojnik(), this->DajNazivnik());
    ++*this;
    return pomocni;
}
Razlomak& Razlomak::operator --(){
    *this=*this-Razlomak(1);
    return *this;
}
Razlomak Razlomak::operator --(int){
    Razlomak pomocni(brojnik, nazivnik);
    --*this;
    return pomocni;
}
Razlomak::operator long double() const{
    return (long double)brojnik/nazivnik;
}
bool Razlomak::operator <(const Razlomak &r2) const{
    return ((long double)*this)<((long double)r2);
}
bool Razlomak::operator <=(const Razlomak &r2) const{
    return ((long double)*this)<=((long double)r2);
}
bool Razlomak::operator >(const Razlomak &r2) const{
    return ((long double)*this)>((long double)r2);
}
bool Razlomak::operator >=(const Razlomak &r2) const{
    return ((long double)*this)>=((long double)r2);
}
bool Razlomak::operator ==(const Razlomak &r2) const{
    return (brojnik==r2.brojnik && nazivnik==r2.nazivnik);
}
bool Razlomak::operator !=(const Razlomak &r2) const{
    return !(*this==r2);
}
std::ostream& operator <<(std::ostream &fout, const Razlomak &r2){
    fout<<r2.brojnik;
    if(r2.nazivnik!=1)fout<<"/"<<r2.nazivnik;
    return fout;
}
std::istream& operator >>(std::istream &fin, Razlomak &r2){
    long long int a, b=1;
    if(!fin || fin.eof())return fin;
    fin>>a;
    if(!fin)return fin;
    if(fin.eof() || fin.peek()==' ' || fin.peek()=='\n' || fin.peek()=='\t' || fin.peek()=='\v' || fin.peek()=='\f' || fin.peek()=='\r'){
        r2=Razlomak(a,b);
        return fin;
    }
    if(fin.peek()=='/'){
        char c;
        fin.get(c);
        fin>>b;
        if(fin){
            if(fin.eof() || fin.peek()==' ' || fin.peek()=='\n' || fin.peek()=='\t' || fin.peek()=='\v' || fin.peek()=='\f' || fin.peek()=='\r'){
                r2=Razlomak(a,b);
                return fin;
            }
        }
    }
    fin.setstate(std::ios::failbit);
    return fin;
}

int main ()
{
    std::istringstream is ("5/17\r10\r20\r30\r15/17\r"); //ne mora sa \n zavrsiti
    Razlomak r, p, q;
        is>> r; //5/17
        std::cout << r << std::endl;
        is.clear(); is.ignore (100, '\n');
        //tri zaredom
        is >> r >> p >> q; //10 20 30 -> 10/1 20/1 30/1
        std::cout << r << " " << p << " " << q << std::endl;
        is.clear(); is.ignore (100, '\n');
        is >> r;
        std::cout << r;
    return 0;
     Razlomak c;
    Razlomak a{3,5};
    Razlomak b{4,10};
   
    c=a+b;
    c*=2;
    std::cout<<c<<"\n";
    c-=(a++)-b;
    std::cout<<--c<<"\n";
    c+=(--a)*b;
    std::cout<<c<<"\n";
    c/=a/b;
    std::cout<<c<<"\n";
    std::cout<<(a<b)<<" "<<(a<=b)<<" "<<(a>b)<<" "<<(a>=b)<<" "<<(a==b)<<" "<<(a!=b)<<"\n";
    if(!(std::cin>>c))std::cout<<"nije fino"; else std::cout<<(long double)c;
	return 0;
}