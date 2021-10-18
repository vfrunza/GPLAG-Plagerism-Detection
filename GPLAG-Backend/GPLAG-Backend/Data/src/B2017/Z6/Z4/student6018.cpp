/B2017/2018: Primjer ispita 13
#include <iostream>
#include <complex>ž
//1

const double pi=3.14;
class Sinusoida {
    double amplituda, frekvencija, faza;
    double NormirajFazu (double f) {
        double ff=f-2*pi*int((f+pi)/(2*pi));
        return ff;
    }
void Normiraj (Sinusoida &s){
     if (s.amplituda<0){
            s.amplituda=-s.amplituda;
            s.faza=NormirajFazu(s.faza+pi);
        }
        else if (s.frekvencija<0){
            s.frekvencija=-s.frekvencija;
            s.faza=NormirajFazu(pi-s.faza);
        } else {
            s.faza=NormirajFazu(s.faza);
        }
}
    
public:
    ~ Sinusoida () {}
    Sinusoida (double a, double f,double ffaza=0) {
        if (a<0){
            amplituda=-a;
            frekvencija=f;
            faza=ffaza+pi;
            faza=NormirajFazu(faza);
        }
        else if (f<0){
            amplituda=a;
            frekvencija=-f;
            faza=pi-ffaza;
            faza=NormirajFazu(faza);
        } else {
            amplituda=a;
            frekvencija=f;
            faza=NormirajFazu(ffaza);
        }
    }
    tip DajAmplitudu () const { return amplituda; }
    tip DajFrekvenciju () const { return frekvencija; }
    tip DajFazu () const { return faza; }
    void Sinusoida (double a){
        if (a<0){
            amplituda=-a;
            faza=ffaza+pi;
            faza=NormirajFazu(faza);
        } else amplituda=a;
        
    }
    void Sinusoida(double f){
        if (f<0){
            frekvencija=-f;
            faza=pi-ffaza;
            faza=NormirajFazu(faza);
    } else { frekvencija=f; }
    }
    void Sinusoida(double ff){
        faza=NormirajFazu(ff);
    }
    friend Sinusoida operator + (const Sinusoida &s1, const Sinusoida &s2){
        if (s1.frekvencija!=s2.frekvencija) throw ("ne mogu se sabirati");
        Sinusoida nova;
        nova.frekvencija=s1.frekvencija;
        std::complex<double> nova_kompleksna;
        nova_kompleksna=polar(s1.amplituda, s1.faza)+polar(s2.amplituda, s2.faza);
        nova.amplituda=abs(nova_kompleksna);
        nova.faza=arg(nova_kompleksna);
        Normiraj (nova);
        return nova;
    }
    friend Sinusoida& operator += (const Sinusoida &s1){
        if (s1.frekvencija!=frekvencija) throw ("ne mogu se sabirati");
        std::complex<double> nova_kompleksna;
        nova_kompleksna=polar(s1.amplituda, s1.faza)+polar(amplituda, faza);
        amplituda=abs(nova_kompleksna);
        faza=arg(nova_kompleksna);
        Normiraj (*this);
        return *this;
    }
    friend Sinusoida operator - (const Sinusoida &s1, const Sinusoida &s2){
        if (s1.frekvencija!=s2.frekvencija) throw ("ne mogu se sabirati");
        Sinusoida nova;
        nova.frekvencija=s1.frekvencija;
        std::complex<double> nova_kompleksna;
        nova_kompleksna=polar(s1.amplituda, s1.faza)-polar(s2.amplituda, s2.faza);
        nova.amplituda=abs(nova_kompleksna);
        nova.faza=arg(nova_kompleksna);
        Normiraj(nova);
        return nova;
    }
    friend Sinusoida& operator -= (const Sinusoida &s1){
        if (s1.frekvencija!=frekvencija) throw ("ne mogu se sabirati");
        std::complex<double> nova_kompleksna;
        nova_kompleksna=polar(s1.amplituda, s1.faza)-polar(amplituda, faza);
        amplituda=abs(nova_kompleksna);
        faza=arg(nova_kompleksna);
        Normiraj (*this);
        return *this;
    }
    friend Sinusoida operator * (const Sinusoida &s1, int broj){
        Sinusoida nova;
        nova.frekvencija=s1.frekvencija;
        nova.faza=s1.faza;
        nova.amplituda=s1.amplituda*broj;
        Normiraj(nova);
        return nova;
    }
    friend Sinusoida& operator *= (const Sinusoida &s1){
        faza=faza+s1.faza;
        amplituda=s1.amplituda*amplituda;
        Normiraj(*this);
        return *this;
    }
    friend Sinusoida& operator /= (const Sinusoida &s1){
        faza=faza-s1.faza;
        amplituda=s1.amplituda/amplituda;
        Normiraj(*this);
        return *this;
    }
    friend Sinusoida operator * (int broj,const Sinusoida &s1){
        Sinusoida nova;
        nova.frekvencija=s1.frekvencija;
        nova.faza=s1.faza;
        nova.amplituda=s1.amplituda*broj;
        Normiraj(nova);
        return nova;
    }
    friend Sinusoida operator / (const Sinusoida &s1, int broj){
        Sinusoida nova;
        nova.frekvencija=s1.frekvencija;
        nova.faza=s1.faza;
        nova.amplituda=s1.amplituda/broj;
        Normiraj(nova);
        return nova;
    }
    double operator () (double t){
        return amplituda*sin(frekvencija*t+faza);
    }
    std::ostream& operator << (std::ostream &tok, const Sinusoida &s){
        tok << "<A=" << s.DajAmplitudu() << ", w=" << s.DajFrekvenciju();
        if (s.DajFazu()==0) tok << ">";
        else tok << ", phi=" << s.DajFazu() << ">";
        
        return tok;
    }
};


