/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <utility>
#include <string>
#include <iomanip>

class Datum {
  int d, m, g;
  int DajDan () const { return d; }
  int DajMjesec() const{ return m; }
  int DajGod() const { return g; }
  
  friend class Pregled;
  public:
  Datum (int dan, int mjesec, int godina) { Postavi (dan, mjesec, godina); } 
  void Postavi (int dan, int mjesec, int godina);
  std::tuple<int, int, int> Ocitaj() const { return std::make_tuple(d,m,g); }
  void Ispisi() { std::cout << d << "/" << m << "/" << g; }
  
};

void Datum::Postavi (int dan, int mjesec, int godina) {
  int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
  if (godina%4==0 && godina%100!=0 || godina%400==0) broj_dana[1]++;
  if (godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>broj_dana[mjesec-1])
     throw std::domain_error ("Neispravan datum");
  d=dan; m=mjesec; g=godina;
}

class Vrijeme {
  int h, m;
  int DajSat() const{return h; }
  int DajMin() const{return m; }
  friend class Pregled;
  public:
  Vrijeme (int sati, int minute) { Postavi(sati, minute); }
  void Postavi(int sati, int minute);
  std::pair<int, int> Ocitaj() const { return std::make_pair(h,m); }
  void Ispisi() const {std::cout << h << ":" << m; }
};

void Vrijeme::Postavi(int sati, int minute) {
  if (sati<0 || sati>23 || minute<0 || minute>59) throw std::domain_error ("Neispravno vrijeme");
  h=sati; m=minute;
}

class Pregled {
  std::string ime;
  Datum dat;
  Vrijeme  vr;
  static int brojac;
  
  public:
  Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda,
          const Vrijeme &vrijeme_pregleda): dat(datum_pregleda), vr(vrijeme_pregleda) { ime=ime_pacijenta; brojac++;}
       
  Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,
          int godina_pregleda, int sati_pregleda, int minute_pregleda): dat(dan_pregleda, mjesec_pregleda, godina_pregleda), vr(sati_pregleda, minute_pregleda) {
            ime=ime_pacijenta; brojac++;
          }
          
  void PromijeniPacijenta(const std::string &ime_pacijenta) {  ime=ime_pacijenta; } 
  void PromijeniDatum(const Datum &novi_datum) { dat=novi_datum; }
  void PromijeniVrijeme(const Vrijeme &novo_vrijeme) { vr=novo_vrijeme; }
  void PomjeriDanUnaprijed();
  void PomjeriDanUnazad();
  std::string DajImePacijenta() const {return ime;}
  Datum DajDatumPregleda() const {return dat;}
  Vrijeme DajVrijemePregleda() const { return vr; }
  static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
  void Ispisi() const {
    std::cout << std::left << std::setw(30) << DajImePacijenta() << this->DajDatumPregleda().DajDan() <<
      "/"<<this->DajDatumPregleda().DajMjesec()<<"/"<<this->DajDatumPregleda().DajGod()<<   " " << this->DajVrijemePregleda().DajSat() <<
      ":" << this->DajVrijemePregleda().DajMin() <<  std::endl;
  }
  friend class Pregledi;
};
int Pregled::brojac=0;

void Pregled::PomjeriDanUnaprijed() {
  int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
  Datum datic(Pregled::dat);
  std::tuple<int, int, int> t(datic.Ocitaj()); int day=std::get<0>(t), mon=std::get<1>(t), year=std::get<2>(t); 
  if (year%4==0 && year%100!=0 || year%400==0) broj_dana[1]++;
  day++;
  if (day>broj_dana[mon-1]) day=1, mon++;
  if (mon>12) mon=1, year++; 
  
  Pregled::dat.d=day; Pregled::dat.m=mon; Pregled::dat.g=year;
  
}

void Pregled::PomjeriDanUnazad() {
  int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
  Datum datic(Pregled::dat);
  std::tuple<int, int, int> t(datic.Ocitaj()); int day=std::get<0>(t), mon=std::get<1>(t), year=std::get<2>(t);
  if (year%4==0 && year%100!=0 || year%400==0) broj_dana[1]++;
  day--;
  if (day<1) {
    day=broj_dana[mon-1];
    mon--;
  }
  if (mon<1) {
    day=broj_dana[11];
    mon=12;
    year--;
  }
  
  Pregled::dat.d=day; Pregled::dat.m=mon; Pregled::dat.g=year;
} 

