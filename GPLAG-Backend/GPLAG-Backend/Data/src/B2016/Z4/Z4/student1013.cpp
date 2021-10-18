/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <memory>

using namespace std;


class Datum
{
    int dan,mjesec,godina;
     
     
     int VratiDane()const
    {
        int niz[12]={31,28,31,30,31,30,30,31,30,31,30,31};
        int suma=0;
        for(int i=2000;i<godina;i++)
        {
            if(i%4==0 && i%100!=0 && i%400==0)
                suma+=366;
            else suma+=365;
        }
        for(int i=0;i<mjesec;i++)
            suma+=niz[i];
            
        return suma+dan;
    }
    
      
    public:
    Datum(int dan=1, int mjesec=1, int godina=1900){Postavi(dan,mjesec,godina);};
    void Postavi(int dan, int mjesec, int godina)
    {
        Datum::dan=dan;
        Datum::mjesec=mjesec;
        Datum::godina=godina;
        
    }
    int DajDan() const {return dan;}
    int DajMjesec() const{return mjesec;}
    int DajGodinu() const{return godina;}
    void Ispisi() const
    {
        cout<<dan<<"/"<<mjesec<<"/"<<godina;
    }

};

class Kupac
{
    string ime;
    Datum d;
    
    public:
    Kupac(const std::string &ime_i_prezime="", const Datum &datum_rodjenja=0){Postavi(ime_i_prezime,datum_rodjenja);};
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja)
    {
        ime=ime_i_prezime;
        d=datum_rodjenja;   
    }
    std::string DajImePrezime() const{return ime;}
    Datum DajDatumRodjenja() const{return d;}
    void Ispisi() const
    {
        cout<<ime<<"(";d.Ispisi();cout<<")";
    }

};

class Stan
{
    string adresa;
    int sprat,broj;
    bool namjesten;
    double kvad;
    
    public:
    Stan(const std::string &adresa="", int sprat=0, int broj_soba=0, bool namjesten=0, double kvadratura=0){Postavi(adresa,sprat,broj_soba,namjesten,kvadratura);};
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura)
    {
        Stan::adresa=adresa;
        Stan::sprat=sprat;
              broj=broj_soba;
        Stan::namjesten=namjesten;
              kvad=kvadratura;
    }
    std::string DajAdresu() const{return adresa;}
    int DajSprat() const {return sprat;}
    int DajBrojSoba() const {return broj;}
    bool DajNamjesten() const{return namjesten;}
    double DajKvadraturu() const {return kvad;}
    void Ispisi() const
    {
        cout<<"Stan se nalazi na adresi "<<adresa<<" na "<<sprat<<". spratu i ima "<<broj<<" soba."<<endl;
        cout<<"Kvadratura stana je "<<kvad<<" (m^2) i ";
        if(namjesten) cout<<"stan je namjesten.";
        else cout<<"stan nije namjesten.";
        cout<<endl;
    }

};

class Prodaja
{
    string ime;
    double cijena;
    Datum d;
    Kupac k;
    Stan s;
    
