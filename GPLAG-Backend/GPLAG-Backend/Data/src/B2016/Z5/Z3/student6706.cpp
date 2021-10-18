/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include<iostream>
#include <stdexcept>
#include<cmath>
using namespace std;
class Razlomak{
    long long int brojnik, nazivnik;
    //staticka fja za najveci zajednicki sadrzilac
    static long long int NZD(long long int x, long long int y);
    public:
    Razlomak(long long int brojnik, long long int nazivnik);//konstruktor sa dva parametra
    Razlomak(){brojnik=0; nazivnik=1;} //konstruktor bez parametara
    Razlomak(long long int brojnik){ //konstruktor sa jednim parametrom
        Razlomak::brojnik=brojnik;
        nazivnik=1;
    }
    long long int DajBrojnik() const{ return brojnik;}
    long long int DajNazivnik() const {return nazivnik;}
    //operatori preklapanja fje obicne
    friend Razlomak operator + (const Razlomak &r1, const Razlomak &r2);//sabiranje
    friend Razlomak operator - (const Razlomak &r1, const Razlomak &r2); //oduzimanje
    friend Razlomak operator * (const Razlomak &r1, const Razlomak &r2); //mnozenje
    friend Razlomak operator / (const Razlomak &r1, const Razlomak &r2); //dijeljenje
    //operatori unarni fje obicne 
    friend Razlomak operator+(const Razlomak &r){
        return {r.brojnik, r.nazivnik}; //vraća svoj operand neizmijenjen
    }
    friend Razlomak operator-(const Razlomak &r){
        return{(-1)*r.brojnik, r.nazivnik}; // vraća razlomak na koji je primijenjen sa izvrnutim znakom 
    }
    //operatori binarni fje clanice
    Razlomak &operator +=(const Razlomak &r1); //sabiranje +=
    Razlomak &operator -=(const Razlomak &r1); //oduzimanje -=
    Razlomak &operator *=(const Razlomak &r1);//mnozenje *=
    Razlomak &operator /=(const Razlomak &r1); //dijeljenje /=
    //unarni operatori fje clanice
    Razlomak &operator ++ ();//++r
    Razlomak operator ++(int); // r++
    Razlomak &operator --();// --r
    Razlomak operator --(int); // r--
    //operatori poredjenja fje obicne
    friend bool operator ==(const Razlomak &r1, const Razlomak &r2);// operator ==
    friend bool operator !=(const Razlomak &r1, const Razlomak &r2); // operator !=
    friend bool operator <(const Razlomak &r1,const Razlomak &r2);
    friend bool operator >(const Razlomak &r1,const Razlomak &r2);
    friend bool operator <=(const Razlomak &r1,const Razlomak &r2);
    friend bool operator >=(const Razlomak &r1,const Razlomak &r2);
    friend ostream &operator <<(ostream &tok, const Razlomak &r); //ispis
    friend istream &operator >>(istream &tok, Razlomak &r);//upis
      operator long double() const {
      return (long double) brojnik/nazivnik;
}
};
Razlomak::Razlomak(long long brojnik, long long int nazivnik){ //konstruktor sa dva parametra
    if(nazivnik==0) throw logic_error("Nekorektan razlomak");
    long long int p=NZD(brojnik, nazivnik);
    if(nazivnik<0 && brojnik>0) {
        Razlomak::brojnik=(brojnik/p)*(-1);
        Razlomak::nazivnik=(nazivnik/p)*(-1);
    }
    else if(nazivnik<0 && brojnik<0){
        Razlomak::brojnik=(brojnik/p)*(-1);
        Razlomak::nazivnik=(nazivnik/p)*(-1);
    }
    else {
    Razlomak::brojnik=brojnik/p;
    Razlomak::nazivnik=nazivnik/p;
    }
}
    Razlomak operator + (const Razlomak &r1, const Razlomak &r2){ //sabiranje
    long long int m=-9223372036854775807; //radi prekoracenja
    long long int M=9223372036854775807;//radi prekoracenja
    long long int y=r2.brojnik/r2.nazivnik,x=r1.brojnik/r1.nazivnik;//radi prekoracenja
    if(y>0 && x>M-y) throw overflow_error("Nemoguce dobiti tacan rezultat");
    if(y<0 && x<m-y) throw overflow_error("Nemoguce dobiti tacan rezultat");
    long long int r=Razlomak::NZD(r1.nazivnik,r2.nazivnik);  
    long long int brojnik=r1.brojnik*(r2.nazivnik/r) + r2.brojnik*(r1.nazivnik/r);
    long long int nazivnik=r1.nazivnik*(r2.nazivnik/r);
    return Razlomak(brojnik, nazivnik);
    }
    Razlomak operator - (const Razlomak &r1, const Razlomak &r2){ //oduzimanje
    long long int m=-9223372036854775807; //radi prekoracenja
    long long int M=9223372036854775807;//radi prekoracenja
    long long int y=r2.brojnik/r2.nazivnik,x=r1.brojnik/r1.nazivnik;//radi prekoracenja
    if(y<0 && x>M-y) throw overflow_error("Nemoguce dobiti tacan rezultat");
    if(y>0 && x<m-y) throw overflow_error("Nemoguce dobiti tacan rezultat");
    long long int r=Razlomak::NZD(r1.nazivnik,r2.nazivnik);  
    long long int brojnik=r1.brojnik*(r2.nazivnik/r) - r2.brojnik*(r1.nazivnik/r);
    long long int nazivnik=r1.nazivnik*(r2.nazivnik/r);
    return Razlomak(brojnik,nazivnik);
    }
    Razlomak operator * (const Razlomak &r1, const Razlomak &r2){ //mnozenje
    long long int m=-9223372036854775807; //radi prekoracenja
    long long int M=9223372036854775807;//radi prekoracenja
    long long int y=r2.brojnik/r2.nazivnik,x=r1.brojnik/r1.nazivnik;//radi prekoracenja
    if(y>0 && (x<m/y || x>M/y)) throw overflow_error("Nemoguce dobiti tacan rezultat");
    if(y<0 && (x==m || (-1)*x>M/((-1)*y) || (-1)*x>m/((-1)*y))) throw overflow_error("Nemoguce dobiti tacan rezultat");
        long long int s=Razlomak::NZD(r1.brojnik,r2.nazivnik), t=Razlomak::NZD(r2.brojnik, r1.nazivnik);
        long long int brojnik=(r1.brojnik/s)*(r2.brojnik/t);
        long long int nazivnik=(r1.nazivnik/t)*(r2.nazivnik/s);
        return Razlomak(brojnik, nazivnik);
    }
    Razlomak operator / (const Razlomak &r1, const Razlomak &r2){ //dijeljenje
    long long int r=Razlomak::NZD(r1.nazivnik,r2.nazivnik),u=Razlomak::NZD(r1.brojnik, r2.brojnik);
    long long int brojnik=(r1.brojnik/u)*(r2.nazivnik/r);
    long long int nazivnik=(r1.nazivnik/r)*(r2.brojnik/u);
    return Razlomak(brojnik, nazivnik);
    }
    Razlomak &Razlomak::operator +=(const Razlomak &r1){ //sabiranje +=
    long long int m=-9223372036854775807; //radi prekoracenja
    long long int M=9223372036854775807;//radi prekoracenja
    long long int y=r1.brojnik/r1.nazivnik,x=brojnik/nazivnik;//radi prekoracenja
    if(y>0 && x>M-y) throw overflow_error("Nemoguce dobiti tacan rezultat");
    if(y<0 && x<m-y) throw overflow_error("Nemoguce dobiti tacan rezultat");
    long long int r=NZD(nazivnik,r1.nazivnik);  
    brojnik=brojnik*(r1.nazivnik/r) + r1.brojnik*(nazivnik/r);
    nazivnik=nazivnik*(r1.nazivnik/r);
    Razlomak(brojnik, nazivnik);
    return *this;
    }
    Razlomak &Razlomak::operator -=(const Razlomak &r1){ //oduzimanje -=
    long long int m=-9223372036854775807; //radi prekoracenja
    long long int M=9223372036854775807;//radi prekoracenja
    long long int y=r1.brojnik/r1.nazivnik,x=brojnik/nazivnik;//radi prekoracenja
    if(y<0 && x>M-y) throw overflow_error("Nemoguce dobiti tacan rezultat");
    if(y>0 && x<m-y) throw overflow_error("Nemoguce dobiti tacan rezultat");
    long long int r=NZD(nazivnik,r1.nazivnik);  
    brojnik=brojnik*(r1.nazivnik/r) - r1.brojnik*(nazivnik/r);
    nazivnik=nazivnik*(r1.nazivnik/r);
    Razlomak(brojnik,nazivnik); 
    return *this;
    }
    Razlomak &Razlomak::operator *=(const Razlomak &r1){//mnozenje *=
    long long int m=-9223372036854775807; //radi prekoracenja
    long long int M=9223372036854775807;//radi prekoracenja
    long long int y=r1.brojnik/r1.nazivnik,x=brojnik/nazivnik;//radi prekoracenja
    if(y>0 && (x<m/y || x>M/y)) throw overflow_error("Nemoguce dobiti tacan rezultat");
    if(y<0 && (x==m || (-1)*x>M/((-1)*y) || (-1)*x>m/((-1)*y))) throw overflow_error("Nemoguce dobiti tacan rezultat");
        long long int s=NZD(brojnik,r1.nazivnik), t=NZD(r1.brojnik,nazivnik);
        brojnik=(brojnik/s)*(r1.brojnik/t);
        nazivnik=(nazivnik/t)*(r1.nazivnik/s);
        Razlomak(brojnik, nazivnik); 
        return *this;
    }
    Razlomak &Razlomak::operator /=(const Razlomak &r1){ //dijeljenje /=
    long long int r=NZD(nazivnik,r1.nazivnik),u=NZD(brojnik, r1.brojnik);
    brojnik=(brojnik/u)*(r1.nazivnik/r);
    nazivnik=(nazivnik/r)*(r1.brojnik/u);
    Razlomak(brojnik, nazivnik);
    return *this;
    }
    Razlomak &Razlomak::operator ++ (){ //++r
        brojnik=brojnik+nazivnik;
        return *this;
    }
    Razlomak Razlomak::operator ++(int){ // r++
        Razlomak pomocni(*this);
        brojnik=brojnik+nazivnik;
        return pomocni;
    }
    Razlomak &Razlomak::operator --(){ // --r
        brojnik=brojnik-nazivnik;
        return *this;
    }
    Razlomak Razlomak::operator --(int){ // r--
        Razlomak pomocni(*this);
        brojnik=brojnik-nazivnik;
        return pomocni;
    }
