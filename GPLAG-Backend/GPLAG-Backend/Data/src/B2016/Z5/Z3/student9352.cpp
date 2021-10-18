/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <cmath>

using namespace std;

class Razlomak{
    long long int brojnik;
    long long int nazivnik;
public:

    Razlomak() { brojnik=0; nazivnik=1; }


    Razlomak(long long int _brojnik) { brojnik=_brojnik; nazivnik=1; }


    Razlomak (long long int _brojnik, long long int _nazivnik)
    {
       if(_nazivnik==0) throw logic_error("Nekorektan razlomak");
       long long int r;
       if(_brojnik<0 && _nazivnik<0)
       {
           r=NZD(-_brojnik,-_nazivnik);
           brojnik=(_brojnik*(-1))/r;
           nazivnik=_nazivnik*(-1)/r;
       }
       else{
           if(_brojnik<0)
           {
                r=NZD(-_brojnik,_nazivnik);
                brojnik=_brojnik/r;
                nazivnik=_nazivnik/r;
           }
           if(_nazivnik<0) 
           {
               r=NZD(_brojnik, -_nazivnik);
               brojnik=_brojnik*(-1)/r;
               nazivnik=_nazivnik*(-1)/r;
           }
           if(_brojnik>0 && _nazivnik> 0)
           {
                r=NZD(_brojnik, _nazivnik);
                brojnik=_brojnik/r;
                nazivnik=_nazivnik/r;
           }
       }
    }
    
    static long long int NZD(long long int _brojnik, long long int _nazivnik)
    {
        for(;;)
        {
            if(_brojnik==0) return _nazivnik;
            _nazivnik %= _brojnik;
            if(_nazivnik==0) return _brojnik;
            _brojnik %= _nazivnik;
        }
    }
    
    Razlomak operator+(const Razlomak &raz2)
    {
        Razlomak rez;
        // raz1 = p1/q1    raz2=p2/q2    
        
        long long int p1{this->brojnik};
        long long int q1{this->nazivnik};
        long long int p2{raz2.brojnik};
        long long int q2{raz2.nazivnik};
        
        long long int nzd1 = NZD(p1,q1);
        long long int nzd2 = NZD(p2,q2);
        p1/=nzd1; q1/=nzd1;
        p2/=nzd2; q2/=nzd2;
        
        long long int r = NZD(q1, q2);
        rez.brojnik = p1*(q2/r) + p2*(q1/r);
        rez.nazivnik = q1*(q2/r);
        
        r=NZD(rez.brojnik, rez.nazivnik);
        rez.brojnik /= r;
        rez.nazivnik /= r;
        return rez;
    }
    
    Razlomak operator-(const Razlomak &raz2)
    {
        Razlomak rez;
        
        long long int p1{this->brojnik};
        long long int q1{this->nazivnik};
        long long int p2{raz2.brojnik};
        long long int q2{raz2.nazivnik};
        
        long long int nzd1 = NZD(p1,q1);
        long long int nzd2 = NZD(p2,q2);
        p1/=nzd1;  q1/=nzd1;
        p2/=nzd2;  q2/=nzd2;
        
        long long int r = NZD(q1, q2);
        rez.brojnik = p1*(q2/r) - p2*(q1/r);
        rez.nazivnik = q1*(q2/r);
        r=NZD(rez.brojnik,rez.nazivnik);
        rez.brojnik /= r;
        rez.nazivnik /= r;
        return rez;
    }
    
    Razlomak operator*(const Razlomak &raz2)
    {
        Razlomak rez;
        
        long long int p1{this->brojnik};
        long long int q1{this->nazivnik};
        long long int p2{raz2.brojnik};
        long long int q2{raz2.nazivnik};
        
        long long int s = NZD(p1, q2);
        long long int t = NZD(p2, q1);
        
        rez.brojnik = (p1/s)*(p2/t);
        rez.nazivnik = (q1/t)*(q2/s);
        t=NZD(rez.brojnik,rez.nazivnik);
        rez.brojnik/=t;
        rez.nazivnik/=t;
        return rez;
    }
    
