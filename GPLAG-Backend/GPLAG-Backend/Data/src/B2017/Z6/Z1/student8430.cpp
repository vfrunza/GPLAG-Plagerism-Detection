/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <fstream>

class Spremnik{
    protected:
    double tezina;
    std::string ime;
    public:
    virtual ~Spremnik(){}
    Spremnik(double a, std::string s): tezina(a), ime(s){};
    virtual double DajTezinu() const{return tezina;};
    virtual double DajUkupnuTezinu() const = 0;
    virtual void Ispisi() const = 0;
    virtual Spremnik *DajKopiju()const=0;
};

class Sanduk: public Spremnik{
    std::vector<double> tezina_predmeta;
    double suma;
    public:
    ~Sanduk(){}
    Sanduk(double a, std::string s, std::vector<double> v): Spremnik(a, s), tezina_predmeta(v){}
    double DajUkupnuTezinu() const{
        double suma(0);
        for(int i=0; i<tezina_predmeta.size(); i++){
            suma+=tezina_predmeta[i];
        }
        return tezina+suma;
    }
    Spremnik *DajKopiju()const override{return new Sanduk(*this);}
    void Ispisi() const{
        std::cout<<"Vrsta spremnika: Sanduk\n"<<"Sadrzaj: "<<ime<<"\nTezine predmeta: ";
        for(auto x:tezina_predmeta){
            std::cout<<x<<" ";
        }
        std::cout<<"(kg)";
        std::cout<<"\nVlastita tezina: "<<DajTezinu()<<" (kg)"<<std::endl<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
};

class Vreca: public Spremnik{
    double tezina_praska;
    public:
    ~Vreca(){}
    Vreca(double a, std::string s, double b): Spremnik(a, s), tezina_praska(b){}
    double DajUkupnuTezinu() const{return tezina+tezina_praska;}
    Spremnik *DajKopiju()const override{return new Vreca(*this);}
    void Ispisi() const{
        std::cout<<"Vrsta spremnika: Vreca\n"<<"Sadrzaj: "<<ime<<std::endl;
        std::cout<<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<"\nTezina pohranjene materije: "<<tezina_praska<<" (kg)"<<std::endl<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
};

class Bure: public Spremnik{
    double gustina_tecnosti, zapremina_tecnosti;
    public:
    ~Bure(){}
    Bure(double a, std::string s, double b, double c): Spremnik(a,s), gustina_tecnosti(b), zapremina_tecnosti(c){}
    double DajUkupnuTezinu() const{return tezina+(gustina_tecnosti*(zapremina_tecnosti/1000));}                                                //POKUSAJ PODIJELITI GUSTINU SA ZAPREMINOM
    Spremnik *DajKopiju()const override{return new Bure(*this);}
    void Ispisi() const{
        std::cout<<"Vrsta spremnika: Bure\n"<<"Sadrzaj: "<<ime<<std::endl;
        std::cout<<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<std::endl<<"Specificna tezina tecnosti: "<<gustina_tecnosti<<" (kg/m^3)"<<std::endl<<"Zapremina tecnosti: "<<zapremina_tecnosti<<" (l)"<<std::endl<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
};

class Skladiste{
    std::vector<std::shared_ptr<Spremnik>> vec_pok;
    static Spremnik *pok;
    public:
    Skladiste(){}
    Spremnik *DodajSanduk(double a, std::string s,std::vector<double> v){
        std::shared_ptr<Sanduk> k(new Sanduk(a,s,v));
        vec_pok.push_back(k); //NEDOVRSENO
        pok=k.get();
        return k.get();
    }
    Spremnik *DodajVrecu(double a, std::string s, double b){
        std::shared_ptr<Vreca> k(new Vreca(a, s, b));
        vec_pok.push_back(k); 
        pok=k.get();
        return k.get();
    }
    Spremnik *DodajBure(double a, std::string s, double b, double c){
        std::shared_ptr<Bure> k(new Bure(a, s, b, c));
        vec_pok.push_back(k);
        pok=k.get();
        return k.get();
    }
    Spremnik *DodajSpremnik(Spremnik *a, bool k){
        if(k){
            vec_pok.emplace_back(std::move(a));
            return std::move(a);
        }
        else vec_pok.emplace_back(a->DajKopiju());
    }
    void BrisiSpremnik(Spremnik *a){
         delete a;
    }
    Spremnik &DajNajlaksi()const{
        try{
            if(vec_pok.size()==0) throw std::range_error("Skladiste je prazno");
            return **std::min_element(vec_pok.begin(), vec_pok.end(), [](std::shared_ptr<Spremnik> a, std::shared_ptr<Spremnik> b){return a->DajTezinu()<b->DajTezinu();});
        }catch(std::range_error e){
            throw;
        }
    }
    Spremnik &DajNajtezi()const{
        try{
            if(vec_pok.size()==0) throw std::range_error("Skladiste je prazno");
            return **std::max_element(vec_pok.begin(), vec_pok.end(), [](std::shared_ptr<Spremnik> a, std::shared_ptr<Spremnik> b){return a->DajTezinu()<b->DajTezinu();});
        }catch(std::range_error e){
            throw;
        }
    }
    int BrojPreteskih(double z)const{
        return std::count_if(vec_pok.begin(), vec_pok.end(), [z](std::shared_ptr<Spremnik> a){return a->DajUkupnuTezinu()>z;});
    }
    void IzlistajSkladiste(){
        std::sort(vec_pok.begin(), vec_pok.end(), [](std::shared_ptr<Spremnik> a, std::shared_ptr<Spremnik> b){return a->DajUkupnuTezinu()>b->DajUkupnuTezinu();});
        std::for_each(vec_pok.begin(), vec_pok.end(), [](std::shared_ptr<Spremnik> a) {a->Ispisi();});
    }
    void UcitajIzDatoteke(std::string ime_datoteke){
        try{
        if(vec_pok.size()!=0) vec_pok.resize(0);
        std::ifstream citaj(ime_datoteke);
        if(!citaj) throw std::logic_error("Trazena datoteka ne postoji");
        double tezina, broj, clan;
        std::vector<double> clanovi;
        std::string recenica, znak;
        while(getline(citaj, recenica)){
            if(!citaj) throw std::logic_error("Datoteka sadrzi besmislene podatke");
            if(recenica[0]=='S'){
                citaj>>tezina>>znak>>broj>>znak;
                if(!citaj) throw std::logic_error("Datoteka sadrzi besmislene podatke");
                while(citaj>>clan>>znak){
                    throw std::logic_error("Datoteka sadrzi besmislene podatke");
                    clanovi.push_back(clan);
                }
            }else if(recenica.at(0)=='V'){
                citaj>>tezina>>znak>>clan;
                throw std::logic_error("Datoteka sadrzi besmislene podatke");
            }else{
                citaj>>tezina>>znak>>clan>>znak>>broj;
                throw std::logic_error("Datoteka sadrzi besmislene podatke");
            }
        }
        }catch(std::logic_error e){
            throw;
        }
        
    }
};

Spremnik *Skladiste::pok(nullptr);


int main ()
{
 try
{
    std::ofstream izlaz("TEST.TXT");
    izlaz << "S Tepsije\n9 5 2 3 1 2 2 4 3 1 3\n";
    izlaz << "V Brasno\n0.9 100\n";
    izlaz << "B Suncokretovo ulje\n5 1300 150";
    izlaz.flush();
    izlaz.close();

    Skladiste ETF;
    ETF.UcitajIzDatoteke("TEST.TXT");
    ETF.IzlistajSkladiste();
}
catch(std::logic_error le)
{
    std::cout << le.what();
}
	return 0;
}
