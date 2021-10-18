/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <limits>
#include <cmath>

class Razlomak
{
    long long int brojnik, nazivnik;
    static long long int NZD (long long int br, long long int naz) {
        if(naz==0) return br;
        return NZD(naz, br%naz);
    }
    void SkratiRazlomak(long long int &br, long long int &naz) {
        auto x(NZD(br,naz));
        br/=x;
        naz/=x;
    };
    static void TestOwerflowaPlus(long long int prvi, long long int drugi);
    static void TestOwerflowaPuta(long long int prvi, long long int drugi);
public:
    Razlomak (long long int br=0, long long int naz=1);
    long long int DajBrojnik() const{ return brojnik;}
    long long int DajNazivnik() const { return nazivnik;}
    friend Razlomak operator +(const Razlomak& x, const Razlomak &y);
    friend Razlomak operator -(const Razlomak& x, const Razlomak &y);
    friend Razlomak operator *(const Razlomak& x, const Razlomak &y);
    friend Razlomak operator /(const Razlomak& x, const Razlomak &y);
    Razlomak& operator -();
    Razlomak& operator +();
    Razlomak& operator +=(const Razlomak &y);
    Razlomak& operator -=(const Razlomak &y);
    Razlomak& operator *=(const Razlomak &y);
    Razlomak& operator /=(const Razlomak &y);
    friend bool operator >(const Razlomak& x, const Razlomak &y);
    friend bool operator <(const Razlomak& x, const Razlomak &y);
    friend bool operator <=(const Razlomak& x, const Razlomak &y);
    friend bool operator >=(const Razlomak& x, const Razlomak &y);
    friend bool operator ==(const Razlomak& x, const Razlomak &y);
    friend bool operator !=(const Razlomak& x, const Razlomak &y);
    friend std::ostream &operator << (std::ostream &tok, const Razlomak &y);
    friend std::istream operator >> (std::istream &ulaz, const Razlomak &y);
    operator long double() const{
        return (long double)(brojnik)/nazivnik;
    }
};

void Razlomak::TestOwerflowaPlus(long long int prvi, long long int drugi)
{
    if(drugi>0 and prvi>std::numeric_limits<long long int>::max()-drugi) throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
    else if(drugi<0 and prvi<std::numeric_limits<long long int>::lowest()-drugi) throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
}

void Razlomak::TestOwerflowaPuta(long long int prvi, long long int drugi){
    if(drugi>0 and prvi<std::numeric_limits<long long int>::lowest()/drugi) throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
    else if( prvi==std::numeric_limits<long long int>::lowest() or (drugi<0 and -prvi>std::numeric_limits<long long int>::max()/(-drugi))) throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
}

Razlomak::Razlomak (long long int br, long long int naz)
{
    if(naz==0) throw std::logic_error ("Nekorektan razlomak");
    if(br>0 and naz<0) {
        br=-br;
        naz=-naz;
    }
    if(br<0 and naz<0) {
        br=-br;
        naz=-naz;
    }
    SkratiRazlomak(br,naz);
    brojnik=br;
    nazivnik=naz;
}
                                                                //operatori
Razlomak operator +(const Razlomak& x, const Razlomak &y)
{
    auto r(Razlomak::NZD(x.nazivnik, y.nazivnik));
    long long int prvi(x.brojnik*(y.nazivnik/r)), drugi(y.brojnik*(x.nazivnik/r));
    Razlomak::TestOwerflowaPlus(prvi, drugi);
    return Razlomak(x.brojnik*(y.nazivnik/r)+y.brojnik*(x.nazivnik/r), x.nazivnik*(y.nazivnik/r));
}
Razlomak operator -(const Razlomak& x, const Razlomak &y)
{
    auto r(Razlomak::NZD(x.nazivnik, y.nazivnik));
    long long int prvi(x.brojnik*(y.nazivnik/r)), drugi(-y.brojnik*(x.nazivnik/r));
    Razlomak::TestOwerflowaPlus(prvi, drugi);
    return Razlomak(x.brojnik*(y.nazivnik/r)-y.brojnik*(x.nazivnik/r), x.nazivnik*(y.nazivnik/r));
}
Razlomak operator *(const Razlomak& x, const Razlomak &y)
{
    auto s(Razlomak::NZD(x.brojnik, y.nazivnik)), t(Razlomak::NZD(y.brojnik, x.nazivnik));
    long long int prvi(x.brojnik/s), drugi(y.brojnik/t);
    Razlomak::TestOwerflowaPuta(prvi, drugi);
    Razlomak::TestOwerflowaPuta(x.nazivnik/t, y.nazivnik/s);
    return Razlomak(prvi*drugi, (x.nazivnik/t)* (y.nazivnik/s));
}
Razlomak operator /(const Razlomak& x, const Razlomak &y)
{
    auto r(Razlomak::NZD(x.nazivnik, y.nazivnik)), u(Razlomak::NZD(x.brojnik, y.brojnik));
    long long int prvi(x.brojnik/u), drugi(y.nazivnik/r);
    Razlomak::TestOwerflowaPuta(prvi, drugi);
    Razlomak::TestOwerflowaPuta(x.nazivnik/r, y.brojnik/u);
    return Razlomak((prvi*drugi), ((x.nazivnik/r)* (y.brojnik/u)));
}
 Razlomak& Razlomak::operator -(){
     if(brojnik==std::numeric_limits<long long int>::lowest()) throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
     brojnik=-brojnik;
     return*this;
 };
