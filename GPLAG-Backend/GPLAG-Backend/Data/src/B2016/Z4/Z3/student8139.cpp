/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <algorithm>

class Datum{
    int d, m, g;
    void TestDatuma(int dan, int mjesec, int godina) const{
        int broj_dana[]{31,28,31,30,31,30,31,31,30,31,30,31};
        if((godina%4==0 && godina%100!=0) || godina%400==0) broj_dana[1]++;
        if(godina<1 || dan < 1 || mjesec<1 || mjesec>12 || dan>broj_dana[mjesec-1])
            throw std::domain_error("Neispravan datum");
    }
public:
    Datum(int dan, int mjesec, int godina) : d(dan), m(mjesec), g(godina) {TestDatuma(dan,mjesec,godina);}
    void Postavi(int dan, int mjesec, int godina){TestDatuma(dan,mjesec,godina); d=dan; m=mjesec; g=godina; }
    int DajDan() const{ return d; }
    int DajMjesec() const{ return m; }
    int DajGodinu() const{return g; }
    void Ispisi() const{ std::cout << "(" << DajDan() << "/" << DajMjesec() << "/" << DajGodinu() << ")" ; }
};

class Kupac{
    std::string ime;
    Datum datum;
public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja) : ime(ime_i_prezime), datum(datum_rodjenja) {}
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja){ ime=ime_i_prezime; datum=datum_rodjenja; }
    std::string DajImePrezime() const{ return ime; }
    Datum DajDatumRodjenja() const{ return datum; }
    void Ispisi() const{ std::cout << DajImePrezime() << " " ; datum.Ispisi() ; }
};

class Stan{
    std::string address;
    int sprat, broj_soba;
    bool namjesten;
    double kvadratura;
public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) : 
    address(adresa), sprat(sprat), broj_soba(broj_soba), namjesten(namjesten), kvadratura(kvadratura) {
        if(sprat<0 || broj_soba<0 || kvadratura<0) throw std::domain_error("Neispravan unos podataka");
    }
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
        address=adresa; this->sprat=sprat; this->broj_soba=broj_soba; this->namjesten=namjesten; this->kvadratura=kvadratura;
    }
    std::string DajAdresu() const{ return address; }
    int DajSprat() const{ return sprat; }
    int DajBrojSoba() const{ return broj_soba; }
    bool DajNamjesten() const{ return namjesten; }
    double DajKvadraturu() const{ return kvadratura; }
    void Ispisi() const{
        std::cout << "Stan se nalazi na adresi "<< DajAdresu()<< " na " << DajSprat() << ". spratu i ima " << DajBrojSoba() << " soba." << std::endl;
        if(namjesten) std::cout << "Kvadratura stana je " << DajKvadraturu() << " (m^2) i stan je namjesten." << std::endl;
        else std::cout << "Kvadratura stana je " << DajKvadraturu() << " (m^2) i stan nije namjesten." << std::endl;
    }
};

