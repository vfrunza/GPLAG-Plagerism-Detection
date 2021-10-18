/B2017/2018: Zadaća 4, Zadatak 3
/B2017/2018: Zadaæa 4, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <iomanip>
#include <vector>
#include <initializer_list>
#include <algorithm>
class Datum
{
  int d,m,g;
  bool Provjeri(int d, int m, int g)
  {
    int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
    if((g%4==0 && g%100!=0) || g%400==0) broj_dana[1]++;
    if(g<1||m<1||m>12||d<1||d>broj_dana[m-1]) return false;
    return true;
  }
public:
  Datum(int dan, int mjesec, int godina )
  {
    Postavi(dan,mjesec,godina);
  }
  void Postavi(int dan, int mjesec, int godina)
  {
    if(!Provjeri(dan,mjesec,godina)) throw std::domain_error("Neispravan datum");
    d=dan;
    m=mjesec;
    g=godina;
  }
  std::tuple<int,int,int> Ocitaj()const
  {
    return std::make_tuple(d,m,g);
  }
  void Ispisi() const;
};
void Datum::Ispisi()const
{
  std::cout<<d<<"/"<<m<<"/"<<g;
}

class Vrijeme
{
  int h,m;
public:
  Vrijeme(int sati, int minute)
  {
    Postavi(sati,minute);
  }
  void Postavi(int sati, int minute)
  {
    if(!(sati>=0&&sati<=23)||!(minute>=0&&minute<=59)) throw std::domain_error("Neispravno vrijeme");
    h=sati;
    m=minute;
  }
  std::pair<int,int>Ocitaj()const
  {
    return std::make_pair(h,m);
  }
  void Ispisi()const;
};

void Vrijeme::Ispisi()const
{
  if(h<10)std::cout<<0<<h<<":";
  else std::cout<<h<<":";
  if(m<10)std::cout<<0<<m;
  else std::cout<<m;
}

class Pregled
{
  std::string ime;
  Datum dat;
  Vrijeme v;
public:
  Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda,const Vrijeme&vrijeme_pregleda):ime(ime_pacijenta),dat(datum_pregleda),v(vrijeme_pregleda) {}
  Pregled(const std::string &ime_pacijenta, int dan_pregleda,int mjesec_pregleda,int godina_pregleda, int sati_pregleda, int minute_pregleda):
    ime(ime_pacijenta),dat(dan_pregleda,mjesec_pregleda,godina_pregleda),v(sati_pregleda,minute_pregleda) {};
  void PromjeniPacijenta(const std::string &ime_pacijenta)
  {
    this->ime=ime_pacijenta;
  }
  void PromjeniDatum(const Datum &novi_datum);
  void PromjeniVrijeme(const Vrijeme &novo_vrijeme);
  void PomjeriDanUnaprijed();
  void PomjeriDanUnazad();
  std::string DajImePacijenta()const
  {
    return ime;
  }
  Datum DajDatumPregleda()const
  {
    return dat;
  }
  Vrijeme DajVrijemePregleda()const
  {
    return v;
  }
  static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
  void Ispisi()const;
};

void Pregled::PromjeniDatum(const Datum &novi_datum)
{
  this->dat.Postavi(std::get<0>(novi_datum.Ocitaj()),std::get<1>(novi_datum.Ocitaj()),std::get<2>(novi_datum.Ocitaj()));

}
void Pregled::PromjeniVrijeme(const Vrijeme &novo_vrijeme)
{
  this->v.Postavi(novo_vrijeme.Ocitaj().first,novo_vrijeme.Ocitaj().second);
}
bool Pregled::DolaziPrije(const Pregled &p1, const Pregled &p2)
{
  std::vector<int> prvi,drugi;
  prvi.push_back(std::get<2>(p1.dat.Ocitaj()));
  drugi.push_back(std::get<2>(p2.dat.Ocitaj()));
  prvi.push_back(std::get<1>(p1.dat.Ocitaj()));
  drugi.push_back(std::get<1>(p2.dat.Ocitaj()));
  prvi.push_back(std::get<0>(p1.dat.Ocitaj()));
  drugi.push_back(std::get<0>(p2.dat.Ocitaj()));
  prvi.push_back(std::get<1>(p1.v.Ocitaj()));
  drugi.push_back(std::get<1>(p2.v.Ocitaj()));
  prvi.push_back(std::get<0>(p1.v.Ocitaj()));
  drugi.push_back(std::get<0>(p2.v.Ocitaj()));
  for(int i=0; i<prvi.size(); i++)
    if(prvi[i]<drugi[i])return true;
  return false;
}

