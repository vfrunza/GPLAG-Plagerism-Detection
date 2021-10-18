/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <utility>
#include <string>
#include <algorithm>
#include <iomanip>
#include <initializer_list>

class Datum{
    int dan,mjesec,godina;
public:
    Datum(int dan, int mjesec, int godina){
        Postavi(dan,mjesec,godina);
    }
    void Postavi(int dan, int mjesec, int godina){
        if (dan<1 || mjesec<1 || godina<1 || mjesec>12 || dan>31) throw std::domain_error ("Neispravan datum");
        Datum::dan=dan;
        Datum::mjesec=mjesec;
        Datum::godina=godina;
    }
    std::tuple<int, int, int> Ocitaj() const{
        return std::tuple <int,int,int> {dan,mjesec,godina};
    }
    void Ispisi() const{
        std::cout << dan << "/" << mjesec << "/" << godina;
    }
};
class Vrijeme{
    int sati,minute;
public:
    Vrijeme(int sati, int minute){
        Postavi(sati,minute);
    }
    void Postavi(int sati, int minute){
        if (sati<0 || sati>24 || minute <0 || minute>60) throw std::domain_error ("Neispravno vrijeme");
        Vrijeme::sati=sati;
        Vrijeme::minute=minute;
    }
    std::pair<int, int> Ocitaj () const{
        return std::pair<int,int> {sati,minute};
    }
    void Ispisi() const{
        if (sati < 10) std::cout << "0" << sati <<":";
        else std::cout << sati <<":";
        if (minute < 10) std::cout << "0" << minute;
        else std::cout << minute;
    }
};
class Pregled{
    std::string ime_pacijenta;
    Datum datum_pregleda{{1},{1},{0}};  
    Vrijeme vrijeme_pregleda {{0},{0}};
public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda){
        PromijeniPacijenta (ime_pacijenta);
        PromijeniDatum (datum_pregleda);
        PromijeniVrijeme (vrijeme_pregleda);
    }
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,int godina_pregleda, int sati_pregleda, int minute_pregleda){
        PromijeniPacijenta (ime_pacijenta);
        PromijeniDatum(Datum(dan_pregleda,mjesec_pregleda,godina_pregleda));
        PromijeniVrijeme(Vrijeme(sati_pregleda,minute_pregleda));
    }
    void PromijeniPacijenta(const std::string &ime_pacijenta){
        Pregled::ime_pacijenta=ime_pacijenta;
    }
    void PromijeniDatum(const Datum &novi_datum){
        datum_pregleda=novi_datum;
    }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme){
        vrijeme_pregleda=novo_vrijeme;
    }
    void PomjeriDanUnaprijed(){
        std::tuple <int,int,int> a (datum_pregleda.Ocitaj());
        Datum novi_datum {{std::get<0>(a)++},{std::get<1>(a)},{std::get<2>(a)}};
        PromijeniDatum(novi_datum);
    }
    void PomjeriDanUnazad(){
        std::tuple <int,int,int> a (datum_pregleda.Ocitaj());
        Datum novi_datum {{std::get<0>(a)--},{std::get<1>(a)},{std::get<2>(a)}};
        /*if (std::get<0>(novi_datum)<=0 && ((std::get<1>(novi_datum)%2==0 && std::get<1>(novi_datum)<7) || (std::get<1>(novi_datum)%2==1 && std::get<1>(novi_datum)>7) )){
            std::get<0>(novi_datum)=31;
            std::get<1>(novi_datum)--;
        }
        if (std::get<0>(novi_datum)<=0 && ((std::get<1>(novi_datum)%2==1 && std::get<1>(novi_datum)<7) || (std::get<1>(novi_datum)%2==0 && std::get<1>(novi_datum)>7) )){
            std::get<0>(novi_datum)=30;
            std::get<1>(novi_datum)--;
        }*/
        PromijeniDatum(novi_datum);
    }
    std::string DajImePacijenta() const{
        return ime_pacijenta;
    }
    Datum DajDatumPregleda() const{
        return datum_pregleda;
    }
    Vrijeme DajVrijemePregleda() const{
        return vrijeme_pregleda;
    }
    friend bool DolaziPrije(const Pregled &p1, const Pregled &p2){
        Datum d1(p1.DajDatumPregleda()),d2(p2.DajDatumPregleda());
        std::tuple<int, int, int> dat1 (d1.Ocitaj()),dat2 (d2.Ocitaj());
        Vrijeme v1(p1.DajVrijemePregleda()), v2(p2.DajVrijemePregleda());
        std::pair<int, int> vri1(v1.Ocitaj()),vri2(v2.Ocitaj());
        if (std::get<2>(dat1)!=std::get<2>(dat2)) return std::get<2>(dat1)<std::get<2>(dat2);
        else if (std::get<1>(dat1)!=std::get<1>(dat2)) return std::get<1>(dat1)<std::get<1>(dat2);
        else if (std::get<0>(dat1)!=std::get<0>(dat2)) return std::get<0>(dat1)<std::get<0>(dat2);
        else if (vri1.first!=vri2.first) return vri1.first < vri2.first;
        else return vri1.second < vri2.second;
        
    }
    void Ispisi() const{
        std::cout << std::left << std::setw(30) << ime_pacijenta << " ";
        datum_pregleda.Ispisi();
        std::cout << " ";
        vrijeme_pregleda.Ispisi();
        std::cout << std::endl;
    }
};

