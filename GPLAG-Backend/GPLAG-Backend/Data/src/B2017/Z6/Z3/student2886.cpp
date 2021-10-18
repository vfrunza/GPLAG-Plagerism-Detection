/B2017/2018: Primjer ispita 9
#include <iostream>
#include <vector>
#include <memory>
#include <functional>
class GrafickiElement{
public:
    enum Boje {Crvena, Zelena, Zuta, Plava, Ljubicasta, Crna, Bijela};
    friend std::ostream& operator << (std::ostream &tok, const Boje &boja){
        std::vector<std::string> v{"Crvena", "Zelena", "Zuta", "Plava", "Ljubicasta", "Crna", "Bijela"};
        for (int i=0; i<7; i++){
            if (i==boja) tok << v[i];
        }
        return tok;
    }
    GrafickiElement(Boje boja) : boja(boja) {}
    Boje DajBoju() const {  return boja; }
    virtual void Ispisi() const {     std::cout << boja; };     //(3)
    virtual GrafickiElement* DajKopiju () const = 0;                       //(2) 
    virtual double DajPovrsinu () const = 0;
    
private:
    Boje boja;
};
class Tacka : public GrafickiElement{
    double x, y;
public:
    double DajX () const { return x; }
    double DajY () const { return y; }
    Tacka(Boje boja, double x, double y) :
        GrafickiElement(boja), x(x), y(y) {}
    Tacka(double x, double y) : x(x), y(y) { boja=1; }
    void Ispisi() const override {  
        boja.Ispisi();                                            //(3) dodala override zbog odlucivanja koja metoda ISPISI će se ispisati
        std::cout << "{" << x << "," << y << "}";       //dodati za ispis boje ******
        
    }
    friend Tacka operator * (double k, const Tacka &t){        //(7)
        return Tacka(k*t.x, k*t.y);
    }
    friend Tacka operator * ( const Tacka &t, double k){       //(7)
        return Tacka(k*t.x, k*t.y);
    }
    double DajPovrsinu () const override {
        return 0;
    }
};

class Krug : public GrafickiElement {
    double poluprecnik; //imaju boju iz Grafickog elementa
    Tacka t;
public:
    Krug (Boja boja, double poluprecnik, double x, double y) : poluprecnik(poluprecnik), t(boja,x,y) {}
    Krug (Boja boja, double poluprecnik, Tacka t) : poluprecnik(poluprecnik), t(t){}
    Tacka DajCentar () const {
        return  t;
    }
   double DajPovrsinu () const override {
       return poluprecnik*poluprecnik*3.14; //naivno za pi, kolega
   }
   void Ispisi () const override { 
        GrafickiElement::boja.Ispisi();         //dodala ispis ***/
        std::cout << "Krug poluprecnika: " << poluprecnik << " s centrom u (" << t.DajX() << "," <<
        t.DajY() << ")" << std::endl;
   
};
class Poligon : public GrafickiElement {
    int broj_tjemena;
    double *x, *y;
public:

~ Poligon () {
    delete [] x;
    delete [] y;
    broj_tjemena=0;
}

    Poligon (const Poligon &p){
        broj_tjemena=p.broj_tjemena;
        x=new double[broj_tjemena];             //prepravi za niz, pa prekopiraj
        y=new double [broj_tjemena];   
        for (int i=0; i<broj_tjemena; i++){
            x[i]=p.x[i];
            y[i]=p.y[i];
        }
    }
    Poligon (Poligon &&p){
        broj_tjemena=p.broj_tjemena;
        x=p.x;
        y=p.y;                              //(2)
        p.x=nullptr;
        p.y=nullptr;
    }                                                               //da smo radili preko DajKopiju, onda bismo
    Poligon& operator = (const Poligon &p){                         //dobili kopije preko pametnih pokazivaca
        broj_tjemena=p.broj_tjemena;                                //u ovom trenutku ostavimo ovako, jer ćemo metodu
        delete x; delete y;                         //(2)              DajKopiju() koristiti u narednoj klasi koja
        x=new double[broj_tjemena];             //prepravi za niz, pa prekopiraj ****/
        y=new double [broj_tjemena];   
        for (int i=0; i<broj_tjemena; i++){
            x[i]=p.x[i];
            y[i]=p.y[i];
        }
        return *this;
    }
    Poligon& operator = (Poligon &&p){
        std::swap(broj_tjemena, p.broj_tjemena);        //(2)
        std::swap(x,p.x);
        std::swap (y, p.y);
        return *this;
    }
    Poligon(GrafickiElement::Boje boja, int broj_tjemena) : //(2) ovdje vjerovatno provjeriti je li uspjela alokacija ili zamijeniti sa pametnim pokazivačima
        GrafickiElement(boja), broj_tjemena(broj_tjemena){  //(4) radimo izmjenu zbog sigurne alokacije
         try {
             x(new double[broj_tjemena]);
             try { 
                 y(new double[broj_tjemena]);
             } catch (...) {
                 delete [] x;
                 delete [] y;
             }
        }   catch {
                 delete [] x;
            }
    void PostaviTjeme(int redni_broj, double x, double y)               
    {
        Poligon::x[redni_broj - 1] = x;
        Poligon::y[redni_broj - 1] = y;
    }
    void DodajTjeme (int redni, double x, double y){
        if (redni_broj>broj_tjemena) throw "prekoracili opseg";
        Poligon p()
        //kreiraj novi, kopiraj u novi, obrisi niz *********
    }
    void DodajTjeme (int redni, Tacka t){
        //isto lagano, u šta dodajem ? nije konstruktor ?
    }
    void Ispisi() const override                //(3) ovdje isto dodala, zbog odlucivanja koja metoda Ispisi() se ispisuje
    {
        std::cout << "{";
        for(int i = 0 ; i < broj_tjemena; i++) {
            std::cout << "{" << x[i] << "," << y[i] << "}";
            if(i != broj_tjemena - 1) std::cout << ",";
        }
        std::cout << "}";
    }
    
    std::shared_ptr<GrafickiElement> DajKopiju () const override {      //(2)
        return std::make_shared<Poligon> (GrafickiElement::boja, broj_tjemena);
    }
    double DajPovrsinu () const override {
        double suma=0;
        for (int i=2; i<broj_tjemena; i++){
            suma+=(x[0]*(y[i])+x[i]*(y[i]-y[0])+x[i]*(y[0]-y[i]));
        }
        return suma;
    }
    Tacka& operator [] (int broj) const {
        return Tacka(std::ref(a[broj]),std::ref(b[broj]));
    }                                   
};
class GrafickiSistem
{
    std::vector<std::shared_ptr<GrafickiElement>> elementi;
public:
    ~ GrafickiSistem () {} 
                                                    // (1) dodala destruktor, napravila konstruktore i operatore =
    GrafickiSistem() {}                                               
    GrafickiSistem(const GrafickiSistem &v){
        for (auto x : v.elementi){
            elementi.push_back(std::make_shared<GrafickiElement>(x));
        }
    }
    GrafickiSistem (GrafickiSistem &&v){
        elementi=v.elementi;
        v.elementi.clear();
        //ovdje provjeriti da li se treba dodijeliti svaki pametni pok posebno ili ipak ne, jer su pametni? <NE>
    }
    
