/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok! bilo koji znak koji nije slovo, broj ili znak “crtica”, razmak ili apostrof.
#include <iostream>
#include<string>
#include<stdexcept>
#include<iomanip>
#include<algorithm>
#include<initializer_list>
#include<memory>
using std::cout;
using std::cin;
using std::string;
using std::endl;

class Datum{
    int dan, mjesec, godina;
    public:
    Datum(int dan, int mjesec, int godina);
    void Postavi(int dan, int mjesec, int godina);
    int DajDan() const {return dan;};
    int DajMjesec() const{return mjesec;};
    int DajGodinu() const{return godina;};
    void Ispisi() const{cout<<dan<<"/"<<mjesec<<"/"<<godina;};
};
        Datum::Datum(int dan, int mjesec, int godina){ 
                int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            if(((godina % 4 == 0) && (godina % 100 != 0)) || godina % 400 == 0) 
                broj_dana[1]++;
            if(godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12|| dan > broj_dana[mjesec-1])
                throw std::domain_error("Neispravan datum!");
            Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina;
        }
            
        void Datum::Postavi(int dan, int mjesec, int godina) {
            int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            if((godina % 4 == 0 && godina % 100 != 0 )|| godina % 400 == 0)
                broj_dana[1]++;
            if(godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > broj_dana[mjesec-1])
                throw std::domain_error("Neispravan datum!");
            Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina;
        }

class Kupac{
    string imeiprezime; 
    Datum datumrodjenja;
    static bool IspravanTekst(string imeiprezime);
    public:
    Kupac(const std::string &ime_i_prezime, const Datum & datum_rodjenja);
    void Postavi(const std::string & ime_i_prezime, const Datum & datum_rodjenja);
    std::string DajImePrezime() const{return imeiprezime;};
    Datum DajDatumRodjenja() const{return datumrodjenja;};
    void Ispisi() const{cout<<DajImePrezime()<<"(";
    datumrodjenja.Ispisi();
    cout<<")";};
};
        Kupac::Kupac(const std::string &ime_i_prezime, const Datum & datum_rodjenja) :
                datumrodjenja(datum_rodjenja.DajDan(), datum_rodjenja.DajMjesec(), datum_rodjenja.DajGodinu()){
                    if (IspravanTekst(ime_i_prezime)==true)
                    imeiprezime=ime_i_prezime;  
                    else throw std::domain_error("Neispravano ime i prezime");
                    datumrodjenja=datum_rodjenja;
                }
                
        void Kupac::Postavi(const std::string & ime_i_prezime, const Datum & datum_rodjenja){
            if (IspravanTekst(ime_i_prezime)==true)
            imeiprezime=ime_i_prezime;  
            else throw std::domain_error("Neispravano ime i prezime");
            datumrodjenja=Datum(datum_rodjenja);
        }
        
        bool Kupac::IspravanTekst(string s){
            for (int i=0; i<s.size(); i++){
                if (!((s[i]>='a'&& s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='0'&&s[i]<='9')|| (s[i]==' ')|| s[i]=='-'|| s[i]==39 ))
                return false;
            }
            return true;
        }

