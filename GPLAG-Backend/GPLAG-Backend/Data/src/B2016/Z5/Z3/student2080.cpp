/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <initializer_list>
#include <limits>

class Razlomak{
    long long int brojnik, nazivnik;
    static long long int NZD(long long int p, long long int q){
        while(q!=0){
            int pom(p);
            p=q;
            q=pom%q;
        }
        return p;
    }
    public:
    Razlomak(long long int a, long long int b){
        if(b==0)throw std::logic_error("Nekorektan razlomak");
        if(a<0 && b<0){ a*=-1; b*=-1; }
        else if(a>0 && b<0){ a*=-1; b*=-1; }
        brojnik=a/NZD(a,b);
        nazivnik=b/NZD(a,b);
    }
    Razlomak(std::initializer_list<long long int> lista){
        auto it(lista.begin());
        if(lista.size()==0){
            brojnik=0; nazivnik=1;
        }
        else if(lista.size()==1){
           brojnik=*it;
           nazivnik=1;
        }
        else if(lista.size()==2){
            long long int a,b;
            a=*it;
            it++;
            b=*it;
            if(b==0)throw std::logic_error("Nekorektan razlomak");
            if(a<0 && b<0){ a*=-1; b*=-1; }
            else if(a>0 && b<0){ a*=-1; b*=-1; }
            brojnik=a/NZD(a,b);
            nazivnik=b/NZD(a,b);
        }
    }
    Razlomak(long long int a){
        brojnik=a;
        nazivnik=1;
    }
    Razlomak(){
        brojnik=0;
        nazivnik=1;
    }
    operator long double() const{
        long double rez(static_cast<long double>(brojnik)/nazivnik);
        return rez;
    }
    long long int DajBrojnik() const { return brojnik; }
    long long int DajNazivnik() const { return nazivnik; }
    Razlomak operator +(){
        return *this;
    }
    Razlomak operator -(){
        this->brojnik*=-1;
        return *this;
    }
    Razlomak operator ++(int){
        Razlomak pomocna(*this);
        brojnik=brojnik+nazivnik;
        return pomocna;
    }
    Razlomak &operator ++(){
        brojnik=brojnik+nazivnik;
        return *this;
    }
    Razlomak operator --(int){
        Razlomak pomocna(*this);
        brojnik=brojnik-nazivnik;
        return pomocna;
    }
    Razlomak &operator --(){
        brojnik=brojnik-nazivnik;
        return *this;
    }
    
    bool operator <(const Razlomak &p){
        long double rezultat1,rezultat2;
        rezultat1=static_cast<long double>(brojnik)/nazivnik;
        rezultat2=static_cast<long double>(p.brojnik)/p.nazivnik;
        return rezultat1<rezultat2;
    }
    bool operator >(const Razlomak &p){
        long double rezultat1,rezultat2;
        rezultat1=static_cast<long double>(brojnik)/nazivnik;
        rezultat2=static_cast<long double>(p.brojnik)/p.nazivnik;
        return rezultat1>rezultat2;
    }
    bool operator <=(const Razlomak &p){
        long double rezultat1,rezultat2;
        rezultat1=static_cast<long double>(brojnik)/nazivnik;
        rezultat2=static_cast<long double>(p.brojnik)/p.nazivnik;
        return rezultat1<=rezultat2;
    }
    bool operator >=(const Razlomak &p){
        long double rezultat1,rezultat2;
        rezultat1=static_cast<long double>(brojnik)/nazivnik;
        rezultat2=static_cast<long double>(p.brojnik)/p.nazivnik;
        return rezultat1>=rezultat2;
    }
    bool operator ==(const Razlomak &p){
        long double rezultat1,rezultat2;
        rezultat1=static_cast<long double>(brojnik)/nazivnik;
        rezultat2=static_cast<long double>(p.brojnik)/p.nazivnik;
        return rezultat1==rezultat2;  // poredjenje popraviti
    }
    friend Razlomak operator +(const Razlomak &p, const Razlomak &q);
    friend Razlomak operator -(const Razlomak &p, const Razlomak &q);
    friend Razlomak operator *(const Razlomak &p, const Razlomak &q);
    friend Razlomak operator /(const Razlomak &p, const Razlomak &q);
    friend Razlomak &operator +=(Razlomak &p, const Razlomak &q);
    friend Razlomak &operator -=(Razlomak &p, const Razlomak &q);
    friend Razlomak &operator *=(Razlomak &p, const Razlomak &q);
    friend Razlomak &operator /=(Razlomak &p, const Razlomak &q);
    friend std::ostream &operator <<(std::ostream &tok, const Razlomak &p);
    friend std::istream &operator >>(std::istream &tok, Razlomak &p);
};

long long int DajMax(){
    return std::numeric_limits<long long int>::max();
}

