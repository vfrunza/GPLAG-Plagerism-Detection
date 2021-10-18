/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <tuple>
#include <stdexcept>
#include <initializer_list>
#include <algorithm>

class Datum{
    int dan,mjesec,godina;
        public:
        
    Datum(int dan, int mjesec, int godina){
        this->dan=dan;
        this->mjesec=mjesec;
        this->godina=godina;
    }
    
    Datum(const Datum &datum){
        std::tuple<int,int,int> a=datum.Ocitaj();
        dan=std::get<0>(a);
        mjesec=std::get<1>(a);
        godina=std::get<2>(a);
        
    } 
    
    void Postavi(int dan, int mjesec, int godina){
         int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
         if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0) broj_dana[1]++;
         if(godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > broj_dana[mjesec - 1]) throw std::domain_error("Neispravan datum!");
         this->dan = dan;
         this->mjesec = mjesec;
         this->godina = godina;
    }
    
    std::tuple<int, int, int> Ocitaj() const{
        return std::make_tuple(dan,mjesec,godina);
    }
    
    void Ispisi() const{
        std::cout << dan<<" /"<<mjesec<<" /"<<godina ;
    }
    
};

class Vrijeme{
  int sati, minute;
  public:
Vrijeme(int sati, int minute){
    this->sati=sati;
    this->minute=minute;
}
Vrijeme(const Vrijeme &vrijeme){
    std::pair<int,int> par =vrijeme.Ocitaj();
    sati=par.first;
    minute=par.second;
    
}

void Postavi(int sati, int minute){
    if(sati<0 || sati>23 || minute<0 ||minute>59) throw std::domain_error("Neispravno vrijeme");
sati=sati;
minute=minute;
}

std::pair<int, int> Ocitaj () const{
    return std::make_pair(sati,minute);
}
void Ispisi() const{
    std::cout << sati<<" : "<<minute << std::endl;
}
};



class Pregled{
    std::string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;
    
    public:
         Pregled():datum_pregleda(1,1,1),vrijeme_pregleda(0,0){
             this->ime_pacijenta="";
         }
        Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda,const Vrijeme &vrijeme_pregleda):datum_pregleda(datum_pregleda),vrijeme_pregleda(vrijeme_pregleda){
            this->ime_pacijenta=ime_pacijenta;
        }
        Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,int godina_pregleda, int sati_pregleda, int minute_pregleda):
        datum_pregleda(dan_pregleda,mjesec_pregleda,godina_pregleda),vrijeme_pregleda(sati_pregleda,minute_pregleda){
            this->ime_pacijenta=ime_pacijenta;
         
        }
        void PromijeniPacijenta(const std::string &ime_pacijenta){
            this->ime_pacijenta=ime_pacijenta;
        }
        void PromijeniDatum(const Datum &novi_datum){
            datum_pregleda=novi_datum;
        }
        void PromijeniVrijeme(const Vrijeme &novo_vrijeme){
            vrijeme_pregleda=novo_vrijeme;
        }
        void PomjeriDanUnaprijed(){
            int dan,mjesec,godina;
            int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
            
            std::tuple<int,int,int> datum;
            datum=datum_pregleda.Ocitaj();
            godina=std::get<2>(datum);
            mjesec=std::get<1>(datum);
            dan=std::get<0>(datum);
            dan++;
            if((godina %4==0 && godina%100!=0)|| godina%400==0) broj_dana[1]++;
            if(broj_dana[mjesec-1]<dan){dan=1; mjesec++;}
            if(mjesec>12){godina++; mjesec=1;}
            datum_pregleda.Postavi(dan,mjesec,godina);  
           // datum_pregleda.Ispisi();
        }
        void PomjeriDanUnazad(){
            int dan, mjesec,godina;
            int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
            std::tuple<int,int,int>(datum);
            datum=datum_pregleda.Ocitaj();
            dan=std::get<0>(datum);
            mjesec=std::get<1>(datum);
            godina=std::get<2>(datum);
            dan--;
            if((godina%4==0 && godina%100!=0)||godina%400==0) broj_dana[1]++;
            if(dan<1){
                if(mjesec>1){mjesec--; dan=broj_dana[mjesec-1];}
                else{
                    mjesec=12; godina--; dan=broj_dana[mjesec-1];
                }
            }
            datum_pregleda.Postavi(dan,mjesec,godina);
            //datum_pregleda.Ispisi();
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
              int dan1,dan2,mjesec1,mjesec2,godina1,godina2;
            std::tuple<int,int,int>datum1;
            std::tuple<int,int,int>datum2;
            datum1=p1.datum_pregleda.Ocitaj();
            datum2=p2.datum_pregleda.Ocitaj();
            
             dan1=std::get<0>(datum1);
            mjesec1=std::get<1>(datum1);
            godina1=std::get<2>(datum1);
            
             dan2=std::get<0>(datum2);
            mjesec2=std::get<1>(datum2);
            godina2=std::get<2>(datum2);
       
            if(dan1<=dan2 && mjesec1<=mjesec2 && godina1<=godina2) return true;
            
            return false;
        }
        
        void Ispisi() const{
            std::cout<< ime_pacijenta<< "  , ";
            datum_pregleda.Ispisi();
            std::cout<< "  , ";
            vrijeme_pregleda.Ispisi();
            std::cout<<std::endl;
        }
};



