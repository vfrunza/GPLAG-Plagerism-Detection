/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
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
    if(godina<1 || mjesec<1 || dan<1 || dan>broj_dana[mjesec-1])throw std::domain_error("Neispravan datum.");
    d=dan;m=mjesec;g=godina;
}
class Kupac{
  std::string imeiprezime;
  Datum datum_rodj;
  public:
  Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja): datum_rodj(datum_rodjenja) {Postavi(ime_i_prezime,datum_rodjenja);}
  void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja){
    for(int i=0;i<ime_i_prezime.length();i++){
      if((ime_i_prezime[i]<'A' && ime_i_prezime[i]!=' ') || (ime_i_prezime[i]>'Z' && ime_i_prezime[i]<'a') || ime_i_prezime[i]>'z')throw std::domain_error("Neispravno ime i prezime.");
      //else if((ime_i_prezime[i]<'A' || ime_i_prezime[i]>'Z') && ime_i_prezime[i]!=' ')throw std::domain_error("Neispravno ime i prezime.");
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
    if(sprat<=0 || broj_soba<=0 || kvadratura<=0 || (namjesten!=0 && namjesten!=1))throw std::domain_error("Neispravan unos podataka.");
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
      if((ime_agenta_prodaje[i]<'A' && ime_agenta_prodaje[i]!=' ') || (ime_agenta_prodaje[i]>'Z' && ime_agenta_prodaje[i]<'a') || ime_agenta_prodaje[i]>'z')throw std::domain_error("Neispravno ime i prezime.");
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
  if(kupljen.DajBrojSoba()==1)std::cout <<kupljen.DajBrojSoba()<<" sobu." << " Kvadratura stana je "<<kupljen.DajKvadraturu()<<" (m^2) i stan ";
  if(kupljen.DajBrojSoba()>=2 && kupljen.DajBrojSoba()<=4)std::cout <<kupljen.DajBrojSoba()<<" sobe." <<" Kvadratura stana je "<<kupljen.DajKvadraturu()<<" (m^2) i stan ";
  if(kupljen.DajBrojSoba()>=5)std::cout <<kupljen.DajBrojSoba()<<" soba." << " Kvadratura stana je "<<kupljen.DajKvadraturu()<<" (m^2) i stan ";
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
  int dimenzija;
  Prodaja **niz=nullptr;
  int broj_prodatih;
  public:
  explicit Prodaje(int max_broj_prodaja): dimenzija(max_broj_prodaja), broj_prodatih(0), niz(new Prodaja* [dimenzija]{}) {for(int i=0;i<dimenzija;i++)niz[i]=nullptr;}
  Prodaje(std::initializer_list<Prodaja> spisak_prodaja) : dimenzija(spisak_prodaja.size()), niz(new Prodaja*[spisak_prodaja.size()] {}),broj_prodatih(0) {
    for(int i=0;i<spisak_prodaja.size();i++)niz[i]=nullptr;
    for(auto it=spisak_prodaja.begin();it!=spisak_prodaja.end();it++)niz[broj_prodatih++]=new Prodaja(*it);
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
    std::cout << "Dobrodosli!" << std::endl<<std::endl;
    int n;
    int daLiJePrekinuto(0);
    std::vector<Stan> v;
    std::vector<Kupac> k;
    std::vector<Prodaja> p;
    do{
      std::cout <<"Izaberite opciju:" << std::endl<<" 0 - kraj" <<std::endl<<" 1 - uredjivanje stanova"<<std::endl<<" 2 - uredjivanje kupaca"<<std::endl<<" 3 - uredjivanje prodaja"<<std::endl;
      std::cin >> n;
      if(n==0){std::cout << std::endl<<std::endl<<"Dovidjenja!";break;}
      if(n==1){
        int opcija;
        do{
        std::cout <<std::endl<<"Izaberite opciju:" << std::endl<<" 0 - nazad" <<std::endl<<" 1 - dodavanje stana"<<std::endl<<" 2 - uredjivanje stanova"<<std::endl<<" 3 - ispis svih stanova"<<std::endl<<" 4 - kraj"  << std::endl;
        std::cin.ignore(10000,'\n');
        std::cin.clear();
        std::cin>>opcija;
        if(opcija==0)break;
        if(opcija==1){
          int UspjesnoUnesen(0);
          do{
            UspjesnoUnesen=0;
          std::cin.ignore(10000,'\n');
          std::cin.clear();
          std::string adresa;
          std::cout << "Unesite adresu: " ;
          std::getline(std::cin,adresa);
          std::cout<<"Unesite sprat: ";
          int sprat;
          std::cin>>sprat;
          std::cout << "Unesite broj soba: ";
          int broj_soba;
          std::cin >> broj_soba;
          int namjesten;
          std::cout << "Da li je stan namjesten (1 - da, 0 - ne): " ;
          std::cin >> namjesten;
          std::cout << "Unesite kvadraturu: ";
          double kvadratura;
          std::cin >> kvadratura;
          try{
          if(namjesten!=0 && namjesten!=1)throw std::domain_error("Neispravan unos podataka.");
          Stan s(adresa,sprat,broj_soba,namjesten,kvadratura);
          v.push_back(s);
          std::cout << "Stan je uspjesno dodan!" << std::endl;
          }catch(std::domain_error e){
            std::cout << "Izuzetak: "<<e.what()<<" Molimo unesite opet." << std::endl<<std::endl;
            UspjesnoUnesen=1;
          }
          }while(UspjesnoUnesen!=0);
        }
        if(opcija==2){
          std::cout << "Odaberite stan. Dostupni stanovi su: " << std::endl;
          for(int i=0;i<v.size();i++){
            std::cout << " "<<i+1<<" - ";
            v[i].Ispisi() ;
          }
          std::cin.ignore(10000,'\n');
          std::cin.clear();
          int redni_broj_stana;
          std::cin>>redni_broj_stana;
          std::cout <<std::endl<<"Odaberite polje koje zelite urediti: "<< std::endl<<" 0 - nazad"<<std::endl<<" 1 - adresa"<<std::endl<<" 2 - sprat" << std::endl<<" 3 - broj soba"<<std::endl<<" 4 - da li je stan namjesten"<<std::endl<<" 5 - kvadratura"<<std::endl<<" 6 - sve"<<std::endl;
          int polje;
          std::cin >> polje;
          if(polje==0)continue;
          if(polje==1){
            std::cin.ignore(10000,'\n');
            std::cin.clear();
            std::string nova_adresa;
            std::cout << "Unesite adresu: " ;
            std::getline(std::cin,nova_adresa);
            for(int i=0;i<v.size();i++){
              if(redni_broj_stana==(i+1))v[i].Postavi(nova_adresa,v[i].DajSprat(),v[i].DajBrojSoba(),v[i].DajNamjesten(),v[i].DajKvadraturu());
            }
          }
          if(polje==2){
            int UspjesnoUnesen(0);
            do{
            UspjesnoUnesen=0;
            int novi_sprat;
            std::cin.ignore(10000,'\n');
            std::cin.clear();
            std::cout << "Unesite sprat: " ;
            std::cin >> novi_sprat;
            try{
            for(int i=0;i<v.size();i++){
              if(redni_broj_stana==(i+1))v[i].Postavi(v[i].DajAdresu(),novi_sprat,v[i].DajBrojSoba(),v[i].DajNamjesten(),v[i].DajKvadraturu());
            }
            }catch(std::domain_error e){
                std::cout << "Izuzetak: "<<e.what()<<" Molimo unesite opet."<<std::endl;
                  UspjesnoUnesen=1;
            }
            }while(UspjesnoUnesen!=0);
          }
          if(polje==3){
            int UspjesnoUnesen(0);
            do{
              UspjesnoUnesen=0;
              int novi_broj_soba;
              std::cin.ignore(10000,'\n');
              std::cin.clear();
              std::cout << "Unesite broj soba: ";
              std::cin >>novi_broj_soba;
              try{
              for(int i=0;i<v.size();i++){
              if(redni_broj_stana==(i+1))v[i].Postavi(v[i].DajAdresu(),v[i].DajSprat(),novi_broj_soba,v[i].DajNamjesten(),v[i].DajKvadraturu());
            }
            }catch(std::domain_error e){
                std::cout << "Izuzetak: "<<e.what()<<" Molimo unesite opet." <<std::endl;
                  UspjesnoUnesen=1;
            }
            }while(UspjesnoUnesen!=0);
          }
          if(polje==4){
            int UspjesnoUnesen(0);
            do{
              UspjesnoUnesen=0;
              int novi_namjesten;
              std::cin.ignore(10000,'\n');
              std::cin.clear();
              try{
              std::cout << "Da li je stan namjesten (1 - da, 0 - ne): " ;
              std::cin >>novi_namjesten;
              if(novi_namjesten!=0 || novi_namjesten!=1)throw std::domain_error("Neispravan unos podataka.");
              for(int i=0;i<v.size();i++){
              if(redni_broj_stana==(i+1))v[i].Postavi(v[i].DajAdresu(),v[i].DajSprat(),v[i].DajBrojSoba(),novi_namjesten,v[i].DajKvadraturu());
            }
            }catch(std::domain_error e){
                std::cout << "Izuzetak: "<<e.what()<<" Molimo unesite opet." <<std::endl;
                  UspjesnoUnesen=1;
            }
            }while(UspjesnoUnesen!=0);
          }
          if(polje==5){
            int UspjesnoUnesen(0);
            do{
              UspjesnoUnesen=0;
              double nova_kvadratura;
              std::cin.ignore(10000,'\n');
              std::cin.clear();
              std::cout << "Unesite kvadraturu: ";
              std::cin >>nova_kvadratura;
            try{
              for(int i=0;i<v.size();i++){
              if(redni_broj_stana==(i+1))v[i].Postavi(v[i].DajAdresu(),v[i].DajSprat(),v[i].DajBrojSoba(),v[i].DajNamjesten(),nova_kvadratura);
            }
            }catch(std::domain_error e){
                std::cout << "Izuzetak: "<<e.what()<<" Molimo unesite opet." <<std::endl;
                  UspjesnoUnesen=1;
            }
            }while(UspjesnoUnesen!=0);
          }
          if(polje==6){
            int UspjesnoUnesen(0);
          do{
            UspjesnoUnesen=0;
          std::cin.ignore(10000,'\n');
          std::cin.clear();
          std::string adresa;
          std::cout << "Unesite adresu: " ;
          std::getline(std::cin,adresa);
          std::cout<<"Unesite sprat: ";
          int sprat;
          std::cin>>sprat;
          std::cout << "Unesite broj soba: ";
          int broj_soba;
          std::cin >> broj_soba;
          int namjesten;
          std::cout << "Da li je stan namjesten (1 - da, 0 - ne): " ;
          std::cin >> namjesten;
          std::cout << "Unesite kvadraturu: ";
          double kvadratura;
          std::cin >> kvadratura;
          try{
          if(namjesten!=0 && namjesten!=1)throw std::domain_error("Neispravan unos podataka.");
          for(int i=0;i<v.size();i++){
            if(redni_broj_stana==(i+1))v[i].Postavi(adresa,sprat,broj_soba,namjesten,kvadratura);
          }
          }catch(std::domain_error e){
            std::cout << "Izuzetak: "<<e.what()<<" Molimo unesite opet." << std::endl<<std::endl;
            UspjesnoUnesen=1;
          }
          }while(UspjesnoUnesen!=0);
          }
        }
        if(opcija==3){
          for(int i=0;i<v.size();i++){
            std::cout << i+1<<". ";
            v[i].Ispisi();
          }
        }
        if(opcija==4){daLiJePrekinuto=1;break;}
        
        }while(opcija!=4);
      }
        if(n==2){
        int opcija;
        do{
        std::cout <<std::endl<<"Izaberite opciju:" << std::endl<<" 0 - nazad" <<std::endl<<" 1 - dodavanje kupca"<<std::endl<<" 2 - uredjivanje kupaca"<<std::endl<<" 3 - ispis svih kupaca"<<std::endl<<" 4 - kraj"  << std::endl;
        std::cin.ignore(10000,'\n');
        std::cin.clear();
        std::cin>>opcija;
        if(opcija==0)break;
        if(opcija==1){
          int UspjesnoUnesen(0);
          do{
            UspjesnoUnesen=0;
            std::cout << "Unesite ime i prezime kupca: ";
            std::cin.ignore(10000,'\n');
            std::cin.clear();
            std::string ime_i_prezime;
            std::getline(std::cin,ime_i_prezime);
            std::cout << "Unesite datum rodjenja (formata d/m/g): ";
            int dan,mjesec,godina;
            char znak,znak2;
            std::cin >> dan >>znak>>mjesec>>znak2>>godina ;
            try{
              Datum datum=Datum(dan,mjesec,godina);
              Kupac kupac=Kupac(ime_i_prezime,datum);
              k.push_back(kupac);
              std::cout << "Kupac je uspjesno dodan!" << std::endl;
            }catch(std::domain_error e){
              std::cout << "Izuzetak: "<<e.what()<<" Molimo unesite opet." << std::endl;
              UspjesnoUnesen=1;
            }
          }while(UspjesnoUnesen!=0);
        }
        if(opcija==2){
          int UspjesnoUnesen(0);
          std::cout << "Odaberite kupca kojeg zelite urediti. Dostupni kupci su:" << std::endl;
          for(int i=0;i<k.size();i++){
            std::cout <<" "<< i+1<<" - " ;
            k[i].Ispisi();
          }
          int redni_broj_kupca;
          std::cin >> redni_broj_kupca;
          do{
          UspjesnoUnesen=0;
          std::cin.ignore(1000,'\n');
          std::cin.clear();
          std::cout << "Unesite ime i prezime kupca: ";
          std::string novo_ime;
          std::getline(std::cin,novo_ime);
          int dan,mjesec,godina;
          char znak1,znak2;
          std::cout<<"Unesite datum rodjenja (formata d/m/g): ";
          std::cin >> dan>>znak1>>mjesec>>znak2>>godina;
          try{
          Datum datum=Datum(dan,mjesec,godina);
          for(int i=0;i<k.size();i++){
            if(redni_broj_kupca==(i+1)){k[i].Postavi(novo_ime,datum);}
          }
          std::cout << "Kupac je uspjesno izmijenjen!" << std::endl;
          }catch(std::domain_error e){
            std::cout << "Izuzetak: "<<e.what()<<"Molimo unesite opet." << std::endl;
            UspjesnoUnesen=1;
          }
          }while(UspjesnoUnesen!=0);
        }
        if(opcija==3){
          for(int i=0;i<k.size();i++)k[i].Ispisi();
        }
        if(opcija==4){daLiJePrekinuto=1;break;}
        }while(opcija!=4);
        }
        if(n==3){
          int opcija;
          do{
            std::cout <<std::endl<<"Izaberite opciju:" << std::endl<<" 0 - nazad" <<std::endl<<" 1 - dodavanje prodaje"<<std::endl<<" 2 - uredjivanje prodaje"<<std::endl<<" 3 - ispis prodaja"<<std::endl<<" 4 - brisanje prodaja"  << std::endl<<" 5 - kraj"<<std::endl;
            std::cin.ignore(1000,'\n');
            std::cin.clear();
            std::cin>>opcija;
            if(opcija==0)break;
            if(opcija==1){
               int opcija2;
              do{
              std::cout << std::endl<<"Izaberite opciju:" << std::endl<<" 0 - nazad"<<std::endl<<" 1 - dodavanje potpuno nove prodaje"<<std::endl<<" 2 - dodavanje nove prodaje na osnovu arhive"<<std::endl<<" 3 - kraj"<<std::endl;
              std::cin >> opcija2;
              if(opcija2==0)break;
              if(opcija2==1){
                int UspjesnoUnesen(0);
                do{
                  UspjesnoUnesen=0;
                std::cout << "Unesite ime i prezime agenta prodaje: ";
                std::string novo_ime_agenta;
                std::getline(std::cin,novo_ime_agenta);
                std::cout << "Unesite datum prodaje (formata d/m/g): ";
                int dan,mjesec,godina;
                char znak1,znak2;
                std::cin>>dan>>znak1>>mjesec>>znak2>>godina;
                try{
                  Datum datum=Datum(dan,mjesec,godina);
                  std::cout << "Unesite cijenu stana: ";
                  int cijena;
                  std::cin >> cijena;
                  std::cout << "Unesite ime kupca: " ;
                  std::cin.ignore(10000,'\n');
                  std::cin.clear();
                  std::string novo_ime_kupca;
                  std::getline(std::cin,novo_ime_kupca);
                  std::cout << "Unesite datum rodjenja kupca (formata d/m/g): ";
                  int dan1,mjesec1,godina1;
                  char znak3,znak4;
                  std::cin >> dan1>>znak3>>mjesec1>>znak4>>godina1;
                  Datum datum_kupca=Datum(dan1,mjesec1,godina1);
                  Kupac kupac=Kupac(novo_ime_kupca,datum_kupca);
                  std::cout<<"Unesite adresu: ";
                  std::string adresa_stanovanja;
                  std::cin.ignore(1000,'\n');
                  std::cin.clear();
                  std::getline(std::cin,adresa_stanovanja);
                  std::cout<<"Unesite sprat: ";
                  int sprat;
                  std::cin >> sprat;
                  std::cout << "Unesite broj soba: " ;
                  int broj_soba;
                  std::cin >> broj_soba;
                  std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                  int namjesten_stan;
                  std::cin >> namjesten_stan;
                  std::cout << "Unesite kvadraturu: ";
                  double kvadratura;
                  std::cin>>kvadratura;
                  if(namjesten_stan!=0 && namjesten_stan!=1)throw std::domain_error("Neispravan unos podataka.");
                  Stan trenutni=Stan(adresa_stanovanja,sprat,broj_soba,namjesten_stan,kvadratura);
                  Prodaja prodaja=Prodaja(novo_ime_agenta,cijena,datum,kupac,trenutni);
                  p.push_back(prodaja);
                  std::cout << "Prodaja uspjesno dodana!" << std::endl;
                  }catch(std::domain_error e){
                  std::cout << "Izuzetak: "<< e.what()<<" Molimo unesite opet." << std::endl;
                  UspjesnoUnesen=1;
                }
                
              }while(UspjesnoUnesen!=0);
            }
            if(opcija2==2){
               int UspjesnoUnesen(0);
               std::cin.ignore(1000,'\n');
               std::cin.clear();
                do{
                  UspjesnoUnesen=0;
                std::cout << "Unesite ime i prezime agenta prodaje: ";
               
                std::string novo_ime_agenta;
                std::getline(std::cin,novo_ime_agenta);
                std::cout << "Unesite datum prodaje (formata d/m/g): ";
                int dan,mjesec,godina;
                char znak1,znak2;
                std::cin>>dan>>znak1>>mjesec>>znak2>>godina;
                try{
                  std::cout << "Unesite cijenu stana: ";
                  int cijena;
                  std::cin >> cijena;
                  /*std::cin.ignore(1000,'\n');
                  std::cin.clear();*/
                  std::cout << "Odaberite kupca. Dostupni kupci su:" << std::endl;
                  for(int i=0;i<k.size();i++){
                    std::cout <<" "<< i+1<<" - " ;
                    k[i].Ispisi();
                  }
                  int redni_broj_kupca;
                  /*std::cin.ignore(10000,'\n');
                  std::cin.clear();*/
                  std::cin >> redni_broj_kupca;
                  std::cout << "Odaberite stan. Dostupni stanovi su:" << std::endl;
                  for(int i=0;i<v.size();i++){
                    std::cout <<" "<< i+1<<" - ";
                    v[i].Ispisi();
                  }
                  int redni_broj_stana;
                  std::cin >> redni_broj_stana;
                  std::string ime_kupca;
                  int d,m,g;
                  for(int i=0;i<k.size();i++){
                    if((i+1)==redni_broj_kupca){
                      d=k[i].DajDatumRodjenja().DajDan();
                      m=k[i].DajDatumRodjenja().DajMjesec();
                      g=k[i].DajDatumRodjenja().DajMjesec();
                      ime_kupca=k[i].DajImePrezime();
                    }
                  }
                  Datum datum=Datum(d,m,g);
                  std::string Adresa;
                  int sprat,soba,namjesten;
                  double kvadrat;
                  for(int i=0;i<v.size();i++){
                    if((i+1)==redni_broj_stana){
                      Adresa=v[i].DajAdresu();
                      sprat=v[i].DajSprat();
                      soba=v[i].DajBrojSoba();
                      namjesten=v[i].DajNamjesten();
                      kvadrat=v[i].DajKvadraturu();
                    }
                  }
                  Prodaja prod=Prodaja(novo_ime_agenta,cijena,dan,mjesec,godina,ime_kupca,datum,Adresa,sprat,soba,namjesten,kvadrat);
                  p.push_back(prod);
                  std::cout << "Prodaja uspjesno dodana!" << std::endl;
                }catch(std::domain_error e){
                  std::cout << "Izuzetak: "<<e.what()<<" Molimo unesite opet." << std::endl;
                  UspjesnoUnesen=1;
                }
                }while(UspjesnoUnesen!=0);
              }
              if(opcija2==3){daLiJePrekinuto=1;break;}
            }while(opcija2!=3);
            }
            if(opcija==2){
              std::cout << "Odaberite prodaju koju zelite izmijeniti. Dostupne prodaje su: " << std::endl;
              for(int i=0;i<p.size();i++){
                std::cout <<" "<< i+1<<" - " << std::endl;
                p[i].Ispisi();
              }
              int odaberi,zapamcena_prodaja;
              std::cin >> zapamcena_prodaja;
              std::cout << std::endl<<"Izaberite opciju: " << std::endl<<" 0 - nazad"<<std::endl<<" 1 - izmjena agenta"<<std::endl<<" 2 - izmjena datuma prodaje"<<std::endl<<" 3 - izmjena kupca"<<std::endl<<" 4 - izmjena stana"<<std::endl<<" 5 - izmjena cijene stana"<<std::endl;
              std::cin >> odaberi;
              if(odaberi==1){
              std::cout << "Unesite ime i prezime agenta prodaje: ";
              std::string novo_ime_agenta;
              std::getline(std::cin,novo_ime_agenta);
              /*for(int i=0;i<p.size();i++){
                if((i+1)==zapamcena_prodaja){
                  
                //  p[i]=Prodaja(novo_ime_agenta,p[i].DajCijenuStana(),p[i].DajDatumProdaje(),p[i].DajImeKupca(),p[i].DajAdresu())
                }
              }*/
              std::cout << "Prodaja je uspjesno izmijenjena!" << std::endl;
              std::cin.ignore(1000,'\n');
              std::cin.clear();
              }
              if(odaberi==2){
                std::cout << "Unesite datum prodaje (formata d/m/g): ";
                int dan,mj,god;
                char znak1,znak2;
                std::cin >> dan>>znak1>>mj>>znak2>>god;
                try{
                Datum dat=Datum(dan,mj,god);
                for(int i=0;i<p.size();i++){
                  if((i+1)==zapamcena_prodaja)p[i].PromijeniDatumKupovine(dat);
                }
                std::cout << "Prodaja je uspjesno izmijenjena!" << std::endl;

                }catch(std::domain_error e){
                  std::cout << "Izuzetak: "<<e.what()<<" Molimo unesite opet." << std::endl;
                }
              }
              if(odaberi==3){
                std::cout << std::endl<<"Izaberite opciju:"<<std::endl<<" 0 - nazad"<<std::endl<<" 1 - odabir postojeceg kupca"<<std::endl<<" 2 - dodavanje novog kupca " << std::endl;
                int novi;
                std::cin >> novi;
                if(novi==0)break;
                if(novi==1){
                  std::cout << "Odaberite kupca. Dostupni kupci su:" << std::endl;
                  for(int i=0;i<k.size();i++)k[i].Ispisi();
                  int najnoviji;
                  std::cin >> najnoviji;
                  for(int i=0;i<k.size();i++){
                    if((i+1)==najnoviji)p[zapamcena_prodaja].PromijeniKupca(k[i]);
                  }
                  std::cout << "Prodaja je uspjesno izmijenjena!" << std::endl;
                }
                if(novi==2){
                  std::cout << "Unesite ime i prezime kupca:" ;
                  std::string novo_ime_kupca;
                  std::getline(std::cin,novo_ime_kupca);
                  std::cin.ignore(10000,'\n');
                  std::cin.clear();
                  std::cout << "Unesite datum rodjenja (formata dan/mjesec/godina):" ;
                  int d,m,g;
                  char znak1,znak2;
                  std::cin >> d>>znak1>>m>>znak2>>g;
                  try {
                    Datum dat(d,m,g);
                    Kupac kup(novo_ime_kupca,dat);
                    for(int i=0;i<p.size();i++){
                      if((i+1)==zapamcena_prodaja)p[i].PromijeniKupca(kup);
                    }
                  std::cout << "Prodaja je uspjesno izmijenjena!" << std::endl;
                  }
                  catch (std::domain_error e) {
                    std::cout << "Izuzetak: "<<e.what() <<" Molimo unesite opet."<< std::endl;
                  }
                  
                }
                  
                }
                if(odaberi==5){
                  std::cout << "Unesite cijenu stana: ";
                  int cijena;
                  std::cin >> cijena;
                  for(int i=0;i<p.size();i++){
                    if((i+1)==zapamcena_prodaja)p[i].PromijeniCijenuProdaje(cijena);
                  }
                  
                }
              }
            //}
            if(opcija==3){
              for(int i=0;i<p.size();i++){
                std::cout << i+1<<". " <<std::endl;
                p[i].Ispisi();
              }
            }
            //if(opcija==4)
        }while(opcija!=5);
        }
      if(daLiJePrekinuto==1)break;
      if(n==0)break;
    }while(n!=0);

  }catch(std::range_error e){
    std::cout << e.what() << std::endl;
  }catch(...){
    std::cout << "Problemi sa memorijom" << std::endl;
  }
	return 0;
}