#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <vector>
#include <initializer_list>
#include <algorithm>

class Datum{
    int dan, mjesec, godina;
    friend class Kupac;
    friend class Prodaja;
    friend class Prodaje;
public:
    Datum(int dan, int mjesec, int godina):dan(dan),mjesec(mjesec),godina(godina){if(dan>31 || dan<1 || mjesec<1 || mjesec>12 || godina<1) throw std::domain_error("Neispravan datum"); Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;}
    void Postavi(int dan, int mjesec, int godina){if(dan>31 || dan<1 || mjesec<1 || mjesec>12 || godina<1) throw std::domain_error("Neispravan datum"); Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;}
    int DajDan() const{return dan;}
    int DajMjesec() const {return mjesec;}
    int DajGodinu() const{return godina;}
    void Ispisi()const ;
};
void Datum::Ispisi()const {
    std::cout<<dan<<"/"<<mjesec<<"/"<<godina<<std::endl;
}

class Kupac{
    std::string ime_i_prezime;
    Datum datum;
    friend class Prodaja;
    friend class Prodaje;
public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja): datum(datum_rodjenja){ for(int i(0);i<ime_i_prezime.length();i++){
        if(!((ime_i_prezime[i]>='a' && ime_i_prezime[i]<='z') || (ime_i_prezime[i]>='A' && ime_i_prezime[i]<='Z') || ime_i_prezime[i]==' '))
        throw std::domain_error("Neispravno ime i prezime");
    }
    Kupac::ime_i_prezime=ime_i_prezime;
    datum=datum_rodjenja;}
    
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja){for(int i(0);i<ime_i_prezime.length();i++){
        if(!((ime_i_prezime[i]>='a' && ime_i_prezime[i]<='z') || (ime_i_prezime[i]>='A' && ime_i_prezime[i]<='Z') || ime_i_prezime[i]==' '))
        throw std::domain_error("Neispravno ime i prezime");
    }
    Kupac::ime_i_prezime=ime_i_prezime; datum=datum_rodjenja;}
    std::string DajImePrezime() const { return ime_i_prezime;}
    Datum DajDatumRodjenja() const {return datum;}
    void Ispisi() const;
};
void Kupac::Ispisi() const{
    std::cout<<DajImePrezime()<<" ("<<DajDatumRodjenja().dan<<"/"<<DajDatumRodjenja().mjesec<<"/"<<DajDatumRodjenja().godina<<")"<<std::endl;
}

class Stan{
    std::string adresa;
    int sprat;
    int broj_soba;
    bool namjesten;
    double kvadratura;
    friend class Prodaja;
    friend class Prodaje;

public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){if(sprat<0 || broj_soba<=0 || kvadratura<=0 || ((int)namjesten!=1 && (int)namjesten!=0)) throw std::domain_error("Neispravan unos podataka"); Stan::adresa=adresa;Stan::sprat=sprat; Stan::broj_soba=broj_soba; Stan::namjesten=namjesten; Stan::kvadratura=kvadratura;}
    void Postavi(const std::string &adresa, int sprat,int broj_soba, bool namjesten,double kvadratura){if(sprat<0 || broj_soba<=0 || kvadratura<=0) throw std::domain_error("Neispravan unos podataka"); Stan::adresa=adresa; Stan::sprat=sprat; Stan::broj_soba=broj_soba; Stan::namjesten=namjesten; Stan::kvadratura=kvadratura;}
    std::string DajAdresu() const{return adresa;}
    int DajSprat() const {return sprat;}
    int DajBrojSoba() const{return broj_soba;}
    bool DajNamjesten() const{return namjesten;}
    double DajKvadraturu() const{return kvadratura;}
    void Ispisi() const;
};

void Stan::Ispisi() const{
    if(DajBrojSoba()==1){
        if(DajNamjesten()==true){
            std::cout<<"Stan se nalazi na adresi "<<DajAdresu()<<" na "<<DajSprat()<<". spratu i ima "<<DajBrojSoba()<<" sobu.";
            std::cout<<" Kvadratura stana je "<<DajKvadraturu()<<" (m^2) i stan je namjesten."<<std::endl;
        }
        else{
            std::cout<<"Stan se nalazi na adresi "<<DajAdresu()<<" na "<<DajSprat()<<". spratu i ima "<<DajBrojSoba()<<" sobu.";
            std::cout<<" Kvadratura stana je "<<DajKvadraturu()<<" (m^2) i stan nije namjesten."<<std::endl;
        }
    }
    else if(DajBrojSoba()%10==2 || DajBrojSoba()%10==3 || DajBrojSoba()%10 ==4){
        if(DajNamjesten()==true){
            std::cout<<"Stan se nalazi na adresi "<<DajAdresu()<<" na "<<DajSprat()<<". spratu i ima "<<DajBrojSoba()<<" sobe.";
            std::cout<<" Kvadratura stana je "<<DajKvadraturu()<<" (m^2) i stan je namjesten."<<std::endl;
        }
        else{
            std::cout<<"Stan se nalazi na adresi "<<DajAdresu()<<" na "<<DajSprat()<<". spratu i ima "<<DajBrojSoba()<<" sobe.";
            std::cout<<" Kvadratura stana je "<<DajKvadraturu()<<" (m^2) i stan nije namjesten."<<std::endl;
        }
    }
    else{
        if(DajNamjesten()==true){
            std::cout<<"Stan se nalazi na adresi "<<DajAdresu()<<" na "<<DajSprat()<<". spratu i ima "<<DajBrojSoba()<<" soba.";
            std::cout<<" Kvadratura stana je "<<DajKvadraturu()<<" (m^2) i stan je namjesten."<<std::endl;
        }
        else{
            std::cout<<"Stan se nalazi na adresi "<<DajAdresu()<<" na "<<DajSprat()<<". spratu i ima "<<DajBrojSoba()<<" soba.";
            std::cout<<" Kvadratura stana je "<<DajKvadraturu()<<" (m^2) i stan nije namjesten."<<std::endl;
        }
    }
}

class Prodaja{
    std::string ime_agenta_prodaje;
    double cijena_stana;
    Datum datumprodaje;
    Kupac kupacstana;
    Stan kupljenistan;
    friend class Prodaje;
public:
    Prodaja(const std::string &ime_agenta_prodaje,double cijena_stana,const Datum &datum_prodaje,const Kupac &kupac_stana,const Stan &kupljeni_stan): datumprodaje(datum_prodaje),kupacstana(kupac_stana),kupljenistan(kupljeni_stan){
        if(cijena_stana<0) throw std::domain_error("Neispravna cijena");
        Prodaja::ime_agenta_prodaje=ime_agenta_prodaje; 
        Prodaja::cijena_stana=cijena_stana;
        datumprodaje=datum_prodaje;
        kupacstana=kupac_stana;
        kupljenistan=kupljeni_stan;}
    Prodaja(const std::string &ime_agenta_prodaje,double cijena_stana,int dan_prodaje, int mjesec_prodaje, int godina_prodaje,std::string &ime_kupca, const Datum &datum_rodjenja_kupca,const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata): datumprodaje(dan_prodaje,mjesec_prodaje,godina_prodaje),kupacstana(ime_kupca,datum_rodjenja_kupca),kupljenistan(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata){
        if(cijena_stana<0) throw std::domain_error("Neispravna cijena");
        Prodaja::ime_agenta_prodaje=ime_agenta_prodaje;
        Prodaja::cijena_stana=cijena_stana;
        datumprodaje.dan=dan_prodaje;
        datumprodaje.mjesec=mjesec_prodaje;
        datumprodaje.godina=godina_prodaje;
        kupacstana.ime_i_prezime=ime_kupca;
        kupacstana.datum=datum_rodjenja_kupca;
        kupljenistan.adresa=adresa_stana;
        kupljenistan.sprat=sprat_stana;
        kupljenistan.broj_soba=broj_soba;
        kupljenistan.namjesten=namjesten_stan;
        kupljenistan.kvadratura=broj_kvadrata;}
        
