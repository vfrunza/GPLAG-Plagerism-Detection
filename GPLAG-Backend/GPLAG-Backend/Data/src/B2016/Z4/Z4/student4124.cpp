/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <string>
#include <iomanip>
#include <initializer_list>
#include <algorithm>
#include <vector>
#include <memory>

class Datum {
    int dan, mjesec, godina;
    static void TestDatum(int d, int m, int g) {
        int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if((g%4==0 and g%100!=0) or g%400==0) broj_dana[1]++;
        if(g<1 or m<1 or m>12 or d<1 or d>broj_dana[m-1])
            throw std::domain_error("Neispravan datum");
    }
public:
    Datum(int dan, int mjesec, int godina) { Postavi(dan,mjesec,godina); }
    void Postavi(int dan, int mjesec, int godina) {
        TestDatum(dan, mjesec, godina);
        Datum::dan=dan;
        Datum::mjesec=mjesec;
        Datum::godina=godina;
    }
    int DajDan() const {return dan;}
    int DajMjesec() const {return mjesec;}
    int DajGodinu() const {return godina;}
    void Ispisi() const {std::cout << dan << "/" << mjesec << "/" << godina;}
};

class Kupac {
    std::string ime_i_prezime;
    Datum datum_rodjenja;
    static void TestImePrezime(const std::string &ime_i_prezime) {
        for(char x : ime_i_prezime)
            if(!((x>='A' and x<='Z') or (x>='a' and x<='z') or x==' ' or x=='"' or x=='-'))
                throw std::domain_error("Neispravno ime i prezime");
    }
public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja) : datum_rodjenja(datum_rodjenja) {
        Kupac::ime_i_prezime = ime_i_prezime;
    }
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja) {
        TestImePrezime(ime_i_prezime);
        Kupac::ime_i_prezime=ime_i_prezime;
        Kupac::datum_rodjenja=datum_rodjenja;
    }
    std::string DajImePrezime() const {return ime_i_prezime;}
    Datum DajDatumRodjenja() const{return datum_rodjenja;}
    void Ispisi() const { std::cout << ime_i_prezime << " ("; datum_rodjenja.Ispisi(); std::cout << ")";}
};

class Stan {
    std::string adresa;
    int sprat, broj_soba;
    bool namjesten;
    double kvadratura;
public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
        Postavi(adresa, sprat, broj_soba, namjesten, kvadratura);
    }
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
        if(sprat<0 or broj_soba<0 or kvadratura<0) throw std::domain_error("Neispravan unos podataka");
        Stan::adresa=adresa;
        Stan::sprat=sprat;
        Stan::broj_soba=broj_soba;
        Stan::namjesten=namjesten;
        Stan::kvadratura=kvadratura;
    }
    std::string DajAdresu() const {return adresa;}
    int DajSprat() const {return sprat;}
    int DajBrojSoba() const {return broj_soba;}
    bool DajNamjesten() const {return namjesten;}
    double DajKvadraturu() const {return kvadratura;}
    void Ispisi() const;
};

void Stan::Ispisi() const {
    std::cout << "Stan se nalazi na adresi " << adresa << " na " << sprat << ". spratu i ima " << broj_soba << " ";
    if(broj_soba==1) std::cout << "sobu.";
        else if(broj_soba==2 or broj_soba==3 or broj_soba==4) std::cout << "sobe.";
            else std::cout << "soba.";
    std::cout << " Kvadratura stana je " << kvadratura << " (m^2) i stan ";
    if(namjesten) std::cout << "je namjesten.";
        else std::cout << "nije namjesten.";
}

class Prodaja {
    std::string ime_agenta_prodaje;
    double cijena_stana;
    Datum datum_prodaje;
    Kupac kupac_stana;
    Stan kupljeni_stan;
public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, 
        const Kupac &kupac_stana, const Stan &kupljeni_stan) : ime_agenta_prodaje(ime_agenta_prodaje),
            cijena_stana(cijena_stana), datum_prodaje(datum_prodaje), kupac_stana(kupac_stana),
            kupljeni_stan(kupljeni_stan) {}
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje,
        int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, 
        const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) :
            ime_agenta_prodaje(ime_agenta_prodaje), cijena_stana(cijena_stana),
            datum_prodaje(dan_prodaje, mjesec_prodaje, godina_prodaje), kupac_stana(ime_kupca, datum_rodjenja_kupca),
            kupljeni_stan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata) {}
    void PromijeniKupca(const Kupac &novi_kupac) {kupac_stana=novi_kupac;}
    void PromijeniStan(const Stan &novi_stan) {kupljeni_stan=novi_stan;}
    void PromijeniDatumKupovine(const Datum &novi_datum) {datum_prodaje=novi_datum;}
    void PromijeniCijenuProdaje(const double &nova_cijena) {cijena_stana=nova_cijena;}
    void PromijeniImeAgenta(const std::string &novo_ime) {ime_agenta_prodaje=novo_ime;}
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImeAgenta() const {return ime_agenta_prodaje;}
    std::string DajImeKupca() const {return kupac_stana.DajImePrezime();}
    Datum DajDatumProdaje() const {return datum_prodaje;}
    double DajCijenuStana() const {return cijena_stana;}
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
    void Ispisi() const;
};

