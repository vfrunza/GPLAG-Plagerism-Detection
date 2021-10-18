#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <algorithm>
#include <initializer_list>
#include <cstring>
#include <vector>
int BrojDana(int mjesec,int godina){
    int broj_dana[]{31,28,31,30,31,30,31,31,30,31,30,31};
     if(godina % 4 == 0 && godina%100!=0 || godina%400==0)broj_dana[1]++;
     return broj_dana[mjesec-1];
}
class Datum{
    int dan,mjesec,godina;
    public:
    Datum(int dan,int mjesec,int godina){
        Postavi(dan,mjesec,godina);
    }
    void Postavi(int dan,int mjesec,int godina){
        if(godina < 1 || mjesec < 1 || mjesec > 12 || dan < 1 ||dan > BrojDana(mjesec,godina))
            throw std::domain_error("Neispravan datum");
        Datum::dan=dan;Datum::mjesec=mjesec;Datum::godina=godina;
    }
    int DajDan() const{return dan;}
    int DajMjesec() const{return mjesec;}
    int DajGodinu() const{return godina;}
    void Ispisi() const{std::cout << dan << "/" << mjesec << "/" << godina;}
};
class Kupac{
    std::string ime_i_prezime;
    Datum datum_rodjenja;
  public:  
  Kupac(const std::string &ime_i_prezime,const Datum &datum_rodjenja):datum_rodjenja(datum_rodjenja){
      for(int i(0);i < ime_i_prezime.length();i++){
          if(!(ime_i_prezime[i] >= 'a' && ime_i_prezime[i] <= 'z' || ime_i_prezime[i] >= 'A' && ime_i_prezime[i] <= 'Z'
           || ime_i_prezime[i] >= '0' && ime_i_prezime[i] <= '9' ||ime_i_prezime[i] == ' '
           || ime_i_prezime[i] == '-' || ime_i_prezime[i] == '"'))
            throw std::domain_error("Neispravno prezime");}
            Kupac::ime_i_prezime=ime_i_prezime;
    }
    void Postavi(const std::string &ime_i_prezime,const Datum &datum_rodjenja){
         for(int i(0);i < ime_i_prezime.length();i++){
          if(!(ime_i_prezime[i] >= 'a' && ime_i_prezime[i] <= 'z' || ime_i_prezime[i] >= 'A' && ime_i_prezime[i] <= 'Z'
           || ime_i_prezime[i] >= '0' && ime_i_prezime[i] <= '9' ||ime_i_prezime[i] == ' '
           || ime_i_prezime[i] == '-' || ime_i_prezime[i] == '"'))
            throw std::domain_error("Neispravno prezime");}
            Kupac::datum_rodjenja=datum_rodjenja;
            Kupac::ime_i_prezime=ime_i_prezime;   
    }
    std::string DajImePrezime() const{
        return ime_i_prezime;
    }
    Datum DajDatumRodjenja() const{return datum_rodjenja;}
    void Ispisi() const{std::cout << ime_i_prezime << "(";datum_rodjenja.Ispisi();std::cout << ")";}
};
class Stan{
    std::string adresa;
    int sprat,broj_soba;
    bool namjesten;
    double kvadratura;
  public:  
  Stan(const std::string &adresa,int sprat,int broj_soba,bool namjesten,double kvadratura){Postavi(adresa,sprat,broj_soba,namjesten,kvadratura);}
  void Postavi(const std::string &adresa,int sprat,int broj_soba,bool namjesten,double kvadratura){
      if(kvadratura < 0 ||broj_soba < 0 ||sprat < 0)throw std::domain_error("Neispravan unos podataka");
      Stan::adresa=adresa;Stan::sprat=sprat;Stan::broj_soba=broj_soba;Stan::namjesten=namjesten;Stan::kvadratura=kvadratura;
  }
  std::string DajAdresu() const{return adresa;}
  int DajSprat() const{return sprat;}
  int DajBrojSoba() const{return DajBrojSoba();}
  bool DajNamjesten() const{return namjesten;}
  double DajKvadraturu() const{return kvadratura;}
  void Ispisi() const;
};
void Stan::Ispisi() const{
    std::cout << "Stan se nalazi na adresi " << adresa << " na " << sprat << ".spratu i ima ";
    if(broj_soba % 10 == 1 && (broj_soba%100)/10 != 1)std::cout << broj_soba << " sobu.";
    else if((broj_soba % 10 == 2 || broj_soba % 10 == 3 ||broj_soba % 10 == 4) && (broj_soba%100)/10 != 1)std::cout << broj_soba << " sobe.";
    else std::cout << broj_soba << " soba.";
    std::cout << "\nKvadratura stana je " << kvadratura << " (m^2) i stan ";
    if(!namjesten)std::cout << "ni";
    std::cout << "je namjesten.";
}
class Prodaja{
    std::string ime_agenta_prodaje;
    double cijena_stana;
    Datum datum_prodaje;
    Kupac kupac_stana;
    Stan kupljeni_stan;
    public:
    Prodaja(const std::string &ime_agenta_prodaje,double cijena_stana,const Datum &datum_prodaje,const Kupac &kupac_stana,
    const Stan &kupljeni_stan):datum_prodaje(datum_prodaje),kupac_stana(kupac_stana),kupljeni_stan(kupljeni_stan){
        Prodaja::ime_agenta_prodaje=ime_agenta_prodaje;Prodaja::cijena_stana=cijena_stana;
    }
    Prodaja(const std::string &ime_agenta_prodaje,double cijena_stana,int dan_prodaje,int mjesec_prodaje,
    int godina_prodaje,const std::string &ime_kupca,const Datum &datum_rodjenja_kupca,const std::string &adresa_stana,
    int sprat_stana,int broj_soba,bool namjesten_stan,double broj_kvadrata):
    kupljeni_stan(adresa_stana,broj_soba,sprat_stana,namjesten_stan,broj_kvadrata),datum_prodaje(dan_prodaje,mjesec_prodaje,godina_prodaje),
    kupac_stana(ime_kupca,datum_rodjenja_kupca){
        Prodaja::ime_agenta_prodaje=ime_agenta_prodaje;Prodaja::cijena_stana=cijena_stana;
    }
    void PromijeniKupca(const Kupac &novi_kupac){
        kupac_stana=novi_kupac;
    }
    void PromijeniStan(const Stan &novi_stan){
        kupljeni_stan=novi_stan;    
    }
    void PromijeniDatumKupovine(const Datum &novi_datum){
        datum_prodaje=novi_datum;
    }
    void PromijeniCijenuProdaje(const double &nova_cijena){
        cijena_stana=nova_cijena;
    }
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImeAgenta() const{return ime_agenta_prodaje;}
    std::string DajImeKupca() const{return kupac_stana.DajImePrezime();}
    Datum DajDatumProdaje() const{return datum_prodaje;}
    double DajCijenuStana() const{return cijena_stana;}
    friend bool ProdatPrije(const Prodaja &p1,const Prodaja &p2);
    void Ispisi() const;
};
void Prodaja::PomjeriDanUnaprijed(){
    int d(datum_prodaje.DajDan()),m(datum_prodaje.DajMjesec()),g(datum_prodaje.DajGodinu());
    d++;
    if(d > BrojDana(m,d))d=1,m++;
    if(m>12)m=1,g++;
    datum_prodaje={d,m,g};
}
void Prodaja::PomjeriDanUnazad(){
    int d(datum_prodaje.DajDan()),m(datum_prodaje.DajMjesec()),g(datum_prodaje.DajGodinu());
    d--;
    if(d < 1){;m--;d=BrojDana(m,g);}
    if(m < 1){m=12;g--;d=31;}
    
    datum_prodaje={d,m,g};
}
bool ProdatPrije(const Prodaja &p1,const Prodaja &p2){
    if(p1.datum_prodaje.DajGodinu() < p2.datum_prodaje.DajGodinu())return true;
    else if(p1.datum_prodaje.DajGodinu() == p2.datum_prodaje.DajGodinu()){
        if(p1.datum_prodaje.DajMjesec() < p2.datum_prodaje.DajMjesec())return true;
        else if(p1.datum_prodaje.DajMjesec() == p2.datum_prodaje.DajMjesec()){
            return p1.datum_prodaje.DajDan() < p2.datum_prodaje.DajDan();
        }else return false;
    }else return false;
}
void Prodaja::Ispisi() const{
    std::cout << "Ime agenta:" << ime_agenta_prodaje;
    std::cout << "\nIme kupca:"; kupac_stana.Ispisi();
    std::cout << "\nZakazani datum prodaje: "; datum_prodaje.Ispisi();
    std::cout << "\nCijena stana: " << cijena_stana;
    std::cout << "\nInformacije o stanu:\n";
    kupljeni_stan.Ispisi();
}
class Prodaje{
    Prodaja **spisak_prodaja = nullptr;
    int max_broj_prodaja,broj_prodaja;
    static bool PorediDatume(Prodaja *x,Prodaja *y){
    int d1(x->DajDatumProdaje().DajDan()),m1(x->DajDatumProdaje().DajMjesec()),g1(x->DajDatumProdaje().DajGodinu());
        int d2(y->DajDatumProdaje().DajDan()),m2(y->DajDatumProdaje().DajMjesec()),g2(y->DajDatumProdaje().DajGodinu());
        if(g1 < g2)return true;
        else if(g1 == g2){
            if(m1 < m2)return true;
            else if(m1 == m2){
                return d1 < d2;
            }else return false;
        }
        else return false;
}
    public:
    explicit Prodaje(int max_broj_prodaja):spisak_prodaja(new Prodaja*[max_broj_prodaja]{}),
    broj_prodaja(0),max_broj_prodaja(max_broj_prodaja){}
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
    ~Prodaje();
    Prodaje(const Prodaje &prodaje);
    Prodaje(Prodaje &&prodaje);
    Prodaje &operator =(const Prodaje &prodaje);
    Prodaje &operator =(Prodaje &&prodaje);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana,const Datum &datum_prodaje,
    const Kupac &kupac_stana,const Stan &kupljeni_stan);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana,int dan_prodaje,
    int mjesec_prodaje,int godina_prodaje,std::string &ime_kupca,const Datum &datum_rodjenja_kupca,
    const std::string &adresa_stana,int sprat_stana,int broj_soba,bool namjesten_stan,double broj_kvadrata);
    void RegistrirajProdaju(Prodaja *prodaja);
    int DajBrojProdaja() const{return broj_prodaja;}
    int DajBrojProdajaNaDatum(const Datum &datum);
    Prodaja &DajNajranijuProdaju();
    Prodaja DajNajranijuProdaju() const;
    Prodaja &DajNajskupljuProdaju();
    Prodaja DajNajskupljuProdaju() const;
    void IsprazniKolekciju();
    void ObrisiNajranijuPonudu();
    void ObrisiProdajeAgenta(const std::string &ime_agenta);
    void ObrisiProdajeNaDatum(const Datum &datum);
    void IspisiSveProdaje() const;
    void IspisiProdajeNaDatum(const Datum &datum) const;
    
};
Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja):max_broj_prodaja(spisak_prodaja.size()),
broj_prodaja(spisak_prodaja.size()),spisak_prodaja(new Prodaja*[spisak_prodaja.size()]{}){
    auto it(spisak_prodaja.begin());
    try{
        for(int i(0);i < spisak_prodaja.size();i++)Prodaje::spisak_prodaja[i]=new Prodaja(*it++);
    }catch(...){
        for(int i(0);i < spisak_prodaja.size();i++)delete Prodaje::spisak_prodaja[i];
        delete[] Prodaje::spisak_prodaja;throw;
    }
}
Prodaje::~Prodaje(){
    for(int i(0);i < broj_prodaja;i++)delete spisak_prodaja[i];
    delete[] spisak_prodaja;
}
Prodaje::Prodaje(const Prodaje &prodaje):spisak_prodaja(new Prodaja*[prodaje.broj_prodaja]{}),
max_broj_prodaja(prodaje.max_broj_prodaja),broj_prodaja(prodaje.broj_prodaja){
    try{
        for(int i(0);i < broj_prodaja;i++)spisak_prodaja[i]=new Prodaja(*prodaje.spisak_prodaja[i]);
    }catch(...){
        for(int i(0);i < broj_prodaja;i++)delete spisak_prodaja[i];
        delete spisak_prodaja;throw;
    }
}
Prodaje::Prodaje(Prodaje &&prodaje):spisak_prodaja(prodaje.spisak_prodaja){
    max_broj_prodaja=prodaje.max_broj_prodaja;
    broj_prodaja=prodaje.broj_prodaja;
    prodaje.spisak_prodaja=nullptr;
    prodaje.broj_prodaja=0;
}
Prodaje &Prodaje::operator =(const Prodaje &prodaje){
    if(this != &prodaje){
        Prodaja **tmp(new Prodaja*[prodaje.broj_prodaja]{});
        try{
            for(int i(0);i < prodaje.broj_prodaja;i++)tmp[i]=new Prodaja(*prodaje.spisak_prodaja[i]);
            for(int i(0);i < broj_prodaja;i++)delete spisak_prodaja[i];
            delete[] spisak_prodaja;
            broj_prodaja=prodaje.broj_prodaja;
            max_broj_prodaja=prodaje.max_broj_prodaja;
            spisak_prodaja=tmp;
        }catch(...){
            for(int i(0);i < prodaje.broj_prodaja;i++)delete tmp[i];
            delete[] tmp;throw;
        }
    }
    return *this;
}
Prodaje &Prodaje::operator =(Prodaje &&prodaje){
    std::swap(spisak_prodaja,prodaje.spisak_prodaja);
    std::swap(broj_prodaja,prodaje.broj_prodaja);
    std::swap(max_broj_prodaja,prodaje.max_broj_prodaja);
    return *this;
}
void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana,const Datum &datum_prodaje,
const Kupac &kupac_stana,const Stan &kupljeni_stan){
    if(broj_prodaja == max_broj_prodaja)throw std::range_error("Dostignut maksimalni broj prodaja");
    spisak_prodaja[broj_prodaja++]=new Prodaja(ime_agenta_prodaje,cijena_stana,datum_prodaje,kupac_stana,kupljeni_stan);
}
void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana,int dan_prodaje,
    int mjesec_prodaje,int godina_prodaje,std::string &ime_kupca,const Datum &datum_rodjenja_kupca,
    const std::string &adresa_stana,int sprat_stana,int broj_soba,bool namjesten_stan,double broj_kvadrata){
        if(broj_prodaja==max_broj_prodaja)throw std::range_error("Dostignut maksimalni broj prodaja");
        Datum datum_prodaje(dan_prodaje,mjesec_prodaje,godina_prodaje);
        Kupac kupac_stana(ime_kupca,datum_rodjenja_kupca);
        Stan kupljeni_stan(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata);
        RegistrirajProdaju(ime_agenta_prodaje,cijena_stana,datum_prodaje,kupac_stana,kupljeni_stan);
    }