void Pregled::Ispisi()const
{
  std::cout<<std::left<<std::setw(30)<<ime;
  dat.Ispisi();
  std::cout<<" ";
  v.Ispisi();
  std::cout<<std::endl;
}
void Pregled::PomjeriDanUnaprijed()
{
  int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
  int a[] {std::get<0>(this->dat.Ocitaj()),std::get<1>(this->dat.Ocitaj()),std::get<2>(this->dat.Ocitaj())};
  a[0]++;
  if(a[0]>broj_dana[a[1]-1]) {
    a[0]=1;
    a[1]++;
  }
  if(a[1]>12) {
    a[1]=1;
    a[2]++;
  }
  this->dat.Postavi(a[0],a[1],a[2]);
}
void Pregled::PomjeriDanUnazad()
{
  int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
  int a[] {std::get<0>(this->dat.Ocitaj()),std::get<1>(this->dat.Ocitaj()),std::get<2>(this->dat.Ocitaj())};
  a[0]--;
  if(a[0]==0) {
    a[1]--;
    a[0]=broj_dana[a[1]-1];
  }
  if(a[1]==0) {
    a[1]=12;
    a[2]--;
  }
  this->dat.Postavi(a[0],a[1],a[2]);
}

class Pregledi
{
  int max,broj;
  Pregled**elementi;
public:
  explicit Pregledi(int max_broj_pregleda):max(max_broj_pregleda),broj(0),elementi(new Pregled*[max_broj_pregleda] {}) {};
  Pregledi(std::initializer_list<Pregled> spisak_pregleda):max(spisak_pregleda.size()),broj(spisak_pregleda.size()),
    elementi(new Pregled*[spisak_pregleda.size()])
  {
    auto it(spisak_pregleda.begin());
    for(int i=0; i<spisak_pregleda.size(); i++) {
      try {
        elementi[i]=new Pregled(*it);
        it++;
      } catch(...) {
        for(int i=0; i<spisak_pregleda.size(); i++)delete elementi[i];
        delete[] elementi;
      }
    }
  }
  ~Pregledi()
  {
    for(int i=0; i<broj; i++) delete elementi[i];
    delete [] elementi;
  }
  Pregledi(const Pregledi &pregledi):max(pregledi.max),broj(pregledi.broj),elementi(new Pregled*[pregledi.max] {})
  {
    for(int i=0; i<max; i++) {
      try {
        elementi[i]=new Pregled(*(pregledi.elementi[i]));
      } catch(...) {
        for(int i=0; i<max; i++) delete elementi[i];
        delete[] elementi;
        throw;
      }
    }
  }
  Pregledi(Pregledi &&pregledi):max(pregledi.max),broj(pregledi.broj),elementi(pregledi.elementi)
  {
    pregledi.elementi=nullptr;
  }

