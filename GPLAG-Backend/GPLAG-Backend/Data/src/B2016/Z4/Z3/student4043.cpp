/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <initializer_list>

class Datum {
        int d,m,g;
    public:
        Datum(int dan, int mjesec, int godina) {
            Postavi(dan,mjesec,godina);
        }
        void Postavi(int dan, int mjesec, int godina);
        int DajDan() const { return d; }
        int DajMjesec() const { return m; }
        int DajGodinu() const { return g; }
        void Ispisi() const { std::cout<<d<<"/"<<m<<"/"<<g; }
};

void Datum::Postavi (int dan, int mjesec, int godina) {
    int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if((godina%4==0 && godina%100!=0) || godina%400==0) broj_dana[1]++;
    if(godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>broj_dana[mjesec-1]) throw std::domain_error ("Neispravan datum");
    d=dan; m=mjesec; g=godina;
}

class Kupac {
        std::string ime_i_p;
        Datum dat;
    public:
        Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja) : dat(datum_rodjenja){
            Postavi(ime_i_prezime, datum_rodjenja);
        }
        void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
        std::string DajImePrezime() const { return ime_i_p; }
        Datum DajDatumRodjenja() const { return dat; }
        void Ispisi() const { 
            std::cout<<ime_i_p<<" (";
            dat.Ispisi();
            std::cout<<")"; 
        }
};

void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja)  {
    for(int i(0);i<ime_i_prezime.size();i++) {
        if(((ime_i_prezime[i]>'9' && ime_i_prezime[i]<'A') && (ime_i_prezime[i]!=' ' && ime_i_prezime[i]!='-' && ime_i_prezime[i]!='\'')) || (ime_i_prezime[i]>'Z' && ime_i_prezime[i]<'a') || ime_i_prezime[i]>'z')
            throw std::domain_error ("Neispravno ime i prezime");
    }
    ime_i_p=ime_i_prezime;
    dat = Datum(datum_rodjenja.DajDan(),datum_rodjenja.DajMjesec(),datum_rodjenja.DajGodinu());
}

class Stan {
        std::string adr;
        int spr,br_soba;
        bool namjest;
        double kvadr;
    public:
        Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
            Postavi(adresa,sprat,broj_soba,namjesten,kvadratura);
        }
        void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
        std::string DajAdresu() const { return adr; }
        int DajSprat() const { return spr; }
        int DajBrojSoba() const { return br_soba; }
        bool DajNamjesten() const { return namjest; }
        double DajKvadraturu() const { return kvadr; }
        void Ispisi() const;
};

void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura)  {
    if(sprat<0 || br_soba<0 || kvadratura<0) throw std::domain_error ("Neispravan unos parametara");
    spr=sprat; br_soba=broj_soba; kvadr=kvadratura;
    adr = adresa;  namjest = namjesten;
}
void Stan::Ispisi() const {
    std::cout<<"Stan se nalazi na adresi "<<adr<<" na "<<spr<<". spratu i ima ";
    if(br_soba>=5 && br_soba<=20) std::cout<<br_soba<<" soba.";
    else if(br_soba%10==1) std::cout<<br_soba<<" sobu.";
    else if(br_soba%10==2 || br_soba%10==3 || br_soba%10==4) std::cout<<br_soba<<" sobe.";
    else std::cout<<br_soba<<" soba.";
    std::cout<<"Kvadratura stana je "<<kvadr<<" (m^2) i stan ";
    if(namjest) std::cout<<"je namjesten.";
    else std::cout<<"nije namjesten.";
}

