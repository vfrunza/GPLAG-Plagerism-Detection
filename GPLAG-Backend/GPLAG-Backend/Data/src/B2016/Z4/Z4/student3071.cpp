#include <iostream>
#include <string>
#include <cstring>
#include <utility>
#include <stdexcept>
class Datum{
    int dan, mjesec, godina;
    public:
    Datum(int dan, int mjesec, int godina){
        Postavi(dan,mjesec,godina);
    }
    void Postavi(int dan, int mjesec, int godina){
        int broj_dana[]{31,28,31,30,31,30,31,30,31,30,31,30};
        if((godina%4==0 && godina%100!=0) || godina%400==0) broj_dana[1]++;
        if(godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>broj_dana[mjesec-1])
        throw std::domain_error{"Neispravan datum!"};
        Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
    }
    int DajDan() const{
        return dan;
    }
    int DajMjesec() const{
        return mjesec;
    }
    int DajGodinu() const{
        return godina;
    }
    void Ispisi() const{
        std::cout<<DajDan()<<"/"<<DajMjesec()<<"/"<<DajGodinu();
    }
};

class Kupac{
    std::string ime_i_prezime;
    Datum datum_rodjenja;
    public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja):
        datum_rodjenja(datum_rodjenja.DajDan(),datum_rodjenja.DajMjesec(),datum_rodjenja.DajGodinu())
    {
        Kupac::ime_i_prezime=ime_i_prezime;
    }
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja)
    {   
        Kupac::datum_rodjenja.Postavi(datum_rodjenja.DajDan(),datum_rodjenja.DajMjesec(),datum_rodjenja.DajGodinu());
        std::string v=ime_i_prezime;
        for(int i=0; i<ime_i_prezime.length(); i++){
            if(!(v[i]>='A' && v[i]<='Z') && !(v[i]>='a' && v[i]<='z') && !(v[i]>='0' && v[i]<='9') && v[i]!=' ' && v[i]!=39) throw std::domain_error{"Neispravno ime i prezime"}; 
        }
        try{
        Kupac::ime_i_prezime=ime_i_prezime;
        }
        catch(std::domain_error e){
            std::cout<<e.what()<<std::endl;
        }
    }
    std::string DajImePrezime() const{
        return ime_i_prezime;
    }
    Datum DajDatumRodjenja() const{
        return datum_rodjenja;
    }
    void Ispisi() const{
        std::cout<<ime_i_prezime<<"("<<datum_rodjenja.DajDan()<<"/"<<datum_rodjenja.DajMjesec()<<"/"<<datum_rodjenja.DajGodinu()<<")"<<std::endl;
    }

};

class Stan{
    std::string adresa;
    int sprat, broj_soba;
    double kvadratura;
    bool namjesten;
    public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten,double kvadratura){
        Postavi(adresa,sprat,broj_soba,namjesten,kvadratura);
    }
    void Postavi(const std::string &adresa, int sprat, int broj_soba,bool namjesten, double kvadratura){
        if(sprat<0 || broj_soba<=0 || kvadratura<=0) throw std::domain_error{"Neispravan unos podataka"};
        try{
        Stan::adresa=adresa; Stan::sprat=sprat; Stan::broj_soba=broj_soba; Stan::namjesten=namjesten; Stan::kvadratura=kvadratura;
        }
        catch(std::domain_error e){
            std::cout<<e.what()<<std::endl;
        }
    }
    std::string DajAdresu() const{
        return adresa;
    }
    int DajSprat() const{
        return sprat;
    }
    int DajBrojSoba() const{
        return broj_soba;
    }
    bool DajNamjesten() const{
        return namjesten;
    }
    double DajKvadraturu() const{
        return kvadratura;
    }
    void Ispisi() const{
        if(DajBrojSoba()>4){
        std::cout<<"Stan se nalazi na adresi "<<DajAdresu()<<" na "<<DajSprat()<<". spratu i ima "<<DajBrojSoba()<<" soba."<<std::endl;
        }else{
        std::cout<<"Stan se nalazi na adresi "<<DajAdresu()<<" na "<<DajSprat()<<". spratu i ima "<<DajBrojSoba()<<" sobe."<<std::endl;    
        }
        if(DajNamjesten()==true){
        std::cout<<"Kvadratura stana je "<<DajKvadraturu()<<" (m^2) i stan je namjesten."<<std::endl;
        }else{
        std::cout<<"Kvadratura stana je "<<DajKvadraturu()<<" (m^2) i stan nijje namjesten."<<std::endl;    
        }
    }
};

