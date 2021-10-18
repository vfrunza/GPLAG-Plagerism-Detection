/B 2016/2017, Zadaća 4, Zadatak 4
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <memory>
using namespace std;

class Datum{
    int dan, mjesec, godina;
    public:
    //Datum() { dan=mjesec=godina=0; }
    Datum(int dan, int mjesec, int godina) { Postavi(dan, mjesec, godina); }
    void Postavi(int dan, int mjesec, int godina){
        if(dan<0 || dan>31 || mjesec<1 || mjesec>12 || godina<1 || godina>2017) throw domain_error("Neispravan datum");
        Datum::dan=dan;
        Datum::mjesec=mjesec;
        Datum::godina=godina;
    }
    int DajDan() const { return dan; }
    int DajMjesec() const { return mjesec; }
    int DajGodinu() const { return godina; }
    void Ispisi() const { cout<<DajDan()<<"/"<<DajMjesec()<<"/"<<DajGodinu(); }
};

class Kupac{
    string ime_i_prezime;
    Datum datum;
    public:
    string s2;
    //Kupac() { ime_i_prezime=s2;}
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja) : datum(datum_rodjenja) { Postavi(ime_i_prezime, datum_rodjenja); }
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja){
        for(int i=0; i<ime_i_prezime.length(); i++){
            if(!((ime_i_prezime[i]>='a' && ime_i_prezime[i]<='z') ||
            (ime_i_prezime[i]>='A' && ime_i_prezime[i]<='Z') || ime_i_prezime[i]==' ' ||
            ime_i_prezime[i]=='-')) throw domain_error("Neispravno ime i prezime");
        }
        Kupac::ime_i_prezime=ime_i_prezime;
        datum=datum_rodjenja;
    }
    std::string DajImePrezime() const { return ime_i_prezime; }
    Datum DajDatumRodjenja() const { return datum; }
    void Ispisi() const { 
        cout<<DajImePrezime()<<" ("<<datum.DajDan()<<"/"<<
        datum.DajMjesec()<<"/"<<datum.DajGodinu()<<")";
    }
};
class Stan{
    string adresa;
    int sprat, broj_soba;
    bool namjesten;
    double kvadratura;
  public:
  Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten,double kvadratura){
      Postavi(adresa, sprat, broj_soba, namjesten, kvadratura);
  }
  void Postavi(const std::string &adresa, int sprat, int broj_soba,bool namjesten, double kvadratura){
      if(broj_soba<0 || sprat<0 || kvadratura<0) throw domain_error("Neispravan unos podataka");
      Stan::adresa=adresa;
      Stan::sprat=sprat;
      Stan::broj_soba=broj_soba;
      Stan::namjesten=namjesten;
      Stan::kvadratura=kvadratura;
  }
  std::string DajAdresu() const { return adresa; }
  int DajSprat() const { return sprat; }
  int DajBrojSoba() const { return broj_soba; }
  bool DajNamjesten() const { return namjesten; }
  double DajKvadraturu() const { return kvadratura; }
  void Ispisi() const {
      cout<<"Stan se nalazi na adresi "<<DajAdresu()<<" na spratu "<<DajSprat()<<
      " i ima ";
      if(broj_soba%10==1 && broj_soba!=11){
          cout<<DajBrojSoba()<<" sobu. ";
      }
      else if(broj_soba%10>=2 && broj_soba%10<=4){
          cout<<DajBrojSoba()<<" sobe. ";
      }
      else cout<<DajBrojSoba()<<" soba. ";
      cout<<"Kvadratura stana je "<<kvadratura<<" (m^2) i stan";
      if (namjesten==true) cout<<" je namjesten."<<endl;
      if(namjesten==false) cout<<" nije namjesten."<<endl;
  }

};
class Prodaja{
    string ime_agenta_prodaje;
    Kupac kupac_stana;
    Datum datum_prodaje;
    Stan kupljeni_stan;
    string ime_kupca;
    double cijena_stana;
    
    public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,
    const Datum &datum_prodaje, const Kupac &kupac_stana,const Stan &kupljeni_stan) : 
    kupac_stana(kupac_stana), datum_prodaje(datum_prodaje), kupljeni_stan(kupljeni_stan){
        Prodaja::ime_agenta_prodaje=ime_agenta_prodaje;
        Prodaja::cijena_stana=cijena_stana;
    }
    
    
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,int dan_prodaje, 
    int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca,
    const std::string &adresa_stana, int sprat_stana, int broj_soba,bool namjesten_stan, 
    double broj_kvadrata) :cijena_stana(cijena_stana), datum_prodaje(Datum(dan_prodaje, mjesec_prodaje, godina_prodaje)), 
    kupac_stana(Kupac(ime_kupca, datum_rodjenja_kupca)), 
    kupljeni_stan(Stan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata)){
        Prodaja::ime_agenta_prodaje=ime_agenta_prodaje;
        //Prodaja::cijena_stana=cijena_stana;
    }

    void PromijeniKupca(const Kupac &novi_kupac){
        kupac_stana=novi_kupac;
    }
    void PromijeniAgentaProdaje(const string &novo_ime_agenta_prodaje){
        ime_agenta_prodaje=novo_ime_agenta_prodaje;
    }
    void PromijeniStan(const Stan &novi_stan){
        kupljeni_stan=novi_stan;
    }
    void PromijeniDatumKupovine(const Datum &novi_datum){
        datum_prodaje=novi_datum;
    }
    void PromijeniCijenuProdaje(const double &nova_cijena){
        cijena_stana=nova_cijena;
    }
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImeAgenta() const { return ime_agenta_prodaje; }
    std::string DajImeKupca() const { return ime_kupca; }
    Datum DajDatumProdaje() const { return datum_prodaje; }
    double DajCijenuStana() const { return cijena_stana; }
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
    void Ispisi() const {
        cout<<"Ime agenta: "<<setw(7)<<DajImeAgenta()<<endl;
        cout<<"Ime kupca: "<<setw(7);
        kupac_stana.Ispisi();
        cout<<endl;
        cout<<"Zakazani datum prodaje: "<<setw(7);
        datum_prodaje.Ispisi();
        cout<<endl;
        cout<<"Cijena stana: "<<setw(7)<<DajCijenuStana()<<endl;
        cout<<"Informacije o stanu: "<<endl;
        kupljeni_stan.Ispisi();
        
    }

};

