/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

class Datum {
    int dan,mjesec,godina;
    public:
    Datum (int d, int m, int g) { Postavi(d,m,g); }
    void Postavi (int d ,int m, int g){
        int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if((g % 4 == 0 && g % 100 != 0 )|| g % 400 == 0) broj_dana[1]++;
        if(g < 1 || d < 1 || m < 1 || m > 12 || d > broj_dana[m - 1]) throw std::domain_error("Neispravan datum!");
        dan=d; mjesec=m; godina=g;
    }
    int DajDan () const {return dan; }
    int DajMjesec () const {return mjesec;}
    int DajGodinu () const {return godina;}
    void Ispisi () const { std::cout<<DajDan()<<"/"<<DajMjesec()<<"/"<<DajGodinu(); }
};

class Kupac {
    std::string ime_i_prezime;
    Datum datum_rodjenja;
    public:
    Kupac(const std::string &s, const Datum &dat):  ime_i_prezime(s),datum_rodjenja(dat) {}
    void Postavi(const std::string &s, const Datum &dat){
        // provjera je li ime i prezime dobro
        for(int i=0; i<s.length(); i++){
            if(!(s[i]=='`' || s[i]==' ' || s[i]=='-' || 
            (s[i]<='z' && s[i]>='a') || (s[i]<='Z' && s[i]>='A') ||
            (s[i]>='1' && s[i]<='9'))) throw std::domain_error ("Neispravno ime i prezime");
        }
        ime_i_prezime=s;
        datum_rodjenja=dat;
    }
    
    std::string DajImePrezime() const{ return ime_i_prezime;}
    Datum DajDatumRodjenja() const {return datum_rodjenja;}
    void Ispisi() const { 
        auto dat=DajDatumRodjenja();
        std::cout<<DajImePrezime()<<"(";
        dat.Datum::Ispisi();
        std::cout<<")"; }
};

class Stan {
    std::string adresa;
    int sprat,broj_soba;
    bool namjesten;
    double kvadratura;
    public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
        Postavi(adresa, sprat, broj_soba, namjesten, kvadratura);
    }
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
        if(sprat<0 || broj_soba<0 || kvadratura<0) throw std::domain_error ("Neispravan unos podataka");
        Stan::adresa=adresa; Stan::sprat=sprat; Stan::broj_soba=broj_soba; 
        Stan::namjesten=namjesten; Stan::kvadratura=kvadratura;
    }
    std::string DajAdresu() const {return adresa;}
    int DajSprat() const {return sprat;}
    int DajBrojSoba() const {return broj_soba;}
    bool DajNamjesten() const {return namjesten;}
    double DajKvadraturu() const {return kvadratura;}
    void Ispisi() const {
        std::cout<<"Stan se nalazi na adresi "<<DajAdresu()<<" na "<<DajSprat()<<" spratu i ima "<<DajBrojSoba()<<" soba.";
        std::cout<<"Kvadratura stana je "<<DajKvadraturu()<<" i stan ";
        if(DajNamjesten()) std::cout<<"je namjesten";
        else std::cout<<"nije namjesten";
    }
};

