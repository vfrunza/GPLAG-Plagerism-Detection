#include <iostream>
#include <algorithm>
#include <stdexcept>

bool DaLiJeGodinaPrestupna(int godina) {
    bool jes=false;
    if(godina%4==0) {
        if(godina%100==0 && godina%400==0) jes=true;
        else if (godina%100==0) jes=false;
        else jes=true;
    }
    else jes=false;
    return jes;
}

class Datum {
    int dan,mjesec,godina;
public:

    Datum () {
        dan=1; mjesec=1; godina=0;
    }
    Datum(int dan, int mjesec, int godina) {
         if(!(dan>0 && dan<=31 && mjesec>0 && mjesec<=12 && godina>=0)) throw std::domain_error("Neispravan datum");
        switch(mjesec) {
            case 4: case 6: case 9: case 11:
            if(dan>30) throw std::domain_error("Neispravan datum"); break;
            case 2:
            if(DaLiJeGodinaPrestupna(godina)) {
                if(dan>29) throw std::domain_error("Neispravan datum");
            }
                else if (dan>28) throw std::domain_error("Neispravan datum");
        }
        this->dan=dan; this->mjesec=mjesec; this->godina=godina;
    }
    void Postavi(int dan, int mjesec, int godina){
        if(!(dan>0 && dan<=31 && mjesec>0 && mjesec<=12 && godina>=0)) throw std::domain_error("Neispravan datum");
        switch(mjesec) {
            case 4: case 6: case 9: case 11:
            if(dan>30) throw std::domain_error("Neispravan datum"); break;
            case 2:
            if(DaLiJeGodinaPrestupna(godina)) {
                if(dan<29) throw std::domain_error("Neispravan datum");
            }
                else if (dan>28) throw std::domain_error("Neispravan datum");
        }
        this->dan=dan; this->mjesec=mjesec; this->godina=godina;
    }
    int DajDan() const {return dan;}
    int DajMjesec() const {return mjesec;}
    int DajGodinu() const {return godina;}
    void Ispisi() const { std::cout<<dan<<"/"<<mjesec<<"/"<<godina;}
};


class Kupac {
    std::string ime_i_prezime;
    Datum datum_rodjenja;
public:
    Kupac()
    {
        ime_i_prezime="";
        datum_rodjenja=Datum();
    }
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja) {
        for(int i=0;i<ime_i_prezime.length();i++) {
            if(!((ime_i_prezime[i]>='A' && ime_i_prezime[i]<='Z') || (ime_i_prezime[i]>='a' && ime_i_prezime[i]<='z') || (ime_i_prezime[i]>='0' && ime_i_prezime[i]<='9') || ime_i_prezime[i]=='-' || ime_i_prezime[i]==' ')) throw std::domain_error("Neispravno ime i prezime");

            
        }
        this->ime_i_prezime=ime_i_prezime; this->datum_rodjenja=datum_rodjenja;
    }
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja) {
        for(int i=0;i<ime_i_prezime.length();i++) {
            if(!((ime_i_prezime[i]>='A' && ime_i_prezime[i]<='Z') || (ime_i_prezime[i]>='a' && ime_i_prezime[i]<='z') || (ime_i_prezime[i]>='0'
            && ime_i_prezime[i]<='9') || ime_i_prezime[i]=='-' || ime_i_prezime[i]==' '))
            throw std::domain_error("Neispravno ime i prezime");

            //this->ime_i_prezime=ime_i_prezime; this->datum_rodjenja=datum_rodjenja;
        }
        this->ime_i_prezime=ime_i_prezime; this->datum_rodjenja=datum_rodjenja;
    }
    std::string DajImePrezime() const{return ime_i_prezime;}
    Datum DajDatumRodjenja() const {return datum_rodjenja;}
    void Ispisi() const {std::cout<<ime_i_prezime<<" ("<<datum_rodjenja.DajDan()<<"/"<<datum_rodjenja.DajMjesec()<<"/"<<datum_rodjenja.DajGodinu()<<")";}
};

