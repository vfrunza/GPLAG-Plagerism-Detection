/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <initializer_list>
#include <limits>
#include <string>

using namespace std;

class Razlomak
{
    long long int brojnik, nazivnik;
    static long long int NZD(long long int p, long long int q);
    static bool PrekoracenjeZaSabiranje(long long int x, long long int y);
    static bool PrekoracenjeZaOduzimanje(long long int x, long long int y);
    static bool PrekoracenjeZaMnozenje(long long int x, long long int y);
    static bool JesuLiJednaki(long double x, long double y, long double Eps = 1e-10) 
    { return fabs(x - y) <= Eps * (fabs(x) + fabs(y)); }
    public:
        Razlomak(long long int brojnik=0, long long int nazivnik=1);
        Razlomak(initializer_list<long long int> lista);
        long long int DajBrojnik() const { return brojnik; }
        long long int DajNazivnik() const { return nazivnik; }
        friend Razlomak operator +(const Razlomak &r1, const Razlomak &r2);
        friend Razlomak operator -(const Razlomak &r1, const Razlomak &r2);
        friend Razlomak operator *(const Razlomak &r1, const Razlomak &r2);
        friend Razlomak operator /(const Razlomak &r1, const Razlomak &r2);
        friend Razlomak operator +(const Razlomak &r);
        friend Razlomak operator -(Razlomak &r);
        Razlomak &operator +=(const Razlomak &r);
        Razlomak &operator -=(const Razlomak &r);
        Razlomak &operator *=(const Razlomak &r);
        Razlomak &operator /=(const Razlomak &r);
        friend Razlomak &operator ++(Razlomak &r);
		friend Razlomak operator ++(Razlomak &r, int);
		friend Razlomak &operator --(Razlomak &r);
		friend Razlomak operator --(Razlomak &r, int);
		friend bool operator >(const Razlomak &r1, const Razlomak &r2);
		friend bool operator <(const Razlomak &r1, const Razlomak &r2);
		friend bool operator >=(const Razlomak &r1, const Razlomak &r2);
		friend bool operator <=(const Razlomak &r1, const Razlomak &r2);
		friend bool operator ==(const Razlomak &r1, const Razlomak &r2);
		friend bool operator !=(const Razlomak &r1, const Razlomak &r2);
		friend ostream &operator <<(ostream &tok, Razlomak r);
		friend istream &operator >>(istream &tok, Razlomak &r);
		operator long double() const { return ((long double)brojnik/(long double)nazivnik); }
};

Razlomak::Razlomak(long long int brojnik, long long int nazivnik)
{
    if(nazivnik==0) throw logic_error("Nekorektan razlomak");
    if(nazivnik<0)
    {
        nazivnik*=(-1);
        brojnik*=(-1);
    }
    long long int nzd(NZD(abs(brojnik), abs(nazivnik)));
    brojnik/=nzd;
    nazivnik/=nzd;
    this->brojnik=brojnik;
    this->nazivnik=nazivnik;
}

Razlomak::Razlomak(initializer_list<long long int> lista)
{
    if(lista.size()==0)
    {
        brojnik=0;
        nazivnik=1;
    }
    else if(lista.size()==1)
    {
        brojnik=*lista.begin();
        nazivnik=1;
    }
    else if(lista.size()==2)
    {
        auto it(lista.begin());
        it++;
        if(*it==0) throw logic_error("Nekorektan razlomak");
        if(*it<0)
        {
            nazivnik=*it*(-1);
            brojnik=*lista.begin()*(-1);
        }
        else
        {
            nazivnik=*it;
            brojnik=*lista.begin();
        }
        long long int nzd(NZD(brojnik, nazivnik));
        brojnik/=nzd;
        nazivnik/=nzd;
    }
    else throw logic_error("Prekoracen broj parametara");
}

long long int Razlomak::NZD(long long int p, long long int q)
{
    while(1)
    {
        if(q==0) return p;
        long long int pomocna(p);
        p=q, 
        q=pomocna%q;
    }
}
    
bool Razlomak::PrekoracenjeZaSabiranje(long long int x, long long int y)
{
    long long int M(numeric_limits<long long int>::max());
    long long int m(numeric_limits<long long int>::min());
    if(y>0 && x>M-y) return true;
    else if(y<0 && x<m-y) return true;
    return false;
}