class Pregledi{
    Pregled *pregledi;
    int broj_pregleda;
    int max_broj_pregleda;

public:
explicit Pregledi(int _max_broj_pregleda):pregledi(new Pregled[_max_broj_pregleda]()),broj_pregleda(0),max_broj_pregleda(_max_broj_pregleda){}
Pregledi(std::initializer_list<Pregled> spisak_pregleda):pregledi(new Pregled[spisak_pregleda.size()]){
    
        std::copy(spisak_pregleda.begin(),spisak_pregleda.end(),pregledi);
        this->broj_pregleda=spisak_pregleda.size();
        this->max_broj_pregleda=spisak_pregleda.size();
    }
~Pregledi(){
    for(int i=0;i<broj_pregleda;i++){
    delete pregledi;
    }
    delete [] pregledi;
    
}
Pregledi(const Pregledi &pregledi):pregledi(new Pregled[pregledi.broj_pregleda]),broj_pregleda(pregledi.broj_pregleda),max_broj_pregleda(pregledi.max_broj_pregleda){
    std::copy(pregledi.pregledi, pregledi.pregledi+pregledi.broj_pregleda, this->pregledi);
}
Pregledi(Pregledi &&pregledi):pregledi(pregledi.pregledi),broj_pregleda(pregledi.broj_pregleda),max_broj_pregleda(pregledi.max_broj_pregleda){
    pregledi.pregledi=nullptr;
}
//Pregledi &operator =(const Pregledi &pregledi){
 //   Pregled *novi_pregled(new Pregled[pregledi.broj_pregleda])
//}
/* Pregledi &operator =(Pregledi &&pregledi){
     std::swap(pregledi,pregledi.pregledi);
     std::swap(broj_pregleda,pregledi.broj_pregleda);
 return *this;
}*/
void RegistrirajPregled(const std::string &ime_pacijenta,const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda){
    if(broj_pregleda<max_broj_pregleda){
    Pregled Pomocni=Pregled(ime_pacijenta,datum_pregleda,vrijeme_pregleda);
    pregledi[broj_pregleda]=Pomocni;
    broj_pregleda++;
    }
    else throw std::range_error("kapacitet popunjen");
}
void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,int mjesec_pregleda, int godina_pregleda, int sati_pregleda,int minute_pregleda);
void RegistrirajPregled(Pregled *pregled){
    
}
int DajBrojPregleda() const{
    return broj_pregleda;
}
int DajBrojPregledaNaDatum(const Datum &datum) const;
Pregled &DajNajranijiPregled();
Pregled DajNajranijiPregled() const;
void IsprazniKolekciju();
void ObrisiNajranijiPregled();
void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
void IspisiPregledeNaDatum(const Datum &datum) const;
void IspisiSvePreglede() const{
    for(int i=0;i<broj_pregleda;i++){
        pregledi[i].Ispisi();
    }
}
};
int main ()
{
    Datum Prvi=Datum(1,3,2005);
    Prvi.Ispisi();
    
    Datum Drugi=Datum(1,1,2003);
    Drugi.Ispisi();
    
    Vrijeme Prvo=Vrijeme(00,11);
    Prvo.Ispisi();
    
    Pregled Pregled1=Pregled("Hamo husic",Prvi,Prvo);
  //  Pregled1.Ispisi();
   
   
    Pregled Pregled2 =Pregled("Hamo puzic",Drugi,Prvo);
    //Pregled2.Ispisi();
    
    Pregled1.PomjeriDanUnazad();
    //Pregled1.Ispisi();
     try{
     
     Pregledi MojiPregledi= Pregledi(2);
     MojiPregledi.RegistrirajPregled("Hamo Sehic",Prvi,Prvo);
     MojiPregledi.RegistrirajPregled("Hamo Sehip",Prvi,Prvo);
     
     MojiPregledi.IspisiSvePreglede();
     std::cout << "svi pregledi" << std::endl;
     
     
     MojiPregledi.RegistrirajPregled("Hamo Sehic",Prvi,Prvo);
     }catch(std::exception &e){
         std::cout<<e.what();
     }
     std::cout<<std::endl;
    std::cout << "prije: " << std::boolalpha<<Pregled::DolaziPrije(Pregled1,Pregled2);
    
    Pregledi Temp={Pregled1,Pregled2};
    Temp.IspisiSvePreglede();
    
    Pregledi kopirani = Pregledi(Temp);
    std::cout<<"kopirani"<<std::endl;
    kopirani.IspisiSvePreglede();
    
    
    Pregledi MojiPregledi= Pregledi(2);
     MojiPregledi.RegistrirajPregled("Hamo Sehic",Prvi,Prvo);
     MojiPregledi.RegistrirajPregled("Hamo Sehip",Prvi,Prvo);
    std::cout<<"pomjesrajuci :";
    Pregledi novi(std::move(MojiPregledi));
    novi.IspisiSvePreglede();
	return 0;
}
