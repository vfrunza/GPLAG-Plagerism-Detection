/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <algorithm>
#include <string>
#include <initializer_list>
#include <new>
#include <vector>
#include <iomanip>
#include <utility>
int obrisano;

class Datum
{
 int dan, mjesec, godina;
 public:
 Datum(int dan, int mjesec, int godina);
 void Postavi(int dan, int mjesec, int godina);
 std::tuple<int,int,int> Ocitaj() const;
 void Ispisi() const;
 friend class Pregled;
 friend class Pregledi;
};

void Datum::Postavi(int dan, int mjesec, int godina)
{
 int broj_dana[12]={31,28,31,30,31,30,31,31,30,31,30,31};
 if((godina%4==0 && godina%100!=0) || godina%400==0) broj_dana[1]++;
 if(godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>broj_dana[mjesec-1]) throw std::domain_error("Neispravan datum");
 Datum::dan=dan;
 Datum::mjesec=mjesec;
 Datum::godina=godina;
}

Datum::Datum(int dan, int mjesec, int godina) { Datum::Postavi(dan,mjesec,godina); }

std::tuple<int,int,int> Datum::Ocitaj() const
{
 auto pomocna=std::make_tuple(Datum::dan,Datum::mjesec,Datum::godina);
 return pomocna;
}

void Datum::Ispisi() const
{
 std::cout << dan << "/" << mjesec << "/" << godina;
}

class Vrijeme
{
 int sati,minute;
 public:
 Vrijeme(int sati, int minute);
 void Postavi(int sati, int minute);
 std::pair<int,int> Ocitaj() const;
 void Ispisi() const;
 friend class Pregled;
 friend class Pregledi;
};

void Vrijeme::Postavi(int sati, int minute)
{
 if(sati<0 || sati>23 || minute<0 || minute>59) throw std::domain_error("Neispravno vrijeme");
 Vrijeme::sati=sati;
 Vrijeme::minute=minute;
}

Vrijeme::Vrijeme(int sati, int minute) { Vrijeme::Postavi(sati,minute); }

std::pair<int,int> Vrijeme::Ocitaj() const
{
 auto pomocna=std::make_pair(Vrijeme::sati, Vrijeme::minute);
 return pomocna;
}

void Vrijeme::Ispisi() const
{
 if(sati>9 && minute>9) std::cout << sati << ":" << minute;
 else if(sati<10 && minute>9) std::cout << "0" << sati << ":" << minute;
 else if(minute<10 && sati>9) std::cout << sati << ":0" << minute;
 else if(sati<10 && minute<10) std::cout << "0" << sati << ":0" << minute;
}

class Pregled
{
 std::string ime;
 Datum datum;
 Vrijeme vrijeme;
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
 friend class Datum;
 friend class Vrijeme;
 friend class Pregledi;
};

Pregled::Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) : ime(ime_pacijenta), datum(datum_pregleda), vrijeme(vrijeme_pregleda) {}

Pregled::Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) : ime(ime_pacijenta), datum(Datum(dan_pregleda,mjesec_pregleda,godina_pregleda)), vrijeme(Vrijeme(sati_pregleda, minute_pregleda)) {}

void Pregled::PromijeniPacijenta(const std::string &ime_pacijenta) { Pregled::ime=ime_pacijenta; }

void Pregled::PromijeniDatum(const Datum &novi_datum) { Pregled::datum=novi_datum; }

void Pregled::PromijeniVrijeme(const Vrijeme &novo_vrijeme) { Pregled::vrijeme=novo_vrijeme; }

void Pregled::PomjeriDanUnaprijed()
{
 int broj_dana[12]={31,28,31,30,31,30,31,31,30,31,30,31};
 Pregled::datum.dan++;
 if(Pregled::datum.dan>broj_dana[Pregled::datum.mjesec-1]) 
 {
  Pregled::datum.dan=1;
  Pregled::datum.mjesec++;
  if(Pregled::datum.mjesec>12) 
  {
   Pregled::datum.mjesec=1;
   Pregled::datum.godina++;
  }
 }
}
 
void Pregled::PomjeriDanUnazad()
{
 int broj_dana[12]={31,28,31,30,31,30,31,31,30,31,30,31};
 Pregled::datum.dan--;
 if(Pregled::datum.dan<=0)
 {
  Pregled::datum.dan=broj_dana[Pregled::datum.mjesec-1];
  Pregled::datum.mjesec--;
  if(Pregled::datum.mjesec<=0)
  {
   Pregled::datum.mjesec=12;
   Pregled::datum.godina--;
  }
 }
}

std::string Pregled::DajImePacijenta() const { return Pregled::ime; }

Datum Pregled::DajDatumPregleda() const { return Pregled::datum; }