class Prodaja {
        std::string ime_agenta;
        double cijena;
        Datum dat_prodaje;
        Kupac kupac;
        Stan stan;
    public:
        Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan) : 
            ime_agenta(ime_agenta_prodaje), cijena(cijena_stana), 
            dat_prodaje(datum_prodaje.DajDan(),datum_prodaje.DajMjesec(),datum_prodaje.DajGodinu()), 
            kupac(kupac_stana.DajImePrezime(),kupac_stana.DajDatumRodjenja()), 
            stan(kupljeni_stan.DajAdresu(),kupljeni_stan.DajSprat(),kupljeni_stan.DajBrojSoba(),kupljeni_stan.DajNamjesten(),kupljeni_stan.DajKvadraturu()) { }
        Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) :
            ime_agenta(ime_agenta_prodaje), cijena(cijena_stana),
            dat_prodaje(dan_prodaje,mjesec_prodaje,godina_prodaje),
            kupac(ime_kupca,datum_rodjenja_kupca),
            stan(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata) { }
        void PromijeniKupca(const Kupac &novi_kupac) { kupac=novi_kupac; }
        void PromijeniStan(const Stan &novi_stan) { stan=novi_stan; }
        void PromijeniDatumKupovine(const Datum &novi_datum) { dat_prodaje=novi_datum; }
        void PromijeniCijenuProdaje(const double &nova_cijena) { cijena=nova_cijena; }
        void PomjeriDanUnaprijed() {
            int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
            if((dat_prodaje.DajGodinu()%4==0 && dat_prodaje.DajGodinu()%100!=0) || dat_prodaje.DajGodinu()%400==0) broj_dana[1]++;
            if(dat_prodaje.DajDan()==broj_dana[dat_prodaje.DajMjesec()]) {
                if(dat_prodaje.DajMjesec()==12) dat_prodaje.Postavi(1,1,dat_prodaje.DajGodinu()+1);
                else dat_prodaje.Postavi(1,dat_prodaje.DajMjesec()+1,dat_prodaje.DajGodinu());
            }
            else dat_prodaje.Postavi(dat_prodaje.DajDan()+1,dat_prodaje.DajMjesec(),dat_prodaje.DajGodinu());
        }
        void PomjeriDanUnazad() {
            int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
            if((dat_prodaje.DajGodinu()%4==0 && dat_prodaje.DajGodinu()%100!=0) || dat_prodaje.DajGodinu()%400==0) broj_dana[1]++;
            if(dat_prodaje.DajDan()==1) {
                if(dat_prodaje.DajMjesec()==1) dat_prodaje.Postavi(31,12,dat_prodaje.DajGodinu()-1);
                else dat_prodaje.Postavi(31,dat_prodaje.DajMjesec()-1,dat_prodaje.DajGodinu());
            }
            else dat_prodaje.Postavi(dat_prodaje.DajDan()-1,dat_prodaje.DajMjesec(),dat_prodaje.DajGodinu());
        }
        std::string DajImeAgenta() const { return ime_agenta; }
        std::string DajImeKupca() const { return kupac.DajImePrezime(); }
        Datum DajDatumProdaje() const { return dat_prodaje; }
        double DajCijenuStana() const { return cijena; }
        
        //PRODAT PRIJE !!!!!!!!!!
        
        friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
        friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2) {
            if(p1.DajCijenuStana()>p2.DajCijenuStana()) return true;
            return false;
        }
        void Ispisi() const {
            std::cout<<"Ime agenta: "<<DajImeAgenta()<<std::endl;
            std::cout<<"Ime kupca: ";
            kupac.Ispisi();
            std::cout<<"\nZakazani datum prodaje: ";
            dat_prodaje.Ispisi();
            std::cout<<"\nCijena stana: "<<cijena<<std::endl;
            std::cout<<"Informacije o stanu: "<<std::endl;
            stan.Ispisi();
        }
};

class Prodaje {
        const int max_broj_prodaja;
        int trenutni_br_prodaja;
        Prodaja **pok=nullptr;


