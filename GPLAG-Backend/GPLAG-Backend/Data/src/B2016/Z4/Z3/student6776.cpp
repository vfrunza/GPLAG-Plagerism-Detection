/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <new>
#include <string>
#include <iomanip>

class Datum{
  int dan,mjesec,godina;
public:
    Datum(int dan, int mjesec, int godina){Postavi(dan,mjesec,godina);}
    void Postavi(int d, int m, int god);
    int DajDan() const {return dan;}
    int DajMjesec() const {return mjesec;};
    int DajGodinu() const {return godina;};
    void Ispisi() const {std::cout<<"("<<DajDan()<<"/"<<DajMjesec()<<"/"<<DajGodinu()<<")";}
    friend class Kupac;
    friend class Prodaja;
};
void Datum::Postavi(int d, int m, int god){
        int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
        if(god%4==0 && (god%100!=0 || god%400==0))   {broj_dana[1]++;}
        if(god<1 || m <1 || m>12 || d<1 || d>broj_dana[m-1]){
            throw std::domain_error("Neispravan datum");
        }
        dan=d; mjesec=m; godina=god;
    }
class Kupac{
    std::string ime_i_prezime;
    Datum datum_rodjenja;
    bool IspravanKarakter(char slovo){
    if(!((slovo>='A' && slovo<='Z') || (slovo>='a' && slovo<='z') || (slovo>='0' &&slovo<='9') || slovo==' ' || slovo=='\'' || slovo=='-')) return false;
    return true;
}
    bool IspravnoIme(std::string ime){
    for(int i=0;i<ime.length();i++){
        if(IspravanKarakter(ime[i])==false) return false;
    }
    return true;
}    
public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja):datum_rodjenja(datum_rodjenja){
        Postavi(ime_i_prezime, datum_rodjenja);
    }
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja){
        if(IspravnoIme(ime_i_prezime)==false){throw std::domain_error("Neispravno ime");}
        Kupac::ime_i_prezime=ime_i_prezime; Kupac::datum_rodjenja=datum_rodjenja;
    }
    std::string DajImePrezime()const{return ime_i_prezime;}
    Datum DajDatumRodjenja() const {return datum_rodjenja;};
    void Ispisi() const {std::cout<<DajImePrezime()<<" ";   datum_rodjenja.Ispisi();}
    friend bool IspravnoIme(std::string);
    friend class Prodaja;
};
class Stan{
    std::string adresa;
    int sprat;
    int broj_soba;
    bool namjesten;
    double kvadratura;
public:    
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
        Postavi(adresa,sprat,broj_soba,namjesten,kvadratura);
    }
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
        if(sprat<0 || broj_soba<0 || kvadratura<0) throw std::domain_error("Neispravan unos podataka");
        Stan::adresa=adresa;    Stan::sprat=sprat;  Stan::broj_soba=broj_soba;  Stan::namjesten=namjesten;  Stan::kvadratura=kvadratura;
    }
    std::string DajAdresu() const {return adresa;}
    int DajSprat() const {return sprat;}
    int DajBrojSoba() const {return broj_soba;}
    bool DajNamjesten() const {return namjesten;}
    double DajKvadraturu() const {return kvadratura;}
    void Ispisi() const;
};
void Stan::Ispisi() const{
        std::cout<<"Stan se nalazi na adresi "<<DajAdresu()<<" na "<<DajSprat()<<". spratu i ima "<<DajBrojSoba();
        {
            if(DajBrojSoba()%10==1 && DajBrojSoba()!=11 && DajBrojSoba()%100!=11) {std::cout<<" sobu.";}
            if(DajBrojSoba()%10>=2 && DajBrojSoba()%10<=4){std::cout<<" sobe.";}
            if(((DajBrojSoba()%10>=5 && DajBrojSoba()%10<=9) || DajBrojSoba()%10==0)){std::cout<<" soba.";}
        }
        std::cout<<std::endl;
        std::cout<<"Kvadratura stana je "<<DajKvadraturu()<<" (m^2) i stan ";
        if(DajNamjesten()){std::cout<<"je namjesten.";}
        if(!(DajNamjesten())) {std::cout<<"nije namjesten.";}
    }
