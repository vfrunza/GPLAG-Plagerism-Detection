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
class Skladiste{
    std::vector<std::shared_ptr<Spremnik>> spremnik;
    public:
    Skladiste(){}
    ~Skladiste(){}
    Skladiste(const Skladiste &p){
        spremnik.resize(p.spremnik.size());
        for(int i=0; i<p.spremnik.size(); i++) spremnik[i]=std::shared_ptr<Spremnik>(p.spremnik[i]->DajKopiju());
    }
    Skladiste(Skladiste &&p){
        std::swap(p.spremnik,spremnik);
    }
    Skladiste &operator =(const Skladiste &p){
        spremnik.resize(p.spremnik.size());
        for(int i=0; i<p.spremnik.size(); i++){
         for(int i=0; i<p.spremnik.size(); i++) spremnik[i]=std::shared_ptr<Spremnik>(p.spremnik[i]->DajKopiju());
        }
        return *this;
    }
    Skladiste &operator =(Skladiste &&p){
        spremnik=std::move(p.spremnik);
        return *this;
    }
    Spremnik &DodajSanduk(double tezina, std::string naziv, std::vector<double> tezina_predmeta){
        spremnik.push_back(std::make_shared<Sanduk>(Sanduk(tezina,naziv,tezina_predmeta)));
        return *spremnik[spremnik.size()-1];
    }
    Spremnik &DodajVrecu(double tezina, std::string naziv, double tezina_predmeta){
        spremnik.push_back(std::make_shared<Vreca>(Vreca(tezina,naziv,tezina_predmeta)));
        return *spremnik[spremnik.size()-1];
    }
    Spremnik &DodajBure(double tezina, std::string naziv, double gustina_predmeta, double zapremina_predmeta){
        spremnik.push_back(std::make_shared<Bure>(Bure(tezina,naziv,gustina_predmeta,zapremina_predmeta)));
        return *spremnik[spremnik.size()-1];
    }
    Spremnik &DodajSpremnik(Spremnik* tip_spremnika, bool dane){
        if(dane==true){
            spremnik.push_back(std::shared_ptr<Spremnik>(tip_spremnika));
            return *spremnik[spremnik.size()-1];
        } 
        else{
            spremnik.push_back(std::shared_ptr<Spremnik>(tip_spremnika->DajKopiju()));
        }
        return *tip_spremnika;
    }
    void BrisiSpremnik(Spremnik &s){
       // auto it=std::find(spremnik.begin(),spremnik.end(),s);
        
        
    }
    Spremnik &DajNajtezi(){
        if(spremnik.size()==0) throw std::range_error("Skladiste je prazno");
        return **std::max_element(spremnik.begin(),spremnik.end(),[](const std::shared_ptr<Spremnik> s1, const std::shared_ptr<Spremnik> s2){return s1->DajTezinu()<s2->DajTezinu();});
    }
    Spremnik &DajNajlaksi(){
        if(spremnik.size()==0) throw std::range_error("Skladiste je prazno");
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
    }
};
int main ()
{
    try{
    Skladiste ETF;
    ETF.UcitajIzDatoteke("ROBA.TXT");
    ETF.IzlistajSkladiste();
    }catch(std::range_error Izuzetak){
        std::cout<<Izuzetak.what();
    }catch(std::logic_error le){
        std::cout<<le.what();
    }
    /*
    try
    {

        Skladiste ETF;
        //Spremnik *s = ETF.DodajSpremnik(new Vreca(0.5, "Secer", 40), true);
        ETF.DodajSanduk(50, "Voce", {1,3,5,6});
        ETF.DodajVrecu(0.1, "Brasno", 25.5);
        ETF.DodajBure(5, "Krv", 1300, 150);
        ETF.DodajSpremnik(new Vreca(0.5, "Secer", 40), true);
        Bure *b = new Bure(15, "Voda", 1000, 200);
        ETF.DodajSpremnik(b, false);
        delete b;
        ETF.IzlistajSkladiste();

    }
    catch(std::range_error re)
    {
        std::cout << re.what();
    }*/
	return 0;
}
