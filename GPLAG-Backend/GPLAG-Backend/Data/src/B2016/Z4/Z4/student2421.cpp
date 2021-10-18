/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include<string>
#include<iomanip>
#include<initializer_list>
#include<stdexcept>
#include<algorithm>
#include<memory>
using namespace std; 

class Datum{
    
  int dan, mjesec, godina; 
  
  public:
  Datum(int d, int m, int g); 
  void Postavi(int d, int m, int g);
  int DajMjesec() const;
  int DajDan() const ;
  int DajGodinu() const;
  void Ispisi() const { cout<<"("<<dan<<"/"<<mjesec<< "/"<<godina<<")"; }

};
 Datum::Datum(int d, int m, int g)
  {
    int broj_dana[] {31, 28, 31, 30,31, 30, 31, 31, 30, 31, 30, 31};
    if((g%4==0 && g%100!=0) || g %400==0)
    broj_dana[1]++;
    if(g <1 || d<1 || m<1 || m>12 || d>broj_dana[m-1]) throw logic_error("Neispravan datum"); 
    dan=d;
    mjesec=m;
    godina=g;
  } 
  void Datum::Postavi(int d, int m, int g)
   {
    int broj_dana[] {31, 28, 31, 30,31, 30, 31, 31, 30, 31, 30, 31};
    if(g%4==0 && g%100!=0 || g %400==0)
    broj_dana[1]++;
    if(g <1 || d<1 || m<1 || m>12 || d>broj_dana[m-1]) throw logic_error("Neispravan datum"); 
    dan=d;
    mjesec=m;
    godina=g;
  }

int Datum::DajMjesec() const{return mjesec; }
int Datum::DajDan() const {return dan; }
int Datum:: DajGodinu() const {return godina;}

 

 class Kupac{
 string ime_i_prezime; 
 Datum datum_rodjenja; 
 
 public: 
 Kupac(const string &ime_i_prezime, const Datum &datum_rodjenja): datum_rodjenja(datum_rodjenja.DajDan(), datum_rodjenja.DajMjesec(), 
 datum_rodjenja.DajGodinu())
 {
  //for(int i=0; i<ime_i_prezime.size(); i++) 
 Kupac::ime_i_prezime=ime_i_prezime; 
 }
 
 void Postavi (const string &ime_i_prezime, const Datum &datum_rodjenja){
  for(int i=0; i<ime_i_prezime.size(); i++) 
  if( ((ime_i_prezime[i]<'A'|| ime_i_prezime[i]>'Z') || (ime_i_prezime[i]<'a'|| ime_i_prezime[i]>'z')
  || (ime_i_prezime[i]<'0'|| ime_i_prezime[i]>'9') || ime_i_prezime[i]=='-' || ime_i_prezime[i]==' ' || ime_i_prezime=="'"))
 Kupac::ime_i_prezime=ime_i_prezime; 
 Kupac::datum_rodjenja.Postavi(datum_rodjenja.DajDan(),datum_rodjenja.DajMjesec(), datum_rodjenja.DajGodinu());
 }
 string DajImePrezime() const{ return ime_i_prezime; }
 Datum DajDatumRodjenja() const {return datum_rodjenja; }
   void Ispisi() const{
     cout<<ime_i_prezime<<"("<<datum_rodjenja.DajDan()<<"/"<<datum_rodjenja.DajMjesec()<<"/"<<datum_rodjenja.DajGodinu()<<")"; 
   }
};