class Prodaja{
    std::string ime_agenta;
    double cijena;
    Datum dat_prodaje;
    Kupac kupac;
    Stan stan;
    
public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,
        const Stan &kupljeni_stan) : ime_agenta(ime_agenta_prodaje), cijena(cijena_stana), dat_prodaje(datum_prodaje), kupac(kupac_stana), stan(kupljeni_stan) {}
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
        std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba,
        bool namjesten_stan, double broj_kvadrata) : ime_agenta(ime_agenta_prodaje), cijena(cijena_stana), 
        dat_prodaje(dan_prodaje,mjesec_prodaje,godina_prodaje), kupac(ime_kupca,datum_rodjenja_kupca), 
        stan(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata) {}
    void PromijeniKupca(const Kupac &novi_kupac){ kupac=novi_kupac; }
    void PromijeniStan(const Stan &novi_stan){ stan=novi_stan; }
    void PromijeniDatumKupovine(const Datum &novi_datum){ dat_prodaje=novi_datum; }
    void PromijeniCijenuProdaje(const double &nova_cijena){ cijena=nova_cijena; }
    void PomjeriDanUnaprijed(){
        int novi_dan, novi_mjesec, nova_godina;
        nova_godina=dat_prodaje.DajGodinu();
        novi_mjesec=dat_prodaje.DajMjesec();
        novi_dan=dat_prodaje.DajDan()+1;
        int broj_dana[]{31,28,31,30,31,30,31,31,30,31,30,31};
        if(nova_godina%4==0 && ( nova_godina%100 !=0 || nova_godina%400==0)){
            broj_dana[1]++;
        }
        if(novi_dan>broj_dana[novi_mjesec-1]){ novi_dan=1; novi_mjesec++; }
        if(novi_mjesec>12){ novi_mjesec=1; nova_godina++; }
        dat_prodaje.Postavi(novi_dan,novi_mjesec,nova_godina);
    }
    void PomjeriDanUnazad(){
        int novi_dan, novi_mjesec, nova_godina;
        nova_godina=dat_prodaje.DajGodinu();
        novi_mjesec=dat_prodaje.DajMjesec();
        novi_dan=dat_prodaje.DajDan()-1;
        int broj_dana[]{31,28,31,30,31,30,31,31,30,31,30,31};
        if(nova_godina%4==0 && ( nova_godina%100 !=0 || nova_godina%400==0)){
            broj_dana[1]++;
        }
        if(novi_dan<1){ novi_mjesec--; if(novi_mjesec<1) {novi_mjesec=12; nova_godina--;} novi_dan=broj_dana[novi_mjesec-1];}
        dat_prodaje.Postavi(novi_dan, novi_mjesec, nova_godina);
    }
    std::string DajImeAgenta() const{ return ime_agenta; }
    std::string DajImeKupca() const{ return kupac.DajImePrezime(); }
    Datum DajDatumProdaje() const{ return dat_prodaje; }
    double DajCijenuStana() const{ return cijena; }
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2){
        if(p1.DajDatumProdaje().DajGodinu()>p2.DajDatumProdaje().DajGodinu()) return true;
        else if(p1.DajDatumProdaje().DajMjesec()>p2.DajDatumProdaje().DajMjesec()) return true;
        else if(p1.DajDatumProdaje().DajDan()>p2.DajDatumProdaje().DajDan()) return true;
        return false;
    }
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2){ return p1.DajCijenuStana()>p2.DajCijenuStana(); }
    void Ispisi() const{
        std::cout << std::left << "Ime agenta: " << std::setw(30); std::cout << std::right << DajImeAgenta() << std::endl;
        std::cout << std::left << "Ime kupca: " << std::setw(30); kupac.Ispisi() ; std::cout << std::endl;
        std::cout << "Zakazani datum prodaje: " ; dat_prodaje.Ispisi() ; std::cout << std::endl;
        std::cout << "Cijena stana: " << DajCijenuStana() << std::endl;
        std::cout << "Informacije o stanu: " << std::endl;
        stan.Ispisi();
    }
};

class Prodaje{
    int max_broj_prodaja; 
    int broj_prodaja;
    Prodaja** pok;
    void Alociraj();
    void Dealociraj();
    bool PrijeIme(std::string ime1, std::string ime2) const{
        for(auto &c : ime1) c=tolower(c);
        for(auto &c : ime2) c=tolower(c);
        for(int i=0; i<ime1.length(); i++){
            if(ime1[i]<ime2[i]) return true;
        }
        return false;
    }
public:
    explicit Prodaje(int max_broj_prodaja);
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
    ~Prodaje();
    Prodaje(const Prodaje &prodaje);
    Prodaje(Prodaje &&prodaje);
    Prodaje &operator =(const Prodaje &prodaje);
    Prodaje &operator =(Prodaje &&prodaje);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
        const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void RegistrirajProdaju(Prodaja *prodaja);
    int DajBrojProdaja() const;
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

void Prodaje::Alociraj(){
    pok=new Prodaja*[max_broj_prodaja];
    for(int i=0; i<max_broj_prodaja; i++) pok[i]=nullptr;
}

void Prodaje::Dealociraj(){
    if(pok==nullptr) return;
    for(int i=0; i<broj_prodaja; i++) delete pok[i];
    delete[] pok;
    pok=nullptr;
    broj_prodaja=0;
}

Prodaje::Prodaje(int max_broj_prodaja) : max_broj_prodaja(max_broj_prodaja), broj_prodaja(0), pok(nullptr){ Alociraj(); }

Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja) : max_broj_prodaja(spisak_prodaja.size()), broj_prodaja(0) {
    Alociraj();
    for(auto it=spisak_prodaja.begin(); it != spisak_prodaja.end(); it++){
        pok[broj_prodaja]=new Prodaja(*it);
        broj_prodaja++;
    }
}

