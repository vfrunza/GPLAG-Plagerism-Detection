#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>
#include <algorithm>
#include <fstream>
#include <cstring>


class Spremnik
{
protected:
    double tezina_spremnika;
    std::string sadrzaj;

public:
    Spremnik(double tezina, std::string ime) : tezina_spremnika(tezina), sadrzaj(ime) {}
    double DajTezinu() {
        return tezina_spremnika;
    }
    virtual double DajUkupnuTezinu() const = 0; // iskljuceno za spremink
    virtual void Ispisi() const = 0; //iskljuceno za spremink
    virtual std::shared_ptr<Spremnik> DajNoviSpremnik() const = 0; //iskljuceno za spremnik
    virtual ~Spremnik() {};

};

class Sanduk : public Spremnik
{
    std::vector<double> tezina_predmeta;
public:
    Sanduk(double tezina, std::string ime, std::vector<double> tezine_vektor) : Spremnik (tezina, ime) {
        tezina_predmeta.resize(tezine_vektor.size());
        tezina_predmeta=tezine_vektor;
    }
    double DajUkupnuTezinu() const {
        double suma(0);
        for (int i = 0; i < tezina_predmeta.size(); i++) {
            suma+=tezina_predmeta[i];
        }
        return tezina_spremnika+suma;
    }
    void Ispisi() const {
        std::cout << "Vrsta spremnika: Sanduk" << std::endl;
        std::cout << "Sadrzaj: " << sadrzaj<< std::endl;
        std::cout << "Tezine predmeta: ";
        for (int i = 0; i < tezina_predmeta.size(); i++) std::cout << tezina_predmeta[i] <<" ";
        std::cout<< "(kg)" << std::endl;
        std::cout << "Vlastita tezina: "<< tezina_spremnika<< " (kg)" << std::endl;
        std::cout << "Ukupna tezina: " << DajUkupnuTezinu()<< " (kg)"<< std::endl;
    }
    std::shared_ptr<Spremnik> DajNoviSpremnik() const {
        return std::make_shared<Sanduk>(Sanduk(tezina_spremnika, sadrzaj, tezina_predmeta));
    }
    ~Sanduk() {};
    friend class Skladiste;

};

class Vreca : public Spremnik
{
    double tezina_materije;
public:
    Vreca(double tezina_vrece, std::string ime, double tezina_mat) : Spremnik(tezina_vrece, ime), tezina_materije(tezina_mat) {}
    double DajUkupnuTezinu() const {
        return tezina_spremnika+tezina_materije;
    }
    void Ispisi() const {
        std::cout << "Vrsta spremnika: Vreca" << std::endl;
        std::cout << "Sadrzaj: " << sadrzaj<< std::endl;
        std::cout << "Vlastita tezina: "<< tezina_spremnika<< " (kg)" << std::endl;
        std::cout << "Tezina pohranjene materije: " << tezina_materije<< " (kg)"<< std::endl;
        std::cout << "Ukupna tezina: " <<DajUkupnuTezinu() << " (kg)"<< std::endl;
    }
    std::shared_ptr<Spremnik> DajNoviSpremnik() const {
        return std::make_shared<Vreca>(Vreca(tezina_spremnika, sadrzaj, tezina_materije));
    }
    ~Vreca() {};
    friend class Skladiste;
};

class Bure : public Spremnik
{
    double gustina, zapremina;

public:
    Bure(double tezina, std::string naziv_tecnosti, double gustoca, double volumen) : Spremnik(tezina, naziv_tecnosti), gustina(gustoca), zapremina(volumen) {}
    double DajUkupnuTezinu() const {
        return tezina_spremnika + (gustina*zapremina/1000);
    }
    void Ispisi() const {
        std::cout << "Vrsta spremnika: Bure" << std::endl;
        std::cout << "Sadrzaj: " << sadrzaj<< std::endl;
        std::cout << "Vlastita tezina: "<< tezina_spremnika<< " (kg)" << std::endl;
        std::cout << "Specificna tezina tecnosti: " << gustina<< " (kg/m^3)"<< std::endl;
        std::cout << "Zapremina tecnosti: "<< zapremina<< " (l)" << std::endl;
        std::cout << "Ukupna tezina: " <<DajUkupnuTezinu() << " (kg)"<< std::endl;
    }
    std::shared_ptr<Spremnik> DajNoviSpremnik() const {
        return std::make_shared<Bure>(Bure(tezina_spremnika, sadrzaj, gustina, zapremina));
    }
    ~Bure() {};
    friend class Skladiste;

};