class Prodaja{
    std::string ime_agenta_prodaje;
    double cijena_stana;
    Datum datum_prodaje;
    Kupac kupac_stana;
    Stan kupljeni_stan;
    public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,const Datum &datum_prodaje, const Kupac &kupac_stana,const Stan &kupljeni_stan):
        datum_prodaje(datum_prodaje.DajDan(),datum_prodaje.DajMjesec(),datum_prodaje.DajGodinu()), kupac_stana(kupac_stana.DajImePrezime(),kupac_stana.DajDatumRodjenja()),kupljeni_stan(kupljeni_stan.DajAdresu(),kupljeni_stan.DajNamjesten(),kupljeni_stan.DajSprat(),kupljeni_stan.DajBrojSoba(),kupljeni_stan.DajKvadraturu())
    {
        Prodaja::ime_agenta_prodaje=ime_agenta_prodaje; Prodaja::cijena_stana=cijena_stana; 
        
    }
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
     std::string &ime_kupca, const Datum &datum_rodjenja_kupca,
     const std::string &adresa_stana, int sprat_stana, int broj_soba,
     bool namjesten_stan, double broj_kvadrata):
        datum_prodaje(dan_prodaje,mjesec_prodaje,godina_prodaje), kupac_stana(ime_kupca,datum_rodjenja_kupca),kupljeni_stan(adresa_stana,sprat_stana,namjesten_stan,broj_soba,broj_kvadrata)
     {
         Prodaja::ime_agenta_prodaje=ime_agenta_prodaje;
         Prodaja::cijena_stana=cijena_stana; 
         
     }
    void PromijeniKupca(const Kupac &novi_kupac){
        kupac_stana=novi_kupac;
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
    std::string DajImeAgenta() const{
        return ime_agenta_prodaje;
    }
    std::string DajImeKupca() const{
        return kupac_stana.DajImePrezime();
    }
    Datum DajDatumProdaje() const{
        return datum_prodaje;
    }
    double DajCijenuStana() const{
        return cijena_stana;
    }
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
    void Ispisi() const;
    
};

void Prodaja::PomjeriDanUnaprijed(){
    int d,m,g;
    d=datum_prodaje.DajDan();
    m=datum_prodaje.DajMjesec();
    g=datum_prodaje.DajGodinu();
    d++;
    if(((g%4==0 && g%100!=0) || g%400==0) && m==2){
        if(d==30) { d=1; m++; }
    }
    if(d==29 && m==2) { d=1; m++; }
    if(d==32) { d=1; m++; }
    if(m==13) { m=1; g++; }
    datum_prodaje.Postavi(d,m,g);
}
void Prodaja::PomjeriDanUnazad(){
    int d,m,g;
    d=datum_prodaje.DajDan();
    m=datum_prodaje.DajMjesec();
    g=datum_prodaje.DajGodinu();
    d--;
    if(((g%4==0 && g%100!=0) || g%400==0) && m==3){
        if(d==0) {d=29; m--;}   
    }    
    if(d==0 && m==3) { d=28; m--; }
    if(d==0 && m%2==0) { d=31; m--; }
    if(d==0 && m%2!=0) { d=30; m--; }
    datum_prodaje.Postavi(d,m,g);
}
bool ProdatPrije(const Prodaja &p1, const Prodaja &p2){
    if(p1.DajDatumProdaje().DajMjesec()<p2.DajDatumProdaje().DajMjesec() && p1.DajDatumProdaje().DajGodinu()<=p2.DajDatumProdaje().DajGodinu()) return true;
    if(p1.DajDatumProdaje().DajMjesec()==p2.DajDatumProdaje().DajMjesec() && p1.DajDatumProdaje().DajGodinu()<p2.DajDatumProdaje().DajGodinu()) return true;
    if(p1.DajDatumProdaje().DajMjesec()==p2.DajDatumProdaje().DajMjesec() && p1.DajDatumProdaje().DajGodinu()==p2.DajDatumProdaje().DajGodinu() && p1.DajDatumProdaje().DajDan()<p2.DajDatumProdaje().DajDan()) return true;
    return false;
}
bool SkupljiStan(const Prodaja &p1, const Prodaja &p2){
    if(p1.DajCijenuStana()<p2.DajCijenuStana()) return true;
    return false;
}

class Prodaje{
    explicit Prodaje(int max_broj_prodaja);
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
    ~Prodaje();
    Prodaje(const Prodaje &prodaje);
    Prodaje(Prodaje &&prodaje);
    Prodaje &operator =(const Prodaje &prodaje);
    Prodaje &operator =(Prodaje &&prodaje);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje,
     double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,
    const Stan &kupljeni_stan);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, int dan_prodaje,
    int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
     const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,
     int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
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
int main ()
{
	return 0;
}