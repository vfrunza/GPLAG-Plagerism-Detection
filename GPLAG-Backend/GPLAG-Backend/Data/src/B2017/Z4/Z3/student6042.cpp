/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include <iomanip>
#include <tuple>
#include <initializer_list>
#include <algorithm>
#include <vector>

class Datum{
    int d, m, g;
    public:
    Datum(int dan, int mjesec, int godina){ Postavi(dan, mjesec, godina);}
    void Postavi(int dan, int mjesec, int godina){
        int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(godina%4==0 && godina%100!=0 && godina%400==0) broj_dana[1]++;
        if(dan<1 || dan>broj_dana[mjesec-1] || mjesec<1 || mjesec>12 || godina<1) throw std::domain_error("Neispravan datum");
        Datum::d=dan; Datum::m=mjesec; Datum::g=godina;
    }
    
    std::tuple<int, int, int> Ocitaj() const{
        std::tuple<int, int, int> pomocni=std::make_tuple(d, m, g);
        
        return pomocni;
    }
    void Ispisi() const{
        std::cout<<d<<"/"<<m<<"/"<<g;
    }
};

class Vrijeme{
    int h, min;
    public:
    
    Vrijeme(int sati, int minute){Postavi(sati, minute);}
    void Postavi(int sati, int minute){
        if(sati<0 || sati>23 || minute<0 || minute>59) throw std::domain_error("Neispravno vrijeme");
        Vrijeme::h=sati; Vrijeme::min=minute;
    }
    
    std::pair<int, int> Ocitaj() const{
        
        std::pair<int, int> pomocni=std::make_pair(h, min);
        return pomocni;
    }
    
    void Ispisi() const{
        std::cout<<std::setw(2)<<std::setfill('0')<<h<<":"<<std::setw(2)<<std::setfill('0')<<min;
    }
};

class Pregled{
    std::string i_p;
    Datum dat;
    Vrijeme v;
    
    public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda):i_p(ime_pacijenta), dat(datum_pregleda), v(vrijeme_pregleda){}
    
    
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda): dat(dan_pregleda, mjesec_pregleda, godina_pregleda), v(sati_pregleda, minute_pregleda){
        Pregled::i_p=ime_pacijenta;
    }
    
    void PromijeniPacijenta(const std::string &ime_pacijenta){
        Pregled::i_p=ime_pacijenta;
    }
    
    void PromijeniDatum(const Datum &novi_datum){
        Pregled::dat=novi_datum;
    }
    
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme){
        Pregled::v=novo_vrijeme;
    }
    
    void PomjeriDanUnaprijed(){
        int g=std::get<2>(dat.Ocitaj());
        int m=std::get<1>(dat.Ocitaj());
        int d=std::get<0>(dat.Ocitaj());
        int broj_dana[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(g%4==0 && g%100!=0 && g%400==0) broj_dana[1]++;
        d++;
        if(d>broj_dana[m-1]) d=1, m++;
        if(m>12) m=1, g++;
    }
    
    void PomjeriDanUnazad(){
        int g=std::get<2>(dat.Ocitaj());
        int m=std::get<1>(dat.Ocitaj());
        int d=std::get<0>(dat.Ocitaj());
        int broj_dana[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(g%4==0 && g%100!=0 && g%400==0) broj_dana[1]++;
        d--;
        if(d==0) d=broj_dana[m-2]; m--;
        if(m==0) m=12; g--;
    }
    
    std::string DajImePacijenta() const{ return i_p;}
    Datum DajDatumPregleda() const { return dat;}
    Vrijeme DajVrijemePregleda() const { return v;}
    
    
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2){
        bool logicka(false);
        Datum dat1(p1.DajDatumPregleda());
        Datum dat2(p2.DajDatumPregleda());
        Vrijeme v1(p1.DajVrijemePregleda());
        Vrijeme v2(p2.DajVrijemePregleda());
        int g1=std::get<2>(dat1.Ocitaj());
        int m1=std::get<1>(dat1.Ocitaj());
        int d1=std::get<0>(dat1.Ocitaj());
        int g2=std::get<2>(dat2.Ocitaj());
        int m2=std::get<1>(dat2.Ocitaj());
        int d2=std::get<0>(dat2.Ocitaj());
        int h1=std::get<0>(v1.Ocitaj());
        int min1=std::get<1>(v1.Ocitaj());
        int h2=std::get<0>(v2.Ocitaj());
        int min2=std::get<1>(v2.Ocitaj());
        if(g1<g2) logicka=true;
        if(g1==g2){
           if(m1<m2){
               logicka=true;
           }
           else if(m1==m2){
               if(d1<d2){
                   logicka=true;
               }
               else if(d1==d2){
                   if(h1<h2){
                       logicka=true;
                   }
                   else if(h1==h2){
                       if(min1<min2) logicka=true;
                   }
               }
           }
        }
        return logicka;
    }
    
    
    void Ispisi() const{
        std::cout<<std::setw(30)<<std::left<<DajImePacijenta()<<" "; DajDatumPregleda().Ispisi(); std::cout<<" ";DajVrijemePregleda().Vrijeme::Ispisi(); std::cout<<std::endl;
    }
    
};

