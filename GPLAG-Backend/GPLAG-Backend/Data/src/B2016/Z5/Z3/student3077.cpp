/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <limits>

typedef std::numeric_limits<long long int> granica;
using std::cout;

class Razlomak{
  long long int brojnik, nazivnik;
  static long long int NZD(long long int a, long long int b); 
  public:
  Razlomak(long long int a=0, long long int b=1);
  long long int DajBrojnik() const{ return brojnik;}
  long long int DajNazivnik() const{ return nazivnik;}
  Razlomak &operator+=(const Razlomak &r);
  Razlomak &operator-=(const Razlomak &r);
  Razlomak &operator*=(const Razlomak &r);
  Razlomak &operator/=(const Razlomak &r);
  Razlomak &operator+(){ return *this;};
  Razlomak &operator-();
  Razlomak &operator++();
  Razlomak &operator++(int);
  Razlomak &operator--();
  Razlomak &operator--(int);
  friend Razlomak operator+(const Razlomak &r1, const Razlomak &r2);
  friend Razlomak operator -(const Razlomak &r1, const Razlomak &r2);
  friend Razlomak operator*(const Razlomak &r1, const Razlomak &r2);
  friend Razlomak operator/(const Razlomak r1, const Razlomak r2);
  friend std::ostream &operator<<(std::ostream &ispis, const Razlomak &r);
  friend std::istream &operator>>(std::istream &unos, Razlomak &r);
  friend bool operator>(const Razlomak &r1, const Razlomak &r2);
  friend bool operator>=(const Razlomak &r1, const Razlomak &r2);
  friend bool operator<(const Razlomak &r1, const Razlomak &r2);
  friend bool operator<=(const Razlomak &r1, const Razlomak &r2);
  friend bool operator==(const Razlomak &r1, const Razlomak &r2);
  friend bool operator!=(const Razlomak &r1, const Razlomak &r2);
  friend void OverflowMnozenje(long long int br1, long long int br2, long long int nzd2, long long int nzd1);
  friend void OverflowSabiranje(const Razlomak &r1, const Razlomak &r2, long long int nzd);
  friend void OverflowOduzimanje(const Razlomak &r1, const Razlomak &r2,long long int nzd);
  operator long double() { return (long double)(this->brojnik)/this->nazivnik;} 
};

long long int Razlomak::NZD(long long int a, long long int b) {
    if(b==0) return a;
    return NZD(b,a%b);}

Razlomak::Razlomak(long long int a, long long int b){
    if(b==0) throw std::logic_error("Nekorektan razlomak");
    if(a==granica::max() && b<0) throw std::logic_error("Nemoguce dobiti tacan rezultat");
    if((a<0 && b<0) || b<0){
        brojnik=-a;
        nazivnik=-b;
    }
    else {
        brojnik=a;
        nazivnik=b;
    }
    long long int nzd(NZD(abs(brojnik),abs(nazivnik)));
    brojnik/=nzd;
    nazivnik/=nzd;
}


void OverflowMnozenje(long long int br1, long long int br2, long long int nzd2, long long int nzd1=1){
    if(br2>0 &&(br1/nzd1<granica::min()/(br2/nzd2) || br1/nzd1>granica::max()/(br2/nzd2)))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    else if(br2<0 &&(br1/nzd1==granica::min() || -br1/nzd1>granica::max()/(-br2/nzd2) || -br1/nzd1<granica::min()/(-br2/nzd2) ))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");    
}



void OverflowSabiranje(const Razlomak &r1,const Razlomak &r2,long long int nzd){
     OverflowMnozenje(r1.brojnik,r2.nazivnik,nzd);
     OverflowMnozenje(r2.brojnik,r1.nazivnik,nzd);
     OverflowMnozenje(r1.nazivnik, r2.nazivnik,nzd);
     if(r2.brojnik>0 && r1.brojnik*(r2.nazivnik/nzd)>granica::max()-r2.brojnik*(r1.nazivnik/nzd))
        throw std::logic_error("Nemoguce dobiti tacan rezultat");
    else if(r2.brojnik<0 && r1.brojnik*(r2.nazivnik/nzd)<granica::min()-r2.brojnik*(r1.nazivnik/nzd))
        throw std::logic_error("Nemoguce dobiti tacan rezultat");
}

