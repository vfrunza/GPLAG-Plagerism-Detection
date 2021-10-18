/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
class Datum{
    int d,m,g;
    void Test(int d,int m,int g){
        int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(g % 4 == 0 && g % 100 != 0 || g % 400 == 0) broj_dana[1]++;
        if(g < 1 || d < 1 || m < 1 || m > 12 || d > broj_dana[m - 1])
        throw std::domain_error("Neispravan datum!");  
    }
public:    
    Datum(int dan, int mjesec, int godina) {
        Test(d,m,g);
         d=dan; m=mjesec; g=godina;
}
    void Postavi(int dan, int mjesec, int godina){
         Test(d,m,g);
         d = dan; m=mjesec; g=godina ;
    }
    int DajDan() const  {   return d;}
    int DajMjesec() const{ return m;} 
    int DajGodinu() const{  return g;}
    void Ispisi() const{ std::cout<<d<<"/"<<m<<"/"<<g;}   
};
class Kupac{
    std::string i_i_p;
    Datum dr;
    void Test(std::string ime){
        for(int i=0;i<ime.length();i++){
            if(ime[i]!=' '&&!(ime[i]>='a'&&ime[i]<='z')&&!(ime[i]>='A'&&ime[i]<='Z')&&!(ime[i]>='0'&&ime[i]<='9')&&ime[i]!='-')
                throw std::domain_error("Neispravno ime i prezime");
        }
    }
public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja):dr(datum_rodjenja){
        i_i_p=ime_i_prezime;
    }
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja){
        Test(ime_i_prezime); 
        dr=datum_rodjenja; 
        i_i_p=ime_i_prezime;
    }
    std::string DajImePrezime() const{  
        return i_i_p;
    }
    Datum DajDatumRodjenja() const {
        return dr;
    }
    void Ispisi() const{    
        std::cout<<i_i_p<<"(";
        dr.Ispisi();
        std::cout<<")";
}
};
class Stan{
    std::string adresa;
    bool namjesten;
    double kvadratura;
    int broj_soba, sprat;
public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
        if(kvadratura<0||broj_soba<0||sprat<0)   throw std::domain_error("Neispravan unos podataka");
        Stan::adresa=adresa;
        Stan::namjesten=namjesten;
        Stan::kvadratura=kvadratura;
        Stan::broj_soba=broj_soba;
        Stan::sprat=sprat;
    }
    void Postavi(const std::string &adresa, int sprat, int broj_soba,bool namjesten, double kvadratura){
        if(kvadratura<0||broj_soba<0||sprat<0)   throw std::domain_error("Neispravan unos podataka");
        Stan::adresa=adresa;
        Stan::namjesten=namjesten;
        Stan::kvadratura=kvadratura;
        Stan::broj_soba=broj_soba;
        Stan::sprat=sprat;
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
        char c;
        if(broj_soba>4) c='a';
        else if(broj_soba==1)   c='u';
        else
            c='e';
        std::cout<<"Stan se nalazi na adresi "<<adresa<<" na "<<sprat<<" spratu i ima "<<broj_soba<<" sob"<<c<<". Kvadratura stana je "<<kvadratura<<" ";
    }
};

class Prodaja{
    std::string ime_agenta_prodaje;
    Datum datum_prodaje;
    Kupac kupac_stana;
    Stan kupljeni_stan;
    double cijena_stana;
public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,const Stan &kupljeni_stan):datum_prodaje(datum_prodaje),kupac_stana(kupac_stana), kupljeni_stan(kupljeni_stan) {
        Prodaja::cijena_stana=cijena_stana;
        Prodaja::datum_prodaje=datum_prodaje;
    }
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba,bool namjesten_stan, double broj_kvadrata)
    :datum_prodaje(dan_prodaje,mjesec_prodaje,godina_prodaje),kupac_stana(ime_kupca,datum_rodjenja_kupca),  kupljeni_stan(adresa_stana, sprat_stana,broj_soba, namjesten_stan,broj_kvadrata){
        Prodaja::ime_agenta_prodaje=ime_agenta_prodaje;
        Prodaja::cijena_stana=cijena_stana;
    }
    void PromijeniKupca(const Kupac &novi_kupac){
        Prodaja::kupac_stana=novi_kupac;
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
    void PomjeriDanUnaprijed(){
        int dan=datum_prodaje.DajDan(), mj=datum_prodaje.DajMjesec(), g=datum_prodaje.DajGodinu();
        int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(g % 4 == 0 && g % 100 != 0 || g % 400 == 0) broj_dana[1]++;
        if(dan>broj_dana[mj--])
        {
            mj++;
            dan=1;
        }
        if(mj>12)
        {
            mj=1;
            g++;
        }
        datum_prodaje.Postavi(dan,mj,g);
    }
    void PomjeriDanUnazad(){
        int dan=datum_prodaje.DajDan(), mj=datum_prodaje.DajMjesec(), g=datum_prodaje.DajGodinu();
        int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(g % 4 == 0 && g % 100 != 0 || g % 400 == 0) broj_dana[1]++;
        if(dan<1)
        {
            mj--;
                if(mj<1)
                {
                    mj=12;
                    g--;
                }
            dan=broj_dana[mj-1];
        }
        datum_prodaje.Postavi(dan,mj,g);
    }
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
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2){
        int d1(p1.datum_prodaje.DajDan()),d2(p2.datum_prodaje.DajDan()), m1(p1.datum_prodaje.DajMjesec()),m2(p2.datum_prodaje.DajMjesec()), g1(p1.datum_prodaje.DajGodinu()), g2(p2.datum_prodaje.DajGodinu());
        if(g1<g2||g1==g2&&m1<m2||g1==g2&&m1==m2&&d1<d2)
            return true;
        return false;
    }
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2){
        if(p1.cijena_stana>p2.cijena_stana)
            return true;
        return false;
    }
    void Ispisi() const{
        std::cout<<"Ime agenta: "<<DajImeAgenta()<<std::endl<<"Ime kupca: ";
        kupac_stana.Ispisi();
        std::cout<<std::endl<<"Zakazani datum prodaje: ";
        datum_prodaje.Ispisi();
        std::cout<<"Cijena stana: "<<cijena_stana<<std::endl<<"Informacije o stanu: "<<std::endl;
        kupljeni_stan.Ispisi();
    }

};
class Prodaje{
    
public:
    explicit Prodaje(int max_broj_prodaja);
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
    ~Prodaje();
    Prodaje(const Prodaje &prodaje);
    Prodaje(Prodaje &&prodaje);
    Prodaje &operator =(const Prodaje &prodaje);
    Prodaje &operator =(Prodaje &&prodaje);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,const Stan &kupljeni_stan);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, int dan_prodaje,int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
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