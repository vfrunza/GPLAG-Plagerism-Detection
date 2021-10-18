/B2017/2018: Zadaća 6, Zadatak 2
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <new>
#include <memory>
#include <fstream>
#include <algorithm>

class Spremnik
{
protected:
    double tezina_spremnika;
    std::string ime_onog_u_spremniku;
public:
    Spremnik (double tezina, std::string ime) : tezina_spremnika(tezina), ime_onog_u_spremniku(ime) {}

    double DajTezinu () const {
        return tezina_spremnika;
    }

    virtual double DajUkupnuTezinu () const = 0;

    virtual void Ispisi () const = 0;

    virtual Spremnik *DajKopiju () const = 0;

    virtual ~Spremnik () {}
};

class Sanduk : public Spremnik
{
    std::vector<double> tezina_predmeta;
public:

    Sanduk (double tezina, std::string ime, std::vector<double> tezine) : Spremnik(tezina, ime), tezina_predmeta(tezine) {}


    double DajUkupnuTezinu () const {
        double suma(0);
        for (double x : tezina_predmeta) suma+=x;
        return suma+DajTezinu();
    }

    void Ispisi () const {
        std::cout<<"Vrsta spremnika: Sanduk"<<std::endl<<"Sadrzaj: "<<ime_onog_u_spremniku<<std::endl<<"Tezine predmeta: ";
        for (double x : tezina_predmeta) std::cout<<x<<" ";
        std::cout<<"(kg)"<<std::endl<<"Vlastita tezina: "<<tezina_spremnika<<" (kg)"<<std::endl<<"Ukupna tezina: "<<
                 DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }

    Spremnik *DajKopiju () const override {
        return new Sanduk(*this);
    }

};

class Vreca : public Spremnik
{
    double tezina_materije;
public:

    Vreca (double tezina, std::string ime, double tezina_materije) : Spremnik(tezina, ime), tezina_materije(tezina_materije) {}

    double DajUkupnuTezinu() const {
        return tezina_materije+DajTezinu();
    }

    void Ispisi() const {
        std::cout<<"Vrsta spremnika: Vreca"<<std::endl<<"Sadrzaj: "<<ime_onog_u_spremniku<<std::endl<<
                 "Vlastita tezina: "<<tezina_spremnika<<" (kg)"<<std::endl<<"Tezina pohranjene materije: "<<tezina_materije
                 <<" (kg)"<<std::endl<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }

    Spremnik *DajKopiju () const override {
        return new Vreca(*this);
    }

};

class Bure : public Spremnik
{
    double gustoca, zapremina;
public:

    Bure (double tezina, std::string ime, double sp_tezina, double zap_tecnosti) : Spremnik(tezina, ime), gustoca(sp_tezina),
        zapremina(zap_tecnosti) {}

    double DajUkupnuTezinu() const {
        return DajTezinu()+(zapremina/1000)*gustoca;
    }

    void Ispisi() const {
        std::cout<<"Vrsta spremnika: Bure"<<std::endl<<"Sadrzaj: "<<ime_onog_u_spremniku<<std::endl<<
                 "Vlastita tezina: "<<tezina_spremnika<<" (kg)"<<std::endl<<"Specificna tezina tecnosti: "<<gustoca<<
                 " (kg/m^3)"<<std::endl<<"Zapremina tecnosti: "<<zapremina<<" (l)"<<std::endl<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }

    Spremnik *DajKopiju () const override {
        return new Bure (*this);
    }

};

typedef std::vector<std::shared_ptr<Spremnik> > VektorPametnihSpremnika;

typedef std::shared_ptr<Spremnik> PametniSpremnik;

class Skladiste
{
    VektorPametnihSpremnika spremnici;
public:

    Skladiste () : spremnici(0) {}

    // Kopirajuci konstruktor
    Skladiste (const Skladiste &s);

    //operator dodjele
    Skladiste& operator=(const Skladiste &s);

    //Pomjerajuci konstruktor
    Skladiste (Skladiste &&s);

