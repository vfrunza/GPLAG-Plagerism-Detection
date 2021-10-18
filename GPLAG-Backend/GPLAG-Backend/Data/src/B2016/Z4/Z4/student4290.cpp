#include <iostream>
#include <string>
#include <stdexcept>
#include <new>
#include <vector>
#include <memory>
class Datum{
    int d,m,g;
    public:
        Datum(int dan,int mjesec,int godina){Postavi(dan,mjesec,godina);}
        void Postavi(int dan,int mjesec,int godina);
        int DajDan()const{return d;}
        int DajMjesec()const{return m;}
        int DajGodinu()const{return g;}
        void Ispisi()const{std::cout<<d<<"/"<<m<<"/"<<g;}
        friend int VeciManjiIsti(const Datum &d1,const Datum &d2);
};
class Kupac{
    std::string imeprezime;
    Datum rodjenje;
    public:
        Kupac(const std::string &ime_i_prezime,const Datum &datum_rodjenja):rodjenje(datum_rodjenja.DajDan(),datum_rodjenja.DajMjesec(),datum_rodjenja.DajGodinu()){imeprezime=ime_i_prezime;}
        void Postavi(const std::string &ime_i_prezime,const Datum &datum_rodjenja);
        std::string DajImePrezime() const{return imeprezime;}
        Datum DajDatumRodjenja() const{return rodjenje;}
        void Ispisi()const{std::cout<<imeprezime<<"("<<rodjenje.DajDan()<<"/"<<rodjenje.DajMjesec()<<"/"<<rodjenje.DajGodinu()<<")";}
};
class Stan{
    std::string adresa;
    int sprat,brojsoba;
    bool namjesten;
    double kvadratura;
    public:
        Stan(const std::string &adresa,int sprat,int broj_soba,bool namjesten,double kvadratura){Postavi(adresa,sprat,broj_soba,namjesten,kvadratura);}
        void Postavi(const std::string &adresa,int sprat,int broj_soba,bool namjesten,double kvadratura);
        std::string DajAdresu() const{return adresa;}
        int DajSprat()const{return sprat;}
        int DajBrojSoba()const{return brojsoba;}
        bool DajNamjesten()const{return namjesten;}
        double DajKvadraturu()const{return kvadratura;}
        void Ispisi()const;
};
class Prodaja{
    std::string ime_agenta;
    double cijena;
    Datum prodaje;
    Kupac kupac;
    Stan stan;
    public:
        Prodaja(const std::string &ime_agenta_prodaje,double cijena_stana,const Datum &datum_prodaje,const Kupac &kupac_stana,const Stan &kupljeni_stan);
        Prodaja(const std::string &ime_agenta_prodaje,double cijena_stana,int dan_prodaje,int mjesec_prodaje,int godina_prodaje,const std::string &ime_kupca,const Datum &datum_rodjenja_kupca,const std::string &adresa_stana,int sprat_stana,int broj_soba,bool namjesten_stan,double broj_kvadrata);
        void PromijeniKupca(const Kupac &novi_kupac){kupac=novi_kupac;}
        void PromijeniStan(const Stan &novi_stan){stan=novi_stan;}
        void PromijeniDatumKupovine(const Datum &novi_datum){prodaje=novi_datum;}
        void PromijeniCijenuProdaje(const double &nova_cijena){cijena=nova_cijena;}
        void PomjeriDanUnaprijed();
        void PomjeriDanUnazad();
        std::string DajImeAgenta()const{return ime_agenta;}
        std::string DajImeKupca()const{return kupac.DajImePrezime();}
        Datum DajDatumProdaje()const{return prodaje;}
        double DajCijenuStana()const{return cijena;}
        friend bool ProdatPrije(const Prodaja &p1,const Prodaja &p2){return (VeciManjiIsti(p1.DajDatumProdaje(),p2.DajDatumProdaje())==-1);}
        friend bool SkupljiStan(const Prodaja &p1,const Prodaja &p2){return p1.DajCijenuStana()>p2.DajCijenuStana();}
        void Ispisi();
};
class Prodaje{
    std::vector<std::shared_ptr<Prodaja>> pok;
    public:
        Prodaje();
        Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
        Prodaje(const Prodaje &prodaje);
        Prodaje &operator=(const Prodaje &prodaje);
        void RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana,const Datum &datum_prodaje,const Kupac &kupac_stana,const Stan &kupljeni_stan);
        void RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana,int dan_prodaje,int mjesec_prodaje,int godina_prodaje,const std::string &ime_kupca,const Datum &datum_rodjenja_kupca,const std::string &adresa_stana,int sprat_stana,int broj_soba,bool namjesten_stan,double broj_kvadrata);
        void RegistrirajProdaju(Prodaja *prodaja);
        int DajBrojProdaja()const{return pok.size();}
        int DajBrojProdajaNaDatum(const Datum &datum)const;
        int DajBrojProdajaOdAgenta(const std::string &ime_agenta)const;
        Prodaja &DajNajranijuProdaju();
        Prodaja DajNajranijuProdaju()const;
        Prodaja &DajNajskupljuProdaju();
        Prodaja &DajProdaju(int n){if(n>pok.size())throw std::domain_error("Nema toliko prodaja");return *pok[n];}
        Prodaja DajNajskupljuProdaju() const;
        void IsprazniKolekciju();
        void ObrisiNajranijuProdaju();
        void ObrisiProdajeAgenta(const std::string &ime_agenta);
        void ObrisiProdajeNaDatum(const Datum &datum);
        void IspisProdajeNaDatum(const Datum &datum);
        void Ispisi();
};
int VeciManjiIsti(const Datum &d1,const Datum &d2){
    if(d1.DajDan()==d2.DajDan() && d1.DajMjesec()==d2.DajMjesec() && d1.DajGodinu()==d2.DajGodinu())return 0;
    if((d1.g<d2.g || (d1.g==d2.g&&d1.m<d2.m) || (d1.g==d2.g&&d1.m==d2.m&&d1.d<d2.d)))return -1;
    if((d1.g>d2.g || (d1.g==d2.g&&d1.m>d2.m) || (d1.g==d2.g&&d1.m==d2.m&&d1.d>d2.d)))return 1;
}
void Datum::Postavi(int dan,int mjesec,int godina){
    int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if(godina%4==0 && (g%100!=0 || g%400==0))broj_dana[1]++;
    if(godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>broj_dana[mjesec-1])throw std::domain_error("Neispravan datum");
    d=dan;m=mjesec;g=godina;
}
void Kupac::Postavi(const std::string &ime_i_prezime,const Datum &datum_rodjenja){
    rodjenje=Datum(datum_rodjenja.DajDan(),datum_rodjenja.DajMjesec(),datum_rodjenja.DajGodinu());
    for(int i=0;i<ime_i_prezime.size();i++){
        if(ime_i_prezime[i]<='A' && ime_i_prezime[i]>='Z' && ime_i_prezime[i]<='a' && ime_i_prezime[i]>'z' && ime_i_prezime[i]!=' ' && ime_i_prezime[i]!='-' && ime_i_prezime[i]<='0' && ime_i_prezime[i]>='9' && ime_i_prezime[i]!=39)
            throw std::domain_error("Neispravno ime i prezime");
    }
    imeprezime=ime_i_prezime;
}
void Stan::Postavi(const std::string &adresa,int sprat,int broj_soba,bool namjesten,double kvadratura){
    if(sprat<0 || broj_soba<1 || kvadratura<1)throw std::domain_error("Neispravan unos podataka");
    Stan::adresa=adresa;
    Stan::sprat=sprat;
    brojsoba=broj_soba;
    Stan::namjesten=namjesten;
    Stan::kvadratura=kvadratura;
}
void Stan::Ispisi()const{
    if(namjesten){
        if(brojsoba==1)std::cout<<"Stan se nalazi na adresi "<<adresa<<" na "<<sprat<<". spratu i ima "<<brojsoba<<" sobu. Kvadratura stana je "<<kvadratura<< "(m^2) i stan je namjesten.";
        else if(brojsoba>4 )std::cout<<"Stan se nalazi na adresi "<<adresa<<" na "<<sprat<<". spratu i ima "<<brojsoba<<" soba. Kvadratura stana je "<<kvadratura<< "(m^2) i stan je namjesten.";
        else std::cout<<"Stan se nalazi na adresi "<<adresa<<" na "<<sprat<<". spratu i ima "<<brojsoba<<" sobe. Kvadratura stana je "<<kvadratura<< "(m^2) i stan je namjesten.";
    }
    else if(!namjesten){
        if(brojsoba==1)std::cout<<"Stan se nalazi na adresi "<<adresa<<" na "<<sprat<<". spratu i ima "<<brojsoba<<" sobu. Kvadratura stana je "<<kvadratura<< "(m^2) i stan nije namjesten.";
        else if(brojsoba>4 )std::cout<<"Stan se nalazi na adresi "<<adresa<<" na "<<sprat<<". spratu i ima "<<brojsoba<<" soba. Kvadratura stana je "<<kvadratura<< "(m^2) i stan nije namjesten.";
        else std::cout<<"Stan se nalazi na adresi "<<adresa<<" na "<<sprat<<". spratu i ima "<<brojsoba<< " sobe. Kvadratura stana je "<<kvadratura<< "(m^2) i stan nije namjesten.";
    }
}
Prodaja::Prodaja(const std::string &ime_agenta_prodaje,double cijena_stana,const Datum &datum_prodaje,const Kupac &kupac_stana,const Stan &kupljeni_stan):prodaje(datum_prodaje),kupac(kupac_stana),stan(kupljeni_stan){
    ime_agenta=ime_agenta_prodaje;cijena=cijena_stana;
}
Prodaja::Prodaja(const std::string &ime_agenta_prodaje,double cijena_stana,int dan_prodaje,int mjesec_prodaje,int godina_prodaje,const std::string &ime_kupca,
            const Datum &datum_rodjenja_kupca,const std::string &adresa_stana,int sprat_stana,int broj_soba,bool namjesten_stan,double broj_kvadrata):
            stan(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata),kupac(ime_kupca,datum_rodjenja_kupca),prodaje(dan_prodaje,mjesec_prodaje,godina_prodaje){
                ime_agenta=ime_agenta_prodaje;cijena=cijena_stana;
            }
