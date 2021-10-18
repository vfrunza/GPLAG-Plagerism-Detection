/B2017/2018: Zadaća 4, Zadatak 4
#include <initializer_list>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <utility> //za pair i za move
#include <memory> //pametni pok
#include <string>
#include <vector>
#include <tuple>
using std::initializer_list;
using std::domain_error;
using std::min_element;
using std::logic_error;
using std::range_error;
using std::stable_sort;
using std::make_shared;
using std::shared_ptr;
using std::make_tuple;
using std::make_pair;
using std::count_if;
using std::for_each;
using std::getline;
using std::vector;
using std::string;
using std::right;
using std::tuple;
using std::find;
using std::swap;
using std::endl;
using std::pair;
using std::cout;
using std::setw;
using std::left;
using std::sort;
using std::get;
using std::cin;
using std::tie;
typedef tuple<int, int, int> Tapl;
typedef pair<int, int> Par;

class Datum{
    int dan, mjesec, godina; 
  public:
    Datum(int d, int m, int g) { Postavi(d, m, g); }
    void Postavi(int d, int m, int g);
    Tapl Ocitaj() const { return make_tuple(dan, mjesec, godina); }
    void Ispisi() const { 
        cout << dan << "/" << mjesec << "/" << godina; 
    }
};
void Datum::Postavi(int d, int m, int g){
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((g % 4 == 0 && g % 100 != 0) || g % 400 == 0) broj_dana[1]++; //**
    if(g < 1 || d < 1 || m < 1 || m > 12 || d > broj_dana[m-1]) throw domain_error("Neispravan datum");
    dan = d;
    mjesec = m;
    godina = g;
}
class Vrijeme{
    int sati, minute;
  public:
    Vrijeme(int h, int m) { Postavi(h, m); }
    void Postavi(int h, int m);
    Par Ocitaj() const { return make_pair(sati, minute); }
    void Ispisi() const { 
        if(sati < 10) cout << 0; 
        cout << sati << ":";
        if(minute < 10) cout << 0; 
        cout << minute;
    }
};
void Vrijeme::Postavi(int h, int m){
    if(h < 0 || h > 23 || m < 0 || m > 59) throw domain_error("Neispravno vrijeme");
    sati = h;
    minute = m;
}
class Pregled{
    string ime;
    Datum datum;
    Vrijeme vrijeme;
  public:
    Pregled(const string &ime_p, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) : ime(ime_p), datum(datum_pregleda), vrijeme(vrijeme_pregleda) {}
    Pregled(const string &ime_p, int dan_p, int mjesec_p, int godina_p, int sati_p, int minute_p) : ime(ime_p), datum(dan_p, mjesec_p, godina_p), vrijeme(sati_p, minute_p) {}
    void PromijeniPacijenta(const string &ime_pacijenta) { ime = ime_pacijenta; }
    void PromijeniDatum(const Datum &novi_datum) { datum = novi_datum; }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme) { vrijeme = novo_vrijeme; }
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    string DajImePacijenta() const { return ime; }
    Datum DajDatumPregleda() const { return datum; }
    Vrijeme DajVrijemePregleda() const { return vrijeme; }
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
    void Ispisi() const {
        cout << setw(30) << left << ime;
        datum.Ispisi();
        cout << " ";
        vrijeme.Ispisi();
        cout << endl;
    }
};
void Pregled::PomjeriDanUnaprijed() {
    Tapl d(datum.Ocitaj());
    int dan(get<0>(d)), mjesec(get<1>(d)), godina(get<2>(d));
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0) broj_dana[1]++; //**
    dan++;
    if(dan > broj_dana[mjesec-1]) dan = 1, mjesec++;
    if(mjesec > 12) mjesec = 1, godina++;
    if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0) dan++; //godina prestupna
    datum = Datum(dan, mjesec, godina);
}
void Pregled::PomjeriDanUnazad(){
    Tapl d(datum.Ocitaj());
    int dan(get<0>(d)), mjesec(get<1>(d)), godina(get<2>(d));
    dan--;
    if(dan == 0) mjesec--;
    if(mjesec == 0) mjesec = 12, godina--;
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(dan == 0) dan = broj_dana[mjesec-1]; // [mjesec-1] a ne [mjesec]
    if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0) dan++; //godina prestupna
    datum = Datum(dan, mjesec, godina);
}
bool Pregled::DolaziPrije(const Pregled &p1, const Pregled &p2){
    int d, m, g, dd, mm, gg;
    Tapl datum1(p1.datum.Ocitaj()), datum2(p2.datum.Ocitaj());
    tie(d, m, g) = datum1;
    tie(dd, mm, gg) = datum2;
    if(g < gg) return true;
    else if(g > gg) return false;
    if(m < mm) return true;
    else if(m > mm) return false;
    if(d < dd) return true;
    else if(d > dd) return false;
    Par vr1(p1.vrijeme.Ocitaj()), vr2(p2.vrijeme.Ocitaj());
    int h, min, hh, mmin;
    tie(h, min) = vr1;
    tie(hh, mmin) = vr2;
    if(h < hh) return true;
    else if(h > hh) return false;
    if(min < mmin) return true;
    return false;
}

