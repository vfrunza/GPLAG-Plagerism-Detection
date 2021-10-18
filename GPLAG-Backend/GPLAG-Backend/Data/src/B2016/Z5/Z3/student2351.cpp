/B16/17 (Zadaća 5, Zadatak 3)
#include <stdexcept>
#include <iostream>

class Razlomak {
    long long int brojnik, nazivnik;
    
    static int EuklidovAlgoritam (int a, int b) {
        if (b==0) return a;
        a%=b;
        return EuklidovAlgoritam(b,a);
    }
    public:
    Razlomak (long long int b=0, long long int n=1) { brojnik=b; nazivnik=n; 
        if (EuklidovAlgoritam(b,n)==0) std::logic_error ("Nekorektan razlomak");
        long long int skracivanje = EuklidovAlgoritam(abs(brojnik), abs(nazivnik));
        brojnik/=skracivanje;
        nazivnik/=skracivanje;
    }
    int DajBrojnik () const { return brojnik; }
    int DajNazivnik () const { return nazivnik; }
    friend std::ostream &operator <<(std::ostream &tok, const Razlomak &r);
    friend std::istream &operator >>(std::istream &tok, Razlomak &r);
    friend Razlomak operator +(const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator -(const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator *(const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator /(const Razlomak &r1, const Razlomak &r2);
     operator long double() const;
    
};



Razlomak operator +(const Razlomak &r1, const Razlomak &r2) {
    int r = Razlomak::EuklidovAlgoritam(r1.nazivnik, r2.nazivnik);
    return Razlomak ((r1.brojnik*(r2.nazivnik/r) + r2.brojnik*(r1.nazivnik/r)) , (r1.nazivnik*(r2.nazivnik/r)));
}
Razlomak operator -(const Razlomak &r1, const Razlomak &r2) {
    int r = Razlomak::EuklidovAlgoritam(r1.nazivnik, r2.nazivnik);
    return Razlomak ((r1.brojnik*(r2.nazivnik/r) - r2.brojnik*(r1.nazivnik/r)), (r1.nazivnik*(r2.nazivnik/r)));
}

Razlomak operator *(const Razlomak &r1, const Razlomak &r2) {
    int t = Razlomak::EuklidovAlgoritam(r2.brojnik, r1.nazivnik);
    int s = Razlomak::EuklidovAlgoritam(r1.brojnik, r2.nazivnik);
    return Razlomak (((r1.brojnik/s)*(r2.brojnik/t)), ((r1.nazivnik/t)*(r2.nazivnik/s)));
}

Razlomak operator /(const Razlomak &r1, const Razlomak &r2) {
    int u = Razlomak::EuklidovAlgoritam(r1.brojnik, r2.brojnik);
    int r = Razlomak::EuklidovAlgoritam(r1.nazivnik, r2.nazivnik);
    return Razlomak (((r1.brojnik/u)*(r2.nazivnik/r)), ((r1.nazivnik/r)*(r2.brojnik/u)));
}

Razlomak::operator long double() const {
    return(long double)brojnik/nazivnik; }


std::ostream &operator <<(std::ostream &tok, const Razlomak &r) {
    if (r.nazivnik == 1) {
        return tok << r.brojnik;
    }
    else { return tok << r.brojnik << "/" << r.nazivnik; }
}
std::istream &operator >>(std::istream &tok, Razlomak &r) {
    int br1;
    int peek;
    int m=0;
    int naz1=1;
    bool a=false;
    
    
    tok >> br1;
    if (naz1) { m=br1; a=true; }
    
    if (tok.peek()=='\r') {
        tok.ignore();
        m=br1;
        tok >> naz1;
        a=true;
    }
    
    if (tok.peek()=='/') {
        tok.ignore();
        tok >> naz1;
        peek=tok.peek();
        a=true;
    }
    if (tok.peek() !=' ') {
        tok.setstate(std::ios::failbit);
    }
    if (tok || a) {
        if (naz1==0) naz1=1;
        r = Razlomak(br1,naz1);
    }
    
    return tok;
    
}








int main ()
{
    Razlomak r(5,10);
    
	return 0;
}