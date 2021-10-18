/B 2016/2017, Zadaća 4, Zadatak 4
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <list>
#include <vector>
#include <memory>

using namespace std;

class Datum{
    int dan, mjesec, godina;

public:
    
    Datum(){};
    
    Datum(int d, int m, int g)
    {
        //if(d>31 || d<1 || m>12 || m<1 || g<0)
           // throw domain_error("Neispravan datum");
        dan=d; mjesec=m; godina=g;
    }
    
    void Postavi(int d, int m, int g)
    {
        //if(d>31 || d<1 || m>12 || m<1 || g<0)
           // throw domain_error("Neispravan datum");
        dan=d; mjesec=m; godina=g;
    }
    
    int DajDan() const {return dan;}
    int DajMjesec() const {return mjesec;}
    int DajGodinu() const {return godina;}
    void Ispisi() const {cout<<dan<<"/"<<mjesec<<"/"<<godina;}
};


    class Kupac{
    string ime_i_prezime;
    Datum datum_rodjenja;
    bool JeLiIspravnoIme(string s)
    {
        for(int i=0; i<s.size(); i++)
         {
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9') || s[i]=='-' || s[i]==' ' || s[i]=='\'')
                continue;
            else 
                return false;
         }
        return true;
    }
    
    public:

    Kupac(){}
    
    Kupac(const string &ime, const Datum &dat)
    {
        if(dat.DajDan()>31 || dat.DajDan()<1 || dat.DajMjesec()>12 || dat.DajMjesec()<1 || dat.DajGodinu()<0)
           throw domain_error("Neispravan datum");
           
        if(!JeLiIspravnoIme(ime))
            throw domain_error("Neispravno ime i prezime");
            
        ime_i_prezime=ime; datum_rodjenja.Postavi(dat.DajDan(), dat.DajMjesec(), dat.DajGodinu());
    }
    
    void Postavi(const string &ime, const Datum &dat)
    {
        if(dat.DajDan()>31 || dat.DajDan()<1 || dat.DajMjesec()>12 || dat.DajMjesec()<1 || dat.DajGodinu()<0)
           throw domain_error("Neispravan datum");
           
        if(!JeLiIspravnoIme(ime))
            throw domain_error("Neispravno ime i prezime");
            
        ime_i_prezime=ime;  datum_rodjenja.Postavi(dat.DajDan(), dat.DajMjesec(), dat.DajGodinu());
       
    }
    
    string DajIme() const {return ime_i_prezime;}
    Datum DajDatumRodjenja() const {return datum_rodjenja;}
    void Ispisi() const {cout<<ime_i_prezime<<" ("; datum_rodjenja.Ispisi(); cout<<")";}
    
};

bool ZavrsavaNa(int br)
    {
        br=br%10;
        if(br==2 || br==3 || br==4)
            return false; //ZAVRSAVA NA E
        return true; //ZAVRSAVA NA A
    }
    
class Stan{
    string adresa;
    int sprat, broj_soba;
    bool namjesten=false;
    double kvadratura;
    
    
    public:
    
    Stan(){}
    
    Stan(const string &adr, int s, int sobe, bool nam ,double kvadrati)
    {
        if(s<0 || sobe<0 || kvadrati<0)
            throw domain_error("Neispravan unos podataka");
            
        adresa=adr; sprat=s; broj_soba=sobe; namjesten=nam; kvadratura=kvadrati;
    }
    
    void Postavi(const string &adr, int s, int sobe, bool nam ,double kvadrati)
    {
        if(s<0 || sobe<0 || kvadrati<0)
            throw domain_error("Neispravan unos podataka");
            
        adresa=adr; sprat=s; broj_soba=sobe; namjesten=nam; kvadratura=kvadrati;
    }
    
    string DajAdresu() const {return adresa;}
    int DajSprat() const {return sprat;}
    int DajBrojSoba() const {return broj_soba;}
    bool DajNamjesten() const {return namjesten;}
    double DajKvadraturu() const {return kvadratura;}
    void Ispisi() const
    {
        cout<<"Stan se nalazi na adresi "<<adresa<<" na "<<sprat<<". spratu i ima ";
        cout<<broj_soba; int sobe=broj_soba;
        if(sobe%10==1)
            cout<<". sobu."; 
        else if(ZavrsavaNa(sobe)) 
            cout<<" soba."; 
        else 
            cout<<" sobe.";
        cout<<" Kvadratura stana je "<<kvadratura<<" (m^2) i stan ";
        if(namjesten) cout<<"je ";
        else cout<<"nije ";
        cout<<"namjesten.";
    }

};

