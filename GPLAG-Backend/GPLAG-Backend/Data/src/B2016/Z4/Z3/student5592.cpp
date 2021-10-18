/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <string>
#include <iomanip>
#include <initializer_list>
#include <algorithm>
#include <vector>



class Datum{
    
    int dan,mjesec,godina;
    int BrojDana(int mjesec, int godina);
    
    public:
    
    Datum (int dan, int mjesec, int godina){
        Postavi(dan,mjesec,godina);
        
    }
    
    void Postavi(int dan, int mjesec, int godina);
    int DajDan() const { return dan;}
    int DajMjesec() const{ return mjesec; }
    int DajGodinu() const{ return godina; }
    void Ispisi() const { std::cout<< dan <<"/"<< mjesec <<"/"<< godina; }
};

class Kupac {
    
    std::string ime;
    Datum dat;
    
    public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja) : dat(datum_rodjenja){ Postavi(ime_i_prezime,datum_rodjenja); }
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    std::string DajImePrezime() const { return ime; }
    Datum DajDatumRodjenja() const { return dat; }
    void Ispisi() const;
};

class Stan {
    
    std::string adr;
    int sp;
    int br;
    bool namj;
    double kv;
    
    public:
    
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){ Postavi(adresa,sprat,broj_soba,namjesten,kvadratura); }
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
    
    std::string DajAdresu() const { return adr; }
    int DajSprat() const { return sp; }
    int DajBrojSoba() const {return br; }
    bool DajNamjesten() const { return namj;}
    double DajKvadraturu() const { return kv; }
    
    void Ispisi() const; 
    
};

class Prodaja {
    
    std::string imeag;
    double cijena;
    Datum dat;
    Kupac k;
    Stan s;
    int BrojDana(int mjesec,int godina);
    
    public:
    
    Prodaja( const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje,
            const Kupac &kupac_stana, const Stan &kupljeni_stan);
    Prodaja (const std::string &ime_agenta_prodaje, double cijena_stana,int dan_prodaje,
            int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum
            &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba,
            bool namjesten_stan, double broj_kvadrata);
            
    void PromijeniKupca(const Kupac &novi_kupac){ k=novi_kupac;}
    void PromijeniStan(const Stan &novi_stan) {s=novi_stan;}
    void PromijeniDatumKupovine(const Datum &novi_datum) { dat=novi_datum;}
    void PromijeniCijenuProdaje(const double &nova_cijena) {cijena=nova_cijena;}
    
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    
    std::string DajImeAgenta() const { return imeag;}
    std::string DajImeKupca() const { return k.DajImePrezime(); }
    Datum DajDatumProdaje() const { return dat; }
    double DajCijenuStana() const { return cijena; }
    
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2){
        if (p1.DajCijenuStana()>p2.DajCijenuStana()) return true;
        else return false;
    }
    
    void Ispisi() const;
    
    
    
    
};


class Prodaje {
    
    Prodaja ** niz=nullptr;
    int maks_prodaja, broj_prodaja;
    
    public: 
    
    explicit Prodaje (int max_broj_prodaja);
    
    Prodaje (std::initializer_list<Prodaja> spisak_prodaja);
       
    ~Prodaje();
    
    Prodaje (const Prodaje &prodaje);
    Prodaje (Prodaje &&prodaje);
    Prodaje &operator=(const Prodaje &prodaje);
    Prodaje &operator=(Prodaje &&prodaje);
    
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana,const Datum
                            &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana, int dan_prodaje, int mjesec_prodaje,
                            int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca,
                            const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan,double broj_kvadrata);
    void RegistrirajProdaju(Prodaja *prodaja);
    
    
    Prodaja &DajProdaju(int redni_broj_prodaje);
    int DajBrojProdaja() const { return broj_prodaja; }
    int DajBrojProdajaNaDatum (const Datum &datum) const;
    int DajBrojProdajaOdAgenta (const std::string &ime_agenta) const;
    Prodaja &DajNajranijuProdaju();
    Prodaja DajNajranijuProdaju() const;
    Prodaja &DajNajskupljuProdajU();
    Prodaja DajNajskupljuProdajU() const;
    
    
    Prodaja **begin() const { return niz; }
    Prodaja **end() const { return niz+broj_prodaja; }
    
    void IsprazniKolekciju();
    void ObrisiNajranijuProdaju();
    void ObrisiProdajeAgenta(const std::string &ime_agenta);
    void ObrisiProdajeNaDatum (const Datum &datum);
    
    void IspisiProdajeNaDatum (const Datum &datum) const;
    void IspisiSveProdaje() const;
};



Stan NapraviStan(){
    
    std::cout<<"Unesite adresu: ";
    std::cin.ignore(1000,'\n');
    std::cin.clear();
    std::string ad;
    getline(std::cin,ad);
    
    std::cout<<"Unesite sprat: ";
    int sprat,broj,e1;
    std::cin>>sprat;
    
    std::cout<<"Unesite broj soba: ";
    std::cin>>broj;
    
    std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
    std::cin>>e1;
    
    std::cout<<"Unesite kvadraturu: ";
    double kvad;
    std::cin>>kvad;
    
    bool e;
    if(e1==0 || e1==1) e=e1;
    else throw std::domain_error  ("Neispravan unos podataka.");
  
    
    Stan s(ad,sprat,broj,e,kvad);
    
    return s;
    
}