void Prodaja::PomjeriDanUnaprijed(){
    int d=prodaje.DajDan();
    int m=prodaje.DajMjesec();
    int g=prodaje.DajGodinu();
    int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if(g%4==0 && (g%100!=0 || g%400==0))broj_dana[1]++;
    d++;
    if(d>broj_dana[m-1]){m++;d-=broj_dana[m-1];}
    if(m>12){g++;m=1;d=1;}
    prodaje=Datum(d,m,g);
}
void Prodaja::PomjeriDanUnazad(){
    int d=prodaje.DajDan();
    int m=prodaje.DajMjesec();
    int g=prodaje.DajGodinu();
    int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if(g%4==0 && (g%100!=0 || g%400==0))broj_dana[1]++;
    d--;
    if(d<1){m--;d=broj_dana[m-1];}
    if(m<1){g--;m=12;d=31;}
    prodaje=Datum(d,m,g);
}

void Prodaja::Ispisi(){
    std::cout<<std::left<<"Ime agenta: "<<std::right<<ime_agenta<<std::endl;
    std::cout<<std::left<<"Ime kupca: "<<std::right;
    kupac.Ispisi();
    std::cout<<std::endl<<std::left<<"Zakazani datum prodaje: "<<std::right;
    prodaje.Ispisi();
    std::cout<<std::endl<<std::left<<"Cijena stana: "<<std::right<<cijena<<std::endl;
    stan.Ispisi();
}
Prodaje::Prodaje(){
    pok.resize(0);
}

Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja){
    try{
        for(auto i=spisak_prodaja.begin();i!=spisak_prodaja.end();i++){
            pok.emplace_back(std::make_shared<Prodaja>(*i));
        }
    }
    catch(...){
        throw std::bad_alloc();
    }
}
Prodaje::Prodaje(const Prodaje &prodaje){
    for(int i=0;i<prodaje.pok.size();i++)
    pok.emplace_back(std::make_shared<Prodaja>(*prodaje.pok[i]));
}
Prodaje &Prodaje::operator =(const Prodaje &prodaje){
    pok.resize(0);
    for(int i=0;i<prodaje.pok.size();i++)
    pok.emplace_back(std::make_shared<Prodaja>(*prodaje.pok[i]));
    return *this;
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana,const Datum &datum_prodaje,const Kupac &kupac_stana,const Stan &kupljeni_stan){
    pok.emplace_back(std::make_shared<Prodaja>(ime_agenta_prodaje,cijena_stana,datum_prodaje,kupac_stana,kupljeni_stan));
}
void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana,int dan_prodaje,int mjesec_prodaje,int godina_prodaje,const std::string &ime_kupca,
const Datum &datum_rodjenja_kupca,const std::string &adresa_stana,int sprat_stana,int broj_soba,bool namjesten_stan,double broj_kvadrata){
    pok.emplace_back(std::make_shared<Prodaja>(ime_agenta_prodaje,cijena_stana,dan_prodaje,mjesec_prodaje,godina_prodaje,ime_kupca,datum_rodjenja_kupca,adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata));
    }