class Prodaja{
  string ime_agenta_prodaje;
  double cijena_stana;
  Datum datum_prodaje;
  Kupac kupac_stana;
  Stan kupljeni_stan;
  
  public:
  
  Prodaja(const string &ime, double cijena, const Datum &datum, const Kupac &kupac,const Stan &stan)
  {
      ime_agenta_prodaje=ime;
      cijena_stana=cijena;
      datum_prodaje.Postavi(datum.DajDan(), datum.DajMjesec(), datum.DajGodinu());
      kupac_stana.Postavi(kupac.DajIme(), kupac.DajDatumRodjenja());
      kupljeni_stan.Postavi(stan.DajAdresu(), stan.DajSprat(), stan.DajBrojSoba(), stan.DajNamjesten(), stan.DajKvadraturu());
  }
  
  void Postavi(const string &ime, double cijena, const Datum &datum, const Kupac &kupac,const Stan &stan)
  {
      ime_agenta_prodaje=ime;
      cijena_stana=cijena;
      datum_prodaje.Postavi(datum.DajDan(), datum.DajMjesec(), datum.DajGodinu());
      kupac_stana.Postavi(kupac.DajIme(), kupac.DajDatumRodjenja());
      kupljeni_stan.Postavi(stan.DajAdresu(), stan.DajSprat(), stan.DajBrojSoba(), stan.DajNamjesten(), stan.DajKvadraturu());
  }
  
  void PomjeriDanUnaprijed();
  void PomjeriDanUnazad();
  
  void PromijeniKupca(const Kupac &novi_kupac) {kupac_stana.Postavi(novi_kupac.DajIme(), novi_kupac.DajDatumRodjenja());}
  void PromijeniStan(const Stan &novi_stan) { kupljeni_stan.Postavi(novi_stan.DajAdresu(), novi_stan.DajSprat(), novi_stan.DajBrojSoba(), novi_stan.DajNamjesten(), novi_stan.DajKvadraturu()); }
  void PromijeniDatumKupovine(const Datum &novi_datum) { datum_prodaje.Postavi(novi_datum.DajDan(), novi_datum.DajMjesec(), novi_datum.DajGodinu()); }
  void PromijeniCijenuProdaje(const double &nova_cijena) {cijena_stana=nova_cijena;}
  
  string DajImeAgenta() const {return ime_agenta_prodaje;}
  string DajImeKupca() const {return kupac_stana.DajIme();}
  Datum DajDatumProdaje() const {return datum_prodaje;}
  double DajCijenuStana() const {return cijena_stana;}
  Datum DajDatumRodjenjaKupca() const {return kupac_stana.DajDatumRodjenja();}
  Kupac DajKupca() const {return kupac_stana;}
  Stan DajStan() const {return kupljeni_stan;}
  
  friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
  friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2); 
  
  void Ispisi() const
  {
      cout<<left<<setw(32)<<"Ime agenta: "; cout<<ime_agenta_prodaje<<endl;
      cout<<setw(32)<<"Ime kupca: "; cout<<kupac_stana.DajIme(); cout<<" ("; kupac_stana.DajDatumRodjenja().Ispisi(); cout<<")"<<endl;
      cout<<setw(32)<<"Zakazani datum prodaje: "; datum_prodaje.Ispisi(); cout<<endl;
      cout<<setw(32)<<"Cijena stana: "<<cijena_stana<<endl;
      cout<<"Informacije o stanu: "<<endl; kupljeni_stan.Ispisi(); //cout<<endl;
  }
};

