/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include<string>
#include<stdexcept>
#include<iomanip>
#include<initializer_list>
#include<algorithm>
#include<vector>
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
    
    const int kapacitet;
    int broj_evidentiranih;
    Prodaja **sveprodaje;
    
    
  public:
  explicit Prodaje(int max_broj_prodaja):kapacitet(max_broj_prodaja),broj_evidentiranih(0),sveprodaje(new Prodaja*[max_broj_prodaja]{}){};
  Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
  ~Prodaje();
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

Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja):kapacitet(20),broj_evidentiranih(spisak_prodaja.size()),
sveprodaje(new Prodaja*[kapacitet]{}){
    try{
        int br(0);
    for(const auto &a : spisak_prodaja){
        sveprodaje[br]=new Prodaja(a);
        br++;
        
    }
    }catch(...){
        for(int i=0;i<spisak_prodaja.size();i++) delete sveprodaje[i];
        delete []sveprodaje;
        throw;
    }
}
Prodaje::~Prodaje(){
    
    for(int i=0;i<broj_evidentiranih;i++) delete sveprodaje[i];
    delete[] sveprodaje;
}

Prodaje::Prodaje(const Prodaje &prodaje):kapacitet(prodaje.kapacitet),broj_evidentiranih(prodaje.broj_evidentiranih),sveprodaje(new Prodaja*[prodaje.kapacitet]{}){
    try{
        for(int i=0;i<prodaje.broj_evidentiranih;i++){
           sveprodaje[i]=new Prodaja(*prodaje.sveprodaje[i]);
        }
    }catch(...){
        for(int i=0;i<prodaje.broj_evidentiranih;i++) delete sveprodaje[i];
        delete [] sveprodaje; throw;
    }

}
Prodaje::Prodaje(Prodaje &&prodaje):kapacitet(prodaje.kapacitet),broj_evidentiranih(prodaje.broj_evidentiranih),sveprodaje(prodaje.sveprodaje){
    prodaje.sveprodaje=nullptr; prodaje.broj_evidentiranih=0;
}

Prodaje &Prodaje::operator =(const Prodaje &prodaje){
   if(prodaje.broj_evidentiranih>broj_evidentiranih){
       try{
           for(int i=broj_evidentiranih;i<prodaje.broj_evidentiranih;i++){
               sveprodaje[i]=new Prodaja(*prodaje.sveprodaje[i]);
           }
       }catch(...){
           for(int i=broj_evidentiranih;i<prodaje.broj_evidentiranih;i++){
               delete sveprodaje[i]; sveprodaje[i]=nullptr;
           }
           throw;
       }
   }else{
       for(int i=prodaje.broj_evidentiranih;i<broj_evidentiranih;i++){
           delete sveprodaje[i]; sveprodaje[i]=nullptr;
       }
   }
   broj_evidentiranih=prodaje.broj_evidentiranih;
   for(int i=0;i<broj_evidentiranih;i++) *sveprodaje[i]=*prodaje.sveprodaje[i];
   
   return *this;
} 

Prodaje &Prodaje::operator =(Prodaje &&prodaje){
    std::swap(broj_evidentiranih,prodaje.broj_evidentiranih);
    std::swap(sveprodaje,prodaje.sveprodaje);
    return *this;
}
void Prodaje::RegistrirajProdaju (const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan){
    if(broj_evidentiranih>=kapacitet)
    throw std::range_error("Dostignut maksimalni broj prodaja");
    
    *sveprodaje[broj_evidentiranih]=Prodaja(ime_agenta_prodaje,cijena_stana,datum_prodaje,kupac_stana,kupljeni_stan);
    broj_evidentiranih++;
    
}
void Prodaje::RegistrirajProdaju (const std::string &ime_agenta_prodaje, double cijena_stana,int dan_prodaje,int mjesec_prodaje, int godina_prodaje,
    std::string &ime_kupca, const Datum &datum_rodjenja_kupca,const std::string &adresa_stana,int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata)
{
    if(broj_evidentiranih>=kapacitet)
    throw std::range_error("Dostignut maksimalni broj prodaja");
    
    *sveprodaje[broj_evidentiranih]=Prodaja(ime_agenta_prodaje,cijena_stana,dan_prodaje,mjesec_prodaje,godina_prodaje,ime_kupca,datum_rodjenja_kupca,
    adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata);
    
    broj_evidentiranih++;
}

