/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <string>
#include <new>
#include <memory>
#include <iomanip>

int bdum[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

class Datum {
    int dan,mjesec, godina;
    public:
       Datum(int d, int m, int g) {
           if(m<0 || m>12 || g<0) throw std::domain_error("Neispravan datum");
           if(g%4==0 && g%100!=0 || g%400==0) bdum[2]++;
           for(int i=1;i<=12;i++) {
               if(m==i) {
                   if(d<0 || d>bdum[i]) throw std::domain_error("Neispravan datum");
                   else {
                       dan=d;
                       mjesec=m;
                       godina=g;
                       break;
                   }
               }
           }
       }
        void Postavi(int day, int month, int year) {
            if(month<0 || month>12 || year<0) throw std::domain_error("Neispravan datum");
           if(year%4==0 && year%100!=0 || year%400==0) bdum[2]++;
           for(int i=1;i<=12;i++) {
               if(month==i) {
                   if(day<0 || day>bdum[i]) throw std::domain_error("Neispravan datum");
                   else {
                       dan=day;
                       mjesec=month;
                       godina=year;
                       break;
                   }
               }
        }   
       }
       
       std::tuple<int, int, int> Ocitaj() const {
           return std::make_tuple(dan, mjesec, godina);
       }
       
       void Ispisi() const {
           std::cout<<dan<<"/"<<mjesec<<"/"<<godina;
       }
};

class Vrijeme {
    int sati, minute;
    public:
    
       Vrijeme(int s, int m) {
           if(s<0 || s>23 || m<0 || m>59) throw std::domain_error("Neispravno vrijeme");
           sati=s;
           minute=m;
       }
       
       void Postavi(int s, int m) {
           if(s<0 || s>23 || m<0 || m>59) throw std::domain_error("Neispravno vrijeme");
           sati=s;
           minute=m;
       }
       
       std::pair<int, int> Ocitaj() const {
           return std::make_pair(sati, minute);
       }
       
       void Ispisi() const {
           if(sati<10) std::cout<<"0"<<sati<<":";
           else std::cout << sati;
           if(minute<10) std::cout <<"0"<<minute;
           else std::cout <<minute;
       }
};

class Pregled {
    std::string name;
    Datum date;
    Vrijeme times;
    public:
    
        Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) {
            name=ime_pacijenta;
            date=datum_pregleda;
            times=vrijeme_pregleda;
        }
        
        Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) {
            name=ime_pacijenta;
            date.Datum::Postavi(int dan_pregleda, int mjesec_pregleda, int godina_pregleda);
            times.Vrijeme::Postavi(int sati_pregleda, int minute_pregleda);
        }
        
        void PromijeniPacijenta(const std::string &ime_pacijenta) {
            name=ime_pacijenta;
        }
        
        void PromijeniDatum(const Datum &novi_datum) {
            date=novi_datum;
        }
        
        void PromijeniVrijeme(const Vrijeme &novo_vrijeme) {
            times=novo_vrijeme;
        }
        
        void PomjeriDanUnaprijed() {
            if(date.mjesec==12) {
                if(date.dan==31) {
                    date.dan=1;
                    date.Datum::mjesec=1;
                    date.godina+=1;
                }
            }
            int i;
            for(i=1;i<=12;i++) {
                if(date.dan==bdum[i]) {
                     date.dan=1;
                     date.mjesec+=1;
                     break;
                }
            }
            if(i==13) date.dan+=1;
        }
        
        void PomjeriDanUnazad() {
            if(date.mjesec==1) {
                if(date.dan==1) {
                    date.dan=31;
                    date.mjesec=12;
                    date.godina-=1;
                }
            }
            int i;
            for(i=2;i<=12;i++) {
                if(date.dan==1) {
                    date.dan=bdum[i-1];
                    date.mjesec-=1;
                    break;
                }
            }
            if(i==13) date.dan-=1;
        }
        
        std::string DajImePacijenta() const { return name; }
        Datum DajDatumPregleda() const { return date; }
        Vrijeme DajVrijemePregleda() const { return times; }
        
     static bool DolaziPrije(const Pregled &p1, const Pregled &p2) {
            if(p1.date.godina<p2.date.godina) return true;
            else if(p2.date.godina<p1.date.godina) return false;
            else {
                if(p1.date.mjesec<p2.date.mjesec) return true;
                else if(p2.date.mjesec<p1.date.mjesec) return false;
                else {
                    if(p1.date.dan<p2.date.dan) return true;
                    else if(p2.date.dan<p1.date.dan) return false;
                    else {
                        if(p1.times.sati<p2.times.sati) return true;
                        else if(p2.times.sati<p1.times.sati) return false;
                        else {
                            if(p1.times.minute<p2.times.minute) return true;
                            else if(p2.times.minute<p1.times.minute) return false;
                        }
                    }
                }
            }
        }
        
        void Ispisi() const {
            std::cout<<std::left<<std::setw(30)<<ime_pacijenta<<date.Ispisi()<<" "<<times.Ispisi();
        }
};

class Pregledi {
    Pregled **pok;
    int broj=0;
    public:
    
      explicit Pregledi(int max_broj_pregleda) {
          pok= new Pregled*[max_broj_pregleda];
      }
      
      Pregledi(std::initializer_list<Pregled> spisak_pregleda) {
          pok=new Pregled*[spisak_pregleda.size()];
          for(auto it=spisak_pregleda.begin(); it!=spisak_pregleda.end(); it++) pok[i]=new Pregled(*it);
      }
      
      ~Pregledi() {
          for(int i=0;i<;i++) delete[] pok[i];
          delete[] pok;
      }
      
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
int main ()
{
    
	return 0;
}
