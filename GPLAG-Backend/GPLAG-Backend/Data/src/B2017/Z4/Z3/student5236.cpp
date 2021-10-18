#include <iostream>
#include <tuple>
#include <stdexcept>
#include <utility>
#include <iomanip>
class Datum{
    int dan,mjesec,godina;
    public:
    Datum(int dan, int mjesec, int godina){ Postavi(dan,mjesec,godina);}
    void Postavi(int dan, int mjesec, int godina);
    std::tuple<int, int, int> Ocitaj() const;
    void Ispisi()const{
        std::cout<<dan<<"/"<<mjesec<<"/"<<godina;
    }
    friend class Pregled;
};
class Vrijeme{
    int sati,minute;
    public:
    Vrijeme(int sati, int minute){ Postavi(sati,minute); }
    void Postavi(int sati, int minute);
    std::pair<int, int> Ocitaj() const;
    void Ispisi()const;
    friend class Pregled;
};
class Pregled{
    std::string ime_pacijenta;
    Datum d_p=Datum(1,1,1);
    Vrijeme v_p=Vrijeme(1,1);
    public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda,
       const Vrijeme &vrijeme_pregleda);
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,
       int godina_pregleda, int sati_pregleda, int minute_pregleda);
   void PromijeniPacijenta(const std::string &ime_pacijenta){
       Pregled::ime_pacijenta=ime_pacijenta;
   }
   void PromijeniDatum(const Datum &novi_datum){
       d_p.dan=novi_datum.dan;d_p.mjesec=novi_datum.mjesec;d_p.godina=novi_datum.godina;
   }
   void PromijeniVrijeme(const Vrijeme &novo_vrijeme){
       v_p.sati=novo_vrijeme.sati;v_p.minute=novo_vrijeme.minute;
   }
   void PomjeriDanUnaprijed();
   void PomjeriDanUnazad();
   std::string DajImePacijenta() const{ return ime_pacijenta; }
   Datum DajDatumPregleda() const{ return d_p; }
   Vrijeme DajVrijemePregleda() const{ return v_p; }
   static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
   void Ispisi()const;
};

class Pregledi{
    const int max_br_pregleda;
    int broj_evidentiranih;
    Pregled **p;
    public:
    explicit Pregledi(int max_broj_pregleda):max_br_pregleda(max_broj_pregleda),
    broj_evidentiranih(0),p(new Pregled*[max_br_pregleda]{}){}
    ~Pregledi();
    Pregledi(const Pregledi &pregledi);
    Pregledi(Pregledi &&pregledi);
    Pregledi &operator =(const Pregledi &pregledi);
    Pregledi &operator =(Pregledi &&pregledi);
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda,
       const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(Pregled *pregled);
};
void Datum::Postavi(int dan, int mjesec, int godina){
    int broj_dana[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina%4==0 && godina%100!=0) || godina%400==0)broj_dana[1]++;
    if(godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>broj_dana[mjesec-1])
        throw std::domain_error("Neispravan datum");
    Datum::dan=dan;Datum::mjesec=mjesec;Datum::godina=godina;    
}
std::tuple<int, int, int> Datum::Ocitaj() const{
    std::tuple<int, int, int> d;
    std::get<0>(d)=dan;std::get<1>(d)=mjesec;std::get<2>(d)=godina;
    return d;
}
void Vrijeme::Postavi(int sati, int minute){
    if(sati<0 || sati>23 || minute<0 || minute>59)
       throw std::domain_error("Neispravno vrijeme");
    Vrijeme::sati=sati;Vrijeme::minute=minute;
}
std::pair<int, int> Vrijeme::Ocitaj() const{
    std::pair<int, int>v;
    v.first=sati;v.second=minute;
    return v;
}
void Vrijeme::Ispisi() const{
    if(sati<0 || sati>23 || minute<0 || minute>59)
       throw std::domain_error("Neispravno vrijeme!");
    if(sati<10 && minute>10){
        std::cout<<"0"<<sati<<":"<<minute;
    }else if(sati>10 && minute<10){
        std::cout<<sati<<":0"<<minute;
    }else if(sati<10 && minute<10){
        std::cout<<"0"<<sati<<":0"<<minute;
    }else{
        std::cout<<sati<<":"<<minute;
    }
}
Pregled::Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda,
    const Vrijeme &vrijeme_pregleda){
    Pregled::d_p.dan=datum_pregleda.dan;
    Pregled::d_p.mjesec=datum_pregleda.mjesec;
    Pregled::d_p.godina=datum_pregleda.godina;
    Pregled::v_p.sati=vrijeme_pregleda.sati;
    Pregled::v_p.minute=vrijeme_pregleda.minute;
    Pregled::ime_pacijenta=ime_pacijenta;
}
Pregled::Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,
   int godina_pregleda, int sati_pregleda, int minute_pregleda):
   d_p(dan_pregleda,mjesec_pregleda,godina_pregleda),
   v_p(sati_pregleda,minute_pregleda){
       Pregled::ime_pacijenta=ime_pacijenta;
   }

