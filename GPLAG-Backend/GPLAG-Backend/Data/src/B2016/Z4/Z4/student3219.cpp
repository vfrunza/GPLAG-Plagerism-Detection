/B 2016/2017, Zadaća 4, Zadatak 4
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <string>
#include <algorithm>


using namespace std;

class Datum {
    int D,M,G;
    public:
    Datum(int dan, int mjesec, int godina);
    void Postavi(int dan, int mjesec, int godina);
    int DajDan() const { return D; }
    int DajMjesec() const { return M; }
    int DajGodinu() const { return G; }
    void Ispisi() const; 
};

Datum::Datum(int dan, int mjesec, int godina) {
    Postavi(dan,mjesec,godina);
}

void Datum::Postavi(int dan, int mjesec, int godina) {
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0)
    broj_dana[1]++;
    
    if(godina < 1 || mjesec < 1 || mjesec > 12 || dan < 1 || dan > broj_dana[mjesec-1]) throw std::domain_error("Neispravan datum!");
    D=dan; M=mjesec; G=godina;
}

void Datum::Ispisi() const {
    cout<<D<<"/"<<M<<"/"<<G;
} 

class Kupac {
    string ImeIPrezime;
    Datum DatumRodjenja;
    public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja): DatumRodjenja(datum_rodjenja.DajDan(),datum_rodjenja.DajMjesec(),datum_rodjenja.DajGodinu()) { Postavi(ime_i_prezime, datum_rodjenja); }
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);  
    std::string DajImePrezime() const { return ImeIPrezime; } 
    Datum DajDatumRodjenja() const { return DatumRodjenja; }
    void Ispisi() const; 
};

void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja) {
    int i(0);
    while(i<ime_i_prezime.length()) {
        if(!((ime_i_prezime[i]>='0' && ime_i_prezime[i]<='9') || (ime_i_prezime[i]>='A' && ime_i_prezime[i]<='Z') || (ime_i_prezime[i]>='a' && ime_i_prezime[i]<='z')  || ime_i_prezime[i]==' ' || ime_i_prezime[i]=='"' || ime_i_prezime[i]=='-')) throw domain_error ("Neispravno ime i prezime");
    }
    Kupac::DatumRodjenja.Postavi(datum_rodjenja.DajDan(), datum_rodjenja.DajMjesec(), datum_rodjenja.DajGodinu());
    ImeIPrezime=ime_i_prezime;
}

void Kupac::Ispisi() const {
    cout<<ImeIPrezime<<" ("; DatumRodjenja.Ispisi(); cout<<")";
}

class Stan {
    string adresa;
    int sprat, BrojSoba;
    bool namjesten;
    double kvadrata;
    void je_ili_nije( bool namjestaj) const { if(namjestaj) cout<<"je"; else cout<<"nije"; }
    void BS( int BrSoba ) const { if(BrSoba%10==1 && BrSoba!=11) cout<<"sobu"; else if((BrSoba%10==2 && BrSoba!=12) || (BrSoba==3 && BrSoba!=13) || (BrSoba==4 && BrSoba!=14)) cout<<"sobe"; else cout<<"soba"; } 
    public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) { Postavi(adresa,sprat,broj_soba,namjesten, kvadratura); };
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);  
    std::string DajAdresu() const { return adresa; }
    int DajSprat() const  { return sprat; }
    int DajBrojSoba() const  { return BrojSoba; }
    bool DajNamjesten() const  {  return namjesten; }
    double DajKvadraturu() const { return kvadrata; }
    void Ispisi() const;
};

void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
    if(sprat<0 || broj_soba<0 || namjesten<0 || kvadratura<0) throw domain_error ("Neispravan unos podataka");
    Stan::adresa=adresa;
    Stan::sprat=sprat;
    BrojSoba=broj_soba;
    Stan::namjesten=namjesten;
    kvadrata=kvadratura;
}