class Stan{
    string adresa;
    int sprat, broj_soba;
    bool namjesten;
    double kvadratura;
    static bool IspravanTekst(string adresa);
    public:
    Stan(const std::string & adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
    void Postavi(const std::string & adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
    std::string DajAdresu() const{return adresa;};
    int DajSprat() const{return sprat;};
    int DajBrojSoba() const{return broj_soba;};
    bool DajNamjesten() const{return namjesten;};
    double DajKvadraturu() const{return kvadratura;};
    void Ispisi() const;
};
        bool Stan::IspravanTekst(string s){
            for (int i=0; i<s.size(); i++){
                if (!((s[i]>='a'&& s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='0'&&s[i]<='9')|| (s[i]==' ')|| s[i]=='-'|| s[i]==39 ))
                return false;
            }
            return true;
        }
        
        Stan::Stan(const std::string & adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
                if (IspravanTekst(adresa)) Stan::adresa=adresa;
                else throw std::domain_error ("Neispravna adresa");
                if (broj_soba<0 || sprat<0|| kvadratura<0) throw std::domain_error("Neispravan unos podataka");
                else {
                    Stan::sprat=sprat; Stan::broj_soba=broj_soba; Stan::namjesten=namjesten; Stan::kvadratura=kvadratura;
                }
                
        }
            
        void Stan::Postavi(const std::string & adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
            if (IspravanTekst(adresa)==true) Stan::adresa=adresa;
                else throw std::domain_error ("Neispravna adresa");
            if (broj_soba<0 || sprat<0|| kvadratura<0) throw std::domain_error("Neispravan unos podataka");
                else {
                    Stan::sprat=sprat; Stan::broj_soba=broj_soba; Stan::namjesten=namjesten; Stan::kvadratura=kvadratura;
                }
        }
        
        void Stan::Ispisi() const{
                int brs=DajBrojSoba();
                if (brs==1|| (brs%10==1 && brs!=11))
                    cout<<"Stan se nalazi na adresi "<<DajAdresu()<<" na "<<DajSprat()<<". spratu i ima "<<DajBrojSoba()<<" sobu."<<endl;
                else if (brs==2 || brs==3 || brs==4 || (brs%10==2 && brs!=12)||(brs%10==3 && brs!=13)||(brs%10==4 && brs!=14)) 
                    cout<<"Stan se nalazi na adresi "<<DajAdresu()<<" na "<<DajSprat()<<". spratu i ima "<<DajBrojSoba()<<" sobe."<<endl;
                else cout<<"Stan se nalazi na adresi "<<DajAdresu()<<" na "<<DajSprat()<<". spratu i ima "<<DajBrojSoba()<<" soba."<<endl;
                bool nmj=DajNamjesten();
                if (nmj==true) cout<<"Kvadratura stana je "<<DajKvadraturu()<<" (m^2) i stan je namjesten.";
                else cout<<"Kvadratura stana je "<<DajKvadraturu()<<" (m^2) i stan nije namjesten.";
        }
            
class Prodaja{
    string ime_agenta_prodaje;
    double cijena_stana;
    Datum datumprodaje;
    Kupac kupacstana;
    Stan kupljenistan;
    static bool IspravanTekst(string ime_agenta_prodaje);
    public:
    Prodaja(const std::string & ime_agenta_prodaje, double cijena_stana,const Datum & datum_prodaje, const Kupac & kupac_stana, const Stan & kupljeni_stan);
    Prodaja(const std::string & ime_agenta_prodaje, double cijena_stana,int dan_prodaje, int mjesec_prodaje, int godina_prodaje,std::string & ime_kupca, const Datum & datum_rodjenja_kupca, const std::string & adresa_stana, int sprat_stana, int broj_soba,bool namjesten_stan, double broj_kvadrata);
    void PromijeniKupca(const Kupac & novi_kupac){kupacstana=novi_kupac;};
    void PromijeniStan(const Stan & novi_stan){kupljenistan=novi_stan;};
    void PromijeniDatumKupovine(const Datum & novi_datum){datumprodaje=novi_datum;};
    void PromijeniCijenuProdaje(const double & nova_cijena){cijena_stana=nova_cijena;};
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImeAgenta() const{return ime_agenta_prodaje;};
    std::string DajImeKupca() const{return kupacstana.DajImePrezime(); };
    Datum DajDatumProdaje() const{return datumprodaje; };
    double DajCijenuStana() const{return cijena_stana; };
    friend bool ProdatPrije(const Prodaja & p1, const Prodaja & p2);
    friend bool SkupljiStan(const Prodaja & p1, const Prodaja & p2);
    void Ispisi() const;
};
        Prodaja::Prodaja(const std::string & ime_agenta_prodaje, double cijena_stana,const Datum & datum_prodaje, const Kupac & kupac_stana, const Stan & kupljeni_stan):
            datumprodaje(datum_prodaje.DajDan(), datum_prodaje.DajMjesec(), datum_prodaje.DajGodinu()), 
            kupacstana(kupac_stana.DajImePrezime(), kupac_stana.DajDatumRodjenja()), 
            kupljenistan(kupljeni_stan.DajAdresu(), kupljeni_stan.DajSprat(), kupljeni_stan.DajBrojSoba(), kupljeni_stan.DajNamjesten(), kupljeni_stan.DajKvadraturu()){
                if (IspravanTekst(ime_agenta_prodaje)== true) Prodaja::ime_agenta_prodaje=ime_agenta_prodaje;
                else throw std::domain_error("Neispravno ime");
                if (cijena_stana<0) throw std::domain_error("Neispravan unos");
                else Prodaja::cijena_stana=cijena_stana;
                Prodaja::datumprodaje=datum_prodaje;
                Prodaja::kupacstana=kupac_stana;
                Prodaja::kupljenistan=kupljeni_stan;
            }
            
        Prodaja::Prodaja(const std::string & ime_agenta_prodaje, double cijena_stana,int dan_prodaje, int mjesec_prodaje, int godina_prodaje,std::string & ime_kupca, const Datum & datum_rodjenja_kupca, const std::string & adresa_stana, int sprat_stana, int broj_soba,bool namjesten_stan, double broj_kvadrata):
            datumprodaje( dan_prodaje, mjesec_prodaje, godina_prodaje),
            kupacstana(ime_kupca, datum_rodjenja_kupca), 
            kupljenistan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata){
                if (IspravanTekst(ime_agenta_prodaje)== true) Prodaja::ime_agenta_prodaje=ime_agenta_prodaje;
                else throw std::domain_error("Neispravno ime");
                if (cijena_stana<0) throw std::domain_error("Neispravan unos");
                else Prodaja::cijena_stana=cijena_stana;
            }
            
