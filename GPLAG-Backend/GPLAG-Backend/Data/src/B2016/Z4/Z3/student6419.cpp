/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
class Datum {
        int dan, mjesec, godina;
    public:
        Datum(int dan, int mjesec, int godina) { Postavi(dan, mjesec, godina);}
        void Postavi(int dan, int mjesec, int godina);
        int DajDan() const {return dan;}
        int DajMjesec() const {return mjesec; }
        int DajGodinu() const {return godina; }
        void Ispisi() const {std::cout << dan << "/" << mjesec << "/" << godina;}
};
void Datum::Postavi(int dan, int mjesec, int godina) {
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};    
    if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0) broj_dana[1]++;
    if(godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > broj_dana[mjesec - 1]) throw std::domain_error("Neispravan datum");
    Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina; 
}
class Kupac {
        std::string ime_i_prezime;
        Datum datum_rodjenja;
    public:
        Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja): datum_rodjenja(datum_rodjenja) { Postavi(ime_i_prezime, datum_rodjenja);}
        void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
        std::string DajImePrezime() const { return ime_i_prezime; }
        Datum DajDatumRodjenja() const { return datum_rodjenja; }
        void Ispisi() const { std::cout << ime_i_prezime << " ("; datum_rodjenja.Ispisi(); std::cout << ")";} 
};
void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja) {
    for(int i(0); i<ime_i_prezime.length(); i++) {
        if(!((ime_i_prezime[i]>='A' && ime_i_prezime[i]<='Z') || (ime_i_prezime[i]>='a' && ime_i_prezime[i]<='z') || (ime_i_prezime[i]>='0' && ime_i_prezime[i]<='9') || ime_i_prezime[i]==' ' || ime_i_prezime[i]=='-' || ime_i_prezime[i]=='\'')) throw std::domain_error("Neispravno ime i prezime");
    }
    Kupac::ime_i_prezime=ime_i_prezime;
    Kupac::datum_rodjenja=datum_rodjenja;
}
class Stan {
        std::string adresa;
        int sprat, broj_soba;
        bool namjesten;
        double kvadratura;
    public:
        Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {Postavi(adresa, sprat, broj_soba, namjesten, kvadratura);};
        void Postavi(const std::string &adresa, int sprat, int broj_soba,bool namjesten, double kvadratura);
        std::string DajAdresu() const {return adresa; }
        int DajSprat() const { return sprat; }
        int DajBrojSoba() const { return broj_soba; }
        bool DajNamjesten() const { return namjesten; }
        double DajKvadraturu() const { return kvadratura; }
        void Ispisi() const;
};
void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba,bool namjesten, double kvadratura) {
    if(sprat<0 || broj_soba<0 || kvadratura<0) throw std::domain_error("Neispravan unos podataka");
    Stan::adresa=adresa; 
    Stan::sprat=sprat; 
    Stan::broj_soba=broj_soba; 
    Stan::namjesten=namjesten; 
    Stan::kvadratura=kvadratura;
}
void Stan::Ispisi() const {
    std::cout << "Stan se nalazi na adresi " << adresa << " na " << sprat << ". spratu i ima " << broj_soba;
    if(broj_soba==1) std::cout << " sobu." << std::endl;
    else if(broj_soba==2 || broj_soba==3 || broj_soba==4) std::cout << " sobe." << std::endl;
    else std::cout << " soba." << std::endl;
    std::cout << "Kvadratura stana je " << kvadratura << " (m^2) i stan ";
    if(namjesten) std::cout << "je namjesten.";
    else std::cout << "nije namjesten.";
}
class Prodaja {
        std::string ime_agenta_prodaje;
        double cijena_stana, broj_kvadrata;
        Datum datum_prodaje{1, 1, 2001};
        Kupac kupac_stana{"Stafa Kralj", Datum(1, 1, 1)};
        Stan kupljeni_stan{"Marsala TITA 10", 5, 5, true, 80};
        int dan_prodaje, mjesec_prodaje, godina_prodaje;
        bool namjesten_stan;
    public:
        Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, 
        const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan) {
            Prodaja::ime_agenta_prodaje=ime_agenta_prodaje;
            Prodaja::cijena_stana=cijena_stana;
            Prodaja::datum_prodaje=datum_prodaje;
            Prodaja::kupac_stana=kupac_stana;
            Prodaja::kupljeni_stan=kupljeni_stan;
        }
        Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, 
        int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, 
        const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, 
        int broj_soba, bool namjesten_stan, double broj_kvadrata) {
            Prodaja::ime_agenta_prodaje=ime_agenta_prodaje;
            Prodaja::cijena_stana=cijena_stana;
            Prodaja::dan_prodaje=dan_prodaje; Prodaja::mjesec_prodaje=mjesec_prodaje; Prodaja::godina_prodaje=godina_prodaje;
            Prodaja::kupac_stana=Kupac(ime_kupca, datum_rodjenja_kupca);
            Prodaja::kupljeni_stan=Stan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata);
        }
        void PromijeniKupca(const Kupac &novi_kupac) { kupac_stana=novi_kupac; }//
        void PromijeniStan(const Stan &novi_stan) {kupljeni_stan=novi_stan; }//
        void PromijeniDatumKupovine(const Datum &novi_datum) { datum_prodaje=novi_datum; }//
        void PromijeniCijenuProdaje(const double &nova_cijena) { cijena_stana=nova_cijena; }//
        void PomjeriDanUnaprijed(); //
        void PomjeriDanUnazad(); //
        std::string DajImeAgenta() const { return ime_agenta_prodaje; }//
        std::string DajImeKupca() const {return kupac_stana.DajImePrezime(); }//
        Datum DajDatumProdaje() const { return datum_prodaje; }//
        double DajCijenuStana() const { return cijena_stana; }//
        friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2); //
        friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);//
        void Ispisi() const ;//
};
void Prodaja::PomjeriDanUnazad() {
    if(dan_prodaje==1 && (mjesec_prodaje==1 || mjesec_prodaje==3 || mjesec_prodaje==5 || mjesec_prodaje==7 || mjesec_prodaje==8 || mjesec_prodaje==10 || mjesec_prodaje==12)) {
        if(mjesec_prodaje==1) {
            dan_prodaje=31;
            mjesec_prodaje = 12;
            godina_prodaje--;
        }
        else if(mjesec_prodaje==8) {
            dan_prodaje=31;
            mjesec_prodaje--;
        }
        else if(mjesec_prodaje==3) {
            dan_prodaje=28;
            mjesec_prodaje--;
        }
        else {
            dan_prodaje=30;
            mjesec_prodaje--;
        }
    }
    else if(dan_prodaje==1 && (mjesec_prodaje==4 || mjesec_prodaje==6 || mjesec_prodaje==9 || mjesec_prodaje==11)) {
        dan_prodaje=31;
        mjesec_prodaje--;
    }
    else dan_prodaje--;
}
void Prodaja::Ispisi()  const {
    std::cout << "Ime agenta:             " << ime_agenta_prodaje << std::endl;
    std::cout << "Ime kupca:              ";
    kupac_stana.Ispisi();
    std::cout << std::endl;
    std::cout << "Zakazani datum prodaje: ";
    datum_prodaje.Ispisi();
    std::cout << std::endl;
    std::cout << "Cijena stana:           " << cijena_stana << std::endl;
    std::cout << "Informacije o stanu:" << std::endl;
    kupljeni_stan.Ispisi();
}
void Prodaja::PomjeriDanUnaprijed(){ 
    if(dan_prodaje==31 && (mjesec_prodaje==1 || mjesec_prodaje==3 || mjesec_prodaje==5 || mjesec_prodaje==7 || mjesec_prodaje==8 || mjesec_prodaje==10 || mjesec_prodaje==12)) {
        dan_prodaje=1;
        mjesec_prodaje++;
        if(mjesec_prodaje==13) godina_prodaje++;
    }
    else if(dan_prodaje==30 && (mjesec_prodaje==4 || mjesec_prodaje==6 || mjesec_prodaje==9 || mjesec_prodaje==11)) {
        dan_prodaje=1;
        mjesec_prodaje++;
    }
    else if((dan_prodaje==29 || dan_prodaje==28) && mjesec_prodaje==2) {
        dan_prodaje=1;
        mjesec_prodaje++;
    }
    else dan_prodaje++;
}
bool ProdatPrije(const Prodaja &p1, const Prodaja &p2) {
    if(p1.godina_prodaje==p2.godina_prodaje) {
        if(p1.mjesec_prodaje== p2.mjesec_prodaje) {
            if(p1.dan_prodaje<p2.dan_prodaje) return true;
            else return false;
        }
        if(p1.mjesec_prodaje<p2.mjesec_prodaje) return true;
        else return false;
    }
    if(p1.godina_prodaje<p2.godina_prodaje) return true;
    return false;
}
bool SkupljiStan(const Prodaja &p1, const Prodaja &p2) {
    if(p1.cijena_stana>p2.cijena_stana) return true;
    return false;
}
class Prodaje {
    explicit Prodaje(int max_broj_prodaja);   
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);   
    ~Prodaje();   
    Prodaje(const Prodaje &prodaje);   
    Prodaje(Prodaje &&prodaje);   
    Prodaje &operator =(const Prodaje &prodaje);  
    Prodaje &operator =(Prodaje &&prodaje);   
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, 
    const Kupac &kupac_stana,const Stan &kupljeni_stan);   
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, int dan_prodaje, int mjesec_prodaje, 
    int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, 
    int broj_soba, bool namjesten_stan, double broj_kvadrata);   
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
int main () {
    std::vector<Stan> Stanovi;
    std::vector<Kupac> Kupci;
    std::cout << "Dobrodosli!" << std::endl << std::endl << std::endl;
    for(;;) {
    std::cout << "Izaberite opciju:" << std::endl << " 0 - kraj" << std::endl << " 1 - uredjivanje stanova" << std::endl <<
        " 2 - uredjivanje kupaca" << std::endl << " 3 - uredjivanje prodaja" << std::endl;
    int opcija1;
    std::cin >> opcija1;
    if(opcija1==0) {
        std::cout << std::endl << std::endl << "Dovidjenja!";
        return 0;
    }
    else if(opcija1==1) {
        for(;;) {
            std::cout << "Izaberite opciju:" << std::endl << " 0 - nazad" << std::endl << " 1 - dodavanje stana" << std::endl <<  " 2 - uredjivanje stanova" << std::endl << 
            " 3 - ispis svih stanova" << std::endl << " 4 - kraj" << std::endl;
            int opcija2;
            std::cin >> opcija2;
            if(opcija2==0) break;
            else if(opcija2==1) {
                for(;;) {
                    std::string adresa;
                    int sprat, broj_soba;
                    int namj;
                    bool namjesten(false);
                    double kvadratura;
                    std::cin.ignore();
                    std::cout << "Unesite adresu: ";
                    std::getline(std::cin, adresa);
                    std::cout << "Unesite sprat: ";
                    std::cin >> sprat;
                    std::cout << "Unesite broj soba: ";
                    std::cin >> broj_soba;
                    std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                    std::cin >> namj;
                    if(namj==1) namjesten=true;
                    std::cout << "Unesite kvadraturu: ";
                    std::cin >> kvadratura;
                    try {
                        if(namj<0 || namj>1) throw std::domain_error("Neispravan unos podataka");
                    }
                    catch(std::domain_error e) {
                        std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet." << std::endl << std::endl;
                        continue;
                    }
                    try {
                        auto s=Stan(adresa, sprat, broj_soba, namjesten, kvadratura);
                        Stanovi.push_back(s);
                        std::cout << "Stan je uspjesno dodan!" << std::endl;
                        break;
                    }
                    catch(std::domain_error e) {
                        std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet." << std::endl;
                    }
                }
            }
            else if(opcija2==2) {
                std::cout << "Odaberite stan. Dostupni stanovi su:" << std::endl;
                for(int i(0); i<Stanovi.size(); i++) {
                    std::cout << " " << i+1 << " - "; 
                    Stanovi[i].Ispisi();
                    std::cout << std::endl;
                }
                int koji;
                std::cin >> koji;
                for(;;) {
                    std::string adresa;
                    int sprat, broj_soba;
                    int namj;
                    bool namjesten(false);
                    double kvadratura;
                    std::cin.ignore();
                    std::cout << "Unesite adresu: ";
                    std::getline(std::cin, adresa);
                    std::cout << "Unesite sprat: ";
                    std::cin >> sprat;
                    std::cout << "Unesite broj soba: ";
                    std::cin >> broj_soba;
                    std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                    std::cin >> namj;
                    if(namj==1) namjesten=true;
                    std::cout << "Unesite kvadraturu: ";
                    std::cin >> kvadratura;
                    try {
                        if(namj<0 || namj>1) throw std::domain_error("Neispravan unos podataka");
                    }
                    catch(std::domain_error e) {
                        std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet." << std::endl << std::endl;
                        continue;
                    }
                    try {
                        auto s=Stan(adresa, sprat, broj_soba, namjesten, kvadratura);
                        Stanovi[koji-1]=s;
                        std::cout << "Stan je uspjesno izmijenjen!" << std::endl;
                        break;
                    }
                    catch(std::domain_error e) {
                        std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet." << std::endl;
                    }
                }
            }
            else if(opcija2==3) {
                for(int i(0); i<Stanovi.size(); i++) {
                    std::cout << i+1 << ". ";
                    Stanovi[i].Ispisi();
                    std::cout << std::endl;
                }
            }
            else if(opcija2==4) {
                std::cout << std::endl << std::endl << "Dovidjenja!";
                return 0;
            }
        }
    }
    else if(opcija1==2) {
        for(;;) {
            std::cout << "Izaberite opciju:" << std::endl << " 0 - nazad" << std::endl << " 1 - dodavanje kupca" << std::endl <<  " 2 - uredjivanje kupaca" << std::endl << 
            " 3 - ispis svih kupaca" << std::endl << " 4 - kraj" << std::endl;
            int opcija2;
            std::cin >> opcija2;
            if(opcija2==0) break;
            else if(opcija2==1) {
                for(;;) {
                    std::string ime_kupca;
                    int dan, mjesec, godina;
                    std::cin.ignore();
                    std::cout << "Unesite ime i prezime kupca: ";
                    std::getline(std::cin, ime_kupca);
                    std::cout << "Unesite datum rodjenja (formata d/m/g): ";
                    std::cin >> dan;
                    std::cin.get();
                    std::cin >> mjesec;
                    std::cin.get();
                    std::cin >> godina;
                    try {
                        auto k=Kupac(ime_kupca, Datum(dan, mjesec, godina));
                        Kupci.push_back(k);
                        std::cout << "Kupac je uspjesno dodan!" << std::endl << std::endl;
                        break;
                    }
                    catch(std::domain_error e) {
                        std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet." << std::endl;
                    }
                }
            }
                else if(opcija2==2) {
                    std::cout << "Odaberite kupca kojeg zelite urediti. Dostupni kupci su: " <<std::endl;
                    for(int i(0); i<Kupci.size(); i++) {
                        std::cout << " " << i+1 << " - ";
                        Kupci[i].Ispisi();
                        std::cout << std::endl;
                    }
                    int koji;
                    std::cin >> koji;
                    for(;;) {
                        std::string ime_kupca;
                        int dan, mjesec, godina;
                        std::cin.ignore();
                        std::cout << "Unesite ime i prezime kupca: ";
                        std::getline(std::cin, ime_kupca);
                        std::cout << "Unesite datum rodjenja (formata d/m/g): ";
                        std::cin >> dan;
                        std::cin.get();
                        std::cin >> mjesec;
                        std::cin.get();
                        std::cin >> godina;
                        try {
                            auto k=Kupac(ime_kupca, Datum(dan, mjesec, godina));
                            Kupci[koji-1]=k;
                            std::cout << "Kupac je uspjesno izmijenjen!" << std::endl <<std::endl;
                            break;
                        }
                        catch(std::domain_error e) {
                            std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet." << std::endl;
                        }
                    }
                }
                else if(opcija2==3) {
                    for(int i(0); i<Kupci.size(); i++) {
                        Kupci[i].Ispisi();
                        std::cout << std::endl;
                    }
                }
                else if(opcija2==4) return 0;
            }
        }
    }
    return 0;
}