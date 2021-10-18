/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <string>
#include <tuple>
#include <iomanip>
#include <utility>
#include <initializer_list>
#include <algorithm>

typedef std::string String;

class Datum {
    
int dan,mjesec,godina;
    
friend class Pregled;
friend class Vrijeme;
friend class Pregledi;

int DajDan() const {
    return dan;
}
int DajMjesec() const {
    return mjesec;
}

int DajGodinu() const {
    return godina;
}
public:
  
  
Datum(int dan, int mjesec, int godina); 
void Postavi(int dan, int mjesec, int godina);
std::tuple<int, int, int> Ocitaj() const;
void Ispisi() const {
    std::cout << dan << "/" << mjesec << "/" << godina;
}

};

Datum::Datum(int dan, int mjesec, int godina) {
    int br_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
    if(godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0) br_dana[1]++;
    if(godina < 1 || mjesec < 1 || dan < 1 || mjesec > 12 || dan > br_dana[mjesec-1]) throw std::domain_error("Neispravan datum");
    Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
}

void Datum::Postavi(int dan, int mjesec, int godina) {
    int br_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
    if(godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0) br_dana[1]++;
    if(godina < 1 || mjesec < 1 || dan < 1 || mjesec > 12 || dan > br_dana[mjesec-1]) throw std::domain_error("Neispravan datum");
    Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina;
}

std::tuple<int, int, int> Datum::Ocitaj() const {
    return std::make_tuple(Datum::dan,Datum::mjesec,Datum::dan);
}

class Vrijeme {
    
int h,min;
friend class Datum;
friend class Pregledi;
friend class Pregled;

int DajSati() const {
    return h;
}

int DajMinute() const {
    return min;
}
public:


Vrijeme(int sati, int minute) : h(sati), min(minute) {
    if(sati < 0 || minute < 0 || sati > 23 || minute > 59) throw std::domain_error("Neispravno vrijeme");
}
void Postavi(int sati, int minute);
std::pair<int, int> Ocitaj () const;
void Ispisi() const {
    std::cout << h << ":" << min;
    }
};

void Vrijeme::Postavi(int sati, int minute) {
    if(sati < 0 || minute < 0 || sati > 23 || minute > 59) throw std::domain_error("Neispravno vrijeme");
    Vrijeme::h = sati; Vrijeme::min = minute;
}

std::pair<int, int> Vrijeme::Ocitaj() const {
    std::pair<int, int> v;
    v.first = h; v.second = min;
    return v;
}

class Pregled {
    
Datum datum;
String ime;
Vrijeme vrijeme;
static int br_preg;

friend class Pregledi;
friend class Datum;
friend class Vrijeme; 

public:

Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
void PromijeniPacijenta(const std::string &ime_pacijenta);
void PromijeniDatum(const Datum &novi_datum);
void PromijeniVrijeme(const Vrijeme &novo_vrijeme);
void PomjeriDanUnaprijed();
void PomjeriDanUnazad();
std::string DajImePacijenta() const;
Datum DajDatumPregleda() const;
Vrijeme DajVrijemePregleda() const;
static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
void Ispisi() const;
};

Pregled::Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) : datum(datum_pregleda), vrijeme(vrijeme_pregleda) {
    ime = ime_pacijenta;
    br_preg++;
   
    
    
}

Pregled::Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) : datum(dan_pregleda,mjesec_pregleda,godina_pregleda), vrijeme(sati_pregleda,minute_pregleda) {
    ime = ime_pacijenta;
    br_preg++;
}

void Pregled::PromijeniPacijenta(const std::string &ime_pacijenta) {
    Pregled::ime = ime_pacijenta;
    std::getline(std::cin, ime);
     
    
}

void Pregled::PromijeniDatum(const Datum &novi_datum) {
    datum = novi_datum;
}

void Pregled::PromijeniVrijeme(const Vrijeme &novo_vrijeme) {
    vrijeme = novo_vrijeme;
}

void Pregled::PomjeriDanUnaprijed() {
    int br_dana[] {31,30,28,31,30,31,30,31,31,30,31,30};
    if(datum.godina % 4 == 0 && datum.godina % 100 != 0 || datum.godina % 400 == 0) br_dana[1]++;
    datum.dan++;
    if(datum.dan > br_dana[datum.mjesec-1]) {
        datum.dan=1; datum.mjesec++;
    }
    if(datum.mjesec > 12) {
        datum.mjesec=1; datum.godina++;
    }
}

