#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <memory>
class Datum{
    int d,m,g;
    public:
        Datum(int dan, int mjesec, int godina){Postavi(dan,mjesec,godina);}
        void Postavi(int dan, int mjesec, int godina){
            if(dan <= 0 || dan >= 31 || mjesec <1 || mjesec > 12 || godina < 0 || dan > brojDana(mjesec,godina))
                throw std::domain_error("Neispravan datum");
        }
        int DajDan()const{return d;}
        int DajMjesec()const{return m;}
        int DajGodinu()const{return g;}
        void Ispisi()const{std::cout <<d<<"/"<<m<<"/"<<g;}
    private:
        static int brojDana(int mon, int god){
            int numd[]{31,28,31,30,31,30,31,31,30,31,30,31};
            if((god%4==0 && god%100!=0) || god%400==0) numd[1]++;
                return numd[mon-1];
        }
};
class Kupac{
    std::string ime;
    Datum rodj;
    public:
        Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja):rodj(datum_rodjenja){
            Postavi(ime_i_prezime,datum_rodjenja);
        }
        void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja){
            if(!isValid(ime_i_prezime))
                throw std::domain_error("Neispravno ime i prezime");
        }
        std::string DajImePrezime()const{ return ime; }
        Datum DajDatumRodjenja()const{ return rodj; }
        void Ispisi()const{std::cout << ime << " ("; rodj.Ispisi();std::cout << ")";}
    private:
        static bool isValid(const std::string &s){
            for(int i = 0; i < s.length(); i++)
                if(!((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >='a'&&s[i]<='z') || 
                (s[i] >= '0' && s[i] <= '9') || s[i] == '-' || s[i] == ' ' || s[i] == '\''))
                    return false;
            return true;
        }
};
class Stan{
    std::string adresa;
    int sprat,soba;
    bool namjesten;
    double kvadratura;
    public: 
        Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten,
        double kvadratura){
            Postavi(adresa,sprat,broj_soba,namjesten,kvadratura);
        }
        void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten,
        double kvadratura){
            if(sprat < 0 || broj_soba < 0 || kvadratura < 0)
                throw std::domain_error("Neispravan unos podataka");
            this->adresa = adresa; this->sprat = sprat; soba = broj_soba; 
            this->namjesten = namjesten; this->kvadratura = kvadratura;
        }
        std::string DajAdresu()const{ return adresa; }
        int DajSprat()const{ return sprat; }
        int DajBrojSoba()const{ return soba; }
        bool DajNamjesten()const{ return namjesten; }
        double DajKvadraturu()const{ return kvadratura; }
        void Ispisi() const;
};
void Stan::Ispisi()const{
    std::string s("sobe"); int x(soba%10);
    std::string nam("je namjesten.");
    if(!namjesten) nam = "nije namjesten.";
    if(x == 1) s = "sobu";
    else if(x > 4) s = "soba";
    std::cout << "Stan se nalazi na adresi " << adresa << " na " << sprat <<
    ". spratu i ima " << soba << " " << s << " .Kvadratura stana je " << 
    std::fixed << std::setprecision(2) << kvadratura << " (m^2) i stan " << nam;
}
class Prodaja{
    std::string imeAgenta;
    double cijenaStana;
    Datum datumProdaje;
    Kupac kupacStana;
    Stan kupljeniStan;
    public:
        Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,
            const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan):
            imeAgenta(ime_agenta_prodaje),cijenaStana(cijena_stana),datumProdaje(datum_prodaje),
            kupacStana(kupac_stana),kupljeniStan(kupljeni_stan){ }
        
        Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,
            int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
            std::string &ime_kupca, const Datum &datum_rodjenja_kupca,
            const std::string &adresa_stana, int sprat_stana, int broj_soba,
            bool namjesten_stan, double broj_kvadrata):
            imeAgenta(ime_agenta_prodaje), cijenaStana(cijena_stana),
            datumProdaje(Datum(dan_prodaje, mjesec_prodaje, godina_prodaje)),
            kupacStana(ime_kupca, datum_rodjenja_kupca),
            kupljeniStan(Stan(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata)){ }
        
        void PromijeniKupca(const Kupac &novi_kupac){ kupacStana = novi_kupac; }
        void PromijeniStan(const Stan &novi_stan){ kupljeniStan = novi_stan; }
        void PromijeniDatumKupovine(const Datum &novi_datum){ datumProdaje = novi_datum; }
        void PromijeniCijenuProdaje(const double &nova_cijena){ cijenaStana = nova_cijena; }
        void PomjeriDanUnaprijed(){
            int d(datumProdaje.DajDan()),m(datumProdaje.DajMjesec()),g(datumProdaje.DajGodinu());
            d++; if(d > dajBrDana(m,g)) d = 1; m++;
            if(m > 12) m = 1; g++;
            datumProdaje.Postavi(d,m,g);
        }
        void PomjerDanUnazad(){
            int d(datumProdaje.DajDan()-1),m(datumProdaje.DajMjesec()),g(datumProdaje.DajGodinu());
            if(d < 1){
                m--; if(m < 1) {m = 12; g--;}
                d = dajBrDana(m,g);
            }
            datumProdaje.Postavi(d,m,g);
        }
        std::string DajImeAgenta()const{ return imeAgenta; }
        std::string DajImeKupca()const{ return kupacStana.DajImePrezime(); }
        Datum DajDatumProdaje()const{ return datumProdaje; }
        double DajCijenuStana()const{ return cijenaStana; }
        friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
        friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
        void Ispisi() const;
    private:
        static int dajBrDana(int m, int g){
            int n[]{31,28,31,30,31,30,31,31,30,31,30};
            if((g%4==0 &&g%100!=0) ||g%400==0) n[1]++;
            return n[m-1];
        }
};
void Prodaja::Ispisi()const{
    std::cout << std::left << std::setw(20) << "Ime agenta:" << DajImeAgenta() << "\n"<<
    std::setw(20) << "Ime kupca:"; kupacStana.Ispisi(); 
    std::cout << std::setw(20) << "Zakazani datum prodaje:"; DajDatumProdaje().Ispisi();
    std::cout << std::setw(20) << "\nCijena stana:" << DajCijenuStana() << "\nInformacije o stanu:\n";
    kupljeniStan.Ispisi();
}
bool ProdatPrije(const Prodaja &p1, const Prodaja &p2){
    int d1,m1,g1,d2,m2,g2;
    g1 = p1.DajDatumProdaje().DajGodinu(); 
    g2 = p2.DajDatumProdaje().DajGodinu();
    m1 = p1.DajDatumProdaje().DajMjesec();
    m2 = p2.DajDatumProdaje().DajMjesec();
    d1 = p1.DajDatumProdaje().DajDan();
    d2 = p2.DajDatumProdaje().DajDan();
    if(g1 != g2) return g1 < g2;
    if(m1 != m2) return m1 < m2; return d1 < d2;
}
bool SkupljiStan(const Prodaja &p1, const Prodaja &p2){
    return p1.DajCijenuStana() > p2.DajCijenuStana();
}
class Prodaje{
    std::vector<std::shared_ptr<Prodaja>> p;
    int max, cur;
    public:
        explicit Prodaje(){
            //p = new Prodaja*[max_broj_prodaja];
        }
        Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
        ~Prodaje(){
            //if(p){
              //  for(int i = 0; i < cur; i++) delete p[i]; delete[] p;
            //}
        }
        Prodaje(const Prodaje &prodaje){
            *this = prodaje;
        }
        Prodaje(Prodaje &&prodaje){
            *this = prodaje;
        }
        Prodaje &operator=(const Prodaje &prodaje);
        Prodaje &operator=(Prodaje &&prodaje);
        void RegistritrajProdaju(const std::string &ime_agenta_prodaje,
            double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,
            const Stan &kupljeni_stan);
        void RegistritrajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana,
            int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
            const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,
            int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
        void RegistritrajProdaju(Prodaja &prodaja);
        int DajBrojProdaja()const{return cur;}
        int DajBrojProdajaNaDatum(const Datum &datum)const;
        int DajBrojProdajaOdAgenta(const std::string &ime_agenta)const;
        Prodaja &DajNajranijuProdaju();
        Prodaja DajNajranijuProdaju() const;
        Prodaja &DajNajskupljuProdaju();
        Prodaja DajNajskupljuProdaju() const;
        void IsprazniKolekciju();
        void ObrisiNajranijuProdaju();
        void ObrisiProdajeAgenta(const std::string &ime_agenta);
        void ObrisiProdajeNaDatum(const Datum &datum);
        void IspisiProdajeNaDatum(const Datum &datum)const;
        void IspisiSveProdaje() const;
    private:
        bool istiDat(const Datum &d1, const Datum &d2)const{
            return d1.DajDan() == d2.DajDan() && d1.DajMjesec() == d2.DajMjesec() && d1.DajGodinu() == d2.DajGodinu();
        }
};
void Prodaje::IspisiSveProdaje()const{
    std::sort(p.begin(),p.end(),[](std::shared_ptr<Prodaja> a, std::shared_ptr<Prodaja> b){
        if(ProdatPrije(*a,*b) || ProdatPrije(*a,*b))
            return ProdatPrije(*a,*b);
        return a->DajImeKupca() < b->DajImeKupca();
    });
    std::for_each(p.begin(),p.end(),[](std::shared_ptr<Prodaja> a){ a->Ispisi(); });
}
void Prodaje::IspisiProdajeNaDatum(const Datum &datum)const{
    std::sort(p.begin(),p.end(),[](std::shared_ptr<Prodaja> a,std::shared_ptr<Prodaja> b){
       return a->DajImeKupca() < b->DajImeKupca();
    });
    for(int i = 0; i < p.size(); i++)
        if(istiDat(p[i]->DajDatumProdaje(), datum)) p[i]->Ispisi();
}
void Prodaje::ObrisiProdajeNaDatum(const Datum &datum){
    p.resize( p.end() - std::remove_if(p.begin(),p.end(),[datum,this](std::shared_ptr<Prodaja> a){
       return istiDat(a->DajDatumProdaje(),datum); 
    }));
}
void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta){
    p.resize( p.end() - std::remove_if(p.begin(),p.end(),[ime_agenta](std::shared_ptr<Prodaja> a){
        return ime_agenta == a->DajImeAgenta();
    }));
}
void Prodaje::ObrisiNajranijuProdaju(){
    if(!p.size() ) throw::std::range_error("Prazna kolekcija");
    std::remove_if(p.begin(),p.end(),[this](std::shared_ptr<Prodaja> a){
       return a.get() == &DajNajranijuProdaju(); 
    });
    cur--;
}
void Prodaje::IsprazniKolekciju(){
    //for(int i = 0; i < cur; i++) delete p[i]; delete[] p;
    //p = nullptr; cur = 0;
    p.resize(0);
}
Prodaja Prodaje::DajNajskupljuProdaju()const{
    if(!p.size()) throw std::domain_error("Nema registriranih prodaja");
    return **std::max_element(p.begin(),p.end(),[](std::shared_ptr<Prodaja> a,std::shared_ptr< Prodaja > b){
       return SkupljiStan(*a,*b); 
    });
}
Prodaja &Prodaje::DajNajskupljuProdaju(){
    if(!p.size()) throw std::domain_error("Nema registriranih prodaja");
     Prodaja &x = **std::max_element(p.begin(),p.end(),[](std::shared_ptr<Prodaja> a,std::shared_ptr< Prodaja> b){
       return SkupljiStan(*a,*b); 
    });
    return x;
} 
Prodaja &Prodaje::DajNajranijuProdaju(){
    if(!p.size()) throw std::domain_error("Nema registriranih prodaja");
    Prodaja &x = **std::min_element(p.begin(),p.end(),[](std::shared_ptr<Prodaja> a,std::shared_ptr< Prodaja > b){
       return  ProdatPrije(*a,*b);
    });
    return x;
}
Prodaja Prodaje::DajNajranijuProdaju()const{
    if(!p.size()) throw std::domain_error("Nema registriranih prodaja");
    return **std::min_element(p.begin(),p.end(),[](std::shared_ptr<Prodaja > a,std::shared_ptr< Prodaja > b){
       return ProdatPrije(*a,*b); 
    });
}