void Prodaja::PomjeriDanUnaprijed(){
    if(datum_prodaje.DajMjesec()==1 || datum_prodaje.DajMjesec()==3 || datum_prodaje.DajMjesec()==5
    || datum_prodaje.DajMjesec()==7 || datum_prodaje.DajMjesec()==8 || datum_prodaje.DajMjesec()==10 
    || datum_prodaje.DajMjesec()==12){
        if(datum_prodaje.DajDan()==31){
            datum_prodaje.Postavi(1,datum_prodaje.DajMjesec(), datum_prodaje.DajGodinu());
            if(datum_prodaje.DajMjesec()==12){
                datum_prodaje.Postavi(datum_prodaje.DajDan(), 1, datum_prodaje.DajGodinu()+1);
            }
            else datum_prodaje.Postavi(datum_prodaje.DajDan(),datum_prodaje.DajMjesec()+1, datum_prodaje.DajGodinu());
        }
        else datum_prodaje.Postavi(datum_prodaje.DajDan()+1, datum_prodaje.DajMjesec(), datum_prodaje.DajGodinu());
    }
    else if(datum_prodaje.DajMjesec()==4 || datum_prodaje.DajMjesec()==6 
            || datum_prodaje.DajMjesec()==9 || datum_prodaje.DajMjesec()==1){
        if(datum_prodaje.DajDan()==30){
            datum_prodaje.Postavi(1, datum_prodaje.DajMjesec()+1, datum_prodaje.DajGodinu());
        }
        else datum_prodaje.Postavi(datum_prodaje.DajDan()+1, datum_prodaje.DajMjesec(), datum_prodaje.DajGodinu());
    }
    else if(datum_prodaje.DajMjesec()==2){
        if((datum_prodaje.DajGodinu()%4==0 && datum_prodaje.DajGodinu()%100!=0) 
        || datum_prodaje.DajGodinu()%400==0){
            if(datum_prodaje.DajDan()==29){
                datum_prodaje.Postavi(1,datum_prodaje.DajMjesec()+1, datum_prodaje.DajGodinu());
            }
            else datum_prodaje.Postavi(datum_prodaje.DajDan()+1, datum_prodaje.DajMjesec(), datum_prodaje.DajGodinu());
        }
        else if(datum_prodaje.DajDan()==28){
            datum_prodaje.Postavi(1, datum_prodaje.DajMjesec()+1, datum_prodaje.DajGodinu());
        } 
        else datum_prodaje.Postavi(datum_prodaje.DajDan()+1, datum_prodaje.DajMjesec(), datum_prodaje.DajGodinu());
    }
}
void Prodaja::PomjeriDanUnazad(){
    if(datum_prodaje.DajMjesec()==12 || datum_prodaje.DajMjesec()==10 || datum_prodaje.DajMjesec()==7 || datum_prodaje.DajMjesec()==5){
        if(datum_prodaje.DajDan()==1){
            datum_prodaje.Postavi(30, datum_prodaje.DajMjesec()-1, datum_prodaje.DajGodinu());
        }
        else datum_prodaje.Postavi(datum_prodaje.DajDan()-1, datum_prodaje.DajMjesec(), datum_prodaje.DajGodinu());
    }
    else if(datum_prodaje.DajMjesec()==11 || datum_prodaje.DajMjesec()==9 || datum_prodaje.DajMjesec()==6 || datum_prodaje.DajMjesec()==4){
        if(datum_prodaje.DajDan()==1){
            datum_prodaje.Postavi(31, datum_prodaje.DajMjesec()-1, datum_prodaje.DajGodinu());
        }
        else datum_prodaje.Postavi(datum_prodaje.DajDan()-1, datum_prodaje.DajMjesec(), datum_prodaje.DajGodinu());
    }
    else if(datum_prodaje.DajMjesec()==1){
        if(datum_prodaje.DajDan()==1){
            datum_prodaje.Postavi(31, 12, datum_prodaje.DajGodinu()-1);
        }
        else datum_prodaje.Postavi(datum_prodaje.DajDan()-1, datum_prodaje.DajMjesec(), datum_prodaje.DajGodinu());
    }
    else if(datum_prodaje.DajMjesec()==3){
        if(datum_prodaje.DajDan()==1){
            datum_prodaje.Postavi(28, datum_prodaje.DajMjesec()-1, datum_prodaje.DajGodinu());
            if((datum_prodaje.DajGodinu()%4==0 && datum_prodaje.DajGodinu()%100!=0) || datum_prodaje.DajGodinu()%400==0)
                datum_prodaje.Postavi(29, datum_prodaje.DajMjesec()-1, datum_prodaje.DajGodinu());
        }
        else datum_prodaje.Postavi(datum_prodaje.DajDan()-1, datum_prodaje.DajMjesec(), datum_prodaje.DajGodinu());
    }
    else if(datum_prodaje.DajMjesec()==8){
        if(datum_prodaje.DajDan()==1){
            datum_prodaje.Postavi(31, datum_prodaje.DajMjesec()-1,datum_prodaje.DajGodinu());
        }
        else datum_prodaje.Postavi(datum_prodaje.DajDan()-1, datum_prodaje.DajMjesec(), datum_prodaje.DajGodinu());
    }
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


class Prodaje{
    vector<shared_ptr<Prodaja>>prodaje;
    static bool blah(shared_ptr<Prodaja>p1, shared_ptr<Prodaja>p2){ return ProdatPrije(*p1, *p2); }
    static bool fuj(shared_ptr<Prodaja>p1, shared_ptr<Prodaja>p2){ return SkupljiStan(*p1, *p2); }
    public:
    explicit Prodaje() { prodaje.resize(0);}
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
    Prodaje(const Prodaje &prodaje);
    Prodaje(Prodaje &&prodaje);
    Prodaje &operator =(const Prodaje &prodaje);
    Prodaje &operator =(Prodaje &&prodaje);
    
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje,
    double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,
    const Stan &kupljeni_stan){
        prodaje.push_back(make_shared<Prodaja>(ime_agenta_prodaje, cijena_stana, datum_prodaje, kupac_stana, kupljeni_stan));
    }
    
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje,
    int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
    const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,
    int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata){
        prodaje.push_back(make_shared<Prodaja>(ime_agenta_prodaje, cijena_stana, dan_prodaje, mjesec_prodaje, godina_prodaje,
        ime_kupca, datum_rodjenja_kupca, adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata));
        
    }
    
    void RegistrirajProdaju(shared_ptr<Prodaja> prodaja){
        prodaje.push_back(make_shared<Prodaja>(*prodaja));
    }
    int DajBrojProdaja() const{
        return prodaje.size();
    }
    int DajBrojProdajaNaDatum(const Datum &datum) const;
    int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const;
    Prodaja &DajProdaju(int redni_broj){ 
        if(redni_broj>prodaje.size()) throw domain_error("Lose");
        return *prodaje[redni_broj]; }
    Prodaja &DajNajranijuProdaju();
    Prodaja DajNajranijuProdaju() const;
    Prodaja &DajNajskupljuProdaju();
    Prodaja DajNajskupljuProdaju() const;
    void IsprazniKolekciju() { prodaje.resize(0); }
    void ObrisiNajranijuProdaju();
    void ObrisiProdajeAgenta(const std::string &ime_agenta); 
    void ObrisiProdajeNaDatum(const Datum &datum);
    void IspisiProdajeNaDatum(const Datum &datum) const;
    void IspisiSveProdaje() const;

};

