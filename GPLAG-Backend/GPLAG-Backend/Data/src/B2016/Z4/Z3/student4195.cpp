#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <functional>

using std::cout;
using std::string;
using std::cin;
using std::endl;
using std::logic_error;
using std::domain_error;
using std::range_error;


class Datum{
    static void ProvjeriDatum(int,int,int,string);
    int dan,mjesec,godina;
   public:
    Datum(int dan, int mjesec, int godina){ 
        Postavi(dan,mjesec,godina);
    }
    void Postavi(int dan, int mjesec, int godina);
    int DajDan() const { return dan; }
    int DajMjesec() const { return mjesec; }
    int DajGodinu() const { return godina; }
    void Ispisi() const{ cout<<DajDan()<<"/"<<DajMjesec()<<"/"<<DajGodinu(); }
};


bool PrestupnaGodina(int godina){
    if(godina%400==0 or (godina%100!=0 and godina%4==0)) return true;
    return false;
}

int BrojDana(int mjesec, int godina){
    int dani[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if(PrestupnaGodina(godina))
        dani[1]++;
    return dani[mjesec-1];
}

void Datum::ProvjeriDatum(int dan, int mjesec, int godina,string poruka){ //Baci izuzetak ako ne valja, u supr nista ne radi
    if(mjesec<1 or mjesec>12 or dan<1 or godina<1 or dan>BrojDana(mjesec,godina)) 
        throw domain_error(poruka);
}

void Datum::Postavi(int dan,int mjesec, int godina){
    ProvjeriDatum(dan,mjesec,godina,"Neispravan datum");
    Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
}



bool JeLiBroj(char c){
    if(c>='0' and c<='9') return true;
    return false;
}

bool JeLiSlovo(char c){
    if( (c>='A' and c<='Z') or (c>='a' and c<='z')) return true;
    return false;
}

void ProvjeriIme(string ime){
    for(int i=0; i<ime.size(); i++){
        if(!(JeLiSlovo(ime.at(i)) or JeLiBroj(ime.at(i)) or ime.at(i)=='-' or ime.at(i)=='\'' or ime.at(i)==' '))
            throw domain_error("Neispravno ime i prezime");
    }
}

class Kupac{
    string iip;
    Datum dat_rod;
   public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja): iip(ime_i_prezime),dat_rod(datum_rodjenja){
        ProvjeriIme(iip);
    };
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    std::string DajImePrezime() const { return iip; }
    Datum DajDatumRodjenja() const{ return dat_rod; }
    void Ispisi() const {
        cout<<iip<<" ("; 
        dat_rod.Ispisi();
        cout<<")";
    }
};

void Kupac::Postavi(const string &ime_i_prezime, const Datum &datum_rodjenja){
    ProvjeriIme(ime_i_prezime);
    iip=ime_i_prezime; dat_rod=datum_rodjenja;
}


class Stan{
    string adresa;
    int sprat,broj_soba;
    bool namjesten;
    double kvadratura;
   public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten,
     double kvadratura) {Postavi(adresa,sprat,broj_soba,namjesten,kvadratura);}
    void Postavi(const std::string &adresa, int sprat, int broj_soba,
     bool namjesten, double kvadratura);
    std::string DajAdresu() const { return adresa; }
    int DajSprat() const{return sprat; }
    int DajBrojSoba() const { return broj_soba; }
    bool DajNamjesten() const { return namjesten; }
    double DajKvadraturu() const { return kvadratura; }
    void Ispisi() const;
};

void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba,
     bool namjesten, double kvadratura){
         if(sprat<0 or broj_soba<0 or kvadratura<0) throw domain_error("Neispravan unos podataka");
         Stan::adresa=adresa; Stan::namjesten=namjesten;
         Stan::sprat=sprat; Stan::broj_soba=broj_soba; Stan::kvadratura=kvadratura;
}

void Stan::Ispisi() const{
    cout<<"Stan se nalazi na adresi "<<DajAdresu()<<" na "<<DajSprat()<<". spratu i ima "<<DajBrojSoba()<<" ";
    int cifra(broj_soba%10);
    if(((broj_soba/10)%10)!=0) cout<<"soba"; //Uzimano u obzir do 20 soba (vrlo realno)
    else if(cifra==1) cout<<"sobu";
    else if(cifra>=2 and cifra<=4) cout<<"sobe";
    else cout<<"soba";
    cout<<". Kvadratura stana je "<<DajKvadraturu()<<" (m^2) i stan ";
    if(DajNamjesten()) cout<<"je ";
    else cout<<"nije ";
    cout<<"namjesten.";
}
     

class Prodaja{
    string ime_agenta;
    double cijena_stana;
    Datum datum_prodaje;
    Kupac kupac;
    Stan stan;
   public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,             //Prvi konstruktor
    const Datum &datum_prodaje, const Kupac &kupac_stana,
    const Stan &kupljeni_stan):ime_agenta(ime_agenta_prodaje),cijena_stana(cijena_stana), datum_prodaje(datum_prodaje),kupac(kupac_stana),stan(kupljeni_stan){
        if(cijena_stana<0) throw std::domain_error("Neispravna cijena");
        ProvjeriIme(ime_agenta_prodaje);
    }
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,
    int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
    std::string &ime_kupca, const Datum &datum_rodjenja_kupca,
    const std::string &adresa_stana, int sprat_stana, int broj_soba,
    bool namjesten_stan, double broj_kvadrata): //Konstr inicijalizaciona lista
    ime_agenta(ime_agenta_prodaje), cijena_stana(cijena_stana),datum_prodaje(dan_prodaje,mjesec_prodaje,godina_prodaje),
    kupac(ime_kupca,datum_rodjenja_kupca),stan(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata){
        if(cijena_stana<0) throw std::domain_error("Neispravna cijena");
        ProvjeriIme(ime_agenta_prodaje);
    }
    void PromijeniKupca(const Kupac &novi_kupac) { kupac=novi_kupac; };
    void PromijeniStan(const Stan &novi_stan) { stan = novi_stan; }
    void PromijeniDatumKupovine(const Datum &novi_datum) { datum_prodaje=novi_datum; }
    void PromijeniCijenuProdaje(const double &nova_cijena) {
        if(cijena_stana<0) throw std::domain_error("Neispravna cijena");
        cijena_stana=nova_cijena; }
    void PromijeniAgenta(const string &ime) {  //Dodano radi maina 
        ProvjeriIme(ime);
        ime_agenta = ime;
    } 
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImeAgenta() const { return ime_agenta; }
    std::string DajImeKupca() const { return kupac.DajImePrezime(); }
    Datum DajDatumProdaje() const { return datum_prodaje; }
    double DajCijenuStana() const { return cijena_stana; }
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
    void Ispisi() const;
};

