/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <tuple>
#include <stdexcept>
#include <utility>
#include <iomanip>
#include <string>
#include <initializer_list>
#include <algorithm>

class Datum {
    int d, m, g;
    bool TestDatuma(int dan, int mjesec, int godina) const;
public:
    Datum(int dan, int mjesec, int godina) {
        if(!TestDatuma(dan, mjesec, godina)) throw std::domain_error("Neispravan datum");
        d=dan; m=mjesec; g=godina;
    };
    void Postavi(int dan, int mjesec, int godina) {
        if(!TestDatuma(dan, mjesec, godina)) throw std::domain_error("Neispravan datum");
        d=dan; m=mjesec; g=godina;
    }
    std::tuple<int, int, int> Ocitaj() const { return std::tie(d, m, g); }
    void Ispisi() const { std::cout<<d<<"/"<<m<<"/"<<g; };
};

bool Datum::TestDatuma(int dan, int mjesec, int godina) const {
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina%4==0 && godina%100!=0) || godina%400==0) broj_dana[1]++;
    if(godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>broj_dana[mjesec-1]) return false;
    return true;
}


class Vrijeme {
    int s, min;
    bool TestVremena(int sati, int minute) const;
public:
    Vrijeme(int sati, int minute) {
        if(sati<0 || sati>23 || minute<0 || minute>59) throw std::domain_error("Neispravno vrijeme");
        s=sati; min=minute;
    }
    void Postavi(int sati, int minute) {
        if(sati<0 || sati>23 || minute<0 || minute>59) throw std::domain_error("Neispravno vrijeme");
        s=sati; min=minute;
    }
    std::pair<int, int> Ocitaj () const { return std::make_pair(s, min); }
    void Ispisi() const { std::cout<<std::setw(2)<<std::setfill('0')<<s<<":"<<std::setw(2)<<min<<std::setfill(' '); }
};


class Pregled {
    std::string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;
public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) : datum_pregleda(datum_pregleda), vrijeme_pregleda(vrijeme_pregleda) { 
        Pregled::ime_pacijenta=ime_pacijenta; 
    }
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) : 
    ime_pacijenta(ime_pacijenta), datum_pregleda(dan_pregleda, mjesec_pregleda, godina_pregleda), vrijeme_pregleda(sati_pregleda, minute_pregleda) {}
    void PromijeniPacijenta(const std::string &ime_pacijenta) { Pregled::ime_pacijenta=ime_pacijenta; }
    void PromijeniDatum(const Datum &novi_datum) { datum_pregleda=novi_datum; }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme) { vrijeme_pregleda=novo_vrijeme; }
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImePacijenta() const { return ime_pacijenta; }
    Datum DajDatumPregleda() const { return datum_pregleda; }
    Vrijeme DajVrijemePregleda() const { return vrijeme_pregleda; }
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
    void Ispisi() const { std::cout<<std::setw(30)<<std::left<<ime_pacijenta<<std::right; datum_pregleda.Ispisi(); std::cout<<" "; vrijeme_pregleda.Ispisi(); std::cout<<std::endl;}
};

bool Pregled::DolaziPrije(const Pregled &p1, const Pregled &p2) {
    std::tuple<int, int, int> dat1(p1.datum_pregleda.Ocitaj()), dat2(p2.datum_pregleda.Ocitaj());
    if(std::get<2>(dat1)==std::get<2>(dat2)) {
        if(std::get<1>(dat1)==std::get<1>(dat2)) {
            if(std::get<0>(dat1)==std::get<0>(dat2)) {
                std::pair<int, int> vr1(p1.vrijeme_pregleda.Ocitaj()), vr2(p2.vrijeme_pregleda.Ocitaj());
                if(vr1.first==vr2.first) {
                    return vr1.second<vr2.second;
                }
                else return vr1.first<vr2.first;
            }
            else return std::get<0>(dat1)<std::get<0>(dat2);
        }
        else return std::get<1>(dat1)<std::get<1>(dat2);
    }
    else return std::get<2>(dat1)<std::get<2>(dat2);
}