void Prodaje::RegistrirajProdaju(Prodaja *prodaja){
    pok.emplace_back(prodaja);
}
int Prodaje::DajBrojProdajaNaDatum(const Datum &datum)const{
    int brojac(0);
    for(int i=0;i<pok.size();i++){
        if(VeciManjiIsti(pok[i]->DajDatumProdaje(),datum)==0)brojac++;
    }
    return brojac;
}
int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta)const{
    int brojac(0);
    for(int i=0;i<pok.size();i++){
        if(pok[i]->DajImeAgenta()==ime_agenta)brojac++;
    }
    return brojac;
}
Prodaja &Prodaje::DajNajranijuProdaju(){
    int index=0;
    for(int i=0;i<pok.size();i++){
        if(VeciManjiIsti(pok[i]->DajDatumProdaje(),pok[index]->DajDatumProdaje())==-1)index=i;
    }
    return *pok[index];
}
Prodaja Prodaje::DajNajranijuProdaju() const{
    int index=0;
    for(int i=0;i<pok.size();i++){
        if(VeciManjiIsti(pok[i]->DajDatumProdaje(),pok[index]->DajDatumProdaje())==-1)index=i;
    }
    return *pok[index];
}
Prodaja &Prodaje::DajNajskupljuProdaju(){
    int index=0;
    for(int i=0;i<pok.size();i++){
        if(pok[i]->DajCijenuStana()>pok[index]->DajCijenuStana())index=i;
    }
    return *pok[index];
}
Prodaja Prodaje::DajNajskupljuProdaju()const{
    int index=0;
    for(int i=0;i<pok.size();i++){
        if(pok[i]->DajCijenuStana()>pok[index]->DajCijenuStana())index=i;
    }
    return *pok[index];
}
void Prodaje::IsprazniKolekciju(){
    pok.resize(0);
}
void Prodaje::ObrisiNajranijuProdaju(){
    int index=0;
    for(int i=0;i<pok.size();i++){
        if(ProdatPrije(*(pok[i]),*(pok[index])))index=i;
    }
    for(int i=0;i<pok.size();i++){
        if(i==index){
            for(int j=i;j<pok.size()-1;j++)pok[j]=pok[j+1];
            pok.resize(pok.size()-1);
            break;
        }
    }    
}
void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta){
    for(int i=0;i<pok.size();i++){
        if(ime_agenta==pok[i]->DajImeAgenta()){
            for(int j=i;j<pok.size()-1;j++)pok[i]=pok[j+1];
            pok.resize(pok.size()-1);
            i--;
        }
    }
}
void Prodaje::ObrisiProdajeNaDatum(const Datum &datum){
    for(int i=0;i<pok.size();i++){
        if(VeciManjiIsti(datum,pok[i]->DajDatumProdaje())==0){
            for(int j=i;j<pok.size()-1;j++)pok[i]=pok[j+1];
            pok.resize(pok.size()-1);
            i--;
        }
    }
}
void Prodaje::IspisProdajeNaDatum(const Datum &datum){
    for(int i=0;i<pok.size();i++){
        if(VeciManjiIsti(datum,pok[i]->DajDatumProdaje())==0)pok[i]->Ispisi();
    }
} 
void Prodaje::Ispisi(){
    for(int i=0;i<pok.size();i++)pok[i]->Ispisi();
}
int main (){
    Prodaje p;
    p.RegistrirajProdaju("Kerim",170000,11,3,2004,"Selma",{11,2,1997},"Hivze 23",3,3,false,46);
    p.RegistrirajProdaju("Amir",270000,12,6,2008,"Amira",{13,6,1994},"Avde 123",1,4,true,72);
    Prodaje s(p);
    p.RegistrirajProdaju("Alma",120000,12,12,2012,"Ajisa",{13,9,1979},"Makarska 20",2,2,false,34);
    p.Ispisi();
    s.Ispisi();
    
	return 0;
}