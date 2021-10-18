/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti danostupni danan pred rok!
#include <iostream>
#include <stdexcept>
#include <string>
#include <initializer_list>
#include <algorithm>
#include <cmath>
#include <vector>

class Datum{
    int dan, mjesec, godina;
public:
    Datum(int dan, int mjesec, int godina){
        Postavi(dan, mjesec, godina);
    }
    void Postavi(int dan, int mjesec, int godina);
    int DajDan()const{ return dan;}
    int DajMjesec()const{ return mjesec;}
    int DajGodinu()const{ return godina;}
    void Ispisi()const{ std::cout << dan << "/" << mjesec << "/" << godina;}
};
void Datum::Postavi(int dan, int mjesec, int godina){
    int br_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if ((godina % 4 == 0 && godina % 100 == 0) || godina % 400 == 0) br_dana[1]++;
    if (godina < 1 || dan< 1 || mjesec < 1 || mjesec > 12 || dan > br_dana[mjesec - 1])
        throw std::domain_error("Neispravan datum");
    Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina;
}

class Kupac{
    std::string ime_i_prezime;
    Datum datum_rodjenja;
public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja):datum_rodjenja(datum_rodjenja.DajDan(), datum_rodjenja.DajMjesec(), datum_rodjenja.DajGodinu()){
        Postavi(ime_i_prezime, datum_rodjenja);
    }
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    std::string DajImeIPrezime()const{return ime_i_prezime;}
    Datum DajDatumRodjenja()const{return datum_rodjenja;}
    void Ispisi()const;
};
void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja){
    for (int i = 0; i < ime_i_prezime.length(); i++){
        char znak(ime_i_prezime[i]);
        if ((znak < '0' || (znak > '9' && znak < 'A') || (znak > 'Z' && znak < 'a') || znak > 'z') && znak != ' ' && znak != '-' && znak != '!')
            throw std::domain_error("Neispravno ime i prezime");
    }
    Kupac::ime_i_prezime = ime_i_prezime; Kupac::datum_rodjenja = datum_rodjenja;
}
void Kupac::Ispisi()const{
    std::cout << ime_i_prezime << " ("; datum_rodjenja.Ispisi(); std::cout << ")";
}

class Stan{
    std::string adresa;
    int sprat, broj_soba;
    bool namjesten;
    double kvadratura;
public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
        Postavi(adresa, sprat, broj_soba, namjesten, kvadratura);
    }
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
    std::string DajAdresu()const{return adresa;}
    int DajSprat()const{return sprat;}
    int DajBrojSoba()const{return broj_soba;}
    bool DajNamjesten()const{return namjesten;}
    double DajKvadraturu()const{return kvadratura;}
    void Ispisi()const;
};
void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
    if (sprat < 0 || broj_soba < 0 || kvadratura < 0)
        throw std::domain_error("Neispravan unos podataka");
    Stan::adresa = adresa; Stan::sprat = sprat; Stan::broj_soba = broj_soba; Stan::namjesten = namjesten; Stan::kvadratura = kvadratura;
}
void Stan::Ispisi()const{
    std::cout << "Stan se nalazi na adresi " << adresa << " na " << sprat << ". spratu i ima " << broj_soba;
    if (broj_soba%10 == 1) std::cout << " sobu.";
    else if (broj_soba%10 >= 2 && broj_soba%10 <= 4) std::cout << " sobe.";
    else if ((broj_soba%10 >= 5 && broj_soba%10 <= 9) || broj_soba%10 == 0 || (broj_soba >= 11 && broj_soba <= 14)) std::cout << " soba.";
    std::cout << " Kvadratura stana je " << kvadratura << " (m^2) i stan";
    if (namjesten) std::cout << " je "; else std::cout << " nije "; 
    std::cout << "namjesten.";
}