    void PromijeniKupca(const Kupac &novi_kupac){kupacstana=novi_kupac;}
    void PromijeniStan(const Stan &novi_stan){kupljenistan=novi_stan;}
    void PromijeniDatumKupovine(const Datum &novi_datum){datumprodaje=novi_datum;}
    void PromijeniCijenuProdaje(const double &nova_cijena){if(nova_cijena<0) throw std::domain_error("Neispravna cijena"); cijena_stana=nova_cijena;}   
    void PomjeriDanUnaprijed(){datumprodaje.dan+=1;}
    void PomjeriDanUnazad(){datumprodaje.dan-=1;}
    std::string DajImeAgenta()const {return ime_agenta_prodaje;}
    std::string DajImeKupca() const{return kupacstana.ime_i_prezime;}
    Datum DajDatumProdaje() const{return datumprodaje;}
    double DajCijenuStana() const{return cijena_stana;}
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
    void Ispisi() const;
};

void Prodaja::Ispisi() const{
    std::cout<<std::setw(32)<<std::left<<"Ime agenta:";
    std::cout<<Prodaja::DajImeAgenta()<<std::endl;
    std::cout<<std::setw(32)<<std::left<<"Ime kupca:";
    std::cout<<DajImeKupca();
    std::cout<<" ("<<kupacstana.datum.dan<<"/"<<kupacstana.datum.mjesec<<"/"<<kupacstana.datum.godina<<")"<<std::endl;
    std::cout<<std::setw(32)<<std::left<<"Zakazani datum prodaje: ";
    std::cout<<DajDatumProdaje().DajDan()<<"/"<<DajDatumProdaje().DajMjesec()<<"/"<<DajDatumProdaje().DajGodinu()<<std::endl;
    std::cout<<std::setw(32)<<std::left<<"Cijena stana: ";
    std::cout<<DajCijenuStana()<<std::endl;
    std::cout<<std::setw(32)<<std::left<<"Informacije o stanu: "<<std::endl;
    if(kupljenistan.broj_soba==1){
        if(kupljenistan.DajNamjesten()==true){
            std::cout<<"Stan se nalazi na adresi "<<kupljenistan.DajAdresu()<<" na "<<kupljenistan.DajSprat()<<". spratu i ima "<<kupljenistan.DajBrojSoba()<<" sobu.";
            std::cout<<" Kvadratura stana je "<<kupljenistan.DajKvadraturu()<<" (m^2) i stan je namjesten."<<std::endl;
        }
        else{
            std::cout<<"Stan se nalazi na adresi "<<kupljenistan.DajAdresu()<<" na "<<kupljenistan.DajSprat()<<". spratu i ima "<<kupljenistan.DajBrojSoba()<<" sobu.";
            std::cout<<" Kvadratura stana je "<<kupljenistan.DajKvadraturu()<<" (m^2) i stan nije namjesten."<<std::endl;
        }
    }
    else if(kupljenistan.DajBrojSoba()%10 == 2 || kupljenistan.DajBrojSoba()%10 == 3 || kupljenistan.DajBrojSoba()%10 ==4 ){
        std::cout<<"Stan se nalazi na adresi "<<kupljenistan.DajAdresu()<<" na "<<kupljenistan.DajSprat()<<". spratu i ima "<<kupljenistan.DajBrojSoba()<<" sobe.";
        if(kupljenistan.DajNamjesten()==true) std::cout<<" Kvadratura stana je "<<kupljenistan.DajKvadraturu()<<" (m^2) i stan je namjesten."<<std::endl;
        else std::cout<<" Kvadratura stana je "<<kupljenistan.DajKvadraturu()<<" (m^2) i stan nije namjesten."<<std::endl;
    }
    else {
        std::cout<<"Stan se nalazi na adresi "<<kupljenistan.DajAdresu()<<" na "<<kupljenistan.DajSprat()<<". spratu i ima "<<kupljenistan.DajBrojSoba()<<" soba.";
        if(kupljenistan.DajNamjesten()==true) std::cout<<" Kvadratura stana je "<<kupljenistan.DajKvadraturu()<<" (m^2) i stan je namjesten."<<std::endl;
        else std::cout<<" Kvadratura stana je "<<kupljenistan.DajKvadraturu()<<" (m^2) i stan nije namjesten."<<std::endl;
    }
}

bool ProdatPrije(const Prodaja &p1, const Prodaja &p2){
    if(p1.DajDatumProdaje().DajDan()<p2.DajDatumProdaje().DajDan() && p1.DajDatumProdaje().DajMjesec()<=p2.DajDatumProdaje().DajMjesec() && p1.DajDatumProdaje().DajGodinu()<=p2.DajDatumProdaje().DajGodinu()) return true;
    else if(p1.DajDatumProdaje().DajDan()<=p2.DajDatumProdaje().DajDan() && p1.DajDatumProdaje().DajMjesec()<p2.DajDatumProdaje().DajMjesec() && p1.DajDatumProdaje().DajGodinu()<=p2.DajDatumProdaje().DajGodinu()) return true;
    else if(p1.DajDatumProdaje().DajDan()<=p2.DajDatumProdaje().DajDan() && p1.DajDatumProdaje().DajMjesec()<=p2.DajDatumProdaje().DajMjesec() && p1.DajDatumProdaje().DajGodinu()<p2.DajDatumProdaje().DajGodinu()) return true;
    else return false;
}
bool SkupljiStan(const Prodaja &p1, const Prodaja &p2){
    if(p1.DajCijenuStana()>p2.DajCijenuStana()) return true;
    else return false;
}

