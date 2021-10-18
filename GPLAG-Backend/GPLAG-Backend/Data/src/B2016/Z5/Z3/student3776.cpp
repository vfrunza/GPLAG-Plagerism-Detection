#include <iostream>
#include <cmath>
#include <stdexcept>
#include <limits>

const double eps(1e-10);



 long long int M=std::numeric_limits<long long int>::max();
     long long int m=std::numeric_limits<long long int>::lowest();
        
class Razlomak{
    
    static bool Jednakii(double x,double y){
		if(std::fabs(x-y)<=eps*(std::fabs(x)+std::fabs(y))) {return true;}
		return false;
    }
    
    static int NZD(long long int br,long long int nz){
        for(;;){
            if(br==0) return nz;
            nz%=br;
            if(nz==0) return br;
            br%=nz;
        }
    }
    static void OverPlusMinus(long long int operand_1,long long int operand_2){
        if((operand_2>0 && operand_1>M-operand_2) || ( operand_2<0 &&  operand_1<m-operand_2)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    }
    static void Overputa(long long int operand_1,long long int operand_2){
        if(( operand_2>0 && (operand_1<(m/operand_2) || operand_1>(M/operand_2))) || ((operand_2<0 && (operand_1==m || -operand_1>(M/operand_2) || -operand_1<(m/-operand_2) )) ))  throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    }
    long long int brojnik,nazivnik;
    public:
    Razlomak (long long int x,long long int y){Postavi (x,y);}
    Razlomak(long long int jedan) { brojnik=jedan; nazivnik=1;}
    Razlomak (){brojnik=0; nazivnik=1;}
    Razlomak(const Razlomak &r){   Postavi(r.brojnik,r.nazivnik);}
     void Postavi(long long int a,long long int b);
    void Ispisi() const {std::cout<<"("<<brojnik<<","<<nazivnik<<")";}
    long long int DajBrojnik() const {return brojnik;}
    long long int DajNazivnik() const { return nazivnik;}
    friend std::ostream &operator << (std::ostream &tok,const Razlomak &r);
    friend Razlomak operator +(const Razlomak &r1,const Razlomak &r2);
    friend Razlomak operator -(const Razlomak &r1,const Razlomak &r2);
    friend Razlomak operator *(const Razlomak &r1,const Razlomak &r2);
    friend Razlomak operator /(const Razlomak &r1,const Razlomak &r2);
    friend std::istream &operator >> (std::istream &tok,Razlomak &r);
    friend Razlomak operator + (const Razlomak &r) { return r;}
    friend Razlomak operator -(const Razlomak &r){ if((-r.brojnik>M || -r.brojnik<m ) || (-r.nazivnik>M || -r.nazivnik<m)) throw std::overflow_error("Nemoguce dobiti tacan rezultat"); else return Razlomak(-r.brojnik,-r.nazivnik);}
    friend Razlomak operator +=(Razlomak &r1,const Razlomak &r2);
    friend Razlomak operator -=(Razlomak &r1,const Razlomak &r2);
    friend Razlomak operator *=(Razlomak &r1,const Razlomak &r2);
    friend Razlomak operator /=(Razlomak &r1,const Razlomak &r2);
    friend Razlomak &operator ++(Razlomak &r){
        Razlomak pomocni(1);
        r+=pomocni;
        return r;
    }
    friend Razlomak operator ++(Razlomak &r,int){
        Razlomak pomochni(r);
       /* Razlomak pomoc(1);
        r+=pomoc;*/
       return pomochni;
    }
    
      friend Razlomak &operator --(Razlomak &r){
        Razlomak pomocni(1);
        r-=pomocni;
        return r;
    }
    friend Razlomak operator --(Razlomak &r,int){
        Razlomak pomochni(r);
       /* Razlomak pomoc(1);
        r+=pomoc;*/
        return pomochni;
    }
    
    friend bool operator < (const Razlomak &r1,const Razlomak &r2){
        return (((long double)r1.brojnik/r1.nazivnik<(long double)r2.brojnik/r2.nazivnik) && !Jednakii((long double)r1.brojnik/r1.nazivnik,(long double)r2.brojnik/r2.nazivnik) );
    }
    
    friend bool operator > (const Razlomak &r1,const Razlomak &r2){
        return (((long double)r1.brojnik/r1.nazivnik>(long double)r2.brojnik/r2.nazivnik) && !Jednakii((long double)r1.brojnik/r1.nazivnik,(long double)r2.brojnik/r2.nazivnik) );
    }
    friend bool operator <= (const Razlomak &r1,const Razlomak &r2){
        return (((long double)r1.brojnik/r1.nazivnik<=(long double)r2.brojnik/r2.nazivnik) || Jednakii((long double)r1.brojnik/r1.nazivnik,(long double)r2.brojnik/r2.nazivnik) );
    }
    
    friend bool operator >= (const Razlomak &r1,const Razlomak &r2){
        return (((long double)r1.brojnik/r1.nazivnik>=(long double)r2.brojnik/r2.nazivnik) || Jednakii((long double)r1.brojnik/r1.nazivnik,(long double)r2.brojnik/r2.nazivnik) );
    }
    
    friend bool operator == (const Razlomak &r1,const Razlomak &r2){
        return (Jednakii((long double)r1.brojnik/r1.nazivnik,(long double)r2.brojnik/r2.nazivnik) );
    }
    operator long double() const;
    
 
     
    
    

   
};
    std::istream &operator >>(std::istream &tok, Razlomak &a) { 
      char znak; 
      tok >> std::ws;      
         tok >>  a.brojnik ;
         znak=std::cin.get();
         if(znak=='/'){
         tok>> a.nazivnik;
         }
         else if(znak!='\n'){
             a.nazivnik=1;
         }
         else{
              tok.setstate(std::ios::failbit);
         }
     return tok; 
    }
    