class Prodaja{
    std::string ime_agenta_prodaje;
    double cijena_stana;
    Datum datum_prodaje;
    Kupac kupac_stana;
    Stan kupljeni_stan;
    static void Normalizuj(int &d, int &m, int &g){
        
    }
public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan):
    datum_prodaje(datum_prodaje), kupac_stana(kupac_stana), kupljeni_stan(kupljeni_stan){
        Prodaja::ime_agenta_prodaje = ime_agenta_prodaje; 
        Prodaja::cijena_stana = cijena_stana;
    }
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, const std::string &ime_kupca, const Datum &datum_rodjenja_kupca, 
    const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata):
    datum_prodaje(dan_prodaje, mjesec_prodaje, godina_prodaje), kupac_stana(ime_kupca, datum_rodjenja_kupca), kupljeni_stan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata)
    {
        Prodaja::ime_agenta_prodaje = ime_agenta_prodaje;
        Prodaja::cijena_stana = cijena_stana;
    }
    void PromijeniAgentaProdaje(const std::string &agent){
        Prodaja::ime_agenta_prodaje = agent;
    }
    void PromijeniKupca(const Kupac &novi_kupac){
        kupac_stana = novi_kupac;
    }
    void PromijeniStan(const Stan &novi_stan){
        kupljeni_stan = novi_stan;
    }
    void PromijeniDatumKupovine(const Datum &novi_datum){
        datum_prodaje = novi_datum;
    }
    void PromijeniCijenuProdaje(const double &nova_cijena){
        cijena_stana = nova_cijena;
    }
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImeAgenta()const{return ime_agenta_prodaje;}
    std::string DajImeKupca()const{return kupac_stana.DajImeIPrezime();}
    Datum DajDatumProdaje()const{return datum_prodaje;}
    double DajCijenuStana()const{return cijena_stana;}
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2){
        Datum prvi(p1.DajDatumProdaje()), drugi(p2.DajDatumProdaje());
        return prvi.DajGodinu() < prvi.DajGodinu() || prvi.DajMjesec() < drugi.DajMjesec() || prvi.DajDan() < drugi.DajDan();
    }
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2){
        return p1.DajCijenuStana() > p2.DajCijenuStana(); 
    }
    void Ispisi()const;
};
void Prodaja::PomjeriDanUnaprijed(){
    int dan(datum_prodaje.DajDan()), mjesec(datum_prodaje.DajMjesec()), godina(datum_prodaje.DajGodinu());
    int br_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    dan++;
    if (dan > br_dana[mjesec - 1]){dan = 1; mjesec++;}
    if (mjesec > 12){mjesec = 1, godina++;}
    datum_prodaje.Postavi(dan, mjesec, godina);
}
void Prodaja::PomjeriDanUnazad(){
    int dan(datum_prodaje.DajDan()), mjesec(datum_prodaje.DajMjesec()), godina(datum_prodaje.DajGodinu());
    int br_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    dan--;
    if(dan < 1){mjesec--; dan = br_dana[mjesec - 1];}
    if (mjesec < 1){godina--; mjesec = 12;}
    datum_prodaje.Postavi(dan, mjesec, godina);
}
void Prodaja::Ispisi()const{
    std::cout << "Ime agenta:                     " << ime_agenta_prodaje << "\n";
    std::cout << "Ime kupca:                      " << kupac_stana.DajImeIPrezime(); std::cout << " (";kupac_stana.DajDatumRodjenja().Ispisi(); std::cout << ")\n";
    std::cout << "Zakazani datum prodaje:         "; datum_prodaje.Ispisi(); std::cout << "\n";
    std::cout << "Cijena stana:                   " << cijena_stana << "\n";
    std::cout << "Informacije o stanu:\n"; kupljeni_stan.Ispisi();
}

class Prodaje{
    Prodaja** spisak_prodaja;
    int max_broj_prodaja;
    int br_alociranih{0};
    static Prodaja **AlocirajMemoriju(int mbp);
    static void DealocirajMemoriju(Prodaja **&p, int n);
    void ImaLiMjesta(){
        if (br_alociranih == max_broj_prodaja)
            throw std::range_error("Dostignut maksimalni broj prodaja");
    }
    static int PorediDatume(const Datum &d1, const Datum &d2);
    static bool Jednaki(double a, double b){
        return std::abs(a - b) <= std::pow(10,-8)*(std::abs(a) + std::abs(b));
    };
    static bool JednakeProdaje(const Prodaja &p1, const Prodaja &p2);
    void IzbaciNullptr(int i);
public:
    explicit Prodaje(int max_broj_prodaja);
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
    Prodaje(const Prodaje &prodaje);
    Prodaje(Prodaje &&prodaje);
    Prodaje &operator=(const Prodaje &prodaje);
    Prodaje &operator=(Prodaje &&prodaje);
    ~Prodaje();
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, const std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void RegistrirajProdaju(Prodaja* prodaja);
    int DajBrojProdaja()const{
        return br_alociranih;
    }
    int DajBrojProdajaNaDatum(const Datum &datum)const{
        return std::count_if(spisak_prodaja, spisak_prodaja + br_alociranih, [datum](Prodaja* p){return p != nullptr && PorediDatume(datum, p->DajDatumProdaje()) == 0;});
    }
    int DajBrojProdajaOdAgenta(const std::string &ime_agenta)const{
        return std::count_if(spisak_prodaja, spisak_prodaja + br_alociranih, [ime_agenta](Prodaja* p){return p != nullptr && p->DajImeAgenta() == ime_agenta;});
    }
    Prodaja &DajProdaju(int n);
    Prodaja &DajNajranijuProdaju();
    Prodaja DajNajranijuProdaju()const;
    Prodaja &DajNajskupljuProdaju();
    Prodaja DajNajskupljuProdaju()const;
    void IsprazniKolekciju();
    void ObrisiNajranijuProdaju();
    void ObrisiProdajeAgenta(const std::string &ime_agenta);
    void ObrisiProdajeNaDatum(const Datum &datum);
    void IspisiProdajeNaDatum(const Datum &datum)const;
    void IspisiSveProdaje()const;
};

