/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <limits>
class Razlomak {
    long long int brojnik, nazivnik;
    static long long int NZD(int brojnik, int nazivnik);
    static bool sabiranje_prekoracenje(long long int x, long long int y);
    static bool oduzimanje_prekoracenje(long long int x, long long int y);
    static bool mnozenje_prekoracenje(long long int x, long long int y);
    public:
    Razlomak(long long int br, long long int naz);
    Razlomak(long long int br=0);
    void Ispisi ()const ;
    long long int DajBrojnik() const {return brojnik; }
    long long int DajNazivnik() const {return nazivnik; }
    friend Razlomak operator+ (const Razlomak &a, const Razlomak &b);
    friend Razlomak operator- (const Razlomak &a, const Razlomak &b);
    friend Razlomak operator* (const Razlomak &a, const Razlomak &b);
    friend Razlomak operator/ (const Razlomak &a, const Razlomak &b);
    friend Razlomak operator+ (const Razlomak &a) { return a;}
    friend Razlomak operator -( Razlomak &a);
    inline friend Razlomak operator += (Razlomak &a, const Razlomak &b);
    inline friend Razlomak operator -= (Razlomak &a, const Razlomak &b);
    inline friend Razlomak operator*= (Razlomak &a, const Razlomak &b);
    inline friend Razlomak operator/= (Razlomak &a, const Razlomak &b);
    inline friend Razlomak operator ++(Razlomak &a);
    inline friend Razlomak operator ++(Razlomak &a, int);
    inline friend Razlomak operator --(Razlomak &a);
    inline friend Razlomak operator --(Razlomak &a, int);
    friend std::ostream & operator<<(std::ostream&tok, const Razlomak &a);
    friend std::istream &operator >>(std::istream&tok, Razlomak &a);
    friend bool operator<(const Razlomak &a, const Razlomak &b);
    friend bool operator>(const Razlomak &a, const Razlomak &b);
    friend bool operator>=(const Razlomak &a, const Razlomak &b);
    friend bool operator<=(const Razlomak &a, const Razlomak &b);
    operator long double();
    void SkratiRazlomak();
};
long long int Razlomak::NZD(int brojnik, int nazivnik) {
    if (nazivnik==0) return brojnik;
    else return NZD(nazivnik, brojnik%nazivnik);
}
Razlomak operator-(Razlomak &a) {
    a.brojnik*=-1;
    return a;
}
void Razlomak::Ispisi() const {
    std::cout<<DajBrojnik()<<"/"<<DajNazivnik()<<std::endl;
}
bool Razlomak::sabiranje_prekoracenje(long long int x, long long int y) {
    if ((y>0 && x>std::numeric_limits<long long int>::max()-y) || (y<0 && x<std::numeric_limits<long long int>::lowest()-y)) return true;
    else return false;
}
bool Razlomak::oduzimanje_prekoracenje(long long int x, long long int y) {
    if ((y<0 && x>y-std::numeric_limits<long long int>::lowest()) || (y>0 && x<y-std::numeric_limits<long long int>::max())) return true;
    else return false;
}
bool Razlomak::mnozenje_prekoracenje(long long int x, long long int y) {
    if ((y>0 &&(y<std::numeric_limits<long long int>::lowest()/x)||(y>std::numeric_limits<long long int>::max()/x)) || (y<0 && (x==std::numeric_limits<long long int>::lowest() || (-x)<std::numeric_limits<long long int>::lowest()/(-y)))) return true;
    else return false;
}
Razlomak::Razlomak (long long int br, long long int naz) {
    if (naz==0) throw std::logic_error ("Nekorektan razlomak");
    int nzd(NZD(br, naz));
    br/=nzd;
    naz/=nzd;
    if (br<0 && naz<0) {
        brojnik=fabs(br);
        nazivnik=fabs(naz);
    }
    else if (br<0 || naz<0) {
        brojnik=fabs(br)*(-1);
        nazivnik=fabs(naz);
    }
    else {
        brojnik=br;
        nazivnik=naz;
    }
}
void Razlomak::SkratiRazlomak () {
    long long int nzd(NZD(brojnik, nazivnik));
    brojnik/=nzd;
    nazivnik/=nzd;
    if (brojnik<0 && nazivnik<0) {
        brojnik=fabs(brojnik);
        nazivnik=fabs(nazivnik);
    }
    else if (brojnik<0 || nazivnik<0) {
        brojnik=fabs(brojnik)*(-1);
        nazivnik=fabs(nazivnik);
    }
}
Razlomak::Razlomak (long long int br) {
    brojnik=br;
    nazivnik=1;
}
Razlomak operator+(const Razlomak &a, const Razlomak &b) {
    long long int r(Razlomak::NZD(a.DajNazivnik(), b.DajNazivnik()));  
    Razlomak zbir(a.brojnik*(b.nazivnik/r)+b.brojnik*(a.nazivnik/r),a.nazivnik*(b.nazivnik/r));
    return zbir;
}
inline Razlomak operator+=(Razlomak &a, const Razlomak &b) {
    a=a+b;
    a.SkratiRazlomak();
    return a;
}
Razlomak operator-(const Razlomak &a, const Razlomak &b) {
    long long int r(Razlomak::NZD(a.DajNazivnik(), b.DajNazivnik()));
    Razlomak razlika(a.brojnik*(b.nazivnik/r)+b.brojnik*(a.nazivnik/r),a.nazivnik*(b.nazivnik/r));
    return razlika;
}
inline Razlomak operator -=(Razlomak &a, const Razlomak &b) {
    a=a-b;
    a.SkratiRazlomak();
    return a;
}
Razlomak operator*(const Razlomak &a, const Razlomak &b) {
    long long int s(Razlomak::NZD(a.brojnik, b.nazivnik));
    long long int t(Razlomak::NZD(b.brojnik, a.nazivnik));
    Razlomak proizvod((a.brojnik/s)*(b.brojnik/t), (a.nazivnik/t)*(b.nazivnik/s));
    return proizvod;
}
inline Razlomak operator*= (Razlomak &a, const Razlomak &b) {
    a=a*b;
    a.SkratiRazlomak();
    return a;
}
Razlomak operator /(const Razlomak &a, const Razlomak &b) {
    long long int u(Razlomak::NZD(a.brojnik, b.brojnik));
    long long int r(Razlomak::NZD(a.nazivnik, b.nazivnik));
    Razlomak kolicnik((a.brojnik/u)*(b.nazivnik/r), (a.nazivnik/r)*(b.brojnik/u));
    return kolicnik;
}
Razlomak operator /= (Razlomak &a, const Razlomak &b) {
    a=a/b;
    a.SkratiRazlomak();
    return a;
}
inline Razlomak operator ++(Razlomak &a) {
    Razlomak temp(1,1);
    a=a+temp;
    a.SkratiRazlomak();
    return a;
}
inline Razlomak operator++ (Razlomak &a, int) {
    Razlomak temp(a), temp2(1,1);
    a=a+temp2;
    a.SkratiRazlomak();
    return temp;
}
inline Razlomak operator --(Razlomak &a) {
    Razlomak temp (1,1);
    a=a-temp;
    a.SkratiRazlomak();
    return a;
}
inline Razlomak operator --(Razlomak &a, int) {
    Razlomak temp(a), temp2(1,1);
    a=a-temp2;
    a.SkratiRazlomak();
    return temp;
}
std::ostream &operator<<(std::ostream& tok, const Razlomak &a) {
    tok<<a.brojnik;
    if (a.nazivnik==1) return tok;
    else tok<<"/"<<a.nazivnik;
    return tok;
}
std::istream &operator>>(std::istream&tok, Razlomak &a) {
    a.brojnik=1;
    a.nazivnik=1;
    char znak;
    std::cin.clear();
    tok>>std::ws;
    //std::cin.ignore(10000, '\n');
    if (a.brojnik>=0 && a.brojnik<=9)
    tok>>a.brojnik>>std::ws;
    else tok.setstate(std::ios::failbit);
    znak=tok.peek();
    if (znak=='/') {
        tok>>znak;
        tok>>std::ws;
        if (a.nazivnik>=0 && a.nazivnik<=9)
            tok>>a.nazivnik;
        else tok.setstate(std::ios::failbit);
        //tok>>std::ws;
        if (tok.peek()!='\n' && tok.peek()!=' ') tok.setstate(std::ios::failbit);
    }
    else if (!znak)tok.setstate(std::ios::failbit);
    a.SkratiRazlomak();
    return tok;
}
bool operator <(const Razlomak &a, const Razlomak &b) {
    long double prvi(static_cast<long double>(a.brojnik)/a.nazivnik);
    long double drugi(static_cast<long double>(b.brojnik)/b.nazivnik);
    return prvi<drugi;
}
bool operator >(const Razlomak &a, const Razlomak &b) {
    long double prvi(static_cast<long double>(a.brojnik)/a.nazivnik);
    long double drugi(static_cast<long double>(b.brojnik)/b.nazivnik);
    return prvi>drugi;
}
bool operator >=(const Razlomak &a, const Razlomak &b) {
    long double prvi(static_cast<long double>(a.brojnik)/a.nazivnik);
    long double drugi(static_cast<long double>(b.brojnik)/b.nazivnik);
    return prvi>=drugi;
}
bool operator <=(const Razlomak &a, const Razlomak &b) {
    long double prvi(static_cast<long double>(a.brojnik)/a.nazivnik);
    long double drugi(static_cast<long double>(b.brojnik)/b.brojnik);
    return prvi<=drugi;
}
Razlomak::operator long double() {
    long double x(static_cast<long double>(brojnik)/nazivnik);
    return x;
}
int main ()
{
    Razlomak razlomak(2,8);
    Razlomak razlomak2(1,2);
    Razlomak a;
    std::cin>>a;
    std::cout<<a;
    
    /*Razlomak zbir(razlomak+razlomak2);
    std::cout<<zbir<<std::endl;
    Razlomak proizvod(razlomak*razlomak2);
    std::cout<<proizvod<<std::endl;
    Razlomak kolicnik(razlomak/razlomak2);
    std::cout<<kolicnik<<std::endl;
    -razlomak2;
    std::cout<<razlomak2<<std::endl;
    razlomak2++;
    std::cout<<razlomak2<<std::endl;*/
    
    
	return 0;
}