void OverflowOduzimanje(const Razlomak &r1, const Razlomak &r2, long long int nzd){
    OverflowMnozenje(r1.brojnik, r2.nazivnik,nzd);
    OverflowMnozenje(r2.brojnik, r1.nazivnik,nzd);
    OverflowMnozenje(r1.nazivnik,r2.nazivnik,nzd);
    if(r2.brojnik>0 && r1.brojnik*(r2.nazivnik/nzd)<granica::min()+r1.brojnik*(r2.nazivnik/nzd))
        throw std::logic_error("Nemoguce dobiti tacan rezultat");
    else if(r2.brojnik<0 && r1.brojnik*(r2.nazivnik/nzd)>granica::max()+r1.brojnik*(r2.nazivnik/nzd))
        throw std::logic_error("Nemoguce dobiti tacan rezultat");
}


Razlomak operator+(const Razlomak &r1, const Razlomak &r2){
    Razlomak povratni;
    long long int nzd=Razlomak::NZD(r1.nazivnik, r2.nazivnik);
    OverflowSabiranje(r1,r2,nzd);
    povratni.brojnik=r1.brojnik*(r2.nazivnik/nzd)+r2.brojnik*(r1.nazivnik/nzd);
    povratni.nazivnik=r1.nazivnik*(r2.nazivnik/nzd);
    return povratni={povratni.brojnik,povratni.nazivnik};
}


Razlomak &Razlomak::operator+=(const Razlomak &r){
    long long int nzd(NZD(this->nazivnik, r.nazivnik));
    OverflowSabiranje(*this,r,nzd);
    this->brojnik=this->brojnik*(r.nazivnik/nzd)+r.brojnik*(this->nazivnik/nzd);
    this->nazivnik*=(r.nazivnik/nzd);
    return *this={this->brojnik,this->nazivnik};
}


Razlomak operator-(const Razlomak &r1, const Razlomak &r2){
    Razlomak povratni;
    long long int nzd(Razlomak::NZD(r1.nazivnik, r2.nazivnik));
    povratni.brojnik=r1.brojnik*(r2.nazivnik/nzd)-r2.brojnik*(r1.nazivnik/nzd);
    povratni.nazivnik=r1.nazivnik*(r2.nazivnik*nzd);
    return povratni={povratni.brojnik,povratni.nazivnik};
}

Razlomak &Razlomak::operator-=(const Razlomak &r){
    long long int nzd(NZD(this->nazivnik,r.nazivnik));
    this->brojnik=this->brojnik*(r.nazivnik/nzd)-r.brojnik*(this->nazivnik/nzd);
    this->nazivnik*=(r.nazivnik/nzd);
    return *this={this->brojnik,this->nazivnik};
}

Razlomak operator*(const Razlomak &r1, const Razlomak &r2){
    Razlomak povratni;
    long long int nzd1(Razlomak::NZD(r1.brojnik, r2.nazivnik)), nzd2(Razlomak::NZD(r2.brojnik, r1.nazivnik));
    OverflowMnozenje(r1.brojnik,r2.brojnik,nzd2,nzd1);
    OverflowMnozenje(r1.nazivnik,r2.nazivnik,nzd1,nzd2);
    povratni.brojnik=(r1.brojnik/nzd1)*(r2.brojnik/nzd2);
    povratni.nazivnik=(r1.nazivnik/nzd2)*(r2.nazivnik/nzd1);
    return povratni={povratni.brojnik,povratni.nazivnik};
}


Razlomak &Razlomak::operator*=(const Razlomak &r){
    long long int nzd1(NZD(this->brojnik, r.nazivnik)), nzd2(NZD(r.brojnik,this->nazivnik));
    OverflowMnozenje(this->brojnik,r.brojnik,nzd2,nzd1);
    OverflowMnozenje(this->nazivnik,r.nazivnik,nzd2,nzd1);
    this->brojnik=(this->brojnik/nzd1)*(r.brojnik/nzd2);
    this->nazivnik=(this->nazivnik/nzd2)*(r.nazivnik/nzd1);
    return *this={this->brojnik,this->nazivnik};
}

Razlomak operator/(const Razlomak r1, const Razlomak r2){
    long long int nzd1(Razlomak::NZD(r1.brojnik, r2.brojnik)),nzd2(Razlomak::NZD(r1.nazivnik, r2.nazivnik));
    Razlomak povratni;
    povratni.brojnik=(r1.brojnik/nzd1)*(r2.nazivnik/nzd2);
    povratni.nazivnik=(r1.nazivnik/nzd2)*(r2.brojnik/nzd1);
    return povratni={povratni.brojnik,povratni.nazivnik};
}

