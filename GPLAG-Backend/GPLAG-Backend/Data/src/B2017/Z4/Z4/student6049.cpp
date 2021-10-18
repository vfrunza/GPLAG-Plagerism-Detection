#include<iostream>
#include<tuple>
#include<utility>
#include<vector>
#include<iomanip>
#include<string>
#include<stdexcept>
#include<algorithm>
#include<initializer_list>
#include<memory>
class Datum {
    int dan, mjesec, godina;
    static int DajBrojDana(int mjesec, int godina);
    public:
    Datum(int dan, int mjesec, int godina) { 
        if(mjesec<1 || mjesec>12 || godina<1 || dan<1 || dan>DajBrojDana(mjesec,godina)) throw std::domain_error("Neispravan datum"); 
        Datum::dan=dan;
        Datum::mjesec=mjesec;
        Datum::godina=godina;
    }
    void Postavi(int dan, int mjesec, int godina) {
        if(mjesec<1 || mjesec>12 || godina<1 || dan<1 || dan>DajBrojDana(mjesec,godina)) throw std::domain_error("Neispravan datum");
        Datum::dan=dan;
        Datum::mjesec=mjesec;
        Datum::godina=godina;
    }
    std::tuple<int,int,int> Ocitaj() const { return std::make_tuple(dan,mjesec,godina); }
    void Ispisi() const { std::cout<<dan<<"/"<<mjesec<<"/"<<godina; }
};
int Datum::DajBrojDana(int mjesec, int godina) {
    std::vector<int> broj_dana_u_mjesecima{31,28,31,30,31,30,31,31,30,31,30,31};
    if(godina%4==0 && (godina%100!=0 || godina%400==0)) broj_dana_u_mjesecima[1]++;
    return broj_dana_u_mjesecima[mjesec-1];
}
class Vrijeme {
    int sati, minute;
    public:
    Vrijeme(int sati, int minute) {
        if(sati<0 || sati>23 || minute<0 || minute>59) throw std::domain_error("Neispravno vrijeme");
        Vrijeme::sati=sati;
        Vrijeme::minute=minute;
    }
    void Postavi(int sati, int minute) {
        if(sati<0 || sati>23 || minute<0 || minute>59) throw std::domain_error("Neispravno vrijeme");
        Vrijeme::sati=sati;
        Vrijeme::minute=minute;
    }
    std::pair<int,int> Ocitaj() const { return std::make_pair(sati,minute); }
    void Ispisi() const { std::cout<<std::right<<std::setw(2)<<std::setfill('0')<<sati<<":"<<std::setw(2)<<std::setfill('0')<<minute; }
};
class Pregled {
  std::string ime_pacijenta;
  Datum datum_pregleda;
  Vrijeme vrijeme_pregleda;
  static int DajBrDana(int mjesec,int godina);
  public: 
  Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda): ime_pacijenta(ime_pacijenta), datum_pregleda(datum_pregleda) ,vrijeme_pregleda(vrijeme_pregleda) {}
  Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda): ime_pacijenta(ime_pacijenta), datum_pregleda(dan_pregleda,mjesec_pregleda,godina_pregleda), vrijeme_pregleda(sati_pregleda,minute_pregleda) {}
  void PromijeniPacijenta(const std::string &ime_pacijenta) { this->ime_pacijenta=ime_pacijenta; }
  void PromijeniDatum(const Datum &novi_datum) { datum_pregleda=novi_datum; }
  void PromijeniVrijeme(const Vrijeme &novo_vrijeme) {vrijeme_pregleda=novo_vrijeme; }
  void PomjeriDanUnaprijed();
  void PomjeriDanUnazad();
  std::string DajImePacijenta() const { return ime_pacijenta; }
  Datum DajDatumPregleda() const { return datum_pregleda; }
  Vrijeme DajVrijemePregleda() const { return vrijeme_pregleda; }
  static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
  void Ispisi() const;
};
int Pregled::DajBrDana(int mjesec, int godina) {
    std::vector<int> broj_dana_u_mjesecima{31,28,31,30,31,30,31,31,30,31,30,31};
    if(godina%4==0 && (godina%100!=0 || godina%400==0)) broj_dana_u_mjesecima[1]++;
    return broj_dana_u_mjesecima[mjesec-1];
}
void Pregled::PomjeriDanUnaprijed() {
    std::tuple<int,int,int> dat(this->datum_pregleda.Ocitaj());
    std::get<0>(dat)++;
    if(std::get<0>(dat)>Pregled::DajBrDana(std::get<1>(dat),std::get<2>(dat))) {
        std::get<0>(dat)=1;
        std::get<1>(dat)++;
        if(std::get<1>(dat)>12) {
            std::get<1>(dat)=1;
            std::get<2>(dat)++;
        }
    }
    this->datum_pregleda.Postavi(std::get<0>(dat),std::get<1>(dat),std::get<2>(dat));
}
void Pregled::PomjeriDanUnazad() {
    std::tuple<int,int,int> dat(this->datum_pregleda.Ocitaj());
    std::get<0>(dat)--;
    if(std::get<0>(dat)<1) {
        std::get<1>(dat)--;
        if(std::get<1>(dat)<1) {
            std::get<2>(dat)--;
            std::get<1>(dat)=12;
        }
        std::get<0>(dat)=DajBrDana(std::get<1>(dat),std::get<2>(dat));
    }
}
bool Pregled::DolaziPrije(const Pregled &p1, const Pregled &p2) {
    std::tuple<int,int,int> prvi(p1.datum_pregleda.Ocitaj()), drugi(p2.datum_pregleda.Ocitaj());
    if(std::get<2>(prvi)<std::get<2>(drugi)) return true;
    else if(std::get<2>(prvi)==std::get<2>(drugi)) {
        if(std::get<1>(prvi)<std::get<1>(drugi)) return true;
        else if(std::get<1>(prvi)==std::get<1>(drugi)) {
            if(std::get<0>(prvi)<std::get<0>(drugi)) return true;
            else if(std::get<0>(prvi)==std::get<0>(drugi)) {
                std::pair<int,int> p(p1.vrijeme_pregleda.Ocitaj()),d(p2.vrijeme_pregleda.Ocitaj());
                if(p.first<d.first) return true;
                else if(p.first==d.first) return p.second<d.second;
            }
            else return false;
        }
        else return false;
    }
    return false;
}
void Pregled::Ispisi() const {
    std::cout<<std::left<<std::setw(30)<<std::setfill(' ')<<ime_pacijenta;
    datum_pregleda.Datum::Ispisi();
    std::cout<<" ";
    vrijeme_pregleda.Vrijeme::Ispisi();
    std::cout<<std::endl;
}
class Pregledi {
  std::vector<std::shared_ptr<Pregled>> pregledi;
  static bool DaLiJeRaniji(const Pregled &p1, const Pregled &p2);
  public:
  explicit Pregledi(): pregledi(0) {}
  Pregledi(std::initializer_list<Pregled> spisak_pregleda);
  ~Pregledi() {};
  Pregledi(const Pregledi &pregledi);
  Pregledi(Pregledi &&pregledi)=default;
  Pregledi &operator=(const Pregledi &pregledi);
  Pregledi &operator=(Pregledi &&pregledi)=default;
  void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
  void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
  void RegistrirajPregled(std::shared_ptr<Pregled> pregled);
  int DajBrojPregleda() const { return pregledi.size(); }
  int DajBrojPregledaNaDatum(const Datum &datum) const;
  Pregled &DajNajranijiPregled();
  Pregled DajNajranijiPregled() const;
  void IsprazniKolekciju();
  void ObrisiNajranijiPregled();
  void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
  void IspisiPregledeNaDatum(const Datum &d) const;
  void IspisiSvePreglede() const;
};
Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda) {
    pregledi.resize(spisak_pregleda.size());
    int i(0);
    for(auto pregled: spisak_pregleda) {
        pregledi[i]=std::make_shared<Pregled>(pregled);
        i++;
    }
}
Pregledi::Pregledi(const Pregledi &pregledi) {
    this->pregledi.resize(pregledi.pregledi.size());
    for(int i=0; i<pregledi.pregledi.size(); i++) this->pregledi[i]=std::make_shared<Pregled>(*(pregledi.pregledi[i]));
}
Pregledi &Pregledi::operator=(const Pregledi &pregledi) {
    if(this==&pregledi) return *this;
    this->pregledi.resize(pregledi.pregledi.size());
    for(int i=0; i<pregledi.pregledi.size(); i++) this->pregledi[i]=std::make_shared<Pregled>(*(pregledi.pregledi[i]));
    return *this;
}
void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) {
    pregledi.push_back(std::make_shared<Pregled>(Pregled(ime_pacijenta,datum_pregleda,vrijeme_pregleda)));
}
void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) {
    pregledi.push_back(std::make_shared<Pregled>(Pregled(ime_pacijenta,dan_pregleda,mjesec_pregleda,godina_pregleda,sati_pregleda,minute_pregleda)));
}
void Pregledi::RegistrirajPregled(std::shared_ptr<Pregled> pregled) {
    pregledi.push_back(pregled);
}
int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const {
    std::tuple<int,int,int> d1(datum.Ocitaj());
    int brojpregledanadatum(std::count_if(pregledi.begin(),pregledi.end(),[d1] (std::shared_ptr<Pregled> p) {
        std::tuple<int,int,int> d2(p->DajDatumPregleda().Ocitaj());
        if(std::get<0>(d1)==std::get<0>(d2) && std::get<1>(d1)==std::get<1>(d2) && std::get<2>(d1)==std::get<2>(d2)) return true;
        return false;
    }));
    return brojpregledanadatum;
}
Pregled &Pregledi::DajNajranijiPregled() {
    if(pregledi.size()==0) throw std::domain_error("Nema registriranih pregleda");
    return **std::min_element(pregledi.begin(),pregledi.end(),[](std::shared_ptr<Pregled> p1, std::shared_ptr<Pregled> p2) { return Pregled::DolaziPrije(*p1,*p2);});
} 
Pregled Pregledi::DajNajranijiPregled() const {
    if(pregledi.size()==0) throw std::domain_error("Nema registriranih pregleda");
    return **std::min_element(pregledi.begin(),pregledi.end(),[](std::shared_ptr<Pregled> p1, std::shared_ptr<Pregled> p2) { return Pregled::DolaziPrije(*p1,*p2);});
}