class Prodaja{
    std::string ime_agenta_prodaje;
    double cijena_stana;
    Datum datum_prodaje;
    Kupac kupac_stana;
    Stan kupljeni_stan;
    
void Normalizirajdatum(Datum &datum){
    int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
    if(datum.godina%4==0 && (datum.godina%100!=0 || datum.godina%400==0))   {broj_dana[1]++;}
    if(datum.dan>broj_dana[datum.mjesec-1]){datum.dan=1;datum.mjesec++;}
    if(datum.mjesec>12){datum.godina++; datum.mjesec=1;}
    
    if(datum.dan==0){datum.mjesec--;
        if(datum.mjesec==0){datum.godina--; datum.mjesec=12;  datum.dan=broj_dana[datum.mjesec-1];}
        datum.dan=broj_dana[datum.mjesec-1];
    }
    datum_prodaje.dan=datum.dan; datum_prodaje.mjesec=datum.mjesec; datum_prodaje.godina=datum.godina;
}    
public:    
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, 
    const Datum &datum_prodaje, const Kupac &kupac_stana,
    const Stan &kupljeni_stan):datum_prodaje(datum_prodaje),kupac_stana(kupac_stana),kupljeni_stan(kupljeni_stan){
        Prodaja::ime_agenta_prodaje=ime_agenta_prodaje;
        Prodaja::cijena_stana=cijena_stana;
        Prodaja::datum_prodaje=datum_prodaje;
        Prodaja::kupac_stana=kupac_stana;
        Prodaja::kupljeni_stan=kupljeni_stan;
    }
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, 
        int dan_prodaje, int mjesec_prodaje, int godina_prodaje, 
        std::string &ime_kupca, const Datum &datum_rodjenja_kupca,
        const std::string &adresa_stana, int sprat_stana, int broj_soba,
        bool namjesten_stan, double broj_kvadrata):datum_prodaje(dan_prodaje,mjesec_prodaje,godina_prodaje),
        kupac_stana(ime_kupca, datum_rodjenja_kupca),kupljeni_stan(adresa_stana,sprat_stana,broj_soba,
        namjesten_stan,broj_kvadrata){
            Prodaja::ime_agenta_prodaje=ime_agenta_prodaje;
            Prodaja::cijena_stana=cijena_stana;
            Prodaja::datum_prodaje=datum_prodaje;
            Prodaja::kupac_stana=kupac_stana;
            Prodaja::kupljeni_stan=kupljeni_stan;
        }
    void PromjeniKupca(const Kupac &novi_kupac){Prodaja::kupac_stana=novi_kupac;}
    void PromjeniStan(const Stan &novi_stan){Prodaja::kupljeni_stan=novi_stan;}
    void PromjeniDatumKupovine(const Datum &novi_datum){Prodaja::datum_prodaje=novi_datum;}
    void PomjeriDanUnaprijed(){datum_prodaje.dan++; Normalizirajdatum(datum_prodaje);}
    void PomjeriDanUnazad(){datum_prodaje.dan--; Normalizirajdatum(datum_prodaje);}
    std::string DajImeAgenta() const {return ime_agenta_prodaje;}
    std::string DajImeKupca() const {return kupac_stana.ime_i_prezime;}
    Datum DajDatumProdaje() const {return datum_prodaje;}
    double DajCijenuStana() const {return cijena_stana;}
    void Ispisi() const;
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
};
void Prodaja::Ispisi() const {
    std::cout<<std::left<<std::setw(40)<<"Ime agenta:"<<DajImeAgenta()
    <<std::left<<std::setw(41)<<"\nIme kupca: "; kupac_stana.Ispisi();
    std::cout<<std::left<<std::setw(41)<<"\nZakazani datum prodaje:"; datum_prodaje.Ispisi();
    std::cout<<std::left<<std::setw(41)<<"\nCijena stana:"<<DajCijenuStana()
    <<"\nInformacije o stanu:"; kupljeni_stan.Ispisi();
}
//bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);


int main (){
    try{
        std::string ime_agenta_prodaje{"Niko Nikic"};
        
        std::string ime_kupca{"Mujo Mujic"};
        Datum datum_kupca(21,9,1982);
        Kupac buyer(ime_kupca, datum_kupca);
        
        double cijena_stana(78958);
        Datum datum_prodaje(31,12,2016);
        
        
        std::string adresa{"Hamdije Cemerlica 14"};
        int sprat=5;
        int broj_soba=10;
        bool namj=true;
        double kvad=35.45;
        Stan Apartment(adresa, sprat, broj_soba, namj, kvad);


        Prodaja sell(ime_agenta_prodaje,cijena_stana,datum_prodaje,buyer,Apartment);
        sell.Ispisi();
        std::cout<<std::endl;
        std::cout<<std::endl;        
        sell.PomjeriDanUnaprijed();
        sell.Ispisi();
    }catch(std::domain_error izu){
        std::cout<<izu.what();
    }
	return 0;
}