    public:
        explicit Prodaje(int max_broj_prodaja) : max_broj_prodaja(max_broj_prodaja) {
            pok=new Prodaja *[max_broj_prodaja]{nullptr};
            trenutni_br_prodaja=0;
        }
        Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
        ~Prodaje() {
            IsprazniKolekciju();
            delete[] pok;
        }
        Prodaje(const Prodaje &prodaje);
        Prodaje(Prodaje &&prodaje);
        Prodaje &operator =(const Prodaje &prodaje);
        Prodaje &operator =(Prodaje &&prodaje);
        void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
        void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
        void RegistrirajProdaju(Prodaja *prodaja) { 
            if(trenutni_br_prodaja<max_broj_prodaja) {
                pok[trenutni_br_prodaja]=prodaja; 
                trenutni_br_prodaja++; 
            }
            else throw std::range_error ("Dostignut maksimalni broj prodaja");
        }
        int DajBrojProdaja() const { return trenutni_br_prodaja; }
        int DajBrojProdajaNaDatum(const Datum &datum) const {
            int broj = 0;
            broj = std::count_if(pok[0],pok[trenutni_br_prodaja], [datum](Prodaja prod){ if(prod.DajDatumProdaje().DajDan() == datum.DajDan() && prod.DajDatumProdaje().DajMjesec() == datum.DajMjesec() && prod.DajDatumProdaje().DajGodinu() == datum.DajGodinu()) return true; else return false;});
            return broj;
        }
        int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const {
            int br(0);
            for(int i(0);i<trenutni_br_prodaja;i++) {
                if(pok[i]->DajImeAgenta()==ime_agenta) br++;
            }
            return br;
        }
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

Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja) : max_broj_prodaja(spisak_prodaja.size()), trenutni_br_prodaja(spisak_prodaja.size()), pok(new Prodaja *[spisak_prodaja.size()]) {
    std::copy(spisak_prodaja.begin(),spisak_prodaja.end(),*pok); // FALI LAMBDA FUNKCIJA, USTVARI NE ZNAM STA FALI NE FALI LAMBDA
}
Prodaje::Prodaje(const Prodaje &prodaje) : max_broj_prodaja(prodaje.max_broj_prodaja), trenutni_br_prodaja(prodaje.trenutni_br_prodaja), pok(new Prodaja *[prodaje.max_broj_prodaja]) {
    std::copy(prodaje.pok,prodaje.pok+prodaje.max_broj_prodaja,pok);
}
Prodaje::Prodaje(Prodaje &&prodaje) {
    
}
Prodaje &operator =(const Prodaje &prodaje);
        Prodaje &operator =(Prodaje &&prodaje);
