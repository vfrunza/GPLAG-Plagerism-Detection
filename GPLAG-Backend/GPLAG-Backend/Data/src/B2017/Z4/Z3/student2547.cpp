#include <algorithm>
#include <iostream>
#include <tuple>
#include <string>
#include <stdexcept>
#include <iomanip>

using namespace std;

class Datum {
    int d,m,g;
    bool Prestupna(int g) {
        if(g%4!=0) return false;
        if(g%4==0 && g%100==0 && g%400!=0) return false;
        return true;
    }
    void JeLiIspravan(int d, int m, int g) {
        if(d<1 || m<1 || m>12 || g<1) throw domain_error("Neispravan datum");
        if((m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12) && d>31) throw domain_error("Neispravan datum");
        if((m==4 || m==6 || m==9 || m==11) && d>30) throw domain_error("Neispravan datum");
        if(m==2 && d>28 && Prestupna(g)==0) throw domain_error("Neispravan datum");
        if(m==2 && d>29 && Prestupna(g)==1) throw domain_error("Neispravan datum");
    }
    public:
    Datum(int dan, int mjesec, int godina) {
        JeLiIspravan(dan,mjesec,godina);
        d=dan; m=mjesec; g=godina;
    }
    void Postavi(int dan, int mjesec, int godina) {
        JeLiIspravan(dan,mjesec,godina);
        d=dan; m=mjesec; g=godina;
    }
    tuple<int, int, int> Ocitaj() const {
        return (tuple<int, int, int> (d,m,g));
    }
    void Ispisi() const {
        cout << d << "/" << m << "/" << g << endl;
    }
};

class Vrijeme {
    int h,m;
    void JeLiIspravno(int sat, int min) {
        if(sat>23 || min>59) throw domain_error("Neispravno vrijeme");
    }
    public:
    Vrijeme(int sati, int minute) {
        JeLiIspravno(sati, minute);
        h=sati; m=minute;
    }
    void Postavi(int sati, int minute) {
        h=sati; m=minute;
    }
    pair<int, int> Ocitaj () const {
        return (pair<int, int>(h,m));
    }
    void Ispisi() const {
        cout << setw(2) << setfill('0') << h << ":" << m << endl;
    }
};

class Pregled {
    string ime;
    Datum dat;
    Vrijeme v;
    public:
    Pregled(const string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) : dat(datum_pregleda), v(vrijeme_pregleda) {
        ime=ime_pacijenta; dat=datum_pregleda; v=vrijeme_pregleda;
    } 
    Pregled(const string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) {
        ime=ime_pacijenta; dat.Postavi(dan_pregleda,mjesec_pregleda,godina_pregleda); v.Postavi(sati_pregleda,minute_pregleda);
    }
    void PromijeniPacijenta(const string &ime_pacijenta) {
        ime=ime_pacijenta;
    }
    void PromijeniDatum(const Datum &novi_datum) {
        dat=novi_datum;
    }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme) {
        v=novo_vrijeme;
    }
    void PomjeriDanUnaprijed() {
        tuple<int,int,int> trenutni_datum(dat.Ocitaj());
        dat.Postavi(get<0>(trenutni_datum)+1,get<1>(trenutni_datum),get<2>(trenutni_datum));
    }
    void PomjeriDanUnazad() {
        tuple<int,int,int> trenutni_datum(dat.Ocitaj());
        dat.Postavi(get<0>(trenutni_datum)-1,get<1>(trenutni_datum),get<2>(trenutni_datum));
    } 
    string DajImePacijenta() const {
        return ime;
    }
    Datum DajDatumPregleda() const {
        return dat;
    }
    Vrijeme DajVrijemePregleda() const {
        return v;
    }
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2) {
        tuple<int,int,int> date1(p1.dat.Ocitaj()), date2(p2.dat.Ocitaj());
        pair<int,int> time1(p1.v.Ocitaj()), time2(p2.v.Ocitaj());
        if(get<2>(date1)==get<2>(date2)) {
            if(get<1>(date1)==get<1>(date2)) {
                if(get<0>(date1)==get<0>(date2)) {
                    if(get<1>(time1)==get<1>(time2)) {
                        if(get<0>(time1)<get<0>(time2)) return true;
                    }
                    else if(get<1>(time1)<get<1>(time2)) return true;
                }
                else if(get<0>(date1)<get<0>(date2)) return true;
            }
            else if(get<1>(date1)<get<1>(date2)) return true;
        }
        else if(get<2>(date1)<get<2>(date2)) return true;
        return false;
    }
    void Ispisi() const {
        cout << setw(30) << left << ime;
        cout << " Datum: "; dat.Ispisi();
        cout << " Vrijeme: "; v.Ispisi();
    }
};

class Pregledi {
    int velicina;
    Pregled **svi_pr;
    public:
    explicit Pregledi(int max_broj_pregleda) : svi_pr(new Pregled*[max_broj_pregleda]), velicina(max_broj_pregleda) {
        fill(svi_pr[0], svi_pr[max_broj_pregleda], nullptr);
    }
    Pregledi(initializer_list<Pregled> spisak_pregleda) : velicina(spisak_pregleda.size()), svi_pr(new Pregled*[spisak_pregleda.size()]) {
        initializer_list::iterator pom(spisak_pregleda.begin());
        for(int i=0;i<spisak_pregleda.size();i++) {
            svi_pr[i]=new Pregled();
            *svi_pr[i]=*pom;
            pom++;
        }
    }
    ~Pregledi() {
        for(int i=0;i<velicina;i++) {
            delete svi_pr[i];
        }
        delete [] svi_pr;
    }
    Pregledi(const Pregledi &pregledi) : velicina(pregledi.velicina) {
        svi_pr=new Pregled*[velicina];
        for(int i=0;i<pregledi.velicina;i++) {
            svi_pr[i]=new Pregled(*(pregledi.svi_pr)[i]);
        }
    }
    Pregledi(Pregledi &&pregledi);  
    Pregledi &operator =(const Pregledi &pregledi); 
    Pregledi &operator =(Pregledi &&pregledi);
    void RegistrirajPregled(const string &ime_pacijenta,  
    const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);  
    void RegistrirajPregled(const string &ime_pacijenta, int dan_pregleda, 
    int mjesec_pregleda, int godina_pregleda, int sati_pregleda, 
    int minute_pregleda); 
    void RegistrirajPregled(Pregled *pregled);
    int DajBrojPregleda() const;
    int DajBrojPregledaNaDatum(const Datum &datum) const; 
    Pregled &DajNajranijiPregled(); 
    Pregled DajNajranijiPregled() const;
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta(const string &ime_pacijenta); 
    void IspisiPregledeNaDatum(const Datum &datum) const;
    void IspisiSvePreglede() const; 
};

void Unos(int &x) {
    int u;
    cout << "Odaberite jednu od sljedecih opcija" << endl;
    cout << "1 - Broj pregleda na datum" << endl;
    cout << "2 - Najraniji pregled" << endl;
    cout << "3 - Obrisi pregled pacijenta" << endl;
    cout << "4 - Obrisi najraniji pregled" << endl;
    cout << "5 - Ispisi sve pregleda na datum" << endl;
    cout << "6 - Ispisi sve preglede" << endl;
    cout << "7 - Kraj programa" << endl;
    cin >> u;
    x=u;
}

int main () {
    int x;
    Unos(&x);
    switch(x) {
        case 1: {
            
        }
        case 2: {
            
        }
        case 3: {
            
        }
        case 4: {
            
        }
        case 5: {
        }
        case 6: {
            
        }
        case 7: return 0;
        default: 
    }
	return 0;
}