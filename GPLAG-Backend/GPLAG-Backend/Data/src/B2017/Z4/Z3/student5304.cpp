#include <iostream>
#include <stdexcept>
#include <tuple>
#include <utility>
#include <iomanip>
#include <vector>
#include <memory>
#include <algorithm>
#include <string>
#include <cstring>

bool Prestupna(int godina){
    if(godina % 100 != 0 && godina % 400 == 0 && godina % 4 == 0) return true;
    return false;
}
class Datum{
    int dan, mjesec, godina;
    public:
    Datum(int dan, int mjesec, int godina){
       // if(dan > 31 || mjesec > 12 || mjesec < 1 || dan < 1) throw std::domain_error("Neispravan datum");
        Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina;
    }
    void Postavi(int dan, int mjesec, int godina){
        //if(dan > 31 || mjesec > 12 || mjesec < 1 || dan < 1) throw std::domain_error("Neispravan datum");
        Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina;
    }
    std::tuple<int, int, int> Ocitaj() const{
        std::tuple<int, int, int> t;
        std::get<0>(t) = dan;
        std::get<1>(t) = mjesec;
        std::get<2>(t) = godina;
        return t;
    }
    void Ispisi() const{
        std::cout<<std::right<<std::setfill('0')<<std::setw(2)<<Datum::dan<<"/"<<Datum::mjesec<<"/"<<Datum::godina;
    }
    int DajDan() const { return dan;}
    int DajMjesec() const { return mjesec;}
    int DajGodinu() const {return godina;}
    friend class Pregled;
    friend class Pregledi;
};

