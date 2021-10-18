/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;

class Spremnik  // apstraktna nadklasa
{

  double tezina;

protected :
  std::string naziv_robe;


public:

  virtual ~Spremnik() {}

  Spremnik(double tezina, const std::string &naziv_robe) : tezina(tezina), naziv_robe(naziv_robe) {}

  double DajTezinu() const {
    return tezina;
  }
  virtual double DajUkupnuTezinu() const = 0;
  virtual void Ispisi() const = 0;

  virtual std::shared_ptr<Spremnik> DajKopiju() const = 0;

};

class Sanduk : public Spremnik //naslijedjene klase...
{


  std::vector<double> tezine_predmeta;

public:

  Sanduk(double tezina_sanduka, const std::string &naziv_predmeta, const std::vector<double> &tezine_predmeta) : Spremnik(tezina_sanduka,naziv_predmeta), tezine_predmeta(tezine_predmeta) {}

  double DajUkupnuTezinu() const override {
    double ukupna_tezina_sanduka(DajTezinu());
    for (int i=0; i<tezine_predmeta.size(); i++) ukupna_tezina_sanduka+=tezine_predmeta.at(i);
    return ukupna_tezina_sanduka;
  }
  void Ispisi() const override {
    cout<<"Vrsta spremnika: Sanduk"<<endl<<"Sadrzaj: "<<naziv_robe<<endl<<"Tezine predmeta: ";
    for(int i=0; i<tezine_predmeta.size(); i++) cout<<tezine_predmeta.at(i)<<" ";
    cout<<"(kg)"<<endl<<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<endl<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<endl;

  }

  virtual std::shared_ptr<Spremnik> DajKopiju() const override {
    return std::make_shared<Sanduk> (*this);
  }


};

class Vreca : public Spremnik
{


  double tezina_predmeta;

public:

  Vreca(double tezina_vrece, const std::string &naziv_predmeta, double tezina_predmeta) : Spremnik(tezina_vrece,naziv_predmeta), tezina_predmeta(tezina_predmeta) {}

  double DajUkupnuTezinu() const override {
    double ukupna_tezina_vrece(DajTezinu());
    ukupna_tezina_vrece+=tezina_predmeta;
    return ukupna_tezina_vrece;
  }
  void Ispisi() const override {
    cout<<"Vrsta spremnika: Vreca"<<endl<<"Sadrzaj: "<<naziv_robe<<endl;

    cout<<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<endl<<"Tezina pohranjene materije: "<<tezina_predmeta<<" (kg)"<<endl<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<endl;

  }

  virtual std::shared_ptr<Spremnik> DajKopiju() const override {
    return std::make_shared<Vreca> (*this);
  }


};

class Bure : public Spremnik
{

  double gustina_tecnosti;
  double zapremina_tecnosti;

public:

  Bure(double tezina_bureta, const std::string &naziv_tecnosti, double gustina_tecnosti, double zapremina_tecnosti) : Spremnik(tezina_bureta, naziv_tecnosti), gustina_tecnosti(gustina_tecnosti), zapremina_tecnosti(zapremina_tecnosti) {}

  double DajUkupnuTezinu() const override {
    double ukupna_tezina_bureta(DajTezinu());
    ukupna_tezina_bureta+=(gustina_tecnosti*zapremina_tecnosti*0.001);
    return ukupna_tezina_bureta;
  }
  void Ispisi() const override {
    cout<<"Vrsta spremnika: Bure"<<endl<<"Sadrzaj: "<<naziv_robe<<endl;

    cout<<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<endl<<"Specificna tezina tecnosti: "<<gustina_tecnosti<<" (kg/m^3)"<<endl<<"Zapremina tecnosti: "<<zapremina_tecnosti<<" (l)"<<endl;
    cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<endl;

  }

  virtual std::shared_ptr<Spremnik> DajKopiju() const override {
    return std::make_shared<Bure> (*this);
  }

};

class Skladiste
{

  std::vector<std::shared_ptr<Spremnik>>skladiste; //!!!!!

public:

  virtual ~Skladiste() {
    for (int i=0;i<skladiste.size();i++) skladiste.at(i)=nullptr;
    skladiste.resize(0);
  }

  Skladiste() {}

  Skladiste(const Skladiste &neko_skladiste) { // kopirajuci konstruktor

    for(int i=0; i<neko_skladiste.skladiste.size(); i++)
      skladiste.push_back( (neko_skladiste.skladiste.at(i))->DajKopiju() );

  }

  Skladiste(Skladiste &&neko_skladiste) { // pomjerajuci konstruktor ??? da li ce ovo raditi?

    for(int i=0; i<neko_skladiste.skladiste.size(); i++)
      skladiste=std::move(neko_skladiste.skladiste);

  }

