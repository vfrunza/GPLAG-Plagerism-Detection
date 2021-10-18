/B2017/2018: Zadaća 6, Zadatak 2
/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>
#include <fstream>
#include <algorithm>
class Spremnik{
    protected:
    double tezina;
    std::string naziv;
    public:
    Spremnik(){}
    Spremnik(double tezina, std::string naziv):tezina(tezina),naziv(naziv){}
    double DajTezinu()const{
        return tezina;
    }
    virtual double DajUkupnuTezinu()const=0;
    virtual Spremnik *DajKopiju()const=0;
    virtual void Ispisi()const{};
    virtual ~Spremnik(){}
};
class Sanduk:public Spremnik{
    std::vector<double> tezina_predmeta;
    public:
    Sanduk(){}
    Sanduk(double tezina, std::string naziv, std::vector<double> tezina_predmeta):Spremnik(tezina,naziv),tezina_predmeta(tezina_predmeta){}
    double DajUkupnuTezinu()const override{
        double suma_tezina_predmeta(0);
        for(int i=0; i<tezina_predmeta.size(); i++) suma_tezina_predmeta+=tezina_predmeta.at(i);
        return double(tezina+suma_tezina_predmeta);
    }
    Sanduk *DajKopiju()const override{
        return new Sanduk(*this);
    }
    void Ispisi()const{
        std::cout<<"Vrsta spremnika: Sanduk"<<std::endl;
        std::cout<<"Sadrzaj: "<<naziv<<std::endl;
        std::cout<<"Tezine predmeta: ";
        for(auto x:tezina_predmeta)std::cout<<x<<" ";
        std::cout<<"(kg)"<<std::endl;
        std::cout<<"Vlastita tezina: "<<tezina<<" (kg)"<<std::endl;
        std::cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
};
class Vreca:public Spremnik{
    double tezina_predmeta;
    public:
    Vreca(){}
    Vreca(double tezina, std::string naziv, double tezina_predmeta):Spremnik(tezina,naziv),tezina_predmeta(tezina_predmeta){}
    double DajUkupnuTezinu()const override{
        return double(tezina+tezina_predmeta);
    }
    Vreca *DajKopiju()const override{
        return new Vreca(*this);
    }
    void Ispisi()const{
        std::cout<<"Vrsta spremnika: Vreca"<<std::endl;
        std::cout<<"Sadrzaj: "<<naziv<<std::endl;
        std::cout<<"Vlastita tezina: "<<tezina<<" (kg)"<<std::endl;
        std::cout<<"Tezina pohranjene materije: "<<tezina_predmeta<<" (kg)"<<std::endl;
        std::cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
};
class Bure:public Spremnik{
    double gustina_predmeta;
    double zapremina_predmeta;
    public:
    Bure(){}
    Bure(double tezina, std::string naziv, double gustina_predmeta, double zapremina_predmeta):Spremnik(tezina,naziv), gustina_predmeta(gustina_predmeta),zapremina_predmeta(zapremina_predmeta){}
    double DajUkupnuTezinu()const override{
        return double(tezina+(gustina_predmeta*zapremina_predmeta/1000));
    }
    Bure *DajKopiju()const override{
        return new Bure(*this);
    }
    void Ispisi()const{
        std::cout<<"Vrsta spremnika: Bure"<<std::endl;
        std::cout<<"Sadrzaj: "<<naziv<<std::endl;
        std::cout<<"Vlastita tezina: "<<tezina<<" (kg)"<<std::endl;
        std::cout<<"Specificna tezina tecnosti: "<<gustina_predmeta<<" (kg/m^3)"<<std::endl;
        std::cout<<"Zapremina tecnosti: "<<zapremina_predmeta<<" (l)"<<std::endl;
        std::cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
};
class PolimorfniSpremnik{
    Spremnik* spremnik;
    public:
    PolimorfniSpremnik():spremnik(nullptr){}
    ~PolimorfniSpremnik(){delete spremnik;}
    PolimorfniSpremnik(const Spremnik &p):spremnik(p.DajKopiju()){}
    PolimorfniSpremnik(const PolimorfniSpremnik &p){
         if(!p.spremnik) spremnik = nullptr;     
         else spremnik = p.spremnik->DajKopiju();
    }
    PolimorfniSpremnik(PolimorfniSpremnik &&p){
         spremnik = p.spremnik; p.spremnik = nullptr; 
    }
    PolimorfniSpremnik &operator =(const PolimorfniSpremnik &p){
         Spremnik *p_novi(nullptr);     
         if(p.spremnik != nullptr) p_novi = p.spremnik->DajKopiju();     
         delete spremnik;     
         spremnik = p_novi;
        return *this;
    }
    PolimorfniSpremnik &operator =(PolimorfniSpremnik &&p){
        std::swap(spremnik, p.spremnik);
        return *this;
    }
    Spremnik &DodajSanduk(double tezina, std::string naziv, std::vector<double> tezina_predmeta){
        spremnik=Sanduk(tezina,naziv,tezina_predmeta).DajKopiju();
        return *spremnik;
    }
    Spremnik &DodajVrecu(double tezina, std::string naziv, double tezina_predmeta){
        spremnik=Vreca(tezina,naziv,tezina_predmeta).DajKopiju();
        return *spremnik;
    }
    Spremnik &DodajBure(double tezina, std::string naziv, double gustina_predmeta, double zapremina_predmeta){
        spremnik=Bure(tezina,naziv,gustina_predmeta,zapremina_predmeta).DajKopiju();
        return *spremnik;
    }
    Spremnik &DodajSpremnik(Spremnik* tip_spremnika, bool dane){
        if(dane==true){
            spremnik=tip_spremnika->DajKopiju();
            return *spremnik;
        } 
        else{
            spremnik=tip_spremnika->DajKopiju();
        }
        return *tip_spremnika;
    }
    void BrisiSpremnik(Spremnik &s){
       // auto it=std::find(spremnik.begin(),spremnik.end(),s);
        
        
    }
    double DajTezinu()const{
        if(spremnik==nullptr) throw std::logic_error("Nespecificiran spremnik");
        return (*spremnik).DajTezinu();
    }
    double DajUkupnuTezinu()const{
        if(spremnik==nullptr) throw std::logic_error("Nespecificiran spremnik");
        return (*spremnik).DajUkupnuTezinu();
    }
    void Ispisi()const{
        if(spremnik==nullptr) throw std::logic_error("Nespecificiran spremnik");
        return (*spremnik).Ispisi();
    }
    /*
    Spremnik &DajNajtezi(){
        if(spremnik==nullptr) throw std::range_error("Skladiste je prazno");
        return **std::max_element(spremnik.begin(),spremnik.end(),[](const std::shared_ptr<Spremnik> s1, const std::shared_ptr<Spremnik> s2){return s1->DajTezinu()<s2->DajTezinu();});
    }
    Spremnik &DajNajlaksi(){
        if(spremnik==nullptr) throw std::range_error("Skladiste je prazno");
        return **std::min_element(spremnik.begin(),spremnik.end(),[](const std::shared_ptr<Spremnik> s1, const std::shared_ptr<Spremnik> s2){return s1->DajTezinu()<s2->DajTezinu();});
    }
    int BrojPreteskih(int velicina)const{
        return std::count_if(spremnik.begin(),spremnik.end(),[velicina](const std::shared_ptr<Spremnik> s1){ return s1->DajUkupnuTezinu()>velicina;});
    }
    void IzlistajSkladiste()const{
        std::vector<std::shared_ptr<Spremnik>> v(spremnik);
        std::sort(v.begin(),v.end(),[](const std::shared_ptr<Spremnik> s1, const std::shared_ptr<Spremnik> s2){return s1->DajUkupnuTezinu()>s2->DajUkupnuTezinu();});
        for(auto x : v) x->Ispisi();
    }
    void UcitajIzDatoteke(std::string s){
        spremnik.resize(0);
        std::ifstream ulazni_tok(s);
        if(!ulazni_tok) throw std::logic_error("Trazena datoteka ne postoji");
        std::string naziv_predmeta;
        char naziv_spremista;
        char znak;
        double tezina;
        double tezina_predmeta;
        double zapremina_predmeta;
        int broj_predmeta;
        bool test=0;
        for(;;){
            ulazni_tok >> naziv_spremista; if(naziv_spremista != 'S' && naziv_spremista != 'V' && naziv_spremista != 'B') { test=1; break; }
            ulazni_tok>>znak;
            std::getline(ulazni_tok,naziv_predmeta);
            naziv_predmeta=znak+naziv_predmeta;
            if(naziv_spremista=='S'){
                std::vector<double> tezina_predmeta_v;
                ulazni_tok >> tezina >> broj_predmeta;
                for(int i=0; i<broj_predmeta; i++) { ulazni_tok >> tezina_predmeta; tezina_predmeta_v.push_back(tezina_predmeta);}
                if(!ulazni_tok){ test=1; break; }
                DodajSanduk(tezina,naziv_predmeta,tezina_predmeta_v);
            }
            if(naziv_spremista=='V'){
                ulazni_tok >> tezina >> tezina_predmeta; if(!ulazni_tok) { test=1; break; }
                DodajVrecu(tezina,naziv_predmeta,tezina_predmeta);
            }
            if(naziv_spremista=='B'){
                ulazni_tok >> tezina >> tezina_predmeta >> zapremina_predmeta; if(!ulazni_tok) { test=1; break; }
                DodajBure(tezina,naziv_predmeta,tezina_predmeta,zapremina_predmeta);
            }
            //ulazni_tok.ignore(1000,'\n');
        }
        if(ulazni_tok.bad()) throw  std::logic_error("Problemi pri citanju datoteke");  
        if(test==1 && (!ulazni_tok.eof())) throw std::logic_error("Datoteka sadrzi besmislene podatke");
    }*/
};

int main (){
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
    catch(std::logic_error le)
    {
        std::cout << le.what();
    }
	return 0;
}