int main ()
{
    int a,b,c,d,e,f,e1;
    std::string ad;
    int s,bs;
    bool n;
    double kv;
    std::vector<std::string> i {"Unesite ime i prezime agenta prodaje: ","Unesite datum prodaje (formata d/m/g): ","Unesite cijenu stana: ","Unesite ime kupca: ", "Unesite datum rodjenja kupca (formata d/m/g): ", "Unesite adresu: ","Unesite sprat: ",
                                "Unesite broj soba: ", "Da li je stan namjesten (1 - da, 0 - ne): ", "Unesite kvadraturu: "};
    std::vector<Stan> v;
    std::vector<Kupac> k;
    Prodaje p(20);
    
    std::cout<<"Dobrodosli!"<<std::endl<<std::endl<<std::endl;
    
    for(;;){
    std::cout<<"Izaberite opciju:"<<std::endl<<" 0 - kraj"<<std::endl<<" 1 - uredjivanje stanova"<<std::endl<<" 2 - uredjivanje kupaca"<<std::endl<<" 3 - uredjivanje prodaja"<<std::endl;
    
    std::cin>>a;
    
    
    if(a==0) break;
    
    if(a==1){
        
        for(;;){
      std::cout<<"Izaberite opciju:"<<std::endl<<" 0 - nazad"<<std::endl<<" 1 - dodavanje stana"<<std::endl<<" 2 - uredjivanje stanova"<<
                        std::endl<<" 3 - ispis svih stanova"<<std::endl<<" 4 - kraj"<<std::endl;
        
        std::cin>>b;
        
        if (b==0) break;
        if (b==1){
            
    
            for(;;){
                try{
            
            std::cin.ignore(1000,'\n');
            std::cin.clear();
            
            std::cout<<"Unesite adresu: ";
            getline(std::cin,ad);
            
            std::cout<<"Unesite sprat: ";
            std::cin>>s;
            
            std::cout<<"Unesite broj soba: ";
            std::cin>>bs;
            
            std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
            std::cin>>e1;
            
            std::cout<<"Unesite kvadraturu: ";
            std::cin>>kv;
            
            if(e1==0 || e1==1) n=e1;
            
            else throw std::domain_error("Neispravan unos podataka");
        
        
        
        
            
            Stan stan(ad,s,bs,n,kv);
            
            v.push_back(stan);
            
            std::cout<<"Stan je uspjesno dodan!"<<std::endl;
            std::cout<<std::endl;
            
            break;
        }
        
        catch(std::domain_error e){ std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;}
        
        }
        }
        
        
        else if(b==3){
            
            for(int i(0);i<v.size();i++){
                std::cout<<i+1<<". ";
                v[i].Ispisi();
            }
            std::cout<<std::endl;
        }
        
        else if(b==2){
            std::cout<<"Odaberite stan. Dostupni stanovi su:"<<std::endl;
            
            for(int i(0);i<v.size();i++){
                std::cout<<" "<<i+1<<" - ";
                v[i].Ispisi();
            }
            
            
            std::cin>>c;
            std::cout<<std::endl;
         
                        std::cout<<"Odaberite polje koje zelite urediti:"<<std::endl;
                        std::cout<<" 0 - nazad"<<std::endl<<" 1 - adresa"<<std::endl<<" 2 - sprat"<<std::endl<<" 3 - broj soba"
                                 <<std::endl<<" 4 - da li je stan namjesten"<<std::endl<<" 5 - kvadratura"<<std::endl<<" 6 - sve"<<std::endl;
                        
                        for(int i(0);i<v.size();i++){
                            
                        if (c==i+1){        
                        std::cin>>d;
                        
                        if(d==0) break;
                        
                        else if(d==2){
                            for(;;){
                                std::cout<<"Unesite sprat: ";
                                int novis(0);
                                std::cin>>novis;
                                
                                try{
                                        v[i].Postavi(ad,novis,bs,n,kv);
                                        std::cout<<"Stan je uspjesno izmijenjen!"<<std::endl<<std::endl;
                                        break;
                                }
                                
                                catch(std::domain_error e) {std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet. "<<std::endl; }
                            }
                        }
                        
                        else if(d==3){
                            for(;;){
                                std::cout<<"Unesite broj soba: ";
                                int novas(0);
                                std::cin>>novas;
                                
                                try{
                                        v[i].Postavi(ad,s,novas,n,kv);
                                        std::cout<<"Stan je uspjesno izmijenjen!"<<std::endl<<std::endl;
                                        break;
                                }
                                
                                catch(std::domain_error e){ std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;}
                            }
                        }
                        
                        else if(d==4){
                            for(;;){
                                std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                                 bool m;
                                 std::cin>>m;
                                
                                try{
                                        v[i].Postavi(ad,s,bs,m,kv);
                                        std::cout<<"Stan je uspjesno izmijenjen!"<<std::endl<<std::endl;
                                        break;
                                }
                                
                                catch(std::domain_error e) { std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;}
                            }
                        }
                        
                        else if(d==5){
                            for(;;){
                                std::cout<<"Unesite kvadraturu: ";
                                double kvad;
                                std::cin>>kvad;
                                try{
                                        v[i].Postavi(v[i].DajAdresu(),v[i].DajSprat(),v[i].DajBrojSoba(),v[i].DajNamjesten(),kvad);
                                        std::cout<<"Stan je uspjesno izmijenjen!"<<std::endl<<std::endl;
                                        break;
                                }
                                catch(std::domain_error e) {std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                            }
                        }
                        
                        } 
                        
                        
                        else if(d==6){
                            for(;;){
                                std::cout<<"Unesite adresu: ";
                                std::cin.ignore(1000,'\n');
                                std::cin.clear();
                                std::string s;
                                getline(std::cin,s);
                                
                                std::cout<<"Unesite sprat: ";
                                int spr;
                                std::cin>>spr;
                                
                                std::cout<<"Unesite broj soba: ";
                                int brs;
                                std::cin>>brs;
                                
                                std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                                bool j;
                                std::cin>>j;
                                
                                std::cout<<"Unesite kvadraturu: ";
                                double kva;
                                std::cin>>kva;
                                try{
                                    v[i].Postavi(s,spr,brs,j,kva);
                                    std::cout<<"Stan je uspjesno izmijenjen!"<<std::endl<<std::endl; 
                                    break;
                                }
                                
                                catch(std::domain_error e) {std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl; }
                            }
                        }
                        
                }
                
            
            
        }
            
        
        
                
    }
    
    }
    
    
    }
    
    if(a==2){
        for(;;){
            std::cout<<"Izaberite opciju:"<<std::endl<<" 0 - nazad"<<std::endl<<" 1 - dodavanje kupca"<<std::endl<<" 2 - uredjivanje kupaca"<<std::endl<<" 3 - ispis svih kupaca"<<std::endl<<" 4 - kraj"<<std::endl;
            
        
            std::cin>>e;
            if(e==0) break;
            if(e==3) {
                
                for(int i(0);i<k.size();i++)
                k[i].Ispisi();
                
                std::cout<<std::endl;
            }
            
            if(e==1){
                for(;;){
                    std::cout<<"Unesite ime i prezime kupca: ";
                    std::cin.ignore(1000,'\n');
                    std::cin.clear();
                    std::string s;
                    
                    getline(std::cin,s);
                    
                    int dan,mjesec,godina;
                    char znak1,znak2;
                    
                    std::cout<<"Unesite datum rodjenja (formata d/m/g): ";
                    std::cin>>dan>>znak1>>mjesec>>znak2>>godina;
                   try{ 
                    Kupac ku(s,Datum(dan,mjesec,godina));
                    
                    k.push_back(ku);
                    std::cout<<"Kupac je uspjesno dodan!"<<std::endl<<std::endl;
                    break;
                   }
                   catch(std::domain_error e) { std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl; }
                }
            }
            
            if(e==2){
                std::cout<<"Odaberite kupca kojeg zelite urediti. Dostupni kupci su:"<<std::endl;
                
                for(int i(0);i<k.size();i++){
                    std::cout<<" "<<i+1<<" - ";
                    k[i].Ispisi();
                }
                
                std::cin>>f;
                
                for(;;){
                    std::cout<<"Unesite ime i prezime kupca: ";
                    std::cin.ignore(1000,'\n');
                    std::cin.clear();
                    std::string s;
                    getline(std::cin,s);
                    
                    std::cout<<"Unesite datum rodjenja (formata d/m/g): ";
                    int dan, mjesec,godina;
                    char z,l;
                    std::cin>>dan>>z>>mjesec>>l>>godina;
                    
                    try{
                        k[f-1].Postavi(s,Datum(dan,mjesec,godina));
                        std::cout<<"Kupac je uspjesno izmijenjen!"<<std::endl<<std::endl;
                        break;
                    }
                    catch(std::domain_error e) {std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;}
                }
                
                
            }
      
        }
    }
    
    if(a==3){
        for(;;){
            std::cout<<"Izaberite opciju:"<<std::endl<<" 0 - nazad"<<std::endl<<" 1 - dodavanje prodaje"<<std::endl<<" 2 - uredjivanje prodaje"<<std::endl<<" 3 - ispis prodaja"<<std::endl<<" 4 - brisanje prodaja"<<std::endl<<" 5 - kraj"<<std::endl;
            
            int b;
            std::cin>>b;
            
            if(b==0) break;
            
            if(b==1){
            
            for(;;){
            
            std::cout<<"Izaberite opciju:"<<std::endl<<" 0 - nazad"<<std::endl<<" 1 - dodavanje potpuno nove prodaje"<<std::endl<<" 2 - dodavanje nove prodaje na osnovu arhive"<<std::endl<<" 3 - kraj"<<std::endl;
            
            std::cin.ignore(1000,'\n');
            std::cin.clear();
            int o;
            std::cin>>o;
            
            if(o==1){
                std::cout<<i[0];
                std::cin.ignore(1000,'\n');
                std::cin.clear();
                std::string imeag; 
                getline(std::cin,imeag);
                
                std::cout<<i[1];
                
                int d,m,g;
                char z1,z2;
                std::cin>>d>>z1>>m>>z2>>g;
                
                std::cout<<i[2];
                int cijena,sprat,soba;
                
                std::cin>>cijena;
                
                std::cout<<i[3];
                std::cin.ignore(1000,'\n');
                std::cin.clear();
                std::string ime;
                getline(std::cin,ime);
                
                std::cout<<i[4];
                int d1,m1,g1;
                char znaknovi,znaknovi1;
                std::cin>>d1>>znaknovi>>m1>>znaknovi1>>g1;
                
                k.push_back(Kupac(ime,Datum(d1,m1,g1)));
                
                std::cout<<i[5];
                std::cin.ignore(1000,'\n');
                std::cin.clear();
                std::string adr;
                getline(std::cin,adr);
                
                std::cout<<i[6];
                std::cin>>sprat;
                std::cout<<i[7];
                std::cin>>soba;
                std::cout<<i[8];
                bool e;
                std::cin>>e;
                
                std::cout<<i[9];
                double kvad;
                std::cin>>kvad;
                
                v.push_back(Stan(adr,sprat,soba,e,kvad));
                
                p.RegistrirajProdaju(imeag,cijena,d,m,g,ime,Datum(d1,m1,g1),adr,sprat,soba,e,kvad);
                std::cout<<"Prodaja uspjesno dodana!"<<std::endl<<std::endl;
            }
            
          if(o==2){
                
                std::cout<<i[0];
                std::cin.ignore(1000,'\n');
                std::cin.clear();
                std::string im;
                getline(std::cin,im);
                
                std::cout<<"Unesite datum prodaje (formata d/m/g): ";
           
                int dat,mj,go,cijena;
                char ze,ze2;
               
                std::cin>>dat>>ze>>mj>>ze2>>go;
                
                
                
                std::cout<<i[2];
                
                std::cin>>cijena;
                
                std::cout<<"Odaberite kupca. Dostupni kupci su:"<<std::endl;
                
                for(int i(0);i<k.size();i++){
                    std::cout<<" "<<i+1<<" - ";
                    k[i].Ispisi();
                }
                
                int pom1;
                std::cin>>pom1;
                
                std::cout<<"Odaberite stan. Dostupni stanovi su:"<<std::endl;
                
                for(int i(0);i<v.size();i++){
                    std::cout<<" "<<i+1<<" - ";
                    v[i].Ispisi();
                }
                
               if(!(std::cin.peek())){
                  std::cout<<"a";
                std::cin.ignore(1000,'\n');
                std::cin.clear();
               }
               
                int pomocna;
                std::cin>>pomocna;
                
                try{
                p.RegistrirajProdaju(im,cijena,Datum(dat,mj,go),k[pom1-1],v[pomocna-1]);
                }
                catch(std::domain_error e) {std::cout<<e.what()<<"."<<std::endl;}
                
                std::cout<<"Prodaja uspjesno dodana!"<<std::endl<<std::endl;
              
            }
            
            if(o==0) break;
            
            if (o==3) {std::cout<<std::endl<<std::endl<<"Dovidjenja!"; return 0;}
            
            
            
            }
        }
        
        
        if(b==2){
            std::cout<<"Odaberite prodaju koju želite urediti. Dostupne prodaje su:"<<std::endl;
               
                int br(0);
                for(auto i(p.begin());i!=p.end();i++){
                std::cout<<br+1<<"."<<std::endl;
                
                (*i)->Ispisi();
                if(br!=p.DajBrojProdaja()-1) std::cout<<std::endl;
                br++;
                
            
            }
            int e;
            
            std::cin>>e;
            
        
                
                std::cout<<"Izaberite opciju:"<<std::endl<<" 0 - nazad"<<std::endl<<" 1 - izmjena agenta"<<std::endl<<
                            " 2 - izmjena datuma prodaje"<<std::endl<<" 3 - izmjena kupca"<<std::endl<<" 4 - izmjena stana"
                            <<std::endl<<" 5 - izmjena cijene stana"<<std::endl;
                            
                int g;
                std::cin>>g;
                
                if(g==0) break;
                
                if(g==3){
                    for(;;){
                    std::cout<<"Izaberite opciju:"<<std::endl<<" 0 - nazad"<<std::endl<<" 1 - odabir postojeceg kupca"
                             <<std::endl<<" 2 - dodavanje novog kupca"<<std::endl;
                             
                    int m;
                    std::cin>>m;
                    
                    if(m==0) break;
                    
                    if(m==1){
                        std::cout<<"Odaberite kupca. Dostupni kupci su:"<<std::endl;
                        
                        for(int i(0);i<k.size();i++){
                            std::cout<<i+1<<" - ";
                            k[i].Ispisi();
                        }
                        
                        int postojeci;
                        std::cin>>postojeci;
                        
                        p.DajProdaju(e).PromijeniKupca(k[postojeci-1]);
                        std::cout<<"Prodaja je uspjesno izmijenjena!"<<std::endl<<std::endl;
                        break;
                    }
                    
                    if(m==2){
                        for(;;){
                        std::cout<<"Unesite ime i prezime kupca: ";
                        std::cin.ignore(1000,'\n');
                        std::cin.clear();
                        std::string s;
                        getline(std::cin,s);
                        std::cout<<"Unesite datum rodjenja (formata d/m/g): ";
                        int d,m,g;
                        char z1,z2;
                        std::cin>>d>>z1>>m>>z2>>g;
                        
                        try{p.DajProdaju(e).PromijeniKupca(Kupac(s,Datum(d,m,g)));
                        std::cout<<"Prodaja je uspjesno izmijenjena!"<<std::endl<<std::endl; break; }

                        
                        catch(std::domain_error e){ std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl; }
                        
                        }
                        break;
                    }
                    
                    }
                }
                
                
                
                if(g==4){
                    
                       
                        std::cout<<"Izaberite opciju:"<<std::endl<<" 0 - nazad"<<std::endl<<" 1 - odabir postojeceg stana"<<std::endl<<" 2 - dodavanje novog stana"<<std::endl;
                   int m;
                   std::cin>>m;
                   
                   if(m==0) break;
                   if(m==2){
                    for(;;){
                    try{
                        Stan s(NapraviStan());
                        p.DajProdaju(e).PromijeniStan(s);
                        std::cout<<"Prodaja je uspjesno izmijenjena!"<<std::endl<<std::endl;
                        break;
                        
                    }
                    catch(std::domain_error e) { std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet. "<<std::endl;}
                    }
                   }
                    
                    if(m==1){
                        
                        for(int i(0);i<v.size();i++){
                            std::cout<<i+1<<" - ";
                            v[i].Ispisi();
                        }
                        
                        int r;
                        std::cin>>r;
                        
                        p.DajProdaju(e).PromijeniStan(v[r-1]);
                        
                        std::cout<<"Prodaja je uspjesno izmijenjena!"<<std::endl<<std::endl;
                        
                    }
                
                    }
                    
                    
                  if (g==5){
                        std::cout<<"Unesite cijenu stana: ";
                        int cijen;
                        std::cin>>cijen;
                        
                        p.DajProdaju(e).PromijeniCijenuProdaje(cijen);
                        std::cout<<"Prodaja je uspjesno izmijenjena!"<<std::endl<<std::endl;
                        
             }
                    
                  if(g==1){
                        
                        std::cout<<"Unesite ime i prezime agenta prodaje: ";
                        std::cin.ignore(1000,'\n');
                        std::cin.clear();
                        std::string a;
                        getline(std::cin,a);
                      //  Prodaja pro= p.DajProdaju(e);
                      
                       p.DajProdaju(e)=Prodaja(a,p.DajProdaju(e).DajCijenuStana(),p.DajProdaju(e).DajDatumProdaje(),k[e-1],v[e-1]);
                       std::cout<<"Prodaja je uspjesno izmijenjena!"<<std::endl<<std::endl;
                      
                      
                    }
                if(g==2){
                        int d,m,g;
                        std::cout<<"Unesite datum prodaje (formata d/m/g): ";
                        char z1,z2;
                        std::cin>>d>>z1>>m>>z2>>g;
                        p.DajProdaju(e).PromijeniDatumKupovine(Datum(d,m,g));
                        std::cout<<"Prodaja je uspjesno izmijenjena!"<<std::endl<<std::endl;
                        
                    }
            
            }
            
        if(b==3){
            
            for(;;){
            std::cout<<"Izaberite opciju:"<<std::endl<<" 0 - nazad"<<std::endl<<" 1 - ispis svih prodaja"<<std::endl<<" 2 - ispis prodaja na datum"
                    <<std::endl<<" 3 - ispis najranije prodaje"<<std::endl<<" 4 - ispis najskuplje prodaje"<<std::endl<<" 5 - ispis broja prodaja"
                    <<std::endl<<" 6 - ispis broja prodaja po datumu"<<std::endl<<" 7 - ispis broja prodaja po agentu"<<std::endl<<" 8 - kraj"<<std::endl;
                    
            int m;
            std::cin>>m;
            
            if(m==0) break;
            if(m==1) p.IspisiSveProdaje();
            if(m==2){
                std::cout<<"Unesite datum (d/m/g): ";
                int d,m,g;
                char z1,z2;
                std::cin>>d>>z1>>m>>z2>>g;
                std::cout<<"Prodaje na datum "<<d<<"/"<<m<<"/"<<g<<" su:";
                p.IspisiProdajeNaDatum(Datum(d,m,g));
            }
            
            if(m==3){
                p.DajNajranijuProdaju().Ispisi();
                std::cout<<std::endl;
            }
            
            if(m==4){
                p.DajNajskupljuProdajU().Ispisi();
                std::cout<<std::endl;
            }
            if(m==5){
               std::cout<<"Broj prodaja: "<<p.DajBrojProdaja()<<std::endl<<std::endl;}
            if(m==6){
                std::cout<<"Unesite datum (d/m/g): ";
                int d,m,g;
                char z1,z2;
                std::cin>>d>>z1>>m>>z2>>g;
                std::cout<<"Broj prodaja na uneseni datum: "<<p.DajBrojProdajaNaDatum(Datum(d,m,g))<<std::endl<<std::endl;
            }
            if(m==7){
                std::cout<<"Unesite ime agenta: ";
                std::cin.ignore(1000,'\n');
                std::cin.clear();
                std::string imeagenta;
                getline(std::cin,imeagenta);
                
                std::cout<<"Broj prodaja unesenog agenta: "<<p.DajBrojProdajaOdAgenta(imeagenta)<<std::endl<<std::endl;
            }
            
            if(m==8) { std::cout<<std::endl<<std::endl<<"Dovidjenja!"; return 0; }
             
                    
        
            }
        }
        if(b==4){
            for(;;){
                std::cout<<"Izaberite opciju:"<<std::endl<<" 0 - nazad"<<std::endl<<" 1 - brisanje najranije prodaje"<<std::endl<<" 2 - brisanje prodaja agenta"
                        <<std::endl<<" 3 - brisanje prodaja po datumu"<<std::endl<<" 4 - brisanje svih prodaja"<<std::endl;
                        
                int m;
                std::cin>>m;
                
                if(m==0) break;
                if (m==1){
                 try{   
                 p.ObrisiNajranijuProdaju();
                 std::cout<<"Najranija prodaja je obrisana!"<<std::endl<<std::endl;
                 }
                 
                 catch(std::range_error e){
                 std::cout<<"Izuzetak: "<<e.what()<<"."<<std::endl<<std::endl;
                }
                }
                
                if(m==3) {
                    std::cout<<"Unesite datum: ";
                    int d,m,g;
                    char z1,z2;
                    std::cin>>d>>z1>>m>>z2>>g;
                   
                   p.ObrisiProdajeNaDatum(Datum(d,m,g));
                   std::cout<<"Sve prodaje na taj datum su obrisane."<<std::endl<<std::endl;
          
                }
                
                if(m==2){
                    std::cout<<"Unesite ime agenta: ";
                    std::cin.ignore(1000,'\n');
                    std::cin.clear();
                    std::string ime;
                    getline(std::cin,ime);
                    
                    p.ObrisiProdajeAgenta(ime); 
                   std::cout<<"Sve prodaje tog agenta su obrisane."<<std::endl<<std::endl;
                
                }
                
                if(m==4){
                    
                        p.IsprazniKolekciju();
                        std::cout<<"Sve prodaje su obrisane."<<std::endl<<std::endl;
                    
                }
            }
        }
            
            
        }
        }
    }
    
    
    
    std::cout<<std::endl<<std::endl<<"Dovidjenja!";
    
	return 0;
	
	
	
	
	

}




int Datum::BrojDana(int mjesec, int godina){
    
    int broj_dana[]{31,28,31,30,31,30,31,31,30,31,30,31};
    
    if(godina % 4 == 0 || godina % 100 != 0 || godina%400 == 0)
    broj_dana[1]++;
    
    
    return broj_dana[mjesec-1];
}
void Datum::Postavi (int dan,int mjesec,int godina){
    
    if(godina < 1 || mjesec < 1 || dan < 1 || mjesec > 12 || dan > BrojDana(mjesec,godina))
    throw std::domain_error ("Neispravan datum");
    
    Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
}

void Kupac::Ispisi() const {
    
    std::cout<< ime <<" "<< "(";
    dat.Ispisi();
    std::cout<< ")"<<std::endl; 
}

void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja){
    
    for (int i(0);i<ime_i_prezime.size();i++){
        
        if(!( (ime_i_prezime[i]>='A' && ime_i_prezime[i]<='Z') || (ime_i_prezime[i]>='a' && ime_i_prezime[i]<='z') 
            || (ime_i_prezime[i]>='0' && ime_i_prezime[i]<='9') || ime_i_prezime[i]==' ' || ime_i_prezime[i]=='\'' || ime_i_prezime[i]=='-'))
            
            throw std::domain_error ("Neispravno ime i prezime");
    }
    
    ime=ime_i_prezime;
    dat.Postavi(datum_rodjenja.DajDan(),datum_rodjenja.DajMjesec(),datum_rodjenja.DajGodinu());
}

void Stan::Postavi (const std::string &adresa, int sprat, int broj_soba,bool namjesten, double kvadratura){
 
    
    if(sprat<0 || broj_soba<0 || kvadratura<0)
        throw std::domain_error ("Neispravan unos podataka");
        
   adr=adresa; sp=sprat; br=broj_soba; namj=namjesten; kv=kvadratura;
}

void Stan::Ispisi () const {
    
    
   if(br%10==1 || br%10>=5){
            std::cout<<"Stan se nalazi na adresi "<<adr<<" na "<<sp<<"."<<" spratu i ima "<<br<<" soba. ";
            std::cout<<"Kvadratura stana je "<<kv;
            
            if(namj==true)   std::cout<<" (m^2) i stan je namjesten."<<std::endl;
            
            else std::cout<< " (m^2) i stan nije namjesten."<<std::endl;
        }
        
   else if (br%10==2 || br%10==3 || br%10==4 ){
       
            std::cout<<"Stan se nalazi na adresi "<<adr<<" na "<<sp<<"."<<" spratu i ima "<<br<<" sobe. ";
            std::cout<<"Kvadratura stana je "<<kv;
            
            if(namj==true) std::cout<<" (m^2) i stan je namjesten."<<std::endl;
            else std::cout<<" (m^2) i stan nije namjesten."<<std::endl;
            
        }
        

}

int Prodaja::BrojDana (int mjesec, int godina){
    int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
    
    if(godina%4==0 || godina%100!=0 || godina%400==0)
    broj_dana[1]++;
    
    return broj_dana[mjesec-1];
}

Prodaja::Prodaja ( const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,
                        const Stan &kupljeni_stan) :dat(datum_prodaje), k(kupac_stana), s(kupljeni_stan) {
           
                            imeag=ime_agenta_prodaje;
                            cijena=cijena_stana;
                        }
                        
                        
Prodaja::Prodaja (const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
                        std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba,
                        bool namjesten_stan, double broj_kvadrata) : dat(Datum(dan_prodaje,mjesec_prodaje,godina_prodaje)), k(Kupac(ime_kupca,datum_rodjenja_kupca)),
                        s(Stan(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata)) 
                        {
                            imeag=ime_agenta_prodaje;
                            cijena=cijena_stana;
                        }
void Prodaja::PomjeriDanUnaprijed() {
    
    if(dat.DajDan()+1>BrojDana(dat.DajMjesec(),dat.DajGodinu())){
        
        if(dat.DajMjesec()==12) dat.Postavi(1,1,dat.DajGodinu()+1);
        
        else dat.Postavi(1,dat.DajMjesec()+1,dat.DajGodinu());
        
    }
    
    else dat.Postavi(dat.DajDan()+1,dat.DajMjesec(),dat.DajGodinu());
}

void Prodaja::PomjeriDanUnazad() {
    
    if(dat.DajDan()-1==0){
        
        if(dat.DajMjesec()==1) dat.Postavi(31,12,dat.DajGodinu()-1);
        
        else dat.Postavi(BrojDana(dat.DajMjesec()-1,dat.DajGodinu()),dat.DajMjesec()-1,dat.DajGodinu());
    }
    
    else dat.Postavi(dat.DajDan()-1,dat.DajMjesec(),dat.DajGodinu());
}

void Prodaja::Ispisi() const {
    std::cout<<std::setw(32)<<std::left<<"Ime agenta: "<<imeag<<std::endl;
    std::cout<<std::setw(32)<<std::left<<"Ime kupca: "<<k.DajImePrezime()<<" "<<"("<<k.DajDatumRodjenja().DajDan()<<"/"<<k.DajDatumRodjenja().DajMjesec()<<"/"<<k.DajDatumRodjenja().DajGodinu()<<")"<<std::endl;
    std::cout<<std::setw(32)<<std::left<<"Zakazani datum prodaje: ";
    dat.Ispisi();
    std::cout<<std::endl;
    std::cout<<std::setw(32)<<std::left<<"Cijena stana: "<<cijena<<std::endl;
    std::cout<<std::setw(32)<<std::left<<"Informacije o stanu: "<<std::endl;
    s.Ispisi();
}

bool ProdatPrije( const Prodaja &p1, const Prodaja &p2){
    
    Datum dat1=p1.DajDatumProdaje(), dat2=p2.DajDatumProdaje();
    
    if(dat1.DajGodinu()<dat2.DajGodinu()) return true;
    
    else if(dat1.DajGodinu()>dat2.DajGodinu()) return false;
    
    if(dat1.DajMjesec()<dat2.DajMjesec()) return true;
    
    else if(dat1.DajMjesec()>dat2.DajMjesec()) return false;
    
    if (dat1.DajDan()<dat2.DajDan()) return true;
    else return false;
}

Prodaje::Prodaje(int max_broj_prodaja): maks_prodaja(max_broj_prodaja), broj_prodaja(0){
    
    niz=new Prodaja* [max_broj_prodaja];
    
    for(int i(0);i<maks_prodaja;i++){
        niz[i]=nullptr;
    }
}

Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja) : maks_prodaja(spisak_prodaja.size()), broj_prodaja(0) {
    
    niz = new Prodaja*[int(spisak_prodaja.size())];
 
    for(int j(0);j<maks_prodaja;j++){
        niz[j]=nullptr;
    }
    
    for(auto it=spisak_prodaja.begin(); it != spisak_prodaja.end(); it++){
        niz[broj_prodaja] = new Prodaja(*it);
        broj_prodaja++;
    }
}