    //Pomjerajuci operator dodjele
    Skladiste& operator=(Skladiste &&s);

    Spremnik* DodajSanduk (double tezina, std::string ime, std::vector<double> tezine) {
        std::shared_ptr<Spremnik> sanduk (new Sanduk (tezina, ime, tezine));
        spremnici.push_back(sanduk);
        return &(*sanduk);
    }

    Spremnik* DodajVrecu (double tezina, std::string ime, double tezina_materije) {
        std::shared_ptr<Spremnik> vreca (new Vreca (tezina, ime, tezina_materije));
        spremnici.push_back(vreca);
        return &(*vreca);
    }

    Spremnik* DodajBure (double tezina, std::string ime, double sp_tezina, double zapremina) {
        std::shared_ptr<Spremnik> bure (new Bure (tezina, ime, sp_tezina, zapremina));
        spremnici.push_back(bure);
        return &(*bure);
    }

    Spremnik* DodajSpremnik (Spremnik *spremnik, bool vlasnistvo) {
        if (vlasnistvo)
            spremnici.push_back(std::shared_ptr<Spremnik>(spremnik));
        else {
            spremnici.push_back(std::shared_ptr<Spremnik> (spremnik->DajKopiju()));
            return &(*spremnici.at(spremnici.size()-1));
        }
        return &(*spremnik);
    }

    void BrisiSpremnik (Spremnik *za_brisanje) {
        int i(0);
        for (auto x : spremnici) {
            if (&(*x)==za_brisanje) spremnici.erase(spremnici.begin()+i);
            i++;
        }
    }

    Spremnik& DajNajlaksi() const = delete; // ne smije se pozvati nad konstantnim objektom

    Spremnik& DajNajlaksi () {
        if (spremnici.size()==0) throw std::range_error ("Skladiste je prazno");
        int najlaksi(0);
        for (int i = 0; i<spremnici.size(); i++) if (spremnici.at(i)->DajTezinu()<spremnici.at(najlaksi)->DajTezinu()) najlaksi=i;
        return *spremnici.at(najlaksi);
    }

    Spremnik& DajNajtezi () const = delete;

    Spremnik& DajNajtezi();

    int BrojPreteskih (int max) const;

    void IzlistajSkladiste() const;

    void UcitajIzDatoteke(std::string ime);
};

void Skladiste::UcitajIzDatoteke (std::string ime)
{
    std::ifstream ulazni_tok(ime);
    if (!ulazni_tok) throw std::logic_error ("Trazena datoteka ne postoji");
    spremnici.resize(0); // u slucaju da u skladistu vec ima robe ona treba da se obrise
    while (ulazni_tok) {
        char znak,praznina;
        ulazni_tok>>znak>>std::noskipws>>praznina>>std::skipws; // funkcije preskacu ws ili ne preskacu ws
        if (ulazni_tok.eof()) break;
        if (praznina!=' ') throw std::logic_error ("Datoteka sadrzi besmislene podatke");
        std::string trenutno_ime;
        std::getline(ulazni_tok, trenutno_ime);

        if (znak=='S') {
            double tezina_sanduka;
            int broj_predmeta,i(0);
            ulazni_tok>>tezina_sanduka>>broj_predmeta;
            if (!ulazni_tok && !ulazni_tok.eof()) throw std::logic_error ("Datoteka sadrzi besmislene podatke");
            std::vector<double> predmeti;
            while (ulazni_tok) {
                if (i==broj_predmeta) break;
                double predmet;
                ulazni_tok>>predmet;
                predmeti.push_back(predmet);
                if (!ulazni_tok) throw std::logic_error ("Datoteka sadrzi besmislene podatke");
                i++;
            }
            DodajSanduk(tezina_sanduka,trenutno_ime,predmeti);
        }

        else if (znak=='V') {
            double tezina_vrece, tezina_materije;
            ulazni_tok>>tezina_vrece>>tezina_materije;
            if (!ulazni_tok && !ulazni_tok.eof()) throw std::logic_error ("Datoteka sadrzi besmislene podatke");
            DodajVrecu(tezina_vrece,trenutno_ime,tezina_materije);
        }

        else if (znak=='B') {
            double tezina_bureta, specificna_tezina, zapremina;
            ulazni_tok>>tezina_bureta>>specificna_tezina>>zapremina;
            if (!ulazni_tok && !ulazni_tok.eof()) throw std::logic_error ("Datoteka sadrzi besmislene podatke");
            DodajBure(tezina_bureta, trenutno_ime, specificna_tezina, zapremina);
        }

        else throw std::logic_error ("Datoteka sadrzi besmislene podatke");
        
        if (ulazni_tok.bad()) throw std::logic_error ("Problemi pri citanju datoteke");

    }
}

