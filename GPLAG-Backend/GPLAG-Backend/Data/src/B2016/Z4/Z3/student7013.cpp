/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>



class Datum{
    int dan;
    int mjesec;
    int godina;
    
    public:
    Datum(int dan, int mjesec, int godina);
    void Postavi(int dan, int mjesec, int godina);
    int DajDan() const;
    int DajMjesec() const;
    int DajGodinu() const;
    void Ispisi() const;
};



class Kupac{
    std::string ime_i_prezime;
    Datum datum_rodjenja;
    
    public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    std::string DajImePrezime() const;
    Datum DajDatumRodjenja() const;
    void Ispisi() const;
};




class Stan{
    std::string adresa;
    int sprat;
    int broj_soba;
    bool namjesten;
    double kvadratura;
    
    public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
    std::string DajAdresu() const;
    int DajSprat() const;
    int DajBrojSoba() const;
    bool DajNamjesten() const;
    double DajKvadraturu() const;
    void Ispisi() const;
};





class Prodaja{
    std::string ime_agenta_prodaje;
    double cijena_stana;
    Datum datum_prodaje;
    Kupac kupac_stana;
    Stan kupljeni_stan;
    
    
    
    public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,
    int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
    std::string &ime_kupca, const Datum &datum_rodjenja_kupca,
    const std::string &adresa_stana, int sprat_stana, int broj_soba,
    bool namjesten_stan, double broj_kvadrata);
    void PromijeniKupca(const Kupac &novi_kupac);
    void PromijeniStan(const Stan &novi_stan);
    void PromijeniDatumKupovine(const Datum &novi_datum);
    void PromijeniCijenuProdaje(const double &nova_cijena);
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImeAgenta() const { return ime_agenta_prodaje; }
    std::string DajImeKupca() const { return kupac_stana.DajImePrezime(); }
    Datum DajDatumProdaje() const { return datum_prodaje; }
    double DajCijenuStana() const { return cijena_stana; }
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
    void Ispisi() const;
};





class Prodaje{
    int ukupni_broj_prodaja;
    Prodaja** glavni_pok;
    int broj_prodaja;
    
    public:
    explicit Prodaje(int max_broj_prodaja);
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
    ~Prodaje();
    Prodaje(const Prodaje &prodaje);
    Prodaje(Prodaje &&prodaje);
    Prodaje &operator =(const Prodaje &prodaje);
    Prodaje &operator =(Prodaje &&prodaje);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje,
    double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, int dan_prodaje,
    int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
    const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,
    int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void RegistrirajProdaju(Prodaja *prodaja);
    int DajBrojProdaja() const { return broj_prodaja; }
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









//Klasa Datum
Datum::Datum(int dan, int mjesec, int godina){
    Postavi(dan, mjesec, godina);
}



void Datum::Postavi(int dan, int mjesec, int godina){
    if(mjesec<1 || mjesec>12){
        throw std::domain_error("Neispravan datum");
    }
     int februar=28;
    if((godina%4==0)||(godina%100==0 && godina%400==0)){
        februar=29;
    }
    std::vector<int> br_dana {31,februar,31,30,31,30,31,31,30,31,30,31};
    if(dan>br_dana[mjesec-1] || dan<1){
        throw std::domain_error("Neispravan datum");
    }
    this->dan=dan;
    this->mjesec=mjesec;
    this->godina=godina;
}


int Datum::DajDan() const{
    return dan;
}

int Datum::DajMjesec() const{
    return mjesec;
}

int Datum::DajGodinu() const{
    return godina;
}



void Datum::Ispisi() const{
    std::cout<<DajDan()<<"/"<<DajMjesec()<<"/"<<DajGodinu()<<std::endl;
}










//Klasa Kupac
Kupac::Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja)
    : datum_rodjenja(datum_rodjenja.DajDan(), datum_rodjenja.DajMjesec(), datum_rodjenja.DajGodinu())
{
    this->ime_i_prezime = ime_i_prezime;
    //this->datum_rodjenja = Datum(datum_rodjenja.DajDan(), datum_rodjenja.DajMjesec(), datum_rodjenja.DajGodinu());
}





void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja){
    for(int i{}; i<ime_i_prezime.length(); i++){
        if((ime_i_prezime[i]<'A' || (ime_i_prezime[i]>'Z' && ime_i_prezime[i]<'a')) || ime_i_prezime[i]>'z'
            || ime_i_prezime[i]==' ' || ime_i_prezime[i]=='-' || ime_i_prezime[i]=='\''){
            throw std::domain_error("Neispravno ime i prezime");
        }
    }
    
    this->datum_rodjenja.Postavi(datum_rodjenja.DajDan(), datum_rodjenja.DajMjesec(), datum_rodjenja.DajGodinu());
    
        this->ime_i_prezime=ime_i_prezime;
        this->datum_rodjenja=datum_rodjenja;
}