Prodaje::Prodaje(initializer_list<Prodaja>spisak_prodaja){
    for(auto it=spisak_prodaja.begin(); it!=spisak_prodaja.end();it++){
        prodaje.push_back(make_shared<Prodaja>(*it));
    }
}
Prodaje::Prodaje(const Prodaje &prodaje){
    for(int i=0; i<prodaje.prodaje.size(); i++)
         this->prodaje.push_back(make_shared<Prodaja>(*prodaje.prodaje[i]));
}

Prodaje::Prodaje(Prodaje &&prodaje){
    this->prodaje=prodaje.prodaje;
    prodaje.prodaje.resize(0);
}

Prodaje &Prodaje::operator=(const Prodaje &prodaje){
    this->prodaje.resize(0);
    for(int i=0; i<prodaje.prodaje.size(); i++){
        this->prodaje.push_back(make_shared<Prodaja>(*prodaje.prodaje[i]));
    }
    return *this;
}

Prodaje &Prodaje::operator =(Prodaje &&prodaje){
    this->prodaje.resize(0);
    this->prodaje=prodaje.prodaje;
    prodaje.prodaje.resize(0);
    return *this;
}
int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const{
    return count_if(&prodaje[0], &prodaje[prodaje.size()], [this, &datum](shared_ptr<Prodaja> prodaja){
        if(prodaja->DajDatumProdaje().DajDan()==datum.DajDan() && 
        prodaja->DajDatumProdaje().DajMjesec()==datum.DajMjesec() &&
        prodaja->DajDatumProdaje().DajGodinu()==datum.DajGodinu()) return true;
        else return false;});
}
int Prodaje::DajBrojProdajaOdAgenta(const string &ime_agenta) const{
    return count_if(&prodaje[0], &prodaje[prodaje.size()], [this, &ime_agenta](shared_ptr<Prodaja> prodaja){
        if(prodaja->DajImeAgenta()==ime_agenta) return true;
        else return false;});
}

Prodaja &Prodaje::DajNajranijuProdaju(){
    //if(prodaje.size()==0)
    auto poranila(min_element(&prodaje[0], &prodaje[prodaje.size()], [](shared_ptr<Prodaja>p1, shared_ptr<Prodaja>p2){return blah(p1, p2);}));
    return **poranila;
        
}
Prodaja Prodaje::DajNajranijuProdaju() const{
    auto poranila(min_element(&prodaje[0], &prodaje[prodaje.size()], [](shared_ptr<Prodaja>p1, shared_ptr<Prodaja>p2){return blah(p1, p2);}));
    return **poranila;
}
Prodaja &Prodaje::DajNajskupljuProdaju() {
    auto ima_se_moze_se(max_element(&prodaje[0], &prodaje[prodaje.size()], [](shared_ptr<Prodaja>p1, shared_ptr<Prodaja>p2)
    {return fuj(p1, p2);}));
    return **ima_se_moze_se;
}

Prodaja Prodaje::DajNajskupljuProdaju() const{
     auto ima_se_moze_se(max_element(&prodaje[0], &prodaje[prodaje.size()], [](shared_ptr<Prodaja>p1, shared_ptr<Prodaja>p2)
    {return fuj(p1, p2);}));
    return **ima_se_moze_se;
}

void Prodaje::ObrisiNajranijuProdaju(){
    //if(trenutni_broj_prodaja==0) throw range_error("Prazna kolekcija");
    sort(&prodaje[0], &prodaje[prodaje.size()], blah);
    prodaje.erase(prodaje.begin());
}