Prodaje::~Prodaje() {
    
    for(int i(0);i<broj_prodaja;i++)
        delete niz[i];
        
    delete[] niz;
    
    
}
Prodaje::Prodaje(const Prodaje &prodaje){
    
    this->niz = new Prodaja*[prodaje.broj_prodaja];
    this->maks_prodaja = this->broj_prodaja = prodaje.broj_prodaja;
    
    for(int i(0); i<maks_prodaja; i++){
        this->niz[i] = new Prodaja(*prodaje.niz[i]);
    }
}

Prodaje::Prodaje(Prodaje &&prodaje){
    
    niz = prodaje.niz;
    broj_prodaja = prodaje.broj_prodaja;
    maks_prodaja = prodaje.maks_prodaja;
    
    prodaje.niz = nullptr;
}

Prodaje& Prodaje::operator =(const Prodaje &prodaje){
    
    if(this==&prodaje)
        return *this;
        
    
    for(int i(0); i<broj_prodaja; i++) delete niz[i];
    delete [] niz;
    
    maks_prodaja=prodaje.maks_prodaja;
    broj_prodaja=prodaje.broj_prodaja;
    
    niz = new Prodaja*[prodaje.maks_prodaja];
    
    for(int i(0); i<prodaje.broj_prodaja; i++) niz[i] = new Prodaja(*prodaje.niz[i]);

    
    return *this;
}