class Pregledi{
    int max_broj_pregleda, br_pregleda;
    Pregled **pok;
   
    public:
    explicit Pregledi(int max_broj_pregleda):max_broj_pregleda(max_broj_pregleda), br_pregleda(0), pok(new Pregled*[max_broj_pregleda]){}
    
    Pregledi(std::initializer_list<Pregled> spisak_pregleda):max_broj_pregleda(spisak_pregleda.size()), br_pregleda(spisak_pregleda.size()), pok(new Pregled*[spisak_pregleda.size()]){
        int brojac_alociranih(0);
        try{
            for(Pregled x: spisak_pregleda) pok[brojac_alociranih++]=new Pregled(x);
        }
        catch(...){
            for(int i=0; i<brojac_alociranih; i++) delete pok[i];
            throw;
        }
    }
    
    ~Pregledi(){ for(int i=0; i<br_pregleda; i++) delete [] pok[i]; delete [] pok;}
    
    Pregledi(const Pregledi &pregledi):max_broj_pregleda(pregledi.max_broj_pregleda), br_pregleda(pregledi.br_pregleda), pok(new Pregled*[pregledi.max_broj_pregleda]){
        std::copy(pregledi.pok, pregledi.pok+max_broj_pregleda, pok);
    }
    
    Pregledi (Pregledi &&pregledi): max_broj_pregleda(pregledi.max_broj_pregleda),br_pregleda(pregledi.br_pregleda), pok(pregledi.pok){ pregledi.pok=nullptr; pregledi.br_pregleda=0;}
    
    Pregledi &operator =(const Pregledi &pregledi){
        max_broj_pregleda=pregledi.max_broj_pregleda; 
        for(int i=0; i<pregledi.br_pregleda; i++) *pok[i]=*pregledi.pok[i];
        return *this;
    }
    
