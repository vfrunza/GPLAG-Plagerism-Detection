/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <utility>
#include <string>
#include <iomanip>
//#include <cstring>

class Datum {
    int dan,mjesec,godina;
    
    public:
    Datum(int dan,int mjesec,int godina) {
        int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
        if((godina%4==0 && godina%100!=0) || godina%400==0) broj_dana[1]++;
        if(godina<1 || mjesec<1 || dan<1 || mjesec>12 || dan>broj_dana[mjesec-1])
            throw std::domain_error("Neispravan datum");
        Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
    }
    
    void Postavi(int dan,int mjesec,int godina) {
        int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
        if((godina%4==0 && godina%100!=0) || godina%400==0) broj_dana[1]++;
        if(godina<1 || mjesec<1 || dan<1 || mjesec>12 || dan>broj_dana[mjesec-1])
            throw std::domain_error("Neispravan datum");
        Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
    }
    
    std::tuple<int,int,int> Ocitaj() const {
        std::tuple<int,int,int> datum{dan,mjesec,godina};
        return datum;
    }
    void Ispisi() const{
        std::cout<<dan<<"/"<<mjesec<<"/"<<godina;
    }
    
    int DajDan() const { return dan; } 
    int DajMjesec() const { return mjesec; }
    int DajGodinu() const { return godina; }
    
    friend bool DaLiSuIstiDatumi(Datum d1,Datum d2);
};

bool DaLiSuIstiDatumi (Datum d1,Datum d2) {
        if(d1.dan==d2.dan) {
            if(d1.mjesec==d2.mjesec) {
                if(d1.godina==d2.godina) 
                    return true;
            }
        }
        return false;
    }

class Vrijeme {
    int sati,minute;
    
    public:
    static bool DaLiJeIspravnoVrijeme(int sati,int minute) {
        if(sati<0 || minute<0 || sati>23 || minute>59)
            return false;
        return true;
    }
    
    Vrijeme (int sati,int minute) {
        if(!DaLiJeIspravnoVrijeme(sati,minute))
            throw std::domain_error("Neispravno vrijeme");
        Vrijeme::sati=sati; Vrijeme::minute=minute;
    }
    void Postavi(int sati,int minute) {
        if(!DaLiJeIspravnoVrijeme(sati,minute))
            throw std::domain_error("Neispravno vrijeme");
        Vrijeme::sati=sati; Vrijeme::minute=minute;
    }
    std::pair<int,int> Ocitaj() const {
        std::pair<int,int> vrijeme;
        vrijeme=std::make_pair(sati,minute);
        return vrijeme;
    }
    void Ispisi() const{
        std::cout<<std::setw(2)<<std::setfill('0')<<sati<<":";
        std::cout<<std::setw(2)<<std::setfill('0')<<minute;
    }
    int DajSate() const { return sati; }
    int DajMinute() const { return minute; }
};

class Pregled {
    std::string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;
    
