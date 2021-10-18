/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <tuple>
#include <string>
#include <algorithm>
using std::string;
using std::cout;
using std::cin;

// RAZLOG ZA PASTE - ZADATAK JE IZBRISAN SA C9 I DEMONSTRATOR NIJE MOGAO URADITI RESTORE
// (IZ NEPOZNATOG RAZLOGA) PA MI JE POSLAO KOD ZADATKA

class Datum{
    int dan,mjesec,godina;
    public:
    Datum(int dan, int mjesec, int godina);
    void Postavi(int dan, int mjesec, int godina);
    std::tuple<int, int, int> Ocitaj() const{ return std::make_tuple(dan,mjesec,godina); }
    void Ispisi() const{ cout<<dan<<"/"<<mjesec<<"/"<<godina; }
};
Datum::Datum(int dan, int mjesec, int godina){
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina%4==0 && godina%100!=0) || godina%400==0) broj_dana[1]++;
    if(godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>broj_dana[mjesec-1])
    throw std::domain_error("Neispravan datum!");
    Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
}
void Datum::Postavi(int dan, int mjesec, int godina){
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina%4==0 && godina%100!=0) || godina%400==0) broj_dana[1]++;
    if(godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>broj_dana[mjesec-1])
    throw std::domain_error("Neispravan datum!");
    Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
}

class Vrijeme{
    int sati,minute;
    public:
    Vrijeme(int sati, int minute);
    void Postavi(int sati, int minute);
    std::pair<int, int> Ocitaj () const{ return std::make_pair(sati,minute); }
    void Ispisi() const{ cout<<std::setw(2)<<std::setfill('0')<<std::right<<sati<<":"<<std::setw(2)<<std::setfill('0')<<std::right<<minute; }
};
Vrijeme::Vrijeme(int sati, int minute){
    if(sati<0 || sati>23 || minute<0 || minute>59)
    throw std::domain_error("Neispravno vrijeme");
    Vrijeme::sati=sati; Vrijeme::minute=minute;
}
void Vrijeme::Postavi(int sati, int minute){
    if(sati<0 || sati>23 || minute<0 || minute>59)
    throw std::domain_error("Neispravno vrijeme");
    Vrijeme::sati=sati; Vrijeme::minute=minute;
}

class Pregled{
    string ime;
    Datum dat;
    Vrijeme vrijeme;
    public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda,const Vrijeme &vrijeme_pregleda);
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void PromijeniPacijenta(const std::string &ime_pacijenta){ ime=ime_pacijenta; }
    void PromijeniDatum(const Datum &novi_datum){ dat=Datum(novi_datum); }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme){ vrijeme=Vrijeme(novo_vrijeme); }
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImePacijenta() const{ return ime; }
    Datum DajDatumPregleda() const{ return dat; }
    Vrijeme DajVrijemePregleda() const{ return vrijeme; }
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
    void Ispisi() const{ cout<<std::fixed<<std::setw(30)<<std::setfill(' ')<<std::left<<ime;
    DajDatumPregleda().Ispisi(); cout<<" "; DajVrijemePregleda().Ispisi();  }
};
Pregled::Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda,const Vrijeme &vrijeme_pregleda):
    ime(ime_pacijenta),dat(datum_pregleda), vrijeme(vrijeme_pregleda){}
Pregled::Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,int godina_pregleda,
    int sati_pregleda, int minute_pregleda):ime(ime_pacijenta),dat(dan_pregleda,mjesec_pregleda,godina_pregleda),
    vrijeme(sati_pregleda,minute_pregleda){}
