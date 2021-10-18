/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <string>
//#include <vector>
#include <iomanip>
#include <algorithm>
class Datum{
  int d,m,g;
  public:
  Datum(int dan,int mjesec,int godina){
      Postavi(dan,mjesec,godina);
  };
  void Postavi(int dan,int mjesec,int godina);
  int DajDan() const{return d;};
  int DajMjesec() const{return m;};
  int DajGodinu() const{return g;};
  void Ispisi() const{std::cout << d <<"/"<<m<<"/"<<g << std::endl;};
};
void Datum::Postavi(int dan,int mjesec, int godina){
    int broj_dana[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if((godina%4==0 && godina%100!=0) || godina%400==0)broj_dana[1]++;
    if(godina<1 || mjesec<1 || dan<1 || dan>broj_dana[mjesec-1])throw std::domain_error("Neispravan datum");
    d=dan;m=mjesec;g=godina;
}
class Kupac{
  std::string imeiprezime;
  Datum datum_rodj;
  public:
  Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja): datum_rodj(datum_rodjenja) {Postavi(ime_i_prezime,datum_rodjenja);}
  void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja){
    for(int i=0;i<ime_i_prezime.length();i++){
      if((ime_i_prezime[i]<='a' && ime_i_prezime[i]>='z' && ime_i_prezime[i]!=' ') || (ime_i_prezime[i]<='A' && ime_i_prezime[i]>='Z' && ime_i_prezime[i]!=' '))throw std::domain_error("Neispravno ime i prezime");
    }
    imeiprezime=ime_i_prezime;
    datum_rodj=datum_rodjenja;
  };
  std::string DajImePrezime() const{return imeiprezime;};
  Datum DajDatumRodjenja() const{return datum_rodj;};
  void Ispisi() const{std::cout << imeiprezime<<" ("<<datum_rodj.DajDan()<<"/"<<datum_rodj.DajMjesec()<<"/"<<datum_rodj.DajGodinu()<<")" << std::endl;}
};
class Stan{
  std::string adresa_stanovanja;
  int sprat_stan;
  int br_s;
  bool namjesten_stan;
  double kvadrat;
  public:
  Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){Postavi(adresa,sprat,broj_soba,namjesten,kvadratura);}
  void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
    adresa_stanovanja=adresa;
    if(sprat<=0 || broj_soba<=0 || kvadratura<=0)throw std::domain_error("Neispravan unos podataka");
    sprat_stan=sprat;
    br_s=broj_soba;
    namjesten_stan=namjesten;
    kvadrat=kvadratura;
  };
  std::string DajAdresu() const{return adresa_stanovanja;};
  int DajSprat() const{return sprat_stan;};
  int DajBrojSoba() const{return br_s;};
  bool DajNamjesten() const{return namjesten_stan;};
  double DajKvadraturu() const{return kvadrat;};
  void Ispisi() const{std::cout << "Stan se nalazi na adresi "<< adresa_stanovanja<< " na "<<sprat_stan<<". spratu i ima ";
  if(br_s==1)std::cout <<br_s<<" sobu." << std::endl<<"Kvadratura stana je "<<kvadrat<<" (m^2) i stan ";
  if(br_s>=2 && br_s<=4)std::cout <<br_s<<" sobe." << std::endl<<"Kvadratura stana je "<<kvadrat<<" (m^2) i stan ";
  if(br_s>=5)std::cout <<br_s<<" soba." << std::endl<<"Kvadratura stana je "<<kvadrat<<" (m^2) i stan ";
  if(namjesten_stan==true)std::cout << "je namjesten." << std::endl;
  else std::cout << "nije namjesten." << std::endl;
  };
};
class Prodaja{
  std::string imeagenta;
  double cijena;
  Datum prodaje;
  Kupac kupac;
  Stan kupljen;
  public:
  Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan): prodaje(datum_prodaje), kupac(kupac_stana), kupljen(kupljeni_stan) {
    for(int i=0;i<ime_agenta_prodaje.length();i++){
      if((ime_agenta_prodaje[i]<='a' && ime_agenta_prodaje[i]>='z' && ime_agenta_prodaje[i]!=' ') || (ime_agenta_prodaje[i]<='A' && ime_agenta_prodaje[i]>='Z' && ime_agenta_prodaje[i]!=' '))throw std::domain_error("Neispravno ime i prezime");
    }
    imeagenta=ime_agenta_prodaje;
    cijena=cijena_stana;
  }
  Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata); 
  void PromijeniKupca(const Kupac &novi_kupac){ kupac=novi_kupac;};
  void PromijeniStan(const Stan &novi_stan){kupljen=novi_stan;};
  void PromijeniDatumKupovine(const Datum &novi_datum){prodaje=novi_datum;};
  void PromijeniCijenuProdaje(const double &nova_cijena){cijena=nova_cijena;};
  void PomjeriDanUnaprijed();
  void PomjeriDanUnazad(); 
  std::string DajImeAgenta() const{return imeagenta;};
  std::string DajImeKupca() const{return kupac.DajImePrezime();};
  Datum DajDatumProdaje() const{return prodaje;};
  double DajCijenuStana() const{return cijena;};
  friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
  friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
  void Ispisi() const{std::cout <<std::setw(30)<<std::left<< "Ime agenta: "<<std::left<<imeagenta<< std::endl<<std::setw(30)<<"Ime kupca: "<<std::left<<kupac.DajImePrezime()<<" ("<<kupac.DajDatumRodjenja().DajDan()<<"/"<<kupac.DajDatumRodjenja().DajMjesec()<<"/"<<kupac.DajDatumRodjenja().DajGodinu()<<")"<<std::endl<<std::setw(30)<< "Zakazani datum prodaje: ";
    std::cout << std::left<<prodaje.DajDan()<<"/"<<prodaje.DajMjesec()<<"/"<<prodaje.DajGodinu()<< std::endl<<std::setw(30)<< "Cijena stana: "<<std::left<< cijena<<std::endl<<"Informacije o stanu: "<<std::endl;
    std::cout << "Stan se nalazi na adresi "<< kupljen.DajAdresu()<< " na "<<kupljen.DajSprat()<<". spratu i ima ";
  if(kupljen.DajBrojSoba()==1)std::cout <<kupljen.DajBrojSoba()<<" sobu." << std::endl<<"Kvadratura stana je "<<kupljen.DajKvadraturu()<<" (m^2) i stan ";
  if(kupljen.DajBrojSoba()>=2 && kupljen.DajBrojSoba()<=4)std::cout <<kupljen.DajBrojSoba()<<" sobe." << std::endl<<"Kvadratura stana je "<<kupljen.DajKvadraturu()<<" (m^2) i stan ";
  if(kupljen.DajBrojSoba()>=5)std::cout <<kupljen.DajBrojSoba()<<" soba." << std::endl<<"Kvadratura stana je "<<kupljen.DajKvadraturu()<<" (m^2) i stan ";
  if(kupljen.DajNamjesten()==true)std::cout << "je namjesten." << std::endl;
  else std::cout << "nije namjesten." << std::endl;
    
  };
};
Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) : prodaje(dan_prodaje,mjesec_prodaje,godina_prodaje),kupac(ime_kupca,datum_rodjenja_kupca),kupljen(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata) {
  imeagenta=ime_agenta_prodaje;
  cijena=cijena_stana;
}
void Prodaja::PomjeriDanUnaprijed(){
  int broj_dana[12]={31,28,31,30,31,30,31,31,30,31,30,31};
  int dan=prodaje.DajDan();
  int mjesec=prodaje.DajMjesec();
  int godina=prodaje.DajGodinu();
  if((godina%4==0 && godina%100!=0) || godina%400==0)broj_dana[1]++;
  dan++;
  if(dan>broj_dana[mjesec-1]){dan=1;mjesec++;}
  if(mjesec>12){mjesec=1;godina++;}
  prodaje.Postavi(dan,mjesec,godina);
}
void Prodaja::PomjeriDanUnazad(){
  int broj_dana[12]={31,28,31,30,31,30,31,31,30,31,30,31};
  int dan=prodaje.DajDan();
  int mjesec=prodaje.DajMjesec();
  int godina=prodaje.DajGodinu();
  if((godina%4==0 && godina%100!=0) || godina%400==0)broj_dana[1]++;
  dan--;
  if(dan<=0){dan=broj_dana[mjesec-2];mjesec--;}
  if(mjesec<=0){mjesec=12;godina--;}
  prodaje.Postavi(dan,mjesec,godina);
}
bool ProdatPrije(const Prodaja &p1, const Prodaja &p2){
  if(p1.prodaje.DajGodinu()<p2.prodaje.DajGodinu())return true;
  if(p1.prodaje.DajGodinu()==p2.prodaje.DajGodinu() && p1.prodaje.DajMjesec()<p2.prodaje.DajMjesec())return true;
  if(p1.prodaje.DajDan()<=p2.prodaje.DajDan() && p1.prodaje.DajMjesec()<=p2.prodaje.DajMjesec() && p1.prodaje.DajGodinu()<=p2.prodaje.DajGodinu())return true;
  else return false;
}
bool SkupljiStan(const Prodaja &p1, const Prodaja &p2){
  if(p1.cijena>=p2.cijena)return true;
  else return false;
}
class Prodaje{
  std::vector<std::shared_ptr<Prodaja> v;

