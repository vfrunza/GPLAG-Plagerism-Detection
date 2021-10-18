#include <string>
#include <iostream>
#include <stdexcept>

class Obrok {
    std::string naziv;
    double cijena;
    std::string narucioc;
public:
    Obrok(std::string naziv, double cijena, std::string narucioc) : naziv(naziv), cijena(cijena), narucioc(narucioc) {}
    std::string DajNazivObroka() const { return naziv; }
    double DajCijenuObroka() const { return cijena; }
    std::string DajNarucioca() const { return narucioc; }
    void Ispisi() const {
        std::cout << narucioc << " je narucio " << naziv << " i treba platiti "<< cijena << " KM.\n";
    }
    Obrok *DajKopiju() const { return new Obrok(*this); } 
};

class Narudzbe {
    int broj_narudzbi, kapacitet;
    Obrok **obroci;
public:
    Narudzbe() : broj_narudzbi(0), kapacitet(20),obroci(new Obrok*[kapacitet]) {}
    ~Narudzbe() { 
    	for(int i=0;i<broj_narudzbi-1;i++) delete obroci[i];
    	delete[] obroci;
    }
    Narudzbe(const Narudzbe &n) : broj_narudzbi(n.broj_narudzbi),kapacitet(n.kapacitet), obroci(new Obrok*[kapacitet])
    {
        //std::copy(n.obroci, n.obroci + broj_narudzbi, obroci);
        for(int i=0;i<broj_narudzbi;i++)
        {
        	obroci[i] = n.obroci[i]->DajKopiju();
        }
    }
    Narudzbe(Narudzbe &&n) : broj_narudzbi(n.broj_narudzbi),kapacitet(n.kapacitet), obroci(new Obrok*[kapacitet])
    {
    	n.obroci = nullptr;
    	n.kapacitet = 0;
    }
    
    Narudzbe &operator =(const Narudzbe &n) 
    {
    	broj_narudzbi=n.broj_narudzbi;
    	kapacitet=n.kapacitet;
    	
    	Obrok **novi_prostor = new Obrok*[n.kapacitet];
    	for(int i=0;i<n.kapacitet;i++)
    	{
    		novi_prostor[i]=n.obroci[i];
    	}
    	
    	for(int i=0;i<n.kapacitet;i++)
    	{
    		delete [] obroci[i];
    	}
    	
    	delete obroci;
    	
    	obroci=novi_prostor;
    	return *this;
    	
    }
    
    Narudzbe &operator=(Narudzbe &&n)
    {
    	broj_narudzbi=n.broj_narudzbi;
    	std::swap(obroci,n.obroci);
    	std::swap(kapacitet,n.kapacitet);
    	return *this;
    	
    }
    
    void NaruciObrok(std::string naziv, double cijena, std::string narucioc)
    {
        if(broj_narudzbi > kapacitet) 
        {
        	
        }
		obroci[broj_narudzbi++] = new Obrok(naziv, cijena, narucioc);
    }	
    	
    const Obrok &operator[] (int redni_broj) const
    {
        return *obroci[redni_broj];
    }
};
int main() {
    Narudzbe etf_fast_food;
    for(int i=0;i<25;i++)
    etf_fast_food.NaruciObrok("burek", i, "Brus Li");
    
    for(int i=0;i<25;i++)
    etf_fast_food[i].Ispisi();
return 0;
}
