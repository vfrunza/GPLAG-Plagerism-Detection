#include <iostream>
#include <string>
#include <stdexcept>

class Datum{
    int dan,mjesec,godina;
    int BrojDana(int mjesec, int godina) {
 int brojdana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
 if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0){
 brojdana[1]++;
 }
 return brojdana[mjesec - 1];
}

public:
Datum(int d, int mj, int god){Postavi(d,mj,god);
}
void Postavi(int d, int mj, int god){
     dan=d;
    mjesec=mj;
    godina=god;
     if(godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > BrojDana(mjesec, godina))
      throw std::domain_error("Neispravan datum!");
}
int DajDan() const{  return dan; }
int DajMjesec() const{ return mjesec; }
int DajGodinu() const{ return godina; }
void Ispisi() const{   std::cout<<dan<<"/"<<mjesec<<"/"<<godina<<std::endl; }
friend class Kupac;
friend class Prodaja;
};




class Kupac{
    std::string imeprezime;
    Datum datumrodjenja;
    
public:
Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja):
datumrodjenja(datum_rodjenja){
    imeprezime=ime_i_prezime;
        for(int i=0;i<ime_i_prezime.length();i++){
        if((ime_i_prezime[i]<'0' && ime_i_prezime[i]>'9') || (ime_i_prezime[i]<'A' && ime_i_prezime[i]>'Z') || (ime_i_prezime[i]>'a' && ime_i_prezime[i]>'z') || (ime_i_prezime[i]!='-') || ime_i_prezime[i]!=39)
 throw std::domain_error ("Neispravno ime i prezime");
}            
}
void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja){
    datumrodjenja=datum_rodjenja;
    imeprezime=ime_i_prezime;
        for(int i=0;i<ime_i_prezime.length();i++){
        if((ime_i_prezime[i]<'0' && ime_i_prezime[i]>'9') || (ime_i_prezime[i]<'A' && ime_i_prezime[i]>'Z') || (ime_i_prezime[i]>'a' && ime_i_prezime[i]>'z') || (ime_i_prezime[i]!='-') || ime_i_prezime[i]!=39)
 throw std::domain_error ("Neispravno ime i prezime");
}
}
std::string DajImePrezime() const{ return imeprezime; }
Datum DajDatumRodjenja() const{ return datumrodjenja; }
void Ispisi() const{ std::cout<<imeprezime<<" ("<<datumrodjenja.dan<<"/"<<datumrodjenja.mjesec<<"/"<<datumrodjenja.godina<<")"; }
friend class Prodaja;
};




class Stan {
    std::string adres;
    int kat;
    int sobe;
    bool namjestaj;
    double kvadrat;
    
    public:
Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){Postavi(adresa,sprat,broj_soba,namjesten,kvadratura);}
void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
    adres=adresa;
    sprat=kat;
    sobe=broj_soba;
    namjestaj=namjesten;
    kvadrat=kvadratura;
    if(sobe<0 || kat<0 || kvadrat<0){
        throw std::domain_error("Neispravan unos podataka");
    }
}
std::string DajAdresu() const{ return adres;}
int DajSprat() const{ return kat; }
int DajBrojSoba() const { return sobe; }
bool DajNamjesten() const{ return namjestaj; }
double DajKvadraturu() const{ return kvadrat; }
void Ispisi() const{
    std::cout<<"Stan se nalazi na adresi "<<adres<<" na "<<kat<<"."<<" spratu i ima "<<sobe;
if(sobe==1) std::cout<<"sobu";
    if(sobe==2 || sobe==3 || sobe==4) std::cout<<"sobe";
    if(sobe>4) std::cout<<"soba";
    std::cout<<std::endl;
    std::cout<<"Kvadratura stana je "<<kvadrat<<" (m^2) i stan ";
    if(namjestaj==1) std::cout<<"je";
    if(namjestaj!=1) std::cout<<"nije";
    std::cout<<" namjesten.";
}
friend class Prodaja;
};



class Prodaja{
   std::string agent;
   double cijena;
   Datum prodaj;
   Kupac kup;
   Stan stann;
   
    public:
Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan):
        prodaj(datum_prodaje),kup(kupac_stana),stann(kupljeni_stan){
            agent=ime_agenta_prodaje;
            cijena=cijena_stana;
        }
        
Prodaja (const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datumrodjenjakupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata):
     prodaj(dan_prodaje,mjesec_prodaje,godina_prodaje),kup(ime_kupca,datumrodjenjakupca), stann(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata) {
    agent=ime_agenta_prodaje;
    cijena=cijena_stana;
}

void PromijeniKupca(const Kupac &novi_kupac){
    kup=novi_kupac;
} 
void PromijeniStan(const Stan &novi_stan){
    stann=novi_stan;
}
void PromijeniDatumKupovine(const Datum &novi_datum){
    prodaj=novi_datum;
}
void PromijeniCijenuProdaje(const double &nova_cijena){
    cijena=nova_cijena;
}
void PomjeriDanUnaprijed(){
    prodaj.dan=prodaj.dan+1;
}
void PomjeriDanUnazad(){
    prodaj.dan=prodaj.dan-1;
}
std::string DajImeAgenta() const{ return agent; }
std::string DajImeKupca() const{
    return kup.imeprezime;
}
Datum DajDatumProdaje() const{
    return prodaj;
}
double DajCijenuStana() const{
    return cijena;
}
friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2){
     if(p1.prodaj.godina<p2.prodaj.godina){
        return true;
    }
    if(p1.prodaj.godina==p2.prodaj.godina){
        if(p1.prodaj.mjesec<p2.prodaj.mjesec){
            return true;
        }
    }
    if(p1.prodaj.godina==p2.prodaj.mjesec){
        if(p1.prodaj.mjesec==p2.prodaj.mjesec){
            if(p1.prodaj.dan<p2.prodaj.dan){
                return true;
            }
        }
    }
    return false;
}

friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2){
    if(p1.cijena>p2.cijena){
        return true;
    }
    return false;
}

void Ispisi() const;
};


int main ()
{
    Datum d1 (12, 3, 2004);
    std::cout<<d1.DajMjesec();
    std::cout<<std::endl;
    std::cout<<d1.DajDan();
	return 0;
}