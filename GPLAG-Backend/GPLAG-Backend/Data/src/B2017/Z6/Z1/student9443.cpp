/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <new>
#include <stdexcept>
#include <algorithm>
#include <typeinfo>
#include <fstream>

double ZaDouble(std::ifstream &ulazni_tok, char &znak) {
    double tezina{0};
    if(znak >= '0' && znak <= '9') {
        tezina=znak-'0';
        while((znak = ulazni_tok.get()) != EOF && znak >= '0' && znak <= '9') {
            tezina*=10;
            tezina+=znak-'0';
        }
        if(znak == '.' && (znak = ulazni_tok.get()) != EOF && znak >= '0' && znak <= '9') {
            int x{10};
            do{
                tezina+= double(znak-'0')/x;
                x*=10;
            } while((znak = ulazni_tok.get()) != EOF && znak >= '0' && znak <= '9'); 
        }
        else if(znak != ' ' && znak != '\n' && ulazni_tok) throw std::logic_error("Datoteka sadrzi besmislene podatke");
    }
    else throw std::logic_error("Datoteka sadrzi besmislene podatke");
    return tezina;
}

class Spremnik {
    std::string Naziv;
    double Tezina;
    public:
    Spremnik(double tezina, std::string naziv) { Tezina=tezina; Naziv=naziv; }
    double DajTezinu() const { return Tezina; }
    std::string DajNaziv() const { return Naziv; }
    virtual double DajUkupnuTezinu() const = 0;
    virtual void Ispisi() const = 0;
    virtual std::shared_ptr<Spremnik> DajKopiju() const = 0;
    virtual ~Spremnik() {};
};

class Sanduk : public Spremnik {
    std::vector<double> TezUNjima;
    public:
    Sanduk(double Tez, std::string Naz, std::vector<double> TPojed) : Spremnik(Tez, Naz) { TezUNjima=TPojed; }
    double DajUkupnuTezinu() const override { double ukupna{0}; for(int i=0; i<TezUNjima.size(); i++) ukupna+=TezUNjima[i]; return ukupna+Spremnik::DajTezinu(); }
    void Ispisi() const override { 
        std::cout << "Vrsta spremnika: Sanduk" << std::endl << "Sadrzaj: " << Spremnik::DajNaziv() << std::endl << "Tezine predmeta: ";
        for(int i=0; i<TezUNjima.size(); i++) std::cout << TezUNjima[i] << " ";
        std::cout << "(kg)" << std::endl << "Vlastita tezina: " << Spremnik::DajTezinu() << " (kg)" << std::endl << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;
    }
    std::shared_ptr<Spremnik> DajKopiju() const override { return std::make_shared<Sanduk>(*this); }
    ~Sanduk() override {}
};

class Vreca : public Spremnik {
    double TezPraska;
    public:
    Vreca(double Tez, std::string Naz, double tp) : Spremnik(Tez, Naz) { TezPraska=tp; }
    double DajUkupnuTezinu() const override { return TezPraska+Spremnik::DajTezinu(); }
    void Ispisi() const override {
        std::cout << "Vrsta spremnika: Vreca" << std::endl << "Sadrzaj: " << Spremnik::DajNaziv() << std::endl << "Vlastita tezina: " << Spremnik::DajTezinu() << " (kg)" 
                                         << std::endl << "Tezina pohranjene materije: " << TezPraska << " (kg)" << std::endl << "Ukupna tezina: " 
                                         << DajUkupnuTezinu() << " (kg)" << std::endl;
    }
    std::shared_ptr<Spremnik> DajKopiju() const override { return std::make_shared<Vreca>(*this); }
    ~Vreca() override {}
};