        bool Prodaja::IspravanTekst(string s){
            for (int i=0; i<s.size(); i++){
                if (!((s[i]>='a'&& s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='0'&&s[i]<='9')|| (s[i]==' ')|| s[i]=='-'|| s[i]==39 ))
                return false;
            }
            return true;
        }
        
        void Prodaja::PomjeriDanUnaprijed(){
            int godina=datumprodaje.DajGodinu();
            int mjesec=datumprodaje.DajMjesec();
            int dan=datumprodaje.DajDan();
            int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0) broj_dana[1]++;
            dan++;
            if(dan > broj_dana[mjesec-1]) {dan=1; mjesec++;}
            if(mjesec > 12) {mjesec = 1; godina++;}
            datumprodaje.Postavi(dan, mjesec, godina);
        }
        
        void Prodaja::PomjeriDanUnazad(){
            int godina=datumprodaje.DajGodinu();
            int mjesec=datumprodaje.DajMjesec();//4
            int dan=datumprodaje.DajDan();
            int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0) broj_dana[1]++;
            dan--;
            if(dan <=0) { mjesec--;}
            if(mjesec <=0) {mjesec = 12; godina--; dan=broj_dana[mjesec-1];}
            datumprodaje.Postavi(dan, mjesec, godina);
        }
        
        void Prodaja::Ispisi()const{
            cout<<"\nIme agenta: "<<std::setw(20)<<DajImeAgenta()<<endl;
            cout<<"Ime kupca: "<<std::setw(16)<<DajImeKupca()<<endl;
            cout<<"Zakazani datum prodaje: ";
            DajDatumProdaje().Ispisi();
            cout<<endl;
            cout<<"Cijena stana: "<<std::setw(9)<<DajCijenuStana()<<endl;
            cout<<"Informacije o stanu: "<<endl;
            kupljenistan.Ispisi();
        }
        
        bool ProdatPrije(const Prodaja &p1, const Prodaja &p2){
            if (p1.DajDatumProdaje().DajGodinu()<p2.DajDatumProdaje().DajGodinu()) return true;
            if ((p1.DajDatumProdaje().DajGodinu()==p2.DajDatumProdaje().DajGodinu())&&(p1.DajDatumProdaje().DajMjesec()<p2.DajDatumProdaje().DajMjesec()) )return true;
            if (((p1.DajDatumProdaje().DajGodinu()==p2.DajDatumProdaje().DajGodinu())&&(p1.DajDatumProdaje().DajMjesec()<p2.DajDatumProdaje().DajMjesec()))&& (p1.DajDatumProdaje().DajDan()<p2.DajDatumProdaje().DajDan())) return true;
            return false;
        }
        
        bool SkupljiStan(const Prodaja & p1, const Prodaja & p2){
            double a=p1.DajCijenuStana();
            double b=p2.DajCijenuStana();
            if (a-b<000000000000001) return false;
            else return true;
        }
        