Prodaje& Prodaje::operator =(Prodaje &&prodaje){
    
    if(this==&prodaje){
        return *this;
    }
    
    for(int i(0);i<broj_prodaja;i++) delete niz[i];
    delete[] niz;
    
    //plitka kopija, kradem sve  i obrisat cu ga hehe
    
    niz=prodaje.niz;
    maks_prodaja=prodaje.maks_prodaja;
    broj_prodaja=prodaje.broj_prodaja;
    
    prodaje.niz=nullptr;
    
    return *this;
    
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje,
                                const Kupac &kupac_stana, const Stan &kupljeni_stan) {
                                    
            if (broj_prodaja>=maks_prodaja)  throw std::range_error ("Dostignut maksimalni broj prodaja");
            
            niz[broj_prodaja]= new Prodaja(ime_agenta_prodaje,cijena_stana,datum_prodaje,kupac_stana,kupljeni_stan);
            broj_prodaja++;
}


void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana, int dan_prodaje, int mjesec_prodaje,
                                int godina_prodaje,  std::string &ime_kupca, const Datum &datum_rodjenja_kupca,
                                const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata ){
            if (broj_prodaja>=maks_prodaja) throw std::range_error("Dostignut maksimalan broj prodaja");
            
            niz[broj_prodaja]=new Prodaja(ime_agenta_prodaje,cijena_stana,Datum(dan_prodaje,mjesec_prodaje,godina_prodaje),Kupac(ime_kupca,
                                            datum_rodjenja_kupca),Stan(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata));
                                            
            broj_prodaja++;
}

