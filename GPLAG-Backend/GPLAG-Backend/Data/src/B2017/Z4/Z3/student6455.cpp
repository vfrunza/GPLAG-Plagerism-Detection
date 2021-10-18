/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <tuple>
#include <algorithm>
class Datum{
    int dan, mjesec, godina;
    public:
    friend class Pregled;
    friend class Pregledi;
    
    Datum(int dan, int mjesec, int godina);
    void Postavi(int dan, int mjesec, int godina);
    std::tuple<int, int, int> Ocitaj() const{
        std::tuple<int, int, int> t(dan, mjesec, godina);
        return t;
    }
    void Ispisi() const{
        std::cout<<dan<<"/"<<mjesec<<"/"<<godina;
    }
   friend bool operator==(const Datum &d1, const Datum &d2);
    
};
 bool operator==(const Datum &d1, const Datum &d2){
        return d1.dan==d2.dan && d1.mjesec==d2.mjesec && d1.godina==d2.godina;
    }
  Datum::Datum (int dan, int mjesec, int godina){
      int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
      if(godina%4==0 &&( godina%100!=0 || godina%400==0)) broj_dana[1]++;
      if(godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>broj_dana[mjesec-1]) throw std::domain_error("Neispravan datum");
      Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
  }
  void Datum::Postavi(int dan, int mjesec, int godina){
       int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
      if(godina%4==0 &&( godina%100!=0 || godina%400==0)) broj_dana[1]++;
      if(godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>broj_dana[mjesec-1]) throw std::domain_error("Neispravan datum");
      Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
  }
class Vrijeme{
    int sati;
    int minute;
    public:
    friend class Pregled;
    friend class Pregledi;
    friend bool operator==(const Vrijeme &v1, const Vrijeme &v2);
    Vrijeme(int sati, int minute);
    void Postavi(int sati, int minute);
    std::pair<int, int> Ocitaj () const{
        std::pair<int, int> t(sati, minute);
        return t;
    }
    void Ispisi() const{
        std::cout<<sati<<"::"<<minute;
    }
};
bool operator==(const Vrijeme &v1, const Vrijeme &v2){
        return v1.sati==v2.sati && v1.minute==v2.minute;
    }
  Vrijeme::Vrijeme(int sati, int minute){
      if(sati<0 || sati>23 || minute<0 || minute>59 ) throw std::domain_error("Neispravno vrijeme");
      Vrijeme::sati=sati; Vrijeme::minute=minute;
  }
  void Vrijeme::Postavi(int sati, int minute){
         if(sati<0 || sati>23 || minute<0 || minute>59 ) throw std::domain_error("Neispravno vrijeme");
      Vrijeme::sati=sati; Vrijeme::minute=minute;
  }
  
class Pregled{
    std::string ime_pacijenta;
    Vrijeme vrijeme_pregleda;
    Datum datum_pregleda;
    public:
    friend class Pregledi;
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda,
    const Vrijeme &vrijeme_pregleda):ime_pacijenta(ime_pacijenta), datum_pregleda(datum_pregleda), vrijeme_pregleda(vrijeme_pregleda){}
    friend bool operator == (const Pregled &p1, const Pregled &p2);
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,
     int godina_pregleda, int sati_pregleda, int minute_pregleda):ime_pacijenta(ime_pacijenta), datum_pregleda(dan_pregleda,mjesec_pregleda,godina_pregleda),
     vrijeme_pregleda(sati_pregleda,minute_pregleda){}
    void PromijeniPacijenta(const std::string &ime_pacijenta){
        Pregled::ime_pacijenta=ime_pacijenta;
    }
    void PromijeniDatum(const Datum &novi_datum){
        Pregled::datum_pregleda=novi_datum;
    }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme){
        Pregled::vrijeme_pregleda=novo_vrijeme;
    }
    void PomjeriDanUnaprijed(){
         int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
      if(datum_pregleda.godina%4==0 &&( datum_pregleda.godina%100!=0 || datum_pregleda.godina%400==0)) broj_dana[1]++;
      datum_pregleda.dan++;
      if(datum_pregleda.dan>broj_dana[datum_pregleda.mjesec-1]) datum_pregleda.dan=1, datum_pregleda.mjesec++;
      if(datum_pregleda.mjesec>12 ) datum_pregleda.mjesec=1, datum_pregleda.godina++;
    }
    void PomjeriDanUnazad(){
         int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
      if(datum_pregleda.godina%4==0 && (datum_pregleda.godina%100!=0 || datum_pregleda.godina%400==0)) broj_dana[1]++;
      datum_pregleda.dan--;
      if(datum_pregleda.dan<1) {datum_pregleda.mjesec--; datum_pregleda.dan=broj_dana[datum_pregleda.mjesec];}
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
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2){
        if(p1.datum_pregleda.godina==p2.datum_pregleda.godina){
            if(p1.datum_pregleda.mjesec==p2.datum_pregleda.mjesec){
                if(p1.datum_pregleda.dan==p2.datum_pregleda.dan){
                    if(p1.vrijeme_pregleda.sati==p2.vrijeme_pregleda.sati){
                        if(p1.vrijeme_pregleda.minute==p2.vrijeme_pregleda.minute){
                            return false;
                        }
                        return p1.vrijeme_pregleda.minute<p2.vrijeme_pregleda.minute;
                    }
                    return p1.vrijeme_pregleda.sati<p2.vrijeme_pregleda.sati;
                }
                return p1.datum_pregleda.dan<p2.datum_pregleda.dan;
            }
            return p1.datum_pregleda.mjesec<p2.datum_pregleda.mjesec;
        }
        return p1.datum_pregleda.godina<p2.datum_pregleda.godina;
    }
    void Ispisi() const{
        std::cout<<std::setw(30)<<std::left<<ime_pacijenta<<datum_pregleda.dan<<"/"<<datum_pregleda.mjesec<<"/"<<datum_pregleda.godina<<"/"<<" "<<vrijeme_pregleda.sati<<":"<<vrijeme_pregleda.minute<<std::endl;
    }
};
bool operator == (const Pregled &p1, const Pregled &p2){
        return p1.ime_pacijenta==p2.ime_pacijenta && p1.vrijeme_pregleda==p2.vrijeme_pregleda  &&
        p1.datum_pregleda==p2.datum_pregleda ;
    }