//2
class Apstraktna {
    double tezina;
public:
    Apstraktna (double tezina) : tezina(tezina) {}
    double DajSpecificnuTezinu () { return tezina; }
    virtual double DajZapreminu () const = 0;
    virtual double DajTezinu () const = 0;
    virtual void Ispisi () const = 0;
    virtual Apstraktna* DajKopiju () const = 0;
};

class Kvadar : Apstraktna {
    double a,b,c;
public:
    Kvadar (double tezina, double a, double b, double c) : Apstraktna(tezina), (a), b(b); c(c) {}
    double DajA () const { return a; }
    double DajB () const { return b; }
    double DajC () const { return c; }
    double DajZapreminu () const override { return a*b*c; }
    double DajTezinu () const override { return DajSpecificnuTezinu()*DajZapreminu(); }
    void Ispisi () const override {
        std::cout << "Duzine kvadra a,b,c su redom:" << DajA()  << " "<< DajB() << " " << DajC() << std::endl;
    }
    Apstraktna* DajKopiju () const override {
        return new Kvadar (*this);
    }
};

class Lopta : Apstraktna {
    double r;
public:
    Lopta (double tezina, double r) : Apstraktna(tezina), r(r) {}
    double Dajr () const { return r; }
    double DajZapreminu () const override { return (4*r*r*r*3.14)/3; }
    double DajTezinu () const override { return DajSpecificnuTezinu()*DajZapreminu(); }
    void Ispisi () const override {
        std::cout << "Poluprecnik lopte je " << Dajr() << std:endl;
    }
    Apstraktna* DajKopiju() const override {
        return new Lopta(*this);
    }
};

class Valjak : Apstraktna {
    double R,h;
public:
    Valjak (double tezina, double R, double h) : Apstraktna(tezina), R(R), h(h) {}
    double DajR () const { return R; }
    double DajVisinu () const { return h; }
    double DajZapreminu () const override { return h*R*R*3.14; }
    double DajTezinu () const override { return DajSpecificnuTezinu()*DajZapreminu(); }
    void Ispisi () const override {
        std::cout << " Poluprecnik baze i visina valjka su redom: " << DajR() << " " << DajVisinu() << std::endl;
    }
    Apstraktna* DajKopiju () const override {
        return new Valjak(*this);
    }
};