Prodaja** Prodaje::AlocirajMemoriju(int mbp){
    Prodaja** spisak;
    try{
    spisak = new Prodaja*[mbp]; //sta ako ne uspije?
    }catch(std::bad_alloc) {throw;}
    for (int i = 0; i < mbp; i++) spisak[i] = nullptr;
    return spisak;
}
void Prodaje::DealocirajMemoriju(Prodaja **&p, int n){
    if (p){
        for (int i = 0; i < n; i++){ delete p[i]; p[i] = nullptr;};
    }
    delete[] p; p = nullptr;
}
int Prodaje::PorediDatume(const Datum &d1, const Datum &d2){
    int g1(d1.DajGodinu()), g2(d2.DajGodinu()), m1(d1.DajMjesec()), m2(d2.DajMjesec()), dan1(d1.DajDan()), dan2(d2.DajDan());
    if(g1 < g2 || (g1 == g2 && m1 < m2) || (g1 == g2 && m1 == m2 && dan1 < dan2))
        return -1;
    else if (g1 > g2 || (g1 == g2 && m1 > m2) || (g1 == g2 && m1 == m2 && dan1 > dan2))
        return 1;
    else return 0;
}
bool Prodaje::JednakeProdaje(const Prodaja &p1, const Prodaja &p2){
    return PorediDatume(p1.DajDatumProdaje(), p2.DajDatumProdaje()) == 0 && p1.DajImeAgenta() == p2.DajImeAgenta() && Jednaki(p1.DajCijenuStana(), p2.DajCijenuStana()) && p1.DajImeKupca() == p2.DajImeKupca();
}
void Prodaje::IzbaciNullptr(int i){
    for (int j = i; j < max_broj_prodaja - 1; j++)
    {
            spisak_prodaja[j] = spisak_prodaja[j + 1];
    }
}
Prodaje::Prodaje(int max_broj_prodaja):max_broj_prodaja(max_broj_prodaja){
     Prodaje::spisak_prodaja = AlocirajMemoriju(max_broj_prodaja);
}
Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja):max_broj_prodaja(spisak_prodaja.size()){
    int i(0);
    Prodaja **novi_spisak_prodaja = AlocirajMemoriju(spisak_prodaja.size());
    for (auto p = spisak_prodaja.begin(); p != spisak_prodaja.end(); p++){
        try{
            novi_spisak_prodaja[i++] = new Prodaja(*p); 
        } catch (std::bad_alloc){
            DealocirajMemoriju(novi_spisak_prodaja, max_broj_prodaja);
            throw;
        }
    }
    Prodaje::spisak_prodaja = novi_spisak_prodaja;
}
Prodaje::Prodaje(const Prodaje &prodaje){
    Prodaja** novi_spisak_prodaja = AlocirajMemoriju(prodaje.max_broj_prodaja);
    try{
        for (int i = 0; i < prodaje.max_broj_prodaja; i++) novi_spisak_prodaja[i] = new Prodaja(*prodaje.spisak_prodaja[i]);
    } catch (std::bad_alloc){
        DealocirajMemoriju(novi_spisak_prodaja, prodaje.max_broj_prodaja);
        throw;
    }
    Prodaje::spisak_prodaja = novi_spisak_prodaja;
    Prodaje::max_broj_prodaja = prodaje.max_broj_prodaja;
}
Prodaje::Prodaje(Prodaje &&prodaje){
    Prodaje::spisak_prodaja = prodaje.spisak_prodaja;
    Prodaje::max_broj_prodaja = prodaje.max_broj_prodaja;
    prodaje.spisak_prodaja = nullptr;
}
Prodaje &Prodaje::operator=(const Prodaje &prodaje){
    //Uvijek realokacija?, samodestrukcija
    if (this != &prodaje)
    {
        DealocirajMemoriju(spisak_prodaja, max_broj_prodaja);
        Prodaja** novi_spisak_prodaja = AlocirajMemoriju(prodaje.max_broj_prodaja);
        try{
            for (int i = 0; i < prodaje.max_broj_prodaja; i++) novi_spisak_prodaja[i] = new Prodaja(*prodaje.spisak_prodaja[i]);
        }catch(std::bad_alloc){
            DealocirajMemoriju(novi_spisak_prodaja, prodaje.max_broj_prodaja);
            throw;
        }
        spisak_prodaja = novi_spisak_prodaja;
        max_broj_prodaja = prodaje.max_broj_prodaja;
    }
    return *this;
}
Prodaje &Prodaje::operator=(Prodaje &&prodaje){
    spisak_prodaja = prodaje.spisak_prodaja;
    max_broj_prodaja = prodaje.max_broj_prodaja;
    prodaje.spisak_prodaja = nullptr;
    return *this;
}
Prodaje::~Prodaje(){
    DealocirajMemoriju(spisak_prodaja, max_broj_prodaja);
}
void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan){
    ImaLiMjesta();
    try{
        spisak_prodaja[br_alociranih] = new Prodaja(ime_agenta_prodaje, cijena_stana, datum_prodaje, kupac_stana, kupljeni_stan);
        br_alociranih++;
    }catch (std::bad_alloc){
        throw;
    }
}
void Prodaje::RegistrirajProdaju(Prodaja *prodaja){
    ImaLiMjesta();
    spisak_prodaja[br_alociranih] = prodaja;
    br_alociranih++;
}
void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, const std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata){
    ImaLiMjesta();
    try{
        spisak_prodaja[br_alociranih] = new Prodaja(ime_agenta_prodaje, cijena_stana, Datum(dan_prodaje, mjesec_prodaje, godina_prodaje), Kupac(ime_kupca, datum_rodjenja_kupca), Stan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata));
        br_alociranih++;
        
    }catch(std::bad_alloc){
        throw;
    }
}
Prodaja &Prodaje::DajProdaju(int n){
    //int br(0);
    //for(int i = 0; i < max_broj_prodaja; i++){
        //if (spisak_prodaja[i]) br++;
        //if (br == n) break;
    //}
    return *spisak_prodaja[n];
}
Prodaja &Prodaje::DajNajranijuProdaju(){
    if (!DajBrojProdaja())
        throw std::domain_error("Nema registriranih prodaja");
    return **std::min_element(spisak_prodaja, spisak_prodaja + br_alociranih, [](const Prodaja* p1, const Prodaja *p2){return PorediDatume(p1->DajDatumProdaje(), p2->DajDatumProdaje()) == -1;});
}
Prodaja Prodaje::DajNajranijuProdaju()const{
    if (!DajBrojProdaja())
        throw std::domain_error("Nema registriranih prodaja");
    return **std::min_element(spisak_prodaja, spisak_prodaja + br_alociranih, [](const Prodaja* p1, const Prodaja *p2){return PorediDatume(p1->DajDatumProdaje(), p2->DajDatumProdaje()) == -1;});
}
Prodaja &Prodaje::DajNajskupljuProdaju(){
    if (!DajBrojProdaja())
        throw std::domain_error("Nema registriranih prodaja");
    return **std::max_element(spisak_prodaja, spisak_prodaja + br_alociranih, [](const Prodaja* p1, const Prodaja *p2){return p1->DajCijenuStana() < p2->DajCijenuStana();});
}
Prodaja Prodaje::DajNajskupljuProdaju()const{
    if (!DajBrojProdaja())
        throw std::domain_error("Nema registriranih prodaja");
    return **std::max_element(spisak_prodaja, spisak_prodaja + br_alociranih, [](const Prodaja* p1, const Prodaja *p2){return p1->DajCijenuStana() < p2->DajCijenuStana();});
}
void Prodaje::IsprazniKolekciju(){
    if (DajBrojProdaja() == 0)
        throw std::range_error("Prazna kolekcija");
    DealocirajMemoriju(spisak_prodaja, max_broj_prodaja);
    br_alociranih = 0;
}
void Prodaje::ObrisiNajranijuProdaju(){
    if (DajBrojProdaja() == 0)
        throw std::range_error("Prazna kolekcija");
    Prodaja najranija(DajNajranijuProdaju());
    Prodaja** brisi(std::find_if(spisak_prodaja, spisak_prodaja + br_alociranih, [najranija](Prodaja* p){return JednakeProdaje(*p, najranija);}));
    delete *brisi; *brisi = nullptr;
    IzbaciNullptr(brisi - spisak_prodaja);
    br_alociranih--;
}
void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta){
    if (DajBrojProdaja() == 0)
        throw std::range_error("Prazna kolekcija");
    for (int i = 0; i < br_alociranih; i++){
        if (spisak_prodaja[i]->DajImeAgenta() == ime_agenta)
        {
            delete spisak_prodaja[i]; spisak_prodaja[i] = nullptr;
            IzbaciNullptr(i);
            br_alociranih--;
        }
    }
}
void Prodaje::ObrisiProdajeNaDatum(const Datum &datum){
    if (DajBrojProdaja() == 0)
        throw std::range_error("Prazna kolekcija");
    for (int i = 0; i < br_alociranih; i++){
        if (PorediDatume(spisak_prodaja[i]->DajDatumProdaje(), datum) == 0)
        {
            delete spisak_prodaja[i]; spisak_prodaja[i] = nullptr;
            IzbaciNullptr(i);
            br_alociranih--;
        }
    }
}
void Prodaje::IspisiProdajeNaDatum(const Datum &datum)const{
    Prodaja** spisak_prodaja2;
    try
    {
        spisak_prodaja2 = AlocirajMemoriju(br_alociranih);
        for (int i = 0; i < br_alociranih; i++)
            spisak_prodaja2[i] = new Prodaja(*spisak_prodaja[i]);
    }
    catch(std::bad_alloc)
    {
        throw;
    }
    std::sort(spisak_prodaja2, spisak_prodaja2 + br_alociranih, [](const Prodaja* p1, const Prodaja *p2){
        return p1->DajImeKupca() < p2->DajImeKupca();    
    });
    for (int i = 0; i < br_alociranih; i++){
        if (PorediDatume(spisak_prodaja2[i]->DajDatumProdaje(), datum) == 0)
        {
            spisak_prodaja2[i]->Ispisi(); std::cout << std::endl;
        }
    }
    DealocirajMemoriju(spisak_prodaja2, br_alociranih);
}
void Prodaje::IspisiSveProdaje()const{
    Prodaja** spisak_prodaja2;
    try
    {   spisak_prodaja2 = AlocirajMemoriju(br_alociranih);
        for (int i = 0; i < br_alociranih; i++)
            spisak_prodaja2[i] = new Prodaja(*spisak_prodaja[i]);
    }
    catch (std::bad_alloc)
    {
        throw;
    }
    std::sort(spisak_prodaja2, spisak_prodaja2 + br_alociranih, [](const Prodaja* p1, const Prodaja *p2){
        return (PorediDatume(p1->DajDatumProdaje(), p2->DajDatumProdaje()) == -1 || (PorediDatume(p1->DajDatumProdaje(), p2->DajDatumProdaje()) == 0 && p1->DajImeKupca() < p2->DajImeKupca())); //return true;
    });
    for (int i = 0; i < br_alociranih; i++){
        if (spisak_prodaja2[i]){
             spisak_prodaja2[i]->Ispisi(); std::cout << std::endl;}
    }
    DealocirajMemoriju(spisak_prodaja2, br_alociranih);
}

