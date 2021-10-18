/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <tuple>
#include <utility>
#include <algorithm>
#include <stdexcept>
#include <iomanip>
#include <string>
#include <cmath>
#include <initializer_list>
#include <vector>


class Datum {
    int d, m, g;
    static int BrojDana (int mjesec, int godina) {
        int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (godina%4==0 && (godina%100!=0 || godina%400==0)) broj_dana[1]++;
        return broj_dana[mjesec-1];
    }
  public:
    Datum(int dan, int mjesec, int godina) { Postavi(dan, mjesec, godina); }
    void Postavi(int dan, int mjesec, int godina) {
        if (godina<1 || mjesec<1 || mjesec>12) throw std::domain_error("Neispravan datum");
        if (dan<1 || dan>BrojDana(mjesec, godina)) throw std::domain_error("Neispravan datum");
        d=dan; m=mjesec; g=godina;
    }
    std::tuple<int, int, int> Ocitaj() const { return std::make_tuple(d, m, g); }
    void Ispisi() const { std::cout << d << "/"  << m << "/" << g; }
};

class Vrijeme {
    int h, min;
  public:
    Vrijeme(int sati, int minute) { Postavi(sati, minute); }
    void Postavi(int sati, int minute) {
        if (sati<0 || sati>23 || minute<0 || minute>59) throw std::domain_error("Neispravno vrijeme");
        h=sati; min=minute;
    }
    std::pair<int, int> Ocitaj () const { return std::make_pair(h, min); }
    void Ispisi() const { std::cout << std::setfill('0') << std::setw(2) << h << ":" << std::setw(2) << min << std::setfill(' '); }
};

class Pregled {
    std::string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;
    static int BrojDana (int mjesec, int godina) {
        int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (godina%4==0 && (godina%100!=0 || godina%400==0)) broj_dana[1]++;
        return broj_dana[mjesec-1];
    }
  public:
    Pregled(const std::string &ime, const Datum &datum, const Vrijeme &vrijeme) : ime_pacijenta(ime), datum_pregleda(datum), vrijeme_pregleda(vrijeme) { }
        
    Pregled (const std::string &ime, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) : 
        ime_pacijenta(ime), datum_pregleda(dan_pregleda, mjesec_pregleda, godina_pregleda), vrijeme_pregleda(sati_pregleda, minute_pregleda) { }
    
    
    void PromijeniPacijenta(const std::string &ime_pacijenta) { Pregled::ime_pacijenta=ime_pacijenta; }
    void PromijeniDatum(const Datum &novi_datum) { datum_pregleda=novi_datum; }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme) { vrijeme_pregleda=novo_vrijeme; }
    
    void PomjeriDanUnaprijed() {
        std::tuple<int, int, int> dat(datum_pregleda.Ocitaj());
        int d(std::get<0>(dat)), mj(std::get<1>(dat)), god(std::get<2>(dat));
        d++;
        if (d>BrojDana(mj, god)) { d=1; mj++; }
        if (mj>12) { mj=1; god++; }
        datum_pregleda=Datum(d, mj, god);
    }
    
    void PomjeriDanUnazad() {
        std::tuple<int, int, int> dat(datum_pregleda.Ocitaj());
        int d(std::get<0>(dat)), mj(std::get<1>(dat)), god(std::get<2>(dat));
        d--;
        if (d<1) { mj--; if (mj>0) d=BrojDana(mj, god); }
        if (mj<1) { mj=12; god--; if (god<1) throw std::domain_error("Neispravan datum"); d=31; }
        
        datum_pregleda=Datum(d, mj, god);
    }
    
    std::string DajImePacijenta() const { return ime_pacijenta; }
    Datum DajDatumPregleda() const { return datum_pregleda; }
    Vrijeme DajVrijemePregleda() const { return vrijeme_pregleda; }
    
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2) {
        std::tuple<int, int, int> dat1(p1.datum_pregleda.Ocitaj());
        std::tuple<int, int, int> dat2(p2.datum_pregleda.Ocitaj());
        std::pair<int, int> vr1(p1.vrijeme_pregleda.Ocitaj());
        std::pair<int, int> vr2(p2.vrijeme_pregleda.Ocitaj());
        int dan1(std::get<0>(dat1)), dan2(std::get<0>(dat2)), mj1(std::get<1>(dat1)), mj2(std::get<1>(dat2)), god1(std::get<2>(dat1)), god2(std::get<2>(dat2));
        int h1(vr1.first), h2(vr2.first), min1(vr1.second), min2(vr2.second);
        
        return ((god1<god2) || (god1==god2 && mj1<mj2) || (god1==god2 && mj1==mj2 && dan1<dan2) || (god1==god2 && mj1==mj2 && dan1==dan2 && h1<h2) || (god1==god2 && mj1==mj2 && dan1==dan2 && h1==h2 && min1<min2));
    }
    
    void Ispisi() const { std::cout << std::setw(30) << std::setfill(' ') << std::left << DajImePacijenta() << std::right; datum_pregleda.Ispisi(); std::cout << " "; vrijeme_pregleda.Ispisi(); std::cout << std::endl; }
};