class Pregledi{
    const int max_br_pregleda;
	int broj_pregleda;
	Pregled **pregled=nullptr;
	void OslobodiPreglede(){
		if (pregled==nullptr) return;
		for (int i=0; i<broj_pregleda; i++) delete pregled[i];
		delete [] pregled;
	}
public:
    explicit Pregledi(int max_broj_pregleda):broj_pregleda(0),max_br_pregleda(max_broj_pregleda), pregled(nullptr){
    	try{
        	pregled=new Pregled*[max_br_pregleda];
    	}
		catch(...){
        	OslobodiPreglede();
            throw;
    	}
	}
    Pregledi(std::initializer_list<Pregled> spisak_pregleda):broj_pregleda(spisak_pregleda.size()), max_br_pregleda(spisak_pregleda.size()), pregled(nullptr){
		pregled = new Pregled*[spisak_pregleda.size()];
	    for(auto i = 0; i < spisak_pregleda.size(); i++) {
	        pregled[i]=nullptr;
	    }
	    int indeks(0);
	    for(auto it = spisak_pregleda.begin(); it != spisak_pregleda.end(); it++) {
	        pregled[indeks]=new Pregled(*it);
	        indeks++;
	    }
	}
    ~Pregledi(){
        OslobodiPreglede();
    }
    Pregledi(const Pregledi &pregledi): broj_pregleda(pregledi.broj_pregleda), max_br_pregleda(pregledi.max_br_pregleda),pregled(nullptr){
		pregled=nullptr;
	    try{
	        pregled=new Pregled*[max_br_pregleda];
	    }
	    catch(...){
	        OslobodiPreglede();
	        throw;
	    }
	    try {
	        for( int i=0;i<broj_pregleda;i++) this->pregled[i]=new Pregled(*pregledi.pregled[i]);
	    }
	    catch(...){
	        OslobodiPreglede();
	        throw;
	    }
	}
    Pregledi(Pregledi &&pregledi):max_br_pregleda(pregledi.max_br_pregleda),pregled(nullptr){
		if (broj_pregleda==pregledi.max_br_pregleda){
			pregled=new Pregled*[pregledi.max_br_pregleda];
			for (int i(0);i<pregledi.max_br_pregleda;i++) pregled[i]=nullptr;
			pregledi.pregled=nullptr;
		}
		else throw std::range_error ("Dostignut maksimalni broj pregleda");
	}
    Pregledi &operator =(const Pregledi &pregledi){
		//if (max_br_pregleda!=pregledi.max_br_pregleda) throw std::range_error ("Dostignut maksimalni broj pregleda");
		if (&pregledi==this) return *this;
		for (int i=0;i<broj_pregleda;i++) delete pregled[i];
		broj_pregleda=pregledi.broj_pregleda;
		try{
			for(int i=0;i<broj_pregleda;i++) pregled[i]=new Pregled(*pregledi.pregled[i]);
		}
		catch (...){
			OslobodiPreglede();
			throw;
		}
		return *this;
	}
    Pregledi &operator =(Pregledi &&pregledi){
		//if(max_br_pregleda!=pregledi.max_br_pregleda)throw std::logic_error ("Nesaglasni kapaciteti liga");
		if (&pregledi==this) return *this;
		pregled=pregledi.pregled;
		broj_pregleda=pregledi.broj_pregleda;
		pregledi.pregled=nullptr;
		return *this;
	}
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda){
        if (broj_pregleda==max_br_pregleda) throw std::range_error ("Dostignut maksimalni broj pregleda");
        try{
            pregled[broj_pregleda++]=new Pregled(ime_pacijenta,datum_pregleda,vrijeme_pregleda);
        }
        catch (std::bad_alloc){
            broj_pregleda--;
            throw std::domain_error("Neuspjesno registriranje pregleda");
        }
        catch(...){
            broj_pregleda--;
            throw;
        }
    }
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda){
        if (broj_pregleda==max_br_pregleda) throw std::range_error ("Dostignut maksimalni broj pregleda");
        
        try{
            Datum datum_pregleda (dan_pregleda,mjesec_pregleda,godina_pregleda);
            Vrijeme vrijeme_pregleda (sati_pregleda, minute_pregleda);
            pregled[broj_pregleda++]=new Pregled(ime_pacijenta,datum_pregleda,vrijeme_pregleda);
        }
        catch (std::bad_alloc){
            broj_pregleda--;
            throw std::domain_error("Neuspjesno registriranje pregleda");
        }
        catch(...){
            broj_pregleda--;
            throw;
        }
    }
    void RegistrirajPregled(Pregled *pregled){
        if (broj_pregleda==max_br_pregleda) throw std::range_error ("Dostignut maksimalni broj pregleda");
        try{
            Datum datum_pregleda (pregled->DajDatumPregleda());
            Vrijeme vrijeme_pregleda (pregled->DajVrijemePregleda());
            std::string ime_pacijenta (pregled->DajImePacijenta());
            Pregledi::pregled[broj_pregleda++]=new Pregled(ime_pacijenta,datum_pregleda,vrijeme_pregleda);
        }
        catch (std::bad_alloc){
            broj_pregleda--;
            throw std::domain_error("Neuspjesno registriranje pregleda");
        }
        catch(...){
            broj_pregleda--;
            throw;
        }
    }
    int DajBrojPregleda() const {return broj_pregleda;}
    
    
    int DajBrojPregledaNaDatum(const Datum &datum) const{
        return std::count_if (pregled,pregled+broj_pregleda,[datum](const Pregled *pregled1){
            return datum.Ocitaj()==((pregled1)->DajDatumPregleda()).Ocitaj();
        });
    }
   /* Pregled &DajNajranijiPregled(){
        return **std::min_element (pregled,pregled+broj_pregleda,[](const Pregled *pregled1){
            return (((pregled1+1))->DajDatumPregleda()).Ocitaj()<((pregled1)->DajDatumPregleda()).Ocitaj();
        });
    }*/
    Pregled DajNajranijiPregled() const{
        int min=0;
        for (int i(0);i<broj_pregleda;i++) 
            if (DolaziPrije(pregled[i]),pregled[min]) min=i;
        return *pregled[min];
    }
    void IsprazniKolekciju(){
        if (broj_pregleda==0) throw std::range_error("Prazna kolekcija");
        for(int i(0);i<broj_pregleda;i++)
            delete pregled[i];
        broj_pregleda=0;
    }
    void ObrisiNajranijiPregled(){
        if (broj_pregleda==0) throw std::range_error("Prazna kolekcija");
        Pregled p=this->DajNajranijiPregled();
        for(int i(0);i<broj_pregleda;i++){
            if (pregled[i]->DajImePacijenta()==p.DajImePacijenta() && pregled[i]->DajDatumPregleda()==p.DajDatumPregleda()){
                delete pregled[i];
                for (int j=i;j<broj_pregleda-1;j++){
                    Pregled *pom=pregled[j];
                    pregled[j]=pregled[j+1];
                    pregled[j+1]=pom;
                }
                broj_pregleda--;
            }
        }
    }
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta){
        for (int i(0);i<broj_pregleda;i++){
            if (pregled[i]->DajImePacijenta()==ime_pacijenta) {
                delete pregled[i];
                for (int j=i;j<broj_pregleda-1;j++){
                    Pregled *pom=pregled[j];
                    pregled[j]=pregled[j+1];
                    pregled[j+1]=pom;
                }
                i--;
                broj_pregleda--;
            }
        }
    }
    
    void IspisiPregledeNaDatum(const Datum &datum) const{
        int k=0;
        Pregled** pom=new Pregled*[broj_pregleda];
        for(int i=0; i<broj_pregleda; i++)
        {
            if(pregled[i]->DajDatumPregleda()==datum )
                {
                    pom[k]=new Pregled(*pregled[i]);
                    k++;
                }
        }
        for(int o=0; o<k; o++)
        {
            for(int b=0; b<k; b++)
            if(DolaziPrije(*pom[o],*pom[b]))
                {
                    Pregled* pom2=pom[o];
                    pom[o]=pom[b];
                    pom[b]=pom2;
                }
        }
        for(int h=0; h<k; h++)
            pom[h]->Ispisi();
        for(int i=0; i<k; i++)
            delete pom[i];
        delete [] pom;
    }
    void IspisiSvePreglede() const{
        Pregled** pom=new Pregled*[broj_pregleda];
        for(int i=0; i<broj_pregleda; i++)
            pom[i]=new Pregled(*pregled[i]);
        for(int a=0; a<broj_pregleda; a++)
            for(int b=0; b<broj_pregleda; b++)
            {
                if(DolaziPrije(*pom[a],*pom[b]))
                {
                Pregled* pom2=pom[a];
                pom[a]=pom[b];
                pom[b]=pom2;
                }
            }
        for(int i=0; i<broj_pregleda; i++)
            pom[i]->Ispisi();
        for(int y=0; y<broj_pregleda; y++)
            delete pom[y];
        delete [] pom;
    }

};

