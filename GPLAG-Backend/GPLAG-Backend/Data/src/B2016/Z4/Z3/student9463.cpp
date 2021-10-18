/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <string>
#include <iomanip>
#include <algorithm>
 class Datum {
     int d,m,g;
     public:
    Datum(int dan, int mjesec, int godina) {
        Postavi(dan,mjesec,godina);
    }
    void Postavi(int dan, int mjesec, int godina) {
        
       
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina % 4 == 0 && (godina % 100 != 0 || godina % 400 == 0))
        broj_dana[1]++;
    if(godina < 1 || mjesec < 1 || mjesec > 12 || dan < 1 || dan > broj_dana[mjesec - 1])
        throw std::domain_error("Neispravan datum!");
        
        else {
            d=dan;
            m=mjesec;
            g=godina;
        }
        
    }
    int DajDan() const {
        return d;
    }
    int DajMjesec() const {
        return m;
    }
    int DajGodinu() const {
        return g;
    }
    void Ispisi() const {
        std::cout<<DajDan()<<"/"<<DajMjesec()<<"/"<<DajGodinu();
    }
};

class Kupac {
    Datum d;
    std::string ime_i_prezime;
    public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja):d(datum_rodjenja) {
       for(int i(0);i<ime_i_prezime.length();i++) {
           //ubacit uslov za broj
            if(ime_i_prezime[i]<65 && ime_i_prezime[i]>122 && ime_i_prezime[i]!=' ' && ime_i_prezime[i]!='-' && ime_i_prezime[i]!=39 ) throw std::domain_error ("Neispravno ime i prezime");
            
        }
        this->ime_i_prezime=ime_i_prezime;
    }
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja) {
        d=datum_rodjenja;
        
        this->ime_i_prezime=ime_i_prezime;
    }
    std::string DajImePrezime() const {
        return ime_i_prezime;
    }
    Datum DajDatumRodjenja() const {
        return d;
    }
    void Ispisi() const {
        std::cout<<ime_i_prezime<<"(";
        d.Ispisi();
        std::cout<<")";
    }

};
class Stan {
    std::string adresa;
    int sprat;
    int broj_soba;
    bool namjesten;
    double kvadratura;
    public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
         if(sprat<0 || broj_soba<0 || kvadratura<0) throw std::domain_error ("Neispravan unos podataka");
        else  {
            this->adresa=adresa;
            this->sprat=sprat;
            this->broj_soba=broj_soba;
            this->namjesten=namjesten;
            this->kvadratura=kvadratura;
        }
    }
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
        if(sprat<0 || broj_soba<0 || kvadratura<0) throw std::domain_error ("Neispravan unos podataka");
        else  {
            this->adresa=adresa;
            this->sprat=sprat;
            this->broj_soba=broj_soba;
            this->namjesten=namjesten;
            this->kvadratura=kvadratura;
        }
        
    }
    std::string DajAdresu() const {
        return adresa;
    }
    int DajSprat() const {
        return sprat;
    }
    int DajBrojSoba() const {
        return broj_soba;
    }
    bool DajNamjesten() const {
        return namjesten;
    }
    double DajKvadraturu() const {
        return kvadratura;
    }
    void Ispisi() const {
        std::cout<<"Stan se nalazi na adresi"<<DajAdresu()<<"na"<<DajSprat()<<". spratu i ima ";
        if(broj_soba%10==1 && broj_soba!=11) std::cout<<broj_soba<<" sobu";
        else if(broj_soba%10==2 && broj_soba!=12) std::cout<<broj_soba<<" sobe";
        else if(broj_soba%10==3 && broj_soba!=13) std::cout<<broj_soba<<" sobe";
        else if(broj_soba%10==4 && broj_soba!=14) std::cout<<broj_soba<<" sobe";
        else if(broj_soba%10==5 ) std::cout<<broj_soba<<" soba";
        else std::cout<<broj_soba<<" soba.";
        std::cout<<std::endl;
        std::cout<<" Kvadratura stana je "<<kvadratura<<" i stan ";
        if(namjesten)std::cout<<"je namjesten";
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
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,const Datum &datum_prodaje, const Kupac &kupac_stana,const Stan &kupljeni_stan):datum_prodaje(datum_prodaje),kupac_stana(kupac_stana),kupljeni_stan(kupljeni_stan) {
      this->ime_agenta_prodaje=ime_agenta_prodaje;
        this->cijena_stana=cijena_stana;
       // this->datum_prodaje=datum_prodaje;
       // this->kupac_stana=kupac_stana;
       // this->kupljeni_stan=kupljeni_stan;
    }
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca,const std::string &adresa_stana, int sprat_stana, int broj_soba,bool namjesten_stan, double broj_kvadrata): datum_prodaje(dan_prodaje,mjesec_prodaje,godina_prodaje), kupac_stana(ime_kupca,datum_rodjenja_kupca),kupljeni_stan(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata){
        this->ime_agenta_prodaje=ime_agenta_prodaje;
        this->cijena_stana=cijena_stana;
        //datum_prodaje.Postavi(dan_prodaje,mjesec_prodaje,godina_prodaje);
        //kupac_stana.Postavi(ime_kupca,datum_rodjenja_kupca);
        //kupljeni_stan.Postavi(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata);
    }
    void PromijeniKupca(const Kupac &novi_kupac) {
        kupac_stana=novi_kupac;
    }
    void PromijeniStan(const Stan &novi_stan)   {
        kupljeni_stan=novi_stan;
    }
    void PromijeniDatumKupovine(const Datum &novi_datum){
        datum_prodaje=novi_datum;
    }
    void PromijeniCijenuProdaje(const double &nova_cijena) {
        cijena_stana=nova_cijena;
    }
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImeAgenta() const {
        return ime_agenta_prodaje;
    }
    std::string DajImeKupca() const {
        return kupac_stana.DajImePrezime();
    }
    Datum DajDatumProdaje() const {
        return datum_prodaje;
    }
    double DajCijenuStana() const {
        return cijena_stana;
    }
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2) {
        Datum d1=p1.DajDatumProdaje();
        Datum d2=p2.DajDatumProdaje();
        if(d1.DajGodinu()<d2.DajGodinu())return true;
        if(d1.DajGodinu()>d2.DajGodinu()) return false;
        if(d1.DajMjesec()<d2.DajMjesec()) return true;
        if(d1.DajMjesec()>d2.DajMjesec()) return false;
        if(d1.DajDan()<d2.DajDan()) return  true;
         return  false;
        
        
    }
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2) {
        double cijena1=p1.DajCijenuStana();
        double cijena2=p2.DajCijenuStana();
        if(cijena1<cijena2) return true;
        else return false;
    }
    void Ispisi() const;
};
void Prodaja::PomjeriDanUnaprijed()  {
    
    int dan,mjesec, godina;
    dan=datum_prodaje.DajDan();
    mjesec=datum_prodaje.DajMjesec();
    godina=datum_prodaje.DajGodinu();
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina % 4 == 0 &&( godina % 100 != 0 || godina % 400 == 0))
    broj_dana[1]++;
    dan+=1;
    if(dan>broj_dana[mjesec-1]) {
        dan=1;
        mjesec++;
        if(mjesec>12) {
            godina++;
        }
    }
    datum_prodaje.Postavi(dan,mjesec,godina);
}
void Prodaja::PomjeriDanUnazad() {
    
    int dan,mjesec,godina;
    dan=datum_prodaje.DajDan();
    mjesec=datum_prodaje.DajMjesec();
    godina=datum_prodaje.DajGodinu();
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina % 4 == 0 &&( godina % 100 != 0 || godina % 400 == 0))
    broj_dana[1]++;
    dan--;
    if(dan==0) {
        bool da(true);
        mjesec--;
        if(mjesec==0) {
            mjesec=12;
            godina--;
            dan=31;
            da=false;
        }
        if(da) {
            dan=broj_dana[mjesec-2];
        }
    }
     datum_prodaje.Postavi(dan,mjesec,godina);
   
}
void Prodaja::Ispisi() const {
    std::cout<<std::setw(30)<<"Ime agenta: "<<std::setw(30)<<DajImeAgenta();
    std::cout<<std::setw(30)<<"Ime kupca: "<<std::setw(30)<<DajImeKupca();
    std::cout<<std::setw(30)<<"Zakazani datum prodaje: "<<std::setw(30);
    DajDatumProdaje().Ispisi();
    std::cout<<std::setw(30)<<"Cijena stana: "<<std::setw(30)<<DajCijenuStana();
    std::cout<<"Informacije o stanu:"<<std::endl;
    kupljeni_stan.Ispisi();
}
class Prodaje {
    Prodaja ** niz;
    int max_broj_prodaja, broj_prodaja;
    void Alociraj();
   