void Prodaje::RegistrirajProdaju(Prodaja *prodaja){
    if(broj_prodaja==max_broj_prodaja)throw std::range_error("Dostignut maksimalni broj prodaja");
    spisak_prodaja[broj_prodaja++]=prodaja;
}
int Prodaje::DajBrojProdajaNaDatum(const Datum &datum){
    int d(datum.DajDan()),m(datum.DajMjesec()),g(datum.DajGodinu());
    return std::count_if(spisak_prodaja,spisak_prodaja+broj_prodaja,[d,m,g](Prodaja *prodaja){
        int d1(prodaja->DajDatumProdaje().DajDan()),m1(prodaja->DajDatumProdaje().DajMjesec()),g1(prodaja->DajDatumProdaje().DajGodinu());
        return d == d1 && m == m1 && g == g1;
    });
}
Prodaja &Prodaje::DajNajranijuProdaju(){
    if(broj_prodaja == 0)throw std::domain_error("Nema registriranih prodaja");
    return **std::min_element(spisak_prodaja,spisak_prodaja+broj_prodaja,PorediDatume);
}
Prodaja Prodaje::DajNajranijuProdaju() const{
    if(broj_prodaja == 0)throw std::domain_error("Nema registriranih prodaja");
     return **std::min_element(spisak_prodaja,spisak_prodaja+broj_prodaja,[](Prodaja *x,Prodaja *y){
        int d1(x->DajDatumProdaje().DajDan()),m1(x->DajDatumProdaje().DajMjesec()),g1(x->DajDatumProdaje().DajGodinu());
        int d2(y->DajDatumProdaje().DajDan()),m2(y->DajDatumProdaje().DajMjesec()),g2(y->DajDatumProdaje().DajGodinu());
        if(g1 < g2)return true;
        else if(g1 == g2){
            if(m1 < m2)return true;
            else if(m1 == m2){
                return d1 < d2;
            }else return false;
        }
        else return false;
    });
}
Prodaja &Prodaje::DajNajskupljuProdaju(){
    if(broj_prodaja == 0)throw std::domain_error("Nema registriranih prodaja");
    return **std::max_element(spisak_prodaja,spisak_prodaja+broj_prodaja,[](Prodaja *x,Prodaja *y){
        return x->DajCijenuStana() < y->DajCijenuStana();
        
    });
}
Prodaja Prodaje::DajNajskupljuProdaju() const{
    if(broj_prodaja == 0)throw std::domain_error("Nema registriranih prodaja");
    return **std::max_element(spisak_prodaja,spisak_prodaja+broj_prodaja,[](Prodaja *x,Prodaja *y){
        return x->DajCijenuStana() < y->DajCijenuStana();
        
    });
}
void Prodaje::IsprazniKolekciju(){
    for(int i(0);i < broj_prodaja;i++)delete spisak_prodaja[i];
    delete[] spisak_prodaja;
    spisak_prodaja=nullptr;
    broj_prodaja=0;
    max_broj_prodaja=0;
}
void Prodaje::ObrisiNajranijuPonudu(){
    if(broj_prodaja==0)throw std::range_error("Prazna kolekcija");
    try{
        auto pok(&(this -> DajNajranijuProdaju()));
        for(int i(0);i < broj_prodaja;i++){
            if(spisak_prodaja[i] == pok){
                delete spisak_prodaja[i];
                while(i < broj_prodaja-1){spisak_prodaja[i]=spisak_prodaja[i+1];i++;}
                spisak_prodaja[broj_prodaja-1]=nullptr;
                broj_prodaja--;
                break;
            }
        }
    }catch(...){
        return;
    }
}
void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta){
    for(int i(0);i < broj_prodaja;i++){
        if(ime_agenta == spisak_prodaja[i]->DajImeAgenta()){
            delete spisak_prodaja[i];
            for(int j(i);j < broj_prodaja-1;j++){
                spisak_prodaja[j]=spisak_prodaja[j+1];
            }
            spisak_prodaja[broj_prodaja-1]=nullptr;
            broj_prodaja--;
            i--;
        }
    }
}
void Prodaje::ObrisiProdajeNaDatum(const Datum &datum){
    int d(datum.DajDan()),m(datum.DajMjesec()),g(datum.DajGodinu());
     for(int i(0);i < broj_prodaja;i++){
         auto tmp(spisak_prodaja[i]->DajDatumProdaje());
        if(d == tmp.DajDan() && m == tmp.DajMjesec() && g == tmp.DajGodinu()){
            delete spisak_prodaja[i];
            for(int j(i);j < broj_prodaja-1;j++){
                spisak_prodaja[j]=spisak_prodaja[j+1];
            }
            spisak_prodaja[broj_prodaja-1]=nullptr;
            broj_prodaja--;
            i--;
        }
    }
}
void Prodaje::IspisiSveProdaje() const{
    Prodaja **tmp;
    tmp=new Prodaja*[broj_prodaja];
    for(int i(0);i < broj_prodaja;i++)tmp[i]=spisak_prodaja[i];
    std::sort(tmp,tmp+broj_prodaja,[](Prodaja *x,Prodaja *y){
        int d1(x->DajDatumProdaje().DajDan()),m1(x->DajDatumProdaje().DajMjesec()),g1(x->DajDatumProdaje().DajGodinu());
        int d2(y->DajDatumProdaje().DajDan()),m2(y->DajDatumProdaje().DajMjesec()),g2(y->DajDatumProdaje().DajGodinu());
        if(g1 < g2)return true;
        else if(g1 == g2){
            if(m1 < m2)return true;
            else if(m1 == m2){
                if(d1<d2)return true;
                else if(d1==d2){
                    return x->DajImeKupca()<y->DajImeKupca();
                }
                else return false;
            }else return false;
        }
        else return false;
    });
    for(int i(0);i < broj_prodaja;i++){tmp[i]->Ispisi();std::cout << std::endl;}
    delete[] tmp;
}
void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const{
    for(int i(0);i < broj_prodaja;i++){
        auto dat(spisak_prodaja[i]->DajDatumProdaje());
        if(dat.DajDan() == datum.DajDan() && dat.DajMjesec() == datum.DajMjesec() && dat.DajGodinu() == datum.DajGodinu()){
            spisak_prodaja[i]->Ispisi();
        }
    }
}
int main ()
{
  /*  std::vector<Stan> stanovi;
   std::cout << "Dobrodosli!\n";
   for(;;){
       int n;
       std::cout << "\nIzaberite opciju:\n";
       std::cout << "0 - kraj\n" << "1 - uredjivanje stanova\n" << "2 - uredjivanje kupaca\n" << "3 - uredjivanje prodaja\n";
       std::cin >> n;
       switch(n){
           case 0:
           break;
           case 1:
                unos:std::cout << "\nIzaberite opciju:\n" << "0 - nazad\n" << "1 - dodavanje stana\n" << "2 - uredjivanje stanova\n" <<
                "3 - ispis svih stanova\n" << "4 - kraj\n";
                std::cin >> n;
                switch(n){
                    case 0:
                    break;
                    case 1:
                        greska: {std::string adresa;
                        int sprat,broj_soba;
                        double kvad;
                        int namjesten;
                        std::cin.ignore(10000,'\n');
                        std::cout << "Unesite adresu:";
                        std::getline(std::cin,adresa);
                        std::cout << "Unesite sprat:";
                        std::cin >> sprat;
                        std::cout << "Unesite broj soba:";
                        std::cin >> broj_soba;
                        std::cout << "Da li je stan namjesten (1 - da, 0 - ne):";
                        std::cin >> namjesten;
                        std::cout << "Unesite kvadraturu:";
                        std::cin >> kvad;
                        if(namjesten !=0 && namjesten != 1){std::cout << "Izuzetak: Neispravan unos podataka.Molimo unesite opet.\n";goto greska;}
                        try{
                            stanovi.push_back({adresa,sprat,broj_soba,(bool)namjesten,kvad});
                            std::cout << "Stan je uspjesno dodan!\n";
                            goto unos;
                        }catch(std::domain_error izuzetak){
                            std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet.\n";
                            goto unos;
                        }}
                    break;
                    case 3:
                        for(int i(0);i < stanovi.size();i++){
                            std::cout << i+1 << ". ";
                            stanovi[i].Ispisi();
                            std::cout << std::endl;
                        }
                        goto unos;
                    break;
                    case 4:
                    break;
                }     
           break;
           case 2:
                std::cout << "Odaberite stan: Dostupni stanovi su:\n";
                for(int i(0);i < stanovi.size();i++){
                            std::cout << i+1 << " - ";
                            stanovi[i].Ispisi();
                            std::cout << std::endl;
                        }
                std::cin >> n;
                switch(n){
                    case 0:
                        goto unos;
                    break;
                    case 1:
                    break;
                    case 2:
                    break;
                    case 3:
                    break;
                    case 4:
                    break;
                    case 5:
                    break;
                    case 6:
                    break;
                
                }
           break;
           case 3:
           break;
           default:
           break;
       }
       
   }
   
 */
	return 0;
}