void Prodaje::RegistrirajProdaju(Prodaja *prodaja){
    
    if(broj_prodaja>=maks_prodaja){
        
     delete prodaja;
     prodaja=nullptr;
        
     throw std::range_error("Dostignut maksimalni broj prodaja");
    }
    niz[broj_prodaja]=prodaja;
    
    broj_prodaja++;
}

int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const {
    
    
   return  std::count_if(niz,niz+broj_prodaja,[datum](Prodaja *p){
            
            Datum dat(p->DajDatumProdaje());
            
            if(datum.DajDan()==dat.DajDan() && datum.DajMjesec()==dat.DajMjesec() && datum.DajGodinu()==dat.DajGodinu())
            return 1;
            
            else return 0;
   });
}

int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const {
    
    
    return std::count_if(niz,niz+broj_prodaja,[ime_agenta](Prodaja *p){
        
        if(ime_agenta==(*p).DajImeAgenta())
        return 1;
        
        else return 0;
    });
    
}

Prodaja& Prodaje::DajNajranijuProdaju(){
    
    return **(std::min_element(niz,niz+broj_prodaja,[](Prodaja *p1,Prodaja *p2){
        
        if(ProdatPrije(*p1,*p2))
        return 1;
        
        else return 0;
    }));
    
}


Prodaja Prodaje::DajNajranijuProdaju() const{
    
    return **(std::min_element(niz,niz+broj_prodaja,[](Prodaja *p1,Prodaja *p2){
        
        if(ProdatPrije(*p1,*p2))
        return 1;
        
        else return 0;
        
        
    }));
}