void Pregled::PomjeriDanUnazad() {
    int br_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(datum.godina % 4 == 0 && datum.godina % 100 != 0 || datum.godina % 400 == 0) br_dana[1]++;
    datum.dan--;
    if(datum.dan < 1) {
        datum.mjesec--;
        if(datum.mjesec == 0) {
            datum.mjesec=12; datum.godina--; datum.dan=30;
        } else 
            datum.dan=br_dana[datum.mjesec-1];
    }
}

std::string Pregled::DajImePacijenta() const {
    return Pregled::ime;
}

Datum Pregled::DajDatumPregleda() const {
    return Pregled::datum;
}

Vrijeme Pregled::DajVrijemePregleda() const {
    return Pregled::vrijeme;
}

static bool DolaziPrije(const Pregled &p1, const Pregled &p2) {
    Datum dat1(p1.DajDatumPregleda());
    Datum dat2(p2.DajDatumPregleda());
    int d1,d2,m1,m2,g1,g2;
    std::tuple<int, int, int> o1(dat1.Ocitaj());
    std::tuple<int, int, int> o2(dat2.Ocitaj());
    std::tie(d1, m1, g1)= o1;
    std::tie(d2, m2, g2) = o2;
    if(g1<g2) return true;
    if(g1==g2){
        if(m1==m2){
            if(d1<d2) return true;
            else if(d1==d2){
                Vrijeme vr1(p1.DajVrijemePregleda());
                Vrijeme vr2(p2.DajVrijemePregleda());
                std::pair<int, int> k1(vr1.Ocitaj());
                std::pair<int, int> k2(vr2.Ocitaj());
                int sati1 = std::get<0>(k1);
                int min1 = std::get<1>(k1);
                int sati2 = std::get<0>(k2);
                int min2 = std::get<1>(k2);
                
                if(sati1 < sati2) return true;
                else if(sati1 == sati2) {
                    if(min1 < min2) return true;
                    return false;
                }
            }
            return false;
        }else if(m1<m2) return true;
        return false;
    }
    return false;
    
}

void Pregled::Ispisi() const {
    std::cout << std::left << std::setw(30) << DajImePacijenta() << this->DajDatumPregleda().DajDan() << "/" << this->DajDatumPregleda().DajMjesec() << "/" << this->DajDatumPregleda().DajGodinu() << " " <<  this->DajVrijemePregleda().DajSati() << ":" << this->DajVrijemePregleda().DajMinute() << std::endl;
}



