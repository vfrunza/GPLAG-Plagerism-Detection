/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <string>
#include <iomanip>



class Datum{
    int dan,mjesec,godina;
    
 public:
    Datum(int dan, int mjesec, int godina){
        Postavi(dan,mjesec,godina);
    }
    void Postavi(int dan, int mjesec, int godina){
        if(dan<=0 || dan>31 || mjesec<=0 || mjesec>12 || godina<0)
            throw std::domain_error("Neispravan datum");
            
        int dani[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        if( (godina%4==0 && godina%100!=0) || (godina%400==0))
            dani[1]++; 
            
        if(dan>dani[mjesec-1])
            throw std::domain_error("Neispravan datum");
            
        this->dan=dan;
        this->mjesec=mjesec;
        this->godina=godina;
        
        
        
    }
    std::tuple<int, int, int> Ocitaj() const {
        return std::make_tuple(dan,mjesec,godina);
    }
    void Ispisi() const{
        std::cout<<dan<<"/"<<mjesec<<"/"<<godina;
    }
};

class Vrijeme{
    int minute,sati;
    
public:

    Vrijeme(int sati, int minute){
        Postavi(sati,minute);
    }

    void Postavi(int sati, int minute){
        if((minute < 0 || minute > 59) || (sati < 0 || sati > 23))
            throw std::domain_error("Neispravno vrijeme");
          this->minute = minute;
          this->sati = sati;
        
    }
    std::pair<int, int> Ocitaj () const{
        return std::make_pair(sati,minute);
    }
    void Ispisi() const{
        std::cout<<sati<<":"<<minute;
    }

};

class Pregled{
    std::string ime_pacijenta;
    Datum datum;
    Vrijeme vrijeme;
    
public:

    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda,const Vrijeme &vrijeme_pregleda): ime_pacijenta(ime_pacijenta),
    datum(datum_pregleda),vrijeme(vrijeme_pregleda){}
    
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,
    int godina_pregleda, int sati_pregleda, int minute_pregleda): ime_pacijenta(ime_pacijenta),
    datum(dan_pregleda,mjesec_pregleda,godina_pregleda),vrijeme(sati_pregleda,minute_pregleda){}
    
    
    void PromijeniPacijenta(const std::string &ime_pacijenta){
        this->ime_pacijenta=ime_pacijenta;
    }
    void PromijeniDatum(const Datum &novi_datum){
        this->datum=novi_datum;
    }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme){
        this->vrijeme=novo_vrijeme;
    }
    void PomjeriDanUnaprijed(){
        auto moj_datum=datum.Ocitaj();
        int dani = std::get<0>(moj_datum);
        int mjesec = std::get<1>(moj_datum);
        int godina=std::get<2>(moj_datum);
        bool prestupna(false);
        if( (godina%4==0 && godina%100!=0) || (godina%400==0))
            prestupna=true;
        
        if ((dani==31 && (mjesec==1 || mjesec==3 || mjesec==5 || mjesec==7 || mjesec==8 || mjesec==10 || mjesec==12))  
            || (dani==30 && (mjesec==4 || mjesec==6 || mjesec==9 || mjesec==11)) || (dani==28 && mjesec==2 && !prestupna ) || (mjesec==2 && dani==29 && prestupna) )
        {
            mjesec++;
            dani=1;
            if(mjesec==13){
                mjesec=1;
                godina++;
            }
        }
        else
            dani++;
            
        datum=Datum(dani,mjesec,godina);
        
    }
    void PomjeriDanUnazad(){
        auto moj_datum=datum.Ocitaj();
        int dani = std::get<0>(moj_datum);
        int mjesec = std::get<1>(moj_datum);
        int godina=std::get<2>(moj_datum);
        
        
        bool prestupna(false);
        if( (godina%4==0 && godina%100!=0) || (godina%400==0))
            prestupna=true;
        
        if(dani==1 && (mjesec==2 || mjesec==4 || mjesec==6 || mjesec==8|| mjesec==9 || mjesec==11 || mjesec==1))  {
            mjesec--;
            dani=31;
            if(mjesec==0){
                mjesec=12;
                godina--;
            }
        }
        else if(dani==1 && (mjesec==5 || mjesec==7 || mjesec==10 || mjesec==12)){
            mjesec--;
            dani=30;
        }
        
        else if(dani==1 && mjesec==3){
            if(prestupna){
                mjesec--;
                dani=29;
                
            }
            else{
                mjesec--;
                dani=28;
            }
            
        }
        
        else
            dani--;
            
        datum=Datum(dani,mjesec,godina);
    }
    
    std::string DajImePacijenta() const {
        return ime_pacijenta;
    }
    Datum DajDatumPregleda() const{
        return datum;
        
    }
    Vrijeme DajVrijemePregleda() const {
        return vrijeme;
    }
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2){
        Datum dat1=p1.DajDatumPregleda();
        Datum dat2=p2.DajDatumPregleda();
        
        auto datum1=dat1.Ocitaj();
        auto datum2=dat2.Ocitaj();
        
        int d1=std::get<0>(datum1);
        int m1=std::get<1>(datum1);
        int g1=std::get<2>(datum1);
        
        int d2=std::get<0>(datum2);
        int m2=std::get<1>(datum2);
        int g2=std::get<2>(datum2);
        
        if(g1<g2) return true;
        else if(g1>g2) return false;
        else{
            if(m1<m2) return true;
            else if(m1>m2) return false;
            else{
                if(d1<d2) return true;
                else if(d1 == d2){
                    auto sati1=p1.DajVrijemePregleda();
                    auto sati2 = p2.DajVrijemePregleda();
                    
                    auto sat1=sati1.Ocitaj();
                    auto sat2 = sati2.Ocitaj();
                    
                    int h1=std::get<0>(sat1);
                    int min1=std::get<1>(sat1);
                    
                    int h2=std::get<0>(sat2);
                    int min2 = std::get<1>(sat2);
                    
                    if(h1 == h2){
                        if(min1 < min2) return true;
                        return false;
                    }
                    
                    else if(h1 < h2) return true;
                    else return false;
                    
                }
                return false;
            }
        }
    }
    
    void Ispisi() const{
        std::cout<<std::setw(30)<<std::left<<ime_pacijenta<<" ";
        datum.Ispisi();
        std::cout<<" ";
        vrijeme.Ispisi();
        std::cout<<std::endl;
    }
};