  Pregledi &operator=(Pregledi &&pregledi)
  {
    if(&pregledi!=this) {
      max=pregledi.max;
      broj=pregledi.broj;
      for(int i=0; i<max; i++) delete elementi[i];
      delete [] elementi;
      elementi=pregledi.elementi;
      pregledi.elementi=nullptr;
    }
    return *this;
  }
  Pregledi &operator =(Pregledi &pregledi)
  {
    if(&pregledi!=this) {
      max=pregledi.max;
      broj=pregledi.broj;
      for(int i=0; i<max; i++) delete elementi[i];
      delete [] elementi;
      elementi=new Pregled*[max];
      for(int i=0; i<max; i++) {
        try {
          elementi[i]=new Pregled(*(pregledi.elementi[i]));
        } catch(...) {
          for(int i=0; i<max; i++) delete elementi[i];
          delete [] elementi;
          throw;
        }
      }
    }
    return *this;
  }
  void RegistrirajPregled(const std::string &ime_pacijenta,const Datum &datum_pregleda,const Vrijeme &vrijeme_pregleda);
  void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,int mjesec_pregleda,int godina_pregleda,int sati_pregleda,int minute_pregleda);
  void RegistrirajPregled(Pregled *pregled);
  int DajBrojPregleda()const
  {
    return broj;
  }
  int DajBrojPregledaNaDatum(const Datum &datum)const;
  Pregled &DajNajranijiPregled();
  Pregled DajNajranijiPregled()const;
  void IsprazniKolekciju();
  void ObrisiNajranijiPregled();
  void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
  void IspisiPregledeNaDatum(const Datum &datum) const;
  void IspisiSvePreglede() const;

};

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta,const Datum &datum_pregleda,const Vrijeme &vrijeme_pregleda)
{
  if(broj==max)throw std::range_error("Dostignut maksimalni broj pregleda");
  Pregled a(ime_pacijenta,datum_pregleda,vrijeme_pregleda);
  try {
    elementi[broj]=new Pregled(a);
  } catch(...) {
    throw;
  }
  broj++;
}

void Pregledi:: RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,int mjesec_pregleda,int godina_pregleda,int sati_pregleda,int minute_pregleda)
{
  if(broj==max)throw std::range_error("Dostignut maksimalni broj pregleda");
  Pregled a(ime_pacijenta,dan_pregleda,mjesec_pregleda,godina_pregleda,sati_pregleda,minute_pregleda);
  try {
    elementi[broj]=new Pregled(a);
  } catch(...) {
    throw;
  }
  broj++;
}

void Pregledi::RegistrirajPregled(Pregled *pregled)
{
  if(broj==max)throw std::range_error("Dostignut maksimalni broj pregleda");
  elementi[broj]=pregled;
  pregled=nullptr;
  broj++;
}


int Pregledi::DajBrojPregledaNaDatum(const Datum &datum)const
{
  return std::count_if(elementi,elementi+broj,[datum](Pregled*pregled) {
    return(std::get<0>(datum.Ocitaj())==std::get<0>((pregled->DajDatumPregleda()).Ocitaj())&&
           std::get<1>(datum.Ocitaj())==std::get<1>((pregled->DajDatumPregleda()).Ocitaj())&&
           std::get<2>(datum.Ocitaj())==std::get<2>((pregled->DajDatumPregleda()).Ocitaj()));
  });
}

