/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <utility>
#include <string>
#include <iomanip>
#include <new>
#include <vector>
#include <algorithm>


class Datum
{
    int d,m,g;
public:
    Datum(int dan, int mjesec, int godina) {
        int br_dana[12] {31,28,31,30,31,30,31,31,30,31,30,31};
        if((godina%4==0 && godina%100!=0) || godina%400==0) br_dana[1]++;
        if(godina<1 || mjesec<1 || dan<1 || mjesec>12 || dan>br_dana[mjesec-1]) throw std::domain_error("Neispravan datum");
        d=dan;
        m=mjesec;
        g=godina;
    }

    void Postavi(int dan, int mjesec, int godina) {
        int br_dana[12] {31,28,31,30,31,30,31,31,30,31,30,31};
        if((godina%4==0 && godina%100!=0) || godina%400==0) br_dana[1]++;
        if(godina<1 || mjesec<1 || dan<1 || mjesec>12 || dan>br_dana[mjesec-1]) throw std::domain_error("Neispravan datum");
        d=dan;
        m=mjesec;
        g=godina;
    }

    std::tuple<int, int, int> Ocitaj() const {
        std::tuple<int,int,int> Povratni;
        Povratni=std::make_tuple(d,m,g);
        return Povratni;
    }
    void Ispisi() const {
        //if(d<10) std::cout<<"0";
        std::cout<<d<<"/";
        //if(m<10) std::cout<<"0";
        std::cout<<m<<"/";
        //if(g<10) std::cout<<"000";
        //else if(g<100) std::cout<<"00";
        //else if(g<1000) std::cout<<"0";
        std::cout<<g;
    }
};

class Vrijeme
{
    int min,hour;
public:
    Vrijeme(int sati, int minute) {
        if(sati<0 || sati>23 || minute<0 || minute>59) throw std::domain_error("Neispravno vrijeme");
        min=minute;
        hour=sati;
    }
    void Postavi(int sati, int minute) {
        if(sati<0 || sati>23 || minute<0 || minute>59) throw std::domain_error("Neispravno vrijeme");
        min=minute;
        hour=sati;
    }
    std::pair<int, int> Ocitaj () const {
        std::pair<int,int> Povratni;
        Povratni=std::make_pair(hour,min);
        return Povratni;
    }
    void Ispisi() const {
        if(hour<10) std::cout<<"0";
        std::cout<<hour<<":";
        if(min<10) std::cout<<"0";
        std::cout<<min;

    }
};

class Pregled
{
    
    Datum dat_pregleda;
    Vrijeme vr_pregleda;
    std::string name;
    
public:

    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda):dat_pregleda(datum_pregleda),vr_pregleda(vrijeme_pregleda) {
        name=ime_pacijenta;
    }

    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda):dat_pregleda(dan_pregleda,mjesec_pregleda,godina_pregleda),vr_pregleda(sati_pregleda,minute_pregleda) {
        name=ime_pacijenta;
    }

    void PromijeniPacijenta(const std::string &ime_pacijenta) {
        name=ime_pacijenta;
    }

    void PromijeniDatum(const Datum &novi_datum) {
        int D,M,G;
        std::tie(D,M,G)=novi_datum.Ocitaj();
        dat_pregleda.Postavi(D,M,G);
    }

    void PromijeniVrijeme(const Vrijeme &novo_vrijeme) {
        std::pair<int,int> TrebaMi(novo_vrijeme.Ocitaj());
        vr_pregleda.Postavi(TrebaMi.first,TrebaMi.second);
    }

    void PomjeriDanUnaprijed() {
        int br_dana[12] {31,28,31,30,31,30,31,31,30,31,30,31};
        int D,M,G;
        std::tie(D,M,G)=dat_pregleda.Datum::Ocitaj();
        if(D>br_dana[M-1]) {
            D=0;
            M++;
            if(M>12) {
                M=0;
                G++;
            }
        }
        dat_pregleda.Datum::Postavi(D,M,G);
    }

    void PomjeriDanUnazad() {
        int br_dana[12] {31,28,31,30,31,30,31,31,30,31,30,31};
        int D,M,G;
        std::tie(D,M,G)=dat_pregleda.Datum::Ocitaj();
        D--;
        if(D==0) {
            D=br_dana[M-2];
            M--;
            if(M==0) {
                M=12;
                G--;
            }
        }
        dat_pregleda.Datum::Postavi(D,M,G);
    }

    std::string DajImePacijenta() const {
        return name;
    }

    Datum DajDatumPregleda() const {

        return dat_pregleda;
    }

    Vrijeme DajVrijemePregleda() const {
        return vr_pregleda;
    }

    static bool DolaziPrije(const Pregled &p1, const Pregled &p2) {
        //int br_dana[12] {31,28,31,30,31,30,31,31,30,31,30,31};
        int D1,M1,G1,D2,M2,G2;
        std::tie(D1,M1,G1)=p1.dat_pregleda.Ocitaj();
        std::tie(D2,M2,G2)=p2.dat_pregleda.Ocitaj();
        std::pair<int,int> Vrijeme1(p1.vr_pregleda.Ocitaj());
        std::pair<int,int> Vrijeme2(p2.vr_pregleda.Ocitaj());
        if(G1<G2) return true;
        else if(G1>G2) return false;
        else if(G1==G2) {
            if(M1<M2) return true;
            else if(M1>M2) return false;
            else if(M1==M2) {
                if(D1<D2) return true;
                else if(D1>D2) return false;
                if(D1==D2) {
                    if(Vrijeme1.first<Vrijeme2.first) return true;
                    else if(Vrijeme1.first>Vrijeme2.first) return false;
                    if(Vrijeme1.first==Vrijeme2.first) {
                        if(Vrijeme1.second<Vrijeme2.second) return true;
                        else return false;
                    }
                }
            }
        }
    }

    void Ispisi() const {
        std::cout<<std::left<<std::setw(30)<<name;
        dat_pregleda.Ispisi();
        std::cout<<" ";
        vr_pregleda.Ispisi();
    }

};