void Prodaja::Ispisi() const {
    cout<<std::left<<std::setw(32)<<"Ime agenta: "<<DajImeAgenta()<<endl;
    cout<<std::setw(32)<<"Ime kupca: ";
    kupac.Ispisi();
    cout<<endl;
    cout<<std::setw(32)<<"Zakazani datum prodaje: ";
    datum_prodaje.Ispisi();
    cout<<endl;
    cout<<std::setw(32)<<"Cijena stana: "<<cijena_stana<<endl;
    cout<<"Informacije o stanu:          "<<endl;
    stan.Ispisi();
    cout<<endl;
}

bool ProsliDatum(const Datum &dat1, const Datum &dat2){
    if(dat1.DajGodinu()==dat2.DajGodinu()){
        if(dat1.DajMjesec()==dat2.DajMjesec())
            return dat1.DajDan()<dat2.DajDan();
        return dat1.DajMjesec()<dat2.DajMjesec();
    }
    return dat1.DajGodinu()<dat2.DajGodinu();
}

bool PrethodniDatum(const Prodaja &a, const Prodaja &b){
    Datum dat1(a.DajDatumProdaje()),dat2(b.DajDatumProdaje());
    if(dat1.DajGodinu()==dat2.DajGodinu()){
        if(dat1.DajMjesec()==dat2.DajMjesec()){
            if(dat1.DajDan()==dat2.DajDan())
                return a.DajImeKupca()<b.DajImeKupca();
            return dat1.DajDan()<dat2.DajDan();
        }
        return dat1.DajMjesec()<dat2.DajMjesec();
    }
    return dat1.DajGodinu()<dat2.DajGodinu();
}

bool ProdatPrije(const Prodaja &p1, const Prodaja &p2){
    return ProsliDatum( p1.DajDatumProdaje(),p2.DajDatumProdaje() );
}

bool SkupljiStan(const Prodaja &p1, const Prodaja &p2){
    return p1.DajCijenuStana()>p2.DajCijenuStana();
}

void Prodaja::PomjeriDanUnaprijed(){
    int dan(datum_prodaje.DajDan());
    int mjesec(datum_prodaje.DajMjesec());
    int godina(datum_prodaje.DajGodinu());
    dan++;
    if(dan>BrojDana(mjesec,godina)){
        dan=1;
        mjesec++;
        if(mjesec>12){
            mjesec=1;
            godina++;
        }
    }
    datum_prodaje.Postavi(dan,mjesec,godina);
}

void Prodaja::PomjeriDanUnazad(){
    int dan(datum_prodaje.DajDan());
    int mjesec(datum_prodaje.DajMjesec());
    int godina(datum_prodaje.DajGodinu());
    dan--;
    if(dan<1){
        mjesec--;
            if(mjesec<1){
            mjesec=12;
            godina--;
        }
        dan=BrojDana(mjesec,godina);
    }
    datum_prodaje.Postavi(dan,mjesec,godina);
}

bool IstiDatumi(const Datum &dat1, const Datum &dat2){
    if(dat1.DajDan()==dat2.DajDan() and dat1.DajMjesec()==dat2.DajMjesec() and dat1.DajGodinu()==dat2.DajGodinu()) return true;
    return false;
}

class Prodaje{
    int broj_prodaja, max_broj_prodaja;
    Prodaja **lista_prodaja;
   public:
    explicit Prodaje(int max_broj_prodaja):broj_prodaja(0), max_broj_prodaja(max_broj_prodaja),lista_prodaja(new Prodaja*[max_broj_prodaja]){
        for(int i=0; i<max_broj_prodaja; i++) lista_prodaja[i] = nullptr;
    }
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
    ~Prodaje() { 
        for(int i=0; i<broj_prodaja; i++) 
            delete lista_prodaja[i]; 
        delete[] lista_prodaja; 
    }
    Prodaje(const Prodaje &prodaje);
    Prodaje(Prodaje &&prodaje);
    Prodaje &operator =(const Prodaje &prodaje);
    Prodaje &operator =(Prodaje &&prodaje);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje,
     double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,
    const Stan &kupljeni_stan);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje,
    int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
     const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,
     int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void RegistrirajProdaju(Prodaja *prodaja);
    int DajBrojProdaja() const {return broj_prodaja; }
    int DajBrojProdajaNaDatum(const Datum &datum) const;
    int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const;
    Prodaja &DajNajranijuProdaju();
    Prodaja DajNajranijuProdaju() const;
    Prodaja &DajNajskupljuProdaju();
    Prodaja DajNajskupljuProdaju() const;
    Prodaja &DajProdaju(int indeks) const {
        if(indeks>=broj_prodaja) throw std::domain_error("Nevalidan indeks");
        return *lista_prodaja[indeks];
    }
    void IsprazniKolekciju();
    void ObrisiNajranijuProdaju();
    void ObrisiProdajeAgenta(const std::string &ime_agenta); 
    void ObrisiProdajeNaDatum(const Datum &datum);
    void IspisiProdajeNaDatum(const Datum &datum) const;
    void IspisiSveProdaje() const;
};


void Prodaje::IspisiSveProdaje() const {
    std::vector<Prodaja> kandid;
    for(int i=0; i<broj_prodaja; i++){
        kandid.push_back(*lista_prodaja[i]);
    }
    std::sort(kandid.begin(), kandid.end(), [](Prodaja a, Prodaja b){
        return PrethodniDatum(a,b);
    });
    for(int i=0; i<kandid.size(); i++){
        kandid.at(i).Ispisi();
        cout<<endl;
    }
}