class Prodaja {
     std::string ime_agenta_prodaje;
     double cijena_stana;
     Datum datum_prodaje;
     Kupac kupac_stana;
     Stan kupljeni_stan;
     public:
     //konstruktor
     Prodaja(const std::string &ime_agenta, double cijena,const Datum &datum, 
     const Kupac &kupac,const Stan &stan): 
         ime_agenta_prodaje(ime_agenta), cijena_stana(cijena), datum_prodaje(datum),
         kupac_stana(kupac), kupljeni_stan(stan){}
     //drugi konstruktor
     Prodaja(const std::string &ime_agenta, double cijena, int dan, int mjesec, int godina,
     std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba,
     bool namjesten_stan, double broj_kvadrata): ime_agenta_prodaje(ime_agenta), cijena_stana(cijena),
                                                 datum_prodaje(Datum(dan, mjesec, godina)), 
                                                 kupac_stana(Kupac(ime_kupca, datum_rodjenja_kupca)),
                                                 kupljeni_stan(Stan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata))
                                                 {}
     //funkcije
     void PromijeniKupca(const Kupac &novi_kupac)  {kupac_stana=novi_kupac;}
     void PromijeniStan(const Stan &novi_stan)    {kupljeni_stan=novi_stan;}
     void PromijeniDatumKupovine(const Datum &novi_datum)   {datum_prodaje=novi_datum;}
     void PromijeniCijenuProdaje(const double &nova_cijena) {cijena_stana=nova_cijena;}
     
     void PomjeriDanUnaprijed(){
        int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(((datum_prodaje.Datum::DajGodinu()) % 4 == 0 && (datum_prodaje.Datum::DajGodinu()) % 100 != 0 )|| (datum_prodaje.Datum::DajGodinu()) % 400 == 0) broj_dana[1]++;
        int dan=datum_prodaje.DajDan();
        int mjesec=datum_prodaje.DajMjesec();
        int godina=datum_prodaje.DajGodinu();
        dan++; 
        if(dan>broj_dana[mjesec-1]) {
            dan=1; 
            mjesec++;
            if(mjesec==13) {mjesec=1; godina++;}
        }
        datum_prodaje.Postavi(dan,mjesec,godina);
    }    
    
    
     void PomjeriDanUnazad(){
         int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(   ( (datum_prodaje.Datum::DajGodinu()) % 4 == 0 && (datum_prodaje.Datum::DajGodinu()) % 100 != 0   )|| 
            (datum_prodaje.Datum::DajGodinu()) % 400 == 0    ) broj_dana[1]++;
        int dan=datum_prodaje.DajDan();
        int mjesec=datum_prodaje.DajMjesec();
        int godina=datum_prodaje.DajGodinu();
        dan--; 
        if(dan==0) {
            mjesec--;
            if(mjesec==0) {mjesec=12; godina--;}
            dan=broj_dana[mjesec-1];
        }
        datum_prodaje.Datum::Postavi(dan,mjesec,godina);
            
    }
       
     std::string DajImeAgenta() const {return ime_agenta_prodaje;}
     std::string DajImeKupca() const {return (kupac_stana.Kupac::DajImePrezime());}
     Datum DajDatumProdaje() const {return datum_prodaje;}
     double DajCijenuStana() const {return cijena_stana;}
     Stan DajStan() const {return kupljeni_stan;}
     // napisi prijateljske 
     friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
     friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
     void Ispisi() const{
         std::cout<<std::setw(30)<<"Ime agenta:"<<DajImeAgenta()<<std::endl;
         std::cout<<std::setw(30)<<"Ime kupca:"<<DajImeKupca()<<" ";
         (kupac_stana.Kupac::DajDatumRodjenja()).Datum::Ispisi();
         std::cout<<std::endl;
         std::cout<<std::setw(30)<<"Zakazani datum prodaje:";
         DajDatumProdaje().Datum::Ispisi();
         std::cout<<std::endl;
         std::cout<<std::setw(30)<<"Cijena stana:"<<DajCijenuStana()<<std::endl;
         std::cout<<"Informacije o stanu:"<<std::endl;
         (DajStan()).Stan::Ispisi();
     }
};

bool ProdatPrije( const Prodaja &p1, const Prodaja &p2){
      if(  (p1.DajDatumProdaje()).DajGodinu()==(p2.DajDatumProdaje()).DajGodinu() ) {
          if( (p1.DajDatumProdaje()).DajMjesec()==(p2.DajDatumProdaje()).DajMjesec()){ 
              if(   (p1.DajDatumProdaje()).DajDan() < (p2.DajDatumProdaje()).DajDan()  ) return true;
          }
          if(   (p1.DajDatumProdaje()).DajMjesec()<(p2.DajDatumProdaje()).DajMjesec()  ) return true;
      }
      if(    (p1.DajDatumProdaje()).DajGodinu()<(p2.DajDatumProdaje()).DajGodinu()    )  return true;
      
      else return false;
}

bool SkupljiStan(const Prodaja &p1, const Prodaja &p2){
       if(   p1.DajCijenuStana() > p1.DajCijenuStana()  )  return true;
       else return false;
       
}
      
      

class Prodaje {
    int broj_prodaja;
    int max_velicina;
    Prodaja **niz;
    