class Pregledi {
    int br_pregleda;
    int max_br;
    Pregled **pregledi;
public:
    explicit Pregledi(int max_broj_pregleda) : br_pregleda(0), max_br(max_broj_pregleda), pregledi(new Pregled*[max_broj_pregleda]) { for(int i=0; i<max_broj_pregleda; i++) pregledi[i]=nullptr; }
    Pregledi(std::initializer_list<Pregled> spisak_pregleda);
    ~Pregledi();
    Pregledi(const Pregledi &p);
    Pregledi &operator =(const Pregledi &p);
    Pregledi(Pregledi &&p) : br_pregleda(p.br_pregleda), max_br(p.max_br) { p.pregledi=nullptr; }
    Pregledi &operator =(Pregledi &&pregledi);
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void RegistrirajPregled(Pregled *pregled);
    int DajBrojPregleda() const { return br_pregleda; }
    int DajBrojPregledaNaDatum(const Datum &datum) const;
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum(const Datum &datum) const;
    void IspisiSvePreglede() const;
};

Pregledi &Pregledi::operator=(Pregledi &&p) {
	if(p.max_br!=max_br) throw std::logic_error("Nesaglasni kapaciteti");
	std::swap(br_pregleda, p.br_pregleda);
	std::swap(pregledi, p.pregledi);
	return *this;
}

void Pregledi::IspisiSvePreglede() const {
    std::sort(pregledi+0, pregledi+br_pregleda, [](Pregled *p1, Pregled *p2)->bool { return Pregled::DolaziPrije(*p1, *p2); });
    for(int i=0; i<br_pregleda; i++) pregledi[i]->Ispisi();
}

void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const {
    std::tuple<int, int, int> d1=datum.Ocitaj();
    std::sort(pregledi+0, pregledi+br_pregleda, [](Pregled *p1, Pregled *p2)->bool { return Pregled::DolaziPrije(*p1, *p2); });
    std::for_each(pregledi+0, pregledi+br_pregleda, [d1](Pregled *p){
                                                                    std::tuple<int, int, int> d2(p->DajDatumPregleda().Ocitaj());
                                                                    if(std::get<0>(d1)==std::get<0>(d2) && std::get<1>(d1)==std::get<1>(d2) && std::get<2>(d1)==std::get<2>(d2)) p->Ispisi();
                                                                    });
}

void Pregledi::IsprazniKolekciju() {
    br_pregleda=0;
    for(int i=0; i<max_br; i++) { 
        delete pregledi[i];
        pregledi[i]=nullptr;
    }
}

void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta) {
    int br(std::count_if(pregledi+0, pregledi+br_pregleda, [ime_pacijenta](Pregled *p) { return p->DajImePacijenta()==ime_pacijenta; }));
    if(br==0) return;
    int brojac(0);
    for(int i=0; i<br_pregleda-brojac; i++) {
        if(pregledi[i]->DajImePacijenta()==ime_pacijenta) {
            auto pom=pregledi[i];
            pregledi[i]=pregledi[br_pregleda-1-brojac];
            pregledi[br_pregleda-1-brojac]=pom;
            i--;
            brojac++;
        }
    }
    for(int i=1; i<=br; i++) {
        delete pregledi[br_pregleda-i];
        pregledi[br_pregleda-i]=nullptr;
    }
    br_pregleda-=br;
}

void Pregledi::ObrisiNajranijiPregled() {
    if(br_pregleda==0) throw std::range_error("Prazna kolekcija");
    std::sort(pregledi+0, pregledi+br_pregleda, [](Pregled *p1, Pregled *p2)->bool { return Pregled::DolaziPrije(*p1, *p2); });
    auto pom=pregledi[br_pregleda-1];
    pregledi[br_pregleda-1]=pregledi[0];
    pregledi[0]=pom;
    delete pregledi[br_pregleda-1];
    pregledi[br_pregleda-1]=nullptr;
    br_pregleda--;
}

