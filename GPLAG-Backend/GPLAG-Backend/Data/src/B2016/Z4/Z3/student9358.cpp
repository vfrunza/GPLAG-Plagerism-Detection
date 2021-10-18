/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <new>
#include <memory>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <utility>
#include <stdexcept>
#include <algorithm>
#include <cmath>
#include <iomanip>


class Datum{
    int dan, mjesec, godina;
    
    public:
    Datum(int dan, int mjesec, int godina){ Postavi(dan, mjesec, godina)};
    void Postavi(int dan, int mjesec, int godina);
    int DajDan() const{ return dan; }
    int DajMjesec() const{ return mjesec; }
    int DajGodinu() const{ return godina;}
    void Ispisi() const{ std::cout <<  dan << "/" << mjesec << "/" <<godina; }
};

void Datum::Postavi(int dan, int mjesec, int 
godina){
    int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if(g%4 == 0 && g% 100 != 0 || g%400 == 0) broj_dana[1]++;
    if(g<1 || d<1 || m<1 || m>12 || d > broj_dana[m-1])
      throw std::domain_error("Neispravan datum!");
      Datum::dan= dan; Datum::mjesec=mjesec; Datum::godina=godina;
}


class Kupac{
    std::string ime_i_prezime;
    Datum datum_rodjenja;
    
    bool JelLegitimanZnak(char znak){
        return ( (znak >= 'A' &&  znak <= 'Z') ||  (znak >= 'a' &&  znak <= 'z') || (znak >= '0' &&  znak <= '9') || znak ==' ' || znak == '\'' || znak =='-') 
    }
    void TestImena(std::string ime_i_prezime){// da li treba STATIC,
        for(int i=0; i<ime_i_prezime.lenght(); i++){
            if(! JelLegitimanZnak(ime_i_prezime[i])) throw std::domain_error("Neispravno ime i prezime");
            }
        }
    public:
    
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja){
        Postavi(ime_i_prezime,datum_rodjenja);}
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    
    std::string DajImePrezime() const { 
        TestImena(ime_i_prezime);//moze li ovo ovako
        return ime_i_prezime;
        }
        
    Datum DajDatumRodjenja() const{ return datum_rodjenja;}
    void Ispisi() const { std::cout << DajImePrezime() << "(" << DajDatumRodjenja() << ")";
};

void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja):
               datum_rodjenja(datum_rodjenja) { //nisam siguna da mi je oo dobro
                   Kupac::ime_i_prezime = ime_i_prezime;
}


class Stan {
    std::string adresa;
    int sprat;
    int broj_soba;
    bool namjesten;
    double kvadratura;
    
    public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
        Postavi(adresa, sprat, broj_soba, namjesten, kvadratura);
    }
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
    std::string DajAdresu() const { return adresa;}
    int DajSprat() const{ return sprat;}
    int DajBrojSoba() const{ return broj_soba;}
    bool DajNamjesten() const{ return namjesten;}
    double DajKvadraturu() const{ return kvadraturu;}
    void Ispisi() const(){ 
        if(DajBrojSoba % 10 == 2 || DajBrojSoba % 10 == 3 || DajBrojSoba % 10 == 4){ std::cout << "Stan se nalazi na adresi "<< DajAdresu() << "na " << DajSprat() << "spratu i ima " << DajBrojSoba() << " sobe." << std::endl;
        if(DajNamjesten() ==true) std::cout << "Kvadratura stana je " << DajKvadraturu() << " (m^2) i stan je namjesten."; 
        else std::cout << "Kvadratura stana je " << DajKvadraturu() << " (m^2) i stan nije namjesten.";
        }
        else{
            std::cout << "Stan se nalazi na adresi "<< DajAdresu() << "na " << DajSprat() << "spratu i ima " << DajBrojSoba() << " soba." << std::endl;
        if(DajNamjesten() ==true) std::cout << "Kvadratura stana je " << DajKvadraturu() << " (m^2) i stan je namjesten."; 
        else std::cout << "Kvadratura stana je " << DajKvadraturu() << " (m^2) i stan nije namjesten.";
        }
    
};

void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura):
                                   {
    if( sprat<0 || broj_soba <0 || kvadratura <0) throw std::domain_error("Neispravan unos podataka");
    
}

int main ()
{
    
	return 0;
}