/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <exception>

using namespace std;

long long int m = -9223372036854775807;
long long int M =  9223372036854775807;

static long long int NZD(long long int a, long long int b){
    if(b == 0) return a;
    else NZD(b, a%b);
}

class Razlomak{
      long long int brojnik;
      long long int nazivnik;
      
    public:
        Razlomak(long long int _brojnik, long long int _nazivnik):brojnik(_brojnik), nazivnik(_nazivnik){
            if(_nazivnik == 0) throw logic_error("Nekorektan razlomak");
            
            long long int djelilac = NZD(brojnik, nazivnik);
            
            if(djelilac != 0){
                brojnik /= djelilac;
                nazivnik /= djelilac;
            }
            
            if(nazivnik < 0){
                nazivnik *= -1;
                brojnik *= -1;
            }
        }
        
        Razlomak(long long int _brojnik){
            brojnik = _brojnik;
            nazivnik = 1;
        }
        
        Razlomak(){
            brojnik = 0;
            nazivnik = 1;
        }
        
        
        long long int DajBrojnik(){
            return brojnik;
        }
        
        long long int DajNazivnik(){
            return nazivnik;
        }
        
        friend istream& operator >> (istream& in, Razlomak &raz);
        operator long double();
        Razlomak& operator++();
        Razlomak& operator--();
        Razlomak operator++(int);
        Razlomak operator--(int);
        friend bool operator<(Razlomak lijevi, Razlomak desni);
        friend bool operator>(Razlomak lijevi, Razlomak densi);
        friend bool operator<=(Razlomak lijevi, Razlomak desni);
        friend bool operator>=(Razlomak lijevi, Razlomak desni);
        friend bool operator==(Razlomak lijevi, Razlomak desni);
        friend bool operator!=(Razlomak lijevi, Razlomak desni);
};

static long long int ProvjerenoSabiranje(long long int x, long long int y){
    if (y > 0){
        if(x > M - y) throw overflow_error("Nemoguce dobiti tacan rezultat");
    }
    else{
        if(x < m - y) throw overflow_error("Nemoguce dobiti tacan rezultat");
    }
    return (x + y);
}

static long long int ProvjerenoOduzimanje(long long int x, long long int y){
    if(y > 0){
        if(x > M + y) throw overflow_error("Nemoguce dobiti tacan rezultat");
    }
    else{
        if(x < m + y) throw overflow_error("Nemoguce dobiti tacan rezultat");
    }
    return (x - y);
}

static long long int ProvjerenoMnozenje(long long int x, long long int y){
    if (y > 0){
        if (x < m / y || x > M / y) throw overflow_error("Nemoguce dobiti tacan rezultat");
    } 
    else{
        if (x == m || -x > M / (-y) || -x < m / (-y)) throw overflow_error("Nemoguce dobiti tacan rezultat");
    }
    return (x*y);
}

Razlomak operator+(Razlomak lijevi, Razlomak desni ){
    long long int r = NZD(lijevi.DajNazivnik(), desni.DajNazivnik());
    
    long long int p1 = lijevi.DajBrojnik();
    long long int q1 = lijevi.DajNazivnik();
    long long int p2 = desni.DajBrojnik();
    long long int q2 = desni.DajNazivnik();
    
    long long int _brojnik = ProvjerenoSabiranje(ProvjerenoMnozenje(p1,(q2/r)),ProvjerenoMnozenje(p2, (q1/r)));
    long long int _nazivnik = ProvjerenoMnozenje(q1, (q2/r));
    
    return Razlomak(_brojnik, _nazivnik);
}

Razlomak operator -(Razlomak raz){
    long long int _brojnik = raz.DajBrojnik() * -1;
    long long int _nazivnik = raz.DajNazivnik();
    return Razlomak( _brojnik, _nazivnik);     
}

Razlomak operator +(Razlomak raz){
    long long int _brojnik = raz.DajBrojnik();
    long long int _nazivnik = raz.DajNazivnik();
    return Razlomak(_brojnik, _nazivnik);
}

Razlomak operator-(Razlomak lijevi, Razlomak desni){
    return(lijevi+(-desni));
}

