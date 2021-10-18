#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <stdexcept>

class Spremnik
{
protected:
    double tezina;
    std::string ime;
public:
    Spremnik(double tezina, const std::string &ime) : tezina(tezina), ime(ime) {}
    virtual ~Spremnik() {}
    double DajTezinu() { return tezina; }
    virtual double DajUkupnuTezinu() const = 0;
    virtual void Ispisi() const = 0;
    virtual Spremnik *DajKopiju() const = 0;
};
typedef std::shared_ptr<Spremnik> PSpremnik;

class Sanduk : public Spremnik
{
    std::vector<double> tezine;
public:
    Sanduk(double tezina, const std::string &ime, const std::vector<double> &tezine)
    : Spremnik(tezina, ime), tezine(tezine) {}
    double DajUkupnuTezinu() const override;
    void Ispisi() const override;
    Spremnik *DajKopiju() const override { return new Sanduk(*this); }
};
double Sanduk::DajUkupnuTezinu() const
{
    double s(tezina);
    for (auto x : tezine) s += x;
    return s;
}
void Sanduk::Ispisi() const
{
    std::cout << "Vrsta spremnika: Sanduk\nSadrzaj: " << ime << "\nTezine predmeta:";
    for (auto x : tezine) std::cout << ' ' << x;
    std::cout << " (kg)\nVlastita tezina: " << tezina << " (kg)\nUkupna tezina: " << DajUkupnuTezinu() << " (kg)\n";
}

class Vreca : public Spremnik
{
    double tezinaSadrzaja;
public:
    Vreca(double tezina, const std::string &ime, double tezinaSadrzaja)
    : Spremnik(tezina, ime), tezinaSadrzaja(tezinaSadrzaja) {}
    double DajUkupnuTezinu() const override { return tezina + tezinaSadrzaja; }
    void Ispisi() const override;
    Spremnik *DajKopiju() const override { return new Vreca(*this); }
};
void Vreca::Ispisi() const
{
    std::cout << "Vrsta spremnika: Vreca\nSadrzaj: " << ime << "\nVlastita tezina: " << tezina
    << " (kg)\nTezina pohranjene materije: " << tezinaSadrzaja << " (kg)\nUkupna tezina: " << DajUkupnuTezinu() << " (kg)\n";
}

class Bure : public Spremnik
{
    double gustina, zapremina;
public:
    Bure(double tezina, const std::string &ime, double gustina, double zapremina)
    : Spremnik(tezina, ime), gustina(gustina), zapremina(zapremina) {}
    double DajUkupnuTezinu() const override { return tezina + gustina * zapremina / 1000.; }
    void Ispisi() const override;
    Spremnik *DajKopiju() const override { return new Bure(*this); }
};
void Bure::Ispisi() const
{
    std::cout << "Vrsta spremnika: Bure\nSadrzaj: " << ime << "\nVlastita tezina: " << tezina
    << " (kg)\nSpecificna tezina tecnosti: " << gustina << " (kg/m^3)\nZapremina tecnosti: " << zapremina << " (l)\nUkupna tezina: " << DajUkupnuTezinu() << " (kg)\n";
}

class Skladiste
{
    std::vector<PSpremnik> spremnici;
public:
    Skladiste() = default;
    ~Skladiste() = default;
    Skladiste(const Skladiste&);
    Skladiste(Skladiste &&s) { std::swap(spremnici, s.spremnici); }
    Skladiste &operator =(Skladiste s) { std::swap(spremnici, s.spremnici); return *this; }
    Spremnik *DodajSanduk(double t, const std::string &i, const std::vector<double> &v);
    Spremnik *DodajVrecu(double t, const std::string &i, double ts);
    Spremnik *DodajBure(double t, const std::string &i, double g, double z);
    Spremnik *DodajSpremnik(Spremnik*, bool);
    void BrisiSpremnik(Spremnik*);
    Spremnik &DajNajlaksi();
    Spremnik &DajNajtezi();
    int BrojPreteskih(int) const;
    void IzlistajSkladiste() const;
    void UcitajIzDatoteke(const std::string&);
};
Skladiste::Skladiste(const Skladiste &s) : spremnici(s.spremnici.size())
{
    std::transform(s.spremnici.begin(), s.spremnici.end(), spremnici.begin(), [](const PSpremnik &p) {
        auto kopija(p->DajKopiju());
        PSpremnik novi;
        try { novi = PSpremnik(kopija); }
        catch (...) { delete kopija; throw; }
        return novi;
    });
}