  public:
  explicit Prodaje(int max_broj_prodaja){}
  Prodaje(std::initializer_list<Prodaja> spisak_prodaja)  niz(new Prodaja*[spisak_prodaja.size()] {}) {
    for(int i=0;i<spisak_prodaja.size();i++)std::shared_ptr<Prodaja> p=(std::make_shared(Prodaja));
  }
  ~Prodaje(){for(int i=0;i<broj_prodatih;i++)delete niz[i];
  delete [] niz;}
  Prodaje(const Prodaje &prodaje);
  Prodaje(Prodaje &&prodaje);
  Prodaje &operator =(const Prodaje &prodaje);
  Prodaje &operator =(Prodaje &&prodaje);
  void RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,const Stan &kupljeni_stan);
  void RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana, int dan_prodaje,int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,
  int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
  void RegistrirajProdaju(Prodaja *prodaja){  if(broj_prodatih==dimenzija)throw std::range_error("Dostignut maksimalni broj prodaja");
   niz[broj_prodatih]=prodaja; broj_prodatih++;};
  Prodaja &DajProdaju(int broj);
  int DajBrojProdaja() const{return broj_prodatih;};
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

};
  
Prodaja &Prodaje::DajProdaju(int broj){
  if(broj>=broj_prodatih)throw std::range_error("Neispravan broj");
  for(int i=0;i<broj_prodatih;i++)if(broj==(i-1))return *niz[i];
}
void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,const Stan &kupljeni_stan) {
  if(broj_prodatih==dimenzija)throw std::range_error("Dostignut maksimalni broj prodaja");
  niz[broj_prodatih]=new Prodaja(ime_agenta_prodaje,cijena_stana,datum_prodaje,kupac_stana,kupljeni_stan);
  broj_prodatih++;
  
}
 void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana, int dan_prodaje,int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,
  int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) { 
    if(broj_prodatih==dimenzija)throw std::range_error("Dostignut maksimalni broj prodaja");
    niz[broj_prodatih]=new Prodaja(ime_agenta_prodaje,cijena_stana,dan_prodaje,mjesec_prodaje,godina_prodaje,ime_kupca,datum_rodjenja_kupca,adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata);
    broj_prodatih++;
  }
  
  int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const{
    int brojac;
    brojac=std::count_if(niz,niz+broj_prodatih,[datum] (Prodaja* p) {
      const Datum dat=p->DajDatumProdaje();
      if(dat.DajDan()==datum.DajDan() && dat.DajMjesec()==datum.DajMjesec() && dat.DajGodinu()==datum.DajGodinu())return true;
      else return false;
    });
    return brojac;
  }
  
  int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const{
    int brojac(0);
    for(int i=0;i<broj_prodatih;i++){
    if(niz[i]->DajImeAgenta()==ime_agenta)brojac++;
    }
    return brojac;
  }
  Prodaje::Prodaje(const Prodaje &prodaje) :dimenzija(prodaje.dimenzija),  broj_prodatih(prodaje.broj_prodatih) {
    Prodaja** niz(new Prodaja*[dimenzija]);
    for(int i=0;i<broj_prodatih;i++)niz[i]=nullptr;
    try{
    for(int i=0;i<dimenzija;i++)niz[i]=new Prodaja(*prodaje.niz[i]);
    }catch(...){
      for(int i=0;i<dimenzija;i++)delete niz[i];
      delete [] niz;
    }
  }
  Prodaje::Prodaje(Prodaje &&prodaje) : dimenzija(prodaje.dimenzija), broj_prodatih(prodaje.broj_prodatih) {
    prodaje.niz=nullptr;
  }
  Prodaje &Prodaje::operator =(const Prodaje &prodaje){
    if(&prodaje==this)return *this;
    for(int i=0;i<broj_prodatih;i++)delete niz[i];
    delete []niz;
    dimenzija=prodaje.dimenzija; broj_prodatih=prodaje.broj_prodatih;
    niz=new Prodaja*[dimenzija];
    for(int i=0;i<broj_prodatih;i++)niz[i]=new Prodaja(*prodaje.niz[i]);
  }
  Prodaje &Prodaje::operator =(Prodaje &&prodaje){
    std::swap(dimenzija,prodaje.dimenzija);
    std::swap(broj_prodatih,prodaje.broj_prodatih);
    std::swap(niz,prodaje.niz);
  }
  Prodaja &Prodaje::DajNajranijuProdaju(){
    auto p=std::min_element(niz,niz+broj_prodatih, [] (Prodaja* prodaja, Prodaja* prodaja2){
     if(ProdatPrije(*prodaja,*prodaja2)==true)return true;
      else return false;
    });
    return **p;
  }
  Prodaja Prodaje::DajNajranijuProdaju() const{
    auto p=std::min_element(niz,niz+broj_prodatih, [] (Prodaja* prodaja, Prodaja* prodaja2){
     if(ProdatPrije(*prodaja,*prodaja2)==true)return true;
      else return false;
    });
    return **p;
  }
  Prodaja &Prodaje::DajNajskupljuProdaju(){
    auto p=std::max_element(niz,niz+broj_prodatih,[] (Prodaja* prodaja1, Prodaja* prodaja2){
      if(SkupljiStan(*prodaja1,*prodaja2)==true)return true;
      else return false;
    });
    return **p;
  }
  Prodaja Prodaje::DajNajskupljuProdaju() const{
    auto p=std::max_element(niz,niz+broj_prodatih,[] (Prodaja* prodaja1, Prodaja* prodaja2){
      if(SkupljiStan(*prodaja1,*prodaja2)==true)return true;
      else return false;
    });
    return **p;
  }
    void Prodaje::IsprazniKolekciju(){
      for(int i=0;i<broj_prodatih;i++)delete niz[i];
      delete[] niz;
    }
     void Prodaje::ObrisiNajranijuProdaju(){
       if(broj_prodatih==0)throw std::range_error("Prazna kolekcija");
       Prodaja p=this->DajNajranijuProdaju();
       for(int i=0;i<broj_prodatih;i++){
         if(niz[i]->DajDatumProdaje().DajGodinu()==p.DajDatumProdaje().DajGodinu() && niz[i]->DajDatumProdaje().DajMjesec()==p.DajDatumProdaje().DajMjesec() && niz[i]->DajDatumProdaje().DajDan()==p.DajDatumProdaje().DajDan()){ delete niz[i];
         for(int k=i;k<broj_prodatih;k++){
           Prodaja *prodaja=niz[k];
           niz[k]=niz[k+1];
           niz[k+1]=prodaja;
          }
          broj_prodatih--;
        }
      }
    }
    void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta){
      for(int i=0;i<broj_prodatih;i++){
        if(niz[i]->DajImeAgenta()==ime_agenta){
          delete niz[i];
          for(int k=i;k<broj_prodatih;k++){
           Prodaja *prodaja=niz[k];
           niz[k]=niz[k+1];
           niz[k+1]=prodaja;
          }
          broj_prodatih--;
        }
      }
    }
    void Prodaje::ObrisiProdajeNaDatum(const Datum &datum){
       Prodaja p=this->DajNajranijuProdaju();
       Datum dat=p.DajDatumProdaje();
       for(int i=0;i<broj_prodatih;i++){
         if(niz[i]->DajDatumProdaje().DajGodinu()==dat.DajGodinu() && niz[i]->DajDatumProdaje().DajMjesec()==dat.DajMjesec() && niz[i]->DajDatumProdaje().DajDan()==dat.DajDan()){delete niz[i];
         for(int k=i;k<broj_prodatih;k++){
           Prodaja *prodaja=niz[k];
           niz[k]=niz[k+1];
           niz[k+1]=prodaja;
          }
         broj_prodatih--;
         }
       }
    }
    void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const{
      std::vector<Prodaja> v;
      for(int i=0;i<broj_prodatih;i++){
        if(niz[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu() && niz[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec() && niz[i]->DajDatumProdaje().DajDan()==datum.DajDan())v.push_back(*niz[i]);
      }
      std::sort(v.begin(),v.end(), [] (Prodaja p1, Prodaja p2){
        if(p1.DajImeAgenta()>p2.DajImeAgenta())return true;
        else return false;
      });
      for(int i=0;i<v.size();i++){
        v[i].Ispisi();
        //std::cout  << std::endl;
      }
    }
      void Prodaje::IspisiSveProdaje() const{
        std::sort(niz,niz+dimenzija, [] (Prodaja *p1, Prodaja *p2){
          if(p1->DajDatumProdaje().DajGodinu()==p2->DajDatumProdaje().DajGodinu() && p1->DajDatumProdaje().DajMjesec()==p2->DajDatumProdaje().DajMjesec() && p1->DajDatumProdaje().DajDan()==p2->DajDatumProdaje().DajDan()){if(p1->DajImeKupca()>p2->DajImeKupca())return true;
            else return false;
          }
          if(ProdatPrije(*p1,*p2)==true)return true;
          else return false;
        });
        for(int i=0;i<broj_prodatih;i++)niz[i]->Ispisi();
      }
    
  
int main ()
{
  try{
    
  /*int d,m,g;
  std::cin >> d>>m>>g ;
  Datum dat(d,m,g);
  std::cin.clear();
  std::cin.ignore(1000,'\n');
  std::string s;
  std::getline(std::cin,s);
  Kupac kupac(s,dat);
  std::string adresa;
  int sprat, broj_soba;
  bool namjesten(true); double kvadratura;
  std::getline(std::cin,adresa);
  std::cin>>sprat>>broj_soba>>kvadratura;
  Stan stan(adresa,sprat,broj_soba,namjesten,kvadratura);
  std::cin.ignore(1000,'\n');
  std::cin.clear();
  std::string imeagenta;
  std::getline(std::cin,imeagenta);
  double cijena;
  std::cin>>cijena;
  Prodaja prodaja(imeagenta,cijena,dat,kupac,stan);
  prodaja.PomjeriDanUnaprijed();
  prodaja.PomjeriDanUnazad();
  prodaja.Ispisi();*/
  }catch(std::range_error e){
    std::cout << e.what() << std::endl;
  }catch(...){
    std::cout << "Problemi sa memorijom" << std::endl;
  }
	return 0;
}