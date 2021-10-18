/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <utility>
#include <string>
#include <tuple>
#include <iomanip>
#include <algorithm>



class Datum
{
    int dan, mjesec, godina;
    int DajDan() const {
        return dan;
    }
    int DajMjesec() const{
        return mjesec;
    }
    int DajGodinu() const{
        return godina;
    }
    friend class Pregled;
public:
    Datum(int dan, int mjesec, int godina);
    void Postavi(int dan, int mjesec, int godina);
    std::tuple<int, int, int> Ocitaj() const;
    void Ispisi() const;
};

Datum::Datum(int dan, int mjesec, int godina)
{
    Datum::Postavi(dan, mjesec, godina);
}

void Datum::Postavi(int dan, int mjesec, int godina)
{
    Datum::dan=dan;
    Datum::mjesec=mjesec;
    Datum::godina=godina;
}

std::tuple<int, int, int> Datum::Ocitaj() const
{
    return std::make_tuple(dan, mjesec, godina);
}

void Datum::Ispisi() const
{
    std::cout << Datum::dan << "/" << Datum::mjesec << "/" << Datum::godina << " ";
}

/////////////////////////////////
class Vrijeme
{
    int sati, minute;
public:
    Vrijeme(int sati, int minute);
    void Postavi(int sati, int minute);
    std::pair<int, int> Ocitaj () const;
    void Ispisi() const;
};

Vrijeme::Vrijeme(int sati, int minute)
{
    Postavi(sati, minute);
}

void Vrijeme::Postavi(int sati, int minute)
{
    Vrijeme::sati=sati;
    Vrijeme::minute=minute;
}

std::pair<int, int> Vrijeme::Ocitaj() const
{
    return std::make_pair(sati, minute);
}

void Vrijeme::Ispisi() const
{
    if(Vrijeme::sati < 10)std::cout << "0";
    std::cout << Vrijeme::sati << ":";
    if(Vrijeme::minute < 10)std::cout << "0";
    std::cout << Vrijeme::minute << std::endl;
}

//////////////////////////////////
class Pregled
{
    std::string ime;
    Datum d;
    Vrijeme v;
    static int broj_pregleda;
    friend class Pregledi;
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

Pregled::Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda):d(datum_pregleda), v(vrijeme_pregleda)
{
    Pregled::ime=ime_pacijenta;
    broj_pregleda++;
}

Pregled::Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda):d(dan_pregleda, mjesec_pregleda, godina_pregleda), v(sati_pregleda, minute_pregleda)
{
    Pregled::ime=ime_pacijenta;
    broj_pregleda++;
}

void Pregled::PromijeniPacijenta(const std::string &ime_pacijenta)
{
    Pregled::ime=ime_pacijenta;
}

void Pregled::PromijeniDatum(const Datum &novi_datum)
{
    Pregled::d=novi_datum;
}

void Pregled::PromijeniVrijeme(const Vrijeme &novo_vrijeme)
{
    Pregled::v=novo_vrijeme;
}

int Pregled::broj_pregleda=0;

void Pregled::PomjeriDanUnaprijed()
{
    int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
    int da,mj,gd;
    std::tuple<int, int, int> p(Pregled::d.Datum::Ocitaj());
    std::tie(da,mj,gd)=p;
    if(gd % 4 == 0 && gd % 100 != 0 || gd % 400 == 0)
        broj_dana[1]++;
    da++;
    if(da > broj_dana[mj-1]) da=1, mj++;
    if(mj>12) mj=1, gd++;
    Pregled::d.dan=da;
    Pregled::d.mjesec=mj;
    Pregled::d.godina=gd;
}

void Pregled::PomjeriDanUnazad()
{
    int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
    int da,mj,gd;
    std::tuple<int, int, int> p(Pregled::d.Datum::Ocitaj());
    std::tie(da,mj,gd)=p;
    if(gd % 4 == 0 && gd % 100 != 0 || gd % 400 == 0)
        broj_dana[1]++;
    da--;
    if(da < 1) {
        da=broj_dana[mj-1];
        mj--;
    }
    if(mj<1) {
        da=broj_dana[11];
        mj=12;
        gd--;
    }
    Pregled::d.dan=da;
    Pregled::d.mjesec=mj;
    Pregled::d.godina=gd;
}


