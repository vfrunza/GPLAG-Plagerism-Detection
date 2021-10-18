/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <climits>
#include <cmath>
#define eps 1E-18
#define M LLONG_MAX
#define m LLONG_MIN

using namespace std;

class Razlomak {
    long long int brojnik,nazivnik;
    static long long int NZD(long long int p, long long int q) {p=abs(p);  long long int p1; while(1) { p1=p%q; p=q; q=p1; if(q==0) break; } return p; }
    static bool Isti(long double p, long double d) { if( fabs(p-d)<=eps*(fabs(p)+ fabs(d))) return true; else return false; }
    static bool t_s(long long int x, long long int y)   { if(y>0) { if(x>M-y) return true; return false; } else { if(x<m-y) return true; return false; } }
    static bool t_o(long long int x, long long int y)   { y=-y; if(y>0) { if(x>M-y) return true; return false; } else { if(x<m-y) return true; return false; } }
    static bool t_m(long long int x, long long int y)   { if(y>0) { if(x<m/y || x>M/y) return true; return false; } else { if(x==m || -x>M/(-y) || -x<m/(-y)) return true; return false; } }
   
    public:
    Razlomak(long long int b=0,long long int n=1);
    Razlomak(initializer_list<long long int>  b_n);
    long long int DajBrojnik() const { return brojnik; };
    long long int DajNazivnik() const { return nazivnik; };
    friend Razlomak operator +(Razlomak r1, const Razlomak &r2);
    friend Razlomak operator -(Razlomak r1, const Razlomak &r2);
    friend Razlomak operator *(Razlomak r1, const Razlomak &r2);
    friend Razlomak operator /(Razlomak r1, const Razlomak &r2);
    friend Razlomak operator +(const Razlomak &r1);
    friend Razlomak operator -(Razlomak &r1);
    friend Razlomak &operator +=(Razlomak &r1, const Razlomak &r2);
    friend Razlomak &operator -=(Razlomak &r1, const Razlomak &r2);
    friend Razlomak &operator *=(Razlomak &r1, const Razlomak &r2);
    friend Razlomak &operator /=(Razlomak &r1, const Razlomak &r2);
    friend Razlomak &operator ++(Razlomak &r1);
    friend Razlomak &operator --(Razlomak &r1);
    friend Razlomak operator ++(Razlomak &r1, int);
    friend Razlomak operator --(Razlomak &r1, int);
    friend bool operator <(const Razlomak &r1, const Razlomak &r2);
    friend bool operator >(const Razlomak &r1, const Razlomak &r2);
    friend bool operator <=(const Razlomak &r1, const Razlomak &r2);
    friend bool operator >=(const Razlomak &r1, const Razlomak &r2);
    friend bool operator ==(const Razlomak &r1, const Razlomak &r2);
    friend bool operator !=(const Razlomak &r1, const Razlomak &r2);
    friend ostream &operator <<(ostream &tok, const Razlomak &r1);
    friend istream &operator >>(istream &tok,Razlomak &r1);
    explicit operator long double() const { return (double)brojnik/nazivnik; }
    
    
};

    Razlomak::Razlomak(long long int b, long long int n) {
        if(n<0) { n*=(-1); b*=(-1); }
        
        if(n==0) throw logic_error ("Nekorektan razlomak");
        int nzd=NZD(b,n);
        b/=nzd;
        n/=nzd;
        brojnik=b; nazivnik=n;
    }
    Razlomak::Razlomak(initializer_list<long long int>  b_n) {
        if(b_n.size()==1) { 
            auto it=b_n.begin();
            brojnik=*it;
            nazivnik=1;
        }
        else{
            auto it=b_n.begin();
            auto it2=it; it2++;
            int nzd=NZD(*it,*it2);
            brojnik=*it/nzd;
            nazivnik=*it2/nzd;
        }
    }
    Razlomak operator +(Razlomak r1, const Razlomak &r2) {
        r1+=r2;
        Razlomak r3(r1.brojnik,r1.nazivnik);
        return r3;
    }            
    Razlomak operator -(Razlomak r1, const Razlomak &r2) {
        r1-=r2;
        Razlomak r3(r1.brojnik,r1.nazivnik);
        return r3;
    }
    Razlomak operator *(Razlomak r1, const Razlomak &r2) {
        r1*=r2;
        Razlomak r3(r1.brojnik,r1.nazivnik);
        
        return r3;
    }
    Razlomak operator /(Razlomak r1, const Razlomak &r2) {
        r1/=r2;
        Razlomak r3(r1.brojnik,r1.nazivnik);
        return r3;
    }
    Razlomak operator +(const Razlomak &r1) {
        return r1;
    }
    Razlomak operator -(Razlomak &r1) {
        if(r1.brojnik==m) throw overflow_error ("Nemoguce dobiti tacan rezultat");
        r1.brojnik=-r1.brojnik;
        return r1;
    }
    Razlomak &operator +=(Razlomak &r1, const Razlomak &r2) {
        Razlomak pom(r1);
        int r=Razlomak::NZD(r1.DajNazivnik(),r2.DajNazivnik());
        if(Razlomak::t_m(pom.brojnik, r2.nazivnik/r) || Razlomak::t_m(r2.brojnik, pom.nazivnik/r) || Razlomak::t_m(pom.nazivnik, r2.nazivnik/r) || Razlomak::t_s(pom.brojnik*(r2.nazivnik/r), r2.brojnik*(pom.nazivnik/r))) throw overflow_error ("Nemoguce dobiti tacan rezultat");
        r1.brojnik=pom.brojnik*(r2.nazivnik/r) + r2.brojnik*(pom.nazivnik/r);
        r1.nazivnik=pom.nazivnik*(r2.nazivnik/r);
        return r1;
    }
    Razlomak &operator -=(Razlomak &r1, const Razlomak &r2) {
        Razlomak pom(r1);
        int r=Razlomak::NZD(r1.nazivnik,r2.nazivnik);
        if(Razlomak::t_m(pom.brojnik, r2.nazivnik/r) || Razlomak::t_m(r2.brojnik, pom.nazivnik/r) || Razlomak::t_m(pom.nazivnik, r2.nazivnik/r) || Razlomak::t_o(pom.brojnik*(r2.nazivnik/r), r2.brojnik*(pom.nazivnik/r))) throw overflow_error ("Nemoguce dobiti tacan rezultat");
        r1.brojnik=pom.brojnik*(r2.nazivnik/r) - r2.brojnik*(pom.nazivnik/r);
        r1.nazivnik=pom.nazivnik*(r2.nazivnik/r);
        return r1;
    }
    Razlomak &operator *=(Razlomak &r1, const Razlomak &r2) {
        int s=Razlomak::NZD(r1.brojnik,r2.nazivnik);
        int t=Razlomak::NZD(r2.brojnik,r1.nazivnik);
        Razlomak pom(r1);
        if(Razlomak::t_m(pom.brojnik/s, r2.brojnik/t) || Razlomak::t_m(pom.nazivnik/t, r2.nazivnik/s)) throw overflow_error ("Nemoguce dobiti tacan rezultat");
        r1.brojnik=(pom.brojnik/s)*(r2.brojnik/t);
        r1.nazivnik=(pom.nazivnik/t)*(r2.nazivnik/s);
        return r1;
    }
    Razlomak &operator /=(Razlomak &r1, const Razlomak &r2) {
        int r=Razlomak::NZD(r1.nazivnik,r2.nazivnik);
        int u=Razlomak::NZD(r1.brojnik,r2.brojnik);
        Razlomak pom(r1);
        if(Razlomak::t_m(pom.brojnik/u, r2.nazivnik/r) || Razlomak::t_m(pom.nazivnik/r, r2.brojnik/u)) throw overflow_error ("Nemoguce dobiti tacan rezultat");
        r1.brojnik=(pom.brojnik/u)*(r2.nazivnik/r);
        r1.nazivnik=(pom.nazivnik/r)*(r2.brojnik/u);
        return r1;
    }
    Razlomak &operator ++(Razlomak &r1) {
        Razlomak jedan(1);
        return r1+=jedan;
    }
    Razlomak &operator --(Razlomak &r1) {
        Razlomak jedan(1);
        return r1-=jedan;
    }
    Razlomak operator ++(Razlomak &r1, int) {
        Razlomak jedan(1);
        Razlomak pom(r1.brojnik,r1.nazivnik);
        r1+=jedan;
        return pom;
    }
    Razlomak operator --(Razlomak &r1, int) {
        Razlomak jedan(1);
        Razlomak pom(r1.brojnik,r1.nazivnik);
        r1-=jedan;
        return pom;
    }
    bool operator <(const Razlomak &r1, const Razlomak &r2) {
        long double prvi=(double)r1.brojnik/r1.nazivnik;
        long double drugi=(double)r2.brojnik/r2.nazivnik;
        return prvi<drugi;
    }
    bool operator >(const Razlomak &r1, const Razlomak &r2) {
        long double prvi=(double)r1.brojnik/r1.nazivnik;
        long double drugi=(double)r2.brojnik/r2.nazivnik;
        return prvi>drugi;
    }
    bool operator <=(const Razlomak &r1, const Razlomak &r2) {
        long double prvi=(double)r1.brojnik/r1.nazivnik;
        long double drugi=(double)r2.brojnik/r2.nazivnik;
        if(prvi<drugi || Razlomak::Isti(prvi,drugi)) return true;
        else return false;
    }
    bool operator >=(const Razlomak &r1, const Razlomak &r2) {
        long double prvi=(double)r1.brojnik/r1.nazivnik;
        long double drugi=(double)r2.brojnik/r2.nazivnik;
        if(prvi>drugi || Razlomak::Isti(prvi,drugi)) return true;
        else return false;
    }
    bool operator ==(const Razlomak &r1, const Razlomak &r2) {
        long double prvi=(double)r1.brojnik/r1.nazivnik;
        long double drugi=(double)r2.brojnik/r2.nazivnik;
        return Razlomak::Isti(prvi,drugi);
    }
    bool operator !=(const Razlomak &r1, const Razlomak &r2) {
        long double prvi=(double)r1.brojnik/r1.nazivnik;
        long double drugi=(double)r2.brojnik/r2.nazivnik;
        return !Razlomak::Isti(prvi,drugi);
    }
    ostream &operator <<(ostream &tok, const Razlomak &r1) {
        if(r1.nazivnik==1) tok<<r1.brojnik;
        else tok<<r1.brojnik<<"/"<<r1.nazivnik;
        return tok;
    }
    istream &operator >>(istream &tok,Razlomak &r1) {
        char znak;
        tok>>std::ws;
        tok>>r1.brojnik;
        if(tok.peek()!= '/') { r1.nazivnik=1; return tok; }
        else {
            tok>>znak>>r1.nazivnik;
        }
        if(tok.peek()!=' ' && tok.peek()!='\t' && tok.peek()!='\n' && tok.peek()!='\v' && tok.peek()!='\f') tok.setstate(std::ios::failbit);
        int nzd=Razlomak::NZD(r1.brojnik,r1.nazivnik);
        r1.brojnik/=nzd;
        r1.nazivnik/=nzd;
        
       
        return tok;
    }

   
int main ()
{
    Razlomak r (127,17), t (57,11);
    cout<<"Zbir 127/17 i 57/11 je: "<< r + t <<endl;
    cout<<"Razlika 127/17 i 57/11 je: "<< r - t <<endl;
    cout<<"Proizvod 127/17 i 57/11 je: "<< r * t <<endl;
    cout<<"Kolicnik 127/17 i 57/11 je: "<< r / t <<endl;
    cout<<"Prefiksno inkrementirani daju sljedece razlomke: "<< ++r <<" "<<++t<<endl;
    cout<<"Postfiksno dekrementirani daju: "<<r-- <<" "<<t--<< " a oni su sada: "<<r<<" "<<t<<endl;
    t+=r;
    t-=r;
    t*=r;
    t/=r;
    cout<<"Nakon izvodjenja operatora += , -= , *= i /= razlomci su: "<<r<<" "<<t<<endl;
	return 0;
}