/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>
#include <cstring>
#include <vector>

class Datum{
    int dan,mjesec,godina;
    
    bool Ispravnost_Datuma(int &d,int &m,int &g){
        int broj_dana[]{31,28,31,30,31,30,31,31,30,31,30,31};
            if((g%4==0 && g%100!=0) || g%400==0)
            broj_dana[1]++;
        if(g<1 || m<1 || m>12 || d<1 || d>broj_dana[m-1]) return false;
    return true;
    }
    public:
    Datum (int dan,int mjesec,int godina){
        if(Ispravnost_Datuma(dan,mjesec,godina)==false) throw std::domain_error("Neispravan datum");
        Datum::dan=dan;
        Datum::mjesec=mjesec;
        Datum::godina=godina;
    }
    void Postavi(int dan,int mjesec,int godina){
        if(Ispravnost_Datuma(dan,mjesec,godina)==false) throw std::domain_error("Neispravan datum"); Datum::dan=dan;
        Datum::mjesec=mjesec;
        Datum::godina=godina;
    }
    int DajDan() const {return dan;}
    int DajMjesec() const{return mjesec;}
    int DajGodinu() const{return godina;}
    void Ispisi() const{
        std::cout<<dan<<"/"<<mjesec<<"/"<<godina;
    }
};

class Kupac{
    std::string ime_i_prezime;
    Datum datum_rodj;
    
    bool Ispravnost_Imena(std::string s){
         for(int i(0); i<s.length(); i++)
            if((s[i]>='0' && s[i]<='9') || (s[i]>='A' && s[i]<='z') || s[i]==' ' || s[i]=='-' || s[i]=='"') return true;
            return false;
    }
    public:
    Kupac (const std::string &ime_i_prezime,const Datum &datum_rodjenja) : datum_rodj(Datum(datum_rodjenja)){
        if(Ispravnost_Imena(ime_i_prezime)==false) throw std::domain_error("Neispravno ime i prezime");
        Kupac::ime_i_prezime=ime_i_prezime;
        
    }
    void Postavi(const std::string &ime_i_prezime,const Datum &datum_rodjenja){
        if(Ispravnost_Imena(ime_i_prezime)==false) throw std::domain_error("Neispravno ime i prezime");
        Kupac::ime_i_prezime=ime_i_prezime;Kupac::datum_rodj=datum_rodjenja;
    }
    std::string DajImePrezime () const{return ime_i_prezime;}
    Datum DajDatumRodjenja () const{return datum_rodj;}
    void Ispisi() const{
        std::cout<<ime_i_prezime<<" ("<<datum_rodj.DajDan()<<"/"<<datum_rodj.DajMjesec()<<"/"<<datum_rodj.DajGodinu()<<")";
    }
};



class Stan {
    std::string adresa;
    int sprat,broj_soba;
    bool namjesten;
    double kvadratura;
    
    public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
        if(sprat<0 || broj_soba<0 || kvadratura<0) throw std::domain_error("Neispravan unos podataka");
        Stan::adresa=adresa;
        Stan::sprat=sprat;
        Stan::broj_soba=broj_soba;
        Stan::namjesten=namjesten;
        Stan::kvadratura=kvadratura;
    }
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
        if(sprat<0 || broj_soba<0 || kvadratura<0) throw std::domain_error("Neispravan unos podataka");
        Stan::adresa=adresa;
        Stan::sprat=sprat;
        Stan::broj_soba=broj_soba;
        Stan::namjesten=namjesten;
        Stan::kvadratura=kvadratura;
    }
    
    std::string DajAdresu() const{return adresa;}
    int DajSprat() const{return sprat;}
    int DajBrojSoba() const{return broj_soba;}
    bool DajNamjesten() const{return namjesten;}
    double DajKvadraturu() const{return kvadratura;}
    void Ispisi() const{
        std::cout<<"Stan se nalazi na adresi "<<adresa<<" na "<<sprat<<". spratu i ima "<<broj_soba;
        if(broj_soba%10==1) std::cout<<" sobu.";
        if(broj_soba%10==2 || broj_soba%10==3 ||broj_soba%10==4) std::cout<<" sobe.";
        else std::cout<<" soba.";
        std::cout<<std::endl<<"Kvadratura stana je "<<kvadratura<<" (m^2) i stan ";
        if(namjesten==false) std::cout<<"nije namjesten.";
        else std::cout<<"je namjesten.";
    }
};


