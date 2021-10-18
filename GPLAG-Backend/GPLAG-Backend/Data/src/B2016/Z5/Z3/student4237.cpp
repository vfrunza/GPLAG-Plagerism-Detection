#include <stdexcept>
#include <iostream>
#include <string>
#include <map>
#include <limits>
#include <string>
long long int NZD(long long int a,long long int b){
        if((a%b)==0)
            return b;
        return NZD(b,(a%b));
    }
class Razlomak{
    long long int br, naz;
    bool OWF(long long int a, long long int b, char c){
        if(c=='+'){
            if(b<0)
                if(a<std::numeric_limits<long long int>::min()-b)
                    return true;
            if(a>std::numeric_limits<long long int>::max()-b)
                return true;
        }
        if(c=='-'){
            if(b<0)
                if(a<std::numeric_limits<long long int>::max()+b)
                    return true;
            if(a>std::numeric_limits<long long int>::min()+b)
                return true;
            
        }
        if(c=='*'){
            if(b<0)
                if(a==std::numeric_limits<long long int>::min() || -a>std::numeric_limits<long long int>::max()/(-b) || -a<std::numeric_limits<long long int>::min()/(-b))
                    return true;
            if(a<std::numeric_limits<long long int>::min()/b || a>std::numeric_limits<long long int>::max()/b)        
                    return true;
        }
        if(c=='%'){
             if(a==std::numeric_limits<long long int>::min() && (b<=1)) 
                return true;
        }
        return false;
    }
    public:
    Razlomak(long long int a, long long int b);
    Razlomak(long long int a);
    Razlomak();
    Razlomak(std::initializer_list<long long int> lista_timova);
    long long int DajBrojnik() const;
    long long int DajNazivnik() const;
    Razlomak &operator +=(Razlomak &r);
    Razlomak &operator /=(Razlomak &r);
    Razlomak &operator *=(Razlomak &r);
    Razlomak &operator -=(Razlomak &r);
    Razlomak &operator ++();
    Razlomak operator ++(int);
    Razlomak &operator --();
    Razlomak operator --(int);
    friend Razlomak operator +(Razlomak a, Razlomak b);
    friend Razlomak operator -(Razlomak a, Razlomak b);
    friend Razlomak operator *(Razlomak a, Razlomak b);
    friend Razlomak operator /(Razlomak a, Razlomak b);
    friend std::ostream &operator <<(std::ostream &tok, const Razlomak &a);
    friend std::istream &operator >>(std::istream &tok, Razlomak &a);
    operator double(){
        return double(br)/naz;
    }
    long long int operator()(int a)const{
        if(a==1) return br;
        return naz;
    }
    long long int &operator()(int a){
        if(a==1) return br;
        return naz;
    }
};
    Razlomak::Razlomak(long long int a, long long int b){
        if(b==0)
            throw std::logic_error("Nekorektan razlomak");
        auto c=NZD(std::abs(a),std::abs(b));
        if(a<0 && b<0){ 
            a=-a; b=-b;
        }
        else if(a>0 && b<0){
            b=-b; a=-a;
        }
        br=a/c;
        naz=b/c;
    }
    Razlomak::Razlomak(long long int a){
        br=a; naz=1;
    }
    Razlomak::Razlomak(){
        br=0; naz=1;
    }
    Razlomak::Razlomak(std::initializer_list<long long int> lista_timova){
         if(lista_timova.size()==0){
           br=0; naz=1; 
        }
        else if(lista_timova.size()==1){
            br=*(lista_timova.begin());
            naz=1;
        }
        else if(lista_timova.size()==2){
            auto it(lista_timova.begin());
            br=*(it); it++; naz=*it;
        }
        auto c=NZD(br,naz);
        br/=c; naz/=c;
    }
    Razlomak &Razlomak::operator +=(Razlomak &r){
        *this=*this+r;
        return *this;
    }
    Razlomak &Razlomak::operator -=(Razlomak &r){
        *this=*this-r;
        return *this;
    }
    Razlomak &Razlomak::operator *=(Razlomak &r){
        *this=*this*r;
        return *this;
    }
    Razlomak &Razlomak::operator /=(Razlomak &r){
        *this=*this/r;
        return *this;
    }
    Razlomak Razlomak::operator ++(int){
        auto pomocni(*this);
        *this=*this+Razlomak(1);
        return pomocni;
    }
    Razlomak &Razlomak::operator ++(){
         return *this=*this+Razlomak(1);
    }
    Razlomak &Razlomak::operator --(){
        return*this=*this-Razlomak(1);
    }
    Razlomak Razlomak::operator --(int){
         auto pomocni(*this);
        *this=*this-Razlomak(1);
        return pomocni;
        
    }
    long long int Razlomak::DajBrojnik() const{return br;}
    long long int Razlomak::DajNazivnik() const{return naz;}
    Razlomak operator +(Razlomak a, Razlomak b){
        auto r(NZD(a.naz, b.naz));
        return Razlomak((a.br*(b.naz/r)+b.br*(a.naz/r)),(a.naz*(b.naz/r)));
    }
    Razlomak operator -(Razlomak a, Razlomak b){
        auto r(NZD(a.naz, b.naz));
        return Razlomak((a.br*(b.naz/r)-b.br*(a.naz/r)),(a.naz*(b.naz/r)));
    }
    Razlomak operator *(Razlomak a, Razlomak b){
        auto s(NZD(a.br, b.naz)), t(NZD(b.br, a.naz));
        return Razlomak( (a.br/s)*(b.br/t), (a.naz/t)*(b.naz/s));
    }
    Razlomak operator/ (Razlomak a, Razlomak b){
        auto u(NZD(a.br, b.br)), r(NZD(a.naz, b.naz));
        return Razlomak( (a.br/u)*(b.br/r), (a.naz/r)*(b.naz/u));
    }
    std::ostream &operator <<(std::ostream &tok, const Razlomak &a){
        tok<<a.br<<"/"<<a.naz;
        return tok;
    }  
    std::istream &operator >>(std::istream &tok, Razlomak &a){
        char kosa;
        tok>>a.br>>kosa>>a.naz;
        return tok;
    }  

/*long long int operator *(long long int x, long long int y){
    if(OWF(x,y,'*')) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    return x*y;
}
long long int operator +(long long int x, long long int y){
    if(OWF(x,y,'+')) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    return x+y;
}
long long int operator -(long long int x, long long int y){
    if(OWF(x,y,'-')) throw std::overflow_error("Nemoguce dobiti tacan rezultat");        
    return x-y;
}
long long int operator %(long long int x, long long int y)*/
int main ()
{
    Razlomak r(27,100);
    std::cout<< double(r) << std::endl;
    r(1)=10;
	std::cout << r(2) << std::endl;
	return 0;
}