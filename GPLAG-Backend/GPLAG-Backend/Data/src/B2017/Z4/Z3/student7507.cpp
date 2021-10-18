/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <memory>
#include <tuple>
#include <utility>
#include <string>
#include <iomanip>
#include <algorithm>




class Datum
{
    int dan, mjesec, godina;
    friend class Pregled;
    int DajDan() const {
        return dan;
    }
    int DajMjesec() const{
        return mjesec;
    }
    int DajGodinu() const{
        return godina;
    }
public:
    Datum(int dan, int mjesec, int godina) {
        Postavi(dan,mjesec,godina);
    }
    void Postavi(int dan, int mjesec, int godina);
    std::tuple<int, int, int> Ocitaj() const;
    void Ispisi() const {
        std::cout << dan << "/" << mjesec << "/" << godina;
    }

};

void Datum::Postavi(int dan, int mjesec, int godina)
{
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0)
        broj_dana[1]++;
    if(godina < 1 || mjesec < 1 || mjesec > 12 || dan < 1 || dan > broj_dana[mjesec - 1])
        throw std::domain_error("Neispravan datum");
    Datum::dan=dan;
    Datum::mjesec=mjesec;
    Datum::godina=godina;

}

std::tuple<int, int, int> Datum::Ocitaj() const
{
    return std::make_tuple(dan, mjesec, godina);
}

//kraj klase datum 

class Vrijeme
{
    int sati, minute;
    friend class Pregled;
    int DajSati() const{
        return sati;
    }
    int DajMinute() const {
        return minute;
    }
public:
    Vrijeme(int sati, int minute) {
        Postavi(sati, minute);
    }
    void Postavi(int sati, int minute);
    std::pair<int, int> Ocitaj() const {
        return std::make_pair(sati, minute);
    }
    void Ispisi() const {
        std::cout << sati << ":" << minute;
    }
};

void Vrijeme::Postavi(int sati, int minute)
{
    if(sati < 0 || sati > 23 || minute < 0 || minute > 59)
        throw std::domain_error("Neispravno vrijeme");
    Vrijeme::sati=sati;
    Vrijeme::minute=minute;
}


class Pregled
{
    std::string ime_pac;
    Datum dat;
    Vrijeme vri;
    static int broj_p;
    friend class Datum;
    friend class Vrijeme;
    friend class Pregledi;
public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda):dat(datum_pregleda), vri(vrijeme_pregleda) {
        ime_pac=ime_pacijenta;
        broj_p++;
    }
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,
            int godina_pregleda, int sati_pregleda, int minute_pregleda):dat(dan_pregleda, mjesec_pregleda, godina_pregleda),vri(sati_pregleda, minute_pregleda) {
        ime_pac = ime_pacijenta;
        broj_p++;
    }
    void PromijeniPacijenta(const std::string &ime_pacijenta) {
        ime_pac = ime_pacijenta;
    }
    void PromijeniDatum(const Datum &novi_datum) {
        dat=novi_datum;
    }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme) {
        vri = novo_vrijeme;
    }
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImePacijenta() const {
        return ime_pac;
    }
    Datum DajDatumPregleda() const {
        return dat;
    }
    Vrijeme DajVrijemePregleda() const {
        return vri;
    }
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
    void Ispisi() const {
       std::cout << std::left << std::setw(30) << DajImePacijenta() << this->DajDatumPregleda().DajDan() << "/" << this->DajDatumPregleda().DajMjesec() << "/" << this->DajDatumPregleda().DajGodinu() << " " <<  this->DajVrijemePregleda().DajSati() << ":" << this->DajVrijemePregleda().DajMinute() << std::endl;
    }

};
int Pregled::broj_p=0;
void Pregled::PomjeriDanUnaprijed()
{
    int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
    int d,m,g;
    std::tuple<int, int, int> p(Pregled::dat.Datum::Ocitaj());
    std::tie(d,m,g)=p;
    if(g % 4 == 0 && g % 100 != 0 || g % 400 == 0)
        broj_dana[1]++;
    d++;
    if(d > broj_dana[m-1]) d=1, m++;
    if(m>12) m=1, g++;
    Pregled::dat.dan=d;
    Pregled::dat.mjesec=m;
    Pregled::dat.godina=g;
}

void Pregled::PomjeriDanUnazad()
{
    int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
    int d,m,g;
    std::tuple<int, int, int> p(Pregled::dat.Datum::Ocitaj());
    std::tie(d,m,g)=p;
    if(g % 4 == 0 && g % 100 != 0 || g % 400 == 0)
        broj_dana[1]++;
    d--;
    if(d < 1) {
        d=broj_dana[m-1];
        m--;
    }
    if(m<1) {
        d=broj_dana[11];
        m=12;
        g--;
    }
    Pregled::dat.dan=d;
    Pregled::dat.mjesec=m;
    Pregled::dat.godina=g;
}


static bool DolaziPrije(const Pregled &p1, const Pregled &p2)
{
    Datum dat1(p1.DajDatumPregleda());
    Datum dat2(p2.DajDatumPregleda());
    int d1,d2,m1,m2,g1,g2;
    std::tuple<int, int, int> o1(dat1.Ocitaj());
    std::tuple<int, int, int> o2(dat2.Ocitaj());
    std::tie(d1, m1, g1)= o1;
    std::tie(d2, m2, g2) = o2;
    if(g1 < g2) return true;
    if(g1==g2) {
        if(m1==m2) {
            if(d1 < d2) { return true;}
            else if(d1 == d2) {
                Vrijeme vri1(p1.DajVrijemePregleda());
                Vrijeme vri2(p2.DajVrijemePregleda());
                std::pair<int, int> k1(vri1.Ocitaj());
                std::pair<int, int> k2(vri2.Ocitaj());
                int sati1=std::get<0> (k1);
                int min1=std::get<1>(k1);
                int sati2=std::get<0>(k2);
                int min2=std::get<1>(k2);

                if(sati1 < sati2) return true;
                else if(sati1 == sati2) {
                    if(min1 < min2) return true;
                    return false;
                }
            }
            return false;
        } else if(m1 < m2 ) return true;
        return false;
    }
    return false ;
}


class Pregledi
{
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
        return Pregled::broj_p;
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