std::string Pregled::DajImePacijenta() const
{
    return Pregled::ime;
}

Datum Pregled::DajDatumPregleda() const
{
    return Pregled::d;
}

Vrijeme Pregled::DajVrijemePregleda() const
{
    return Pregled::v;
}

bool Pregled::DolaziPrije(const Pregled &p1, const Pregled &p2)
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

void Pregled::Ispisi() const
{
    std::cout << std::left << std::setw(30) << DajImePacijenta();
    d.Datum::Ispisi();
    v.Vrijeme::Ispisi();
}

//////////////////////////////
class Pregledi
{
    Pregled **p;
    int max;
    int ukupan_broj_pregleda;
    friend class Pregled;
public:    
    explicit Pregledi(int max_broj_pregleda);
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

Pregledi::Pregledi(int max_broj_pregleda):max(max_broj_pregleda)
{
    p=new Pregled*[max];
    Pregledi::ukupan_broj_pregleda=0;
}

Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda):max(spisak_pregleda.size())
{
    ukupan_broj_pregleda=spisak_pregleda.size();
    
    p=new Pregled*[ukupan_broj_pregleda];
    
    int i(0);
	for(auto it=spisak_pregleda.begin(); it != spisak_pregleda.end(); it++) 
	{
		try {
			p[i] = new Pregled(*it);
			i++;
		} catch(std::bad_alloc) {
			for(int i=0; i<ukupan_broj_pregleda; i++) 
			{
				delete[] p[i];
				p[i]=nullptr;
			}
			delete[] p;
			throw;
		}
	}
}

Pregledi::~Pregledi()
{
    for(int i=0; i<ukupan_broj_pregleda; i++) delete p[i];
    delete[] p;
}

Pregledi::Pregledi(const Pregledi &pregledi):max(pregledi.max)
{
    ukupan_broj_pregleda=pregledi.ukupan_broj_pregleda;
    for(int i=0; i<ukupan_broj_pregleda; i++) p[i]=nullptr;
    try {
		for(int i=0; i<ukupan_broj_pregleda; i++) {
			p[i]=new Pregled(*pregledi.p[i]);

		}
	} catch(...) {
		for(int i=0; i<ukupan_broj_pregleda; i++) delete[] p[i];
        delete[] p;
		throw;
	}
}

Pregledi::Pregledi(Pregledi &&pregledi):max(pregledi.max)
{
    ukupan_broj_pregleda=pregledi.ukupan_broj_pregleda;
    p=pregledi.p;
    pregledi.p=nullptr;
    pregledi.ukupan_broj_pregleda = 0;
}

Pregledi &Pregledi::operator =(const Pregledi &pregledi){
    if(this != &pregledi)
    {
        for (int i=0; i<ukupan_broj_pregleda; i++)delete[] p[i];
        delete[] p;
        ukupan_broj_pregleda=pregledi.ukupan_broj_pregleda;
        p=new Pregled*[pregledi.max];
        for(int i=0; i<ukupan_broj_pregleda; i++) p[i]=new Pregled(*pregledi.p[i]);
    }
    return *this;
}

Pregledi &Pregledi::operator =(Pregledi &&pregledi)
{
    std::swap(ukupan_broj_pregleda, pregledi.ukupan_broj_pregleda);
    std::swap(p, pregledi.p);
    
    return *this;
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda)
{
    if(ukupan_broj_pregleda > max)throw std::range_error("Dostignut maksimalan broj pregleda");
    Pregled pregled{ime_pacijenta, datum_pregleda, vrijeme_pregleda};
    p[ukupan_broj_pregleda++]=new Pregled(pregled);
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda)
{
    if(ukupan_broj_pregleda > max)throw std::range_error("Dostignut maksimalan broj pregleda");
    Pregled pregled{ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda};
    p[ukupan_broj_pregleda++]=nw(pregled);
    
    // DINAMICKA ALOKACIJA JE SMRT
    
    //std::cout << "XXXXXXXXX";
    //if(max==ukupan_broj_pregleda)delete[] p[ukupan_broj_pregleda];
}