class Stan{
  string adresa;
  int sprat; 
  int broj_soba; 
  bool namjesten;
  double kvadratura; 
  public: 
  Stan (const string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura)
{
  Stan::adresa=adresa; if(sprat<0 || broj_soba<0 || kvadratura<0) throw domain_error("Neispravan unos podatka");
  Stan::sprat=sprat;  
  Stan::broj_soba=broj_soba; 
  Stan::namjesten=namjesten; 
  Stan::kvadratura=kvadratura; 
} 
void Postavi(const string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
  if(sprat<0 || broj_soba<0 || kvadratura<0) domain_error("Neispravan unos podatka"); 
  Stan::adresa=adresa; 
  Stan::sprat=sprat; 
  Stan::broj_soba=broj_soba; 
  Stan::namjesten=namjesten; 
  Stan::kvadratura=kvadratura; 
}
string  DajAdresu() const{return adresa;}
int DajSprat() const {return sprat; } 
int DajBrojSoba() const{return broj_soba; }
bool DajNamjesten() const{return namjesten; }
double DajKvadraturu() const{return kvadratura; }
void Ispisi() const;
};
void Stan::Ispisi() const {
 if(!namjesten){cout<<"Kvadratura stana je "<<kvadratura<<"(m^2) i stan nije namjesten."; }
  if(namjesten){cout<<"Kvadratura stana je "<<kvadratura<<"(m^2) i stan je namjesten.";}
    
 if(broj_soba==1){ cout<<"Stan se nalazi na adresi "<<adresa<<"na "<<sprat<<" spratu i ima 1 sobu."<<endl; }
 if(broj_soba==2 || broj_soba==3 || broj_soba==4){ 
  cout<<"Stan se nalazi na adresi "<<adresa<<" na "<<sprat<<" spratu i ima "<<broj_soba<<" sobe."<<endl; }
 else { cout<<"Stan se nalazi na adresi "<<adresa<<" na "<<sprat<<" spratu i ima "<<broj_soba<<" soba."<<endl; }
}

class Prodaja {
string ime_agenta_prodaja;
double cijena_stana; 
Datum datum_prodaje; 
Kupac kupac_stana; 
Stan kupljeni_stan;

public:
Prodaja(const string &ime_agenta_prodaja, double cijena_stana, const Datum &datum_prodaje, 
const Kupac &kupac_stana,const Stan &kupljeni_stan)
:
ime_agenta_prodaja(ime_agenta_prodaja),
cijena_stana(cijena_stana),
datum_prodaje(datum_prodaje.DajDan(),datum_prodaje.DajMjesec(),datum_prodaje.DajGodinu()),
kupac_stana(kupac_stana.DajImePrezime(),kupac_stana.DajDatumRodjenja()) ,
kupljeni_stan(kupljeni_stan.DajAdresu(),kupljeni_stan.DajSprat(),kupljeni_stan.DajBrojSoba(),kupljeni_stan.DajNamjesten(), kupljeni_stan.DajKvadraturu())
{}

Prodaja(const string &ime_agenta_prodaja, double cijena_stana,
int dan_prodaje, int mjesec_prodaje, int godina_prodaje, 
string &ime_kupca, const Datum &datum_rodjenja_kupca, 
const string &adresa_stana, int sprat_stana, int broj_soba,
bool namjesten_stan, double broj_kvadrata): 
ime_agenta_prodaja(ime_agenta_prodaja), cijena_stana(cijena_stana),
datum_prodaje(dan_prodaje, mjesec_prodaje, godina_prodaje), 
kupac_stana(ime_kupca, datum_rodjenja_kupca), 
kupljeni_stan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata)
{}

void PromijeniKupca(const Kupac & novi_kupac){
 kupac_stana.Postavi(novi_kupac.DajImePrezime(),novi_kupac.DajDatumRodjenja()); }
 void PromijeniDatumKupovine(const Datum &novi_datum){
    datum_prodaje.Postavi(novi_datum.DajDan(), novi_datum.DajMjesec(),novi_datum.DajGodinu()); 
}
void PromijeniStan(const Stan &novi_stan)
{
    kupljeni_stan.Postavi(novi_stan.DajAdresu(),novi_stan.DajSprat(),  novi_stan.DajBrojSoba(),
    novi_stan.DajNamjesten(), novi_stan.DajKvadraturu()); 
}

void PromijeniCijenuProdaje(const double& nova_cijena){
    cijena_stana=nova_cijena; 
} 