static bool DolaziPrije (const Pregled &p1, const Pregled &p2) {
  Datum datic1(p1.DajDatumPregleda()), datic2(p2.DajDatumPregleda());
  std::tuple<int, int, int> t1(datic1.Ocitaj()), t2(datic2.Ocitaj());
  int dan1=std::get<0>(t1), mj1=std::get<1>(t1), god1=std::get<2>(t1);
  int dan2=std::get<0>(t2), mj2=std::get<1>(t2), god2=std::get<2>(t2);
  
  Vrijeme vr1(p1.DajVrijemePregleda()), vr2(p2.DajVrijemePregleda());
  std::pair<int, int> vrem1(vr1.Ocitaj()), vrem2(vr2.Ocitaj());
  int h1=std::get<0>(vrem1), m1=std::get<1>(vrem1);
  int h2=std::get<0>(vrem2), m2=std::get<1>(vrem2);
  
  if (god1>god2) return false;
  else if (god1==god2) {
    if (mj1>mj2)  return false;
    else if (mj1==mj2) {
      if (dan1>dan2) return false;  
      else if (dan1<dan2) return true;
      else if (dan1==dan2) {
        
        if (h1>h2) return false;
        else if (h1<h2) return true;
        else if (h1==h2) {
          if (m1>m2) return false;
          else if (m1<m2) return true;
        }
      } 
    }
    else if (mj1<mj2) return true;
  }
  else if (god1<god2) return true;
} 


class Pregledi {
  Pregled** preg;
  int bp; const int mbp;
  
  public:
  explicit Pregledi(int max_broj_pregleda):mbp(max_broj_pregleda) {
    bp=0; preg=new Pregled*[mbp];
  }
  Pregledi(std::initializer_list<Pregled> spisak_pregleda);
  ~Pregledi() {
    for (int i=0; i<mbp; i++) delete[] preg[i];
    delete[] preg;
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

Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda):mbp(spisak_pregleda.size()) {
  bp=spisak_pregleda.size(); preg=new Pregled*[spisak_pregleda.size()];
  
  //for (auto it=spisak_pregleda.begin(); it!=spisak_pregleda.end(); it++) (*it)=nullptr;
  for (int i=0; i<bp; i++) preg[i]=nullptr;
  int k(0);
  try {
    int i(0);
    for (auto it1=spisak_pregleda.begin(); it1!=spisak_pregleda.end(); it1++) {
      preg[i]=new Pregled(*it1); 
      i++; k++;
  }
  }
  catch(...) {
    for (int i=0; i<k; i++) delete[] preg[i];
    delete[] preg;
    throw;
  }
}

Pregledi::Pregledi(const Pregledi &pregledi): mbp(pregledi.mbp) {
  bp=pregledi.bp;
  preg=new Pregled*[pregledi.mbp];
  for (int i=0; i<bp; i++) preg[i]=nullptr;
  
  try {
    for (int i=0; i<bp; i++) {
      preg[i]=new Pregled(*pregledi.preg[i]);
    }
  }
  catch (...) {
    for (int i=0; i<bp; i++) delete preg[i];
    delete[] preg;
    throw;
  }
}

Pregledi::Pregledi(Pregledi &&pregledi):mbp(pregledi.mbp), bp(pregledi.bp), preg(pregledi.preg) {
  pregledi.preg=nullptr;
}

Pregledi &Pregledi::operator =(const Pregledi &pregledi) {
  if (this!=&pregledi) {
    for (int i=0; i<bp; i++) delete preg[i];
      delete [] preg;
    bp=pregledi.bp;
    preg=new Pregled*[mbp];
    for (int i=0; i<bp; i++) preg[i]=new Pregled(*pregledi.preg[i]);
  }
  return *this;
}

Pregledi &Pregledi::operator =(Pregledi &&pregledi) {
  if (this!=&pregledi) {
  for (int i=0; i<bp; i++) delete preg[i];
  delete[] preg;
  bp=pregledi.bp;
  preg=pregledi.preg;
  pregledi.preg=nullptr;
  
  }
  return *this;
}

void Pregledi:: RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) {
  if (bp>mbp) throw std::range_error ("Dostignut maksimalan broj pregleda");
  Pregled p(ime_pacijenta, datum_pregleda, vrijeme_pregleda);
  preg[bp++]=new Pregled(p);
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,int mjesec_pregleda, int godina_pregleda, int sati_pregleda,int minute_pregleda) {
  if (bp>mbp) throw std::range_error ("Dostignut maksimalan broj pregleda");
  Pregled p(ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda);
  preg[bp++]=new Pregled(p);
}

void Pregledi:: RegistrirajPregled(Pregled *pregled) {
  if (bp>mbp) throw std::domain_error ("Dostignut maksimalan broj pregleda");
  preg[bp++]=pregled;
}

int Pregledi::DajBrojPregleda() const { return Pregled::brojac; }

int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const {
  int t=count_if (preg, preg+bp, [&datum] (Pregled p) {
    int b(0);
    while (preg->DajDatumPregleda()==datum) b++;
  });
  return t; 
}



int main () 
{
  
  Datum d{1,4,2001}, d1{1,4,2001};
  Vrijeme v{2,12}, v2{9,12};
  Pregled p{"amina", d, v}, p1{"sara", d1, v2};
  bool jel(DolaziPrije(p,p1));
  std::cout << jel;
  
  /*p.PomjeriDanUnaprijed();
  p.Ispisi();*/
  
	return 0;
}