void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const{
     std::vector<Prodaja> kandid;
     for(int i=0; i<broj_prodaja; i++){
        if(IstiDatumi(datum,lista_prodaja[i]->DajDatumProdaje())){
            kandid.push_back(*lista_prodaja[i]);
        }
    }
    std::sort(kandid.begin(), kandid.end(), [](Prodaja a, Prodaja b){
        return a.DajImeKupca()<b.DajImeKupca();
    });
    for(int i=0; i<kandid.size(); i++){
        kandid[i].Ispisi();
        cout<<endl;
    }
}

void Prodaje::ObrisiProdajeNaDatum(const Datum &datum){
    for(int i=0; i<broj_prodaja; i++){
        if(IstiDatumi(datum,lista_prodaja[i]->DajDatumProdaje())){
            delete lista_prodaja[i];
            for(int j=i+1; j<broj_prodaja; j++)
                lista_prodaja[j]=lista_prodaja[j-1];
            i--;
            broj_prodaja--;
        }
    }
}

void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta){
    for(int i=0; i<broj_prodaja; i++){
        if(lista_prodaja[i]->DajImeAgenta()==ime_agenta){
            delete lista_prodaja[i];
            for(int j=i+1; j<broj_prodaja; j++)
                lista_prodaja[j]=lista_prodaja[j-1];
            i--;
            broj_prodaja--;
        }
    }
}

void Prodaje::ObrisiNajranijuProdaju(){
    if(broj_prodaja==0) throw range_error("Prazna kolekcija");
    auto pok=std::min_element(lista_prodaja, lista_prodaja+broj_prodaja, [](Prodaja* pok1,Prodaja* pok2){
        return ProsliDatum(pok1->DajDatumProdaje(),pok2->DajDatumProdaje());
    });
    for(int i=0; i<broj_prodaja; i++){
        if(lista_prodaja[i]==*pok){
            delete lista_prodaja[i];
            for(int j=i+1; j<broj_prodaja; j++) 
                lista_prodaja[j]=lista_prodaja[j-1];
            break;
        }
    }
    broj_prodaja--;
}

void Prodaje::IsprazniKolekciju(){
    for(int i=0; i<broj_prodaja; i++) delete lista_prodaja[i];
    broj_prodaja=0;
}

Prodaja Prodaje::DajNajskupljuProdaju() const{
    return DajNajskupljuProdaju();
}

Prodaja& Prodaje::DajNajskupljuProdaju(){
    if(broj_prodaja==0) throw domain_error("Nema registriranih prodaja");
    return **std::max_element(lista_prodaja, lista_prodaja+broj_prodaja, [](Prodaja* pok1,Prodaja* pok2){
        return pok1->DajCijenuStana()<pok2->DajCijenuStana();
    });
}

Prodaja Prodaje::DajNajranijuProdaju() const{
     return DajNajranijuProdaju();
}

Prodaja& Prodaje::DajNajranijuProdaju(){
    if(broj_prodaja==0) throw domain_error("Nema registriranih prodaja");
    return **std::min_element(lista_prodaja, lista_prodaja+broj_prodaja, [](Prodaja* pok1,Prodaja* pok2){
        return ProsliDatum(pok1->DajDatumProdaje(),pok2->DajDatumProdaje());
    });
}

int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const{
    return std::count_if(lista_prodaja, lista_prodaja+broj_prodaja, [ime_agenta](Prodaja* pok1){
        return pok1->DajImeAgenta()==ime_agenta;
    });
}

int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const{
    return std::count_if(lista_prodaja, lista_prodaja+broj_prodaja, [datum](Prodaja* pok1){
        return IstiDatumi(pok1->DajDatumProdaje(),datum);
    });
}

void Prodaje::RegistrirajProdaju(Prodaja *prodaja){
        if(broj_prodaja==max_broj_prodaja) throw std::range_error("Dostignut maksimalan broj prodaja");
        lista_prodaja[broj_prodaja]= prodaja;
        broj_prodaja++;
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana,int dan_prodaje,int mjesec_prodaje, 
int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, 
const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata){
    
     if(broj_prodaja==max_broj_prodaja) throw std::range_error("Dostignut maksimalan broj prodaja");
     lista_prodaja[broj_prodaja]=new Prodaja(ime_agenta_prodaje, cijena_stana, dan_prodaje, mjesec_prodaje, 
                                             godina_prodaje, ime_kupca,datum_rodjenja_kupca, 
                                             adresa_stana, sprat_stana,broj_soba,
                                             namjesten_stan,broj_kvadrata);
      broj_prodaja++;
      
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje,
double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,const Stan &kupljeni_stan) {
   
     if(broj_prodaja==max_broj_prodaja) throw std::range_error("Dostignut maksimalan broj prodaja");
     lista_prodaja[broj_prodaja]=new Prodaja(ime_agenta_prodaje,cijena_stana,datum_prodaje,kupac_stana,kupljeni_stan);
     broj_prodaja++;
}

Prodaje& Prodaje::operator =(Prodaje &&prodaje){
    for(int i=0; i<broj_prodaja; i++) delete lista_prodaja[i];
    lista_prodaja=prodaje.lista_prodaja; 
    broj_prodaja=prodaje.broj_prodaja;
    lista_prodaja=nullptr; 
    prodaje.broj_prodaja=0; //Jako bitno radi destruktora
    return *this;
}

Prodaje& Prodaje::operator =(const Prodaje &prodaje){
    try{
        Prodaja** prostor(new Prodaja*[broj_prodaja]);
        for(int i=0; i<broj_prodaja; i++) delete lista_prodaja[i]; //Izbrisemo postojece
        broj_prodaja=prodaje.broj_prodaja;
        max_broj_prodaja=prodaje.max_broj_prodaja;
        lista_prodaja=prostor;
        for(int i=0; i<broj_prodaja; i++) lista_prodaja[i]=nullptr;
        try{
            for(int i=0; i<broj_prodaja; i++){
                lista_prodaja[i]=new Prodaja(*prodaje.lista_prodaja[i]);
            }
        }
        catch(std::bad_alloc){
            for(int i=0; i<broj_prodaja; i++) delete lista_prodaja[i];
            throw;
        }
    }
    catch(std::bad_alloc){
        throw;
    }
    return *this;
}