class Pregledi{
    vector<shared_ptr<Pregled>> p;
  public:
    Pregledi() {} 
    explicit Pregledi(initializer_list<Pregled> spisak_pregleda);
    ~Pregledi();
    Pregledi(const Pregledi &pregledi);
    Pregledi(Pregledi &&pregledi) : p(move(pregledi.p)) {}
    Pregledi& operator =(const Pregledi &pregledi);
    Pregledi& operator =(Pregledi &&pregledi);
    void RegistrirajPregled(const string &ime_p, const Datum &datum_p, const Vrijeme &vrijeme_p);
    void RegistrirajPregled(const string &ime_p, int dan_p, int mjesec_p, int godina_p, int sati_p, int minute_p);
    void RegistrirajPregled(shared_ptr<Pregled>  pregled) { p[p.size()] = pregled; }
    int DajBrojPregleda() const  { return p.size();}
    int DajBrojPregledaNaDatum(const Datum &datum) const;
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta(const string &ime_p);
    void IspisiPregledeNaDatum(const Datum &datum)  ;
    void IspisiSvePreglede() const ;
};
Pregledi::Pregledi(initializer_list<Pregled> spisak_pregleda) : p(vector<shared_ptr<Pregled>> (spisak_pregleda.size(), nullptr)) {
    for(int i=0; i<p.size(); i++){
        try{
            p[i] = make_shared<Pregled>(*(spisak_pregleda.begin() + i));
        }
        catch(...){
            for(int j=0; j<i; j++) p[i] = nullptr;
            p.resize(0);
            throw;
        }
    }
}
Pregledi::~Pregledi() {
    for(int i=0; i<p.size(); i++) p[i] = nullptr;
    p.resize(0);
}
Pregledi::Pregledi(const Pregledi &pregledi) : p(vector<shared_ptr<Pregled>> (pregledi.p.size(), nullptr)) {
    try{
        for(int i=0; i<p.size(); i++) p[i] = make_shared<Pregled>(*pregledi.p[i]);
    }
    catch(...){
        for(int i=0; i<p.size(); i++) p[i] = nullptr;
        p.resize(0);
        throw;
    }
}
Pregledi& Pregledi::operator =(const Pregledi &pregledi) {
    vector<shared_ptr<Pregled>> vec(pregledi.p.size(), nullptr);
    try{
        for(int i=0; i<vec.size(); i++) vec[i] = make_shared<Pregled> (*(pregledi.p[i]));
    }
    catch(...){
        for(int i=0; i<vec.size(); i++) vec[i] = nullptr;
        vec.resize(0);
        throw;
    }
    p = move(vec);
    return *this;

}
Pregledi& Pregledi::operator =(Pregledi &&pregledi) {
    p = move(pregledi.p);
    return *this;
}
void Pregledi::RegistrirajPregled(const string &ime_p, const Datum &datum_p, const Vrijeme &vrijeme_p){
    try{
        p.emplace_back(make_shared<Pregled>(ime_p, datum_p, vrijeme_p));
    }
    catch(...){
        throw;
    }
}
void Pregledi::RegistrirajPregled(const string &ime_p, int dan_p, int mjesec_p, int godina_p, int sati_p, int minute_p){
    try{
        p.emplace_back(make_shared<Pregled>(ime_p, Datum(dan_p, mjesec_p, godina_p), Vrijeme(sati_p, minute_p)));
    }
    catch(...){
        throw;
    }
}
int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const {
    Tapl dat(datum.Ocitaj());
    int br(count_if(p.begin(), p.end(), [&dat](shared_ptr<Pregled>  pregled){
        Tapl dat2((pregled->DajDatumPregleda()).Ocitaj());
        return dat == dat2;
    }));
    return br;
}
Pregled& Pregledi::DajNajranijiPregled() {
    auto pok(min_element(p.begin(), p.end(), [](shared_ptr<Pregled> p1, shared_ptr<Pregled> p2){
        return Pregled::DolaziPrije(*p1, *p2);
    })); // **
    if(pok == p.end()) throw domain_error("Nema registriranih pregleda");
    return **pok;
}
Pregled Pregledi::DajNajranijiPregled() const {
    auto pok(min_element(p.begin(), p.end(), [](shared_ptr<Pregled> p1, shared_ptr<Pregled> p2){
        return Pregled::DolaziPrije(*p1, *p2);
    }));
    if(pok == p.end()) throw domain_error("Nema registriranih pregleda");
    return **pok;
}
void Pregledi::IsprazniKolekciju() {
    // **
    for(int i=0; i<p.size(); i++) p[i] = nullptr;
    p.resize(0);
}
void Pregledi::ObrisiNajranijiPregled() {
    auto najraniji(min_element(p.begin(), p.end(), [](shared_ptr<Pregled> p1, shared_ptr<Pregled> p2){
        return Pregled::DolaziPrije(*p1, *p2);
    }));
    if(najraniji == p.end()) throw range_error("Prazna kolekcija");
    p.erase(najraniji);
}
void Pregledi::ObrisiPregledePacijenta(const string &ime_p) {
    for(int i=0; i<p.size(); i++){
        if(p[i]->DajImePacijenta() == ime_p){ 
            p[i] = nullptr; // **
            p.erase(p.begin()+i);
        }
    }
}
void Pregledi::IspisiPregledeNaDatum(const Datum &dat)  {
    sort(p.begin(), p.end(), [](shared_ptr<const Pregled> p1, shared_ptr<const Pregled> p2){
        return Pregled::DolaziPrije(*p1, *p2);
    });
    Tapl d1(dat.Ocitaj());
    for_each(p.begin(), p.end(), [&d1](shared_ptr<const Pregled> pp){
        Tapl d2((pp->DajDatumPregleda()).Ocitaj());
        if(d1 == d2) pp->Ispisi();
    });
}
/*void Pregledi::IspisiSvePreglede()  {
    sort(p.begin(), p.end(), [](shared_ptr<const Pregled> p1, shared_ptr<const Pregled> p2){
        return Pregled::DolaziPrije(*p1, *p2);
    });
    for_each(p.begin(), p.end(), [](shared_ptr<const Pregled> p1){
        p1->Ispisi();
    });
}

*/