void Prodaje::ObrisiProdajeAgenta(const string &ime_agenta){
    for(int i=0; i<prodaje.size(); i++){
        if(prodaje[i]->DajImeAgenta()==ime_agenta) { 
            prodaje.erase(prodaje.begin()+i);
            i--;
        }
    }
}
void Prodaje::ObrisiProdajeNaDatum(const Datum &datum){
    for(int i=0; i<prodaje.size(); i++){
        if(prodaje[i]->DajDatumProdaje().DajDan()==datum.DajDan() && 
        prodaje[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec() &&
        prodaje[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu()){
            prodaje.erase(prodaje.begin()+i);
            i--;
        }
    }
}
void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const{
    Prodaje heeelp;
    for(int i=0; i<prodaje.size(); i++){
        if(this->prodaje[i]->DajDatumProdaje().DajDan()==datum.DajDan() &&
        this->prodaje[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec() &&
        this->prodaje[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu()) heeelp.prodaje.push_back(make_shared<Prodaja>(*prodaje[i]));
    }
    sort(&heeelp.prodaje[0], &heeelp.prodaje[heeelp.prodaje.size()], blah);
    heeelp.IspisiSveProdaje();
}

void Prodaje::IspisiSveProdaje() const{
    Prodaje helpic;
    for(int i=0; i<prodaje.size(); i++){
        helpic.prodaje.push_back(make_shared<Prodaja>(*prodaje[i]));
    }
    sort(&helpic.prodaje[0], &helpic.prodaje[helpic.prodaje.size()], blah);
    for(int i=0; i<helpic.prodaje.size(); i++){
        helpic.prodaje[i]->Ispisi();
    }
}

int main ()
{
    Prodaje p;
    int opcija, korak_stan;
    vector<Stan>stanovi;
    vector<Kupac>kupci;
    
    cout<<"Dobrodosli!"<<endl<<endl<<endl;
    izlaz:
    cout<<"Izaberite opciju:"<<endl;
    cout<<" 0 - kraj"<<endl;
    cout<<" 1 - uredjivanje stanova"<<endl;
    cout<<" 2 - uredjivanje kupaca"<<endl;
    cout<<" 3 - uredjivanje prodaja"<<endl;
    cin>>opcija;
    
    switch(opcija){
        case 0 : {
            cout<<endl<<endl<<"Dovidjenja!"; return 0;
        }
        case 1:{
            izlaz1:
            cout<<"Izaberite opciju:\n 0 - nazad\n 1 - dodavanje stana\n 2 - uredjivanje stanova\n 3 - ispis svih stanova\n 4 - kraj"<<endl;
            cin>>korak_stan;
            switch(korak_stan){
                case 0: goto izlaz;
                case 1: {
                    podizlaz:
                    int brojac1=0;
                    cout<<"Unesite adresu: ";
                    brojac1++;
                    string adresa;
                    if(brojac1==1) cin.ignore(1000, '\n');
                    getline(cin, adresa);
                    cout<<"Unesite sprat: ";
                    try{
                    int sprat;
                    cin>>sprat;
                    cout<<"Unesite broj soba: ";
                    int broj_soba;
                    cin>>broj_soba;
                    cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                    bool namjesten;
                    int pomoc;
                    cin>>pomoc;
                    
                    cout<<"Unesite kvadraturu: ";
                    double kvadratura;
                    cin>>kvadratura;
                    if(pomoc==1 || pomoc==0) namjesten=pomoc;
                    else if(pomoc!=0 && pomoc!=1) throw domain_error("Neispravan unos podataka.");
                    Stan novi=Stan(adresa, sprat, broj_soba, namjesten, kvadratura);
                    stanovi.push_back(novi);
                    }
                    catch(domain_error izuzetak){
                        cout<<"Izuzetak: "<<izuzetak.what()<<". Molimo unesite opet."<<endl;
                        cin.ignore(10000,'\n');
                        goto podizlaz;
                    }
                    
                    cout<<"Stan je uspjesno dodan!"<<endl<<endl; goto izlaz1;
                }
                break;
                case 2:{
                    cout<<"Odaberite stan. Dostupni stanovi su:"<<endl;
                    for(int i=0; i<stanovi.size(); i++){
                        cout<<" "<<i+1<<" - ";
                        stanovi[i].Ispisi();
                    }
                    //cout<<endl;
                    int korak_stan_uredjivanje, uredjivanje_stana;
                    cin>>korak_stan_uredjivanje;
                    cout<<"Odaberite polje koje zelite uredti:\n 0 - nazad\n1 - adresa\n 2 - sprat\n 3 - broj soba\n 4 - da li je stan namjesten\n 5 - kvadratura\n 6 - sve"<<endl;
                    cin>>uredjivanje_stana;
                    switch(uredjivanje_stana){
                        case 0:  goto izlaz1;
                        case 1:{
                            cout<<"Unesite adresu: ";
                            string adresa2;
                            cin.ignore(10000, '\n');
                            getline(cin, adresa2);
                            stanovi[korak_stan_uredjivanje-1].Postavi(adresa2, stanovi[korak_stan_uredjivanje-1].DajSprat(), 
                            stanovi[korak_stan_uredjivanje-1].DajBrojSoba(), stanovi[korak_stan_uredjivanje-1].DajNamjesten(), 
                            stanovi[korak_stan_uredjivanje-1].DajKvadraturu());
                            cout<<"Stan je uspjesno izmijenjen!"<<endl<<endl; goto izlaz1;
                        }
                        case 2:{
                            podizlaz2:
                            cout<<"Unesite sprat: ";
                            int spratic;
                            try{
                                cin>>spratic;
                                stanovi[korak_stan_uredjivanje-1].Postavi(stanovi[korak_stan_uredjivanje-1].DajAdresu(), 
                                spratic, stanovi[korak_stan_uredjivanje-1].DajBrojSoba(), stanovi[korak_stan_uredjivanje-1].DajNamjesten(), 
                                stanovi[korak_stan_uredjivanje-1].DajKvadraturu());
                            }
                            catch(domain_error poruka){
                                cout<<"Izuzetak: "<<poruka.what()<<". Molimo unesite opet."<<endl;
                                goto podizlaz2;
                            }
                            cout<<"Stan je uspjesno izmijenjen!"<<endl<<endl; goto izlaz1;
                        }
                        case 3:{
                            podizlaz3:
                            cout<<"Unesite broj soba: ";
                            int brs;
                            try{
                                cin>>brs;
                                stanovi[korak_stan_uredjivanje-1].Postavi(stanovi[korak_stan_uredjivanje-1].DajAdresu(), 
                                stanovi[korak_stan_uredjivanje-1].DajSprat(), brs, stanovi[korak_stan_uredjivanje-1].DajNamjesten(),
                                stanovi[korak_stan_uredjivanje-1].DajKvadraturu());
                            }
                            catch(domain_error pp){
                                cout<<"Izuzetak: "<<pp.what()<<". Molimo unesite opet."<<endl;
                                goto podizlaz3;
                            }
                            cout<<"Stan je uspjesno izmijenjen!"<<endl<<endl; goto izlaz1;
                            
                        }
                        case 4:{
                            podizlaz4:
                            cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                            int je_li;
                            try{
                            cin>>je_li;
                            stanovi[korak_stan_uredjivanje-1].Postavi(stanovi[korak_stan_uredjivanje-1].DajAdresu(), 
                            stanovi[korak_stan_uredjivanje-1].DajSprat(), stanovi[korak_stan_uredjivanje-1].DajBrojSoba(), je_li, 
                            stanovi[korak_stan_uredjivanje-1].DajKvadraturu());
                            }
                            catch(domain_error p1){
                                cout<<"Izuzetak: "<<p1.what()<<". Molimo unesite opet."<<endl;
                                goto podizlaz4;
                            }
                            cout<<"Stan je uspjesno izmijenjen!"<<endl<<endl; goto izlaz1;
                        }
                        case 5:{
                            podizlaz5:
                            cout<<"Unesite kvadraturu: ";
                            double kvadratura1;
                            try{
                            cin>>kvadratura1;
                            stanovi[korak_stan_uredjivanje-1].Postavi(stanovi[korak_stan_uredjivanje-1].DajAdresu(), 
                            stanovi[korak_stan_uredjivanje-1].DajSprat(), stanovi[korak_stan_uredjivanje-1].DajBrojSoba(), 
                            stanovi[korak_stan_uredjivanje-1].DajNamjesten(), kvadratura1);
                            }
                            catch(domain_error p3){
                                cout<<"Izuzetak: "<<p3.what()<<". Molimo unesite opet."<<endl;
                                goto podizlaz5;  
                            }
                            cout<<"Stan je uspjesno izmijenjen!"<<endl<<endl; goto izlaz1;
                        }
                        case 6:{
                            podizlaz6:
                            cout<<"Unesite adresu: ";
                            string adr;
                            int sp, bs;
                            double kv;
                            bool nm;
                            int pompom;
                            cin.ignore(1000, '\n');
                            getline(cin, adr);
                            try{
                            cout<<"Unesite sprat: ";
                            cin>>sp;
                            cout<<"Unesite broj soba: ";
                            cin>>bs;
                            cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                            cin>>pompom;
                            cout<<"Unesite kvadraturu: ";
                            cin>>kv;
                            if(pompom==1 || pompom==0) nm=pompom;
                            else if(pompom!=0 && pompom!=1) throw domain_error("Neispravan unos podataka.");
                            stanovi[korak_stan_uredjivanje-1].Postavi(adr, sp, bs, nm, kv);
                            }
                            catch(domain_error p4){
                                cout<<"Izuzetak: "<<p4.what()<<". Molimo unesite opet."<<endl;
                                cin.ignore(10000, '\n');
                                goto podizlaz6;
                            }
                            cout<<"Stan je uspjesno izmijenjen!"<<endl<<endl; goto izlaz1;
                        }
                    }
                }
                case 3:{
                    for(int i=0; i<stanovi.size(); i++){
                        cout<<i+1<<". ";stanovi[i].Ispisi();
                    }
                    goto izlaz1;
                }
                case 4: cout<<endl<<endl<<"Dovidjenja!"; return 0;
            }
        }
        case 2:{
            izlaz3:
            cout<<"Izaberite opciju:\n 0 - nazad\n 1 - dodavanje kupca\n 2 - uredjivanje kupaca\n 3 - ispis svih kupaca\n 4 - kraj"<<endl;
            int opcija_za_kupce;
            cin>>opcija_za_kupce;
            switch(opcija_za_kupce){
                case 0: goto izlaz;
                case 1:{
                    int brojac=0;
                    podizlaz7:
                    cout<<"Unesite ime i prezime kupca: ";
                    string ime_i_prezime;
                    brojac++;
                    if(brojac==1) cin.ignore(10000, '\n');
                    getline(cin, ime_i_prezime);
                    cout<<"Unesite datum rodjenja (formata d/m/g): ";
                    try{
                    int dan, mjesec, godina;
                    cin>>dan;
                    cin.get();
                    cin>>mjesec;
                    cin.get();
                    cin>>godina;
                    cin.get();
                    Datum datum=Datum(dan, mjesec, godina);
                    try{
                    Kupac novi=Kupac(ime_i_prezime, datum);
                    kupci.push_back(novi);
                    }
                    catch(domain_error izuzetakxx){
                        cout<<"Izuzetak: "<<izuzetakxx.what()<< ". Molimo unesite opet."<<endl;
                        goto podizlaz7;
                    }
                    }
                    catch(domain_error p6){
                        cout<<"Izuzetak: "<<p6.what()<<". Molimo unesite opet."<<endl;
                        goto podizlaz7;
                    }
                    cout<<"Kupac je uspjesno dodan!"<<endl<<endl;
                    goto izlaz3;
                }
            case 2:{
                podizlaz8:
                cout<<"Odaberite kupca kojeg zelite urediti. Dostupni kupci su:"<<endl;
                for(int i=0; i<kupci.size(); i++){
                    cout<<" "<<i+1<<" - ";
                    kupci[i].Ispisi();
                }
                
                int korak_uredjivanja_kupca;
                cin>>korak_uredjivanja_kupca;
                string ime_i_prezime2;
                cout<<"Unesite ime i prezime kupca: ";
                cin.ignore(10000, '\n');
                getline(cin, ime_i_prezime2);
                cout<<"Unesite datum rodjenja (formata d/m/g): ";
                try{
                int dan1, mjesec1, godina1;
                cin>>dan1;
                cin.get();
                cin>>mjesec1;
                cin.get();
                cin>>godina1;
                cin.get();
                Datum datum1=Datum(dan1, mjesec1, godina1);
                kupci[korak_uredjivanja_kupca-1].Postavi(ime_i_prezime2, datum1);
                }
                catch(domain_error p7){
                    cout<<"Izuzetak: "<<p7.what()<<". Molimo unesite opet."<<endl;
                    goto podizlaz8;
                }
                cout<<"Kupac je uspjesno izmijenjen!"<<endl<<endl; goto izlaz3;
            }
            case 3:{
                for(int i=0; i<kupci.size(); i++){
                    kupci[i].Ispisi();
                }
                goto izlaz3;
            }
            case 4: cout<<endl<<endl<<"Dovidjenja"; return 0;
            }
        }
        case 3:{
            izlaz4:
            cout<<"Izaberite opciju:\n 0 - nazad\n 1 - dodavanje prodaje\n 2 - uredjivanje prodaje\n 3 - ispis prodaja\n 4 - brisanje prodaja\n 5 - kraj"<<endl;
            int prodaja;
            cin>>prodaja;
            switch(prodaja){
                case 0: goto izlaz;
                case 1: {
                    izlaz5:
                    cout<<"Izaberite opciju:\n 0 - nazad\n 1 - dodavanje potpuno nove prodaje\n 2 - dodavanje nove prodaje na osnovu arhive\n 3 - kraj"<<endl;
                    int dodavanje_prodaje;
                    cin>>dodavanje_prodaje;
                    switch(dodavanje_prodaje){
                        case 0: goto izlaz4;
                        case 1:{
                            podizlaz9:
                            
                            cout<<"Unesite ime i prezime agenta prodaje: ";
                            string ime_agenta_prodaje;
                            cin.ignore(10000, '\n');
                            getline(cin, ime_agenta_prodaje);
                            cout<<"Unesite datum prodaje (formata d/m/g): ";
                            int d,m,g;
                            
                            cin>>d;
                            cin.get();
                            cin>>m;
                            cin.get();
                            cin>>g;
                            cin.get();
                            Datum dpr=Datum(d,m,g);
                            double cijena;
                            cout<<"Unesite cijenu stana: ";
                            cin>>cijena;
                            cout<<"Unesite ime kupca: ";
                            string ik;
                            cin.ignore(10000, '\n');
                            getline(cin, ik);
                            cout<<"Unesite datum rodjenja kupca (formata d/m/g): ";
                            int dd, mm, gg;
                            cin>>dd;
                            cin.get();
                            cin>>mm;
                            cin.get();
                            cin>>gg;
                            cin.get();
                            cout<<"Unesite adresu: ";
                            string adresaa;
                            //cin.ignore(10000, '\n');
                            getline(cin, adresaa);
                            cout<<"Unesite sprat: ";
                            int spratt;
                            cin>>spratt;
                            cout<<"Unesite broj soba: ";
                            int brr;
                            cin>>brr;
                            cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                            bool nmj;
                            cin>>nmj;
                            cout<<"Unesite kvadraturu: ";
                            double kvd;
                            cin>>kvd;
                            try{
                            Datum datum2=Datum(dd,mm,gg);
                            Kupac kupac=Kupac(ik, datum2);
                            Stan stan=Stan(adresaa, spratt, brr, nmj, kvd);
                            Prodaja pr=Prodaja(ime_agenta_prodaje, cijena, dpr, kupac, stan);
                            p.RegistrirajProdaju(ime_agenta_prodaje, cijena, dpr, kupac, stan);
                            }
                            catch(domain_error izuzetak2){
                                cout<<"Izuzetak: "<<izuzetak2.what()<<". Molimo unesite opet."<<endl;
                                goto podizlaz9;
                            }
                            cout<<"Prodaja uspjesno dodana!"<<endl<<endl;
                            goto izlaz5;
                        }
                        case 2:{
                            podizlaz10:
                            cout<<"Unesite ime i prezime agenta prodaje: ";
                            string iip;
                            cin.ignore(10000, '\n');
                            getline(cin, iip);
                            cout<<"Unesite datum prodaje (formata d/m/g): ";
                            int d2, m2, g2;
                            try{
                            cin>>d2;
                            cin.get();
                            cin>>m2;
                            cin.get();
                            cin>>g2;
                            cin.get();
                            cout<<"Unesite cijenu stana: ";
                            double cijenaa;
                            try{
                                cin>>cijenaa;
                            }
                            catch(domain_error izuzetak3){
                                cout<<"Izuzetak: "<<izuzetak3.what()<<". Molimo unesite opet."<<endl;
                                goto podizlaz10;
                            }
                            cout<<"Odaberite kupca. Dostupni kupci su: ";
                            for(int i=0; i<kupci.size(); i++){
                                cout<<i+1<<" - ";
                                kupci[i].Ispisi();
                            }
                            int unesi_kupca;
                            cin>>unesi_kupca;
                            cout<<"Odaberite stan. Dostupni stanovi su: ";
                            for(int i=0; i<stanovi.size(); i++){
                                cout<<i+1<<" - ";
                                stanovi[i].Ispisi();
                            }
                            int de_stan;
                            cin>>de_stan;
                            Datum datum3=Datum(d2,m2,g2);
                            p.RegistrirajProdaju(iip, cijenaa, datum3, kupci[unesi_kupca-1],stanovi[de_stan-1]);
                            }
                            catch(domain_error izuzetak4){
                                cout<<"Izuzetak: "<<izuzetak4.what()<<". Molimo unesite opet."<<endl;
                                goto podizlaz10;
                            }
                            cout<<"Prodaja uspjesno dodana!"<<endl<<endl;
                            goto izlaz5;
                        }
                        case 3: cout<<endl<<endl<<"Dovidjenja!"; return 0;
                    }
                }
                case 2:{
                    cout<<"Odaberite prodaju koju zelite urediti. Dostupne prodaje su: "<<endl;
                    for(int i=0; i<p.DajBrojProdaja(); i++){
                        cout<<" "<<i<<endl;
                        p.DajProdaju(i).Ispisi();
                        //cout<<endl;
                    }
                    int odaberi_za_uredjivanje;
                    cin>>odaberi_za_uredjivanje;
                    cout<<"Izaberite opciju:\n 0 - nazad\n 1 - izmjena agenta\n 2 - izmjena datuma prodaje\n 3 - izmjena kupca\n 4 - izmjena stana\n 5 - izmjena cijene stana:"<<endl;
                    int sta_da_izmijenis;
                    cin>>sta_da_izmijenis;
                    switch(sta_da_izmijenis){
                        case 0: goto izlaz4;
                        case 1:{
                            podizlaz20:
                            cout<<"Unesite ime i prezime agenta prodaje: ";
                            string s2;
                            cin.ignore(10000, '\n');
                            getline(cin, s2);
                            try{
                            //for(int i=0; i<p.DajBrojProdaja(); i++){
                            p.DajProdaju(odaberi_za_uredjivanje-1).PromijeniAgentaProdaje(s2);
                            //}
                            }
                            catch(domain_error nnn){
                                cout<<"Izuzetak: "<<nnn.what()<<". Molimo unesite opet."<<endl;
                                goto podizlaz20;
                            }
                            cout<<"Prodaja je uspjesno izmijenjena!"<<endl<<endl;
                            goto izlaz4;
                        }
                        case 2:{
                            podizlaz11:
                            cout<<"Unesite datum prodaje (formata d/m/g): ";
                            int dann, mjesecc, godinna;
                            try{
                            cin>>dann;
                            cin.get();
                            cin>>mjesecc;
                            cin.get();
                            cin>>godinna;
                            cin.get();
                            Datum novii=Datum(dann, mjesecc, godinna);
                            //for(int i=0; i<p.DajBrojProdaja(); i++){
                            p.DajProdaju(odaberi_za_uredjivanje-1).PromijeniDatumKupovine(novii);
                            }
                            //}
                            catch(domain_error izuzetak5){
                                cout<<"Izuzetak: "<<izuzetak5.what()<<". Molimo unesite opet."<<endl; goto podizlaz11;
                            }
                            cout<<"Prodaja je uspjesno izmijenjena!"<<endl<<endl;
                            goto izlaz4;
                        }
                        case 3: {
                            cout<<"Izaberite opciju:\n 0 - nazad\n 1 - Odabir postojeceg kupca\n 2 - dodavanje novog kupca:\n";
                            int izmjena_kupca;
                            cin>>izmjena_kupca;
                            switch(izmjena_kupca){
                                case 0: goto izlaz4;
                                case 1:{
                                    cout<<"Odaberite kupca. Dostupni kupci su:";
                                    for(int i=1; i<=kupci.size(); i++){
                                        cout<<" "<<i<<" - ";
                                        kupci[i].Ispisi();
                                        //cout<<endl;
                                    }
                                    int de_kupca_za_izmjenu;
                                    cin>>de_kupca_za_izmjenu;
                                    p.DajProdaju(odaberi_za_uredjivanje).PromijeniKupca(kupci[de_kupca_za_izmjenu]);
                                    cout<<"Prodaja uspjesno izmijenjena!"<<endl<<endl; goto izlaz4;
                                }
                                case 2:{
                                    podizlaz12:
                                    cout<<"Unesite ime i prezime kupca: ";
                                    string de_iip;
                                    getline(cin, de_iip);
                                    cout<<"Unesite datum rodjenja (formata dan/mjesec/godina): ";
                                    int dannn, mjeseccc, godinaaa;
                                    try{
                                    cin>>dannn;
                                    cin.get();
                                    cin>>mjeseccc;
                                    cin.get();
                                    cin>>godinaaa;
                                    cin.get();
                                    Datum datumcic=Datum(dannn, mjeseccc, godinaaa);
                                    Kupac neue=Kupac(de_iip, datumcic);
                                    kupci.emplace_back(neue);
                                    p.DajProdaju(odaberi_za_uredjivanje).PromijeniKupca(neue);
                                    }
                                    catch(domain_error izuzetak6){
                                        cout<<"Izuzetak: "<<izuzetak6.what()<<". Molimo unesite opet."<<endl;
                                        goto podizlaz12;
                                    }
                                    cout<<"Prodaja uspjesno izmijenjena!"<<endl<<endl; goto izlaz4;
                                }
                            }
                        }
                        case 4:{
                            cout<<"Izaberite opciju:\n 0 - nazad\n 1 - odabir postojeceg stana\n 2 - dodavanje novog stana"<<endl;
                            int x_opcija;
                            cin>>x_opcija;
                            switch(x_opcija){
                                case 0: goto izlaz4;
                                case 1:{
                                    cout<<"Odaberite stan. Dostupni stanovi su:"<<endl;
                                    for(int i=1; i<=stanovi.size(); i++){
                                        cout<<" "<<i<<" - ";
                                        stanovi[i].Ispisi();
                                        //cout<<endl;
                                    }
                                    int odaberi_stan;
                                    cin>>odaberi_stan;
                                    p.DajProdaju(odaberi_za_uredjivanje).PromijeniStan(stanovi[odaberi_stan]);
                                    goto izlaz4;
                                }
                                case 2:{
                                    podizlaz13:
                                    cout<<"Unesite adresu: ";
                                    string unesite_adresu;
                                    getline(cin, unesite_adresu);
                                    cout<<"Unesite sprat: ";
                                    int unesite_sprat;
                                    try{
                                    cin>>unesite_sprat;
                                    cout<<"Unesite broj soba: ";
                                    int ubr;
                                    cin>>ubr;
                                    cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                                    bool jel_nmj;
                                    int stajaznam;
                                    cin>>stajaznam;
                                    cout<<"Unesite kvadraturu: ";
                                    int de_kvadr;
                                    cin>>de_kvadr;
                                    if(stajaznam==1 || stajaznam==0) jel_nmj=stajaznam;
                                    else if(stajaznam!=0 && stajaznam!=1) throw domain_error("Neispravan unos podataka.");
                                    Stan fuj=Stan(unesite_adresu,unesite_sprat,ubr, jel_nmj, de_kvadr);
                                    stanovi.emplace_back(fuj);
                                    p.DajProdaju(odaberi_za_uredjivanje).PromijeniStan(fuj);
                                    }
                                    catch(domain_error izuzetak7){
                                        cout<<"Izuzetak: "<<izuzetak7.what()<<". Molimo unesite opet."<<endl;
                                        goto podizlaz13;
                                    }
                                    cout<<"Prodaja uspjesno izmijenjena!"<<endl<<endl;
                                    goto izlaz4;
                                }
                            }
                        }
                        case 5:{
                            cout<<"Unesite cijenu stana: ";
                            int unc;
                            cin>>unc;
                            p.DajProdaju(odaberi_za_uredjivanje).PromijeniCijenuProdaje(unc);
                            goto izlaz4;
                        }
                    }
                }
                case 3:{
                    izlaz6:
                    cout<<"Izaberite opciju:\n 0 - nazad\n 1 - ispis svih prodaja\n 2 - ispis prodaja na datum\n 3 - ispis najranije prodaje\n 4 - ispis najskuplje prodaje\n 5 - ispis broja prodaja\n 6 - ispis broja prodaja po datumu\n 7 - ispis broja prodaja po agentu\n 8 - kraj"<<endl;
                    int opcija_za_ispis;
                    switch(opcija_za_ispis){
                        case 0: goto izlaz4;
                        case 1:{
                            for(int i=0; i<p.DajBrojProdaja(); i++){
                                p.IspisiSveProdaje();
                                cout<<endl;
                            }
                        goto izlaz6;
                        }
                        case 2:{
                            cout<<"Unesite datum: ";
                            //try{
                            int di, mi, gi;
                            cin>>di;
                            cin.get();
                            cin>>mi;
                            cin.get();
                            cin>>gi;
                            cin.get();
                            Datum dii=Datum(di, mi, gi);
                            cout<<"Ispis prodaje na datum ";
                            dii.Ispisi();
                            cout<<"su: "<<endl;
                            p.IspisiProdajeNaDatum(dii);
                            goto izlaz6;
                        }
                        case 3:{
                            p.DajNajranijuProdaju().Ispisi();
                            //p.Ispisi();
                            goto izlaz6;
                        }
                        case 4:{
                            p.DajNajskupljuProdaju().Ispisi();
                            goto izlaz6;
                        }
                        case 5:{
                            podizlaz19:
                            try{
                            int a=p.DajBrojProdaja();
                            cout<<"Broj prodaja: "<<a<<endl;
                            goto izlaz6;
                            }
                            catch(domain_error izi){
                                cout<<"Izuzetak: "<<izi.what()<<endl;
                                goto podizlaz19;
                            }
                        }
                        case 6:{
                            podizlaz18:
                            try{
                            cout<<"Unesite datum: ";
                            int d3, m3, g3;
                            cin>>d3;
                            cin>>m3;
                            cin.get();
                            cin>>g3;
                            cin.get();
                            Datum dd3=Datum(d3, m3, g3);
                            try{
                            int b=p.DajBrojProdajaNaDatum(dd3);
                            cout<<"Broj prodaja na uneseni datum: "<<b<<endl;
                            goto izlaz6;
                            }
                            catch(range_error joj){
                                cout<<"Izuzetak: "<<joj.what()<<endl;
                                goto podizlaz18;
                            }
                        }
                        catch(domain_error ma){
                            cout<<"Izuzetak: "<<ma.what()<<endl;
                            cin.ignore(10000, '\n');
                            goto podizlaz18;
                        }
                        case 7:{
                            podizlaz17:
                            cout<<"Unesite ime agenta: ";
                            string s3;
                            cin.ignore(1000, '\n');
                            getline(cin, s3);
                            try{
                            int c=p.DajBrojProdajaOdAgenta(s3);
                            cout<<"Broj prodaja: "<<c<<endl;
                            goto izlaz6;
                            }
                            catch(domain_error evo_ne_znam){
                                cout<<"Izuzetak: "<<evo_ne_znam.what()<<endl; goto podizlaz17;
                            }
                        }
                        case 8: cout<<endl<<endl<<"Dovidjenja!"; return 0;
                    }
                }
                case 4:{
                    izlaz7:
                    cout<<"Izaberite opciju:\n 0 - nazad\n 1 - brisanje najranije prodaje\n 2 - brisanje prodaje agenta\n 3 - brisanje prodaje po datumu\n 4 - brisanje svih prodaja\n";
                    int opcija_za_brisanje;
                    cin>>opcija_za_brisanje;
                    switch(opcija_za_brisanje){
                        case 0: goto izlaz4;
                        case 1:{
                            podizlaz16:
                            try{
                            p.ObrisiNajranijuProdaju();
                            cout<<"Najranija prodaja je obrisana!"; goto izlaz7;
                            }
                            catch(range_error nece){
                                cout<<"Izuzetak: "<<nece.what()<<endl; goto podizlaz16;
                            }
                        }
                        case 2:{
                            podizlaz21:
                            cout<<"Unesite ime agenta: ";
                            string agent;
                            cin.ignore(10000, '\n');
                            getline(cin, agent);
                            try{
                            p.ObrisiProdajeAgenta(agent);
                            }
                            catch(domain_error nmv){
                                cout<<"Izuzetak: "<<nmv.what()<<". Molimo unesite opet."<<endl;
                                goto podizlaz21;
                            }
                            cout<<"Sve prodaje tog agenta su obrisane."<<endl; goto izlaz7;
                            
                        }
                        case 3:{
                            podizlaz14:
                            try{
                            cout<<"Unesite datum: ";
                            int d5, m5, g5;
                            cin>>d5;
                            cin.get();
                            cin>>m5;
                            cin.get();
                            cin>>g5;
                            cin.get();
                            Datum dd5=Datum(d5,m5,g5);
                            try{
                            p.ObrisiProdajeNaDatum(dd5); goto izlaz7;
                            cout<<"Sve prodaje na taj datum su obrisane."<<endl;
                            }
                            catch(range_error nada){
                                cout<<"Izuzetak: "<<nada.what()<<endl;
                                goto podizlaz14;
                            }
                        }
                        catch(domain_error datum){
                            cout<<"Izuzetak: "<<datum.what()<<endl;
                            cin.ignore(10000, '\n');
                            goto podizlaz14;
                        }
                        case 4:{
                            podizlaz15:
                            try{
                            p.IsprazniKolekciju();
                            cout<<"Sve prodaje su obrisane."<<endl; goto izlaz7;
                            }
                            catch(range_error nula){
                                cout<<"Izuzetak: "<<nula.what()<<endl;
                                goto podizlaz15;
                            }
                        }
                        }
                    }
                }
                }
            }
        }
    }
    

	return 0;
}