class Pregledi{
    Pregled** pok_na_niz;
    int max_broj_pregleda;
    int broj_pregleda;
    void OslobodiMemoriju(Pregled** pok, int broj){
	if(!pok) return;
	for(int i=0;i<broj;i++) delete pok[i];
	delete[] pok;
     }
    
    public:
    explicit Pregledi(int max_broj_pregleda):max_broj_pregleda(max_broj_pregleda),broj_pregleda(0), pok_na_niz(new Pregled*[max_broj_pregleda]{}){}
   
    Pregledi(std::initializer_list<Pregled> spisak_pregleda): max_broj_pregleda(spisak_pregleda.size()),broj_pregleda(spisak_pregleda.size()), pok_na_niz(new Pregled*[spisak_pregleda.size()]{}){
       int i(0);
        for(auto it(spisak_pregleda.begin()); it!=spisak_pregleda.end();it++){
            pok_na_niz[i++]=new Pregled(*it);
        }
    }
    ~Pregledi(){
        OslobodiMemoriju(pok_na_niz,max_broj_pregleda );
    }
    Pregledi(const Pregledi &pregledi):max_broj_pregleda(pregledi.max_broj_pregleda), broj_pregleda(pregledi.broj_pregleda), pok_na_niz(new Pregled*[pregledi.max_broj_pregleda]{}){
        for(int i=0;i<pregledi.broj_pregleda;i++){
            pok_na_niz[i]=new Pregled(*pregledi.pok_na_niz[i]);
        }
    }
    
    
    Pregledi(Pregledi &&pregledi):max_broj_pregleda(pregledi.max_broj_pregleda){
        broj_pregleda=pregledi.broj_pregleda;
        pok_na_niz=pregledi.pok_na_niz;
        pregledi.pok_na_niz=nullptr;
        pregledi.broj_pregleda=0;
    }
    Pregledi &operator =(const Pregledi &pregledi){
        OslobodiMemoriju(pok_na_niz, broj_pregleda);
        broj_pregleda=pregledi.broj_pregleda;
        pok_na_niz=new Pregled*[max_broj_pregleda]{};
        for(int i=0;i<broj_pregleda;i++){
            pok_na_niz[i]=new Pregled(*pregledi.pok_na_niz[i]);
        }
        return *this;
    }
    Pregledi &operator =(Pregledi &&pregledi){
        std::swap(broj_pregleda, pregledi.broj_pregleda);
        std::swap(pok_na_niz, pregledi.pok_na_niz);
        return *this;
    }
   