Pregled& Pregledi::DajNajranijiPregled()
{
  if(broj==0)throw std::domain_error("Nema registriranih pregleda");
  return (**(std::min_element(elementi,elementi+broj,[](Pregled*p1,Pregled*p2)->bool{
    if(std::get<2>(p1->DajDatumPregleda().Ocitaj())<std::get<2>(p2->DajDatumPregleda().Ocitaj()))return true;
    else if(std::get<2>(p1->DajDatumPregleda().Ocitaj())>std::get<2>(p2->DajDatumPregleda().Ocitaj()))return false;
    else if(std::get<2>(p1->DajDatumPregleda().Ocitaj())==std::get<2>(p2->DajDatumPregleda().Ocitaj()))
    {
      if(std::get<1>(p1->DajDatumPregleda().Ocitaj())<std::get<1>(p2->DajDatumPregleda().Ocitaj()))return true;
      else if(std::get<1>(p1->DajDatumPregleda().Ocitaj())>std::get<1>(p2->DajDatumPregleda().Ocitaj()))return false;
      else if(std::get<1>(p1->DajDatumPregleda().Ocitaj())==std::get<1>(p2->DajDatumPregleda().Ocitaj())) {
        if(std::get<0>(p1->DajDatumPregleda().Ocitaj())<std::get<0>(p2->DajDatumPregleda().Ocitaj()))return true;
        else if(std::get<0>(p1->DajDatumPregleda().Ocitaj())>std::get<0>(p2->DajDatumPregleda().Ocitaj()))return false;
        else if(std::get<0>(p1->DajDatumPregleda().Ocitaj())==std::get<0>(p2->DajDatumPregleda().Ocitaj())) {
          if(std::get<0>(p1->DajVrijemePregleda().Ocitaj())<std::get<0>(p2->DajVrijemePregleda().Ocitaj()))return true;
          else if(std::get<0>(p1->DajVrijemePregleda().Ocitaj())>std::get<0>(p2->DajVrijemePregleda().Ocitaj()))return false;
          else if(std::get<0>(p1->DajVrijemePregleda().Ocitaj())==std::get<0>(p2->DajVrijemePregleda().Ocitaj())) {
            if(std::get<1>(p1->DajVrijemePregleda().Ocitaj())<std::get<1>(p2->DajVrijemePregleda().Ocitaj()))return true;
            else if(std::get<1>(p1->DajVrijemePregleda().Ocitaj())>std::get<1>(p2->DajVrijemePregleda().Ocitaj()))return false;
            else if(std::get<1>(p1->DajVrijemePregleda().Ocitaj())==std::get<1>(p2->DajVrijemePregleda().Ocitaj())) return true;
          }
        }
      }
    }
    return false;})));
}

Pregled Pregledi::DajNajranijiPregled()const
{
  if(broj==0)throw std::domain_error("Nema registriranih pregleda");
  return {this->DajNajranijiPregled().DajImePacijenta(),this->DajNajranijiPregled().DajDatumPregleda(),this->DajNajranijiPregled().DajVrijemePregleda()};

}
void Pregledi::IsprazniKolekciju()
{
  for(int i=0; i<broj; i++) {
    delete elementi[i];
    elementi[i]=nullptr;
  }
  broj=0;
}

bool JednakiPregledi(const Pregled &a,const Pregled &b)
{
  return(a.DajImePacijenta()==b.DajImePacijenta()&&std::get<2>(a.DajDatumPregleda().Ocitaj())==std::get<2>(b.DajDatumPregleda().Ocitaj())
         && std::get<1>(a.DajDatumPregleda().Ocitaj())==std::get<1>(b.DajDatumPregleda().Ocitaj()) &&
         std::get<0>(a.DajDatumPregleda().Ocitaj())==std::get<0>(a.DajDatumPregleda().Ocitaj()) &&
         std::get<0>(a.DajVrijemePregleda().Ocitaj())==std::get<0>(b.DajVrijemePregleda().Ocitaj()) &&
         std::get<1>(a.DajVrijemePregleda().Ocitaj())==std::get<1>(b.DajVrijemePregleda().Ocitaj()));
}

void Pregledi::ObrisiNajranijiPregled()
{
  if(broj==0)throw std::range_error("Prazna kolekcija");
  std::vector<Pregled> a;
  std::for_each(elementi,elementi+broj,[this,&a](Pregled*p) {
    if(!JednakiPregledi(this->DajNajranijiPregled(),*p))a.push_back(*p);
  });
  for(int i=0; i<broj; i++) delete elementi[i];
  for(int i=0; i<a.size(); i++) elementi[i]=new Pregled(a[i]);
  broj=a.size();
}

