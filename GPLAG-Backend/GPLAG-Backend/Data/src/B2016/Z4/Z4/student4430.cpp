/B 2016/2017, Zadaća 4, Zadatak 4
//Napomena: testovi ce biti dostupni dan pred rok!

#include <iostream>
#include <stdexcept>
using namespace std; 
class Datum{
    int dan, mjesec, godina; 
public:
    Datum(int dan, int mjesec, int godina);
    void Postavi(int dan, int mjesec, int godina);
    int DajDan() const;
    int DajMjesec() const;
    int DajGodinu() const;
    void Ispisi() const;

};
Datum::Datum(int dan, int mjesec, int godina){
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0) broj_dana[1]++;
    if(godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > broj_dana[mjesec - 1])
        throw domain_error("Neispravan datum");
    Datum::dan=dan; 
    Datum::mjesec=mjesec; 
    Datum::godina=godina; 
}
void Datum::Postavi(int dan, int mjesec, int godina){
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0) broj_dana[1]++;
    if(godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > broj_dana[mjesec - 1])
        throw domain_error("Neispravan datum");
    Datum::dan=dan; 
    Datum::mjesec=mjesec; 
    Datum::godina=godina; 
}
int Datum::DajDan() const {
    return dan; 
}
int Datum::DajMjesec() const{
    return mjesec;
}
int Datum::DajGodinu() const{
    return godina; 
}
void Datum::Ispisi() const{
    cout << DajDan() << "/" << DajMjesec() << "/" << DajGodinu(); 
}
class Kupac{
  Datum datum_rodj; 
  string ime_i_prezime; 
public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    string DajImePrezime() const;
    Datum DajDatumRodjenja() const;
    void Ispisi() const;
};
Kupac::Kupac(const string &ime_i_prezime, const Datum &datum_rodjenja) : datum_rodj(datum_rodjenja){
    for(int i=0; i<ime_i_prezime.size(); i++){
        if(ime_i_prezime[i]!='-' && ime_i_prezime[i]!=' ' && ime_i_prezime[i]<'0' && ime_i_prezime[i]>'9' && ime_i_prezime[i]<'a' && ime_i_prezime[i]>'z' && ime_i_prezime[i]<'A' && ime_i_prezime[i]>'Z')
            throw domain_error ("Neispravno ime i prezime"); 
    }
}
void Kupac::Postavi(const string &ime_i_prezime, const Datum &datum_rodjenja){
     for(int i=0; i<ime_i_prezime.size(); i++){
        if(ime_i_prezime[i]!='-' && ime_i_prezime[i]!=' ' && ime_i_prezime[i]<'0' && ime_i_prezime[i]>'9' && ime_i_prezime[i]<'a' && ime_i_prezime[i]>'z' && ime_i_prezime[i]<'A' && ime_i_prezime[i]>'Z')
            throw domain_error ("Neispravno ime i prezime"); 
    }
}
string Kupac::DajImePrezime() const{
    return ime_i_prezime; 
}
Datum Kupac::DajDatumRodjenja() const{
    return datum_rodj; 
}
void Kupac::Ispisi() const{
    cout << ime_i_prezime << " (" << datum_rodj.Datum::DajDan() << "/" << datum_rodj.Datum::DajMjesec() << "/" << datum_rodj.Datum::DajGodinu() << ")";
}
class Stan{
    string adresa; 
    int sprat, broj_soba; 
    bool namjesten; 
    double kvadratura; 
public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
    std::string DajAdresu() const;
    int DajSprat() const;
    int DajBrojSoba() const;
    bool DajNamjesten() const;
    double DajKvadraturu() const;
    void Ispisi() const;
};
Stan::Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
    if(sprat<0 || broj_soba<0 || kvadratura<0) throw domain_error ("Neispravan unos podataka"); 
    Stan::adresa=adresa; 
    Stan::sprat=sprat; 
    Stan::broj_soba=broj_soba; 
    Stan::namjesten=namjesten; 
    Stan::kvadratura=kvadratura; 
}
void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
     if(sprat<0 || broj_soba<0 || kvadratura<0) throw domain_error ("Neispravan unos podataka"); 
    Stan::adresa=adresa; 
    Stan::sprat=sprat; 
    Stan::broj_soba=broj_soba; 
    Stan::namjesten=namjesten; 
    Stan::kvadratura=kvadratura; 
}
string Stan::DajAdresu() const{
    return adresa; 
}
int Stan::DajSprat() const {
    return sprat; 
}
int Stan::DajBrojSoba() const {
    return broj_soba; 
}
bool Stan::DajNamjesten() const {
    return namjesten; 
}
double Stan::DajKvadraturu() const{
    return kvadratura; 
}
void Stan::Ispisi() const {
    cout << "Stan se nalazi na adresi " << DajAdresu() << " na " << DajSprat() << ". i ima " << DajBrojSoba();
    if(DajBrojSoba()%10==1) cout << " sobu."; 
    else if(DajBrojSoba()%10==2 || DajBrojSoba()%10==3 || DajBrojSoba()%10==4) cout << " sobe."; 
    else cout << " soba."; 
    cout << endl; 
    cout << "Kvadratura stana je " << DajKvadraturu() << " (m^2) i stan "; 
    if(DajNamjesten()) cout << "je namjesten."; 
    else cout << "nije namjesten."; 
}
class Prodaja{
    string ime_agenta_prodaje, ime_kupca, adresa_stana;
    double cijena_stana;
    int dan_prodaje, mjesec_prodaje, godina_prodaje;
    Stan kupljeni_stan;
    Datum datum_rodjenja_kupca, datum_prodaje;
    Kupac kupac_stana;
public:
   // Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
  // Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void PromijeniKupca(const Kupac &novi_kupac);
    void PromijeniStan(const Stan &novi_stan);
    void PromijeniDatumKupovine(const Datum &novi_datum);
    void PromijeniCijenuProdaje(const double &nova_cijena);
    //void PomjeriDanUnaprijed();
    //void PomjeriDanUnazad();
    string DajImeAgenta() const;
    string DajImeKupca() const;
    Datum DajDatumProdaje() const;
    double DajCijenuStana() const;
    //friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    //friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
    //void Ispisi() const;
};
/*Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan){
        
        Prodaja::ime_agenta_prodaje=ime_agenta_prodaje; 
        Prodaja::cijena_stana=cijena_stana; 
        Prodaja::datum_prodaje=datum_prodaje;
        Prodaja::kupac_stana=kupac_stana;
        Prodaja::kupljeni_stan=kupljeni_stan;
    }*/
//::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata){
    

void Prodaja::PromijeniKupca(const Kupac &novi_kupac){
        Prodaja::kupac_stana=novi_kupac; 
    }
void Prodaja::PromijeniStan(const Stan &novi_stan){
        Prodaja::kupljeni_stan=novi_stan;
    }
void Prodaja::PromijeniDatumKupovine(const Datum &novi_datum){
        Prodaja::datum_prodaje=novi_datum;
    }
void Prodaja::PromijeniCijenuProdaje(const double &nova_cijena){
        Prodaja::cijena_stana=nova_cijena;
    }
//void Prodaja::PomjeriDanUnaprijed(){
//void Prodaja::PomjeriDanUnazad();
string Prodaja::DajImeAgenta() const{
        return ime_agenta_prodaje;
    }
string Prodaja::DajImeKupca() const{
        return ime_kupca;
    }
Datum Prodaja::DajDatumProdaje() const{
        return datum_prodaje;
    }
double Prodaja::DajCijenuStana() const{
        return cijena_stana;
    }
//void Prodaja::Ispisi() const;

int main ()
{
	return 0;
}