Razlomak& Razlomak::operator +(){
    return*this;
}
Razlomak& Razlomak::operator +=(const Razlomak& y){
    auto r(Razlomak::NZD(nazivnik, y.nazivnik));
    long long int prvi(brojnik*(y.nazivnik/r)), drugi(y.brojnik*(nazivnik/r));
    Razlomak::TestOwerflowaPlus(prvi, drugi);
    brojnik=brojnik*(y.nazivnik/r)+y.brojnik*(nazivnik/r);
    nazivnik= nazivnik*(y.nazivnik/r);
    return*this;
}
Razlomak& Razlomak::operator -=(const Razlomak& y){
    auto r(Razlomak::NZD(nazivnik, y.nazivnik));
    auto brojniky=-y.brojnik;
    long long int prvi(brojnik*(y.nazivnik/r)), drugi(brojniky*(nazivnik/r));
    Razlomak::TestOwerflowaPlus(prvi, drugi);
    brojnik=brojnik*(y.nazivnik/r)+y.brojnik*(nazivnik/r);
    nazivnik= nazivnik*(y.nazivnik/r);
    return*this;
}
Razlomak& Razlomak::operator *=(const Razlomak&y){
    auto s(Razlomak::NZD(brojnik, y.nazivnik)), t(Razlomak::NZD(y.brojnik, nazivnik));
    long long int prvi(brojnik/s), drugi(y.brojnik/t);
    Razlomak::TestOwerflowaPuta(prvi, drugi);
    Razlomak::TestOwerflowaPuta(nazivnik/t, y.nazivnik/s);
    brojnik=prvi*drugi;
    nazivnik=(nazivnik/t)* (y.nazivnik/s);
    return *this;
}
Razlomak& Razlomak::operator /=(const Razlomak &y){
    auto r(Razlomak::NZD(nazivnik, y.nazivnik)), u(Razlomak::NZD(brojnik, y.brojnik));
    long long int prvi(brojnik/u), drugi(y.nazivnik/r);
    Razlomak::TestOwerflowaPuta(prvi, drugi);
    Razlomak::TestOwerflowaPuta(nazivnik/r, y.brojnik/u);
    brojnik=prvi*drugi,
    nazivnik=(nazivnik/r)* (y.brojnik/u);
    return *this;
}
bool operator <(const Razlomak& x, const Razlomak &y){
    long double xx(static_cast<long double>(x.brojnik)/x.nazivnik);
    long double yy(static_cast<long double>(y.brojnik)/y.nazivnik);
    return xx<yy;
}
bool operator >(const Razlomak& x, const Razlomak &y){
    long double xx(static_cast<long double>(x.brojnik)/x.nazivnik), yy(static_cast<long double>(y.brojnik)/y.nazivnik);
    return xx>yy;
}
bool operator <=(const Razlomak& x, const Razlomak &y){
    long double xx(static_cast<long double>(x.brojnik)/x.nazivnik), yy(static_cast<long double>(y.brojnik)/y.nazivnik);
    return xx<=yy;
}
bool operator >=(const Razlomak& x, const Razlomak &y){
    long double xx(static_cast<long double>(x.brojnik)/x.nazivnik), yy(static_cast<long double>(y.brojnik)/y.nazivnik);
    return xx>=yy;
}
bool operator ==(const Razlomak& x, const Razlomak &y){
    long double xx(static_cast<long double>(x.brojnik)/x.nazivnik), yy(static_cast<long double>(y.brojnik)/y.nazivnik);
    return xx==yy;
}
bool operator !=(const Razlomak& x, const Razlomak &y){
    long double xx(static_cast<long double>(x.brojnik)/x.nazivnik), yy(static_cast<long double>(y.brojnik)/y.nazivnik);
    return xx!=yy;
}
std::ostream &operator << (std::ostream& tok, const Razlomak &y){
    tok << y.brojnik;
    if(y.nazivnik!=1) tok << "/" << y.nazivnik;
    return tok;
}
std::istream &operator >>(std::istream &ulaz,Razlomak &p)
{
    char znak;
    long long int q,r;
    if(!(ulaz>>q)){
        ulaz.setstate(std::ios::failbit);
        return ulaz;
    }
    if((ulaz.peek()==EOF) or (ulaz.peek()=='\t') or (ulaz.peek()=='\v') or (ulaz.peek()=='\f') or (ulaz.peek()==' ') or (ulaz.peek()=='\n') or (ulaz.peek()=='\r')){
        p=Razlomak(q,1);
        return ulaz;
    }
    else if(ulaz.peek()=='/'){
        ulaz>>znak;
        if(ulaz.peek()>'9' or ulaz.peek()<'0'){
            ulaz.setstate(std::ios::failbit);
            return ulaz;
        }
        if(!(ulaz>>r) or ((ulaz.peek()!=EOF) and (ulaz.peek()!='\t') and (ulaz.peek()!='\v') and (ulaz.peek()!='\f') and (ulaz.peek()!=' ') and (ulaz.peek()!='\n') and (ulaz.peek()!='\r'))){
            ulaz.setstate(std::ios::failbit);
            return ulaz;
        }
        p=Razlomak(q,r);
        return ulaz;
    }
    ulaz.setstate(std::ios::failbit);
    return ulaz;
}
using std::cin;
using std::cout;
int main ()
{ 
    try{
        Razlomak r1, r2;
    std::cout << "Unesite prvi razlomak: ";
    cin >> r1;
    std::cout <<"Unesite drugi razlomak: ";
    cin >> r2;
    cout << "Zbir razlomka je: "<< r1+r2;
    cout << "Razlika razlomka je: "<< r1-r2;
    cout << "Proizvod razlomka je: "<< r1*r2;
    cout << "Prvi razlomak podijeljen sa drugim iznosi: "<<r1/r2;
    } catch(std::overflow_error e){
        cout << e.what();
    }
    return 0;
}