    public:
    explicit Prodaje(int max_broj_prodaja);
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
    ~Prodaje() {IsprazniKolekciju() ; };
    
    Prodaje(const Prodaje &prodaje); //gotova
    Prodaje(Prodaje &&prodaje); //gotova
    Prodaje &operator =(const Prodaje &prodaje); //gotova;
    Prodaje &operator =(Prodaje &&prodaje);//gotova
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje,
    double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,
    const Stan &kupljeni_stan);//gotova
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana, int dan_prodaje,
    int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
    const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,
    int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata); //gotova
    
    void RegistrirajProdaju(Prodaja *prodaja);// gotova
    int DajBrojProdaja() const {
        return broj_prodaja;
    } //gotova
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
void Prodaje::Alociraj() {
    niz=new Prodaja*[max_broj_prodaja];
    for(int i(0);i<max_broj_prodaja;i++) {
        niz[i]=nullptr;
    }
}
void Prodaje::IsprazniKolekciju() {
    if(niz==nullptr) return;
    for(int i(0);i<max_broj_prodaja;i++) {
        delete [] niz[i];
    }
    delete []niz;
    niz=nullptr;
    broj_prodaja=0;
}
Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja):max_broj_prodaja(spisak_prodaja.size())  {
    Alociraj();
    broj_prodaja=0;
    try {
        for(auto it=spisak_prodaja.begin();it<spisak_prodaja.end();it++) {
            niz[broj_prodaja]=new Prodaja(*it);
            broj_prodaja++;
        }
    }
        catch(std::bad_alloc) {
            IsprazniKolekciju();
            throw;
        }
    }
    


