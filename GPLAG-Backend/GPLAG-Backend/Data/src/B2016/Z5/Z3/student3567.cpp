/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <initializer_list>
#include <cmath>
#include <limits>
#include <stdexcept>
#include <iomanip>
using namespace std;

class Razlomak {
    long long int brojnik, nazivnik;
    
    static long long int NZD(long long int a, long long int b);
    public:
    Razlomak(long long int brojnik = 0, long long int nazivnik = 1);
    Razlomak(const initializer_list<long long int> &lista);
    long long int DajBrojnik() const {
        return brojnik;
    }
    long long int DajNazivnik() const {
        return nazivnik;
    }
    Razlomak &operator +=(const Razlomak &razlomak) {
        return *this = *this + razlomak;
    }
    Razlomak &operator -=(const Razlomak &razlomak) {
        return *this = *this - razlomak;
    }
    Razlomak &operator *=(const Razlomak &razlomak) {
        return *this = *this * razlomak;
    }
    Razlomak &operator /=(const Razlomak &razlomak) {
        return *this = *this / razlomak;
    }
    operator long double() const {
        return (long double)(brojnik) / (long double)(nazivnik);
    }
    
    friend Razlomak operator +(const Razlomak &razlomak1, const Razlomak &razlomak2);
    friend Razlomak operator -(const Razlomak &razlomak1, const Razlomak &razlomak2);
    friend Razlomak operator *(const Razlomak &razlomak1, const Razlomak &razlomak2);
    friend Razlomak operator /(const Razlomak &razlomak1, const Razlomak &razlomak2);
    friend Razlomak operator +(const Razlomak &razlomak);
    friend Razlomak operator -(const Razlomak &razlomak);
    friend Razlomak &operator ++(Razlomak &razlomak);
    friend Razlomak operator ++(Razlomak &razlomak, int broj);
    friend Razlomak &operator --(Razlomak &razlomak);
    friend Razlomak operator --(Razlomak &razlomak, int broj);
    friend bool operator <(const Razlomak &razlomak1, const Razlomak &razlomak2);
    friend bool operator >(const Razlomak &razlomak1, const Razlomak &razlomak2);
    friend bool operator <=(const Razlomak &razlomak1, const Razlomak &razlomak2);
    friend bool operator >=(const Razlomak &razlomak1, const Razlomak &razlomak2);
    friend bool operator ==(const Razlomak &razlomak1, const Razlomak &razlomak2);
    friend bool operator !=(const Razlomak &razlomak1, const Razlomak &razlomak2);
    friend ostream &operator <<(ostream &tok, const Razlomak &razlomak);
    friend istream &operator >>(istream &tok, Razlomak &razlomak);
    
    
};

long long int Razlomak::NZD(long long int p, long long int q) {
    if(q == 0){
        return p;
    } else {
        return NZD(q, p%q);
    }
}

Razlomak::Razlomak(long long int brojnik, long long int nazivnik) {
    if(nazivnik < 0) {
        nazivnik*=-1;
        brojnik*=-1;
    }
    Razlomak::brojnik=brojnik/NZD(abs(brojnik),abs(nazivnik));
    Razlomak::nazivnik=nazivnik/NZD(abs(brojnik),abs(nazivnik));
}

Razlomak::Razlomak(const initializer_list<long long int> &lista) {
    if(lista.size()==0) {
        brojnik=0;
        nazivnik=1;
    } else if(lista.size()==1) {
        brojnik=*lista.begin();
        nazivnik=1;
    } else if(lista.size()==2) {
        initializer_list<long long int>::iterator it(lista.begin());
        brojnik=*it/NZD(abs(*it),abs(*(it+1)));
        nazivnik=*(it+1)/NZD(abs(*it),abs(*(it+1)));
    }
}

Razlomak operator +(const Razlomak &razlomak1, const Razlomak &razlomak2) {
    long long int p1(razlomak1.DajBrojnik()), p2(razlomak2.DajBrojnik()), q1(razlomak1.DajNazivnik()), q2(razlomak2.DajNazivnik()), m(numeric_limits<long long int>::min()), M(numeric_limits<long long int>::max());
    long long int r(Razlomak::NZD(abs(q1),abs(q2)));
    long long int temp1(q2/r), temp2(q1/r);
    if(temp1>=0) {
        if(p1<m/temp1 || p1>M/temp1) {
            throw overflow_error("Nemoguce dobiti tacan rezultat");
        }
    } else {
        if(p1==m || -p1>M/(-temp1) || -p1<m/(-temp1)) {
            throw overflow_error("Nemoguce dobiti tacan rezultat");
        }
    }
    long long int temp3(p1*temp1);
    if(temp2>=0) {
        if(p2<m/temp2 || p2>M/temp2) {
            throw overflow_error("Nemoguce dobiti tacan rezultat");
        }
    } else {
        if(p2==m || -p2>M/(-temp2) || -p2<m/(-temp2)) {
            throw overflow_error("Nemoguce dobiti tacan rezultat");
        }
    }
    long long int temp4(p2*temp2);
    if(temp1>=0) {
        if(q1<m/temp1 || q1>M/temp1) {
            throw overflow_error("Nemoguce dobiti tacan rezultat");
        }
    } else {
        if(q1==m || -q1>M/(-temp1) || -q1<m/(-temp1)) {
            throw overflow_error("Nemoguce dobiti tacan rezultat");
        }
    }
    long long int temp5(q1*temp1);
    if(temp4>=0) {
        if(temp3>M-temp4) {
            throw overflow_error("Nemoguce dobiti tacan rezultat");
        }
    } else {
        if(temp3<m-temp4) {
            throw overflow_error("Nemoguce dobiti tacan rezultat");
        }
    }
    return Razlomak(temp3 + temp4, temp5);
}