void Stan::Ispisi() const {
    cout<< "Stan se nalazi na adresi"<<Stan::adresa<<" na "<<Stan::sprat<<" spratu i ima "<<BrojSoba; BS(BrojSoba); cout<<". Kvadratura stana je "<<kvadrata<<" i stan "; je_ili_nije(namjesten) ;cout<<" namjesten";
}

class Prodaja {
    string Agent;
    double Cijena;
    Datum DatumProdaje;
    Kupac KupacStana;
    Stan KupljeniStan;
    
    public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);   
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);   
    void PromijeniKupca(const Kupac &novi_kupac); 
    void PromijeniStan(const Stan &novi_stan);   
    void PromijeniDatumKupovine(const Datum &novi_datum);   
    void PromijeniCijenuProdaje(const double &nova_cijena) { Cijena=nova_cijena; };   
    void PomjeriDanUnaprijed();   
    void PomjeriDanUnazad();   
    std::string DajImeAgenta() const { return Agent; };   
    std::string DajImeKupca() const { return KupacStana.DajImePrezime(); };
    Datum DajDatumProdaje() const { return DatumProdaje; };  
    double DajCijenuStana() const   { return Cijena; };
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);   
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);   
    void Ispisi() const; 
};

Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan):
    DatumProdaje(datum_prodaje.DajDan(),datum_prodaje.DajMjesec(),datum_prodaje.DajGodinu()),
    KupacStana(kupac_stana.DajImePrezime(), kupac_stana.DajDatumRodjenja()),
    KupljeniStan(kupljeni_stan.DajAdresu(),kupljeni_stan.DajSprat(),kupljeni_stan.DajBrojSoba(),kupljeni_stan.DajNamjesten(),kupljeni_stan.DajKvadraturu()) {
    Agent=ime_agenta_prodaje;
    Cijena=cijena_stana;
}

 Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) :
     Agent(ime_agenta_prodaje),
     Cijena(cijena_stana),
     DatumProdaje(dan_prodaje,mjesec_prodaje,godina_prodaje),
     KupacStana(ime_kupca,datum_rodjenja_kupca),
     KupljeniStan(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata) {}

void Prodaja::PromijeniKupca(const Kupac &novi_kupac) {
    KupacStana.Postavi(novi_kupac.DajImePrezime(),novi_kupac.DajDatumRodjenja());
}  

void Prodaja::PromijeniStan(const Stan &novi_stan) {
    KupljeniStan.Postavi(novi_stan.DajAdresu(), novi_stan.DajSprat(), novi_stan.DajBrojSoba(), novi_stan.DajNamjesten(), novi_stan.DajKvadraturu());
}

void Prodaja::PromijeniDatumKupovine(const Datum &novi_datum) {
    DatumProdaje.Postavi(novi_datum.DajDan(), novi_datum.DajMjesec(), novi_datum.DajGodinu());
}

void Prodaja::PomjeriDanUnaprijed(){
    int dani=DatumProdaje.DajDan()+1;
    int mjeseci=DatumProdaje.DajMjesec();
    int godine=DatumProdaje.DajGodinu();
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godine % 4 == 0 && godine % 100 != 0) || godine % 400 == 0) broj_dana[1]++;
    if(dani>broj_dana[DatumProdaje.DajMjesec()-1])  { mjeseci++; dani=1; }
    if(mjeseci>12) { godine++; mjeseci=1; }
    DatumProdaje.Postavi(dani, mjeseci, godine);
}

void Prodaja::PomjeriDanUnazad() {
    int dani=DatumProdaje.DajDan()-1;
    int mjeseci=DatumProdaje.DajMjesec();
    int godine=DatumProdaje.DajGodinu();
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godine % 4 == 0 && godine % 100 != 0) || godine % 400 == 0) broj_dana[1]++;
    if(dani<1)  { mjeseci--; dani=broj_dana[mjeseci-1]; }
    if(mjeseci<1) { godine--; mjeseci=12; }
    DatumProdaje.Postavi(dani, mjeseci, godine);
    
}

