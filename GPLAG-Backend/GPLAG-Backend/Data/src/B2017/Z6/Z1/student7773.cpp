/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <memory>
#include <algorithm>
#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>


using std::cout;

class Spremnik {
    protected:
    double vlastita_tezina;
    std::string sadrzaj;
    
    public:
    Spremnik(double tezina, std::string sadrzaj):vlastita_tezina(tezina), sadrzaj(sadrzaj) {}
    virtual void Ispisi() const=0;
    virtual double DajTezinu() const { return vlastita_tezina;}
    virtual double DajUkupnuTezinu() const=0;
    virtual std::shared_ptr<Spremnik> DajKopiju() const=0;
};

class Sanduk: public Spremnik {
    std::vector<double> tezine_predmeta;
    
    public:
    Sanduk(double tezina, std::string sadrzaj, std::vector<double> tezine): Spremnik(tezina,sadrzaj), tezine_predmeta(tezine){}
    double DajUkupnuTezinu() const override{
        double suma(0);
        for (int i=0; i<tezine_predmeta.size();++i)
        suma+=tezine_predmeta[i];
        return suma+vlastita_tezina;
    }
    void Ispisi() const override {
        cout<<"Vrsta spremnika: Sanduk"<<std::endl<<"Sadrzaj: "<<sadrzaj<<std::endl<<"Tezine predmeta: ";
        for(int i(0);i<tezine_predmeta.size();++i)
        cout<<tezine_predmeta[i]<<" ";
        cout<<"(kg)"<<std::endl<<"Vlastita tezina: "<<vlastita_tezina<<" (kg)"<<std::endl<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)\n";
    }
    std::shared_ptr<Spremnik>DajKopiju()
    const override{ return std::make_shared<Sanduk>(*this);}
};

class Vreca : public Spremnik {
    double tezina_praska;
    
    public:
    Vreca(double tezina, std::string sadrzaj, double tezina_praska) : Spremnik(tezina,sadrzaj),tezina_praska(tezina_praska){}
    double DajUkupnuTezinu() const override{return tezina_praska+vlastita_tezina;}
    void Ispisi() const override {
        cout<<"Vrsta spremnika: Vreca"<<std::endl<<"Sadrzaj: "<<sadrzaj<<std::endl<<"Vlastita tezina: "<<vlastita_tezina;
        cout<<" (kg)"<<std::endl<<"Tezina pohranjene materije: "<<tezina_praska<<" (kg)"<<std::endl;
        cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)\n";
    };
    std::shared_ptr<Spremnik>DajKopiju()
    const override{ return std::make_shared<Vreca>(*this);}
};
class Bure : public Spremnik {
    double specificna_gustina;
    double zapremina_tecnosti;
    
    public:
    Bure(double tezina, std::string sadrzaj, double gustina, double zapremina) : Spremnik(tezina, sadrzaj), specificna_gustina(gustina),
                                                                                 zapremina_tecnosti(zapremina) {}
    double DajUkupnuTezinu() const override { return vlastita_tezina+(specificna_gustina*zapremina_tecnosti/1000); }
    void Ispisi() const override { cout<<"Vrsta spremnika: Bure"<<std::endl<<"Sadrzaj: "<<sadrzaj<<std::endl<<"Vlastita tezina: "
                                            <<vlastita_tezina<<" (kg)"<<std::endl<<"Specificna tezina tecnosti: "<<specificna_gustina<<" (kg/m^3)"
                                            <<std::endl<<"Zapremina tecnosti: "<<zapremina_tecnosti<<" (l)"<<std::endl
                                            <<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)\n"; }
    std::shared_ptr<Spremnik> DajKopiju() const override { return std::make_shared<Bure> (*this); }
};
class Skladiste {
    
    std::vector<std::shared_ptr<Spremnik>> spremnici;
    
    public:
    Skladiste() {}
    Skladiste(const Skladiste &s) {
        for(int i=0; i<s.spremnici.size(); ++i) spremnici.push_back(s.spremnici[i]->DajKopiju());
    }
    Skladiste(Skladiste &&s) { spremnici=s.spremnici; }
    Skladiste &operator=(Skladiste s) { std::swap(spremnici, s.spremnici); return *this; }
    Spremnik *DodajSanduk(double tezina, std::string sadrzaj, std::vector<double> tezine);
    Spremnik *DodajVrecu(double tezina, std::string sadrzaj, double tezina_praska);
    Spremnik *DodajBure(double tezina, std::string sadrzaj, double gustina, double zapremina);
    Spremnik *DodajSpremnik(Spremnik *novi, bool pobrini_se_o_meni);
    void BrisiSpremnik(Spremnik *obrisi_me);
    
