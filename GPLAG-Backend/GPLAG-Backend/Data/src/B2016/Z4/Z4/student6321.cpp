/B 2016/2017, Zadaća 4, Zadatak 4
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include<string>
#include<stdexcept>
#include<iomanip>
#include<initializer_list>
#include<algorithm>
#include<vector>
#include<memory>
class Datum{
    int dan;
    int mjesec;
    int godina;
    
    public:
    Datum(int dan,int mjesec,int godina){Postavi(dan,mjesec,godina);};
    void Postavi(int dan,int mjesec, int godina);
    int DajDan() const{return  dan;};
    int DajMjesec() const{return mjesec;};
    int DajGodinu() const{return godina;};
    void Ispisi() const{std::cout<<dan<<"/"<<mjesec<<"/"<<godina;};
};
void Datum::Postavi(int dan,int mjesec,int godina){
    int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if((godina%4==0 && godina%100!=0) || godina%400==0) broj_dana[1]++;
    if(godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>broj_dana[mjesec-1])
    throw std::domain_error("Neispravan datum");
    
    Datum::dan=dan;Datum::mjesec=mjesec;Datum::godina=godina;
}

class Kupac{
    
    std::string ime_i_prezime;
    Datum datum_rodjenja;
    
    static void IspravnoIme(std::string s);
    
    public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja);//{Postavi(const std::string &ime_i_prezime,const Datum &datum_rodjenja);};
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    std::string DajImeIPrezime() const{return ime_i_prezime;};
    Datum DajDatumRodjenja() const{return datum_rodjenja;};
    void Ispisi() const{std::cout<<ime_i_prezime<<" (";
    datum_rodjenja.Ispisi(); std::cout<<")";};
};

void Kupac::IspravnoIme(std::string s){
     for(int i=0;i<s.length();i++){
        
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='1' && s[i]<='9') || 
        s[i]==' ' || s[i]==39) continue;
        else{ 
            throw std::domain_error("Neispravno ime i prezime");
        }
        
    }
}
 Kupac::Kupac(const std::string &ime_i_prezime,const Datum &datum_rodjenja): datum_rodjenja(datum_rodjenja) {
    IspravnoIme(ime_i_prezime);
    Kupac::ime_i_prezime=ime_i_prezime;
    
}
void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja){
    
    IspravnoIme(ime_i_prezime);
    Kupac::ime_i_prezime=ime_i_prezime;
    Kupac::datum_rodjenja=datum_rodjenja;
}

class Stan{
    
    std::string adresa;
    int sprat;
    int broj_soba;
    bool namjesten;
    double kvadratura;
    
    public:
    Stan(const std::string &adresa,int sprat,int broj_soba,bool namjesten, double kvadratura){ Postavi(adresa,sprat,broj_soba,namjesten,kvadratura);};
    void Postavi(const std::string &adresa,int sprat, int broj_soba, bool namjesten,double kvadratura);
    std::string DajAdresu() const{return adresa;};
    int DajSprat() const{return sprat;};
    int DajBrojSoba() const{return broj_soba;};
    bool DajNamjesten() const{return namjesten;};
  double DajKvadraturu() const{return kvadratura;};
    void Ispisi() const;
};
void Stan::Postavi(const std::string &adresa,int sprat,int broj_soba,bool namjesten,double kvadratura){
    if(sprat<0 || broj_soba<0 || kvadratura<0) throw std::domain_error("Neispravan unos podataka");
    
    Stan::adresa=adresa; Stan::sprat=sprat; Stan::broj_soba=broj_soba; Stan::namjesten=namjesten; Stan::kvadratura=kvadratura;
    
}
void Stan::Ispisi()const{
    
    std::cout<<"Stan se nalazi na adresi "<<adresa<<" na "<<sprat<<". spratu i ima "<<broj_soba;
    if(broj_soba==1) std::cout<<" sobu.";
    if(broj_soba>=2 && broj_soba<=4) std::cout<<" sobe.";
    if(broj_soba>=5) std::cout<<" soba.";
    
    std::cout<<std::endl;
    std::cout<<"Kvadratura stana je "<<kvadratura<<" (m^2) i stan ";
    if(namjesten) std::cout<<"je";
    else std::cout<<"nije";
    
    std::cout<<" namjesten.";
}