long long int DajMin(){
    return std::numeric_limits<long long int>::min();
}

void TestPrekoracenjaSabiranje(long long int x, long long int y){
    if((y>0 && x>DajMax()-y) || (y<0 && x<DajMin()-y))throw std::overflow_error("Nemoguce dobiti tacan rezultat");
}

void TestPrekoracenjaOduzimanje(long long int x, long long int y){
    if((y>0 && x<DajMin()+y) || (y<0 && x>DajMax()+y))throw std::overflow_error("Nemoguce dobiti tacan rezultat");
}

void TestPrekoracenjaMnozenje(long long int x, long long int y){
    if((y>0 && (x<DajMin()/y || x>DajMax()/y)) || (y<0 && (x==DajMin() || -x<DajMin()/(-y) || -x>DajMax()/(-y))))throw std::overflow_error
    ("Nemoguce dobiti tacan rezultat");
}

long long int NZD(long long int p, long long int q){
    while(q!=0){
        int pom(p);
        p=q;
        q=pom%q;
    }
    return p;
}
Razlomak operator +(const Razlomak &p, const Razlomak &q){
    long long int pomocna_brojnik,pomocna_nazivnik;
    long long int r(NZD(q.brojnik,q.nazivnik));
    long long int a,b;
    a=p.brojnik*(q.nazivnik/r);
    b=p.nazivnik*(q.brojnik/r);
    TestPrekoracenjaSabiranje(a,b);
    pomocna_brojnik=a+b;
    TestPrekoracenjaMnozenje(p.nazivnik,q.nazivnik/r);
    pomocna_nazivnik=p.nazivnik*(q.nazivnik/r);
    Razlomak rezultat(pomocna_brojnik,pomocna_nazivnik);
    return rezultat;
}
Razlomak &operator +=(Razlomak &p, const Razlomak &q){
    long long int pomocna_brojnik,pomocna_nazivnik;
    long long int r(NZD(p.nazivnik,q.nazivnik));
    long long int a,b;
    a=p.brojnik*(q.nazivnik/r);
    b=p.nazivnik*(q.brojnik/r);
    TestPrekoracenjaSabiranje(a,b);
    pomocna_brojnik=a+b;
    TestPrekoracenjaMnozenje(p.nazivnik,q.nazivnik/r);
    pomocna_nazivnik=p.nazivnik*(q.nazivnik/r);
    Razlomak rezultat(pomocna_brojnik,pomocna_nazivnik);
    p.brojnik=rezultat.brojnik;
    p.nazivnik=rezultat.nazivnik;
    return p;
}
Razlomak operator -(const Razlomak &p, const Razlomak &q){
    long long int pomocna_brojnik,pomocna_nazivnik;
    long long int r(NZD(p.nazivnik,q.nazivnik));
    TestPrekoracenjaMnozenje(p.brojnik,q.nazivnik/r);
    TestPrekoracenjaMnozenje(p.nazivnik,q.brojnik/r);
    TestPrekoracenjaOduzimanje(p.brojnik*(q.nazivnik/r),p.nazivnik*(q.brojnik/r));
    pomocna_brojnik=p.brojnik*(q.nazivnik/r)-p.nazivnik*(q.brojnik/r);
    TestPrekoracenjaMnozenje(q.nazivnik,q.nazivnik/r);
    pomocna_nazivnik=p.nazivnik*(q.nazivnik/r);
    Razlomak rezultat(pomocna_brojnik,pomocna_nazivnik);
    return rezultat;
}
Razlomak &operator -=(Razlomak &p, const Razlomak &q){
    long long int pomocna_brojnik,pomocna_nazivnik;
     long long int r(NZD(p.nazivnik,q.nazivnik));
     TestPrekoracenjaMnozenje(p.brojnik,q.nazivnik/r);
     TestPrekoracenjaMnozenje(p.nazivnik,q.brojnik/r);
     TestPrekoracenjaOduzimanje(p.brojnik*(q.nazivnik/r),p.nazivnik*(q.brojnik/r));
     pomocna_brojnik=p.brojnik*(q.nazivnik/r)-p.nazivnik*(q.brojnik/r);
     TestPrekoracenjaMnozenje(p.nazivnik,q.nazivnik/r);
     pomocna_nazivnik=p.nazivnik*(q.nazivnik/r);
     Razlomak rezultat(pomocna_brojnik,pomocna_nazivnik);
     p.brojnik=rezultat.brojnik;
     p.nazivnik=rezultat.nazivnik;
     return p;
}
Razlomak operator *(const Razlomak &p, const Razlomak &q){
    long long int pomocna_brojnik,pomocna_nazivnik;
    long long int t(NZD(q.brojnik,p.nazivnik));
    long long int s(NZD(p.brojnik,q.nazivnik));
    TestPrekoracenjaMnozenje(p.brojnik/s,q.brojnik/t);
    pomocna_brojnik=(p.brojnik/s)*(q.brojnik/t);
    TestPrekoracenjaMnozenje(p.nazivnik/t,q.nazivnik/s);
    pomocna_nazivnik=(p.nazivnik/t)*(q.nazivnik/s);
    Razlomak rezultat(pomocna_brojnik,pomocna_nazivnik);
    return rezultat;
}
Razlomak &operator *=(Razlomak &p, const Razlomak &q){
    long long int pomocna_brojnik,pomocna_nazivnik;
    long long int s(NZD(p.brojnik,q.nazivnik));
    long long int t(NZD(q.brojnik,p.nazivnik));
    TestPrekoracenjaMnozenje(p.brojnik/s,q.brojnik/t);
    pomocna_brojnik=(p.brojnik/s)*(q.brojnik/t);
    TestPrekoracenjaMnozenje(p.nazivnik/t,q.nazivnik/s);
    pomocna_nazivnik=(p.nazivnik/t)*(q.nazivnik/s);
    Razlomak rezultat(pomocna_brojnik,pomocna_nazivnik);
    p.brojnik=rezultat.brojnik;
    p.nazivnik=rezultat.nazivnik;
    return p;
}
Razlomak operator /(const Razlomak &p, const Razlomak &q){
    long long int pomocna_brojnik,pomocna_nazivnik;
    long long int u(NZD(p.brojnik,q.brojnik));
    long long int r(NZD(p.nazivnik,q.nazivnik));
    TestPrekoracenjaMnozenje(p.brojnik/u,q.nazivnik/r);
    TestPrekoracenjaMnozenje(p.nazivnik/r,q.brojnik/u);
    pomocna_brojnik=(p.brojnik/u)*(q.nazivnik/r);
    pomocna_nazivnik=(p.nazivnik/r)*(q.brojnik/u);
    Razlomak rezultat(pomocna_brojnik,pomocna_nazivnik);
    return rezultat;
}
Razlomak &operator /=(Razlomak &p, const Razlomak &q){
    long long int pomocna_brojnik,pomocna_nazivnik;
    long long int u(NZD(p.brojnik,q.brojnik));
    long long int r(NZD(p.nazivnik,q.nazivnik));
    TestPrekoracenjaMnozenje(p.brojnik/u,q.nazivnik/r);
    TestPrekoracenjaMnozenje(p.nazivnik/r,q.brojnik/u);
    pomocna_brojnik=(p.brojnik/u)*(q.nazivnik/r);
    pomocna_nazivnik=(p.nazivnik/r)*(q.brojnik/u);
    Razlomak rezultat(pomocna_brojnik,pomocna_nazivnik);
    p.brojnik=rezultat.brojnik;
    p.nazivnik=rezultat.nazivnik;
    return p;
}
std::ostream &operator <<(std::ostream &tok, const Razlomak &p){
    if(p.nazivnik==1)tok << p.brojnik;
    else tok<<p.brojnik<< "/" <<p.nazivnik;
    return tok;
}
std::istream &operator >>(std::istream &tok, Razlomak &p){
    char znak;
    long long int br,naz;
    tok>>br;
    if(std::cin.peek()=='\n' || std::cin.peek()==' '){
        Razlomak r(br);
        p.brojnik=r.brojnik;
        p.nazivnik=r.nazivnik;
        return tok;
    }
    tok>>znak;
    if(znak=='/'){
        tok>>naz;
        if(std::cin.peek()=='\n'){
            Razlomak r(br,naz);
            p.brojnik=r.brojnik;
            p.nazivnik=r.nazivnik;
            return tok;
        }
        std::cin.clear(); std::cin.ignore(1000,'\n');
    }
    Razlomak r(br,naz);
    p.brojnik=r.brojnik;
    p.nazivnik=r.nazivnik;
    return tok;
}
int main (){
    try{
        Razlomak r;
        std::cin>>r;
        std::cout<<double(r) << std::endl;
        Razlomak a{1,2};
        Razlomak b;
        b=r+a;
        std::cout << "Rezultat: " << b << std::endl;
        b+=b;
        std::cout << "Sada: " << b << std::endl;
        a=b*r;
        std::cout << "Sada: " << a << std::endl;
        a++;
        b--;
        std::cout << a << " i " << b << std::endl;
        Razlomak c(-2,-3);
        c/=b;
        c-=a;
        c=b/r;
        std::cout << "Rezultat: " << c << std::endl;
        Razlomak g(1);
        std::cout << g;
    }
    catch(std::overflow_error iz){
        std::cout<<iz.what();
    }
    catch(std::logic_error iz){
        std::cout<<iz.what();
    }
	return 0;
}