void Prodaje::RegistrirajProdaju(Prodaja *prodaja){
    if(broj_evidentiranih>=kapacitet)
    throw std::range_error("Dostignut maksimalni broj prodaja");
    sveprodaje[broj_evidentiranih]=prodaja;
    broj_evidentiranih++;
}

int Prodaje::DajBrojProdaja() const{
   return broj_evidentiranih;
}

int Prodaje:: DajBrojProdajaNaDatum(const Datum &datum) const{
   
    
    return std::count_if(sveprodaje[0],sveprodaje[broj_evidentiranih],[datum](Prodaja a){ Datum b(a.DajDatumProdaje());
    if(b.DajDan()==datum.DajDan() && b.DajMjesec()==datum.DajMjesec() && b.DajGodinu()==datum.DajGodinu()) return true; else return false; });

}

int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const{
     return std::count_if(sveprodaje[0],sveprodaje[broj_evidentiranih],[ime_agenta](Prodaja a){ if(a.DajImeAgenta()==ime_agenta) return true; else return false; });
}
Prodaja &Prodaje::DajNajranijuProdaju(){
    
    auto b(std::min_element(sveprodaje[0],sveprodaje[broj_evidentiranih],[](Prodaja a,Prodaja b){ return ProdatPrije(a,b);}));
    
    return *b;
}
Prodaja Prodaje::DajNajranijuProdaju() const{
     auto b(std::min_element(sveprodaje[0],sveprodaje[broj_evidentiranih],[](Prodaja a,Prodaja b){ return ProdatPrije(a,b);}));
    
    return *b;
}
Prodaja &Prodaje::DajNajskupljuProdaju(){
    
    auto b(std::max_element(sveprodaje[0],sveprodaje[broj_evidentiranih],[](Prodaja a,Prodaja b){ return SkupljiStan(a,b);}));
    return *b;
}

Prodaja Prodaje::DajNajskupljuProdaju() const{
    
    auto b(std::max_element(sveprodaje[0],sveprodaje[broj_evidentiranih],[](Prodaja a,Prodaja b){ return SkupljiStan(a,b);}));
    return *b;
}

void Prodaje::IsprazniKolekciju(){
    for(int i=0;i<kapacitet;i++){
        delete sveprodaje[i];
        sveprodaje[i]=nullptr;
    }
    broj_evidentiranih=0;
}
void Prodaje::ObrisiNajranijuProdaju(){
    auto p(-1);
    
    if(broj_evidentiranih<=0) throw std::range_error("Prazna kolekcija");
    
    for(int i=0;i<broj_evidentiranih;i++){
        if(sveprodaje[i]->DajDatumProdaje().DajDan()==DajNajranijuProdaju().DajDatumProdaje().DajDan() && sveprodaje[i]->DajDatumProdaje().DajMjesec()==DajNajranijuProdaju().DajDatumProdaje().DajMjesec() &&
        sveprodaje[i]->DajDatumProdaje().DajGodinu()==DajNajranijuProdaju().DajDatumProdaje().DajGodinu()){
            delete sveprodaje[i];
            sveprodaje[i]=nullptr;
            p=i;
            break;
        }
    }
    for(int i=p;i<kapacitet-1;i++){
        
        sveprodaje[i]=sveprodaje[i+1];
        
    }
    broj_evidentiranih--;
    
}
void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta){

 if(broj_evidentiranih<=0) throw std::range_error("Prazna kolekcija");
 int br(0);
 
 for(int i=0;i<broj_evidentiranih;i++){
     if(sveprodaje[i]->DajImeAgenta()==ime_agenta){
         delete sveprodaje[i];
         sveprodaje[i]=nullptr;
         br++;
     }
 }
 
 for(int i=0;i<kapacitet;i++){
     if(sveprodaje[i]==nullptr){
         for(int j=i;j<kapacitet-1;j++){
             sveprodaje[j]=sveprodaje[j+1];
         }
     }
 }
 
 broj_evidentiranih=broj_evidentiranih-br;
}