class Prodaja{
    std::string ime_agenta;
    double cijena_stana;
    Datum datum_prodaje;
    Kupac kupac_stana;
    Stan kupljeni_stan;
    
    static void IspravnoIme(std::string s);
    static int BrojDana(int mjesec,int godina);


    public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,int dan_prodaje,int mjesec_prodaje, int godina_prodaje,
    std::string &ime_kupca, const Datum &datum_rodjenja_kupca,const std::string &adresa_stana,int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void PromijeniKupca(const Kupac &novi_kupac)   {kupac_stana=novi_kupac;};
    void PromijeniStan(const Stan &novi_stan)   {kupljeni_stan=novi_stan;};
    void PromijeniDatumKupovine(const Datum &novi_datum)  {datum_prodaje=novi_datum;};
    void PromijeniCijenuProdaje(const double &nova_cijena)   {cijena_stana=nova_cijena;};
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImeAgenta() const{return ime_agenta;};
    std::string DajImeKupca() const{return kupac_stana.DajImeIPrezime();};
    Datum DajDatumProdaje() const {return datum_prodaje;};
    double DajCijenuStana() const{return cijena_stana;};
    friend bool ProdatPrije(const Prodaja &p1,const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
    void Ispisi() const;
    
};
void Prodaja::IspravnoIme(std::string s){
     for(int i=0;i<s.length();i++){
        
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='1' && s[i]<='9') || 
        s[i]==' ' || s[i]==39) continue;
        else{ 
            throw std::domain_error("Neispravno ime i prezime");
        }
        
    }
}
int Prodaja::BrojDana(int mjesec,int godina){
    int b[]{31,28,31,30,31,30,31,31,30,31,30,31};
    if((godina%4==0 && godina%100!=0) || godina%400==0)
    b[1]++;
    
    return b[mjesec-1];
    
}


Prodaja::Prodaja(const std::string &ime_agenta_prodaje,double cijena_stana,const Datum &datum_prodaje,const Kupac &kupac_stana, const Stan &kupljeni_stan)
:datum_prodaje(datum_prodaje),kupac_stana(kupac_stana),kupljeni_stan(kupljeni_stan){
    
    IspravnoIme(ime_agenta_prodaje);
 Prodaja::ime_agenta=ime_agenta_prodaje;
 Prodaja::cijena_stana=cijena_stana;
}

Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,int dan_prodaje,int mjesec_prodaje, int godina_prodaje,
    std::string &ime_kupca, const Datum &datum_rodjenja_kupca,const std::string &adresa_stana,int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata)
    :datum_prodaje(dan_prodaje,mjesec_prodaje,godina_prodaje),kupac_stana(ime_kupca,datum_rodjenja_kupca),kupljeni_stan(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata){
        IspravnoIme(ime_agenta_prodaje);
     Prodaja::ime_agenta=ime_agenta_prodaje;
     Prodaja::cijena_stana=cijena_stana;
        
    }
void Prodaja::PomjeriDanUnaprijed(){
    auto dan(datum_prodaje.DajDan());
    auto mjesec(datum_prodaje.DajMjesec());
    auto godina(datum_prodaje.DajGodinu());
   dan++;
    if(dan>BrojDana(mjesec,godina)){
        dan=1;
        mjesec++;
    }
    if(mjesec>12){
        mjesec=1;
        godina++;
    }
    datum_prodaje.Postavi(dan,mjesec,godina);
}
void Prodaja::PomjeriDanUnazad(){
    auto dan(datum_prodaje.DajDan());
    auto mjesec(datum_prodaje.DajMjesec());
    auto godina(datum_prodaje.DajGodinu());
    dan--;
    if(dan<1 && mjesec>1){
        mjesec--;
        dan=BrojDana(mjesec,godina);
    }
    if(dan<1 && mjesec<1){
        mjesec=12;
        godina--;
        dan=BrojDana(mjesec,godina);
    }
    datum_prodaje.Postavi(dan,mjesec,godina);
    
}
bool ProdatPrije(const Prodaja &p1,const Prodaja &p2){
    auto dan1(p1.datum_prodaje.DajDan());
    auto mjesec1(p1.datum_prodaje.DajMjesec());
    auto godina1(p1.datum_prodaje.DajGodinu());
    auto dan2(p2.datum_prodaje.DajDan());
    auto mjesec2(p2.datum_prodaje.DajMjesec());
    auto godina2(p2.datum_prodaje.DajGodinu());
   if(godina1==godina2){
       if(mjesec1==mjesec2){
           
           return dan1<=dan2;
       }
       else if(mjesec1<mjesec2) return true;
       else return false;
       
   }
   else if(godina1<godina2) return true; 
    else return false;
    
}