Vrijeme Pregled::DajVrijemePregleda() const { return Pregled::vrijeme; }

bool Pregled::DolaziPrije(const Pregled &p1, const Pregled &p2)
{
 if(p1.datum.godina<p2.datum.godina) return true;
 else if(p1.datum.godina>p2.datum.godina) return false;
 else if(p1.datum.godina==p2.datum.godina)
 {
  if(p1.datum.mjesec<p2.datum.mjesec) return true;
  else if(p1.datum.mjesec>p2.datum.mjesec) return false;
  else if(p1.datum.mjesec==p2.datum.mjesec)
  {
   if(p1.datum.dan<p2.datum.dan) return true;
   else if(p1.datum.dan>p2.datum.dan) return false;
   else if(p1.datum.dan==p2.datum.dan)
   {
    if(p1.vrijeme.sati>p2.vrijeme.sati) return false;
    else if(p1.vrijeme.sati<p2.vrijeme.sati) return true;
    else if(p1.vrijeme.sati==p2.vrijeme.sati)
    {
     if(p1.vrijeme.minute>p1.vrijeme.minute) return false;
     else return true;
    }
   }
  }
 }
 return true;
}

void Pregled::Ispisi() const
{
 std::cout << std::setw(30) << std::left << Pregled::ime;
 Pregled::datum.Ispisi();
 std::cout << " ";
 Pregled::vrijeme.Ispisi();
 std::cout << std::endl;
}

class Pregledi
{
 int broj_pregleda;
 int maximalan_broj_pregleda;
 Pregled **termini;
 public:
 explicit Pregledi(int max_broj_pregleda); 
 Pregledi(std::initializer_list<Pregled> spisak_pregleda); 
 ~Pregledi();
 Pregledi(const Pregledi &pregledi);
 Pregledi(Pregledi &&pregledi);
 Pregledi &operator =(const Pregledi &pregledi);
 Pregledi &operator =(Pregledi &&pregledi);
 void RegistrirajPregled(const std::string &ime_pacijenta,const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
 void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,int mjesec_pregleda, int godina_pregleda, int sati_pregleda,int minute_pregleda);
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
 friend class Datum;
 friend class Vrijeme;
 friend class Pregled;
};

Pregledi::Pregledi(int max_broj_pregleda) : broj_pregleda(0), maximalan_broj_pregleda(max_broj_pregleda)
{
 termini=new Pregled*[max_broj_pregleda]{};
}

Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda) : broj_pregleda(spisak_pregleda.size()), maximalan_broj_pregleda(spisak_pregleda.size()) 
{
 try
 {
  termini=new Pregled*[maximalan_broj_pregleda]{};
  try
  {
   int i(0);
   for(auto it(spisak_pregleda.begin());it!=spisak_pregleda.end();it++)
   {
    termini[i]=new Pregled(*it);
    i++;
   }
  }
  catch(...)
  {
   for(int i(0);i<broj_pregleda;i++)
   {
    delete termini[i];
   }
   delete[] termini;
   throw;
  }
 }
 catch(...)
 {
  throw;
 }
}

Pregledi::~Pregledi()
{
 for(int i(0);i<broj_pregleda;i++)
 {
  delete termini[i];
 }
 delete[] termini;
}

Pregledi::Pregledi(const Pregledi &pregledi)
{
 maximalan_broj_pregleda=pregledi.maximalan_broj_pregleda;
 broj_pregleda=pregledi.broj_pregleda;
 try
 {
  termini=new Pregled*[maximalan_broj_pregleda]{};
  try
  {
   for(int i(0);i<broj_pregleda;i++)
   {
    termini[i]=new Pregled(*pregledi.termini[i]);
   }
  }
  catch(...)
  {
   for(int i(0);i<broj_pregleda;i++)
   {
    delete termini[i];
   }
   delete[] termini;
   throw;
  }
 }
 catch(...)
 {
  throw;
 }
}

Pregledi::Pregledi(Pregledi &&pregledi) 
{
 maximalan_broj_pregleda=pregledi.maximalan_broj_pregleda;
 broj_pregleda=pregledi.broj_pregleda;
 termini=pregledi.termini;
 pregledi.termini=nullptr;
 pregledi.broj_pregleda=0;
 pregledi.maximalan_broj_pregleda=0;
}

Pregledi &Pregledi::operator =(const Pregledi &pregledi)
{
 if(this==&pregledi) return *this;
 for(int i(0);i<broj_pregleda;i++)
 {
  delete termini[i];
  termini[i]=nullptr;
 }
 delete[] termini;
 broj_pregleda=pregledi.broj_pregleda;
 try
 {
  termini=new Pregled*[broj_pregleda]{};
  try
  {
   for(int i(0);i<pregledi.broj_pregleda;i++)
   {
    termini[i]=new Pregled(*pregledi.termini[i]);
   }
  }
  catch(...)
  {
   for(int i(0);i<broj_pregleda;i++)
   {
    delete termini[i];
   }
   delete[] termini;
  }
 }
 catch(...)
 {
  throw;
 }
 return *this;
}