void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan) {
    if(trenutni_br_prodaja<max_broj_prodaja) {
        pok[trenutni_br_prodaja]=new Prodaja(ime_agenta_prodaje,cijena_stana,datum_prodaje,kupac_stana,kupljeni_stan);
        trenutni_br_prodaja++;
    }
    else throw std::range_error ("Dostignut maksimalni broj prodaja");
}
void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) {
    if(trenutni_br_prodaja<max_broj_prodaja) {
        pok[trenutni_br_prodaja]=new Prodaja(ime_agenta_prodaje,cijena_stana,dan_prodaje,mjesec_prodaje,godina_prodaje,ime_kupca,datum_rodjenja_kupca,adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata);
        trenutni_br_prodaja++;
    }
    else throw std::range_error ("Dostignut maksimalni broj prodaja");
}
Prodaja &Prodaje::DajNajranijuProdaju() {
    if(trenutni_br_prodaja==0) throw std::domain_error ("Nema registriranih prodaja");
    return *std::min_element(pok[0],pok[trenutni_br_prodaja], [](Prodaja &prod1, Prodaja &prod2) { Datum dat1 = prod1.DajDatumProdaje();
                                                                                        Datum dat2 = prod2.DajDatumProdaje();
                                                                                        if(dat1.DajGodinu()<dat2.DajGodinu()) return true;
                                                                                        else if(dat1.DajGodinu()==dat2.DajGodinu() && dat1.DajMjesec()<dat2.DajMjesec()) return true;
                                                                                        else if(dat1.DajGodinu()==dat2.DajGodinu() && dat1.DajMjesec()==dat2.DajMjesec() && dat1.DajDan()<dat2.DajDan()) return true;
                                                                                        return false;});
    //return p;
}
Prodaja Prodaje::DajNajranijuProdaju() const {
    if(trenutni_br_prodaja==0) throw std::domain_error ("Nema registriranih prodaja");
    return *std::min_element(pok[0],pok[trenutni_br_prodaja], [](Prodaja prod1,Prodaja prod2) { Datum dat1 = prod1.DajDatumProdaje();
                                                                                        Datum dat2 = prod2.DajDatumProdaje();
                                                                                        if(dat1.DajGodinu()<dat2.DajGodinu()) return true;
                                                                                        else if(dat1.DajGodinu()==dat2.DajGodinu() && dat1.DajMjesec()<dat2.DajMjesec()) return true;
                                                                                        else if(dat1.DajGodinu()==dat2.DajGodinu() && dat1.DajMjesec()==dat2.DajMjesec() && dat1.DajDan()<dat2.DajDan()) return true;
                                                                                        return false;});
}
Prodaja &Prodaje::DajNajskupljuProdaju() {
    if(trenutni_br_prodaja==0) throw std::domain_error ("Nema registriranih prodaja");
    return *std::max_element(pok[0],pok[trenutni_br_prodaja], [](Prodaja p1, Prodaja p2){ if(p1.DajCijenuStana()>p2.DajCijenuStana()) return true; return false; });
}
Prodaja Prodaje::DajNajskupljuProdaju() const {
    if(trenutni_br_prodaja==0) throw std::domain_error ("Nema registriranih prodaja");
    return *std::max_element(pok[0],pok[trenutni_br_prodaja], [](Prodaja p1, Prodaja p2){ if(p1.DajCijenuStana()>p2.DajCijenuStana()) return true;
                                                                                         return false; });
}
void Prodaje::IsprazniKolekciju(){
    for(int i = 0; i < trenutni_br_prodaja; i ++)
        delete pok[i];
    trenutni_br_prodaja = 0;
}
void Prodaje::ObrisiNajranijuProdaju() {
    if(trenutni_br_prodaja==0) throw std::range_error ("Prazna kolekcija");
    Prodaja *pr(&DajNajranijuProdaju());
    for(int i = 0; i < trenutni_br_prodaja; i++)
    {
        if(pok[i] == pr)
        {
            for(int j = i; j < trenutni_br_prodaja-1; j ++)
                pok[j] = pok[j+1];
            break;
        }
    }
    delete pr;
    trenutni_br_prodaja--;
    
}
void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta){
    for(int i(0); i < trenutni_br_prodaja; i ++) {
        if(pok[i]->DajImeAgenta()==ime_agenta) {
            Prodaja *temp = pok[i];
            for(int j=i ; j < trenutni_br_prodaja - 1; j++) pok[j] = pok[j+1];
            delete temp;
            trenutni_br_prodaja--;
        }
    }
}
void Prodaje::ObrisiProdajeNaDatum(const Datum &datum){
    for(int i(0);i<trenutni_br_prodaja;i++) {
        if(pok[i]->DajDatumProdaje().DajDan()==datum.DajDan() && pok[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec() && pok[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu()) {
            Prodaja *temp=pok[i];
            for(int j=i;j<trenutni_br_prodaja-1;j++) pok[j]=pok[j+1];
            delete temp;
            trenutni_br_prodaja--;
        }
    }
}
void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const {
    for(int i(0);i<trenutni_br_prodaja;i++) {
        if(pok[i]->DajDatumProdaje().DajDan()==datum.DajDan() && pok[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec() && pok[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu()) {
            pok[i]->Ispisi();
        }
    }
}
void Prodaje::IspisiSveProdaje() const {
    for(int i(0);i<trenutni_br_prodaja;i++) {
        pok[i]->Ispisi();
    }
}
int main ()
{
	return 0;
}