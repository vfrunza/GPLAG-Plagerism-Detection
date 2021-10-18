/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

class Spremnik {
    protected:
    double tezina;
    std::string naziv;
    public:
    Spremnik(double tezina, std::string naziv) : tezina(tezina), naziv(naziv) { }
    virtual ~Spremnik() {}
    double DajTezinu() const { return tezina; }
    virtual double DajUkupnuTezinu() const = 0;
    virtual void Ispisi() const = 0;
};

class Sanduk : public Spremnik {
    std::vector<double> t_predmeta;
    public:
    Sanduk(double tezina, std::string naziv, std::vector<double> t_predmeta) :
            Spremnik::Spremnik(tezina, naziv), t_predmeta(t_predmeta) { }
    double DajUkupnuTezinu() const {
        double ukupna(0);
        for(int i=0; i<t_predmeta.size(); i++)
            ukupna+=t_predmeta[i];
        return ukupna+tezina;
    }
    void Ispisi() const {
        std::cout<<"Vrsta spremnika: Sanduk"<<std::endl
                 <<"Sadrzaj: "<<naziv<<std::endl
                 <<"Tezine predmeta: ";
                 for(int i=0; i<t_predmeta.size(); i++) 
                    std::cout<<t_predmeta[i]<<" ";
        std::cout<<"(kg)"<<std::endl
                 <<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<std::endl
                 <<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
};

class Vreca : public Spremnik {
    double tezina_praha;
    public:
    Vreca(double tezina, std::string naziv, double tezina_praha) :
          Spremnik::Spremnik(tezina, naziv), tezina_praha(tezina_praha) { }
    double DajUkupnuTezinu() const { return tezina+tezina_praha; }
    void Ispisi() const {
        std::cout<<"Vrsta spremnika: Vreca"<<std::endl
                 <<"Sadrzaj: "<<naziv<<std::endl
                 <<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<std::endl
                 <<"Tezina pohranjene materije: "<<tezina_praha<<" (kg)"<<std::endl
                 <<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
};

class Bure : public Spremnik {
    double RO, V_tecnosti;
    public:
    Bure(double tezina, std::string naziv, double RO, double V_tecnosti) : 
         Spremnik::Spremnik(tezina, naziv), RO(RO), V_tecnosti(V_tecnosti) { }
    double DajUkupnuTezinu() const {
        return tezina + (RO * (V_tecnosti/1000));
    }
    void Ispisi() const {
        std::cout<<"Vrsta spremnika: Bure"<<std::endl
                 <<"Sadrzaj: "<<naziv<<std::endl
                 <<"Vlastita tezina: "<<tezina<<" (kg)"<<std::endl
                 <<"Specificna tezina tecnosti: "<<RO<<" (kg/m^3)"<<std::endl
                 <<"Zapremina tecnosti: "<<V_tecnosti<<" (l)"<<std::endl
                 <<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
};

class Skladiste {
    std::vector<std::shared_ptr<Spremnik>> v;
    public:
    Spremnik *DodajSanduk(double tezina, std::string naziv, std::vector<double> t_predmeta) {
        auto tmp = std::make_shared<Sanduk>(tezina,naziv,t_predmeta);
        v.push_back(tmp);
        return tmp.get();
    }
    Spremnik *DodajVrecu(double tezina, std::string naziv, double tezina_praha) {
       auto tmp = std::make_shared<Vreca>(tezina,naziv,tezina_praha);
        v.push_back(tmp);
        return tmp.get();
    }
    Spremnik *DodajBure(double tezina, std::string naziv, double RO, double V) {
        auto tmp = std::make_shared<Bure>(tezina,naziv,RO,V);
        v.push_back(tmp);
        return tmp.get();
    }
    Spremnik *DodajSpremnik(Spremnik *p, bool provjera) {
        
            
    }
    Spremnik &DajNajlaksi() {
        int min(0);
        int j(0);
        for(int i=0; i<v.size(); i++) {
            if(v[i]->DajTezinu()<min)
                min=v[i]->DajTezinu();
                j=i;
        }
    
    }
    void IzlistajSkladiste() const {
        for(int i=0; i<v.size(); i++) 
            v[i]->Ispisi();
    }
    
};

int main ()
{
    Sanduk s(1,"a", {2,2});
    s.Ispisi();
    Vreca v(2,"a",5);
    v.Ispisi();
    Bure b(5,"b", 1300, 150);
    b.Ispisi();
	return 0;
}
