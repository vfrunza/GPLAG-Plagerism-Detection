/B2017/2018: Zadaća 6, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <algorithm>
class Temperatura {
   int broj_tempi, kapacitet;
   double *pok;
public:
   explicit Temperatura (int max_broj) :broj_tempi(0), kapacitet (max_broj), pok(new double [max_broj]){}
   ~Temperatura () { delete [] pok; }
   Temperatura (const Temperatura &t);
   Temperatura (Temperatura &&t);
   Temperatura &operator = (const Temperatura &t);
   Temperatura &operator = (Temperatura &&t);
   void ObrisiTempe () {
       broj_tempi =0; kapacitet=0;
   }
   void RegistrujNovu (double t) ;
   void Ispisi ();
   double DajMinimalnu () const;   
   double DajMaximalnu () const;
   double DajProsjek () const;
};
Temperatura::Temperatura (const Temperatura &t)  : broj_tempi(t.broj_tempi),kapacitet (t.kapacitet), pok (new double[t.kapacitet]) {
    for (int i=0; i<broj_tempi; i++) 
        pok[i]=t.pok[i];
}
Temperatura::Temperatura (Temperatura &&t) : broj_tempi(t.broj_tempi), kapacitet (t.kapacitet), pok(t.pok) {
    t.pok=nullptr; t.broj_tempi=0; t.kapacitet=0;
}
Temperatura &Temperatura::operator= (const Temperatura &t) {
    if (&t==this) return *this;
    double *novi = new double [t.kapacitet];
    for (int i=0; i<t.broj_tempi; i++) novi[i]=t.pok[i];
    delete [] pok;
    kapacitet = t.kapacitet; broj_tempi = t.broj_tempi;
    pok=novi;
    return *this;
}
Temperatura &Temperatura::operator = (Temperatura &&t) {
    std::swap (broj_tempi, t.broj_tempi); std::swap (kapacitet, t.kapacitet);
    std::swap (pok, t.pok);
    return *this;
}
void Temperatura::RegistrujNovu (double t) {
    if (broj_tempi == kapacitet) throw std::logic_error ("Popunjeno");
    pok[broj_tempi++] = t;
}
double Temperatura::DajMinimalnu () const {
    double min=pok[0];
    for (int i=0; i<broj_tempi; i++ ) {
        if (pok[i]<min) min=pok[i];
    }
    return min;
}
double Temperatura::DajMaximalnu () const {
    double max=pok[0];
    for (int i=0; i<broj_tempi; i++ ) {
        if (pok[i]>max) max=pok[i];
    }
    return max;
}
double Temperatura::DajProsjek () const {
    double suma(0);
    for (int i=0; i<broj_tempi; i++) 
        suma+=pok[i];
    return suma/broj_tempi;
}
void Temperatura::Ispisi () {
    std::sort (pok, pok+broj_tempi, [](double temp1, double temp2) {
        return temp1 > temp2;
    });
    for (int i=0; i<broj_tempi; i++) 
        std::cout << pok[i] << std::endl;
}
int main () {
    Temperatura t (5);
    t.RegistrujNovu (23);
    t.RegistrujNovu (-2);
    t.RegistrujNovu (45);
    t.RegistrujNovu (0);
    Temperatura t1(3);
    t1.RegistrujNovu (22); t1.RegistrujNovu (12);
    t1=t;
    t1.Ispisi ();
 return 0;
}