void Skladiste::IzlistajSkladiste () const
{
    std::vector<int> polozaji(spremnici.size());
    VektorPametnihSpremnika kopija=spremnici;
    std::sort(kopija.begin(), kopija.end(), [] (PametniSpremnik p1, PametniSpremnik p2) {
        return p1->DajUkupnuTezinu()>p2->DajUkupnuTezinu();
    });
    std::for_each(kopija.begin(), kopija.end(), [](PametniSpremnik p) {
        p->Ispisi();
    });
    /*     for (int i = 0; i<spremnici.size(); i++){
             int pozicija(0);
             for (int j = 0; j<spremnici.size(); j++){

                 if (spremnici.at(i)->DajUkupnuTezinu()<spremnici.at(j)->DajUkupnuTezinu()) pozicija++;
             }
             polozaji.at(pozicija)=i;
         } // popraviti za endl

         for (int x = 0; x<spremnici.size(); x++) { spremnici.at(polozaji.at(x))->Ispisi(); std::cout<<std::endl<<std::endl; }
    */
}

Spremnik& Skladiste::DajNajtezi ()
{
    if (spremnici.size()==0) throw std::range_error ("Skladiste je prazno");
    int najtezi(0);
    for (int i = 0; i<spremnici.size(); i++) if (spremnici.at(i)->DajTezinu()>spremnici.at(najtezi)->DajTezinu()) najtezi=i;
    return *spremnici.at(najtezi);
}

int Skladiste::BrojPreteskih (int max) const
{
    int vrati(0);
    for (auto x : spremnici) if (x->DajUkupnuTezinu()>max) vrati++;
    return vrati;
}

// kopirajuci konstruktor
Skladiste::Skladiste (const Skladiste &s)
{
    for (int i = 0; i<s.spremnici.size(); i++)
        spremnici.push_back(std::shared_ptr<Spremnik>(s.spremnici.at(i)->DajKopiju()));
}

// operator dodjele
Skladiste& Skladiste::operator = (const Skladiste &s)
{
    if (this==&s) return *this;
    spremnici.resize(0);
    for (int i = 0; i<s.spremnici.size(); i++)
        spremnici.push_back(std::shared_ptr<Spremnik>(s.spremnici.at(i)->DajKopiju()));
    return *this;
}

//pomjerajuci konstruktor
Skladiste::Skladiste (Skladiste &&s)
{
    std::swap(spremnici, s.spremnici);
}

//pomjerajuci operator dodjele
Skladiste& Skladiste::operator = (Skladiste &&s)
{
    spremnici=s.spremnici;
    s.spremnici.resize(0);
    return *this;
}

class PolimorfniSpremnik {
  Spremnik *spremnik;
  void DaLiJeSpecificiran () const {
      if(!spremnik) throw std::logic_error ("Nespecificiran spremnik");
  }
  public:
  
  PolimorfniSpremnik() : spremnik(nullptr) {}
  
  ~PolimorfniSpremnik() { delete spremnik; }
  
  //konstruktor koji inicijalizira pomocu spremnika
  PolimorfniSpremnik(const Spremnik &s) : spremnik(s.DajKopiju()) {}
  