bool ProdatPrije(const Prodaja &p1, const Prodaja &p2) {
    if(p1.DajDatumProdaje().DajGodinu()<p2.DajDatumProdaje().DajGodinu()) return true;
    else if(p1.DajDatumProdaje().DajGodinu()>p2.DajDatumProdaje().DajGodinu()) return false;
    if(p1.DajDatumProdaje().DajMjesec()<p2.DajDatumProdaje().DajMjesec()) return true;
    else if(p1.DajDatumProdaje().DajMjesec()>p2.DajDatumProdaje().DajMjesec()) return false;
    if(p1.DajDatumProdaje().DajDan()<p2.DajDatumProdaje().DajDan()) return true;
    else return false;
    
}

bool SkupljiStan(const Prodaja &p1, const Prodaja &p2){
    if(p1.Cijena>p2.Cijena) return true;
    else return false;
}

void Prodaja::Ispisi() const {
    cout<<"Ime agenta:                     "<<DajImeAgenta()<<endl;
    cout<<"Ime kupca:                      ";KupacStana.Ispisi(); cout<<endl;
    cout<<"Zakazani datum prodaje:         ";DatumProdaje.Ispisi(); cout<<endl;
    cout<<"Cijena stana:                   "<<Cijena<<endl;
    cout<<"Informacije o stanu:"<<endl;
    KupljeniStan.Ispisi();
    
    
}

class Prodaje {
    Prodaja **pok=nullptr;
    int ima=0,max=0;
    void Unisti() { for(int i(0);i<ima;i++) delete pok[i]; delete [] pok; }
    bool IstiDatum(Datum d1,Datum d2) const { if(d1.DajDan()==d2.DajDan() && d1.DajMjesec()==d2.DajMjesec() && d1.DajGodinu()==d2.DajGodinu()) return true; else return false; }
    public:
    explicit Prodaje(int max_broj_prodaja) {
        max=max_broj_prodaja;
        pok=new Prodaja *[max];
        ima=0;
    } 
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);   
    ~Prodaje() {
        Unisti();
    } 
    Prodaje(const Prodaje &prodaje);   
    Prodaje(Prodaje &&prodaje);   
    Prodaje &operator =(const Prodaje &prodaje);  
    Prodaje &operator =(Prodaje &&prodaje);   
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);   
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);   
    void RegistrirajProdaju(Prodaja *prodaja);   
    int DajBrojProdaja() const { return ima; }
    int DajBrojProdajaNaDatum(const Datum &datum) const;   
    int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const; 
    Prodaja &DajProdaju(int indeks);
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

Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja) {
    max=spisak_prodaja.size();
    pok=new Prodaja *[max];
    auto elemenat=spisak_prodaja.begin();
    int i=0;
    while(i<max) {
        pok[i]=new Prodaja(*elemenat++);
        i++;
    }
    ima=i;
}

Prodaje::Prodaje(const Prodaje &prodaje) {         
    ima=prodaje.ima;
    max=prodaje.max;
    for(int i(0);i<ima;i++) {
        pok[i]=new Prodaja(*prodaje.pok[i]);
    }
}                              //kopirajuci konstr

Prodaje::Prodaje(Prodaje &&prodaje) {
    ima=prodaje.ima;
    max=prodaje.max;
    pok=prodaje.pok;
    prodaje.pok=nullptr;
}                                   //pomjerajuci konstr 

Prodaje &Prodaje::operator =(const Prodaje &prodaje) {              
    if(this!= &prodaje) {
        Unisti();
        ima=prodaje.ima;
        max=prodaje.max;
        pok=new Prodaja *[max];
        for(int i(0);i<ima;i++) {
            pok[i]=new Prodaja ( *prodaje.pok[i]);
        }
        return *this;
    }
    else return *this;
}                  //kopirajuci operator dodjele