    public:
    Pregled(const std::string &ime_pacijenta,const Datum &datum_pregleda,const Vrijeme &vrijeme_pregleda): 
            datum_pregleda(datum_pregleda.DajDan(),datum_pregleda.DajMjesec(),datum_pregleda.DajGodinu()),
            vrijeme_pregleda(vrijeme_pregleda.DajSate(),vrijeme_pregleda.DajMinute()){
        Pregled::ime_pacijenta=ime_pacijenta;
        
    }
    Pregled(const std::string &ime_pacijenta,int dan_pregleda,int mjesec_pregleda,int godina_pregleda,int sati_pregleda, int minute_pregleda):
            datum_pregleda(dan_pregleda,mjesec_pregleda,godina_pregleda),vrijeme_pregleda(sati_pregleda,minute_pregleda) {
            Pregled::ime_pacijenta=ime_pacijenta;
    }
    void PromijeniPacijenta(const std::string &ime_pacijenta) {
        Pregled::ime_pacijenta=ime_pacijenta;
    }
    void PromijeniDatum(const Datum &novi_datum){
        int d=novi_datum.DajDan(); int m=novi_datum.DajMjesec();int g=novi_datum.DajGodinu();
        datum_pregleda.Postavi(d,m,g);
    }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme){
        int s=novo_vrijeme.DajSate(); int m=novo_vrijeme.DajMinute();
        vrijeme_pregleda.Postavi(s,m);
    }

    void PomjeriDanUnaprijed(){
        int d=datum_pregleda.DajDan(); int m=datum_pregleda.DajMjesec();int g=datum_pregleda.DajGodinu();
        int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
        d++;
        if(d>broj_dana[m-1]) {
            d=1;
            m+=1;
            if(m==12) {
                m=1;
                g++;
            }
        }
        datum_pregleda.Postavi(d,m,g);
    }
    
    void PomjeriDanUnazad(){
        int d=datum_pregleda.DajDan(); int m=datum_pregleda.DajMjesec();int g=datum_pregleda.DajGodinu();
        int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
        d--;
        if(d==0) {
            if(m==1) d=31;
            else d=broj_dana[m-2];
            m--;
            if(m==0) {
                m=12;
                g--;
            }
        }
        datum_pregleda.Postavi(d,m,g);
    }
    std::string DajImePacijenta() const{
        return ime_pacijenta;
    }
    Datum DajDatumPregleda() const{
        Datum dat(datum_pregleda.DajDan(),datum_pregleda.DajMjesec(),datum_pregleda.DajGodinu());
        return dat;
    }
    Vrijeme DajVrijemePregleda() const{
        Vrijeme v(vrijeme_pregleda.DajSate(),vrijeme_pregleda.DajMinute());
        return v;
    }
    static bool DolaziPrije(const Pregled &p1,const Pregled &p2){
        int g1=p1.datum_pregleda.DajGodinu();
        int g2=p2.datum_pregleda.DajGodinu();
        if(g2>g1) return false;
        else {
            int m1=p1.datum_pregleda.DajMjesec();
            int m2=p2.datum_pregleda.DajMjesec();
            if(m2>m1) return false;
            else {
                int d1=p1.datum_pregleda.DajDan();
                int d2=p2.datum_pregleda.DajDan();
                if(d2>d1) return false;
                else {
                    int s1=p1.vrijeme_pregleda.DajSate();
                    int s2=p2.vrijeme_pregleda.DajSate();
                    if(s2>s1) return false;
                    else {
                        int min1=p1.vrijeme_pregleda.DajMinute();
                        int min2=p2.vrijeme_pregleda.DajMinute();
                        if(min2>min1) return false;
                    }
                }
            }
        }
        return true;
    }
    void Ispisi() const{
        std::cout<<std::left<<std::setw(30)<<std::setfill(' ')<<ime_pacijenta;
        datum_pregleda.Ispisi();
        std::cout<<" ";
        vrijeme_pregleda.Ispisi();
        std::cout<<std::endl;
    }
    Datum DajDatum(Pregled p) {
        return p.datum_pregleda;
    }
};

class Pregledi{
    int broj_pregleda;
    const int max_broj_pregleda;
    Pregled **pregled;
    
    public:
    explicit Pregledi(int max_broj_pregleda): broj_pregleda(0),
            max_broj_pregleda(max_broj_pregleda),
            pregled(new Pregled*[max_broj_pregleda]{}){}
            