class Pregledi
{
    const int max_broj_pregleda;
    int broj_pregleda;
    Pregled **PREGLEDI=nullptr;
public:

    explicit Pregledi(int max_broj_pregleda):max_broj_pregleda(max_broj_pregleda),broj_pregleda(0),PREGLEDI(new Pregled*[max_broj_pregleda] {}) {}

    Pregledi(std::initializer_list<Pregled> spisak_pregleda):max_broj_pregleda(spisak_pregleda.size()),broj_pregleda(spisak_pregleda.size()),PREGLEDI(new Pregled*[max_broj_pregleda] {}) {
        auto it(spisak_pregleda.begin());
        int brojac(0);
        while(it!=spisak_pregleda.end()) {
            try {
                PREGLEDI[brojac]=new Pregled(it->DajImePacijenta(),it->DajDatumPregleda(),it->DajVrijemePregleda());
            } catch(...) {
                for(int i=0; i<max_broj_pregleda; i++) delete PREGLEDI[i];
                delete[] PREGLEDI;
                throw;
            }
            brojac++;
        }
    }

    ~Pregledi() {
        for(int i=0; i<max_broj_pregleda; i++) delete PREGLEDI[i];
        delete[] PREGLEDI;
    }

    Pregledi(const Pregledi &pregledi):max_broj_pregleda(pregledi.max_broj_pregleda),broj_pregleda(pregledi.broj_pregleda) {
        try {
            PREGLEDI=new Pregled*[pregledi.max_broj_pregleda] {};
            for(int i=0; i<pregledi.max_broj_pregleda; i++) PREGLEDI[i]=new Pregled(pregledi.PREGLEDI[i]->DajImePacijenta(),pregledi.PREGLEDI[i]->DajDatumPregleda(),pregledi.PREGLEDI[i]->DajVrijemePregleda());
        } catch(...) {
            for(int i=0; i<pregledi.max_broj_pregleda; i++) delete PREGLEDI[i];
            delete[] PREGLEDI;
            throw;
        }
    }

    Pregledi(Pregledi &&pregledi):max_broj_pregleda(pregledi.max_broj_pregleda),broj_pregleda(pregledi.broj_pregleda) {
        try {
            PREGLEDI=new Pregled*[pregledi.max_broj_pregleda] {};
            for(int i=0; i<pregledi.max_broj_pregleda; i++) PREGLEDI[i]=new Pregled(pregledi.PREGLEDI[i]->DajImePacijenta(),pregledi.PREGLEDI[i]->DajDatumPregleda(),pregledi.PREGLEDI[i]->DajVrijemePregleda());
        } catch(...) {
            for(int i=0; i<pregledi.max_broj_pregleda; i++) delete PREGLEDI[i];
            delete[] PREGLEDI;
            throw;
        }
    }

    Pregledi &operator =(const Pregledi &pregledi) {
        if(&pregledi!=this) {

            for(int i=0; i<broj_pregleda; i++) delete PREGLEDI[i];
            for(int i=0; i<pregledi.broj_pregleda; i++) PREGLEDI[i]=new Pregled(pregledi.PREGLEDI[i]->DajImePacijenta(),pregledi.PREGLEDI[i]->DajDatumPregleda(),pregledi.PREGLEDI[i]->DajVrijemePregleda());
        }
        broj_pregleda=pregledi.broj_pregleda;
        return *this;
    }

    Pregledi &operator =(Pregledi &&pregledi) {
        if(&pregledi!=this) {
            delete[] PREGLEDI;
            PREGLEDI=pregledi.PREGLEDI;
            broj_pregleda=pregledi.broj_pregleda;
            pregledi.PREGLEDI=nullptr;
            pregledi.broj_pregleda=0;
        }
        return *this;
    }