Razlomak operator*(Razlomak lijevi, Razlomak desni){
    long long int s = NZD(desni.DajNazivnik(), lijevi.DajNazivnik());
    long long int t = NZD(desni.DajBrojnik(), lijevi.DajNazivnik());
    
    long long int p1 = lijevi.DajBrojnik();
    long long int q1 = lijevi.DajNazivnik();
    long long int p2 = desni.DajBrojnik();
    long long int q2 = desni.DajNazivnik();
    
    long long int _brojnik = ProvjerenoMnozenje((p1/s),(p2/t));
    long long int _nazivnik = ProvjerenoMnozenje((q1/t),(q2/s));
    
    return Razlomak(_brojnik, _nazivnik);
}

Razlomak operator/(Razlomak lijevi, Razlomak desni){
    long long int u = NZD(lijevi.DajBrojnik(), desni.DajBrojnik());
    long long int r = NZD(lijevi.DajNazivnik(), desni.DajNazivnik());
    
    long long int p1 = lijevi.DajBrojnik();
    long long int q1 = lijevi.DajNazivnik();
    long long int p2 = desni.DajBrojnik();
    long long int q2 = desni.DajNazivnik();
    
    long long int _brojnik = ProvjerenoMnozenje((p1/u),(q2/r));
    long long int _nazivnik = ProvjerenoMnozenje((q1/r),(p2/u));
    
    return Razlomak(_brojnik, _nazivnik);
}

Razlomak:: operator long double(){
    return static_cast<long double>((long double)brojnik/(long double)nazivnik);
}

ostream& operator<<(ostream& out, Razlomak raz1){
    
    Razlomak raz(raz1.DajBrojnik(), raz1.DajNazivnik());
    if(raz.DajBrojnik()%raz.DajNazivnik() == 0) return out << raz.DajBrojnik()/raz.DajNazivnik();
    else if(raz.DajBrojnik() != 0 && raz.DajNazivnik() != 1) return out << raz.DajBrojnik() << "/" << raz.DajNazivnik();
    else return out << raz.DajBrojnik();
}

istream& operator>>(istream& in, Razlomak &raz){
    char c;
    in >> ws;
    in>>raz.brojnik;
    if(in.peek() != '/'){
        raz.nazivnik = 1;
    }
    else{
        in>>c;
        in>>raz.nazivnik;
    }
    if(in.peek() != ' ') in.setstate(ios::failbit);
    return in;
}

Razlomak operator+=(Razlomak lijevi, Razlomak desni){
    return lijevi + desni;
}

Razlomak operator-=(Razlomak lijevi, Razlomak desni){
    return lijevi - desni;
}

Razlomak operator*=(Razlomak lijevi, Razlomak desni){
    return lijevi * desni;
}

Razlomak operator/=(Razlomak lijevi, Razlomak desni){
    return lijevi / desni;
}

Razlomak& Razlomak:: operator++(){
    brojnik += nazivnik;
}

Razlomak& Razlomak:: operator--(){
    brojnik -= nazivnik;
}

Razlomak Razlomak:: operator++(int){
    Razlomak privremeni(brojnik, nazivnik);
    
    ++(*this);
    
    return privremeni;
}

Razlomak Razlomak:: operator--(int){
    Razlomak privremeni(brojnik, nazivnik);
    --(*this);
    return privremeni;
}

bool operator<(Razlomak lijevi, Razlomak desni){
    long double left = lijevi;
    long double right = desni;
    return (left < right);
}

bool operator>(Razlomak lijevi, Razlomak desni){
    long double left = lijevi;
    long double right = desni;
    return(left > right);
}

bool operator<=(Razlomak lijevi, Razlomak desni){
    long double left = lijevi;
    long double right = desni;
    return (left<=right);
}

bool operator>=(Razlomak lijevi, Razlomak desni){
    long double left = lijevi;
    long double right = desni;
    return (left>=right);
}

bool operator==(Razlomak lijevi, Razlomak desni){
    long double left = lijevi;
    long double right = desni;
    return(left == right);
}

bool operator !=(Razlomak lijevi, Razlomak desni){
    long double left = lijevi; 
    long double right = desni;
    return(left != right);
}

int main ()
{
    Razlomak r1, r2, r3, r4, r5, r6;
    cin >> r1 >> r2 >> r3 >> r4 >> r5 >> r6;
    cout << r1 +r2;
    ++r3;
    cout << (r3) << endl;
    cout << (r4) << endl;
    cout << (r3 + (r4++)) << endl;
    cout << (r4) << endl;
    cout << (r5*r6) << endl;
    cout << (r6 > r1) << endl;
    cout << (r6 == r4) << endl;
    cout << (r3 != r6) << endl;
    cout << (r3 += r2) << endl;
    
	return 0;
}