void Prodaja::PomjeriDanUnaprijed()
{
    if(datum_prodaje.DajMjesec()==1 || datum_prodaje.DajMjesec()==3 || datum_prodaje.DajMjesec()==5 || datum_prodaje.DajMjesec()==7 || datum_prodaje.DajMjesec()==8 || datum_prodaje.DajMjesec()==10 || datum_prodaje.DajMjesec()==12)
    {
        if(datum_prodaje.DajDan()==31)
        {
            datum_prodaje.Postavi(1, datum_prodaje.DajMjesec(), datum_prodaje.DajGodinu());
            if(datum_prodaje.DajMjesec()==12)
                datum_prodaje.Postavi(1, 1, datum_prodaje.DajGodinu()+1);
            else
                datum_prodaje.Postavi(1,datum_prodaje.DajMjesec()+1, datum_prodaje.DajGodinu());
        }
        else
            datum_prodaje.Postavi(datum_prodaje.DajDan()+1, datum_prodaje.DajMjesec(), datum_prodaje.DajGodinu());
    }
    
    else if(datum_prodaje.DajMjesec()==4 || datum_prodaje.DajMjesec()==6 || datum_prodaje.DajMjesec()==9 || datum_prodaje.DajMjesec()==11)
    {
        if(datum_prodaje.DajDan()==30)
            datum_prodaje.Postavi(1, datum_prodaje.DajMjesec()+1, datum_prodaje.DajGodinu());
        else
            datum_prodaje.Postavi(datum_prodaje.DajDan()+1, datum_prodaje.DajMjesec(), datum_prodaje.DajGodinu());
    }
    
    else if(datum_prodaje.DajMjesec()==2)
    {
        if((datum_prodaje.DajGodinu()%4==0 && datum_prodaje.DajGodinu()%100!=0) || datum_prodaje.DajGodinu()%400==0)
        {   
            if(datum_prodaje.DajDan()==29)
                datum_prodaje.Postavi(1, 3, datum_prodaje.DajGodinu());
            else
                datum_prodaje.Postavi(datum_prodaje.DajDan()+1, datum_prodaje.DajMjesec(), datum_prodaje.DajGodinu());
        }
        else
        {
            if(datum_prodaje.DajDan()==28)
                datum_prodaje.Postavi(1, 3, datum_prodaje.DajGodinu());
            else
                datum_prodaje.Postavi(datum_prodaje.DajDan()+1, datum_prodaje.DajMjesec(), datum_prodaje.DajGodinu());
        }
    }
}

void Prodaja::PomjeriDanUnazad()
{
    if(datum_prodaje.DajMjesec()==12 || datum_prodaje.DajMjesec()==10 || datum_prodaje.DajMjesec()==7 || datum_prodaje.DajMjesec()==5)
    {
        if(datum_prodaje.DajDan()==1)
            datum_prodaje.Postavi(30, datum_prodaje.DajMjesec()-1, datum_prodaje.DajGodinu());
        else
            datum_prodaje.Postavi(datum_prodaje.DajDan()-1, datum_prodaje.DajMjesec(), datum_prodaje.DajGodinu());
    }
    
    else if(datum_prodaje.DajMjesec()==11 || datum_prodaje.DajMjesec()==9 || datum_prodaje.DajMjesec()==6 || datum_prodaje.DajMjesec()==4|| datum_prodaje.DajMjesec()==2)
    {
        if(datum_prodaje.DajDan()==1)
            datum_prodaje.Postavi(31, datum_prodaje.DajMjesec()-1, datum_prodaje.DajGodinu());
        else
            datum_prodaje.Postavi(datum_prodaje.DajDan()-1, datum_prodaje.DajMjesec(), datum_prodaje.DajGodinu());
    }
    
    else if(datum_prodaje.DajMjesec()==1)
    {
        if(datum_prodaje.DajDan()==1)
            datum_prodaje.Postavi(31, 12, datum_prodaje.DajGodinu()-1);
        else
            datum_prodaje.Postavi(datum_prodaje.DajDan()-1, datum_prodaje.DajMjesec(), datum_prodaje.DajGodinu());
    }
    
    else if(datum_prodaje.DajMjesec()==3)
    {
        if(datum_prodaje.DajDan()==1)
        {
            if((datum_prodaje.DajGodinu()%4==0 && datum_prodaje.DajGodinu()%100!=0) || datum_prodaje.DajGodinu()%400==0)
                datum_prodaje.Postavi(29, 2, datum_prodaje.DajGodinu());
            else
                datum_prodaje.Postavi(28, 2, datum_prodaje.DajGodinu());
        }
        else
            datum_prodaje.Postavi(datum_prodaje.DajDan()-1, datum_prodaje.DajMjesec(), datum_prodaje.DajGodinu());
    }
}