inline Prodaje::Prodaje(Prodaje &&prodaje):broj_prodaja(prodaje.DajBrojProdaja()),max_broj_prodaja(prodaje.broj_prodaja),lista_prodaja(prodaje.lista_prodaja){
    prodaje.lista_prodaja=nullptr; //Samo preusmjerili pokazivac na resurse i uzeli broj prodaja
    prodaje.broj_prodaja=0; //Jako bitno radi destruktora
}

Prodaje::Prodaje(const Prodaje &prodaje): broj_prodaja(prodaje.DajBrojProdaja()), max_broj_prodaja(prodaje.max_broj_prodaja),lista_prodaja(new Prodaja*[broj_prodaja]){
    for(int i=0; i<broj_prodaja; i++) lista_prodaja[i]=nullptr;
    try{
        for(int i=0; i<broj_prodaja; i++){
            lista_prodaja[i]=new Prodaja(*(prodaje.lista_prodaja[i]));
        }
    }
    catch(std::bad_alloc){
         for(int i=0; i<broj_prodaja; i++) delete lista_prodaja[i];
         delete[] lista_prodaja;
         throw;
    }
}

Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja): broj_prodaja(spisak_prodaja.size()),max_broj_prodaja(broj_prodaja), lista_prodaja(new Prodaja*[broj_prodaja]){
    for(int i=0; i<broj_prodaja; i++) lista_prodaja[i]=nullptr;
    int j(0);
    try{
        for(auto it=spisak_prodaja.begin(); it!=spisak_prodaja.end(); it++,j++){
            lista_prodaja[j]=new Prodaja(*it);
        }
    }
    catch(std::bad_alloc){
        for(int i=0; i<broj_prodaja; i++) delete lista_prodaja[i];
        delete[] lista_prodaja;
        throw;
    }
}

void DodavanjeStana(std::vector<Stan>& stanovi){
    string adresa;
    int sprat,broj_soba,nam_int;
    bool namjesten;
    double kvadratura;
    while(true){
        try{
            cin.ignore(10000,'\n'); //U ovu funkc se uslo putem unosa broja
          cout<<"Unesite adresu: ";
          getline(cin,adresa);
          cout<<"Unesite sprat: ";
          cin>>sprat;
          cout<<"Unesite broj soba: ";
          cin>>broj_soba;
          cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
          cin>>nam_int;
          cout<<"Unesite kvadraturu: ";
          cin>>kvadratura;
          if(nam_int!=0 and nam_int!=1) throw std::domain_error("Neispravan unos podataka");
          if(nam_int==0) namjesten=false;
          else namjesten=true;
          stanovi.push_back(Stan(adresa,sprat,broj_soba,namjesten,kvadratura));
          cout<<"Stan je uspjesno dodan!"<<endl;
          return;
        }
        catch(std::domain_error e){
            cout<<"Izuzetak: "<<e.what()<< ". Molimo unesite opet."<<endl;
        }
    }
}

void IspisSvihStanova(std::vector<Stan>& stanovi){
    for(int i=0; i<stanovi.size(); i++){
        cout<<i+1<<". ";
        stanovi.at(i).Ispisi();
        cout<<endl;
    }
}

void UredjivanjeStana(std::vector<Stan>& stanovi){
    if(stanovi.size()==0){
        cout<<"Nema dostupnih stanova!"<<endl;
        return;
    }
    cout<<"Odaberite stan. Dostupni stanovi su: "<<endl;
    int unos;
    for(int i=0; i<stanovi.size(); i++){
        cout<<" "<<i+1<<" - ";
        stanovi.at(i).Ispisi();
        cout<<endl;
    }
    cin>>unos;
    if(unos<1 or unos>stanovi.size()){
        cout<<"Pogresan indeks!"<<endl;
        return;
    }
    int polje;
    cout<<"\nOdaberite polje koje zelite urediti:"<<endl;
    cout<<" 0 - nazad\n 1 - adresa\n 2 - sprat\n 3 - broj_soba\n 4 - da li je stan namjesten\n 5 - kvadratura\n 6 - sve\n";
    cin>>polje;
    switch(polje){
        case 0: return;
        case 1:{
            string adresa;
            cout<<"Unesite adresu: ";
            cin.ignore(10000,'\n');
            getline(cin,adresa);
            stanovi.at(unos-1).Postavi(
                                adresa,stanovi.at(unos-1).DajSprat(),stanovi.at(unos-1).DajBrojSoba(),
                                stanovi.at(unos-1).DajNamjesten(),stanovi.at(unos-1).DajKvadraturu());
            cout<<"Stan je uspjesno izmijenjen!"<<endl;
            return;    
        }
        case 2:{
            int sprat;
            while(true){
                try{
                    cout<<"Unesite sprat: ";
                    cin>>sprat;
                    if(sprat<0){ //Jednostavnije je mnogo ovako provjeriti, nego pisati try catch blok, smijestati sve to u petlju itd.
                        cout<<"Izuzetak: Neispravan unos podataka. Molimo unesite opet."<<endl;
                        continue;
                    }
                    stanovi.at(unos-1).Postavi(
                                    stanovi.at(unos-1).DajAdresu(),sprat,stanovi.at(unos-1).DajBrojSoba(),
                                    stanovi.at(unos-1).DajNamjesten(),stanovi.at(unos-1).DajKvadraturu());
                    
                    cout<<"Stan je uspjesno izmijenjen!"<<endl;
                    return;
                }
                catch(std::domain_error e){
                    cout<<"Izuzetak: "<<e.what()<< ". Molimo unesite opet."<<endl;
                }
            }
        }
        case 3:{
            int broj_soba;
            while(true){
                try{
                    cout<<"Unesite broj soba: ";
                    cin>>broj_soba;
                    stanovi.at(unos-1).Postavi(
                                    stanovi.at(unos-1).DajAdresu(), stanovi.at(unos-1).DajSprat(),broj_soba,
                                    stanovi.at(unos-1).DajNamjesten(),stanovi.at(unos-1).DajKvadraturu());
                   cout<<"Stan je uspjesno izmijenjen!"<<endl;
                   return;
                }
                catch(std::domain_error e){
                    cout<<"Izuzetak: "<<e.what()<< ". Molimo unesite opet."<<endl;
                }               
            }
        }
        case 4:{
            bool da_li;
            int nam_int;
            while(true){
                try{
                    cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                    cin>>nam_int;
                    if(nam_int!=0 and nam_int!=1){
                        cout<<"Izuzetak: Neispravan unos podataka. Molimo unesite opet."<<endl;
                        continue;
                    }
                    if(nam_int==0) da_li=false;
                    else da_li=true;
                    stanovi.at(unos-1).Postavi(
                                        stanovi.at(unos-1).DajAdresu(), stanovi.at(unos-1).DajSprat(),
                                        stanovi.at(unos-1).DajBrojSoba(), da_li,stanovi.at(unos-1).DajKvadraturu());
                    cout<<"Stan je uspjesno izmijenjen!"<<endl;
                    return;
                }
                catch(std::domain_error e){
                    cout<<"Izuzetak: "<<e.what()<< ". Molimo unesite opet."<<endl;
                }                
            }
        }
        case 5:{
            double kvadratura;
            while(true){
                try{
                    cout<<"Unesite kvadraturu: ";
                    cin>>kvadratura;
                    stanovi.at(unos-1).Postavi(
                                    stanovi.at(unos-1).DajAdresu(), stanovi.at(unos-1).DajSprat(),
                                    stanovi.at(unos-1).DajBrojSoba(),
                                    stanovi.at(unos-1).DajNamjesten(),kvadratura);
                    cout<<"Stan je uspjesno izmijenjen!"<<endl;
                    return;
                }
                catch(std::domain_error e){
                    cout<<"Izuzetak: "<<e.what()<< ". Molimo unesite opet."<<endl;
                }                
            }
        }
        case 6:{
            while(true){
                string adresa;
                int broj_soba,sprat,nam_int;
                bool namjesten;
                double kvadratura;
                try{
                  cin.ignore(10000,'\n'); //U ovu funkc se uslo putem unosa broja
                  cout<<"Unesite adresu: ";
                  getline(cin,adresa);
                  cout<<"Unesite sprat: ";
                  cin>>sprat;
                  cout<<"Unesite broj soba: ";
                  cin>>broj_soba;
                  cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                  cin>>nam_int;
                  cout<<"Unesite kvadraturu: ";
                  cin>>kvadratura;
                  if(nam_int!=0 and nam_int!=1) throw std::domain_error("Neispravan unos podataka");
                  if(nam_int==0) namjesten=false;
                  else namjesten=true;
                  stanovi.at(unos-1)=Stan (adresa,sprat,broj_soba,namjesten,kvadratura);
                  cout<<"Stan je uspjesno izmijenjen!"<<endl;
                  return;
                }
                catch(std::domain_error e){
                    cout<<"Izuzetak: "<<e.what()<< ". Molimo unesite opet."<<endl;
                }
            }
        }
    }
}