class Pregledi {
    Pregled** p;
    int max_broj_pregleda;
    int broj_pregleda;
    
    static bool JednakiDatumi (const Datum &d1, const Datum &d2) {
        std::tuple<int, int, int> dat1(d1.Ocitaj());
        std::tuple<int, int, int> dat2(d2.Ocitaj());
        int dan1(std::get<0>(dat1)), dan2(std::get<0>(dat2)), mj1(std::get<1>(dat1)), mj2(std::get<1>(dat2)), god1(std::get<2>(dat1)), god2(std::get<2>(dat2));
        return (dan1==dan2 && mj1==mj2 && god1==god2);
    }
    
  public:
    explicit Pregledi (int max) : max_broj_pregleda(max), broj_pregleda(0) {
        p=new Pregled*[max_broj_pregleda]{};
        
    }
    Pregledi(std::initializer_list<Pregled> spisak_pregleda) : max_broj_pregleda(spisak_pregleda.size()), broj_pregleda(spisak_pregleda.size()) {
        p=new Pregled*[max_broj_pregleda]{};
        auto it(spisak_pregleda.begin());
        try {
            for (int i=0; i<max_broj_pregleda; i++) p[i]=new Pregled(*it++);
        }
        catch(...) {
            for (int i=0; i<max_broj_pregleda; i++) if (p[i]!=nullptr) delete p[i];
            delete[] p;
            throw;
        }
    }
    
    
    