    int VratiDane()const
    {
        int niz[12]={31,28,31,30,31,30,30,31,30,31,30,31};
        int suma=0;
        for(int i=2000;i<d.DajGodinu();i++)
        {
            if(i%4==0 && i%100!=0 && i%400==0)
                suma+=366;
            else suma+=365;
        }
        for(int i=0;i<d.DajMjesec();i++)
            suma+=niz[i];
            
        return suma+d.DajDan();
    }
    
    
    public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,const Datum &datum_prodaje, const Kupac &kupac_stana,const Stan &kupljeni_stan)
    {
        ime=ime_agenta_prodaje;
        cijena=cijena_stana;
        d=datum_prodaje;
        k=kupac_stana;
        s=kupljeni_stan;
    }
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
    std::string &ime_kupca, const Datum &datum_rodjenja_kupca,
    const std::string &adresa_stana, int sprat_stana, int broj_soba,
    bool namjesten_stan, double broj_kvadrata)
    {
        ime=ime_agenta_prodaje;
        cijena=cijena_stana;
        d.Postavi(dan_prodaje,mjesec_prodaje,godina_prodaje);
        k.Postavi(ime_kupca,datum_rodjenja_kupca);
        s.Postavi(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata);
    }
    void PromijeniKupca(const Kupac &novi_kupac)
    {
        k=novi_kupac;
    }
    void PromijeniStan(const Stan &novi_stan)
    {
        s=novi_stan;
    }
    void PromijeniDatumKupovine(const Datum &novi_datum)
    {
        d=novi_datum;
    }
    void PromijeniCijenuProdaje(const double &nova_cijena)
    {
        cijena=nova_cijena;
    }
    
    void PomjeriDanUnaprijed()
    {
        d.Postavi(d.DajDan()+1,d.DajMjesec(),d.DajGodinu());
    }
    void PomjeriDanUnazad()
    {
         d.Postavi(d.DajDan()-1,d.DajMjesec(),d.DajGodinu());
    }
    std::string DajImeAgenta() const
    {
        return ime;
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
    
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2)
    {
        return p1.VratiDane()<p2.VratiDane();
    }
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2)
    {
        return p1.DajCijenuStana()>p2.DajCijenuStana();
    }
    
    void Ispisi() const
    {
        cout<<"Ime agenta: "<<ime<<endl;
        cout<<"Ime kupca: ";k.Ispisi();cout<<endl;
        cout<<"Zakazani datum prodaje: ";d.Ispisi();cout<<endl;
        cout<<"Cijena stana "<<cijena<<endl;
        cout<<"Informacije o stanu "<<endl;
        s.Ispisi();
    }

    
};

class Prodaje
{
    int stanje;
    vector<shared_ptr<Prodaja>> pok;
    
    public:
    explicit Prodaje()
    {   
        stanje=0;
    }
    
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja)
    {
        stanje=spisak_prodaja.size();
        
        auto it=spisak_prodaja.begin();
        for(int i=0;i<stanje;i++)
        {
            pok.push_back(make_shared<Prodaja>(*it));
            it++;
        }
        
    }
    ~Prodaje()
    {
        for(int i=0;i<stanje;i++)
             pok[i]=nullptr;
        stanje=0;
    }
    
    Prodaje(const Prodaje &prodaje)
    {
        stanje=prodaje.stanje;
        for(int i=0;i<stanje;i++)
            pok.push_back((prodaje.pok[i]));
    }
    
    Prodaje(Prodaje &&prodaje)
    {
        stanje=prodaje.stanje;
       
        pok=prodaje.pok;
        
    }
    Prodaje &operator =(const Prodaje &prodaje)
    {
        if(this!=&prodaje)
        {
            
            for(int i=0;i<stanje;i++)
                     pok[i]=nullptr;
            
            
            stanje=prodaje.stanje;
            
        for(int i=0;i<stanje;i++)
            pok.push_back((prodaje.pok[i]));     
        }
        return *this;
    }
    Prodaje &operator =(Prodaje &&prodaje)
    {
        if(this!=&prodaje)
        {
            
            for(int i=0;i<stanje;i++)
                      pok[i]=nullptr;
            
            
            stanje=prodaje.stanje;
        
        for(int i=0;i<stanje;i++)
            pok.push_back((prodaje.pok[i]));     
        
        }
        return *this;
    }
    
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,const Stan &kupljeni_stan)
    {
        pok.push_back(make_shared<Prodaja>(ime_agenta_prodaje,cijena_stana,datum_prodaje,kupac_stana,kupljeni_stan));
        stanje++;
        
    }
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana, int dan_prodaje,int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
     const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata)
     {
         pok.push_back(make_shared<Prodaja>(ime_agenta_prodaje,cijena_stana,dan_prodaje,mjesec_prodaje,godina_prodaje,ime_kupca,datum_rodjenja_kupca,adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata));
         stanje++;
         
     }
    void RegistrirajProdaju(shared_ptr<Prodaja> prodaja)
    {  
        pok.push_back((prodaja));
        stanje++;
        
    }
    int DajBrojProdaja() const
    {
        return stanje;
    }
    
    int DajBrojProdajaNaDatum(const Datum &datum) const
    {
        int br=0;
                
        br=count_if(pok.begin(),pok.end(),[&datum](shared_ptr<Prodaja> p1){if(p1->DajDatumProdaje().DajDan()==datum.DajDan() && p1->DajDatumProdaje().DajMjesec()==datum.DajMjesec()
        && p1->DajDatumProdaje().DajGodinu()==datum.DajGodinu()) return true;}); 
        
        return br;
    }
    int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const
    {
        int br=0;
        for(int i=0;i<stanje;i++)
        {
            if(ime_agenta==pok[i]->DajImeAgenta()) br++;
        }
        return br;
    }
    
    Prodaja &DajNajranijuProdaju();
    Prodaja DajNajranijuProdaju() const;
    Prodaja &DajNajskupljuProdaju();
    Prodaja DajNajskupljuProdaju() const;
    
    void IsprazniKolekciju()
    {
        for(int i=0;i<stanje;i++)
               pok[i]=nullptr;
       
    
        stanje=0;
        
    }
    
    void ObrisiNajranijuProdaju();
    void ObrisiProdajeAgenta(const std::string &ime_agenta); 
    void ObrisiProdajeNaDatum(const Datum &datum);
    void IspisiProdajeNaDatum(const Datum &datum) const;
    
    void IspisiSveProdaje() const
    {
        for(int i=0;i<stanje;i++)
             pok[i]->Ispisi();
    }

};


