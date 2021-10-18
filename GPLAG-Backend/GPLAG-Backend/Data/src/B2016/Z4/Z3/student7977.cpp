/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <algorithm>

class Datum {
    int dan;
    int mjesec;
    int godina;
public:
    Datum(int d, int m, int g){ Postavi(d, m, g); }
    Datum(const Datum &d){ dan = d.dan; mjesec = d.mjesec; godina = d.godina; }
    void Postavi(int dan, int mjesec, int godina);
    int DajDan() const { return dan; }
    int DajMjesec() const { return mjesec; }
    int DajGodinu() const { return godina; }
    void Ispisi() const{ 
        std::cout << dan << "/" << mjesec << "/" << godina;
    }
};

void Datum::Postavi(int d, int m, int g){
    std::vector<int> broj_dana{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(g%4==0 && (g%100!=0 || g%400==0)) broj_dana[1]++;
    if(g<1 || d<1 || m<1 || m>12 || d>broj_dana[m-1]){
        throw std::domain_error("Neispravan datum");
    }
    dan = d; mjesec = m; godina = g;
}



class Kupac {
    std::string ime_i_prezime;
    Datum datum_rodjenja;
public:
    Kupac(const std::string &i_i_p, const Datum &d_r);
    void Postavi(const std::string &i_i_p, const Datum &d_r);
    std::string DajImePrezime() const{ return ime_i_prezime; }
    Datum DajDatumRodjenja() const { return datum_rodjenja; }
    void Ispisi() const{
        std::cout << ime_i_prezime << "(";
        datum_rodjenja.Ispisi();
        std::cout << ")" << std::endl;
    }
};

Kupac::Kupac(const std::string &i_i_p, const Datum &d_r) : datum_rodjenja(d_r) {
    for(int i=0; i<i_i_p.length(); i++){
        if(!((i_i_p[i]>='A' && i_i_p[i]<='Z')||(i_i_p[i]>='a' && i_i_p[i]<='z')||(i_i_p[i]>='0' && i_i_p[i]<='9')||i_i_p[i]==' '||i_i_p[i]=='-'||i_i_p[i]==39)){
            throw std::domain_error("Neispravano ime i prezime");
        }
    }
    ime_i_prezime = i_i_p;
}

void Kupac::Postavi(const std::string &i_i_p, const Datum &d_r){
    for(int i=0; i<i_i_p.length(); i++){
        if(!((i_i_p[i]>='A' && i_i_p[i]<='Z')||(i_i_p[i]>='a' && i_i_p[i]<='z')||(i_i_p[i]>='0' && i_i_p[i]<='9')||i_i_p[i]==' '||i_i_p[i]=='-'||i_i_p[i]== 39)){
            throw std::domain_error("Neispravano ime i prezime");
        }
    }
    ime_i_prezime = i_i_p;
    datum_rodjenja = d_r;
}

class Stan {
    std::string adresa;
    int sprat;
    int broj_soba;
    bool namjesten;
    double kvadratura;
public: 
    Stan(const std::string &a, int s, int b_s, bool n, double k);
    void Postavi(const std::string &adresa, int sprat, int broj_soba,bool namjesten, double kvadratura);
    std::string DajAdresu() const{ return adresa; }
    int DajSprat() const{ return sprat; }
    int DajBrojSoba() const{ return broj_soba; }
    bool DajNamjesten() const{ return namjesten; }
    double DajKvadraturu()  const{ return kvadratura; }
    void Ispisi() const;
};

Stan::Stan(const std::string &a, int s, int b_s, bool n, double k){
    if(s<0 || b_s<0 || k<0) throw std::domain_error("Nispravan unos podataka");
    adresa = a; sprat = s; broj_soba = b_s; namjesten = n; kvadratura = k;
}

void Stan::Postavi(const std::string &a, int s, int b_s, bool n, double k){
    if(s<0 || b_s<0 || k<0) throw std::domain_error("Nispravan unos podataka");
    adresa = a; sprat = s; broj_soba = b_s; namjesten = n; kvadratura = k;
}

void Stan::Ispisi() const{
        std::cout << "Stan se nalazi na adresi " << adresa << " na " << sprat << ". spratu" << " i ima ";
        if(broj_soba % 10 == 1) std::cout << broj_soba << " sobu.";
        else if(broj_soba % 10 == 2 || broj_soba %10 == 3 || broj_soba % 10 == 4) std::cout << broj_soba << " sobe.";
        else std::cout << broj_soba << " soba.";
        std::cout << " Kvadratura stana je " << kvadratura << " (m^2) i stan ";
        if(namjesten) std::cout << "je namjesten.";
        else std ::cout << "nije namjesten.";
}

class Prodaja {
    std::string ime_agenta_prodaje;
    double cijena_stana;
    Datum datum_prodaje;
    Kupac kupac_stana;
    Stan kupljeni_stan;
    
public: 
    Prodaja(const std::string &i_a_p, double c_s, const Datum &d_p, const Kupac &kupac_s, const Stan &kupljeni_s) : ime_agenta_prodaje(i_a_p), cijena_stana(c_s), datum_prodaje(d_p), kupac_stana(kupac_s), kupljeni_stan(kupljeni_s){}
    Prodaja(const std::string &i_a_p, double c_s, int dan_p, int m_p, int g_p, std::string &ime_k, const Datum &d_r_k, const std::string &a_s, int s_s, int b_s, bool n_s, double b_k) : datum_prodaje(dan_p, m_p, g_p), kupac_stana(ime_k, d_r_k), kupljeni_stan(a_s, s_s, b_s, n_s, b_k){
        ime_agenta_prodaje = i_a_p; cijena_stana = c_s; 
    }
    void PromijeniAgentaProdaje(std::string i_a_p){ ime_agenta_prodaje = i_a_p; }
    void PromijeniKupca(const Kupac &novi_kupac){
        kupac_stana.Postavi(novi_kupac.DajImePrezime(), novi_kupac.DajDatumRodjenja());
    } 
    void PromijeniStan(const Stan &novi_stan){
        kupljeni_stan.Postavi(novi_stan.DajAdresu(), novi_stan.DajSprat(), novi_stan.DajBrojSoba(), novi_stan.DajNamjesten(), novi_stan.DajKvadraturu());
    }
    void PromijeniDatumKupovine(const Datum &novi_datum){
        datum_prodaje.Postavi(novi_datum.DajDan(), novi_datum.DajMjesec(), novi_datum.DajGodinu());
    }
    void PromijeniCijenuProdaje(const double &nova_cijena){ cijena_stana = nova_cijena; }
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImeAgenta() const { return ime_agenta_prodaje; }
    std::string DajImeKupca() const{ return kupac_stana.DajImePrezime(); }
    Kupac DajKupca() const{ return kupac_stana; }
    Datum DajDatumProdaje() const { return datum_prodaje; }
    double DajCijenuStana() const { return cijena_stana; }
    Stan DajStan() const { return kupljeni_stan; }
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
    void Ispisi() const;
};

void Prodaja::PomjeriDanUnaprijed(){
    int d(datum_prodaje.DajDan()), m(datum_prodaje.DajMjesec()), g(datum_prodaje.DajGodinu());
    std::vector<int> broj_dana{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(g%4==0 && (g%100!=0 || g%400==0)) broj_dana[1]++;
    d++;
    if(d>broj_dana[m-1]){
        if(m == 12){ d=1; m=1; g++; }
        else{ d=1; m++; }
    }
    datum_prodaje.Postavi(d, m, g);
}

void Prodaja::PomjeriDanUnazad(){
    int d(datum_prodaje.DajDan()), m(datum_prodaje.DajMjesec()), g(datum_prodaje.DajGodinu());
    std::vector<int> broj_dana{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(g%4==0 && (g%100!=0 || g%400==0)) broj_dana[1]++;
    d--;
    if(d<1){
        if(m == 1) { d=broj_dana[11]; m=12; g--; }
        else { d=broj_dana[m-1]; m--; }
    }
    datum_prodaje.Postavi(d, m, g);
}

bool ProdatPrije(const Prodaja &p1, const Prodaja &p2){
    if((p1.datum_prodaje).DajGodinu() < (p2.datum_prodaje).DajGodinu()) return true;
    else if((p1.datum_prodaje).DajGodinu() == (p2.datum_prodaje).DajGodinu()){
        if((p1.datum_prodaje).DajMjesec() < (p2.datum_prodaje).DajMjesec()) return true;
        else if((p1.datum_prodaje).DajMjesec() == (p2.datum_prodaje).DajMjesec()){
            if((p1.datum_prodaje).DajDan() < (p2.datum_prodaje).DajDan()) return true;
        }
    } 
    return false;
}

bool SkupljiStan(const Prodaja &p1, const Prodaja &p2){
    if(p1.cijena_stana < p2.cijena_stana) return true;
    return false;
}

void Prodaja::Ispisi() const{
    std::cout << "Ime agenta:                     " <<  ime_agenta_prodaje << std::endl;
    std::cout << "Ime kupca:                      " << kupac_stana.DajImePrezime() << std::endl;
    std::cout << "Zakazani datum prodaje:         ";
    datum_prodaje.Ispisi();
    std::cout << std::endl;
    std::cout << "Cijena stana:                   " << cijena_stana << std::endl;
    std::cout << "Informacije o stanu:            " << std::endl;
    kupljeni_stan.Ispisi();
    std::cout << std::endl;
}

class Prodaje {
    int max_broj_prodaja;
    int broj_prodaja;
    Prodaja** prodaje_se;
public:
    explicit Prodaje(int m_b_p) : max_broj_prodaja(m_b_p), broj_prodaja(0), prodaje_se(new Prodaja* [max_broj_prodaja]) {}
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja) : max_broj_prodaja(spisak_prodaja.size()), broj_prodaja(spisak_prodaja.size()), prodaje_se(new Prodaja* [max_broj_prodaja]){
        int i(0);
        for(Prodaja x : spisak_prodaja){
            prodaje_se[i] = new Prodaja(x);
            i++;
        }
    }
    Prodaja* begin(){ return *prodaje_se; }
	Prodaja* end(){ return *(prodaje_se + broj_prodaja); }
    ~Prodaje();
    Prodaje(const Prodaje &prodaje);
    Prodaje(Prodaje &&prodaje);
    Prodaje &operator =(const Prodaje &prodaje);
    Prodaje &operator =(Prodaje &&prodaje);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan){
        if(max_broj_prodaja == broj_prodaja) throw std::range_error("Dostignut maksimalan broj prodaja");
        prodaje_se[broj_prodaja] = new Prodaja(ime_agenta_prodaje,cijena_stana, datum_prodaje, kupac_stana, kupljeni_stan);
        broj_prodaja++;
    }
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana,int dan_prodaje,int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata){
        if(max_broj_prodaja == broj_prodaja) throw std::range_error("Dostignut maksimalan broj prodaja");
        prodaje_se[broj_prodaja] = new Prodaja(ime_agenta_prodaje, cijena_stana, dan_prodaje, mjesec_prodaje, godina_prodaje, ime_kupca, datum_rodjenja_kupca, adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata);
        broj_prodaja++;
    }
    void RegistrirajProdaju(Prodaja *p){
        if(max_broj_prodaja == broj_prodaja) throw std::range_error("Dostignut maksimalan broj prodaja");
        prodaje_se[broj_prodaja] = new Prodaja(p->DajImeAgenta(), p->DajCijenuStana(), p->DajDatumProdaje(), p->DajKupca(), p->DajStan());
        broj_prodaja++;
    }
    int DajBrojProdaja() const { return broj_prodaja; }
    int DajBrojProdajaNaDatum(const Datum &datum) const;
    int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const;
    Prodaja &DajNajranijuProdaju();
    Prodaja DajNajranijuProdaju() const;
    Prodaja &DajNajskupljuProdaju();
    Prodaja DajNajskupljuProdaju() const;
    void IsprazniKolekciju(){
        for(int i=0; i < broj_prodaja; i++) delete prodaje_se[i];
        delete[] prodaje_se;
        broj_prodaja=0;
        max_broj_prodaja = 0;
    }
    void ObrisiNajranijuProdaju();
    void ObrisiProdajeAgenta(const std::string &ime_agenta);
    void ObrisiProdajeNaDatum(const Datum &datum);
    void IspisiProdajeNaDatum(const Datum &datum) const;
    void IspisiSveProdaje() const;
};

