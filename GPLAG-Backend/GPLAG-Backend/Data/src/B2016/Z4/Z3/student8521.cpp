/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <string>
#include <iomanip>
#include <new>
#include <initializer_list>
#include <algorithm>
#include <vector>

using namespace std;

class Datum {
    mutable int d,m,g;
    public:
    static int BrojDana(int mjesec,int godina);
    Datum (int dan,int mjesec,int godina){Postavi(dan,mjesec,godina);}
    void Postavi(int dan,int mjesec,int godina);
    int DajDan() const{return d;}
    int DajMjesec() const{return m;}
    int DajGodinu() const{return g;}
    void Ispisi() const{cout<<d<<"/"<<m<<"/"<<g;}
    static bool VratiManjiDatum(const Datum &d1,const Datum &d2);
};
int Datum::BrojDana(int mjesec,int godina){
    int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
    if (godina%400==0 && (godina%100!=0 || godina%400==0))broj_dana[1]++;
    return broj_dana[mjesec-1];
}
 void Datum::Postavi(int dan,int mjesec,int godina){
     if(godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>BrojDana(mjesec,godina))throw domain_error("Neispravan datum");
     d=dan;m=mjesec;g=godina;
 }
bool Datum::VratiManjiDatum(const Datum &d1,const Datum &d2){
   if(d1.DajGodinu()<d2.DajGodinu())return true;
   if(d1.DajGodinu()==d2.DajGodinu() && d1.DajMjesec()<d2.DajMjesec())return true;
   if(d1.DajGodinu()==d2.DajGodinu() && d1.DajMjesec()==d2.DajMjesec() && d1.DajDan()<d2.DajDan())return true;
   return false;
    
}