void Ignorisi(){
    std::cin.ignore(1000,'\n');
}

void IzmijeniStan(Stan &s, int p){
    for(;;)
    {   
        std::string nova_adresa; int novi_sprat; double nova_kvadratura; int novi_br_soba, novi_namjesten; 
        if (p == 1){std::cout << "Unesite adresu: "; std::getline(std::cin, nova_adresa);}
        else if (p == 2){std::cout << "Unesite sprat: "; std::cin >> novi_sprat; Ignorisi();}
        else if (p == 3){std::cout << "Unesite broj soba: "; std::cin >> novi_br_soba; Ignorisi();}
        else if (p == 4){std::cout << "Da li je stan namjesten (1 - da, 0 - ne): "; std::cin >> novi_namjesten; Ignorisi();}
        else if (p == 5){std::cout << "Unesite kvadraturu: "; std::cin >> nova_kvadratura; Ignorisi();}
        try{
            if (p == 1){s.Postavi(nova_adresa, s.DajSprat(), s.DajBrojSoba(), s.DajNamjesten(), s.DajKvadraturu());} 
            else if (p == 2){s.Postavi(s.DajAdresu(), novi_sprat, s.DajBrojSoba(), s.DajNamjesten(), s.DajKvadraturu());} 
            else if (p == 3){s.Postavi(s.DajAdresu(), s.DajSprat(), novi_br_soba, s.DajNamjesten(), s.DajKvadraturu());} 
            else if (p == 4){s.Postavi(s.DajAdresu(), s.DajSprat(), s.DajBrojSoba(), novi_namjesten, s.DajKvadraturu());} 
            else if (p == 5){s.Postavi(s.DajAdresu(), s.DajSprat(), s.DajBrojSoba(), s.DajNamjesten(), nova_kvadratura);} 
            
            break;
        }catch(std::domain_error e){
            std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet.\n";
        }
    }
}

