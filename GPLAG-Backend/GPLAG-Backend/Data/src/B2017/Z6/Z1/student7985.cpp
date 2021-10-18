/B2017/2018: Zadaća 6, Zadatak 1
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <vector>
using std::make_shared;
using std::range_error;
using std::logic_error;
using std::shared_ptr;
using std::ifstream;
using std::string;
using std::vector;
using std::swap;
using std::move;
using std::cout;
using std::endl;

class Spremnik{
  protected:
    double kilograma;
    string sadrzaj;
  public:
    virtual ~Spremnik() {}
    Spremnik(double kilograma, string sadrzaj) : kilograma(kilograma), sadrzaj(sadrzaj) {}
     double DajTezinu() const { return kilograma; } // ne treba biti virtual ??
    virtual double DajUkupnuTezinu() const = 0;
    virtual void Ispisi() const = 0;
    virtual Spremnik* DajKopiju() const = 0;
};

class Sanduk : public Spremnik {
    vector<double> kg_vector;
  public: 
    Sanduk(double kilograma, string sadrzaj, vector<double> kg_vector) : 
        Spremnik(kilograma, sadrzaj), kg_vector(kg_vector) {}
    double DajUkupnuTezinu() const override {
        double suma(0);
        for(double x : kg_vector) suma += x;
        return suma + kilograma;
    }
    void Ispisi() const override {
        cout << "Vrsta spremnika: Sanduk" << endl;
        cout << "Sadrzaj: " << sadrzaj << endl;
        cout << "Tezine predmeta: ";
        for(double x : kg_vector) cout << x << " ";
        cout << "(kg)" << endl;
        cout << "Vlastita tezina: " << kilograma << " (kg)" << endl;
        cout << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << endl;
    }
    Spremnik* DajKopiju() const override {
        //return new Sanduk(kilograma, sadrzaj, kg_vector);
        return new Sanduk(*this);
    }
};
class Vreca : public Spremnik {
    double kg_materije;
  public:
    Vreca(double kilograma, string sadrzaj, double kg_materije) : 
        Spremnik(kilograma, sadrzaj), kg_materije(kg_materije) {}
    double DajUkupnuTezinu() const override {
        return kg_materije + kilograma;
    }
    void Ispisi() const override {
        cout << "Vrsta spremnika: Vreca" << endl;
        cout << "Sadrzaj: " << sadrzaj << endl;
        cout << "Vlastita tezina: " << kilograma << " (kg)" << endl;
        cout << "Tezina pohranjene materije: " << kg_materije << " (kg)" << endl;
        cout << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << endl;
    }
    Spremnik* DajKopiju() const override {
        //return new Vreca(kilograma, sadrzaj, kg_materije);
        return new Vreca(*this);
    }
};
class Bure : public Spremnik {
    double gustina, zapremina;
  public:
    Bure(double kilograma, string sadrzaj, double gustina, double zapremina) : 
        Spremnik(kilograma, sadrzaj), gustina(gustina), zapremina(zapremina) {}
    double DajUkupnuTezinu() const override {
        return kilograma + zapremina*gustina/1000.0 ;
    }
    void Ispisi() const override {
        cout << "Vrsta spremnika: Bure" << endl;
        cout << "Sadrzaj: " << sadrzaj << endl;
        cout << "Vlastita tezina: " << kilograma << " (kg)" << endl;
        cout << "Specificna tezina tecnosti: " << gustina << " (kg/m^3)" << endl;
        cout << "Zapremina tecnosti: " << zapremina << " (l)" << endl;
        cout << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << endl;
    }
    Spremnik* DajKopiju() const override {
        //return new Bure(kilograma, sadrzaj, gustina, zapremina); 
        return new Bure(*this); // **  isto
    }
};

class Skladiste{
    vector<shared_ptr<Spremnik>> v;
    static void Izuzetak() { throw logic_error("Datoteka sadrzi besmislene podatke"); }
  public:
    explicit Skladiste() {}
    Skladiste(const Skladiste &s){
        vector<shared_ptr<Spremnik>> pom;
        for(int i=0; i<s.v.size(); i++) pom.emplace_back(shared_ptr<Spremnik> (s.v[i]->DajKopiju()));
        v = move(pom);
    }
    Skladiste& operator =(Skladiste s){
        swap(v, s.v);
        return *this;
    }
    Skladiste(Skladiste &&s){
        swap(s.v, v); 
    }
    // kad se kopirajuci operator dodjele ne realizuje tehnikom copy&swap,
    // poseban pomjerajuci operator dodjele nije ni potreban (zahv. eliziji)
    