Razlomak operator -(const Razlomak &razlomak1, const Razlomak &razlomak2) {
    long long int p1(razlomak1.DajBrojnik()), p2(razlomak2.DajBrojnik()), q1(razlomak1.DajNazivnik()), q2(razlomak2.DajNazivnik()), m(numeric_limits<long long int>::min()), M(numeric_limits<long long int>::max());
    long long int r(Razlomak::NZD(abs(q1),abs(q2)));
    long long int temp1(q2/r), temp2(q1/r);
    if(temp1>=0) {
        if(p1<m/temp1 || p1>M/temp1) {
            throw overflow_error("Nemoguce dobiti tacan rezultat");
        }
    } else {
        if(p1==m || -p1>M/(-temp1) || -p1<m/(-temp1)) {
            throw overflow_error("Nemoguce dobiti tacan rezultat");
        }
    }
    long long int temp3(p1*temp1);
    if(temp2>=0) {
        if(p2<m/temp2 || p2>M/temp2) {
            throw overflow_error("Nemoguce dobiti tacan rezultat");
        }
    } else {
        if(p2==m || -p2>M/(-temp2) || -p2<m/(-temp2)) {
            throw overflow_error("Nemoguce dobiti tacan rezultat");
        }
    }
    long long int temp4(p2*temp2);
    if(temp1>=0) {
        if(q1<m/temp1 || q1>M/temp1) {
            throw overflow_error("Nemoguce dobiti tacan rezultat");
        }
    } else {
        if(q1==m || -q1>M/(-temp1) || -q1<m/(-temp1)) {
            throw overflow_error("Nemoguce dobiti tacan rezultat");
        }
    }
    long long int temp5(q1*temp1);
    if(temp4>=0) {
        if(temp3<m+temp4) {
            throw overflow_error("Nemoguce dobiti tacan rezultat");
        }
    } else {
        if(temp3>M+temp4) {
            throw overflow_error("Nemoguce dobiti tacan rezultat");
        }
    }
    return Razlomak(temp3 - temp4, temp5);
}

Razlomak operator *(const Razlomak &razlomak1, const Razlomak &razlomak2) {
    long long int p1(razlomak1.DajBrojnik()), p2(razlomak2.DajBrojnik()), q1(razlomak1.DajNazivnik()), q2(razlomak2.DajNazivnik()), m(numeric_limits<long long int>::min()), M(numeric_limits<long long int>::max());
    long long int s(Razlomak::NZD(abs(p1), abs(q2))), t(Razlomak::NZD(abs(p2),abs(q1)));
    long long int temp1(p1/s), temp2(p2/t), temp3(q1/t), temp4(q2/s);
    if(temp2>=0) {
        if(temp1<m/temp2 || temp1>M/temp2) {
            throw overflow_error("Nemoguce dobiti tacan rezultat");
        }
    } else {
        if(temp1==m || -temp1>M/(-temp2) || -temp1<m/(-temp2)) {
            throw overflow_error("Nemoguce dobiti tacan rezultat");
        }
    }
    if(temp4>=0) {
        if(temp3<m/temp4 || temp3>M/temp4) {
            throw overflow_error("Nemoguce dobiti tacan rezultat");
        }
    } else {
        if(temp3==m || -temp3>M/(-temp4) || -temp3<m/(-temp4)) {
            throw overflow_error("Nemoguce dobiti tacan rezultat");
        }
    }
    return Razlomak(temp1*temp2, temp3*temp4);
}