void Pregledi::IspisiSvePreglede() const {
    auto najmanji(min_element(p.begin(), p.end(), [](shared_ptr<const Pregled> p1, shared_ptr<const Pregled> p2){
        return Pregled::DolaziPrije(*p1, *p2);
    }));
    if(najmanji != p.end()) (*najmanji)->Ispisi();
    else return;
    
    typedef decltype (najmanji) Tip;
    auto it(p.begin());
    int i = 0;
    for(; it != p.end(), i != p.size(); it++, i++){
        it = p.begin();
        Tip najmanji2(it);
       
        for(auto it2(p.begin()); it2 != p.end(); it2++){
            if(Pregled::DolaziPrije(**it2, **najmanji2) && it2 != najmanji && !Pregled::DolaziPrije(**it2, **najmanji)){
                najmanji2 = it2;
            }
        }
                
        (*najmanji2)->Ispisi();
        najmanji = najmanji2;
        
    }
    
    
} 
void Devranisi(){
    cin.clear();
    cin.ignore(10000, '\n');
}
void UnesiDatum(int &d, int &m, int &g, bool pregleda = false){
    cout << "Unesite dan mjesec i godinu ";
    if(pregleda) cout << "pregleda";
    cout << ": ";
    cin >> d >> m >> g;
}
void IspisiDatum(Tapl t){
    int d, m, g;
    tie(d, m, g) = t;
    cout << d << " " << m << " " << g;
}