void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta)
{

  std::vector<Pregled> a;
  std::for_each(elementi,elementi+broj,[&a,ime_pacijenta](Pregled*p) {
    if(ime_pacijenta!=p->DajImePacijenta())a.push_back(*p);
  });
  for(int i=0; i<broj; i++) delete elementi[i];
  for(int i=0; i<a.size(); i++) elementi[i]=new Pregled(a[i]);
  broj=a.size();
}



void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const
{
  std::vector<Pregled> a;
  std::for_each(elementi,elementi+broj,[&a,datum](Pregled*p) {
    if(std::get<0>(datum.Ocitaj())==std::get<0>((p->DajDatumPregleda()).Ocitaj())&&
        std::get<1>(datum.Ocitaj())==std::get<1>((p->DajDatumPregleda()).Ocitaj())&&
        std::get<2>(datum.Ocitaj())==std::get<2>((p->DajDatumPregleda()).Ocitaj())) a.push_back(*p);
  });
  std::sort(a.begin(),a.end(),[](Pregled p1,Pregled p2)->bool{
    if(std::get<0>(p1.DajVrijemePregleda().Ocitaj())<std::get<0>(p2.DajVrijemePregleda().Ocitaj()))return true;
    else if(std::get<0>(p1.DajVrijemePregleda().Ocitaj())>std::get<0>(p2.DajVrijemePregleda().Ocitaj()))return false;
    else if(std::get<0>(p1.DajVrijemePregleda().Ocitaj())==std::get<0>(p2.DajVrijemePregleda().Ocitaj()))
    {
      if(std::get<1>(p1.DajVrijemePregleda().Ocitaj())<std::get<1>(p2.DajVrijemePregleda().Ocitaj()))return true;
      else if(std::get<1>(p1.DajVrijemePregleda().Ocitaj())>std::get<1>(p2.DajVrijemePregleda().Ocitaj()))return false;
      else if(std::get<1>(p1.DajVrijemePregleda().Ocitaj())==std::get<1>(p2.DajVrijemePregleda().Ocitaj())) return true;
    }
    return false;});
  for(auto x:a) x.Ispisi();
}

void Pregledi::IspisiSvePreglede() const
{
  std::vector<Pregled> a;
  std::for_each(elementi,elementi+broj,[&a](Pregled*pregled) {
    a.push_back(*pregled);
  });
  std::sort(a.begin(),a.end(),[](Pregled p1,Pregled p2)->bool{
    if(std::get<2>(p1.DajDatumPregleda().Ocitaj())<std::get<2>(p2.DajDatumPregleda().Ocitaj()))return true;
    else if(std::get<2>(p1.DajDatumPregleda().Ocitaj())>std::get<2>(p2.DajDatumPregleda().Ocitaj()))return false;
    else if(std::get<2>(p1.DajDatumPregleda().Ocitaj())==std::get<2>(p2.DajDatumPregleda().Ocitaj()))
    {
      if(std::get<1>(p1.DajDatumPregleda().Ocitaj())<std::get<1>(p2.DajDatumPregleda().Ocitaj()))return true;
      else if(std::get<1>(p1.DajDatumPregleda().Ocitaj())>std::get<1>(p2.DajDatumPregleda().Ocitaj()))return false;
      else if(std::get<1>(p1.DajDatumPregleda().Ocitaj())==std::get<1>(p2.DajDatumPregleda().Ocitaj())) {
        if(std::get<0>(p1.DajDatumPregleda().Ocitaj())<std::get<0>(p2.DajDatumPregleda().Ocitaj()))return true;
        else if(std::get<0>(p1.DajDatumPregleda().Ocitaj())>std::get<0>(p2.DajDatumPregleda().Ocitaj()))return false;
        else if(std::get<0>(p1.DajDatumPregleda().Ocitaj())==std::get<0>(p2.DajDatumPregleda().Ocitaj())) {
          if(std::get<0>(p1.DajVrijemePregleda().Ocitaj())<std::get<0>(p2.DajVrijemePregleda().Ocitaj()))return true;
          else if(std::get<0>(p1.DajVrijemePregleda().Ocitaj())>std::get<0>(p2.DajVrijemePregleda().Ocitaj()))return false;
          else if(std::get<0>(p1.DajVrijemePregleda().Ocitaj())==std::get<0>(p2.DajVrijemePregleda().Ocitaj())) {
            if(std::get<1>(p1.DajVrijemePregleda().Ocitaj())<std::get<1>(p2.DajVrijemePregleda().Ocitaj()))return true;
            else if(std::get<1>(p1.DajVrijemePregleda().Ocitaj())>std::get<1>(p2.DajVrijemePregleda().Ocitaj()))return false;
            else if(std::get<1>(p1.DajVrijemePregleda().Ocitaj())==std::get<1>(p2.DajVrijemePregleda().Ocitaj())) return true;
          }
        }
      }
    }
    return false;});
  for(auto x:a) x.Ispisi();
}

