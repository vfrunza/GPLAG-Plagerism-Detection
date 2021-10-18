/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <string>
#include <algorithm>
#include <vector>
#include <ctype.h>

class Datum{
    int dan, mjesec, godina;
    public:
    Datum(int dan, int mjesec, int godina) { Postavi(dan, mjesec, godina); }
    void Postavi(int dan, int mjesec, int godina);
    int DajDan() const { return dan; }
    int DajMjesec() const { return mjesec; }
    int DajGodinu() const { return godina; }
    void Ispisi() const { std::cout << dan << "/" << mjesec <<"/" << godina; }
};
    void Datum::Postavi(int dan, int mjesec, int godina) {
            if(dan < 0 || dan > 31) throw std::domain_error("Neispravan datum");
            if(mjesec < 0 || mjesec > 12) throw std::domain_error("Neispravan datum");
            
            if((mjesec == 4 || mjesec == 6 || mjesec== 9 || mjesec==11) && (dan >= 31))  throw std::domain_error("Neispravan datum");
            
            if(mjesec==2){
                if(godina%4==0 && godina%400==0 && godina%100!=0){
                    if(dan>29) throw std::domain_error("Neispravan datum");
                }
                else{
                    if(dan > 28) throw std::domain_error("Neispravan datum");
                }
            }
            
            this->dan=dan;
            this->mjesec=mjesec;
            this->godina=godina;
        }
        
class Kupac{
    std::string ime_prezime;
    Datum datum;
    public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja) : datum(datum_rodjenja.DajDan(),datum_rodjenja.DajMjesec(), datum_rodjenja.DajGodinu()){
        for (unsigned i=0; i<ime_i_prezime.length(); i++){
            if((ime_i_prezime.at(i) != '-') && (ime_i_prezime.at(i) != '\'') && (!isspace(ime_i_prezime.at(i))) && (!isalnum(ime_i_prezime.at(i))) && (!isdigit(ime_i_prezime.at(i))))
                throw std::domain_error("Neispravno ime i prezime");
        }
        ime_prezime=ime_i_prezime;
    }
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja){
        ime_prezime=ime_i_prezime;
        datum=datum_rodjenja;
    }
    std::string DajImePrezime() const { return ime_prezime; }
    Datum DajDatumRodjenja() const { return datum; }
    void Ispisi() const { std::cout << ime_prezime << " (";
    datum.Ispisi(); 
    std::cout << ")" << std::endl; }
    
};

class Stan{
    std::string adresa;
    int sprat, broj_soba;
    bool namjesten;
    double kvadratura;
    
    public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) { Postavi(adresa, sprat, broj_soba, namjesten, kvadratura); }
    
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
    std::string DajAdresu() const { return adresa; }
    int DajSprat() const { return sprat; }
    int DajBrojSoba() const { return broj_soba; }
    bool DajNamjesten() const { return namjesten; }
    double DajKvadraturu() const { return kvadratura; }
    void Ispisi() const;
};

    void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
        if(sprat < 0) throw std::domain_error("Neispravan unos podataka");
        if(broj_soba < 0) throw std::domain_error("Neispravan unos podataka");
        if(kvadratura < 0) throw std::domain_error("Neispravan unos podataka");
        
        this->adresa=adresa;
        this->sprat=sprat;
        this->broj_soba=broj_soba;
        this->namjesten=namjesten;
        this->kvadratura=kvadratura;
    }
    
    void Stan::Ispisi() const{
        std::cout << "Stan se nalazi na adresi " << adresa << " na " << sprat << ". spratu i ima " << broj_soba;
        if(broj_soba == 1) std::cout << " sobu. ";
        else if (broj_soba==2 || broj_soba==3 || broj_soba==4) std::cout << " sobe. ";
        else std::cout << " soba. ";
        std::cout << "Kvadratura stana je " << kvadratura << " (m^2) i stan ";
        if(namjesten) std::cout << "je namjesten.";
        else std::cout << "nije namjesten.";
        
    }

class Prodaja{
    std::string ime_agenta;
    double cijena_stana;
    Datum dat_prodaje;
    Kupac kupac;
    Stan stan;
    
