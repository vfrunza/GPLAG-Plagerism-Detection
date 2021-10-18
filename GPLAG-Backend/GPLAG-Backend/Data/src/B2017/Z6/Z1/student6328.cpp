/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <string>
#include <vector>
class Spremnik{
protected:
    std::string naziv;
    double tezina;
public:
    Spremnik(std::string naziv, double tezina): naziv(naziv),tezina(tezina){}
    virtual void Ispisi() const =0;
    virtual double DajUkupnuTezinu() const = 0;
    std::string DajNaziv()const{ return this->naziv;}
    double DajTezinu() const { return this->tezina;}
};

class Sanduk: public Spremnik{
protected:
    std::string naziv;
    double tezina;
    std::vector<double>tezine;
public:
    Sanduk(std::string naziv, double tezina, std::vector<double>tezine):Spremnik(naziv,tezina),tezine(tezine){}
    double DajUkupnuTezinu() const{ double suma=0; for(int i=0;i<tezine.size();i++) suma+=tezine[i]; return suma+tezina;}
    void Ispisi() const{
        std::cout<<"Vrsta Spremnika: Sanduk"<<std::endl<<"Sadrzaj: "<<this->naziv<<std::endl<<"Tezine predmeta: ";
        for(int i=0;i<tezine.size();i++) std::cout<<tezine[i]<<" ";
        std::cout<<std::endl<<"Vlastita tezina: "<<this->tezina<<std::endl<<"Ukupna tezina: "<<DajUkupnuTezinu()<<std::endl;
    }
    
};

class Bure: public Spremnik{
protected:
    std::string naziv;
    double tezina,spectezina,zapremina;
public:
    Bure(std::string naziv,double tezina, double spectezina, double zapremina):Spremnik(naziv,tezina),spectezina(spectezina),zapremina(zapremina){}
    double DajUkupnuTezinu() const{}
    void Ispisi()const{
        std::cout<<"Vrsta spreminka: Bure"<<std::endl<<"Sadrzaj: "<<this->naziv<<std::endl<<"Vlastita tezina: "<<this->tezina<<std::endl<<"Specificna tezina tecnosti: "<<spectezina<<" (kg/m^3)"<<std::endl<<"Zapremina tecnosti: "<<this->zapremina<<std::endl<<"Ukupna tezina: "<<DajUkupnuTezinu()<<std::endl;
        
    }
};



int main ()
{
	return 0;
}
