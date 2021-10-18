/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <limits>
constexpr long long int MIN = std::numeric_limits<long long int>::min();
constexpr long long int MAX = std::numeric_limits<long long int>::max();

class Razlomak {
    long long int brojnik;
    long long int nazivnik;
    static long long int NZD(long long int br, long long int naz) {
        long long int i = br,pomocna;
        
        
        while(true) {
        if(naz == 0) return i;
        if(i%naz == 1 ) return 1;
        pomocna = i;
        i = naz;
        naz = pomocna%naz;
        
        }
    }
    
    static void izuzetakOverflow() {
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    }
    public:
    Razlomak(long long int br = 0, long long int naz = 1);
    long long int DajBrojnik() const { return brojnik; }
    long long int DajNazivnik() const { return nazivnik; }
    friend Razlomak operator +(const Razlomak &p, const Razlomak &q);
    friend Razlomak operator -(const Razlomak &p, const Razlomak &q);
    friend Razlomak operator *(const Razlomak &p, const Razlomak &q);
    friend Razlomak operator /(const Razlomak &p, const Razlomak &q);
    Razlomak &operator +();
    Razlomak &operator -();
    friend std::ostream &operator <<(std::ostream &tok, const Razlomak &r);
    friend std::istream &operator >>(std::istream &tok, Razlomak &r);
    operator long double();
    Razlomak &operator +=(const Razlomak &q);
    Razlomak &operator -=(const Razlomak &q);
    Razlomak &operator *=(const Razlomak &q);
    Razlomak &operator /=(const Razlomak &q);
    friend Razlomak &operator ++(Razlomak &r);
    friend Razlomak operator ++(Razlomak &r,int);
    friend Razlomak &operator --(Razlomak &r);
    friend Razlomak operator --(Razlomak &r,int);
    friend bool operator <(const Razlomak &p, const Razlomak &q);
    friend bool operator >(const Razlomak &p, const Razlomak &q);
    friend bool operator <=(const Razlomak &p, const Razlomak &q);
    friend bool operator >=(const Razlomak &p, const Razlomak &q);
    friend bool operator ==(const Razlomak &p, const Razlomak &q);
    friend inline bool operator !=(const Razlomak &p, const Razlomak &q);
};
    
    Razlomak::Razlomak(long long int br, long long int naz ) {
      
        if(naz == 0) throw std::logic_error("Nekorektan razlomak");
        else if(naz < 0) { br = br*(-1); naz = naz*(-1); }
        else if( br == naz) {  brojnik = 1; nazivnik = 1; }                          
        else if( br < 0) { br= br*(-1); naz = naz*(-1); }
        
        if(naz == 1){ brojnik = br; nazivnik = naz; }
         else {  auto nazy =  NZD(br,naz);

             brojnik = br/nazy;
             nazivnik = naz/nazy;
         }
        
    }
   
    
   Razlomak operator +(const Razlomak &p, const Razlomak &q) { // trebal friend i 2 par ?
        auto r = Razlomak::NZD(p.nazivnik,q.nazivnik);
        long long int naz;
        long long int br;
        if(p.brojnik*(q.nazivnik/r) > MAX - p.nazivnik*(q.brojnik/r)) Razlomak::izuzetakOverflow();
      //  else if(q.brojnik > MAX/(q.nazivnik/r) || q.brojnik < MIN/)
        br = p.brojnik*(q.nazivnik/r) + q.brojnik*(p.nazivnik/r);
        naz = p.nazivnik*(q.nazivnik/r);
        return {br,naz};
    }
    
     Razlomak operator -(const Razlomak &p, const Razlomak &q) {
        auto r = Razlomak::NZD(p.nazivnik,q.nazivnik);
        long long int naz;
        long long int br;
        br = p.brojnik*(q.nazivnik/r) - q.brojnik*(p.nazivnik/r);
        naz = p.nazivnik*(q.nazivnik/r);
        return {br,naz};
        
    }
    
   Razlomak operator *(const Razlomak &p, const Razlomak &q) {
        auto s =  Razlomak::NZD(p.brojnik,q.nazivnik);
        auto t =  Razlomak::NZD(q.brojnik,p.nazivnik);
        long long int naz;
        long long int br;
        br = (p.brojnik/s)*(q.brojnik/t);
        naz = (p.nazivnik/s)*(q.nazivnik/t);
        return {br,naz};
    }
    
     Razlomak operator /(const Razlomak &p, const Razlomak &q) {
         auto r =  Razlomak::NZD(p.nazivnik,q.nazivnik);
         auto u =  Razlomak::NZD(p.brojnik,q.brojnik);
         long long int naz;
         long long int br;
         br = (p.brojnik/u)*(q.nazivnik/r);
         naz = (p.nazivnik/r)*(q.brojnik/u);
         return {br,naz};
    }
    
    Razlomak &Razlomak::operator +() {
        if(brojnik < 0 && brojnik < MAX*(-1) )  Razlomak::izuzetakOverflow();
        if(nazivnik < 0 && nazivnik < MAX*(-1) )  Razlomak::izuzetakOverflow(); //il svi mijenjaju znak
        
       return *this;
        
    }
    
     Razlomak &Razlomak::operator -() {
      //  if( p.brojnik > 0 && p.brojnik > MAX*(-1))  Razlomak::izuzetakOverflow(); //il min
       // if(p.nazivnik > 0 && p.nazivnik > MAX*(-1))  Razlomak::izuzetakOverflow();
        brojnik *= -1;
        return *this;
       
        
    }
    
     std::ostream &operator <<(std::ostream &tok, const Razlomak &r) {
        if(r.nazivnik == 1) return tok << r.brojnik;
        return tok << r.brojnik << "/" << r.nazivnik ;
    }
    
     std::istream &operator >>(std::istream &tok,  Razlomak &r) {
        char znak;
        long long int br,naz;
        tok >> std::ws; // pojede bjeline
        
        tok >> br;
        if( tok.peek() != '/') {
            r.brojnik = br;
            r.nazivnik = 1;
            return tok;
        }
        tok >> znak; 
        if(znak != '/') tok.setstate(std::ios::failbit);
        tok >> naz;
        if(tok.peek()  != '\n' && tok.peek() != '\t' && tok.peek() != '\f' && tok.peek() != '\v' && tok.peek() != ' ') tok.setstate(std::ios::failbit);
        auto de = Razlomak::NZD(br,naz);
        r.brojnik = br/de;
        r.nazivnik = naz/de;
        
        
        return tok;
    }
    
    Razlomak::operator long double() {
        return ((long double)brojnik)/nazivnik;
    }
    
     Razlomak &Razlomak::operator +=( const Razlomak &q) { //vracal ref na objekat ???
        auto r =  Razlomak::NZD(nazivnik,q.nazivnik);
        
        brojnik = brojnik*(q.nazivnik/r) + q.brojnik*(nazivnik/r);     // hocel bit dobro il ko kod trouglovaa
        nazivnik = nazivnik*(q.nazivnik/r);
        return *this;
        
    }
    
     Razlomak &Razlomak::operator -=( const Razlomak &q) {
        auto r =  Razlomak::NZD(nazivnik,q.nazivnik);
      
        brojnik = brojnik*(q.nazivnik/r) - q.brojnik*(nazivnik/r);
        nazivnik = nazivnik*(q.nazivnik/r);
        return *this;
    }
    
     Razlomak &Razlomak::operator *=( const Razlomak &q) {
        auto s =  Razlomak::NZD(brojnik,q.nazivnik);
        auto t =  Razlomak::NZD(q.brojnik,nazivnik);
       
        brojnik = (brojnik/s)*(q.brojnik/t);
        nazivnik = (nazivnik/s)*(q.nazivnik/t);
        return *this;
    }
    
     Razlomak &Razlomak::operator /=( const Razlomak &q) {
        auto r =  Razlomak::NZD(nazivnik,q.nazivnik);
        auto u =  Razlomak::NZD(brojnik,q.brojnik);
       
        brojnik = (brojnik/u)*(q.nazivnik/r);
        nazivnik = (nazivnik/r)*(q.brojnik/u);
        return *this;
    }
    
    Razlomak &operator ++(Razlomak &r) { //++r prefiksni
       r += 1;
        return r;
    }  
    
     Razlomak operator ++(Razlomak &r,int) { //r++
        Razlomak upomoc(r);
        r+=1;
        return upomoc;
    }
    
     Razlomak &operator --(Razlomak &r) {
        r -= 1;
        return r;
    }
    
     Razlomak operator --(Razlomak &r,int) {
        Razlomak upomoc(r);
        r -= 1;
        return upomoc;
    }
    
    bool operator <(const Razlomak &p, const Razlomak &q) {
        long double prvi,drugi;
        prvi = (long double)p.brojnik/p.nazivnik;
        drugi = (long double)q.brojnik/q.nazivnik;
        return prvi < drugi;
    }
    
     bool operator >(const Razlomak &p, const Razlomak &q) {
        long double prvi,drugi;
        prvi = (long double)p.brojnik/p.nazivnik;
        drugi = (long double)q.brojnik/q.nazivnik;
        return prvi > drugi;
    }
    
     bool operator <=(const Razlomak &p, const Razlomak &q) {
        long double prvi,drugi;
        prvi = (long double)p.brojnik/p.nazivnik;
        drugi = (long double)q.brojnik/q.nazivnik;
        return prvi <= drugi;
    }
    
     bool operator >=(const Razlomak &p, const Razlomak &q) {
        long double prvi,drugi;
        prvi = (long double)p.brojnik/p.nazivnik;
        drugi = (long double)q.brojnik/q.nazivnik;
        return prvi >= drugi;
    }
    
    bool operator ==(const Razlomak &p, const Razlomak &q) {
        long double prvi,drugi;
        prvi = (long double)p.brojnik/p.nazivnik;
        drugi = (long double)q.brojnik/q.nazivnik;
        return prvi == drugi;
    }
    
     inline bool operator != (const Razlomak &p, const Razlomak &q) {
        return !(p == q);
    }
    
   
    








