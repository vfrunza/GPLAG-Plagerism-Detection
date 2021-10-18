#include <iostream>
#include <stdexcept>
#include <iterator>
#include <algorithm>
#include <vector>
#include <utility>
#include <limits>
#include <

class Razlomak
{
    long long int brojnik,nazivnik;
    static int NZD(long long int brojnik_1,long long int nazivnik_1) {
        if( brojnik_1%nazivnik_1 == 0 ) return nazivnik_1;
        return NZD( nazivnik_1, brojnik_1%nazivnik_1 );
    }
    static long long int Saberi(long long int x,long long int y) {
        if((y>0 && std::numeric_limits<long long int>::max() - y < x) || (y<0 && std::numeric_limits<long long int>::lowest() - y > x))
            throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        return x+y;
    }
    static long long int Oduzmi(long long int x,long long int y) {
        if((y>0 && std::numeric_limits<long long int>::max() + y < x) || (y<0 && std::numeric_limits<long long int>::lowest() + y > x))
            throw std::overflow_error("Nemoguce dobiti tacan rezultat"); //provjeriti oduzimanje
        return x-y;
    }
    static long long int Pomnozi(long long int x,long long int y) {
        if((y>0 && std::numeric_limits<long long int>::lowest()/y > x) || (y<0 && std::numeric_limits<long long int>::lowest()==x) || (y<0 && (-x)>std::numeric_limits<long long int>::max()/(-y)) ||(y<0 && (-x) < std::numeric_limits<long long int>::lowest()/(-y)))
            throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        return x*y;
    }
    //nisam sigurna za to
public:
    Razlomak(long long int vrijednost_brojnika=0, long long int vrijednost_nazivnika=1) { //podrazumijevane parametre??
        if(vrijednost_nazivnika==0) throw std::logic_error("Nekorektan razlomak");
        if((vrijednost_brojnika>0 && vrijednost_nazivnika>0)) {
            int k;
            k=NZD(vrijednost_brojnika,vrijednost_nazivnika);
            brojnik=vrijednost_brojnika/k;
            nazivnik=vrijednost_nazivnika/k;
        } else if(vrijednost_brojnika<0 && vrijednost_nazivnika<0) {
            int k;
            k=NZD(vrijednost_brojnika,vrijednost_nazivnika);
            brojnik=(-1)*(vrijednost_brojnika/k);
            nazivnik=(-1)*(vrijednost_nazivnika/k);
        } else if(vrijednost_nazivnika<0 || vrijednost_brojnika<0) {
            int k;
            k=NZD(vrijednost_brojnika,vrijednost_nazivnika);
            brojnik=(-1)*(vrijednost_brojnika/k);
            nazivnik=vrijednost_nazivnika/k;
        }
    }
    Razlomak(std::initializer_list<Razlomak>) {}
    long long int DajBrojnik() const {
        return brojnik;
    }
    long long int DajNazivnik() const {
        return nazivnik;
    }
    Razlomak operator +(Razlomak drugi);//prvi je *this
    Razlomak operator -(Razlomak drugi);
    Razlomak operator *(Razlomak drugi);
    Razlomak operator /(Razlomak drugi);
    Razlomak operator +() {
        return *this;
    }
    Razlomak operator -() { //izuzeak
        return Razlomak(-this->brojnik,this->nazivnik);
    }
    Razlomak operator +=(Razlomak drugi) {
        return *this=*this+drugi;
    }
    Razlomak operator -=(Razlomak drugi) {
        return *this=*this-drugi;
    }
    Razlomak operator *=(Razlomak drugi) {
        return *this= (*this)*drugi;
    }
    Razlomak operator /=(Razlomak drugi) {
        return *this = (*this)/drugi;
    }

    Razlomak operator ++() {
        return Razlomak(this->brojnik+1,this->nazivnik+1);   // je li to uredu??
    }
    Razlomak &operator ++(Razlomak &x) {
        return Razlomak(x.brojnik+1,x.nazivnik+1);
    }
};
Razlomak Razlomak::operator+(Razlomak drugi)
{
    Razlomak zbir;
    int r;
    r=Razlomak::NZD(this->nazivnik,drugi.nazivnik);
    zbir=Razlomak::Pomnozi(Razlomak::Saberi(Razlomak::Pomnozi(this->brojnik,Razlomak::Pomnozi(drugi.nazivnik,1/r)),Razlomak::Pomnozi(drugi.brojnik,Razlomak::Pomnozi(this->nazivnik,1/r))),1/(Razlomak::Pomnozi(this->nazivnik,Razlomak::Pomnozi(drugi.nazivnik,1/r))));
    return zbir; //možda je greska pri množenju!
}
Razlomak Razlomak::operator -(Razlomak drugi)
{
    Razlomak razlika;
    int r;
    r=Razlomak::NZD(this->nazivnik,drugi.nazivnik);
    razlika=Razlomak::Pomnozi(Razlomak::Oduzmi(Razlomak::Pomnozi(this->brojnik,Razlomak::Pomnozi(drugi.nazivnik,1/r)),Razlomak::Pomnozi(drugi.brojnik,Razlomak::Pomnozi(this->nazivnik,1/r))),1/(Razlomak::Pomnozi(this->nazivnik,Razlomak::Pomnozi(drugi.nazivnik,1/r))));
    return razlika; //možda je greska pri množenju!
}
Razlomak Razlomak::operator *(Razlomak drugi)
{
    int s,t;
    Razlomak mnozenje;
    s=Razlomak::NZD(this->brojnik,drugi.nazivnik);
    t=Razlomak::NZD(drugi.brojnik,this->nazivnik);
    mnozenje=Razlomak::Pomnozi(Razlomak::Pomnozi(Razlomak::Pomnozi(this->brojnik,1/s),Razlomak::Pomnozi(drugi.brojnik,1/t)),1/(Razlomak::Pomnozi(Razlomak::Pomnozi(this->nazivnik,1/t),Razlomak::Pomnozi(drugi.nazivnik,1/s))));
    return mnozenje; //proveriti formule
}
Razlomak Razlomak::operator /(Razlomak drugi)
{
    int u,r;
    Razlomak dijeljenje;
    u=Razlomak::NZD(this->brojnik,drugi.brojnik);
    r=Razlomak::NZD(this->nazivnik,drugi.nazivnik);
    dijeljenje=Razlomak::Pomnozi(Razlomak::Pomnozi(Razlomak::Pomnozi(this->brojnik,1/u),Razlomak::Pomnozi(drugi.nazivnik,1/r)),1/Razlomak::Pomnozi(Razlomak::Pomnozi(this->nazivnik,1/r),Razlomak::Pomnozi(drugi.brojnik,1/u)));
    return dijeljenje;
}


int main ()
{
    std::cout<<"RADI, KEEP WORKING!";

    return 0;
}