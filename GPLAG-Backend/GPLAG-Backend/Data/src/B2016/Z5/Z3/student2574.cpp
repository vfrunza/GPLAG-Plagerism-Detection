/B16/17 (Zadaća 5, Zadatak 3)      1.2 boda
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <utility>
#include <limits>
#include <initializer_list>

#define MAX std::numeric_limits<long long>::max()
#define MIN std::numeric_limits<long long>::min()

class Razlomak {
        long long int brojnik;
        long long int nazivnik;
        static long long int EuklidovAlgoritam (long long int brojnik, long long int nazivnik) {
            if (nazivnik==0)
                return brojnik;
            else     
                return EuklidovAlgoritam(nazivnik,brojnik%nazivnik);
        }
    public :
        Razlomak (long long int brojnik_main=0, long long int nazivnik_main=1) {
            if (nazivnik_main==0)
                throw std::logic_error ("Nekorektan razlomak");
            if (brojnik_main<0 && nazivnik_main<0) { brojnik_main=-brojnik_main; nazivnik_main=-nazivnik_main; };
            if (brojnik_main>0 && nazivnik_main<0) { brojnik_main=-brojnik_main; nazivnik_main=-nazivnik_main; };
            brojnik=brojnik_main;
            nazivnik=nazivnik_main;
            auto NZD (EuklidovAlgoritam(brojnik,nazivnik));
            brojnik/=NZD;
            nazivnik/=NZD;
        }
        Razlomak (std::initializer_list<long long int> lista) : brojnik(0), nazivnik(1) {
            auto it (lista.begin());
            brojnik=*it;
            it++;
            if (brojnik>=0 && it!=lista.end()) nazivnik=*it;
            else if (brojnik>=0 && it==lista.end()) nazivnik=1;
            if (nazivnik==0)  throw std::logic_error ("Nekorektan razlomak");
            if (brojnik<0 && nazivnik<0) { brojnik=-brojnik; nazivnik=-nazivnik; };
            if (brojnik>0 && nazivnik<0) { brojnik=-brojnik; nazivnik=-nazivnik; };
            auto NZD (EuklidovAlgoritam(brojnik,nazivnik));
            brojnik/=NZD;
            nazivnik/=NZD;
        }
        Razlomak (const Razlomak &main_razlomak)  {
            brojnik=main_razlomak.brojnik;
            nazivnik=main_razlomak.nazivnik;
        }
        long long int DajBrojnik () const { return brojnik; }
        long long int DajNazivnik () const { return nazivnik; }
        friend std::ostream& operator << (std::ostream &tok, const Razlomak &raz1); 
        friend std::istream& operator >> (std::istream &tok, Razlomak &raz1);
        friend bool operator == (const Razlomak &prvi, const Razlomak &drugi);
        friend bool operator != (const Razlomak &prvi, const Razlomak &drugi);
        friend bool operator >= (const Razlomak &prvi, const Razlomak &drugi);
        friend bool operator > (const Razlomak &prvi, const Razlomak &drugi);
        friend bool operator <= (const Razlomak &prvi, const Razlomak &drugi);
        friend bool operator < (const Razlomak &prvi, const Razlomak &drugi);
        friend Razlomak &operator += (Razlomak &prvi, const Razlomak &drugi);
        friend Razlomak operator + (const Razlomak &prvi, const Razlomak &drugi);
        friend Razlomak operator + (const Razlomak &raz1);
        friend Razlomak operator ++ (Razlomak &raz1, int);
        friend Razlomak &operator ++ (Razlomak &raz1);
        friend Razlomak &operator -= (Razlomak &prvi, const Razlomak &drugi);
        friend Razlomak operator - (const Razlomak &prvi, const Razlomak &drugi);
        friend Razlomak operator - (Razlomak &raz1);
        friend Razlomak operator -- (Razlomak &raz1, int);
        friend Razlomak &operator -- (Razlomak &raz1);
        friend Razlomak &operator *= (Razlomak &prvi, const Razlomak &drugi);
        friend Razlomak operator * (const Razlomak &prvi, const Razlomak &drugi);
        friend Razlomak &operator /= (Razlomak &prvi, const Razlomak &drugi);
        friend Razlomak operator / (const Razlomak &prvi, const Razlomak &drugi);
        operator long double() const { return (long double)brojnik/nazivnik;}
};
    
    std::ostream& operator << (std::ostream &tok, const Razlomak &raz1) {
        if (raz1.nazivnik==1)
            tok<<raz1.brojnik;
        else if (raz1.brojnik%raz1.nazivnik==0)
            tok<<"1"<<std::endl;
        else 
            tok<<raz1.brojnik<<"/"<<raz1.nazivnik;
        return tok;
    }
    
    std::istream& operator >> (std::istream &tok, Razlomak &raz1) {
        char je_li_broj(0); 
        tok>>std::ws;
        je_li_broj=tok.peek();
        if (je_li_broj<='9' && je_li_broj>='0') { 
            tok >> raz1.brojnik;
            tok.clear();
            raz1.nazivnik=1;
            if (tok.peek() == ' ' || tok.peek()=='nul') { tok.clear(); raz1.nazivnik=1; }
            else if (tok.peek() != '/') tok.setstate(std::ios::failbit);
            else  tok.get();
            if (tok.peek()=='nul' || tok.peek()==' ')
                 raz1.nazivnik=1;
            else if (tok.peek()<='9' && tok.peek()>='0')
                tok>>raz1.nazivnik;
            if (!(tok.peek()==' '))
                tok.setstate(std::ios::failbit);
        }
        else {
            tok.setstate(std::ios::failbit);
        }
        raz1=Razlomak(raz1.brojnik,raz1.nazivnik);
        return tok;
    }
    
    bool operator  == (const Razlomak &prvi, const Razlomak &drugi) {
        return prvi.brojnik==drugi.brojnik && prvi.nazivnik==drugi.nazivnik;
    }
    
    inline bool operator != (const Razlomak &prvi, const Razlomak &drugi) {
        return !(prvi==drugi);
    }
    
    bool operator >= (const Razlomak &prvi, const Razlomak &drugi) {
        return (((long double)(prvi)) >= ((long double)(drugi)));
    }
    
    bool operator > (const Razlomak &prvi, const Razlomak &drugi) {
        return (long double)(prvi) > (long double)(drugi);
    }
    
    bool operator <= (const Razlomak &prvi, const Razlomak &drugi) {
        return (long double)(prvi) <= (long double)(drugi);
    }
    
    bool operator < (const Razlomak &prvi, const Razlomak &drugi) {
        return (long double)(prvi) < (long double)(drugi);
    }
    
    Razlomak &operator += (Razlomak &prvi, const Razlomak &drugi) {
        if (((long double)(drugi))>=0 && ((long double)(prvi) > (MAX - (long double)(drugi))))
            throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
        if (((long double)(drugi))<0 && ((long double)(prvi) < (MIN - (long double)(drugi))))
            throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
        long long int r (Razlomak::EuklidovAlgoritam(prvi.nazivnik,drugi.nazivnik));
        long long int gornji = prvi.brojnik*(drugi.nazivnik/r)+drugi.brojnik*(prvi.nazivnik/r);
        long long int donji = prvi.nazivnik*(drugi.nazivnik/r);
        prvi.brojnik=gornji;
        prvi.nazivnik=donji;
        return prvi;
    }
    
    Razlomak operator + (const Razlomak &prvi, const Razlomak &drugi) {
        Razlomak treci(prvi);
        treci+=drugi;
        treci=Razlomak(treci.brojnik,treci.nazivnik);
        return treci;
    }
    
    Razlomak operator + (const Razlomak &raz1) { 
        return raz1;
    }
    
    Razlomak operator ++ (Razlomak &raz1, int) {
        auto helper(raz1);
        raz1.brojnik++;
        raz1.nazivnik++;
        helper=Razlomak(raz1.brojnik,raz1.nazivnik);
        return helper;
    }

    Razlomak &operator ++ (Razlomak &raz1) {
        raz1.brojnik++; 
        raz1.nazivnik++;
        raz1=Razlomak(raz1.brojnik,raz1.nazivnik);
        return raz1;
    } 
    
    Razlomak &operator -= (Razlomak &prvi, const Razlomak &drugi) {
        if (((long double)(drugi))<0 && ((long double)(prvi) > (MAX - (long double)(drugi))))
            throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
        if (((long double)(drugi))>=0 && ((long double)(prvi) < (MIN - (long double)(drugi))))
            throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
        long long int r = Razlomak::EuklidovAlgoritam(prvi.nazivnik,drugi.nazivnik);
        long long int gornji = prvi.brojnik*(drugi.nazivnik/r)-drugi.brojnik*(prvi.nazivnik/r);
        long long int donji = prvi.nazivnik*(drugi.nazivnik/r);
        prvi.brojnik=gornji;
        prvi.nazivnik=donji;
        return prvi;
    }
    
    Razlomak operator - (const Razlomak &prvi, const Razlomak &drugi) {
        Razlomak treci(prvi);
        treci-=drugi;
        return treci;
    }
    
    Razlomak operator - (Razlomak &raz1) { 
        raz1.brojnik=-raz1.brojnik;
        raz1.nazivnik=-raz1.nazivnik;
        if (raz1.brojnik<0 && raz1.nazivnik<0) { raz1.brojnik=-raz1.brojnik; raz1.nazivnik=-raz1.nazivnik; };
        if (raz1.brojnik>0 && raz1.nazivnik<0) { raz1.brojnik=-raz1.brojnik; raz1.nazivnik=-raz1.nazivnik; };
        raz1=Razlomak(raz1.brojnik,raz1.nazivnik);
        return raz1;
    }
    
    Razlomak operator -- (Razlomak &raz1, int) {
        auto helper(raz1);
        raz1.brojnik--;
        raz1.nazivnik--;
        if (raz1.brojnik<0 && raz1.nazivnik<0) { raz1.brojnik=-raz1.brojnik; raz1.nazivnik=-raz1.nazivnik; };
        if (raz1.brojnik>0 && raz1.nazivnik<0) { raz1.brojnik=-raz1.brojnik; raz1.nazivnik=-raz1.nazivnik; };
        helper=Razlomak(raz1.brojnik,raz1.nazivnik);
        return helper;
    }
    
    Razlomak &operator -- (Razlomak &raz1) {
        raz1.brojnik--;
        raz1.nazivnik--;
        if (raz1.brojnik<0 && raz1.nazivnik<0) { raz1.brojnik=-raz1.brojnik; raz1.nazivnik=-raz1.nazivnik; };
        if (raz1.brojnik>0 && raz1.nazivnik<0) { raz1.brojnik=-raz1.brojnik; raz1.nazivnik=-raz1.nazivnik; };
        raz1=Razlomak(raz1.brojnik,raz1.nazivnik);
        return raz1;
    }
    
    Razlomak &operator *= (Razlomak &prvi, const Razlomak &drugi) {
        if (((long double)(drugi))>0 && ((long double)(prvi) < (MIN / (long double)(drugi))))
            throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
        else if (((long double)(drugi))>0 && ((long double)(prvi) > (MAX / (long double)(drugi))))
            throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
        if (((long double)(drugi))<0 && ((long double)(prvi) == MIN))
            throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
        else if (((long double)(drugi))<0 && (-((long double)(prvi))) < (MIN / (-(long double)(drugi))))
            throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
        long long int s = Razlomak::EuklidovAlgoritam(prvi.brojnik,drugi.nazivnik);
        long long int t = Razlomak::EuklidovAlgoritam(drugi.brojnik,prvi.nazivnik);
        long long int gornji = (prvi.brojnik/s)*(drugi.brojnik/t); 
        long long int donji = (prvi.nazivnik/t)*(drugi.nazivnik/s);
        prvi.brojnik=gornji;
        prvi.nazivnik=donji;
        return prvi;
    }
    
    Razlomak operator * (const Razlomak &prvi, const Razlomak &drugi) {
        Razlomak treci(prvi);
        treci*=drugi;
        return treci;
    }
    
    Razlomak &operator /= (Razlomak &prvi, const Razlomak &drugi) {
        long long int u = Razlomak::EuklidovAlgoritam(prvi.brojnik,drugi.brojnik);
        long long int r = Razlomak::EuklidovAlgoritam(prvi.nazivnik,drugi.nazivnik);
        long long int gornji = (prvi.brojnik/u)*(drugi.nazivnik/r); 
        long int donji = (prvi.nazivnik/r)*(drugi.brojnik/u);
        prvi.brojnik=gornji;
        prvi.nazivnik=donji;
        return prvi;
    }
    
    inline Razlomak operator / (const Razlomak &prvi, const Razlomak &drugi) {
        Razlomak treci(prvi);
        treci/=drugi;
        return treci;
    }

int main () {
    try {
        Razlomak x{5},y{4};
        auto zbir (x+y);
        std::cout<<"         "<<y;
    }
    catch (std::logic_error iz) {
        std::cout<<iz.what(); 
    }
    catch (std::overflow_error iz) {
        std::cout<<iz.what();
    }
	return 0;
}