class Prodaje{
    int max_broj_prodaja;
    int broj_prodaja;
    Prodaja **sveprodaje; 
    public:
   explicit Prodaje(int max_broj_prodaja): max_broj_prodaja(max_broj_prodaja), broj_prodaja(0), sveprodaje(new Prodaja*[max_broj_prodaja]{}) {}
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
   ~Prodaje() ;
    Prodaje(const Prodaje & prodaje);
    Prodaje(Prodaje && prodaje): max_broj_prodaja(prodaje.max_broj_prodaja), sveprodaje(prodaje.sveprodaje),broj_prodaja(prodaje.broj_prodaja){prodaje.sveprodaje=nullptr;prodaje.broj_prodaja=0;}
    Prodaje & operator =(const Prodaje & prodaje);//
    Prodaje & operator =(Prodaje && prodaje);//
    void RegistrirajProdaju(const std::string & ime_agenta_prodaje, double cijena_stana, const Datum & datum_prodaje, const Kupac & kupac_stana,const Stan & kupljeni_stan);
    void RegistrirajProdaju(const std::string & ime_agenta_prodaje, double cijena_stana, int dan_prodaje,int mjesec_prodaje, int godina_prodaje, std::string & ime_kupca,const Datum & datum_rodjenja_kupca, const std::string & adresa_stana,int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void RegistrirajProdaju(Prodaja *prodaja);//
    int DajBrojProdaja() const{return broj_prodaja;}; //
    int DajBrojProdajaNaDatum(const Datum & datum) const; //
    int DajBrojProdajaOdAgenta(const std::string & ime_agenta) const;//
    Prodaja & DajNajranijuProdaju();
    Prodaja DajNajranijuProdaju() const;
    Prodaja & DajNajskupljuProdaju();
    Prodaja DajNajskupljuProdaju() const;
    void IsprazniKolekciju();
    void ObrisiNajranijuProdaju();
    void ObrisiProdajeAgenta(const std::string & ime_agenta);//
    void ObrisiProdajeNaDatum(const Datum & datum);//
    void IspisiProdajeNaDatum(const Datum & datum) const;
    void IspisiSveProdaje() const;
    Prodaje& DajProdaju(int index);
    Prodaja **begin() const { return sveprodaje; }
    Prodaja **end() const { return sveprodaje + max_broj_prodaja; }
    /*U klasu "Prodaje" potrebno je dodati novu metodu "DajProdaju" koja
  kao parametar prima redni broj prodaje, a vraća referencu na
  odgovarajuću prodaju pohranjenu unutar klase (na taj način se
  omogućava izmjena individualnih prodaja). U slučaju da redni broj
  prodaje nije ispravan, treba baciti izuzetak po volji (neće se
  testirati).*/
};
        Prodaje::~Prodaje(){
            for (int i=0; i<broj_prodaja; i++) delete sveprodaje[i];
            delete[] sveprodaje;
        }
        Prodaje::Prodaje(const std::initializer_list<Prodaja> spisak_prodaja) : broj_prodaja(spisak_prodaja.size()),
    max_broj_prodaja(spisak_prodaja.size()), sveprodaje(nullptr) {
    int brojac(0);
    try {
        for(const auto &x : spisak_prodaja)
            sveprodaje[brojac] = new Prodaja(x);
            brojac++;
    }
    catch(...) {
        for (int i=0; i<broj_prodaja; i++) delete sveprodaje[i];
            delete[] sveprodaje;
        throw; // prosljedjujemo izuzetak ..
    }
}
        Prodaje::Prodaje(const Prodaje & prodaje):  max_broj_prodaja(prodaje.max_broj_prodaja), sveprodaje(new Prodaja*[prodaje.max_broj_prodaja]{}), broj_prodaja(prodaje.broj_prodaja){
            try{
                for (int i=0; i<prodaje.broj_prodaja; i++) sveprodaje[i]=new Prodaja(*prodaje.sveprodaje[i]);
            }
            catch(...){
                for (int i=0; i<prodaje.broj_prodaja; i++) delete sveprodaje[i];
            delete[] sveprodaje; throw;
            }
        }
        void Prodaje::RegistrirajProdaju(const std::string & ime_agenta_prodaje, double cijena_stana, const Datum & datum_prodaje, const Kupac & kupac_stana, const Stan & kupljeni_stan){
            if (broj_prodaja>=max_broj_prodaja) throw std::range_error("Dostignut maksimalni broj prodaja!");
            Prodaja s(ime_agenta_prodaje, cijena_stana, datum_prodaje, kupac_stana, kupljeni_stan);
            sveprodaje[broj_prodaja++]=&s;
        }
        