class Stan {
    std::string adresa;
    int sprat,broj_soba;
    bool namjesten; double kvadratura;
public:
    Stan()
    {
        adresa="";
        sprat=0;
        broj_soba=0;
        namjesten=false;
        kvadratura=0;
    }
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
        if (sprat < 0 || broj_soba < 0 || kvadratura < 0)
            throw std::domain_error("Neispravan unos podataka");
        this->adresa = adresa;
        this->sprat = sprat;
        this->broj_soba = broj_soba;
        this->namjesten = namjesten;
        this->kvadratura = kvadratura;
    }
    void Postavi(const std::string &adresa, int sprat, int broj_soba,bool namjesten, double kvadratura) {
        if (sprat < 0 || broj_soba < 0 || kvadratura < 0)
            throw std::domain_error("Neispravan unos podataka");
        this->adresa = adresa;
        this->sprat = sprat;
        this->broj_soba = broj_soba;
        this->namjesten = namjesten;
        this->kvadratura = kvadratura;
    }
    std::string DajAdresu() const { return adresa; }
    int DajSprat() const {return sprat;}
    int DajBrojSoba() const {return broj_soba;}
    bool DajNamjesten() const {return namjesten;}
    double DajKvadraturu() const {return kvadratura;}
    void Ispisi() const {
        std::string slovo = "";
        if (broj_soba % 10 == 1) slovo = "u";
        else if (broj_soba % 10 == 2 || broj_soba % 10 == 3 || broj_soba % 10 == 4) slovo = "e";
        else slovo = "a";
        if(broj_soba==11 || broj_soba==12 || broj_soba==13 || broj_soba==14) slovo='a';
        std::string namjestenString = "";
        if (namjesten) namjestenString = "je";
        else namjestenString = "nije";

        std::cout << "Stan se nalazi na adresi " << DajAdresu() << " na " << DajSprat() << ". spratu i ima " << DajBrojSoba() << " sob" << slovo << ". " <<
        "Kvadratura stana je " << DajKvadraturu() << " (m^2) i stan " << namjestenString << " namjesten\n";

    }
};

class Prodaja {
    std::string ime_agenta_prodaje;
    double cijena_stana;
    Datum datum_prodaje;
    Kupac kupac_stana;
    Stan kupljeni_stan;

public:
    Prodaja()
    {
        ime_agenta_prodaje="";
        cijena_stana=0;
        datum_prodaje=Datum();
        kupac_stana=Kupac();
        kupljeni_stan=Stan();
    }
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,const Datum &datum_prodaje, const Kupac &kupac_stana,const Stan &kupljeni_stan) : kupac_stana(kupac_stana), kupljeni_stan(kupljeni_stan) {
        this->ime_agenta_prodaje=ime_agenta_prodaje;
        if(cijena_stana<0) throw std::domain_error("Neispravan unos podataka");
        else this->cijena_stana=cijena_stana;
        this->datum_prodaje=datum_prodaje;
        this->kupac_stana=kupac_stana;
        this->kupljeni_stan=kupljeni_stan;
    }

    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,int dan_prodaje, int mjesec_prodaje, int godina_prodaje,std::string &ime_kupca, const Datum &datum_rodjenja_kupca,const std::string &adresa_stana, int sprat_stana, int broj_soba,bool namjesten_stan, double broj_kvadrata) : kupac_stana(ime_kupca, datum_rodjenja_kupca), kupljeni_stan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata) {
        this->ime_agenta_prodaje = ime_agenta_prodaje;
        if(cijena_stana<0) throw std::domain_error("Neispravan unos podataka");
        else this->cijena_stana=cijena_stana;

    }
    void PromijeniKupca(const Kupac &novi_kupac) {
        kupac_stana = novi_kupac;
    };

    void PromijeniDatumKupovine(const Datum &novi_datum) {
        datum_prodaje = novi_datum;
    }

    void PromijeniStan(const Stan &novi_stan) {
        kupljeni_stan = novi_stan;
    }

    void PromijeniCijenuProdaje(const double &nova_cijena) {
        cijena_stana = nova_cijena;
    }

    void PomjeriDanUnaprijed() {
        int mjeseci[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (DaLiJeGodinaPrestupna(datum_prodaje.DajGodinu()))  mjeseci[1]++;
        int dan = datum_prodaje.DajDan();
        int mjesec = datum_prodaje.DajMjesec();
        int godina = datum_prodaje.DajGodinu();
        dan++;
        if (dan > mjeseci[mjesec - 1])  {
            dan = 1;
            mjesec++;
            if (mjesec > 12)  {
                mjesec = 1;
                godina++;
            }
        }

        datum_prodaje.Postavi(dan, mjesec, godina);

    }

    void PomjeriDanUnazad() {
        int mjeseci[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (DaLiJeGodinaPrestupna(datum_prodaje.DajGodinu()))  mjeseci[1]++;
        int dan = datum_prodaje.DajDan();
        int mjesec = datum_prodaje.DajMjesec();
        int godina = datum_prodaje.DajGodinu();

        dan--;
        if (dan < 1)  {
            mjesec--;
            dan = mjeseci[mjesec - 1];
            if (mjesec < 1)  {
                mjesec = 12;
                godina--;
            }
        }

        datum_prodaje.Postavi(dan, mjesec, godina);

    }

    std::string DajImeAgenta() const {
        return ime_agenta_prodaje;
    }

    std::string DajImeKupca() const {
        return kupac_stana.DajImePrezime();
    }

    Datum DajDatumProdaje() const {
        return datum_prodaje;
    }

    double DajCijenuStana() const {
        return cijena_stana;
    }

    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);

    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);

    void Ispisi() const;
};

