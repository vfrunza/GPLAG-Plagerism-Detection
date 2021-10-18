/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip>
class Datum{
  int dan, mjesec, godina;
  friend class Kupac;
  friend class Prodaja;
  public:
  Datum(int dan, int mjesec, int godina);
  void Postavi(int dan, int mjesec, int godina);
  int DajDan() const{return dan;}
  int DajMjesec() const{return mjesec;}
  int DajGodinu() const{return godina;}
  void Ispisi() const;
};
class Kupac{
  std::string ime_i_prezime;
 friend class Datum;
 friend class Prodaja;
  Datum datum_rodjenja;
  int dan{datum_rodjenja.DajDan()};
  int mjesec{datum_rodjenja.DajMjesec()};
  int godina{datum_rodjenja.DajGodinu()};
  public:    
  friend class Datum;
  friend class Prodaja;
  Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja) : ime_i_prezime(ime_i_prezime), datum_rodjenja(datum_rodjenja){
      for(int i=0; i<ime_i_prezime.size(); i++)
       if(!((ime_i_prezime[i]>='A' && ime_i_prezime[i]<='Z') || (ime_i_prezime[i]>='a' && ime_i_prezime[i]<='z') || (ime_i_prezime[i]>='0' && ime_i_prezime[i]<='9') || ime_i_prezime[i]=='-' || ime_i_prezime[i]=='\'' || ime_i_prezime[i]==' '))
       throw std::domain_error("Neispravno ime i prezime");
  }
  void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
  std::string DajImePrezime() const;
  Datum DajDatumRodjenja() const;
  void Ispisi() const;
};
class Stan{
    std::string adresa;
    int sprat, broj_soba;
    double kvadratura;
    bool namjesten;
    public:
     Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura):sprat(sprat), broj_soba(broj_soba),kvadratura(kvadratura), namjesten(namjesten){
         if(sprat <0 || broj_soba<0 || kvadratura<0) throw std::domain_error("Neispravan unos podataka");
         Stan::adresa=adresa;
     }
     void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
     std::string DajAdresu() const;
     int DajSprat() const;
     int DajBrojSoba() const;
     bool DajNamjesten() const;
     double DajKvadraturu() const;
     void Ispisi() const;
};
class Prodaja{
    friend class Datum;
    friend class Kupac;
    friend class Stan;
    std::string ime_agenta_prodaje, ime_kupca, adresa_stana;
    double cijena_stana, broj_kvadrata;
    Datum datum;
    Kupac kupac_stana;
    Stan kupljeni_stan;
    bool namjesten_stan;
    int dan_prodaje, mjesec_prodaje, godina_prodaje, sprat_stana, broj_soba;
    public:
    friend class Datum;
    friend class Kupac;
    friend class Stan;
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan): cijena_stana(cijena_stana),datum(datum_prodaje),
     kupac_stana(kupac_stana),kupljeni_stan(kupljeni_stan){
         Prodaja::ime_agenta_prodaje=ime_agenta_prodaje;
     }
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, 
     const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) : cijena_stana(cijena_stana), 
     datum(datum_rodjenja_kupca), dan_prodaje(dan_prodaje),mjesec_prodaje(mjesec_prodaje),godina_prodaje(godina_prodaje),
     broj_kvadrata(broj_kvadrata), sprat_stana(sprat_stana),kupac_stana(ime_kupca, datum_rodjenja_kupca),broj_soba(broj_soba),namjesten_stan(namjesten_stan), kupljeni_stan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata){
        Prodaja::ime_agenta_prodaje=ime_agenta_prodaje; 
        Prodaja::ime_kupca=ime_kupca;
        Prodaja::adresa_stana=adresa_stana;
     }
     void PromijeniKupca(const Kupac &novi_kupac);
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
int main (){
 try{
     std::string adresa;
     int sprat{0}, broj_soba{0}, namjesten{0};
     double kvadratura{0};
     int izbor{-1}, izbor1{-1};
     std::cout <<"Dobrodosli!"<<std::endl;
     std::cout <<std::endl;
     while(izbor!=0){
         std::cout <<"Izaberite opciju:"<<std::endl;
         std::cout <<" 0 - kraj"<<std::endl;
         std::cout <<" 1 - uredjivanje stanova"<<std::endl;
         std::cout <<" 2 - uredjivanje kupaca"<<std::endl;
         std::cout <<" 3 - uredjivanje prodaja"<<std::endl;
         std::cin >>izbor;
         switch(izbor){
             case 1:
               while(izbor1!=0){
                   std::cout <<" 0 - nazad"<<std::endl;
                   std::cout <<" 1 - dodavanje stana"<<std::endl;
                   std::cout <<" 2 - uredjivanje stanova"<<std::endl;
                   std::cout <<" 3 - ispis svih stanova"<<std::endl;
                   std::cout <<" 4 -kraj"<<std::endl;
                   switch(izbor1){
                       case 1:
                        std::cout <<"Unesite adresu: ";
                        std::getline(std::cin,adresa);
                        std::cout <<"Unesite sprat: ";
                        std::cin >>sprat;
                        std::cout <<"Unesite broj soba: ";
                        std::cin >>broj_soba;
                        std::cout <<"Da li je stan namjesten(1 - da, 0 - ne): ";
                        std::cin >>namjesten;
                        std::cout <<"Unesite kvadraturu: ";
                        std::cin >>kvadratura;
                        if(sprat<0 || broj_soba<0 || kvadratura <0) throw std::domain_error("Izuzetak: Neispravan unos podataka. Molimo unesite opet.");
                        case 0: break;
                   }
               }
               case 0: break;
         }
     }
 /*   Datum dat(15,5,2017);
    dat.Ispisi();
    std::cout <<std::endl;
    dat.Postavi(16,5,2017);
    dat.Ispisi();*/
   /* std::cout <<std::endl;
    std::cout<<dat.DajDan()<<".";
    std::cout<<dat.DajMjesec()<<".";
    std::cout<<dat.DajGodinu();*/
  //  Kupac kupac("Nihad Biogradlija",{2,1,1962});
   // kupac.Ispisi();
  //  kupac.DajDatumRodjenja().Ispisi();
    //std::cout <<kupac.DajImePrezime();
    //kupac.Ispisi();
  //  kupac.Postavi("Senija Biogradlija",{19,11,1996});
 // Stan stan("Hamdije Cemerlica 14",1,31,false,39.21);
  //stan.Ispisi();
 //kupac.PromijeniKupca("Suljo Suljic",{21,9,1982});
 // Prodaja prodaja2("Niko Nikic", 78985, {31,12,2017}, {"Mujo Mujic",{21,9,1982}},{"Hamdije Cemerlica 14",5,5,true,35.45});
 // Prodaja prodaja1("Senija Biogradlija", 25000, {31,12,2017},{"Suljo Suljic",{19,11,1996}},{"Bulevar Kulina bana 2",5,5,true,39.21});
 // std::cout <<std::boolalpha<<SkupljiStan(prodaja1,prodaja2);
 //prodaja.DajDatumProdaje().Ispisi();
// std::cout <<prodaja.DajCijenuStana()<<std::endl;
 // prodaja.PromijeniKupca({"Suljo Suljic",{21,9,1982}});
// prodaja.PromijeniDatumKupovine({20,9,2017});
//  prodaja.PromijeniCijenuProdaje(25000);
//  prodaja.PromijeniStan({"Bulevar Kulina bana 2",7,3,true,45});
//  Prodaja prodaja("Niko Nikic", 78985, 27,5,2017,(std::string &)"Mujo Mujic",{21,9,1982},"Hamdije Cemerlica 14",5,5,true,35.45);
  //prodaja.PomjeriDanUnazad();
 // prodaja.Ispisi();
 }
 catch(std::domain_error izuzetak){
  std::cout <<izuzetak.what()<<std::endl;     
 }
 return 0;
}
Datum::Datum(int dan, int mjesec, int godina){
    int broj_dana[]{31,28,31,30,31,30,31,31,30,31,30,31};
    if((godina%4==0 && godina%100!=0) || godina%400==0) broj_dana[1]++;
    if(dan<1 || dan>broj_dana[mjesec-1] || mjesec<1 || mjesec>12 || godina<1){
        std::cout<<dan<<" "<<mjesec<<" "<<godina;
        throw std::domain_error("Neispravan datum");
    }
    Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
}
void Datum::Postavi(int dan, int mjesec, int godina){
    Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
}
void Datum::Ispisi() const{
    std::cout <<dan<<"/"<<mjesec<<"/"<<godina;
}
void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja){
    Kupac::ime_i_prezime=ime_i_prezime;
    Kupac::datum_rodjenja=datum_rodjenja;
}
void Kupac::Ispisi() const{
    std::cout <<ime_i_prezime<<" (";
    datum_rodjenja.Ispisi();
    std::cout <<")";
}
std::string Kupac::DajImePrezime() const{
    return Kupac::ime_i_prezime;
}
Datum Kupac::DajDatumRodjenja() const{
    return Kupac::datum_rodjenja;
}
void Stan::Ispisi() const{
    std::cout <<"Stan se nalazi na adresi "<<DajAdresu()<<" na "<<DajSprat()<<". spratu i ima "<<DajBrojSoba();
    if(DajBrojSoba()%10==5 || DajBrojSoba()%10==6 || DajBrojSoba()%10==7 || DajBrojSoba()%10==8 || DajBrojSoba()%10==9 || (DajBrojSoba()>=11 && DajBrojSoba()<=19) || DajBrojSoba()%10==0)
    std::cout<<" soba."<<std::endl;
    else if(DajBrojSoba()%10==2 || DajBrojSoba()%10==3 || DajBrojSoba()%10==4)
    std::cout <<" sobe."<<std::endl;
    else std::cout <<" sobu."<<std::endl;
    std::cout <<"Kvadratura stana je "<<DajKvadraturu()<<" (m^2) i stan";
    bool t{Stan::DajNamjesten()};
    if(t==true) std::cout <<" je namjesten.";
    else std::cout <<" nije namjesten.";
}
std::string Stan::DajAdresu() const{
    return Stan::adresa;
}
int Stan::DajSprat() const{
    return Stan::sprat;
}
int Stan::DajBrojSoba() const{
    return Stan::broj_soba;
}
double Stan::DajKvadraturu() const{
    return Stan::kvadratura;
}
bool Stan::DajNamjesten() const{
    return Stan::namjesten;
}
std::string Prodaja::DajImeAgenta() const{
    return Prodaja::ime_agenta_prodaje;
}
Datum Prodaja::DajDatumProdaje() const{
    return Prodaja::datum;
}
double Prodaja::DajCijenuStana() const{
    return Prodaja::cijena_stana;
}
void Prodaja::Ispisi() const{
    std::cout <<"Ime agenta: "<<std::setw(30)<<std::right<<DajImeAgenta()<<std::endl;
    std::cout <<"Ime kupca: "<<std::setw(31)<<std::right;
    Prodaja::kupac_stana.Ispisi();
    std::cout <<std::endl;
    std::cout <<std::setw(32)<<std::left<<"Zakazani datum prodaje: "<<std::right;
    Prodaja::datum.Ispisi();
    std::cout <<std::endl;
    std::cout <<std::setw(32)<<std::left<<"Cijena stana: "<<std::right<<Prodaja::cijena_stana<<std::endl;
    Prodaja::kupljeni_stan.Ispisi();
}
void Prodaja::PromijeniKupca(const Kupac &novi_kupac){
    Prodaja::kupac_stana=novi_kupac;
}
void Prodaja::PromijeniDatumKupovine(const Datum &novi_datum){
    Prodaja::datum=novi_datum;
}
void Prodaja::PromijeniCijenuProdaje(const double &nova_cijena){
    Prodaja::cijena_stana=nova_cijena;
}
void Prodaja::PromijeniStan(const Stan &novi_stan){
    Prodaja::kupljeni_stan=novi_stan;
}
void Prodaja::PomjeriDanUnaprijed(){
    int mjesec{Prodaja::datum.Datum::DajMjesec()};
    int godina{Prodaja::datum.Datum::DajGodinu()};
    int broj_dana[]{31,28,31,30,31,30,31,31,30,31,30,31};
    if((godina%4==0 && godina%100!=0) || godina%400==0) broj_dana[1]++;
    int dan{Prodaja::datum.Datum::DajDan()+1};
    if(dan>broj_dana[mjesec-1]) {
        if(mjesec!=12){
            dan=1;
            mjesec++;
        }
        else{
            dan=1;
            mjesec=1;
            godina++;
        }
    }
    Datum dat(dan,mjesec,godina);
    PromijeniDatumKupovine(dat);
}
void Prodaja::PomjeriDanUnazad(){
    int mjesec{Prodaja::datum.Datum::DajMjesec()};
    int godina{Prodaja::datum.Datum::DajGodinu()};
    int broj_dana[]{31,28,31,30,31,30,31,31,30,31,30,31};
    if((godina%4==0 && godina%100!=0) || godina%400==0) broj_dana[1]++;
    int dan{Prodaja::datum.Datum::DajDan()-1};
    if(dan<1){
     if(mjesec!=1){dan=broj_dana[mjesec-2]; mjesec--;}
     else {dan=broj_dana[11]; mjesec=12; godina--;}
    }
    Datum dat(dan,mjesec,godina);
    PromijeniDatumKupovine(dat);
}
bool ProdatPrije(const Prodaja &p1, const Prodaja &p2){
    int dani1{0}, dani2{0}, danx1{0}, danx2{0};
    int broj_dana[]{31,59,90,120,151,181,212,243,273,304,335,365};
    int mjesec1{p1.Prodaja::datum.Datum::DajMjesec()}, mjesec2{p2.Prodaja::datum.Datum::DajMjesec()};
    danx1=(p1.Prodaja::datum.Datum::DajGodinu()-1)/4;
    danx2=(p2.Prodaja::datum.Datum::DajGodinu()-1)/4;
    dani1=(p1.Prodaja::datum.DajGodinu()-1)*365+broj_dana[mjesec1-1]+p1.Prodaja::datum.Datum::DajDan()+danx1;
    dani2=(p2.Prodaja::datum.DajGodinu()-1)*365+broj_dana[mjesec2-1]+p2.Prodaja::datum.Datum::DajDan()+danx2;
    if(dani1<dani2) return true;
    return false;
}
bool SkupljiStan(const Prodaja &p1, const Prodaja &p2){
    double cijena_stana1{0}, cijena_stana2{0};
    cijena_stana1=p1.Prodaja::DajCijenuStana();
    cijena_stana2=p2.Prodaja::DajCijenuStana();
    if(cijena_stana1>cijena_stana2) return true;
    return false;
}