#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <stdexcept>
#include <fstream>

class Spremnik {
    double tezina;
    std::string naziv;
    
    public:
    Spremnik(double tezina, std::string naziv): tezina(tezina), naziv(naziv){}
    double DajTezinu() const { return tezina;}
    virtual double DajUkupnuTezinu() const =0;
    virtual void Ispisi() const { std::cout<<"Sadrzaj: "<<naziv<<std::endl;}
     virtual std::shared_ptr<Spremnik> DajKopiju() const =0;
     virtual ~Spremnik()=default;
        
    
};
class Sanduk:public Spremnik {
    std::vector<double> tezine_predmeta;
    public:
    Sanduk(double tezina, std::string naziv, std::vector<double> tezine_predmeta): Spremnik(tezina, naziv), 
    tezine_predmeta(tezine_predmeta) {}
    double DajUkupnuTezinu() const override{
        double suma(0);
        std::for_each(tezine_predmeta.begin(), tezine_predmeta.end(), [&suma](double p){suma+=p; });
        suma+=DajTezinu();
        return suma;
    }
    void Ispisi() const override{
        std::cout<<"Vrsta spremnika: Sanduk"<<std::endl;
        Spremnik::Ispisi();
                std::cout<<"Tezine predmeta: "; 
    std::for_each(tezine_predmeta.begin(), tezine_predmeta.end(), [](double p){std::cout<<p<<" ";});
    std::cout<<"(kg)"<<std::endl
    <<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<std::endl
    <<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
                 
    }
    std::shared_ptr<Spremnik> DajKopiju() const override {
        return std::make_shared<Sanduk> (*this);
    }
    
    
};

class Vreca: public Spremnik{
    double tezina_materije;
    public:
    Vreca(double tezina, std::string naziv, double tezina_materije): Spremnik(tezina, naziv), 
    tezina_materije(tezina_materije){}
    double DajUkupnuTezinu() const { return DajTezinu()+tezina_materije;}
    void Ispisi() const override{
        std::cout<<"Vrsta spremnika: Vreca"<<std::endl;
        Spremnik::Ispisi();
                
   std::cout <<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<std::endl
    <<"Tezina pohranjene materije: "<<tezina_materije<<" (kg)"<<std::endl
    <<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
                 
    }
    std::shared_ptr<Spremnik> DajKopiju() const override {
        return std::make_shared<Vreca> (*this);
    }
    
};
class Bure: public Spremnik{
    double specificna_tezina, zapremina;
    public:
    Bure(double tezina, std::string naziv, double specificna_tezina, double zapremina): Spremnik(tezina, naziv), 
    specificna_tezina(specificna_tezina), zapremina(zapremina){}
    double DajUkupnuTezinu() const { return DajTezinu()+specificna_tezina*zapremina/1000.;}
    void Ispisi() const override{
        std::cout<<"Vrsta spremnika: Bure"<<std::endl;
        Spremnik::Ispisi();
                
   std::cout <<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<std::endl
    <<"Specificna tezina tecnosti: "<<specificna_tezina<<" (kg/m^3)"<<std::endl
    <<"Zapremina tecnosti: "<<zapremina<<" (l)"<<std::endl
    <<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
                 
    }
    std::shared_ptr<Spremnik> DajKopiju() const override {
        return std::make_shared<Bure> (*this);
    }
    
};

class PolimorfniSpremnik{
    std::shared_ptr<Spremnik> p_spremnik;
    void Test() const { 
        if(!p_spremnik) throw std::logic_error("Nespecificiran spremnik");
}
public:
PolimorfniSpremnik() : p_spremnik(nullptr){}
~PolimorfniSpremnik()=default;
PolimorfniSpremnik(const Spremnik& s):p_spremnik(s.DajKopiju()){}
PolimorfniSpremnik(const PolimorfniSpremnik& p){
    if(!p.p_spremnik) p_spremnik=nullptr;
    else p_spremnik=p.p_spremnik->DajKopiju();
}
PolimorfniSpremnik(PolimorfniSpremnik && s){
    p_spremnik=s.p_spremnik; s.p_spremnik=nullptr;
}
PolimorfniSpremnik & operator=(const PolimorfniSpremnik& s){
   
    if(s.p_spremnik)p_spremnik=s.p_spremnik->DajKopiju();
    else p_spremnik=nullptr;
   
    return *this;
    
}

PolimorfniSpremnik& operator =( PolimorfniSpremnik&&s){
    p_spremnik=s.p_spremnik;
    s.p_spremnik=nullptr;
    return *this;
}
 double DajTezinu() const {Test(); return p_spremnik->DajTezinu();}
    double DajUkupnuTezinu() const { Test(); return p_spremnik->DajUkupnuTezinu();}
    void Ispisi() const { Test(); p_spremnik->Ispisi();}   


};
int main(){
    PolimorfniSpremnik s1(Sanduk(3, "Svicevi :D", {5, 2, 3, 1, 7, 8}));
std::cout << s1.DajTezinu()  << std::endl << s1.DajUkupnuTezinu() << std::endl;
s1.Ispisi();

    return 0;
}