void Pregled::PomjeriDanUnaprijed(){
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    auto t(dat.Ocitaj());
    if((std::get<2>(t)%4==0 && std::get<2>(t)%100!=0) || std::get<2>(t)%400==0) broj_dana[1]++;
    std::get<0>(t)++;
    if(std::get<0>(t)>broj_dana[std::get<1>(t)-1]){ std::get<0>(t)=1; std::get<1>(t)++; }
    if(std::get<1>(t)>12){ std::get<1>(t)=1; std::get<2>(t)++; }
    dat.Postavi(std::get<0>(t),std::get<1>(t),std::get<2>(t));
}
void Pregled::PomjeriDanUnazad(){
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    auto t(dat.Ocitaj());
    if((std::get<2>(t)%4==0 && std::get<2>(t)%100!=0) || std::get<2>(t)%400==0) broj_dana[1]++;
    std::get<0>(t)--;
    if(std::get<0>(t)<1){
        std::get<1>(t)--;
        if(std::get<1>(t)<1){ std::get<1>(t)=12; std::get<2>(t)--; }
        std::get<0>(t)=broj_dana[std::get<1>(t)-1];
    }
    dat.Postavi(std::get<0>(t),std::get<1>(t),std::get<2>(t));
}
bool Pregled::DolaziPrije(const Pregled &p1, const Pregled &p2){
    auto d1(p1.DajDatumPregleda().Ocitaj()),d2(p2.DajDatumPregleda().Ocitaj());
    if(std::get<2>(d1)==std::get<2>(d2)){
        if(std::get<1>(d1)==std::get<1>(d2)){
            if(std::get<0>(d1)==std::get<0>(d2)){
                auto v1(p1.DajVrijemePregleda().Ocitaj()),v2(p2.DajVrijemePregleda().Ocitaj());
                if(std::get<0>(v1)==std::get<0>(v2)){
                    if(std::get<1>(v1)==std::get<1>(v2)) return false;
                    return std::get<1>(v1)>std::get<1>(v2);
                }
                return std::get<0>(v1)>std::get<0>(v2);
            }
            return std::get<0>(d1)>std::get<0>(d2);
        }
        return std::get<1>(d1)>std::get<1>(d2);
    }
    return std::get<2>(d1)>std::get<2>(d2);
}

bool operator ==(const Datum &d1,const Datum &d2){
    return d1.Ocitaj()==d2.Ocitaj();
}

