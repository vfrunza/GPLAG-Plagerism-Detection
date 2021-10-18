/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <limits>
typedef long long int lint;
typedef long double ldouble;
typedef std::numeric_limits<long long int> limit;
class Razlomak{
    lint brojnik,nazivnik;
    static lint NZD(lint a,lint b);
    void Postavi();
    static bool m_overflow(lint a,lint b);
    static bool s_overflow(lint a,lint b);
    static bool o_overflow(lint a,lint b);
  public:
    Razlomak(lint b,lint n);
    Razlomak(lint b=0);
    lint DajBrojnik()const{return brojnik;}
    lint DajNazivnik()const{return nazivnik;}
    friend Razlomak operator+(const Razlomak&a){return a;}
    friend Razlomak operator-(Razlomak&a);
    friend Razlomak operator+(const Razlomak&a,const Razlomak&b);
    friend Razlomak operator-(const Razlomak&a,const Razlomak&b);
    friend Razlomak operator*(const Razlomak&a,const Razlomak&b);
    friend Razlomak operator/(const Razlomak&a,const Razlomak&b);
    friend Razlomak&operator+=(Razlomak&a,const Razlomak&b);
    friend Razlomak&operator-=(Razlomak&a,const Razlomak&b);
    friend Razlomak&operator*=(Razlomak&a,const Razlomak&b);
    friend Razlomak&operator/=(Razlomak&a,const Razlomak&b);
    friend Razlomak&operator++(Razlomak&a);
    friend Razlomak operator++(Razlomak&a,int);
    friend Razlomak&operator--(Razlomak&a);
    friend Razlomak operator--(Razlomak&a,int);
    friend std::ostream&operator<<(std::ostream&tok,const Razlomak&a);
    friend std::istream&operator>>(std::istream&tok,Razlomak&a);
    friend bool operator<(const Razlomak&a,const Razlomak&b);
    friend bool operator>(const Razlomak&a,const Razlomak&b);
    friend bool operator<=(const Razlomak&a,const Razlomak&b);
    friend bool operator>=(const Razlomak&a,const Razlomak&b);
    friend bool operator==(const Razlomak&a,const Razlomak&b);
    operator long double();
};
bool Razlomak::m_overflow(lint a,lint b){
    if((a>0 &&(a>limit::max()/b || a<limit::lowest()/b))||(a<0 && (b==limit::lowest() || -b>limit::max()/(-a) || -b<limit::lowest()/(-a)))) return true;
    return false;    
}
bool Razlomak::s_overflow(lint a,lint b){
    if((a>0 && b>limit::max()-a)||(a<0 && b<limit::lowest()-a))return true;
    return false;
}
bool Razlomak::o_overflow(lint a,lint b){
    if((a<0 && b>a-limit::lowest())||(a>0 && b<a-limit::max()))return true;
    return false;
}
void Razlomak::Postavi(){
    lint x(NZD(brojnik,nazivnik));
    brojnik/=x;
    nazivnik/=x;
    if(nazivnik<0){
        brojnik*=-1;
        nazivnik*=-1;
    }
}
lint Razlomak::NZD(lint a,lint b){
    if(b==0) return a;
    return NZD(b,a%b);
}
Razlomak::Razlomak(lint b,lint n){
    if(n==0)throw std::logic_error("Nekorektan razlomak");
    brojnik=b;nazivnik=n;
    Postavi();
}
Razlomak::Razlomak(lint b){
    brojnik=b;
    nazivnik=1;
}
Razlomak operator-(Razlomak&a){
    if(a.brojnik==std::numeric_limits<long long int>::lowest()) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    a.brojnik*=-1; 
    return a;
}
Razlomak operator+(const Razlomak&a,const Razlomak&b){
    lint x(Razlomak::NZD(a.nazivnik,b.nazivnik));
    if(Razlomak::m_overflow(a.brojnik,b.nazivnik/x)||Razlomak::m_overflow(b.brojnik,a.nazivnik/x)||
    Razlomak::m_overflow(a.nazivnik,b.nazivnik/x)||Razlomak::s_overflow(a.brojnik*(b.nazivnik/x),b.brojnik*(a.nazivnik/x)))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    Razlomak temp(a.brojnik*(b.nazivnik/x)+b.brojnik*(a.nazivnik/x),a.nazivnik*(b.nazivnik/x));
    temp.Postavi();
    return temp;
}
Razlomak operator-(const Razlomak&a,const Razlomak&b){
    lint x(Razlomak::NZD(a.nazivnik,b.nazivnik));
    if(Razlomak::m_overflow(a.brojnik,b.nazivnik/x)||Razlomak::m_overflow(b.brojnik,a.nazivnik/x)||
    Razlomak::m_overflow(a.nazivnik,b.nazivnik/x)||Razlomak::o_overflow(a.brojnik*(b.nazivnik/x),b.brojnik*(a.nazivnik/x)))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    Razlomak temp(a.brojnik*(b.nazivnik/x)-b.brojnik*(a.nazivnik/x),a.nazivnik*(b.nazivnik/x));
    temp.Postavi();
    return temp;
}
Razlomak operator*(const Razlomak&a,const Razlomak&b){
    lint x(Razlomak::NZD(a.brojnik,b.nazivnik));
    lint y(Razlomak::NZD(b.brojnik,a.nazivnik));
    if(Razlomak::m_overflow(a.brojnik/x,b.brojnik/y)||Razlomak::m_overflow(a.nazivnik/y,b.nazivnik/x))throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    Razlomak temp((a.brojnik/x)*(b.brojnik/y),(a.nazivnik/y)*(b.nazivnik/x));
    temp.Postavi();
    return temp;
}
Razlomak operator/(const Razlomak&a,const Razlomak&b){
    lint x(Razlomak::NZD(a.brojnik,b.brojnik));
    lint y(Razlomak::NZD(a.nazivnik,b.nazivnik));
    if(Razlomak::m_overflow(a.brojnik/x,b.nazivnik/y)||Razlomak::m_overflow(a.nazivnik/y,b.brojnik/x))throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    Razlomak temp((a.brojnik/x)*(b.nazivnik/y),(a.nazivnik/y)*(b.brojnik/x));
    temp.Postavi();
    return temp;
}
Razlomak&operator+=(Razlomak&a,const Razlomak&b){
    return a=a+b;
}
Razlomak&operator-=(Razlomak&a,const Razlomak&b){
    return a=a-b;
}
Razlomak&operator*=(Razlomak&a,const Razlomak&b){
    return a=a*b;
}
Razlomak&operator/=(Razlomak&a,const Razlomak&b){
    return a=a/b;
}
Razlomak&operator++(Razlomak&a){
    if(Razlomak::s_overflow(a.brojnik,a.nazivnik))throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    a.brojnik+=a.nazivnik;
    return a;
}
Razlomak operator++(Razlomak&a,int){
    auto temp(a);
    ++a;
    return temp;
}
Razlomak&operator--(Razlomak&a){
    if(Razlomak::o_overflow(a.brojnik,a.nazivnik))throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    a.brojnik-=a.nazivnik;
    return a;
}
Razlomak operator--(Razlomak&a,int){
    auto temp(a);
    --a;
    return temp;
}
std::ostream&operator<<(std::ostream&tok,const Razlomak&a){
    tok<<a.brojnik;
    if(a.nazivnik!=1)tok<<"/"<<a.nazivnik;
    return tok;
}
std::istream&operator>>(std::istream&tok,Razlomak&a){
    a.brojnik=0; a.nazivnik=1;
    char znak;
    tok>>a.brojnik;
    znak=tok.peek();
    if(!znak) tok.setstate(std::ios::failbit);
    else if(znak=='/'){
        tok>>znak>>std::ws>>a.nazivnik;
        if(tok.peek()!=' '&& tok.peek()!='\n' && tok.peek()!=0 && tok.peek()!='\r') tok.setstate(std::ios::failbit);
    }
    a.Postavi();
    return tok;
}
bool operator<(const Razlomak&a,const Razlomak&b){
    ldouble x((ldouble)a.brojnik/a.nazivnik),y((ldouble)b.brojnik/b.nazivnik);
    return x<y;
}
bool operator>(const Razlomak&a,const Razlomak&b){
    ldouble x((ldouble)a.brojnik/a.nazivnik),y((ldouble)b.brojnik/b.nazivnik);
    return x>y;
}
bool operator<=(const Razlomak&a,const Razlomak&b){
    ldouble x((ldouble)a.brojnik/a.nazivnik),y((ldouble)b.brojnik/b.nazivnik);
    return x<=y;
}
bool operator>=(const Razlomak&a,const Razlomak&b){
    ldouble x((ldouble)a.brojnik/a.nazivnik),y((ldouble)b.brojnik/b.nazivnik);
    return x>=y;
}
bool operator==(const Razlomak&a,const Razlomak&b){
    ldouble x((ldouble)a.brojnik/a.nazivnik),y((ldouble)b.brojnik/b.nazivnik);
    return x==y;
}
Razlomak::operator long double(){
    return static_cast<long double>(brojnik)/nazivnik;
}
int main (){
    try{
    std::cout<<"blabla\n";
    Razlomak a(-1,2);
    Razlomak b(-4611627387903);
    a+=b;
    std::cin>>a>>b;
    std::cout<<a<<" "<<b<<std::endl;
    }catch(std::overflow_error x){std::cout<<x.what();}
	return 0;
}