class Pregledi{
    int max_broj_pregleda,broj_pregleda;
    Pregled **pregledi;
    
public:
    explicit Pregledi(int max_broj_pregleda);
    Pregledi(std::initializer_list<Pregled> spisak_pregleda);
    ~Pregledi();
    Pregledi(const Pregledi &pregledi);
    Pregledi(Pregledi &&pregledi);
    Pregledi &operator =(const Pregledi &pregledi);
    Pregledi &operator =(Pregledi &&pregledi);
    void RegistrirajPregled(const std::string &ime_pacijenta,
    const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,
    int mjesec_pregleda, int godina_pregleda, int sati_pregleda,
    int minute_pregleda);
    
    void RegistrirajPregled(Pregled *pregled);
    
    int DajBrojPregleda() const { return broj_pregleda; };
    
    int DajBrojPregledaNaDatum(const Datum &datum) const;
    
    Pregled &DajNajranijiPregled();
    
    Pregled DajNajranijiPregled() const;
    
    void IsprazniKolekciju(); //samo ces kopirati destruktor, onda ces obrisatis ve iz njeg i samo pozvati ovu metodu u njemu
    
    void ObrisiNajranijiPregled();  
    
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
    
    void IspisiPregledeNaDatum(const Datum &datum) const;   
    
    void IspisiSvePreglede() const;
};

