/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <string>

class Spremnik {
      protected: 
      double tezina_spreminka;
      std::string materije_u_spreminku;
      explicit Spremnik(double tezina, std::string ime) :  tezina_spreminka(tezina), materije_u_spreminku(ime) {}
      public: 
      virtual ~Spremnik() {}
      Spremnik() : tezina_spreminka(0) {}
      virtual double DajTezinu() const = 0; //abstraktna metoda
      virtual double DajUkupnuTezinu() const = 0; 
      virtual void Ispisi() const = 0; 
      virtual std::shared_ptr<Spremnik> DajKopiju() const = 0; 
      //da ova ima kopirajuci i/ili pomjerajuci morale bi joj i kcerke imati sve to i obavezno bi se njen morao pozvati
      //uz dopunu za te nove atribute
};

class Sanduk : public Spremnik { //skontaj hocel ovo biti public, protected ili private, ali ja msm da je public OK
      std::string predmeti_u_sanduku; 
      std::vector<double> tezina_predmeta;
      public: 
      Sanduk(double tezina, std::string popis, std::vector<double> tezine) : Spremnik(tezina, popis), tezina_predmeta(tezine) {}
      //u ovim konst se skoro obavezno poziva onaj osim ako bazna klasa posjeduje konst bez parametara
                  //tada ce on biti pozvan automatski
                  
      double DajUkupnuTezinu() const override; 
      double DajTezinu() const override { return tezina_spreminka; }
      void Ispisi() const override;
      std::shared_ptr<Spremnik> DajKopiju() const override { return std::make_shared<Sanduk>(*this); }
                  
}; 

double Sanduk::DajUkupnuTezinu() const {
      double ukupna_tezina(tezina_spreminka); 
      for(auto &x : tezina_predmeta) 
      ukupna_tezina+=x; 
      return ukupna_tezina; 
}

void Sanduk::Ispisi() const {
      std::cout << "Vrsta spremnika: Sanduk" << std::endl << "Sadrzaj: " << materije_u_spreminku << std::endl; 
      std::cout << "Tezine predmeta: ";
      for(auto &x : tezina_predmeta) 
      std::cout << x << " "; 
      std::cout << "(kg)" << std::endl;
      std::cout << "Vlastita tezina: " << tezina_spreminka << " (kg)" << std::endl; 
      std::cout << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl; 
 }

class Vreca : public Spremnik {
      std::string naziv_pohranjene_materije;
      double tezina_pohranjene_materije;
      public: 
      Vreca(double tezina, std::string naziv, double tezina_pohranjene_materije)
      : Spremnik(tezina, naziv), tezina_pohranjene_materije(tezina_pohranjene_materije) {}
      double DajTezinu() const override { return tezina_spreminka; }
      double DajUkupnuTezinu() const override { return tezina_pohranjene_materije+tezina_spreminka; }
      void Ispisi() const override; 
      std::shared_ptr<Spremnik> DajKopiju() const override { return std::make_shared<Vreca>(*this); }
};

void Vreca::Ispisi() const {
      std::cout << "Vrsta spremnika: Vreca" << std::endl << "Sadrzaj: " << materije_u_spreminku << std::endl; 
      std::cout << "Vlastita tezina: " << tezina_spreminka << " (kg)" << std::endl; 
      std::cout << "Tezina pohranjene materije: " << tezina_pohranjene_materije <<" (kg)" << std::endl;
      std::cout << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl; 
}

class Bure : public Spremnik {
      std::string naziv_tecnosti; 
      double gustina_tecnosti; 
      double zapremina; 
      public:
      Bure(double tezina, std::string naziv, double ro, double V) : Spremnik(tezina, naziv), gustina_tecnosti(ro), 
      zapremina(V) {}
      double DajTezinu() const override { return tezina_spreminka; }
      double DajUkupnuTezinu() const override { return (zapremina*gustina_tecnosti)/1000+tezina_spreminka; } //eventualno podijeliti s nekim powerom desetke jer je ono u l a oni su
      void Ispisi() const override; 
      std::shared_ptr<Spremnik> DajKopiju() const override { return std::make_shared<Bure>(*this); }
      
};

void Bure::Ispisi() const {
      std::cout << "Vrsta spremnika: Bure" << std::endl << "Sadrzaj: " << materije_u_spreminku << std::endl; 
      std::cout << "Vlastita tezina: " << tezina_spreminka <<  " (kg)" << std::endl; 
      std::cout << "Specificna tezina tecnosti: " << gustina_tecnosti << " (kg/m^3)" << std::endl; 
      std::cout << "Zapremina tecnosti: " << zapremina << " (l)" << std::endl; 
      std::cout << "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl; 
      
}