bool Razlomak::PrekoracenjeZaOduzimanje(long long int x, long long int y)
{
    long long int m(numeric_limits<long long int>::min());
    if(y>0 && x<m+y) return true;
    else if(y<0 && Razlomak::PrekoracenjeZaSabiranje(x, -y)) return true;
    return false;
}

bool Razlomak::PrekoracenjeZaMnozenje(long long int x, long long int y)
{
    long long int M(numeric_limits<long long int>::max());
    long long int m(numeric_limits<long long int>::min());
    if(y>0 && (x<(m/y) || x>(M/y))) return true;
    else if(y<0 && (x==m || -x>M/(-y) || -x<m/(-y))) return true;
    return false;
}

Razlomak operator +(const Razlomak &r1, const Razlomak &r2)
{
    if(Razlomak::PrekoracenjeZaMnozenje(r1.brojnik, (r2.nazivnik/Razlomak::NZD(r1.nazivnik, r2.nazivnik)))) throw overflow_error("Nemoguce dobiti tacan rezultat");
    if(Razlomak::PrekoracenjeZaMnozenje(r2.brojnik, (r1.nazivnik/Razlomak::NZD(r1.nazivnik, r2.nazivnik)))) throw overflow_error("Nemoguce dobiti tacan rezultat");
    if(Razlomak::PrekoracenjeZaSabiranje(r1.brojnik*(r2.nazivnik/Razlomak::NZD(r1.nazivnik, r2.nazivnik)), r2.brojnik*(r1.nazivnik/Razlomak::NZD(r1.nazivnik, r2.nazivnik)))) throw overflow_error("Nemoguce dobiti tacan rezultat");
    if(Razlomak::PrekoracenjeZaMnozenje(r1.nazivnik, (r2.nazivnik/Razlomak::NZD(r1.nazivnik, r2.nazivnik)))) throw overflow_error("Nemoguce dobiti tacan rezultat");
    Razlomak zbir;
    zbir.brojnik=r1.brojnik*(r2.nazivnik/Razlomak::NZD(r1.nazivnik, r2.nazivnik))+r2.brojnik*(r1.nazivnik/Razlomak::NZD(r1.nazivnik, r2.nazivnik));
    zbir.nazivnik=r1.nazivnik*(r2.nazivnik/Razlomak::NZD(r1.nazivnik, r2.nazivnik));
    
    zbir=Razlomak(zbir.brojnik, zbir.nazivnik);
    
    return zbir;
}

Razlomak operator -(const Razlomak &r1, const Razlomak &r2)
{
    if(Razlomak::PrekoracenjeZaMnozenje(r1.brojnik, (r2.nazivnik/Razlomak::NZD(r1.nazivnik, r2.nazivnik)))) throw overflow_error("Nemoguce dobiti tacan rezultat");
    if(Razlomak::PrekoracenjeZaMnozenje(r2.brojnik, (r1.nazivnik/Razlomak::NZD(r1.nazivnik, r2.nazivnik)))) throw overflow_error("Nemoguce dobiti tacan rezultat");
    if(Razlomak::PrekoracenjeZaOduzimanje(r1.brojnik*(r2.nazivnik/Razlomak::NZD(r1.nazivnik, r2.nazivnik)), r2.brojnik*(r1.nazivnik/Razlomak::NZD(r1.nazivnik, r2.nazivnik)))) throw overflow_error("Nemoguce dobiti tacan rezultat");
    if(Razlomak::PrekoracenjeZaMnozenje(r1.nazivnik, (r2.nazivnik/Razlomak::NZD(r1.nazivnik, r2.nazivnik)))) throw overflow_error("Nemoguce dobiti tacan rezultat");
    Razlomak razlika;
    razlika.brojnik=r1.brojnik*(r2.nazivnik/Razlomak::NZD(r1.nazivnik, r2.nazivnik))-r2.brojnik*(r1.nazivnik/Razlomak::NZD(r1.nazivnik, r2.nazivnik));
    razlika.nazivnik=r1.nazivnik*(r2.nazivnik/Razlomak::NZD(r1.nazivnik, r2.nazivnik));
    
    razlika=Razlomak(razlika.brojnik, razlika.nazivnik);
    
    return razlika;
}