    Pregledi &operator = (Pregledi &&pregledi){
        std::swap(max_broj_pregleda, pregledi.max_broj_pregleda);
        std::swap(br_pregleda, pregledi.br_pregleda);
        std::swap(pok, pregledi.pok);
        return *this;
    }
    
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda){
        if(br_pregleda>=max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
        Pregled pomocna(ime_pacijenta, datum_pregleda, vrijeme_pregleda);
        *pok[br_pregleda++]=pomocna;
        br_pregleda++;
        std::sort(pok, pok+br_pregleda, [](Pregled *p1, Pregled *p2){return Pregled::DolaziPrije(*p1, *p2);});
    }
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan, int mjesec, int godina, int sati, int minute){
        if(br_pregleda==max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
        Datum datum_p(dan, mjesec, godina);
        Vrijeme v_p(sati, minute);
        Pregled p(ime_pacijenta, datum_p, v_p);
        *pok[br_pregleda++]=p;
        br_pregleda++;
        std::sort(pok, pok+br_pregleda, [](Pregled *p1, Pregled *p2){return Pregled::DolaziPrije(*p1, *p2);});
    }
    void RegistrirajPregled(Pregled *pregled){
        if(br_pregleda>=max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
        pok[br_pregleda]=pregled; 
        br_pregleda++;
        std::sort(pok, pok+br_pregleda, [](Pregled *p1, Pregled *p2){return Pregled::DolaziPrije(*p1, *p2);});
    }
    
    int DajBrojPregleda() const{ return br_pregleda;}
    int DajBrojPregledaNaDatum(const Datum &datum) const{
      int broj=std::count_if(pok, pok+br_pregleda, [datum] (Pregled *po){ 
          Datum datum1(po->DajDatumPregleda());
          int g=std::get<2>(datum1.Ocitaj());
          int m=std::get<1>(datum1.Ocitaj());
          int d=std::get<0>(datum1.Ocitaj());
          return (g==std::get<2>(datum.Ocitaj()) && m==std::get<1>(datum.Ocitaj()) && d==std::get<0>(datum.Ocitaj()));});
          return broj;
    }
    
    Pregled &DajNajranijiPregled(){
        if(br_pregleda==0) throw std::domain_error("Nema registriranih pregleda");
       auto p=std::min_element(pok, pok+br_pregleda, [](Pregled *p1, Pregled *p2){ 
            Datum d1(p1->DajDatumPregleda());
            Datum d2(p2->DajDatumPregleda());
            Vrijeme v1(p1->DajVrijemePregleda());
            Vrijeme v2(p2->DajVrijemePregleda());
            int h1=std::get<0>(v1.Ocitaj());
            int h2=std::get<0>(v2.Ocitaj());
            int minute1=std::get<1>(v1.Ocitaj());
            int minute2=std::get<1>(v2.Ocitaj());
            int g1=std::get<2>(d1.Ocitaj());
            int m1=std::get<1>(d1.Ocitaj());
            int dan1=std::get<0>(d1.Ocitaj());
            int g2=std::get<2>(d2.Ocitaj());
            int m2=std::get<1>(d2.Ocitaj());
            int dan2=std::get<0>(d2.Ocitaj());
            bool logicka;
            if(g1<g2) logicka=true;
            else if(g1==g2){
                if(m1<m2){ logicka=true;}
                else if(m1==m2){
                    if(dan1<dan2){ logicka=true;}
                    else if(dan1==dan2){
                        if(h1<h2) logicka=true;
                        else if(h1==h2){
                            if(minute1<minute2) logicka=true;
                            else logicka=false;
                        }
                    }
                }
            }
            return logicka;});
            return **p;
    }
    
    Pregled DajNajranijiPregled() const{
        if(br_pregleda==0) throw std::domain_error("Nema registriranih pregleda");
 
       auto p=std::min_element(pok, pok+br_pregleda, [] (Pregled *p1,Pregled *p2) {
            Datum d1(p1->DajDatumPregleda());
            Datum d2(p2->DajDatumPregleda());
            Vrijeme v1(p1->DajVrijemePregleda());
            Vrijeme v2(p2->DajVrijemePregleda());
            int g1=std::get<2>(d1.Ocitaj());
            int g2=std::get<2>(d2.Ocitaj());
            int m1=std::get<1>(d1.Ocitaj());
            int m2=std::get<1>(d2.Ocitaj());
            int dan1=std::get<0>(d1.Ocitaj());
            int dan2=std::get<0>(d2.Ocitaj());
            int h1=std::get<0>(v1.Ocitaj());
            int minute1=std::get<1>(v1.Ocitaj());
            int h2=std::get<0>(v2.Ocitaj());
            int minute2=std::get<1>(v2.Ocitaj());
              bool logicka;
            if(g1<g2) logicka=true;
            else if(g1==g2){
                if(m1<m2){ logicka=true;}
                else if(m1==m2){
                    if(dan1<dan2){ logicka=true;}
                    else if(dan1==dan2){
                        if(h1<h2) logicka=true;
                        else if(h1==h2){
                            if(minute1<minute2) logicka=true;
                            else logicka=false;
                        }
                    }
                }
            }
            return logicka;});
        return **p;
    }
    
    void IsprazniKolekciju(){
        for(int i=0; i<br_pregleda; i++){
            delete pok[i];
            pok[i]=nullptr;
        }
    }
    
    void ObrisiNajranijiPregled(){
        if(br_pregleda==0) throw std::range_error("Prazna kolekcija");       
        Pregled pregled=(DajNajranijiPregled());

       auto p=(std::find_if(pok, pok+br_pregleda, [pregled](Pregled *p){ 
            
            std::string ime1(pregled.DajImePacijenta());
            std::string ime2(p->DajImePacijenta());
            Datum d1(pregled.DajDatumPregleda());
            Datum d2(p->DajDatumPregleda());
            Vrijeme v1(pregled.DajVrijemePregleda());
            Vrijeme v2(p->DajVrijemePregleda());
            int h1=std::get<0>(v1.Ocitaj());
            int minute1=std::get<1>(v1.Ocitaj());
            int h2=std::get<0>(v2.Ocitaj());
            int minute2=std::get<1>(v2.Ocitaj());
            int g1=std::get<2>(d1.Ocitaj());
            int g2=std::get<2>(d2.Ocitaj());
            int m1=std::get<1>(d1.Ocitaj());
            int m2=std::get<1>(d2.Ocitaj());
            int dan1=std::get<0>(d1.Ocitaj());
            int dan2=std::get<0>(d2.Ocitaj());
            bool logicka;
            if(ime1==ime2 && g1==g2 && m1==m2 && dan1==dan2 && h1==h2 && minute1==minute2) logicka=true;
            return logicka;
        }));
        
        for(auto po=pok; po<pok+br_pregleda; po++){
            if(*po==*p) po=nullptr; br_pregleda--;
        }
        std::sort(pok, pok+br_pregleda, [](Pregled *p1, Pregled *p2){return Pregled::DolaziPrije(*p1, *p2);});
    }
    
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta){
        for(auto p=*pok; p<*pok+br_pregleda; p++) { 
            if(p->DajImePacijenta()==ime_pacijenta) p=nullptr; br_pregleda--;
        }
        
        std::sort(pok, pok+br_pregleda, [](Pregled *p1, Pregled *p2){return Pregled::DolaziPrije(*p1, *p2);});
    }
    
    void IspisiPregledeNaDatum(const Datum &datum) const{
        std::vector<Pregled> pomocni;
         for(auto p=*pok; p<*pok+br_pregleda; p++){ 
             Datum d1(p->DajDatumPregleda());
             int g1=std::get<2>(d1.Ocitaj());
             int m1=std::get<1>(d1.Ocitaj());
             int dan1=std::get<0>(d1.Ocitaj());
             int g2=std::get<2>(datum.Ocitaj());
             int m2=std::get<1>(datum.Ocitaj());
             int dan2=std::get<0>(datum.Ocitaj());
             if(g1==g2 && m1==m2 && dan1==dan2) pomocni.push_back(*p);
         }
         
         std::sort(pomocni.begin(), pomocni.end(), [](Pregled p1, Pregled p2){
        Vrijeme v1(p1.DajVrijemePregleda());
        Vrijeme v2(p2.DajVrijemePregleda());
        int h1=std::get<0>(v1.Ocitaj());
        int min1=std::get<1>(v1.Ocitaj());
        int h2=std::get<0>(v2.Ocitaj());
        int min2=std::get<1>(v2.Ocitaj());
        bool logicka(false);
       if(h1>h2) logicka=true;
       else if(h1==h2){
           if(min1>min2) logicka=true;
           else logicka=false;
       }
       return logicka;
        });
        for(int i=0; i<pomocni.size(); i++){
            pomocni[i].Ispisi();
        }
    }
    
    void IspisiSvePreglede() const{
        for(int i=0; i<br_pregleda; i++) (pok[i]->Pregled::Ispisi());
    }

    
};



int main ()
{
    std::cout<<"Unesite maksimalan broj pregleda: ";
    int broj_pregleda; 
    std::cin>>broj_pregleda;
    for(;;){
    std::string ime_novog_pacijenta;
    std::cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
    std::cin.getline(ime_novog_pacijenta, 100);
    if(ime_novog_pacijenta==kraj) break;
    std::cout<<"Unesite dan mjesec i godinu pregleda: ";
    int dan, mjesec, godina;
    std::cin>>dan>>mjesec>>godina;
    Datum datum(dan ,mjesec, godina);
    std::cout<<"Unesite sate i minute pregleda: ";
    int sati, minute;
    std::cin>>sati>>minute;
    Vrijeme vrijeme(sati, minute);
    }
    
	return 0;
}