int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta)const{
    int sum(0);
    for(int i = 0; i < cur; i++){
        if(ime_agenta == p[i]->DajImeAgenta()) sum++;
    }
    return sum;
}
int Prodaje::DajBrojProdajaNaDatum(const Datum &datum)const{
    return std::count_if(p.begin(),p.end(),[datum](std::shared_ptr<Prodaja > asd){
        auto tmp = asd->DajDatumProdaje();
        return (tmp.DajDan() == datum.DajDan() && tmp.DajMjesec() == datum.DajMjesec() && tmp.DajGodinu() == datum.DajGodinu());
    });
}
void Prodaje::RegistritrajProdaju(Prodaja &prodaja){
    //if(cur == max) throw std::range_error("Dostignut maksimalan broj prodaja");
    p.push_back(std::make_shared<Prodaja>(prodaja));
    //p[cur] = new Prodaja(prodaja); cur++;
}
void Prodaje::RegistritrajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana,
    int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
    const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,
    int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata){
    if(cur == max) throw std::range_error("Dostignut maksimalan broj prodaja");
    Datum d(dan_prodaje,mjesec_prodaje,godina_prodaje);
    Kupac k(ime_kupca,datum_rodjenja_kupca);
    Stan s(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata);
    p.push_back(std::make_shared<Prodaja>(ime_agenta_prodaje,cijena_stana,d,k,s));
    //p[cur] = new Prodaja(ime_agenta_prodaje,cijena_stana,d,k,s);
    //cur++;
}
void Prodaje::RegistritrajProdaju(const std::string &ime_agenta_prodaje,
    double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,
    const Stan &kupljeni_stan){
        //if(cur == max) throw std::range_error("Dostignut maksimalan broj prodaja");
    p.push_back(std::make_shared<Prodaja>(ime_agenta_prodaje, cijena_stana, datum_prodaje, kupac_stana, kupljeni_stan));
    //p[cur] = novi; cur++;
}
Prodaje &Prodaje::operator=(Prodaje &&prodaje){
    if(&prodaje != this){
        //for(int i = 0; i < max; i++) delete p[i]; delete[] p;
        p = std::move(prodaje.p); prodaje.p.resize(0);
        //max = prodaje.max;
    }
    return *this;
}
Prodaje &Prodaje::operator=(const Prodaje &prodaje){
    if(&prodaje != this){
        std::vector<std::shared_ptr<Prodaja>> novi;
        try{
            //novi = new Prodaja*[prodaje.max]{};
            for(int i = 0; i < prodaje.p.size(); i++) novi.push_back(std::make_shared< Prodaja>(*prodaje.p[i]));
            //for(int i = 0; i < max; i++) delete p[i]; delete[] p;
            //max = prodaje.max; p = novi; cur = prodaje.cur;
            p = novi;
        }catch(...){
            //for(int i = 0; i < prodaje.max;i++) delete novi[i]; delete[] novi;
            throw;
        }
    }
    return *this;
}
Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja):max(spisak_prodaja.size()){
    //p= new Prodaja*[spisak_prodaja.size()];
    int n(0);
    try{
        for(auto &i:spisak_prodaja){p.push_back(std::make_shared< Prodaja>(i)); }
    }catch(...){
        //for(int i = 0; i < n; i++) delete p[i];delete[] p;
        throw;
    }
    //cur = max;
}
int main(){
    
    return 0;
}