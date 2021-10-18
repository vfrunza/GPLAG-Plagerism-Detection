/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Datum{
    int dan_atribut, mjesec_atribut, godina_atribut;
    public: 
  Datum(int dan, int mjesec, int godina){ Postavi(dan,mjesec,godina);}
   void Postavi(int d, int m, int g);
   int DajDan() const { return dan_atribut;}
   int DajMjesec() const{ return mjesec_atribut;}
   int DajGodinu() const {return godina_atribut;}
   void Ispisi() const{ cout<<dan_atribut<<"/"<<mjesec_atribut<<"/"<<godina_atribut;}
};
void Datum::Postavi(int d, int m, int g) {
 int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
 if((g % 4 == 0) && (g % 100 != 0 || g % 400 == 0)) broj_dana[1]++;
 int n=(m-1);
 if(g < 1 || d < 1 || m < 1 || m > 12 || d > broj_dana[n]) throw std::domain_error("Neispravan datum");
 dan_atribut = d; mjesec_atribut = m; godina_atribut = g;
}


class Kupac {
    string ime_prezime;
    Datum rodjen;
    public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja) : rodjen(datum_rodjenja) {
    for(int i=0;i<ime_i_prezime.size();i++){
        if(ime_i_prezime[i]< '-' || ime_i_prezime[i] ==  '.'  || ime_i_prezime[i] ==  '/' ||  ime_i_prezime[i]> '9' || ime_i_prezime[i]<'A' || ime_i_prezime[i]>= 'Z' || ime_i_prezime[i]<'a' || ime_i_prezime[i]> 'z' ) throw domain_error ("Neispravno ime i prezime"); 
     
    }
    ime_prezime=ime_i_prezime;
    
}
   
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    string DajImePrezime() const{return ime_prezime;}
    Datum DajDatumRodjenja() const{return rodjen;}
    void Ispisi() const{ cout<<ime_prezime << "("<< rodjen.DajDan() << "/" << rodjen.DajMjesec()<< "/" << rodjen.DajGodinu() << ")";}
};
void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja){
    rodjen = datum_rodjenja;
    for(int i=0;i<ime_i_prezime.size();i++){
        if(ime_i_prezime[i]< '-' || ime_i_prezime[i] ==  '.'  || ime_i_prezime[i] ==  '/' ||  ime_i_prezime[i]> '9' || ime_i_prezime[i]<'A' || ime_i_prezime[i]>= 'Z' || ime_i_prezime[i]<'a' || ime_i_prezime[i]> 'z' ) throw domain_error ("Neispravno ime i prezime"); 
     
    }
    ime_prezime=ime_i_prezime;
    
}
class Stan{
    string adresa_stan;
    int sprat_stan;
    int broj_soba_stan;
    bool namjesten_stan;
    double kvadratura_stan;
public:
Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten,double kvadratura) { Postavi(adresa,  sprat, broj_soba, namjesten, kvadratura); }
void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
std::string DajAdresu() const;
int DajSprat() const{return sprat_stan;}
int DajBrojSoba() const{return broj_soba_stan;}
bool DajNamjesten() const{return namjesten_stan;}
double DajKvadraturu() const{return kvadratura_stan;}
void Ispisi() const; // +
};

void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
    adresa_stan=adresa;
    if(sprat<0) throw domain_error("Neispravan unos podataka");
    sprat_stan=sprat;
    if(broj_soba<0) throw domain_error("Neispravan unos podataka");
    broj_soba_stan=broj_soba;
    namjesten_stan=namjesten;
    if(kvadratura<0) throw domain_error("Neispravan unos podataka");
    kvadratura_stan=kvadratura;
}

class Prodaja{
    string ime;
    double cijena;
    Datum datum_p;
    Kupac kupac_s;
    Stan kupljen;
  
    
    public:
Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,const Datum &datum_prodaje, const Kupac &kupac_stana,const Stan &kupljeni_stan) : datum_p(datum_prodaje) , kupac_s(kupac_stana) , kupljen(kupljeni_stan) {
    
     for(int i=0;i<ime_agenta_prodaje.size();i++){
        if(ime_agenta_prodaje[i]< '-' || ime_agenta_prodaje[i] ==  '.'  || ime_agenta_prodaje[i] ==  '/' ||  ime_agenta_prodaje[i]> '9' || ime_agenta_prodaje[i]<'A' || ime_agenta_prodaje[i]>= 'Z' || ime_agenta_prodaje[i]<'a' || ime_agenta_prodaje[i]> 'z' ) throw domain_error ("Neispravno ime i prezime"); 
     
    }
    ime=ime_agenta_prodaje;
    if(cijena_stana<0) throw domain_error("Neispravan unos podataka");
    cijena_stana=cijena;
    
}
Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca,const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) : datum_p(dan_prodaje,mjesec_prodaje,godina_prodaje), kupac_s(ime_kupca,datum_rodjenja_kupca),kupljen(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata){
     
      for(int i=0;i<ime_agenta_prodaje.size();i++){
        if(ime_agenta_prodaje[i]< '-' || ime_agenta_prodaje[i] ==  '.'  || ime_agenta_prodaje[i] ==  '/' ||  ime_agenta_prodaje[i]> '9' || ime_agenta_prodaje[i]<'A' || ime_agenta_prodaje[i]>= 'Z' || ime_agenta_prodaje[i]<'a' || ime_agenta_prodaje[i]> 'z' ) throw domain_error ("Neispravno ime i prezime"); 
     
    }
    ime=ime_agenta_prodaje;
    if(cijena_stana<0) throw domain_error("Neispravan unos podataka");
    cijena_stana=cijena;
  
}
void PromijeniKupca(const Kupac &novi_kupac){

}
void PromijeniStan(const Stan &novi_stan);
void PromijeniDatumKupovine(const Datum &novi_datum);
void PromijeniCijenuProdaje(const double &nova_cijena);
void PomjeriDanUnaprijed();
void PomjeriDanUnazad();
std::string DajImeAgenta() const;
std::string DajImeKupca() const;
Datum DajDatumProdaje() const;
double DajCijenuStana() const;
friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
void Ispisi() const;
};
int main ()
{
	return 0;
}