std::string Kupac::DajImePrezime() const{
    return ime_i_prezime;
}



Datum Kupac::DajDatumRodjenja() const{
    return datum_rodjenja;
}








void Kupac::Ispisi() const{
    std::cout << ime_i_prezime;
    std::cout<<" (";
    datum_rodjenja.Ispisi();
    std::cout<<")"<<std::endl;
}











//Klasa Stan
void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
    for(int i{}; i<adresa.length()-1; i++){
        if(adresa[i]=='-' && adresa[i+1]<'0'){
            throw std::domain_error("Neispravan unos podataka");
        }
    }
    if(sprat<0 || broj_soba<0 || kvadratura<0){
        throw std::domain_error("Neispravan unos podataka");
    }
    this->adresa=adresa;
    this->sprat=sprat;
    this->broj_soba=broj_soba;
    this->namjesten=namjesten;
    this->kvadratura=kvadratura;
}







Stan::Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
    Postavi(adresa, sprat, broj_soba, namjesten, kvadratura);
}





std::string Stan::DajAdresu() const{
    return adresa;
}



int Stan::DajSprat() const{
    return sprat;
}


int Stan::DajBrojSoba() const{
    return broj_soba;
}


bool Stan::DajNamjesten() const{
    return namjesten;
}


double Stan::DajKvadraturu() const{
    return kvadratura;
}




void Stan::Ispisi() const{
    if(namjesten==1){
        if(DajBrojSoba()==1 || (DajBrojSoba()%10==1 && DajBrojSoba()!=11)){
        std::cout<<"Stan se nalazi na adresi "<<DajAdresu()<<" na "<<DajSprat()<<". spratu i ima "<<DajBrojSoba()<<" sobu."<<std::endl;
        std::cout<<"Kvadratura stana je "<<DajKvadraturu()<<" (m^2) i stan je namjesten."<<std::endl;
        }
        else if((DajBrojSoba()==2 || (DajBrojSoba()%10==2 && DajBrojSoba()!=12)) ||
                 (DajBrojSoba()==3 || (DajBrojSoba()%10==3 && DajBrojSoba()!=13)) ||
                 (DajBrojSoba()==4 || (DajBrojSoba()%10==4 && DajBrojSoba()!=14))){
            std::cout<<"Stan se nalazi na adresi "<<DajAdresu()<<" na "<<DajSprat()<<". spratu i ima "<<DajBrojSoba()<<" sobe."<<std::endl;
            std::cout<<"Kvadratura stana je "<<DajKvadraturu()<<" (m^2) i stan je namjesten."<<std::endl;
        }
        else{
            std::cout<<"Stan se nalazi na adresi "<<DajAdresu()<<" na "<<DajSprat()<<". spratu i ima "<<DajBrojSoba()<<" soba."<<std::endl;
            std::cout<<"Kvadratura stana je "<<DajKvadraturu()<<" (m^2) i stan je namjesten."<<std::endl;
        }
    }
    
    if(namjesten==0){
        if(DajBrojSoba()==1 || (DajBrojSoba()%10==1 && DajBrojSoba()!=11)){
        std::cout<<"Stan se nalazi na adresi "<<DajAdresu()<<" na "<<DajSprat()<<". spratu i ima "<<DajBrojSoba()<<" sobu."<<std::endl;
        std::cout<<"Kvadratura stana je "<<DajKvadraturu()<<" (m^2) i stan nije namjesten."<<std::endl;
        }
        else if((DajBrojSoba()==2 || (DajBrojSoba()%10==2 && DajBrojSoba()!=12)) ||
                 (DajBrojSoba()==3 || (DajBrojSoba()%10==3 && DajBrojSoba()!=13)) ||
                 (DajBrojSoba()==4 || (DajBrojSoba()%10==4 && DajBrojSoba()!=14))){
            std::cout<<"Stan se nalazi na adresi "<<DajAdresu()<<" na "<<DajSprat()<<". spratu i ima "<<DajBrojSoba()<<" sobe."<<std::endl;
            std::cout<<"Kvadratura stana je "<<DajKvadraturu()<<" (m^2) i stan nije namjesten."<<std::endl;
        }
        else{
            std::cout<<"Stan se nalazi na adresi "<<DajAdresu()<<" na "<<DajSprat()<<". spratu i ima "<<DajBrojSoba()<<" soba."<<std::endl;
            std::cout<<"Kvadratura stana je "<<DajKvadraturu()<<" (m^2) i stan nije namjesten."<<std::endl;
        }
    }
}