bool operator !=(const Razlomak &r1, const Razlomak &r2){ // operator !=
long double x=r1.brojnik/r1.nazivnik, y=r2.brojnik/r2.nazivnik;
return x!=y;
}
bool operator ==(const Razlomak &r1, const Razlomak &r2){ // operator ==
        long double x=r1.brojnik/r1.nazivnik, y=r2.brojnik/r2.nazivnik;
        return x==y;
} 
bool operator <(const Razlomak &r1,const Razlomak &r2){
    long long int raz1, raz2;
    raz1=r1.brojnik/r1.nazivnik;
    raz2=r2.brojnik/r2.nazivnik;
    if(raz1<raz2) return true;
    return false;
}

bool operator >(const Razlomak &r1,const Razlomak &r2){
     long long int raz1, raz2;
    raz1=r1.brojnik/r1.nazivnik;
    raz2=r2.brojnik/r2.nazivnik;
    if(raz1>raz2) return true;
    return false;
}

bool operator <=(const Razlomak &r1,const Razlomak &r2){
     long long int raz1, raz2;
    raz1=r1.brojnik/r1.nazivnik;
    raz2=r2.brojnik/r2.nazivnik;
    if(raz1<=raz2) return true;
    return false;
}

bool operator >=(const Razlomak &r1,const Razlomak &r2){
    long long int raz1, raz2;
    raz1=r1.brojnik/r1.nazivnik;
    raz2=r2.brojnik/r2.nazivnik;
    if(raz1>=raz2) return true;
    return false;
}
long long int Razlomak::NZD(long long int x, long long int y){
    if(x%y==0) return y;
    else return NZD(y,x%y);
}
ostream &operator <<(ostream &tok, const Razlomak &r){ //ispis
        if(r.nazivnik==1) tok<<r.brojnik;
        else tok<<r.brojnik<<"/"<<r.nazivnik;
        return tok;
}
istream &operator >>(istream &tok, Razlomak &r){ 
        char znak;
        tok>>ws;
            if(tok.peek()==' ') {tok>>znak; tok.setstate(ios::failbit); }
            if(tok.peek()<'1' || tok.peek()>'9') tok.setstate(ios::failbit);
            tok>>r.brojnik;
            if(tok.peek()==' ' || tok.peek()=='\0' || tok.peek()=='\n' || tok.peek()==-1){r.nazivnik=1;
            return tok; }
            if(tok.peek()!='/' && tok.peek()!='\0') tok.setstate(ios::failbit);
            if(tok.peek()=='\0'){r.nazivnik=1; tok.setstate(ios::failbit); }
            tok>>znak;
            if(tok.peek()<'1' || tok.peek()>'9') tok.setstate(ios::failbit);
            tok>>r.nazivnik;
            if(tok.peek()==' ' || tok.peek()=='\0' || tok.peek()=='\n' || tok.peek()==-1){ 
                long long int n=Razlomak::NZD(r.brojnik,r.nazivnik);
            r.brojnik=r.brojnik/n;
            r.nazivnik=r.nazivnik/n;
                return tok; }
            else tok.setstate(ios::failbit);
            long long int n=Razlomak::NZD(r.brojnik,r.nazivnik);
            r.brojnik=r.brojnik/n;
            r.nazivnik=r.nazivnik/n;
            return tok;
}

int main ()
{
Razlomak r (17, 18), t (21), v(17/18);
            std::cout << "r = " << r << ", t = " << t << ", v = " << v<<endl;
            bool n=r>=v;
            cout<<n<<endl;
	return 0;
}