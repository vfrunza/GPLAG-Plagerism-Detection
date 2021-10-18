/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <initializer_list>
#include <algorithm>

class Datum{
    int dan, mjesec, godina;
    public:
    
    Datum(int dan, int mjesec, int godina) { Postavi(dan,mjesec,godina);}
    void Postavi(int dan, int mjesec, int godina);
    int DajDan() const{return dan;}
    int DajMjesec() const{return mjesec;}
    int DajGodinu() const{return godina;}
    void Ispisi() const { std::cout<<dan<<"/"<<mjesec<<"/"<<godina;}
};

void Datum::Postavi(int dan, int mjesec, int godina){
    int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if((godina%4==0 && godina%100!=0) || godina%400==0) broj_dana[1]++;
    if(godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>broj_dana[mjesec-1]) throw std::domain_error("Neispravan datum");
    Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
}



class Kupac{
    std::string ime_i_prezime;
    Datum datum_rodjenja;
    
    public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja): datum_rodjenja(datum_rodjenja) {Postavi(ime_i_prezime, datum_rodjenja);}
    void Postavi(const  std::string &ime_i_prezime, const Datum &datum_rodjenja);
    std::string DajImePrezime() const {return ime_i_prezime;}
    Datum DajDatumRodjenja() const { return datum_rodjenja;}
    void Ispisi() const {std::cout<<ime_i_prezime<<" ("; datum_rodjenja.Ispisi(); std::cout<<")";}
};

void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja){
    for(int i(0); i<int(ime_i_prezime.size()); i++){
        if( ((ime_i_prezime.at(i)>='a' && ime_i_prezime.at(i)<='z') || (ime_i_prezime.at(i)>='A' && ime_i_prezime.at(i)<='Z')  || (ime_i_prezime.at(i)>='0' && ime_i_prezime.at(i)<='9'))==false 
        && ime_i_prezime.at(i)!=' ' && ime_i_prezime.at(i)!='-'  && ime_i_prezime.at(i)!='\'') throw std::domain_error("Neispravno ime i prezime");
    }
    Kupac::ime_i_prezime=ime_i_prezime; Kupac::datum_rodjenja=datum_rodjenja;
}



class Stan{
    std::string adresa;
    int sprat;
    int broj_soba;
    bool namjesten;
    double kvadratura;
    
    public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {Postavi(adresa,sprat,broj_soba,namjesten,kvadratura);}
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
    std::string DajAdresu() const {return adresa;}
    int DajSprat () const {return sprat;}
    int DajBrojSoba () const{return broj_soba;}
    bool DajNamjesten() const{return namjesten;}
    double DajKvadraturu() const {return kvadratura;}
    void Ispisi() const;
    
};

void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
    if(sprat<0 || broj_soba<0 || kvadratura<0) throw std::domain_error("Neispravan unos podataka");
    Stan::adresa=adresa; Stan::sprat=sprat; Stan::broj_soba=broj_soba; Stan::namjesten=namjesten; Stan::kvadratura=kvadratura;
}

void Stan::Ispisi() const{
    std::cout<<"Stan se nalazi na adresi "<<adresa<<" na "<<sprat<<". spratu i ima "<<broj_soba;
    int p(broj_soba%100); if(p<0) p*=(-1);
    if((p<10 || p>20 ) && (p%10==2 || p%10==3 || p%10==4)) std::cout<<" sobe.";
    else if((p<10 || p>20) && p%10==1) std::cout<<" sobu.";
    else std::cout<<" soba.";
    
    std::cout<<std::endl<<"Kvadratura stana je "<<kvadratura<<" (m^2) i stan ";
    if(namjesten) std::cout<<"je namjesten.";
    else std::cout<<"nije namjesten.";
}



class Prodaja{
    std::string ime_agenta;
    double cijena_stana;
    Datum datum_prodaje;
    Kupac kupac_stana;
    Stan kupljeni_stan;
    
    public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
            std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, 
            int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void PromijeniKupca(const Kupac &novi_kupac){kupac_stana=novi_kupac;}
    void PromijeniStan(const Stan &novi_stan){kupljeni_stan=novi_stan;}
    void PromijeniDatumKupovPrine(const Datum &novi_datum){datum_prodaje=novi_datum;}
    void PromijeniCijenuProdaje(const double &nova_cijena){cijena_stana=nova_cijena;}
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImeAgenta() const{return ime_agenta;}
    std::string DajImeKupca() const{return kupac_stana.DajImePrezime();}
    Datum DajDatumProdaje() const{return datum_prodaje;}
    double DajCijenuStana() const{return cijena_stana;}
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
    void Ispisi() const;
};

Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan):
                ime_agenta(ime_agenta_prodaje), cijena_stana(cijena_stana), datum_prodaje(datum_prodaje), kupac_stana(kupac_stana), kupljeni_stan(kupljeni_stan) {}

Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
                std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, 
                int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata):
                
                ime_agenta(ime_agenta_prodaje), cijena_stana(cijena_stana), datum_prodaje(dan_prodaje, mjesec_prodaje, godina_prodaje),
                kupac_stana(ime_kupca,datum_rodjenja_kupca), kupljeni_stan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata) {}