//Klasa Prodaja
Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, 
            const Kupac &kupac_stana, const Stan &kupljeni_stan)
    : datum_prodaje(datum_prodaje.DajDan(), datum_prodaje.DajMjesec(), datum_prodaje.DajGodinu()),
      kupac_stana(kupac_stana.DajImePrezime(), kupac_stana.DajDatumRodjenja()),
      kupljeni_stan(kupljeni_stan.DajAdresu(), kupljeni_stan.DajSprat(), kupljeni_stan.DajBrojSoba(), 
            kupljeni_stan.DajNamjesten(), kupljeni_stan.DajKvadraturu())
{
    for(int i{}; i<ime_agenta_prodaje.length()-1; i++){
        if(ime_agenta_prodaje[i]<'A' || (ime_agenta_prodaje[i]>'Z' && ime_agenta_prodaje[i]<'a') || ime_agenta_prodaje[i]>'z' || ime_agenta_prodaje[i]==' ' || ime_agenta_prodaje[i]=='-' || ime_agenta_prodaje[i]=='\''){
            throw std::domain_error("Neispravno ime i prezime");
        }
    }
    if(cijena_stana<0){
        throw std::domain_error("Neispravan unos podataka");
    }
    
    //this->datum_prodaje.Postavi(datum_prodaje.DajDan(), datum_prodaje.DajMjesec(), datum_prodaje.DajGodinu());
    //this->kupac_stan = Stan(kupac_stana.DajImePrezime(), kupac_stana.DajDatumRodjenja());
    //this->kupljeni_stan.Postavi(kupljeni_stan.DajAdresu(), kupljeni_stan.DajSprat(), kupljeni_stan.DajBrojSoba(), 
      //      kupljeni_stan.DajNamjesten(), kupljeni_stan.DajKvadraturu());
    this->ime_agenta_prodaje=ime_agenta_prodaje;
    this->cijena_stana=cijena_stana;
}








Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,
    int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
    std::string &ime_kupca, const Datum &datum_rodjenja_kupca,
    const std::string &adresa_stana, int sprat_stana, int broj_soba,
    bool namjesten_stan, double broj_kvadrata) :
        datum_prodaje(dan_prodaje, mjesec_prodaje, godina_prodaje), 
        kupac_stana(ime_kupca, datum_rodjenja_kupca), 
        kupljeni_stan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata)
{
        
        if(cijena_stana<0){
        throw std::domain_error("Neispravan unos podataka");
    }
    
    //this->datum_prodaje.Postavi(dan_prodaje, mjesec_prodaje, godina_prodaje);
    //this->kupac_stana.Postavi(ime_kupca, datum_rodjenja_kupca);
    //this->kupljeni_stan.Postavi(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata);
    this->ime_agenta_prodaje = ime_agenta_prodaje;
    this->cijena_stana = cijena_stana;
    
    
}
    
    
    
    
    
    
    
    
    
    
void Prodaja::PromijeniKupca(const Kupac &novi_kupac){
    kupac_stana.Postavi(novi_kupac.DajImePrezime(), novi_kupac.DajDatumRodjenja());
    
} 




void Prodaja::PromijeniStan(const Stan &novi_stan){
    kupljeni_stan.Postavi(novi_stan.DajAdresu(), novi_stan.DajSprat(), novi_stan.DajBrojSoba(),
        novi_stan.DajNamjesten(), novi_stan.DajKvadraturu());
}








void Prodaja::PromijeniDatumKupovine(const Datum &novi_datum){
    datum_prodaje.Postavi(novi_datum.DajDan(), novi_datum.DajMjesec(), novi_datum.DajGodinu());
}






void Prodaja::PromijeniCijenuProdaje(const double &nova_cijena){
    if(nova_cijena<0){
        throw std::domain_error("Neispravan unos podataka");
    }
    this->cijena_stana=nova_cijena;
}