    GrafickiSistem& operator = (const GrafickiSistem &v){
        if (*this!=v){
        elementi.clear();
        for (auto x : v.elementi){
            elementi.push_back(std::make_shared<GrafickiElement>(x));
        }
        }
        return *this;
    }
    GrafickiSistem& operator = (GrafickiSistem &&v){
        std::swap(elementi, v.elementi);
        return *this;
    }
    void RegistrirajElement(GrafickiElement *e)
    {
        elementi.push_back(std::static_pointer_cast<std::shared_ptr<GrafickiElement>>(e));          // (1) napravila pametni od glupog, pa ga onda ubacila
    }
    void RegistrirajElement(const GrafickiElement &e){
        elementi.push_back(std::make_shared<GrafickiElement>(e));
    }
    void Datotekama (std::string ime){
      std::ifstream tok (ime);
      if (!tok) throw "greska";
         elementi.clear();                   //POSLIJE SVAKOG REDA DODIJELI ELEMENTE I UNESI U VEKTOR ********* 
      int broj_elemenata;
      tok >> broj_elemenata;
for (;;){
      if (!tok) break; 
      char koji_je;
      tok << koji_je;
      if (koji_je=="T"){
          int boja;
          double x,y;
          tok >> boja  >> x >> y;
          elementi.push_back(std::make_shared<Tacka>(boja,x,y));
      }
      else if (koji_je=="P"){
          int boja, tjemena;
          tok >> boja >>  tjemena 
          for (int i=0; i<tjemena; i++){
              double x,y;
              tok >> x >>  y ;
              elementi.push_back(std::make_shared<Poligon>(boja, Tacka(x,y)));
          }
          tok >> pojela;
      }
      else {
          int boja;
          double x,y,poluprecnik;
          tok >> boja  >> x  >> y  >> poluprecnik;
          elementi.push_back(std::make_shared<Krug>(boja,poluprecnik,Tacka(x,y)));
      }
    }
    void IspisiSve()
    {       
        for(int i = 0; i < elementi.size(); i++) {
            elementi[i]->Ispisi();
            std::cout << std::endl;
        }
    }
    
    
    
};
/* ZADATAK 3: Nakon što se pozove metoda IspisiSve, te unutar nje metoda Ispisi() koja ispisuje element, kompajler neće biti u
              mogućnosti da zaključi koju metodu Ispisi() iz koje klase da pozove, jer nisu postavljene kao virtualne. Tada bi 
              program ispisao uvijek metodu Ispisi() iz "prve" klase, tj iz klase GrafickiElement. Nakon izmjene, kompajler je
              u mogućnosti zaključiti iz koje klase poziva metodu Ispisi(), te će se za različite elemente ispisivati različita
              metoda. Prvi put bi se ispisalo samo Crvena, Plava, dok će se nakon izmjene isisati kompletni podaci elemenata. */
              
int main()
{
    GrafickiSistem s;
    s.RegistrirajElement(new Tacka(GrafickiElement::Crvena, 30, 20));
    Poligon *p(new Poligon(GrafickiElement::Plava, 4));
    p->PostaviTjeme(1, 10, 10);
    p->PostaviTjeme(2, 10, 50);
    p->PostaviTjeme(3, 50, 50);
    p->PostaviTjeme(4, 50, 10);
    s.RegistrirajElement(p);
    s.IspisiSve();
}