class Vrijeme{
    int sat, minuta;
    public:
    Vrijeme(int sat, int minuta){
        //if(sat > 23 || sat < 1 || minuta > 59 || minuta < 1) throw std::domain_error("Neispravno vrijeme");
        Vrijeme::sat = sat; Vrijeme::minuta = minuta;
    }
    void Postavi(int sat, int minuta){
        //if(sat > 23 || sat < 1 || minuta > 59 || minuta < 1) throw std::domain_error("Neispravno vrijeme");
        Vrijeme::sat = sat; Vrijeme::minuta = minuta;
    }
    std::pair<int, int> Ocitaj() const{
        std::pair<int, int> t;
        t.first = sat;
        t.second = minuta;
        return t;
    }
    void Ispisi() const{
        std::cout<<std::right<<std::setfill('0')<<std::setw(2)<<Vrijeme::sat<<":"<<Vrijeme::minuta;
    }
    int DajMinute() const {return minuta;}
    int DajSate() const {return sat;}
    friend class Pregled;
    friend class Pregledi;
};
class Pregled{
    std::string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;
    public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda,  const Vrijeme &vrijeme_pregleda) : datum_pregleda(datum_pregleda), vrijeme_pregleda(vrijeme_pregleda){
        Pregled::ime_pacijenta = ime_pacijenta;
    }
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,  int godina_pregleda, int sati_pregleda, int minute_pregleda) : 
    datum_pregleda(dan_pregleda, mjesec_pregleda, godina_pregleda), vrijeme_pregleda(sati_pregleda, minute_pregleda){
        Pregled::ime_pacijenta = ime_pacijenta;
    }
     void PromijeniPacijenta(const std::string &ime_pacijenta){
         Pregled::ime_pacijenta = ime_pacijenta;
     } 
    void PromijeniDatum(const Datum &novi_datum){
         auto d(novi_datum.Datum::Ocitaj());
         Pregled::datum_pregleda.Datum::Postavi(std::get<0>(d), std::get<1>(d), std::get<2>(d));
    }  
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme){
        auto vr(novo_vrijeme.Vrijeme::Ocitaj());
        Pregled::vrijeme_pregleda.Vrijeme::Postavi(vr.first, vr.second);
    } 
    void PomjeriDanUnaprijed(){
        auto d(Pregled::datum_pregleda.Datum::Ocitaj());
        std::get<0>(d)++;
        std::vector<std::vector<int>> br_dana{{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                                              {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
        if(Prestupna(std::get<2>(d))){
            if(std::get<0>(d) > br_dana[1][std::get<1>(d)]){ std::get<1>(d)++; std::get<0>(d) = 1;}
        }
        else if(!Prestupna(std::get<2>(d))){
            if(std::get<0>(d) > br_dana[0][std::get<1>(d)]){ std::get<1>(d)++; std::get<0>(d) = 1;}
        }
        if(std::get<1>(d) > 12){std::get<1>(d) = 1; std::get<2>(d)++;}
        Pregled::datum_pregleda.Datum::Postavi(std::get<0>(d), std::get<1>(d), std::get<2>(d));
    } 
     void PomjeriDanUnazad(){
        auto d(Pregled::datum_pregleda.Datum::Ocitaj());
        std::get<0>(d)--;
        std::vector<std::vector<int>> br_dana{{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                                              {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
        if(Prestupna(std::get<2>(d))){
            if(std::get<0>(d) < 1){ std::get<1>(d)--; std::get<0>(d) = br_dana[1][std::get<1>(d)];}
        }
        else if(!Prestupna(std::get<2>(d))){
            if(std::get<0>(d) < 1){ std::get<1>(d)--; std::get<0>(d) = br_dana[0][std::get<1>(d)];}
        }
        if(std::get<1>(d) < 1){std::get<1>(d) = 12; std::get<2>(d)--;}
        Pregled::datum_pregleda.Datum::Postavi(std::get<0>(d), std::get<1>(d), std::get<2>(d));
     }
     std::string DajImePacijenta() const{return ime_pacijenta;}  
    Datum DajDatumPregleda() const{return datum_pregleda;}  
    Vrijeme DajVrijemePregleda() const{return vrijeme_pregleda;}  
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2){
        auto t1(p1.datum_pregleda.Datum::Ocitaj());
        auto t2(p2.datum_pregleda.Datum::Ocitaj());
        if(std::get<2>(t2) > std::get<2>(t1)) return true;
        if(std::get<1>(t2) > std::get<1>(t1)) return true;
        if(std::get<0>(t2) > std::get<0>(t1)) return true;
        auto v1(p1.vrijeme_pregleda.Vrijeme::Ocitaj());
        auto v2(p2.vrijeme_pregleda.Vrijeme::Ocitaj());
        if(std::get<0>(v2) > std::get<0>(v1)) return true;
        if(std::get<1>(v2) > std::get<1>(v1)) return true;
        else return false;
    }  
    void Ispisi() const{
        std::cout<<std::left<<std::setw(30)<<ime_pacijenta;
        std::cout<<" ";
        datum_pregleda.Datum::Ispisi();
        std::cout<<" ";
        vrijeme_pregleda.Vrijeme::Ispisi();    
        
    }
    friend class Pregledi;
};

class Pregledi{
    int br_p;
    const int max_br_p;
    Pregled **pregled{};
    Pregledi() = default;
    
    void AlocirajNiz(int br){
        pregled = nullptr;
        try{
            pregled = new Pregled*[br];
        }
        catch(std::bad_alloc){
            IsprazniKolekciju();
            throw;
        }
    }
    public:
    explicit Pregledi(int m) : br_p(0), max_br_p(m), pregled(nullptr){
        AlocirajNiz(max_br_p);
    }
    Pregledi(std::initializer_list<Pregled> spisak) : br_p(spisak.size()), max_br_p(spisak.size()), pregled(nullptr){
       
        try{
            pregled = new Pregled*[br_p];
            for(int i = 0; i < br_p; i++){
                pregled[i] = nullptr;
            }
            int br = 0;
            for(auto &x: spisak){
                pregled[br] = new Pregled(x);
                br++;
            }
        }catch(std::bad_alloc){
                IsprazniKolekciju();
                throw;
            }
    }
    ~Pregledi(){
        if(pregled == nullptr) return;
        for(int i = 0; i < br_p; i++){
            delete pregled[i];
        }
        delete[] pregled;
    }
    Pregledi(const Pregledi & pregledi) : br_p(pregledi.br_p), max_br_p(pregledi.max_br_p), pregled(nullptr){
        AlocirajNiz(max_br_p);
        try{
            for(int i = 0; i < br_p; i++){
                this->pregled[i] = new Pregled(*pregledi.pregled[i]);
            }
        }
        catch(std::bad_alloc){
            IsprazniKolekciju();
            throw;
        }
    }
    Pregledi(Pregledi &&pregledi) : br_p(pregledi.br_p), max_br_p(pregledi.max_br_p), pregled(nullptr){
      pregled = pregledi.pregled;
      pregledi.pregled = nullptr;
    }
    Pregledi &operator =(const Pregledi &pregledi){
        if(max_br_p != pregledi.max_br_p) throw std::logic_error("Nesaglasne liste pregleda");
        if(&pregledi == this) return *this;
        for(int i = 0; i < br_p; i++){
            delete pregled[i];
        }
        br_p = pregledi.br_p;
        try{
            for(int i = 0; i < br_p; i++){
                pregled[i] = new Pregled(*pregledi.pregled[i]);
            }
        }
        catch(std::bad_alloc){
            IsprazniKolekciju();
            throw;
        }
        return *this;
    }
    Pregledi &operator =(Pregledi &&pregledi){
        if(max_br_p != pregledi.max_br_p) throw std::logic_error("Nesaglasne liste pregleda");
        if(&pregledi == this) return *this;
        pregled = pregledi.pregled;
        br_p = pregledi.br_p;
        pregledi.pregled = nullptr;
        return *this;
    }
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda){
        if(br_p == max_br_p) throw std::range_error("Raspored popunjen");
        try{
            pregled[br_p++] = new Pregled(ime_pacijenta, datum_pregleda, vrijeme_pregleda);
        }
        catch(std::bad_alloc){
            br_p--;
            throw std::logic_error("Neuspjesna registracija pregleda");
        }
        catch(...){
            br_p--;
            throw;
        }
    }
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) {
        if(br_p == max_br_p) throw std::range_error("Raspored popunjen");
        try{
            pregled[br_p++] = new Pregled(ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda);
        }
        catch(std::bad_alloc){
            br_p--;
            throw std::logic_error("Neuspjesna registracija pregleda");
        }
        catch(...){
            br_p--;
            throw;
        }
    }
    int DajBrojPregleda() const {
        if(br_p == 0) throw std::domain_error("Nema registriranih pregleda");
        return br_p;}
    void IsprazniKolekciju(){
        if(pregled == nullptr) return;
        for(int i = 0; i < br_p; i++){
            delete pregled[i];
        }
        delete[] pregled;
    }
    int DajBrojPregledaNaDatum(const Datum &datum) const{
        if(br_p == 0) throw std::domain_error("Nema registriranih pregleda");
        return std::count_if(pregled, pregled + br_p, [&](Pregled *p){ return (p->DajDatumPregleda().DajDan() == datum.DajDan() && p->DajDatumPregleda().DajMjesec() == datum.DajMjesec() && p->DajDatumPregleda().DajGodinu() == datum.DajGodinu());});
    }
    Pregled &DajNajranijiPregled(){
        if(br_p == 0) throw std::domain_error("Nema registriranih pregleda");
        Pregled *najraniji(pregled[0]);
        for(int i = 0; i < br_p; i++){
            if(Pregled::DolaziPrije(*pregled[i], *najraniji)) najraniji = pregled[i];
        }
    return *najraniji;
    }
    Pregled DajNajranijiPregled() const{
        if(br_p == 0) throw std::domain_error("Nema registriranih pregleda");
        Pregled *najraniji(pregled[0]);
        for(int i = 0; i < br_p; i++){
            if(Pregled::DolaziPrije(*pregled[i], *najraniji)) najraniji = pregled[i];
        }
    return *najraniji;
    }
    void IspisiSvePreglede() const{
        int i = 0;
        for(; i < br_p; i++){
            (*pregled[i]).Ispisi();
            std::cout << std::endl;
        }
        if(i == 0) throw ("Nema pregleda\n");
    }
    void IspisiPregledeNaDatum(const Datum &datum) const{
        int i = 0;
        for(int i = 0; i < br_p; i++){
            if(pregled[i] ->DajDatumPregleda().DajDan() == datum.DajDan() && 
            pregled[i] ->DajDatumPregleda().DajMjesec() == datum.DajMjesec() && 
            pregled[i] ->DajDatumPregleda().DajGodinu() == datum.DajGodinu()){
                pregled[i]->Ispisi();
                std::cout<<std::endl;
            }
        }
        if(i == 0) throw ("Nema pregleda na trazeni dan");
    }
    void ObrisiNajranijiPregled(){
        if(br_p == 0) throw std::range_error("Prazna kolekcija");
        Pregled p = Pregledi::DajNajranijiPregled();
        Pregledi temp = Pregledi(max_br_p);
        int brojac = 0;
        for(int i = 0; i < br_p; i++){
            auto t=pregled[i];
            if (t->DajImePacijenta() != p.DajImePacijenta() && 
            t->DajDatumPregleda().DajDan() != p.DajDatumPregleda().DajDan() && 
            t->DajDatumPregleda().DajMjesec() != p.DajDatumPregleda().DajMjesec() && 
            t->DajDatumPregleda().DajGodinu() != p.DajDatumPregleda().DajGodinu() && 
            t->DajVrijemePregleda().DajSate() != p.DajVrijemePregleda().DajSate() && 
            t->DajVrijemePregleda().DajMinute() != p.DajVrijemePregleda().DajMinute())
            temp.pregled[brojac++] = pregled[i];
        }
        std::copy(temp.pregled, temp.pregled + max_br_p, pregled);
        br_p = brojac;
    }
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta){
        if(br_p == 0) std::range_error("Prazna kolekcija");
        Pregledi temp = Pregledi(max_br_p);
        int brojac = 0;
        for(int i = 0; i < br_p; i++){
            if(pregled[i]->DajImePacijenta() != ime_pacijenta) 
            temp.pregled[brojac++] = pregled[i];
        }
        br_p = brojac;
        std::copy(temp.pregled, temp.pregled + max_br_p, pregled);
    }
};

int main ()
{
    try{
    std::cout<<"Unesite maksimalan broj pregleda: ";
    int m;
    std::cin>>m;
    Pregledi p(m);
    std::cin.clear();
    std::cin.ignore(100000,'\n');
    int a = 0;
    while(a < m){
    std::cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
    std::string s;
    std::getline(std::cin, s);
     std::cin.clear();
    std::cin.ignore(100000,'\n');
    std::string kraj = "kraj";
    if(s.compare(kraj)==0) break;
    std::cout<<"Unesite dan mjesec i godinu pregleda: ";
    int d(0), m(0), g(0);
    std::cin.clear();
    std::cin.ignore(100000,'\n');
    std::cin>>d>>m>>g;
    std::cin.clear();
    std::cin.ignore(100000,'\n');
    std::cout<<"Unesite sate i minute pregleda: ";
    int h(0), minu(0);
    std::cin.clear();
    std::cin.ignore(10000,'\n');
    std::cin>>h>>minu;
    std::cin.clear();
    std::cin.ignore(100000,'\n');
    p.RegistrirajPregled(s, d, m, g, h, minu);
    a++;
    }
    std::cout<<"Trenutno su registrovani sljedeci pregledi "<<std::endl;
    p.IspisiSvePreglede();
    int opcija(0);
    while(opcija != 7){
        std::cout<<"Odaberite jednu od sljedecih opcija\n"<<"1 - Broj pregleda na datum\n"<<"2 - Najraniji pregled\n"<<"3 - Obrisi pregled pacijenta\n";
        std::cout<<"4 - Obrisi najraniji pregled\n"<<"5 - Ispisi sve pregleda na datum\n"<<"6 - Ispisi sve preglede\n"<<"7 - Kraj programa\n\n";
         std::cin.clear();
        std::cin.ignore(100000,'\n');
        std::cin>>opcija;
        std::cin.clear();
        std::cin.ignore(100000,'\n');
        if(opcija == 1){
            std::cout<<"Unesite dan mjesec i godinu : ";
            int d(0), m(0), g(0);
            std::cin>>d>>m>>g;
            Datum dat(d, m, g);
            std::cout<<"Broj pregleda na datum "<<d<<" "<<m<<" "<<g<<" je: ";
            std::cout<<p.DajBrojPregledaNaDatum(dat);
        }
        else if(opcija == 2){
            std::cout<<"Najraniji pregled je: ";
            p.DajNajranijiPregled().Pregled::Ispisi();
        }
        else if(opcija == 3){
            std::cout<<"Unesite ime pacijenta: ";
            std::string ime;
            std::getline(std::cin, ime);
            int br = p.DajBrojPregleda();
            p.ObrisiPregledePacijenta(ime);
            std::cout<<"Uspjesno obrisano "<<br - p.DajBrojPregleda()<<" pregleda";
        }
        else if(opcija == 4){
            p.ObrisiNajranijiPregled();
            std::cout<<"Najraniji pregled uspjesno obrisan ";
        }
        else if(opcija == 5){
            std::cout<<"Unesite dan mjesec i godinu : ";
            int d(0), m(0), g(0);
            Datum da(d, m, g);
            std::cout<<"Pregledi na datum "<<d<<" "<<m<<" "<<g<<" su:"<<std::endl;
            p.IspisiPregledeNaDatum(da);
        }
        else if(opcija == 6){
            p.IspisiSvePreglede();
        }
        else if(opcija == 7){
            break;
        }
        std::cout<<std::endl;
    }
	return 0;
    }catch(std::bad_alloc e){
        std::cout<<e.what();
    }catch(std::logic_error e){
        std::cout<<e.what();
    }catch(std::domain_error e){
        std::cout<<e.what();
    }
    catch(std::range_error e){
        std::cout<<e.what();
    }
    catch(const std::string s){
        std::cout<<s;
    }
    catch(...){
    }
}