void Prodaja::PomjeriDanUnaprijed(){
    int novi_dan_prodaje=DajDatumProdaje().DajDan()+1;
    int novi_mjesec_prodaje=DajDatumProdaje().DajMjesec();
    int nova_godina_prodaje=DajDatumProdaje().DajGodinu();
    
    int februar=28;
    if((nova_godina_prodaje%4==0)||(nova_godina_prodaje%100==0 && nova_godina_prodaje%400==0)){
        februar=29;
    }
    std::vector<int> br_dana {31,februar,31,30,31,30,31,31,30,31,30,31};
    if(novi_dan_prodaje>br_dana[novi_mjesec_prodaje-1]){
        if(novi_mjesec_prodaje==12){
            novi_dan_prodaje=1;
            novi_mjesec_prodaje=1;
            nova_godina_prodaje++;
        }
        else novi_mjesec_prodaje++;
    }
    datum_prodaje.Postavi(novi_dan_prodaje, novi_mjesec_prodaje, nova_godina_prodaje);
}

void Prodaja::PomjeriDanUnazad(){
    int novi_dan_prodaje=DajDatumProdaje().DajDan()-1;
    int novi_mjesec_prodaje=DajDatumProdaje().DajMjesec();
    int nova_godina_prodaje=DajDatumProdaje().DajGodinu();
    
    int februar=28;
    if((nova_godina_prodaje%4==0)||(nova_godina_prodaje%100==0 && nova_godina_prodaje%400==0)){
        februar=29;
    }
    std::vector<int> br_dana {31,februar,31,30,31,30,31,31,30,31,30,31};
    if(novi_dan_prodaje<1){
        novi_mjesec_prodaje--;
        if(novi_mjesec_prodaje == 0 ) novi_mjesec_prodaje = 12, nova_godina_prodaje--;
        novi_dan_prodaje = br_dana[novi_mjesec_prodaje-1];
    }
    datum_prodaje.Postavi(novi_dan_prodaje, novi_mjesec_prodaje, nova_godina_prodaje);
}





bool ProdatPrije(const Prodaja &p1, const Prodaja &p2){
    if(p1.DajDatumProdaje().DajGodinu()==p2.DajDatumProdaje().DajGodinu()){
        if(p1.DajDatumProdaje().DajMjesec()==p2.DajDatumProdaje().DajMjesec()){
            return p1.DajDatumProdaje().DajDan()<p2.DajDatumProdaje().DajDan();
        }
        return p1.DajDatumProdaje().DajMjesec()<p2.DajDatumProdaje().DajMjesec();
    }
    return p1.DajDatumProdaje().DajGodinu()<p2.DajDatumProdaje().DajGodinu();
}







bool SkupljiStan(const Prodaja &p1, const Prodaja &p2){
    return p1.DajCijenuStana()>p2.DajCijenuStana();
}













//Klasa Prodaje
Prodaje::Prodaje(int max_broj_prodaja) : ukupni_broj_prodaja(max_broj_prodaja), broj_prodaja(0), glavni_pok(nullptr){
    try{
        glavni_pok=new Prodaja* [ukupni_broj_prodaja];
        for(int i{}; i<ukupni_broj_prodaja; i++)
            glavni_pok[i]=nullptr;
    }
    catch(...){
        delete [] glavni_pok;
        glavni_pok=nullptr;
        std::bad_alloc e;
        throw e;
    }
}







Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja) : ukupni_broj_prodaja(spisak_prodaja.size()), broj_prodaja(spisak_prodaja.size()), glavni_pok(nullptr){
    try{
        glavni_pok=new Prodaja* [ukupni_broj_prodaja];
        for(int i{}; i<ukupni_broj_prodaja; i++)
            glavni_pok[i]=nullptr;
    }
    catch(...){
        delete [] glavni_pok;
        glavni_pok=nullptr;
        std::bad_alloc e;
        throw e;
    }
    auto it=spisak_prodaja.begin();
    try{
        for(int i{}; i<broj_prodaja; i++)
            glavni_pok[i]=new Prodaja(*it++);
    }
    catch(...){
        for(int i{}; i<ukupni_broj_prodaja; i++)
            delete glavni_pok[i];
        delete [] glavni_pok;
        glavni_pok=nullptr;
        std::bad_alloc e;
        throw e;
    }
}








Prodaje::~Prodaje(){
    for(int i{}; i<ukupni_broj_prodaja; i++)
        delete glavni_pok[i];
    delete [] glavni_pok;
    glavni_pok=nullptr;
}