class Pregledi{
    int max_br_pregleda;
    int broj_reg;
    Pregled **niz_pregleda=nullptr;
    public:
    explicit Pregledi(int max_broj_pregleda);
    Pregledi(std::initializer_list<Pregled> spisak_pregleda);
    ~Pregledi(){ for(int i(0);i<max_br_pregleda;i++) delete niz_pregleda[i]; delete[] niz_pregleda; }
    Pregledi(const Pregledi &pregledi);
    Pregledi(Pregledi &&pregledi);
    Pregledi &operator =(const Pregledi &pregledi);
    Pregledi &operator =(Pregledi &&pregledi);
    void RegistrirajPregled(const std::string &ime_pacijenta,
    const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,
    int mjesec_pregleda, int godina_pregleda, int sati_pregleda,
    int minute_pregleda);
    void RegistrirajPregled(Pregled *pregled);
    int DajBrojPregleda() const{ return broj_reg; }
    int DajBrojPregledaNaDatum(const Datum &datum) const;
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum(const Datum &datum) const;
    void IspisiSvePreglede() const;
};
Pregledi::Pregledi(int max_broj_pregleda):max_br_pregleda(max_broj_pregleda),broj_reg(0){
    niz_pregleda=new Pregled*[max_br_pregleda]{}; }
Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda):max_br_pregleda(spisak_pregleda.size()){
    niz_pregleda=new Pregled*[spisak_pregleda.size()]{};
    int i(0);
    for(auto it(spisak_pregleda.begin());it!=spisak_pregleda.end();it++){
        niz_pregleda[i]=new Pregled(*it);
        i++;
    }
    broj_reg=spisak_pregleda.size();
}
Pregledi::Pregledi(const Pregledi &pregledi):max_br_pregleda(pregledi.max_br_pregleda){
    niz_pregleda=new Pregled*[pregledi.max_br_pregleda]{};
    for(int i(0);i<pregledi.broj_reg;i++){
        niz_pregleda[i]=new Pregled(*pregledi.niz_pregleda[i]);
    }
    broj_reg=pregledi.broj_reg;
}
Pregledi::Pregledi(Pregledi &&pregledi):max_br_pregleda(pregledi.max_br_pregleda){
    niz_pregleda=new Pregled*[pregledi.max_br_pregleda]{};
    for(int i(0);i<pregledi.broj_reg;i++){
        niz_pregleda[i]=pregledi.niz_pregleda[i];
        pregledi.niz_pregleda[i]=nullptr;
    }
    broj_reg=pregledi.broj_reg;
    pregledi.niz_pregleda=nullptr;
}
Pregledi &Pregledi::operator =(const Pregledi &pregledi){
    if(&pregledi!=this){
        for(int i(0);i<max_br_pregleda;i++) delete niz_pregleda[i]; delete[] niz_pregleda;
        niz_pregleda=nullptr;
        max_br_pregleda=pregledi.max_br_pregleda;
        niz_pregleda=new Pregled*[pregledi.max_br_pregleda]{};
        for(int i(0);i<pregledi.broj_reg;i++){
            niz_pregleda[i]=new Pregled(*pregledi.niz_pregleda[i]);
        }
        broj_reg=pregledi.broj_reg;
    }
    return *this;
}
Pregledi &Pregledi::operator =(Pregledi &&pregledi){
    if(&pregledi!=this){
        for(int i(0);i<max_br_pregleda;i++) delete niz_pregleda[i]; delete niz_pregleda;
        niz_pregleda=nullptr;
        max_br_pregleda=pregledi.max_br_pregleda;
        niz_pregleda=new Pregled*[pregledi.max_br_pregleda]{};
        for(int i(0);i<pregledi.broj_reg;i++){
            niz_pregleda[i]=pregledi.niz_pregleda[i];
            pregledi.niz_pregleda[i]=nullptr;
        }
        pregledi.niz_pregleda=nullptr;
        broj_reg=pregledi.broj_reg;
    }
    return *this;
}
void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta,const Datum &datum_pregleda,
const Vrijeme &vrijeme_pregleda){
        for(int i(0);i<max_br_pregleda;i++){
            if(niz_pregleda[i]==nullptr){
                niz_pregleda[i]=new Pregled(ime_pacijenta,datum_pregleda,vrijeme_pregleda);
                broj_reg++;
                return;
            }
        }
        throw std::range_error("Dostignut maksimalni broj pregleda");
}
void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,int mjesec_pregleda,
int godina_pregleda, int sati_pregleda,int minute_pregleda){
    for(int i(0);i<max_br_pregleda;i++){
            if(niz_pregleda[i]==nullptr){
                niz_pregleda[i]=new Pregled(ime_pacijenta,dan_pregleda,mjesec_pregleda,godina_pregleda,
                sati_pregleda,minute_pregleda);
                broj_reg++;
                return;
            }
        }
    throw std::range_error("Dostignut maksimalni broj pregleda");
}
void Pregledi::RegistrirajPregled(Pregled *pregled){
    for(int i(0);i<max_br_pregleda;i++){
            if(niz_pregleda[i]==nullptr){
                niz_pregleda[i]=pregled;
                pregled=nullptr;
                broj_reg++;
                return;
            }
        }
    throw std::range_error("Dostignut maksimalni broj pregleda");
}
int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const{
    return std::count_if(niz_pregleda,niz_pregleda+broj_reg,[&datum](Pregled *pregled){
       return datum.Ocitaj()==pregled->DajDatumPregleda().Ocitaj(); });
}
Pregled &Pregledi::DajNajranijiPregled(){
    if(broj_reg==0) throw std::domain_error("Nema registriranih pregleda");
    return **std::min_element(niz_pregleda,niz_pregleda+broj_reg,[](Pregled *p1,Pregled *p2){
        return !Pregled::DolaziPrije(*p1,*p2); });
}
Pregled Pregledi::DajNajranijiPregled() const{
    if(broj_reg==0) throw std::domain_error("Nema registriranih pregleda");
    return **std::min_element(niz_pregleda,niz_pregleda+broj_reg,[](Pregled *p1,Pregled *p2){
        return !Pregled::DolaziPrije(*p1,*p2); });
}
void Pregledi::IsprazniKolekciju(){
    for(int i(0);i<broj_reg;i++){
        delete niz_pregleda[i];
        niz_pregleda[i]=nullptr;
    }
    broj_reg=0;
}
void Pregledi::ObrisiNajranijiPregled(){
    if(broj_reg==0) throw std::range_error("Prazna kolekcija");
    Pregled *min(niz_pregleda[0]);
    for(int i(0);i<broj_reg;i++){
        if(Pregled::DolaziPrije(*min,*niz_pregleda[i])) min=niz_pregleda[i];
    }
    for(int i(0);i<broj_reg;i++){
        if(min==niz_pregleda[i]){
            delete niz_pregleda[i];
            for(int j(i);j<broj_reg-1;j++) niz_pregleda[j]=niz_pregleda[j+1];
            broj_reg--;
            niz_pregleda[broj_reg]=nullptr;
            i--;
        }
    }
}
void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta){
    for(int i(0);i<broj_reg;i++){
        if(ime_pacijenta==niz_pregleda[i]->DajImePacijenta()){
            delete niz_pregleda[i];
            for(int j(i);j<broj_reg-1;j++) niz_pregleda[j]=niz_pregleda[j+1];
            broj_reg--;
            niz_pregleda[broj_reg]=nullptr;
            i--;
        }
    }
}
void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const{
    std::sort(niz_pregleda,niz_pregleda+broj_reg,[](Pregled *p1,Pregled *p2){
        return !Pregled::DolaziPrije(*p1,*p2); });
    for(int i(0);i<broj_reg;i++){
        if(datum==niz_pregleda[i]->DajDatumPregleda()) 
        { niz_pregleda[i]->Ispisi(); cout<<std::endl; }
    }
}
void Pregledi::IspisiSvePreglede() const{
    std::sort(niz_pregleda,niz_pregleda+broj_reg,[](Pregled *p1,Pregled *p2){
        return !Pregled::DolaziPrije(*p1,*p2); });
    for(int i(0);i<broj_reg;i++){ niz_pregleda[i]->Ispisi(); cout<<std::endl; }
}