Prodaje::Prodaje(const Prodaje & prodaje):max_broj_prodaja(prodaje.max_broj_prodaja){
    
    broj_prodaja=prodaje.broj_prodaja;
    Alociraj();
    try {
        for(int i(0);i<broj_prodaja;i++) niz[i]=new Prodaja(*prodaje.niz[i]);
    }
    catch(std::bad_alloc) {
        IsprazniKolekciju();
        throw;
    }
}
Prodaje::Prodaje(Prodaje &&prodaje): max_broj_prodaja(prodaje.max_broj_prodaja) {
    broj_prodaja=prodaje.broj_prodaja;
    niz=prodaje.niz;
    prodaje.niz=nullptr;
    prodaje.broj_prodaja=0;
}
Prodaje& Prodaje::operator =(const Prodaje &prodaje) {
    if(&prodaje!=this) {
        IsprazniKolekciju();
        max_broj_prodaja=prodaje.max_broj_prodaja;
        broj_prodaja=prodaje.broj_prodaja;
        Alociraj();
        for(int i(0);i<broj_prodaja;i++) {
            niz[i]=new Prodaja(*(prodaje.niz[i]));
        }
    }
    return *this;
}
Prodaje &Prodaje::operator =(Prodaje &&prodaje) {
    if(&prodaje!=this) {
        IsprazniKolekciju();
        max_broj_prodaja=prodaje.max_broj_prodaja;
        broj_prodaja=prodaje.broj_prodaja;
        niz=prodaje.niz;
        prodaje.niz=nullptr;
        prodaje.max_broj_prodaja=0;
    }
    return *this;
}
void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje,
    double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,
    const Stan &kupljeni_stan) {
        if(broj_prodaja>max_broj_prodaja) throw std::range_error ("Dostignut maksimalni broj prodaja");
        niz[broj_prodaja]=new Prodaja(ime_agenta_prodaje,cijena_stana,datum_prodaje,kupac_stana,kupljeni_stan);
        broj_prodaja++;
    }

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana, int dan_prodaje,
    int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
    const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,
    int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) {
        if(broj_prodaja>max_broj_prodaja) throw std::range_error ("Dostignut maksimalni broj prodaja");
        niz[broj_prodaja]=new Prodaja(ime_agenta_prodaje,cijena_stana,dan_prodaje,mjesec_prodaje,godina_prodaje,ime_kupca,datum_rodjenja_kupca,adresa_stana,sprat_stana,
        broj_soba,namjesten_stan,broj_kvadrata);
        broj_prodaja++;
    }
    void Prodaje::RegistrirajProdaju(Prodaja *prodaja) {
        if(broj_prodaja>max_broj_prodaja) throw std::range_error ("Dostignut maksimalni broj prodaja");
        niz[broj_prodaja]=prodaja;
        broj_prodaja++;
    }
  /* int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const {
       
        return std::count_if(niz, niz+broj_prodaja, [](Prodaja *p){int dan, mjesec, godina; 
            Datum d=p->DajDatumProdaje();
            dan=d.DajDan();
            mjesec=d.DajMjesec();
            godina=d.DajGodinu();
            if(dan==datum.DajDan() && mjesec==datum.DajMjesec() && godina==datum.DajGodinu()) return true;
            else return false;
        });
    }*/
int main ()
{
    std::cout<<"Da";
	return 0;
}