void Prodaja::PomjeriDanUnaprijed (){
    int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if((datum_prodaje.DajGodinu()%4==0 && datum_prodaje.DajGodinu()%100!=0) || datum_prodaje.DajGodinu()%400==0) broj_dana[1]++;
    int dan(datum_prodaje.DajDan()), mjesec(datum_prodaje.DajMjesec()), godina(datum_prodaje.DajGodinu());
    dan++;
    if(dan>broj_dana[mjesec-1]) dan=1, mjesec++;
    if(mjesec>12) mjesec=1, godina++;
    datum_prodaje.Postavi(dan, mjesec, godina);
}

void Prodaja::PomjeriDanUnazad (){
    int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    int dan(datum_prodaje.DajDan()), mjesec(datum_prodaje.DajMjesec()), godina(datum_prodaje.DajGodinu());
    if((godina%4==0 && godina%100!=0) || godina%400==0) broj_dana[1]++;
    dan--;
    if(dan==0) {
        mjesec--;
        if(mjesec==0) {mjesec=12; godina--;}
        dan=broj_dana[mjesec-1];
    }
    datum_prodaje.Postavi(dan,mjesec,godina);
}

bool ProdatPrije(const Prodaja &p1, const Prodaja &p2){
    if(p1.datum_prodaje.DajGodinu()<p2.datum_prodaje.DajGodinu()) return true;
    if(p1.datum_prodaje.DajGodinu()==p2.datum_prodaje.DajGodinu()) {
        if(p1.datum_prodaje.DajMjesec()<p2.datum_prodaje.DajMjesec()) return true;
        if(p1.datum_prodaje.DajMjesec()==p2.datum_prodaje.DajMjesec()){
            if(p1.datum_prodaje.DajDan()<p2.datum_prodaje.DajDan()) return true;
        }
    }
    return false;
}

bool SkupljiStan(const Prodaja &p1, const Prodaja &p2){
    return p1.cijena_stana>p2.cijena_stana;
}

void Prodaja::Ispisi()const{
    std::cout<<std::setw(30)<<"Ime agenta:"<<ime_agenta
             <<std::setw(30)<<"Ime kupca:"; kupac_stana.Ispisi();
    std::cout<<std::setw(30)<<"Zakazani datum prodaje:"; datum_prodaje.Ispisi();
    std::cout<<std::setw(30)<<"Cijena stana:"<<cijena_stana
            <<std::setw(30)<<"Informacije o stanu:"<<std::endl; kupljeni_stan.Ispisi();
}



class Prodaje{
    int max_broj_prodaja;
    int broj_prodaja;
    Prodaja **niz;
    
    static bool ProvjeraDatuma(Datum d1, Datum d2){
        if(d1.DajGodinu()==d2.DajGodinu()){
            if(d1.DajMjesec()==d2.DajMjesec()){
                if(d1.DajDan()==d2.DajDan()) return true;
            }
        }
        return false;
    }
    
    public:
    explicit Prodaje(int max_broj_prodaja);
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
    ~Prodaje();
    Prodaje (const Prodaje &prodaje);
    Prodaje (Prodaje &&prodaje);
    Prodaje &operator=(const Prodaje &prodaje);
    Prodaje &operator=(Prodaje &&prodaje);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
                            std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana,
                            int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void RegistrirajProdaju(Prodaja *prodaja);
    int DajBrojProdaja () const;
    Prodaja &DajProdaju(int redni_broj);
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


Prodaje::Prodaje(int max_broj_prodaja) {
     niz=new Prodaja *[max_broj_prodaja];
    for(int i(0); i<max_broj_prodaja; i++){
        niz[i]=nullptr;
    }
    Prodaje::max_broj_prodaja=max_broj_prodaja;
    broj_prodaja=0;
}

Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja){
    
    niz=new Prodaja *[int(spisak_prodaja.size())]; broj_prodaja=0;
    for(int i(0); i<int(spisak_prodaja.size()); i++) niz[i]=nullptr;
    try{
        int i(0);
    for(auto it(spisak_prodaja.begin()); it!=spisak_prodaja.end(); it++,i++ ){
        niz[i]=new Prodaja(*it); broj_prodaja++;
    }
    max_broj_prodaja=int(spisak_prodaja.size());
    }
    catch(...){
        for(int i(0); i<broj_prodaja; i++) delete niz[i]; delete[] niz;
    }
}

