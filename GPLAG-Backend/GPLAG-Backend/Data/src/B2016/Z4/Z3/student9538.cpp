/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <string>
#include <algorithm>

using namespace std;


class Datum
{
    int dan,mjesec,godina;
    
    public:
    Datum(int dan,int mjesec,int godina)
    {
        int niz[12]={31,28,31,30,31,30,30,31,30,31,30,31};
        if(godina%4==0 && godina%100!=0 && godina%400==0) niz[1]++;
        
        
        if(dan>niz[mjesec-1] || mjesec<0 || mjesec>12 || dan<0) throw domain_error("Neispravan datum");
        
        Datum::dan=dan;
        Datum::mjesec=mjesec;
        Datum::godina=godina;
    }
    void Postavi(int dan,int mjesec,int godina)
    {
        int niz[12]={31,28,31,30,31,30,30,31,30,31,30,31};
        if(godina%4==0 && godina%100!=0 && godina%400==0) niz[1]++;
        
        
        if(dan>niz[mjesec-1] || mjesec<0 || mjesec>12 || dan<0) throw domain_error("Neispravan datum");
        
        Datum::dan=dan;
        Datum::mjesec=mjesec;
        Datum::godina=godina;
    }
    int DajDan()const{return dan;}
    int DajMjesec()const{return mjesec;}
    int DajGodinu()const{return godina;}
    void Ispisi()const
    {
        cout<<dan<<"/"<<mjesec<<"/"<<godina;
    }
    
};

class Kupac
{
    string ime;
    Datum datum;
    
    char ToUpper(char s)
    {
        if(s>='a' && s<='z')
            s-=32;
        return s;
    }
    
    public:
    Kupac(const std::string &ime_i_prezime,const Datum &datum_rodjenja):datum(datum_rodjenja.DajDan(),datum_rodjenja.DajMjesec(),datum_rodjenja.DajGodinu())
    {
        for(int i=0;i<ime_i_prezime.size();i++)
        {
            if((ToUpper(ime_i_prezime[i])<'A' || ToUpper(ime_i_prezime[i])>'Z') && ime_i_prezime[i]!=' ')
                throw domain_error("Neispravno ime i prezime");
        }
        ime=ime_i_prezime;
    }
    void Postavi(const std::string &ime_i_prezime,const Datum &datum_rodjenja)
    {
        for(int i=0;i<ime_i_prezime.size();i++)
        {
            if((ToUpper(ime_i_prezime[i])<'A' || ToUpper(ime_i_prezime[i])>'Z') && ime_i_prezime[i]!=' ')
                throw domain_error("Neispravno ime i prezime");
        }
        ime=ime_i_prezime;
        datum.Postavi(datum_rodjenja.DajDan(),datum_rodjenja.DajMjesec(),datum_rodjenja.DajGodinu());

    }
    std::string DajImePrezime()const{return ime;}
    Datum DajDatumRodjenja() const{return datum;}
    void Ispisi() const
    {
        cout<<ime<<"(";
        datum.Ispisi();
        cout<<")";
    }
    
};

class Stan
{
    string adresa;
    int sprat,broj_soba;
    bool namjesten;
    double kvadratura;
    
    public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten,double kvadratura)
    {
        if(sprat<0 || broj_soba<0 || kvadratura<0) throw domain_error("Neispravan unos podataka");
        Stan::adresa=adresa;
        Stan::sprat=sprat;
        Stan::broj_soba=broj_soba;
        Stan::namjesten=namjesten;
        Stan::kvadratura=kvadratura;
    }
    void Postavi(const std::string &adresa, int sprat, int broj_soba,bool namjesten, double kvadratura)
    {
        if(sprat<0 || broj_soba<0 || kvadratura<0) throw domain_error("Neispravan unos podataka");
        Stan::adresa=adresa;
        Stan::sprat=sprat;
        Stan::broj_soba=broj_soba;
        Stan::namjesten=namjesten;
        Stan::kvadratura=kvadratura;
    }
    std::string DajAdresu() const
    {
        return adresa;
    }
    int DajSprat() const
    {
        return sprat;
    }
    int DajBrojSoba() const
    {
        return broj_soba;
    }
    bool DajNamjesten() const
    {
        return namjesten;
    }
    double DajKvadraturu() const
    {
        return kvadratura;
    }
    void Ispisi() const
    {
        cout<<"Stan se nalazi na adresi "<<adresa<<" na "<<sprat<<". spratu i ima "<<broj_soba<<" soba."<<endl;
        cout<<"Kvadratura stana je "<<kvadratura<<" (m^2) i ";
        if(namjesten) cout<<"stan je namjesten.";
        else cout<<"stan nije namjesten.";
    }

};

class Prodaja
{
  string ime_agenta;
  double cijena;
  Datum d;Kupac k;Stan s;
  