Razlomak operator *(const Razlomak &r1, const Razlomak &r2)
{
    if(Razlomak::PrekoracenjeZaMnozenje((r1.brojnik/Razlomak::NZD(r1.brojnik, r2.nazivnik)), (r2.brojnik/Razlomak::NZD(r1.nazivnik, r2.brojnik)))) throw overflow_error("Nemoguce dobiti tacan rezultat");
    if(Razlomak::PrekoracenjeZaMnozenje((r1.nazivnik/Razlomak::NZD(r1.nazivnik, r2.brojnik)), (r2.nazivnik/Razlomak::NZD(r1.brojnik, r2.nazivnik)))) throw overflow_error("Nemoguce dobiti tacan rezultat");
    
    Razlomak proizvod;
    proizvod.brojnik=(r1.brojnik/Razlomak::NZD(r1.brojnik, r2.nazivnik))*(r2.brojnik/Razlomak::NZD(r1.nazivnik, r2.brojnik));
    proizvod.nazivnik=(r1.nazivnik/Razlomak::NZD(r1.nazivnik, r2.brojnik))*(r2.nazivnik/Razlomak::NZD(r1.brojnik, r2.nazivnik));
    
    proizvod=Razlomak(proizvod.brojnik, proizvod.nazivnik);
    return proizvod;
}

Razlomak operator /(const Razlomak &r1, const Razlomak &r2)
{
    if(Razlomak::PrekoracenjeZaMnozenje((r1.brojnik/Razlomak::NZD(r1.brojnik, r2.brojnik)), (r2.nazivnik/Razlomak::NZD(r1.nazivnik, r2.nazivnik)))) throw overflow_error("Nemoguce dobiti tacan rezultat");
    if(Razlomak::PrekoracenjeZaMnozenje((r1.nazivnik/Razlomak::NZD(r1.nazivnik, r2.nazivnik)), (r2.brojnik/Razlomak::NZD(r1.brojnik, r2.brojnik)))) throw overflow_error("Nemoguce dobiti tacan rezultat");
    
    Razlomak kolicnik;
    kolicnik.brojnik=(r1.brojnik/Razlomak::NZD(r1.brojnik, r2.brojnik))*(r2.nazivnik/Razlomak::NZD(r1.nazivnik, r2.nazivnik));
    kolicnik.nazivnik=(r1.nazivnik/Razlomak::NZD(r1.nazivnik, r2.nazivnik))*(r2.brojnik/Razlomak::NZD(r1.brojnik, r2.brojnik));
    
    kolicnik=Razlomak(kolicnik.brojnik, kolicnik.nazivnik);
    return kolicnik;
}

Razlomak operator +(const Razlomak &r)
{ return r; }

Razlomak operator -(Razlomak &r)
{
    if(r.brojnik==numeric_limits<long long int>::min()) throw overflow_error("Nemoguce dobiti tacan rezultat");
    r.brojnik*=(-1);
    return r;
}

Razlomak &Razlomak::operator +=(const Razlomak &r)
{
    if(Razlomak::PrekoracenjeZaMnozenje(brojnik, (r.nazivnik/Razlomak::NZD(nazivnik, r.nazivnik)))) throw overflow_error("Nemoguce dobiti tacan rezultat");
    if(Razlomak::PrekoracenjeZaMnozenje(r.brojnik, (nazivnik/Razlomak::NZD(nazivnik, r.nazivnik)))) throw overflow_error("Nemoguce dobiti tacan rezultat");
    if(Razlomak::PrekoracenjeZaSabiranje(brojnik*(r.nazivnik/Razlomak::NZD(nazivnik, r.nazivnik)), r.brojnik*(nazivnik/Razlomak::NZD(nazivnik, r.nazivnik)))) throw overflow_error("Nemoguce dobiti tacan rezultat");
    if(Razlomak::PrekoracenjeZaMnozenje(nazivnik, (r.nazivnik/Razlomak::NZD(nazivnik, r.nazivnik)))) throw overflow_error("Nemoguce dobiti tacan rezultat");
    
    brojnik=brojnik*(r.nazivnik/Razlomak::NZD(nazivnik, r.nazivnik))+r.brojnik*(nazivnik/Razlomak::NZD(nazivnik, r.nazivnik));
    nazivnik=nazivnik*(r.nazivnik/Razlomak::NZD(nazivnik, r.nazivnik));
    
    *this=Razlomak(brojnik, nazivnik);
    
    return *this;
}