    Spremnik* DodajSanduk(double kilograma, string sadrzaj, vector<double> kg_vector){
        v.emplace_back(make_shared<Sanduk> (Sanduk(kilograma, sadrzaj, kg_vector)));
        return (v[v.size()-1]).get();
    }
    Spremnik* DodajVrecu(double kilograma, string sadrzaj, double kg_materije){
        v.emplace_back(make_shared<Vreca> (Vreca(kilograma, sadrzaj, kg_materije)));
        return (v[v.size()-1]).get();
    }
    Spremnik* DodajBure(double kilograma, string sadrzaj, double gustina, double zapremina){
        v.emplace_back(make_shared<Bure> (Bure(kilograma, sadrzaj, gustina, zapremina)));
        return (v[v.size()-1]).get();
    }
    Spremnik* DodajSpremnik(Spremnik *spremnik, bool pripada_klasi){
        if(pripada_klasi){
            v.emplace_back(shared_ptr<Spremnik> (spremnik));
            return spremnik;
        }
        Spremnik* pom(spremnik->DajKopiju());
        v.emplace_back(shared_ptr<Spremnik> (pom));
        return pom;
    }
    void BrisiSpremnik(Spremnik *spremnik){
        for(int i=0; i<v.size(); i++){
            if(spremnik == (v[i]).get()){
                v[i] = nullptr;
                v.erase(v.begin()+i);
                break;
            }
        }
    }
    Spremnik& DajNajlaksi(){
        if(v.size() == 0) throw range_error("Skladiste je prazno");
        return **std::min_element(v.begin(), v.end(), [](shared_ptr<Spremnik> p1, shared_ptr<Spremnik> p2){
            return p1->DajTezinu() < p2->DajTezinu();
        });
    }
    // ?? ne smiju se moci pozvati nad konstantnim objektima tipa Skladiste
    Spremnik& DajNajtezi(){
        if(v.size() == 0) throw range_error("Skladiste je prazno");
        return **std::max_element(v.begin(), v.end(), [](shared_ptr<Spremnik> p1, shared_ptr<Spremnik> p2){
            return p1->DajTezinu() < p2->DajTezinu();
        });
    }
    int BrojPreteskih(int x) const { // **
        return std::count_if(v.begin(), v.end(), [x](shared_ptr<Spremnik> p){
            return p->DajUkupnuTezinu() > x;
        });
    }
    void IzlistajSkladiste() const {
        vector<Spremnik*> pom;
        for(auto p : v) pom.emplace_back(p.get());
        std::sort(pom.begin(), pom.end(), [](Spremnik* p1, Spremnik* p2){
            return p1->DajUkupnuTezinu() > p2->DajUkupnuTezinu();
        });
        for(Spremnik* p : pom) p->Ispisi();
    }
    void UcitajIzDatoteke(string ime_datoteke){ // string oder ?? **
        ifstream tok(ime_datoteke);
        if(!tok) throw logic_error("Trazena datoteka ne postoji");
        *this = Skladiste();
        char c;
        while(tok >> c){
            while(tok.peek() == ' ') tok.get();
            string sadrzaj;
            std::getline(tok, sadrzaj);
            double kilograma;
            if(c == 'S'){
                int broj_predmeta;
                tok >> kilograma >> broj_predmeta;
                if(!tok) Izuzetak();
                vector<double> kg_vector(broj_predmeta);
                for(double &x : kg_vector) {
                    tok >> x;
                    if(!tok) Izuzetak();
                }
                if(tok.peek() != EOF && tok.peek() != '\n') Izuzetak();
                DodajSanduk(kilograma, sadrzaj, kg_vector);
            }
            else if(c == 'V'){
                double kg_materije;
                tok >> kilograma >> kg_materije;
                if(!tok || (tok.peek() != EOF && tok.peek() != '\n')) Izuzetak();
                DodajVrecu(kilograma, sadrzaj, kg_materije);
            }
            else if(c == 'B'){
                double ro, ve;
                tok >> kilograma >> ro >> ve;
                if(!tok || (tok.peek() != EOF && tok.peek() != '\n')) Izuzetak();
                DodajBure(kilograma, sadrzaj, ro, ve);
            }
            else {
                Izuzetak();
            }
        }
    }
    
    
};

int main (){
    try{
        Skladiste s;
        s.UcitajIzDatoteke("ROBA.TXT");
        s.IzlistajSkladiste();
    }
    catch(range_error er){
        cout << er.what();
    }
    catch(logic_error er){
        cout << er.what();
    }
	return 0;
}