class Skladiste
{
    std::vector<std::shared_ptr<Spremnik>> vektor_spremista;

public:
    Skladiste() = default;
    Skladiste (Skladiste &&neko) : vektor_spremista(neko.vektor_spremista) {};
    Skladiste &operator = (Skladiste neko) {
        std::swap(vektor_spremista, neko.vektor_spremista);
        return *this;
    }
    Spremnik *DodajSanduk(double tezina, std::string ime, std::vector<double> tezine_vektor) {
        vektor_spremista.emplace_back(std::make_shared<Sanduk> (Sanduk(tezina, ime, tezine_vektor)));
        return vektor_spremista[vektor_spremista.size()-1].get();
    }
    Spremnik *DodajVrecu(double tezina_vrece, std::string ime, double tezina_mat) {
        vektor_spremista.emplace_back (std::make_shared<Vreca> ( Vreca(tezina_vrece,ime,tezina_mat) ) );
        return vektor_spremista[vektor_spremista.size()-1].get();
    }
    Spremnik *DodajBure(double tezina, std::string naziv_tecnosti, double gustoca, double volumen) {
        vektor_spremista.emplace_back( std::make_shared<Bure> (Bure(tezina, naziv_tecnosti, gustoca, volumen)));
        return vektor_spremista[vektor_spremista.size()-1].get();
    }
    Spremnik *DodajSpremnik(Spremnik *dodaj, bool promjenjiva) {
        if(promjenjiva) {
            vektor_spremista.emplace_back(dodaj);
            dodaj=nullptr;
            return vektor_spremista[vektor_spremista.size()-1].get();
        } else {
            auto pomocna(dodaj->DajNoviSpremnik());
            vektor_spremista.emplace_back(pomocna);
            return vektor_spremista[vektor_spremista.size()-1].get();
        }
    }
    void BrisiSpremnik(Spremnik *brisani) {
        for (int i = 0; i < vektor_spremista.size(); i++) {
            if(vektor_spremista[i].get()==brisani) {
                vektor_spremista[i]=nullptr;
                vektor_spremista.erase(vektor_spremista.begin() + i);
            }
        }
    }
    Spremnik &DajNajlaksi() {
        if(vektor_spremista.empty()) throw std::range_error("Skladiste je prazno");
        auto min = vektor_spremista[0];
        for (int i = 1; i < vektor_spremista.size(); i++) {
            if(vektor_spremista[i]->DajTezinu() < min->DajTezinu()) min = vektor_spremista[i];
        }
        return *min;
    }
    Spremnik &DajNajtezi() {
        if(vektor_spremista.empty()) throw std::range_error("Skladiste je prazno");
        auto max = vektor_spremista[0];
        for (int i = 1; i < vektor_spremista.size(); i++) {
            if(vektor_spremista[i]->DajTezinu() > max->DajTezinu()) max = vektor_spremista[i];
        }
        return *max;
    }
    int BrojPreteskih(int parametar) const {
        int brojac(0);
        for (int i = 0; i < vektor_spremista.size(); i++) {
            if(vektor_spremista[i]->DajUkupnuTezinu() > parametar) brojac++;
        }
        return brojac;
    }
    void IzlistajSkladiste() const {
        auto pomocni_vektor(vektor_spremista);
        std::sort(pomocni_vektor.begin(), pomocni_vektor.end(), [](std::shared_ptr<Spremnik> prvi, std::shared_ptr<Spremnik> drugi) {
            return prvi->DajUkupnuTezinu() > drugi->DajUkupnuTezinu();
        });
        for (int i = 0; i < pomocni_vektor.size(); i++) {
            pomocni_vektor[i]->Ispisi();
        }
    }
    void UcitajIzDatoteke(std::string ime_datoteke) {
        std::ifstream ulaz(ime_datoteke);
        if(!ulaz) throw std::logic_error("Trazena datoteka ne postoji");
        std::vector<std::shared_ptr<Spremnik>> pomocni_vektor;
        while(true) {
            if(ulaz.eof())break;
            std::string sadrzaj;
            char slovo;
            ulaz>>slovo;
            ulaz.ignore(1);
            if(slovo == 'S') {
              if(!ulaz.eof() && !ulaz) throw std::logic_error ("Problemi pri citanju datoteke");
              if(ulaz.eof()) throw std::logic_error("Datoteka sadrzi besmislene podatke");
              std::getline(ulaz, sadrzaj);
              if(!ulaz.eof() && !ulaz) throw std::logic_error ("Problemi pri citanju datoteke");
              if(ulaz.eof()) throw std::logic_error("Datoteka sadrzi besmislene podatke");
              double tezina_datoteka;
              ulaz>>tezina_datoteka;
              if(!ulaz.eof() && !ulaz) throw std::logic_error ("Problemi pri citanju datoteke");
              if(ulaz.eof()) throw std::logic_error("Datoteka sadrzi besmislene podatke");
              int broj_predmeta;
              ulaz>>broj_predmeta;
              if(!ulaz.eof() && !ulaz) throw std::logic_error ("Problemi pri citanju datoteke");
              if(ulaz.eof()) throw std::logic_error("Datoteka sadrzi besmislene podatke");
              std::vector<double> tezine;
              tezine.resize(broj_predmeta);
              for (int i = 0; i < broj_predmeta; i++) {
                  ulaz>>tezine[i];
              if(ulaz.eof()) throw std::logic_error("Datoteka sadrzi besmislene podatke");
              if(!ulaz.eof() && !ulaz) throw std::logic_error ("Datoteka sadrzi besmislene podatke");
              }
              pomocni_vektor.emplace_back(std::make_shared<Sanduk>(Sanduk(tezina_datoteka, sadrzaj, tezine)));
              ulaz.ignore(10000, '\n');
            } else if(slovo=='V') {
                if(!ulaz.eof() && !ulaz) throw std::logic_error ("Problemi pri citanju datoteke");
                if(ulaz.eof()) throw std::logic_error("Datoteka sadrzi besmislene podatke");
                std::getline(ulaz, sadrzaj);
                if(!ulaz.eof() && !ulaz) throw std::logic_error ("Problemi pri citanju datoteke");
                if(ulaz.eof()) throw std::logic_error("Datoteka sadrzi besmislene podatke");
                double tezina_vrece, tezina_pohranjene_materije;
                ulaz>>tezina_vrece>>tezina_pohranjene_materije;
                if(!ulaz.eof() && !ulaz) throw std::logic_error ("Problemi pri citanju datoteke");
                pomocni_vektor.emplace_back(std::make_shared<Vreca>(Vreca(tezina_vrece, sadrzaj, tezina_pohranjene_materije)));
                ulaz.ignore(10000, '\n');
            } else if(slovo=='B') {
                if(!ulaz.eof() && !ulaz) throw std::logic_error ("Problemi pri citanju datoteke");
                if(ulaz.eof()) throw std::logic_error("Datoteka sadrzi besmislene podatke");
                std::getline(ulaz, sadrzaj);
                if(!ulaz.eof() && !ulaz) throw std::logic_error ("Problemi pri citanju datoteke");
                if(ulaz.eof()) throw std::logic_error("Datoteka sadrzi besmislene podatke");
                double tezina_bureta, gustina, zapremina;
                ulaz>>tezina_bureta>>gustina>>zapremina;
                if(!ulaz.eof() && !ulaz) throw std::logic_error ("Problemi pri citanju datoteke");
                pomocni_vektor.emplace_back(std::make_shared<Bure>(Bure(tezina_bureta, sadrzaj, gustina, zapremina)));
                ulaz.ignore(10000, '\n');
            } else throw std::logic_error("Datoteka sadrzi besmislene podatke");
        }
        this->vektor_spremista=pomocni_vektor;
    }

};