void UnesiKupca(std::vector<Kupac> &kupci, bool uredjivanje, int i){
    std::string iip;
    for(;;)
    {
        std::cout << "Unesite ime i prezime kupca: ";
        std::getline(std::cin, iip);
        std::cout << "Unesite datum rodjenja (formata d/m/g): ";
        int d, m, g; char znak;
        std::cin >> d >> znak >> m >> znak >> g; Ignorisi();
        try{
            Datum dat(d, m, g); 
            if (uredjivanje) kupci[i] = Kupac(iip, dat);
            else kupci.push_back(Kupac(iip, dat)); 
            std::cout << "Kupac je uspjesno " ;if (uredjivanje)std::cout << "izmijenjen!\n"; else std::cout << "dodan!\n"; break;
        }
        catch (std::domain_error e){
            std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet.\n";
        }
    }
}

Stan UnesiStan(std::vector <Stan> &stanovi, bool arhiviraj = true, bool pisi = true){
    std::string adresa; int sprat, br_soba; int namjesten; double kvadratura;
    for(;;)
    {
        std::cout << "Unesite adresu: "; std::getline(std::cin, adresa);
        std::cout << "Unesite sprat: "; std::cin >> sprat; Ignorisi();
        std::cout << "Unesite broj soba: ", std::cin >> br_soba; Ignorisi();
        std::cout << "Da li je stan namjesten (1 - da, 0 - ne): "; std::cin >> namjesten; Ignorisi();
        std::cout << "Unesite kvadraturu: "; std::cin >> kvadratura; Ignorisi();
        try{
            if (namjesten != 0 && namjesten != 1) throw std::domain_error("Neispravan unos podataka");
            Stan stan(adresa, sprat, br_soba, namjesten, kvadratura);
            //if (arhiviraj)
                stanovi.push_back(stan); 
            if (pisi)
                std::cout << "Stan je uspjesno dodan!\n"; 
            return stan;
        }catch(std::domain_error e){
            std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet.\n";
        }
    }
}