    public:
    explicit Prodaje(int max_broj_prodaja): max_velicina(max_broj_prodaja), broj_prodaja(0), niz(new Prodaja*[max_broj_prodaja] {}) {} 
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja): broj_prodaja(0), max_velicina(spisak_prodaja.size()){
        niz=new Prodaja*[spisak_prodaja.size()];
        int i(0);
        for(auto it=spisak_prodaja.begin(); it<spisak_prodaja.end(); it++){
            niz[i]= new Prodaja(*it);
            i++;
        }
    }
    ~Prodaje() {
        for(int i=0; i<max_velicina; i++) delete niz[i];
        delete [] niz;
    }
    //kopirajuci konstruktor
    Prodaje(const Prodaje &p): broj_prodaja(p.broj_prodaja), max_velicina(p.max_velicina){
        niz=new Prodaja*[p.max_velicina];
        for(int i=0; i<p.broj_prodaja; i++) niz[i]= new Prodaja(*(p.niz[i]));
    }
    //pomjerajuci konstruktor
    Prodaje(Prodaje &&p): broj_prodaja(p.broj_prodaja), max_velicina(p.max_velicina), niz(p.niz) {
        for(int i=0; i<p.max_velicina; i++) {
            niz[i]=p.niz[i];
            niz[i]=nullptr;
        }
        p.niz=nullptr;
    
    }    
    //kopirajuci operator dodjele
    Prodaje &operator =(const Prodaje &p){
        Prodaja **nova_alokacija=new Prodaja*[p.max_velicina];
        for(int i=0; i<p.max_velicina; i++) delete niz[i];
        delete [] niz;
        broj_prodaja=p.broj_prodaja; max_velicina=p.max_velicina;
        niz=nova_alokacija;
        for(int i=0; i<max_velicina; i++){
            niz[i]= new Prodaja(*(p.niz[i]));
        }
        return *this;
    }
    
    //pomjerajuci operator dodjele
    Prodaje &operator =(Prodaje &&p){
        if(&p!=this){
            for(int i=0; i<max_velicina; i++) delete niz[i];
            delete [] niz;
            niz=p.niz;
            for(int i=0; i<max_velicina; i++) {
                niz[i]=p.niz[i];
                p.niz[i]=nullptr;
            }
            p.niz=nullptr;
        }
        return *this;
    }
    
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, 
    const Kupac &kupac_stana, const Stan &kupljeni_stan){
        if(broj_prodaja==max_velicina) throw std::range_error ("Dostignut maksimalni broj prodaja");
        niz[broj_prodaja]= new Prodaja(ime_agenta_prodaje,cijena_stana,datum_prodaje, kupac_stana, kupljeni_stan);
        broj_prodaja++;
    }
    
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena, int dan_prodaje, int mjesec_prodaje, 
    int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,
    int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata){
        if(broj_prodaja==max_velicina) throw std::range_error ("Dostignut maksimalni broj prodaja");
        niz[broj_prodaja]= new Prodaja(ime_agenta_prodaje,cijena, dan_prodaje,mjesec_prodaje,godina_prodaje,
                                        ime_kupca,datum_rodjenja_kupca, adresa_stana, sprat_stana, 
                                        broj_soba, namjesten_stan, broj_kvadrata);
        broj_prodaja++;
    }
    
    void RegistrirajProdaju(Prodaja *prodaja){
        if(broj_prodaja==max_velicina) throw std::range_error ("Dostignut maksimalni broj prodaja");
        niz[broj_prodaja]=prodaja;
        broj_prodaja++;
    }
    
    int DajBrojProdaja() const {return broj_prodaja; }
    int DajBrojProdajaNaDatum(const Datum &datum) const {
          int broj=std::count_if(niz, niz+broj_prodaja, [datum] (Prodaja *x){
                 auto dat=(*x).DajDatumProdaje();
                 if( dat.DajDan() == datum.DajDan() && dat.DajMjesec()==datum.DajMjesec() && 
                 dat.DajGodinu()==datum.DajGodinu() ) return true;
                 else return false;
         });
         
         return broj;
       
    }
     
     int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const{
        std::count_if(niz,niz +broj_prodaja, [ime_agenta] (Prodaja *x){
            if( (*x).DajImeAgenta()== ime_agenta ) return true;
              else return false;
        });
    }    
    
    Prodaja &DajNajranijuProdaju() {
        if(broj_prodaja==0) throw std::domain_error ("Nema registriranih prodaja");
        auto min=std::min_element(niz, niz+broj_prodaja, [] (Prodaja *x, Prodaja *y) {
            if( ProdatPrije((*x), (*y)) )return true;
            else return false;
        });
        
        return (*(*min));
    }
    
    Prodaja DajNajranijuProdaju() const {
        if(broj_prodaja==0) throw std::domain_error ("Nema registriranih prodaja");
        auto min=std::min_element(niz, niz+broj_prodaja, [] (Prodaja *x, Prodaja *y) {
            if( ProdatPrije((*x), (*y)) )return true;
            else return false;
        });
        
        return (*(*min));
        
    }
    
    Prodaja &DajNajskupljuProdaju(){
        if(broj_prodaja==0) throw std::domain_error ("Nema registriranih prodaja");
        auto max=std::max_element(niz, niz+broj_prodaja, [] (Prodaja *x, Prodaja *y) {
            if(!( ProdatPrije((*x), (*y))) )return true;
            else return false;
        });
        return (*(*max));
    }
    
    Prodaja DajNajskupljuProdaju() const {
        if(broj_prodaja==0) throw std::domain_error ("Nema registriranih prodaja");
        auto max=std::max_element(niz, niz+broj_prodaja, [] (Prodaja *x, Prodaja *y) {
            if(!( ProdatPrije((*x), (*y))) )return true;
            else return false;
        });
        return (*(*max));
    }
    
    void IsprazniKolekciju() {
        for( int i=0; i<broj_prodaja; i++) {
            delete niz[i];
            niz[i]=nullptr;
             //treba li na null
        }
    }
    
    void ObrisiNajranijuProdaju() {
        if(broj_prodaja==0) throw std::range_error ("Prazna kolekcija");
       auto min=std::min_element(niz, niz+broj_prodaja, [] (Prodaja *x, Prodaja *y) {
            if( ProdatPrije((*x), (*y)) )return true;
            else return false;
        });
        delete min;
        min=nullptr;
    }
    
    void ObrisiProdajeAgenta(const std::string &ime_agenta){
         for(int i=0; i<broj_prodaja; i++){
            if(( (*niz[i]).DajImeAgenta() )==ime_agenta) {
                delete niz[i];
                niz[i]=nullptr;
            }
        }
    }
    
    void ObrisiProdajeNaDatum(const Datum &datum) {
        for(int i=0; i<broj_prodaja; i++){
             auto dat=(*niz[i]).Prodaja::DajDatumProdaje();
            if(dat.DajDan()==datum.DajDan() && dat.DajMjesec()==datum.DajMjesec() && 
            dat.DajGodinu()==datum.DajGodinu()) {
                delete niz[i];
                niz[i]=nullptr;
            }
        }
    }
    Prodaja &DajProdaju(int x){
        return (*niz[x-1]);
    }
    
    /*void IspisiProdajeNaDatum(const Datum &datum) const{
        std::vector<Prodaja> ispisi_ove;
        std::for_each(niz, niz+broj_prodaja, [datum, ispisi_ove] ( Prodaja* x) { 
            Datum dat=(*x).Prodaja::DajDatumProdaje();
            if(dat.DajDan()==datum.DajDan() && dat.DajMjesec()==datum.DajMjesec() && 
               dat.DajGodinu()==datum.DajGodinu())  ispisi_ove.push_back(*x);
        });
        sort(ispisi_ove.begin(), ispisi_ove.end(), [] (Prodaja x, Prodaja y) {
            if((std::strcmp(x.Prodaja::DajImeKupca(), y.Prodaja::DajImeKupca()))==1) return true;
            else return false;
        });
        for(int i=0; i<ispisi_ove.size(); i++){
            ispisi_ove[i].Prodaja::Ispisi();
            std::cout<<std::endl;
        }
            
    }
    
    void IspisiSveProdaje() const {
        std::vector<Prodaja>ispisi_ove;
        std::for_each(niz, niz+broj_prodaja, [ispisi_ove] (Prodaja *x) {
            ispisi_ove.push_back(*x);
        });
        sort(ispisi_ove.begin(), ispisi_ove.end(), [] (Prodaja x, Prodaja y) {
            if(  ProdatPrije(x.Prodaja::DajDatumProdaje(), y.Prodaja::DajDatumProdaje()) ) return true;
            else if( x.Prodaja::DajDatumProdaje()==y.Prodaja::DajDatumProdaje()) {
                if(std::strcmp(x.Prodaja::DajImeKupca(), y.Prodaja::DajImeKupca())) return true;
            }
            else return false;
        });
        
        for(int i=0; i<broj_prodaja; i++){
            (*niz[i]).Prodaja::Ispisi();
            std::cout<<std::endl;
        }
    }*/
    
};

    
int main() {
    std::cout<<"Dobrodosli!"<<std::endl;
    std::vector<Stan> stanovi;
    for(;;){
        int opcija;
        std::cout<<std::endl<<"Izaberite opciju:"<<std::endl<<"0 - kraj"<<std::endl<<"1 - uredjivanje stanova"<<
        std::endl<<"2 - uredjivanje kupaca"<<std::endl<<"3 - uredjivanje prodaja"<<std::endl;
        std::cin>>opcija;
        if(opcija==1){
            for(;;){
                int stanopcija
                std::cout<<"Izaberite opciju:\n0 - nazad \n1 - dodavanje stana\n2 - uredjivanje stanova\n3 - ispis svih stanova\n4 - kraj";
                std::cin>>stanopcija;
                if(stanopcija==1){
                    
                    bool dobarunos(0);
                    while(!dobarunos){
                        std::string adresa;
                        int sprat; brojsoba;
                        bool namj;
                        double kvadrat;
                        std::cout<<"Unesite adresu: ";
                        std::cin>>adresa;
                        std::cout<<std::endl<<"Unesite sprat: ";
                        std::cin>>sprat;
                        std::cout<<std::endl<<"Unesite broj soba: ";
                        std::cin>>brojsoba;
                        std::cout<<std::endl<<"Da li je stan namjesten (1 - da, 0 - ne): "
                        if(!std::cin>>namj){
                            std::cout<<"Izuzetak: Neispravan unos podataka. Molimo unesite opet.";
                            continue;
                        } 
                        std::cout<<std::endl<<"Unesite kvadraturu: ";
                        std::cin>>kvadrat;
                        try {
                            stanovi.push_back(Stan(adresa,sprat,brojsoba,namj,kvadrat));
                            dobarnos=1;
                        }catch(std::domain_error Izuzetak){
                            std::cout<<Izuzetak.what()<<std::endl;
                        }
                        if(dobarunos) std::cout<<"Stan je uspjesno dodan!";
                }
                if(stanopcija==2){
                    int i;
                     bool izmjena(0);
                    std::cout<<"Odaberite stan. Dostupni stanovi su: ";
                    for(int j=0; j<stanovi.size(); j++){
                        std::cout<<j+1<<" ";  stanovi[j].Stan::Ispisi(); std::cout<<std::endl;
                    }
                    std::cin<<i;
                    for(;;){
                        if(izmjena) break;
                        int polje;
                        std::cout<<"Odaberite polje koje zelite urediti:\n0 - nazad\n1 - adresa\n2 - sprat\n3 - broj soba\n4 - da li je stan namjesten\n";
                        std::cout<<" 5 - kvadratura\n6 - sve\n";
                        std::cin>>polje;
                        if(polje==0) break;
                        if(polje==1){
                            std::string adr;
                            std::cout<<"Unesite adresu: ";
                            while(!std::cin>>adr) {
                                std::cout<<"Izuzetak: Neispravan unos podataka. Molimo unesite opet."<<std::endl;
                                std::cout<<"Unesite adresu: ";
                            }
                            stanovi[i-1].DajAdresu()=adr;
                            std::cout<<"Stan je uspjesno izmijenjen"
                            izmjena=1;
                        }
                        if(polje==2){
                            int spr;
                            std::cout<<"Unesite sprat: ";
                            while( !std::cin>>spr){
                                std::cout<<"Izuzetak: Neispravan unos podataka. Molimo unesite opet."<<std::endl;
                                std::cout<<"Unesite spat: ";
                            }
                            stanovi[i-1].DajSprat()=spr;
                            std::cout<<"Stan je uspjesno izmijenjen";
                            izmjena=1;
                        }
                        if(polje==3){
                            int br;
                            std::cout<<"Unesite broj soba: ";
                            while( !std::cin>>br){
                                std::cout<<"Izuzetak: Neispravan unos podataka. Molimo unesite opet."<<std::endl;
                                std::cout<<"Unesite broj soba: ";
                            }
                            stanovi[i-1].DajBrojSoba()=br;
                            std::cout<<"Stan je uspjesno izmijenjen";
                            izmjena=1;
                        }
                        if(polje==4){
                            bool na;
                            std::cout<<"Da li je stan namjesten: ";
                            while( !std::cin>>na){
                                std::cout<<"Izuzetak: Neispravan unos podataka. Molimo unesite opet."<<std::endl;
                                std::cout<<"Da li je stan namjesten: ";
                            }
                            stanovi[i-1].DajNamjesten()=na;
                            std::cout<<"Stan je uspjesno izmijenjen";
                            izmjena=1;
                        }
                        if(polje==5){
                            double kv;
                            std::cout<<"Unesite kvadraturu: ";
                            while( !std::cin>>kv){
                                std::cout<<"Izuzetak: Neispravan unos podataka. Molimo unesite opet."<<std::endl;
                                std::cout<<"Unesite kvadraturu: ";
                            }
                            stanovi[i-1].DajKvadraturu()=kv;
                            stanovi[i-1]
                            std::cout<<"Stan je uspjesno izmijenjen";
                            izmjena=1;
                        }
                        if(polje==6){
                            
                        }
                        }
                    
 
                    
                    
                    
                    
                }
    
    
        return 0;
    }
        