    public:
    
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan) :
            dat_prodaje(datum_prodaje.DajDan(), datum_prodaje.DajMjesec(), datum_prodaje.DajGodinu()), 
            kupac(kupac_stana.DajImePrezime(), kupac_stana.DajDatumRodjenja()),
            stan(kupljeni_stan.DajAdresu(), kupljeni_stan.DajSprat(), kupljeni_stan.DajBrojSoba(), kupljeni_stan.DajNamjesten(), kupljeni_stan.DajKvadraturu()){
                ime_agenta=ime_agenta_prodaje;
                this->cijena_stana=cijena_stana;
            }
    
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, 
            const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) :
            dat_prodaje(dan_prodaje, mjesec_prodaje, godina_prodaje), kupac(ime_kupca, datum_rodjenja_kupca),
            stan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata){
                ime_agenta = ime_agenta_prodaje;
                this->cijena_stana=cijena_stana;
            }
    
    void PromijeniKupca(const Kupac &novi_kupac) { kupac.Postavi(novi_kupac.DajImePrezime(), novi_kupac.DajDatumRodjenja()); }
    void PromijeniStan(const Stan &novi_stan) { stan.Postavi(novi_stan.DajAdresu(), novi_stan.DajSprat(), novi_stan.DajBrojSoba(), novi_stan.DajNamjesten(), novi_stan.DajKvadraturu()); }
    void PromijeniDatumKupovina(const Datum &novi_datum) { dat_prodaje.Postavi(novi_datum.DajDan(),novi_datum.DajMjesec(),novi_datum.DajGodinu()); }
    void PromijeniCijenuProdaje(const double &nova_cijena) { cijena_stana=nova_cijena; }
    
    //pomjera datum prodaje za 1 dan unaprijed
    void PomjeriDanUnaprijed();
    
    //pomjera datum prodaje za 1 dan unazad
    void PomjeriDanUnazad();
    
    std::string DajImeAgenta() const { return ime_agenta; }
    std::string DajImeKupca() const { return kupac.DajImePrezime(); }
    Datum DajDatumProdaje() const { return dat_prodaje; }
    double DajCijenuStana() const { return cijena_stana; }
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
    
    void Ispisi() const;
};

    void Prodaja::PomjeriDanUnaprijed(){
        int dan=dat_prodaje.DajDan();
        int mjesec=dat_prodaje.DajMjesec();
        int godina=dat_prodaje.DajGodinu(); 
        //granicni slucajevi: kraj mjeseca, kraj godine
        if(dan==31 && mjesec==12){
            dat_prodaje.Postavi(1, 1, godina+1);
            return;
        }
        if(((mjesec==4 || mjesec==6 || mjesec==9 || mjesec==11)&&(dan==30)) || ((mjesec==1|| mjesec==3 || mjesec==5 || mjesec==7 || mjesec==8 || mjesec==10)&&(dan==31))){
            dat_prodaje.Postavi(1, dat_prodaje.DajMjesec()+1, dat_prodaje.DajGodinu());
            return;
        }
        if(mjesec==2){
            if(godina%4==0 && godina%100!=0 && godina%400==0){
                if(dan==29) dat_prodaje.Postavi(1, 3, godina);
            }
            else{
                if(dan==28) dat_prodaje.Postavi(1, 3, godina);
            }
            return;
        }
        
        dat_prodaje.Postavi(dan+1, mjesec, godina);
    }
    
    void Prodaja::PomjeriDanUnazad(){
        //granicni slucajevi: pocetak godine, pocetak mjeseca
        int dan=dat_prodaje.DajDan();
        int mjesec=dat_prodaje.DajMjesec();
        int godina=dat_prodaje.DajGodinu();   
        
        if(dan==1 && mjesec==1){
            dat_prodaje.Postavi(31,12,godina-1);
            return;
        }
        if(mjesec==5 || mjesec==7 || mjesec==10 || mjesec==12){
            if(dan==1){
                dat_prodaje.Postavi(30, mjesec-1, godina);
            }
            return;
        }
        if(mjesec==2 || mjesec==4 || mjesec==6|| mjesec==8 || mjesec==9 || mjesec==11){
            if(dan==1){
                dat_prodaje.Postavi(31,mjesec-1, godina);
            }
            return;
        }
        if(dan==1 && mjesec==3){
            if(godina%4==0 && godina%400==0 && godina%100!=0) dat_prodaje.Postavi(29,2,godina);
            else dat_prodaje.Postavi(28,2,godina);
            return;
        }
        
        dat_prodaje.Postavi(dan-1, mjesec, godina);
    }
    
    void Prodaja::Ispisi() const{
        std::cout << "Ime agenta: "; std::cout.width(29); std::cout << std::right << ime_agenta << std::endl;
        std::cout << "Ime kupca: "; std::cout.width(30); std::cout << std::right; kupac.Ispisi(); 
        std::cout << "Zakazani datum prodaje: "; std::cout.width(8); std::cout << std::right; dat_prodaje.Ispisi(); std::cout << std::endl;
        std::cout << "Cijena stana: "; std::cout.width(22); std::cout << std::right << cijena_stana << std::endl;
        std::cout << "Informacije o stanu:" << std::endl;
        stan.Ispisi();
        std::cout << std::endl;
        std::cout << std::endl;
    }

    bool ProdatPrije(const Prodaja &p1, const Prodaja &p2){
        Datum d1=p1.DajDatumProdaje();
        Datum d2=p2.DajDatumProdaje();
        if(d1.DajGodinu() < d2.DajGodinu()) return true;
        if(d1.DajGodinu() == d2.DajGodinu() && d1.DajMjesec() < d2.DajMjesec()) return true;
        if(d1.DajGodinu() == d2.DajGodinu() && d1.DajMjesec() == d2.DajMjesec() && d1.DajDan() < d2.DajDan()) return true;
        return false;
    }

    bool SkupljiStan(const Prodaja &p1, const Prodaja &p2) {
        return (p1.DajCijenuStana() > p2.DajCijenuStana());
    }

