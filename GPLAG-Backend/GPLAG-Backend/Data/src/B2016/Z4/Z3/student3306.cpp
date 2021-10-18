/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <list>
#include <vector>

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
    int max_broj_prodaja, trenutni_broj_prodaja=0;
    Prodaja **pok;
    
    public:
    
    explicit Prodaje(int max_)
    {
        max_broj_prodaja=max_;
        trenutni_broj_prodaja=0;
        pok=new Prodaja*[max_broj_prodaja];
    }
    
    Prodaje(initializer_list<Prodaja> spisak_prodaja)
    {
        max_broj_prodaja=spisak_prodaja.size();
        trenutni_broj_prodaja=0;
        pok=new Prodaja*[max_broj_prodaja];
        for(auto it=spisak_prodaja.begin(); it!=spisak_prodaja.end(); it++)
            pok[trenutni_broj_prodaja++]=new Prodaja(*it);
    }
    
    ~Prodaje()
    {
        for(int i=0; i<trenutni_broj_prodaja; i++)
            delete pok[i];
        delete [] pok;
    }
    
    Prodaje(const Prodaje &p)
    {
        max_broj_prodaja=p.max_broj_prodaja;
        trenutni_broj_prodaja=p.trenutni_broj_prodaja;
        pok=new Prodaja*[max_broj_prodaja];
        for(int i=0; i<trenutni_broj_prodaja; i++)
            pok[i]=new Prodaja(*p.pok[i]);
    }
    
    Prodaje(Prodaje &&p)
    {
        max_broj_prodaja=p.max_broj_prodaja;
        trenutni_broj_prodaja=p.trenutni_broj_prodaja;
        pok=p.pok;
        p.trenutni_broj_prodaja=0; p.pok=nullptr;
    }
    
    Prodaje &operator =( Prodaje &prodaje);
    Prodaje &operator =(Prodaje &&prodaje);
    
    void RegistrirajProdaju(const std::string &ime, double cijena, const Datum &datum, const Kupac &kupac, const Stan &stan)
    {
        if(trenutni_broj_prodaja==max_broj_prodaja) throw range_error("Dostignut maksimalni broj prodaja");
        pok[trenutni_broj_prodaja++]=new Prodaja(ime, cijena, datum, kupac, stan);
    }
    
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata)
    {
        if(trenutni_broj_prodaja==max_broj_prodaja) throw range_error("Dostignut maksimalni broj prodaja");
        
        Datum datum(dan_prodaje, mjesec_prodaje, godina_prodaje);
        Kupac kupac(ime_kupca, datum_rodjenja_kupca);
        Stan stan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata);
        
        pok[trenutni_broj_prodaja++]=new Prodaja(ime_agenta_prodaje, cijena_stana, datum, kupac, stan);
    }
    
    void RegistrirajProdaju(Prodaja *prodaja)
    {
        if(trenutni_broj_prodaja==max_broj_prodaja) throw range_error("Dostignut maksimalni broj prodaja");
        pok[trenutni_broj_prodaja++]=prodaja;
    }
    
    int DajBrojProdaja() const
    {
        if(trenutni_broj_prodaja==0) throw domain_error("Nema registriranih prodaja");
        return trenutni_broj_prodaja;
    }
    
    int DajBrojProdajaNaDatum(const Datum &datum) const
    {
        int br=0;
        for(int i=0; i<trenutni_broj_prodaja; i++)
            if(pok[i]->DajDatumProdaje().DajDan()==datum.DajDan() && pok[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec() && pok[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu() )
                br++;
        if(br==0) throw domain_error("Nema registriranih prodaja");
        return br;
    }
    
    int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const
    {
        int br=0;
        for(int i=0; i<trenutni_broj_prodaja; i++)
            if(pok[i]->DajImeAgenta()==ime_agenta)
                br++;
        return br;
    }
    
    Prodaja &DajProdaju(int index) const
    {
        if(index<0 || index>trenutni_broj_prodaja) throw domain_error("Neispravan parametar");
        return *pok[index];
    }
    
    Prodaja &DajNajranijuProdaju()
    {
        int min=0;
        for(int i=0; i<trenutni_broj_prodaja; i++)
            if(ProdatPrije(*pok[i], *pok[min]))
                min=i;
        return *pok[min];
    }
    
    Prodaja DajNajranijuProdaju() const
    {
        int min=0;
        for(int i=0; i<trenutni_broj_prodaja; i++)
            if(ProdatPrije(*pok[i], *pok[min]))
                min=i;
        return *pok[min];
    }
    
    Prodaja &DajNajskupljuProdaju()
    {
        double max=0; int maxi=0;
        for(int i=0; i<trenutni_broj_prodaja; i++)
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
        for(int i=0; i<trenutni_broj_prodaja; i++)
            if(pok[i]->DajCijenuStana()>max) 
            {
                max=pok[i]->DajCijenuStana();
                maxi=i;
            }
        return *pok[maxi];
    }
    
    void IsprazniKolekciju()
    {
        if(trenutni_broj_prodaja==0) throw range_error("Prazna kolekcija");
        for(int i=0; i<trenutni_broj_prodaja; i++)
            delete pok[i];
        trenutni_broj_prodaja=0;
    }
    
    void ObrisiNajranijuProdaju();
    void ObrisiProdajeAgenta(const std::string &ime_agenta);
    void ObrisiProdajeNaDatum(const Datum &datum);
    void IspisiProdajeNaDatum(const Datum &datum) const;
    void IspisiSveProdaje() const;

};

Prodaje &Prodaje::operator =( Prodaje &prodaje)
    {
        if(this==&prodaje) return *this;
        for(int i=0; i<trenutni_broj_prodaja; i++)
            delete pok[i];
        delete [] pok;
        max_broj_prodaja=prodaje.max_broj_prodaja;
        trenutni_broj_prodaja=prodaje.trenutni_broj_prodaja;
        pok=new Prodaja*[max_broj_prodaja];
        for(int i=0; i<trenutni_broj_prodaja; i++)
            pok[i]=new Prodaja(*prodaje.pok[i]);
        prodaje.trenutni_broj_prodaja=0; prodaje.pok=nullptr;
        return *this;
    }
    
    Prodaje &Prodaje::operator =(Prodaje &&prodaje)
    {
        if(this==&prodaje) return *this;
        for(int i=0; i<trenutni_broj_prodaja; i++)
            delete pok[i];
        delete [] pok;
        max_broj_prodaja=prodaje.max_broj_prodaja;
        trenutni_broj_prodaja=prodaje.trenutni_broj_prodaja;
        pok=prodaje.pok;
        trenutni_broj_prodaja=0; 
        return *this;
    }

    void Prodaje::ObrisiNajranijuProdaju()
    {
        if(trenutni_broj_prodaja==0) throw range_error("Prazna kolekcija");
        Prodaja p=this->DajNajranijuProdaju();
        for(int i=0; i<trenutni_broj_prodaja; i++)
        {
            if(pok[i]->DajImeAgenta()==p.DajImeAgenta() && pok[i]->DajDatumProdaje().DajDan()==p.DajDatumProdaje().DajDan() && pok[i]->DajDatumProdaje().DajMjesec()==p.DajDatumProdaje().DajMjesec() && pok[i]->DajDatumProdaje().DajGodinu()==p.DajDatumProdaje().DajGodinu() && pok[i]->DajCijenuStana()==p.DajCijenuStana() && pok[i]->DajImeKupca()==p.DajImeKupca())
            {
                delete pok[i];
                for(int j=i; j<trenutni_broj_prodaja-1; j++)
                {
                    Prodaja *pom=pok[j];
                    pok[j]=pok[j+1];
                    pok[j+1]=pom;
                }
                trenutni_broj_prodaja--;
            }
            
        }
    }
    
    void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta)
    {
        for(int i=0; i<trenutni_broj_prodaja; i++)
        {
            if(pok[i]->DajImeAgenta()==ime_agenta)
            {
                delete pok[i];
                for(int j=i; j<trenutni_broj_prodaja-1; j++)
                {
                    Prodaja *pom=pok[j];
                    pok[j]=pok[j+1];
                    pok[j+1]=pom;
                }
                i--; trenutni_broj_prodaja--;
            }
        }
    }

    void Prodaje::ObrisiProdajeNaDatum(const Datum &datum)
    {
        for(int i=0; i<trenutni_broj_prodaja; i++)
        {
            if(pok[i]->DajDatumProdaje().DajDan()==datum.DajDan() && pok[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec() && pok[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu())
            {
                delete pok[i];
                for(int j=i; j<trenutni_broj_prodaja-1; j++)
                {
                    Prodaja *pom=pok[j];
                    pok[j]=pok[j+1];
                    pok[j+1]=pom;
                }
                i--; trenutni_broj_prodaja--;
            }
            
        }
    }
    
    void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const
    {
        int k=0;
        Prodaja** pom=new Prodaja*[trenutni_broj_prodaja];
        for(int i=0; i<trenutni_broj_prodaja; i++)
        {
            if(pok[i]->DajDatumProdaje().DajDan()==datum.DajDan() && pok[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec() && pok[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu())
                {
                    pom[k]=new Prodaja(*pok[i]);
                    k++;
                }
        }
        for(int o=0; o<k; o++)
        {
            for(int b=0; b<k; b++)
            if(pom[o]->DajImeKupca()<pom[b]->DajImeKupca())
                {
                    Prodaja* pom2=pom[o];
                    pom[o]=pom[b];
                    pom[b]=pom2;
                }
        }
        for(int h=0; h<k; h++)
            {pom[h]->Ispisi(); cout<<endl<<endl;}
        for(int i=0; i<k; i++)
            delete pom[i];
        delete [] pom;
    }
    /*{
      
        
        
        for(int i=0; i<trenutni_broj_prodaja; i++)
            if(pok[i]->DajDatumProdaje().DajDan()==datum.DajDan() && pok[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec() && pok[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu())
                {pok[i]->Ispisi(); cout<<endl<<endl;}
        
    }*/
    
    void Prodaje::IspisiSveProdaje() const
    {
        Prodaja** pom=new Prodaja*[trenutni_broj_prodaja];
        for(int i=0; i<trenutni_broj_prodaja; i++)
            pom[i]=new Prodaja(*pok[i]);
            
        for(int j=0; j<trenutni_broj_prodaja; j++)
            for(int k=0; k<trenutni_broj_prodaja; k++)
            {
                if(ProdatPrije(*pom[j], *pom[k]))
                {
                    Prodaja *pom2=pom[j];
                    pom[j]=pom[k];
                    pom[k]=pom2;
                }
            }
            for(int i=0; i<trenutni_broj_prodaja; i++)
            {    
                pom[i]->Ispisi(); cout<<endl<<endl;
            }
            for(int i=0; i<trenutni_broj_prodaja; i++)
                delete pom[i];
            delete [] pom;
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
    
int main ()
{
    string a="aldin", b="bldin";
    if(a>b)cout<<"a je prije"<<endl<<endl;
    Prodaje prodaje(20);
    string adresa, ime_kupca, ime_agenta;
    int sprat, broj_soba, namjesten, dan=0, mjesec=0, godina=0, cijena_stana;
    double kvadratura;
    vector<Stan> stanovi; vector<Kupac> kupci; vector<Prodaja> prodaja;
    cout<<"Dobrodosli!"<<endl<<endl<<endl;
    for(;;)
    {   glavni_meni:
        cout<<"Izaberite opciju:"<<endl<<" 0 - kraj"<<endl<<" 1 - uredjivanje stanova"<<endl;
        cout<<" 2 - uredjivanje kupaca"<<endl<<" 3 - uredjivanje prodaja"<<endl;
        int opcija=0;
        cin>>opcija;
        int opcija2=0, opcija3=0;
        if(opcija==0) {goto kraj;}
        else if(opcija==1)
        {
            for(;;)
            {   meni_stanovi:
                cout<<"Izaberite opciju:"<<endl<<" 0 - nazad"<<endl<<" 1 - dodavanje stana"<<endl;
                cout<<" 2 - uredjivanje stanova"<<endl<<" 3 - ispis svih stanova"<<endl<<" 4 - kraj"<<endl;
                cin>>opcija2;
                if(opcija2==0) {goto glavni_meni;}
                else if(opcija2==1)
                {
                    int pom;
                    bool valja=false;
                    while(valja==false)
                    {
                        getline(cin, adresa);
                        cout<<"Unesite adresu: "; getline(cin, adresa);
                        cout<<"Unesite sprat: "; cin>>sprat;
                        cout<<"Unesite broj soba: "; cin>>broj_soba;
                        cout<<"Da li je stan namjesten (1 - da, 0 - ne): "; cin>>pom; 
                        cout<<"Unesite kvadraturu: "; cin>>kvadratura;
                        try
                        {
                            if(pom!=1 &&pom!=0)  throw domain_error("Neispravan unos podataka"); namjesten=pom;
                            Stan stan(adresa, sprat, broj_soba, namjesten, kvadratura);
                            stanovi.push_back(stan);
                            cout<<"Stan je uspjesno dodan!"<<endl<<endl;
                            valja=true;
                        }
                        catch(domain_error d){cout<<"Izuzetak: "<<d.what()<<". Molimo unesite opet."<<endl;}
                        catch(range_error r){cout<<"Izuzetak: "<<r.what()<<". Molimo unesite opet."<<endl;}
                    }
                }
                else if(opcija2==2)
                {
                    cout<<"Odaberite stan. Dostupni stanovi su:"<<endl;
                    for(int i=0; i<stanovi.size(); i++)
                    {
                        cout<<" "<<i+1<<" - "; stanovi[i].Ispisi(); cout<<endl;
                    }
                    int biraj_stan;
                    cin>>biraj_stan;
                    cout<<"Odaberite polje koje zelite urediti:"<<endl<<" 0 - nazad"<<endl<<" 1 - adresa"<<endl<<" 2 - sprat"<<endl;
                    cout<<" 3 - broj soba"<<endl<<" 4 - da li je stan namjesten"<<endl<<" 5 - kvadratura"<<endl<<" 6 - sve"<<endl;
                    int polje_stan;
                    cin>>polje_stan;
                    if(polje_stan==0){goto meni_stanovi;}
                    else if(polje_stan==1)
                    {   
                        for(;;)
                        {
                            try
                            {
                                getline(cin, adresa);
                                cout<<"Unesite adresu: ";
                                getline(cin, adresa);
                                stanovi[biraj_stan-1].Postavi(adresa, stanovi[biraj_stan-1].DajSprat(), stanovi[biraj_stan-1].DajBrojSoba(), stanovi[biraj_stan-1].DajNamjesten(), stanovi[biraj_stan-1].DajKvadraturu());
                                cout<<"Stan je uspjesno izmijenjen!"<<endl<<endl;
                                goto meni_stanovi;
                            }
                            catch(domain_error d){cout<<"Izuzetak: "<<d.what()<<". Molimo unesite opet."<<endl;}
                            catch(range_error r){cout<<"Izuzetak: "<<r.what()<<". Molimo unesite opet."<<endl;}
                        }
                    }
                    else if(polje_stan==2)
                    {
                        for(;;)
                        {
                            try
                            {
                                cout<<"Unesite sprat: ";
                                cin>>sprat;
                                stanovi[biraj_stan-1].Postavi(stanovi[biraj_stan-1].DajAdresu(), sprat, stanovi[biraj_stan-1].DajBrojSoba(), stanovi[biraj_stan-1].DajNamjesten(), stanovi[biraj_stan-1].DajKvadraturu());
                                cout<<"Stan je uspjesno izmijenjen!"<<endl<<endl;
                                goto meni_stanovi;
                            }
                            catch(domain_error d){cout<<"Izuzetak: "<<d.what()<<". Molimo unesite opet."<<endl;}
                            catch(range_error r){cout<<"Izuzetak: "<<r.what()<<". Molimo unesite opet."<<endl;}
                        }
                    }
                    else if(polje_stan==3)
                    {
                        for(;;)
                        {
                            try
                            {
                                cout<<"Unesite broj soba: ";
                                cin>>broj_soba;
                                stanovi[biraj_stan-1].Postavi(stanovi[biraj_stan-1].DajAdresu(), sprat, broj_soba, stanovi[biraj_stan-1].DajNamjesten(), stanovi[biraj_stan-1].DajKvadraturu());
                                cout<<"Stan je uspjesno izmijenjen!"<<endl<<endl;
                                goto meni_stanovi;
                            }
                            catch(domain_error d){cout<<"Izuzetak: "<<d.what()<<". Molimo unesite opet."<<endl;}
                            catch(range_error r){cout<<"Izuzetak: "<<r.what()<<". Molimo unesite opet."<<endl;}
                        }
                    }
                    else if(polje_stan==4)
                    {
                        for(;;)
                        {
                            cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                            int pom;
                            cin>>pom;
                            try
                            {
                                if(pom!=1 && pom!=0)  throw domain_error("Neispravan unos podataka");
                                namjesten=pom;
                                stanovi[biraj_stan-1].Postavi(stanovi[biraj_stan-1].DajAdresu(), sprat, stanovi[biraj_stan-1].DajBrojSoba(), namjesten, stanovi[biraj_stan-1].DajKvadraturu());
                                cout<<"Stan je uspjesno izmijenjen!"<<endl<<endl;
                                goto meni_stanovi;
                            }
                            catch(domain_error d){cout<<"Izuzetak: "<<d.what()<<". Molimo unesite opet."<<endl;}
                            catch(range_error r){cout<<"Izuzetak: "<<r.what()<<". Molimo unesite opet."<<endl;}
                        }
                    }
                    else if(polje_stan==5)
                    {
                        for(;;)
                        {
                            cout<<"Unesite kvadraturu: ";
                            cin>>kvadratura;
                            try
                            {
                                stanovi[biraj_stan-1].Postavi(stanovi[biraj_stan-1].DajAdresu(), stanovi[biraj_stan-1].DajSprat(), stanovi[biraj_stan-1].DajBrojSoba(), stanovi[biraj_stan-1].DajNamjesten(), kvadratura);
                                cout<<"Stan je uspjesno izmijenjen!"<<endl<<endl;
                                goto meni_stanovi;
                            }
                            catch(domain_error d){cout<<"Izuzetak: "<<d.what()<<". Molimo unesite opet."<<endl;}
                            catch(range_error r){cout<<"Izuzetak: "<<r.what()<<". Molimo unesite opet."<<endl;}
                        }
                    }
                    else if(polje_stan==6)
                    {
                        for(;;)
                        {
                            getline(cin, adresa);
                            cout<<"Unesite adresu: "; getline(cin, adresa);
                            cout<<"Unesite sprat: "; cin>>sprat;
                            cout<<"Unesite broj soba: "; cin>>broj_soba;
                            cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";cin>>namjesten;
                            cout<<"Unesite kvadraturu: "; cin>>kvadratura;
                            try
                            {
                                stanovi[biraj_stan-1].Postavi(adresa, sprat, broj_soba, namjesten, kvadratura);
                                cout<<"Stan je uspjesno izmijenjen!"<<endl<<endl;
                                goto meni_stanovi;
                            }
                            catch(domain_error d){cout<<"Izuzetak: "<<d.what()<<". Molimo unesite opet."<<endl;}
                            catch(range_error r){cout<<"Izuzetak: "<<r.what()<<". Molimo unesite opet."<<endl;} 
                        }
                    }
    
                }
                else if(opcija2==3)
                {
                    for(int i=0; i<stanovi.size(); i++)
                    {
                        cout<<i+1<<". "; stanovi[i].Ispisi(); cout<<endl;
                    }
                }
                else if(opcija2==4) {goto kraj;}
            }
            
        }
        else if(opcija==2)
        {
            meni_kupac:
            cout<<endl<<"Izaberite opciju:"<<endl<<" 0 - nazad"<<endl<<" 1 - dodavanje kupca"<<endl;
            cout<<" 2 - uredjivanje kupaca"<<endl<<" 3 - ispis svih kupaca"<<endl<<" 4 - kraj"<<endl;
            cin>>opcija2;
            if(opcija2==0) {goto glavni_meni;}
            else if(opcija2==1)
            {
                bool moze=false;
                while(moze==false)
                {
                    getline(cin, ime_kupca);
                    cout<<"Unesite ime i prezime kupca: "; getline(cin, ime_kupca);
                    cout<<"Unesite datum rodjenja (formata d/m/g): ";  string unos_datuma; cin>>unos_datuma; NapraviDatum(unos_datuma, dan, mjesec, godina);
                    try
                    {
                        Datum datum(dan, mjesec, godina);
                        Kupac kupac(ime_kupca, datum);
                        kupci.push_back(kupac);
                        moze=true;
                        cout<<"Kupac je uspjesno dodan!"<<endl;
                        goto meni_kupac;
                    }
                    catch(domain_error d2){cout<<"Izuzetak: "<<d2.what()<<". Molimo unesite opet."<<endl;}
                    catch(range_error r2){cout<<"Izuzetak: "<<r2.what()<<". Molimo unesite opet."<<endl;}
                }
            }
            else if(opcija2==2)
            {
                cout<<"Odaberite kupca kojeg zelite urediti. Dostupni kupci su:"<<endl;
                for(int i=0; i<kupci.size(); i++)
                {
                    cout<<" "<<i+1<<" - "; kupci[i].Ispisi(); cout<<endl;
                }
                int biraj_kupca;
                cin>>biraj_kupca;
                bool moze=false;
                while(moze==false)
                {
                    getline(cin, ime_kupca);
                    cout<<"Unesite ime i prezime kupca: "; getline(cin, ime_kupca);
                    cout<<"Unesite datum rodjenja (formata d/m/g): "; string unos_datuma; cin>>unos_datuma; NapraviDatum(unos_datuma, dan, mjesec, godina);
                    try
                    {
                        Datum datum(dan, mjesec, godina);
                        Kupac kupac(ime_kupca, datum);
                        kupci[biraj_kupca-1].Postavi(ime_kupca, datum);
                        moze=true;
                        cout<<"Kupac je uspjesno izmijenjen!"<<endl;
                        goto meni_kupac;
                    }
                    catch(domain_error d2){cout<<"Izuzetak: "<<d2.what()<<". Molimo unesite opet."<<endl;}
                    catch(range_error r2){cout<<"Izuzetak: "<<r2.what()<<". Molimo unesite opet."<<endl;}
                }
            }
            else if(opcija2==3)
            {
                for(int i=0; i<kupci.size(); i++)
                {
                    kupci[i].Ispisi(); cout<<endl;
                }
                goto meni_kupac;
            }
        }
        else if(opcija==3)
        {
            meni_prodaja:
            cout<<"Izaberite opciju:"<<endl<<" 0 - nazad"<<endl<<" 1 - dodavanje prodaje"<<endl<<" 2 - uredjivanje prodaje"<<endl;
            cout<<" 3 - ispis prodaja"<<endl<<" 4 - brisanje prodaja"<<endl<<" 5 - kraj"<<endl;
            cin>>opcija2;
            if(opcija2==0) {goto glavni_meni;}
            else if(opcija2==1)
            {
                meni_pravi_prodaju:
                cout<<"Izaberite opciju:"<<endl<<" 0 - nazad"<<endl<<" 1 - dodavanje potpuno nove prodaje"<<endl<<" 2 - dodavanje nove prodaje na osnovu arhive"<<endl<<" 3 - kraj"<<endl;
                cin>>opcija3;
                if(opcija3==0) {goto meni_prodaja;}
                else if(opcija3==1)
                {
                    bool ide=false;
                    while(ide==false)
                    {
                        int d=0, m=0, g=0;
                        getline(cin, ime_agenta);
                        cout<<"Unesite ime i prezime agenta prodaje: "; getline(cin, ime_agenta);
                        cout<<"Unesite datum prodaje (formata d/m/g): "; string unos_datuma; cin>>unos_datuma; NapraviDatum(unos_datuma, d, m, g);
                        cout<<"Unesite cijenu stana: "; cin>>cijena_stana;
                        getline(cin, ime_kupca);
                        cout<<"Unesite ime kupca: "; getline(cin, ime_kupca);
                        cout<<"Unesite datum rodjenja kupca (formata d/m/g): "; string unos_datuma2; cin>>unos_datuma2; NapraviDatum(unos_datuma2, dan, mjesec, godina);
                        getline(cin, adresa);
                        cout<<"Unesite adresu: "; getline(cin, adresa);
                        cout<<"Unesite sprat: "; cin>>sprat;
                        cout<<"Unesite broj soba: "; cin>>broj_soba;
                        cout<<"Da li je stan namjesten (1 - da, 0 - ne): "; cin>>namjesten;
                        cout<<"Unesite kvadraturu: "; cin>>kvadratura;
                        try
                        {
                            Datum datum1(d, m, g);
                            Datum datum2(dan, mjesec, godina);
                            Kupac kupac(ime_kupca, datum2); kupci.push_back(kupac);
                            Stan stan(adresa, sprat, broj_soba, namjesten, kvadratura); stanovi.push_back(stan);
                            prodaje.RegistrirajProdaju(ime_agenta, cijena_stana, datum1, kupac, stan);
                            ide=true;
                            cout<<"Prodaja uspjesno dodana!"<<endl<<endl;
                            goto meni_pravi_prodaju;
                        }
                        catch(domain_error d3){cout<<"Izuzetak: "<<d3.what()<<". Molimo unesite opet."<<endl;}
                        catch(range_error r3){cout<<"Izuzetak: "<<r3.what()<<". Molimo unesite opet."<<endl;}
                    }
                }
                else if(opcija3==2)
                {
                    bool ide3=false;
                    while(ide3==false)
                    {
                        int d=0, m=0, g=0;
                        getline(cin, ime_agenta);
                        cout<<"Unesite ime i prezime agenta prodaje: "; getline(cin, ime_agenta);
                        cout<<"Unesite datum prodaje (formata d/m/g): "; string unos_datuma; cin>>unos_datuma; NapraviDatum(unos_datuma, d, m, g);
                        cout<<"Unesite cijenu stana: "; cin>>cijena_stana;
                        cout<<"Odaberite kupca. Dostupni kupci su:"<<endl;
                        for(int i=0; i<kupci.size(); i++)
                        {
                            cout<<" "<<i+1<<" - "; kupci[i].Ispisi(); cout<<endl;
                        }
                        int odaberi_kupca;
                        cin>>odaberi_kupca;
                        cout<<"Odaberite stan. Dostupni stanovi su:"<<endl;
                        for(int i=0; i<stanovi.size(); i++)
                        {
                            cout<<" "<<i+1<<" - "; stanovi[i].Ispisi(); cout<<endl;
                        }
                        int odaberi_stan;
                        cin>>odaberi_stan;
                        try
                            {
                                Datum datum1(d, m, g);
                                prodaje.RegistrirajProdaju(ime_agenta, cijena_stana, datum1, kupci[odaberi_kupca-1], stanovi[odaberi_stan-1]);
                                ide3=true;
                                cout<<"Prodaja uspjesno dodana!"<<endl<<endl;
                                goto meni_pravi_prodaju;
                            }
                            catch(domain_error d3){cout<<"Izuzetak: "<<d3.what()<<". Molimo unesite opet."<<endl;}
                            catch(range_error r3){cout<<"Izuzetak: "<<r3.what()<<". Molimo unesite opet."<<endl;}
                    }
                }
            }
            else if(opcija2==2)
            {
                meni_uredi_prodaje:
                cout<<"Odaberite prodaju koju želite urediti. Dostupne prodaje su:"<<endl;
                for(int i=0; i<prodaje.DajBrojProdaja(); i++)
                {
                    cout<<i+1<<"."<<endl; prodaje.DajProdaju(i).Ispisi(); cout<<endl;
                }
                int odaberi_prodaju;
                cin>>odaberi_prodaju;
                cout<<"Izaberite opciju:"<<endl<<" 0 - nazad"<<endl<<" 1 - izmjena agenta"<<endl<<" 2 - izmjena datuma prodaje"<<endl<<" 3 - izmjena kupca"<<endl;
                cout<<" 4 - izmjena stana"<<endl<<" 5 - izmjena cijene stana"<<endl;
                cin>>opcija3;
                if(opcija3==0) {goto meni_prodaja;}
                else if(opcija3==1)
                {
                    bool moze=false;
                    while(moze==false)
                    {
                        getline(cin, ime_agenta);
                        cout<<"Unesite ime i prezime agenta prodaje: "; getline(cin, ime_agenta);
                        try
                        {   
                            prodaje.DajProdaju(odaberi_prodaju-1).Postavi(ime_agenta, prodaje.DajProdaju(odaberi_prodaju-1).DajCijenuStana(), prodaje.DajProdaju(odaberi_prodaju-1).DajDatumProdaje(), {prodaje.DajProdaju(odaberi_prodaju-1).DajImeKupca(), prodaje.DajProdaju(odaberi_prodaju-1).DajDatumRodjenjaKupca()}, prodaje.DajProdaju(odaberi_prodaju-1).DajStan());
                            moze=true;
                            cout<<"Prodaja je uspjesno izmijenjena!"<<endl<<endl;
                            goto meni_prodaja;
                        }
                        catch(domain_error d2){cout<<"Izuzetak: "<<d2.what()<<". Molimo unesite opet."<<endl;}
                        catch(range_error r2){cout<<"Izuzetak: "<<r2.what()<<". Molimo unesite opet."<<endl;}
                    }
                }
                else if(opcija3==2)
                {
                    bool moze=false;
                    while(moze==false)
                    {
                        cout<<"Unesite datum prodaje (formata d/m/g): "; string unos_datuma; cin>>unos_datuma; NapraviDatum(unos_datuma, dan, mjesec, godina);
                        try
                        {   
                            prodaje.DajProdaju(odaberi_prodaju-1).PromijeniDatumKupovine({dan, mjesec, godina});
                            moze=true;
                            cout<<"Prodaja je uspjesno izmijenjena!"<<endl<<endl;
                            goto meni_prodaja;
                        }
                        catch(domain_error d2){cout<<"Izuzetak: "<<d2.what()<<". Molimo unesite opet."<<endl;}
                        catch(range_error r2){cout<<"Izuzetak: "<<r2.what()<<". Molimo unesite opet."<<endl;}
                    }
                    
                }
                else if(opcija3==3)
                {
                    cout<<"Izaberite opciju:"<<endl<<" 0 - nazad"<<endl<<" 1 - odabir postojeceg kupca"<<endl<<" 2 - dodavanje novog kupca"<<endl;
                    int opcija4;
                    cin>>opcija4;
                    if(opcija4==0){goto meni_uredi_prodaje;}
                    else if(opcija4==1)
                    {
                        cout<<"Odaberite kupca. Dostupni kupci su:"<<endl;
                        for(int i=0; i<kupci.size(); i++)
                        {
                            cout<<i+1<<" - "; kupci[i].Ispisi(); cout<<endl;
                        }
                        int biraj_kupca;
                        cin>>biraj_kupca;
                        try
                        {   
                            prodaje.DajProdaju(odaberi_prodaju-1).PromijeniKupca({kupci[biraj_kupca-1].DajIme(), {kupci[biraj_kupca-1].DajDatumRodjenja()}});
                            cout<<"Prodaja je uspjesno izmijenjena!"<<endl<<endl;
                            goto meni_prodaja;
                        }
                        catch(domain_error d2){cout<<"Izuzetak: "<<d2.what()<<". Molimo unesite opet."<<endl;}
                        catch(range_error r2){cout<<"Izuzetak: "<<r2.what()<<". Molimo unesite opet."<<endl;}
                    }
                    else if(opcija4==2)
                    {
                        bool moze=false;
                        while(moze==false)
                        {
                            getline(cin, ime_kupca);
                            cout<<"Unesite ime i prezime kupca: "; getline(cin, ime_kupca);
                            cout<<"Unesite datum rodjenja (formata d/m/g): "; string unos_datuma; cin>>unos_datuma; NapraviDatum(unos_datuma, dan, mjesec, godina);
                            try
                            {   
                                prodaje.DajProdaju(odaberi_prodaju-1).PromijeniKupca({ime_kupca, {dan, mjesec, godina}});
                                kupci.push_back({ime_kupca, {dan, mjesec, godina}});
                                moze=true;
                                cout<<"Prodaja je uspjesno izmijenjena!"<<endl<<endl;
                                goto meni_prodaja;
                            }
                            catch(domain_error d2){cout<<"Izuzetak: "<<d2.what()<<". Molimo unesite opet."<<endl;}
                            catch(range_error r2){cout<<"Izuzetak: "<<r2.what()<<". Molimo unesite opet."<<endl;}
                        }
                    }
                }
                else if(opcija3==4)
                {
                    cout<<"Izaberite opciju:"<<endl<<" 0 - nazad"<<endl<<" 1 - odabir postojeceg stana"<<endl<<" 2 - dodavanje novog stana"<<endl;
                    int opcija4;
                    cin>>opcija4;
                    if(opcija4==0){goto meni_uredi_prodaje;}
                    else if(opcija4==1)
                    {
                        cout<<"Odaberite stan. Dostupni stanovi su:"<<endl;
                        for(int i=0; i<stanovi.size(); i++)
                        {
                            cout<<" "<<i+1<<" - "; stanovi[i].Ispisi(); cout<<endl;
                        }
                        int biraj_stan;
                        cin>>biraj_stan;
                        try
                        {   
                            prodaje.DajProdaju(odaberi_prodaju-1).PromijeniStan(stanovi[biraj_stan-1]);
                            cout<<"Prodaja je uspjesno izmijenjena!"<<endl<<endl;
                            goto meni_prodaja;
                        }
                        catch(domain_error d2){cout<<"Izuzetak: "<<d2.what()<<". Molimo unesite opet."<<endl;}
                        catch(range_error r2){cout<<"Izuzetak: "<<r2.what()<<". Molimo unesite opet."<<endl;}
                    }
                    else if(opcija4==2)
                    {
                        getline(cin, adresa);
                        cout<<"Unesite adresu: "; getline(cin, adresa);
                        cout<<"Unesite sprat: "; cin>>sprat;
                        cout<<"Unesite broj soba: "; cin>>broj_soba;
                        cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";cin>>namjesten;
                        cout<<"Unesite kvadraturu: "; cin>>kvadratura;
                        try
                        {
                            Stan stan(adresa, sprat, broj_soba, namjesten, kvadratura);
                            stanovi.push_back(stan);
                            prodaje.DajProdaju(odaberi_prodaju-1).PromijeniStan(stan);
                            cout<<"Prodaja je uspjesno izmijenjena!"<<endl<<endl;
                            goto meni_prodaja;
                        }
                        catch(domain_error d1) {cout<<"Izuzetak: "<<d1.what();}
                        catch(range_error r1) {cout<<"Izuzetak: "<<r1.what();}      
                    }
                }
                else if(opcija3==5)
                {
                    cout<<"Unesite cijenu stana: "; cin>>cijena_stana;
                    prodaje.DajProdaju(odaberi_prodaju-1).PromijeniCijenuProdaje(cijena_stana);
                    cout<<"Prodaja je uspjesno izmijenjena!"<<endl<<endl;
                    goto meni_prodaja;
                }
            }
            else if(opcija2==3)
            {
                meni_ispisa:
                cout<<"Izaberite opciju:"<<endl<<" 0 - nazad"<<endl<<" 1 - ispis svih prodaja"<<endl;
                cout<<" 2 - ispis prodaja na datum"<<endl<<" 3 - ispis najranije prodaje"<<endl<<" 4 - ispis najskuplje prodaje"<<endl;
                cout<<" 5 - ispis broja prodaja"<<endl<<" 6 - ispis broja prodaja po datumu"<<endl<<" 7 - ispis broja prodaja po agentu"<<endl<<" 8 - kraj"<<endl;
                cin>>opcija3;
                if(opcija3==0) {goto meni_prodaja;}
                else if(opcija3==1)
                {
                    prodaje.IspisiSveProdaje();
                    goto meni_ispisa;
                }
                else if(opcija3==2)
                {
                    cout<<"Unesite datum (d/m/g): "; string unos_datuma; cin>>unos_datuma; NapraviDatum(unos_datuma, dan, mjesec, godina);
                    cout<<"Prodaje na datum "<<dan<<"/"<<mjesec<<"/"<<godina<<" su:"<<endl;
                    prodaje.IspisiProdajeNaDatum({dan, mjesec, godina});
                    goto meni_ispisa;
                }
                else if(opcija3==3)
                {
                    prodaje.DajNajranijuProdaju().Ispisi(); cout<<endl<<endl;
                    goto meni_ispisa;
                }
                else if(opcija3==4)
                {
                    prodaje.DajNajskupljuProdaju().Ispisi(); cout<<endl<<endl;
                    goto meni_ispisa;
                }
                else if(opcija3==5)
                {
                    cout<<"Broj prodaja: "<<prodaje.DajBrojProdaja()<<endl<<endl;
                }
                else if(opcija3==6)
                {
                    cout<<"Unesite datum (d/m/g): "; string unos_datuma; cin>>unos_datuma; NapraviDatum(unos_datuma, dan, mjesec, godina);
                    cout<<"Broj prodaja na uneseni datum: "<<prodaje.DajBrojProdajaNaDatum({dan, mjesec, godina});
                    goto meni_ispisa;
                }
                else if(opcija3==7)
                {
                    getline(cin, ime_agenta);
                    cout<<"Unesite ime agenta: "; getline(cin, ime_agenta);
                    cout<<"Broj prodaja unesenog agenta: "<<prodaje.DajBrojProdajaOdAgenta(ime_agenta);
                    goto meni_ispisa;
                }
                else if(opcija3==8){goto kraj;}
            }
            else if(opcija2==4)
            {
                cout<<"Izaberite opciju: "<<endl<<" 0 - nazad"<<endl<<" 1 - brisanje najranije prodaje"<<endl<<" 2 - brisanje prodaja agenta"<<endl;
                cout<<" 3 - brisanje prodaja po datumu"<<endl<<" 4 - brisanje svih prodaja"<<endl;
                cin>>opcija3;
                if(opcija3==0) {goto meni_prodaja;}
                else if(opcija3==1)
                {
                    try
                    {   prodaje.ObrisiNajranijuProdaju();
                        cout<<"Obrisana najranija je obrisana!"<<endl<<endl;
                        goto meni_prodaja;
                    }
                    catch(range_error rr) {cout<<"Izuzetak: "<<rr.what()<<endl<<endl;}
                }
                else if(opcija3==2)
                {
                    getline(cin, ime_agenta);
                    cout<<"Unesite ime agenta: "; getline(cin, ime_agenta);
                    prodaje.ObrisiProdajeAgenta(ime_agenta);
                    cout<<"Sve prodaje tog agenta su obrisane."<<endl<<endl;
                    goto meni_prodaja;
                }
                else if(opcija3==3)
                {
                    cout<<"Unesite datum (d/m/g): "; string unos_datuma; cin>>unos_datuma; NapraviDatum(unos_datuma, dan, mjesec, godina);
                    prodaje.ObrisiProdajeNaDatum({dan, mjesec, godina});
                    cout<<"Sve prodaje na taj datum su obrisane."<<endl<<endl;
                    goto meni_prodaja;
                }
                else if(opcija3==4)
                {
                    prodaje.IsprazniKolekciju();
                    cout<<"Sve prodaje su obrisane."<<endl<<endl;
                    goto meni_prodaja;
                }
            }
            else if(opcija2==5) {goto kraj;}
        }
    }
    kraj:
    cout<<endl<<endl<<"Dovidjenja!";
    
	return 0;
}