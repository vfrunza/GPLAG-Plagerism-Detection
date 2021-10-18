#include <iostream>
#include <stdexcept>
#include <climits>
#include <cmath>

using namespace std;
                                                    
class Razlomak {
    long long int brojnik,nazivnik;
    void skaliraj(){
      int i=2;
        while(i<=brojnik && i<=nazivnik){
            
            if(brojnik%i==0 && nazivnik%i==0){
                brojnik/=i; nazivnik/=i;
            }
            else i++;
        }
    }
    public:
    Razlomak(long long int b=0,long long int n=1){
        int i=2;
        if(n==0)throw;
        while(i<=b && i<=n){
            
            if(b%i==0 && n%i==0){
                b/=i; n/=i;
            }
            else  i++;
        }
        brojnik=b;
        nazivnik=n;
    }
    
    Razlomak(initializer_list<long long int>  lista){
        if(lista.size()==1)
            *this=Razlomak(*lista.begin(),1);
        else{
            auto it=lista.begin();
            it++;
            *this=Razlomak(*lista.begin(),*it);
        }
    }
    long long int DajBrojnik() const { return brojnik; };
    long long int DajNazivnik() const { return nazivnik; };
    friend Razlomak operator +(Razlomak r1, const Razlomak &r2){
        long long int br=r1.brojnik*r2.nazivnik+r2.brojnik*r1.nazivnik;
        long long int nz=r1.nazivnik*r2.nazivnik;
        Razlomak r3(br,nz);
        r3.skaliraj();
        return r3;
    }
    friend Razlomak operator -(Razlomak r1, const Razlomak &r2){
        long long int br=r1.brojnik*r2.nazivnik-r2.brojnik*r1.nazivnik;
        long long int nz=r1.nazivnik*r2.nazivnik;
        Razlomak r3(br,nz);
        r3.skaliraj();
        return r3;   
    }
    friend Razlomak operator *(Razlomak r1, const Razlomak &r2){
        long long int br=r1.brojnik*r2.brojnik;
        long long int nz=r1.nazivnik*r2.nazivnik;
        Razlomak r3(br,nz);
        r3.skaliraj();
        return r3;
    }
    friend Razlomak operator /(Razlomak r1, const Razlomak &r2){
        
        long long int br=r1.brojnik*r2.nazivnik;
        long long int nz=r1.nazivnik*r2.brojnik;
        Razlomak r3(br,nz);
        r3.skaliraj();
        return r3;
    }
    
    friend Razlomak operator +(const Razlomak &r1){
        Razlomak r2(r1); return r2;
    }
    friend Razlomak operator -(Razlomak &r1){
        Razlomak r2(-r1.brojnik,r1.nazivnik); return r2;
    }
    friend Razlomak &operator +=(Razlomak &r1, const Razlomak &r2){
         r1=r1+r2; return r1;
    }
    friend Razlomak &operator -=(Razlomak &r1, const Razlomak &r2){
         r1=r1-r2; return r1;
    }
    
    friend Razlomak &operator *=(Razlomak &r1, const Razlomak &r2){
         r1=r1*r2; return r1;
    }
    friend Razlomak &operator /=(Razlomak &r1, const Razlomak &r2){
         r1=r1/r2; return r1;
    }
    
    friend Razlomak &operator ++(Razlomak &r1){
            r1.brojnik+=r1.nazivnik;
            r1.skaliraj();
            return r1;
    }
    friend Razlomak &operator --(Razlomak &r1){
            r1.brojnik-=r1.nazivnik;
            r1.skaliraj();
            return r1;
    }
    
    friend Razlomak operator ++(Razlomak &r1, int){
        Razlomak rh=r1;
        r1.brojnik+=r1.nazivnik;
         r1.skaliraj();
        return rh;
    }
    friend Razlomak operator --(Razlomak &r1, int){
        Razlomak rh=r1;
        r1.brojnik-=r1.nazivnik;
          r1.skaliraj();
        return rh;
    }
    
    friend bool operator <(const Razlomak &r1, const Razlomak &r2){
        return r1.brojnik/r1.nazivnik < r2.brojnik/r2.nazivnik;
    }
    friend bool operator >(const Razlomak &r1, const Razlomak &r2){
         return r1.brojnik/r1.nazivnik > r2.brojnik/r2.nazivnik;
    }
    friend bool operator <=(const Razlomak &r1, const Razlomak &r2){
        return !(r1<r2);
    }
    friend bool operator >=(const Razlomak &r1, const Razlomak &r2){
        return !(r1<r2);
    }
    friend bool operator ==(const Razlomak &r1, const Razlomak &r2){
        return !(r1<r2 || r1>r2);
    }
    friend bool operator !=(const Razlomak &r1, const Razlomak &r2){
        return (r1<r2 || r1>r2);
    }
    
    
    friend ostream &operator <<(ostream &tok, const Razlomak &r1){
        if(r1.brojnik==0) return tok<<"0";
        else if(r1.nazivnik==1) return tok<<r1.brojnik;
        else return tok<<r1.brojnik<<"/"<<r1.nazivnik;
    }
    friend istream &operator >>(istream &tok,Razlomak &r1){
        char znak;
        tok>>std::ws;
        tok>>r1.brojnik;
        if(tok.peek()!= '/') { r1.nazivnik=1; return tok; }
        else {
            tok>>znak>>r1.nazivnik;
        }
        if(tok.peek()!=' ' && tok.peek()!='\t' && tok.peek()!='\n' && tok.peek()!='\v' && tok.peek()!='\f') tok.setstate(ios::failbit);
        r1=Razlomak(r1.brojnik,r1.nazivnik);
       
        return tok;
    }
    explicit operator long double() const { 
        return (double)brojnik/nazivnik; }
    
};


int main(){
    Razlomak razlomak(17,15);
    cout<<"Brojnik: "<<razlomak.DajBrojnik()<<",a nazivnik: "<<razlomak.DajNazivnik()<<endl;
    Razlomak r1(15,2), r2(15,2);
    Razlomak r3(r1+r2); cout<<r3.DajBrojnik()<<","<<r3.DajNazivnik()<<endl;
    r3+=r1*r2/r1; cout<<r3.DajBrojnik()<<","<<r3.DajNazivnik()<<endl;
    r3++; r3--; cout<<r3.DajBrojnik()<<","<<r3.DajNazivnik()<<endl;
    
    return 0;
}