Prodaje &Prodaje::operator =(Prodaje &&prodaje) {
    if(this != &prodaje) {
        Unisti();
        ima=prodaje.ima;
        max=prodaje.max;
        pok=prodaje.pok;
        prodaje.pok=nullptr;
        return *this;
    }
    else return *this;
}                       //pomjerajuci operator dodjele

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan) {
    if(ima==max) throw range_error ("Dostignut maksimalni broj prodaja");
    else {
        pok[ima++]=new Prodaja (ime_agenta_prodaje,cijena_stana,datum_prodaje,kupac_stana,kupljeni_stan);
    }
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) {
   if(ima==max) throw range_error ("Dostignut maksimalni broj prodaja");
    else {
        pok[ima++]=new Prodaja (ime_agenta_prodaje,cijena_stana,dan_prodaje,mjesec_prodaje,godina_prodaje,ime_kupca,datum_rodjenja_kupca,adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata);
    }      
}

void Prodaje::RegistrirajProdaju(Prodaja *prodaja) {
    if(ima==max) throw range_error ("Dostignut maksimalni broj prodaja");
    else {
        pok[ima++]=prodaja;
    }
}

int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const {
    if(ima==0) throw domain_error ("Nema registriranih prodaja");
    int brojac=count_if(pok,pok+ima,[datum](Prodaja *pok2) {  return (datum.DajDan()==pok2->DajDatumProdaje().DajDan() && datum.DajMjesec()==pok2->DajDatumProdaje().DajMjesec() && datum.DajGodinu()==pok2->DajDatumProdaje().DajGodinu());   } );
    return brojac;
}

int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const {
    if(ima==0) throw domain_error ("Nema registriranih prodaja");
    int brojac(0);
    for(int i(0);i<ima;i++) {
        if(ime_agenta==pok[i]->DajImeAgenta()) brojac++;
    }
    return brojac;
}

Prodaja &Prodaje::DajNajranijuProdaju() {
    if(ima==0) throw domain_error ("Nema registriranih prodaja");
    return **min_element(pok,pok+ima,[](Prodaja* prod1, Prodaja* prod2) {
        if(prod1->DajDatumProdaje().DajGodinu() < prod2->DajDatumProdaje().DajGodinu()) return true;
        else if(prod1->DajDatumProdaje().DajGodinu() > prod2->DajDatumProdaje().DajGodinu()) return false;
        if(prod1->DajDatumProdaje().DajMjesec() < prod2->DajDatumProdaje().DajMjesec()) return true;
        else if(prod1->DajDatumProdaje().DajMjesec() > prod2->DajDatumProdaje().DajMjesec()) return false;
        if(prod1->DajDatumProdaje().DajDan()<prod2->DajDatumProdaje().DajDan()) return true;
        else return false;
    });
}

Prodaja &Prodaje::DajProdaju(int indeks) {
    if(indeks>ima || indeks<0) throw domain_error ("Nepostojeci indeks");
    return *(pok[indeks-1]);
}

Prodaja Prodaje::DajNajranijuProdaju() const {
    if(ima==0) throw domain_error ("Nema registriranih prodaja");
    return **min_element(pok,pok+ima,[](Prodaja* prod1, Prodaja* prod2) {
        if(prod1->DajDatumProdaje().DajGodinu() < prod2->DajDatumProdaje().DajGodinu()) return true;
        else if(prod1->DajDatumProdaje().DajGodinu() > prod2->DajDatumProdaje().DajGodinu()) return false;
        if(prod1->DajDatumProdaje().DajMjesec() < prod2->DajDatumProdaje().DajMjesec()) return true;
        else if(prod1->DajDatumProdaje().DajMjesec() > prod2->DajDatumProdaje().DajMjesec()) return false;
        if(prod1->DajDatumProdaje().DajDan()<prod2->DajDatumProdaje().DajDan()) return true;
        else return false;
    });
}

Prodaja &Prodaje::DajNajskupljuProdaju() {
    if(ima==0) throw domain_error ("Nema registriranih prodaja");
    return **max_element(pok,pok+ima,[](Prodaja *prod1, Prodaja *prod2) {
        if(prod1->DajCijenuStana()>prod2->DajCijenuStana()) return true;
        else return false;
    });
}