    void RegistrirajPregled(const std::string &ime_pacijenta,const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) {
        if(broj_pregleda+1>max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
        try {
            PREGLEDI[broj_pregleda]=new Pregled(ime_pacijenta,datum_pregleda,vrijeme_pregleda);
            broj_pregleda++;
        } catch(...) {
            delete PREGLEDI[broj_pregleda];
            throw;
        }
    }

    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,int mjesec_pregleda, int godina_pregleda, int sati_pregleda,int minute_pregleda) {
        if(broj_pregleda+1>max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
        try {
            PREGLEDI[broj_pregleda]=new Pregled(ime_pacijenta,dan_pregleda,mjesec_pregleda,godina_pregleda,sati_pregleda,minute_pregleda);
            broj_pregleda++;
        } catch(...) {
            delete PREGLEDI[broj_pregleda];
            throw;
        }
    }

    void RegistrirajPregled(Pregled *pregled){
        if(broj_pregleda+1>max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
        try {
            
            PREGLEDI[broj_pregleda]=new Pregled(pregled->DajImePacijenta(),pregled->DajDatumPregleda(),pregled->DajVrijemePregleda());
            broj_pregleda++;
        } catch(...) {
            delete PREGLEDI[broj_pregleda];
            throw;
        }
    }

    int DajBrojPregleda() const {
        return broj_pregleda;
    }

    int DajBrojPregledaNaDatum(const Datum &datum) const {
        int D,M,G;
        std::tie(D,M,G)=datum.Ocitaj();
        int brojac_pregleda(0);
        for(int i=0; i<broj_pregleda; i++) {
            int d,m,g;
            Datum pomocni(1,1,1);
            pomocni=PREGLEDI[i]->DajDatumPregleda();
            std::tie(d,m,g)=pomocni.Ocitaj();
            if(D==d && M==m && G==g) brojac_pregleda++;
        }
        return brojac_pregleda;
    }

    Pregled &DajNajranijiPregled() {
        return **std::min_element(PREGLEDI,PREGLEDI+broj_pregleda,[](const Pregled *p1,const Pregled *p2) {
            return Pregled::DolaziPrije(*p1,*p2);
        });
    }

    Pregled DajNajranijiPregled() const {
        return **std::min_element(PREGLEDI,PREGLEDI+broj_pregleda,[](const Pregled *p1,const Pregled *p2) {
            return Pregled::DolaziPrije(*p1,*p2);
        });
    }

    void IsprazniKolekciju() {
        for(int i=0; i<broj_pregleda; i++) {
            delete PREGLEDI[i];
            PREGLEDI[i]=nullptr;
        }
        delete[] PREGLEDI;
        PREGLEDI=nullptr;
        broj_pregleda=0;
    }

    void ObrisiNajranijiPregled() {
        Pregled Pomoc(this->DajNajranijiPregled());
        auto t(Pomoc.DajDatumPregleda().Ocitaj());
        std::pair<int,int> PomocVrijeme(Pomoc.DajVrijemePregleda().Ocitaj());
        int one,two,three,four,five;
        std::tie(one,two,three)=t;
        four=PomocVrijeme.first;
        five=PomocVrijeme.second;


        for(int i=0; i<broj_pregleda; i++) {
            int jedan,dva,tri,cetiri,pet;
            auto t1(PREGLEDI[i]->DajDatumPregleda().Ocitaj());
            std::tie(jedan,dva,tri)=t1;
            std::pair<int,int> PomocVrijeme1(PREGLEDI[i]->DajVrijemePregleda().Ocitaj());
            cetiri=PomocVrijeme1.first;
            pet=PomocVrijeme1.second;
            if(one==jedan && two==dva && three==tri && four==cetiri && five==pet) {
                delete PREGLEDI[i];
                for(int j=i; j<broj_pregleda-1; j++)
                    PREGLEDI[j]=PREGLEDI[j+1];

                PREGLEDI[broj_pregleda-1]=nullptr;
                broj_pregleda--;
            }
        }
    }

    void ObrisiPregledePacijenta(const std::string &ime_pacijenta) {

        for(int i=0; i<broj_pregleda; i++) {
            if(PREGLEDI[i]->DajImePacijenta()==ime_pacijenta) {
                delete PREGLEDI[i];
                for(int j=i; j<broj_pregleda-1; j++)
                    PREGLEDI[j]=PREGLEDI[j+1];

                PREGLEDI[broj_pregleda-1]=nullptr;
                broj_pregleda--;
                i--;
            }
        }

    }

    void IspisiPregledeNaDatum(const Datum &datum) const {
        std::tuple<int,int,int> Help(datum.Ocitaj());
        int Day1,Month1,Year1,DayHelp,MonthHelp,YearHelp;
        std::tie(DayHelp,MonthHelp,YearHelp)=Help;

        for(int i=0; i<broj_pregleda; i++) {
            std::tuple<int,int,int> CurrentHelp((PREGLEDI[i]->DajDatumPregleda()).Ocitaj());
            std::tie(Day1,Month1,Year1)=CurrentHelp;
            if(Day1==DayHelp && Month1==MonthHelp && Year1==YearHelp) PREGLEDI[i]->Ispisi();
        }
    }

    void IspisiSvePreglede() const {
        Pregled **HelpMe;
        try {
            HelpMe=new Pregled*[broj_pregleda] {};
            std::copy(PREGLEDI,PREGLEDI+broj_pregleda,HelpMe);
            std::sort(HelpMe,HelpMe+broj_pregleda,[](const Pregled *p1,const Pregled *p2) {
                return Pregled::DolaziPrije(*p1,*p2);
            });
            for(int i=0; i<broj_pregleda; i++) {
                HelpMe[i]->Ispisi();
                std::cout<<std::endl;
            }
            //Necemo brisati nesto tipa HelpMe[i], jer tada ode sadrzaj...
            delete[] HelpMe;
        } catch(...) {
            delete[] HelpMe;
        }
    }

};

int main ()

{
    std::cout<<"Unesite maksimalan broj pregleda: ";
    int max_broj_pregleda;
    std::cin>>max_broj_pregleda;
    Pregledi svi_pregledi(max_broj_pregleda);
    try {

        int brojac_pacijenata(0);
        while(1) {
            std::cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
            std::string novi_pacijent;
            std::cin>>novi_pacijent;
            if(novi_pacijent=="kraj") break;
            std::cout<<"Unesite dan mjesec i godinu pregleda: ";
            int dan,mjesec,godina;
            std::cin>>dan>>mjesec>>godina;
            std::cout<<"Unesite sate i minute pregleda: ";
            int sati,minute;
            std::cin>>sati>>minute;
            svi_pregledi.RegistrirajPregled(novi_pacijent,dan,mjesec,godina,sati,minute);
            brojac_pacijenata++;
            if(brojac_pacijenata==max_broj_pregleda) break;

        }
        std::cout<<"Trenutno su registrovani sljedeci pregledi \n";
        svi_pregledi.IspisiSvePreglede();

        while(1) {
            std::cout<<"\nOdaberite jednu od sljedecih opcija";
            std::cout<<"\n1 - Broj pregleda na datum";
            std::cout<<"\n2 - Najraniji pregled";
            std::cout<<"\n3 - Obrisi pregled pacijenta";
            std::cout<<"\n4 - Obrisi najraniji pregled";
            std::cout<<"\n5 - Ispisi sve pregleda na datum";
            std::cout<<"\n6 - Ispisi sve preglede";
            std::cout<<"\n7 - Kraj programa";
            int unos_opcije;
            std::cin>>unos_opcije;
            if(unos_opcije==1) {
                std::cout<<"\nUnesite dan mjesec i godinu : ";
                int d,m,g;
                std::cin>>d>>m>>g;
                Datum temp(d,m,g);
                int n(svi_pregledi.DajBrojPregledaNaDatum(temp));
                std::cout<<"Broj pregleda na datum "<<d<<" "<<m<<" "<<g<<" je: "<<n;
                

            } else if(unos_opcije==2) {
                std::cout<<"\nNajraniji pregled je: \n";
                svi_pregledi.DajNajranijiPregled().Ispisi();
            }
            else if(unos_opcije==3){
                std::cout<<"\nUnesite ime pacijenta: ";
                std::string s;
                std::cin>>s;
                int n(svi_pregledi.DajBrojPregleda());
                svi_pregledi.ObrisiPregledePacijenta(s);
                int m(svi_pregledi.DajBrojPregleda());
                std::cout<<"Uspjesno obrisano "<<n-m<<" pregleda";
            }
            else if(unos_opcije==4){
                svi_pregledi.ObrisiNajranijiPregled();
                std::cout<<"\nNajraniji pregled uspjesno obrisan";
            }
            else if(unos_opcije==5){
                std::cout<<"\nUnesite dan mjesec i godinu : ";
                int d,m,g;
                std::cin>>d>>m>>g;
                std::cout<<"Pregledi na datum "<<d<<" "<<m<<" "<<g<<" su:\n";
                Datum temp(d,m,g);
                svi_pregledi.IspisiPregledeNaDatum(temp);
            }
            else if(unos_opcije==6){
                std::cout<<std::endl;
                svi_pregledi.IspisiSvePreglede();
            }
            else if(unos_opcije==7) return 0;
            std::cout<<std::endl;
        }

    } catch(...) {
        std::cout<<"Problemi sa memorijom";
    }
    return 0;
}