class Skladiste {
      std::vector<std::shared_ptr<Spremnik>> inventory; 
      public: 
      Skladiste() {}
      Skladiste(const Skladiste &skladiste); 
      Skladiste(Skladiste &&skladiste);
      Skladiste &operator =(const Skladiste &skladiste); 
      Skladiste &operator =(Skladiste &&skladiste); 
      ~Skladiste() {}
      Spremnik* DodajSanduk(double tezina, std::string naziv, std::vector<double> tezine) { return DodajSpremnik(new Sanduk(tezina, naziv, tezine), true); }; //ja bih njih oznacila kao staticke 
      Spremnik* DodajBure(double tezina, std::string naziv, double ro, double v) { return DodajSpremnik(new Bure(tezina, naziv, ro, v), true); }
      Spremnik* DodajVrecu(double tezina, std::string naziv, double tezina_pohranjene_materije) { return DodajSpremnik(new Vreca(tezina, naziv, tezina_pohranjene_materije), true); }
      Spremnik* DodajSpremnik(Spremnik* spremink, bool kontrolna); 
      //EVENTUALNO DA SVUGDJE DODAS VIRTUALNI DESTRUKTOR MOZDA 
      void BrisiSpremnik(Spremnik *spremnik); 
      Spremnik &DajNajlaksi() const = delete;  //ovo vjerovatno nije ovako
      Spremnik &DajNajtezi() const = delete; 
      Spremnik &DajNajtezi(); 
      Spremnik &DajNajlaksi();
      int BrojPreteskih(int granica) const { return std::count_if(inventory.begin(), inventory.end(), [granica](std::shared_ptr<Spremnik> s) { return (*s).DajUkupnuTezinu()>granica; }); } 
      void IzlistajSkladiste() const; 
};

Skladiste::Skladiste(const Skladiste &skladiste) {
         try {
            for(int i=0; i<skladiste.inventory.size(); i++)
            inventory.push_back(skladiste.inventory[i]->DajKopiju());
      }
      catch(...) {
            throw;
      }
      
}

Skladiste::Skladiste(Skladiste &&skladiste) : inventory(skladiste.inventory) {
      for(int i=0; i<skladiste.inventory.size(); i++)
      skladiste.inventory[i]=nullptr;
}

Skladiste & Skladiste::operator =(const Skladiste &skladiste) { //*************VALJDA
      inventory=skladiste.inventory; 
      return *this; 
}

Skladiste & Skladiste::operator =(Skladiste &&skladiste) { //****************VALJDA
      inventory=skladiste.inventory;  
      return *this;
}

Spremnik* Skladiste::DodajSpremnik(Spremnik *spremink, bool kontrolna) {

      auto pomocni=std::shared_ptr<Spremnik>(spremink->DajKopiju()); //daj Boze da ovo ista radi
   if(kontrolna) {
         delete spremink; //valjda
         inventory.emplace_back(pomocni); 
         return pomocni.get(); //OVO FKT NIJE RAZMISLI MALO
   } 
   else {
      inventory.emplace_back(pomocni); 
      return spremink; 
   }
}

Spremnik &Skladiste::DajNajtezi() {
      if(inventory.size()==0) throw std::range_error("Skladiste je prazno"); 
      auto rezultat=std::max_element(inventory.begin() , inventory.end(),
       [] (std::shared_ptr<Spremnik> s1, std::shared_ptr<Spremnik> s2) { return (*s1).DajTezinu()<(*s2).DajTezinu(); });
       return **rezultat; 
}
Spremnik &Skladiste::DajNajlaksi() {
      if(inventory.size()==0) throw std::range_error("Skladiste je prazno"); 
      auto rezultat=std::min_element(inventory.begin(), inventory.end(), 
      [] (std::shared_ptr<Spremnik> s1, std::shared_ptr<Spremnik> s2) {return (*s1).DajTezinu()<(*s2).DajTezinu(); });
      return **rezultat; 
}

void Skladiste::IzlistajSkladiste() const {
      
  //std::sort(inventory.begin(), inventory.end(), [] (std::shared_ptr<Spremnik> s1, std::shared_ptr<Spremnik> s2)
    //  { return (*s1).DajUkupnuTezinu()>=(*s2).DajUkupnuTezinu(); } );
      std::for_each(inventory.begin(), inventory.end(), [](std::shared_ptr<Spremnik> s)
      { (*s).Ispisi(); });
}

void Skladiste::BrisiSpremnik(Spremnik * spremink) {
      if(inventory.size()==0) throw std::range_error("Skladiste je prazno"); 
      auto rezultat=std::find_if(inventory.begin(), inventory.end(), [spremink](std::shared_ptr<Spremnik> s) { return &(*s)==spremink; }); 
      if(rezultat!=inventory.end()) {
            *rezultat=nullptr; 
      }
      for(int i=0; i<inventory.size(); i++)
      if(inventory[i]==nullptr) { inventory.erase(inventory.begin()+i); }

}
int main ()
{
	return 0;
}