Prodaje::~Prodaje(){ Dealociraj(); }

/*Prodaje::Prodaje(const Prodaje &prodaje) : broj_prodaja(prodaje.broj_prodaja), max_broj_prodaja(prodaje.max_broj_prodaja){
    Alociraj();
    for(int i=0; i<broj_prodaja; i++)
        pok[i]= new Prodaja(prodaje.pok[i]->DajImeAgenta(), prodaje.pok[i]->DajCijenuStana(), prodaje.pok[i]->DajDatumProdaje(),
        prodaje.pok[i]->Daj)
}*/

Prodaje::Prodaje(Prodaje &&prodaje){
    pok=prodaje.pok;
    broj_prodaja=prodaje.broj_prodaja;
    max_broj_prodaja=prodaje.max_broj_prodaja;
    prodaje.pok=nullptr;
}

Prodaje &Prodaje::operator =(const Prodaje &prodaje){
    if(this==&prodaje) return *this;
    Dealociraj();
    max_broj_prodaja=prodaje.max_broj_prodaja;
    broj_prodaja=prodaje.broj_prodaja;
    Alociraj();
    for(int i=0; i<broj_prodaja; i++) pok[i]= new Prodaja(*prodaje.pok[i]);
    return *this;
}

Prodaje &Prodaje::operator =(Prodaje &&prodaje){
    Dealociraj();
    pok=prodaje.pok;
    max_broj_prodaja=prodaje.max_broj_prodaja;
    broj_prodaja=prodaje.broj_prodaja;
    prodaje.pok=nullptr;
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,const Stan &kupljeni_stan){
    if(broj_prodaja==max_broj_prodaja) throw std::range_error("Dostignut maksimalni broj prodaja");
    pok[broj_prodaja] = new Prodaja(ime_agenta_prodaje,cijena_stana,datum_prodaje,kupac_stana,kupljeni_stan);
    broj_prodaja++;
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
    const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata){
        if(broj_prodaja==max_broj_prodaja) throw std::range_error("Dostignut maksimalni broj prodaja");
        pok[broj_prodaja] = new Prodaja(ime_agenta_prodaje, cijena_stana, dan_prodaje, mjesec_prodaje, godina_prodaje, ime_kupca, datum_rodjenja_kupca, 
                                        adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata);
        broj_prodaja++;
    }

void Prodaje::RegistrirajProdaju(Prodaja *prodaja){
    if(broj_prodaja==max_broj_prodaja) throw std::range_error("Dostignut maksimalni broj prodaja");
    pok[broj_prodaja] = new Prodaja(*prodaja);
    broj_prodaja++;
}

int Prodaje::DajBrojProdaja() const{
    return broj_prodaja;
}

int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const{
    if(broj_prodaja==0) throw std::domain_error("Nema registriranih prodaja");
    return std::count_if(pok, pok+broj_prodaja, [datum](Prodaja *p){
        return (p->DajDatumProdaje().DajGodinu()==datum.DajGodinu() && p->DajDatumProdaje().DajMjesec()==datum.DajMjesec() && p->DajDatumProdaje().DajDan()==datum.DajDan());
    });
}

int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const{
    if(broj_prodaja==0) throw std::domain_error("Nema registriranih prodaja");
    return std::count_if(pok, pok+broj_prodaja, [ime_agenta](Prodaja *p){
        return p->DajImeAgenta()==ime_agenta;
    });
}

Prodaja &Prodaje::DajNajranijuProdaju(){
    if(broj_prodaja==0) throw std::domain_error("Nema registriranih prodaja");
    auto najmanji = std::min_element(pok,pok+broj_prodaja,[](Prodaja *p1, Prodaja *p2){
        return ProdatPrije(*p1,*p2);
    });
    return **najmanji;
}