    ~Pregledi() {
        if (p!=nullptr) for (int i=0; i<broj_pregleda; i++) if (p[i]!=nullptr) { delete p[i]; p[i]=nullptr; }
        delete[] p; p=nullptr;
    }
    Pregledi(const Pregledi &pregledi) : max_broj_pregleda(pregledi.max_broj_pregleda), broj_pregleda(pregledi.broj_pregleda) {
        
        p=new Pregled*[max_broj_pregleda]{};
        try {
            for (int i=0; i<broj_pregleda; i++) p[i]=new Pregled(*(pregledi.p[i]));
        }
        catch(...) {
            if (p!=nullptr) for (int i=0; i<broj_pregleda; i++) delete p[i];
            delete[] p; p=nullptr;
            throw;
        }
    }
    Pregledi(Pregledi &&pregledi) : max_broj_pregleda(pregledi.max_broj_pregleda), broj_pregleda(pregledi.broj_pregleda) {
        p=pregledi.p;
        pregledi.p=nullptr;
    }
    
    
    
    
    Pregledi &operator =(const Pregledi &pregledi) { 
        if (&pregledi!=this) {
            
            if(max_broj_pregleda!=pregledi.max_broj_pregleda) {
                if (p!=nullptr) for (int i=0; i<broj_pregleda; i++) delete p[i];
                delete[] p; p=nullptr;
                
                max_broj_pregleda=pregledi.max_broj_pregleda; broj_pregleda=pregledi.broj_pregleda;
                p=new Pregled*[max_broj_pregleda]{};
                try {
                    for (int i=0; i<broj_pregleda; i++) p[i]=new Pregled(*(pregledi.p[i]));
                }
                catch(...) {
                    for (int i=0; i<broj_pregleda; i++) delete p[i];
                    delete[] p; p=nullptr;
                    throw;
                }
            } 
            else {
                if (broj_pregleda<pregledi.broj_pregleda) {
                    try {
                        for (int i=broj_pregleda; i<pregledi.broj_pregleda; i++) p[i]=new Pregled(*(pregledi.p[i]));
                    }
                    catch(...) {
                        for (int i=broj_pregleda; i<pregledi.broj_pregleda; i++) delete p[i];
                        throw;
                    }
                }
                else if (broj_pregleda>pregledi.broj_pregleda) {
                    for (int i=broj_pregleda; i>pregledi.broj_pregleda; i--) { delete p[i]; p[i]=nullptr; }
                }
                broj_pregleda=pregledi.broj_pregleda;
                for (int i=0; i<broj_pregleda; i++) *(p[i])=*(pregledi.p[i]);
            }
        }
        return *this;
    }
    
    
    Pregledi &operator =(Pregledi &&pregledi) { 
        if (&pregledi!=this) {
            std::swap(max_broj_pregleda, pregledi.max_broj_pregleda);
            std::swap(broj_pregleda, pregledi.broj_pregleda);
            std::swap(p, pregledi.p);
        }
        return *this;
    }
    
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) {
        if (broj_pregleda==max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
        try {
            p[broj_pregleda]=new Pregled(ime_pacijenta, datum_pregleda, vrijeme_pregleda);
        }
        catch(...) {
            delete p[broj_pregleda];
            throw;
        }
        broj_pregleda++;
    }
    
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) {
        if (broj_pregleda==max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
        try {
            p[broj_pregleda]=new Pregled(ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda);
        }
        catch(...) {
            delete p[broj_pregleda];
            throw;
        }
        broj_pregleda++;
    }
    
    void RegistrirajPregled(Pregled *pregled) {
        if (broj_pregleda==max_broj_pregleda) { delete pregled; pregled=nullptr; throw std::range_error("Dostignut maksimalni broj pregleda"); } // Treba li se obrisati ovaj parametar
        try {
            p[broj_pregleda]=new Pregled(*pregled);
        }
        catch(...) {
            delete p[broj_pregleda];
            throw;
        }
        broj_pregleda++;
    }
    int DajBrojPregleda() const { return broj_pregleda; }
    
    int DajBrojPregledaNaDatum(const Datum &datum) const {
        return std::count_if(p, p+broj_pregleda, [datum](Pregled* p1) { return JednakiDatumi((*p1).DajDatumPregleda(), datum); } );
    }
    
    Pregled &DajNajranijiPregled() {
        if (broj_pregleda==0) throw std::domain_error("Nema registriranih pregleda");
        return **(std::min_element(p, p+broj_pregleda, [](Pregled* p1, Pregled* p2) { return Pregled::DolaziPrije(*p1, *p2); } ));
    }
    
    Pregled DajNajranijiPregled() const {
        if (broj_pregleda==0) throw std::domain_error("Nema registriranih pregleda");
        return **(std::min_element(p, p+broj_pregleda, [](Pregled* p1, Pregled* p2) { return Pregled::DolaziPrije(*p1, *p2); } ));
    }
    
    void IsprazniKolekciju() {
        if (p!=nullptr) for (int i=0; i<broj_pregleda; i++) if (p[i]!=nullptr) { delete p[i]; p[i]=nullptr; }
        broj_pregleda=0;
    }
    
    void ObrisiNajranijiPregled() {
        if (broj_pregleda==0) throw std::range_error("Prazna kolekcija");
        auto it(std::find_if(p, p+broj_pregleda, [this](Pregled* p1) { return p1==&DajNajranijiPregled(); }));
        broj_pregleda--;
        
        for (auto i=it; i!=p+broj_pregleda; i++) {
            **i=**(i+1);
        }
        delete p[broj_pregleda]; p[broj_pregleda]=nullptr;
    }
    
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta) {
        for (;;) {
            auto it(std::find_if(p, p+broj_pregleda, [ime_pacijenta](Pregled* p1) { return (*p1).DajImePacijenta()==ime_pacijenta; }));
            if (it==p+broj_pregleda) break;
            broj_pregleda--;
            for (auto i=it; i!=p+broj_pregleda; i++) {
                **i=**(i+1);
            }
            delete p[broj_pregleda]; p[broj_pregleda]=nullptr;
            
        }
    }
    
    void IspisiPregledeNaDatum(const Datum &datum) const {
        
        Pregled** pomocni;
        pomocni=new Pregled*[broj_pregleda]{};
        
        for (int i=0; i<broj_pregleda; i++) pomocni[i]=&*(p[i]);
        
        std::sort(pomocni, pomocni+broj_pregleda, [](Pregled* p1, Pregled* p2) { return Pregled::DolaziPrije(*p1, *p2); } );
        
        std::for_each(pomocni, pomocni+broj_pregleda, [datum] (Pregled* p1) { if (JednakiDatumi((*p1).DajDatumPregleda(), datum)) (*p1).Ispisi(); });
        
        for (int i=0; i<broj_pregleda; i++) pomocni[i]=nullptr;
        delete[] pomocni;
    }
    void IspisiSvePreglede() const {
        
        if (broj_pregleda==0) return;
        
        Pregled** pomocni;
        pomocni=new Pregled*[broj_pregleda]{};
        
        for (int i=0; i<broj_pregleda; i++) pomocni[i]=&*(p[i]);
        
        std::sort(pomocni, pomocni+broj_pregleda, [](Pregled* p1, Pregled* p2) { return Pregled::DolaziPrije(*p1, *p2); } );
        
        std::for_each(pomocni, pomocni+broj_pregleda, [] (Pregled* p1) { (*p1).Ispisi(); });
        
        for (int i=0; i<broj_pregleda; i++) pomocni[i]=nullptr;
        delete[] pomocni;
        
    }
};

