/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>

using namespace std;

class Datum{
    int dan,mjesec,godina;
    int BrojDana(int mjesec,int godina){
        int broj_dana[31,28,31,30,31,30,31,31,30,31,30,31];
        if(godina%4==0 && godina%100!=0 || godina%400==0)
        broj_dana[1]++;
        return broj_dana[mjesec-1];
    }
    public:
    Datum(){
        dan=0;
        mjesec=0;
        godina=0;
    }
    Datum(int dan,int mjesec,int godina){
        if(dan<1 || dan>31 || mjesec<1 || mjesec>12) throw domain_error("Neispravan datum");
        this->dan=dan;
        this->mjesec=mjesec;
        this->godina=godina;
    }
    void Postavi(int dan,int mjesec,int godina){
         if(dan<1 || dan>31 || mjesec<1 || mjesec>12) throw domain_error("Neispravan datum");
        this->dan=dan;
        this->mjesec=mjesec;
        this->godina=godina;
    }
    int DajDan()const{
        return dan;
    }
    int DajMjesec()const{
        return mjesec;
    }
    int DajGodinu()const{
        return godina;
    }
    void Ispisi()const{
        cout<<dan<<"/"<<mjesec<<"/"<<godina<<endl;
    }
};
class Kupac{
    string ime_i_prezime;
    Datum datum_rodjenja;
    public:
    Kupac(){
        ime_i_prezime='\0';
        datum_rodjenja=0;
    }
    Kupac(string &ime_i_prezime,const Datum &datum_rodjenja):datum_rodjenja(dan,mjesec,godina){
        if((ime_i_prezime>='A' && ime_i_prezime<='Z')||(ime_i_prezime>='0' && ime_i_prezime<='9')||(ime_i_prezime==' ')||(ime_i_prezime=='-')){
            ime_i_prezime=this->ime_i_prezime;
            
        }
        else throw domain_error("Neispravno ime i prezime");
    }
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja){
         if((ime_i_prezime>='A' && ime_i_prezime<='Z')||(ime_i_prezime>='0' && ime_i_prezime<='9')||(ime_i_prezime==' ')||(ime_i_prezime=='-')){
            ime_i_prezime=this->ime_i_prezime;
            datum_rodjenja=0;
        }
        else throw domain_error("Neispravno ime i prezime");
    }
std::string DajImePrezime() const{
    return ime_i_prezime;
}
Datum DajDatumRodjenja() const{
    return datum_rodjenja;
}
void Ispisi() const{
    cout<<ime_i_prezime<<" ("<<datum_rodjenja<<")"<<endl;
}

};

class Stan{
  string adresa;
  int sprat;
  int broj_soba;
  bool namjesten;
  double kvadratura;
  public:
  Stan(){
      adresa='\0';sprat=0;broj_soba=0;namjesten=false;kvadratura=0;
  }
  Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten,double kvadratura){
      if(sprat<0 || broj_soba<0 || kvadratura<0) throw domain_error("Neispravan unos podataka");
      adresa=this->adresa;
      this->sprat=sprat;
      this->broj_soba=broj_soba;
      this->namjesten=namjesten;
      this->kvadratura=kvadratura;
  }
void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
     if(sprat<0 || broj_soba<0 || kvadratura<0) throw domain_error("Neispravan unos podataka");
      adresa=this->adresa;
      this->sprat=sprat;
      this->broj_soba=broj_soba;
      this->namjesten=namjesten;
      this->kvadratura=kvadratura;
}
std::string DajAdresu() const{
    return adresa;
}
int DajSprat() const{
    return sprat;
}
int DajBrojSoba() const{
    return broj_soba;
}
bool DajNamjesten() const{
    return namjesten;
}
double DajKvadraturu() const{
    return kvadratura;
}
void Ispisi() const{
    cout<<"Stan se nalazi na adresi "<<adresa<<" na "<<sprat<<". spratu i ima "<<broj_soba<<". soba."<<;
    cout<<"Kvadratura stana je "<<kvadratura<<" (m^2) i stan ";
    if(namjesten)cout<<"je namjesten.";
    else cout<<"nije namjesten.";
}

};

class Prodaja{
    string ime_agenta_prodaje;
    double cijena_stana;
    public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,const Datum &datum_prodaje,const Kupac &kupac_stana,const Stan &kupljeni_stan):datum_prodaje(dan,mjesec,godina),
    kupac_stana(ime_i_prezime,datum_rodjenja),kupljeni_stan(adresa,sprat,broj_soba,namjesten,kvadratura){
        ime_agenta_prodaje=this->ime_agenta_prodaje;
        this->cijena_stana=cijena_stana;
    }
Prodaja(const string &ime_agenta_prodaje,double cijena_stana,int dan_prodaje,int mjesec_prodaje,int godina_prodaje,string &ime_kupca,const Datum &datum_rodjenja_kupca,const string &adresa_stana,int sprat_stana,int broj_soba,bool namjesten_stan,double broj_kvadrata):datum_rodjenja_kupca(dan,mjesec,godina),
dan_prodaje(dan),mjesec_prodaje(mjesec),godina_prodaje(godina),ime_kupca(ime_i_prezime),adresa_stana(adresa),sprat_stana(sprat),broj_soba(broj_soba),namjesten_stan(namjesten),broj_kvadrata(kvadratura){
    ime_agenta_prodaje=this->ime_agenta_prodaje;
    this->cijena_stana=cijena_stana;
}
void PromijeniKupca(const Kupac &novi_kupac){
    novi_kupac.ime_i_prezime=ime_i_prezime;
    novi_kupac.datum_rodjenja=datum_rodjenja;
} 
void PromijeniStan(const Stan &novi_stan){
    novi_stan.adresa=adresa;
    novi_stan.sprat=sprat;
    novi_stan.broj_soba=broj_soba;
    novi_stan.namjesten=namjesten;
    novi_stan.kvadratura=kvadratura;
}
void PromijeniDatumKupovine(const Datum &novi_datum){
    novi_datum.dan=dan;
    novi_datum.mjesec=mjesec;
    novi_datum.godina=godina;
}
void PromijeniCijenuProdaje(const double &nova_cijena){
    nova_cijena=cijena_stana;
}
void PomjeriDanUnaprijed(){
    dan++;
    if(dan>BrojDana(mjesec,godina)) dan=1,mjesec++;
    if(mjesec>12) mjesec=1,godina++;
}
void PomjeriDanUnazad(){
    
}
std::string DajImeAgenta() const{
    return ime_agenta_prodaje;
}
std::string DajImeKupca() const{
    return ime_kupca;
}
Datum DajDatumProdaje() const{
    return datum_prodaje;
}
double DajCijenuStana() const{
    return cijena_stana;
}
friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2){
    if(p1.godina_prodaje<p2.godina_prodaje || p1.mjesec_prodaje<p2.mjesec_prodaje) return true;
    return false;
}
friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2){
    if(p1.cijena_stana>p2.cijena_stana) return true;
    return false;
}
void Ispisi() const;

};


class Prodaje{
    
}