  char ToUpper(char s)
    {
        if(s>='a' && s<='z')
            s-=32;
        return s;
    }
    
  
  public:
      Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,const Datum &datum_prodaje, const Kupac &kupac_stana,
     const Stan &kupljeni_stan):d(datum_prodaje),k(kupac_stana),s(kupljeni_stan)
     {   
         for(int i=0;i<ime_agenta_prodaje.size();i++)
        {
            if((ToUpper(ime_agenta_prodaje[i])<'A' || ToUpper(ime_agenta_prodaje[i])>'Z') && ime_agenta_prodaje[i]!=' ')
                throw domain_error("Neispravno ime i prezime");
        }
         ime_agenta=ime_agenta_prodaje;
         cijena=cijena_stana;
     }
     
      Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
     std::string &ime_kupca, const Datum &datum_rodjenja_kupca,
     const std::string &adresa_stana, int sprat_stana, int broj_soba,
     bool namjesten_stan, double broj_kvadrata):d(dan_prodaje,mjesec_prodaje,godina_prodaje),k(ime_kupca,datum_rodjenja_kupca),s(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata)
     {
         for(int i=0;i<ime_agenta_prodaje.size();i++)
        {
            if((ToUpper(ime_agenta_prodaje[i])<'A' || ToUpper(ime_agenta_prodaje[i])>'Z') && ime_agenta_prodaje[i]!=' ')
                throw domain_error("Neispravno ime i prezime");
        }
         ime_agenta=ime_agenta_prodaje;
         cijena=cijena_stana;
     }
     void PromijeniKupca(const Kupac &novi_kupac)
     {
         k.Postavi(novi_kupac.DajImePrezime(),novi_kupac.DajDatumRodjenja());
     }
     void PromijeniStan(const Stan &novi_stan)
     {
         s.Postavi(novi_stan.DajAdresu(),novi_stan.DajSprat(),novi_stan.DajBrojSoba(),novi_stan.DajNamjesten(),novi_stan.DajKvadraturu());
     }
     void PromijeniDatumKupovine(const Datum &novi_datum)
     {
         d.Postavi(novi_datum.DajDan(),novi_datum.DajMjesec(),novi_datum.DajGodinu());
     }
     void PromijeniCijenuProdaje(const double &nova_cijena)
     {
         cijena=nova_cijena;
     }
     
     void PomjeriDanUnaprijed()
     {
        int niz[12]={31,28,31,30,31,30,30,31,30,31,30,31};
        if(d.DajGodinu()%4==0 && d.DajGodinu()%100!=0 && d.DajGodinu()%400==0) niz[1]++;
        
        if(d.DajDan()==niz[d.DajMjesec()-1] && d.DajMjesec()<12) d.Postavi(1,d.DajMjesec()+1,d.DajGodinu());
        else if(d.DajDan()==niz[d.DajMjesec()-1] && d.DajMjesec()==12) d.Postavi(1,1,d.DajGodinu()+1);
        else d.Postavi(d.DajDan()+1,d.DajMjesec(),d.DajGodinu());
     }
     void PomjeriDanUnazad()
     {
         
        int niz[12]={31,28,31,30,31,30,30,31,30,31,30,31};
        if(d.DajGodinu()%4==0 && d.DajGodinu()%100!=0 && d.DajGodinu()%400==0) niz[1]++;
        
        if(d.DajDan()==1 && d.DajMjesec()>1) d.Postavi(niz[d.DajMjesec()-2],d.DajMjesec()-1,d.DajGodinu());
        else if(d.DajDan()==1 && d.DajMjesec()==1) d.Postavi(niz[11],12,d.DajGodinu()-1);
        else d.Postavi(d.DajDan()-1,d.DajMjesec(),d.DajGodinu());
     }
     
     std::string DajImeAgenta() const
     {
         return ime_agenta;
     }
     std::string DajImeKupca() const
     {
         return k.DajImePrezime();
     }
     Datum DajDatumProdaje() const
     {
         return d;
     }
     double DajCijenuStana() const
     {
         return cijena;
     }
    
     friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
     friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
     
     void Ispisi() const
     {
         cout<<"Ime agenta: "; cout<<ime_agenta; cout<<endl;
         cout<<"Ime kupca: "; k.Ispisi(); cout<<endl;
         cout<<"Zakazani datum prodaje: ";d.Ispisi(); cout<<endl;
         cout<<"Cijena stana: "<<cijena; cout<<endl;
         cout<<"Informacije o stanu: "<<endl;
         s.Ispisi();
     }
};

class Prodaje
{
  int trenutno,max_prodaja;
  Prodaja **prod;
  