Razlomak &Razlomak::operator -=(const Razlomak &r)
{
    if(Razlomak::PrekoracenjeZaMnozenje(brojnik, (r.nazivnik/Razlomak::NZD(nazivnik, r.nazivnik)))) throw overflow_error("Nemoguce dobiti tacan rezultat");
    if(Razlomak::PrekoracenjeZaMnozenje(r.brojnik, (nazivnik/Razlomak::NZD(nazivnik, r.nazivnik)))) throw overflow_error("Nemoguce dobiti tacan rezultat");
    if(Razlomak::PrekoracenjeZaOduzimanje(brojnik*(r.nazivnik/Razlomak::NZD(nazivnik, r.nazivnik)), r.brojnik*(nazivnik/Razlomak::NZD(nazivnik, r.nazivnik)))) throw overflow_error("Nemoguce dobiti tacan rezultat");
    if(Razlomak::PrekoracenjeZaMnozenje(nazivnik, (r.nazivnik/Razlomak::NZD(nazivnik, r.nazivnik)))) throw overflow_error("Nemoguce dobiti tacan rezultat");
    
    brojnik=brojnik*(r.nazivnik/Razlomak::NZD(nazivnik, r.nazivnik))-r.brojnik*(nazivnik/Razlomak::NZD(nazivnik, r.nazivnik));
    nazivnik=nazivnik*(r.nazivnik/Razlomak::NZD(nazivnik, r.nazivnik));
    
    *this=Razlomak(brojnik, nazivnik);
    
    return *this;
}

Razlomak &Razlomak::operator *=(const Razlomak &r)
{
    if(Razlomak::PrekoracenjeZaMnozenje((brojnik/Razlomak::NZD(brojnik, r.nazivnik)), (r.brojnik/Razlomak::NZD(nazivnik, r.brojnik)))) throw overflow_error("Nemoguce dobiti tacan rezultat");
    if(Razlomak::PrekoracenjeZaMnozenje((nazivnik/Razlomak::NZD(nazivnik, r.brojnik)), (r.nazivnik/Razlomak::NZD(brojnik, r.nazivnik)))) throw overflow_error("Nemoguce dobiti tacan rezultat");
    auto pom(brojnik);
    brojnik=(brojnik/Razlomak::NZD(brojnik, r.nazivnik))*(r.brojnik/Razlomak::NZD(nazivnik, r.brojnik));
    nazivnik=(nazivnik/Razlomak::NZD(r.brojnik, nazivnik))*(r.nazivnik/Razlomak::NZD(pom, r.nazivnik));
    
    *this=Razlomak(brojnik, nazivnik);
    return *this;
}

Razlomak &Razlomak::operator /=(const Razlomak &r)
{
    if(Razlomak::PrekoracenjeZaMnozenje((brojnik/Razlomak::NZD(brojnik, r.brojnik)), (r.nazivnik/Razlomak::NZD(nazivnik, r.nazivnik)))) throw overflow_error("Nemoguce dobiti tacan rezultat");
    if(Razlomak::PrekoracenjeZaMnozenje((nazivnik/Razlomak::NZD(nazivnik, r.nazivnik)), (r.brojnik/Razlomak::NZD(brojnik, r.brojnik)))) throw overflow_error("Nemoguce dobiti tacan rezultat");
    auto pom(brojnik);
    brojnik=(brojnik/Razlomak::NZD(brojnik, r.brojnik))*(r.nazivnik/Razlomak::NZD(nazivnik, r.nazivnik));
    nazivnik=(nazivnik/Razlomak::NZD(nazivnik, r.nazivnik))*(r.brojnik/Razlomak::NZD(pom, r.brojnik));
    
    *this=Razlomak(brojnik, nazivnik);
    return *this;
}

Razlomak &operator ++(Razlomak &r)
{   return r+=Razlomak(1, 1);    }

Razlomak operator ++(Razlomak &r, int)
{
    Razlomak pomocni(r);
    r+=Razlomak(1, 1);
    return pomocni;
}

Razlomak &operator --(Razlomak &r)
{   return r-=Razlomak(1, 1);    }