class Prodaje{
    int maxbrojprodaja;
    int broj_prodaja;
    static int brojacnadatum;
    static int brojacnaagenta;
    Prodaja **prodaje;
    std::string ime_agenta_prodaje;
    double cijena_stana;
    Datum datumprodaje;
    Kupac kupacstana;
    Stan kupljenistan;
public:
       explicit Prodaje(int max_broj_prodaja): maxbrojprodaja(max_broj_prodaja),datumprodaje(1,1,1),kupacstana("",datumprodaje),kupljenistan("",1,1,true,1),prodaje(nullptr){ 
           maxbrojprodaja=max_broj_prodaja;
            prodaje=new Prodaja*[maxbrojprodaja];
            for(int i(0);i<maxbrojprodaja;i++) prodaje[i]=nullptr;
    }
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja): datumprodaje(1,1,1),kupacstana("",datumprodaje),kupljenistan("",1,1,true,1),broj_prodaja(0),maxbrojprodaja(spisak_prodaja.size()){
            prodaje=new Prodaja*[maxbrojprodaja];
            for(int i(0);i<maxbrojprodaja;i++) prodaje[i]=nullptr;
            for(auto it1=spisak_prodaja.begin();it1!=spisak_prodaja.end();it1++){
                prodaje[broj_prodaja]=new Prodaja(*it1);
                broj_prodaja++;
            }
    }
    ~Prodaje(){if(prodaje==nullptr) return; 
                for(int i(0);i<broj_prodaja;i++) delete prodaje[i]; 
                delete [] prodaje; 
                prodaje=nullptr; 
                broj_prodaja=0;}
   // Prodaje (const Prodaje &prodaje);
    //Prodaje (Prodaje &&prodaje);
    //Prodaje &operator = (const Prodaje &prodaje);
    //Prodaje &operator = (Prodaje &&prodaje);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana,const Datum &datum_prodaje,const Kupac &kupac_stana,const Stan &kupljeni_stan){
        if(broj_prodaja>maxbrojprodaja) throw std::range_error("Dostignut maksimalni broj prodaja");
        datumprodaje= datum_prodaje;
        kupacstana= kupac_stana;
        kupljenistan=kupljeni_stan;
        Prodaje::ime_agenta_prodaje=ime_agenta_prodaje; 
        Prodaje::cijena_stana=cijena_stana; 
        datumprodaje=datum_prodaje; 
        kupacstana=kupac_stana; 
        kupljenistan=kupljeni_stan;
        broj_prodaja++;
        
    }
        void RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana,int dan_prodaje,int mjesec_prodaje,int godina_prodaje,std::string &ime_kupca,Datum &datum_rodjenja_kupca, const std::string &adresa_stana,int sprat_stana, int broj_soba,bool namjesten_stan,double broj_kvadrata){
        if(broj_prodaja>maxbrojprodaja) throw std::range_error ("Dostignut maksimalni broj prodaja");
        Prodaje::ime_agenta_prodaje=ime_agenta_prodaje;
        Prodaje::cijena_stana=cijena_stana;
        datumprodaje.dan=dan_prodaje; 
        datumprodaje.mjesec=mjesec_prodaje;
        datumprodaje.godina=godina_prodaje; 
        kupacstana.ime_i_prezime=ime_kupca;
        kupacstana.datum=datum_rodjenja_kupca;
        kupljenistan.adresa=adresa_stana; 
        kupljenistan.sprat=sprat_stana; 
        kupljenistan.broj_soba=broj_soba; 
        kupljenistan.namjesten=namjesten_stan; 
        kupljenistan.kvadratura=broj_kvadrata;
        broj_prodaja++;
        
        }
    void RegistrirajProdaju(Prodaja *prodaja){if(broj_prodaja>maxbrojprodaja) throw std::range_error("Dostignut maksimalni broj prodaja");}
    int DajBrojProdaja() const{return broj_prodaja;}
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
int Prodaje::DajBrojProdajaNaDatum(const Datum &datum)const{
    if(broj_prodaja==0) throw std::domain_error("Nema registriranih prodaja");
    return std::count_if(prodaje,prodaje+broj_prodaja,[datum](Prodaja *prodaja){
        return (prodaja->DajDatumProdaje().DajDan()==datum.DajDan() && prodaja->DajDatumProdaje().DajMjesec()==datum.DajMjesec() && prodaja->DajDatumProdaje().DajGodinu()==datum.DajGodinu());
    });
}
int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const{
    if (broj_prodaja==0) throw std::domain_error("Nema registriranih prodaja");
    return std::count_if(prodaje,prodaje+broj_prodaja,[ime_agenta](Prodaja *prodaja){
        return (prodaja->DajImeAgenta()==ime_agenta);
    });
}

Prodaja &Prodaje::DajNajranijuProdaju(){
    if(broj_prodaja==0) throw std::domain_error("Nema registriranih prodaja");
    auto najranija=std::min_element(prodaje,prodaje+broj_prodaja,[](Prodaja *p1, Prodaja *p2){
        return ProdatPrije(*p1,*p2);
    });
    
    return **najranija;
}
Prodaja Prodaje::DajNajranijuProdaju() const{
    if(broj_prodaja==0) throw std::domain_error("Nema registriranih prodaja");
    auto najranija=std::min_element(prodaje,prodaje+broj_prodaja,[](Prodaja *p1, Prodaja *p2){
        return ProdatPrije(*p1,*p2);
    });
    
    return **najranija;
}
Prodaja &Prodaje::DajNajskupljuProdaju(){
    if(broj_prodaja==0) throw std::domain_error("Nema registriranih prodaja");
    auto najskuplja=std::max_element(prodaje,prodaje+broj_prodaja,[](Prodaja *p1, Prodaja *p2){
        return SkupljiStan(*p1,*p2);
    });
    return **najskuplja;
}
Prodaja Prodaje::DajNajskupljuProdaju()const{
    if(broj_prodaja==0) throw std::domain_error("Nema registriranih prodaja");
    auto najskuplja=std::max_element(prodaje,prodaje+broj_prodaja,[](Prodaja *p1, Prodaja *p2){
        return SkupljiStan(*p1,*p2);
    });
    return **najskuplja;
}
void Prodaje::IsprazniKolekciju(){
    for(int i(0);i<broj_prodaja;i++) delete prodaje[i];
    delete [] prodaje;
    prodaje=nullptr;
}