int UredjivanjeSvihStanova(std::vector<Stan>& stanovi){
    std::vector<std::function<void(std::vector<Stan>&)>> funkc{DodavanjeStana,UredjivanjeStana,IspisSvihStanova};
    int br;
    while(true){
        cout<<"Izaberite opciju:\n 0 - nazad\n 1 - dodavanje stana\n 2 - uredjivanje stanova\n 3 - ispis svih stanova\n 4 - kraj"<<endl;
        cin>>br;
        if(br==0) return 1;
        if(br==4) return 0;
        funkc.at(br-1)(stanovi);
        cout<<endl;
    }
    return 1;
}

void DodavanjeKupca(std::vector<Kupac> &kupci){
    string iip;
    while(true){
        try{
            cin.ignore(10000,'\n');
            cout<<"Unesite ime i prezime kupca: ";
            getline(cin,iip);
            int dan,mjesec,godina;
            cout<<"Unesite datum rodjenja (formata d/m/g): ";
            cin>>dan; cin.get();
            cin>>mjesec; cin.get();
            cin>>godina;
            Datum dat(dan,mjesec,godina);
            kupci.push_back(Kupac(iip,dat));
            cout<<"Kupac je uspjesno dodan!"<<endl;
            return;
        }
        catch(std::domain_error e){
            cout<<"Izuzetak: "<<e.what()<< ". Molimo unesite opet."<<endl;
        }
    }
}
/*Odaberite kupca kojeg zelite urediti. Dostupni kupci su:*/
void UredjivanjeKupca(std::vector<Kupac> &kupci){
    int unos;
    cout<<"Odaberite kupca kojeg zelite urediti. Dostupni kupci su:"<<endl;
    for(int i=0; i<kupci.size(); i++){
        cout<<" "<<i+1<<" - ";
        kupci.at(i).Ispisi();
        cout<<endl;
    }
    cin>>unos;
    if(unos<1 or unos>kupci.size()){
        cout<<"Pogresan indeks!";
        return;
    }
    string iip;
    try{
        cin.ignore(10000,'\n');
        cout<<"Unesite ime i prezime kupca: ";
        getline(cin,iip);
        int dan,mjesec,godina;
        cout<<"Unesite datum rodjenja (formata d/m/g): ";
        cin>>dan; cin.get();
        cin>>mjesec; cin.get();
        cin>>godina;
        Datum dat(dan,mjesec,godina);
        kupci.at(unos-1)=Kupac(iip,dat);
        cout<<"Kupac je uspjesno izmijenjen!"<<endl;
        return ;
    }
    catch(std::domain_error e){
        cout<<"Izuzetak: "<<e.what()<< ". Molimo unesite opet."<<endl;
    }
}

void IspisSvihKupaca(std::vector<Kupac> &kupci){
    for(int i=0; i<kupci.size(); i++){
        kupci.at(i).Ispisi();
        cout<<endl;
    }
}