void Prodaje::ObrisiProdajeNaDatum(const Datum &datum){
    
    if(broj_evidentiranih<=0) throw std::range_error("Prazna kolekcija");
 int br(0);
 
 for(int i=0;i<broj_evidentiranih;i++){
     if(sveprodaje[i]->DajDatumProdaje().DajDan()==datum.DajDan() && sveprodaje[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec() &&
        sveprodaje[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu()){
         delete sveprodaje[i];
         sveprodaje[i]=nullptr;
         br++;
     }
 }
 
 for(int i=0;i<kapacitet;i++){
     if(sveprodaje[i]==nullptr){
         for(int j=i;j<kapacitet-1;j++){
             sveprodaje[j]=sveprodaje[j+1];
         }
     }
 }
 
 broj_evidentiranih=broj_evidentiranih-br;
}

void Prodaje::IspisiProdajeNaDatum(const Datum &datum)const{
    
    std::vector<Prodaja> v;
    for(int i=0;i<broj_evidentiranih;i++){
        
        if(sveprodaje[i]->DajDatumProdaje().DajDan()==datum.DajDan() && sveprodaje[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec() &&
        sveprodaje[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu()){
            
            v.push_back(*sveprodaje[i]);
        }
    }
    
    std::sort(v.begin(),v.end(),[](Prodaja p1,Prodaja p2){return p1.DajImeKupca()>p2.DajImeKupca();});
   
   std::for_each(v.begin(),v.end(),[](Prodaja p){p.Ispisi();});
    
}
void Prodaje::IspisiSveProdaje() const{
     std::vector<Prodaja> v;
    for(int i=0;i<broj_evidentiranih;i++){
          v.push_back(*sveprodaje[i]);
   }
    
    std::sort(v.begin(),v.end(),[](Prodaja p1,Prodaja p2){if(p1.DajDatumProdaje().DajDan()==p2.DajDatumProdaje().DajDan() && p1.DajDatumProdaje().DajMjesec()==p2.DajDatumProdaje().DajMjesec() &&
    p1.DajDatumProdaje().DajGodinu()== p2.DajDatumProdaje().DajGodinu())   return p1.DajImeKupca()>p2.DajImeKupca();
    return ProdatPrije(p1,p2);});
   
   std::for_each(v.begin(),v.end(),[](Prodaja p){p.Ispisi();});

}
 Prodaja &Prodaje::DajProdaju(int br){
     
     if(br<0 || br>broj_evidentiranih) throw std::domain_error("izuzetak");
     return *sveprodaje[br-1];
 }
int main ()
{

/*

    std::cout<<"Dobrodosli!";
    
    for(;;){
        try{
            Prodaje sveprodaje(20);
        std::cout<<"Izaberite opciju: "<<std::endl;
        std::cout<<" 0 - kraj\n"<<" 1 - uredjivanje stanova\n"<<" 2 - uredjivanje kupaca\n"<<" 3 - uredjivanje prodaja";
        
        int n;
        std::cin>>n;
        
        if(n==0) break;
        if(n==1){
            for(;;){
             std::cout<<"Izaberite opciju: "<<std::endl;
        std::cout<<" 0 - nazad\n"<<" 1 - dodavanje stana\n"<<" 2 - uredjivanje stanova\n"<<" 3 - ispis svih stanova" <<" 4 - kraj";
            
            int n1;
            std::cin>>n1;
            if(n1==0) break;
            if(n1==1){
                std::cout<<"\nUnesite adresu: ";
                std::cin.ignore(10000,'\n');
                std::string s;
                std::getline(std::cin,s);
                std::cout<<"\nUnesite broj soba: ";
                int sprat;
                std::cin>>sprat;
                std::cout<<"\nUnesite broj soba: ";
                int brsoba;
                std::cin>>brsoba;
                std::cout<<"\nDa li je stan namjesten (1 - da, 0 - ne):";
                bool namjesten;
                std::cin>>namjesten;
                std::cout<<"\nUnesite kvadraturu: ";
                double kvadratura;
                std::cin>>kvadratura;
                
                try{
                    Stan(s,sprat,brsoba,namjesten,kvadratura);
                    
                }catch(std::domain_error e){
                
                std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet.";
                    
                }
                
                
            }else break;
            
            }
        }
        else break;
    }catch(...){
        
    }
        
        
    }
*/
	return 0;
}