Prodaja& Prodaje::DajNajskupljuProdajU(){
    
    
    return **(std::max_element(niz,niz+broj_prodaja,[](Prodaja *p1,Prodaja *p2){
        
        if(SkupljiStan(*p1,*p2))
            return 0;
            
        else return 1;
        
    }));
}


Prodaja Prodaje::DajNajskupljuProdajU() const{
    
    return **(std::max_element(niz,niz+broj_prodaja,[](Prodaja *p1,Prodaja *p2){
        
        if(SkupljiStan(*p1,*p2))
            return 0;
            
        else return 1;
        
        
    }));
}

Prodaja& Prodaje::DajProdaju(int redni_broj_prodaje){
    
    if(redni_broj_prodaje<=0 || redni_broj_prodaje>broj_prodaja)
    throw std::domain_error ("Neispravan redni broj prodaje");
    
    return *(niz[redni_broj_prodaje-1]);
    
}

void Prodaje::IsprazniKolekciju(){
    
    for (int i(0);i<broj_prodaja;i++){
        
        delete niz[i];
        niz[i]=nullptr;
    }
    
    broj_prodaja=0;
    maks_prodaja=0;
}
void Prodaje::ObrisiNajranijuProdaju(){
    
    if(broj_prodaja==0) throw std::range_error ("Prazna kolekcija");
    
    Prodaja* min=*(std::min_element(niz,niz+broj_prodaja,[](Prodaja *p1,Prodaja *p2){
        
        return ProdatPrije(*p1,*p2);
    }));
    
    int i(0);
    
    while(min!=niz[i])
        i++;
        
    std::copy(niz+i+1,niz+broj_prodaja,niz+i);
    
    delete min;
    min=nullptr;
    
    broj_prodaja--;
    
}