Razlomak operator /(const Razlomak &razlomak1, const Razlomak &razlomak2) {
    long long int p1(razlomak1.DajBrojnik()), p2(razlomak2.DajBrojnik()), q1(razlomak1.DajNazivnik()), q2(razlomak2.DajNazivnik()), m(numeric_limits<long long int>::min()), M(numeric_limits<long long int>::max());
    long long int u(Razlomak::NZD(abs(p1),abs(p2))), r(Razlomak::NZD(abs(q1),abs(q2)));
    long long int temp1(p1/u), temp2(q2/r), temp3(q1/r), temp4(p2/u);
    if(temp2>=0) {
        if(temp1<m/temp2 || temp1>M/temp2) {
            throw overflow_error("Nemoguce dobiti tacan rezultat");
        }
    } else {
        if(temp1==m || -temp1>M/(-temp2) || -temp1<m/(-temp2)) {
            throw overflow_error("Nemoguce dobiti tacan rezultat");
        }
    }
    if(temp4>=0) {
        if(temp3<m/temp4 || temp3>M/temp4) {
            throw overflow_error("Nemoguce dobiti tacan rezultat");
        }
    } else {
        if(temp3==m || -temp3>M/(-temp4) || -temp3<m/(-temp4)) {
            throw overflow_error("Nemoguce dobiti tacan rezultat");
        }
    }
    return Razlomak(temp1*temp2, temp3*temp4);
}

Razlomak operator +(const Razlomak &razlomak) {
    return razlomak;
}

Razlomak operator -(const Razlomak &razlomak) {
    if(razlomak.brojnik == numeric_limits<long long int>::min())
        throw overflow_error("Nemoguce dobiti tacan rezultat");
    return Razlomak(-razlomak.brojnik, razlomak.nazivnik);
}

Razlomak &operator ++(Razlomak &razlomak) {
    long long int M(numeric_limits<long long int>::max());
    if(razlomak.brojnik>M-1)
        throw overflow_error("Nemoguce dobiti tacan rezultat");
    razlomak.brojnik = razlomak.brojnik + 1;
    return razlomak;
}

Razlomak operator ++(Razlomak &razlomak, int broj) {
    Razlomak temp(razlomak);
    ++razlomak;
    return temp;
}

Razlomak &operator --(Razlomak &razlomak) {
    long long int m(numeric_limits<long long int>::min());
    if(razlomak.brojnik<m+1)
        throw overflow_error("Nemoguce dobiti tacan rezultat");
    razlomak.brojnik = razlomak.brojnik - 1;
    return razlomak;
}

Razlomak operator --(Razlomak &razlomak, int broj) {
    Razlomak temp(razlomak);
    --razlomak;
    return temp;
}

bool operator <(const Razlomak &razlomak1, const Razlomak &razlomak2) {
    return (long double)(razlomak1) < (long double)(razlomak2);
}

bool operator >(const Razlomak &razlomak1, const Razlomak &razlomak2) {
    return (long double)(razlomak1) < (long double)(razlomak2);
}

bool operator ==(const Razlomak &razlomak1, const Razlomak &razlomak2) {
    long double eps(0.0000000000000001);
    return fabs((long double)(razlomak1) - (long double)(razlomak2)) < eps;
}

bool operator <=(const Razlomak &razlomak1, const Razlomak &razlomak2) {
    return razlomak1 < razlomak2 || razlomak1 == razlomak2;
}

bool operator >=(const Razlomak &razlomak1, const Razlomak &razlomak2) {
    return razlomak1 > razlomak2 || razlomak1 == razlomak2;
}

bool operator !=(const Razlomak &razlomak1, const Razlomak &razlomak2) {
    return !(razlomak1 == razlomak2);
}

ostream &operator <<(ostream &tok, const Razlomak &razlomak) {
    if(razlomak.nazivnik != 1) {
        tok << razlomak.brojnik << "/" << razlomak.nazivnik;
    } else {
        tok << razlomak.brojnik;
    }
    return tok;
}

//popraviti
istream &operator >>(istream &tok, Razlomak &razlomak) {
    long long int brojnik(0), nazivnik(1);
    char znak(0);
    tok >> brojnik;
    znak = tok.peek();
    if(znak <= 32 || znak == '\n' || znak == ' ') {
        tok.get();
        nazivnik = 1;
        razlomak = Razlomak(brojnik, nazivnik);
    } else if(znak == '/') {
        tok.get();
        tok >> nazivnik;
        znak = tok.peek();
        if(znak > 32) {
            tok.setstate(ios::failbit);
            return tok;
        }
        razlomak = Razlomak(brojnik, nazivnik);
    } else {
        tok.setstate(ios::failbit);
    }
    return tok;
}

int main() {
    //orbob
    Razlomak r1(166,77232);
    Razlomak r2(1375,6366);
    cout << r1 << " " << r2 << endl;
    Razlomak r3(r1 - r2);
    Razlomak r4(r3);
    if(r3 != r4) {
        cout << "Nije jednako" << endl;
    } else if(r3 == r4) {
        cout << "Jednako" << endl;
    }
    if(r3 >= r2) {
        cout << "R2 manje jednako od R3" << endl;
    } else if (r3 < r2) {
        cout << "R3 manje od R2" << endl;
    }
    ++r3;
    r2--;
    r1++;
    ------r4;
    cout << -r3 << " " << r3 << " " << +r2 << endl;
    Razlomak r6(r3 + r1), r7({2,3}), r9{3,4};
    cout << r6 << " " << r7 << " " << r9 << endl;
    return 0;
}