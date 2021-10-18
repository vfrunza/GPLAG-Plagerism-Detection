/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <memory>
#include <vector>
#include <fstream>
#include <algorithm>
#include <stdexcept>
class Spremnik{
    protected:
    double kilo;
    std::string naziv;
    public:
    Spremnik(double tezi,std::string ime):kilo(tezi),naziv(ime){}
    double DajTezinu() const{ return kilo;}
    virtual double DajUkupnuTezinu() const=0;
    virtual std::shared_ptr<Spremnik> DajKopiju() const=0;
    virtual void Ispisi()const =0;
    virtual ~Spremnik(){}
};
class Bure:public Spremnik{
    double V;
    double specifi;
    public:
    Bure(double tezina,std::string ime,double s,double zapremina):Spremnik(tezina,ime),specifi(s),V(zapremina){}
    double DajUkupnuTezinu() const override{
        return kilo+(V/1000)*specifi;
        
    }
    std::shared_ptr<Spremnik> DajKopiju() const override{ return std::make_shared<Bure>(*this);
    }
    void Ispisi() const override{
        std::cout<<"Vrsta spremnika: Bure"<<std::endl<<"Sadrzaj: "<<naziv<<std::endl<<"Vlastita tezina: "<<
        kilo<<" (kg)"<<std::endl<<"Specificna tezina tecnosti: "<<specifi<<" (kg/m^3)"<<std::endl<<
        "Zapremina tecnosti: "<<V<<" (l)"<<std::endl<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
        
    }
   
};
class  Vreca: public Spremnik{
    double prah;
    public:
    Vreca(double tezina, std::string ime,double prah1):Spremnik(tezina,ime),prah(prah1){}
    double DajUkupnuTezinu()const override{
        return kilo+prah;
    }
    std::shared_ptr<Spremnik> DajKopiju() const override { return std::make_shared<Vreca>(*this);}
    void Ispisi() const override{
         std::cout<<"Vrsta spremnika: Vreca"<<std::endl<<"Sadrzaj: "<<naziv<<std::endl<<"Vlastita tezina: "<<
        kilo<<" (kg)"<<std::endl<<"Tezina pohranjene materije: "<<prah<<" (kg)"<<std::endl<<
        "Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
   
};
class Sanduk:public Spremnik{
std::vector<double> predmeti ;
public:
Sanduk(double tezina,std::string ime,std::vector<double>v):Spremnik(tezina,ime),predmeti(v){}
double DajUkupnuTezinu()const override{
    double suma=0;
    for(int i=0;i<predmeti.size();i++){
        suma=suma+predmeti[i];
    }
    return suma+kilo;
    
}
std::shared_ptr<Spremnik> DajKopiju() const override{ return std::make_shared<Sanduk>(*this);}
void Ispisi() const override{
    std::cout<<"Vrsta spremnika: Sanduk"<<std::endl<<"Sadrzaj: "<<naziv<<std::endl<<
    "Tezine predmeta: ";
    for(auto i:predmeti){
        std::cout<<i<<" ";
    }
    std::cout<<"(kg)"<<std::endl<<"Vlastita tezina: "<<kilo<<" (kg)"<<std::endl<<
    "Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
}

};
class Skladiste{
    std::vector<std::shared_ptr<Spremnik>> s;
    static bool Element(std::shared_ptr<Spremnik> s1,std::shared_ptr<Spremnik> s2){
        return s1->DajTezinu()<s2->DajTezinu();
    }
    public:
    Skladiste():s(0){}
    Spremnik *DodajSanduk(double tezina,std::string ime,std::vector<double>v);
     Spremnik *DodajBure(double tezina,std::string ime,double zapremina,double spec);
     Spremnik *DodajVrecu(double tezina,std::string ime,double tezinapraha);
    Spremnik *DodajSpremnik(Spremnik *spremnik,bool a);
    void IzlistajSkladiste();
    void BrisiSpremnik(Spremnik *spremnik);
    Spremnik &DajNajlaksi();
    Spremnik &DajNajtezi();
    int BrojPreteskih(double x)const;
    Skladiste &operator=(const Skladiste &skladiste);
    Skladiste(const Skladiste &skladiste);
    Skladiste(Skladiste &&skladiste);
     Skladiste &operator =(Skladiste &&skladiste);
     void UcitajIzDatoteke(std::string datoteka);
};

    
    Spremnik *Skladiste::DodajSanduk(double tezina,std::string ime,std::vector<double>v){
        Sanduk sanduci(tezina,ime,v);
        s.push_back(sanduci.DajKopiju());
        auto a=s[s.size()-1].get();
        return a;
    }
     Spremnik *Skladiste::DodajBure(double tezina,std::string ime,double zapremina,double spec){
        Bure burad(tezina,ime,zapremina,spec);
        s.push_back(burad.DajKopiju());
        auto a=s[s.size()-1].get();
        return a;
    }
     Spremnik *Skladiste::DodajVrecu(double tezina,std::string ime,double tezinapraha){
        Vreca vrece(tezina,ime,tezinapraha);
        s.push_back(vrece.DajKopiju());
        auto a=s[s.size()-1].get();
        return a;
    }
    Spremnik *Skladiste::DodajSpremnik(Spremnik *spremnik,bool a){
        if(a==true){
            s.push_back(std::shared_ptr<Spremnik>(spremnik));
            return spremnik;
        }
        s.push_back(spremnik->DajKopiju());
        auto x=s[s.size()-1].get();
        return x;
    }
    void Skladiste::IzlistajSkladiste(){
        std::sort(s.begin(),s.end(),[](std::shared_ptr<Spremnik> s1,std::shared_ptr<Spremnik> s2){
            return s1->DajUkupnuTezinu()>s2->DajUkupnuTezinu();
        });
        for(int i=0;i<s.size();i++){
            s[i]->Ispisi();
        }
    }
    void Skladiste::BrisiSpremnik(Spremnik *spremnik){
    for(int i=0;i<s.size();i++){
        if(&*s[i]==&*spremnik){
            s.erase(s.begin()+i);
            break;
        }
    }
       
    }
    Spremnik &Skladiste::DajNajlaksi(){
        if(s.size()==0) throw std::range_error("Skladiste je prazno");
        return **std::min_element(s.begin(),s.end(),Element);
       
    }
    Spremnik &Skladiste::DajNajtezi(){
        if(s.size()==0) throw std::range_error("Skladiste je prazno");
        return **std::max_element(s.begin(),s.end(),Element);
       
    }
    int Skladiste::BrojPreteskih(double x)const{
        int brojac=std::count_if(s.begin(),s.end(),[x](std::shared_ptr<Spremnik>s1){
            return s1->DajUkupnuTezinu()>=x;
        });
        return brojac;
    }
    Skladiste &Skladiste::operator=(const Skladiste &skladiste){
        s.resize(0);
        for(auto x:skladiste.s)s.push_back(x->DajKopiju());
        return *this;
    }
    Skladiste::Skladiste(const Skladiste &skladiste){
         s.resize(0);
        for(auto x:skladiste.s)s.push_back(x->DajKopiju());
    }
    Skladiste::Skladiste(Skladiste &&skladiste){
        s=std::move(skladiste.s);
    }
     Skladiste &Skladiste::operator =(Skladiste &&skladiste){
        s=std::move(skladiste.s);
        return *this;
    }
    void Skladiste::UcitajIzDatoteke(std::string datoteka){
        
        std::ifstream ulaz(datoteka);
        if(!ulaz) throw std::logic_error("Trazena datoteka ne postoji");
        char znak;
        while(ulaz>>znak){
            if(znak!='s' ||znak!='v'|| znak!='b') throw std::logic_error("Datoteka sadrzi besmislene podatke");
            else if(znak=='s'){
                std::string ime;
                std::getline(ulaz,ime);
                int n;
                double tezina;
                ulaz>>tezina;
                if(!ulaz) break;
                ulaz>>n;
                if(!ulaz) break;
                std::vector<double>v ;
                for(int i=0;i<n;i++){
                    double x;
                    ulaz>>x;
                    if(!ulaz) break;
                    v.push_back(x);
                }
                ulaz.ignore(1000,'\n');
                s.push_back(std::make_shared<Sanduk>(tezina,ime,v));
            }
            else if(znak=='v'){
                std::string ime;
                std::getline(ulaz,ime);
                int n;
                double tezina;
                ulaz>>tezina;
                if(!ulaz) break;
                ulaz>>n;
                if(!ulaz) break;
                ulaz.ignore(1000,'\n');
                s.push_back(std::make_shared<Vreca>(tezina,ime,n));
            }
            else if(znak=='b'){
                std::string ime;
                std::getline(ulaz,ime);
                double tezina,spec,zap;
                ulaz>>tezina>>spec>>zap;
                if(!ulaz) break;
                ulaz.ignore(1000,'\n');
                s.push_back(std::make_shared<Bure>(tezina,ime,spec,zap));
            }
        }
        if(!ulaz){
            if(ulaz.eof());
            else if(ulaz.bad()) throw std::logic_error("Problemi pri citanju datoteke");
            else throw std::logic_error("Datoteka sadrzi besmislene podatke");
        }
    }
int main ()
{
   
	return 0;
}