bool ProdatPrije(const Prodaja &p1, const Prodaja &p2) {
    Datum d1 = p1.DajDatumProdaje();
    Datum d2 = p2.DajDatumProdaje();

    if (d1.DajGodinu() > d2.DajGodinu()) return true;
    else if (d1.DajGodinu() == d2.DajGodinu() && d1.DajMjesec() > d2.DajMjesec()) return true;
    else if (d1.DajGodinu() == d2.DajGodinu() && d1.DajMjesec() == d2.DajMjesec() && d1.DajDan() > d2.DajDan()) return true;

    return false;
}

bool SkupljiStan(const Prodaja &p1, const Prodaja &p2) {
    return p1.DajCijenuStana() > p2.DajCijenuStana();
}

void Prodaja::Ispisi() const {
    std::cout << "Ime agenta: " << ime_agenta_prodaje << std::endl;
    std::cout << "Ime kupca: " << kupac_stana.DajImePrezime() << std::endl;
    std::cout << "Zakazani datum prodaje: ";
    datum_prodaje.Ispisi();
    std::cout << std::endl;
    std::cout << "Cijena: " << cijena_stana << std::endl;
    std::cout << "Informacije o stanu: " << std::endl;
    kupljeni_stan.Ispisi();
}


class Prodaje {
    Prodaja** prodaje;
    int broj_prodaja, max_broj_prodaja;
public:
    explicit Prodaje(int max_broj_prodaja)
    {
        prodaje=new Prodaja*[max_broj_prodaja];
        for(int i(0);i<max_broj_prodaja;i++)
            prodaje[i]=nullptr;
        this->max_broj_prodaja=max_broj_prodaja;
        this->broj_prodaja=0;
    }
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja)
    {
        prodaje=new Prodaja*[spisak_prodaja.size()];
        broj_prodaja=spisak_prodaja.size();
        max_broj_prodaja=spisak_prodaja.size();

        auto pok=spisak_prodaja.begin();
        int i(0);
        while(pok!=spisak_prodaja.end())
        {
            prodaje[i]=new Prodaja(*pok);
            pok++; i++;
        }
    }
    ~Prodaje()
    {
        for(int i(0);i<max_broj_prodaja;i++)
        {
            delete prodaje[i];
        }
        
        delete [] prodaje;
    }
    Prodaje(const Prodaje &prodaje)
    {

        this->prodaje=new Prodaja*[prodaje.max_broj_prodaja];
        this->broj_prodaja=prodaje.broj_prodaja;
        this->max_broj_prodaja=prodaje.max_broj_prodaja;
        
        for(int i(0);i<this->max_broj_prodaja;i++)
            this->prodaje[i]=nullptr;

        for(int i(0);i<prodaje.broj_prodaja;i++)
        {
            this->prodaje[i] = new Prodaja(*prodaje.prodaje[i]);
        }
    }
    Prodaje(Prodaje &&prodaje)
    {
         this->prodaje=new Prodaja*[prodaje.max_broj_prodaja];
        this->broj_prodaja=prodaje.broj_prodaja;
        this->max_broj_prodaja=prodaje.max_broj_prodaja;
        
        for(int i(0);i<this->max_broj_prodaja;i++)
            this->prodaje[i]=nullptr;

        for(int i(0);i<prodaje.broj_prodaja;i++)
        {
            this->prodaje[i] = new Prodaja(*prodaje.prodaje[i]);
        }
    }
    Prodaje &operator =(const Prodaje &prodaje)
    {
        if(&prodaje==this) return *this;

        for(int i(0);i<this->max_broj_prodaja;i++)
            delete this->prodaje[i];
            
        delete [] this->prodaje;

        this->prodaje=new Prodaja*[prodaje.max_broj_prodaja];
        this->max_broj_prodaja=prodaje.max_broj_prodaja;
        this->broj_prodaja=prodaje.broj_prodaja;

        for(int i(0);i<prodaje.broj_prodaja;i++)
        {
            this->prodaje[i]= new Prodaja(*prodaje.prodaje[i]);
        }

        return *this;
    }
    Prodaje &operator =(Prodaje &&prodaje)
    {
         if(&prodaje==this) return *this;

        for(int i(0);i<this->max_broj_prodaja;i++)
            delete this->prodaje[i];
            
        delete [] this->prodaje;

        this->prodaje=new Prodaja*[prodaje.max_broj_prodaja];
        this->max_broj_prodaja=prodaje.max_broj_prodaja;
        this->broj_prodaja=prodaje.broj_prodaja;

        for(int i(0);i<prodaje.broj_prodaja;i++)
        {
            this->prodaje[i]= new Prodaja(*prodaje.prodaje[i]);
        }

        return *this;
    }
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,const Stan &kupljeni_stan)
     {

         Prodaja p(ime_agenta_prodaje,cijena_stana,datum_prodaje,kupac_stana,kupljeni_stan);
         if(broj_prodaja<max_broj_prodaja)
         {
             prodaje[broj_prodaja]=new Prodaja(p);
             broj_prodaja++;
         }else
         {
            throw std::range_error("Dostignut maksimalni broj prodaja");

         }
     }
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje,
    int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
     const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,
     int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata)
     {
         Prodaja p(ime_agenta_prodaje,cijena_stana,dan_prodaje,mjesec_prodaje,godina_prodaje,ime_kupca,datum_rodjenja_kupca,adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata);
         if(broj_prodaja<max_broj_prodaja)
         {
             prodaje[broj_prodaja]=new Prodaja(p);
             broj_prodaja++;
         }else
         {
            throw std::range_error("Dostignut maksimalni broj prodaja");

         }
     }
    void RegistrirajProdaju(Prodaja *prodaja)
    {
         if(broj_prodaja<max_broj_prodaja)
         {
             prodaje[broj_prodaja]=new Prodaja(*prodaja);
             broj_prodaja++;
         }else
         {
            throw std::range_error("Dostignut maksimalni broj prodaja");

         }
    }
    int DajBrojProdaja() const
    {
        return broj_prodaja;
    }
    int DajBrojProdajaNaDatum(const Datum &datum) const
    {
        int brojac(0);
        for(int i(0);i<broj_prodaja;i++)
        {
            if(prodaje[i]->DajDatumProdaje().DajDan()==datum.DajDan() && prodaje[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec() && prodaje[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu()) brojac++;
        }
        return brojac;
    }
    int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const
    {
        int brojac(0);
        for(int i(0);i<broj_prodaja;i++)
        {
            if(prodaje[i]->DajImeAgenta()==ime_agenta) brojac++;
        }
        
        return brojac;
    }
    
    Prodaja &DajNajranijuProdaju()
    {
        Datum najranija(prodaje[0]->DajDatumProdaje());
        
        for(int i(1);i<broj_prodaja;i++)
        {
            if(prodaje[i]->DajDatumProdaje().DajGodinu()<najranija.DajGodinu()) najranija=prodaje[i]->DajDatumProdaje();
            else if(prodaje[i]->DajDatumProdaje().DajGodinu() == najranija.DajGodinu())
            {
                if(prodaje[i]->DajDatumProdaje().DajMjesec()<najranija.DajMjesec()) najranija=prodaje[i]->DajDatumProdaje();
                else if(prodaje[i]->DajDatumProdaje().DajMjesec() == najranija.DajMjesec())
                {
                    if(prodaje[i]->DajDatumProdaje().DajDan()<najranija.DajDan()) najranija=prodaje[i]->DajDatumProdaje();
                }
            }
        }
        
        for(int i(0);i<broj_prodaja;i++)
            if(prodaje[i]->DajDatumProdaje().DajGodinu()==najranija.DajGodinu()
                && prodaje[i]->DajDatumProdaje().DajMjesec()==najranija.DajMjesec()
                && prodaje[i]->DajDatumProdaje().DajDan()==najranija.DajDan()) return *prodaje[i];
        return *prodaje[0];
    }
    Prodaja DajNajranijuProdaju() const
    {
        Datum najranija(prodaje[0]->DajDatumProdaje());
        
        for(int i(1);i<broj_prodaja;i++)
        {
            if(prodaje[i]->DajDatumProdaje().DajGodinu()<najranija.DajGodinu()) najranija=prodaje[i]->DajDatumProdaje();
            else if(prodaje[i]->DajDatumProdaje().DajGodinu() == najranija.DajGodinu())
            {
                if(prodaje[i]->DajDatumProdaje().DajMjesec()<najranija.DajMjesec()) najranija=prodaje[i]->DajDatumProdaje();
                else if(prodaje[i]->DajDatumProdaje().DajMjesec() == najranija.DajMjesec())
                {
                    if(prodaje[i]->DajDatumProdaje().DajDan()<najranija.DajDan()) najranija=prodaje[i]->DajDatumProdaje();
                }
            }
        }
        
        for(int i(0);i<broj_prodaja;i++)
            if(prodaje[i]->DajDatumProdaje().DajGodinu()==najranija.DajGodinu()
                && prodaje[i]->DajDatumProdaje().DajMjesec()==najranija.DajMjesec()
                && prodaje[i]->DajDatumProdaje().DajDan()==najranija.DajDan()) return *prodaje[i];
        return *prodaje[0];
    }
    Prodaja &DajNajskupljuProdaju()
    {
        double najskuplja(prodaje[0]->DajCijenuStana());
        
        for(int i(1);i<broj_prodaja;i++)
            if(prodaje[i]->DajCijenuStana()>najskuplja) najskuplja=prodaje[i]->DajCijenuStana();
            
        for(int i(0);i<broj_prodaja;i++)
            if(prodaje[i]->DajCijenuStana() == najskuplja) return *prodaje[i];
        
        return *prodaje[0];
    }
    Prodaja DajNajskupljuProdaju() const
    {
        double najskuplja(0);
        
        for(int i(0);i<broj_prodaja;i++)
            if(prodaje[i]->DajCijenuStana()>najskuplja) najskuplja=prodaje[i]->DajCijenuStana();
            
        for(int i(0);i<broj_prodaja;i++)
            if(prodaje[i]->DajCijenuStana() == najskuplja) return *prodaje[i];
        
        return *prodaje[0];
    }
    void IsprazniKolekciju()
    {
        for(int i(0);i<max_broj_prodaja;i++)
        {
            delete prodaje[i];
            prodaje[i]=nullptr;
        }
        
        delete [] prodaje;
        
        prodaje=nullptr;
    }
    void ObrisiNajranijuProdaju()
    {
        if(broj_prodaja==0) throw std::range_error ("Prazna kolekcija");
        Prodaja najranija=*std::min_element(prodaje[0],prodaje[broj_prodaja],[](Prodaja pr1, Prodaja pr2){
            if(pr1.DajDatumProdaje().DajGodinu()<pr2.DajDatumProdaje().DajGodinu()) return false;
            else if(pr1.DajDatumProdaje().DajGodinu()==pr2.DajDatumProdaje().DajGodinu()== pr2.DajDatumProdaje().DajGodinu() && pr1.DajDatumProdaje().DajMjesec()<pr1.DajDatumProdaje().DajMjesec()) return true;
            else if(pr1.DajDatumProdaje().DajGodinu()==pr2.DajDatumProdaje().DajGodinu()== pr2.DajDatumProdaje().DajGodinu() && pr1.DajDatumProdaje().DajMjesec()==pr1.DajDatumProdaje().DajMjesec() && pr1.DajDatumProdaje().DajDan()<pr2.DajDatumProdaje().DajDan()) return true;
            else return false;
        });
        for(int i=0;i<broj_prodaja;i++){
            if(prodaje[i]->DajDatumProdaje().DajDan()==najranija.DajDatumProdaje().DajDan() && prodaje[i]->DajDatumProdaje().DajMjesec()==najranija.DajDatumProdaje().DajMjesec() && prodaje[i]->DajDatumProdaje().DajGodinu()==najranija.DajDatumProdaje().DajGodinu()){
                delete prodaje[i];
                prodaje[i]=nullptr;
                for(int j=i;j<broj_prodaja-1;j++){
                    prodaje[j]=prodaje[j+1];
                }
                broj_prodaja--;
            }
        }
    }
    void ObrisiProdajeAgenta(const std::string &ime_agenta){
        for(int i=0;i<broj_prodaja;i++){
            if(prodaje[i]->DajImeAgenta()==ime_agenta){
                delete prodaje[i];
                prodaje[i]=nullptr;
                for(int j=i;j<broj_prodaja-1;j++){
                    prodaje[j]=prodaje[j+1];
                }
                broj_prodaja--;
            }
        }
    }
    void ObrisiProdajeNaDatum(const Datum &datum){
        for(int i=0;i<broj_prodaja;i++){
            if(prodaje[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu() && prodaje[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec() && prodaje[i]->DajDatumProdaje().DajDan()==datum.DajDan()){
                delete prodaje[i];
                prodaje[i]=nullptr;
                for(int j=i;j<broj_prodaja-1;j++)
                    prodaje[j]=prodaje[j+1];
                broj_prodaja--;
            }
        }
    }
    
    void IspisiProdajeNaDatum(const Datum &datum) const
    {
        Datum najranija(datum);
        for(int i(0);i<broj_prodaja;i++)
         if(prodaje[i]->DajDatumProdaje().DajGodinu()==najranija.DajGodinu()
                && prodaje[i]->DajDatumProdaje().DajMjesec()==najranija.DajMjesec()
                && prodaje[i]->DajDatumProdaje().DajDan()==najranija.DajDan()) prodaje[i]->Ispisi();
    }
    void IspisiSveProdaje() const
    {
        for(int i(0);i<broj_prodaja;i++)
            prodaje[i]->Ispisi();
    }
    Prodaja &DajProdaju(int redniBroj){
        if(redniBroj<0 || redniBroj>broj_prodaja) throw std::range_error ("Ne valja");
        return *prodaje[redniBroj-1];
    }
};


int main() {
    return 0;
}