Prodaje::~Prodaje(){
    for(int i=0; i<broj_prodaja; i++) delete prodaje_se[i];
    delete[] prodaje_se;
}

Prodaje::Prodaje(const Prodaje &p): max_broj_prodaja(p.max_broj_prodaja), broj_prodaja(p.broj_prodaja), prodaje_se(new Prodaja* [p.broj_prodaja]){
    for(int i=0; i<p.broj_prodaja; i++){
        prodaje_se[i] = new Prodaja(*p.prodaje_se[i]);
    }
}

Prodaje::Prodaje(Prodaje &&p) : max_broj_prodaja(p.max_broj_prodaja), broj_prodaja(p.broj_prodaja), prodaje_se(p.prodaje_se){
    p.prodaje_se = nullptr; p.broj_prodaja = 0;
}

Prodaje &Prodaje::operator =(const Prodaje &p){
    if(p.max_broj_prodaja != max_broj_prodaja) throw std::logic_error("Nesaglasni kapaciteti prodaje");
    if(&p != this){
        for(int i=0; i<broj_prodaja; i++) delete prodaje_se[i];
        for(int i=0; i<p.broj_prodaja; i++){
            prodaje_se[i] = new Prodaja(*p.prodaje_se[i]);
        }
        broj_prodaja = p.broj_prodaja;
    }
    return *this;
}