Spremnik *Skladiste::DodajSanduk(double t, const std::string &i, const std::vector<double> &v)
{
    auto novi(std::make_shared<Sanduk>(t, i, v));
    spremnici.emplace_back(novi);
    return novi.get();
}
Spremnik *Skladiste::DodajVrecu(double t, const std::string &i, double ts)
{
    auto novi(std::make_shared<Vreca>(t, i, ts));
    spremnici.emplace_back(novi);
    return novi.get();
}
Spremnik *Skladiste::DodajBure(double t, const std::string &i, double g, double z)
{
    auto novi(std::make_shared<Bure>(t, i, g, z));
    spremnici.emplace_back(novi);
    return novi.get();
}
//?Sta ako se dodaje spremnik koji je vec dodan
Spremnik *Skladiste::DodajSpremnik(Spremnik *s, bool vlasnik)
{
    if (!vlasnik) s = s->DajKopiju();
    else if (std::find_if(spremnici.begin(), spremnici.end(), [s](const PSpremnik &p) { return s == p.get(); }) != spremnici.end()) return s;
    try { spremnici.emplace_back(s); }
    catch (...) { delete s; throw; }
    return s;
}
void Skladiste::BrisiSpremnik(Spremnik *s)
{
    auto it(std::find_if(spremnici.begin(), spremnici.end(), [s](const PSpremnik &x) { return x.get() == s; }));
    if (it != spremnici.end()) spremnici.erase(it);
}
Spremnik &Skladiste::DajNajlaksi()
{
    if (spremnici.empty()) throw std::range_error("Skladiste je prazno");
    return **std::min_element(spremnici.begin(), spremnici.end(), [](const PSpremnik &a, const PSpremnik &b) { return a->DajTezinu() < b->DajTezinu(); });
}
Spremnik &Skladiste::DajNajtezi()
{
    if (spremnici.empty()) throw std::range_error("Skladiste je prazno");
    return **std::max_element(spremnici.begin(), spremnici.end(), [](const PSpremnik &a, const PSpremnik &b) { return a->DajTezinu() < b->DajTezinu(); });
}
int Skladiste::BrojPreteskih(int t) const
{
    return std::count_if(spremnici.begin(), spremnici.end(), [t](const PSpremnik &x) { return x->DajUkupnuTezinu() > t; });
}
void Skladiste::IzlistajSkladiste() const
{
    auto pom(spremnici);
    std::sort(pom.begin(), pom.end(), [](const PSpremnik &a, const PSpremnik &b) { return a->DajUkupnuTezinu() > b->DajUkupnuTezinu(); });
    for (auto &x : pom) x->Ispisi();
}

struct Znak { char c; Znak(char c) : c(c) {} };
using std::fstream; using std::ios;
#include <cctype>
class Fajl : public fstream
{
    void Besmisleni() { throw std::logic_error("Datoteka sadrzi besmislene podatke"); }
    void GreskaCitanje() { if (bad()) throw std::logic_error("Problemi pri citanju datoteke"); }
    void GreskaPisanje() { if (bad()) throw std::logic_error("Problemi sa upisom u datoteku"); }
    Fajl &ProvjeriTok(bool pisanje = true);
    bool ProvjeriPredBroj() { return !std::isspace(peek()); }
public:
    explicit Fajl(const std::string &ime, ios_base::openmode mod = ios::in | ios::out) : fstream(ime, mod) { }
    Fajl(const Fajl&) = delete;
    int get(bool = true);
    int peek(bool = true);
    Fajl &seekg(std::streampos poz){ fstream::seekg(poz); return ProvjeriTok(false); }
    Fajl &seekg(std::streamoff off, ios::seekdir way) { fstream::seekg(off, way); return ProvjeriTok(); }
    Fajl &seekp(std::streampos poz){ fstream::seekp(poz); return ProvjeriTok(); }
    Fajl &seekp(std::streamoff off, ios::seekdir way) { fstream::seekp(off, way); return ProvjeriTok(); }
    std::streampos tellg() { int x(fstream::tellg()); ProvjeriTok(false); return x; }
    template <typename T> Fajl &operator >>(T &x) { if (eof()) Besmisleni(); fstream::operator>>(x); return ProvjeriTok(false); }
    template <typename T> Fajl &operator <<(const T &x) { fstream::operator<<(x); return ProvjeriTok(); }
    Fajl &operator >>(double &x) { if (!ProvjeriPredBroj()) Besmisleni(); return operator>> <double>(x); }
    Fajl &operator >>(int &x) { if (!ProvjeriPredBroj()) Besmisleni(); return operator>> <int>(x); }
    Fajl &operator >>(Znak z) { if (get() != z.c) Besmisleni(); return ProvjeriTok(false); }
    Fajl &operator >>(std::string &s) { if (eof()) Besmisleni(); std::getline(*this, s); return ProvjeriTok(false); }
    int DajDuzinu() { seekg(0, ios::end); return tellg(); }
    
    Fajl &read(char *s, std::streamsize n) { if (eof()) Besmisleni(); fstream::read(s, n); return ProvjeriTok(false); }
    Fajl &write(const char *s, std::streamsize n) { fstream::write(s, n); return ProvjeriTok(); }
    
