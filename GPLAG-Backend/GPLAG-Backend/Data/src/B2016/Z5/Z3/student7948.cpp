/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <limits>
using namespace std;

class Razlomak {
        long long int brojnik, nazivnik;
        static long long int NZD(long long int p, long long int q) {
            long long int nzd(0), temp;
            while(1) {
                temp=p;
                p=q;
                q=temp%q;
                if(q==0) {
                    nzd=p;
                    break;
                }
            }
            return nzd;
        }
        static bool PrekoracnjeSabiranje(long long int x, long long int y) {
            long long int M(numeric_limits<long long int>::max()), m;
            m=-M-1;
            if(y>0) {
                if(x>M-y) return true;
            }
            else if(y<0) {
                if(x<m-y) return true;
            }
            return false;
        }
        static bool PrekoracnjeOduzimanje(long long int x, long long int y) {
            long long int M(numeric_limits<long long int>::max()), m;
            m=-M-1;
            if(y>0) {
                if(x<m+y) return true;
            }
            else if(y<0) {
                if(x>M+y) return true;
            }
            return false;
        }
        static bool PrekoracnjeMnozenje(long long int x, long long int y) {
            long long int M(numeric_limits<long long int>::max()), m;
            m=-M-1;
            if(y>0) {
                if(x<m/y) return true;
                else if(x>M/y) return true;
            }
            if(y<0) {
                if(x==m) return true;
                else if(-x>M/(-y)) return true;
                else if(-x<m/(-y)) return true;
            }
            return false;
        }
    public:
        Razlomak(long long int br, long long int nz);
        Razlomak(long long int br);
        Razlomak();
        long long int DajBrojnik() const {
            return brojnik;
        }
        long long int DajNazivnik() const {
            return nazivnik;
        }
        friend Razlomak operator +(const Razlomak &prvi, const Razlomak &drugi);
        friend Razlomak operator -(const Razlomak &prvi, const Razlomak &drugi);
        friend Razlomak operator *(const Razlomak &prvi, const Razlomak &drugi);
        friend Razlomak operator /(const Razlomak &prvi, const Razlomak &drugi);
        friend Razlomak operator +(const Razlomak &raz);
        friend Razlomak operator -(const Razlomak &raz);
        friend Razlomak operator +=(Razlomak &prvi, const Razlomak &drugi);
        friend Razlomak operator -=(Razlomak &prvi, const Razlomak &drugi);
        friend Razlomak operator *=(Razlomak &prvi, const Razlomak &drugi);
        friend Razlomak operator /=(Razlomak &prvi, const Razlomak &drugi);
        Razlomak &operator ++() {
            Razlomak jedinica(1);
            *this = *this + jedinica;
 			*this=Razlomak(this->brojnik, this->nazivnik);
            return *this;
        }
        Razlomak &operator --() {
            Razlomak jedinica(1);
            *this = *this - jedinica;
 			*this=Razlomak(this->brojnik, this->nazivnik);
            return *this;
        }
        Razlomak operator ++(int) {
            Razlomak stari(*this), jedinica(1);
            *this = *this + jedinica;
            *this=Razlomak(this->brojnik, this->nazivnik);
            return stari;
        }
        Razlomak operator --(int) {
            Razlomak stari(*this), jedinica(1);
            *this = *this - jedinica;
            *this=Razlomak(this->brojnik, this->nazivnik);
            return stari;
        }
        friend bool operator ==(const Razlomak &prvi, const Razlomak &drugi);
        friend bool operator !=(const Razlomak &prvi, const Razlomak &drugi);
        friend bool operator <(const Razlomak &prvi, const Razlomak &drugi);
        friend bool operator >(const Razlomak &prvi, const Razlomak &drugi);
        friend bool operator <=(const Razlomak &prvi, const Razlomak &drugi);
        friend bool operator >=(const Razlomak &prvi, const Razlomak &drugi);
        friend ostream &operator <<(ostream &tok, const Razlomak &raz);
        friend istream &operator >>(istream &tok, Razlomak &raz);
        operator long double() const;
};

    Razlomak::Razlomak(long long int br, long long int nz) {
        if(nz==0) throw logic_error("Nekorektan razlomak");
        auto nzd(NZD(br,nz));
        br=br/nzd; nz=nz/nzd;
        if(nz<0) {
            nz=-nz;
            br=-br;
        }
        brojnik=br; nazivnik=nz;
    }
    Razlomak::Razlomak(long long int br) {
        brojnik=br; nazivnik=1;
    }
    Razlomak::Razlomak() {
        brojnik=0; nazivnik=1;
    }
    
    Razlomak operator +(const Razlomak &prvi, const Razlomak &drugi) {
        long long int r(Razlomak::NZD(prvi.DajNazivnik(),drugi.DajNazivnik()));
        if(Razlomak::PrekoracnjeMnozenje(prvi.DajBrojnik(),(drugi.DajNazivnik()/r))==true ||
            Razlomak::PrekoracnjeMnozenje(drugi.DajBrojnik(),drugi.DajBrojnik())==true ||
            Razlomak::PrekoracnjeMnozenje(prvi.DajNazivnik(),(drugi.DajNazivnik()/r))==true ||
            Razlomak::PrekoracnjeSabiranje(prvi.DajBrojnik()*(drugi.DajNazivnik()/r),drugi.DajBrojnik()*drugi.DajBrojnik())==true)
                throw overflow_error("Nemoguce dobiti tacan rezultat");
        Razlomak novi;
        
        novi.brojnik = prvi.DajBrojnik()*(drugi.DajNazivnik()/r) + drugi.DajBrojnik()*(prvi.DajNazivnik()/r);
        novi.nazivnik = prvi.DajNazivnik()*(drugi.DajNazivnik()/r);
        novi=Razlomak(novi.brojnik, novi.nazivnik);
        return novi;
    }
    Razlomak operator -(const Razlomak &prvi, const Razlomak &drugi) {
        long long int r(Razlomak::NZD(prvi.DajNazivnik(),drugi.DajNazivnik()));
        if(Razlomak::PrekoracnjeMnozenje(prvi.DajBrojnik(),(drugi.DajNazivnik()/r))==true ||
            Razlomak::PrekoracnjeMnozenje(drugi.DajBrojnik(),drugi.DajBrojnik())==true ||
            Razlomak::PrekoracnjeMnozenje(prvi.DajNazivnik(),(drugi.DajNazivnik()/r))==true ||
            Razlomak::PrekoracnjeOduzimanje(prvi.DajBrojnik()*(drugi.DajNazivnik()/r),drugi.DajBrojnik()*drugi.DajBrojnik())==true)
                throw overflow_error("Nemoguce dobiti tacan rezultat");
        Razlomak novi;
        novi.brojnik = prvi.DajBrojnik()*(drugi.DajNazivnik()/r) - drugi.DajBrojnik()*(prvi.DajNazivnik()/r);
        novi.nazivnik = prvi.DajNazivnik()*(drugi.DajNazivnik()/r);
        novi=Razlomak(novi.brojnik, novi.nazivnik);
        return novi;
    }
    Razlomak operator *(const Razlomak &prvi, const Razlomak &drugi) {
        long long int s(Razlomak::NZD(prvi.DajBrojnik(),drugi.DajNazivnik())),
            t(Razlomak::NZD(drugi.DajBrojnik(),prvi.DajNazivnik()));
        if(Razlomak::PrekoracnjeMnozenje((prvi.DajBrojnik()/s),(drugi.DajBrojnik()/t))==true ||
            Razlomak::PrekoracnjeMnozenje((prvi.DajNazivnik()/t),(drugi.DajNazivnik()/s))==true)
                throw overflow_error("Nemoguce dobiti tacan rezultat");
        Razlomak novi;
        novi.brojnik = (prvi.DajBrojnik()/s) * (drugi.DajBrojnik()/t);
        novi.nazivnik = (prvi.DajNazivnik()/t) * (drugi.DajNazivnik()/s);
        novi=Razlomak(novi.brojnik, novi.nazivnik);
        return novi;
    }
    Razlomak operator /(const Razlomak &prvi, const Razlomak &drugi) {
        long long int r(Razlomak::NZD(prvi.DajNazivnik(),drugi.DajNazivnik())),
            u(Razlomak::NZD(prvi.DajBrojnik(),drugi.DajBrojnik()));
        if(Razlomak::PrekoracnjeMnozenje((prvi.DajBrojnik()/u),(drugi.DajNazivnik()/r))==true ||
            Razlomak::PrekoracnjeMnozenje((prvi.DajNazivnik()/r),(drugi.DajBrojnik()/u))==true)
                throw overflow_error("Nemoguce dobiti tacan rezultat");
        Razlomak novi;
        novi.brojnik = (prvi.DajBrojnik()/u) * (drugi.DajNazivnik()/r);
        novi.nazivnik = (prvi.DajNazivnik()/r) * (drugi.DajBrojnik()/u);
        novi=Razlomak(novi.brojnik, novi.nazivnik);
        return novi;
    }

    Razlomak operator +(const Razlomak &raz) {
        return raz;
    }
    Razlomak operator -(const Razlomak &raz) {
        if(Razlomak::PrekoracnjeMnozenje(-1,raz.DajBrojnik())) throw overflow_error("Nemoguce dobiti tacan rezultat");
        return {-raz.brojnik, raz.nazivnik};
    }
    
    Razlomak operator +=(Razlomak &prvi, const Razlomak &drugi) {
        long long int r(Razlomak::NZD(prvi.DajNazivnik(),drugi.DajNazivnik()));
        if(Razlomak::PrekoracnjeMnozenje(prvi.DajBrojnik(),(drugi.DajNazivnik()/r))==true ||
            Razlomak::PrekoracnjeMnozenje(drugi.DajBrojnik(),drugi.DajBrojnik())==true ||
            Razlomak::PrekoracnjeMnozenje(prvi.DajNazivnik(),(drugi.DajNazivnik()/r))==true ||
            Razlomak::PrekoracnjeSabiranje(prvi.DajBrojnik()*(drugi.DajNazivnik()/r),drugi.DajBrojnik()*drugi.DajBrojnik())==true)
                throw overflow_error("Nemoguce dobiti tacan rezultat");
        Razlomak novi;
        novi.brojnik = prvi.DajBrojnik()*(drugi.DajNazivnik()/r) + drugi.DajBrojnik()*(drugi.DajNazivnik()/r);
        novi.nazivnik = prvi.DajNazivnik()*(drugi.DajNazivnik()/r);
        novi=Razlomak(novi.brojnik, novi.nazivnik);
        prvi=novi;
        return prvi;
    }
    Razlomak operator -=(Razlomak &prvi, const Razlomak &drugi) {
        long long int r(Razlomak::NZD(prvi.DajNazivnik(),drugi.DajNazivnik()));
        if(Razlomak::PrekoracnjeMnozenje(prvi.DajBrojnik(),(drugi.DajNazivnik()/r))==true ||
            Razlomak::PrekoracnjeMnozenje(drugi.DajBrojnik(),drugi.DajBrojnik())==true ||
            Razlomak::PrekoracnjeMnozenje(prvi.DajNazivnik(),(drugi.DajNazivnik()/r))==true ||
            Razlomak::PrekoracnjeSabiranje(prvi.DajBrojnik()*(drugi.DajNazivnik()/r),drugi.DajBrojnik()*drugi.DajBrojnik())==true)
                throw overflow_error("Nemoguce dobiti tacan rezultat");
        Razlomak novi;
        novi.brojnik = prvi.DajBrojnik()*(drugi.DajNazivnik()/r) - drugi.DajBrojnik()*drugi.DajBrojnik();
        novi.nazivnik = prvi.DajNazivnik()*(drugi.DajNazivnik()/r);
        novi=Razlomak(novi.brojnik, novi.nazivnik);
        prvi=novi;
        return prvi;
    }
    Razlomak operator *=(Razlomak &prvi, const Razlomak &drugi) {
        long long int s(Razlomak::NZD(prvi.DajBrojnik(),drugi.DajNazivnik())),
            t(Razlomak::NZD(drugi.DajBrojnik(),prvi.DajNazivnik()));
        if(Razlomak::PrekoracnjeMnozenje((prvi.DajBrojnik()/s),(drugi.DajBrojnik()/t))==true ||
            Razlomak::PrekoracnjeMnozenje((prvi.DajNazivnik()/t),(drugi.DajNazivnik()/s))==true)
                throw overflow_error("Nemoguce dobiti tacan rezultat");
        Razlomak novi;
        novi.brojnik = (prvi.DajBrojnik()/s) * (drugi.DajBrojnik()/t);
        novi.nazivnik = (prvi.DajNazivnik()/t) * (drugi.DajNazivnik()/s);
        novi=Razlomak(novi.brojnik, novi.nazivnik);
        prvi=novi;
        return prvi;
    }
    Razlomak operator /=(Razlomak &prvi, const Razlomak &drugi) {
        long long int r(Razlomak::NZD(prvi.DajNazivnik(),drugi.DajNazivnik())),
            u(Razlomak::NZD(prvi.DajBrojnik(),drugi.DajBrojnik()));
        if(Razlomak::PrekoracnjeMnozenje((prvi.DajBrojnik()/u),(drugi.DajNazivnik()/r))==true ||
            Razlomak::PrekoracnjeMnozenje((prvi.DajNazivnik()/r),(drugi.DajBrojnik()/u))==true)
                throw overflow_error("Nemoguce dobiti tacan rezultat");
        Razlomak novi;
        novi.brojnik = (prvi.DajBrojnik()/u) * (drugi.DajNazivnik()/r);
        novi.nazivnik = (prvi.DajNazivnik()/r) * (drugi.DajBrojnik()/u);
        novi=Razlomak(novi.brojnik, novi.nazivnik);
        prvi=novi;
        return prvi;
    }
  
    bool operator ==(const Razlomak &prvi, const Razlomak &drugi) {
        if(prvi.DajBrojnik()==drugi.DajBrojnik() && prvi.DajNazivnik()==drugi.DajNazivnik()) return true;
        return false;
    }  
    bool operator !=(const Razlomak &prvi, const Razlomak &drugi) {
        if(prvi.DajBrojnik()!=drugi.DajBrojnik() || prvi.DajNazivnik()!=drugi.DajNazivnik()) return true;
        return false;
    }
    bool operator <(const Razlomak &prvi, const Razlomak &drugi) {
        long double x(prvi.DajBrojnik()/prvi.DajNazivnik()), y(drugi.DajBrojnik()/drugi.DajNazivnik());
        if(x<y) return true;
        return false;
    }
    bool operator >(const Razlomak &prvi, const Razlomak &drugi) {
        long double x1=prvi.DajBrojnik(), x2=prvi.DajNazivnik(), y1=drugi.DajBrojnik(), y2=drugi.DajNazivnik();
        long double x(x1/x2), y(y1/y2);
        if(x>y) return true;
        return false;
    }
    bool operator <=(const Razlomak &prvi, const Razlomak &drugi) {
        if(prvi==drugi) return true;
        long double x(prvi.DajBrojnik()/prvi.DajNazivnik()), y(drugi.DajBrojnik()/drugi.DajNazivnik());
        if(x<y) return true;
        return false;
    }
    bool operator >=(const Razlomak &prvi, const Razlomak &drugi) {
        if(prvi==drugi) return true;
        long double x(prvi.DajBrojnik()/prvi.DajNazivnik()), y(drugi.DajBrojnik()/drugi.DajNazivnik());
        if(x>y) return true;
        return false;
    }
    
    ostream &operator <<(ostream &tok, const Razlomak &raz) {
        Razlomak novi=raz;
        novi=Razlomak(novi.DajBrojnik(),novi.DajNazivnik());
        if(novi.DajNazivnik()==1) tok << novi.DajBrojnik();
        else if(novi.DajBrojnik()==0) tok << 0;
        else tok << novi.DajBrojnik() << "/" << novi.DajNazivnik();
        return tok;
    }

    istream &operator >>(istream &tok, Razlomak &raz) {
        raz.nazivnik=1;
        tok >> ws;
        if(!tok) tok.setstate(ios::failbit);
        char znak='o';
        tok >> raz.brojnik >> znak;
        if(tok.peek()=='\0') { raz=Razlomak(raz.brojnik, raz.nazivnik); return tok; }
        if(znak=='/') {
            tok >> raz.nazivnik;
            if(tok.peek()!=' ' && tok.peek()!='\n' && tok.peek()!='\v' && tok.peek()!='\f' && tok.peek()!='\t' && tok.peek()!='\r') tok.setstate(ios::failbit);
            raz=Razlomak(raz.brojnik, raz.nazivnik);
            return tok;
        }
        else if(znak==' ' || znak=='\n' || znak=='\v' || znak=='\f' || znak=='\t' || znak=='\r') {
            tok >> ws;
            if(!tok) tok.setstate(ios::failbit);
            else { raz=Razlomak(raz.brojnik, raz.nazivnik); return tok; }
        }
        raz=Razlomak(raz.brojnik, raz.nazivnik);
        return tok;
    }       
   
    Razlomak::operator long double() const {
        long double x(this->DajBrojnik()), y(this->DajNazivnik());
        return x/y;
    }
    
int main () {
    Razlomak r1, r2;
    cin >> r1;
    cin >> r2;
    cout << r1 << endl;
    cout << r2 << endl;
    cout << r1+r2 << endl;
    cout << r1-r2 << endl;
    cout << r1*r2 << endl;
    cout << r1/r2 << endl;
    cout << +r1 << endl;
    cout << -r1 << endl;
    r1*=r2;
    r2+=r1;
    r1/=r2;
    r2-=r1;
    ++r1;
    --r2;
    r1++;
    r2--;
    cout << r1 << endl;
    cout << r2 << endl;
    if(r1==r2) cout << "Jednaki" << endl;
    if(r1!=r2) cout << "Nisu jednaki" << endl;
    if(r1>=r2) cout << "Prvi veci ili jednaki" << endl;
    if(r1<=r2) cout << "Drugi veci ili jednaki" << endl;
    return 0;
}