Pregledi &Pregledi::operator =(Pregledi &&pregledi)
{
 if(this==&pregledi) return *this;
 std::swap(broj_pregleda,pregledi.broj_pregleda);
 std::swap(termini,pregledi.termini);
 return *this;
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta,const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda)
{
 if(broj_pregleda>=maximalan_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
 try
 {
  termini[broj_pregleda++]=new Pregled(Pregled(ime_pacijenta,datum_pregleda,vrijeme_pregleda));
 }
 catch(...)
 {
  for(int i(0);i<broj_pregleda;i++)
  {
   delete termini[i];
  }
  throw;
 }
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,int mjesec_pregleda, int godina_pregleda, int sati_pregleda,int minute_pregleda)
{
 if(broj_pregleda>=maximalan_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
 try
 {
  termini[broj_pregleda++]=new Pregled(Pregled(ime_pacijenta,dan_pregleda,mjesec_pregleda,godina_pregleda,sati_pregleda,minute_pregleda));
 }
 catch(...)
 {
  for(int i(0);i<broj_pregleda;i++)
  {
   delete termini[i];
  }
  throw;
 }
}

void Pregledi::RegistrirajPregled(Pregled *pregled)
{
 if(broj_pregleda>=maximalan_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
 try
 {
  termini[broj_pregleda++]=new Pregled(*pregled);
 }
 catch(...)
 {
  throw;
 }
}

int Pregledi::DajBrojPregleda() const { return Pregledi::broj_pregleda; }

int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const 
{ 
 auto broj=std::count_if(termini,termini+broj_pregleda,[datum](Pregled *p1) 
 { 
  if(p1->datum.godina==datum.godina && p1->datum.mjesec==datum.mjesec && p1->datum.dan==datum.dan) return true;
  return false;
 });
 return broj;
}

Pregled &Pregledi::DajNajranijiPregled()
{
 if(Pregledi::broj_pregleda==0) throw std::domain_error("Nema registriranih pregleda");
 return **std::min_element(termini,termini+broj_pregleda,[](Pregled *p1, Pregled *p2)
 {
  return Pregled::DolaziPrije(*p1,*p2);
 });
}

Pregled Pregledi::DajNajranijiPregled() const
{
 if(broj_pregleda==0) throw std::domain_error("Nema registriranih pregleda");
 return **std::min_element(termini,termini+broj_pregleda-1,[](Pregled *p1, Pregled *p2)
 {
  if(Pregled::DolaziPrije(*p1,*p2)==true) return true;
  return false;
 });
}

void Pregledi::IsprazniKolekciju()
{
 for(int i(0);i<broj_pregleda;i++)
 {
  delete termini[i];
 }
 broj_pregleda=0;
}

void Pregledi::ObrisiNajranijiPregled()
{
 if(broj_pregleda==0) throw std::range_error("Prazna kolekcija");
 delete termini[0];
 termini[0]=termini[broj_pregleda-1];
 broj_pregleda--;
 std::sort(termini,termini+broj_pregleda,[](Pregled *p1, Pregled *p2) 
 {
  if(Pregled::DolaziPrije(*p1,*p2)==true) return true;
  return false;
 });
}

void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta)
{
 for(int i(0);i<broj_pregleda;i++)
 {
  if(termini[i]->Pregled::ime==ime_pacijenta)
  {
   delete termini[i];
   termini[i]=termini[broj_pregleda-1];
   broj_pregleda--;
   std::sort(termini,termini+broj_pregleda,[](Pregled *p1, Pregled *p2) 
   {
    if(Pregled::DolaziPrije(*p1,*p2)==true) return true;
    return false;
   });
   obrisano++;
  }
 }
}

void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const
{
 std::vector<Pregled*> pomocni;
 for(int i(0);i<broj_pregleda;i++)
 {
  if(termini[i]->datum.dan==datum.dan && termini[i]->datum.mjesec==datum.mjesec && termini[i]->datum.godina==datum.godina) 
  {
   pomocni.push_back(termini[i]);
  }
 }
 std::sort(pomocni.begin(),pomocni.end(),[](Pregled *p1, const Pregled *p2)
 {
  if(Pregled::DolaziPrije(*p1,*p2)==true) return true;
  return false;
 });
 for(int i(0);i<pomocni.size();i++)
 {
  pomocni[i]->Pregled::Ispisi();
 }
 pomocni.clear();
}

void Pregledi::IspisiSvePreglede() const
{
 std::sort(termini,termini+broj_pregleda,[](const Pregled *p1,const Pregled *p2) 
 {
  if(Pregled::DolaziPrije(*p1,*p2)==true) return true;
  return false;
 });
 for(int i(0);i<broj_pregleda;i++)
 {
  termini[i]->Pregled::Ispisi();
 }
}

void Ispis()
{
 std::cout << "1 - Broj pregleda na datum" << std::endl;
 std::cout << "2 - Najraniji pregled" << std::endl;
 std::cout << "3 - Obrisi pregled pacijenta" << std::endl;
 std::cout << "4 - Obrisi najraniji pregled" << std::endl;
 std::cout << "5 - Ispisi sve pregleda na datum" << std::endl;
 std::cout << "6 - Ispisi sve preglede" << std::endl;
 std::cout << "7 - Kraj programa" << std::endl;
}

int main ()
{
 int max;
 std::cout << "Unesite maksimalan broj pregleda: ";
 std::cin >> max;
 Pregledi pregledi(max);
 int i(0);
 while(i<max)
 {
  try
  {
   std::string ime;
   std::cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
   std::cin >> ime;
   if(ime=="kraj") break;
   int dan,mjesec,godina,sati,minute;
   std::cout << "Unesite dan mjesec i godinu pregleda: ";
   std::cin >> dan >> mjesec >> godina;
   Datum(dan,mjesec,godina);
   std::cout << "Unesite sate i minute pregleda: ";
   std::cin >> sati >> minute;
   Vrijeme(sati,minute);
   pregledi.RegistrirajPregled(ime,dan,mjesec,godina,sati,minute);
   i++;
  }
  catch(std::range_error e)
  {
   std::cout << e.what() << std::endl;
  }
  catch(std::domain_error e2)
  {
   std::cout << e2.what() << std::endl;
  }
 }
 std::cout << "Trenutno su registrovani sljedeci pregledi" << std::endl;
 pregledi.IspisiSvePreglede();
 int opcija;
 odredi: std::cout << std::endl;
 std::cout << "Odaberite jednu od sljedecih opcija" << std::endl;
 std::cin >> opcija;
 if(opcija==1)
 {
  try
  {
   Ispis();
   int na_dan,na_mjesec,na_godinu;
   std::cout << "Unesite dan mjesec i godinu : ";
   std::cin >> na_dan >> na_mjesec >> na_godinu;
   auto broj_pregleda_na_datum=pregledi.DajBrojPregledaNaDatum(Datum(na_dan,na_mjesec,na_godinu));
   std::cout << "Broj pregleda na datum " << na_dan << " " << na_mjesec << " " << na_godinu << " je: " << broj_pregleda_na_datum << std::endl;
  }
  catch(std::domain_error e)
  {
   std::cout << e.what() << std::endl;
  }
 }
 else if(opcija==2)
 {
  try
  {
   Ispis();
   auto najraniji=pregledi.DajNajranijiPregled();
   std::cout << "Najraniji pregled je:" << std::endl;
   najraniji.Ispisi();
  }
  catch(std::domain_error e)
  {
   std::cout << e.what() << std::endl;
  }
 }
 else if(opcija==3)
 {
  Ispis();
  std::string ime_u3;
  std::cout << "Unesite ime pacijenta: ";
  std::cin >> ime_u3;
  pregledi.ObrisiPregledePacijenta(ime_u3);
  std::cout << "Uspjesno obrisano " << obrisano << " pregleda" << std::endl; 
 }
 else if(opcija==4)
 {
  try
  {
   Ispis();
   pregledi.ObrisiNajranijiPregled();
   std::cout << "Najraniji pregled uspjesno obrisan" << std::endl;
  }
  catch(std::range_error e3)
  {
   std::cout << e3.what() << std::endl;
  }
 }
 else if(opcija==5)
 {
  try
  {
   Ispis();
   int dan_u5, mjesec_u5, godina_u5;
   std::cout << "Unesite dan mjesec i godinu : ";
   std::cin >> dan_u5 >> mjesec_u5 >> godina_u5;
   std::cout << "Pregledi na datum " << dan_u5 << " " << mjesec_u5 << " " << godina_u5 << " su:" << std::endl;
   pregledi.IspisiPregledeNaDatum(Datum(dan_u5,mjesec_u5,godina_u5));
   std::cout << std::endl;
  }
  catch(std::domain_error e)
  {
   std::cout << e.what() << std::endl;
  }
 }
 else if(opcija==6)
 {
  Ispis();
  pregledi.IspisiSvePreglede();
 }
 else if(opcija==7) 
 {
  Ispis();
  return 0;
 }
 goto odredi;
 return 0;
}