    template <typename T> Fajl &Ucitaj(T &x) { return read(reinterpret_cast<char*>(&x), sizeof x); }
    template <typename T> Fajl &Upisi(const T &x) { return write(reinterpret_cast<const char*>(&x), sizeof x); }
};
Fajl &Fajl::ProvjeriTok(bool pisanje)
{
    if (bad())
        if (pisanje) GreskaPisanje(); else GreskaCitanje();
    else if (fail()) Besmisleni();
    return *this;
}
int Fajl::get(bool provjeravaj)
{
    if (eof()) Besmisleni();
    if (!provjeravaj) return fstream::get();
    int x(fstream::get());
    ProvjeriTok(false);
    return x;
}
int Fajl::peek(bool provjeravaj)
{
    if (eof()) Besmisleni();
    if (!provjeravaj) return fstream::peek();
    int x(fstream::peek());
    ProvjeriTok(false);
    return x;
}

inline void _Besmisleni() { throw std::logic_error("Datoteka sadrzi besmislene podatke"); }

void Skladiste::UcitajIzDatoteke(const std::string &ime)
{
    Fajl f(ime, std::ios::in);
    if (!f) throw std::logic_error("Trazena datoteka ne postoji");
    std::vector<PSpremnik> stari(std::move(spremnici));
    spremnici.clear();
    f.peek();
    if (f.eof()) return;
    while (f.good()) try
    {
        double tezina;
        switch (f.get())
        {
            case 'S':
            {
                std::string ime; int n;
                f >> Znak(' ') >> ime >> tezina >> Znak(' ') >> n;
                std::vector<double> v(n);
                for (int i(0); i < n; ++i)
                {
                    if (f.eof()) _Besmisleni();
                    f >> Znak(' ') >> v[i];
                }
                DodajSanduk(tezina, ime, v);
                break;
            }
            case 'V':
            {
                std::string ime; double ts;
                f >> Znak(' ') >> ime >> tezina >> Znak(' ') >> ts;
                DodajVrecu(tezina, ime, ts);
                break;
            }
            case 'B':
            {
                std::string ime; double g, z;
                f >> Znak(' ') >> ime >> tezina >> Znak(' ') >> g >> Znak(' ') >> z;
                DodajBure(tezina, ime, g, z);
                break;
            }
            default: _Besmisleni(); 
        }
        if (!f.eof()) f >> Znak('\n');
    }
    catch (...) { spremnici = std::move(stari); throw; }
}

class PolimorfniSpremnik : public Spremnik
{
    Spremnik *p;
    void Provjeri() const { if (!p) throw std::logic_error("Nespecificiran spremnik"); }
public:
    PolimorfniSpremnik() : Spremnik(0, std::string()), p(nullptr) {}
    ~PolimorfniSpremnik() { delete p; }
    PolimorfniSpremnik(const Spremnik &s) : Spremnik(0, std::string()), p(s.DajKopiju()) { }
    PolimorfniSpremnik(const PolimorfniSpremnik &ps) : Spremnik(0, std::string()), p(ps.DajKopiju()) { }
    PolimorfniSpremnik(PolimorfniSpremnik &&ps) : Spremnik(0, std::string()) { std::swap(p, ps.p); }
    PolimorfniSpremnik &operator =(PolimorfniSpremnik ps) { std::swap(p, ps.p); return *this; }
    PolimorfniSpremnik &operator =(const Spremnik &s);
    double DajTezinu() const { Provjeri(); return p->DajTezinu(); }
    double DajUkupnuTezinu() const { Provjeri(); return p->DajUkupnuTezinu(); }
    void Ispisi() const { Provjeri(); p->Ispisi(); }
    Spremnik *DajKopiju() const { Provjeri(); return p->DajKopiju(); }
};
PolimorfniSpremnik &PolimorfniSpremnik::operator =(const Spremnik &s)
{
    Spremnik *n(s.DajKopiju());
    delete p; p = n;
    return *this;
}

int main()
{
    try
    {
    	PolimorfniSpremnik ps1(Vreca(0.2, "Praskaste cincozne", 0.2)),
	        ps2(Bure(10, "Transformatorsko ulje", 900, 20)), ps3;
	    ps3 = Sanduk(1, "Rafinirana kalamuta", {1, 2, 0.5});
	    Skladiste s;
	    s.DodajSpremnik(&ps1, false);
	    std::cout << "Vlastita tezina vrece: " << ps1.DajTezinu();
	    s.DodajSpremnik(&ps2, false);
	    std::cout << "\nUkupna tezina bureta: " << ps2.DajUkupnuTezinu() << '\n';
	    s.DodajSpremnik(&ps3, false);
	    ps3.Ispisi();
	    s.IzlistajSkladiste();
    }
    catch (const std::exception &e) { std::cout << "Izuzetak: " << e.what(); }
    catch (...) { std::cout << "Izuzetak"; }
	return 0;
}