class PolimorfniSpremnik {
  std::shared_ptr<Spremnik> p_spremnik;
  void Test() const { if(!p_spremnik) throw std::logic_error("Nespecificiran spremnik");}
 public:
 PolimorfniSpremnik() : p_spremnik(nullptr) {}
 ~PolimorfniSpremnik(){};
 PolimorfniSpremnik(const Spremnik &neki) : p_spremnik(neki.DajNoviSpremnik()) {}
 PolimorfniSpremnik(const PolimorfniSpremnik &neki) {
     if(!neki.p_spremnik) p_spremnik = nullptr;
     else p_spremnik = neki.p_spremnik->DajNoviSpremnik();
 }
 PolimorfniSpremnik(PolimorfniSpremnik &&neki) : p_spremnik(neki.p_spremnik){
 neki.p_spremnik = nullptr;
 }
 PolimorfniSpremnik &operator =(PolimorfniSpremnik neki){
     std::swap(p_spremnik, neki.p_spremnik);
     return *this;
 }
 double DajTezinu() const { 
    Test();
    return p_spremnik->DajTezinu();
 }
 double DajUkupnuTezinu() const {
     Test();
     return p_spremnik->DajUkupnuTezinu();
 }
 void Ispisi() const {
     Test();
     p_spremnik->Ispisi();
 }
};
  

int main ()
{
	try
    {

        PolimorfniSpremnik s1(Bure(5,"Benzin", 930, 70));
        PolimorfniSpremnik s2, s3, s4;
        s2 = Sanduk(3, "Tepsije", {0.5, 0.8, 0.6, 0.5});
        s3 = Vreca(0.1, "Patak", 15.5);
        std::cout << s1.DajTezinu() << std::endl;
        std::cout << s2.DajUkupnuTezinu() << std::endl;
        s3.Ispisi();
        s1 = s2;
        s1.Ispisi();
        s4.DajTezinu();
    }
    catch(std::logic_error izuzetak)
    {
        std::cout << izuzetak.what();
    }
	return 0;
}