int UredjivanjeSvihKupaca(std::vector<Kupac>& kupci){
    std::vector<std::function<void(std::vector<Kupac>&)>> funkc{DodavanjeKupca,UredjivanjeKupca,IspisSvihKupaca};
    int br;
    while(true){
        cout<<"Izaberite opciju:\n 0 - nazad\n 1 - dodavanje kupca\n 2 - uredjivanje kupaca\n 3 - ispis svih kupaca\n 4 - kraj"<<endl;
        cin>>br;
        if(br==0) return 1;
        if(br==4) return 0;
        funkc.at(br-1)(kupci);
        cout<<endl;
    }
    return 1;
}

 void DodavanjeProdaje(Prodaje &prodaje, std::vector<Stan>& stanovi, std::vector<Kupac>& kupci){
     while(true){
         int opcija(0);
         try{
             cout<<"Izaberite opciju:"<<endl;
             cout<<" 0 - nazad\n 1 - dodavanje potpuno nove prodaje\n 2 - dodavanje nove prodaje na osnovu arhive\n 3 - kraj"<<endl;
             cin>>opcija;
             if(opcija==3) throw std::runtime_error("Kraj");
             switch(opcija){
                 case 0: return;
                 case 1:{
                     string iipa,iipk,adresa;
                     int dan1,mjesec1,godina1,dan,mjesec,godina,cijena,sprat,broj_soba,nam_int;
                     bool namjesten;
                     double kvadratura;
                     while(true){
                         try{
                             cin.ignore(10000,'\n');
                             cout<<"Unesite ime i prezime agenta prodaje: ";
                             getline(cin,iipa);
                             cout<<"Unesite datum prodaje (formata d/m/g): ";
                             cin>>dan1; cin.get();
                             cin>>mjesec1; cin.get();
                             cin>>godina1;
                             cout<<"Unesite cijenu stana: ";
                             cin>>cijena;
                             cin.ignore(10000,'\n');
                             cout<<"Unesite ime kupca: ";
                             getline(cin,iipk);
                             cout<<"Unesite datum rodjenja kupca (formata d/m/g): ";
                             cin>>dan; cin.get();
                             cin>>mjesec; cin.get();
                             cin>>godina;
                             cin.ignore(10000,'\n');
                             cout<<"Unesite adresu: ";
                             getline(cin,adresa);
                             cout<<"Unesite sprat: ";
                             cin>>sprat;
                             cout<<"Unesite broj soba: ";
                             cin>>broj_soba;
                             cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                             cin>>nam_int;
                             cout<<"Unesite kvadraturu: ";
                             cin>>kvadratura;
                             if(nam_int!=0 and nam_int!=1) throw std::domain_error("Neispravan unos podataka");
                             if(nam_int==0) namjesten=false;
                             else namjesten=true;
                             prodaje.RegistrirajProdaju(iipa,cijena,dan1,mjesec1,godina1,iipk,Datum(dan,mjesec,godina),adresa,
                             sprat,broj_soba,namjesten,kvadratura);
                             stanovi.push_back(Stan(adresa,sprat,broj_soba,namjesten,kvadratura));
                             kupci.push_back(Kupac(iipk,Datum(dan,mjesec,godina)));
                             cout<<"Prodaja uspjesno dodana!"<<endl;
                             throw std::runtime_error("Kraj");
                             
                         }
                         catch(std::domain_error e){
                             cout<<"Izuzetak: "<<e.what()<<" . Molimo unesite opet."<<endl;
                         }
                         catch(std::range_error e){
                             cout<<"Izuzetak: "<<e.what()<<endl;
                             throw std::runtime_error("Kraj");
                         }
                     }
                 }
                 case 2: {
                     string iipa;
                    // Unesite ime i prezime agenta prodaje: Unesite datum prodaje (formata d/m/g): Unesite cijenu stana: Odaberite kupca. Dostupni kupci su:
                     while(true){
                         try{
                             cin.ignore(1000,'\n');
                             cout<<"Unesite ime i prezime agenta prodaje: ";
                             getline(cin,iipa);
                             cout<<"Unesite datum prodaje (formata d/m/g): ";
                             int dan,mjesec,godina;
                             cin>>dan; cin.get();
                             cin>>mjesec; cin.get();
                             cin>>godina;
                             int cijena;
                             cout<<"Unesite cijenu stana: ";
                             cin>>cijena;
                             cout<<"Odaberite kupca. Dostupni kupci su:"<<endl;
                             int no_kupca;
                             for(int i=0; i<kupci.size(); i++){
                                 cout<<" "<<i+1<<" - ";
                                 kupci.at(i).Ispisi();
                                 cout<<endl;
                             }
                             cin>>no_kupca;
                             int no_stana;
                             cout<<"Odaberite stan. Dostupni stanovi su: "<<endl;
                             for(int i=0; i<stanovi.size(); i++){
                                 cout<<" "<<i+1<<" - ";
                                 stanovi.at(i).Ispisi();
                                 cout<<endl;
                             }
                             cin>>no_stana;
                             prodaje.RegistrirajProdaju(iipa,cijena,Datum(dan,mjesec,godina),kupci.at(no_kupca-1),stanovi.at(no_stana-1));
                             cout<<"Prodaja uspjesno dodana!"<<endl;
                             throw std::runtime_error("e");
                         }
                         catch(std::domain_error e){
                             cout<<"Izuzetak: "<<e.what()<<". Molimo unesite ponovo."<<endl;
                         }
                     }
                }
            }
            return;
        }
        catch(std::runtime_error){
            if (opcija==3){
                cout<<endl;
                throw;
            } 
        }
    }
}