Prodaje::~Prodaje(){
    for(int i(0); i<broj_prodaja; i++){
        delete niz[i];
    }
    delete [] niz;
}

Prodaje::Prodaje(const Prodaje &prodaje){
    
    niz=new Prodaja *[prodaje.broj_prodaja]{};
  try{
    for(auto i(0); i<prodaje.broj_prodaja; i++){
        niz[i]=new Prodaja(*prodaje.niz[i]);
    }
    max_broj_prodaja=prodaje.max_broj_prodaja;
    broj_prodaja=prodaje.broj_prodaja;
  }
  catch(...){
      for(int i(0); i<prodaje.broj_prodaja; i++) delete niz[i];
      delete[] niz; throw;
  }
}

Prodaje::Prodaje(Prodaje &&prodaje): max_broj_prodaja(prodaje.max_broj_prodaja), broj_prodaja(prodaje.broj_prodaja), niz(prodaje.niz){
    prodaje.niz=nullptr; prodaje.broj_prodaja=0;
}

Prodaje &Prodaje::operator=(const Prodaje &prodaje){
    Prodaja **temp (new Prodaja *[prodaje.max_broj_prodaja]{});
    try{
        for(int i(0); i<prodaje.broj_prodaja; i++) temp[i]=prodaje.niz[i];
    }
    catch(...){
        for(int i(0); i<prodaje.broj_prodaja; i++) delete temp[i];
        delete[] temp;
    }
    delete[] niz;
    niz=temp;
    broj_prodaja=prodaje.broj_prodaja; max_broj_prodaja=prodaje.max_broj_prodaja;
    return *this;
}

Prodaje &Prodaje::operator=(Prodaje &&prodaje){
    std::swap(broj_prodaja,prodaje.broj_prodaja);
    std::swap(max_broj_prodaja,prodaje.max_broj_prodaja);
    return *this;
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje,  const Kupac &kupac_stana, const Stan &kupljeni_stan){
    if(broj_prodaja==max_broj_prodaja) throw std::range_error("Dostignut maksimalan broj prodaja");
    int i(0);
    while(niz[i]!=nullptr) i++;
    niz[i]=new Prodaja (ime_agenta_prodaje, cijena_stana, datum_prodaje, kupac_stana, kupljeni_stan);
    broj_prodaja++;
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
                                std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,
                                int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata){
    if(broj_prodaja==max_broj_prodaja) throw std::range_error("Dostignut maksimalan broj prodaja");
    int i(0);
    while(niz[i]!=nullptr) i++;
    niz[i]=new Prodaja(ime_agenta_prodaje, cijena_stana, dan_prodaje, mjesec_prodaje, godina_prodaje,ime_kupca, datum_rodjenja_kupca,
                        adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata);
    broj_prodaja++;
}

void Prodaje::RegistrirajProdaju(Prodaja *prodaja){
    if(broj_prodaja==max_broj_prodaja){
        delete prodaja;
        throw std::range_error("Dostignut maksimalan broj prodaja");
    } 
    int i(0);
    while(niz[i]!=nullptr) i++;
    niz[i]=prodaja;
    broj_prodaja++;
}

int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const{
    return std::count_if(niz, niz+broj_prodaja, [&datum](Prodaja *p1){return ProvjeraDatuma(p1->DajDatumProdaje(),datum);} );
}

int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const{
    return std::count_if(niz, niz+broj_prodaja, [ime_agenta](Prodaja *p1){return p1->DajImeAgenta()==ime_agenta; } );
}


Prodaja &Prodaje::DajProdaju(int redni_broj){
    if(redni_broj<1 || redni_broj>broj_prodaja+1) throw;
    return *niz[redni_broj-1];
}

Prodaja &Prodaje::DajNajranijuProdaju(){
    if(broj_prodaja==0) throw std::domain_error ("Nema registriranih prodaja");
    auto it=std::min_element(niz, niz+broj_prodaja, [](Prodaja *p1, Prodaja *p2) {return ProdatPrije(*p1,*p2); });
    return *(*it);
}

Prodaja Prodaje::DajNajranijuProdaju() const {
    if(broj_prodaja==0) throw std::domain_error ("Nema registriranih prodaja");
    auto it=std::min_element(niz, niz+broj_prodaja, [](Prodaja *p1, Prodaja *p2) {return ProdatPrije(*p1,*p2);});
    return *(*it);
}