class Bure : public Spremnik {
    double Gustina;
    double Zapremina;
    public:
    Bure(double Tez, std::string Naz, double Gus, double Zap) : Spremnik(Tez, Naz) { Gustina=Gus; Zapremina=Zap; }
    double DajUkupnuTezinu() const override { return Gustina*Zapremina/1000+Spremnik::DajTezinu(); }
    void Ispisi() const override {
        std::cout << "Vrsta spremnika: Bure" << std::endl << "Sadrzaj: " << Spremnik::DajNaziv() << std::endl << "Vlastita tezina: " << Spremnik::DajTezinu() << " (kg)" 
                                         << std::endl << "Specificna tezina tecnosti: " << Gustina << " (kg/m^3)" << std::endl << "Zapremina tecnosti: " << 
                                        Zapremina << " (l)" << std::endl << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;
    }
    std::shared_ptr<Spremnik> DajKopiju() const override { return std::make_shared<Bure>(*this); }
    ~Bure() override {}
};

class Skladiste {
    std::vector<std::shared_ptr<Spremnik>> v;
    public:
    Skladiste() {}
    Skladiste(const Skladiste &S) {
        for(int i=0; i<S.v.size(); i++) {
            v.push_back(S.v[i]->DajKopiju());
        }
    }
    Skladiste &operator =(const Skladiste &S) {
        v.clear();
        for(int i=0; i<S.v.size(); i++) {
            v.push_back(S.v[i]->DajKopiju());
        }
        return *this;
    }
    ~Skladiste() {
        v.clear();
    }
    Spremnik* DodajSanduk(double Tez, std::string Naz, std::vector<double> TPojed) {
        Sanduk s(Tez, Naz, TPojed);
        v.push_back(s.DajKopiju());
        return v[v.size()-1].get();
    }
    Spremnik* DodajVrecu(double Tez, std::string Naz, double tp) {
        Vreca s(Tez, Naz, tp);
        v.push_back(s.DajKopiju());
        return v[v.size()-1].get();
    }
    Spremnik* DodajBure(double Tez, std::string Naz, double Gus, double Zap) {
        Bure s(Tez, Naz, Gus, Zap);
        v.push_back(s.DajKopiju());
        return v[v.size()-1].get();
    }
    Spremnik* DodajSpremnik(Spremnik* S, bool DaNe) {     
        if(DaNe) {
            v.push_back(std::shared_ptr<Spremnik>(S));
            S=nullptr;
            return (v[v.size()-1].get());
        }
        else {
            v.push_back(S->DajKopiju());
            return (v[v.size()-1].get());
        } 
    }
    void BrisiSpremnik(Spremnik *adresa) {
        for(int i=0; i<v.size(); i++) {
            if(v[i].get() == adresa) {
                v[i] = nullptr;
                v.erase(v.begin()+i);
                adresa=nullptr;
                break;
            }
        }
    }
    Spremnik &DajNajlaksi() {
        if(v.size() == 0) throw std::range_error("Skladiste je prazno");
        return **(std::min_element(v.begin(), v.end(), [](std::shared_ptr<Spremnik> a, std::shared_ptr<Spremnik> b) { if(a->DajTezinu() < b->DajTezinu()) return true; return false; } ));
    }
    Spremnik &DajNajtezi() {
        if(v.size() == 0) throw std::range_error("Skladiste je prazno");
        return **(std::max_element(v.begin(), v.end(), [](std::shared_ptr<Spremnik> a, std::shared_ptr<Spremnik> b) { if(a->DajTezinu() < b->DajTezinu()) return true; return false; } ));
    }
    int BrojPreteskih(double param) const {
        int br{0};
        for(int i=0; i<v.size(); i++) {
            if(v[i]->DajUkupnuTezinu() > param) br++;
        }
        return br;
    }
    void IzlistajSkladiste() const {
        Skladiste Pomoc(*this);
        std::sort(Pomoc.v.begin(), Pomoc.v.end(), [](std::shared_ptr<Spremnik> a, std::shared_ptr<Spremnik> b) { if(a->DajUkupnuTezinu() > b->DajUkupnuTezinu()) return true; return false; } );
        for(int i=0; i<Pomoc.v.size(); i++) Pomoc.v[i]->Ispisi();
    }
    void UcitajIzDatoteke(std::string imedat) {
        v.clear();
        std::ifstream ulazni_tok(imedat);
        if(!ulazni_tok) throw std::logic_error("Trazena datoteka ne postoji");
        else {
            char slovo;
            while((slovo = ulazni_tok.get()) != EOF) {
                char znak;
                std::string ime;
                double tezina;
                if(slovo == 'S' || slovo == 'V' || slovo == 'B') {
                    znak = ulazni_tok.get(); 
                    if(znak != ' ') throw std::logic_error("Datoteka sadrzi besmislene podatke");
                    while((znak = ulazni_tok.get()) != EOF && znak != '\n') {
                        ime.push_back(znak);
                    }
                }
                if(slovo == 'S' && znak == '\n' && (znak = ulazni_tok.get()) != EOF) {
                    int br_pr;
                    std::vector<double> tezpojed;
                    tezina=ZaDouble(ulazni_tok, znak);
                    if((znak = ulazni_tok.get()) != EOF) {
                        if(znak >= '0' && znak <= '9') {
                            br_pr=znak-'0';
                            while((znak = ulazni_tok.get()) != EOF && znak >= '0' && znak <= '9') {
                                br_pr*=10;
                                br_pr+=znak-'0';
                            }
                        }
                        else throw std::logic_error("Datoteka sadrzi besmislene podatke");
                    }
                    else throw std::logic_error("Problemi pri citanju datoteke");
                    for(int i=0; i<br_pr; i++) {
                        if((znak = ulazni_tok.get()) != EOF) tezpojed.push_back(ZaDouble(ulazni_tok, znak)); 
                        else throw std::logic_error("Problemi pri citanju datoteke");
                    }
                    DodajSanduk(tezina, ime, tezpojed);
                }
                else if(slovo == 'V' && znak == '\n' && (znak = ulazni_tok.get()) != EOF) {
                    tezina=ZaDouble(ulazni_tok, znak);
                    double tezmater;
                    if((znak = ulazni_tok.get()) != EOF) {
                        tezmater=ZaDouble(ulazni_tok, znak);
                    }
                    else throw std::logic_error("Problemi pri citanju datoteke");
                    DodajVrecu(tezina, ime, tezmater);
                }
                else if(slovo == 'B' && znak == '\n' && (znak = ulazni_tok.get()) != EOF) {
                    tezina=ZaDouble(ulazni_tok, znak);
                    double spectez, zaprem;
                    if((znak = ulazni_tok.get()) != EOF) { 
                        spectez=ZaDouble(ulazni_tok, znak);
                        if((znak = ulazni_tok.get()) != EOF) zaprem=ZaDouble(ulazni_tok, znak);
                        else throw std::logic_error("Problemi pri citanju datoteke");
                    }
                    else throw std::logic_error("Problemi pri citanju datoteke");
                    DodajBure(tezina, ime, spectez, zaprem);
                }
                else if(ulazni_tok.eof()) throw std::logic_error("Nema vise podataka!");
                else if(ulazni_tok.bad()) throw std::logic_error("Problemi pri citanju datoteke");
                else throw std::logic_error("Datoteka sadrzi besmislene podatke");
            }
        }
        if(ulazni_tok.bad()) throw std::logic_error("Problemi pri citanju datoteke");
        else if (!ulazni_tok.eof())throw std::logic_error("Datoteka sadrzi neocekivane podatke");
    }
};

int main () {
    try {
	Skladiste ETF;
    ETF.UcitajIzDatoteke("ROBA.TXT");
    ETF.IzlistajSkladiste();
    }
    catch(std::range_error izuzetak) {
        std::cout << izuzetak.what();
    }
    catch(std::logic_error izuzetak) {
        std::cout << izuzetak.what();
    }
    catch(...) {
        std::cout << "Neocekivani izuzetak";
    }
   	return 0;
}
