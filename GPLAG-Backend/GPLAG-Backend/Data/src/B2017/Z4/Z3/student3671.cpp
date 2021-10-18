/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <utility>
#include <cmath>
#include <iomanip>
using namespace std;

class Datum
{
    int d,m,g;
public:
    Datum(int dan,int mjesec,int godina) {
        Postavi(dan,mjesec,godina);
    }
    void Postavi(int dan,int mjesec,int godina) {
        int broj_dana[12] {31,28,31,30,31,30,31,31,30,31,30,31};
        if(godina%4!=0 && godina%100!=0 || godina%400==0) broj_dana[1]++;
        if(godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>broj_dana[mjesec-1])
            throw domain_error("Neispravan datum");
        d=dan;
        m=mjesec;
        g=godina;
    }
    tuple<int,int,int>Ocitaj() const {
        return tie(d,m,g);
    }
    void Ispisi() const {
        cout<<d<<"/"<<m<<"/"<<g;
    }
};

class Vrijeme
{
    int sati,minute;
public:
    static bool DaLiJeIspravno(int h,int m) {
        if(h<0 || h>23 || m<0 || m>59) return false;
        return true;
    }
    Vrijeme(int sati,int minute) {
        Postavi(sati,minute);
    }
    void Postavi(int sati,int minute) {
        if(!DaLiJeIspravno(sati,minute)) throw domain_error("Neispravno vrijeme");
        Vrijeme::sati=sati;
        Vrijeme::minute=minute;
    }
    pair<int,int>Ocitaj() const {
        return make_pair(sati,minute);
    }
    void Ispisi() const {
        cout<<setw(2)<<setfill('0')<<sati<<":"<<setw(2)<<setfill('0')<<minute;
    }
};

/*int BrojMinuta(Datum d,Vrijeme v){
    pair<int,int>p(v.Ocitaj());
    int sati=p.first;
    int minute=p.second;
    tuple<int,int,int>datum(d.Ocitaj());
    int dan(get<0>(datum)),mjesec(get<1>(datum)),godina(get<2>(datum));
    int br_dan_u_god=godina*365;
}*/

class Pregled
{
    string ime;
    Datum datum;
    Vrijeme vrijeme;
public:
    Pregled(const string &ime_pacijenta, const Datum &datum_pregleda,const Vrijeme &vrijeme_pregleda) :
        ime(ime_pacijenta),datum(datum_pregleda),vrijeme(vrijeme_pregleda) {}

    Pregled(const string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,int godina_pregleda, int sati_pregleda, int minute_pregleda)
        : ime(ime_pacijenta),datum(dan_pregleda,mjesec_pregleda,godina_pregleda),vrijeme(sati_pregleda,minute_pregleda) {}

    void PromijeniPacijenta(const string &ime_pacijenta) {
        Pregled::ime=ime_pacijenta;
    }
    void PromijeniDatum(const Datum &novi_datum) {
        int dan=get<0>(novi_datum.Ocitaj());
        int mjesec=get<1>(novi_datum.Ocitaj());
        int godina=get<2>(novi_datum.Ocitaj());
        datum.Postavi(dan,mjesec,godina);
    }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme) {
        int h=novo_vrijeme.Ocitaj().first;
        int m=novo_vrijeme.Ocitaj().second;
        vrijeme.Postavi(h,m);
    }
    void PomjeriDanUnaprijed() {
        int dan=get<0>(datum.Ocitaj());
        int mjesec=get<1>(datum.Ocitaj());
        int godina=get<2>(datum.Ocitaj());
        int broj_dana[12] {31,28,31,30,31,30,31,31,30,31,30,31};
        if(godina%4!=0 && godina%100!=0 || godina%400==0) broj_dana[1]++;
        dan++;
        if(dan>broj_dana[mjesec-1]) {
            dan=1;
            mjesec++;
            if(mjesec>12) {
                mjesec=1;
                godina++;
            }
        }
        datum.Postavi(dan,mjesec,godina);
    }
    void PomjeriDanUnazad() {
        int dan=get<0>(datum.Ocitaj());
        int mjesec=get<1>(datum.Ocitaj());
        int godina=get<2>(datum.Ocitaj());
        int broj_dana[12] {31,28,31,30,31,30,31,31,30,31,30,31};
        if(godina%4!=0 && godina%100!=0 || godina%400==0) broj_dana[1]++;
        dan--;
        if(dan<broj_dana[mjesec-1]) {
            throw domain_error("Neispravan datum");
        } else datum.Postavi(dan,mjesec,godina);
    }
    string DajImePacijenta() const {
        return ime;
    }
    Datum DajDatumPregleda() const {
        return datum;
    }
    Vrijeme DajVrijemePregleda() const {
        return vrijeme;
    }
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2) {
        return p1.datum.Ocitaj()<p2.datum.Ocitaj();
    }
    void Ispisi() const {
        cout<<left<<setw(30)<<ime;
        datum.Ispisi();
        cout<<" ";
        vrijeme.Ispisi();
        cout<<endl;
    }
};

class Pregledi
{
    Pregled **pok;
    //Pregledi pregledi;
    int velicina,trenutna_vel;
public:
    explicit Pregledi(int max_broj_pregleda) : trenutna_vel(0),velicina(max_broj_pregleda), pok(new Pregled*[max_broj_pregleda] {}) {}

