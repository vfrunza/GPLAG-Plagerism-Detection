#include <iostream>
#include <vector>
#include <string>
#include <memory>



class Spremnik {
	
	double tezina;
	std::string naziv;
    	
	public:
	virtual ~Spremnik() { }
	Spremnik (double tezina1, std::string ime)  {
		
		Spremnik::tezina = tezina1;
		Spremnik::naziv = ime;
		
		
		
	}
	
	virtual	void Ispisi () const = 0;
	//virtual double DajTezinu () {return tezina;};
	//virtual double DajUkupnuTezinu () const = 0;
	virtual Spremnik* DajKopiju() const = 0;
	
};


class Sanduk : public Spremnik {


double tezina_sanduka;
std::string naziv_sanduka;
std::vector<double> tezina_predmeta;

public:

Sanduk (double tezina1, std::string ime, std::vector<double> v) : Spremnik(tezina1,ime) , tezina_predmeta(v) {}

	

		
Sanduk &DodajSanduk (double tezina1, std::string ime, std::vector<double> v) {
	
	
	tezina_sanduka = tezina1;
	naziv_sanduka = ime;
	tezina_predmeta = v;
	
	return *this;
}

void Ispisi() const override {
	
	double suma=0;
			
	std::cout<<"Vrsta spremnika: Sanduk"<<std::endl;
	std::cout<<"Sadrzaj: "<<naziv_sanduka;
	std::cout<<"Tezine predmeta: ";
	for(int i=0;i<tezina_predmeta.size();i++) {
		std::cout<<tezina_predmeta[i];
	}
	std::cout<<"(kg)"<<std::endl;
	std::cout<<"Vlastita tezina: "<<tezina_sanduka<<"(kg)"<<std::endl;
	std::cout<<"Ukupna tezina: ";
	for(int i=0;i<tezina_predmeta.size();i++) {

		suma+=tezina_predmeta[i];
	}
	std::cout<<(suma+ tezina_sanduka)<<"(kg)";
	
}

Spremnik *DajKopiju() const override {return new Sanduk(*this);} 



	
};


class Vreca : public Spremnik {
	
double tezina_vrece;
std::string naziv_materije;
double tezina_materije;

public:

	
Vreca ( double tezina1, std::string ime , double tezina2) : Spremnik(tezina1,ime), tezina_materije(tezina2) {}

Vreca &DodajVrecu ( double tezina1, std::string ime , double tezina2) {
	
	
	tezina_vrece = tezina1;
	naziv_materije = ime;
	tezina_materije = tezina2;
	
	return *this;
}

void Ispisi() const override {
	
			
	std::cout<<"Vrsta spremnika: Vreca"<<std::endl;
	std::cout<<"Sadrzaj: "<<naziv_materije<<std::endl;
	std::cout<<"Vlastita tezina: "<<tezina_vrece<<"(kg)"<<std::endl;
	std::cout<<"Tezina pohranjene materije: "<<tezina_materije<<"(kg)"<<std::endl;
	std::cout<<"Ukupna tezina: "<<(tezina_materije+tezina_vrece)<<"(kg)";
	
	
}




Spremnik *DajKopiju() const override {return new Vreca(*this);} 

	
};

class Bure : public Spremnik {

double tezina_bureta;
std::string naziv_tecnosti;
double gustina_tecnosti;
double zapremina_tecnosti;

public: 


Bure ( double tezina , std::string ime, double gustina, double zapremina ) : Spremnik(tezina,ime), gustina_tecnosti(gustina) , zapremina_tecnosti(zapremina) {}

Bure &DodajBure( double tezina , std::string ime, double gustina, double zapremina ){
	
	tezina_bureta = tezina;
	naziv_tecnosti = ime;
	gustina_tecnosti = gustina;
	zapremina_tecnosti = zapremina;
	
	return *this;
}
void Ispisi() const override {
	
			
	std::cout<<"Vrsta spremnika: Bure"<<std::endl;
	std::cout<<"Sadrzaj: "<<naziv_tecnosti<<std::endl;
	std::cout<<"Vlastita tezina: "<<tezina_bureta<<"(kg)"<<std::endl;
	std::cout<<"Specificna tezina tecnosti: "<<gustina_tecnosti<<" (kg/m^3)"<<std::endl;
	std::cout<<"Zapremina tecnosti: "<<zapremina_tecnosti<<" (kg)"<<std::endl;
	//std::cout<<"Ukupna tezina: "<<(tezina_materije+tezina_vrece)<<" (kg)";
	
	
}






Spremnik *DajKopiju() const override {return new Bure(*this);} 
	
};






class Skladiste {

std::vector<std::shared_ptr<Spremnik>> vektor;

public: 

Skladiste (const Skladiste &sk) {
	
	for(int i=0;i<sk.vektor.size();i++) {
		
		vektor.push_back(sk.vektor.at(i)->DajKopiju());
	}
	
}

 Skladiste(Skladiste &&sk)
        {
            vektor=sk.vektor;
            sk.vektor.clear();
        }
        
          
        Skladiste &operator=(const Skladiste &sk){
            
            if(&sk!=this) {
                
                
                for(int i = 0;i<vektor.size();i++) delete vektor.at(i);
                vektor.resize(sk.vektor.size());
                
                for(int i=0;i<sk.vektor.size();i++)
                {
                    vektor.at(i)=sk.vektor.at(i)->DajKopiju();
                }
            }
                    
               return *this; 
            }
            
            
                 Skladiste &operator=(Skladiste &&sk)
        {
            if(&sk==this) return *this;
            for(auto p : vektor) delete p;
            vektor=sk.vektor;
            sk.vektor.clear();
            return *this;
        }



	
};




int main ()
{
	return 0;
}
