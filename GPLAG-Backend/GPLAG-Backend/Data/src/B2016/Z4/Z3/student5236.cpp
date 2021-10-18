/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>

class Datum{
    int dan;int mjesec;int godina;
    public:
    Datum(int dan,int mjesec,int godina){
        Postavi(dan,mjesec,godina);
    }
    void Postavi(int dan,int mjesec,int godina){
        int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if((godina%4==0 && godina%100!=0) || godina%400==0)broj_dana[1]++;
        if(godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>broj_dana[mjesec-1])throw std::domain_error("Neispravan datum");
        Datum::dan=dan;Datum::mjesec=mjesec;Datum::godina=godina;
         
    }
    int DajDan()const{ return dan;}
    int DajMjesec()const{return mjesec;}
    int DajGodinu()const{return godina;}
    void Ispisi()const{
        std::cout<<dan<<"/"<<mjesec<<"/"<<godina;
    }
    friend class Kupac;
    friend class Prodaja;
};
class Kupac{
    std::string ime_i_prezime;Datum datum_rodjenja=Datum(1,1,1);
    public:
    Kupac(const std::string &ime_i_prezime,const Datum &datum_rodjenja){
        Postavi(ime_i_prezime,datum_rodjenja);
    }
    void Postavi(const std::string &ime_i_prezime,const Datum &datum_rodjenja){
        Kupac::ime_i_prezime=ime_i_prezime;Kupac::datum_rodjenja.dan=datum_rodjenja.dan;
        Kupac::datum_rodjenja.mjesec=datum_rodjenja.mjesec;Kupac::datum_rodjenja.godina=datum_rodjenja.godina;
        
    }
    std::string DajImeKupca()const{return ime_i_prezime;}
    Datum DajDatumRodjenja()const{return datum_rodjenja;}
    void Ispisi()const{
        for(int i=0;i<ime_i_prezime.length();i++){
            std::cout<<ime_i_prezime[i];
        }
        std::cout<<" ("<<datum_rodjenja.dan<<"/"<<datum_rodjenja.mjesec<<"/"<<datum_rodjenja.godina<<")";
    }
    friend class Prodaja;
};
class Stan{
    std::string adresa;int sprat;int broj_soba;bool namjesten;double kvadratura;
    public:
    Stan(const std::string &adresa,int sprat,int broj_soba,bool namjesten,double kvadratura){
        Postavi(adresa,sprat,broj_soba,namjesten,kvadratura);
    }
    void Postavi(const std::string &adresa,int sprat,int broj_soba,bool namjesten,double kvadratura){
        if(sprat<0 || broj_soba<0 || kvadratura<0)throw std::domain_error("Neispravan unos podataka");
        Stan::adresa=adresa;Stan::sprat=sprat;Stan::broj_soba=broj_soba;Stan::namjesten=namjesten;Stan::kvadratura=kvadratura;
    }
    std::string DajAdresu()const{return adresa;}
    int DajSprat()const{return sprat;}
    int DajBrojSoba()const{return broj_soba;}
    bool DajNamjesten()const{return namjesten;}
    double DajKvadraturu()const{return kvadratura;}
    void Ispisi()const{
        std::cout<<"Stan se nalazi na adresi "<<DajAdresu()<<" na "<<DajSprat()<<". spratu i ima "<<DajBrojSoba()<<" ";
        if(broj_soba<4){
            std::cout<<"sobe."<<std::endl;
        }else if(broj_soba>4){
            std::cout<<"soba."<<std::endl;
        }
        std::cout<<"Kvadratura stana je "<<DajKvadraturu()<<" (m^2) i stan ";
        if(namjesten==true){
            std::cout<<"je namjesten.";
        }else{
            std::cout<<"nije namjesten.";
        }
    }
    friend class Prodaja;
};
class Prodaja{
    std::string ime_agenta_prodaje;double cijena_stana;std::string ime_kupca;
    Kupac kupac_stana=Kupac("kupac",(1,1,1));
    Datum datum_prodaje=Datum(1,1,1);
    Stan kupljeni_stan=Stan("adresa",0,0,0,0);
    public:
    Prodaja(const std::string &ime_agenta_prodaje,double cijena_stana,
      const Datum datum_prodaje,const Kupac &kupac_stana,const Stan &kupljeni_stan){
          Prodaja::ime_agenta_prodaje=ime_agenta_prodaje;Prodaja::kupac_stana=kupac_stana;
          Prodaja::cijena_stana=cijena_stana;Prodaja::datum_prodaje=datum_prodaje;
          Prodaja::kupljeni_stan=kupljeni_stan;
      }
      Prodaja(const std::string &ime_agenta_prodaje,double cijena_stana,int dan_prodaje,int mjesec_prodaje,int godina_prodaje,
      std::string &ime_kupca,const Datum &datum_rodjenja_kupca,const std::string &adresa_stana,int sprat_stana,
      int broj_soba,bool namjesten_stan,double broj_kvadrata){
          Prodaja::ime_agenta_prodaje=ime_agenta_prodaje;Prodaja::cijena_stana=cijena_stana;Prodaja::datum_prodaje.dan=dan_prodaje;
          Prodaja::datum_prodaje.mjesec=mjesec_prodaje;Prodaja::datum_prodaje.godina=godina_prodaje;Prodaja::kupac_stana.ime_kupca=ime_kupca;
          Prodaja::kupac_stana.datum_rodjenja=datum_rodjenja_kupca;Prodaja::kupljeni_stan.adresa=adresa_stana;
          Prodaja::kupljeni_stan.sprat=sprat_stana;Prodaja::kupljeni_stan.broj_soba=broj_soba;Prodaja::kupljeni_stan.namjesten=namjesten_stan;
          Prodaja::kupljeni_stan.kvadratura=broj_kvadrata;
      }
      void PromijeniKupca(const Kupac &novi_kupac){
          Prodaja::kupac_stana=novi_kupac;
      }
      void PromijeniStan(const Stan &novi_stan){
          Prodaja::kupljeni_stan=novi_stan;
      }
      void PromijeniDatumKupovine(const Datum &novi_datum){
          Prodaja::datum_prodaje=novi_datum;
      }
      void PromijeniCijenuProdaje(const double &nova_cijena){
          Prodaja::cijena_stana=nova_cijena;
      }
      void PomjeriDanUnaprijed(){
          Prodaja::datum_prodaje.dan=datum_prodaje.dan+1;
      }
      void PomjeriDanUnazad(){
          Prodaja::datum_prodaje.dan=datum_prodaje.dan-1;
      }
      std::string DajImeAgenta()const{return ime_agenta_prodaje;}
      std::string DajImeKupca()const{return ime_kupca;}
      Datum DajDatumProdaje()const{return datum_prodaje;}
      double DajCijenuStana()const{return cijena_stana;}
     friend bool ProdatPrije(const Prodaja &p1,const Prodaja &p2);
      friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
      void Ispisi()const{
          
      }
};
bool ProdatPrije(const Prodaja &p1,const Prodaja &p2){
    if((p1.datum_prodaje.mjesec>=p2.datum_prodaje.mjesec && p1.datum_prodaje.godina>=p2.datum_prodaje.godina ) || (p1.datum_prodaje.mjesec==p2.datum_prodaje.mjesec && p1.datum_prodaje.godina>=p2.datum_prodaje.godina && p1.datum_prodaje.dan>p2.datum_prodaje.dan)){
       return true;
       }else{
           return false;
       }
}
int main ()
{
	return 0;
}