class Kupac {
    string ime_i_pr;
    Datum datum_r;
    bool Ispravnost(const char c);
    public:
    Kupac(const string &ime_i_prezime, const Datum &datum_rodjenja):datum_r(datum_rodjenja.DajDan(),datum_rodjenja.DajMjesec(),datum_rodjenja.DajGodinu()){
        for(int i=0;i<ime_i_prezime.size();i++){
            if(!Ispravnost(ime_i_prezime[i]))throw domain_error("Neispravno ime i prezime");
        }
        ime_i_pr=ime_i_prezime;
    }
    void Postavi(const string &ime_i_prezime, const Datum &datum_rodjenja);
    string DajImePrezime() const{return ime_i_pr;}
    Datum DajDatumRodjenja() const{return datum_r;}
    void Ispisi() const{ cout<<ime_i_pr<<" (";datum_r.Ispisi();cout<<")";}
};
bool Kupac::Ispravnost(const char c){
    if((c>='a'&& c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9') || c=='-' || c==' ' || c==39)return true;
    return false;
}

void Kupac::Postavi(const string &ime_i_prezime,const Datum &datum_rodjenja){
    for(int i=0;i<ime_i_prezime.size();i++){
        if(!Ispravnost(ime_i_prezime[i]))throw domain_error("Neispravno ime i prezime");
    }
    ime_i_pr=ime_i_prezime;
    datum_r=datum_rodjenja;
}
class Stan {
    string ad;
    int s,br_s;
    bool nam;
    double kv;
    static char DajZadnjeSlovo(int broj);
    public:
    Stan(const string &adresa,int sprat, int broj_soba,bool namjesten,double kvadratura){
        if(sprat<=0 || broj_soba<=0 || kvadratura<=0)throw domain_error("Neispravan unos podataka");
        ad=adresa;s=sprat;br_s=broj_soba;nam=namjesten;kv=kvadratura;
        }
    void Postavi(const string &adresa,int sprat,int broj_soba,bool namjesten,double kvadratura){
        if(sprat<=0 || broj_soba<=0 || kvadratura<=0 )throw domain_error("Neispravan unos podataka");
        ad=adresa;s=sprat;br_s=broj_soba;nam=namjesten;kv=kvadratura;
    }
    string DajAdresu() const {return ad;}
    int DajSprat() const {return s;}
    int DajBrojSoba() const {return br_s;}
    bool DajNamjesten() const {return nam;}
    double DajKvadraturu() const {return kv;}
    void Ispisi() const{cout<<"Stan se nalazi na adresi "<<ad<<" na "<<s<<". spratu i ima "<<br_s<<" sob"<<DajZadnjeSlovo(br_s)<<". Kvadratura stana je "<<kv<<" (m^2) i stan ";
        if(nam)cout<<"je namjesten.";
        else cout<<"nije namjesten.";
    }
};
char Stan::DajZadnjeSlovo(int broj){
    char c;
    if(broj==1){c='u';return c;}
    int zadnja_cifra=broj%10;
    if(zadnja_cifra==2 || zadnja_cifra==3 || zadnja_cifra==4){c='e';return c;}
    c='a';return c;
}
class Prodaja {
    string ime_ag;
    double cijena_st;
    Datum datum_p;
    Kupac kupac_st;
    Stan kupljeni_st;
    bool Ispravno_ime(const char c);
    public:
    Prodaja(const string &ime_agenta_prodaje, double cijena_stana,const Datum &datum_prodaje, const Kupac &kupac_stana,const Stan &kupljeni_stan):datum_p(datum_prodaje.DajDan(),datum_prodaje.DajMjesec(),datum_prodaje.DajGodinu()),kupac_st(kupac_stana.DajImePrezime(),kupac_stana.DajDatumRodjenja()),kupljeni_st(kupljeni_stan.DajAdresu(),kupljeni_stan.DajSprat(),kupljeni_stan.DajBrojSoba(),kupljeni_stan.DajNamjesten(),kupljeni_stan.DajKvadraturu()){
        /*for(int i=0;i<ime_agenta_prodaje.size();i++){
        if(!Ispravno_ime(ime_agenta_prodaje[i]))throw domain_error ("Neispravan unos podataka. Molimo unesite opet.");
        }*/
        
        ime_ag=ime_agenta_prodaje;cijena_st=cijena_stana;
        
    }
    Prodaja(const string &ime_agenta_prodaje, double cijena_stana,int dan_prodaje, int mjesec_prodaje, int godina_prodaje,string &ime_kupca, const Datum &datum_rodjenja_kupca,const string &adresa_stana, int sprat_stana, int broj_soba,bool namjesten_stan, double broj_kvadrata);
    void PromijeniAgenta(const string &novo_ime){ime_ag=novo_ime;}
    void PromijeniKupca(const Kupac &novi_kupac){kupac_st.Postavi(novi_kupac.DajImePrezime(),novi_kupac.DajDatumRodjenja());}
    void PromijeniStan(const Stan &novi_stan){kupljeni_st.Postavi(novi_stan.DajAdresu(),novi_stan.DajSprat(),novi_stan.DajBrojSoba(),novi_stan.DajNamjesten(),novi_stan.DajKvadraturu());}
    void PromijeniDatumKupovine(const Datum &novi_datum){datum_p.Postavi(novi_datum.DajDan(),novi_datum.DajMjesec(),novi_datum.DajGodinu());}
    void PromijeniCijenuProdaje(const double &nova_cijena){cijena_st=nova_cijena;}
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    string DajImeAgenta() const {return ime_ag;}
    string DajImeKupca() const {return kupac_st.DajImePrezime();}
    Datum DajDatumProdaje() const {return datum_p;}
    double DajCijenuStana() const {return cijena_st;}
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
    void Ispisi() const;
};
bool Prodaja::Ispravno_ime(const char c){
    if((c>='a'&& c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9') || c=='-' || c==' ' || c==39)return true;
    return false;
}
inline Prodaja:: Prodaja(const string &ime_agenta_prodaje, double cijena_stana,int dan_prodaje, int mjesec_prodaje, int godina_prodaje,string &ime_kupca, const Datum &datum_rodjenja_kupca,const string &adresa_stana, int sprat_stana, int broj_soba,bool namjesten_stan, double broj_kvadrata):datum_p(dan_prodaje,mjesec_prodaje,godina_prodaje),kupac_st(ime_kupca,datum_rodjenja_kupca),kupljeni_st(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata){
    ime_ag=ime_agenta_prodaje;
    cijena_st=cijena_stana;
    }
void Prodaja::PomjeriDanUnaprijed(){
    int dan(datum_p.DajDan()),mj(datum_p.DajMjesec()),god(datum_p.DajGodinu());
    dan++;
    if(dan>Datum::BrojDana(datum_p.DajMjesec(),datum_p.DajGodinu())){dan=1;mj++;}
    if(mj>12){mj=1;god++;}
    datum_p.Postavi(dan,mj,god);
}
void Prodaja::PomjeriDanUnazad(){
    int dan(datum_p.DajDan()),mj(datum_p.DajMjesec()),god(datum_p.DajGodinu());
    dan--;
    if(dan<1){dan=Datum::BrojDana(datum_p.DajMjesec()+1,datum_p.DajGodinu());mj--;}
    if(mj<1){mj=12;god--;}
    datum_p.Postavi(dan,mj,god);
}
void Prodaja::Ispisi() const{
    cout<<left<<setw(30)<<"Ime agenta: "<<right<<ime_ag<<endl;
    cout<<left<<setw(30)<<"Ime kupca: "<<right;kupac_st.Ispisi();cout<<endl;
    cout<<left<<setw(30)<<"Zakazani datum prodaje: "<<right;datum_p.Ispisi();cout<<endl;
    cout<<left<<setw(30)<<"Cijena stana: "<<right<<cijena_st<<endl;
    cout<<"Informacije o stanu: "<<endl;
    kupljeni_st.Ispisi();
    }
bool ProdatPrije(const Prodaja &p1,const Prodaja &p2){
    if(p1.datum_p.DajGodinu()<p2.datum_p.DajGodinu())return true;
    if((p1.datum_p.DajGodinu()==p2.datum_p.DajGodinu()) && (p1.datum_p.DajMjesec()<p2.datum_p.DajMjesec()))return true;
    if((p1.datum_p.DajGodinu()==p2.datum_p.DajGodinu()) && (p1.datum_p.DajMjesec()==p2.datum_p.DajMjesec()) && (p1.datum_p.DajDan()<p2.datum_p.DajDan()))return true;
    return false;
}
bool SkupljiStan(const Prodaja &p1,const Prodaja &p2){
    if(p1.cijena_st>p2.cijena_st)return true;
    return false;
}
class Prodaje {
    const int max_pr;
    int broj_pr;
    Prodaja **prod;
    public:
    explicit Prodaje(int max_broj_prodaja):max_pr(max_broj_prodaja),broj_pr(0),prod(new Prodaja*[max_broj_prodaja]{}){}
    Prodaje(initializer_list<Prodaja> spisak_prodaja);
    ~Prodaje();
    Prodaje(const Prodaje &prodaje);
    Prodaje(Prodaje &&prodaje);
    Prodaje &operator =(const Prodaje &prodaje);
    Prodaje &operator = (Prodaje &&prodaje);
    void RegistrirajProdaju(const string &ime_agenta_prodaje,double cijena_stana,const Datum &datum_prodaje,const Kupac &kupac_stana,const Stan &kupljeni_stan);
    void RegistrirajProdaju(const string &ime_agenta_prodaje,double cijena_stana,int dan_prodaje,int mjesec_prodaje,int godina_prodaje, string &ime_kupca,const Datum &datum_rodjenja_kupca,const string &adresa_stana,int sprat_stana,int broj_soba,bool namjesten_stan,double broj_kvadrata);
    void RegistrirajProdaju(Prodaja *prodaja);
    int DajBrojProdaja() const{return broj_pr;}
    int DajBrojProdajaNaDatum(const Datum &datum)const;
    int DajBrojProdajaOdAgenta(const string &ime_agenta)const;
    Prodaja &DajNajranijuProdaju();
    Prodaja DajNajranijuProdaju() const;
    Prodaja &DajNajskupljuProdaju();
    Prodaja DajNajskupljuProdaju() const;
    void IsprazniKolekciju();
    void ObrisiNajranijuProdaju();
    void ObrisiProdajeAgenta(const string &ime_agenta);
    void ObrisiProdajeNaDatum(const Datum &datum);
    void IspisiProdajeNaDatum(const Datum &datum) const;
    void IspisiSveProdaje() const;
    Prodaja &DajProdaju(int broj_prodaje);
};
Prodaja &Prodaje::DajProdaju(int broj_prodaje){
    if(broj_prodaje<0 || broj_prodaje>=broj_pr)throw domain_error("Neispravan indeks");
    return *prod[broj_prodaje];
}
Prodaje::Prodaje(initializer_list<Prodaja> spisak_prodaja):max_pr(spisak_prodaja.size()),broj_pr(spisak_prodaja.size()),prod(new Prodaja*[spisak_prodaja.size()]){
    int i=0;
    for(initializer_list<Prodaja>::iterator it=spisak_prodaja.begin();it!=spisak_prodaja.end();it++)
    *prod[i++]=*it;
}
Prodaje::~Prodaje() {
    for(int i=0;i<broj_pr;i++)delete prod[i];
    delete[] prod;
}
Prodaje::Prodaje(const Prodaje &prodaje):max_pr(prodaje.max_pr),broj_pr(prodaje.broj_pr),prod(new Prodaja*[prodaje.max_pr]{}){
    try {
        for(int i=0;i<prodaje.broj_pr;i++){
            prod[i]=new Prodaja(*prodaje.prod[i]);
        }
    }
    catch(...){
            for(int i=0;i<prodaje.broj_pr;i++)delete prod[i];
            delete[] prod;throw;
        }
}
Prodaje::Prodaje(Prodaje &&prodaje):max_pr(prodaje.max_pr),broj_pr(prodaje.broj_pr),prod(prodaje.prod){
    prodaje.prod=nullptr;prodaje.broj_pr=0;
}
Prodaje &Prodaje::operator =(const Prodaje &prodaje){
   if(prodaje.max_pr!=max_pr)throw domain_error("Nesaglasni kapaciteti");
   if(prodaje.broj_pr>broj_pr){
       try {
           for(int i=0;i<broj_pr;i++)prod[i]=new Prodaja(*prodaje.prod[i]);
       }
       catch(...){
           for(int i=0;i<broj_pr;i++){
               delete prod[i];prod[i]=nullptr;
           }
           throw;
       }
   }
   else {
       for(int i=prodaje.broj_pr;i<broj_pr;i++){
           delete prod[i];prod[i]=nullptr;
       }
   }
   broj_pr=prodaje.broj_pr;
   for(int i=0;i<broj_pr;i++)*prod[i] = *prodaje.prod[i];
       
   return *this;
}
Prodaje &Prodaje::operator =(Prodaje &&prodaje){
    if(prodaje.max_pr!=max_pr)throw domain_error("Nesaglasni kapaciteti");
    swap(broj_pr,prodaje.broj_pr);
    swap(prod,prodaje.prod);
    return *this;
}
void Prodaje::RegistrirajProdaju(Prodaja *prodaja){
    if(broj_pr>=max_pr)throw range_error("Dostignut maksimalni broj prodaja");
    prod[broj_pr++]=prodaja;
}
void Prodaje::RegistrirajProdaju(const string &ime_agenta_prodaje,double cijena_stana,const Datum &datum_prodaje,const Kupac &kupac_stana,const Stan &kupljeni_stan){
    if(broj_pr>=max_pr)throw range_error("Dostignut maksimalni broj prodaja");
    prod[broj_pr++]=new Prodaja(ime_agenta_prodaje,cijena_stana,datum_prodaje,kupac_stana,kupljeni_stan);
}
void Prodaje::RegistrirajProdaju(const string &ime_agenta_prodaje,double cijena_stana,int dan_prodaje,int mjesec_prodaje,int godina_prodaje,string &ime_kupca,const Datum &datum_rodjenja_kupca,const string &adresa_stana,int sprat_stana,int broj_soba,bool namjesten_stan,double broj_kvadrata){
    if(broj_pr>=max_pr)throw range_error("Dostignut maksimalni broj prodaja");
    prod[broj_pr++]=new Prodaja(ime_agenta_prodaje,cijena_stana,dan_prodaje,mjesec_prodaje,godina_prodaje,ime_kupca,datum_rodjenja_kupca,adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata);
}
int Prodaje::DajBrojProdajaNaDatum(const Datum &datum)const{
    int brojac(0);
    brojac=count_if(prod,prod+broj_pr,[&datum,&brojac](Prodaja *p){
        if(p->DajDatumProdaje().DajDan()==datum.DajDan() && p->DajDatumProdaje().DajMjesec()==datum.DajMjesec() && p->DajDatumProdaje().DajGodinu()==datum.DajGodinu())return true;
        return false;
    });
    return brojac;
}
int Prodaje::DajBrojProdajaOdAgenta(const string& ime_agenta)const {
    int brojac(0);
    brojac=count_if(prod,prod+broj_pr,[ime_agenta](Prodaja *p){
        if(p->DajImeAgenta()==ime_agenta)return true;
        return false;
    });
    return brojac;
}
Prodaja &Prodaje::DajNajranijuProdaju(){
    if(broj_pr==0)throw domain_error("Nema registriranih prodaja");
    auto p=min_element(prod,prod+broj_pr,[](Prodaja *p1,Prodaja *p2){
       return Datum::VratiManjiDatum(p1->DajDatumProdaje(),p2->DajDatumProdaje());
    });
    return **p;
}
Prodaja Prodaje::DajNajranijuProdaju()const{
    if(broj_pr==0)throw domain_error("Nema registriranih prodaja");
    auto p=min_element(prod,prod+broj_pr,[](Prodaja *p1,Prodaja *p2){
    return Datum::VratiManjiDatum(p1->DajDatumProdaje(),p2->DajDatumProdaje());
    });
    return **p;
}
Prodaja &Prodaje::DajNajskupljuProdaju(){
    if(broj_pr==0)throw domain_error("Nema registriranih prodaja");
    auto p=max_element(prod,prod+broj_pr,[](Prodaja *p1,Prodaja *p2){
        return p1->DajCijenuStana()>p2->DajCijenuStana();
    });
    return **p;
}
Prodaja Prodaje::DajNajskupljuProdaju()const{
    if(broj_pr==0)throw domain_error("Nema registriranih prodaja");
    auto p=max_element(prod,prod+broj_pr,[](Prodaja *p1,Prodaja *p2){
        return p1->DajCijenuStana()>p2->DajCijenuStana();
    });
    return **p;
}
void Prodaje::IsprazniKolekciju(){
    for(int i=0;i<broj_pr;i++){delete prod[i];prod[i]=nullptr;broj_pr=0;}
}
void Prodaje::ObrisiNajranijuProdaju(){
    if(broj_pr==0)throw range_error("Prazna kolekcija");
   Prodaja *p=&DajNajranijuProdaju();
   for(int i=0;i<broj_pr;i++){
       if(prod[i]==p){delete prod[i];prod[i]=nullptr;broj_pr--;}
   }
}
void Prodaje::ObrisiProdajeAgenta(const string &ime_agenta){
    if(broj_pr==0)throw range_error("Prazna kolekcija");
    for(int i=0;i<broj_pr;i++){
        if((*prod[i]).DajImeAgenta()==ime_agenta){delete prod[i];prod[i]=nullptr;broj_pr--;}
    }
}
void Prodaje::ObrisiProdajeNaDatum(const Datum &datum){
    if(broj_pr==0)throw range_error("Prazna kolekcija");
    for(int i=0;i<broj_pr;i++){
        if((*prod[i]).DajDatumProdaje().DajGodinu()==datum.DajGodinu() && (*prod[i]).DajDatumProdaje().DajMjesec()==datum.DajMjesec() && (*prod[i]).DajDatumProdaje().DajDan()==datum.DajDan()){delete prod[i];prod[i]=nullptr;broj_pr--;}
    }
}
void Prodaje::IspisiProdajeNaDatum(const Datum &datum)const{
    vector<Prodaja *>v_pr;
    for(int i=0;i<broj_pr;i++){
        if(prod[i]==nullptr)continue;
        if((*prod[i]).DajDatumProdaje().DajGodinu()==datum.DajGodinu() && (*prod[i]).DajDatumProdaje().DajMjesec()==datum.DajMjesec() && (*prod[i]).DajDatumProdaje().DajDan()==datum.DajDan())v_pr.push_back(prod[i]);
    }
    sort(&v_pr[0],&v_pr[v_pr.size()],[](Prodaja *p1,Prodaja *p2){
        return p1->DajImeAgenta()<p2->DajImeAgenta();
    });
    for(int i=0;i<v_pr.size();i++){
        v_pr[i]->Ispisi();cout<<endl;
    }
}
void Prodaje::IspisiSveProdaje()const{
     vector<Prodaja *>vp;
     for(int i=0;i<broj_pr;i++){if(prod[i]!=nullptr)vp.push_back(prod[i]);}
      sort(&vp[0],&vp[vp.size()],[](Prodaja *p1,Prodaja *p2){
          return Datum::VratiManjiDatum(p1->DajDatumProdaje(),p2->DajDatumProdaje());
      });
      for(int i=0;i<vp.size();i++){
          for(int j=0;j<vp.size();j++){
              if(i==j)continue;
              if(vp[i]->DajDatumProdaje().DajGodinu()==vp[j]->DajDatumProdaje().DajGodinu() && vp[i]->DajDatumProdaje().DajMjesec()==vp[j]->DajDatumProdaje().DajMjesec() && vp[i]->DajDatumProdaje().DajDan()==vp[j]->DajDatumProdaje().DajDan()){
              if(vp[i]->DajImeAgenta() < vp[j]->DajImeAgenta())swap(vp[i],vp[j]);
              }
          }
      }
      for(int i=0;i<vp.size();i++){
          vp[i]->Ispisi();cout<<endl;
      }
      
}
int main ()
{
        cout<<"Dobrodosli!"<<endl<<endl;
        vector<Stan>stanovi;
        vector<Kupac>kupci;
        Prodaje lujka(20);
        for(;;){
        cout<<endl<<"Izaberite opciju:";
        cout<<endl<<" 0 - kraj"<<endl<<" 1 - uredjivanje stanova"<<endl<<" 2 - uredjivanje kupaca"<<endl<<" 3 - uredjivanje prodaja"<<endl;
        int opcija,opcija2;cin>>opcija;
        if(opcija==0)break;
        if(opcija==1){
            for(;;){
                cout<<"Izaberite opciju:"<<endl;
                cout<<" 0 - nazad"<<endl<<" 1 - dodavanje stana"<<endl<<" 2 - uredjivanje stanova"<<endl<<" 3 - ispis svih stanova"<<endl<<" 4 - kraj"<<endl;
                cin>>opcija2;
                if(opcija2==0 || opcija2==4)break;
                if(opcija2==1){
                    for(int i=0;i<1;i++){
                   try {
                   cout<<"Unesite adresu: ";
                   string adr;
                   cin.ignore(10000,'\n');
                   getline(cin,adr);
                   cout<<"Unesite sprat: ";
                   int s;cin>>s;
                   cout<<"Unesite broj soba: ";
                   int br;cin>>br;
                   cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                   int y;cin>>y;
                   cout<<"Unesite kvadraturu: ";
                   double k;cin>>k;
                   if(y!=0 && y!=1)throw domain_error("Neispravan unos podataka");
                   Stan sy(adr,s,br,y,k);
                   stanovi.push_back(sy);
                   }
                   catch(domain_error e){
                       cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<endl;i--;
                   }   
                }
                cout<<"Stan je uspjesno dodan!"<<endl;
            }
            
            if(opcija2==2){
                cout<<"Odaberite stan. Dostupni stanovi su:"<<endl;
                for(int i=0;i<stanovi.size();i++){
                    cout<<" "<<i+1<<" - ";stanovi[i].Ispisi();cout<<endl;
                }
                cout<<endl;
                int indeks;cin>>indeks;
                cout<<"Odaberite polje koji zelite urediti:"<<endl;
                cout<<" 0 - nazad"<<endl<<" 1 - adresa"<<endl<<" 2 - sprat"<<endl<<" 3 - broj soba"<<endl<<" 4 - da li je stan namjesten"<<endl<<" 5 - kvadratura"<<endl<<" 6 - sve"<<endl;
                int opcija3;cin>>opcija3;
                if(opcija3==0)break;
                if(opcija3==1){
                    cout<<"Unesite adresu: ";
                    string a;
                    cin.ignore(1000,'\n');
                    getline(cin,a);
                    stanovi[indeks-1].Postavi(a,stanovi[indeks-1].DajSprat(),stanovi[indeks-1].DajBrojSoba(),stanovi[indeks-1].DajNamjesten(),stanovi[indeks-1].DajKvadraturu());
                    cout<<"Stan je uspjesno izmijenjen!"<<endl;
                }
                if(opcija3==2){
                    for(int i=0;i<1;i++){
                    cout<<"Unesite sprat: ";
                    int sp;cin>>sp;
                    try { stanovi[indeks-1].Postavi(stanovi[indeks-1].DajAdresu(),sp,stanovi[indeks-1].DajBrojSoba(),stanovi[indeks-1].DajNamjesten(),stanovi[indeks-1].DajKvadraturu());
                    cout<<"Stan je uspjesno izmijenjen!"<<endl;}
                    catch(domain_error e){
                        cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<endl;i--;
                    }
                  }
                }
                if(opcija3==3){
                    for(int i=0;i<1;i++){
                    cout<<"Unesite broj soba: ";
                    int g;cin>>g;
                    try{stanovi[indeks-1].Postavi(stanovi[indeks-1].DajAdresu(),stanovi[indeks-1].DajSprat(),g,stanovi[indeks-1].DajNamjesten(),stanovi[indeks-1].DajKvadraturu());
                    cout<<"Stan je uspjesno izmijenjen!"<<endl;}
                    catch(domain_error e){
                        cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<endl;i--;
                    }
                  }
                }
                if(opcija3==4){
                    for(int i=0;i<1;i++){
                    cout<<"Da li je stan namjesten: ";
                    int b;cin>>b;
                    try { if(b!=0 && b!=1)throw domain_error("Neispravan unos podataka");
                        stanovi[indeks-1].Postavi(stanovi[indeks-1].DajAdresu(),stanovi[indeks-1].DajSprat(),stanovi[indeks-1].DajBrojSoba(),b,stanovi[indeks-1].DajKvadraturu());
                    cout<<"Stan je uspjesno izmijenjen!"<<endl;}
                    catch(domain_error e){
                        cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<endl;i--;
                    }
                  }
                }
                if(opcija3==5){
                    for(int i=0;i<1;i++){
                        cout<<"Unesite kvadraturu: ";
                        double h;cin>>h;
                        try{stanovi[indeks-1].Postavi(stanovi[indeks-1].DajAdresu(),stanovi[indeks-1].DajSprat(),stanovi[indeks-1].DajBrojSoba(),stanovi[indeks-1].DajNamjesten(),h);
                        cout<<"Stan je uspjesno izmijenjen!"<<endl;}
                        catch(domain_error e){
                        cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<endl;i--;
                    }
                  }
                }
                if(opcija3==6){
                    for(int i=0;i<1;i++){
                   try {
                   cout<<"Unesite adresu: ";
                   string adr;
                   cin.ignore(10000,'\n');
                   getline(cin,adr);
                   cout<<"Unesite sprat: ";
                   int s;cin>>s;
                   cout<<"Unesite broj soba: ";
                   int br;cin>>br;
                   cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                   int y;cin>>y;
                   cout<<"Unesite kvadraturu: ";
                   double k;cin>>k;
                   if(y!=0 && y!=1)throw domain_error("Neispravan unos podataka");
                   stanovi[indeks-1].Postavi(adr,s,br,y,k);
                   }
                   catch(domain_error e){
                       cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<endl;i--;
                   }   
                }
                cout<<"Stan je uspjesno izmijenjen!"<<endl;
                }
            }
            
            if(opcija2==3){
                for(int i=0;i<stanovi.size();i++){
                    cout<<i+1<<". ";stanovi[i].Ispisi();
                    cout<<endl;
                }
            }
        }
            if(opcija2==4)break;
       }
       if(opcija==2){
           for(;;){
               cout<<"Izaberite opciju:"<<endl;
               cout<<" 0 - nazad"<<endl<<" 1 - dodavanje kupca"<<endl<<" 2 - uredjivanje kupaca"<<endl<<" 3 - ispis svih kupaca"<<endl<<" 4 - kraj"<<endl;
               cin>>opcija2;
               if(opcija2==0 || opcija2==4)break;
               if(opcija2==1){
                    for(int i=0;i<1;i++){
                   try {
                   cout<<"Unesite ime i prezime kupca: ";
                   string im;
                   cin.ignore(10000,'\n');
                   getline(cin,im);
                   cout<<"Unesite datum rodjenja (formata d/m/g): ";
                   int day,month,year;char znak1,znak2;
                   cin>>day>>znak1>>month>>znak2>>year;
                   Datum d(day,month,year);
                   Kupac ku(im,d);
                   kupci.push_back(ku);
                   }
                   catch(domain_error e){
                       cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<endl;i--;
                   }   
                }
                cout<<"Kupac je uspjesno dodan!"<<endl;
               }
               if(opcija2==2){
                   cout<<"Odaberite kupca kojeg zelite urediti. Dostupni kupci su:"<<endl;
                   for(int i=0;i<kupci.size();i++){
                       cout<<" "<<i+1<<" - ";kupci[i].Ispisi();cout<<endl;
                   }
                   int indeks;cin>>indeks;
                   for(int i=0;i<1;i++){
                   try {
                   cout<<"Unesite ime i prezime kupca: ";
                   string im;
                   cin.ignore(10000,'\n');
                   getline(cin,im);
                   cout<<"Unesite datum rodjenja (formata d/m/g): ";
                   int day,month,year;char znak1,znak2;
                   cin>>day>>znak1>>month>>znak2>>year;
                   Datum d(day,month,year);
                   Kupac ku(im,d);
                   kupci[indeks-1].Postavi(im,d);
                   }
                   catch(domain_error e){
                       cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<endl;i--;
                   }   
                }
                cout<<"Kupac je uspjesno izmijenjen!"<<endl;
            }
               if(opcija2==3){
                   for(int i=0;i<kupci.size();i++){
                       kupci[i].Ispisi();cout<<endl;
                   }
               }
           }
           if(opcija2==4)break;
       }
       if(opcija==3){
           for(;;){
            cout<<"Izaberite opciju:"<<endl;
            cout<<" 0 - nazad"<<endl<<" 1 - dodavanje prodaje"<<endl<<" 2 - uredjivanje prodaje"<<endl<<" 3 - ispis prodaja"<<endl<<" 4 - brisanje prodaja"<<endl<<" 5 - kraj"<<endl;
            cin>>opcija2;int opcija3;
            if(opcija2==1){
                 for(;;){
                    cout<<"Izaberite opciju:"<<endl<<" 0 - nazad"<<endl<<" 1 - dodavanje potpuno nove prodaje"<<endl<<" 2 - dodavanje nove prodaje na osnovu arhive"<<endl<<" 3 - kraj"<<endl;
                    cin>>opcija3;
                    if(opcija3==0 || opcija3==3)break;
                if(opcija3==1){
                    for(int i=0;i<1;i++){
                        try {
                    cout<<"Unesite ime i prezime agenta prodaje: ";
                    string ago;cin.ignore(10000,'\n');
                    getline(cin,ago);
                    cout<<"Unesite datum prodaje (formata d/m/g): ";
                    int e,f,k;char z1,z2;
                    cin>>e>>z1>>f>>z2>>k;
                    cout<<"Unesite cijenu stana: ";
                    double pare;cin>>pare;
                    cout<<"Unesite ime kupca: ";
                    string majmun;
                    cin.ignore(10000,'\n');
                    getline(cin,majmun);
                    cout<<"Unesite datum rodjenja kupca (formata d/m/g): ";
                    int x1,x2,x3;char y1,y2;
                    cin>>x1>>y1>>x2>>y2>>x3;
                    cout<<"Unesite adresu: ";
                    string s1;cin.ignore(1000,'\n');
                    getline(cin,s1);
                    cout<<"Unesite sprat: ";
                    int spratko;cin>>spratko;
                    cout<<"Unesite broj soba: ";
                    int sobicak;cin>>sobicak;
                    cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                    int namko;cin>>namko;
                    cout<<"Unesite kvadraturu: ";
                    double kvadratici;cin>>kvadratici;
                    if(namko!=0 && namko!=1)throw domain_error("Neispravan unos podataka");
                    kupci.push_back(Kupac(majmun,Datum(x1,x2,x3)));
                    stanovi.push_back(Stan(s1,spratko,sobicak,namko,kvadratici));
                    lujka.RegistrirajProdaju(ago,pare,e,f,k,majmun,Datum(x1,x2,x3),s1,spratko,sobicak,namko,kvadratici);
                    }
                    catch(domain_error e){
                         cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<endl;i--;
                    }
                    catch(range_error e){
                         cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<endl;i--;
                    }
                  }
                  cout<<"Prodaja uspjesno dodana!"<<endl;
                }
                if(opcija3==2){
                    for(int i=0;i<1;i++){
                    try {
                    cout<<"Unesite ime i prezime agenta prodaje: ";
                    string ago;cin.ignore(10000,'\n');
                    getline(cin,ago);
                    cout<<"Unesite datum prodaje (formata d/m/g): ";
                    int e,f,k;char z1,z2;
                    cin>>e>>z1>>f>>z2>>k;
                    cout<<"Unesite cijenu stana: ";
                    double pare;cin>>pare;
                    cout<<"Odaberite kupca. Dostupni kupci su:"<<endl;
                    for(int i=0;i<kupci.size();i++){
                        cout<<i+1<<" - ";kupci[i].Ispisi();cout<<endl;
                    }
                    int indeks_kupca;cin>>indeks_kupca;
                    cout<<"Odaberite stan. Dostupni stanovi su:"<<endl;
                    for(int i=0;i<stanovi.size();i++){
                        cout<<" "<<i+1<<" - ";stanovi[i].Ispisi();cout<<endl;
                    }
                    int indeks_stana;cin>>indeks_stana;
                    lujka.RegistrirajProdaju(ago,pare,Datum(e,f,k),kupci[indeks_kupca-1],stanovi[indeks_stana-1]);
                    }
                    catch(domain_error e){
                         cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<endl;i--;
                    }
                    catch(range_error e){
                         cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<endl;i--;
                    }
                  }
                  cout<<"Prodaja uspjesno dodana!"<<endl;
                }
              }
             }
             if(opcija2==2){
                 cout<<"Odaberite prodaju koju zelite urediti. Dostupne prodaje su:"<<endl;
                 for(int i=0;i<lujka.DajBrojProdaja();i++){
                     //if(lujka.DajProdaju(i)==nullptr)continue;
                     cout<<i+1<<"."<<endl;
                     //if(lujka.DajProdaju(i)==nullptr)continue;
                     lujka.DajProdaju(i).Ispisi();cout<<endl;
                 }
                 int indeks_prod;cin>>indeks_prod;
                 cout<<"Izaberite opciju: "<<endl<<" 0 - nazad"<<endl<<" 1 - izmjena agenta"<<endl<<" 2 - izmjena datuma prodaje"<<endl<<" 3 - izmjena kupca"<<endl<<" 4 - izmjena stana"<<endl<<" 5 - izmjena cijene stana"<<endl;
                 int opcija3;cin>>opcija3;
                 if(opcija3==0)break;
                 if(opcija3==1){
                     cout<<"Unesite ime i prezime agenta prodaje: ";
                     string ime;cin.ignore(1000,'\n');
                     getline(cin,ime);
                     lujka.DajProdaju(indeks_prod-1).PromijeniAgenta(ime);
                     cout<<"Prodaja je uspjesno izmijenjena!"<<endl;
                 }
                 if(opcija3==2){
                     for(int i=0;i<1;i++){
                         try {
                     cout<<"Unesite datum prodaje (formata d/m/g): ";
                     int di,mi,gi;char t1,t2;cin>>di>>t1>>mi>>t2>>gi;
                     lujka.DajProdaju(indeks_prod-1).PromijeniDatumKupovine(Datum(di,mi,gi));
                             
                         }
                         catch(domain_error e){
                          cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<endl;i--; 
                         }
                     }
                     cout<<"Prodaja je uspjesno izmijenjena!"<<endl;
                 }
                 if(opcija3==3){
                     cout<<"Izaberite opciju:"<<endl<<"0 - nazad"<<endl<<"1 - odabir postojeceg kupca"<<endl<<"2 - dodavanje novog kupca"<<endl;
                     int opcija4;cin>>opcija4;
                     if(opcija4==0)break;
                     if(opcija4==1){
                         cout<<"Odaberite kupca. Dostupni kupci su:"<<endl;
                         for(int i=0;i<kupci.size();i++){
                             cout<<i+1<<" - ";kupci[i].Ispisi();cout<<endl;
                         }
                         int indeks_kupca;cin>>indeks_kupca;
                         lujka.DajProdaju(indeks_prod-1).PromijeniKupca(Kupac(kupci[indeks_kupca-1].DajImePrezime(),kupci[indeks_kupca-1].DajDatumRodjenja()));
                         cout<<"Prodaja je uspjesno izmijenjena!"<<endl;
                     }
                     if(opcija4==2){
                     for(int i=0;i<1;i++){
                     try {
                     cout<<"Unesite ime i prezime kupca: ";
                     string ime;cin.ignore(1000,'\n');
                     getline(cin,ime);
                     cout<<"Unesite datum rodjenja (formata dan/mjesec/godina): ";
                     int d,m,g;char r,t;cin>>d>>r>>m>>t>>g;
                     kupci.push_back(Kupac(ime,Datum(d,m,g)));
                     lujka.DajProdaju(indeks_prod-1).PromijeniKupca(Kupac(ime,Datum(d,m,g)));
                      } 
                      catch(domain_error e){
                          cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<endl;i--; 
                         }
                     }
                     cout<<"Prodaja je uspjesno izmijenjena!"<<endl;
                         
                     }
                 }
                 if(opcija3==4){
                     cout<<"Izaberite opciju:"<<endl<<" 0 - nazad"<<endl<<" 1 - odabir postojeceg stana"<<endl<<" 2 - dodavanje novog stana"<<endl;
                     int opcija4;cin>>opcija4;
                     if(opcija4==0)break;
                     if(opcija4==1){
                         cout<<"Odaberite stan. Dostupni stanovi su:"<<endl;
                         for(int i=0;i<stanovi.size();i++){
                             cout<<" "<<i+1<<" - ";stanovi[i].Ispisi();cout<<endl;
                         }
                         int indeks_stana;cin>>indeks_stana;
                         lujka.DajProdaju(indeks_prod-1).PromijeniStan(stanovi[indeks_stana-1]);
                         cout<<"Prodaja je uspjesno izmijenjena!"<<endl;
                     }
                     if(opcija4==2){
                         for(int i=0;i<1;i++){
                   try {
                   cout<<"Unesite adresu: ";
                   string adr;
                   cin.ignore(10000,'\n');
                   getline(cin,adr);
                   cout<<"Unesite sprat: ";
                   int s;cin>>s;
                   cout<<"Unesite broj soba: ";
                   int br;cin>>br;
                   cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                   int y;cin>>y;
                   cout<<"Unesite kvadraturu: ";
                   double k;cin>>k;
                   if(y!=0 && y!=1)throw domain_error("Neispravan unos podataka");
                   stanovi.push_back(Stan(adr,s,br,y,k));
                   lujka.DajProdaju(indeks_prod-1).PromijeniStan(Stan(adr,s,br,y,k));
                   }
                   catch(domain_error e){
                       cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<endl;i--;
                   }   
                }
                cout<<"Prodaja je uspjesno izmijenjena!"<<endl;
                     }
                 }
                 if(opcija3==5){
                     for(int i=0;i<1;i++){
                         try {
                             cout<<"Unesite cijenu stana: ";
                             double cj;cin>>cj;
                             lujka.DajProdaju(indeks_prod-1).PromijeniCijenuProdaje(cj);
                         }
                         catch(domain_error e){
                             cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<endl;i--; 
                         }
                     }
                     cout<<"Prodaja je uspjesno izmijenjena!"<<endl;
                 }
             }
             if(opcija2==3){
                 cout<<"Izaberite opciju:"<<endl<<" 0 - nazad"<<endl<<" 1 - ispis svih prodaja"<<endl<<" 2 - ispis prodaja na datum"<<endl<<" 3 - ispis najranije prodaje"<<endl<<" 4 - ispis najskuplje prodaje"<<endl<<" 5 - ispis broja prodaja"<<endl<<" 6 - ispis broja prodaja po datumu"<<endl<<" 7 - ispis broja prodaja po agentu"<<endl<<" 8 - kraj"<<endl;
                 int opcija3;cin>>opcija3;
                 if(opcija3==8 || opcija3==0)break;
                 if(opcija3==1){lujka.IspisiSveProdaje();}
                 if(opcija3==2){
                     cout<<"Unesite datum (d/m/g): ";
                     int d,m,g;char z1,z2;
                     cin>>d>>z1>>m>>z2>>g;
                     cout<<"Prodaje na datum ";Datum(d,m,g).Ispisi();cout<<" su :"<<endl;
                     lujka.IspisiProdajeNaDatum(Datum(d,m,g));
                 }
                 if(opcija3==3){
                     cout<<endl;lujka.DajNajranijuProdaju().Ispisi();
                 }
                 if(opcija3==4){
                     cout<<endl;lujka.DajNajskupljuProdaju().Ispisi();
                 }
                 if(opcija3==5){
                     cout<<"Broj prodaja: "<<lujka.DajBrojProdaja();
                 }
                 if(opcija3==6){
                     cout<<"Unesite datum (d/m/g): ";
                     int d,m,g;char z1,z2;
                     cin>>d>>z1>>m>>z2>>g;
                     cout<<"Broj prodaja na uneseni datum: "<<lujka.DajBrojProdajaNaDatum(Datum(d,m,g));
                 }
                 if(opcija3==7){
                     cout<<"Unesite ime agenta: ";
                     string ime;cin.ignore(1000,'\n');
                     getline(cin,ime);
                     cout<<"Broj prodaja: "<<lujka.DajBrojProdajaOdAgenta(ime);
                 }
             }
             if(opcija2==4){
                 for(;;){
                     try {
                 cout<<"Izaberite opciju:"<<endl<<" 0 - nazad"<<endl<<" 1 - brisanje najranije ponude"<<endl<<" 2 - brisanje prodaja agenta"<<endl<<" 3 - brisanje prodaja po datumu"<<endl<<" 4 - brisanje svih prodaja"<<endl;
                 int opcija3;cin>>opcija3;
                 if(opcija3==0)break;
                 if(opcija3==1){
                     lujka.ObrisiNajranijuProdaju();cout<<"Najranija prodaja je obrisana!"<<endl;
                 }
                 if(opcija3==2){
                     cout<<"Unesite ime agenta: ";
                     string ime;cin.ignore(1000,'\n');
                     getline(cin,ime);
                     lujka.ObrisiProdajeAgenta(ime);
                     cout<<"Sve prodaje tog agenta su obrisane.";
                 } 
                 if(opcija3==3){
                     cout<<"Unesite datum: ";
                     int d,m,g;char z1,z2;
                     cin>>d>>z1>>m>>z2>>g;
                     lujka.ObrisiProdajeNaDatum(Datum(d,m,g));
                     cout<<"Sve prodaje na taj datum su obrisane."<<endl;
                 }
                 if(opcija3==4){
                     lujka.IsprazniKolekciju();
                     cout<<"Sve prodaje su obrisane."<<endl;
                 }
                 }
                 catch(range_error r){
                     cout<<"Izuzetak: "<<r.what()<<endl;
                 }
               }
             }
             if(opcija2==5 || opcija2==0 || opcija3==8 || opcija3==3)break;
           }
           if(opcija2==5)break;
       }
        
    }
    cout<<"Dovidjenja!";
  	return 0;
}