void Pregledi::RegistrirajPregled(Pregled *pregled)
{
    if(ukupan_broj_pregleda > max) throw std::range_error("Dostignut maksimalan broj pregleda");
    p[ukupan_broj_pregleda++]=pregled;
}

int Pregledi::DajBrojPregleda() const
{
    return Pregledi::ukupan_broj_pregleda;
}

int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const
{
    int broj = std::count_if(p,p+ukupan_broj_pregleda , [&datum](Pregled *p1)
    {
        if(std::get<0>(p1->DajDatumPregleda().Ocitaj())==std::get<0>(datum.Ocitaj())&&
        std::get<1>(p1->DajDatumPregleda().Ocitaj()) == std::get<1>(datum.Ocitaj()) &&
        std::get<2>(p1->DajDatumPregleda().Ocitaj()) == std::get<2>(datum.Ocitaj())) return true;
        return false;
    });
    return broj;
}

Pregled &Pregledi::DajNajranijiPregled()
{
   
auto pom(*std::min_element(p, p+ukupan_broj_pregleda, [](Pregled *p1, Pregled *p2)
    {
        if(Pregled::DolaziPrije(*p1,*p2)) return true;
        return false;
        
    }));
    return *pom;
}
Pregled Pregledi::DajNajranijiPregled() const
{
    if(ukupan_broj_pregleda==0) throw std::domain_error("Nema registriranih pregleda");
    auto pom(*std::min_element(p, p+ukupan_broj_pregleda, [](Pregled *p1, Pregled *p2)
    {
        if(Pregled::DolaziPrije(*p1,*p2)) return true;
        return false;
        
    }));
    return *pom;
}
void Pregledi::IsprazniKolekciju()
{
    for(int i=0; i<ukupan_broj_pregleda; i++) delete[] p[i];
    delete[] p;
}
void Pregledi::ObrisiNajranijiPregled()
{
    int index(0);
    auto pom(*std::min_element(p, p+ukupan_broj_pregleda, [](Pregled *p1, Pregled *p2)
    {
        if(Pregled::DolaziPrije(*p1,*p2)) return true;
        return false;
        
    }));
    
    /*for(int i=0; i<ukupan_broj_pregleda; i++)
    {
        
        if(pom==p[i])index=i;
        
    }*/
    
    std::remove_if(p, p+ukupan_broj_pregleda, [pom](Pregled *p1)
    {
        if(std::get<0>(p1->DajDatumPregleda().Ocitaj())==std::get<0>(pom->DajDatumPregleda().Ocitaj()) && std::get<1>(p1->DajDatumPregleda().Ocitaj())==std::get<1>(pom->DajDatumPregleda().Ocitaj()) && std::get<2>(p1->DajDatumPregleda().Ocitaj())==std::get<2>(pom->DajDatumPregleda().Ocitaj())) return true;
        return false;
    });
    ukupan_broj_pregleda--;
   // delete[] p[index];
    
}
void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta)
{
    for(int i=0; i<ukupan_broj_pregleda; i++)
    {
        if(p[i]->DajImePacijenta()==ime_pacijenta)
        {
            std::remove(p, p+ukupan_broj_pregleda, p[i]);
            break;
        }
    }
    ukupan_broj_pregleda--;
}
void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const
{
    std::sort(p, p+ukupan_broj_pregleda, [](Pregled *p1, Pregled *p2)
    {
        if(Pregled::DolaziPrije(*p1,*p2))return true;
        return false;
    });
    
    for(int i=0; i<ukupan_broj_pregleda; i++)
    {
       if(std::get<0>(p[i]->Pregled::DajDatumPregleda().Ocitaj())==std::get<0>(datum.Datum::Ocitaj()) && std::get<1>(p[i]->Pregled::DajDatumPregleda().Ocitaj())==std::get<1>(datum.Datum::Ocitaj()) && std::get<2>(p[i]->Pregled::DajDatumPregleda().Ocitaj())==std::get<2>(datum.Datum::Ocitaj()))p[i]->Ispisi();
    }
    
}
void Pregledi::IspisiSvePreglede() const
{
    
    std::sort(p, p+ukupan_broj_pregleda, [](Pregled *p1, Pregled *p2)
    {
        if(Pregled::DolaziPrije(*p1,*p2))return true;
        return false;
    });
    for(int i=0; i<ukupan_broj_pregleda; i++)
    {
       p[i]->Ispisi();
    }
}