Prodaje &Prodaje::operator =(Prodaje &&p){
    if(p.max_broj_prodaja != max_broj_prodaja) throw std::logic_error("Nesaglasni kapaciteti prodaje");
    if(&p != this){
        for(int i=0; i<broj_prodaja; i++) delete prodaje_se[i];
        delete[] prodaje_se;
        
        prodaje_se = p.prodaje_se; broj_prodaja = p.broj_prodaja;
        p.prodaje_se = nullptr; p.broj_prodaja = 0;
    }
    return *this;
}

int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const{
    int k(0);
    //std::count_if(prodaje_se, prodaje_se+broj_prodaja, []());
    for(int i=0; i<broj_prodaja; i++){
        if( (prodaje_se[i]->DajDatumProdaje()).DajGodinu() == datum.DajGodinu() ){
            if( (prodaje_se[i]->DajDatumProdaje()).DajMjesec() == datum.DajMjesec() ){
                if( (prodaje_se[i]->DajDatumProdaje()).DajDan() == datum.DajDan() ){
                    k++;
                }
            }
        }
    }
    return k;
}

int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const{
    int k(0);
    for(int i=0; i<broj_prodaja; i++){
        if( prodaje_se[i]->DajImeAgenta()== ime_agenta ) k++;
    }
    return k;
}

Prodaja &Prodaje::DajNajranijuProdaju(){
    Prodaja** p( std::min_element(prodaje_se, prodaje_se+broj_prodaja, [](Prodaja* p1, Prodaja*p2){
        if(((*p1).DajDatumProdaje()).DajGodinu() != ((*p2).DajDatumProdaje()).DajGodinu() ) return ((*p1).DajDatumProdaje()).DajGodinu() < ((*p2).DajDatumProdaje()).DajGodinu();
        if( ((*p1).DajDatumProdaje()).DajMjesec() != ((*p2).DajDatumProdaje()).DajMjesec() ) return ((*p2).DajDatumProdaje()).DajMjesec() < ((*p1).DajDatumProdaje()).DajMjesec();
        if( ((*p1).DajDatumProdaje()).DajDan() != ((*p2).DajDatumProdaje()).DajDan() ) return ((*p2).DajDatumProdaje()).DajDan() < ((*p1).DajDatumProdaje()).DajDan();
        return ((*p2).DajDatumProdaje()).DajDan() < ((*p1).DajDatumProdaje()).DajDan();
    }) );
    return **p;
}