int main ()
{   
    cout<<"Dobrodosli!"<<endl<<endl<<endl;
	
	Prodaje p;vector<Stan>v;
	for(;;)
	{
	    cout<<"Izaberite opciju:"<<endl;
	    cout<<"0 - kraj"<<endl;
	    cout<<"1 - uredjivanje stanova"<<endl;
	    cout<<"2 - uredjivanje kupaca"<<endl;
	    cout<<"3 - uradjivanje prodaja"<<endl;
	    
	    int n;
	    cin>>n;
	    
	    if(n==0) break;
	    else if(n==1)
	    {   
	        for(;;)
	        {
    	        cout<<"Izaberite opciju: "<<endl;
    	        cout<<"0 - nazad"<<endl;
    	        cout<<"1 - dodavanje stana"<<endl;
    	        cout<<"2 - uredjivanje stanova"<<endl;
    	        cout<<"3 - ispis svih stanova"<<endl;
    	        cout<<"4 - kraj"<<endl;
    	        
    	        int n1;
    	        cin>>n1;
    	        if(n1==4) return 0;
    	        else if(n1==0) break;
    	        else if(n1==1)
    	        {
    	            string s;int sprat;int br;bool namjesten;double kvad;
    	            cout<<"Unesite adresu: ";
    	            getline(cin,s);
    	            cout<<"Unesite sprat: ";
    	            cin>>sprat;
    	            cout<<"Unesite broj soba: ";
    	            cin>>br;
    	            cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
    	            cin>>namjesten;
    	            cout<<"Unesite kvadraturu: ";
    	            cin>>kvad;
    	            
    	            Stan apar(s,sprat,br,namjesten,kvad);
    	            v.push_back(apar);
    	        }
    	        else if(n1==2)
    	        {
    	            cout<<"Odaberite polje koje zelite urediti:"<<endl;
    	            cout<<" 0 - nazad"<<endl;
    	            cout<<" 1 - adresa"<<endl;
    	            cout<<" 2 - sprat"<<endl;
    	            cout<<" 3 - broj soba"<<endl;
    	            cout<<" 4 - da li je stan namjesten"<<endl;
    	            cout<<" 5 - kvadratura"<<endl;
    	            cout<<" 6 - sve"<<endl;
    	            int n2;
    	            cin>>n2;
    	            
    	           
    	            
    	            
    	            if(n2==0) continue;
    	            else if(n2==1)
    	            {
    	                   
    	            }
    	            
    	            
    	        }
	        }     
	        
	    }
	}
	
	
	
	return 0;
}