int main ()
{
    
    std::cout << "Unesite maksimalan broj pregleda: ";
    int n;
    std::cin >> n;
    Pregledi preg(n);
    
    for(int i=0; i<n; i++)
    {
        std::cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        std::string s;
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::getline(std::cin,s);
        if(s=="kraj")break;
        std::cout << "Unesite dan mjesec i godinu pregleda: ";
        int dan, mjesec, godina;
        std::cin >> dan >> mjesec >> godina;
        std::cout << "Unesite sate i minute pregleda: ";
        int h, m;
        std::cin >> h >> m;
        preg.Pregledi::RegistrirajPregled(s, dan, mjesec, godina, h, m);
    }
    
    std::cout << "Trenutno su registrovani sljedeci pregledi" << std::endl;
    preg.Pregledi::IspisiSvePreglede();
    
    int x;
    
while(1)
{
    std::cout << std::endl << "Odaberite jednu od sljedecih opcija" << std::endl;
    std::cout << "1 - Broj pregleda na datum" << std::endl;
    std::cout << "2 - Najraniji pregled" << std::endl;
    std::cout << "3 - Obrisi pregled pacijenta" << std::endl;
    std::cout << "4 - Obrisi najraniji pregled" << std::endl;
    std::cout << "5 - Ispisi sve pregleda na datum" << std::endl;
    std::cout << "6 - Ispisi sve preglede" << std::endl;
    std::cout << "7 - Kraj programa" << std::endl;
    
    std::cin >> x;
    if(x==7)break;
    
   /* if(x==1)
    {
        std::cout << "Unesite dan mjesec i godinu : ";
        int d, m, g;
        std::cin >> d >> m >> g;
        Datum dat(0,0,0);
        dat.Datum::Postavi(d,m,g);
        preg.Pregledi::IspisiPregledeNaDatum(dat);
        //preg.Pregledi::IspisiPregledeNaDatum(dat.Datum::Postavi(d,m,g));
    }*/
    
    if(x==1)
    {
        std::cout << "Unesite dan mjesec i godinu : ";
        int d, m, g;
        std::cin >> d >> m >> g;
        Datum dat(0,0,0);
        dat.Datum::Postavi(d,m,g);
        std::cout << "Broj pregleda na datum ";
        std::cout << d << " " << m << " " << g << " je: ";
        std::cout << preg.Pregledi::DajBrojPregledaNaDatum(dat) << std::endl;
    }
    if(x==4)
    {
        /*for(int i=0; i<n; i++)
        {
            
            
            if(*p==preg.Pregledi::DajNajranijiPregled())delete preg[i];
            
            p++;
        }*/
        preg.Pregledi::ObrisiNajranijiPregled();
        
        std::cout << "Najraniji pregled uspjesno obrisan" << std::endl;
       // auto u(preg.Pregledi::DajNajranijiPregled());
        //preg.Pregledi::~Pregledi();
        
    }
    if(x==6)
    {
        preg.Pregledi::IspisiSvePreglede();
    }
    
}    
    return 0;
}