        void Prodaje::RegistrirajProdaju(const std::string & ime_agenta_prodaje,double cijena_stana, int dan_prodaje,int mjesec_prodaje, int godina_prodaje, std::string & ime_kupca,const Datum & datum_rodjenja_kupca, const std::string & adresa_stana,int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata){
        if (broj_prodaja>=max_broj_prodaja) throw std::range_error("Dostignut maksimalni broj prodaja!");
            Datum d(dan_prodaje,mjesec_prodaje, godina_prodaje);
            Kupac kupac(ime_kupca, datum_rodjenja_kupca);
            Stan stan(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata);
            Prodaja s(ime_agenta_prodaje, cijena_stana, d, kupac, stan);
            sveprodaje[broj_prodaja++]=&s;
        }
        
        void Prodaje::RegistrirajProdaju(Prodaja *prodaja){
            if (broj_prodaja>=max_broj_prodaja) throw std::range_error("Dostignut maksimalni broj prodaja!");
            sveprodaje[broj_prodaja++]=prodaja;
        }
        
         /*Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja): max_broj_prodaja(spisak_prodaja.size()), sveprodaje(new Prodaja*[spisak_prodaja.size()]{}) {
             try{
                while (spisak_prodaja.begin()!=spisak_prodaja.end()) {sveprodaje[i]=new Prodaja(spisak_prodaja.sveprodaje[i]);}
                }
                catch(...){
                    for (int i=spisak_prodaja.begin(); i<spisak_prodaja.end(); i++) delete sveprodaje[i];
                    delete[] sveprodaje; throw;
                }
        }*/

        Prodaje &Prodaje::operator =(const Prodaje & prodaje){
            if (prodaje.max_broj_prodaja!=max_broj_prodaja)throw std::range_error("Dostignut maksimalni broj prodaja");
            if (prodaje.broj_prodaja>broj_prodaja){
                try{
                    for (int i=broj_prodaja; i<prodaje.broj_prodaja; i++) sveprodaje[i]=new Prodaja(*prodaje.sveprodaje[i]);
                 }
                catch(...){
                    for(int i = broj_prodaja; i < prodaje.broj_prodaja; i++) {
                    delete sveprodaje[i]; sveprodaje[i] = nullptr;
                    } 
                throw;
                }
            }
            else {
                for(int i = broj_prodaja; i < prodaje.broj_prodaja; i++) {delete sveprodaje[i]; sveprodaje[i]=nullptr;}
            }
            broj_prodaja=prodaje.broj_prodaja;
            for (int i=0; i<broj_prodaja; i++) *sveprodaje[i]=*prodaje.sveprodaje[i];
            return *this;
        }
        