    Razlomak operator/(const Razlomak &raz2)
    {
        Razlomak rez;
        
        long long int p1{this->brojnik};
        long long int q1{this->nazivnik};
        long long int p2{raz2.brojnik};
        long long int q2{raz2.nazivnik};
        
        long long int r = NZD(q1, q2);
        long long int u = NZD(p1, p2);
        
        rez.brojnik = (p1/u)*(q2/r);
        rez.nazivnik = (q1/r)*(p2/u);
        r = NZD(rez.brojnik,rez.nazivnik);
        rez.brojnik/=r;
        rez.nazivnik/=r;
        return rez;
    }
    
    Razlomak operator-() const
    {
        long long int _brojnik = - this->brojnik;
        Razlomak rez(_brojnik,this->nazivnik);
        return rez;
    }
    
    Razlomak operator+() const
    {
        Razlomak rez = *this;
        return rez;
    }
    
    Razlomak &operator+=(const Razlomak &razl)
    {
        *this = *this + razl;
        return *this;
    }
    
    long long int DajBrojnik() const 
    {
        return brojnik;
    }
    
    long long int DajNazivnik() const
    {
        return nazivnik;
    }
    
    Razlomak &operator-=(const Razlomak &razl)
    {
        *this = *this - razl;
        return *this;
    }
    
    Razlomak &operator*=(const Razlomak &razl)
    {
        *this = *this * razl;
        return *this;
    }
    
    Razlomak &operator/=(const Razlomak &razl)
    {
        *this = *this / razl;
        return *this;
    }
    
    Razlomak &operator++()
    {
        *this = *this + Razlomak(1);
        return *this;
    }
    
    Razlomak operator++(int)
    {
        Razlomak rez(this->brojnik, this->nazivnik);
        ++(*this);
        return rez;
    }
    
    friend ostream &operator<<(ostream &cout, const Razlomak &raz)
    {
        if(raz.nazivnik==1)  return cout<<raz.brojnik;
        return cout<<raz.brojnik<<"/"<<raz.nazivnik;
    }
    
    friend istream &operator>>(istream &cin, Razlomak &raz)
    {
        if(!cin)
        {
            cin.clear();
            cin.ignore(1000,'\n');
        }
        raz.nazivnik=1;
        char kolicnik{'/'};
        cin>>ws;
        cin>>raz.brojnik;
        if(!cin)
        {
            cin.setstate(ios::failbit);
        }
        cin.get(kolicnik);
        if(kolicnik=='/') 
        {
            cin>>raz.nazivnik;
            if(cin.peek()!=' ' && cin.peek()!='\n')  cin.setstate(ios::failbit);
        }
        else if(kolicnik==' ') { cin>>ws; raz.nazivnik=1;}
        else { raz.nazivnik=1; cin.setstate(ios::failbit); return cin; }
        long long int nzd = NZD(raz.brojnik, raz.nazivnik);
        raz.brojnik /= nzd;
        raz.nazivnik /= nzd;
        return cin;
    }
    
    operator long double() const
    {
        long double aproks =  static_cast<long double>(this->brojnik) / static_cast<long double>(this->nazivnik);
        return aproks;
    }
    
    bool operator<(const Razlomak &razl)
    {
        return static_cast<long double>(*this) < static_cast<long double>(razl);
    }
    
    bool operator>(const Razlomak &razl)
    {
        return static_cast<long double>(*this) > static_cast<long double>(razl);
    }
    
    bool operator<=(const Razlomak &razl)
    {
        return static_cast<long double>(*this) <= static_cast<long double>(razl);
    }
    
    bool operator>=(const Razlomak &razl)
    {
        return static_cast<long double>(*this) >= static_cast<long double>(razl);
    }
    
    bool operator==(const Razlomak &razl)
    {
        return static_cast<long double>(*this) == static_cast<long double>(razl);
    }
    
    bool operator!=(const Razlomak &razl)
    {
        return !( *this==razl );
    }
    
};



int main ()
{
    
	return 0;
}