Prodaja Prodaje::DajNajranijuProdaju() const{
    Prodaja** p( std::min_element(prodaje_se, prodaje_se+broj_prodaja, [](Prodaja* p1, Prodaja*p2){
        if(((*p1).DajDatumProdaje()).DajGodinu() != ((*p2).DajDatumProdaje()).DajGodinu() ) return ((*p1).DajDatumProdaje()).DajGodinu() < ((*p2).DajDatumProdaje()).DajGodinu();
        if( ((*p1).DajDatumProdaje()).DajMjesec() != ((*p2).DajDatumProdaje()).DajMjesec() ) return ((*p2).DajDatumProdaje()).DajMjesec() < ((*p1).DajDatumProdaje()).DajMjesec();
        if( ((*p1).DajDatumProdaje()).DajDan() != ((*p2).DajDatumProdaje()).DajDan() ) return ((*p2).DajDatumProdaje()).DajDan() < ((*p1).DajDatumProdaje()).DajDan();
        return ((*p2).DajDatumProdaje()).DajDan() < ((*p1).DajDatumProdaje()).DajDan();
    }) );
    return **p;
}

Prodaja &Prodaje::DajNajskupljuProdaju(){
    if(broj_prodaja == 0) throw std::domain_error("Nema registriranih prodaja");
    return **std::max_element(prodaje_se, prodaje_se+broj_prodaja, [](Prodaja* p1, Prodaja*p2){ return (*p1).DajCijenuStana() > (*p2).DajCijenuStana(); } );
}
Prodaja Prodaje::DajNajskupljuProdaju() const {
    if(broj_prodaja == 0) throw std::domain_error("Nema registriranih prodaja");
    return **std::max_element(prodaje_se, prodaje_se+broj_prodaja, [](Prodaja* p1, Prodaja*p2){ return (*p1).DajCijenuStana() > (*p2).DajCijenuStana(); });
}

void Prodaje::ObrisiNajranijuProdaju(){
    if(broj_prodaja == 0) throw std::range_error("Prazna kolekcija");
    int temp(0);
    for(int i=1; i<broj_prodaja; i++){
        if( (prodaje_se[temp]->DajDatumProdaje()).DajGodinu() < (prodaje_se[i]->DajDatumProdaje()).DajGodinu() ) temp = i;
        else if( (prodaje_se[temp]->DajDatumProdaje()).DajGodinu() == (prodaje_se[i]->DajDatumProdaje()).DajGodinu() ){
            if( (prodaje_se[temp]->DajDatumProdaje()).DajMjesec() < (prodaje_se[i]->DajDatumProdaje()).DajMjesec() ) temp = i;
            else if( (prodaje_se[temp]->DajDatumProdaje()).DajMjesec() == (prodaje_se[i]->DajDatumProdaje()).DajMjesec() ){
                 if( (prodaje_se[temp]->DajDatumProdaje()).DajDan() < (prodaje_se[i]->DajDatumProdaje()).DajDan() ) temp = i;
            }
        }
    }
    Prodaja *p(prodaje_se[temp]);
    int k(1);
    for(int i=0; i<broj_prodaja-1; i++){
        if(i>=temp){ 
            prodaje_se[i] = prodaje_se[temp+k];
            k++;
        }
    }
    broj_prodaja--;
    delete p;
}

void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta){
    if(DajBrojProdajaOdAgenta(ime_agenta) != 0){
        for(int i=0; i<broj_prodaja; i++){
            if(ime_agenta == prodaje_se[i]->DajImeAgenta()){
                Prodaja* p(prodaje_se[i]);
                int k(i);
                for(int j=i+1; j<broj_prodaja-1; j++){
                    prodaje_se[k] = prodaje_se[j];
                    k++;
                }
                delete p;
                broj_prodaja--;
            }
        }
    } 
}

void Prodaje::ObrisiProdajeNaDatum(const Datum &datum){
    for(int i=0; i<broj_prodaja; i++){
        if( (prodaje_se[i]->DajDatumProdaje()).DajGodinu() == datum.DajGodinu() ){
           if( (prodaje_se[i]->DajDatumProdaje()).DajMjesec() == datum.DajMjesec() ){
                if( (prodaje_se[i]->DajDatumProdaje()).DajDan() == (prodaje_se[i]->DajDatumProdaje()).DajDan() ){
                    Prodaja* p(prodaje_se[i]);
                    int k(i);
                    for(int j=i+1; j<broj_prodaja-1; j++){
                        prodaje_se[k] = prodaje_se[j];
                        k++;
                    }
                    delete p;
                    broj_prodaja--;
                }
            }
        }
    }
}

void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const{
    std::sort(prodaje_se, prodaje_se+broj_prodaja, [](Prodaja *p1, Prodaja *p2){ return (*p1).DajImeKupca() < (*p2).DajImeKupca(); });
    for(int i=0; i<broj_prodaja; i++){
        if( (prodaje_se[i]->DajDatumProdaje()).DajGodinu() == datum.DajGodinu() ){
           if( (prodaje_se[i]->DajDatumProdaje()).DajMjesec() == datum.DajMjesec() ){
                if( (prodaje_se[i]->DajDatumProdaje()).DajDan() == (prodaje_se[i]->DajDatumProdaje()).DajDan() ){
                    prodaje_se[i]->Ispisi();
                }
            }
        }
    }
}

void Prodaje::IspisiSveProdaje() const{
    std::sort(prodaje_se, prodaje_se+broj_prodaja, [](Prodaja* p1, Prodaja* p2){
        if(((*p1).DajDatumProdaje()).DajGodinu() != ((*p2).DajDatumProdaje()).DajGodinu() ) return ((*p1).DajDatumProdaje()).DajGodinu() < ((*p2).DajDatumProdaje()).DajGodinu();
        if( ((*p1).DajDatumProdaje()).DajMjesec() != ((*p2).DajDatumProdaje()).DajMjesec() ) return ((*p2).DajDatumProdaje()).DajMjesec() < ((*p1).DajDatumProdaje()).DajMjesec();
        if( ((*p1).DajDatumProdaje()).DajDan() != ((*p2).DajDatumProdaje()).DajDan() ) return ((*p2).DajDatumProdaje()).DajDan() < ((*p1).DajDatumProdaje()).DajDan();
        return ( (*p2).DajImeKupca() < (*p1).DajImeKupca() );
    });
    for(int i=0; i<broj_prodaja; i++){
        prodaje_se[i]->Ispisi();
    }
}