void Prodaja::PomjeriDanUnaprijed() {
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((datum_prodaje.DajGodinu()%4==0 and datum_prodaje.DajGodinu()%100!=0) or datum_prodaje.DajGodinu()%400==0) broj_dana[1]++;
    int novi_dan = datum_prodaje.DajDan()+1;
    int novi_mjesec(datum_prodaje.DajMjesec()), nova_godina(datum_prodaje.DajGodinu());
    if(novi_dan>broj_dana[datum_prodaje.DajMjesec()-1]) {novi_mjesec = datum_prodaje.DajMjesec()+1; novi_dan=0;}
    if(novi_mjesec==13) {novi_mjesec=0; nova_godina++;}
    datum_prodaje.Postavi(novi_dan,novi_mjesec,nova_godina);
}

void Prodaja::PomjeriDanUnazad() {
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((datum_prodaje.DajGodinu()%4==0 and datum_prodaje.DajGodinu()%100!=0) or datum_prodaje.DajGodinu()%400==0) broj_dana[1]++;
    int novi_dan = datum_prodaje.DajDan()-1;
    int novi_mjesec(datum_prodaje.DajMjesec()), nova_godina(datum_prodaje.DajGodinu());
    if(novi_dan==0) {
        novi_mjesec--;
        if(novi_mjesec==0) {
            novi_mjesec=12;
            nova_godina--;
        }
        novi_dan=broj_dana[novi_mjesec-1];
    }
    datum_prodaje.Postavi(novi_dan,novi_mjesec,nova_godina);
}

bool ProdatPrije(const Prodaja &p1, const Prodaja &p2) {
    Datum d1(p1.DajDatumProdaje()), d2(p2.DajDatumProdaje());
    if(d1.DajGodinu()<d2.DajGodinu()) return true;
        else if(d1.DajGodinu()>d2.DajGodinu()) return false;
            else {
                if(d1.DajMjesec()<d2.DajMjesec()) return true;
                    else if(d1.DajMjesec()>d2.DajMjesec()) return false;
                        else {
                            if(d1.DajDan()<d2.DajDan()) return true;
                                else if(d1.DajDan()>d2.DajDan()) return false;
                                    else return false;
                        }
            }
}

bool SkupljiStan(const Prodaja &p1, const Prodaja &p2) {
    if(p1.DajCijenuStana()<p2.DajCijenuStana()) return true;
    return false;
}

void Prodaja::Ispisi() const {
    std::cout << std::left << std::setw(20) << "Ime agenta: " << std::right << std::setw(5) << ime_agenta_prodaje
        << std::endl << std::left << std::setw(20) << "Ime kupca: ";
    kupac_stana.Ispisi();
    std::cout << std::endl << std::left << std::setw(20) << "Zakazani datum prodaje: ";
    datum_prodaje.Ispisi();
    std::cout << std::endl << std::left << std::setw(20) << "Cijena stana: " << std::right << std::setw(5) << cijena_stana
        << std::endl << "Informacije o stanu: " << std::endl;
    kupljeni_stan.Ispisi();
}

class Prodaje {
    std::vector<std::shared_ptr<Prodaja>> prodaje;
public:
    explicit Prodaje() = default;
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
    Prodaje(const Prodaje &prodaje);
    Prodaje(Prodaje &&prodaje);
    Prodaje &operator =(const Prodaje &prodaje);
    Prodaje &operator =(Prodaje &&prodaje);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje,
        const Kupac &kupac_stana, const Stan &kupljeni_stan);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje,
        int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,
        int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void RegistrirajProdaju(std::shared_ptr<Prodaja> prodaja);
    Prodaja &DajProdaju(int redni_broj) const;
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
    
Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja) : prodaje(spisak_prodaja.size()) {
    int i(0);
    for(auto it=spisak_prodaja.begin(); it!=spisak_prodaja.end(); it++) {
        prodaje[i]=std::make_shared<Prodaja>(*it);
        i++;
    }
}

Prodaje::Prodaje(const Prodaje &prodaje) : prodaje(prodaje.prodaje.size()) {
    for(int i(0); i<prodaje.prodaje.size(); i++)
        Prodaje::prodaje[i]=std::make_shared<Prodaja>(*prodaje.prodaje[i]);
}

Prodaje &Prodaje::operator =(const Prodaje &prodaje) {
    Prodaje::prodaje.resize(prodaje.prodaje.size());
    for(int i(0); i<Prodaje::prodaje.size(); i++) Prodaje::prodaje[i]=std::make_shared<Prodaja>(*prodaje.prodaje[i]);
    return *this;
}

Prodaje::Prodaje(Prodaje &&prodaje) : prodaje(prodaje.prodaje.size()) {
    Prodaje::prodaje=std::move(prodaje.prodaje);
}

Prodaje &Prodaje::operator =(Prodaje &&prodaje) {
    Prodaje::prodaje = std::move(prodaje.prodaje);
    return *this;
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje,
        const Kupac &kupac_stana, const Stan &kupljeni_stan) {
            Prodaja p1(ime_agenta_prodaje, cijena_stana, datum_prodaje, kupac_stana, kupljeni_stan);
            prodaje.push_back(std::make_shared<Prodaja>(p1));
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje,
    int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,
    int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) {
        Prodaja p1(ime_agenta_prodaje, cijena_stana, dan_prodaje, mjesec_prodaje, godina_prodaje, ime_kupca,
            datum_rodjenja_kupca, adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata);
        prodaje.push_back(std::make_shared<Prodaja>(p1));
}