class Prodaja {
    std::string ime_agenta_prodaje,ime_kupca,adresa_stana;
    double cijena_stana;
    Datum dat_prodaje,datum_rodjenja_kupca;
    Stan kup_stan;
    Kupac kupac_st;
    int dan_prodaje,mjesec_prodaje,godina_prodaje,broj_soba,broj_stana,broj_kvadrata;
    bool namjesten_stan;
    
    public:
    explicit Prodaja(const std::string &ime_agenta_prodaje,double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, 
            const Stan &kupljeni_stan) : dat_prodaje(Datum(datum_prodaje)), datum_rodjenja_kupca(Datum(1,1,1970)),kupac_st(Kupac(kupac_stana)), kup_stan(Stan(kupljeni_stan)){
        Prodaja::ime_agenta_prodaje=ime_agenta_prodaje;
        Prodaja::cijena_stana=cijena_stana;
    }
    explicit Prodaja(const std::string &ime_agenta_prodaje,double cijena_stana,int dan_prodaje,int mjesec_prodaje,int godina_prodaje,std::string &ime_kupca, 
            const Datum &datum_rodjenja_kupca,const std::string &adresa_stana,int broj_stana,int broj_soba,bool namjesten_stan, 
            double broj_kvadrata) : dat_prodaje(Datum(dan_prodaje,mjesec_prodaje,godina_prodaje)),datum_rodjenja_kupca(Datum(datum_rodjenja_kupca)),
                                    kup_stan(Stan(adresa_stana,broj_stana,broj_soba,namjesten_stan,broj_kvadrata)),kupac_st(Kupac(ime_kupca,datum_rodjenja_kupca)){
                Prodaja::ime_agenta_prodaje=ime_agenta_prodaje;
                Prodaja::cijena_stana=cijena_stana;
                Prodaja::dan_prodaje=dan_prodaje;
                Prodaja::mjesec_prodaje=mjesec_prodaje;
                Prodaja::godina_prodaje=godina_prodaje;
                Prodaja::ime_kupca=ime_kupca;
                Prodaja::adresa_stana=adresa_stana;
                Prodaja::broj_stana=broj_stana;
                Prodaja::broj_soba=broj_soba;
                Prodaja::namjesten_stan=namjesten_stan;
                Prodaja::broj_kvadrata=broj_kvadrata;
            }
    void PromijeniKupca(const Kupac &novi_kupac) {
      Prodaja::kupac_st=Kupac(novi_kupac);
  };
    void PromijeniStan(const Stan &novi_stan){
        Prodaja::kup_stan=novi_stan;
    } 
    void PromijeniDatumKupovine(const Datum &novi_datum){
        Prodaja::dat_prodaje=novi_datum;
    } 
    void PromijeniCijenuProdaje(const double &nova_cijena){
        Prodaja::cijena_stana=nova_cijena;
    }
    void PomjeriDanUnaprijed(){dan_prodaje++;}
    void PomjeriDanUnazad(){dan_prodaje--;}
    std::string DajImeAgenta() const {return ime_agenta_prodaje;}
    std::string DajImeKupca() const{return ime_kupca;}
    Datum DajDatumProdaje() const{return dat_prodaje;}
    double DajCijenuStana() const{return cijena_stana;}
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);    
    void Ispisi() const{
            std::cout<<"Ime agenta:"<<DajImeAgenta()<<std::endl<<"Ime kupca:"<<DajImeKupca();
            std::cout<<"Zakazani datum prodaje: "; DajDatumProdaje().Ispisi(); std::cout<<"Cijena stana:"<<DajCijenuStana();
            std::cout<<"Informacije o stanu:"<<std::endl;
            kup_stan.Ispisi();
        }
};

bool ProdatPrije(const Prodaja &p1, const Prodaja &p2){
    if(p1.DajDatumProdaje().DajGodinu()<p2.DajDatumProdaje().DajGodinu()) return true;
    return false;
}

