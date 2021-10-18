#include <iostream>
#include <string>
#include <tuple>
#include <iomanip>
#include <initializer_list>
#include <algorithm>

class Datum
{
    int d, m, g;
    static int BrojDana(int, int);
    static bool Validan(int d, int m, int g) { return m >= 1 && m <= 12 && d >= 1 && d <= BrojDana(m, g) && g > 0; }
    bool Prije(const Datum&) const;
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    bool eq(const Datum &a) const { return a.d == d && a.m == m && a.g == g; }
    friend class Pregled;
    friend class Pregledi;
public:
    Datum(int dan, int mjesec, int godina) { Postavi(dan, mjesec, godina); }
    void Postavi(int dan, int mjesec, int godina);
    std::tuple<int, int, int> Ocitaj() const { return std::make_tuple(d, m, g); }
    void Ispisi() const;
};
int Datum::BrojDana(int m, int g)
{ 
    static int br_dana[12] { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return br_dana[m-1] + (m == 2 && ((g % 100 != 0 && g % 4 == 0) || g % 400 == 0));
}
void Datum::Postavi(int dan, int mjesec, int godina)
{
    if (!Validan(dan, mjesec, godina)) throw std::domain_error("Neispravan datum");
    d = dan; m = mjesec; g = godina;
}
void Datum::Ispisi() const { std::cout << d << '/' << m << '/' << g; }
bool Datum::Prije(const Datum &x) const { return g < x.g || (g == x.g && (m < x.m || (m == x.m && d < x.d))); }
void Datum::PomjeriDanUnaprijed()
{
    if (Validan(d+1, m, g)) Postavi(d+1, m, g);
    else if (Validan(1, m+1, g)) Postavi(1, m+1, g);
    else Postavi(1, 1, g+1);
}
void Datum::PomjeriDanUnazad()
{
    if (Validan(d-1, m, g)) Postavi(d-1, m, g);
    else if (Validan(BrojDana(m-1, g), m-1, g)) Postavi(BrojDana(m-1, g), m-1, g);
    else if (g > 1) Postavi(BrojDana(12, g-1), 12, g-1);
}
class Vrijeme
{
    int h, m;
    friend class Pregled;
public:
    Vrijeme(int sati, int minute) { Postavi(sati, minute); }
    void Postavi(int sati, int minute);
    std::pair<int, int> Ocitaj() const { return std::make_pair(h, m); }
    void Ispisi() const;
};
void Vrijeme::Postavi(int sati, int minute)
{
    if (sati < 0 || sati > 23 || minute < 0 || minute > 59) throw std::domain_error("Neispravno vrijeme");
    h = sati; m = minute;
}
void Vrijeme::Ispisi() const { std::cout << (h < 10 ? "0" : "") << h << ':' << (m < 10 ? "0" : "") << m; }

class Pregled
{
    std::string imePacijenta;
    Datum datum;
    Vrijeme vrijeme;
    friend class Pregledi;
    bool IstovremenSa(const Pregled &p) { return datum.eq(p.datum) && vrijeme.h == p.vrijeme.h && vrijeme.m == p.vrijeme.m; }
public:
    Pregled(const std::string &ime, const Datum &dat, const Vrijeme &vr) : imePacijenta(ime), datum(dat), vrijeme(vr) {}
    Pregled(const std::string &ime, int dan, int mjesec, int godina, int sati, int minute) : imePacijenta(ime), datum(dan, mjesec, godina), vrijeme(sati, minute) {}
    void PromijeniPacijenta(const std::string &ime) { imePacijenta = ime; }
    void PromijeniDatum(const Datum &dat) { datum = dat; }
    void PromijeniVrijeme(const Vrijeme &vr) { vrijeme = vr; }
    void PomjeriDanUnaprijed() { datum.PomjeriDanUnaprijed(); }
    void PomjeriDanUnazad() { datum.PomjeriDanUnazad(); }
    std::string DajImePacijenta() const { return imePacijenta; }
    Datum DajDatumPregleda() const { return datum; }
    Vrijeme DajVrijemePregleda() const { return vrijeme; }
    static bool DolaziPrije(const Pregled&, const Pregled&);
    void Ispisi() const;
};
bool Pregled::DolaziPrije(const Pregled &a, const Pregled &b)
{
    return a.datum.Prije(b.datum) || (a.datum.eq(b.datum) && (a.vrijeme.h < b.vrijeme.h || (a.vrijeme.h == b.vrijeme.h && a.vrijeme.m < b.vrijeme.m)));
}
void Pregled::Ispisi() const { std::cout << std::setw(30) << std::left << imePacijenta; datum.Ispisi(); std::cout << ' '; vrijeme.Ispisi(); std::cout << std::endl; }

class Pregledi
{
    int brojPregleda{}, maxBrojPregleda{};
    Pregled **pregledi{};
    void Unisti();
    void ProvjeriMax() const { if (brojPregleda >= maxBrojPregleda) throw std::range_error("Dostignut maksimalni broj pregleda"); }
    void Ubaci(Pregled *p);
    void Izbaci(Pregled *&p) { delete p; p = nullptr; --brojPregleda; }
    Pregled *&DajNajraniji() const;
public:
    explicit Pregledi(int max) : maxBrojPregleda(max > 0 ? max : 0) { if (max > 0) pregledi = new Pregled*[max]{}; }
    Pregledi(std::initializer_list<Pregled>);
    ~Pregledi() { Unisti(); }
    Pregledi(const Pregledi &p) { *this = p; }
    Pregledi(Pregledi &&p) { *this = std::move(p); }
    Pregledi &operator =(const Pregledi &p);
    Pregledi &operator =(Pregledi &&p);
    void RegistrirajPregled(const std::string&, const Datum&, const Vrijeme&);
    void RegistrirajPregled(const std::string &ime, int d, int mj, int g, int h, int m) { RegistrirajPregled(ime, Datum(d, mj, g), Vrijeme(h, m)); }
    void RegistrirajPregled(Pregled*);
    int DajBrojPregleda() const { return brojPregleda; }
    int DajBrojPregledaNaDatum(const Datum&) const;
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta(const std::string&);
    void IspisiPregledeNaDatum(const Datum&) const;
    void IspisiSvePreglede() const;
};
void Pregledi::Unisti()
{
    IsprazniKolekciju();
    delete[] pregledi;
}
void Pregledi::Ubaci(Pregled *p)
{
    *std::find(pregledi, pregledi + maxBrojPregleda, nullptr) = p;
    ++brojPregleda;
}
Pregled *&Pregledi::DajNajraniji() const
{
    return *std::min_element(pregledi, pregledi+maxBrojPregleda, [](Pregled *a, Pregled *b) { return a && (!b || Pregled::DolaziPrije(*a, *b)); });
}
Pregledi::Pregledi(std::initializer_list<Pregled> lista) : brojPregleda(0), maxBrojPregleda(lista.size())
{
    if (maxBrojPregleda == 0) return;
    pregledi = new Pregled*[maxBrojPregleda]{};
    try {
        for (auto it(lista.begin()); it != lista.end(); ++it, ++brojPregleda) pregledi[brojPregleda] = new Pregled(*it);
    }
    catch (...) { Unisti(); throw; }
}
Pregledi &Pregledi::operator =(const Pregledi &p)
{
    if (&p == this) return *this;
    if (p.maxBrojPregleda > 0)
    {
        auto _pregledi(new Pregled*[p.maxBrojPregleda]{});
        try
        {
            for (int i(0), j(0); i < p.maxBrojPregleda; ++i)
                if (p.pregledi[i]) { _pregledi[j++] = new Pregled(*p.pregledi[i]); }
        }
        catch (...)
        {
            for (int i(0); i < p.maxBrojPregleda; ++i) delete _pregledi[i];
            delete[] _pregledi; throw;
        }
        Unisti();
        pregledi = _pregledi;
    } else pregledi = nullptr;
    maxBrojPregleda = p.maxBrojPregleda;
    brojPregleda = p.brojPregleda;
    return *this;
}
Pregledi &Pregledi::operator =(Pregledi &&p)
{
    if (&p == this) return *this;
    Unisti();
    pregledi = p.pregledi;
    brojPregleda = p.brojPregleda;
    maxBrojPregleda = p.maxBrojPregleda;
    p.pregledi = nullptr;
    p.brojPregleda = p.maxBrojPregleda = 0;
    return *this;
}
void Pregledi::RegistrirajPregled(const std::string &ime, const Datum &dat, const Vrijeme &vr)
{
    ProvjeriMax();
    Ubaci(new Pregled(ime, dat, vr));
}
void Pregledi::RegistrirajPregled(Pregled *p)
{
    ProvjeriMax(); Ubaci(p);
}
int Pregledi::DajBrojPregledaNaDatum(const Datum &dat) const
{
    return std::count_if(pregledi, pregledi+maxBrojPregleda, [&](Pregled *p) { return p && p->datum.eq(dat); });
}
Pregled &Pregledi::DajNajranijiPregled() { if (brojPregleda == 0) throw std::domain_error("Nema registriranih pregleda"); return *DajNajraniji(); }
Pregled Pregledi::DajNajranijiPregled() const { if (brojPregleda == 0) throw std::domain_error("Nema registriranih pregleda"); return *DajNajraniji(); }
void Pregledi::IsprazniKolekciju() 
{
    if (brojPregleda == 0) return;
    for (int i(0); i < maxBrojPregleda; ++i) { delete pregledi[i]; pregledi[i] = nullptr; }
    brojPregleda = 0;
}
void Pregledi::ObrisiNajranijiPregled()
{
    if (brojPregleda == 0) throw std::range_error("Prazna kolekcija");
    Izbaci(DajNajraniji());
}
void Pregledi::ObrisiPregledePacijenta(const std::string &ime)
{
    if (brojPregleda == 0) return;
    for (int i(0); i < maxBrojPregleda; ++i)
        if (pregledi[i] && pregledi[i]->imePacijenta == ime) Izbaci(pregledi[i]);
}
void Pregledi::IspisiPregledeNaDatum(const Datum &dat) const
{
    int n(DajBrojPregledaNaDatum(dat));
    if (n == 0) return;
    Pregled *trenutni(*std::min_element(pregledi, pregledi+maxBrojPregleda, [&](Pregled *a, Pregled *b) {
        return a && a->datum.eq(dat) && (!b || Pregled::DolaziPrije(*a, *b));
    })), *sljedeci(trenutni);
    for (int br(0); br < n;)
    {
        for (int i(0); i < maxBrojPregleda; ++i)
            if (pregledi[i] && pregledi[i]->datum.eq(dat))
                if (pregledi[i]->IstovremenSa(*trenutni)) { pregledi[i]->Ispisi(); if (++br == n) return; }
                else if (Pregled::DolaziPrije(*trenutni, *pregledi[i]) && (sljedeci == trenutni || Pregled::DolaziPrije(*pregledi[i], *sljedeci)))
                    sljedeci = pregledi[i];
        trenutni = sljedeci;
    }
}
void Pregledi::IspisiSvePreglede() const
{
    if (brojPregleda == 0) return;
    Pregled *trenutni(DajNajraniji()), *sljedeci(trenutni);
    for (int br(0); br < brojPregleda;)
    {
        for (int i(0); i < maxBrojPregleda; ++i)
            if (pregledi[i])
                if (pregledi[i]->IstovremenSa(*trenutni)) { pregledi[i]->Ispisi(); if (++br == brojPregleda) return; }
                else if (Pregled::DolaziPrije(*trenutni, *pregledi[i]) && (sljedeci == trenutni || Pregled::DolaziPrije(*pregledi[i], *sljedeci)))
                    sljedeci = pregledi[i];
        trenutni = sljedeci;
    }
}

int main()
{
    int n, d, mj, g, h, m;
    std::cout << "Unesite maksimalan broj pregleda: ";
	std::cin >> n;
	try
	{
	    Pregledi pregledi(n);
	    std::string s;
	    while (pregledi.DajBrojPregleda() < n)
	    {
	        std::cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
	        std::cin.ignore(10000, '\n');
	        if (std::getline(std::cin, s), s == "kraj") break;
	        std::cout << "Unesite dan mjesec i godinu pregleda: ";
    	    std::cin >> d >> mj >> g;
    	    std::cout << "Unesite sate i minute pregleda: ";
    	    std::cin >> h >> m;
    	    pregledi.RegistrirajPregled(s, Datum(d, mj, g), Vrijeme(h, m));
    	}
    	std::cout << "Trenutno su registrovani sljedeci pregledi\n";
    	pregledi.IspisiSvePreglede();
    	for (;;)
    	{
    	    std::cout << "\nOdaberite jednu od sljedecih opcija\n"
    	    "1 - Broj pregleda na datum\n"
    	    "2 - Najraniji pregled\n"
    	    "3 - Obrisi pregled pacijenta\n"
    	    "4 - Obrisi najraniji pregled\n"
    	    "5 - Ispisi sve pregleda na datum\n"
    	    "6 - Ispisi sve preglede\n"
    	    "7 - Kraj programa\n";
    	    std::cin >> n;
    	    switch (n)
    	    {
    	        case 1:
    	            std::cout << "Unesite dan mjesec i godinu : ";
    	            std::cin >> d >> mj >> g;
    	            std::cout << "Broj pregleda na datum " << d << ' ' << mj << ' ' << g << " je: " << pregledi.DajBrojPregledaNaDatum(Datum(d, mj, g)) << '\n';
    	            break;
    	        case 2: std::cout << "Najraniji pregled je:\n"; pregledi.DajNajranijiPregled().Ispisi(); break;
    	        case 3:
    	            std::cout << "Unesite ime pacijenta: ";
    	            std::cin.ignore(10000, '\n');
    	            std::getline(std::cin, s);
    	            n = pregledi.DajBrojPregleda();
    	            pregledi.ObrisiPregledePacijenta(s);
    	            std::cout << "Uspjesno obrisano " << n - pregledi.DajBrojPregleda() << " pregleda\n";
    	            break;
    	        case 4: pregledi.ObrisiNajranijiPregled(); std::cout << "Najraniji pregled uspjesno obrisan\n"; break;
    	        case 5:
    	            std::cout << "Unesite dan mjesec i godinu : ";
    	            std::cin >> d >> mj >> g;
    	            std::cout << "Pregledi na datum " << d << ' ' << mj << ' ' << g << " su:\n";
    	            pregledi.IspisiPregledeNaDatum(Datum(d, mj, g));
    	            break;
    	        case 6: pregledi.IspisiSvePreglede(); break;
    	        default: return 0;
    	    }
    	}
	}
	catch (...) {}
	return 0;
}