bool SkupljiStan(const Prodaja &p1,const Prodaja &p2){
    
    return p1.DajCijenuStana()>=p2.DajCijenuStana();
}

void Prodaja::Ispisi() const{
    std::cout<<std::left<<std::setw(25)<<"Ime agenta: ";std::cout<<ime_agenta<<std::endl;
    std::cout<<std::left<<std::setw(25)<<"Ime kupca: "; kupac_stana.Ispisi();std::cout<<std::endl;
    std::cout<<std::left<<std::setw(25)<<"Zakazani datum prodaje: "; datum_prodaje.Ispisi();std::cout<<std::endl;
    std::cout<<std::left<<std::setw(25)<<"Cijena stana: "; std::cout<<cijena_stana;std::cout<<std::endl;
    std::cout<<"Informacija o stanu: \n";
    kupljeni_stan.Ispisi();
}
class Prodaje{
    
    int dimenzije;
    std::vector<std::shared_ptr<Prodaja>> sveprodaje;
    
    
    public:
    
     explicit Prodaje(int dimenzije):dimenzije(dimenzije),sveprodaje(dimenzije,nullptr){};
  Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
  ~Prodaje(){for(int i=0;i<dimenzije;i++) sveprodaje[i]=nullptr; sveprodaje.resize(0);};
  Prodaje(const Prodaje &prodaje);
  Prodaje(Prodaje &&prodaje);
  Prodaje &operator =(const Prodaje &prodaje);
  Prodaje &operator =(Prodaje &&prodaje);
  void RegistrirajProdaju (const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
  void RegistrirajProdaju (const std::string &ime_agenta_prodaje, double cijena_stana,int dan_prodaje,int mjesec_prodaje, int godina_prodaje,
    std::string &ime_kupca, const Datum &datum_rodjenja_kupca,const std::string &adresa_stana,int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
  void RegistrirajProdaju(Prodaja *prodaja);
  int DajBrojProdaja()const;
  int DajBrojProdajaNaDatum(const Datum &datum) const;
  int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const;
  Prodaja &DajNajranijuProdaju();
  Prodaja DajNajranijuProdaju() const;
  Prodaja &DajNajskupljuProdaju();
  Prodaja DajNajskupljuProdaju() const;
  void IsprazniKolekciju();
  void ObrisiNajranijuProdaju();
  void ObrisiProdajeAgenta(const std::string &ime_agenta);
  void ObrisiProdajeNaDatum(const Datum &datum);
  void IspisiProdajeNaDatum(const Datum &datum) const;
  void IspisiSveProdaje() const;
  Prodaja &DajProdaju(int br);
    
};
Prodaje:: Prodaje(std::initializer_list<Prodaja> spisak_prodaja):dimenzije(spisak_prodaja.size()){
    
         for(int i=0;i<spisak_prodaja.size();i++)
         sveprodaje.push_back(nullptr);
         int br(0);
         for(auto &x:spisak_prodaja){
             *sveprodaje[br]=x;
             br++;
             
         }

 }
 Prodaje::Prodaje(const Prodaje &prodaje) :dimenzije(prodaje.dimenzije){
     for(int i=0;i<prodaje.dimenzije;i++){
         *sveprodaje[i]=*prodaje.sveprodaje[i];
     }
 }
  Prodaje::Prodaje( Prodaje &&prodaje) :dimenzije(prodaje.dimenzije){
     for(int i=0;i<prodaje.dimenzije;i++){
         *sveprodaje[i]=*prodaje.sveprodaje[i];
     }
 }
 

int main ()
{
	return 0;
}