    Pregledi(std::initializer_list<Pregled> spisak_pregleda) : velicina(spisak_pregleda.size()),
        pok(new Pregled*[spisak_pregleda.size()]) {
        for(int i=0; i<spisak_pregleda.size(); i++)
            pok[i]=new Pregled(*(spisak_pregleda.begin()+i));
        int i(0);
        for(Pregled pregled : spisak_pregleda) {
            pok[i++]=new Pregled(pregled.DajImePacijenta(),pregled.DajDatumPregleda(),pregled.DajVrijemePregleda());
        }
        trenutna_vel=velicina;
    }
    ~Pregledi() {
        for(int i=0; i<velicina; i++) delete pok[i];
        delete[] pok;
    }
    Pregledi(const Pregledi &pregledi) : velicina(pregledi.velicina),pok(new Pregled*[pregledi.velicina] {}) {
        for(int i=0; i<pregledi.velicina; i++) {
            pok[i]=new Pregled(pregledi.p[i]->DajImePacijenta(),pregledi.p[i]->DajDatumPregleda(),pregledi.p[i].DajVrijemePregleda());
        }
        trenutna_vel=velicina;
    }
    Pregledi(Pregledi &&pregledi) : pok(pregledi.pok),velicina(pregledi.velicina),trenutna_vel(pregledi.trenutna_vel) {
        pregledi.pok=nullptr;
    }
    Pregledi &operator =(const Pregledi &pregledi) {
        this->~Pregledi();
        pok=new Pregled*[pregledi.velicina];
        for(int i=0; i<pregledi.velicina; i++) {
            pok[i]=nullptr;
        }
        velicina=pregledi.velicina;
        for(int i=0; i<pregledi.velicina; i++)
            pok[i]=new Pregled(pregledi.p[i]->ime,pregledi.p[i]->datum,pregledi.p[i]->vrijeme);
        trenutna_vel=velicina;
        return *this;
    }
    Pregledi &operator =(Pregledi &&pregledi) {
        this->~Pregledi();
        pok=pregledi.pok;
        velicina=pregledi.velicina;
        trenutna_vel=pregledi.trenutna_vel;
        pregledi.p=nullptr;
        return *this;
    }
    void RegistrirajPregled(const std::string &ime_pacijenta,const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) {
        if(trenutna_vel==velicina)
            throw domain_error("Dostignut maksimalni broj pregleda");
        pok[trenutna_vel++]=new Pregled(ime_pacijenta,datum_pregleda,vrijeme_pregleda);
    }
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,int mjesec_pregleda, int godina_pregleda,int sati_pregleda,
                            int minute_pregleda) {
        if(trenutna_vel==velicina)
            throw domain_error("Dostignut maksimalni broj pregleda");
        pok[trenutna_vel++]=new Pregled(ime_pacijenta,dan_pregleda,mjesec_pregleda,godina_pregleda,sati_pregleda,minute_pregleda);
    }
    void RegistrirajPregled(Pregled *pregled) {
        if(trenutna_vel==velicina)
            throw domain_error("Dostignut maksimalni broj pregleda");
        pok[trenutna_vel++]=new Pregled(pregled->DajImePacijenta(),pregled->DajDatumPregleda(),pregled->DajVrijemePregleda());
        pregled=nullptr;
    }
    int DajBrojPregleda() const {
        return trenutna_vel;
    }
    int DajBrojPregledaNaDatum(const Datum &datum) const {
        return count_if(pok,pok+trenutna_vel,[=] (Pregled *p)->bool {
            tuple<int,int,int>d1(pok->datum.Ocitaj()),d2(datum.Ocitaj());
            int dan1(get<0>(d1)),mjesec1(get<1>(d1)),godina1(get<2>(d1));
            int dan2(get<0>(d2)),mjesec2(get<1>(d2)),godina2(get<2>(d2));
            if(dan1==dan2 && mjesec1==mjesec2 && godina1==godina2) return true;
            return false;
        });
    }
    Pregled &DajNajranijiPregled() {
        if(trenutna_vel==0)
            throw domain_error("Nema registriranih pregleda");
        return min_element(this->p,this->p+trenutna_vel,[] (Pregled *p1,Pregled *p2) -> bool {
            return BrojMinuta(p1->DajDatumPregleda(),p1->DajVrijemePregleda()) < BrojMinuta(p2->DajDatumPregleda(),p2->DajVrijemePregleda());
        });
    }
    Pregled DajNajranijiPregled() const {
        if(trenutna_vel==0)
            throw domain_error("Nema registriranih pregleda");
        return *min_element(this->p,this->p+trenutna_vel,[] (Pregled *p1,Pregled *p2) -> bool {
            return BrojMinuta(p1->DajDatumPregleda(),p1->DajVrijemePregleda()) < BrojMinuta(p2->DajDatumPregleda(),p2->DajVrijemePregleda());
        });
    }
    void IsprazniKolekciju() {
        for(int i=0; i<trenutna_vel; i++) {
            delete p[i];
            p[i]=nullptr;
        }
    }
    void ObrisiNajranijiPregled() {
        if(trenutna_vel==0)
            throw range_error("Prazna kolekcija");
        Pregled pregled(this->DajNajranijiPregled());
        for(int i=0; i<trenutna_vel; i++) {
            if(p[i]->DajImePacijenta()==pregled.DajImePacijenta() &&
                    p[i]->DajDatumPregleda()==pregled.DajDatumPregleda() &&
                    p[i]->DajVrijemePregleda()==pregled.DajVrijemePregleda()) {
                for(int j=i; j<trenutna_vel-1; j++)
                    for(int k=j+1; k<trenutna_vel; k++)
                        p[j]=p[k];
                break;
            }
        }
        delete p[--trenutna_vel];
        p[trenutna_vel]=nullptr;
    }
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum(const Datum &datum) const;
    void IspisiSvePreglede() const;
};

int main ()
{
    return 0;
}