void Prodaje::RegistrirajProdaju(std::shared_ptr<Prodaja> prodaja) {
    prodaje.push_back(prodaja);
}

Prodaja &Prodaje::DajProdaju(int redni_broj) const {
    if(redni_broj>prodaje.size()) throw std::domain_error("Redni broj nije validan");
    return *prodaje[redni_broj-1];
}

int Prodaje::DajBrojProdaja() const {
    return prodaje.size();
}
    
int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const {
    return std::count_if(prodaje.begin(), prodaje.end(),
        [datum] (std::shared_ptr<Prodaja> p) {if(p->DajDatumProdaje().DajDan()==datum.DajDan()
            and p->DajDatumProdaje().DajMjesec()==datum.DajMjesec() and p->DajDatumProdaje().DajGodinu()==datum.DajGodinu()) return true; return false;});
}

int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const {
    return std::count_if(prodaje.begin(), prodaje.end(), [ime_agenta] (std::shared_ptr<Prodaja> p) {if(p->DajImeAgenta()==ime_agenta) return true; return false;});
}

Prodaja &Prodaje::DajNajranijuProdaju() {
    if(prodaje.size()==0) throw std::domain_error("Nema registriranih prodaja");
    return **std::min_element(prodaje.begin(), prodaje.end(),
        [] (std::shared_ptr<Prodaja> p1, std::shared_ptr<Prodaja> p2) {
            if(p1->DajDatumProdaje().DajGodinu()>p2->DajDatumProdaje().DajGodinu()) return false;
            else if(p1->DajDatumProdaje().DajGodinu()<p2->DajDatumProdaje().DajGodinu()) return true;
            else
                if(p1->DajDatumProdaje().DajMjesec()>p2->DajDatumProdaje().DajMjesec()) return false;
                else if(p1->DajDatumProdaje().DajMjesec()<p2->DajDatumProdaje().DajMjesec()) return true;
                else
                    if(p1->DajDatumProdaje().DajDan()>p2->DajDatumProdaje().DajDan()) return false;
                    else if(p1->DajDatumProdaje().DajDan()<p2->DajDatumProdaje().DajDan()) return true;
            return false;
        });
}
    
Prodaja Prodaje::DajNajranijuProdaju() const {
    if(prodaje.size()==0) throw std::domain_error("Nema registriranih prodaja");
    return **std::min_element(prodaje.begin(), prodaje.end(),
        [] (std::shared_ptr<Prodaja> p1, std::shared_ptr<Prodaja> p2) {
            if(p1->DajDatumProdaje().DajGodinu()>p2->DajDatumProdaje().DajGodinu()) return false;
            else if(p1->DajDatumProdaje().DajGodinu()<p2->DajDatumProdaje().DajGodinu()) return true;
            else
                if(p1->DajDatumProdaje().DajMjesec()>p2->DajDatumProdaje().DajMjesec()) return false;
                else if(p1->DajDatumProdaje().DajMjesec()<p2->DajDatumProdaje().DajMjesec()) return true;
                else
                    if(p1->DajDatumProdaje().DajDan()>p2->DajDatumProdaje().DajDan()) return false;
                    else if(p1->DajDatumProdaje().DajDan()<p2->DajDatumProdaje().DajDan()) return true;
            return false;
        });
}
    
Prodaja &Prodaje::DajNajskupljuProdaju() {
    if(prodaje.size()==0) throw std::domain_error("Nema registriranih prodaja");
    return **std::max_element(prodaje.begin(), prodaje.end(),
        [] (std::shared_ptr<Prodaja> p1, std::shared_ptr<Prodaja> p2) {
            if(p1->DajCijenuStana() < p2->DajCijenuStana()) return false;
            else if(p1->DajCijenuStana() > p2->DajCijenuStana()) return true;
            return false;
        });
}

Prodaja Prodaje::DajNajskupljuProdaju() const {
    if(prodaje.size()==0) throw std::domain_error("Nema registriranih prodaja");
    Prodaja p = **std::max_element(prodaje.begin(), prodaje.end(),
        [] (std::shared_ptr<Prodaja> p1, std::shared_ptr<Prodaja> p2) {
            if(p1->DajCijenuStana() < p2->DajCijenuStana()) return false;
            else if(p1->DajCijenuStana() > p2->DajCijenuStana()) return true;
            return false;
        });
    return p;
}

void Prodaje::IsprazniKolekciju() {
    for(int i(0); i<prodaje.size(); i++)
        prodaje[i]=nullptr;
}

void Prodaje::ObrisiNajranijuProdaju() {
    if(prodaje.size()==0) throw std::range_error("Prazna kolekcija");
    for(int i(0); i<prodaje.size(); i++)
        if(&(*prodaje[i])==&DajNajranijuProdaju())
            prodaje[i]=nullptr;
}

void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta) {
    if(prodaje.size()==0) return;
    for(int i(0); i<prodaje.size(); i++)
        if(prodaje[i]->DajImeAgenta()==ime_agenta) {
            prodaje[i]=nullptr;
        }
}