void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta){
    
    for(int i (0);i<broj_prodaja;i++){
        
        if(ime_agenta==niz[i]->DajImeAgenta()){
            
            Prodaja *pom(niz[i]);
            std::copy(niz+i+1,niz+broj_prodaja,niz+i);
            i--;
            delete pom;
            pom=nullptr;
            broj_prodaja--;
        }
           
      
    }
    
    
}
void Prodaje::ObrisiProdajeNaDatum(const Datum &datum){
    
    for(int i(0);i<broj_prodaja;i++){
        
        if(niz[i]->DajDatumProdaje().DajDan()==datum.DajDan() && niz[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec()
            && niz[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu()){
            
            Prodaja *pom(niz[i]);
            std::copy(niz+i+1,niz+broj_prodaja,niz+i);
            i--;
            delete pom;
            pom=nullptr;
            broj_prodaja--;
        }
    }
}

void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const {
    
    std::vector<Prodaja*> v; 
    
    for (int i(0);i<broj_prodaja;i++){
        
        if((niz[i]->DajDatumProdaje()).DajDan()==datum.DajDan() && (niz[i]->DajDatumProdaje()).DajMjesec()==datum.DajMjesec()
            && (niz[i]->DajDatumProdaje()).DajGodinu()==datum.DajGodinu())
        
        v.push_back(niz[i]);
        
    }
    

    
    std::sort(v.begin(),v.end(),[](Prodaja *p1,Prodaja *p2){
        
        if(p1->DajImeKupca() < p2->DajImeKupca())
                return 1;
        else return 0;
    });
    
    for(int i(0);i<v.size();i++){
        
        v[i]->Ispisi();
        std::cout<<std::endl;
    }
}

void Prodaje::IspisiSveProdaje() const{
    
    std::vector<Prodaja*> v;
    
    for(int i(0);i<broj_prodaja;i++){
        v.push_back(niz[i]);
    }
    
    std::sort(v.begin(),v.end(),[](Prodaja *p1,Prodaja *p2){
        
        if( ProdatPrije(*p1,*p2)   )
        return 1;
        
        else if( (p1)->DajDatumProdaje().DajDan()==(p2)->DajDatumProdaje().DajDan() && 
                 (p1)->DajDatumProdaje().DajMjesec()==(p2)->DajDatumProdaje().DajMjesec() &&
                  (p1)->DajDatumProdaje().DajGodinu()==(p2)->DajDatumProdaje().DajGodinu()){
                      
            if (p1->DajImeKupca() < p2->DajImeKupca())
                    return 1;
                  
                  
            else return 0;
        
                  }
                  
        else return 0;
        
    });
    
    for(int i(0);i<v.size();i++){
        v[i]->Ispisi();
        std::cout<<std::endl;
        
    }
}