void Pregled::PomjeriDanUnaprijed(){
    int broj_dana[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(d_p.dan=broj_dana[d_p.mjesec-1] && d_p.mjesec<12){
        d_p.dan=1;
        d_p.mjesec+=1;
    }else if(d_p.dan=broj_dana[d_p.mjesec-1] && d_p.mjesec==12){
        d_p.dan=1;
        d_p.mjesec=1;
        d_p.godina+=1;
    }else{
        d_p.dan+=1;
    }
}
void Pregled::PomjeriDanUnazad(){
    int broj_dana[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(d_p.dan==1 && d_p.mjesec>1){
        d_p.dan=broj_dana[d_p.mjesec-1];
    }else if(d_p.dan==1 && d_p.mjesec==1){
        d_p.mjesec==12;
        d_p.dan=broj_dana[d_p.mjesec-1];
        d_p.godina-=1;
    }else{
        d_p.dan-=1;
    }
}
bool Pregled::DolaziPrije(const Pregled &p1, const Pregled &p2){
    bool a(true);
    if(p1.d_p.godina>p2.d_p.godina){
        a=false;
    }else if(p1.d_p.godina==p2.d_p.godina){
       if(p1.d_p.dan>p2.d_p.dan && p1.d_p.mjesec>p2.d_p.mjesec){
           a=false;
       }else if(p1.d_p.dan==p2.d_p.dan && p1.d_p.mjesec>p2.d_p.mjesec){
           a=false;
       }else if(p1.d_p.dan>p2.d_p.dan && p1.d_p.mjesec==p2.d_p.mjesec){
           a=false;
       }else if(p1.d_p.dan==p2.d_p.dan && p1.d_p.mjesec==p2.d_p.mjesec){
           a=false;
       }else{
           a=true;
       }
    }
    return a;
}
void Pregled::Ispisi()const{
    std::cout<<std::left<<std::setw(31)<<ime_pacijenta<<d_p.dan<<"/"<<d_p.mjesec<<"/"<<d_p.godina<<",";
    if(v_p.sati>10 && v_p.minute<10){
        std::cout<<v_p.sati<<":0"<<v_p.minute<<std::endl;
    }else if(v_p.sati<10 && v_p.minute>10){
        std::cout<<"0"<<v_p.sati<<":"<<v_p.minute<<std::endl;
    }else if(v_p.sati<10 && v_p.minute<10){
        std::cout<<"0"<<v_p.sati<<":0"<<v_p.minute<<std::endl;
    }else{
        std::cout<<v_p.sati<<":"<<v_p.minute<<std::endl;
    }
}
Pregledi::~Pregledi(){
    for(int i(0);i<broj_evidentiranih;i++)delete p[i];
    delete[] p;
}
Pregledi::Pregledi(const Pregledi &pregledi):max_br_pregleda(pregledi.max_br_pregleda),
    broj_evidentiranih(pregledi.broj_evidentiranih),p(new Pregled*[pregledi.max_br_pregleda]{}){}

Pregledi::Pregledi(Pregledi &&pregledi):max_br_pregleda(pregledi.max_br_pregleda),
   broj_evidentiranih(pregledi.broj_evidentiranih),p(pregledi.p){
       pregledi.broj_evidentiranih=0;pregledi.p=nullptr;
   }
Pregledi &Pregledi::operator=(const Pregledi &pregledi){
    if(pregledi.max_br_pregleda!=max_br_pregleda)
        throw std::logic_error("Nesaglasni pregledi!");
    if(pregledi.max_br_pregleda>max_br_pregleda){
        try{
            for(int i=broj_evidentiranih;i<pregledi.broj_evidentiranih;i++){
                p[i]=new Pregled(*pregledi.p[i]);
            }
        }
        catch(...){
            for(int i(0);i<broj_evidentiranih;i++){
            delete p[i];p[i]=nullptr;
            }
            throw;
        }
    }else{
        for(int i=pregledi.broj_evidentiranih;i<broj_evidentiranih;i++){
            delete p[i];p[i]=nullptr;
        }
    } 
    broj_evidentiranih=pregledi.broj_evidentiranih;
    for(int i(0);i<broj_evidentiranih;i++)*p[i]=*pregledi.p[i];
    return *this;
}
Pregledi &Pregledi::operator =(Pregledi &&pregledi){
    if(pregledi.max_br_pregleda!=max_br_pregleda)
    throw std::logic_error("Nesaglasni pregledi!");
    std::swap(broj_evidentiranih,pregledi.broj_evidentiranih);
    std::swap(p,pregledi.p);
    return *this;
}
void Pregledi::RegistrirajPregled(Pregled *pregled){
    if(broj_evidentiranih>=max_br_pregleda)
    throw std::range_error("Dostignut maksimalni broj pregleda");
    p[broj_evidentiranih++]=pregled;
}
int main(){
    
    return 0;
}