void UredjivanjeProdaja(Prodaje &prodaje, std::vector<Stan>& stanovi, std::vector<Kupac>& kupci){
     int prodaja(0);
     cout<<"Odaberite prodaju koju želite urediti. Dostupne prodaje su:"<<endl;
     for(int i=0; i<prodaje.DajBrojProdaja(); i++){
         cout<<i+1<<"."<<endl;
         prodaje.DajProdaju(i).Ispisi();
         if(i!=prodaje.DajBrojProdaja()-1) cout<<endl;
     }
     cin>>prodaja;
     if(prodaja<0 or prodaja>prodaje.DajBrojProdaja()){
         cout<<"Nevalidan indeks";
         return;
     }
     prodaja--;
     int option(0);
     cout<<"Izaberite opciju:"<<endl;
     cout<<" 0 - nazad\n 1 - izmjena agenta\n 2 - izmjena datuma prodaje\n 3 - izmjena kupca\n 4 - izmjena stana\n 5 - izmjena cijene stana"<<endl;
     cin>>option;
     switch(option){
         case 0: return;
         case 1:{
              cin.ignore(10000,'\n');
             while(true){
                 try{
                     string iip;
                     cout<<"Unesite ime i prezime agenta prodaje: ";
                     getline(cin,iip);
                     prodaje.DajProdaju(prodaja).PromijeniAgenta(iip);
                     cout<<"Prodaja je uspjesno izmijenjena!"<<endl;
                     return;
                 }
                 catch(std::domain_error e){
                     cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<endl;
                 }
             }
         }
         case 2:{
             while(true){
                 try{
                     cout<<"Unesite datum prodaje (formata d/m/g): ";
                     int dan,mjesec,godina;
                     cin>>dan; cin.get();
                     cin>>mjesec; cin.get();
                     cin>>godina;
                     prodaje.DajProdaju(prodaja).PromijeniDatumKupovine(Datum(dan,mjesec,godina));
                     cout<<"Prodaja je uspjesno izmijenjena!"<<endl;
                     return;
                 }
                 catch(std::domain_error e){
                     cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<endl;
                 }
             }
         }
         case 3:{
             cout<<"Izaberite opciju:"<<endl;
             int opcija;
             cout<<" 0 - nazad\n 1 - odabir postojeceg kupca\n 2 - dodavanje novog kupca"<<endl;
             cin>>opcija;
             switch(opcija){
                 case 0: return;
                 case 1:{
                     cout<<"Odaberite kupca. Dostupni kupci su:"<<endl;
                     int no_kupca;
                     for(int i=0; i<kupci.size(); i++){
                         cout<<" "<<i+1<<" - ";
                         kupci.at(i).Ispisi();
                         cout<<endl;
                     }
                     cin>>no_kupca;
                     prodaje.DajProdaju(prodaja).PromijeniKupca(kupci.at(no_kupca-1));
                     cout<<"Prodaja je uspjesno izmijenjena!"<<endl;
                     return;
                     
                 }
                 case 2:{
                     string iip;
                      while(true){
                         try{
                             cin.ignore(10000,'\n');
                             cout<<"Unesite ime i prezime kupca: ";
                             getline(cin,iip);
                             cout<<"Unesite datum rodjenja (formata d/m/g): ";
                             int dan,mjesec,godina;
                             cin>>dan; cin.get();
                             cin>>mjesec; cin.get();
                             cin>>godina;
                             prodaje.DajProdaju(prodaja).PromijeniKupca(Kupac(iip,Datum(dan,mjesec,godina)));
                             cout<<"Prodaja je uspjesno izmijenjena!"<<endl;
                             return;
                         }
                         catch(std::domain_error e){
                            cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<endl;
                         }
                     } 
                 }
             }
         }
         case 4:{
            cout<<"Izaberite opciju:"<<endl;
             int opcija;
             cout<<" 0 - nazad\n 1 - odabir postojeceg stana\n 2 - dodavanje novog stana"<<endl;
             cin>>opcija;
             switch(opcija){
                 case 0:return;
                 case 1:{
                     cout<<"Odaberite stan. Dostupni stanovi su:"<<endl;
                     int no_stana;
                     for(int i=0; i<stanovi.size(); i++){
                         cout<<" "<<i+1<<" - ";
                         stanovi.at(i).Ispisi();
                         cout<<endl;
                     }
                     cin>>no_stana;
                     prodaje.DajProdaju(prodaja).PromijeniStan(stanovi.at(no_stana-1));
                     cout<<"Prodaja je uspjesno izmijenjena!"<<endl;
                     return;
                 }
                 case 2:{
                     string adresa;
                     int sprat,broj_soba,nam_int;
                     double kvadratura;
                     bool namjesten;
                      while(true){
                         try{
                              cin.ignore(10000,'\n'); //U ovu funkc se uslo putem unosa broja
                              cout<<"Unesite adresu: ";
                              getline(cin,adresa);
                              cout<<"Unesite sprat: ";
                              cin>>sprat;
                              cout<<"Unesite broj soba: ";
                              cin>>broj_soba;
                              cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                              cin>>nam_int;
                              cout<<"Unesite kvadraturu: ";
                              cin>>kvadratura;
                              if(nam_int!=0 and nam_int!=1) throw std::domain_error("Neispravan unos podataka");
                              if(nam_int==0) namjesten=false;
                              else namjesten=true;
                              prodaje.DajProdaju(prodaja).PromijeniStan(Stan(adresa,sprat,broj_soba,namjesten,kvadratura));
                              cout<<"Prodaja je uspjesno izmijenjena!"<<endl;
                              return;
                         }
                         catch(std::domain_error e){
                            cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<endl;
                         }
                     } 
                 }
             }            
         }
         case 5:{
             while(true){
                 try{
                     cout<<"Unesite cijenu stana: ";
                     int cijena;
                     cin>>cijena;
                     prodaje.DajProdaju(prodaja).PromijeniCijenuProdaje(cijena);
                     cout<<"Prodaja je uspjesno izmijenjena!"<<endl;
                    return;
                 }
                 catch(std::domain_error e){
                    cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<endl;
                 }
             }             
         }
     }
 }

 void IspisProdaja(Prodaje &prodaje, std::vector<Stan>& stanovi, std::vector<Kupac>& kupci){
    while(true){
         int opcija(0);
        try{
             cout<<"Izaberite opciju: "<<endl;
             cout<<" 0 - nazad\n 1 - ispis svih prodaja\n 2 - ispis prodaja na datum\n 3 - ispis najranije prodaje";
             cout<<"\n 4 - ispis najskuplje prodaje\n 5 - ispis broja prodaja\n 6 - ispis broja prodaja po datumu\n 7 - ispis broja prodaja po agentu\n 8 - kraj"<<endl;
             cin>>opcija;
             switch(opcija){
                 case 0: return;
                 case 8: throw std::runtime_error("e");
                 case 1: {
                     prodaje.IspisiSveProdaje();
                     throw std::runtime_error("e");
                 }
                 case 2:{
                     while(true){
                         try{
                             cout<<"Unesite datum rodjenja (formata d/m/g): ";
                             int dan,mjesec,godina;
                             cin>>dan; cin.get();
                             cin>>mjesec; cin.get();
                             cin>>godina;
                             Datum dat(dan,mjesec,godina);
                             cout<<"Prodaje na datum ";
                             dat.Ispisi();
                             cout<<" su: "<<endl<<endl;
                             prodaje.IspisiProdajeNaDatum(Datum(dan,mjesec,godina));
                             throw std::runtime_error("e");
                         }
                         catch(std::domain_error e){
                            cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<endl;
                         }
                     }
                 }
                 case 3: {
                     prodaje.DajNajranijuProdaju().Ispisi();
                     throw std::runtime_error("e");
                 }
                 case 4: {
                     prodaje.DajNajskupljuProdaju().Ispisi();
                     throw std::runtime_error("e") ;
                 }
                 case 5: {
                     cout<<"Broj prodaja: ";
                     cout<<prodaje.DajBrojProdaja();
                     cout<<endl;
                     throw std::runtime_error("e") ;
                 }
                 case 6: {
                     while(true){
                         try{
                             cout<<"Unesite datum rodjenja (formata d/m/g): ";
                             int dan,mjesec,godina;
                             cin>>dan; cin.get();
                             cin>>mjesec; cin.get();
                             cin>>godina;
                             cout<<"Broj prodaja na uneseni datum: ";
                             cout<<prodaje.DajBrojProdajaNaDatum(Datum(dan,mjesec,godina));
                             cout<<endl;
                             throw std::runtime_error("e");
                         }
                         catch(std::domain_error e){
                            cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<endl;
                         }
                     }
                 }
                 case 7: {
                     cin.ignore(10000,'\n');
                     while(true){
                         try{
                             string iip;
                             cout<<"unesite ime i prezime agenta prodaje: ";
                             getline(cin,iip);
                             cout<<"Broj prodaja unesenog agenta: ";
                             cout<<prodaje.DajBrojProdajaOdAgenta(iip)<<endl;
                             cout<<endl;
                              throw std::runtime_error("e");
                         }
                         catch(std::domain_error e){
                             cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<endl;
                         }
                     }
                 }
             }
        }
        catch(std::runtime_error) {
            if(opcija==8) throw;
            cout<<endl;
            
        }
    }
}
 
 void BrisanjeProdaja(Prodaje &prodaje, std::vector<Stan>& stanovi, std::vector<Kupac>& kupci){
     while(true){
         try {
             cout<<"Izaberite opciju:"<<endl;
             int opcija(0);
             cout<<" 0 - nazad\n 1 - brisanje najranije prodaje\n 2 - brisanje prodaja agenta";
             cout<<"\n 3 - brisanje prodaja po datumu\n 4 - brisanje svih prodaja\n";
             cin>>opcija;
             switch(opcija){
                 case 0: return;
                 case 1:{
                     try{
                         prodaje.ObrisiNajranijuProdaju(); 
                         cout<<"Najranija prodaja obrisana."<<endl;
                          throw std::runtime_error("e");
                     }
                     catch(std::range_error e){
                         cout<<"Izuzetak: "<<e.what()<<"."<<endl;
                          throw std::runtime_error("e");
                     }
                 } 
                 case 2:{
                     cin.ignore(10000,'\n');
                     while(true){
                         try{
                             string iip;
                             cout<<"unesite ime i prezime agenta prodaje: ";
                             getline(cin,iip);
                             prodaje.ObrisiProdajeAgenta(iip);
                             cout<<"Sve prodaje tog agenta su obrisane."<<endl;
                              throw std::runtime_error("e");
                         }
                         catch(std::domain_error e){
                             cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<endl;
                         }
                     }
                 }
                 case 3:{
                    while(true){
                         try{
                             cout<<"Unesite datum rodjenja (formata d/m/g): ";
                             int dan,mjesec,godina;
                             cin>>dan; cin.get();
                             cin>>mjesec; cin.get();
                             cin>>godina;
                             prodaje.ObrisiProdajeNaDatum(Datum(dan,mjesec,godina));
                             cout<<"Sve prodaje na taj datum su obrisane."<<endl;
                              throw std::runtime_error("e");
                         }
                         catch(std::domain_error e){
                            cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<endl;
                         }
                     }
                 }
                 case 4: {
                     prodaje.IsprazniKolekciju(); 
                     cout<<"Sve prodaje obrisane."<<endl; 
                      throw std::runtime_error("e");
                     
                 }
             }
         }
         catch(std::runtime_error e){ cout<<endl; }
     }
 }