Prodaja Prodaje::DajNajskupljuProdaju() const{
    if(ima==0) throw domain_error ("Nema registriranih prodaja");
    return **max_element(pok,pok+ima,[](Prodaja *prod1, Prodaja *prod2) {
        return prod1->DajCijenuStana()>prod2->DajCijenuStana();
    });
}

void Prodaje::IsprazniKolekciju() {
    Unisti();
    ima=0; max=0;
}

void Prodaje::ObrisiNajranijuProdaju() {
    if(ima==0) throw range_error ("Prazna kolekcija");
    int najranija=0;
    for(int i(1);i<ima;i++) {
        if(pok[i]->DajDatumProdaje().DajGodinu()<pok[najranija]->DajDatumProdaje().DajGodinu()) { najranija=i; continue; }
        else if(pok[i]->DajDatumProdaje().DajGodinu()>pok[najranija]->DajDatumProdaje().DajGodinu()) continue;
        if(pok[i]->DajDatumProdaje().DajMjesec()<pok[najranija]->DajDatumProdaje().DajMjesec()) { najranija=i; continue; }
        else if(pok[i]->DajDatumProdaje().DajGodinu()>pok[najranija]->DajDatumProdaje().DajGodinu()) continue;
        if(pok[i]->DajDatumProdaje().DajDan()<pok[najranija]->DajDatumProdaje().DajDan())  { najranija=i; continue; }
        else continue;
    }
    delete pok[najranija];
    pok[najranija]=nullptr;
    for(int i(0);i<ima;i++) {
        if(pok[i]==nullptr) {
            for(int j(i+1);j<ima;j++) {
                pok[j-1]=pok[j];
                if(j==ima-1) pok[j]=nullptr;
            }
            ima--;
            i--;
        }
    }
}

void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta) {
    for(int i(0);i<ima;i++) {
        if(ime_agenta==pok[i]->DajImeAgenta()) {
            delete pok[i];
            pok[i]=nullptr;
            for(int j(i+1);j<ima;j++) {
                pok[j-1]=pok[j];
                if(j==ima-1) pok[j]=nullptr;
            }
            ima--;
            i--;
        }
    }
}

void Prodaje::ObrisiProdajeNaDatum(const Datum &datum) {
    for(int i(0);i<ima;i++) {
        if(IstiDatum(pok[i]->DajDatumProdaje(), datum)) { 
            delete pok[i];
            pok[i]=nullptr;
            for(int j(i+1);j<ima;j++) {
                pok[j-1]=pok[j];
                if(j==ima-1) pok[j]=nullptr;
            }
            ima--;
            i--;
        }
    }
}

void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const {
    sort(pok,pok+ima,[](Prodaja *prod1,Prodaja *prod2) {
        return prod1->DajImeAgenta()<prod2->DajImeAgenta();
    });
    for(int i(0);i<ima;i++) {
        if(IstiDatum(pok[i]->DajDatumProdaje(),datum)) pok[i]->Ispisi();
    }
}

void Prodaje::IspisiSveProdaje() const {
    sort(pok,pok+ima, [](Prodaja *prod1, Prodaja *prod2) {
        if(prod1->DajDatumProdaje().DajGodinu()<prod2->DajDatumProdaje().DajGodinu()) return true;
        else if(prod1->DajDatumProdaje().DajGodinu()>prod2->DajDatumProdaje().DajGodinu()) return true;
        if(prod1->DajDatumProdaje().DajMjesec()<prod2->DajDatumProdaje().DajMjesec()) return true;
        else if(prod1->DajDatumProdaje().DajMjesec()>prod2->DajDatumProdaje().DajMjesec()) return false;
        if(prod1->DajDatumProdaje().DajDan()<prod2->DajDatumProdaje().DajDan()) return true;
        else if (prod1->DajDatumProdaje().DajDan()>prod2->DajDatumProdaje().DajDan()) return false;
        else {
            return prod1->DajImeKupca()<prod2->DajImeKupca();
        }
    });
    for(int i(0);i<ima;i++) {
        pok[i]->Ispisi();
    }
}

int main ()
{
	return 0;
}