/*int br_preg,max_broj;
Pregled **pok_pregledi;
String ime_unosa;
Vrijeme vrijeme_pr;
Datum datum_pr;

void AlocirajNiz(int br) {
		pok_pregledi = nullptr;
		try {
			pok_pregledi = new Pregled*[br];
		} catch(...) {
			OcistiPreglede();
			throw;
		}
	}
void OcistiPreglede() {
		if(pok_pregledi == nullptr) return;
		for(int i=0; i<br_pregleda; i++) delete pok_pregledi[i];
		delete[] pok_pregledi;
}

friend class Datum;
friend class Vrijeme;
friend class Pregled;
public:



explicit Pregledi(int max_broj_pregleda):max_broj(max_broj_pregleda), br_preg(0) {AlocirajNiz(max_broj);}
Pregledi(std::initializer_list<Pregled> spisak_pregleda);
~Pregledi();
Pregledi(const Pregledi &pregledi);
Pregledi(Pregledi &&pregledi);
Pregledi &operator =(const Pregledi &pregledi);
Pregledi &operator =(Pregledi &&pregledi);
void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
void RegistrirajPregled(Pregled *pregled);
int DajBrojPregleda() const;
int DajBrojPregledaNaDatum(const Datum &datum) const;
Pregled &DajNajranijiPregled();
Pregled DajNajranijiPregled() const;
void IsprazniKolekciju();
void ObrisiNajranijiPregled();
void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
void IspisiPregledeNaDatum(const Datum &datum) const;
void IspisiSvePreglede() const;
};

 
Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda):max_broj(spisak_pregleda.size()), pok_pregledi(nullptr){
    br_preg = spisak_pregleda.size();
    int brojac(0);
    try {
        pok_pregledi = new Pregled*[br_preg];
        for(int i=0; i<br_preg; i++) pok_pregledi[i] = nullptr;
        for(auto &x : spisak_pregleda) pok_pregledi[brojac++] = new Pregled(x);
    }catch(...) {
        OcistiPreglede();
        throw;
    }
}

Pregledi::~Pregledi() {
    if(pok_pregledi==nullptr) return;
    for(int i=0; i<max_broj; i++) delete pok_pregledi[i];
    delete[] pok_pregledi;
}

Pregledi::Pregledi(const Pregledi &pregledi) :  max_broj(pregledi.max_broj), pok_pregledi(nullptr) {
    broj_preg=pregledi.broj_pregleda;
     p = new Pregled*[pregledi.max_broj];
     for(int i=0; i<broj_preg; i++) p[i]=nullptr;
     try{
         for(int i=0; i<broj_preg; i++){
             p[i]=new Pregled(*pregledi.p[i]);
         }
     }catch(...){
         for(int i=0; i<broj_preg; i++) delete[] p[i];
         delete[] p;
         throw;
     }
     
}

Pregledi::Pregledi(Pregledi &&pregledi) : br_pregleda(pregledi.br_pregleda), max_pregledi(pregledi.br_pregleda), pok_pregledi(nullptr) {
    pok_pregledi = pregledi.pok_pregledi;
    pregledi.pok_pregledi = nullptr;
}

Pregledi &Pregledi::operator =(const Pregledi &pregledi) {
    if(&pregledi == this) return *this;
    
    for(int i=0; i<br_pregleda; i++) delete pok_pregledi[i];
    br_pregleda = pregledi.br_pregleda;
    try {
        for(int i=0; i<br_pregleda; i++) pok_pregledi[i] = new Pregled(*pregledi.pok_pregledi[i]);
    }catch(...) {
        OcistiPreglede();
        throw;
    }
    return *this;
}

Pregledi &Pregledi::operator =(Pregledi &&pregledi) {
    if(&pregledi == this) return *this;
    pok_pregledi = pregledi.pok_pregledi;
    br_pregleda = pregledi.br_pregleda;
    pregledi.pok_pregledi = nullptr;
    return *this;
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) {
    Pregledi::ime_unosa = ime_pacijenta;
    datum_pr = datum_pregleda;
    vrijeme_pr = vrijeme_pregleda;
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) {
    ime_unosa = ime_pacijenta;
    datum_pr.dan=dan_pregleda;
    datum_pr.mjesec=mjesec_pregleda;
    datum_pr.godina=godina_pregleda;
    vrijeme_pr.h=sati_pregleda;
    vrijeme_pr.min=minute_pregleda;
}*/

class Pregledi {
    Pregled **p;
    const int max_broj;
    int broj_pregleda;
    friend class Pregled;

public:
    explicit Pregledi(int max_broj_pregleda):max_broj(max_broj_pregleda){
        p=new Pregled*[max_broj];
        broj_pregleda=0;
    }
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
    int DajBrojPregleda() const{
        return broj_pregleda;
    }
    int DajBrojPregledaNaDatum(const Datum &datum) const{
        
        int broj = std::count_if(p,p+broj_pregleda , [&datum](Pregled *p1){
            if(std::get<0>(p1->DajDatumPregleda().Ocitaj())==std::get<0>(datum.Ocitaj())&&
            std::get<1>(p1->DajDatumPregleda().Ocitaj()) == std::get<1>(datum.Ocitaj()) &&
            std::get<2>(p1->DajDatumPregleda().Ocitaj()) == std::get<2>(datum.Ocitaj())) return true;
            return false ;
        });
        return broj;
    }
    Pregled &DajNajranijiPregled(){
        if(broj_pregleda==0) throw std::domain_error("Nema registriranih pregleda");
    }
    Pregled DajNajranijiPregled() const{
        if(broj_pregleda==0) throw std::domain_error("Nema registriranih pregleda");
        /*auto pom(*std::min_element(p, p+broj_pregleda, [&dat, &vri](Pregled *p1, Pregled *p2){
            if(std::get<0>(p1->DajDatumPregleda().Ocitaj())==std::get<0>(dat.Ocitaj())&&
            std::get<1>(p1->DajDatumPregleda().Ocitaj()) == std::get<1>(dat.Ocitaj()) &&
            std::get<2>(p1->DajDatumPregleda().Ocitaj()) == std::get<2>(dat.Ocitaj() )){
                if(std::get<0>(p1->DajVrijemePregleda().Ocitaj()) == std::get<0>(vri.Ocitaj()){
                    if(std::get<1>(p1->DajVrijemePregleda().Ocitaj()) < std::get<1>(vri.Ocitaj())) return
                }
            }
        }));*/
        /*auto pom(*std::min_element(p, p+broj_pregleda, [](Pregled *p1, Pregled *p2){
            if(DolaziPrije(*p1,*p2)) return *p1;
            //return nullptr;
        }));*/
        
    }
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum(const Datum &datum) const;
    void IspisiSvePreglede() const;
};

Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda):max_broj(spisak_pregleda.size()){
    broj_pregleda=spisak_pregleda.size();
    //?????????
   /* for(auto it=spisak_pregleda.begin(); it!=spisak_pregleda.end() it++)
        (*it)=nullptr;*/
    p=new Pregled *[spisak_pregleda.size()];
    for(int i=0; i<broj_pregleda; i++) p[i]= nullptr;
        int j(0);
    try{
        int i=0;
        for(auto it = spisak_pregleda.begin(); it!=spisak_pregleda.end(); it++){
            p[i] = new Pregled(*it);
            i++;
            j++;
        }
    } catch(std::bad_alloc){
        for(int i=0; i<j; j++)  delete[] p[i];
        delete[] p;
        throw;
    }
}