void Prodaje::ObrisiProdajeNaDatum(const Datum &datum) {
    if(prodaje.size()==0) return;
    for(int i(0); i<prodaje.size(); i++)
        if(prodaje[i]->DajDatumProdaje().DajDan()==datum.DajDan() and
            prodaje[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec() and
            prodaje[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu()) {
            prodaje[i]=nullptr;
        }
}

void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const {
    std::vector<Prodaja> nove;
    for(int i(0); i<prodaje.size(); i++)
        if(prodaje[i]->DajDatumProdaje().DajDan()==datum.DajDan() and
            prodaje[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec() and
            prodaje[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu()) {
            nove.push_back(*prodaje[i]);
        }
    std::sort(nove.begin(), nove.end(), [] (const Prodaja p1, const Prodaja p2)
            {if(p1.DajImeKupca()>p2.DajImeKupca()) return true; return false;});
    for(int i(0); i<nove.size(); i++) {
        nove[i].Ispisi(); std::cout << std::endl; }
}

void Prodaje::IspisiSveProdaje() const {
    std::vector<Prodaja> nove;
    for(int i(0); i<prodaje.size(); i++)
        nove.push_back(*prodaje[i]);
    std::sort(nove.begin(), nove.end(), [] (const Prodaja p1, const Prodaja p2)
            {if(p1.DajDatumProdaje().DajGodinu()>p2.DajDatumProdaje().DajGodinu()) return false;
            else if(p1.DajDatumProdaje().DajGodinu()<p2.DajDatumProdaje().DajGodinu()) return true;
            else
                if(p1.DajDatumProdaje().DajMjesec()>p2.DajDatumProdaje().DajMjesec()) return false;
                else if(p1.DajDatumProdaje().DajMjesec()<p2.DajDatumProdaje().DajMjesec()) return true;
                else
                    if(p1.DajDatumProdaje().DajDan()>p2.DajDatumProdaje().DajDan()) return false;
                    else if(p1.DajDatumProdaje().DajDan()<p2.DajDatumProdaje().DajDan()) return true;
            if(p1.DajImeKupca()>p2.DajImeKupca()) return true; return false;});
}


int main ()
{
    std::cout << "Dobrodosli!" << std::endl << " " << std::endl << " " << std::endl;
    Prodaje p;
    std::vector<Stan> stanovi;
    std::vector<Kupac> kupci;
    std::vector<Prodaja> prodaje;
    while(1) {
        std::cout << "Izaberite opciju:" << std::endl << " 0 - kraj" << std::endl << " 1 - uredjivanje stanova"
            << std::endl << " 2 - uredjivanje kupaca" << std::endl << " 3 - uredjivanje prodaja" << std::endl;
        int n, a;
        std::cin >> n;
        if(n==0) {
            break;
        } else if(n==1) {
            std::string adresa; int sprat, broj_soba; bool namjesten; double kvadratura;
            while(1) {
                std::cout << "Izaberite opciju:" << std::endl << " 0 - nazad" << std::endl << " 1 - dodavanje stana"
                << std::endl << " 2 - uredjivanje stanova" << std::endl << " 3 - ispis svih stanova" << std::endl
                << " 4 - kraj" << std::endl;
                std::cin >> a;
                if(a==0) {
                    break;
                } else if(a==1) {
                    while(1) {
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        std::cout << "Unesite adresu: ";
                        std::getline(std::cin, adresa);
                        std::cout << "Unesite sprat: ";
                        std::cin >> sprat;
                        std::cout << "Unesite broj soba: ";
                        std::cin >> broj_soba;
                        int nam;
                        std::cin.ignore(1000, '\n');
                        std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                        std::cin >> nam;
                        if(nam==1) namjesten=true;
                        else if(nam==0) namjesten=false;
                        std::cout << "Unesite kvadraturu: ";
                        std::cin >> kvadratura;
                        try{
                          if(nam!=1 and nam!=0) throw std::domain_error("Neispravan unos podataka");
                          Stan stan(adresa, sprat, broj_soba, namjesten, kvadratura);
                          stanovi.push_back(stan);
                          std::cout << "Stan je uspjesno dodan!" << std::endl << std::endl;
                          break;
                        }
                        catch(std::domain_error a) {
                            std::cout << "Izuzetak: " << a.what() << ". Molimo unesite opet." << std::endl;
                        }
                    }
                } else if(a==2) {
                    std::cout << "Odaberite stan. Dostupni stanovi su:" << std::endl;
                    for(int i(0); i<stanovi.size(); i++) {
                        std::cout << " " << i+1 << " - ";
                        stanovi[i].Ispisi();
                        std::cout << std::endl;
                    }
                    std::cout << std::endl;
                    int t; std::cin >> t;
                    std::cout << "Odaberite polje koje zelite urediti:" << std::endl << " 0 - nazad" << std::endl
                              << " 1 - adresa" << std::endl << " 2 - sprat" << std::endl << " 3 - broj soba"
                              << std::endl << " 4 - da li je stan namjesten" << std::endl << " 5 - kvadratura" << std::endl
                              << " 6 - sve" << std::endl;
                    int t2; std::cin >> t2;
                    if(t2 == 0) continue;
                    else if(t2==1) {
                        
                    } else if(t2==2) {
                        
                    } else if(t2==3) {
                        
                    } else if(t2==4) {
                        
                    } else if(t2==5) {
                        while(1) {
                            double kvadratura2;
                            std::cout << "Unesite kvadraturu: ";
                            std::cin >> kvadratura2;
                            try {
                                stanovi[t-1].Postavi(stanovi[t-1].DajAdresu(), stanovi[t-1].DajSprat(), 
                                    stanovi[t-1].DajBrojSoba(), stanovi[t-1].DajNamjesten(), kvadratura2);
                                std::cout << "Stan je uspjesno izmijenjen!" << std::endl << std::endl;
                                break;
                            }
                            catch(std::domain_error a) {
                                std::cout << "Izuzetak: " << a.what() << ". Molimo unesite opet." << std::endl;
                            }
                        }
                    } else if(t2==6) {
                        while(1) {
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        std::cout << "Unesite adresu: ";
                        std::string adresa2; std::getline(std::cin, adresa2);
                        std::cout << "Unesite sprat: ";
                        int sprat2; std::cin >> sprat2;
                        std::cout << "Unesite broj soba: ";
                        int broj_soba2; std::cin >> broj_soba2;
                        std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                        int temp2; std::cin >> temp2; bool namjesten2;
                        if(temp2==1) namjesten2=true;
                        else if(temp2==0) namjesten2=false;
                        std::cout << "Unesite kvadraturu: ";
                        double kvadratura2; std::cin >> kvadratura2;
                        try{
                          if(temp2!=1 and temp2!=2) throw std::domain_error("Neispravan unos podataka");
                          stanovi[t-1].Postavi(adresa2, sprat2, broj_soba2, namjesten2, kvadratura2);
                          std::cout << "Stan je uspjesno izmijenjen!" << std::endl << std::endl;
                          break;
                        }
                        catch(std::domain_error a) {
                            std::cout << "Izuzetak: " << a.what() << ". Molimo unesite opet." << std::endl;
                        }
                    }
                    }
                    
                } else if(a==3) {
                    for(int i(0); i<stanovi.size(); i++) {
                        std::cout << i+1 << ". ";
                        stanovi[i].Ispisi();
                        std::cout << std::endl;
                    }
                    std::cout << std::endl;
                } else if(a==4) {
                    return 0;
                }
            }
        } else if(n==2) {
            Datum datum_rodjenja(1,1,1);
            Kupac kupac("", Datum(1,1,1));
            while(1) {
                std::cout << "Izaberite opciju:" << std::endl << " 0 - nazad" << std::endl << " 1 - dodavanje kupca"
                    << std::endl << " 2 - uredjivanje kupaca" << std::endl << " 3 - ispis svih kupaca" 
                    << std::endl << " 4 - kraj" << std::endl;
                int t; std::cin >> t;
                if(t==0) {
                    break;
                } else if(t==1) {
                    while(1) {
                    std::cin.ignore(1000, '\n');
                    std::cout << "Unesite ime i prezime kupca: ";
                    std::string ime_kupca; std::getline(std::cin, ime_kupca);
                    std::cout << "Unesite datum rodjenja (formata d/m/g): ";
                    int d,m,g; char z1, z2; std::cin >> d >> z1 >> m >> z2 >> g;
                        try {
                        datum_rodjenja.Postavi(d,m,g);
                        kupac.Postavi(ime_kupca, datum_rodjenja);
                        kupci.push_back(kupac);
                        std::cout << "Kupac je uspjesno dodan!" << std::endl << std::endl;
                        break;
                        }
                        catch(std::domain_error a) {
                            std::cout << "Izuzetak: " << a.what() << ". Molimo unesite opet." << std::endl;
                        }
                    }
                } else if(t==2) {
                    std::cout << "Odaberite kupca kojeg zelite urediti. Dostupni kupci su:" << std::endl;
                    for(int i(0); i<kupci.size(); i++) {
                        std::cout << " " << i+1 << " - "; kupci[i].Ispisi();
                        std::cout << std::endl;
                    }
                    int t2; std::cin >> t2;
                    std::cin.ignore(1000, '\n');
                    std::cout << "Unesite ime i prezime kupca: ";
                    std::string ime_kupca; std::getline(std::cin, ime_kupca);
                    std::cout << "Unesite datum rodjenja (formata d/m/g): ";
                    int d,m,g; char z1, z2; std::cin >> d >> z1 >> m >> z2 >> g;
                    if(z1=='/' and z2=='/') {
                        try {
                        datum_rodjenja.Postavi(d,m,g);
                        kupci[t2-1].Postavi(ime_kupca, datum_rodjenja);
                        std::cout << "Kupac je uspjesno izmijenjen!" << std::endl << std::endl;
                        }
                        catch(std::domain_error a) {
                            std::cout << "Izuzetak: " << a.what() << ". Molimo unesite opet." << std::endl;
                        }
                    }
                } else if(t==3) {
                    for(Kupac x : kupci) {
                        x.Ispisi();
                        std::cout << std::endl;
                    }
                    std::cout << std::endl;
                } else if(t==4) {
                    return 0;
                }
            }
        } else if(n==3) {
            std::string ime_agenta; int d,m,g; char z1,z2; int d2,m2,g2;  std::string ime_kupca;  int cijena;  std::string adresa;  int sprat; 
             int broj_soba;  int temp; double kvadratura;
             Kupac kupac("", Datum(1,1,1)); Datum dat_prodaje(1,1,1), dat_rodjenja(1,1,1); Prodaja prodaja("", 0, Datum(1,1,1), Kupac("", Datum(1,1,1)), Stan("", 0, 0, false, 0)); Stan stan("", 0, 0, false, 0);
            while(1) {
                std::cout << "Izaberite opciju:" << std::endl << " 0 - nazad" << std::endl << " 1 - dodavanje prodaje"
                    << std::endl << " 2 - uredjivanje prodaje" << std::endl << " 3 - ispis prodaja" << std::endl << " 4 - brisanje prodaja" << std::endl << " 5 - kraj" << std::endl;
                int t; std::cin >> t;
                if(t==0) {
                    break;
                } else if(t==1) {
                    while(1) {
                    std::cout << "Izaberite opciju:" << std::endl << " 0 - nazad" << std::endl << " 1 - dodavanje potpuno nove prodaje"
                    << std::endl << " 2 - dodavanje nove prodaje na osnovu arhive" << std::endl << " 3 - kraj" << std::endl;
                    int t2; std::cin >> t2;
                    if(t2==0) {
                        break;
                    } else if(t2==1) {
                        std::cin.ignore(1000, '\n');
                        std::cout << "Unesite ime i prezime agenta prodaje: ";
                        std::getline(std::cin, ime_agenta);
                        std::cout << "Unesite datum prodaje (formata d/m/g): ";
                        std::cin >> d >> z1 >> m >> z2 >> g;
                        std::cout << "Unesite cijenu stana: "; std::cin >> cijena;
                        std::cin.ignore(1000, '\n');
                        std::cout << "Unesite ime kupca: ";
                        std::getline(std::cin, ime_kupca);
                        std::cout << "Unesite datum rodjenja kupca (formata d/m/g): ";
                        std::cin >> d2 >> z1 >> m2 >> z2 >> g2;
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        std::cout << "Unesite adresu: ";
                        std::getline(std::cin, adresa);
                        std::cout << "Unesite sprat: "; std::cin >> sprat;
                        std::cout << "Unesite broj soba: "; std::cin >> broj_soba;
                        std::cout << "Da li je stan namjesten (1 - da, 0 - ne): "; std::cin >> temp;
                        std::cout << "Unesite kvadraturu: "; std::cin >> kvadratura;
                        try {
                            bool namjesten;
                            if(temp==1) namjesten=true;
                            if(temp==0) namjesten=false;
                            if(temp!=1 and temp!=0)  throw std::domain_error("Neispravan unos podataka");
                            dat_prodaje.Postavi(d,m,g); dat_rodjenja.Postavi(d2,m2,g2);
                            kupac.Postavi(ime_kupca, dat_rodjenja);
                            stan.Postavi(adresa, sprat, broj_soba, namjesten, kvadratura);
                            Prodaja prodaja2(ime_agenta, cijena, dat_prodaje, kupac, stan);
                            prodaje.push_back(prodaja2);
                            p.RegistrirajProdaju(ime_agenta, cijena, dat_prodaje, kupac, stan);
                            stanovi.push_back(stan);
                            kupci.push_back(kupac);
                            std::cout << "Prodaja uspjesno dodana!" << std::endl << std::endl;
                        }
                        catch(std::domain_error a) {
                            std::cout << "Izuzetak: " << a.what() << ". Molimo unesite opet." << std::endl;
                        }
                    } else if(t2==2) {
                        std::cin.ignore(1000, '\n');
                        std::cout << "Unesite ime i prezime agenta prodaje: "; std::string ime_agenta;
                        std::getline(std::cin, ime_agenta);
                        std::cout << "Unesite datum prodaje (formata d/m/g): ";
                        int d,m,g; char z1,z2; std::cin >> d >> z1 >> m >> z2 >> g;
                        std::cout << "Unesite cijenu stana: "; int cijena; std::cin >> cijena;
                        std::cout << "Odaberite kupca. Dostupni kupci su:" << std::endl;
                        for(int i(0); i<kupci.size(); i++) {
                            std::cout << " " << i+1 << " - "; kupci[i].Ispisi();
                            std::cout << std::endl;
                        }
                        int t4; std::cin >> t4;
                        std::cout << "Odaberite stan. Dostupni stanovi su:" << std::endl;
                        for(int i(0); i<stanovi.size(); i++) {
                            std::cout << " " << i+1 << " - "; stanovi[i].Ispisi();
                            std::cout << std::endl;
                        }
                        int t3; std::cin >> t3;
                        try {
                        dat_prodaje.Postavi(d,m,g);
                        Prodaja prodaja(ime_agenta, cijena, dat_prodaje, kupci[t4-1], stanovi[t3-1]);
                        prodaje.push_back(prodaja);
                        p.RegistrirajProdaju(ime_agenta, cijena, dat_prodaje, kupci[t4-1], stanovi[t3-1]);
                        std::cout << "Prodaja uspjesno dodana!" << std::endl << std::endl;
                        }
                        catch(std::domain_error a) {
                            std::cout << "Izuzetak: " << a.what() << ". Molimo unesite opet." << std::endl;
                        }
                    } else if(t2==3) {
                        
                    }
                    }
                } else if(t==2) {
                    std::cout << "Odaberite prodaju koju želite urediti. Dostupne prodaje su:" << std::endl;
                    //p.IspisiSveProdaje();
                    for(int i(0); i<p.DajBrojProdaja(); i++) {
                        std::cout << i+1 << "." << std::endl;
                        p.DajProdaju(i+1).Ispisi();
                        //std::cout << std::endl;
                    }
                    int t2;
                    std::cin >> t2;
                    std::cout << "Izaberite opciju:" << std::endl;
                    std::cout << " 0 - nazad" << std::endl << " 1 - izmjena agenta" << std::endl << " 2 - izmjena datuma prodaje"
                              << std::endl << " 3 - izmjena kupca" << std::endl << " 4 - izmjena stana" << std::endl
                              << " 5 - izmjena cijene stana" << std::endl;
                    int t3;
                    std::cin >> t3;
                    if(t3==0) {
                        continue;
                    } else if(t3==1) {
                        std::cin.ignore(1000, '\n');
                        std::cout << "Unesite ime i prezime agenta prodaje: ";
                        std::string novo_ime; std::getline(std::cin, novo_ime);
                        try {
                        p.DajProdaju(t2).PromijeniImeAgenta(novo_ime);
                        std::cout << "Prodaja je uspjesno izmijenjena!" << std::endl << std::endl;
                        }
                        catch(std::domain_error a) {
                            std::cout << "Izuzetak: " << a.what() << ". Molimo unesite opet." << std::endl;
                        }
                    } else if(t3==2) {
                        std::cout << "Unesite datum prodaje (formata d/m/g): ";
                        int d,m,g; char z1,z2; std::cin >> d >> z1 >> m >> z2 >> g;
                        try {
                        Datum novi_dat(d,m,g);
                        p.DajProdaju(t2).PromijeniDatumKupovine(novi_dat);
                        std::cout << "Prodaja je uspjesno izmijenjena!" << std::endl;
                        }
                        catch(std::domain_error a) {
                            std::cout << "Izuzetak: " << a.what() << ". Molimo unesite opet." << std::endl;
                        }
                    } else if(t3==3) {
                        std::cout << "Izaberite opciju:" << std::endl << " 0 - nazad" << std::endl
                                  << " 1 - odabir postojeceg kupca" << std::endl
                                  << " 2 - dodavanje novog kupca" << std::endl;
                        int t4; std::cin >> t4;
                        if(t4==0) {
                            continue;
                        } else if(t4==1) {
                            std::cout << "Odaberite kupca. Dostupni kupci su:" << std::endl;
                            for(int i(0); i<kupci.size(); i++) {
                                std::cout << " " << i+1 << " - "; kupci[i].Ispisi();
                                std::cout << std::endl;
                            }
                            int t5; std::cin >> t5;
                            p.DajProdaju(t2).PromijeniKupca(kupci[t5-1]);
                            std::cout << "Prodaja je uspjesno izmijenjena!" << std::endl << std::endl;
                        } else if(t4==2) {
                            while(1) {
                                std::cin.ignore(1000, '\n');
                                std::cout << "Unesite ime i prezime kupca: ";
                                std::string ime_kupca; std::getline(std::cin, ime_kupca);
                                std::cout << "Unesite datum rodjenja (formata d/m/g): ";
                                int d,m,g; char z1, z2; std::cin >> d >> z1 >> m >> z2 >> g;
                                if(z1=='/' and z2=='/') 
                                    try {
                                        Datum datum_rodjenja(d,m,g);
                                        Kupac kupac(ime_kupca, datum_rodjenja);
                                        //kupci.push_back(kupac);
                                        p.DajProdaju(t2).PromijeniKupca(kupac);
                                        std::cout << "Prodaja je uspjesno izmijenjena!" << std::endl;
                                        break;
                                    }
                                catch(std::domain_error a) {
                                    std::cout << "Izuzetak: " << a.what() << ". Molimo unesite opet." << std::endl;
                                }
                            }
                        }
                    } else if(t3==4) {
                        std::cout << "Izaberite opciju:" << std::endl << " 0 - nazad" << std::endl
                                  << " 1 - odabir postojeceg stana" << std::endl
                                  << " 2 - dodavanje novog stana" << std::endl;
                        int t4; std::cin >> t4;
                        if(t4==0) {
                            continue;
                        } else if(t4==1) {
                            std::cout << "Odaberite stan. Dostupni stanovi su:" << std::endl;
                            for(int i(0); i<stanovi.size(); i++) {
                                std::cout << " " << i+1 << " - "; stanovi[i].Ispisi();
                                std::cout << std::endl;
                            }
                            int t5; std::cin >> t5;
                            p.DajProdaju(t2).PromijeniStan(stanovi[t5-1]);
                            std::cout << "Prodaja je uspjesno izmijenjena!" << std::endl;
                        } else if(t4==2) {
                            while(1) {
                                std::cin.clear();
                                std::cin.ignore(1000, '\n');
                                std::cout << "Unesite adresu: ";
                                std::getline(std::cin, adresa);
                                std::cout << "Unesite sprat: ";
                                std::cin >> sprat;
                                std::cout << "Unesite broj soba: ";
                                std::cin >> broj_soba;
                                std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                                std::cin >> temp; bool namjesten;
                                if(temp==1) namjesten=true;
                                else if(temp==0) namjesten=false;
                                std::cout << "Unesite kvadraturu: ";
                                std::cin >> kvadratura;
                                try{
                                    if(temp!=1 and temp!=0) throw std::domain_error("Neispravan unos podataka");
                                    Stan stan(adresa, sprat, broj_soba, namjesten, kvadratura);
                                    //stanovi.push_back(stan);
                                    p.DajProdaju(t2).PromijeniStan(stan);
                                    std::cout << "Prodaja je uspjesno izmijenjena!" << std::endl;
                                    break;
                                }
                                catch(std::domain_error a) {
                                    std::cout << "Izuzetak: " << a.what() << ". Molimo unesite opet." << std::endl;
                                }
                            }
                        }
                    } else if(t3==5) {
                            std::cin.ignore(1000, '\n');
                            std::cout << "Unesite cijenu stana: ";
                            double cijena; std::cin >> cijena;
                            p.DajProdaju(t2).PromijeniCijenuProdaje(cijena);
                            std::cout << "Prodaja je uspjesno izmijenjena!" << std::endl;
                    }
                } else if(t==3) {
                    while(1) {
                    std::cout << "Izaberite opciju:" << std::endl;
                    std::cout << " 0 - nazad" << std::endl << " 1 - ispis svih prodaja" << std::endl << " 2 - ispis prodaja na datum"
                              << std::endl << " 3 - ispis najranije prodaje" << std::endl << " 4 - ispis najskuplje prodaje" << std::endl
                              << " 5 - ispis broja prodaja" << std::endl << " 6 - ispis broja prodaja po datumu" << std::endl
                              << " 7 - ispis broja prodaja po agentu" << std::endl << " 8 - kraj" << std::endl;
                    int t2; std::cin >> t2;
                    if(t2==0) {
                        break;
                    } else if(t2==1) {
                        p.IspisiSveProdaje();
                    } else if(t2==2) {
                        std::cout << "Unesite datum (d/m/g): ";
                        int d,m,g; char z1,z2;
                        std::cin >> d >> z1 >> m >> z2 >> g;
                        try {
                            Datum testni(d,m,g);
                            std::cout << "Prodaje na datum ";
                            testni.Ispisi(); std::cout << " su:" << std::endl;
                            p.IspisiProdajeNaDatum(testni);
                        }
                        catch(std::domain_error a) {
                            std::cout << "Izuzetak: " << a.what() << ". Molimo unesite opet." << std::endl;
                        }
                    } else if(t2==3) {
                        p.IspisiProdajeNaDatum(p.DajNajranijuProdaju().DajDatumProdaje());
                    } else if(t2==4) {
                        p.IspisiProdajeNaDatum(p.DajNajskupljuProdaju().DajDatumProdaje());
                    } else if(t2==5) {
                        std::cout << "Broj prodaja: " << p.DajBrojProdaja() << std::endl;
                    } else if(t2==6) {
                        std::cout << "Unesite datum (d/m/g): ";
                        int d,m,g; char z1,z2;
                        std::cin >> d >> z1 >> m >> z2 >> g;
                        try {
                            Datum testni(d,m,g);
                            std::cout << "Broj Prodaje na uneseni datum: ";
                            std::cout << p.DajBrojProdajaNaDatum(testni) << std::endl;
                        }
                        catch(std::domain_error a) {
                            std::cout << "Izuzetak: " << a.what() << ". Molimo unesite opet." << std::endl;
                        }
                    } else if(t2==7) {
                        std::cin.ignore(1000, '\n');
                        std::cout << "Unesite ime agenta: ";
                        std::string testno_ime;
                        std::getline(std::cin, testno_ime);
                        std::cout << "Broj prodaja: " << p.DajBrojProdajaOdAgenta(testno_ime) << std::endl;
                    } else if(t2==8) {
                        return 0;
                    }
                    }
                } else if(t==4) {
                    while(1) {
                    std::cout << std::endl << "Izaberite opciju:" << std::endl;
                    std::cout << " 0 - nazad" << std::endl << " 1 - brisanje najranije prodaje" << std::endl << " 2 - brisanje prodaja agenta"
                              << std::endl << " 3 - brisanje prodaja po datumu" << std::endl << " 4 - brisanje svih prodaja" << std::endl;
                    int t2; std::cin >> t2;
                    try {
                    if(t2==0) {
                        break;
                    } else if(t2==1) {
                        p.ObrisiNajranijuProdaju();
                        std::cout << "Najranija prodaja je obrisana!" << std::endl;
                    } else if(t2==2) {
                        std::cin.ignore(1000, '\n');
                        std::cout << "Unesite ime agenta: ";
                        std::string testno_ime;
                        std::getline(std::cin, testno_ime);
                        p.ObrisiProdajeAgenta(testno_ime);
                        std::cout << "Sve prodaje tog agenta su obrisane." << std::endl;
                    } else if(t2==3) {
                        while(1) {
                        std::cout << "Unesite datum (d/m/g): ";
                        int d,m,g; char z1,z2;
                        std::cin >> d >> z1 >> m >> z2 >> g;
                        try {
                            Datum testni(d,m,g);
                            p.ObrisiProdajeNaDatum(testni);
                            std::cout << "Sve prodaje na taj datum su obrisane." << std::endl;
                            break;
                        }
                        catch(std::domain_error a) {
                            std::cout << "Izuzetak: " << a.what() << ". Molimo unesite opet." << std::endl;
                        }
                        }
                    } else if(t2==4) {
                        p.IsprazniKolekciju();
                        std::cout << "Sve prodaje su obrisane." << std::endl;
                    }
                    }
                    catch(std::range_error a) {
                        std::cout << "Izuzetak: " << a.what() << "." << std::endl;
                    }
                    }
                } else if(t==5) {
                    return 0;
                }
            }
        }
    }
    std::cout << std::endl << "Dovidjenja!";
	return 0;
}