Pregled Pregledi::DajNajranijiPregled() const {
    Pregled **prvi((std::min_element(pregledi+0, pregledi+br_pregleda, [](Pregled *p1, Pregled *p2)->bool { return Pregled::DolaziPrije(*p1, *p2); })));
    if(prvi==pregledi+br_pregleda) throw std::domain_error("Nema registriranih pregleda");
    return **prvi;
}

Pregled &Pregledi::DajNajranijiPregled() {
    Pregled **prvi((std::min_element(pregledi+0, pregledi+br_pregleda, [](Pregled *p1, Pregled *p2)->bool { return Pregled::DolaziPrije(*p1, *p2); })));
    if(prvi==pregledi+br_pregleda) throw std::domain_error("Nema registriranih pregleda");
    return **prvi;
}

Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda) : br_pregleda(spisak_pregleda.size()), max_br(spisak_pregleda.size()), pregledi(new Pregled*[spisak_pregleda.size()]) {		
	for(int i=0; i<spisak_pregleda.size(); i++) pregledi[i]=nullptr;
	try {
		int i=0;
		for(auto it=spisak_pregleda.begin(); it!=spisak_pregleda.end(); it++) { pregledi[i]=new Pregled(*it); i++; }
	}
	catch(...) {
		for(int i=0; i<spisak_pregleda.size(); i++) delete pregledi[i];
		delete[] pregledi;
		pregledi=nullptr;
		throw;
	}
}

Pregledi::~Pregledi() {
    for(int i=0; i<br_pregleda; i++) {
        delete pregledi[i];
        pregledi[i]=nullptr;
    }
    delete[] pregledi;
    pregledi=nullptr;
}

int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const {
    std::tuple<int, int, int> d1=datum.Ocitaj();
    return std::count_if(pregledi+0, pregledi+br_pregleda, [d1](Pregled *p)->bool {
                                                                                    std::tuple<int, int, int> d2(p->DajDatumPregleda().Ocitaj());
                                                                                    return (std::get<0>(d1)==std::get<0>(d2) && std::get<1>(d1)==std::get<1>(d2) && std::get<2>(d1)==std::get<2>(d2));
                                                                                });
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) {
    if(br_pregleda>=max_br) throw std::range_error("Dostignut maksimalni broj pregleda");
    pregledi[br_pregleda]=new Pregled(ime_pacijenta, datum_pregleda, vrijeme_pregleda);
    br_pregleda++;
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) {
    if(br_pregleda>=max_br) throw std::range_error("Dostignut maksimalni broj pregleda");
    Datum d(dan_pregleda, mjesec_pregleda, godina_pregleda);
    Vrijeme v(sati_pregleda, minute_pregleda);
    pregledi[br_pregleda]=new Pregled(ime_pacijenta, d, v);
    br_pregleda++;
}

void Pregledi::RegistrirajPregled(Pregled *pregled) {
    if(br_pregleda>=max_br) throw std::range_error("Dostignut maksimalni broj pregleda");
    pregledi[br_pregleda]=pregled;
    br_pregleda++;
}

Pregledi::Pregledi(const Pregledi &p) : br_pregleda(p.br_pregleda), max_br(p.max_br), pregledi(new Pregled*[p.max_br]{}) {
    try {
        for(int i=0; i<max_br; i++) pregledi[i]=new Pregled(*p.pregledi[i]);
    }
    catch(...) {
        for(int i=0; i<p.max_br; i++) delete pregledi[i];
        delete[] pregledi;
        throw;
    }
}