    Spremnik &DajNajtezi() {
        if(spremnici.size()==0) throw std::range_error ("Skladiste je prazno");
        return **(std::max_element(spremnici.begin(), spremnici.end(),
                [] (std::shared_ptr<Spremnik> x, std::shared_ptr<Spremnik> y) {return x->DajTezinu() < y->DajTezinu(); } )); }
    Spremnik &DajNajlaksi() {
        if(spremnici.size()==0) throw std::range_error ("Skladiste je prazno");
        return **(std::min_element(spremnici.begin(), spremnici.end(),
                [] (std::shared_ptr<Spremnik> x, std::shared_ptr<Spremnik> y) {return x->DajTezinu() < y->DajTezinu(); } )); }
    int BrojPreteskih(int tezina) const {
        return std::count_if(spremnici.begin(), spremnici.end(),
                [tezina] (std::shared_ptr<Spremnik> x) { return x->DajUkupnuTezinu() > tezina;});
    }
    void IzlistajSkladiste() const ;
    void UcitajIzDatoteke(std::string ime_datoteke);
};

void Skladiste::IzlistajSkladiste() const {
    Skladiste pom(*this);
    std::sort(pom.spremnici.begin(),pom.spremnici.end(),[](std::shared_ptr<Spremnik>x, std::shared_ptr<Spremnik>y){
        return x->DajUkupnuTezinu() > y->DajUkupnuTezinu();
    });
    for(int i=0;i<pom.spremnici.size();i++){
        pom.spremnici[i]->Ispisi();
        cout<<std::endl;
    }
}

void Skladiste::UcitajIzDatoteke(std::string ime_datoteke){
    std::ifstream ulazni_tok(ime_datoteke);
    if(!ulazni_tok) throw std::logic_error("Trazena datoteka ne postoji");
    for(;;){
        char znak;
        ulazni_tok>>znak;
        if(znak=='S'){
            std::string sadrzaj, pom;
            ulazni_tok>>sadrzaj;
            std::getline(ulazni_tok,pom);
            sadrzaj+=pom;
            if(!ulazni_tok) break;
            double tezina_sanduka;
            int br;
            ulazni_tok>>tezina_sanduka>>br;
            if(!ulazni_tok) break;
            std::vector<double> tezine;
            for(int i=0;i<br;i++){
                double tezina_predmeta;
                ulazni_tok>>tezina_predmeta;
                if(!ulazni_tok) break;
                tezine.push_back(tezina_predmeta);
            }
            DodajSanduk(tezina_sanduka,sadrzaj,tezine);
            
        }
        else if(znak=='V'){
            std::string sadrzaj,pom;
            ulazni_tok>>sadrzaj;
            std::getline(ulazni_tok,pom);
            sadrzaj+=pom;
            if(!ulazni_tok) break;
            double tezina_vrece, tezina_praska;
            ulazni_tok>>tezina_vrece>>tezina_praska;
            if(!ulazni_tok) break;
            DodajVrecu(tezina_vrece,sadrzaj,tezina_praska);
        }
        else if(znak=='B'){
            std::string sadrzaj,pom;
            ulazni_tok>>sadrzaj;
            std::getline(ulazni_tok,pom);
            sadrzaj+=pom;
            if(!ulazni_tok)break;
            double tezina_bureta,gustina,zapremina;
            ulazni_tok>>tezina_bureta>>gustina>>zapremina;
            if(!ulazni_tok) break;
            DodajBure(tezina_bureta,sadrzaj,gustina,zapremina);
        }
        else throw std::logic_error("Datoteka sadrzi besmislene podatke");
    }
    if(ulazni_tok.bad()) throw std::logic_error("Problem pri citanju datoteke");
    else if(ulazni_tok.eof()) return;
    else throw std::logic_error("Datoteka sadrzi besmislene podatke");
}

Spremnik *Skladiste::DodajSanduk(double tezina, std::string sadrzaj, std::vector<double> tezine) {
    Sanduk pom(tezina, sadrzaj, tezine);
    spremnici.push_back(std::make_shared<Sanduk>(pom));
    Spremnik *glupi(spremnici[spremnici.size()-1].get());
    return glupi;
}
Spremnik *Skladiste::DodajVrecu(double tezina, std::string sadrzaj, double tezina_praska) {
    Vreca pom(tezina, sadrzaj, tezina_praska);
    spremnici.push_back(std::make_shared<Vreca>(pom));
    Spremnik *glupi(spremnici[spremnici.size()-1].get());
    return glupi;
}
Spremnik *Skladiste::DodajBure(double tezina, std::string sadrzaj, double gustina, double zapremina) {
    Bure pom(tezina, sadrzaj, gustina, zapremina);
    spremnici.push_back(std::make_shared<Bure>(pom));
    Spremnik *glupi(spremnici[spremnici.size()-1].get());
    return glupi;
}
Spremnik *Skladiste::DodajSpremnik(Spremnik *novi, bool pobrini_se_o_meni) {
    if(pobrini_se_o_meni==true) {
        std::shared_ptr<Spremnik> p(novi);
        spremnici.push_back(p);
    }
    else {
        spremnici.push_back(novi->DajKopiju());
    }
    Spremnik *glupi(spremnici[spremnici.size()-1].get());
    return glupi;
}
void Skladiste::BrisiSpremnik(Spremnik *obrisi_me) {
    int i;
    for(i=0; i<spremnici.size(); ++i) {
        if(spremnici[i].get()==obrisi_me) {
            spremnici.erase(spremnici.begin()+i);
            break;
        }
    }
}

int main ()
{
    cout<<"zavrsio";
    return 0;
}
