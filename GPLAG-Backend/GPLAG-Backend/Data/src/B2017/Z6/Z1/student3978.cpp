/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>

class Skladiste
{
    public:
};

virtual class Spremnik
{
    double tezina;
    std::string naziv;
    int DajTezinu() const {return tezina;}
    virtual int DajUkupnuTezinu() const {return tezina + 
    virtual void Ispisi() const override
    {
        std::cout << "Vrsta spremnika: " << << std::endl << "Sadrzaj: " << << std::endl 
        << "Tezine predmeta: " << << " (kg)" << std::endl
        << "Vlastita tezina: "
        
    }
    
    void IspisiPodatke() const override //apstraktna 
	{
		std::cout << "Student bachelor studija " << DajIme() << " " << DajPrezime() << ", sa brojem indeksa "
		<<DajBrojIndeksa() << "," << std::endl << "ima prosjek " << DajProsjek() <<"." << std::endl;
	}
    
};

class Sanduk : public Spremnik
{
    
    std::vector<double> tezina_materije;
    
    public:
    
    Sanduk(double tezina, std::string naziv, std::vector<double> tezina_materije)
};

class Vreca : public Spremnik
{
   
    double tezina_materije;
    
    public:
    
    Vreca(double tezina, std::string naziv, double tezina_materije)
};

class Bure : public Spremnik
{
    
    double tezina_materije;
    
    public:
    
    Bure(double tezina, std::string naziv, double tezina_materije)
    
    
};

int main ()
{
	return 0;
}