void Prodaje::ObrisiNajranijuProdaju(){
    if(broj_prodaja==0) throw std::range_error("Prazna kolekcija");
    auto najranija(DajNajranijuProdaju());
    for(int i(0);i<broj_prodaja;i++){
        if(prodaje[i]->DajDatumProdaje().DajDan() == najranija.DajDatumProdaje().DajDan() && prodaje[i]->DajDatumProdaje().DajMjesec() == najranija.DajDatumProdaje().DajMjesec() && prodaje[i]->DajDatumProdaje().DajGodinu() == najranija.DajDatumProdaje().DajGodinu()){
            delete prodaje[i];
            int j=i+1;
            while(j<broj_prodaja){
                prodaje[j-1]=prodaje[j];
                j++;
            }
            broj_prodaja--;
        }
    }
    
}
void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta){
    if(broj_prodaja==0) throw std::range_error("Prazna kolekcija");
    for(int i(0);i<broj_prodaja;i++){
        if(prodaje[i]->DajImeAgenta()==ime_agenta){
            delete prodaje[i];
            int j=i+1;
            while(j<broj_prodaja){
                prodaje[j-1]=prodaje[j];
            }
            broj_prodaja--;
            i--;
        }
    }
}
void Prodaje::ObrisiProdajeNaDatum(const Datum &datum){
    if(broj_prodaja==0) throw std::range_error("Prazna kolekcija");
    for(int i(0);i<broj_prodaja;i++){
        if(prodaje[i]->DajDatumProdaje().DajDan()==datum.DajDan() && prodaje[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec() && prodaje[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu()){
            delete prodaje[i];
            int j=i+1;
            while(j<broj_prodaja){
                prodaje[j-1]=prodaje[j];
            }
            i--;
            broj_prodaja--;
        }
    }
}
void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const{
    for(int i(0);i<broj_prodaja;i++){
        if(prodaje[i]->DajDatumProdaje().DajDan()==datum.DajDan() && prodaje[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec() && prodaje[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu()){
            std::cout<<prodaje[i]->DajDatumProdaje().DajDan()<<"/"<<prodaje[i]->DajDatumProdaje().DajMjesec()<<"/"<<prodaje[i]->DajDatumProdaje().DajGodinu()<<std::endl;
        }
    }
}
void Prodaje::IspisiSveProdaje() const{
    for(int i(0);i<broj_prodaja;i++){
        std::cout<<prodaje[i]<<std::endl;
    }
}

int main ()
{  
    std::string adresa;
    int sprat;
    int brsoba;
    bool namjesten;
    int namjestencifra;
    double kvadratura;
    int dan,mjesec,godina;
    double cijena;
    int danprodaje,mjesecprodaje,godinaprodaje;
    std::string ime_i_prezime_kupca;
    std::string ime_i_prezime_agenta;
    int opcija(0);
    int opcija1(0);
    std::vector<Stan> vektorstanova;
    std::vector<Kupac> vektorkupaca;
    std::vector<Prodaja> vektorprodaja;
    std::cout<<"Dobrodosli!"<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    jodja:
    std::cout<<"Izaberite opciju:"<<std::endl;
    std::cout<<" 0 - kraj"<<std::endl<<" 1 - uredjivanje stanova"<<std::endl<<" 2 - uredjivanje kupaca"<<std::endl<<" 3 - uredjivanje prodaja"<<std::endl;
    std::cin>>opcija;
    if(opcija==0) { std::cout<<std::endl; std::cout<<std::endl; std::cout<<"Dovidjenja!"; return  0;}
    if(opcija==1){
        for(;;){
        jodja2:
        std::cout<<"Izaberite opciju:"<<std::endl;
        std::cout<<" 0 - nazad"<<std::endl<<" 1 - dodavanje stana"<<std::endl<<" 2 - uredjivanje stanova"<<std::endl<<" 3 - ispis svih stanova"<<std::endl<<" 4 - kraj"<<std::endl;
        std::cin>>opcija1;
        
        if(opcija1==0) goto jodja;
        else if(opcija1==4) return 0;
        else if(opcija1==1){
            jodja1:
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            std::cout<<"Unesite adresu: ";
            std::getline(std::cin,adresa);
            std::cout<<"Unesite sprat: ";
            std::cin>>sprat;
            std::cout<<"Unesite broj soba: ";
            std::cin>>brsoba;
            std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
            std::cin>>namjestencifra;
            if(namjestencifra==1) namjesten=true;
            if(namjestencifra==0) namjesten=false;
            //std::cin>>std::ws;
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            std::cout<<"Unesite kvadraturu: ";
            std::cin>>kvadratura;
            try{
                if(namjestencifra!=1 && namjestencifra!=0) throw std::domain_error("Neispravan unos");
                Stan stan(adresa,sprat,brsoba,namjesten,kvadratura);
                vektorstanova.push_back(stan);
                std::cout<<"Stan je uspjesno dodan!"<<std::endl;
            }
            catch(std::domain_error e){
                std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                goto jodja1;
            }
            
        }
        else if(opcija1==3){
        for(int i(0);i<vektorstanova.size();i++){
            std::cout<<i+1<<". ";
            vektorstanova[i].Ispisi();
                }   
            }
        else if(opcija1==2){
            int opcija2;
            std::cout<<"Odaberite stan. Dostupni stanovi su:"<<std::endl;
            for(int i(0);i<vektorstanova.size();i++){
                std::cout<<i+1<<" - ";
                vektorstanova[i].Ispisi();
            }
            int odabrani_stan;
            std::cin>>odabrani_stan;
            std::cout<<"Odaberite polje koje zelite urediti:"<<std::endl;
            std::cout<<" 0 - nazad"<<std::endl<<" 1 - adresa"<<std::endl<<" 2 - sprat"<<std::endl<<" 3 - broj soba"<<std::endl<<" 4 - da li je stan namjesten"<<std::endl<<" 5 - kvadratura"<<std::endl<<" 6 - sve"<<std::endl;
            std::cin>>opcija2;
            if(opcija2==0) goto jodja2;
            else if(opcija2==1){
                std::string nova_adresa;
                std::cin.clear();
                std::cin.ignore(1000,'\n');
                ponovo_adresa:
                std::cout<<"Unesite adresu: ";
                std::getline(std::cin,nova_adresa);
                try{
                vektorstanova[odabrani_stan-1].Postavi(nova_adresa,sprat,brsoba,namjesten,kvadratura);
                adresa=nova_adresa;
                std::cout<<"Stan je uspjesno izmijenjen!"<<std::endl;
                }
                catch(std::domain_error e){
                    std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet.";
                    std::cin.clear();
                    std::cin.ignore(1000,'\n');
                    goto ponovo_adresa;
                }
            }
            else if(opcija2==2){
                int novi_sprat;
                std::cin.clear();
                std::cin.ignore(1000,'\n');
                ponovo_sprat:
                std::cout<<"Unesite sprat: ";
                std::cin>>novi_sprat;
                try{
                vektorstanova[odabrani_stan-1].Postavi(adresa,novi_sprat,brsoba,namjesten,kvadratura);
                sprat=novi_sprat;
                std::cout<<"Stan uspjesno izmijenjen!"<<std::endl;
                }
                catch(std::domain_error e){
                    std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                    std::cin.clear();
                    std::cin.ignore(1000,'\n');
                    goto ponovo_sprat;
                    }
                }
            else if(opcija2==3){
                int novi_broj_soba;
                ponovo_sobe:
                std::cout<<"Unesite broj soba: ";
                std::cin>>novi_broj_soba;
                try{
                vektorstanova[odabrani_stan-1].Postavi(adresa,sprat,novi_broj_soba,namjesten,kvadratura);
                brsoba=novi_broj_soba;
                std::cout<<"Stan uspjesno izmijenjen!"<<std::endl;    
                }
                catch(std::domain_error e){
                    std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                    std::cin.clear();
                    std::cin.ignore(1000,'\n');
                    goto ponovo_sobe;
            }
            }
            else if(opcija2==4){
                bool novi_namjesten;
                int namjestenko;
                ponovo_namjesten:
                std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                std::cin>>namjestenko;
                try{
                    if(namjestenko!=1 && namjestenko!=0) throw std::domain_error("Neispravan unos podataka");
                    if(namjestenko==1) novi_namjesten=true;
                    if(namjestenko==0) novi_namjesten=false;
                    vektorstanova[odabrani_stan-1].Postavi(adresa,sprat,brsoba,novi_namjesten,kvadratura);
                    namjesten=novi_namjesten;
                    std::cout<<"Stan uspjesno izmijenjen!"<<std::endl;
                }
                catch(std::domain_error e){
                    std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                    std::cin.clear();
                    std::cin.ignore(1000,'\n');
                    goto ponovo_namjesten;
            }
            }
            else if(opcija2==5){
                double nova_kvadratura;
                ponovo_kvadratura:
                std::cout<<"Unesite kvadraturu: ";
                std::cin>>nova_kvadratura;
                try{
                    if(nova_kvadratura<0) throw std::domain_error("Neispravan unos podataka");
                    vektorstanova[odabrani_stan-1].Postavi(adresa,sprat,brsoba,namjesten,nova_kvadratura);
                    kvadratura=nova_kvadratura;
                    std::cout<<"Stan uspjesno izmijenjen!"<<std::endl;
                }
                catch(std::domain_error e){
                    std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                    std::cin.clear();
                    std::cin.ignore(1000,'\n');
                    goto ponovo_kvadratura;
                }
            }
            else if(opcija2==6){
                std::string nova_adresa;
                int novi_sprat;
                int novi_brsoba;
                bool novi_namjesten;
                double novi_kvadratura;
                novo_sve:
                std::cin.clear();
                std::cin.ignore(1000,'\n');
                std::cout<<"Unesite adresu: ";
                std::getline(std::cin,nova_adresa);
                std::cout<<"Unesite sprat: ";
                std::cin>>novi_sprat;
                std::cout<<"Unesite broj soba: ";
                std::cin>>novi_brsoba;
                std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                std::cin>>novi_namjesten;
                std::cin.clear();
                std::cin.ignore(1000,'\n');
                std::cout<<"Unesite kvadraturu: ";
                std::cin>>novi_kvadratura;
                try{
                    vektorstanova[odabrani_stan-1].Postavi(nova_adresa,novi_sprat,novi_brsoba,novi_namjesten,novi_kvadratura);
                    adresa=nova_adresa; sprat=novi_sprat; brsoba=novi_brsoba; namjesten=novi_namjesten; kvadratura=novi_kvadratura;
                    std::cout<<"Stan uspjesno izmijenjen!"<<std::endl;
                }
                catch(std::domain_error e){
                    std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet"<<std::endl;
                    goto novo_sve;
                }
            }
        }
        
    }}  //ovdje gotova za stan svasta nesto
    else if(opcija==2){
        for(;;){
            int opcija1;
            std::cout<<"Izaberite opciju:"<<std::endl;
            std::cout<<" 0 - nazad"<<std::endl<<" 1 - dodavanje kupca"<<std::endl<<" 2 - uredjivanje kupaca"<<std::endl<<" 3 - ispis svih kupaca"<<std::endl<<" 4 - kraj"<<std::endl;
            std::cin>>opcija1;
            if(opcija1==0) goto jodja;
            else if(opcija1==4) return 0;
            else if(opcija1==1){
                jodja4:
                char c1,c2;
                std::cin.clear();
                std::cin.ignore(1000,'\n');
                try{
                std::cout<<"Unesite ime i prezime kupca: ";
                std::getline(std::cin,ime_i_prezime_kupca);
                std::cout<<"Unesite datum rodjenja (formata d/m/g): ";
                std::cin>>dan;
                std::cin>>c1;
                if(c1!='/') throw std::domain_error("Neispravan unos podataka");
                std::cin>>mjesec;
                std::cin>>c2;
                if(c2!='/') throw std::domain_error("Neispravan unos podataka");
                std::cin>>godina;
                
                Datum datummrodjenja(dan,mjesec,godina);
                Kupac kupac(ime_i_prezime_kupca,datummrodjenja);
                vektorkupaca.push_back(kupac);
                std::cout<<"Kupac je uspjesno dodan!"<<std::endl;
                }
                catch(std::domain_error e){
                    std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                    goto jodja4;
                }
            
            }
            else if(opcija1==3){
                for(int i(0);i<vektorkupaca.size();i++){
                    vektorkupaca[i].Ispisi();
                }
            }
            else if(opcija1==2){
                std::cout<<"Odaberite kupca kojeg zelite urediti. Dostupni kupci su:"<<std::endl;
                for(int i(0);i<vektorkupaca.size();i++){
                    std::cout<<" "<<i+1<<" - ";
                    vektorkupaca[i].Ispisi();
                }
                int odabrani_kupac;
                std::cin>>odabrani_kupac;
                isponove:
                char c1,c2;
                std::cout<<"Unesite ime i prezime kupca: ";
                std::string novo_ime;
                std::cin.clear();
                std::cin.ignore(1000,'\n');
                std::getline(std::cin,novo_ime);
                std::cout<<"Unesite datum rodjenja (formata d/m/g):";
                try{
                int novi_dan,novi_mjesec,nova_godina;
                std::cin>>novi_dan;
                std::cin>>c1; if(c1!='/') throw std::domain_error("Neispravan unos podataka");
                std::cin>>novi_mjesec;
                std::cin>>c2; if(c2!='/') throw std::domain_error("Neispravan unos podataka");
                std::cin>>nova_godina;
                
                    Datum novidatum(novi_dan,novi_mjesec,nova_godina);
                    vektorkupaca[odabrani_kupac-1].Postavi(novo_ime,novidatum);
                    ime_i_prezime_kupca=novo_ime;
                    dan=novi_dan; mjesec=novi_mjesec; godina=nova_godina;
                    std::cout<<" Kupac je uspjesno izmijenjen!"<<std::endl;
                }
                catch(std::domain_error e){
                    std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                    goto isponove;
                }
                
            }
            
        }
    }
    else if(opcija==3){
        for(;;){
            int opcija1;
            jodjara:
            std::cout<<"Izaberite opciju:"<<std::endl;
            std::cout<<" 0 - nazad"<<std::endl<<" 1 - dodavanje prodaje"<<std::endl<<" 2 - uredjivanje prodaje"<<std::endl<<" 3 - ispis prodaja"<<std::endl<<" 4 - brisanje prodaja"<<std::endl<<" 5 - kraj"<<std::endl;
            std::cin>>opcija1;
            if(opcija1==0) goto jodja;
            else if(opcija1==5) return 0;
            else if(opcija1==1){
                int opcija2;
                jodjica:
                std::cout<<"Izaberite opciju:"<<std::endl;
                std::cout<<" 0 - nazad"<<std::endl<<" 1 - dodavanje potpuno nove prodaje"<<std::endl<<" 2 - dodavanje nove prodaje na osnovu arhive"<<std::endl<<" 3 - kraj"<<std::endl;
                std::cin>>opcija2;
                if(opcija2==0) goto jodjara;
                else if(opcija2==3) return 0;
                else if(opcija2==1){
                    ponovno:
                    char c1,c2,c3,c4;
                    try{ 
                    std::cin.clear();
                    std::cin.ignore(1000,'\n');
                    std::cout<<"Unesite ime i prezime agenta prodaje: ";
                    std::getline(std::cin,ime_i_prezime_agenta);
                    std::cout<<"Unesite datum prodaje (formata d/m/g): ";
                    std::cin>>danprodaje;
                    std::cin>>c1;
                    if(c1!='/') throw std::domain_error("Neispravan unos podataka ");
                    std::cin>>mjesecprodaje;
                    std::cin>>c2;
                    if(c2!='/') throw std::domain_error("Neispravan unos podataka ");
                    std::cin>>godinaprodaje;
                    std::cout<<"Unesite cijenu stana: ";
                    std::cin>>cijena;
                    std::cout<<"Unesite ime kupca: ";
                    std::cin.clear();
                    std::cin.ignore(1000,'\n');
                    std::getline(std::cin,ime_i_prezime_kupca);
                    std::cout<<"Unesite datum rodjenja kupca (formata d/m/g): ";
                    std::cin>>dan;
                    std::cin>>c3;
                    if(c3!='/') throw std::domain_error("Neispravan unos podataka");
                    std::cin>>mjesec;
                    std::cin>>c4;
                    if(c4!='/') throw std::domain_error("Neispravan unos podataka");
                    std::cin>>godina;
                    std::cin.clear();
                    std::cin.ignore(1000,'\n');
                    std::cout<<"Unesite adresu: ";
                    std::getline(std::cin,adresa);
                    std::cout<<"Unesite sprat: ";
                    std::cin>>sprat;
                    std::cout<<"Unesite broj soba: ";
                    std::cin>>brsoba;
                    std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                    std::cin>>namjesten;
                    std::cout<<"Unesite kvadraturu: ";
                    std::cin>>kvadratura;
                    Datum datummrodjenja(dan,mjesec,godina);
                    Datum datumprodaje(danprodaje,mjesecprodaje,godinaprodaje);
                    Kupac kupac(ime_i_prezime_kupca,datummrodjenja);
                    vektorkupaca.push_back(kupac);
                    Stan stan(adresa,sprat,brsoba,namjesten,kvadratura);
                    vektorstanova.push_back(stan);
                    Prodaja prodaja(ime_i_prezime_agenta,cijena,datumprodaje,kupac,stan);
                    vektorprodaja.push_back(prodaja);
                    std::cout<<" Prodaja je uspjesno dodana!"<<std::endl;
                    goto jodjica;
                    }
                    catch(std::domain_error e){
                        std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet:"<<std::endl;
                        goto ponovno;
                    }
                }
                else if(opcija2==2){
                    char c1,c2;
                    ponovi:
                    try{
                    std::cin.clear();
                    std::cin.ignore(1000,'\n');
                    std::cout<<"Unesite ime i prezime agenta prodaje: ";
                    std::getline(std::cin,ime_i_prezime_agenta);
                    std::cout<<"Unesite datum prodaje (formata d/m/g): ";
                    std::cin>>danprodaje;
                    std::cin>>c1;
                    if(c1!='/') throw std::domain_error("Neispravan unos podataka");
                    std::cin>>mjesecprodaje;
                    std::cin>>c2;
                    if(c2!='/') throw std::domain_error("Neispravan unos podataka");
                    std::cin>>godinaprodaje;
                    std::cout<<"Unesite cijenu stana: ";
                    std::cin>>cijena;
                    std::cout<<"Odaberite kupca. Dostupni kupci su:"<<std::endl;
                    for(int i(0);i<vektorkupaca.size();i++){
                        std::cout<<" "<<i+1<<" - ";
                        vektorkupaca[i].Ispisi();
                        }
                    int odabrani_kupac;
                    std::cin>>odabrani_kupac;
                    
                    std::cout<<"Odaberite stan. Dostupni stanovi su:"<<std::endl;
                    for(int i(0);i<vektorstanova.size();i++){
                        std::cout<<" "<<i+1<<" - ";
                        vektorstanova[i].Ispisi();
                    }
                    int odabrani_stan;
                    std::cin>>odabrani_stan;
                    Datum rodjenje=vektorkupaca[odabrani_kupac-1].DajDatumRodjenja();
                    std::string kupitelj=vektorkupaca[odabrani_kupac-1].DajImePrezime();
                    std::string adresitelj=vektorstanova[odabrani_stan-1].DajAdresu();
                    Prodaja prodaja(ime_i_prezime_agenta,cijena,danprodaje,mjesecprodaje,godinaprodaje,kupitelj,rodjenje,adresitelj,vektorstanova[odabrani_stan-1].DajSprat(),vektorstanova[odabrani_stan-1].DajBrojSoba(),vektorstanova[odabrani_stan-1].DajNamjesten(),vektorstanova[odabrani_stan-1].DajKvadraturu());
                    vektorprodaja.push_back(prodaja);
                    std::cout<<" Prodaja je uspjesno dodana!"<<std::endl;
                    goto jodjica;
                    }
                    catch(std::domain_error e){
                        std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                        goto ponovi;
                    }
                }
            }
            else if(opcija1==2){
                
                int opcija2;
                int odabranaprodaja;
                std::cout<<"Odaberite prodaju koju želite urediti. Dostupne prodaje su:"<<std::endl;
                for(int i(0);i<vektorprodaja.size();i++){
                    std::cout<<i+1<<"."<<std::endl;
                    vektorprodaja[i].Ispisi();
                }
                std::cin>>odabranaprodaja;
                nazad:
                std::cout<<"Izaberite opciju:"<<std::endl;
                std::cout<<" 0 - nazad"<<std::endl<<" 1 - izmjena agenta"<<std::endl<<" 2 - izmjena datuma prodaje"<<std::endl<<" 3 - izmjena kupca"<<std::endl<<" 4 - izmjena stana"<<std::endl<<" 5 - izmjena cijene stana"<<std::endl;
                std::cin>>opcija2;
                if(opcija2==0) goto jodjara;
                else if(opcija2==1){
                    std::string novi_agent;
                    std::cin.clear();
                    std::cin.ignore(1000,'\n');
                    std::cout<<"Unesite ime i prezime agenta prodaje:";
                    std::getline(std::cin,novi_agent);
                    vektorprodaja[odabranaprodaja-1].DajImeAgenta()=novi_agent;
                    std::cout<<" Prodaja je uspjesno izmijenjena!"<<std::endl;
                    }
                else if(opcija2==2){
                    ispocetka:
                    try{
                    int nov_dan,nov_mjesec,nov_godina;
                    char c1,c2;
                    std::cout<<"Unesite datum prodaje (formata d/m/g):";
                    std::cin>>nov_dan;
                    std::cin>>c1;
                    if(c1!='/') throw std::domain_error("Neispravan unos podataka");
                    std::cin>>nov_mjesec;
                    std::cin>>c2;
                    if(c2!='/') throw std::domain_error("Neispravan unos podataka");
                    std::cin>>nov_godina;
                    Datum nov_datum(nov_dan,nov_mjesec,nov_godina);
                    vektorprodaja[odabranaprodaja-1].PromijeniDatumKupovine(nov_datum);
                    std::cout<<" Prodaja je uspjesno izmijenjena!"<<std::endl;
                    }
                    catch(std::domain_error e){
                        std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                        std::cin.clear();
                        std::cin.ignore(1000,'\n');
                        goto ispocetka;
                    }
                }
                else if(opcija2==3){
                    int opcija3;
                    std::cout<<"Izaberite opciju:"<<std::endl;
                    std::cout<<" 0 - nazad"<<std::endl<<" 1 - odabir postojeceg kupca"<<std::endl<<" 2 - dodavanje novog kupca"<<std::endl;
                    std::cin>>opcija3;
                    if(opcija3==0) goto nazad;
                    if(opcija3==1){
                        int odabranikupac;
                        std::cout<<"Odaberite kupca. Dostupni kupci su:"<<std::endl;
                        for(int i(0);i<vektorkupaca.size();i++){
                            std::cout<<" "<<i+1<<" - ";
                            vektorkupaca[i].Ispisi();
                        }
                        
                        std::cin>>odabranikupac;
                        mela:
                        try{
                        std::cout<<"Unesite ime i prezime kupca: ";
                        std::cin.clear();
                        std::cin.ignore(1000,'\n');
                        std::string novikupac;
                        std::getline(std::cin,novikupac);
                        std::cout<<"Unesite datum rodjenja (formata dan/mjesec/godina): ";
                        int dan,mjesec,godina;
                        char c,cc;
                        std::cin>>dan;
                        std::cin>>c; if(c!='/') throw std::domain_error("Neispravan unos podataka");
                        std::cin>>mjesec;
                        std::cin>>cc; if(cc!='/') throw std::domain_error("Neispravan unos podataka");
                        std::cin>>godina;
                        Datum dat(dan,mjesec,godina);
                        Kupac novi(novikupac,dat);
                        vektorprodaja[odabranikupac-1].PromijeniKupca(novi);
                        std::cout<<" Prodaja je uspjesno izmijenjena!"<<std::endl;
                        }
                        catch(std::domain_error e){
                            std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                            goto mela;
                        }
                    }
                    else if(opcija3==2){
                        prkno:
                        char ch,cha;
                        int d,m,g;
                        std::string novinejm;
                        std::cin.clear();
                        std::cin.ignore(1000,'\n');
                        try{
                            std::cout<<"Uneiste ime i prezime kupca: ";
                            std::getline(std::cin,novinejm);
                            std::cout<<"Unesite datum rodjenja (formata d/m/g): ";
                            std::cin>>d;
                            std::cin>>ch; if(ch!='/') throw std::domain_error("Neispravan unos podataka");
                            std::cin>>m;
                            std::cin>>cha; if(cha!='/') throw std::domain_error("Neispravan unos podataka");
                            std::cin>>g;
                            Datum datu(d,m,g);
                            Kupac kup(novinejm,datu);
                            vektorkupaca.push_back(kup);
                            std::cout<<"Kupac je uspjesno dodan!"<<std::endl;
                        }
                        catch(std::domain_error e){
                            std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                           // std::cin.clear();
                            //std::cin.ignore(1000,'\n');
                            goto prkno;
                        }
                    }
                }
                else if(opcija2==4){
                    int opcija3;
                    std::cout<<"Izaberite opciju:"<<std::endl;
                    std::cout<<" 0 - nazad"<<std::endl<<" 1 - odabir postojeceg stana"<<std::endl<<" 2 - dodavanje novog stana"<<std::endl;
                    std::cin>>opcija3;
                    if(opcija3==0) goto nazad;
                    else if(opcija3==1){
                        int odabranistan;
                        std::cout<<"Odaberite stan. Dostupni stanovi su:"<<std::endl;
                        for(int i(0);i<vektorstanova.size();i++){
                            std::cout<<" "<<i+1<<" - ";
                            vektorstanova[i].Ispisi();
                        }
                        
                        std::cin>>odabranistan;
                        mella:
                        try{
                            std::cout<<"Unesite adresu: ";
                            std::cin.clear();
                            std::cin.ignore(1000,'\n');
                            std::string novaadresa;
                            std::getline(std::cin,novaadresa);
                            std::cout<<"Unesite sprat: ";
                            int novisprat;
                            std::cin>>novisprat;
                            std::cout<<"Unesite broj soba: ";
                            int novibrsoba;
                            std::cin>>novibrsoba;
                            std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                            bool novinamjesten;
                            std::cin>>novinamjesten;
                            std::cout<<"Unesite kvadraturu: ";
                            double novakvadratura;
                            std::cin>>novakvadratura;
                            Stan novistan(novaadresa,novisprat,novibrsoba,novinamjesten,novakvadratura);
                            vektorprodaja[odabranistan-1].PromijeniStan(novistan);
                            std::cout<<" Prodaja je uspjesno izmijenjena!"<<std::endl;
                        }
                        catch(std::domain_error e){
                            std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                            goto mella;
                        }
                    }
                    else if(opcija3==2){
                        povratak:
                        std::string adresica;
                        int sobe;
                        int spratt;
                        bool namjestenn;
                        double kvadrat;
                        std::cin.clear();
                        std::cin.ignore(1000,'\n');
                        try{
                            std::cout<<"Unesite adresu: ";
                            std::getline(std::cin,adresica);
                            std::cout<<"Unesite sprat: ";
                            std::cin>>spratt;
                            std::cout<<"Unesite broj soba: ";
                            std::cin>>sobe;
                            std::cout<<"Da li je namjesten (1 - da, 0 - ne): ";
                            std::cin>>namjestenn;
                            std::cout<<"Unesite kvadraturu: ";
                            std::cin>>kvadrat;
                            Stan noviji(adresica,spratt,sobe,namjestenn,kvadrat);
                            vektorstanova.push_back(noviji);
                            std::cout<<"Stan je uspjesno dodan!"<<std::endl;
                        }
                        catch(std::domain_error e){
                            std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                            goto povratak;
                        }
                    }
                }
                else if(opcija2==5){
                    cijena:
                    double cijenastana;
                    std::cout<<"Unesite cijenu stana: ";
                    std::cin>>cijenastana;
                    try{
                    vektorprodaja[odabranaprodaja-1].PromijeniCijenuProdaje(cijenastana);
                    std::cout<<" Prodaja je uspjesno izmijenjena!"<<std::endl;}
                    catch(std::domain_error e){
                        std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                        std::cin.clear();
                        std::cin.ignore(1000,'\n');
                        goto cijena;
                    }
                }
            }
            else if(opcija1==3){
                int opcija2(0);
                oaaaa:
                std::cout<<"Izaberite opciju:"<<std::endl;
                std::cout<<" 0 - nazad"<<std::endl<<" 1 - ispis svih prodaja"<<std::endl<<" 2 - ispis prodaja na datum"<<std::endl<<" 3 - ispis najranije prodaje"<<std::endl<<" 4 - ispis najskuplje prodaje"<<std::endl<<" 5 - ispis broja prodaja"<<std::endl<<" 6 - ispis broja prodaja po datumu"<<std::endl<<" 7 - ispis broja prodaja po agentu"<<std::endl<<" 8 - kraj"<<std::endl;
                std::cin>>opcija2;
                if (opcija2==0) goto jodjara;
                else if(opcija2==8) return 0;
                else if(opcija2==1){
                    for(int i(0);i<vektorprodaja.size();i++){
                        vektorprodaja[i].Ispisi();
                    }
                    goto oaaaa;
                }
                else if(opcija2==2){
                    int da,mjes,god;
                    char k1,k2;
                    std::cout<<"Unesite datum (d/m/g): ";
                    std::cin>>da;
                    std::cin>>k1; if(k1!='/') throw std::domain_error("Neispravan unos podataka");
                    std::cin>>mjes;
                    std::cin>>k2; if(k2!='/') throw std::domain_error("Neispravan unos podataka");
                    std::cin>>god;
                    Datum dat(da,mjes,god);
                    for(int i(0);i<vektorprodaja.size();i++){
                        if(vektorprodaja[i].DajDatumProdaje().DajDan()==dat.DajDan() && vektorprodaja[i].DajDatumProdaje().DajMjesec()==dat.DajMjesec() && vektorprodaja[i].DajDatumProdaje().DajGodinu()==dat.DajGodinu()){
                            vektorprodaja[i].Ispisi();
                        }
                    }
                    goto oaaaa;
                    
                }
                else if(opcija2==3){
                    Prodaja najranija=vektorprodaja[0];
                    for(int i(0);i<vektorprodaja.size()-1;i++){
                     for(int j=i+1;j<vektorprodaja.size();j++){
                        if(vektorprodaja[i].DajDatumProdaje().DajDan()<vektorprodaja[j].DajDatumProdaje().DajDan() && vektorprodaja[i].DajDatumProdaje().DajMjesec()<=vektorprodaja[j].DajDatumProdaje().DajMjesec() && vektorprodaja[i].DajDatumProdaje().DajGodinu()<=vektorprodaja[j].DajDatumProdaje().DajGodinu()) najranija=vektorprodaja[i];
                        else if(vektorprodaja[i].DajDatumProdaje().DajDan()<=vektorprodaja[j].DajDatumProdaje().DajDan() && vektorprodaja[i].DajDatumProdaje().DajMjesec()<vektorprodaja[j].DajDatumProdaje().DajMjesec() && vektorprodaja[i].DajDatumProdaje().DajGodinu()<=vektorprodaja[j].DajDatumProdaje().DajGodinu()) najranija=vektorprodaja[i];                    
                        else if(vektorprodaja[i].DajDatumProdaje().DajDan()<=vektorprodaja[j].DajDatumProdaje().DajDan() && vektorprodaja[i].DajDatumProdaje().DajMjesec()<=vektorprodaja[j].DajDatumProdaje().DajMjesec() && vektorprodaja[i].DajDatumProdaje().DajGodinu()<vektorprodaja[j].DajDatumProdaje().DajGodinu()) najranija=vektorprodaja[i];
                         }
                      }
                    najranija.Ispisi();
                    goto oaaaa;
                }
                else if(opcija2==4){
                    Prodaja najskuplja=vektorprodaja[0];
                    for(int i(0);i<vektorprodaja.size()-1;i++){
                        for(int j=i+1; j<vektorprodaja.size();j++){
                            if(vektorprodaja[i].DajCijenuStana()>vektorprodaja[j].DajCijenuStana()) najskuplja=vektorprodaja[i];
                        }
                    }
                    najskuplja.Ispisi();
                }
                else if(opcija2==5){
                    int brojprodaja=vektorprodaja.size();
                    std::cout<<brojprodaja<<std::endl;
                    goto oaaaa;
                }
                else if(opcija2==6){
                    ponavljanje:
                    try{
                    std::cout<<"Unesite datum (d/m/g): ";
                    int d,m,g;
                    int brojac=0;
                    char c1,c2;
                    std::cin>>d;
                    std::cin>>c1; if(c1!='/') throw std::domain_error("Neispravan unos podataka");
                    std::cin>>m;
                    std::cin>>c2; if(c2!='/') throw std::domain_error("Neispravan unos podataka");
                    std::cin>>g;
                    Datum datum(d,m,g);
                    for(int i(0);i<vektorprodaja.size();i++){
                        if(vektorprodaja[i].DajDatumProdaje().DajDan()==datum.DajDan() && vektorprodaja[i].DajDatumProdaje().DajMjesec()==datum.DajMjesec() && vektorprodaja[i].DajDatumProdaje().DajGodinu()==datum.DajGodinu()) brojac++;
                        brojac++;
                    }
                    std::cout<<brojac<<std::endl;
                    goto oaaaa;
                    }
                    catch(std::domain_error e){
                        std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                        std::cin.clear();
                        std::cin.ignore(1000,'\n');
                        goto ponavljanje;
                    }
                }
                else if(opcija2==7){
                    std::string imeagenta;
                    int brojac=0;
                    std::cout<<"Unesite ime agenta: ";
                    std::cin.clear();
                    std::cin.ignore(1000,'\n');
                    std::getline(std::cin,imeagenta);
                    for(int i(0);i<vektorprodaja.size();i++){
                        if(vektorprodaja[i].DajImeAgenta()==imeagenta) brojac++;
                    }
                    std::cout<<brojac<<std::endl;
                    goto oaaaa;
                }
            }
            else if(opcija1==4){
                int opcija2;
                yolo:
                std::cout<<"Izaberite opciju:"<<std::endl;
                std::cout<<" 0 - nazad"<<std::endl<<" 1 - brisanje najranije prodaje"<<std::endl<<" 2 - brisanje prodaja agenta"<<std::endl<<" 3 - brisanje prodaja po datumu"<<std::endl<<" 4 - brisanje svih prodaja"<<std::endl;
                std::cin>>opcija2;
                if(opcija2==0) goto jodjara;
                else if(opcija2==1){
                    try{
                    if(vektorprodaja.size()==0) throw std::range_error("Prazna kolekcija");
                    int mjesto;
                    for(int i(0);i<vektorprodaja.size()-1;i++){
                        for(int j=i+1;j<vektorprodaja.size();j++){
                             if(vektorprodaja[i].DajDatumProdaje().DajDan()<vektorprodaja[j].DajDatumProdaje().DajDan() && vektorprodaja[i].DajDatumProdaje().DajMjesec()<=vektorprodaja[j].DajDatumProdaje().DajMjesec() && vektorprodaja[i].DajDatumProdaje().DajGodinu()<=vektorprodaja[j].DajDatumProdaje().DajGodinu()) mjesto=i;
                             if(vektorprodaja[i].DajDatumProdaje().DajDan()<=vektorprodaja[j].DajDatumProdaje().DajDan() && vektorprodaja[i].DajDatumProdaje().DajMjesec()<vektorprodaja[j].DajDatumProdaje().DajMjesec() && vektorprodaja[i].DajDatumProdaje().DajGodinu()<=vektorprodaja[j].DajDatumProdaje().DajGodinu()) mjesto=i;
                             if(vektorprodaja[i].DajDatumProdaje().DajDan()<=vektorprodaja[j].DajDatumProdaje().DajDan() && vektorprodaja[i].DajDatumProdaje().DajMjesec()<=vektorprodaja[j].DajDatumProdaje().DajMjesec() && vektorprodaja[i].DajDatumProdaje().DajGodinu()<vektorprodaja[j].DajDatumProdaje().DajGodinu()) mjesto=i;
                             vektorprodaja.erase(vektorprodaja.begin()+mjesto);
                             std::cout<<"Najranija prodaja je obrisana."<<std::endl;
                        }
                    }
                    }
                    catch(std::range_error e){
                        std::cout<<"Izuzetak: "<<e.what()<<"."<<std::endl;
                    }
                }
                else if(opcija2==2){
                    try{
                    if(vektorprodaja.size()==0) throw std::range_error("Prazna kolekcija");
                    std::string imeagenta;
                    int mjesto;
                    std::cout<<"Unesite ime agenta: ";
                    std::cin.clear();
                    std::cin.ignore(1000,'\n');
                    std::getline(std::cin,imeagenta);
                    for(int i(0);i<vektorprodaja.size();i++){
                        if(vektorprodaja[i].DajImeAgenta()==imeagenta) mjesto=i; vektorprodaja.erase(vektorprodaja.begin()+mjesto);
                    }
                    std::cout<<"Sve prodaje tog agenta su obrisane."<<std::endl;
                    goto yolo;
                    }
                    catch(std::range_error e){
                        std::cout<<"Izuzetak: "<<e.what()<<std::endl;
                    }
                }
                else if(opcija2==3){
                    brisanje:
                    try{
                    if(vektorprodaja.size()==0) throw std::range_error("Prazna kolekcija");    
                    
                    std::cout<<"Unesite datum (d/m/g): "<<std::endl;
                    int d,m,g;
                    int mjesto;
                    char c1,c2;
                    std::cin>>d;
                    std::cin>>c1; if(c1!='/') throw std::domain_error("Neispravan unos podataka");
                    std::cin>>m;
                    std::cin>>c2; if(c2!='/') throw std::domain_error("Neispravan unos podataka");
                    std::cin>>g;
                    Datum datum(d,m,g);
                    for(int i(0);i<vektorprodaja.size();i++){
                        if(vektorprodaja[i].DajDatumProdaje().DajDan()==datum.DajDan() && vektorprodaja[i].DajDatumProdaje().DajMjesec()==datum.DajMjesec() && vektorprodaja[i].DajDatumProdaje().DajGodinu()==datum.DajGodinu()) mjesto=i;
                        vektorprodaja.erase(vektorprodaja.begin()+mjesto);
                        }
                std::cout<<"Sve prodaje na taj datum su obrisane."<<std::endl;
                    }
                catch(std::domain_error e){
                    std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                    std::cin.clear();
                    std::cin.ignore(1000,'\n');
                    goto brisanje;
                }    
                }
                else if(opcija2==4){
                    auto it=vektorprodaja.begin();
                    auto it2=vektorprodaja.end();
                    vektorprodaja.erase(it,it2);
                }
        }
    }}
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Dovidjenja!";
	return 0;
}