Prodaja Prodaje::DajNajranijuProdaju() const{
    if(broj_prodaja==0) throw std::domain_error("Nema registriranih prodaja");
    auto najmanji = std::min_element(pok,pok+broj_prodaja, [](Prodaja *p1, Prodaja *p2){
        return ProdatPrije(*p1,*p2);
    });
    return **najmanji;
}

Prodaja &Prodaje::DajNajskupljuProdaju(){
    if(broj_prodaja==0) throw std::domain_error("Nema registriranih prodaja");
    auto najveci = std::max_element(pok, pok+broj_prodaja, [](Prodaja *p1, Prodaja *p2){
        return SkupljiStan(*p1,*p2); 
    });
    return **najveci;
}

Prodaja Prodaje::DajNajskupljuProdaju() const{
    if(broj_prodaja==0) throw std::domain_error("Nema registriranih prodaja");
    auto najveci = std::max_element(pok, pok+broj_prodaja, [](Prodaja *p1, Prodaja *p2){
        return SkupljiStan(*p1,*p2); 
    });
    return **najveci;
}

void Prodaje::IsprazniKolekciju(){
    for(int i=0; i<max_broj_prodaja; i++) delete pok[i];
    delete[] pok;
    pok=nullptr;
}
/*
void Prodaje::ObrisiNajranijuProdaju(){
    if(broj_prodaja==0) throw std::range_error("Prazna kolekcija");
    auto najraniji(DajNajranijuProdaju());
    for(int i=0; i<broj_prodaja; i++){
        if(pok[i]==najraniji){
            delete najraniji;
            for(int j=i+1; j<broj_prodaja; j++) pok[j-1]=pok[j];
            broj_prodaja--;
        }
    }
}
*/
void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta){
    if(broj_prodaja==0) throw std::range_error("Prazna kolekcija");
    for(int i=0; i<broj_prodaja; i++){
        if(pok[i]->DajImeAgenta()==ime_agenta){
            delete pok[i];
            for(int j=i+1; j<broj_prodaja; j++) pok[j-1]=pok[j];
            broj_prodaja--; i--;
        }
    }
}

void Prodaje::ObrisiProdajeNaDatum(const Datum &datum){
    if(broj_prodaja==0) throw std::range_error("Prazna kolekcija");
    for(int i=0; i<broj_prodaja; i++){
        if(pok[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu() && pok[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec() && 
        pok[i]->DajDatumProdaje().DajDan()==datum.DajDan()){
            delete pok[i];
            for(int j=i+1; j<broj_prodaja; j++) pok[j-1]=pok[j];
            broj_prodaja--; i--;
        }
    }
}
/*
void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const{
    std::sort(pok,pok+broj_prodaja, [](Prodaja *p1, Prodaja *p2){
        return PrijeIme(p1->DajImeKupca(),p2->DajImeKupca());
    });
    for(int i=0; i<broj_prodaja; i++){
        if(pok[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu() && pok[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec() && 
        pok[i]->DajDatumProdaje().DajDan()==datum.DajDan()) pok[i]->Ispisi();
    }
}

void Prodaje::IspisiSveProdaje() const{
    std::sort(pok,pok+broj_prodaja, [](Prodaja *p1, Prodaja *p2){
        if(p1->DajDatumProdaje().DajGodinu()>p2->DajDatumProdaje().DajGodinu()) return true;
        else{
            if(p1->DajDatumProdaje().DajMjesec()>p2->DajDatumProdaje().DajMjesec()) return true;
            else{
                if(p1->DajDatumProdaje().DajDan()>p2->DajDatumProdaje().DajDan()) return true;
                else{
                    if(PrijeIme(p1->DajImeKupca(),p2->DajImeKupca())) return true;
                    else return false;
                }
            }
        }
    });
}
*/
int main ()
{
	std::string s("Prodavac");
	Datum dat(14,10,1996);
	
	std::string h("Hasan Hadzagic");
	Kupac ja(h,dat);
	//ja.Ispisi();
	std::string adresaaa("24 juni br 30");
	Stan nas(adresaaa, 4, 3, true, 67.56);
	//nas.Ispisi();
	Prodaja p(s,100000,dat,ja,nas);
	p.PomjeriDanUnaprijed();
	p.Ispisi();
	
	return 0;
}