/B2017/2018: Zadaća 6, Zadatak 2
#include <iostream>
#include <memory>
#include <algorithm>
#include <string>
#include <vector>
#include <stdexcept>

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

class PolimorfniSpremnik {
    std::shared_ptr<Spremnik>p_spremnik;
    void Test() const {
        if(p_spremnik==nullptr) throw std::logic_error ("Nespecificiran spremnik");
    }
    
    public:
    PolimorfniSpremnik() {p_spremnik=nullptr;}
    PolimorfniSpremnik(const Spremnik &novi){p_spremnik=novi.DajKopiju();}
    PolimorfniSpremnik(const PolimorfniSpremnik &novi){
        if(novi.p_spremnik==nullptr) p_spremnik=nullptr;
        else p_spremnik=novi.p_spremnik->DajKopiju();
    }
    
    PolimorfniSpremnik(PolimorfniSpremnik &&novi){
        p_spremnik=novi.p_spremnik;
        novi.p_spremnik=nullptr;
    }
    PolimorfniSpremnik &operator=(PolimorfniSpremnik novi){
        std::swap(p_spremnik,novi.p_spremnik);
        return *this;
    }
    
    void Ispisi() const{
        Test();
        p_spremnik->Ispisi();
    }
    
    double DajTezinu() const { 
        Test();
        return p_spremnik->DajTezinu();
    }
    
    double DajUkupnuTezinu() const{
        Test();
        return p_spremnik->DajUkupnuTezinu();
    }
};

int main ()
{
    try{
        PolimorfniSpremnik spremnik1(Bure(2,"Benzin",800,70));
        PolimorfniSpremnik spremnik2, spremnik3;
        spremnik2=Sanduk(3, "Tepsije", {0.5,0.8,0.6,0.5});
        spremnik3=Vreca(0.2, "Brasno", 20);
        cout<<spremnik1.DajTezinu()<<std::endl;
        cout<<spremnik2.DajUkupnuTezinu()<<std::endl;
        spremnik3.Ispisi();
        spremnik1=spremnik2;
        cout<<std::endl;
        spremnik1.Ispisi();
        PolimorfniSpremnik nespecificiran;
        nespecificiran.DajTezinu();
    }
    catch(std::logic_error izuzetak) {
        std::cout<<"\nIZUZETAK: "<<izuzetak.what();
    }
	return 0;
}