int main (){
    Pregledi p;
    while(1){
        cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        string ime_pacijenta;
        getline(cin, ime_pacijenta);
        if(ime_pacijenta == "kraj") break;
        int d, m, g, h, min;
        UnesiDatum(d, m, g, true);
        cout << "Unesite sate i minute pregleda: ";
        cin >> h >> min;
        try{
            p.RegistrirajPregled(ime_pacijenta, d, m, g, h, min);
        }
        catch(...){
            cout << "belaj";
        }
        Devranisi();
    }
    cout << "Trenutno su registrovani sljedeci pregledi\n";
    p.IspisiSvePreglede();
    
    int opcija(0);
    do{
        cout << "Odaberite jednu od sljedecih opcija\n";
        cout << "1 - Broj pregleda na datum\n2 - Najraniji pregled\n";
        cout << "3 - Obrisi pregled pacijenta\n4 - Obrisi najraniji pregled\n";
        cout << "5 - Ispisi sve pregleda na datum\n6 - Ispisi sve preglede\n";
        cout << "7 - Kraj programa\n";
        cin >> opcija;
        Devranisi();
        if(opcija == 1) {
            int d, m, g;
            UnesiDatum(d, m, g);
            Datum dat(d, m, g);
            cout << "Broj pregleda na datum "; IspisiDatum(dat.Ocitaj()); cout << " je: ";
            cout << p.DajBrojPregledaNaDatum(dat) << endl;
        }
        else if(opcija == 2){
            cout << "Najraniji pregled je:\n";
            p.DajNajranijiPregled().Ispisi();
        }
        else if(opcija == 3){
            cout << "Unesite ime pacijenta: ";
            string ime("");
            getline(cin, ime);
            int prije(p.DajBrojPregleda());
            p.ObrisiPregledePacijenta(ime);
            if(prije != p.DajBrojPregleda()) cout << "Uspjesno obrisano " << prije - p.DajBrojPregleda() << " pregleda\n";
        }
        else if(opcija == 4){
            int prije(p.DajBrojPregleda());
            p.ObrisiNajranijiPregled();
            if(prije == p.DajBrojPregleda() + 1) cout << "Najraniji pregled uspjesno obrisan\n";
        }
        else if(opcija == 5){
            int d, m, g;
            UnesiDatum(d, m, g); //**dodati try & catch
            Datum dat(d, m, g);
            cout << "Pregledi na datum "; IspisiDatum(dat.Ocitaj()); cout << " su:\n";
            p.IspisiPregledeNaDatum(dat);
        }
        else if(opcija == 6){
            p.IspisiSvePreglede();
        }
        else if(opcija == 7) break;
        else return 0;
        cout << endl;
    }while(1);
    
    
	return 0;
} 
