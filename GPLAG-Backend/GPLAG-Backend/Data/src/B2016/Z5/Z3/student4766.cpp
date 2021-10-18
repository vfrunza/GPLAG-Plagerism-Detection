#include <iostream>
#include <cmath>
#include <stdexcept>
#include <initializer_list>
#include <limits> 

class Razlomak{
        long long int p,q;
    public:
        Razlomak(long long int p = 0, long long int q = 1);
        Razlomak(std::initializer_list<long long int> l);
        long long int DajBrojnik()const{ return p; }
        long long int DajNazivnik()const{ return q; }
        Razlomak operator+( const Razlomak &r2)const;
        Razlomak operator-( const Razlomak &r2)const;
        Razlomak operator*( const Razlomak &r2)const;
        Razlomak operator/( const Razlomak &r2)const;
        Razlomak operator-()const;
        Razlomak operator+()const{ return *this; }
        Razlomak &operator+=(const Razlomak &r);
        Razlomak &operator-=(const Razlomak &r);
        Razlomak &operator*=(const Razlomak &r);
        Razlomak &operator/=(const Razlomak &r);
        Razlomak &operator++();
        Razlomak &operator--();
        Razlomak operator++(int);
        Razlomak operator--(int);
        bool operator<(const Razlomak &r)const;
        bool operator>(const Razlomak &r)const;
        bool operator<=(const Razlomak &r)const;
        bool operator>=(const Razlomak &r)const;
        bool operator==(const Razlomak &r)const;
        operator long double()const{ return (long double)this->p/this->q; }
        friend std::ostream &operator<<(std::ostream &tok, const Razlomak &r);
        friend std::istream &operator>>(std::istream &tok, Razlomak &r);
    private:
        void skrati();
        static bool isWhite(char c){
            return (c=='\n' || c=='\r' || c=='\f' || c=='\v' || c=='\t' || c==' ');
        }
        static Razlomak form(long long int p1, long long int p2,
            long long int q1, long long int q2, long long int x, long long int y);
        static bool oPlus(long long int x, long long int y){
            if(y > 0) return x > max() - y;
            return x < min() - y;
        }
        static bool oMinus(long long int x, long long int y){ return oPlus(x,-y); }
        static bool oMnoz(long long int x, long long int y){
            if(y > 0) return (x < min()/y || x > max()/y);
            return (x == min() || -x > max()/(-y) || -x < min()/(-y));
        }
        static long long int zbir(long long int x, long long int y){
            if(oPlus(x,y)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
            return x + y;
        }
        static long long int razlika(long long int x, long long int y){
            if(oMinus(x,y)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
            return x - y;
        }
        static long long int prod(long long int x, long long int y){
            if(oMnoz(x,y)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
            return x * y;
        }
        static long long int max(){ return std::numeric_limits<long long int>::max(); }
        static long long int min(){ return std::numeric_limits<long long int>::min(); }
        static long long int nzd(long long int p, long long int q);
        int sgn(long long int x) { if(x < 0) return -1; return 1; }
};
std::istream &operator>>(std::istream &tok, Razlomak &rr){
    char c;
    long long int p, q;
    Razlomak r;
    tok>> r.p; //>> std::ws;
    if(tok.peek() == EOF || Razlomak::isWhite(tok.peek())){
        rr = r; return tok;
    }
    tok >> c >> r.q;
    if(c != '/' || (tok.peek() != EOF && !Razlomak::isWhite(tok.peek()))) tok.setstate(std::ios::failbit);
    //else { r.p = p; r.q = q; r.skrati();}
    r.skrati();
    rr = r;
    return tok;
}
std::ostream &operator<<(std::ostream &tok, const Razlomak &r){
    if(r.q != 1) tok << r.p << "/" << r.q;
    else tok << r.p;
    return tok;
}
bool Razlomak::operator==(const Razlomak &r)const{
    return (long double)this->p/this->q == (long double)r.p/r.q;
}
bool Razlomak::operator>=(const Razlomak &r)const{
    return (*this > r || *this == r);
}
bool Razlomak::operator<=(const Razlomak &r)const{
    return (*this < r || *this == r);
}
bool Razlomak::operator<(const Razlomak &r)const{
    return (long double)this->p/this->q < (long double)r.p/r.q;
}
bool Razlomak::operator>(const Razlomak &r)const{
    return (long double)this->p/this->q > (long double)r.p/r.q;
}
Razlomak Razlomak::operator--(int){
    auto ret(*this); *this -= Razlomak(1);
    return ret;
}
Razlomak Razlomak::operator++(int){
    auto ret(*this); *this += Razlomak(1);
    return ret;
}
Razlomak &Razlomak::operator--(){
    *this = *this - Razlomak(1);
    return * this;
}
Razlomak &Razlomak::operator++(){
    *this = *this + Razlomak(1);
    return *this;
}
Razlomak &Razlomak::operator/=(const Razlomak &r){
    *this = *this / r;
    return *this;
}
Razlomak &Razlomak::operator*=(const Razlomak &r){
    *this = *this * r;
    return *this;
}
Razlomak &Razlomak::operator+=(const Razlomak &r){
    *this = *this + r;
    return *this;
}
Razlomak &Razlomak::operator-=(const Razlomak &r){
    *this = *this - r;
    return *this;
}
Razlomak Razlomak::operator-()const{
    if(p == min()) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    return Razlomak(-p, q);
}
Razlomak Razlomak::form(long long int p1, long long int p2, long long int q1,
    long long int q2, long long int x, long long int y){
        long long int a, b;
        a = prod(p1/x,q2/y); b = prod(q1/y,p2/x);
        return Razlomak(a,b);
    }
Razlomak Razlomak::operator/(const Razlomak &r2)const{
    return form(this->p,r2.p,this->q,r2.q, nzd(this->p,r2.p),nzd(this->q,r2.q));
}
Razlomak Razlomak::operator*(const Razlomak &r2)const{
    return form(this->p,r2.q,this->q,r2.p, nzd(this->p,r2.q),nzd(r2.p,this->q));
}
Razlomak Razlomak::operator-(const Razlomak &r2)const{
    long long int a, b, c;
    a = prod(this->p, r2.q/nzd(this->q,r2.q));
    b = prod(r2.p, this->q/nzd(this->q,r2.q));
    c = prod(this->q, r2.q/nzd(this->q,r2.q));
    long long int brojnik(razlika(a,b));
    return Razlomak(brojnik,c);
}
Razlomak Razlomak::operator+(const Razlomak &r2)const{
    long long int a, b, c;
    a = prod(this->p, r2.q/nzd(this->q,r2.q));
    b = prod(r2.p, this->q/nzd(this->q,r2.q));
    c = prod(this->q, r2.q/nzd(this->q,r2.q));
    long long int brojnik(zbir(a,b));
    return Razlomak(brojnik,c);
}
Razlomak::Razlomak(long long int p, long long int q):p(p),q(q){
    if(q == 0) throw std::logic_error("Nekorektan razlomak");
    int znak = sgn(p) * sgn(q);
    q = std::abs(q);
    if(sgn(p) != znak){
        if(sgn(p) == -1) p = std::abs(p);
        else p *= znak;
    }
    skrati();
}
Razlomak::Razlomak(std::initializer_list<long long int> l){
    if(!l.size()) *this = Razlomak();
    else if(l.size() == 1) * this = Razlomak(*l.begin());
    else if(l.size() == 2) {
        auto it(l.begin()); it++;
        *this = Razlomak(*l.begin(), *it);
    }
    else throw std::domain_error("Razlomak nema tri ili vise param");
}
long long int Razlomak::nzd(long long int p, long long int q){
    if(q == 0) return p;
    return nzd(q,p%q);
}
void Razlomak::skrati(){
    for(long long int i = nzd(p,q);i > 1 || i < -1;i = nzd(p,q)){ p /= i; q /= i; }
}
int main () {
    Razlomak a(1,3);
    Razlomak b(1,3);
    auto x = a * b;
    std::cout << x.DajBrojnik() << " " << x.DajNazivnik();
    Razlomak c{1,2};
    a += b;
    a = a + b;
    a = a-b;
    a = a*b;
    a = a/b;
    a = -a;
    a = a;
    a += b;
    a += c;
    a*= b;
    a/=b;
    a-= b;
    a-=c;
    a++; ++a;
    a--; --a;
    if(a > b || a < b) std::cout << "Jabuke";
    if( a >= b || b <= a || a == b) std::cout << "kruske";
    std::cout << long(a);
    std::cout << a;
    std::cin >> a;
    std::cout << a;
	return 0;
}