bool ProdatPrije(const Prodaja &p1, const Prodaja &p2)
{
    if(p1.DajDatumProdaje().DajGodinu()==p2.DajDatumProdaje().DajGodinu())
    {
        if(p1.DajDatumProdaje().DajMjesec()==p2.DajDatumProdaje().DajMjesec())
            return p1.DajDatumProdaje().DajDan()<p2.DajDatumProdaje().DajDan();
            
        return p1.DajDatumProdaje().DajMjesec()<p2.DajDatumProdaje().DajMjesec();
    }
    return p1.DajDatumProdaje().DajGodinu()<p2.DajDatumProdaje().DajGodinu();
}

bool SkupljiStan(const Prodaja &p1, const Prodaja &p2)
{
    return p1.DajCijenuStana()<p2.DajCijenuStana();
}



class Prodaje{
    vector<shared_ptr<Prodaja>> pok;
    
    public:
    
    explicit Prodaje() {}
    
    Prodaje(initializer_list<Prodaja> spisak_prodaja)
    {
        auto it=spisak_prodaja.begin();
        int i=0;
        while(it!=spisak_prodaja.end())
        {
            pok.push_back(make_shared<Prodaja>(*it));
            i++; it++;
        }
    }
    
    ~Prodaje()
    {
        for(int i=0; i<pok.size(); i++)
            pok[i]=nullptr;
        pok.resize(0);
    }
    
    Prodaje(const Prodaje &p)
    {
        for(int i=0; i<p.pok.size(); i++)
            pok.push_back(make_shared<Prodaja>(*p.pok[i]));
    }
    
    Prodaje(Prodaje &&p)
    {
        pok.resize(p.pok.size());
        for(int i=0; i<p.pok.size(); i++)
            pok[i]=p.pok[i];
            
        for(int i=0; i<p.pok.size(); i++)
            p.pok[i]=nullptr;
        p.pok.resize(0);
    }
    
    Prodaje &operator =( Prodaje &prodaje);
    Prodaje &operator =(Prodaje &&prodaje);
    