bool SkupljiStan(const Prodaja &p1, const Prodaja &p2){
    if(p1.DajCijenuStana()<p2.DajCijenuStana()) return true;
    return false;
}

/*
class Prodaje{
    std::string ime_agenta_prodaje,ime_kupca,adresa_stana;
    double cijena_stana;
    Datum dat_prodaje,datum_r_kupca;
    Stan kup_stan;
    Kupac kupac_st;
    int dan_prodaje,mjesec_prodaje,godina_prodaje,broj_soba,broj_stana,broj_kvadrata;
    bool namjesten_stan;
    Prodaja** _prodaje;
    const int max_prodaja;
    int broj_prodaja;
    
    bool Raniji(const Datum &d1, const Datum &d2){
        if(d1.DajGodinu()<d2.DajGodinu()) return true;
        else if (d1.DajGodinu()==d2.DajGodinu()){
            if(d1.DajMjesec()<d2.DajMjesec()) return true;
                else if(d1.DajMjesec()==d2.DajMjesec()){
                    if(d1.DajDan()<d2.DajDan()) return true;
                }
        }
    return false;
    }
    
    public:
    explicit Prodaje(int max_broj_prodaja) : _prodaje(nullptr), max_broj_prodaja(max_prodaja),broj_prodaja(0) {
        try{
            _prodaje=new Prodaja*[max_prodaja];
            for(int i(0); i<max_prodaja; i++) _prodaje[i]=nullptr;
        }
    
        catch(...){
            if(_prodaje!=nullptr){
                for(int i(0);i<max_broj_prodaja;i++) delete _prodaje[i];
                delete [] _prodaje;
            }
            else delete [] _prodaje;
        }
    }
    
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja) : max_prodaja(spisak_prodaja.size()) {
        try{
            _prodaje = new Prodaja*[max_prodaja];
            for(int i(0); i<max_prodaja; i++)
                _prodaje[i]=nullptr;
                _prodaje[i]=new Prodaja(spisak_prodaja()[i]);
                broj_prodaja=max_prodaja;
        }
        catch(...){
            if(_prodaje!=nullptr){
                for(int i(0);i<max_broj_prodaja;i++) delete _prodaje[i];
                delete [] _prodaje;
            }
            else delete [] _prodaje;
        }
    }
    
    ~Prodaje() {
        for(int i=0; i<max_broj_prodaja; i++) delete _prodaje[i] ;
        delete [] _prodaje;
    }
    
    Prodaje(const Prodaje &prodaje) : max_prodaja(prodaje.max_prodaja){
        broj_prodaja=prodaje.broj_prodaja;
        try{
            _prodaje=new Prodaja*[max_prodaja];
            for(int i(0); i<max_prodaja;i++){
                _prodaje[i]=nullptr;
                _prodaje[i]=new Prodaja(prodaje._prodaje[i]->DajImeKupca());
                *(_prodaje[i])=*(prodaje._prodaje[i]);
            }
        }
        catch(...){
            if(_prodaje!=nullptr){
                for(int i(0);i<max_broj_prodaja;i++) delete _prodaje[i];
                delete [] _prodaje;
            }
            else delete [] _prodaje;
        }
    }
    
    Prodaje (Prodaje &&prodaje) : max_prodaja(prodaje.max_prodaja){
        
        broj_prodaja=prodaje.broj_prodaja;
        _prodaje=prodaje._prodaje;
        prodaje._prodaje=nullptr;
        
    }
    
    Prodaje &operator =(const Prodaje &prodaje){
        broj_prodaja=prodaje.broj_prodaja;
        for(int i(0); i<max_prodaja; i++) delete _prodaje[i];
        delete [] _prodaje;
        
         try{
            _prodaje=new Prodaja*[max_prodaja];
            for(int i(0); i<max_prodaja;i++){
                _prodaje[i]=nullptr;
                _prodaje[i]=new Prodaja(prodaje._prodaje[i]->DajImeKupca());
                *(_prodaje[i])=*(prodaje._prodaje[i]);
            }
        }
        catch(...){
            if(_prodaje!=nullptr){
                for(int i(0);i<max_broj_prodaja;i++) delete _prodaje[i];
                delete [] _prodaje;
            }
            else delete [] _prodaje;
        }
    }
    
    Prodaje &operator =(Prodaje &&prodaje){
        
        std::swap(broj_prodaja,prodaje.broj_prodaja);
        std::swap(_prodaje,prodaje._prodaje);
        return *this;
    }
    
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana,const Datum &datum_prodaje, 
                            const Kupac &kupac_stana, const Stan &kupljeni_stan){
                                
        
        bool hehe1(false),hehe2(false); 
        int p1,p2;
        for(int i(0); i<broj_prodaja; i++){
            
            if(std::strcmp(_prodaje[i]->DajImeAgenta(),ime_agenta_prodaje)==0)
            {
                hehe1=true;
                p1=i;
            }
            
            if(std::strcmp(_prodaje[i]->DajImeKupca(),kupac_stana)==0)
            {
                hehe2=true;
                p2=i;
            }
        }
                  
            _prodaje[p1]->    
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
                                
                            }
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
                            
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje,int dan_prodaje,int mjesec_prodaje,int godina_prodaje,std::string &ime_kupca,
                            const Datum &datum_rodjenja_kupca,const std::string &adresa_stana,int sprat_stana,int broj_soba,bool namjesten_stan,
                            double broj_kvadrata) : datum_r_kupca(Datum(datum_rodjenja_kupca)){
                Prodaje::ime_agenta_prodaje=ime_agenta_prodaje;
                Prodaje::dan_prodaje=dan_prodaje;
                Prodaje::mjesec_prodaje=mjesec_prodaje;
                Prodaje::godina_prodaje=godina_prodaje;
                Prodaje::ime_kupca=ime_kupca;
                Prodaje::adresa_stana=adresa_stana;
                Prodaje::sprat_stana=sprat_stana;
                Prodaje::broj_soba=broj_soba;
                Prodaje::namjesten_stan=namjesten_stan;
                Prodaje::broj_kvadrata=broj_kvadrata;
                }
                        
    void RegistrirajProdaju(Prodaja *prodaja);
    int DajBrojProdaja () const{return broj_prodaja;}
    int DajBrojProdajaNaDatum(const Datum &datum) const{
        for(int i=0; i<DajBrojProdaja();i++){
            if(_prodaje[i].prodaja.DajDatumProdaje()==datum)
                return prodaje[i].DajBrojProdaja();
        }
    int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const{
        for(int i=0; i<DajBrojProdaja();i++){
            if(_prodaje[i].prodaja.DajImeAgenta()==ime_agenta)
            return prodaje[i].DajBrojProdaja();
        }
    }
    
    Prodaja &DajNajranijuProdaju(){
       // std::sort()
        return *std::min(prodaje,prodaje+broj_prodaja,Raniji(prodaje.DajDatumProdaje(),(prodaje+broj_prodaja).DajDatumProdaje()));
    }
    Prodaja DajNajranijuProdaju() const{
        return *std::min(prodaje,prodaje+broj_prodaja,);
    }
    Prodaja &DajNajskupljuProdaju(){
        return *std::max(prodaje,prodaje+broj_prodaja,cijena_stana);
    }
    Prodaja DajNajskupljuProdaju() const{
        return *std::max(prodaje,prodaje+broj_prodaja,cijena_stana);
    }
    void IsprazniKolekciju(){
        for(int i(0); i<DajBrojProdaja(); i++) delete _prodaje[i];
        delete [] _prodaje;
    }
    void ObrisiNajranijuProdaju() {
        delete prodaja.DajNajranijuProdaju;
    }
    void ObrisiAgentaProdaje(const std::string &ime_agenta){
        for(int i=0; i<DajBrojProdaja();i++){
            if(_prodaje[i].prodaja.DajImeAgenta()==ime_agenta)
            delete prodaja.DajImeAgenta();//ime_agenta_prodaje;
        }
    }
    void ObrisiProdajeNaDatum(const Datum &datum){
        for(int i=0; i<DajBrojProdaja();i++){
        if(_prodaje[i].prodaja.DajDatumProdaje()==datum){
          //  delete 
        }
    }
    void IspisiProdajeNaDatum(const Datum &datum) const;
    void IspisiSveProdaje() const;
    }}
};*/