    void RegistrirajPregled(const std::string &ime_pacijenta,
    const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda){
        if(broj_pregleda==max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
        broj_pregleda++;
        pok_na_niz[broj_pregleda]=new Pregled(ime_pacijenta, datum_pregleda, vrijeme_pregleda);
    }
    
    
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,
    int mjesec_pregleda, int godina_pregleda, int sati_pregleda,
     int minute_pregleda){
         if(broj_pregleda==max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
         broj_pregleda++;
         Pregled* pok(new Pregled(ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda));
         for(int i=0;i<broj_pregleda;i++){
             if(pok_na_niz[i]==nullptr){
                 pok_na_niz[i]=pok;
                 break;
             }
         }
     }
    void RegistrirajPregled(Pregled *pregled){
        if(broj_pregleda==max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
        broj_pregleda++;
        for(int i=0;i<broj_pregleda;i++){
             if(pok_na_niz[i]==nullptr){
                 pok_na_niz[i]=pregled;
                 break;
             }
         }
    }
    int DajBrojPregleda() const{
        return broj_pregleda;
    }    
    
    
    
    int DajBrojPregledaNaDatum(const Datum &datum) const{
       int broj=std::count_if(&pok_na_niz[0], &pok_na_niz[broj_pregleda], [&datum](Pregled* p1){
            
      if(p1->datum_pregleda.godina==datum.godina){
            if(p1->datum_pregleda.mjesec==datum.mjesec){
                if(p1->datum_pregleda.dan==datum.dan){
                   
                return true;
            }
            return false;
        }
        return false;
    }
    return false;
    });
        return  broj;
    }

    Pregled &DajNajranijiPregled(){
        if(broj_pregleda==0) throw std::domain_error("Nema registriranih pregleda");
        Pregled** pok=std::min_element(&pok_na_niz[0], &pok_na_niz[broj_pregleda], [](Pregled* p1, Pregled* p2){
            
        if(p1->datum_pregleda.godina==p2->datum_pregleda.godina){
            if(p1->datum_pregleda.mjesec==p2->datum_pregleda.mjesec){
                if(p1->datum_pregleda.dan==p2->datum_pregleda.dan){
                    if(p1->vrijeme_pregleda.sati==p2->vrijeme_pregleda.sati){
                        if(p1->vrijeme_pregleda.minute==p2->vrijeme_pregleda.minute){
                            return false;
                        }
                        return p1->vrijeme_pregleda.minute<p2->vrijeme_pregleda.minute;
                    }
                    return p1->vrijeme_pregleda.sati<p2->vrijeme_pregleda.sati;
                }
                return p1->datum_pregleda.dan<p2->datum_pregleda.dan;
            }
            return p1->datum_pregleda.mjesec<p2->datum_pregleda.mjesec;
        }
        return p1->datum_pregleda.godina<p2->datum_pregleda.godina;
    
            
        });
        return **pok;
    }
    Pregled DajNajranijiPregled() const{
         if(broj_pregleda==0) throw std::domain_error("Nema registriranih pregleda");
        Pregled** pok=std::min_element(&pok_na_niz[0], &pok_na_niz[broj_pregleda], [](Pregled* p1, Pregled* p2){
            
        if(p1->datum_pregleda.godina==p2->datum_pregleda.godina){
            if(p1->datum_pregleda.mjesec==p2->datum_pregleda.mjesec){
                if(p1->datum_pregleda.dan==p2->datum_pregleda.dan){
                    if(p1->vrijeme_pregleda.sati==p2->vrijeme_pregleda.sati){
                        if(p1->vrijeme_pregleda.minute==p2->vrijeme_pregleda.minute){
                            return false;
                        }
                        return p1->vrijeme_pregleda.minute<p2->vrijeme_pregleda.minute;
                    }
                    return p1->vrijeme_pregleda.sati<p2->vrijeme_pregleda.sati;
                }
                return p1->datum_pregleda.dan<p2->datum_pregleda.dan;
            }
            return p1->datum_pregleda.mjesec<p2->datum_pregleda.mjesec;
        }
        return p1->datum_pregleda.godina<p2->datum_pregleda.godina;
    
            
        });
        return **pok;
    }
    void IsprazniKolekciju(){
        OslobodiMemoriju(pok_na_niz, broj_pregleda);
        max_broj_pregleda=max_broj_pregleda;
        broj_pregleda=0;
        pok_na_niz=new Pregled*[max_broj_pregleda]{};
    }
    void ObrisiNajranijiPregled(){
        if(broj_pregleda==0) throw std::range_error("Prazna kolekcija");
       
        for(int i=0;i<broj_pregleda;i++){
            if((*pok_na_niz[i])==DajNajranijiPregled())
            {
                delete pok_na_niz[i];
                pok_na_niz[i]=nullptr;
                broj_pregleda--;
                break;
            }
        }
    }
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta){
        for(int i=0;i<broj_pregleda;i++){
            if(pok_na_niz[i]->ime_pacijenta==ime_pacijenta){
                 delete pok_na_niz[i];
                pok_na_niz[i]=nullptr;
                broj_pregleda--;
                break;
            }
        }
    }

    void IspisiPregledeNaDatum(const Datum &datum) const{
     std::sort(&pok_na_niz[0], &pok_na_niz[broj_pregleda],[](Pregled* p1, Pregled* p2){
         if(p1->vrijeme_pregleda.sati==p2->vrijeme_pregleda.sati){
                        if(p1->vrijeme_pregleda.minute==p2->vrijeme_pregleda.minute){
                            return false;
                        }
                        return p1->vrijeme_pregleda.minute<p2->vrijeme_pregleda.minute;
                    }
                    return p1->vrijeme_pregleda.sati<p2->vrijeme_pregleda.sati;
     });
     for(int i=0;i<broj_pregleda;i++){
         if((*pok_na_niz[i]).datum_pregleda==datum){
             pok_na_niz[i]->Ispisi();
         }
     }
    }
    void IspisiSvePreglede() const{
        std::sort(&pok_na_niz[0], &pok_na_niz[broj_pregleda],[](Pregled* p1, Pregled* p2){
         if(p1->vrijeme_pregleda.sati==p2->vrijeme_pregleda.sati){
                        if(p1->vrijeme_pregleda.minute==p2->vrijeme_pregleda.minute){
                            return false;
                        }
                        return p1->vrijeme_pregleda.minute<p2->vrijeme_pregleda.minute;
                    }
                    return p1->vrijeme_pregleda.sati<p2->vrijeme_pregleda.sati;
     });
     for(int i=0;i<broj_pregleda;i++){
             (*pok_na_niz[i]).Ispisi();
         }
     
    }

};
int main ()
{
    std::cout<<"Unesite maksimalan broj pregleda: ";
    int max_broj_pregleda(0);
    std::cin>>max_broj_pregleda;
    std::string tekst;
    std::string s{"kraj"};
    Pregledi pregled(max_broj_pregleda); 
    int mjesec(0);
    int godina(0);
    int sati(0);
    int minute(0);
    int dan(0);
   std::cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
    std::getline(std::cin, tekst);
    if(tekst!=s){
    do{
    std::cout<<"Unesite dan mjesec i godinu pregleda: ";
    std::cin>>dan>>mjesec>>godina;
    std::cout<<"Unesite sate i minute pregleda: ";
    std::cin>>sati>>minute;
     Datum d(dan,mjesec,godina);
        Vrijeme v(sati,minute);
        Pregled* p=new Pregled(tekst,d,v); 
    pregled.RegistrirajPregled(p);
    std::cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
            std::getline(std::cin, tekst);
        
       
        }while(tekst!=s);
    }
    std::cout<< "Trenutno su registrovani sljedeci pregledi\n";
    pregled.IspisiSvePreglede();

   int broj(0);
   do{
    std::cout<<"Odaberite jednu od sljedecih opcija\n";
    std::cout<<"1 - Broj pregleda na datum\n";
    std::cout<<"2 - Najraniji pregled\n";
    std::cout<<"3 - Obrisi pregled pacijenta\n";
    std::cout<<"4 - Obrisi najraniji pregled\n";
    std::cout<<"5 - Ispisi sve pregleda na datum\n";
    std::cout<<"6 - Ispisi sve preglede\n";
    std::cout<<"7 - Kraj programa\n";   
    std::cin>>broj;
    if(broj==1){
        std::cout<<"Unesite dan mjesec i godinu : ";
        std::cin>>dan>>mjesec>>godina;
        Datum datum(dan, mjesec, godina);
        int broj_pregleda=pregled.DajBrojPregledaNaDatum(datum);
        std::cout<<"Broj pregleda na datum "<<dan<<" "<<mjesec<<" "<<godina<<" je: "<<broj_pregleda<<std::endl;
    }
    if(broj==2){
        std::cout<<"Najraniji pregled je: \n";
        Pregled pre(pregled.DajNajranijiPregled());
        pre.Ispisi();
    }
    std::string s;
    if(broj==3){
        std::cout<<"Unesite ime pacijenta: ";
        std::getline(std::cin, s);
       pregled.ObrisiPregledePacijenta(s);
    }
    if(broj==4){
        pregled.ObrisiNajranijiPregled();
        std::cout<<"Najraniji pregled uspjesno obrisan\n";
    }
    int d,m,g;
    if(broj==5){
        std::cout<<"Unesite dan mjesec i godinu: ";
        std::cin>>d>>m>>g;
        std::cout<<"Pregledi na datum "<<d<<" "<<m<<" "<<g<<"su:\n";
        Datum dat(d,m,g);
        pregled.IspisiPregledeNaDatum(dat);
        
    }
    if(broj==6){
        pregled.IspisiSvePreglede();
    }
     }while(broj!=7);
	return 0;
}