        Prodaje &Prodaje::operator =(Prodaje && prodaje){
            if (prodaje.max_broj_prodaja!=max_broj_prodaja) throw std::range_error("Dostignut maksimalni broj prodaja");
            std::swap(broj_prodaja, prodaje.broj_prodaja);
            std::swap(sveprodaje, prodaje.sveprodaje);
            return *this;
        }
        
        int Prodaje::DajBrojProdajaNaDatum(const Datum & datum) const{
            int broj=0;
            for (int i=0; i<broj_prodaja; i++){
                Datum d=sveprodaje[i]->DajDatumProdaje();
                if(d.DajDan()==datum.DajDan() && d.DajMjesec()==datum.DajMjesec() && d.DajGodinu()==datum.DajGodinu()) broj++;
            }
            return broj;
        }
        
        int Prodaje::DajBrojProdajaOdAgenta(const std::string & ime_agenta) const{
            int broj=0;
            for (int i=0; i<broj_prodaja; i++){
                std::string a=sveprodaje[i]->DajImeAgenta();
                if(a==ime_agenta) broj++;
            }
            return broj;
        }
        
        Prodaja& Prodaje::DajNajranijuProdaju(){
            min_element(sveprodaje,sveprodaje+broj_prodaja ,[](std::shared_ptr<Prodaja> t1,std::shared_ptr<Prodaja> t2){
                Datum d=t1->DajDatumProdaje();
                Datum d2=t2->DajDatumProdaje();
                return(ProdatPrije(d,d2));
            }
            } );
        }
        Prodaja Prodaje::DajNajranijuProdaju() const{
             min_element(sveprodaje ,sveprodaje+broj_prodaja ,[](std::shared_ptr<Prodaja> t1,std::shared_ptr<Prodaja> t2){
                Datum d=t1->DajDatumProdaje();
                Datum d2=t2->DajDatumProdaje();
                return(ProdatPrije(d,d2));
            }
            } );
        }
        Prodaja& Prodaje::DajNajskupljuProdaju(){
             min_element(sveprodaje ,sveprodaje+broj_prodaja ,[](std::shared_ptr<Trougao> t1,std::shared_ptr<Trougao> t2){
                double d=t1->DajCijenuStana();
                double d2=t2->DajCijenuStana();
                return(SkupljiStan(d,d2));
            }
            } );
        }
        Prodaja Prodaje::DajNajskupljuProdaju() const{
            min_element(sveprodaje ,sveprodaje+broj_prodaja ,[](std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2){
                double d=t1->DajCijenuStana();
                double d2=t2->DajCijenuStana();
                return(SkupljiStan(d,d2));
            }
            } );
        }
        
        void Prodaje::ObrisiNajranijuProdaju();*/
        void Prodaje::ObrisiProdajeAgenta(const std::string & ime_agenta){
            for (int i=0; i<broj_prodaja; i++){
                std::string a=sveprodaje[i]->DajImeAgenta();
                if(a==ime_agenta) {delete sveprodaje[i]; sveprodaje[i] = nullptr;}
            }
        }
        void Prodaje::ObrisiProdajeNaDatum(const Datum & datum){
            for (int i=0; i<broj_prodaja; i++){
                Datum d=sveprodaje[i]->DajDatumProdaje();
                if(d.DajDan()==datum.DajDan() && d.DajMjesec()==datum.DajMjesec() && d.DajGodinu()==datum.DajGodinu()) {delete sveprodaje[i]; sveprodaje[i] = nullptr;}
            }
        }
int main ()
{
    try{
    Datum d(15, 5, 1996);
    Kupac k("NIKO NIKIC",d );
    k.Ispisi();
    cout<<endl;
    Stan s("Antuna hangija 9", 2, 5, true, 71.25 );
    s.Ispisi();
    Datum d2(06,10,2017);
    Prodaja p("N",750000, d2, k, s );
    p.PomjeriDanUnazad();
    p.Ispisi();
    }
    catch (std::domain_error x){
        cout<<x.what();
    }
	return 0;
}