int main ()
{
    int n(0);
    cout<<"Unesite maksimalan broj pregleda: ";
    cin>>n;
    Pregledi p(n);
    try{
        for(int i(0);i<n;i++){
            string ime;
            cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
            cin.clear();
            cin.ignore(1000,'\n');
            std::getline(cin,ime);
            if(ime=="kraj") break;
            int d(0),m(0),g(0),h(0),min(0);
            cout<<"Unesite dan mjesec i godinu pregleda: ";
            cin>>d>>m>>g;
            cout<<"Unesite sate i minute pregleda: ";
            cin>>h>>min;
            p.RegistrirajPregled(ime,d,m,g,h,min);
        }
        cout<<"Trenutno su registrovani sljedeci pregledi"<<std::endl;
        p.IspisiSvePreglede(); cout<<std::endl;
        while(true){
            try{
            int opcija(0);
            cout<<"Odaberite jednu od sljedecih opcija\n1 - Broj pregleda na datum\n2 - Najraniji pregled\n3 - Obrisi pregled pacijenta";
            cout<<"\n4 - Obrisi najraniji pregled\n5 - Ispisi sve pregleda na datum\n6 - Ispisi sve preglede\n7 - Kraj programa"<<std::endl;
            cin>>opcija;
            if(opcija==1){
                int d(0),m(0),g(0);
                cout<<"Unesite dan mjesec i godinu : ";
                cin>>d>>m>>g;
                Datum dat(d,m,g);
                cout<<"Broj pregleda na datum "<<d<<" "<<m<<" "<<g<<" je: "<<p.DajBrojPregledaNaDatum(dat)<<std::endl;
            }
            if(opcija==2){
                cout<<"Najraniji pregled je:"<<std::endl;
                p.DajNajranijiPregled().Ispisi(); cout<<std::endl;
            }
            if(opcija==3){
                string ime;
                cin.clear();
                cin.ignore(1000,'\n');
                cout<<"Unesite ime pacijenta: ";
                getline(cin,ime);
                int d(p.DajBrojPregleda());
                p.ObrisiPregledePacijenta(ime);
                cout<<"Uspjesno obrisano "<<d-p.DajBrojPregleda()<<" pregleda"<<std::endl;
            }
            if(opcija==4){
                p.ObrisiNajranijiPregled();
                cout<<"Najraniji pregled uspjesno obrisan"<<std::endl;
            }
            if(opcija==5){
                int d(0),m(0),g(0);
                cout<<"Unesite dan mjesec i godinu : ";
                cin>>d>>m>>g;
                Datum dat(d,m,g);
                cout<<"Pregledi na datum "<<d<<" "<<m<<" "<<g<<" su:"<<std::endl;
                p.IspisiPregledeNaDatum(dat); cout<<std::endl;
            }
            if(opcija==6){
                p.IspisiSvePreglede(); cout<<std::endl;
            }
            if(opcija==7) break;
        }
        catch(std::range_error izuzetak){
            cout<<izuzetak.what()<<std::endl;
        }
        catch(std::domain_error izuzetak){
            cout<<izuzetak.what()<<std::endl;
        }
        cout<<std::endl;
        }
    }
    catch(std::range_error izuzetak){
        cout<<izuzetak.what();
    }
    catch(std::domain_error izuzetak){
        cout<<izuzetak.what();
    }
    
	return 0;
}