  Skladiste &operator =(const Skladiste &neko_skladiste) { // kopirajuci operator dodjele

    for(int i=0; i<skladiste.size(); i++) skladiste.at(i)=nullptr;
    skladiste.resize(0);

    for(int i=0; i<neko_skladiste.skladiste.size(); i++)
      skladiste.push_back( (neko_skladiste.skladiste.at(i))->DajKopiju() );

    return *this;

  }

  Skladiste &operator =(Skladiste &&neko_skladiste) { // pomjerajuci operator dodjele

    for(int i=0; i<skladiste.size(); i++) skladiste.at(i)=nullptr;
    skladiste.resize(0);


    for(int i=0; i<neko_skladiste.skladiste.size(); i++) {
      skladiste.push_back(neko_skladiste.skladiste.at(i));
      neko_skladiste.skladiste.at(i)=nullptr;
    }
    return *this;

  }

  Spremnik *DodajSanduk(double tezina_sanduka, const std::string &naziv_predmeta, const std::vector<double> &tezine_predmeta) {

    std::shared_ptr<Spremnik> pok(std::make_shared<Sanduk> (Sanduk(tezina_sanduka,naziv_predmeta,tezine_predmeta)));
    skladiste.push_back(pok);

    return pok.get();


  } //glupi pok je povratna vrijednost
  Spremnik *DodajVrecu(double tezina_vrece, const std::string &naziv_predmeta, double tezina_predmeta) {

    std::shared_ptr<Spremnik> pok(std::make_shared<Vreca> (Vreca(tezina_vrece,naziv_predmeta,tezina_predmeta)));
    skladiste.push_back(pok);

    return pok.get();

  }
  Spremnik *DodajBure(double tezina_bureta, const std::string &naziv_tecnosti, double gustina_tecnosti, double zapremina_tecnosti) {

    std::shared_ptr<Spremnik> pok(std::make_shared<Bure> (Bure(tezina_bureta,naziv_tecnosti,gustina_tecnosti,zapremina_tecnosti)));
    skladiste.push_back(pok);

    return pok.get();

  }

  Spremnik *DodajSpremnik(Spremnik *pok_na_spremnik, bool vlasnistvo_klase) {

    if(vlasnistvo_klase) {

      std::shared_ptr<Spremnik> pok(pok_na_spremnik);
      skladiste.push_back(pok);

    }

    else {

      std::shared_ptr<Spremnik> pok(pok_na_spremnik->DajKopiju());
      skladiste.push_back(pok);

    }

    return &(*(skladiste.at(skladiste.size()-1)));


  }



  void BrisiSpremnik(Spremnik *spremnik_za_brisanje) {

    for(int i=0; i<skladiste.size(); i++) {
      if(&(*skladiste.at(i))==&(*spremnik_za_brisanje)) {
        skladiste.at(i)=nullptr;
        for(int j=i; j<skladiste.size()-1; j++)
          skladiste.at(j)=skladiste.at(j+1);
        skladiste.at(skladiste.size()-1)=nullptr;
        skladiste.resize(skladiste.size()-1);
      }
    }

  }

  Spremnik &DajNajlaksi() {

    if(skladiste.size()==0) throw std::range_error ("Skladiste je prazno");
    return **std::min_element(skladiste.begin(),skladiste.end(),[](std::shared_ptr<Spremnik> pok1, std::shared_ptr<Spremnik> pok2) {
      return pok1->DajTezinu()<pok2->DajTezinu();
    });

  }

  Spremnik &DajNajtezi() {

    if(skladiste.size()==0) throw std::range_error ("Skladiste je prazno");
    return **std::max_element(skladiste.begin(),skladiste.end(),[](std::shared_ptr<Spremnik> pok1, std::shared_ptr<Spremnik> pok2) {
      return pok1->DajTezinu()<pok2->DajTezinu();
    });

  }

  int BrojPreteskih(int max_tezina) const {

    return std::count_if(skladiste.begin(),skladiste.end(),[max_tezina](std::shared_ptr<Spremnik> pok) {
      return pok->DajUkupnuTezinu()>max_tezina;
    });
  }

  void IzlistajSkladiste() const {

    Skladiste pom_skladiste(*this);

    std::stable_sort(pom_skladiste.skladiste.begin(),pom_skladiste.skladiste.end(),[] (std::shared_ptr<Spremnik> pok1, std::shared_ptr<Spremnik> pok2) {
      return pok1->DajUkupnuTezinu()>pok2->DajUkupnuTezinu();
    });

    for(int i=0; i<pom_skladiste.skladiste.size(); i++)
      pom_skladiste.skladiste.at(i)->Ispisi();


  }


