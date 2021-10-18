/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <tuple>
#include <utility>
#include <iomanip>
#include <stdexcept>
#include <string>

class Datum
{
	int d, m, g;
	public:
	Datum(int dan, int mjesec, int godina) : d(0), m(0), g(0) {d = dan; m = mjesec; g = godina;}
    void Postavi(int dan, int mjesec, int godina);
    int DajDan() const {return d;}
    std::tuple<int, int, int> Ocitaj() const{ return (std::make_tuple(d,m,g));}
    void Ispisi() const {std::cout << d << "/" << m << "/" << g;}
};

class Vrijeme
{
    int s, m;
	public:
	Vrijeme(int sati, int minute) {s = sati; m = minute;}
    void Postavi(int sati, int minute);
    std::pair<int, int> Ocitaj () const {return (std::make_pair(s, m));}
    void Ispisi() const {std::cout.fill('0'); std::cout.width(2); std::cout << s << ":";
        std::cout.fill('0'); std::cout.width(2); std::cout << m; }
};

class Pregled
{
    std::string ime;
    Datum datum_pr;
    Vrijeme vrijeme_pr;
	public:
	Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) : datum_pr(datum_pregleda), vrijeme_pr(vrijeme_pregleda)
	{
	    ime = ime_pacijenta; datum_pr = datum_pregleda; vrijeme_pr = vrijeme_pregleda;
	}
	Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) : datum_pr(dan_pregleda,mjesec_pregleda,godina_pregleda), vrijeme_pr(sati_pregleda,minute_pregleda)
	{
	    ime = ime_pacijenta;
	}
	void Postavi(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda)
	{
	    this->ime = ime_pacijenta; this->datum_pr = datum_pregleda; this->vrijeme_pr = vrijeme_pregleda;
	}
    void PromijeniPacijenta(const std::string &ime_pacijenta) {ime = ime_pacijenta;}
    void PromijeniDatum(const Datum &novi_datum) {datum_pr = novi_datum;}
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme) {vrijeme_pr = novo_vrijeme;}
    void PomjeriDanUnaprijed()
    {
        int dan = datum_pr.DajDan(); dan += 1;
    }
    void PomjeriDanUnazad()
    {
        int dan = datum_pr.DajDan(); dan -= 1;
    }
    std::string DajImePacijenta() const {return ime;}
    Datum DajDatumPregleda() const {return datum_pr;}
    Vrijeme DajVrijemePregleda() const {return vrijeme_pr;}
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2)
    {
        if(p1.DajDatumPregleda().Ocitaj() > p2.DajDatumPregleda().Ocitaj()) return true;
        else return false;
    }
    void Ispisi() const
    {
        std::cout << std::left << std::cout.width(30) << DajImePacijenta();
        DajDatumPregleda().Ispisi(); std::cout << " "; DajVrijemePregleda().Ispisi(); std::cout << std::endl;
    }
};

class Pregledi
{
    const int kapacitet;
    int broj_evidentiranih;
    Pregled **svi_pregledi;
    public:
	explicit Pregledi(int max_broj_pregleda) : kapacitet(max_broj_pregleda), broj_evidentiranih(0), svi_pregledi(new Pregled*[max_broj_pregleda]) {}
    Pregledi(std::initializer_list<Pregled> spisak_pregleda) : broj_evidentiranih(spisak_pregleda.size()), kapacitet(spisak_pregleda.size()), svi_pregledi(new Pregled*[spisak_pregleda.size()])
    {
        int brojac(0);
        for(auto &x : spisak_pregleda) svi_pregledi[brojac++] = new Pregled(x);
    }
    ~Pregledi();
    Pregledi(const Pregledi &pregledi);
    Pregledi(Pregledi &&pregledi);
    Pregledi &operator =(const Pregledi &pregledi);
    Pregledi &operator =(Pregledi &&pregledi);
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda)
    {
        Pregled(ime_pacijenta, datum_pregleda, vrijeme_pregleda);
        int index(-1);
        for (int i = 0; i < broj_evidentiranih; i++)
        {
            if(svi_pregledi[i]->DajImePacijenta() == ime_pacijenta) index = i;
        }
        if (index == -1) throw std::domain_error ("Pacijent nije nadjen");
        if (broj_evidentiranih == kapacitet) throw std::range_error ("Dostignut maksimalni broj pregleda");
        //svi_pregledi[index]->Pregled(ime_pacijenta, datum_pregleda, vrijeme_pregleda);
    }
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda)
    {
        Pregled(ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda);
        int index(-1);
        for (int i = 0; i < broj_evidentiranih; i++)
        {
            if(svi_pregledi[i]->DajImePacijenta() == ime_pacijenta) index = i;
        }
        if (index == -1) throw std::domain_error ("Pacijent nije nadjen");
        if (broj_evidentiranih == kapacitet) throw std::range_error ("Dostignut maksimalni broj pregleda");
        
    }
    void RegistrirajPregled(Pregled *pregled);
   /* {
        if (broj_evidentiranih == kapacitet) throw std::range_error ("Dostignut maksimalni broj pregleda");
        for (int i = 0; i < broj_evidentiranih; i++)
        {
            
        }
    }*/
    int DajBrojPregleda() const {return broj_evidentiranih;}
    int DajBrojPregledaNaDatum(const Datum &datum) const; //realizirati pomocu count_if
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum(const Datum &datum) const;
    void IspisiSvePreglede() const;
    void Obrisi ()
    {
        if (svi_pregledi == nullptr) return;
        for (int i = 0; i < broj_evidentiranih; i++) delete svi_pregledi[i];
        delete[] svi_pregledi; 
    }
};

