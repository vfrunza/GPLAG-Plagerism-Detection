/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <vector>
#include <memory>
#include <fstream>


class Spremnik {
    protected:
    double tezina;
    std::string naziv;
    public:
    friend class Skladiste;
    virtual void Ispisi()const=0;
    virtual double DajTezinu() { return tezina; }
    virtual double DajUkupnuTezinu()const=0;
    virtual std::shared_ptr<Spremnik> DajKopiju()=0;
};




class Sanduk: public Spremnik{
    std::vector<double> tezina_stvari;
    public:
    
    Sanduk(double tez, std::string naz, std::vector<double> tezt) {
        tezina=tez;
        naziv=naz;
        tezina_stvari=tezt;
    }
    
    double DajUkupnuTezinu() const override {
        double suma=0;
        for(int i=0; i<tezina_stvari.size(); i++) suma+=tezina_stvari[i];
        return suma+tezina;
    }
    
    std::shared_ptr<Spremnik> DajKopiju() {
        return std::make_shared<Sanduk>(this-> tezina, this-> naziv, this-> tezina_stvari);
    }
    
    void Ispisi() const override {
        int suma=0;
        std::cout << "Vrsta spremnika: Sanduk" << std::endl;
        std::cout << "Sadrzaj: "<<naziv << std::endl;
        std::cout << "Tezine predmeta: ";
        for(int i=0;i<tezina_stvari.size();i++) std::cout << tezina_stvari[i]<<" ";
        std::cout << "(kg)" << std::endl;
        std::cout << "Vlastita tezina: "<<tezina <<" (kg)"<< std::endl;
        std::cout << "Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)" << std::endl;
    }
};



class Vreca: public Spremnik {
    double tezina_materije;
    public:
    Vreca(double tez, std::string naz, double tezt) {
        tezina=tez;
        naziv=naz;
        tezina_materije=tezt;
    }
    
    double DajUkupnuTezinu() const override {
        return tezina_materije+tezina;
    }
    
    std::shared_ptr<Spremnik> DajKopiju() {
        return std::make_shared<Vreca> (this-> tezina, this-> naziv, this-> tezina_materije);
    }
    
    void Ispisi() const override {
        std::cout << "Vrsta spremnika: Vreca" << std::endl;
        std::cout << "Sadrzaj: " <<naziv<< std::endl;
        std::cout << "Vlastita tezina: "<<tezina<<" (kg)" << std::endl;
        std::cout << "Tezina pohranjene materije: "<<tezina_materije<<" (kg)" << std::endl;
        std::cout << "Ukupna tezina: "<<tezina+tezina_materije<<" (kg)" << std::endl;
    }
};


class Bure: public Spremnik {
    double specificna_gustina;
    double zapremina_tecnosti;
    public:
    Bure(double tez, std::string naz, double gustoca, double zapr) {
        tezina=tez;
        naziv=naz;
        specificna_gustina=gustoca;
        zapremina_tecnosti=zapr;
    }
    
    double DajUkupnuTezinu() const override {
        return tezina+(specificna_gustina*zapremina_tecnosti/1000);
    }
    
    std::shared_ptr<Spremnik> DajKopiju() {
        return std::make_shared<Bure> (this-> tezina, this-> naziv, this-> specificna_gustina, this-> zapremina_tecnosti);
    }
    
    void Ispisi() const override {
        double t(specificna_gustina*zapremina_tecnosti/1000);
        std::cout << "Vrsta spremnika: Bure" << std::endl;
        std::cout << "Sadrzaj: "<<naziv << std::endl;
        std::cout << "Vlastita tezina: "<<tezina<<" (kg)" << std::endl;
        std::cout << "Specificna tezina tecnosti: "<<specificna_gustina<<" (kg/m^3)" << std::endl;
        std::cout << "Zapremina tecnosti: "<<zapremina_tecnosti<<" (l)" << std::endl;
        std::cout << "Ukupna tezina: "<<tezina+t<<" (kg)" << std::endl;
    }
};