int main ()
{
    try{
    Razlomak obj {10,20};
    Razlomak r(2,20);
    
    std::cout<<obj.DajBrojnik()<<std::endl;
    std::cout<<obj.DajNazivnik()<<std::endl;
    auto r1 = obj + r;
    std::cout<<r1<<std::endl;
    auto r2 = obj - r;
    std::cout << r2 << std::endl;
    auto r3 = obj*r;
    std::cout << r3 << std::endl;
    auto r4 = obj/r;
    std::cout << r4 << "     "<<r4.DajNazivnik()<<std::endl;
    auto pl = +obj;
    std::cout << pl << std::endl;
   auto p1 = -obj;
    std::cout << p1 << std::endl;
    r4 +=obj;
    std::cout << r4 << std::endl;
    r1 -= r;
    std::cout << r1 << std::endl;
    r4 *= obj;
    std::cout << r4 << std::endl;
    obj /=r;
    std::cout << obj << std::endl;
    auto m = obj++;
    std::cout<<obj<<"\n"<<m;
    ++obj;
    std::cout << obj << std::endl;
    auto o = obj--;
    std::cout << obj <<"       "<<o<< std::endl;
    --obj;
    std::cout << obj << std::endl;
     if( o < obj) std::cout << "jes" << std::endl;
     else std::cout << "nije" << std::endl;
     if( o > obj) std::cout << "jes" << std::endl;
     else std::cout << "nije" << std::endl;
     if( o <= obj) std::cout << "jes" << std::endl;
     else std::cout << "nije" << std::endl;
    
     if( o >= obj) std::cout << "jes" << std::endl;
     else std::cout << "nije" << std::endl;
     --o;
     --o;
      std::cout << o << std::endl;
     if( o == obj) std::cout << "jes" << std::endl;
     else std::cout << "nije" << std::endl;
     if( o != obj) std::cout << "jes" << std::endl;
     else std::cout << "nije" << std::endl;
   
  
  
  
  
  
   /* Razlomak r(5);
    ++r;
    std::cout << r << std::endl;*/
    
    }catch(std::overflow_error o) {
        std::cout << o.what() << std::endl;
    }
    
	return 0;
}