  public:
  explicit Prodaje(int max_broj_prodaja)
  {
      trenutno=0;
      max_prodaja=max_broj_prodaja;
      
      prod=new Prodaja *[max_prodaja];
  }
  Prodaje(std::initializer_list<Prodaja> spisak_prodaja)
  {
      trenutno=spisak_prodaja.size();
      max_prodaja=100;
      
      prod=new Prodaja *[max_prodaja];
      
      auto j=spisak_prodaja.begin();
      for(int i=0;i<trenutno;i++){
        prod[i]=new Prodaja(*j);j++;
      }
      
  }
  ~Prodaje()
  {
      for(int i=0;i<trenutno;i++)
        delete prod[i];
        delete[] prod;
    
  }
    Prodaje(const Prodaje &prodaje)
    {
        trenutno=prodaje.trenutno;
        max_prodaja=prodaje.max_prodaja;
        
        prod=new Prodaja*[max_prodaja];
        
        for(int i=0;i<trenutno;i++)
            prod[i]=new Prodaja(*prodaje.prod[i]);
    }
    Prodaje(Prodaje &&prodaje)
    {
        trenutno=prodaje.trenutno;
        max_prodaja=prodaje.max_prodaja;
        
        prod=new Prodaja*[max_prodaja];
        
        for(int i=0;i<trenutno;i++)
            prod[i]=prodaje.prod[i];
    }
    Prodaje &operator =(const Prodaje &prodaje)
    {
        if(this==&prodaje) return *this;
        
        for(int i=0;i<trenutno;i++)
                delete prod[i];
        delete[] prod;
        
        trenutno=prodaje.trenutno;
        max_prodaja=prodaje.max_prodaja;
        
        prod=new Prodaja*[max_prodaja];
        
        for(int i=0;i<trenutno;i++)
            prod[i]=new Prodaja(*prodaje.prod[i]);
        
        return *this;
    }
    Prodaje &operator =(Prodaje &&prodaje)
    {
        if(this==&prodaje) return *this;
        
        for(int i=0;i<trenutno;i++)
                delete prod[i];
        delete[] prod;
        
        trenutno=prodaje.trenutno;
        max_prodaja=prodaje.max_prodaja;
        
        prod=new Prodaja*[max_prodaja];
        
        for(int i=0;i<trenutno;i++)
            prod[i]=prodaje.prod[i];
        
        return *this;
        
    }
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje,
     double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,
    const Stan &kupljeni_stan)
    {
        if(trenutno<max_prodaja)
        prod[trenutno++]=new Prodaja(ime_agenta_prodaje,cijena_stana,datum_prodaje,kupac_stana,kupljeni_stan);
        else throw range_error("Dostignut maksimalni broj prodaja");
    }
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana ,int dan_prodaje,
    int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
     const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,
     int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata)
     {
            Datum d(dan_prodaje,mjesec_prodaje,godina_prodaje);
            Kupac k(ime_kupca,datum_rodjenja_kupca);
            Stan s(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata);
            RegistrirajProdaju(ime_agenta_prodaje,cijena_stana,d,k,s);
     }
    void RegistrirajProdaju(Prodaja *prodaja)
    {
        if(trenutno<max_prodaja)
        {
            prod[trenutno++]=new Prodaja(*prodaja);
            delete prodaja;
        }
        else throw range_error("Dostignut maksimalni broj prodaja");
    }
    int DajBrojProdaja() const
    {
        return trenutno;
    }
    
    int DajBrojProdajaNaDatum(const Datum &datum) const
    {
      return count_if(prod,prod+trenutno,[datum](Prodaja *p){if(p->DajDatumProdaje().DajDan()==datum.DajDan() && p->DajDatumProdaje().DajMjesec()==datum.DajMjesec() && p->DajDatumProdaje().DajGodinu()==datum.DajGodinu()) return true;return false;});

    }
    int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const
    {
        return count_if(prod,prod+trenutno,[ime_agenta](Prodaja *p){if(p->DajImeAgenta()==ime_agenta) return true;return false;});
    }
   
    Prodaja &DajNajranijuProdaju();
    Prodaja DajNajranijuProdaju() const;
    Prodaja &DajNajskupljuProdaju();
    Prodaja DajNajskupljuProdaju() const;
   
    void IsprazniKolekciju()
    {
        for(int i=0;i<trenutno;i++)
            delete prod[i];
        trenutno=0;
    }
    void ObrisiNajranijuProdaju();
    void ObrisiProdajeAgenta(const std::string &ime_agenta)
    {
        for(int i=0;i<trenutno;i++)
        {
            if(prod[i]->DajImeAgenta()==ime_agenta)
            {
                delete prod[i];
                for(int j=i;j<trenutno-1;j++)
                    prod[j]=prod[j+1];
                trenutno--;
                i--;
            }
        }
    }
    void ObrisiProdajeNaDatum(const Datum &datum)
    {
        for(int i=0;i<trenutno;i++)
        {
            if(prod[i]->DajDatumProdaje().DajDan()==datum.DajDan() && prod[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec() && prod[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu())
            {
                delete prod[i];
                for(int j=i;j<trenutno-1;j++)
                    prod[j]=prod[j+1];
                trenutno--;
                i--;
            }
        }
    }
    void IspisiProdajeNaDatum(const Datum &datum) const
    {
        for(int i=0;i<trenutno;i++)
        {
            if(prod[i]->DajDatumProdaje().DajDan()==datum.DajDan() && prod[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec() && prod[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu())
            {
                prod[i]->Ispisi();
                cout<<endl;
            }
        }
    }
    
    void IspisiSveProdaje() const
    {
        for(int i=0;i<trenutno;i++){
            prod[i]->Ispisi();cout<<endl;
            
        }
    }

};



int main ()
{
	return 0;
}