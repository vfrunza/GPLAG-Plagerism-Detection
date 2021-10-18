/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <initializer_list>
#include <algorithm>

class Datum {
    private:
       int d, m, g;
       void Test(int d, int m, int g) {
            int br_d []{31,29,31,30,31,30,31,31,30,31,30,31};
            if((g%100==0 && g%4!=0) || g%400!=0)
                br_d[1]--;
            if(g<1 || m<1 || m > 12 || d<1 || d>br_d[m-1])
                throw std::domain_error("Neispravan datum");
       }
    public:
    Datum(int dan, int mjesec, int godina):d(dan),m(mjesec), g(godina){
        Test(dan, mjesec, godina);
        d = dan;
        m = mjesec;
        g = godina;
    }
    void Postavi (int dan, int mjesec, int godina) {
        Test(dan, mjesec, godina);
        d = dan;
        m = mjesec;
        g = godina;
    }
    int DajDan() const { return d; }
    int DajMjesec() const { return m; }
    int DajGodinu() const { return g; }
    void Ispisi () const {
        std::cout<<d<<"/"<<mjesec<<"/"<<godina<<std::endl;
    }   
};

class Kupac {
    private:
        std::string ime_i_prezime;
        Datum datum;
    public:
        Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja):datum(datum_rodjenja){
            for(int i = 0; i<ime_i_prezime.length(); i++){
                if(!((ime_i_prezime[i]>='a' && ime_i_prezime[i]<='z') || (ime_i_prezime[i]>='A' && ime_i_prezime[i]<='Z') || ime_i_prezime[i]==' ' ))
                    throw std::domain_error ("Neispravno ime i prezime");
            }
            Kupac::ime_i_prezime=ime_i_prezime;
            datum = datum_rodjenja;
        }
        void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja){
          
        Kupac::ime_i_prezime = ime_i_prezime;
        datum = datum_rodjenja;
        }
        std::string DajImePrezime() const {
            return ime_i_prezime;
        }
        Datum DajDatumRodjenja () const {
            return datum;
        }
        void Ispisi() const {
            std::cout<<ime_i_prezime<<"("<<datum.dan<<"/"<<datum.mjesec<<"/"<<datum.godina<<")"<<std::endl;
        }
};

class Stan {
    private:
        std::string adresa;
        int sprat;
        int broj_soba;
        bool namjesten;
    double kvadratura;
   public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
        if(sprat <0 || broj_soba <0 || kvadratura <=0 || (int)namjesten != 1 || (int)namjesten != 0)
            throw std::domain_error("Neispravan unos podataka");
            Stan::adresa = adresa;
            Stan::sprat = sprat;
            Stan::broj_soba = broj_soba;
            Stan::namjesten = namjesten;
            Stan::kvadratura = kvadratura;
    }
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
        if(sprat <0 || broj_soba <0 || kvadratura <=0 || (int)namjesten != 1 || (int)namjesten != 0)
            throw std::domain_error("Neispravan unos podataka");
            Stan::adresa = adresa;
            Stan::sprat = sprat;
            Stan::broj_soba = broj_soba;
            Stan::namjesten = namjesten;
            Stan::kvadratura = kvadratura;
    
    }
    void std::string DajAdresu()const {
        return adresa;
        int DajSprat() const {
            return sprat;
        }
        int DajBrojSoba () const {
            return broj_soba;
        }
        bool DajNamjesten() const{
            return namjesten;
        }
        double DajKvadraturu () const {
            return kvadratura;
        }
        void Ispisi() const {
            std::cout << "Stan se nalazi na adresi "<< DajAdresu()<< " na " << DajSprat() << ". spratu i ima " << DajBrojSoba() << " soba." << std::endl;
        if(namjesten) std::cout << "Kvadratura stana je " << DajKvadraturu() << " (m^2) i stan je namjesten." << std::endl;
        else std::cout << "Kvadratura stana je " << DajKvadraturu() << " (m^2) i stan nije namjesten." << std::endl;
        }    
    };
    
    class Prodaja {
    private: 
        std::string ime_agenta_prodaje;
        double cijena_stana;
        Datum datumprodaje;
       ;
    public:
    Prodaja(const std::string &ime_agenta_prodaje,double cijena_stana,const Datum &datum_prodaje,const Kupac &kupac_stana,const Stan &kupljeni_stan): datumprodaje(datum_prodaje),kupacstana(kupac_stana),kupljenistan(kupljeni_stan){Prodaja::ime_agenta_prodaje=ime_agenta_prodaje; Prodaja::cijena_stana=cijena_stana;datumprodaje=datum_prodaje;kupacstana=kupac_stana;kupljenistan=kupljeni_stan;}
    Prodaja(const std::string &ime_agenta_prodaje,double cijena_stana,int dan_prodaje, int mjesec_prodaje, int godina_prodaje,std::string &ime_kupca, const Datum &datum_rodjenja_kupca,const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata): datumprodaje(dan_prodaje,mjesec_prodaje,godina_prodaje),kupacstana(ime_kupca,datum_rodjenja_kupca),kupljenistan(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata){Prodaja::ime_agenta_prodaje=ime_agenta_prodaje;Prodaja::cijena_stana=cijena_stana;datumprodaje.dan=dan_prodaje;datumprodaje.mjesec=mjesec_prodaje;datumprodaje.godina=godina_prodaje;kupacstana.ime_i_prezime=ime_kupca;kupacstana.datum=datum_rodjenja_kupca;kupljenistan.adresa=adresa_stana;kupljenistan.sprat=sprat_stana;kupljenistan.broj_soba=broj_soba;kupljenistan.namjesten=namjesten_stan;kupljenistan.kvadratura=broj_kvadrata;}
    void PromijeniKupca(const Kupac &novi_kupac){kupacstana=novi_kupac;}
    void PromijeniStan(const Stan &novi_stan){kupljenistan=novi_stan;}
    void PromijeniDatumKupovine(const Datum &novi_datum){datumprodaje=novi_datum;}
    void PromijeniCijenuProdaje(const double &nova_cijena){cijena_stana=nova_cijena;}   
    void PomjeriDanUnaprijed(){datumprodaje.dan+=1;}
    void PomjeriDanUnazad(){datumprodaje.dan-=1;}
    };

    
};



int main ()
{
	return 0;
}