Razlomak operator --(Razlomak &r, int)
{
    Razlomak pomocni(r);
    r-=Razlomak(1, 1);
    return pomocni;
}

bool operator >(const Razlomak &r1, const Razlomak &r2)
{
    long double prvi((long double)r1.brojnik/(long double)r1.nazivnik), drugi((long double)r2.brojnik/(long double)r2.nazivnik);
    if(prvi>drugi) return true;
    return false;
}

bool operator >=(const Razlomak &r1, const Razlomak &r2)
{
    long double prvi((long double)r1.brojnik/(long double)r1.nazivnik), drugi((long double)r2.brojnik/(long double)r2.nazivnik);
    if(prvi>drugi || Razlomak::JesuLiJednaki(prvi, drugi)) return true;
    return false;
}

bool operator <(const Razlomak &r1, const Razlomak &r2)
{
    long double prvi((long double)r1.brojnik/(long double)r1.nazivnik), drugi((long double)r2.brojnik/(long double)r2.nazivnik);
    if(prvi<drugi) return true;
    return false;
}

bool operator <=(const Razlomak &r1, const Razlomak &r2)
{
    long double prvi((long double)r1.brojnik/(long double)r1.nazivnik), drugi((long double)r2.brojnik/(long double)r2.nazivnik);
    if(prvi<drugi || Razlomak::JesuLiJednaki(prvi, drugi)) return true;
    return false;
}

bool operator ==(const Razlomak &r1, const Razlomak &r2)
{
    long double prvi((long double)r1.brojnik/(long double)r1.nazivnik), drugi((long double)r2.brojnik/(long double)r2.nazivnik);
    if(Razlomak::JesuLiJednaki(prvi, drugi)) return true;
    return false;
}

bool operator !=(const Razlomak &r1, const Razlomak &r2)
{
    long double prvi((long double)r1.brojnik/(long double)r1.nazivnik), drugi((long double)r2.brojnik/(long double)r2.nazivnik);
    if(Razlomak::JesuLiJednaki(prvi, drugi)) return false;
    return true;;
}

ostream &operator <<(ostream &tok, Razlomak r)
{
    r=Razlomak(r.brojnik, r.nazivnik);
    
    if(r.nazivnik==1) tok << r.brojnik;
    else tok << r.brojnik << "/" << r.nazivnik;
    
    return tok;
}

istream &operator >>(istream &tok, Razlomak &r)
{
    long long int broj;
    char znak;
    
    tok >> broj;
    r.brojnik=broj;
    r.nazivnik=1;
    if(tok.peek()==' ' || tok.peek()==10 || tok.peek()==EOF || tok.peek()==13 ||  tok.peek()==11 || tok.peek()==12 || tok.peek()==9) return tok;
    else if(tok.peek()=='/')
    {
        long long int pom;
        tok >> znak;
        if(!(tok.peek()>='0' && tok.peek()<='9'))
        {
            tok.setstate(ios::failbit);
            return tok;
        }
        tok >> pom;
        
        if(tok.peek()==' ' || tok.peek()==10 || tok.peek()==EOF || tok.peek()==13 ||  tok.peek()==11 || tok.peek()==12 || tok.peek()==9)
        {
            r.brojnik=broj;
            r.nazivnik=pom;
            return tok;
        }
        else tok.setstate(ios::failbit);
    }
    else tok.setstate(ios::failbit);
    
    return tok;
}

int main ()
{
	Razlomak r1, r2{4, 2}, r3(10, 15), r4(6);
	cout << "Unesite brojnik i nazivnik prvog razlomka: ";
	
	cin >> r1;
	if(!cin)
	{
	    cout << "Neispravan tok." << endl;
	    return 0;
	}
	cout << "Ovaj ralomak glasi: " << r1 << endl;
	cout << "Zbir prvog i drugog razlomka: " << r1+r2 << endl;
	cout << "Razlika treceg i drugog razlomka: " << r3-r2 << endl;
	if(r1>r2) cout << "Prvi razlomak je veci od drugog." << endl;
	else if(r1<r2) cout << "Prvi razlomak je manji od drugog." << endl;
	else if(r1==r2) cout << "Prvi i drugi razlomak su isti." << endl;
	
	
	
	return 0;
}