       void Razlomak::Postavi(long long int a,long long int b) {
        if(b==0) throw std::logic_error("Nekorektan razlomak");
        if(b<0 && a>0 ) { brojnik=-(a/NZD(a,b)); nazivnik=std::abs(b/NZD(a,b));}
        if(b<0 && a<0) { brojnik=std::abs(a/NZD(a,b)); nazivnik=std::abs(b/NZD(a,b)); }
        if(a<0 && b>0) {    brojnik=-(a/NZD(a,b)); nazivnik=b/NZD(a,b);}
        else brojnik=a/NZD(a,b); nazivnik=b/NZD(a,b);
    }
    


    
    
    Razlomak operator +(const Razlomak &r1,const Razlomak &r2){
        int r=Razlomak::NZD(r1.nazivnik,r2.nazivnik);
        Razlomak::OverPlusMinus((r1.brojnik/r1.nazivnik),(r2.brojnik/r2.nazivnik));
        return Razlomak((r1.brojnik*(r2.nazivnik/r)+r2.brojnik*(r1.nazivnik/r)),(r1.nazivnik*(r2.nazivnik/r)));
    }
    
    Razlomak operator -(const Razlomak &r1,const Razlomak &r2){
        int r=Razlomak::NZD(r1.nazivnik,r2.nazivnik);
         Razlomak::OverPlusMinus((r1.brojnik/r1.nazivnik),(r2.brojnik/r2.nazivnik));
        return Razlomak((r1.brojnik*(r2.nazivnik/r)-r2.brojnik*(r1.nazivnik/r)),(r1.nazivnik*(r2.nazivnik/r)));
    }
    
    Razlomak operator *(const Razlomak &r1,const Razlomak &r2){
        int s=Razlomak::NZD(r1.brojnik,r2.nazivnik);
        int t=Razlomak::NZD(r2.brojnik,r1.nazivnik);
        return Razlomak((r1.brojnik/s)*(r2.brojnik/t),(r1.nazivnik/t)*(r2.nazivnik/s));
    }
    
      
    Razlomak operator / (const Razlomak &r1,const Razlomak &r2){
        int s=Razlomak::NZD(r1.brojnik,r2.nazivnik);
        int t=Razlomak::NZD(r2.brojnik,r1.nazivnik);
        int r=Razlomak::NZD(r1.nazivnik,r2.nazivnik);
        int u=Razlomak::NZD(r1.brojnik,r2.brojnik);
        return Razlomak((r1.brojnik/u)*(r2.nazivnik/r),(r1.nazivnik/r)*(r2.brojnik/u));
    }
    
     std::ostream &operator << (std::ostream &tok,const Razlomak &r){
      int t=Razlomak::NZD(r.brojnik,r.nazivnik);
      long long int prvi,drugi;
      prvi=r.brojnik/t; drugi=r.nazivnik/t;
       if(r.brojnik==0  ) {tok<<0;}
       if(r.brojnik>=1 && drugi==1) {tok<<prvi;}
       if(r.brojnik!=0 && drugi>1){ tok<<prvi<<"/"<<drugi;}
       return tok;
    }
     Razlomak operator +=(Razlomak &r1,const Razlomak &r2){
        int r=Razlomak::NZD(r1.nazivnik,r2.nazivnik);
        Razlomak::OverPlusMinus((r1.brojnik/r1.nazivnik),(r2.brojnik/r2.nazivnik));
        r1=Razlomak((r1.brojnik*(r2.nazivnik/r)+r2.brojnik*(r1.nazivnik/r)),(r1.nazivnik*(r2.nazivnik/r)));
        return r1;
    }
    Razlomak operator -=(Razlomak &r1,const Razlomak &r2){
         int r=Razlomak::NZD(r1.nazivnik,r2.nazivnik);
          Razlomak::OverPlusMinus((r1.brojnik/r1.nazivnik),(r2.brojnik/r2.nazivnik));
        r1= Razlomak((r1.brojnik*(r2.nazivnik/r)-r2.brojnik*(r1.nazivnik/r)),(r1.nazivnik*(r2.nazivnik/r)));
        return r1;
    }
    Razlomak operator *=(Razlomak &r1,const Razlomak &r2){
        int s=Razlomak::NZD(r1.brojnik,r2.nazivnik);
        int t=Razlomak::NZD(r2.brojnik,r1.nazivnik);
        Razlomak::Overputa((r1.brojnik/r1.nazivnik),(r2.brojnik/r2.nazivnik));
        r1=Razlomak((r1.brojnik/s)*(r2.brojnik/t),(r1.nazivnik/t)*(r2.nazivnik/s));
        return r1;
    }
    Razlomak operator /=(Razlomak &r1,const Razlomak &r2){
        int s=Razlomak::NZD(r1.brojnik,r2.nazivnik);
        int t=Razlomak::NZD(r2.brojnik,r1.nazivnik);
        int r=Razlomak::NZD(r1.nazivnik,r2.nazivnik);
        int u=Razlomak::NZD(r1.brojnik,r2.brojnik);
        r1= Razlomak((r1.brojnik/u)*(r2.nazivnik/r),(r1.nazivnik/r)*(r2.brojnik/u));
        return r1;
    }
    
       
    Razlomak::operator long double () const{
    return (long double)brojnik/nazivnik;
   }
   
    
    
    
int main ()
{
   Razlomak r;
        std::cin >> r;
        long double p=r;
        std::cout << p<<std::endl;

    
	return 0;
}