  // kopirajuci konstruktor
  PolimorfniSpremnik(const PolimorfniSpremnik &p_s) {
      if (!p_s.spremnik) spremnik=nullptr;
      else spremnik=p_s.spremnik->DajKopiju();
  }
  
  //pomjerajuci konstruktor
  PolimorfniSpremnik(PolimorfniSpremnik &&p_s) {
      spremnik=p_s.spremnik; p_s.spremnik=nullptr;
  }
  
  //operator dodjele
  PolimorfniSpremnik& operator = (const PolimorfniSpremnik &p_s) {
      Spremnik *novi(nullptr);
      if (p_s.spremnik != nullptr) novi=p_s.spremnik->DajKopiju();
      delete spremnik;
      spremnik=novi;
      return *this;
  }
  
  //pomjerajuci operator dodjle
  PolimorfniSpremnik& operator = (PolimorfniSpremnik &&p_s) {
      std::swap(spremnik,p_s.spremnik);
      return *this;
  }
  
  double DajTezinu () const { DaLiJeSpecificiran(); return spremnik->DajTezinu(); }
  double DajUkupnuTezinu() const { DaLiJeSpecificiran(); return spremnik->DajUkupnuTezinu(); }
  void Ispisi() const { DaLiJeSpecificiran(); spremnik->Ispisi(); }
  
};

int main ()
{
    try {
        /*Sanduk s(5, "Auspuh", {1,2,3,4,5,6});
        Vreca *v(new Vreca(10, "Cijanid", 15));
        Bure b(20, "Nafta", 1500, 100);
        Skladiste spremnici;
        auto k (spremnici.DodajSanduk(5,"Auspuh", {1,2,3,4,5}));
        spremnici.DodajVrecu(1,"Cijanid",15);
        spremnici.DodajBure(20,"Nafta",150,100);
        spremnici.DodajSpremnik(v,true);
        spremnici.BrisiSpremnik(&(*k));
        spremnici.DodajSpremnik(&b, false);*/
        
        //std::ofstream izlazni_tok("ROBA.TXT");
       /* izlazni_tok<<"S Gevigti"<<std::endl<<"13 3 14 17 15"<<std::endl<<
        "B Suncokretovo ulje"<<std::endl<<"5 1500 45"<<std::endl<<"V Kiseli kupus"<<std::endl<<"0.5 45"<<std::endl
        <<"B Guscja mast"<<std::endl<<"6 1200 78"<<std::endl<<"V Krompir"<<std::endl<<"1 15"<<std::endl<<
        "S Lopate"<<std::endl<<"10 5 2 2 2 2 2"<<std::endl;*/
       /* izlazni_tok<<"S Tepsije"<<std::endl<<"10 9 2 3 1 2 2 4 3 1 3"<<std::endl<<"V Brasno"<<std::endl<<
        "0.2 5"<<std::endl<<"B Suncokretovo ulje"<<std::endl<<"5 1300 150";
        izlazni_tok.close();
        
        Skladiste spremnici_dat; //(spremnici);
        //spremnici_dat=spremnici;
        //spremnici.IzlistajSkladiste();
        spremnici_dat.UcitajIzDatoteke("ROBA.TXT");
        // spremnici=std::move(spremnici_dat);
        // std::cout<<spremnici_dat.DajVelicinu()<<std::endl;
       // spremnici.IzlistajSkladiste();
        spremnici_dat.IzlistajSkladiste();*/
        
        PolimorfniSpremnik s1 (Bure(5,"Benzin", 930, 70));
        PolimorfniSpremnik s2,s3;
        s2 =  Sanduk (3, "Tepsije" ,{0.5, 0.8, 0.6, 0.5});
        s3 = Vreca (0.4, "Brasno", 30);
        std::cout<<s1.DajTezinu()<<std::endl;
        std::cout<<s2.DajUkupnuTezinu()<<std::endl;
        s3.Ispisi();
        s1=s2;
        s1.Ispisi();


    } catch (std::logic_error iz) {
        std::cout<<iz.what();
    }
    return 0;
}