string DajImeAgenta() const{return ime_agenta_prodaja;}
string DajImeKupca() const{return kupac_stana.DajImePrezime();}
Datum DajDatumProdaje() const{return datum_prodaje; } 
double DajCijenuStana() const {return cijena_stana; }

//friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2); 
//friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2); 

void PomjeriDanUnaprijed() {
    int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31}; 
    int dan=datum_prodaje.DajDan(),  mjesec=datum_prodaje.DajMjesec(), godina=datum_prodaje.DajGodinu(); 
    if((godina%4==0 && godina%100!=0) || godina %400==0)  
    broj_dana[1]++;
    dan++; 
    if(dan>broj_dana[mjesec-1]) 
    {dan=1; mjesec++;  }
    if(mjesec>12) mjesec=1, godina++; 
    datum_prodaje.Postavi(dan, mjesec, godina); 
}
void PomjeriDanUnazad(){
    int broj_dana[]  {31,28,31,30,31,30,31,31,30,31,30,31}; 
    int dan=datum_prodaje.DajDan(), mjesec=datum_prodaje.DajMjesec(),godina=datum_prodaje.DajGodinu(); 
    if((godina %4==0 && godina%100!=0) || godina%400==0)  broj_dana[1]++;
    dan--; 
    if(dan>0) dan=broj_dana[mjesec-2]; mjesec--; 
    if(mjesec<0) mjesec=12; godina--; 
    
    datum_prodaje.Postavi(dan, mjesec, godina); 
}
 
 void Ispisi() const{
     cout<<"Ime agenta"<<ime_agenta_prodaja<<endl; 
     cout<<"Ime kupca";
     kupac_stana.Ispisi();
     cout<<endl; 
     cout<<"Zakazani datum prodaje";
     datum_prodaje.Ispisi(); 
     cout<<"Cijena stana:"<<cijena_stana<<endl; 
     cout<<"Informacije o stanu: "<<endl; 
     kupljeni_stan.Ispisi(); 
 }
};



class Prodaje{
 int stanje; 
 //initializer_list<Prodaja>stanje; 
 shared_ptr<Prodaje>pok; 
 public: 
 explicit Prodaje();
 
 Prodaje(initializer_list<Prodaja>spisak_prodaja){
    auto it=spisak_prodaja.begin();
 }
 
 Prodaje(const Prodaje &prodaje):
     stanje(prodaje.stanje){} 

 Prodaje(Prodaje && prodaje):stanje(prodaje.stanje), pok(prodaje.pok) {
      prodaje.stanje=0; 
 }
 Prodaje & operator=(const Prodaje &prodaje){
    if(this==&prodaje) return *this; 
    shared_ptr<Prodaje>pok; 
    
    return *this; 
 } 
 Prodaje &operator =(Prodaje && prodaje){
    if(this==&prodaje) return *this; 
    
    stanje=prodaje.stanje; 
    pok=prodaje.pok; 
    return *this; 
    
 }
 int DajBrojProdaja() const; 
 int DajBrojProdajaOdAgenta(const string &ime_agenta) const; 
 Prodaja &DajNajranijuProdaju(); 
 Prodaja DajNajranijuProdaju()const;
Prodaja & DajNajskupljuProdaju();
Prodaja DajNajskupljuProdaju() const;


void ObrisiNajranijuProdaju() {
 if(stanje==0) throw range_error("Prazna kolekcija");
 Datum(1,2,3); 
}

};
int Prodaje::DajBrojProdaja() const{return stanje; }

Prodaja Prodaje::DajNajranijuProdaju() const{
 if(stanje==0) throw domain_error("Nema registiriranih prodaja");
}


Prodaja Prodaje::DajNajskupljuProdaju() const{
 if(stanje==0) throw domain_error("Nema registiriranih prodaja");
}

int main ()
{
 cout<<"Dobrodosli!"; 
 cout<<"Izaberite opciju:"; 
 
 
  Datum d(2,3,1997);
  Kupac k("Amina", d); 
  Prodaje(); 
  k.Ispisi();
	return 0;
}