  void UcitajIzDatoteke(std::string ime_datoteke) {

    for(int i=0; i<skladiste.size(); i++)
      skladiste.at(i)=nullptr;

    skladiste.resize(0);

    std::ifstream ulazni_tok(ime_datoteke);
    if(!ulazni_tok) {
      ulazni_tok.close();
      throw std::logic_error("Trazena datoteka ne postoji");
    }


    char znak;
    char razmak;
    std::string naziv;


    while((znak=ulazni_tok.get())!=EOF) { //EOF je i u slucaju ostecenja, ne nuzno i kraja datoteke
      if(!(znak=='S' || znak=='V' || znak=='B')) break;
      if((razmak=ulazni_tok.get())!=' ') break;
      char novi_red;

      if(znak=='S') {
        
        std::getline(ulazni_tok,naziv);
        double tezina_sanduka;
        int broj_predmeta;
        
        ulazni_tok>>tezina_sanduka;
        
        if(!ulazni_tok || (razmak=ulazni_tok.get())!=' ') { ulazni_tok.setstate(std::ios_base::failbit); break;}
        ulazni_tok>>broj_predmeta;
    
        if(!ulazni_tok || (razmak=ulazni_tok.get())!=' ') { ulazni_tok.setstate(std::ios_base::failbit); break;}
      
        
        double tezina_predmeta;
        std::vector<double> tezine;
        for(int i=0; i<broj_predmeta; i++) {
          ulazni_tok>>tezina_predmeta;
          if(!ulazni_tok) break;
          tezine.push_back(tezina_predmeta);
        }
        if(!ulazni_tok) {
          tezine.resize(0);
          break;
        } 
        else if((novi_red=ulazni_tok.get())==EOF) {
          DodajSanduk(tezina_sanduka,naziv,tezine);
          break;
        } 
        else if(novi_red=='\n') {
          DodajSanduk(tezina_sanduka,naziv,tezine);
        } 
        else if(novi_red!='\n') ulazni_tok.setstate(std::ios_base::failbit);
      }

      else if(znak=='V') { // tezina_vrece tezina_materije\n ili EOF
        std::getline(ulazni_tok,naziv);
        double tezina_vrece;
        double tezina_materije;
        ulazni_tok>>tezina_vrece;
        if(!ulazni_tok || (razmak=ulazni_tok.get())!=' ') break;
        ulazni_tok>>tezina_materije;
        if(!ulazni_tok) break;

        else if((novi_red=ulazni_tok.get())==EOF) {
          DodajVrecu(tezina_vrece,naziv,tezina_materije);
          break;
        } else if(novi_red=='\n') {
          DodajVrecu(tezina_vrece,naziv,tezina_materije);
        } else if(novi_red!='\n') ulazni_tok.setstate(std::ios_base::failbit);


      }

      else if(znak=='B') { //tezina bureta gustina zapremina\n ili EOF

        std::getline(ulazni_tok,naziv);
        double tezina_bureta;
        double gustina;
        double zapremina;
        ulazni_tok>>tezina_bureta;
        if(!ulazni_tok || (razmak=ulazni_tok.get())!=' ') break;
        ulazni_tok>>gustina;
        if(!ulazni_tok) break;
        ulazni_tok>>zapremina;
        if(!ulazni_tok) break;
        else if( (novi_red=ulazni_tok.get())==EOF) {
          DodajBure(tezina_bureta,naziv,gustina,zapremina);
          break;
        } else if(novi_red=='\n') {
          DodajBure(tezina_bureta,naziv,gustina,zapremina);
        } else if(novi_red!='\n') ulazni_tok.setstate(std::ios_base::failbit);

      }


      if(!ulazni_tok) break;
    }

    if(ulazni_tok.bad()) {
      ulazni_tok.close();
      throw std::logic_error("Problemi pri citanju datoteke");
    }
    if(!ulazni_tok && !ulazni_tok.eof()) {
      ulazni_tok.close();
      throw std::logic_error("Datoteka sadrzi besmislene podatke");
    }

    ulazni_tok.close();

  }

};


int main ()
{
/*Razvijene klase demonstrirajte u testnom programu koji iščitava podatke iz tekstualne datoteke sa imenom “ROBA.TXT”, 
a nakon toga ispisuje spisak svega što se nalazi u skladištu, sortiran u opadajući poredak po ukupnoj težini. 
U testnom programu obavezno predvidite i hvatanje eventualno bačenih izuzetaka koji se mogu pojaviti. 
*/ 
 
try{
  
Skladiste s;
s.UcitajIzDatoteke("ROBA.TXT");

s.IzlistajSkladiste();

}

catch(std::logic_error greska){
  cout<<greska.what()<<endl;
}
catch(std::range_error izuzetak){
  cout<<izuzetak.what()<<endl;
}

  return 0;
}