Pregledi &Pregledi::operator =(const Pregledi &p) {
    if(p.max_br!=max_br) throw std::logic_error("Nesaglasni kapaciteti");
    if(p.max_br>br_pregleda) {
        try {
            for(int i=br_pregleda; i<max_br; i++) pregledi[i]=new Pregled(*p.pregledi[i]);
        }
        catch(...) {
            for(int i=br_pregleda; i<p.max_br; i++) {
                delete pregledi[i];
                pregledi[i]=nullptr;
            }
            throw;
        }
    }
    else {
        for(int i=p.max_br; i<max_br; i++) {
            delete pregledi[i];
            pregledi[i]=nullptr;
        }
    }
    br_pregleda=p.br_pregleda;
    for(int i=0; i<br_pregleda; i++) *pregledi[i]=*p.pregledi[i];
    return *this;
}

int main ()
{
    int n(0);
    std::cout<<"Unesite maksimalan broj pregleda: ";
    std::cin>>n;
    if(!std::cin) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        return 0;
    }
    Pregledi p(n);
    if(n!=0) {
        for(int i=0; i<n; i++) {
            std::cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
            std::string ime;
            std::cin.ignore(1000, '\n');
            std::getline(std::cin, ime);
            if(ime=="kraj") break;
            int d, m, g, s, min;
            std::cout<<"Unesite dan mjesec i godinu pregleda: ";
            std::cin>>d>>m>>g;
            std::cout<<"Unesite sate i minute pregleda: ";
            std::cin>>s>>min;
            p.RegistrirajPregled(ime, d, m, g, s, min);
        }
    }
    std::cout<<"Trenutno su registrovani sljedeci pregledi"<<std::endl;
    p.IspisiSvePreglede();
    int opcija(0);
    while(opcija!=7) {
        std::cout<<std::endl<<"Odaberite jednu od sljedecih opcija"<<std::endl<<"1 - Broj pregleda na datum"<<std::endl<<"2 - Najraniji pregled"<<std::endl<<"3 - Obrisi pregled pacijenta"<<std::endl;
        std::cout<<"4 - Obrisi najraniji pregled"<<std::endl<<"5 - Ispisi sve pregleda na datum"<<std::endl<<"6 - Ispisi sve preglede"<<std::endl<<"7 - Kraj programa"<<std::endl;
    	std::cin>>opcija;
    	if(opcija==1) {
    	    int d, m, g;
    	    std::cout<<"Unesite dan mjesec i godinu : ";
    	    std::cin>>d>>m>>g;
    	    Datum dat(d, m, g);
    	    std::cout<<"Broj pregleda na datum "<<d<<" "<<m<<" "<<g<<" je: "<<p.DajBrojPregledaNaDatum(dat)<<std::endl;
    	}
    	else if(opcija==2) {
    	    std::cout<<"Najraniji pregled je:"<<std::endl;
    	    Pregled pom(p.DajNajranijiPregled());
    	    pom.Ispisi();
    	}
    	else if(opcija==3) {
    	    std::string ime;
    	    std::cout<<"Unesite ime pacijenta: ";
    	    std::cin.ignore(1000, '\n');
    	    std::getline(std::cin, ime);
    	    int br1(p.DajBrojPregleda());
    	    p.ObrisiPregledePacijenta(ime);
    	    int br2(p.DajBrojPregleda());
    	    std::cout<<"Uspjesno obrisano "<<br1-br2<<" pregleda"<<std::endl;
    	}
    	else if(opcija==4) {
    	    p.ObrisiNajranijiPregled(); 
    	    std::cout<<"Najraniji pregled uspjesno obrisan"<<std::endl;
    	}
    	else if(opcija==5) {
    	    int d, m, g;
    	    std::cout<<"Unesite dan mjesec i godinu : ";
    	    std::cin>>d>>m>>g;
    	    Datum dat(d, m, g);
    	    std::cout<<"Pregledi na datum "<<d<<" "<<m<<" "<<g<<" su:"<<std::endl;
    	    p.IspisiPregledeNaDatum(dat);
    	}
    	else if(opcija==6) p.IspisiSvePreglede();
    }
	return 0;
}