    void RegistrirajProdaju(const std::string &ime, double cijena, const Datum &datum, const Kupac &kupac, const Stan &stan)
    {
        Prodaja p(ime, cijena, datum, kupac, stan);
        pok.push_back(make_shared<Prodaja>(p));
    }
    
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata)
    {
        Datum datum(dan_prodaje, mjesec_prodaje, godina_prodaje);
        Kupac kupac(ime_kupca, datum_rodjenja_kupca);
        Stan stan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata);
        Prodaja p(ime_agenta_prodaje, cijena_stana, datum, kupac, stan);
        
        pok.push_back(make_shared<Prodaja>(p));
    }
    
    void RegistrirajProdaju(shared_ptr<Prodaja> prodaja)
    {
        pok.push_back(prodaja);
    }
    
    int DajBrojProdaja() const
    {
        if(pok.size()==0) throw domain_error("Nema registriranih prodaja");
        return pok.size();
    }
    
    int DajBrojProdajaNaDatum(const Datum &datum) const
    {
        int br=0;
        for(int i=0; i<pok.size(); i++)
            if(pok[i]->DajDatumProdaje().DajDan()==datum.DajDan() && pok[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec() && pok[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu() )
                br++;
        if(br==0) throw domain_error("Nema registriranih prodaja");
        return br;
    }
    
    int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const
    {
        int br=0;
        for(int i=0; i<pok.size(); i++)
            if(pok[i]->DajImeAgenta()==ime_agenta)
                br++;
        return br;
    }
    
    Prodaja &DajProdaju(int index) const
    {
        if(index<0 || index>pok.size()) throw domain_error("Neispravan parametar");
        return *pok[index];
    }
    
    Prodaja &DajNajranijuProdaju()
    {
        int min=0;
        for(int i=0; i<pok.size(); i++)
            if(ProdatPrije(*pok[i], *pok[min]))
                min=i;
        return *pok[min];
    }
    
    Prodaja DajNajranijuProdaju() const
    {
        int min=0;
        for(int i=0; i<pok.size(); i++)
            if(ProdatPrije(*pok[i], *pok[min]))
                min=i;
        return *pok[min];
    }
    
    Prodaja &DajNajskupljuProdaju()
    {
        double max=0; int maxi=0;
        for(int i=0; i<pok.size(); i++)
            if(pok[i]->DajCijenuStana()>max) 
            {
                max=pok[i]->DajCijenuStana();
                maxi=i;
            }
        return *pok[maxi];
    }
    
    Prodaja DajNajskupljuProdaju() const
    {
        double max=0; int maxi=0;
        for(int i=0; i<pok.size(); i++)
            if(pok[i]->DajCijenuStana()>max) 
            {
                max=pok[i]->DajCijenuStana();
                maxi=i;
            }
        return *pok[maxi];
    }
    
    void IsprazniKolekciju()
    {
        if(pok.size()==0) throw range_error("Prazna kolekcija");
        for(int i=0; i<pok.size(); i++)
            pok[i]=nullptr;
        pok.resize(0);
    }
    
    void ObrisiNajranijuProdaju();
    void ObrisiProdajeAgenta(const std::string &ime_agenta);
    void ObrisiProdajeNaDatum(const Datum &datum);
    void IspisiProdajeNaDatum(const Datum &datum) const;
    void IspisiSveProdaje() const;

};

Prodaje &Prodaje::operator =(Prodaje &p)
    {
        for(int i=0; i<pok.size(); i++)
            pok[i]=nullptr;
        pok.resize(0);
        for(int i=0; i<p.pok.size(); i++)
            pok.push_back(make_shared<Prodaja>(*p.pok[i]));
        return *this;
    }
    
    Prodaje &Prodaje::operator =(Prodaje &&p)
    {
        for(int i=0; i<pok.size(); i++)
            pok[i]=nullptr;
        pok.resize(0);
        for(int i=0; i<p.pok.size(); i++)
            pok.push_back(p.pok[i]);
        for(int i=0; i<p.pok.size(); i++)
            p.pok[i]=nullptr;
        p.pok.resize(0);
        return *this;
    }

    void Prodaje::ObrisiNajranijuProdaju()
    {
        if(pok.size()==0) throw range_error("Prazna kolekcija");
        Prodaja p=this->DajNajranijuProdaju();
        for(int i=0; i<pok.size(); i++)
        {
            if(pok[i]->DajImeAgenta()==p.DajImeAgenta() && pok[i]->DajDatumProdaje().DajDan()==p.DajDatumProdaje().DajDan() && pok[i]->DajDatumProdaje().DajMjesec()==p.DajDatumProdaje().DajMjesec() && pok[i]->DajDatumProdaje().DajGodinu()==p.DajDatumProdaje().DajGodinu() && pok[i]->DajCijenuStana()==p.DajCijenuStana() && pok[i]->DajImeKupca()==p.DajImeKupca())
            {
                pok[i]=nullptr;
                for(int j=i; j<pok.size()-1; j++)
                {
                    shared_ptr<Prodaja> pom=pok[j];
                    pok[j]=pok[j+1];
                    pok[j+1]=pom;
                }
                pok.resize(pok.size()-1);
            }
            
        }
    }
    
    void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta)
    {
        for(int i=0; i<pok.size(); i++)
        {
            if(pok[i]->DajImeAgenta()==ime_agenta)
            {
                pok[i]=nullptr;
                for(int j=i; j<pok.size()-1; j++)
                {
                    shared_ptr<Prodaja> pom=pok[j];
                    pok[j]=pok[j+1];
                    pok[j+1]=pom;
                }
                i--; pok.resize(pok.size()-1);
            }
        }
    }

    void Prodaje::ObrisiProdajeNaDatum(const Datum &datum)
    {
        for(int i=0; i<pok.size(); i++)
        {
            if(pok[i]->DajDatumProdaje().DajDan()==datum.DajDan() && pok[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec() && pok[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu())
            {
                pok[i]=nullptr;
                for(int j=i; j<pok.size()-1; j++)
                {
                    shared_ptr<Prodaja> pom=pok[j];
                    pok[j]=pok[j+1];
                    pok[j+1]=pom;
                }
                i--; pok.resize(pok.size()-1);
            }
            
        }
    }
    
    void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const
    {
      
        int k=0;
        vector<shared_ptr<Prodaja>> pom;
        
        for(int i=0; i<pok.size(); i++)
            if(pok[i]->DajDatumProdaje().DajDan()==datum.DajDan() && pok[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec() && pok[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu())
                {
                    pom.push_back(make_shared<Prodaja>(*pok[i]));
                    k++;
                }
                
        for(int o=0; o<k; o++)
        {
            for(int b=0; b<k; b++)
            if(pom[o]->DajImeKupca()<pom[b]->DajImeKupca())
                {
                    shared_ptr<Prodaja> pom2=pom[o];
                    pom[o]=pom[b];
                    pom[b]=pom2;
                }
        }
        
        for(int h=0; h<k; h++)
        {
            pok[h]->Ispisi(); cout<<endl<<endl;
        }
        for(int i=0; i<k; i++)
            pom[i]=nullptr;
        pom.resize(0);
        
    }
    
    void Prodaje::IspisiSveProdaje() const
    {
        vector<shared_ptr<Prodaja>> pom;
        for(int i=0; i<pok.size(); i++)
            pom.push_back(make_shared<Prodaja>(*pok[i]));
        for(int a=0; a<pok.size(); a++)
            for(int b=0; b<pok.size(); b++)
            {
                if(ProdatPrije(*pom[a],*pom[b]))
                {
                shared_ptr<Prodaja> pom2=pom[a];
                pom[a]=pom[b];
                pom[b]=pom2;
                }
            }
            for(int i=0; i<pok.size(); i++)
            {    
                pom[i]->Ispisi(); cout<<endl<<endl;
            }
        for(int y=0; y<pok.size(); y++)
            pom[y]=nullptr;
        pom.resize(0);
    }
    
    void NapraviDatum(string s, int &dan, int &mjesec, int &godina)
    {
        int k=1, i=s.length()-1, suma1=0, suma2=0, suma3=0;
        while(s[i]!='/')
        {
            suma1+=(s[i]-'0')*k;
            k*=10;
            i--;
        }
        i--;
        k=1; godina=suma1;
        while(s[i]!='/')
        {
            suma2+=(s[i]-'0')*k;
            k*=10;
            i--;
        }
        i--;
        k=1; mjesec=suma2;
        while(i>=0)
        {
            suma3+=(s[i]-'0')*k;
            k*=10;
            i--;
        }
        dan=suma3;
    }
    
    int main()
    {
        Prodaje prodaje;
        
        Kupac kupac1("Lejla Kafedzic", {20, 12, 1997});
        Kupac kupac2("Niko Nikic", {29, 2, 2016});
        
        Stan stan1("Ferhadija 10", 2, 5, 1, 100);
        Stan stan2("Zmaja od Bosne 5", 4, 5, 0, 100);
        
        prodaje.RegistrirajProdaju("Agentko Agentic", 100000, {3, 6, 2017}, kupac1, stan1);
        prodaje.RegistrirajProdaju("Agent 007", 20000, {2, 6, 2017}, kupac2, stan2);
        
        prodaje.IspisiSveProdaje();
        
        cout<<"Ukupan broj prodaja: "<<prodaje.DajBrojProdaja()<<endl;
        
        prodaje.ObrisiProdajeAgenta("Agent 007");
        
        prodaje.IspisiProdajeNaDatum({2, 6, 2017});
        prodaje.IspisiProdajeNaDatum({3, 6, 2017});
        
        prodaje.RegistrirajProdaju("Novi Agent", 35000, {3, 6, 2017}, {"Mali Princ", {12, 11, 1996}}, {"Ivica 20", 1, 6, 1, 120});
        prodaje.IspisiSveProdaje();
        
        cout<<"Caossss";
        
        return 0;
    }
    
    
    
    