Razlomak &Razlomak::operator/=(const Razlomak &r){
    long long int nzd1(NZD(this->brojnik, r.brojnik)), nzd2(NZD(this->nazivnik, r.nazivnik));
    this->brojnik=(this->brojnik/nzd1)*(r.nazivnik/nzd2);
    this->nazivnik=(this->nazivnik/nzd2)*(r.brojnik/nzd1);
    return *this={this->brojnik,this->nazivnik};
}


std::istream &operator>>(std::istream &unos, Razlomak &r){
    char slash;
    unos>>std::ws;
    unos>>r.brojnik;
    if(unos && (unos.peek()==' ' || unos.peek()=='\n')){
        r.nazivnik=1;
    }
    else{
        unos>>slash>>r.nazivnik;
        if(slash!='/' || unos.peek()!=' ' || !unos) unos.setstate(std::ios::failbit);
    }
    r={r.brojnik,r.nazivnik};
    return unos;
}

Razlomak &Razlomak::operator-(){
    if(this->brojnik==granica::max()) throw std::logic_error("Nemoguce dobiti tacan rezultat");
    return *this={this->brojnik,-this->nazivnik};
}



std::ostream &operator<<(std::ostream &ispis, const Razlomak &r){
    if(r.nazivnik==1)
        ispis<<r.brojnik;
    else if(r.brojnik==0)
        ispis<<r.brojnik;
    else    
        ispis<<r.brojnik<<"/"<<r.nazivnik;
    return ispis;
}


Razlomak &Razlomak::operator++(){
    Razlomak pomocni(1,1);
    return *this+=pomocni;
}

Razlomak &Razlomak::operator--(){
    Razlomak pomocni(1,1);
    return *this-=pomocni;
}

Razlomak &Razlomak::operator++(int){
    Razlomak pomocna(this->brojnik, this->nazivnik);
    pomocna+={1,1};
    return *this;
}
Razlomak &Razlomak::operator--(int){
    Razlomak pomocna(this->brojnik,this->nazivnik);
    pomocna-={1,1};
    return *this;
}


bool operator<(const Razlomak &r1, const Razlomak &r2){
    return (long double)(r1.brojnik)/r1.nazivnik < (long double)(r2.brojnik)/r2.nazivnik;
}

bool operator<=(const Razlomak &r1, const Razlomak &r2){
    return (long double)(r1.brojnik)/r1.nazivnik <= (long double)(r2.brojnik)/r2.nazivnik;
}

bool operator>(const Razlomak &r1, const Razlomak &r2){
    return (long double)(r1.brojnik)/r1.nazivnik > (long double)(r2.brojnik)/r2.nazivnik;
}

bool operator>=(const Razlomak &r1, const Razlomak &r2){
    return (long double)(r1.brojnik)/r1.nazivnik >= (long double)(r2.brojnik)/r2.nazivnik;
}

bool operator==(const Razlomak &r1, const Razlomak &r2){
    return (long double)(r1.brojnik)/r1.nazivnik == (long double)(r2.brojnik)/r2.nazivnik;
}

bool operator!=(const Razlomak &r1, const Razlomak &r2){
    return !(r1==r2);
}
int main ()
{   try{
     Razlomak r;
     cout<<"Unesite razlomak: "<<std::endl;
     std::cin>>r;
     cout<<"Unijeli ste razlomak: "<<std::endl;
     cout<<r;
     Razlomak p{1,2}, q(1,3);
     cout<<"Zbir razlomaka p i q je: ";
     cout<<p+q;
     cout<<std::endl;
     cout<<"Nakon sto pomnozimo r i p rezultat je ";
     cout<<r*p;
     cout<<std::endl;
     cout<<"Podijelimo li q i r imamo: ";
     cout<<q/r;
     cout<<std::endl;
     if(p>q)
        cout<<"Razlomak p je veci!"<<std::endl;
    else 
        cout<<"Razlomak q je veci!"<<std::endl;
    cout<<"Razlomci p i q su ocigledno ";
    if(p!=q)
        cout<<"razliciti"<<std::endl;
    else
        cout<<"isti?"<<std::endl;
    cout<<"Priblizne vrijednosti razlomaka su "<<static_cast<long double>(r)<<" "<<static_cast<long double>(p)<<" "<<static_cast<long double>(q)<<std::endl;
    cout<<"Pa hajmo ih na kraju i malo podijeliti...p/q=";
    cout<<p/q;
    cout<<std::endl;
    
}
    catch(std::logic_error izuzetak){
        std::cout<<izuzetak.what();
    }
    catch(std:: overflow_error izuzetak1){
        cout<<izuzetak1.what();
    }
	return 0;
}