    Pregledi (std::initializer_list<Pregled> spisak_pregleda): broj_pregleda(spisak_pregleda.size()),
            max_broj_pregleda(spisak_pregleda.size()),pregled(new Pregled*[spisak_pregleda.size()]{}) {
        int i=0;
        for(auto it=spisak_pregleda.begin();it!=spisak_pregleda.end();it++){
            try {
                pregled[i]=new Pregled(*it);
                i++;
            }
            catch(std::bad_alloc) {
                for(int i(0);i<spisak_pregleda.size();i++) {
                    delete pregled[i];
                    pregled[i]=nullptr;
                }
                throw;
            }
        }
    }
    ~Pregledi(){
        for(int i(0);i<max_broj_pregleda;i++) 
            delete pregled[i];
            delete[] pregled;
    }
    Pregledi(const Pregledi &pregledi): broj_pregleda(pregledi.broj_pregleda), 
    max_broj_pregleda(pregledi.max_broj_pregleda), pregled(new Pregled*[pregledi.max_broj_pregleda]{}){
        try {
            
            for(int i(0);i<pregledi.broj_pregleda;i++) 
                pregled[i]=new Pregled(*pregledi.pregled[i]);
        }
        catch(...) {
            for(int i(0);i<pregledi.broj_pregleda;i++)
                delete pregled[i];
            delete[] pregled;
            throw;
        }
    }
    Pregledi(Pregledi &&pregledi):broj_pregleda(pregledi.broj_pregleda),
            max_broj_pregleda(pregledi.max_broj_pregleda),pregled(pregledi.pregled){
        pregledi.pregled=nullptr;
        pregledi.broj_pregleda=0;
    }
    Pregledi &operator=(const Pregledi &pregledi);
    Pregledi &operator=(Pregledi &&pregledi);
    void RegistrirajPregled(const std::string &ime_pacijenta,const Datum &datum_pregleda,const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta,int dan_pregleda,int mjesec_pregleda,int godina_pregleda,int sati_pregleda, int minute_pregleda);
    void RegistrirajPregled(Pregled *pregled);
    int DajBrojPregleda() const;
    int DajBrojPregedaNaDatum(const Datum &datum) const;
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum(const Datum &datum) const;
    void IspisiSvePreglede() const;
};


Pregledi &Pregledi::operator=(const Pregledi &pregledi) {
    if(pregledi.broj_pregleda>broj_pregleda){
        try {
            for(int i(0);i<pregledi.broj_pregleda;i++)
                pregled[i]=new Pregled(*pregledi.pregled[i]);
        }
        catch(...) {
            for(int i=broj_pregleda;i<pregledi.broj_pregleda;i++) {
                delete pregled[i];
                pregled[i]=nullptr;
            }
            throw;
        }
    }
    else {
        for(int i=pregledi.broj_pregleda;i<broj_pregleda;i++) {
            delete pregled[i];
            pregled[i]=nullptr;
        }
    }
    broj_pregleda=pregledi.broj_pregleda;
    for(int i(0);i<broj_pregleda;i++) 
        *pregled[i]=*pregledi.pregled[i];
    return *this;
}

Pregledi &Pregledi::operator=(Pregledi &&pregledi) {
    std::swap(broj_pregleda,pregledi.broj_pregleda);
    std::swap(pregled,pregledi.pregled);
    return *this;
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta,
    const Datum &datum_pregleda,const Vrijeme &vrijeme_pregleda){
        if(broj_pregleda>=max_broj_pregleda) throw std::range_error("Dostignut maksimalan broj pregleda");
        pregled[broj_pregleda++]=new Pregled(ime_pacijenta,datum_pregleda,vrijeme_pregleda);
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta,int dan_pregleda,
    int mjesec_pregleda,int godina_pregleda,int sati_pregleda, int minute_pregleda){
        if(broj_pregleda>=max_broj_pregleda) throw std::range_error("Dostignut maksimalan broj pregleda"); 
        pregled[broj_pregleda++]=new Pregled(ime_pacijenta,dan_pregleda,mjesec_pregleda,godina_pregleda,sati_pregleda,minute_pregleda);
}

//void Pregledi::RegistrirajPregled(Pregled *pregled);

int Pregledi::DajBrojPregleda() const{
    return broj_pregleda;
}



//friend bool DaLiSuIstiDatumi(Datum d1,Datum d2);

int Pregledi::DajBrojPregedaNaDatum(const Datum &datum) const{
    int brojac(0);

    for(int i(0);i<broj_pregleda;i++) {
        Datum d=pregled[i]->DajDatumPregleda();
        if(DaLiSuIstiDatumi(datum,d))
            brojac++;
            
    }
    return brojac;
}

//Pregled DajNajranijiPregled() const;

int main () {
    Pregled p("Meho",1,1,2000,14,23);
    p.Ispisi();
    
    //p.Ispisi();
    //std::cout<<p.DajImePacijenta();
    //p.DajDatumPregleda().Ispisi();
    
    
    
	return 0;
}