int main ()
{
    /*try {
        int max, d, m, g, h, min, opcija;
        std::cout << "Unesite maksimalan broj pregleda: ";
        std::cin >> max;
        std::string ime;
        Pregledi pr(max);
        for (int i=0; i<max; i++) {
            std::cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
            std::cin.clear(); std::cin.ignore(10000, '\n');
            std::getline(std::cin, ime);
            if (ime=="kraj") break;
            std::cout << "Unesite dan mjesec i godinu pregleda: ";
            std::cin >> d >> m >> g;
            std::cout << "Unesite sate i minute pregleda: ";
            std::cin >> h >> min;
            try {
                pr.RegistrirajPregled(ime, d, m, g, h, min);
            }
            catch(std::exception &iz) {
                std::cout << iz.what();
                i--;
            }
        }
        std::cout << "Trenutno su registrovani sljedeci pregledi" << std::endl;
        pr.IspisiSvePreglede();
        
        const char* niz_opcija[7]{"Broj pregleda na datum", "Najraniji pregled", "Obrisi pregled pacijenta", "Obrisi najraniji pregled", "Ispisi sve pregleda na datum", "Ispisi sve preglede", "Kraj programa"};
        for (;;) {
            
            std::cout << "Odaberite jednu od sljedecih opcija" << std::endl;
            for (int i=0; i<7; i++) std::cout << i+1 << " - " << niz_opcija[i] << std::endl; 
            std::cin >> opcija;
            
            if (opcija==1) {
                int dan, mj, god;
                std::cout << "Unesite dan mjesec i godinu : ";
                std::cin >> dan >> mj >> god;
                std::cout << "Broj pregleda na datum " << dan << " " << mj << " " << god << " je: " << pr.DajBrojPregledaNaDatum({dan, mj, god}) << std::endl; 
            }
            else if (opcija==2) {
                try {
                    Pregled pregl(pr.DajNajranijiPregled());
                    std::cout << "Najraniji pregled je: " << std::endl;
                    pregl.Ispisi();
                }
                catch(std::domain_error &iz) {
                    std::cout << iz.what() << std::endl;
                }
            }
            else if (opcija==3) {
                std::cin.clear(); std::cin.ignore(10000, '\n');
                std::cout << "Unesite ime pacijenta: ";
                std::getline(std::cin, ime);
                int trenutno(pr.DajBrojPregleda());
                pr.ObrisiPregledePacijenta(ime);
                std::cout << "Uspjesno obrisano " << trenutno-pr.DajBrojPregleda() << " pregleda" << std::endl;
            }
            else if (opcija==4) {
                try {
                    pr.ObrisiNajranijiPregled();
                    std::cout << "Najraniji pregled uspjesno obrisan" << std::endl;
                }
                catch(std::range_error &iz) {
                    std::cout << iz.what() << std::endl;
                } 
            }
            else if (opcija==5) {
                int dan, mj, god;
                std::cout << "Unesite dan mjesec i godinu : ";
                std::cin >> dan >> mj >> god;
                std::cout << "Pregledi na datum " << dan << " " << mj << " " << god << " su:" << std::endl;
                pr.IspisiPregledeNaDatum({dan, mj, god});
            }
            else if (opcija==6) {
                pr.IspisiSvePreglede();
            }
            else break;
        }
    }
    catch(...) {
        std::cout << "Problemi sa memorijom";
    }*/
    
    Pregledi p(20);
        int d(1);
        for(int i = 0; i < 20; i++,d++){
            p.RegistrirajPregled(new Pregled("Dalila", {d,d%12+1,2000+d}, {1,1}));
        }
        p.IspisiSvePreglede();
    
    
	return 0;
}