int UredjivanjeSvihProdaja(Prodaje &prodaje, std::vector<Stan>& stanovi, std::vector<Kupac>& kupci){
    std::vector<std::function<void(Prodaje&,std::vector<Stan>&,std::vector<Kupac>&)>> funkc{DodavanjeProdaje,UredjivanjeProdaja,IspisProdaja,BrisanjeProdaja};
    int br;
    try{
        while(true){
            cout<<"Izaberite opciju:\n 0 - nazad\n 1 - dodavanje prodaje\n 2 - uredjivanje prodaje\n 3 - ispis prodaja\n 4 - brisanje prodaja\n 5 - kraj"<<endl;
            cin>>br;
            if(br==0) return 1;
            if(br==5) return 0;
            funkc.at(br-1)(prodaje,stanovi,kupci);
            cout<<endl;
        }
    }
    catch(std::runtime_error e){
        return 0; //Kraj
    }
    return 1;
}

int main ()
{
    int br(0), rez(0);
    Prodaje prodaje(20);
    std::vector<Stan> stanovi;
    std::vector<Kupac> kupci;
    cout<<"Dobrodosli!"<<endl<<" "<<endl<<" "<<endl;
    while(true){
        cout<<"Izaberite opciju:\n 0 - kraj\n 1 - uredjivanje stanova\n 2 - uredjivanje kupaca\n 3 - uredjivanje prodaja"<<endl;
        cin>>br;
        if(br==0) break;
        else if(br==1) rez=UredjivanjeSvihStanova(stanovi);
        else if(br==2) rez = UredjivanjeSvihKupaca(kupci);
        else rez=UredjivanjeSvihProdaja(prodaje,stanovi,kupci);
        if(rez==0) break;
    }
    cout<<endl<<endl<<"Dovidjenja!";
	return 0;
}