Prodaja &Prodaje::DajNajskupljuProdaju(){
    if(broj_prodaja==0) throw std::domain_error ("Nema registriranih prodaja");
    auto it=std::max_element(niz,niz+10, [](Prodaja *p1, Prodaja *p2){return SkupljiStan(*p1,*p2);});
    return *(*it);
}

Prodaja Prodaje::DajNajskupljuProdaju()const{
    if(broj_prodaja==0) throw std::domain_error ("Nema registriranih prodaja");
    auto it=std::max_element(niz, niz+10, [](Prodaja *p1, Prodaja *p2){return SkupljiStan(*p1,*p2);});
    return *(*it);
}

void Prodaje::IsprazniKolekciju(){
    for(int i(0); i<broj_prodaja; i++){
        delete niz[i]; niz[i]=nullptr;
    }
    broj_prodaja=0;
}

void Prodaje::ObrisiNajranijuProdaju(){
    if(broj_prodaja==0) throw std::range_error ("Prazna kolekcija");
    auto it=std::min_element(niz, niz+10, [](Prodaja *p1, Prodaja *p2){return ProdatPrije(*p1,*p2);});
    (*it)=nullptr;
    broj_prodaja--;
    
    Prodaja **temp(new Prodaja *[broj_prodaja]);
    for(int i(0); i<broj_prodaja; i++) temp[i]=niz[i];
    for(int i(0); i<broj_prodaja; i++) delete niz[i];
    for(int i(0), j(0); i<broj_prodaja; i++, j++){
        if(temp[i]!=nullptr)  niz[j]=temp[i];
        else j--;
    }
    delete[] temp;
    broj_prodaja--;
}

void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta){
    int brojac(0);
    for(int i(0); i<broj_prodaja; i++){
        if(niz[i]!=nullptr){
         if(niz[i]->DajImeAgenta()==ime_agenta) { delete niz [i]; niz[i]=nullptr; brojac++;}
        }
    }
    if(brojac>0){
        Prodaja **temp(new Prodaja *[broj_prodaja]);
        for(int i(0); i<broj_prodaja; i++) temp[i]=niz[i];
        for(int i(0); i<broj_prodaja; i++) {delete niz[i]; niz[i]=nullptr;}
        for(int i(0), j(0); i<broj_prodaja; i++, j++) {
            if(temp[i]!=nullptr) niz[j]=temp[i];
            else j--;
        }
        delete[] temp;
    }
    broj_prodaja-=brojac;
}

void Prodaje::ObrisiProdajeNaDatum(const Datum &datum){
    int brojac(0);
    for(int i(0); i<broj_prodaja; i++){
        if(niz[i]!=nullptr){
            if(ProvjeraDatuma(niz[i]->DajDatumProdaje(), datum)) {delete niz[i]; niz[i]=nullptr; brojac++;}
        }
    }
    if(brojac>0){
        Prodaja **temp(new Prodaja *[broj_prodaja]);
        for(int i(0); i<broj_prodaja; i++) temp[i]=niz[i];
        for(int i(0); i<broj_prodaja; i++) {delete niz[i]; niz[i]=nullptr;}
        for(int i(0),j(0); i<broj_prodaja; i++, j++){
            if(temp[i]!=nullptr) niz[j]=temp[i];
            else j--;
        }
        delete[] temp;
    }
    broj_prodaja-=brojac;
}

void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const{
    int vel(DajBrojProdajaNaDatum(datum));
    Prodaja **temp(temp=new Prodaja *[vel]);
    for(int i(0), j(0); i<broj_prodaja; i++,j++){
        if(ProvjeraDatuma(datum, niz[i]->DajDatumProdaje())) temp[i]=niz[i];
    }
    std::sort(temp,temp+vel, [](Prodaja *p1, Prodaja *p2){return p1->DajImeAgenta()<p2->DajImeAgenta();} );
    for(int i(0); i<vel; i++){
        temp[i]->Ispisi();
        std::cout<<std::endl;
    }
    delete[] temp;
}

void Prodaje::IspisiSveProdaje() const{
    Prodaja **temp(new Prodaja *[broj_prodaja]);
    for(int i(0); i<broj_prodaja; i++) temp[i]=niz[i];
    
    std::sort(temp, temp+broj_prodaja, [](Prodaja *p1, Prodaja *p2)
                                        {
                                            if(ProdatPrije(*p1,*p2)==ProdatPrije(*p2,*p1)) return p1->DajImeKupca()<p2->DajImeKupca();
                                            return ProdatPrije(*p1,*p2);
                                        });
    for(int i(0); i<broj_prodaja; i++){
        temp[i]->Ispisi();
        std::cout<<std::endl;
    }
    delete[] temp;
}


int main ()
{ 
    std::cout<<".";
	return 0;
}