class Skladiste {
    std::vector<std::shared_ptr<Spremnik>> v;
    public:
    Skladiste() {}
    Skladiste(const Skladiste &s) {
        for(int i=0;i<s.v.size();i++) {
            v.push_back(s.v[i]-> DajKopiju());
        }
}
void operator=(const Skladiste &s) {
    for(int i=0; i<s.v.size();i++) {
        v.push_back(s.v[i]-> DajKopiju());
    }
}

Spremnik* DodajSanduk(double tez, std::string naz, std::vector<double> tezt) {
    auto d=std::make_shared<Sanduk>(tez, naz, tezt);
    v.push_back(d);
    return d.get();
}


Spremnik* DodajVrecu(double tez, std::string naz, double tezt) {
    auto d=std::make_shared<Vreca>(tez, naz, tezt);
    v.push_back(d);
    return d.get();
}


Spremnik* DodajBure(double tez, std::string naz, double gustoca, double zapr) {
    auto d=std::make_shared<Bure>(tez, naz, gustoca, zapr);
    v.push_back(d);
    return d.get();
}


Spremnik* DodajSpremnik(Spremnik *p, bool a) {
    if(a) {
        auto d=p-> DajKopiju();
        v.push_back(d);
        delete p;
        return d.get();
    }
    
    else {
        auto d=p-> DajKopiju();
        v.push_back(d);
        return d.get();
    }
}


void BrisiSpremnik(Spremnik* p) {
    for(int i=0; i<v.size(); i++) {
        if(p==v[i].get()) {
            v.erase(v.begin()+i);
            break;
        }
    }
}


Spremnik &DajNajlaksi() {
    int zapamti=0;
    for(int i=1; i<v.size();i++) {
        if(v[i]-> DajTezinu()< v[zapamti]-> DajTezinu()) zapamti=i;
    }
    return *(v[zapamti]);
}


Spremnik &DajNajtezi() {
    int zapamti=0;
    for(int i=1; i<v.size();i++) {
        if(v[i]-> DajTezinu() > v[zapamti]-> DajTezinu()) zapamti=i;
    }
    return *(v[zapamti]);
}


int BrojPreteskih(int a) const {
    int zapamti=0;
    for(int i=0; i<v.size();i++) {
        if(v[i]-> DajTezinu() > a) zapamti+=1;
    }
    return zapamti;
}


void MeineFunction() {
    int min=0;
    for(int i=1; i<v.size(); i++) {
        if(v[i]-> DajUkupnuTezinu() > v[min]-> DajUkupnuTezinu()) min=i;
    }
    v[min]-> Ispisi();
    v.erase(v.begin()+min);
}

void IzlistajSkladiste() {
    Skladiste s2(*this);
    
    for(int i=0; i<s2.v.size();) s2.MeineFunction(); 
}


void UcitajIzDatoteke(std::string s) {
    v.resize(0);
    std::ifstream ulaz(s);
    char c;
    while(ulaz >> c) {
        char sses;
        sses=ulaz.get();
        std::string s;
        if(c=='B') {
            std::getline(ulaz, s);
            double a,b,c;
            ulaz >>a >>b>>c;
            
            v.push_back(std::make_shared<Bure>(a,s,b,c));
            continue;
        }
        
        if(c=='V') {
            std::getline(ulaz, s);
            double a,b;
            ulaz >>a >>b;
            v.push_back(std::make_shared<Vreca>(a,s,b));
            continue;
        }
        
        if(c=='S') {
            std::getline(ulaz, s);
            double a,b;
            std::vector<double> c;
            ulaz >>a >>b;
        for(int i=0; i<b ;i++) {
            double te;
            ulaz >> te;
            c.push_back(te);
        }
        v.push_back(std::make_shared<Sanduk>(a,s,c));
        continue;
        }
        break;
        
    }

}
};
int main ()
{
    try
    {

        Skladiste ETF;
        ETF.DodajSanduk(50, "Voce", {1,3,5,6});
        ETF.DodajVrecu(0.1, "Brasno", 25.5);
        ETF.DodajBure(5, "Krv", 1300, 150);
        ETF.DodajSpremnik(new Vreca(0.5, "Secer", 40), true);
        Bure *b = new Bure(15, "Voda", 1000, 200);
        ETF.DodajSpremnik(b, false);
        delete b;
        ETF.DajNajlaksi().Ispisi();
        std::cout << ETF.BrojPreteskih(40) << std::endl;
        ETF.DajNajtezi().Ispisi();
    }
    catch(std::range_error re)
    {
        std::cout << re.what();
    }
	return 0;
}