void Opcije()
{
  std::cout<<"\nOdaberite jednu od sljedecih opcija\n1 - Broj pregleda na datum\n2 - Najraniji pregled\n3 - "<<
           "Obrisi pregled pacijenta\n4 - Obrisi najraniji pregled\n5 - Ispisi sve pregleda na datum\n6 - Ispisi sve preglede\n7 - Kraj programa\n";
}

int main ()
{
  try {
    int max;
    std::cout<<"Unesite maksimalan broj pregleda: ";
    std::cin>>max;
    std::cin.ignore(10000,'\n');
    Pregledi a(max);
    for(;;) {
      std::string ime{};
      std::cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
      std::cin>>ime;
      if(ime=="kraj") break;
      std::cin.ignore(10000,'\n');
      std::cout<<"Unesite dan mjesec i godinu pregleda: ";
      int dan,mjesec,godina;
      std::cin>>dan>>mjesec>>godina;
      std::cout<<"Unesite sate i minute pregleda: ";
      int sati,minute;
      std::cin>>sati>>minute;
      a.RegistrirajPregled(ime,dan,mjesec,godina,sati,minute);
      if(a.DajBrojPregleda()==max)break;
    }
    std::cout<<"Trenutno su registrovani sljedeci pregledi\n";
    a.IspisiSvePreglede();
    for(;;) {
      Opcije();
      int opcija;
      std::cin>>opcija;
      if(opcija==7)break;
      if(opcija==1) {
        std::cout<<"Unesite dan mjesec i godinu : ";
        int d,m,g;
        std::cin>>d>>m>>g;
        std::cout<<"Broj pregleda na datum "<<d<<" "<<m<<" "<<g<<" je: "<<a.DajBrojPregledaNaDatum(Datum(d,m,g))<<std::endl;
      }
      if(opcija==2) {
        std::cout<<"Najraniji pregled je:\n";
        a.DajNajranijiPregled().Ispisi();
      }
      if(opcija==3) {
        std::cout<<"Unesite ime pacijenta: ";
        std::string ime_pa;
        std::cin>> ime_pa;
        int b(a.DajBrojPregleda());

        a.ObrisiPregledePacijenta(ime_pa);
        std::cout<<"Uspjesno obrisano "<<b-a.DajBrojPregleda()<<" pregleda\n";

      }
      if(opcija==4) {
        a.ObrisiNajranijiPregled();
        std::cout<<"Najraniji pregled uspjesno obrisan\n";
      }
      if(opcija==5) {
        std::cout<<"Unesite dan mjesec i godinu : ";
        int d,m,g;
        std::cin>>d>>m>>g;
        std::cout<<"Pregledi na datum "<<d<<" "<<m<<" "<<g<<" su: \n";
        a.IspisiPregledeNaDatum(Datum(d,m,g));
      }
      if(opcija==6) {
        a.IspisiSvePreglede();
      }
    }
  } catch(std::domain_error e) {
    std::cout<<e.what();
  } catch(std::range_error e) {
    std::cout<<e.what();
  }
  return 0;
}