Prodaje::Prodaje(const Prodaje &prodaje) : ukupni_broj_prodaja(prodaje.ukupni_broj_prodaja), broj_prodaja(prodaje.broj_prodaja), glavni_pok(nullptr){
    try{
        glavni_pok=new Prodaja* [ukupni_broj_prodaja];
    for(int i{}; i<ukupni_broj_prodaja; i++)
        glavni_pok[i]=nullptr;
    }
    catch(...){
        delete [] glavni_pok;
        glavni_pok=nullptr;
        std::bad_alloc e;
        throw e;
    }
    try{
        for(int i{}; i<broj_prodaja; i++)
            glavni_pok[i]=new Prodaja(*prodaje.glavni_pok[i]);
    }
    catch(...){
        for(int i{}; i<ukupni_broj_prodaja; i++)
            delete glavni_pok[i];
        delete [] glavni_pok;
        glavni_pok=nullptr;
        std::bad_alloc e;
        throw e;
    }
}





Prodaje::Prodaje(Prodaje &&prodaje) : ukupni_broj_prodaja(prodaje.ukupni_broj_prodaja), broj_prodaja(prodaje.ukupni_broj_prodaja), glavni_pok(nullptr){
    glavni_pok=prodaje.glavni_pok;
    prodaje.glavni_pok=nullptr;
    prodaje.broj_prodaja=0;
    
}





Prodaje &Prodaje::operator =(const Prodaje &prodaje){
    if(ukupni_broj_prodaja!=prodaje.ukupni_broj_prodaja)
        throw std::logic_error("Nesaglasan ukupni broj prodaja");
    
    if(this==&prodaje){
        return *this;
    }
    
    for(int i{}; i<ukupni_broj_prodaja; i++)
        delete glavni_pok[i];
    delete [] glavni_pok;
    glavni_pok=nullptr;
    
    broj_prodaja=prodaje.broj_prodaja;
    
    try{
        glavni_pok=new Prodaja* [ukupni_broj_prodaja];
        for(int i{}; i<ukupni_broj_prodaja; i++)
            glavni_pok[i]=nullptr;
    }
    catch(...){
        delete [] glavni_pok;
        glavni_pok=nullptr;
        std::bad_alloc e;
        throw e;
    }
    
    try{
        for(int i{}; i<broj_prodaja; i++)
            glavni_pok[i]=new Prodaja(*prodaje.glavni_pok[i]);
    }
    catch(...){
        for(int i{}; i<ukupni_broj_prodaja; i++)
            delete glavni_pok[i];
        delete [] glavni_pok;
        glavni_pok=nullptr;
        std::bad_alloc e;
        throw e;
    }
    return *this;
}








Prodaje &Prodaje::operator =(Prodaje &&prodaje){
    if(ukupni_broj_prodaja=prodaje.ukupni_broj_prodaja)
        throw std::logic_error("Nesaglasan ukupni broj prodaja");
    
    if(this==&prodaje){
        return *this;
    }
    
    for(int i{}; i<ukupni_broj_prodaja; i++)
        delete glavni_pok[i];
    delete [] glavni_pok;
    
    glavni_pok=prodaje.glavni_pok;
    broj_prodaja=prodaje.broj_prodaja;
    
    prodaje.glavni_pok=nullptr;
    prodaje.broj_prodaja=0;
    
    return *this;
}









void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje,
    double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan){
        if(broj_prodaja==ukupni_broj_prodaja){
            throw std::range_error("Dostignut maksimalni broj prodaja");
        }
        glavni_pok[broj_prodaja]=new Prodaja(ime_agenta_prodaje, cijena_stana, datum_prodaje, kupac_stana, kupljeni_stan);
        broj_prodaja++;
    }
    
    
    
    
    

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, int dan_prodaje,
    int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
    const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,
    int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata){
        
        if(broj_prodaja==ukupni_broj_prodaja)
            throw std::range_error("Dostignut maksimalni broj prodaja");
            
        glavni_pok[broj_prodaja]=new Prodaja(ime_agenta_prodaje, glavni_pok[broj_prodaja]->DajCijenuStana(),
    dan_prodaje, mjesec_prodaje, godina_prodaje,
    ime_kupca, datum_rodjenja_kupca,
    adresa_stana, sprat_stana, broj_soba,
    namjesten_stan, broj_kvadrata);
        broj_prodaja++;
    }







void Prodaje::RegistrirajProdaju(Prodaja *prodaja){
    if(broj_prodaja==ukupni_broj_prodaja)
        throw std::range_error("Dostignut maksimalni broj prodaja");
    
    glavni_pok[broj_prodaja]=prodaja;
    broj_prodaja++;
}







//int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const{
    
    
    //int x=std::count_if(glavni_pok.begin(), glavni_pok.end(), [] (Prodaja *p1, Prodaja *p2){
        //if(p1->DajDatumProdaje()==p2->DajDatumProdaje())
            //return true;
       // return false;
   // });
    //return x;
//}




















int main(){
    
    return 0;
}