//napomena za tezinu: moglo se uraditi i tako da se odmah zada specificna tezina
//pa da se onda u konstruktorima nalaze samo parametri kvadra, lopte ili valjka
//ostavimo sada ovako, da se uvijek zadaje specificna duzina tijela
class Kontejner {
    std::vector <Apstraktna*> v;
//obzirom da se ne navodi da se ne smije raditi pametnim pokazivacima, mogli smo cak pojednostaviti i raditi s njima
public:
    ~ Kontejner () {
        for (auto x : v)
            delete x;
    }
    Kontejner () {/* v.size()=0;*/ } //ili čak prazne zagrade
    void DodajKvadar (double tezina, double a, double b, double c){
       // v.push_back(new Apstraktna(Kvadar (tezina,a,b,c)));  
       v.push_back(new Kvadar(tezina,a,b,c));
    }
    void DodajLoptu (double tezina, double r){
        //v.push_back(new Apstraktna(Lopta(tezina,r)));
        v.push_back((new Lopta(tezina,r)));
    }
    void DodajValjak (double tezina, double a, double b){
        //v.push_back(new Apstraktna(Valjak(tezina,a,b)));
        v.push_back(new Valjak(tezina,a,b));
    }
    int DajVelicinuKolekcije () const {
        return v.size();
    }
    Kontejner(const Kontejner &k){
        for (auto x : k){
            //v.push_back(new Apstraktna(x->DajKopiju()));
            v.push_back(x->DajKopiju());
        }
    }
    Kontejner(Kontejner &&k){
        v=k.v;
        k.v.clear();
    }
    Kontejner& operator = (const Kontejner &k){
        for (auto x : v) delete x;
        for (auto x : k.v) v.push_back(new Apstraktna(x->DajKopiju()));
    
        return *this;
    }
    Kontejner& operator = (Kontejner &&k){
        std::swap(v, k.v);
        return *this;
    }
    
    Apstraktna& DajNajtezi () {
        //sorry ermine, zbunim se drugacije
        Apstraktna* najteza=v[0];
        for (int i=1; i<v.size(); i++){
            if (v[i]->DajTezinu()>najteza->DajTezinu()) najteza=v[i];
        }
        return *najteza;
    }
    //analogno uradimo za najlaksi, ili preko fju minimalni i maximalni element
    Apstraktna& operator [] (int broj){
        if (i>v.size()) throw "error";
        for (int i=0; i<v.size(); i++){
            if (i==broj) return *v[i]; //v[i] sam od sebe je pokazivac, pa pošaljemo dereferencirani
        }
        // samo return *v[broj];
    }
    int KolikoImaTezihOd (double tezina){
        return std::count_if(v.begin(),v.end(), [double tezina] (Apstraktna* a1){
                                        return (a1->DajTezinu()>tezina); });
    }
    void Sortiraj (){
        std::sort(v.begin(), v.end(), [] (Apstraktna* a1, Apstraktna* a2){
                                        return (a1->DajTezinu()<a2->DajTezinu());
        });
    }
};

int main ()
{
    std::vector<Apstraktna*> v;
    std::ifstream tok("DAT.TXT");
    for (;;){
        if (!tok) throw ("nema vise");
        char znak;
        tok >> znak;
        if (znak=="K"){
            double tezina,a,b,c;
            
            tok >>tezina >> a >> b >> c;
            v.push_back(new Kvadar(tezina,a,b,c));
        }
        else if (znak=="L"){
            double tezina,r;
            
            tok >> tezina >> r;
            v.push_back(new Lopta(tezina,r));
        }
        else {
            double tezina, a, b;
            
            tok >> tezina >> a >> b;
            v.push_back(new Valjak(tezina,a,b));
        }
    }
    v.Sortiraj();
    for (auto x : v){
        v[i]->Ispisi();
        std::cout >> std::endl;
    }
    
	return 0;
}