void Pregledi::RegistrirajPregled(Pregled *pregled){
    if(broj_pregleda+1>max_broj_pregleda){
        delete pregled;
        throw std::range_error("Dostignut maksimalan broj pregled");
        pregled=nullptr;
    }
    pregledi[broj_pregleda+1]=pregled;
    broj_pregleda++;
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta,const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda){
    if(broj_pregleda+1>max_broj_pregleda) throw std::range_error("Dostignut maksimalan broj pregleda");
    
    broj_pregleda++;
    pregledi[broj_pregleda]=new Pregled(ime_pacijenta,datum_pregleda,vrijeme_pregleda);
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,
    int mjesec_pregleda, int godina_pregleda, int sati_pregleda,
    int minute_pregleda){
        if(broj_pregleda+1>max_broj_pregleda) throw std::range_error("Dostignut maksimalan broj pregleda");
        Pregled pr = Pregled(ime_pacijenta,dan_pregleda,mjesec_pregleda,godina_pregleda,sati_pregleda,minute_pregleda);
        broj_pregleda++;
        pregledi[broj_pregleda]= new Pregled(pr);
    }


Pregledi::Pregledi(const Pregledi &pregledi): max_broj_pregleda(pregledi.max_broj_pregleda), broj_pregleda(pregledi.broj_pregleda){
    this->pregledi = new Pregled*[max_broj_pregleda];
    
    
    for(int i=0; i<max_broj_pregleda; i++){
        (this->pregledi)[i]=nullptr;
    }
    
    
    try{
        for(int i=0; i<broj_pregleda; i++){
            (this->pregledi)[i]=new Pregled(    *(pregledi.pregledi[i])   );
            
        }
    }
    catch(std::bad_alloc e){
        for(int i=0; i<max_broj_pregleda; i++){
            delete (this->pregledi)[i];
        }
        delete[] this->pregledi;
    }
}

Pregledi::Pregledi(Pregledi &&pregledi):pregledi(pregledi.pregledi), broj_pregleda(pregledi.broj_pregleda), max_broj_pregleda(pregledi.max_broj_pregleda){
    pregledi.max_broj_pregleda=0;
    pregledi.broj_pregleda=0;
    pregledi.pregledi=nullptr;
}

Pregledi& Pregledi::operator =(const Pregledi &pregledi){
    if(this==&pregledi) return *this;
    
    //Prepisi sve iz konstruktora kopije
    return *this;
}

Pregledi& Pregledi::operator =(Pregledi &&pregledi){
    if(this==&pregledi) return *this;
    //Prepisi sve iz konstr move-a (sa 2 reference)
    return *this;
}





Pregledi::~Pregledi(){
    
    for(int i=0; i<max_broj_pregleda; i++){
            delete pregledi[i];
    }
    delete[] pregledi;
}

Pregledi::Pregledi(int max_broj_pregleda){
  
    pregledi = new Pregled*[max_broj_pregleda];
    for(int i=0; i<max_broj_pregleda; i++)
        pregledi[i]=nullptr;
    broj_pregleda=0;
    
}

Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda){
    bool uspjela(false);
    try{
        max_broj_pregleda=10000;
        pregledi = new Pregled*[max_broj_pregleda];
        uspjela=true;
        for(int i=0; i<spisak_pregleda.size(); i++)
            pregledi[i]=nullptr;
            
        int i=0;
        for(auto it=spisak_pregleda.begin(); it!=spisak_pregleda.end(); it++){
            pregledi[i] = new Pregled(*it);
            i++;
        }
        broj_pregleda=spisak_pregleda.size();
    }
    catch(std::bad_alloc e){
        if(uspjela){
            for(int i=0; i<max_broj_pregleda; i++){
                delete pregledi[i];
            }
            delete[] pregledi;
            
        }
        broj_pregleda=0;

    }
}

int main ()
{
    Datum d1(31,12,2012);
    Vrijeme v1(12,2);
    Pregled p1("Amra Ridzal",d1,v1);
    p1.PomjeriDanUnaprijed();
    p1.Ispisi();
	return 0;
}