void DodajProdaju(Prodaje &prodaje, std::vector<Stan> &stanovi, std::vector<Kupac> &kupci){ 
    std::string agent;
    std::cout << "Unesite ime i prezime agenta prodaje: ";
    std::getline(std::cin, agent);
    std::cout << "Unesite datum prodaje (formata d/m/g): ";
    for(;;)
    {
        try
        {
            int d, m, g; char znak; std::cin >> d >> znak >> m >> znak >> g; Ignorisi();
            Datum datp(d,m,g);
            std::cout << "Unesite cijenu stana: "; 
            double cijena; std::cin >> cijena; Ignorisi(); 
            std::cout << "Unesite ime kupca: ";
            std::string iip; std::getline(std::cin, iip);
            std::cout << "Unesite datum rodjenja kupca (formata d/m/g): "; std::cin >> d >> znak >> m >> znak >> g; Ignorisi();
            Datum datrk(d, m, g);
            Kupac kupac(iip, datrk); kupci.push_back(kupac);
            Stan stan(UnesiStan(stanovi, false, false));
            prodaje.RegistrirajProdaju(agent, cijena, datp, kupac, stan);
            break;
        }
        catch(std::domain_error e){
            std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet.\n";
        }
    }
}

void IzmijeniProdaju(Prodaje &prodaje, int p, int o, const std::vector<Kupac> &kupci, std::vector <Stan> &stanovi){
    Prodaja &prodaja(prodaje.DajProdaju(p - 1));
    std::string novi_agent, novoiip; int d, m, g; char znak; bool iz (false);int op;
    for(;;)
    {
        try{
            if (o == 1){std::cout << "Unesite ime i prezime agenta prodaje: "; std::getline(std::cin, novi_agent); prodaja.PromijeniAgentaProdaje(novi_agent);}
            else if (o == 2){std::cout << "Unesite datum prodaje (formata d/m/g): "; std::cin >> d >> znak >> m >> znak >> g; Ignorisi(); prodaja.PromijeniDatumKupovine(Datum(d, m, g));}
            else if (o == 3){
                
                if (!iz){std::cout << "Izaberite opciju:\n 0 - nazad\n 1 - odabir postojeceg kupca\n 2 - dodavanje novog kupca\n";  std::cin >> op; Ignorisi();}
                if (op == 0) break;
                else if (op ==2)
                {
                std::cout << "Unesite ime i prezime kupca: "; std::getline(std::cin, novoiip); std::cout << "Unesite datum rodjenja (formata d/m/g): "; std::cin >> d >> znak >> m >> znak >> g; Ignorisi();
                prodaja.PromijeniKupca(Kupac(novoiip, Datum(d,m,g))); iz = false;}
                else if (op == 1){
                    std::cout << "Odaberite kupca. Dostupni kupci su:\n";
                    for (int i = 0; i < kupci.size(); i++){
                        std::cout << " " << i + 1 << " - "; kupci[i].Ispisi(); std::cout << "\n";
                    }
                    int kup; std::cin >> kup; Ignorisi();
                    prodaja.PromijeniKupca(kupci[kup - 1]); iz = false;
                }
            }
            else if (o == 4){
                if (!iz){std::cout << "Izaberite opciju:\n 0 - nazad\n 1 - odabir postojeceg stana\n 2 - dodavanje novog stana\n"; std::cin >> op; Ignorisi();}
                
                if (op == 0) break;
                else if (op == 1){
                    std::cout << "Odaberite stan. Dostupni stanovi su:\n";
                    for (int i = 0; i < stanovi.size(); i++)
                    {
                        std::cout << " " << i + 1 << " - "; stanovi[i].Ispisi(); std::cout << std::endl;
                    }
                    int s; std::cin >> s; Ignorisi();
                    prodaja.PromijeniStan(stanovi[s - 1]); iz = false;
                }
                else if (op == 2){
                    Stan novi_stan(UnesiStan(stanovi, false, false));
                    prodaja.PromijeniStan(novi_stan); iz = false;
                }
                
            }
            else if (o == 5){
                std::cout << "Unesite cijenu stana: "; double nova_cijena; std::cin >> nova_cijena; Ignorisi();
                prodaja.PromijeniCijenuProdaje(nova_cijena);
            }
            std::cout << "Prodaja je uspjesno izmijenjena!\n"; break;
        }catch(std::domain_error e){
            std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet.\n"; iz = true;
        }
    }
}

Datum UnesiDatum(bool bezdmg = false){
    for(;;){
        int d, m , g; char znak; 
        if (!bezdmg)
        std::cout << "Unesite datum (d/m/g): ";
        else std::cout << "Unesite datum: ";
        std::cin >> d >> znak >> m >> znak >> g; Ignorisi();
        try{
            Datum dat (d,m,g);
            return dat;
        }catch(std::domain_error e){
            std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet.\n";
        }
    }
}