int main ()
{
/*try
{
    Vrijeme v(11,15);
    Datum d(3,1,2016);
    Pregled p("Aldin Rizvo",d,v);
    
    Vrijeme v1(12,57);
    Datum d1(3,1,2016);
    Pregled p1("Hamo Pipa",d1,v1);
    
    p1.PomjeriDanUnazad();
    p.PomjeriDanUnaprijed();
    
    Pregledi pr(5);
    pr.RegistrirajPregled(&p);
    pr.RegistrirajPregled(&p1);
    pr.RegistrirajPregled("Hamo Pipa", 12, 6, 2017, 18, 50);
    pr.RegistrirajPregled("Volim te", 15, 5, 2015, 16, 37);
    pr.RegistrirajPregled("Samo ti", d1, v);
    std::cout<<"Svi pregledi: "<<std::endl;
    pr.IspisiSvePreglede();
    
    Datum da(15,5,2015);
    std::cout<<std::endl<<"Ispisujem na datum 15/5/2015: "<<std::endl;
    pr.IspisiPregledeNaDatum(da);
    
    std::cout<<std::endl<<"Najraniji pregled je: "<<std::endl;pr.DajNajranijiPregled().Ispisi();
    pr.ObrisiNajranijiPregled();
    std::cout<<std::endl<<"Preostali pregledi su: "<<std::endl;
    pr.ObrisiPregledePacijenta("Hamo Pipa");
    pr.IspisiSvePreglede();
    
}
catch(std::domain_error e) {std::cout<<e.what();}
catch(std::range_error r) {std::cout<<r.what();}
catch(...){ std::cout<<"Greska!";}
    
    
    
    
    
    Datum d1(1,3,2016);
    Datum d2(31,12,2015);
    Vrijeme v1(16,34);
    Vrijeme v2(14,23);
    
    try{
    Pregled p1("Hello",d1,v1);
    Pregled p2("World",d2,v2);

    p1.Ispisi();
    std::cout<<std::endl;
    p2.Ispisi();
    std::cout<<std::endl;

    p1.PromijeniPacijenta("Saban");
    p2.PromijeniPacijenta("Zvonko");

    p1.Ispisi();
    p2.Ispisi();
    

    p1.PomjeriDanUnazad();
    p2.PomjeriDanUnaprijed();

    p1.Ispisi();
    p2.Ispisi();
    
   

    if (DolaziPrije(p1,p2))
    {
        std::cout<<"Saban je prije"<<std::endl;
    }
    else
    {
        std::cout<<"Zvonko je prije"<<std::endl;
    }

    Datum dat1(12,12,2015),dat2(4,3,2015);
    Vrijeme time1(1,20),time2(11,00);
    Pregledi pregledi(5);

    pregledi.RegistrirajPregled(&p1);
    pregledi.RegistrirajPregled(&p2);
    pregledi.RegistrirajPregled("Momo",dat1,time1);
    pregledi.RegistrirajPregled("Uzeir",dat2,time2);
    pregledi.RegistrirajPregled("Musa",4,3,2015,11,5);

    pregledi.IspisiSvePreglede();
    std::cout<<std::endl;
    std::cout<<pregledi.DajBrojPregleda()<<std::endl;

    pregledi.IsprazniKolekciju();


    pregledi.RegistrirajPregled(&p1);
    pregledi.RegistrirajPregled(&p2);
    pregledi.RegistrirajPregled("Momo",4,3,2015,9,5);
    pregledi.RegistrirajPregled("Uzeir",4,3,2015,10,15);
    pregledi.RegistrirajPregled("Musa",4,3,2015,11,5);


    pregledi.IspisiPregledeNaDatum(dat2);
    std::cout<<std::endl;

    pregledi.IspisiSvePreglede();
    }
    catch(std::domain_error Exp)
    {
        std::cout<<Exp.what();
    }
    catch(std::range_error Exp)
    {
        std::cout<<Exp.what();
    }
*/
return 0;
    //return 123344;
}