int main ()
{
    std::cout << "Dobrodosli!" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::vector<Stan> stan;
    std::vector<Kupac> kupac;
    std::vector<Prodaja> prodaja;
    while(true){
        std::cout << "Izaberite opciju:" << std::endl;
        std::cout << " 0 - kraj" << std::endl;
        std::cout << " 1 - uredjivanje stanova" << std::endl;
        std::cout << " 2 - uredjivanje kupaca" << std::endl;
        std::cout << " 3 - uredjivanje prodaja" << std::endl;
        int pomocna;
        std::cin >> pomocna;
            
        if(pomocna == 0){
            break;
        }else if(pomocna == 1){
            while(true){
                std::cout << "Izaberite opciju:" << std::endl;
                std::cout << " 0 - nazad" << std::endl;
                std::cout << " 1 - dodavanje stana" << std::endl;
                std::cout << " 2 - uredjivanje stanova" << std::endl;
                std::cout << " 3 - ispis svih stanova" << std::endl;
                std::cout << " 4 - kraj" << std::endl;
                std::cin >> pomocna;
                if(pomocna == 0){
                    break;
                }else if(pomocna == 1){
                    while(true){
                        std:: cout << "Unesite adresu: ";
                        std::string adresa;
                        std::cin.ignore(1000,'\n');
                        std::getline(std::cin, adresa);
                        std::cout << "Unesite sprat: ";
                        int sprat;
                        std::cin >> sprat;
                        std::cout << "Unesite broj soba: ";
                        int broj_soba;
                        std::cin >> broj_soba;
                        std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                        int namjesten_stan;
                        std::cin >> namjesten_stan;
                        bool namjesten(false);
                        if(namjesten_stan) namjesten=true;
                        std::cout << "Unesite kvadraturu: ";
                        double kvadratura;
                        std::cin >> kvadratura;
                        if( (namjesten_stan != 0 && namjesten_stan != 1) || sprat<0 || broj_soba<0 || kvadratura<0 ){
                            std::cout << "Izuzetak: Neispravan unos podataka. Molimo unesite opet." << std::endl;
                            continue;
                        }
                        Stan temp(adresa, sprat, broj_soba, namjesten, kvadratura);
                        stan.push_back(temp);
                        break;
                    }
                    std::cout << "Stan je uspjesno dodan!" << std::endl << std::endl;
                }else if(pomocna == 2){
    
                    std::cout << "Odaberite stan. Dostupni stanovi su:" << std::endl;
                    for(int i=0; i<stan.size(); i++){
                        std::cout << " " << i+1 << " - ";
                        stan[i].Ispisi();
                        std::cout << std::endl;
                    }
                    int k;
                    std::cin >> k;
                    if(k <= stan.size()){
                        std::cout << std::endl << "Odaberite polje koji zelite urediti:" << std::endl;
                        std::cout << " 0 - nazad" << std::endl << " 1 - adresa" << std::endl << " 2 - sprat" << std::endl << " 3 - broj soba" << std::endl << " 4 - da li je stan namjesten" << std::endl << " 5 - kvadratura" << std::endl << " 6 - sve" << std::endl;
                        std::cin >> pomocna;
                            
                        if(pomocna == 0){
                            continue;
                        }else if(pomocna == 1){
                            while(true){
                                std:: cout << "Unesite adresu: ";
                                std::string adresa_stana;
                                std::cin.ignore(1000,'\n');
                                std::getline(std::cin, adresa_stana);
                                stan[k-1].Postavi(adresa_stana,stan[k-1].DajSprat(), stan[k-1].DajBrojSoba(), stan[k-1].DajNamjesten(), stan[k-1].DajKvadraturu());
                                break;
                            }
                            std::cout << "Stan je uspjesno izmijenjen!" << std::endl << std::endl;
                        }else if(pomocna == 2){
                            while(true){
                                std::cout << "Unesite sprat: ";
                                int sprat;
                                std::cin >> sprat;
                                if(sprat<0){
                                    std::cout << "Izuzetak: Neispravan unos podataka. Molimo unesite opet." << std::endl;
                                    continue;
                                }
                                stan[k-1].Postavi(stan[k-1].DajAdresu(),sprat, stan[k-1].DajBrojSoba(), stan[k-1].DajNamjesten(), stan[k-1].DajKvadraturu());
                                break;
                            }
                            std::cout << "Stan je uspjesno izmijenjen!" << std::endl << std::endl;
                        }else if( pomocna == 3 ){
                            while(true){
                                std::cout << "Unesite broj soba: ";
                                int broj_soba;
                                std::cin >> broj_soba;
                                if( broj_soba<0 ){
                                    std::cout << "Izuzetak: Neispravan unos podataka. Molimo unesite opet." << std::endl;
                                    continue;
                                }
                                stan[k-1].Postavi(stan[k-1].DajAdresu(),stan[k-1].DajSprat(), broj_soba, stan[k-1].DajNamjesten(), stan[k-1].DajKvadraturu());
                                break;
                            }
                            std::cout << "Stan je uspjesno izmijenjen!" << std::endl << std::endl;
                        }else if( pomocna == 4 ){
                            while(true){
                                std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                                int namjesten_stan;
                                std::cin >> namjesten_stan;
                                bool namjesten(false);
                                if(namjesten_stan) namjesten=true;
                                if( namjesten_stan != 0 && namjesten_stan != 1 ){
                                    std::cout << "Izuzetak: Neispravan unos podataka. Molimo unesite opet." << std::endl;
                                    continue;
                                }
                                stan[k-1].Postavi(stan[k-1].DajAdresu(),stan[k-1].DajSprat(), stan[k-1].DajBrojSoba(), namjesten, stan[k-1].DajKvadraturu());
                                break;
                            }
                            std::cout << "Stan je uspjesno izmijenjen!" << std::endl << std::endl;
                        }else if( pomocna == 5 ){
                            while(true){
                                std::cout << "Unesite kvadraturu: ";
                                double kvadratura;
                                std::cin >> kvadratura;
                                if( kvadratura<0 ){
                                    std::cout << "Izuzetak: Neispravan unos podataka. Molimo unesite opet." << std::endl;
                                    continue;
                                }
                                stan[k-1].Postavi(stan[k-1].DajAdresu(),stan[k-1].DajSprat(), stan[k-1].DajBrojSoba(), stan[k-1].DajNamjesten(), kvadratura);
                                break;
                            }
                            std::cout << "Stan je uspjesno izmijenjen!" << std::endl << std::endl;
                        }else if( pomocna == 6 ){
                             while(true){
                                std:: cout << "Unesite adresu: ";
                                std::string adresa;
                                std::cin.ignore(1000,'\n');
                                std::getline(std::cin, adresa);
                                std::cout << "Unesite sprat: ";
                                int sprat;
                                std::cin >> sprat;
                                std::cout << "Unesite broj soba: ";
                                int broj_soba;
                                std::cin >> broj_soba;
                                std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                                int namjesten_stan;
                                std::cin >> namjesten_stan;
                                bool namjesten(false);
                                if(namjesten_stan) namjesten=true;
                                std::cout << "Unesite kvadraturu: ";
                                double kvadratura;
                                std::cin >> kvadratura;
                                if( (namjesten_stan != 0 && namjesten_stan != 1) || sprat<0 || broj_soba<0 || kvadratura<0 ){
                                    std::cout << "Izuzetak: Neispravan unos podataka. Molimo unesite opet." << std::endl;
                                    continue;
                                }
                                stan[k-1].Postavi(adresa, sprat, broj_soba, namjesten, kvadratura);
                                break;
                            }
                            std::cout << "Stan je uspjesno izmijenjen!" << std::endl << std::endl;
                        }
                    }
                }else if(pomocna == 3){
                    for(int i=0; i<stan.size(); i++){
                        std::cout << i+1 << ". ";
                        stan[i].Ispisi();
                        std::cout << std::endl;
                    }
                    std::cout << std::endl;
                }else if(pomocna==4){
                    return 0;
                }
            }
        }else if(pomocna == 2){
            while(true){
                std::cout << "Izaberite opciju:" << std::endl;
                std::cout << " 0 - nazad" << std::endl;
                std::cout << " 1 - dodavanje kupca" << std::endl;
                std::cout << " 2 - uredjivanje kupaca" << std::endl;
                std::cout << " 3 - ispis svih kupaca" << std::endl;
                std::cout << " 4 - kraj" << std::endl;
                std::cin >> pomocna;
                if(pomocna == 0){
                    break;
                }else if(pomocna == 1){
                    while(true){
                        std::string ime_kupca;
                        std::cin.ignore(1000, '\n');
                        std::cout << "Unesite ime i prezime kupca: ";
                        std::getline(std::cin, ime_kupca);
                        std::string datum;
                        std::cout << "Unesite datum rodjenja (formata d/m/g): ";
                        std::getline(std::cin, datum);
                        int d(0), m(0), g(0), k(0);
                        for(int i=0; i<datum.size(); i++){
                            if(datum[i] == '/'){
                                k++;
                                continue;
                            }
                            if(k == 0){
                                d = d*10 + (datum[i] - '0');
                            }
                            if(k == 1){
                                m = m*10 + (datum[i] - '0');
                            }
                            if(k == 2){
                                g = g*10 + (datum[i] - '0');
                            }
                        }
                        int j;
                        for(j=0; j<ime_kupca.length(); j++){
                            if(!((ime_kupca[j]>='A' && ime_kupca[j]<='Z')||(ime_kupca[j]>='a' && ime_kupca[j]<='z')||(ime_kupca[j]>='0' && ime_kupca[j]<='9')||ime_kupca[j]==' '||ime_kupca[j]=='-'||ime_kupca[j]== 39)){
                                break;
                            }
                        }
                        if( j!= ime_kupca.length() ){
                            std::cout << "Izuzetak: Neispravno ime i prezime. Molimo unesite opet." << std::endl;
                            continue;
                        }  
                        std::vector<int> broj_dana{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
                        if(g%4==0 && (g%100!=0 || g%400==0)) broj_dana[1]++;
                        if(g<1 || d<1 || m<1 || m>12 || d>broj_dana[m-1]){
                            std::cout << "Izuzetak: Neispravan datum. Molimo unesite opet." << std::endl;
                            continue; 
                        }
                        Datum temp1(d, m, g);
                        Kupac temp(ime_kupca, temp1);
                        kupac.push_back(temp);
                        break;
                    }
                    std::cout << "Kupac je uspjesno dodan!" << std::endl << std::endl;
                }else if(pomocna == 2){
                    std::cout << "Odaberite kupca kojeg zelite urediti. Dostupni kupci su:" << std::endl;
                    for(int i=0; i<kupac.size(); i++){
                        std::cout << " " << i+1 << " - " << kupac[i].DajImePrezime() << " ";
                        (kupac[i].DajDatumRodjenja()).Ispisi();
                        std::cout << std::endl;
                    }
                    std::cin >> pomocna;
                    
                    while(true){
                        std::string ime_kupca;
                        std::cin.ignore(1000, '\n');
                        std::cout << "Unesite ime i prezime kupca: ";
                        std::getline(std::cin, ime_kupca);
                        int j;
                        for(j=0; j<ime_kupca.length(); j++){
                            if(!((ime_kupca[j]>='A' && ime_kupca[j]<='Z')||(ime_kupca[j]>='a' && ime_kupca[j]<='z')||(ime_kupca[j]>='0' && ime_kupca[j]<='9')||ime_kupca[j]==' '||ime_kupca[j]=='-'||ime_kupca[j]== 39)){
                                break;
                            }
                        }
                        if( j!= ime_kupca.length() ){
                            std::cout << "Izuzetak: Neispravno ime i prezime. Molimo unesite opet." << std::endl;
                            continue;
                        }   
                        std::string datum;
                        std::cout << "Unesite datum rodjenja (formata d/m/g): ";
                        std::getline(std::cin, datum);
                        int d(0), m(0), g(0), k(0);
                        for(int i=0; i<datum.size(); i++){
                            if(datum[i] == '/'){
                                k++;
                                continue;
                            }
                            if(k == 0){
                                d = d*10 + (datum[i] - '0');
                            }
                            if(k == 1){
                                m = m*10 + (datum[i] - '0');
                            }
                            if(k == 2){
                                g = g*10 + (datum[i] - '0');
                            }
                        }
                        std::vector<int> broj_dana{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
                        if(g%4==0 && (g%100!=0 || g%400==0)) broj_dana[1]++;
                        if(g<1 || d<1 || m<1 || m>12 || d>broj_dana[m-1]){
                            std::cout << "Izuzetak: Neispravan datum. Molimo unesite opet." << std::endl;
                            continue; 
                        }
                        Datum temp1(d, m, g);
                        kupac[pomocna-1].Postavi(ime_kupca, temp1);
                        break;
                    }
                    std::cout << "Kupac je uspjesno izmijenjen!" << std::endl << std::endl;
                }else if(pomocna == 3){
                    for(int i=0; i<kupac.size(); i++){
                        std::cout << kupac[i].DajImePrezime() << " ";
                        (kupac[i].DajDatumRodjenja()).Ispisi();
                        std::cout << std::endl;
                    }
                    std::cout << std::endl;
                }else if(pomocna == 4){
                    return 0;
                }
            }
//Prodaja
        }else if( pomocna == 3){
            while(true){
                std::cout << "Izaberite opciju:" << std::endl;
                std::cout << " 0 - nazad" << std::endl;
                std::cout << " 1 - dodavanje prodaje" << std::endl;
                std::cout << " 2 - uredjivanje prodaje" << std::endl;
                std::cout << " 3 - ispis prodaja" << std::endl;
                std::cout << " 4 - brisanje prodaja" << std::endl;
                std::cout << " 5 - kraj" << std::endl;
                std::cin >> pomocna;
                if(pomocna == 0){
                    break;
                }else if(pomocna == 1){
                    while(true){
                        std::cout << "Izaberite opciju:" << std::endl;
                        std::cout << " 0 - nazad" << std::endl;
                        std::cout << " 1 - dodavanje potpuno nove prodaje" << std::endl;
                        std::cout << " 2 - dodavanje nove prodaje na osnovu arhive" << std::endl;
                        std::cout << " 3 - kraj" << std::endl;
                        std::cin >> pomocna;
                        if(pomocna == 0) break;
                        else if(pomocna == 1){
                            std::cout << "Unesite ime i prezime agenta prodaje: ";
                            std::string agent;
                            std::getline(std::cin, agent);
                            std::cout << "Unesite datum prodaje (formata d/m/g): ";
                            std::string datum;
                            std::getline(std::cin, datum);
                            int d(0), m(0), g(0), k(0);
                            for(int i=0; i<datum.size(); i++){
                                if(datum[i] == '/'){
                                    k++;
                                    continue;
                                }
                                if(k == 0){
                                    d = d*10 + (datum[i] - '0');
                                }
                                if(k == 1){
                                    m = m*10 + (datum[i] - '0');
                                }
                                if(k == 2){
                                    g = g*10 + (datum[i] - '0');
                                }
                            }
                            int cijena_stana;
                            std::cout << "Unesite cijenu stana: ";
                            std::cin >> cijena_stana;
                            std::cout << "Unesite ime kupca: ";
                            std::string ime_kupca;
                            std::getline(std::cin, ime_kupca);
                            std::cout << "Unesite datum rodjenja kupca (formata d/m/g): ";
                            std::string d_r_k;
                            std::getline(std::cin, d_r_k);
                            int d1(0), m1(0), g1(0);
                            k=0;
                            for(int i=0; i<d_r_k.size(); i++){
                                if(datum[i] == '/'){
                                    k++;
                                    continue;
                                }
                                if(k == 0){
                                    d = d*10 + (datum[i] - '0');
                                }
                                if(k == 1){
                                    m = m*10 + (datum[i] - '0');
                                }
                                if(k == 2){
                                    g = g*10 + (datum[i] - '0');
                                }
                            }
                            std:: cout << "Unesite adresu: ";
                            std::string adresa;
                            std::cin.ignore(1000,'\n');
                            std::getline(std::cin, adresa);
                            std::cout << "Unesite sprat: ";
                            int sprat;
                            std::cin >> sprat;
                            std::cout << "Unesite broj soba: ";
                            int broj_soba;
                            std::cin >> broj_soba;
                            std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                            int namjesten_stan(0);
                            std::cin >> namjesten_stan;
                            bool namjesten(false);
                            if(namjesten_stan) namjesten=true;
                            std::cout << "Unesite kvadraturu: ";
                            double kvadratura;
                            std::cin >> kvadratura;
                            if( (namjesten_stan != 0 && namjesten_stan != 1) || sprat<0 || broj_soba<0 || kvadratura<0 ){
                                std::cout << "Izuzetak: Neispravan unos podataka. Molimo unesite opet." << std::endl;
                                continue;
                            }
                            std::vector<int> broj_dana{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
                            if(g%4==0 && (g%100!=0 || g%400==0)) broj_dana[1]++;
                            if(g<1 || d<1 || m<1 || m>12 || d>broj_dana[m-1]){
                                std::cout << "Izuzetak: Neispravan datum. Molimo unesite opet." << std::endl;
                                continue; 
                            }
                            std::vector<int> broj_dana1{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
                            if(g1%4==0 && (g1%100!=0 || g1%400==0)) broj_dana1[1]++;
                            if(g1<1 || d1<1 || m1<1 || m1>12 || d>broj_dana1[m1-1]){
                                std::cout << "Izuzetak: Neispravan datum. Molimo unesite opet." << std::endl;
                                continue; 
                            }
                            Datum datum_rodjenja_kupca(d1, m1, g1);
                            Prodaja p(agent, cijena_stana, d, m, g , ime_kupca, datum_rodjenja_kupca, adresa, sprat, broj_soba, namjesten, kvadratura);
                            prodaja.push_back(p);
                            std::cout << "" << std::endl << std::endl;
                        }else if( pomocna == 2 ){
                            std::cout << "Unesite ime i prezime agenta prodaje: ";
                            std::string agent;
                            std::getline(std::cin, agent);
                            std::cout << "Unesite datum prodaje (formata d/m/g): ";
                            std::string datum;
                            std::getline(std::cin, datum);
                            int d(0), m(0), g(0), k(0);
                            for(int i=0; i<datum.size(); i++){
                                if(datum[i] == '/'){
                                    k++;
                                    continue;
                                }
                                if(k == 0){
                                    d = d*10 + (datum[i] - '0');
                                }
                                if(k == 1){
                                    m = m*10 + (datum[i] - '0');
                                }
                                if(k == 2){
                                    g = g*10 + (datum[i] - '0');
                                }
                            }
                            int cijena_stana;
                            std::cout << "Unesite cijenu stana: ";
                            std::cin >> cijena_stana;
                            std::cout << "Odaberite kupca. Dostupni kupci su:";
                            int temp, temp1;
                            for(int i=0; i<kupac.size(); i++){
                                std::cout << " "  << i+1 << " - " << kupac[i].DajImePrezime() << " ";
                                (kupac[i].DajDatumRodjenja()).Ispisi();
                                std::cout << std::endl;
                            }
                            std::cin >> temp;
                            std::cout << "Odaberite stan. Dostupni stanovi su:" << std::endl;
                            for(int i=0; i<stan.size(); i++){
                                std::cout << i+1 << ". ";
                                stan[i].Ispisi();
                                std::cout << std::endl;
                            }
                            std::cin >>  temp1;
                            Datum datum_prodaje(d,m, g);
                            Prodaja prod(agent, cijena_stana, datum_prodaje, kupac[temp-1], stan[temp-1]);
                            prodaja.push_back(prod);
                        }else if( pomocna == 3 ){
                            return 0;
                        }
                    }
                }else if( pomocna == 2 ){
                    while(true){
                        std::cout << "Odaberite prodaju koju želite urediti. Dostupne prodaje su:" << std::endl;
                        int k;
                        for(int i=0; i<prodaja.size(); i++){
                            std::cout << i+1 << "." << std::endl;
                            prodaja[i].Ispisi();
                            std::cout << std::endl;
                        }
                        std::cin >> k;
                        std::cout << "Izaberite opciju:" << std::endl;
                        std::cout << " 0 - nazad" << std::endl;
                        std::cout << " 1 - izmjena agenta" << std::endl;
                        std::cout << " 2 - izmjena datuma prodaje" << std::endl;
                        std::cout << " 3 - izmjena kupca" << std::endl;
                        std::cout << " 4 - izmjena stana" << std::endl;
                        std::cout << " 5 - izmjena cijene stana" << std::endl;
                        std::cin >> pomocna;
                        if(pomocna == 0) break;
                        else if(pomocna == 1){
                            std::cout << "Unesite ime i prezime agenta prodaje: ";
                            std::string agent;
                            std::getline(std::cin, agent);
                            prodaja[k-1].PromijeniAgentaProdaje(agent);
                        }else if(pomocna == 2){
                            std::cout << "Unesite datum prodaje (formata d/m/g): ";
                            std::string datum;
                            std::getline(std::cin, datum);
                            int d(0), m(0), g(0), k(0);
                            for(int i=0; i<datum.size(); i++){
                                if(datum[i] == '/'){
                                    k++;
                                    continue;
                                }
                                if(k == 0){
                                    d = d*10 + (datum[i] - '0');
                                }
                                if(k == 1){
                                    m = m*10 + (datum[i] - '0');
                                }
                                if(k == 2){
                                    g = g*10 + (datum[i] - '0');
                                }
                            }
                            Datum dat(d,m,g);
                            prodaja[k-1].PromijeniDatumKupovine(dat);
                        }
                    }
                }
            }
        }
    }

	return 0;
}