int main ()
{
    int opcija1;
    bool kraj(false); 
    std::vector <Stan> stanovi;
    std::vector <Kupac> kupci;
    Prodaje prodaje(20);
    
    std::cout << "Dobrodosli!\n\n\n";
    for(;;)
    {
        std::cout << "Izaberite opciju:\n 0 - kraj\n 1 - uredjivanje stanova\n 2 - uredjivanje kupaca\n 3 - uredjivanje prodaja\n";
        std::cin >> opcija1; Ignorisi();
        if (opcija1 == 0) kraj = true;
        else if (opcija1 == 1)
        {
            for(;;)
            {
                int opcija2;
                std::cout << "Izaberite opciju:\n 0 - nazad\n 1 - dodavanje stana\n 2 - uredjivanje stanova\n 3 - ispis svih stanova\n 4 - kraj\n";
                std::cin >> opcija2; Ignorisi();
                if (opcija2 == 4){kraj = true; break;}
                else if (opcija2 == 0) break;
                else if(opcija2 == 1)
                {
                    UnesiStan(stanovi);
                }
                else if (opcija2 == 2){
                    std::cout << "Odaberite stan. Dostupni stanovi su:\n";
                    int st;
                    for (int i = 0; i < stanovi.size(); i++){
                        std::cout << " " << i + 1 << " - "; stanovi[i].Ispisi(); std::cout << "\n";
                    }
                    std::cin >> st; Ignorisi();
                    int p;
                    std::cout << "Odaberite polje koje zelite urediti:\n";
                    std::cout << " 0 - nazad\n 1 - adresa\n 2 - sprat\n 3 - broj soba\n 4 - da li je stan namjesten\n 5 - kvadratura\n 6 - sve\n";
                    std::cin >> p; Ignorisi();
                    if (p >= 1 && p <= 5)IzmijeniStan(stanovi[st - 1], p);
                    else if (p == 6){for (int i = 1; i < 6; i++) IzmijeniStan(stanovi[st - 1], i);}
                    std::cout << "Stan je uspjesno izmijenjen!\n"; 
                }
                else if (opcija2 == 3){
                    for (int i = 0; i < stanovi.size(); i++){
                        std::cout << i + 1 << ". ";stanovi[i].Ispisi(); std::cout << "\n";
                    }
                }
                if (kraj) break;
            }
        }
        else if (opcija1 == 2){
            for(;;)
            {
                std::cout << "Izaberite opciju:\n 0 - nazad\n 1 - dodavanje kupca\n 2 - uredjivanje kupaca\n 3 - ispis svih kupaca\n 4 - kraj\n";
                int opcija2;
                std::cin >> opcija2; Ignorisi();
                if (opcija2 == 4){kraj = true; break;}
                else if (opcija2 == 0)break;
                else if (opcija2 == 1){
                    UnesiKupca(kupci, false, 0);
                }
                else if (opcija2 == 2){
                    std::cout << "Odaberite kupca kojeg zelite urediti. Dostupni kupci su:\n";
                    for (int i = 0; i < kupci.size(); i++){
                        std::cout << " " << i + 1 << " - "; kupci[i].Ispisi(); std::cout << "\n";}
                    int k; std::cin >> k; Ignorisi();
                    UnesiKupca(kupci, true, k - 1);
                }
                else if (opcija2 == 3){
                    for (int i = 0; i < kupci.size(); i++)
                        {kupci[i].Ispisi(); std::cout << "\n";}
                }
                if (kraj) break;
            }
        }
        else if (opcija1 == 3){
            for(;;){
                std::cout << "Izaberite opciju:\n 0 - nazad\n 1 - dodavanje prodaje\n 2 - uredjivanje prodaje\n 3 - ispis prodaja\n 4 - brisanje prodaja\n 5 - kraj\n";
                int opcija2; std::cin >> opcija2; Ignorisi();
                if (opcija2 == 5) {kraj = true; break;}
                else if (opcija2 == 0) break;
                else if (opcija2 == 1){
                    for(;;)
                    {
                        std::cout << "Izaberite opciju:\n 0 - nazad\n 1 - dodavanje potpuno nove prodaje\n 2 - dodavanje nove prodaje na osnovu arhive\n 3 - kraj\n";
                        int opcija3; std::cin >> opcija3; Ignorisi();
                        if (opcija3 == 0)break;
                        else if (opcija3 == 3) {kraj = true; break;}
                        else if (opcija3 == 1){
                            DodajProdaju(prodaje, stanovi, kupci);
                            std::cout << "Prodaja uspjesno dodana!\n";
                        }
                        else if (opcija3 == 2){
                            for(;;)
                            {
                                std::cout << "Unesite ime i prezime agenta prodaje: ";
                                std::string agent; std::getline(std::cin, agent);
                                int d, m, g; char znak; 
                                std::cout << "Unesite datum prodaje (formata d/m/g): "; std::cin >> d >> znak >> m >> znak >> g; Ignorisi();
                                try
                                {
                                    Datum dat(d,m,g);
                                    double cijena; std::cout << "Unesite cijenu stana: "; std::cin >> cijena; Ignorisi();
                                    std::cout << "Odaberite kupca. Dostupni kupci su:\n";
                                    for (int i = 0; i< kupci.size(); i++){
                                        std::cout << " " << i + 1 << " - "; kupci[i].Ispisi(); std::cout << "\n";
                                    }
                                    int k; std::cin >> k; Ignorisi();
                                    std::cout << "Odaberite stan. Dostupni stanovi su:\n";
                                    for (int i = 0; i < stanovi.size(); i++){
                                        std::cout << " " << i + 1 << " - ";stanovi[i].Ispisi();
                                        std::cout << "\n";
                                    }
                                    int s; std::cin >> s; Ignorisi();
                                    prodaje.RegistrirajProdaju(agent, cijena, dat, kupci[k - 1], stanovi[s - 1]);
                                    std::cout << "Prodaja uspjesno dodana!\n"; break;
                                    
                                }
                                catch(std::domain_error e){
                                    std::cout << "Izuzetak: " << e.what() << "Molimo unesite opet.\n";
                                }
                            }
                            
                        }
                    }
                }
                else if (opcija2 == 2){
                    std::cout << "Odaberite prodaju koju želite urediti. Dostupne prodaje su:\n";
                        for (int i = 0; i < prodaje.DajBrojProdaja(); i++)
                        {
                            std::cout << i + 1 << ".\n"; prodaje.DajProdaju(i).Ispisi(); std::cout << "\n";
                        }
                    int p; std::cin >> p; Ignorisi();
                    for(;;)
                    {
                        std::cout << "Izaberite opciju:\n 0 - nazad\n 1 - izmjena agenta\n 2 - izmjena datuma prodaje\n 3 - izmjena kupca\n 4 - izmjena stana\n 5 - izmjena cijene stana\n";
                        int o; std::cin >> o; Ignorisi();
                        if (o == 0)break;
                        IzmijeniProdaju(prodaje, p, o, kupci, stanovi); break;
                    }
                }
                else if (opcija2 == 3){
                    for(;;){
                        try{
                        std::cout << "Izaberite opciju:\n 0 - nazad\n 1 - ispis svih prodaja\n 2 - ispis prodaja na datum\n 3 - ispis najranije prodaje\n 4 - ispis najskuplje prodaje\n 5 - ispis broja prodaja\n 6 - ispis broja prodaja po datumu\n 7 - ispis broja prodaja po agentu\n 8 - kraj\n";
                        int opcija3; std::cin >> opcija3; Ignorisi();
                        if (opcija3 == 0)break;
                        else if (opcija3 == 8){kraj = true; break;}
                        else if (opcija3 == 1) prodaje.IspisiSveProdaje();
                        else if (opcija3 == 2){
                            Datum dat(UnesiDatum());std::cout << "Prodaje na datum "; dat.Ispisi(); std::cout << " su:\n";
                            prodaje.IspisiProdajeNaDatum(dat);
                        }
                        else if (opcija3 == 3){ prodaje.DajNajranijuProdaju().Ispisi();std::cout << std::endl;}
                        else if (opcija3 == 4){ prodaje.DajNajskupljuProdaju().Ispisi(); std::cout << std::endl;}
                        else if (opcija3 == 5){std::cout << "Broj prodaja: " << prodaje.DajBrojProdaja() << "\n";}
                        else if (opcija3 == 6){
                            Datum dat(UnesiDatum());
                            std::cout << "Broj prodaja na uneseni datum: ";
                            std::cout << prodaje.DajBrojProdajaNaDatum(dat) << std::endl;
                        }
                        else if (opcija3 == 7){
                            std::cout << "Unesite ime agenta: "; 
                            std::string agent; std::getline(std::cin, agent);
                            std::cout << "Broj prodaja unesenog agenta: " << prodaje.DajBrojProdajaOdAgenta(agent) << "\n";
                        }
                        }
                        catch(std::domain_error e){
                            std::cout << "Izuzetak: " << e.what() << "\n";
                        }
                        
                    }
                }
                else if (opcija2 == 4){
                    for(;;)
                    {
                        std::cout << "Izaberite opciju:\n 0 - nazad\n 1 - brisanje najranije prodaje\n 2 - brisanje prodaja agenta\n 3 - brisanje prodaja po datumu\n 4 - brisanje svih prodaja\n";
                        int opcija3; std::cin >> opcija3; Ignorisi();
                        try{
                        if (opcija3 == 0) break;
                        else if (opcija3 == 1){ prodaje.ObrisiNajranijuProdaju(); std::cout << "Najranija prodaja je obrisana!\n";}
                        else if (opcija3 == 2){ 
                            std::cout << "Unesite ime agenta: "; std::string agent; std::getline(std::cin, agent);
                            prodaje.ObrisiProdajeAgenta(agent); std::cout << "Sve prodaje tog agenta su obrisane.\n";}
                        else if (opcija3 == 3){
                            Datum dat(UnesiDatum(true));
                            prodaje.ObrisiProdajeNaDatum(dat);
                            std::cout << "Sve prodaje na taj datum su obrisane.\n";
                        }
                        else if (opcija3 == 4){ prodaje.IsprazniKolekciju(); std::cout << "Sve prodaje su obrisane.\n";}
                        }
                        catch (std::range_error e)
                        {
                            std::cout << "Izuzetak: " << e.what() << ".\n";
                        }
                    }
                }
                if (kraj) break;
            }
            //if (kraj) break;
        }
        if (kraj) break;
    }
    std::cout << "\n\nDovidjenja!";
	return 0;
}