class Prodaje{
    int max_broj_prodaja;
    int broj_prodaja;
    Prodaja** prodaje;
    
    public:
    explicit Prodaje(int max_broj_prodaja) : max_broj_prodaja(max_broj_prodaja), broj_prodaja(0), prodaje(new Prodaja*[max_broj_prodaja]) { }
    
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
    ~Prodaje();
    Prodaje(const Prodaje &prodaje);
    Prodaje(Prodaje &&prodaje);
    Prodaje &operator= (const Prodaje &prodaje);
    Prodaje &operator =(Prodaje &&prodaje);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void RegistrirajProdaju(Prodaja *prodaja);
    Prodaja &DajProdaju(int i);
    int DajBrojProdaja() const { return broj_prodaja; }
    int DajBrojProdajaNaDatum(const Datum &datum) const;
    int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const;
    Prodaja &DajNajranijuProdaju();
    Prodaja DajNajranijuProdaju() const; //nije implementirano
    Prodaja &DajNajskupljuProdaju();
    Prodaja DajNajskupljuProdaju() const; //nije implementirano
    void IsprazniKolekciju();
    void ObrisiNajranijuProdaju();
    void ObrisiProdajeAgenta(const std::string &ime_agenta); 
    void ObrisiProdajeNaDatum(const Datum &datum);   
    void IspisiProdajeNaDatum(const Datum &datum) const;
    void IspisiSveProdaje() const;
    
};

    Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja){
            max_broj_prodaja=spisak_prodaja.size();
            prodaje = new Prodaja*[max_broj_prodaja];
            broj_prodaja=0;
            for(auto p:spisak_prodaja){
                *prodaje=new Prodaja(p);
                prodaje++;
            }
        }
    
    Prodaje::~Prodaje(){
            //nema prodaja
            if(prodaje== nullptr) return;
            
            for(int i=0; i<broj_prodaja; i++) delete prodaje[i];
            delete[] prodaje;
            prodaje=nullptr;
            broj_prodaja=0;
        }
        
    Prodaje::Prodaje(const Prodaje &prodaje){
            max_broj_prodaja=prodaje.max_broj_prodaja;
            broj_prodaja=prodaje.broj_prodaja;
            
            this->prodaje=new Prodaja*[max_broj_prodaja];
            
            for(int i =0; i < broj_prodaja; i++){
                this->prodaje[i]=new Prodaja(*(prodaje.prodaje[i]));
            }
        }
        
    Prodaje::Prodaje(Prodaje &&prodaje){
        this->broj_prodaja=prodaje.broj_prodaja;
        this->max_broj_prodaja=prodaje.max_broj_prodaja;
        this->prodaje=prodaje.prodaje;
        prodaje.prodaje=nullptr;
    }
    
    Prodaje &Prodaje::operator= (const Prodaje &prodaje){
        if(&prodaje==this) return *this;
        
       //if(prodaje==nullptr) return;
        
        for(int i=0; i<broj_prodaja; i++) delete this->prodaje[i];
        delete[] this->prodaje;
       // prodaje.prodaje=nullptr;
        
        broj_prodaja=prodaje.broj_prodaja;
        max_broj_prodaja=prodaje.max_broj_prodaja;
        this->prodaje=new Prodaja*[max_broj_prodaja];
        for(int i =0; i < broj_prodaja;i++){
            this->prodaje[i]=new Prodaja(*(prodaje.prodaje[i]));
        }
        
        return *this;
    }

    Prodaje &Prodaje::operator= (Prodaje &&prodaje){
        if(&prodaje==this){
            delete[] this->prodaje;
            
            this->max_broj_prodaja=prodaje.max_broj_prodaja;
            this->broj_prodaja=prodaje.broj_prodaja;
            this->prodaje=prodaje.prodaje;
            prodaje.prodaje=nullptr;
        }
        return *this;
    }
    
    void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan){
        if(broj_prodaja>=max_broj_prodaja) throw std::range_error("Dostignut maksimalni broj prodaja");
        prodaje[broj_prodaja]=new Prodaja(ime_agenta_prodaje, cijena_stana, datum_prodaje, kupac_stana, kupljeni_stan);
        broj_prodaja++;
    } //radi

    void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata){
         if(broj_prodaja>=max_broj_prodaja) throw std::range_error("Dostignut maksimalni broj prodaja");
         prodaje[broj_prodaja]=new Prodaja(ime_agenta_prodaje, cijena_stana, dan_prodaje,mjesec_prodaje, godina_prodaje, ime_kupca, datum_rodjenja_kupca, adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata);
         broj_prodaja++;
     }
    
    void Prodaje::RegistrirajProdaju(Prodaja *prodaja){
        if(broj_prodaja>= max_broj_prodaja) throw std::range_error("Dostignut maksimalan broj prodaja");
        prodaje[broj_prodaja]=prodaja;
        broj_prodaja++;
    } //radi
    
    Prodaja &Prodaje::DajProdaju(int i){
        return *prodaje[i];
    }
    
    int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const{
        return std::count_if(prodaje, prodaje+broj_prodaja, 
                              [&datum] (Prodaja *p)->bool
                              {
                                  if(p->DajDatumProdaje().DajDan()==datum.DajDan() && p->DajDatumProdaje().DajMjesec()==datum.DajMjesec() && p->DajDatumProdaje().DajGodinu()==datum.DajGodinu()) return true;
                                  return false;
                              });
    } //radi
    
    int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const{
        int broj_prodaja_od_agenta=0;
        
        for(int i=0; i < broj_prodaja; i++){
            if(prodaje[i]->DajImeAgenta() == ime_agenta) broj_prodaja_od_agenta++;
        }
        
        return broj_prodaja_od_agenta;
    } //radi
    
    Prodaja &Prodaje::DajNajranijuProdaju(){
        if(broj_prodaja==0) throw std::domain_error("Nema registriranih prodaja");
        return **std::min_element(prodaje, prodaje+broj_prodaja, 
                                  [] (Prodaja *p1, Prodaja *p2)->bool{
                                     return(ProdatPrije(*p1, *p2)); 
                                  });
    } //radi
    
    Prodaja &Prodaje::DajNajskupljuProdaju() {
        if(broj_prodaja==0) throw std::domain_error("Nema registriranih prodaja");
                return **std::max_element(prodaje, prodaje+broj_prodaja, 
                                  [] (Prodaja *p1, Prodaja *p2)->bool{
                                     return(p1->DajCijenuStana() < p2->DajCijenuStana()); 
                                  });
    } //radi
    
    void Prodaje::IsprazniKolekciju(){
        if(prodaje==nullptr) return;
        
        for(int i=0; i < broj_prodaja; i++)
            delete prodaje[i];
            
        broj_prodaja=0;
    } //radi
    
    void Prodaje::ObrisiNajranijuProdaju(){
        if(broj_prodaja== 0) throw std::range_error("Prazna kolekcija");
        Prodaja& p= DajNajranijuProdaju();
        for(int i =0; i < broj_prodaja; i++){
            if(prodaje[i]==&p){
                delete prodaje[i];
                for(int j=i; j < broj_prodaja-1; j++){
                    prodaje[j]=prodaje[j+1];
                }
            }
        }
        broj_prodaja--;
    } //radi
    
    void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta){
        for(int i=0; i<broj_prodaja; i++){
            if(prodaje[i]->DajImeAgenta() == ime_agenta){
                delete prodaje[i];
                for(int j=i; j<broj_prodaja-1; j++){
                    prodaje[j]=prodaje[j+1];
                }
                broj_prodaja--;
            }
        }
    }  //radi
    
    void Prodaje::ObrisiProdajeNaDatum(const Datum &datum){
            for(int i=0; i < broj_prodaja; i++){
            if(prodaje[i]->DajDatumProdaje().DajDan()==datum.DajDan() && prodaje[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec() && prodaje[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu()){
                delete prodaje[i];
                for(int j=i; j < broj_prodaja-1; j++){
                    prodaje[j]=prodaje[j+1];
                }
                broj_prodaja--;
                 i--;
            }
           
        }
    }  //radi
    
    void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const{
        Prodaja** pomocne = prodaje;
        
        std::sort(pomocne, pomocne+broj_prodaja, 
        [](Prodaja *p1, Prodaja *p2){
            if(p1->DajImeKupca() < p2->DajImeKupca()) return true;
            return false;
        });
        for(int i=0; i < broj_prodaja; i++){
            if(prodaje[i]->DajDatumProdaje().DajDan()==datum.DajDan() && prodaje[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec() && prodaje[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu())
                pomocne[i]->Ispisi();
        }
        for(int i=0; i < broj_prodaja; i++){
            delete pomocne[i];
        }
        delete[] pomocne;
        
    } //radi
    
    void Prodaje::IspisiSveProdaje() const{
        Prodaja** pomocne = prodaje;
        std::sort(pomocne, pomocne+broj_prodaja,
        [] (Prodaja* p1, Prodaja* p2){
            if(ProdatPrije(*p1, *p2)) return true;
            if(!ProdatPrije(*p1, *p2)){
                if(p1->DajDatumProdaje().DajDan() == p2->DajDatumProdaje().DajDan() && p1->DajDatumProdaje().DajMjesec() == p2->DajDatumProdaje().DajMjesec() && p1->DajDatumProdaje().DajGodinu() == p2->DajDatumProdaje().DajGodinu()){
                    return p1->DajImeKupca() < p2->DajImeKupca();
                }
            }
            return false;
        });
        
        for(int i =0; i < broj_prodaja; i++){
            pomocne[i]->Ispisi();
        }
        
        for(int i =0; i < broj_prodaja; i++){
            delete pomocne[i];
        }
        delete[] pomocne;
        
    } //radi
    
    
int main ()
{
    std::cout << "Dobrodosli!" << std::endl;
    std::cout << std::endl;
    Prodaje prodaje(20);
    
    for(;;){
        std::cout <<std::endl<< "Izaberite opciju:" << std::endl;
        std::cout << " 0 - kraj" << std::endl;
        std::cout << " 1 - uredjivanje stanova" << std::endl;
        std::cout << " 2 - uredjivanje kupaca" << std::endl;
        std::cout << " 3 - uredjivanje prodaja" << std::endl;
        int n;
        std::cin>>n;
        std::vector<Stan> stanovi;
        std::vector<Kupac> kupci;
        if(n==0) { std::cout << std::endl << std::endl << "Dovidjenja!"; break; }
        
        //Uredjivanje stanova
        if(n==1){
            for(;;){
                
                std::cout << "Izaberite opciju:"<< std::endl;;
                std::cout << " 0 - nazad" << std::endl;
                std::cout << " 1 - dodavanje stana" << std::endl;
                std::cout << " 2 - uredjivanje stanova" << std::endl;
                std::cout << " 3 - ispis svih stanova" << std::endl;
                std::cout << " 4 - kraj" << std::endl;
                int unos;
                std::cin>>unos;
                
                if(unos==0) break;
                
                //dodavanjee stana
                if(unos==1){ 
                    for(;;){
                    
                        std::cout << "Unesite adresu: ";
                        std::cin.ignore();
                        std::string adresa;
                        std::getline(std::cin, adresa);
        
                        
                        std::cout << "Unesite sprat: ";
                        int sprat;
                        std::cin>>sprat;
                        
                        std::cout << "Unesite broj soba: ";
                        //std::cin.clear();
                        int brSoba;
                        std::cin>>brSoba;
                        
                        std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                        int namjesten_int;
                        
                        std::cin>>namjesten_int;
    
                        std::cout << "Unesite kvadraturu: ";
                        double kvadratura;
                        std::cin>>kvadratura;
                        try{
                            bool namjesten;
                            if(namjesten_int==0) namjesten=false;
                            else if(namjesten_int==1) namjesten=true;
                            else throw std::domain_error("Neispravan unos podataka");
                            Stan s(adresa, sprat, brSoba, namjesten,kvadratura);
                            stanovi.push_back(s);
                            std::cout << "Stan je uspjesno dodan!" << std::endl;
                            std::cout << std::endl;
                            break;
                        } catch(std::domain_error izuzetak){
                            std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet." ;
                            std::cout << std::endl;
                        }
                    }
                } 
                if(unos==2){
                    std::cout << "Odaberite stan. Dostupni stanovi su:" << std::endl;
                    for(int i =0; i < stanovi.size();i++){
                        std::cout <<" "<< i+1 << " - "; stanovi[i].Ispisi(); std::cout << std::endl;
                    }
                    int odabraniStan;
                    std::cin >> odabraniStan;
                    std::cout << std::endl<<"Odaberite polje koje zelite urediti:" << std::endl;
                    std::cout << " 0 - nazad"<< std::endl;
                    std::cout << " 1 - adresa"<< std::endl;
                    std::cout << " 2 - sprat"<< std::endl;
                    std::cout << " 3 - broj soba"<< std::endl;
                    std::cout << " 4 - da li je stan namjesten"<< std::endl;
                    std::cout << " 5 - kvadratura"<< std::endl;
                    std::cout << " 6 - sve"<< std::endl;
                    int uredi;
                    std::cin>>uredi;
                    //if(uredi==0) continue;
                    if(uredi==1){
                        for(;;){
                            std::cin.ignore();
                            
                            try{
                                std::string novaAdresa;
                                std::getline(std::cin, novaAdresa);
                                std::cin.clear();
                                stanovi[odabraniStan-1].Postavi(novaAdresa, 
                                                                    stanovi[odabraniStan-1].DajSprat(),
                                                                    stanovi[odabraniStan-1].DajBrojSoba(),
                                                                    stanovi[odabraniStan-1].DajNamjesten(),
                                                                    stanovi[odabraniStan-1].DajKvadraturu());
                                    std::cout << "Stan je uspjesno izmijenjen!" << std::endl;
                                    std::cin.clear();
                                    std::cin.ignore(100, '\n');
                                    break;
                                
                            }
                            catch(std::domain_error izuzetak){
                                std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet." << std::endl;
                                std::cout << std::endl;
                                std::cin.clear();
                                std::cin.ignore(100, '\n');
                            }
                        }
                    }
                    
                    if(uredi==2){
                        for(;;){
                            std::cout <<"Unesite sprat: "; 
                            int noviSprat;
                            try{
                                std::cin>>noviSprat;
                                if(noviSprat < 0) throw std::domain_error("Neispravan unos podataka");
                                stanovi[odabraniStan-1].Postavi(stanovi[odabraniStan-1].DajAdresu(), 
                                                                    noviSprat,
                                                                    stanovi[odabraniStan-1].DajBrojSoba(),
                                                                    stanovi[odabraniStan-1].DajNamjesten(),
                                                                    stanovi[odabraniStan-1].DajKvadraturu());
                                    std::cout << "Stan je uspjesno izmijenjen!" << std::endl;
                                    std::cout <<std::endl;
                                    std::cin.clear();
                                    std::cin.ignore(100, '\n');
                                
                            }
                            catch(std::domain_error izuzetak){
                                std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet." << std::endl;
                                std::cout << std::endl;
                                    std::cin.clear();
                                    std::cin.ignore(100, '\n');                                
                            }
                        }
                    }
                    
                    if(uredi==3){
                        for(;;){
                            std::cout <<"Unesite broj soba: "; 
                            int noviBrojSoba;
                            try{
                                std::cin>>noviBrojSoba;
                                if(noviBrojSoba < 0) throw std::domain_error("Neispravan unos podataka");
                                stanovi[odabraniStan-1].Postavi(stanovi[odabraniStan-1].DajAdresu(), 
                                                                    stanovi[odabraniStan-1].DajSprat(),
                                                                    noviBrojSoba,
                                                                    stanovi[odabraniStan-1].DajNamjesten(),
                                                                    stanovi[odabraniStan-1].DajKvadraturu());
                                    std::cout << "Stan je uspjesno izmijenjen!" << std::endl;
                                    std::cin.clear();
                                    std::cin.ignore(100, '\n');
                                    break;
                                
                            }
                            catch(std::domain_error izuzetak){
                                std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet." << std::endl;
                                std::cout << std::endl;
                                std::cin.clear();
                                std::cin.ignore(100, '\n');
                            }
                        }
                    }
                    
                    if(uredi==4){
                        for(;;){
                            std::cout <<"Da li je stan namjesten (1 - da, 0 - ne): "; 
                            int noviNamjesten;
                            try{
                                std::cin>>noviNamjesten;
                                if(noviNamjesten>1 || noviNamjesten <0) throw std::domain_error("Neispravan unos podataka");
                                bool noviNamjestenBool=false;
                                if(noviNamjesten==0) noviNamjestenBool=false;
                                else if(noviNamjesten==1) noviNamjestenBool=true;
                                stanovi[odabraniStan-1].Postavi(stanovi[odabraniStan-1].DajAdresu(), 
                                                                    stanovi[odabraniStan-1].DajSprat(),
                                                                    stanovi[odabraniStan-1].DajBrojSoba(),
                                                                    noviNamjestenBool,
                                                                    stanovi[odabraniStan-1].DajKvadraturu());
                                    std::cout << "Stan je uspjesno izmijenjen!" << std::endl;
                                    std::cin.clear();
                                    std::cin.ignore(100, '\n');
                                    break;
                                
                            }
                            catch(std::domain_error izuzetak){
                                std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet." << std::endl;
                                std::cout << std::endl;
                                std::cin.clear();
                                std::cin.ignore(100, '\n');                      
                            }
                        }
                    }
                    
                    if(uredi==5){
                        for(;;){
                            std::cout <<"Unesite kvadraturu: "; 
                            double novaKvadratura;
                            std::cin >> novaKvadratura;
                            try{
                                if(novaKvadratura < 0)  throw std::domain_error("Neispravan unos podataka");
                                    stanovi[odabraniStan-1].Postavi(stanovi[odabraniStan-1].DajAdresu(), 
                                                                    stanovi[odabraniStan-1].DajSprat(),
                                                                    stanovi[odabraniStan-1].DajBrojSoba(),
                                                                    stanovi[odabraniStan-1].DajNamjesten(),
                                                                    novaKvadratura);
                                    std::cout << "Stan je uspjesno izmijenjen!" << std::endl;
                                    std::cout << std::endl;
                                    std::cin.clear();
                                    std::cin.ignore(100, '\n');
                                    break;
                            }
                            catch(std::domain_error izuzetak){
                                std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet." << std::endl;
                                std::cin.clear();
                                std::cin.ignore(100, '\n');
                            }
                        }
                    }
                    
                    if(uredi==6){
                        for(;;){
                            std::cout << "Unesite adresu: ";
                            std::cin.ignore();
                            std::string adresa;
                            std::getline(std::cin, adresa);
            
                            
                            std::cout << "Unesite sprat: ";
                            int sprat;
                            std::cin>>sprat;
                            
                            std::cout << "Unesite broj soba: ";
                            //std::cin.clear();
                            int brSoba;
                            std::cin>>brSoba;
                            
                            std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                            int noviNamjesten;
                            std::cin>>noviNamjesten;    
                            
                             std::cout << "Unesite kvadraturu: ";
                            double kvadratura;
                            std::cin>>kvadratura;
                            
                             try{
                                bool namjesten;
                                if(noviNamjesten==0) namjesten=false;
                                else if(noviNamjesten==1) namjesten=true;
                                else throw std::domain_error("Neispravan unos podataka");
                                stanovi[odabraniStan-1].Postavi(adresa, sprat, brSoba, namjesten, kvadratura);
                                
                                std::cout << "Stan je uspjesno izmijenjen!" << std::endl;
                                std::cout << std::endl;
                                std::cin.clear();
                                std::cin.ignore(100, '\n');
                                break;
                                
                            } catch(std::domain_error izuzetak){
                                std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet." << std::endl;
                                std::cout << std::endl;
                                std::cin.clear();
                                std::cin.ignore(100, '\n');
                            }
                        }
                    }
                } 
                if(unos==3){ //ispis stanova
                    int i = 1;
                    for(Stan s: stanovi){
                        std::cout << i << ". "; s.Ispisi(); std::cout << std::endl;
                        i++;
                    }
                    std::cout << std::endl;
                }
                if(unos==4) break; //kraj cega? mozda return?
            }
        }
        
        //uredjivanje kupaca
        if(n==2){
            for(;;){
                
                std::cout << "Izaberite opciju:"<< std::endl;;
                std::cout << " 0 - nazad" << std::endl;
                std::cout << " 1 - dodavanje kupca" << std::endl;
                std::cout << " 2 - uredjivanje kupaca" << std::endl;
                std::cout << " 3 - ispis svih kupaca" << std::endl;
                std::cout << " 4 - kraj" << std::endl;
                int unos;
                std::cin>>unos;
                
                if(unos==0) break;
                
                if(unos==1){ 
                    for(;;){
                        std::cout << "Unesite ime i prezime kupca: ";
                        std::cin.ignore();
                        std::string ime_prezime;
                        std::getline(std::cin, ime_prezime);
                        
                        
                        std::cout << "Unesite datum rodjenja (formata d/m/g): ";
                        std::string datumRodjenja;
                        std::getline(std::cin, datumRodjenja);
                        int danRodjenja=stoi(datumRodjenja.substr(0,2));
                        int mjesecRodjenja=stoi(datumRodjenja.substr(3,2));
                        int godRodjenja=stoi(datumRodjenja.substr(6,4));
                        try{
                            Datum d(danRodjenja, mjesecRodjenja, godRodjenja);
                            Kupac k(ime_prezime, d);
                            kupci.push_back(k);
                            std::cout << "Kupac je uspjesno dodan!" << std::endl;
                            std::cout << std::endl;
                            break;
                        } catch(std::domain_error izuzetak){
                            std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet." << std::endl;
                            //std::cout << std::endl;
                        }
                    }
                } 
                
                if(unos==2){
                     for(;;){
                    std::cout << "Odaberite kupca kojeg zelite urediti. Dostupni kupci su:" << std::endl;
                    for(int i =0; i < kupci.size();i++){
                        std::cout<<" " << i+1 << " - "; kupci[i].Ispisi(); 
                    }
                        int odabraniKupac;
                        std::cin >> odabraniKupac;
                        std::cout << "Unesite ime i prezime kupca: ";
                         std::cin.ignore();
                        std::string ime_prezime;
                        std::getline(std::cin, ime_prezime);
                        
                        std::cout << "Unesite datum rodjenja (formata dan/mjesec/godina): ";
                        std::string datumRodjenja;
                        std::getline(std::cin, datumRodjenja);
                        int danRodjenja=stoi(datumRodjenja.substr(0,2));
                        int mjesecRodjenja=stoi(datumRodjenja.substr(3,2));
                        int godRodjenja=stoi(datumRodjenja.substr(6,4));
                        try{
                            Datum d(danRodjenja, mjesecRodjenja, godRodjenja);
                            Kupac k(ime_prezime, d);
                            kupci.push_back(k);
                            std::cout << "Kupac je uspjesno izmijenjen!" << std::endl;
                            std::cout << std::endl;

                            break;
                        } catch(std::domain_error izuzetak){
                            std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet." << std::endl;
                                std::cout << std::endl;
                                std::cin.clear();
                                std::cin.ignore(100, '\n');
                        }
                     }
                }
                
                if(unos==3){ //ispis kupaca
                    int i = 1;
                    for(Kupac k: kupci){
                        k.Ispisi(); 
                        //std::cout << std::endl;
                        i++;
                    }
                    
                }
                
            }   
        }
    }

	return 0;
}