void Datum::Postavi(int dan, int mjesec, int godina)
{
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0) broj_dana[1]++;
    if(godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > broj_dana[mjesec - 1])
        throw std::domain_error ("Nesipravan datum");
    this->d = dan; this->m = mjesec; this->g = godina;
}


void Vrijeme::Postavi(int sati, int minute)
{
    if(sati < 0 || sati > 23) throw std::domain_error ("Neispravno vrijeme");
    else s = sati;
    if(minute < 0 || minute > 59) throw std::domain_error ("Neispravno vrijeme");
    else m = minute;
}

Pregledi::~Pregledi()
{
    for (int i = 0; i < broj_evidentiranih; i++) delete svi_pregledi[i];
    delete[] svi_pregledi;
}

Pregledi::Pregledi(const Pregledi &pregledi) : kapacitet(pregledi.kapacitet), broj_evidentiranih(pregledi.broj_evidentiranih), svi_pregledi(new Pregled*[pregledi.kapacitet])
{
    for (int i = 0; i < pregledi.broj_evidentiranih; i++)
    {
        svi_pregledi[i] = new Pregled(*pregledi.svi_pregledi[i]);
    }
}

Pregledi::Pregledi(Pregledi &&pregledi) : kapacitet(pregledi.kapacitet), broj_evidentiranih(pregledi.broj_evidentiranih), svi_pregledi(pregledi.svi_pregledi)
{
    pregledi.svi_pregledi = nullptr; pregledi.broj_evidentiranih = 0;
}

Pregledi &Pregledi::operator =(const Pregledi &pregledi)
{
    if (&pregledi != this)
    {
        Obrisi();
        broj_evidentiranih = pregledi.broj_evidentiranih;
        for (int i = 0; i < pregledi.broj_evidentiranih; i++) 
        {
            svi_pregledi[i] = new Pregled(*pregledi.svi_pregledi[i]);
        }
    }
    return *this;
}

Pregledi &Pregledi::operator =(Pregledi &&pregledi)
{
    if (&pregledi != this)
    {
        Obrisi();
        svi_pregledi = pregledi.svi_pregledi;
        broj_evidentiranih = pregledi.broj_evidentiranih;
        pregledi.svi_pregledi = nullptr;
    }
    return *this;
}


int main ()
{
    try{
	int max_br_pr;
	std::cout << "Unesite maksimalan broj pregleda: ";
	std::cin >> max_br_pr;
	std::string ime_pac;
	int d, m, g, s, min;
	Datum datum_preg(d, m, g);
	Vrijeme vrijeme_preg(s, min);
	Pregled pregl(ime_pac, datum_preg, vrijeme_preg);
	//std::cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
	//std::getline(std::cin, ime_pac);
	//std::cin.ignore(1000, '\n');
	for (int i = 0; i < max_br_pr; i++)
	{
	    std::cin.ignore(1000, '\n');
	    std::cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
	    std::getline(std::cin, ime_pac);
	    
	    if (ime_pac.compare("kraj") == 0)
	    {
	        std::cout << "Trenutno su registrovani sljedeci pregledi" << std::endl;
	        pregl.Ispisi(); std::cout << std::endl;
	    }
	    
	    
	    std::cout << "Unesite dan mjesec i godinu pregleda: ";
	    std::cin >> d >> m >> g;  datum_preg.Postavi(d,m,g);
	    std::cout << "Unesite sate i minute pregleda: ";
	    std::cin >> s >> min;  vrijeme_preg.Postavi(s,min);
	    pregl.Postavi(ime_pac, datum_preg, vrijeme_preg);

	}
	
	
	std::cout << std::endl << "Odaberite jednu od sljedecih opcija: ";
	int n;
	std::cin >> n;
	do{
	if (n == 1) std::cout << "1 - Broj pregleda na datum";
	if (n == 2) std::cout << "2 - Najraniji pregled";
	if (n == 3) std::cout << "3 - Obrisi pregled pacijenta";
	if (n == 4) std::cout << "4 - Obrisi najraniji pregled";
	if (n == 5) std::cout << "5 - Ispisi sve pregleda na datum";
	if (n == 6) std::cout << "6 - Ispisi sve preglede";
	if (n == 7) {std::cout << "7 - Kraj programa"; return 0;}
	} while (n != 1 || n != 2 || n != 3 || n != 4 || n != 5 || n != 6 || n != 7);
    }
    catch (std::domain_error izuzetak)
    {
        std::cout << izuzetak.what() << std::endl;
    }
	return 0;
}