int main ()
{   
    std::string adresa;
    int sprat,broj_soba,namjestenost;
    double kvadratura;
   // Kupac s;
    std::vector<Kupac> k;
    try{
    std::cout<<"Dobrodosli!\n\n\nIzaberite opciju: \n0 - kraj\n1 - uredjivanje stanova\n2 - uredjivanje kupaca\n3 - uredjivanje prodaja\n";
    int n;
    std::cin>>n;
    switch(n){
        case 0 : std::cout<<"Dovidjenja!"; return 0;
        case 1 : {std::cout<<std::endl<<"Izaberite opciju: \n0 - nazad\n1 - dodavanje stana\n2 - uredjivanje stanova\n3 - ispis svih stanova\n4 - kraj\n";
                int n1;
                std::cin>>n1;
                switch(n1){
                    case 0: //idi nazad;
                    case 1: {
                            try{
                            std::cin.ignore();
                            std::cout<<"Unesite adresu: ";
                            std::getline(std::cin,adresa);
                            std::cout<<"Unesite sprat: ";
                            std::cin>>sprat;
                            std::cout<<"Unesite broj soba: ";
                            std::cin>>broj_soba;
                            std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                            std::cin>>namjestenost;
                            std::cout<<"Unesite kvadraturu: ";
                            std::cin>>kvadratura;
                            Stan s(adresa,sprat,broj_soba,namjestenost,kvadratura);
                            
                            } catch(std::domain_error e){
                                std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet.";
                            }
                            std::cout<<"Stan je uspjesno dodan!";
                            break;
                    }
                    case 2: {
                        std::cout<<"Odaberite stan. Dostupni stanovi su:\n";
                        break;
                    }
                    case 3: {
                        
                        //ispis svih stanova
                        break;
                    }
                    break;
                }}
            case 2: {
                std::cout<<"Izaberite opciju:\n0 - nazad\1 - dodavanje kupca\n2 - uredjivanje kupaca\n3 - ispis svih kupaca\n4 - kraj";
                    case 0:
                    case 1: {
                        std::string ime;
                        int dd,mm,gggg;
                        
                        std::cout<<"Unesite ime i prezime kupca: ";
                        std::cin.ignore(10000,'\n');
                        std::getline(std::cin,ime);
                        std::cout<<"Unesite datum rodjenja (formata d/m/g): ";
                        std::cin>>dd>>mm>>gggg;
                        try{
                            Datum d(dd,mm,gggg);
                            Kupac s(ime,d);
                            
                    }
                    catch(std::domain_error e){
                        std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet";
                    }
                    k.push_back(s);
                    std::cout<<"Kupac je uspjesno dodan!";
                    break;
                    }
                    case 2: { 
                            for(int i(0);i<k.size();i++){
                                k[i].Ispisi();
                                }
                                std::cout<<std::endl;
                                break;}
                    case 3:{
                    std::cout << "Odaberite kupca kojeg zelite urediti. Dostupni kupci su:\n";
                        for(int i(0);i<k.size();i++){
                            std::cout<<i+1<< " - ";
                            k[i].Ispisi();
                                }
                                std::cout<<std::endl;
                                int nn;
                        std::cin>>nn;
                        for(int i(0);i<k.size();i++){
                        if(i==nn){
                        std::cout<<"Unesite ime i prezime kupca: ";
                        int dd,mm,gggg;
                        std::string ime;
                        std::cin.ignore(10000,'\n');
                        std::getline(std::cin,ime);
                        std::cout<<"Unesite datum rodjenja (formata d/m/g): ";
                        std::cin>>dd>>mm>>gggg;
                        try{
                            Datum d(dd,mm,gggg);
                            Kupac s(ime,d);
                            
                    }
                    catch(std::domain_error e){
                        std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet";
                    }
                    //k.push_back(s);
                    std::cout<<"Kupac je uspjesno dodan!";
                        }}
                    case 4: break;
                }}
    }}
        
        
        
        
        
        
    
    
    

catch(std::domain_error e){
    std::cout<<e.what();
}
	return 0;
}