Pregledi::~Pregledi(){
    for(int i=0; i<max_broj; i++) delete p[i];
    delete[] p;
}
 Pregledi::Pregledi(const Pregledi &pregledi):max_broj(pregledi.max_broj){
     broj_pregleda=pregledi.broj_pregleda;
     p = new Pregled*[pregledi.max_broj];
     for(int i=0; i<broj_pregleda; i++) p[i]=nullptr;
     try{
         for(int i=0; i<broj_pregleda; i++){
             p[i]=new Pregled(*pregledi.p[i]);
         }
     }catch(...){
         for(int i=0; i<broj_pregleda; i++) delete[] p[i];
         delete[] p;
         throw;
     }
     
 }

Pregledi::Pregledi(Pregledi &&pregledi):max_broj(pregledi.max_broj){
    broj_pregleda=pregledi.broj_pregleda;
    p=pregledi.p;
    pregledi.p=nullptr;
    pregledi.broj_pregleda = 0;
}

Pregledi &Pregledi::operator =(const Pregledi &pregledi){
    if(this != &pregledi){
        for (int i=0; i<broj_pregleda; i++)
            delete[] p[i];
        delete[] p;
        broj_pregleda=pregledi.broj_pregleda;
        p=new Pregled*[pregledi.max_broj];
        for(int i=0; i<broj_pregleda; i++) p[i]=new Pregled(*pregledi.p[i]);
    }
    return *this;
}

Pregledi &Pregledi::operator =(Pregledi &&pregledi){
    for(int i=0; i<broj_pregleda; i++) delete p[i];
    delete[] p;
    
    broj_pregleda = pregledi.broj_pregleda;
    p=pregledi.p;
    pregledi.p=nullptr;
    /*std::swap(broj_pregleda, pregledi.broj_pregleda);
    std::swap(p, pregledi.p);*/
    return *this;
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda){
    if(broj_pregleda > max_broj) throw std::range_error("Dostignut maksimalan broj pregleda");
    Pregled preg{ime_pacijenta, datum_pregleda, vrijeme_pregleda};
    p[broj_pregleda++]=new Pregled(preg);
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,
                            int mjesec_pregleda, int godina_pregleda, int sati_pregleda,
                            int minute_pregleda){
                                if(broj_pregleda > max_broj) throw std::range_error("Dostignut maksimalan broj pregleda");
                                Pregled preg{ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda};
                                p[broj_pregleda++] = new Pregled(preg);
                            }

void Pregledi::RegistrirajPregled(Pregled *pregled){
    if(broj_pregleda > max_broj) throw std::range_error("Dostignut maksimalan broj pregleda");
    p[broj_pregleda++]=pregled;
}



    

int main ()
{
    try {
    Datum d{10,3,1998};
    Vrijeme v{17,15};
    

    Pregled pred{"sarahhh", d, v};
    
    Datum d1{15,4,1999};
    Vrijeme v1{18,15};
    Pregled pred1{"amina", d1, v1};
    //Pregled pred {"ime amina je pegla", 25,3,1998, 15,36};
    bool nesto (DolaziPrije(pred, pred1));
    pred.PomjeriDanUnazad();
    pred.Ispisi();
    }
    catch (std::domain_error izuzteka) {
        std::cout << izuzteka.what();
    }
    
    
    
	return 0;
}