void Pregledi::IsprazniKolekciju() {
    pregledi.resize(0);
}
void Pregledi::ObrisiNajranijiPregled() {
    if(pregledi.size()==0) throw std::range_error("Prazna kolekcija");
    Pregled najraniji(DajNajranijiPregled());
    std::tuple<int,int,int> dat(najraniji.DajDatumPregleda().Ocitaj());
    std::tuple<int,int> vr(najraniji.DajVrijemePregleda().Ocitaj());
    for(int i=0; i<pregledi.size(); i++) {
        std::tuple<int,int,int> d(pregledi[i]->DajDatumPregleda().Ocitaj());
        std::tuple<int,int> v(pregledi[i]->DajVrijemePregleda().Ocitaj());
        if(najraniji.DajImePacijenta()==pregledi[i]->DajImePacijenta() && std::get<0>(dat)==std::get<0>(d) && std::get<1>(dat)==std::get<1>(d) && std::get<2>(dat)==std::get<2>(d) && std::get<0>(vr)==std::get<0>(v) && std::get<1>(vr)==std::get<1>(v)) {
            pregledi.erase(pregledi.begin()+i);
            i--;
        }
    }
}
void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta) {
    for(int i=0; i<pregledi.size(); i++) {
        if(pregledi[i]->DajImePacijenta()==ime_pacijenta) {
            pregledi.erase(pregledi.begin()+i);
            i--;
        }
    }
}
void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const {
    std::tuple<int,int,int> dat(datum.Ocitaj());
    std::vector<Pregled> p;
    for(int i=0; i<pregledi.size(); i++) {
        std::tuple<int,int,int> d(pregledi[i]->DajDatumPregleda().Ocitaj());
        if(std::get<0>(dat)==std::get<0>(d) && std::get<1>(dat)==std::get<1>(d) && std::get<2>(dat)==std::get<2>(d)) p.push_back(*pregledi[i]);
    }
    std::sort(p.begin(),p.end(),[](const Pregled &p1, const Pregled &p2) { return Pregled::DolaziPrije(p1,p2);});
    for(auto pregled: p) pregled.Pregled::Ispisi();
}
void Pregledi::IspisiSvePreglede() const {
    std::vector<Pregled> p;
    for(int i=0; i<pregledi.size(); i++) p.push_back(*pregledi[i]);
    std::sort(p.begin(),p.end(),[](const Pregled &p1, const Pregled &p2) { return Pregled::DolaziPrije(p1,p2);});
    for(auto pregled: p) pregled.Pregled::Ispisi();
}
int main () {
    try {
        Pregledi pregledi;
        for(;;) {
            std::string ime;
            std::cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
            std::cin>>ime;
            std::cin.ignore(1000,'\n');
            if(ime=="kraj") break;
            int d,m,g;
            std::cout<<"Unesite dan mjesec i godinu pregleda: ";
            std::cin>>d>>m>>g;
            int sati,minute;
            std::cout<<"Unesite sate i minute pregleda: ";
            std::cin>>sati>>minute;
            pregledi.RegistrirajPregled(ime,d,m,g,sati,minute);
        }
        std::cout<<"Trenutno su registrovani sljedeci pregledi"<<std::endl;
        pregledi.IspisiSvePreglede();
        int opcija(0);
        while(opcija!=7) {
            std::cout<<std::endl<<"Odaberite jednu od sljedecih opcija"<<std::endl<<"1 - Broj pregleda na datum"<<std::endl<<"2 - Najraniji pregled"<<std::endl<<"3 - Obrisi pregled pacijenta"<<std::endl<<"4 - Obrisi najraniji pregled"<<std::endl<<"5 - Ispisi sve pregleda na datum"<<std::endl<<"6 - Ispisi sve preglede"<<std::endl<<"7 - Kraj programa"<<std::endl;
            std::cin>>opcija;
            if(opcija==1) {
                int d,m,g;
                std::cout<<"Unesite dan mjesec i godinu : ";
                std::cin>>d>>m>>g;
                std::cout<<"Broj pregleda na datum "<<d<<" "<<m<<" "<<g<<" je: "<<pregledi.DajBrojPregledaNaDatum(Datum(d,m,g))<<std::endl;
            }
            if(opcija==2) {
                std::cout<<"Najraniji pregled je:"<<std::endl;
                try {
                    pregledi.DajNajranijiPregled().Pregled::Ispisi();
                }
                catch(std::domain_error izuz) {
                    std::cout<<izuz.what()<<std::endl;
                }
            }
            if(opcija==3) {
                std::cin.ignore(1000,'\n');
                std::string s;
                std::cout<<"Unesite ime pacijenta: ";
                std::cin>>s;
                int prijebrisanja(pregledi.DajBrojPregleda());
                pregledi.ObrisiPregledePacijenta(s);
                int poslijebrisanja(pregledi.DajBrojPregleda());
                std::cout<<"Uspjesno obrisano "<<prijebrisanja-poslijebrisanja<<" pregleda"<<std::endl;
            }
            if(opcija==4) {
                try {
                    pregledi.ObrisiNajranijiPregled();
                    std::cout<<"Najraniji pregled uspjesno obrisan"<<std::endl;
                }
                catch (std::range_error izuz) {
                    std::cout<<izuz.what()<<std::endl;
                }
            }
            if(opcija==5) {
                int d,m,g;
                std::cout<<"Unesite dan mjesec i godinu : ";
                std::cin>>d>>m>>g;
                std::cout<<"Pregledi na datum "<<d<<" "<<m<<" "<<g<<" su: "<<std::endl;
                pregledi.IspisiPregledeNaDatum(Datum(d,m,g));
            }
            if(opcija==6) {
                pregledi.IspisiSvePreglede();
            }
        }
    }
    catch(std::domain_error izuz) {
        std::cout<<izuz.what()<<std::endl;
    }
    catch(std::range_error izuz) {
        std::cout<<izuz.what()<<std::endl;
    }
	return 0;
}