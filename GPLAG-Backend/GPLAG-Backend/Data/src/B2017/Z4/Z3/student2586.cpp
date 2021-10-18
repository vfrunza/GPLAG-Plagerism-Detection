/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <tuple>
#include <string>

class Datum
{
    int dan,mjesec,godina;
public:
    Datum(int dan, int mjesec, int godina) {
        Postavi(dan,mjesec,godina);
    }
    void Postavi(int dan, int mjesec, int godina) ;

    std::tuple<int, int, int> Ocitaj() const {
        std::tuple<int, int, int> vrati;
        std::get<0>(vrati)=dan;
        std::get<1>(vrati)=mjesec;
        std::get<2>(vrati)=godina;
        return vrati;
    }
    void Ispisi() const {
        std::cout << dan <<"/"<< mjesec <<"/"<< godina;
    }
};
void Datum::Postavi(int dan, int mjesec, int godina)
{
    int brojdana[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina % 4 == 0 and godina % 100 != 0) or godina % 400 == 0) brojdana[1]++;
    int brdana(brojdana[mjesec-1]);
    if(godina < 1 or dan < 1 or mjesec < 1 or mjesec > 12 or dan>brdana)  throw std::domain_error("Neispravan datum");
    Datum::dan=dan;
    Datum::mjesec=mjesec;
    Datum::godina=godina;
}
bool DaLiJeIspravno(int sat,int min)
{
    if(!(sat>=0 and sat<=23 and min>=0 and min<=59 )) return false;
    return true;
}
class Vrijeme
{
    int sati,minute;
public:

    Vrijeme(int sati, int minute) {
        Postavi(sati,minute);
    }
    void Postavi(int sati, int minute) {
        if(!DaLiJeIspravno(sati, minute))  throw std::domain_error("Neispravno vrijeme");
        Vrijeme::sati=sati;
        Vrijeme::minute=minute;
    }
    std::pair<int, int> Ocitaj () const {
        std::pair<int, int> par;
        par.first=sati;
        par.second=minute;
        return par;
    }
    void Ispisi() const {
        std::cout << std::fixed<< std::setw(2) <<std::right<<std::setfill('0')<< sati <<":"<<std::setw(2)<<std::setfill('0')<<std::right<< minute;
    }
};
class Pregled
{
    std::string ime_pacijenta;
    Datum datum;
    Vrijeme vrijeme;

public:
    friend class Datum;
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda):ime_pacijenta(ime_pacijenta),
        datum(datum_pregleda),vrijeme(vrijeme_pregleda) { }
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,
            int godina_pregleda, int sati_pregleda, int minute_pregleda):ime_pacijenta(ime_pacijenta),datum(dan_pregleda,mjesec_pregleda,godina_pregleda),
        vrijeme(sati_pregleda,minute_pregleda) {}
    void PromijeniPacijenta(const std::string &ime_pacijenta) {
        Pregled::ime_pacijenta=ime_pacijenta;
    }
    void PromijeniDatum(const Datum &novi_datum) {
        Pregled::datum=novi_datum;
    }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme) {
        Pregled::vrijeme=novo_vrijeme;
    }
    void PomjeriDanUnazad() {
        auto danunazad(datum.Ocitaj());
        int brojdana[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if((std::get<2>(danunazad) % 4 == 0 and std::get<2>(danunazad) % 100 != 0) or std::get<2>(danunazad) % 400 == 0) brojdana[1]++;
        int brdana(brojdana[std::get<1>(danunazad)-1]);
        if(std::get<0>(danunazad) <= 0) {
            std::get<0>(danunazad)= brdana;
            std::get<1>(danunazad)= std::get<1>(danunazad)-1;
        }
        if( std::get<1>(danunazad) < 1) {
            std::get<1>(danunazad) = 12;
            std::get<2>(danunazad)-=1;
        }
    }
    void PomjeriDanUnaprijed() {
        auto danunaprijed(datum.Ocitaj());
        int brojdana[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if((std::get<2>(danunaprijed) % 4 == 0 and std::get<2>(danunaprijed) % 100 != 0 ) or std::get<2>(danunaprijed) % 400 == 0) brojdana[1]++;
        int brdana(brojdana[std::get<1>(danunaprijed)-1]);
        if(std::get<0>(danunaprijed) > brdana) {
            std::get<0>(danunaprijed)= 1;
            std::get<1>(danunaprijed)= std::get<1>(danunaprijed)+1;
        }
        if( std::get<1>(danunaprijed) > 12) {
            std::get<1>(danunaprijed) = 1;
            std::get<2>(danunaprijed)+=1;
        }
    }

    std::string DajImePacijenta() const {
        return ime_pacijenta;
    }
    Datum DajDatumPregleda() const {
        return datum;
    }
    Vrijeme DajVrijemePregleda() const {
        return vrijeme;
    }
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2) {
        Datum d1=p1.DajDatumPregleda();
        Vrijeme v1=p1.DajVrijemePregleda();
        Datum d2=p2.DajDatumPregleda();
        Vrijeme v2= p2.DajVrijemePregleda();
        std::tuple<int,int,int> ocitanidat1(d1.Ocitaj());
        int dan1,m1,g1;
        dan1=std::get<0>(ocitanidat1);
        m1=std::get<1>(ocitanidat1);
        g1=std::get<2>(ocitanidat1);
        std::pair<int, int> ocitanovrijeme1(v1.Ocitaj());
        int s1,min1;
        s1=ocitanovrijeme1.first;
        min1=ocitanovrijeme1.second;
        std::tuple<int,int,int> ocitanidat2(d2.Ocitaj());
        int dan2,m2,g2;
        dan2=std::get<0>(ocitanidat2);
        m2=std::get<1>(ocitanidat2);
        g2=std::get<2>(ocitanidat2);
        std::pair<int, int> ocitanovrijeme2(v2.Ocitaj());
        int s2,min2;
        s2=ocitanovrijeme2.first;
        min2=ocitanovrijeme2.second;
        if(g1<g2) return true;
        else if(g1==g2) {
            if(m1<m2) return true;
            else if(m1==m2) {
                if(dan1<dan2) return true;
                else if(dan1==dan2) {
                    if(s1<s2) return true;
                    else if(s1==s2) {
                        if(min1<min2) return true;
                        else return false;
                    } else return false;
                } else return false;
            } else  return false;
        } else return false;
    }
    void Ispisi() const {
        std::cout << std::fixed <<std::left<< std::setw(30) <<std::setfill(' ')<< ime_pacijenta ;
        DajDatumPregleda().Ispisi();
        std::cout << " ";
        DajVrijemePregleda().Ispisi();
        std::cout  << std::endl;
    }
};

bool DolaziPrijepom(const Pregled &p1, const Pregled &p2)
{
    Datum d1=p1.DajDatumPregleda();
    Vrijeme v1=p1.DajVrijemePregleda();
    Datum d2=p2.DajDatumPregleda();
    Vrijeme v2= p2.DajVrijemePregleda();
    std::tuple<int,int,int> ocitanidat1(d1.Ocitaj());
    int dan1,m1,g1;
    dan1=std::get<0>(ocitanidat1);
    m1=std::get<1>(ocitanidat1);
    g1=std::get<2>(ocitanidat1);
    std::pair<int, int> ocitanovrijeme1(v1.Ocitaj());
    int s1,min1;
    s1=ocitanovrijeme1.first;
    min1=ocitanovrijeme1.second;
    std::tuple<int,int,int> ocitanidat2(d2.Ocitaj());
    int dan2,m2,g2;
    dan2=std::get<0>(ocitanidat2);
    m2=std::get<1>(ocitanidat2);
    g2=std::get<2>(ocitanidat2);
    std::pair<int, int> ocitanovrijeme2(v2.Ocitaj());
    int s2,min2;
    s2=ocitanovrijeme2.first;
    min2=ocitanovrijeme2.second;
    if(g1<g2) return true;
    else if(g1==g2) {
        if(m1<m2) return true;
        else if(m1==m2) {
            if(dan1<dan2) return true;
            else if(dan1==dan2) {
                if(s1<s2) return true;
                else if(s1==s2) {
                    if(min1<min2) return true;
                    else return false;
                } else return false;
            } else return false;
        } else  return false;
    } else return false;
}
class Pregledi
{
    int broj;
    const int maxbroj;
    Pregled** pregledi;
public:
    explicit Pregledi(int max_broj_pregleda) : broj(0), maxbroj(max_broj_pregleda),pregledi(new Pregled*[max_broj_pregleda] {}) { }
    Pregledi(std::initializer_list<Pregled> spisak_pregleda): broj(spisak_pregleda.size()), maxbroj(spisak_pregleda.size()),
        pregledi(new Pregled*[spisak_pregleda.size()] {}) {
        int i(0);
        for(auto it(spisak_pregleda.begin()); it<spisak_pregleda.end(); it++) {
            pregledi[i]=new Pregled(Pregled(*it));
            i++;
        }
    }
    ~Pregledi() {
        for(int i(0); i<broj; i++) delete pregledi[i];
        delete [] pregledi;
    }
    Pregledi(const Pregledi &pregl): pregledi(new Pregled*[pregl.broj] {}),maxbroj(pregl.maxbroj) {
        try {
            for(int i(0); i<pregl.broj; i++) {
                pregledi[i]=new Pregled(*pregl.pregledi[i]);
            }
        } catch(std::bad_alloc) {
            for(int i(0); i<pregl.broj; i++)
                delete pregledi[i];
            delete[] pregledi;
            throw;
        }
    }
    Pregledi(Pregledi &&pregl): broj(pregl.broj),pregledi(pregl.pregledi),maxbroj(pregl.maxbroj) {
        pregl.pregledi=nullptr;
        pregl.broj=0;
    }
    Pregledi &operator =(const Pregledi &pregl) {
        if(pregl.maxbroj!=maxbroj) throw std::domain_error("Nesaglasni kapaciteti liga");
        if(&pregl!=this) {
            if(pregl.broj>broj) {
                try {
                    for(int i(broj); i<pregl.broj; i++) {
                        pregledi[i]=new Pregled(*pregl.pregledi[i]);
                    }
                } catch(std::bad_alloc) {
                    for(int i(broj); i<pregl.broj; i++) {
                        delete pregledi[i];
                        pregledi[i]=nullptr;
                    }
                    throw;
                }
            }  else {
                for(int i(broj); i<pregl.broj; i++) {
                    delete pregledi[i];
                    pregledi[i]=nullptr;
                }
            }
        }
        broj=pregl.broj;
        for(int i(0); i<pregl.broj; i++)
            *pregledi[i]=*(pregl.pregledi[i]);
        return *this;
    }
    Pregledi &operator =(Pregledi &&pregl) {
        if(pregl.maxbroj!=maxbroj) throw std::domain_error("Nesaglasni kapaciteti liga");
        if(&pregl!=this) {
            std::swap(broj,pregl.broj);
            std::swap(pregledi,pregl.pregledi);
        }
        return *this;
    }
    void RegistrirajPregled(const std::string &ime_pacijenta,const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) {
        if(maxbroj<=broj) throw std::range_error("Dostignut maksimalni broj pregleda");
        pregledi[broj]=new Pregled(Pregled(ime_pacijenta,datum_pregleda,vrijeme_pregleda));
        broj++;
    }
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,int mjesec_pregleda, int godina_pregleda, int sati_pregleda,int minute_pregleda) {
        if(maxbroj<=broj) throw std::range_error("Dostignut maksimalni broj pregleda");
        pregledi[broj]=new Pregled(Pregled(ime_pacijenta,dan_pregleda,mjesec_pregleda,godina_pregleda,sati_pregleda,minute_pregleda));
        broj++;
    }
    void RegistrirajPregled(Pregled *pregled) {
        if(maxbroj<=broj) throw std::range_error("Dostignut maksimalni broj pregleda");
        pregledi[broj]=new Pregled(Pregled(pregled->DajImePacijenta(),pregled->DajDatumPregleda(),pregled->DajVrijemePregleda()));
    }
    int DajBrojPregleda() const {
        return broj;
    }
    int DajBrojPregledaNaDatum(const Datum &dat) const {
        std::tuple<int,int,int> ocitanidat(dat.Ocitaj());
        int d,m,g;
        d=std::get<0>(ocitanidat);
        m=std::get<1>(ocitanidat);
        g=std::get<2>(ocitanidat);
        int brojac(
        std::count_if(pregledi,pregledi+broj,[=](Pregled* pomdat) {
            std::tuple<int,int,int> ocitaj(pomdat->DajDatumPregleda().Ocitaj());
            int d1,m1,g1;
            d1=std::get<0>(ocitaj);
            m1=std::get<1>(ocitaj);
            g1=std::get<2>(ocitaj);
            if(d1==d and m1==m and g1==g)return true;
            return false;
        }));
        return brojac;
    }
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const {
        if(broj==0) throw std::domain_error("Nema registriranih pregleda");
        Pregled** najranijipregled(std::min_element(pregledi,pregledi+broj,[](Pregled* pomdat1,Pregled* pomdat2) {
            return DolaziPrijepom(*pomdat1,*pomdat2);
        }));
        return **najranijipregled;
    }
    void IsprazniKolekciju() {
        for(int i(0); i<broj; i++) delete pregledi[i];
        delete [] pregledi;
        broj=0;
    }
    void ObrisiNajranijiPregled() {
        if(broj==0) throw std::range_error ("Prazna kolekcija");
        auto najranijipregled(DajNajranijiPregled());
        Datum dat(najranijipregled.DajDatumPregleda());
        std::tuple<int,int,int> ocitanidat(dat.Ocitaj());
        int d,m,g;
        d=std::get<0>(ocitanidat);
        m=std::get<1>(ocitanidat);
        g=std::get<2>(ocitanidat);
        Vrijeme vri(najranijipregled.DajVrijemePregleda());
        std::pair<int, int> ocitanovrijeme(vri.Ocitaj());
        int s,min;
        s=ocitanovrijeme.first;
        min=ocitanovrijeme.second;
        for(int i(0); i<broj; i++) {
            auto najranijipregled1(*pregledi[i]);
            Datum dat1(najranijipregled1.DajDatumPregleda());
            std::tuple<int,int,int> ocitanidat1(dat1.Ocitaj());
            int d1,m1,g1;
            d1=std::get<0>(ocitanidat1);
            m1=std::get<1>(ocitanidat1);
            g1=std::get<2>(ocitanidat1);
            Vrijeme vri1(najranijipregled1.DajVrijemePregleda());
            std::pair<int, int> ocitanovrijeme1(vri1.Ocitaj());
            int s1,min1;
            s1=ocitanovrijeme1.first;
            min1=ocitanovrijeme1.second;
            if(d==d1 and m==m1 and g==g1 and s==s1 and min==min1) {
                delete pregledi[i];
                pregledi[i]=nullptr;
                for(int j(i); j<broj-1; j++) {
                    pregledi[j]=pregledi[j+1];
                }
                pregledi[broj-1]=nullptr;
                broj--;
                break;
            }
        }
    }
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta) {
        for(int i(0); i<broj; i++) {
            std::string ime(pregledi[i]->DajImePacijenta());
            if(ime==ime_pacijenta) {
                delete pregledi[i];
                pregledi[i]=nullptr;
                for(int j(i); j<broj-1; j++) {
                    pregledi[j]=pregledi[j+1];
                }
                pregledi[broj-1]=nullptr;
                broj--;
            }
        }
    }
    void IspisiPregledeNaDatum(const Datum &datum) const {
        std::tuple<int,int,int> ocitanidat(datum.Ocitaj());
        int d,m,g;
        d=std::get<0>(ocitanidat);
        m=std::get<1>(ocitanidat);
        g=std::get<2>(ocitanidat);
        std::sort(pregledi,pregledi+broj,[=](Pregled *pom1,Pregled *pom2) {
            return DolaziPrijepom(*pom1,*pom2);
        });
        std::for_each(pregledi,pregledi+broj,[=](Pregled *pom) {
            std::tuple<int,int,int> ocitaj(pom->DajDatumPregleda().Ocitaj());
            int d1,m1,g1;
            d1=std::get<0>(ocitaj);
            m1=std::get<1>(ocitaj);
            g1=std::get<2>(ocitaj);
            if(d1==d and m1==m and g1==g)pom->Ispisi();
        });
    }
    void IspisiSvePreglede() const {
        std::sort(pregledi,pregledi+broj,[=](Pregled *pom1,Pregled *pom2) {
            return DolaziPrijepom(*pom1,*pom2);
        });
        std::for_each(pregledi,pregledi+broj,[=](Pregled *pom) {
            pom->Ispisi();
        });
    }
};
Pregled &Pregledi::DajNajranijiPregled()
{
    if(broj==0) throw std::domain_error("Nema registriranih pregleda");
    Pregled** najranijipregled(std::min_element(pregledi,pregledi+broj,[](Pregled* pomdat1,Pregled* pomdat2) {
        return DolaziPrijepom(*pomdat1,*pomdat2);
    }));
    return **najranijipregled;
}
int main ()
{
    /**/
    int maxbroj;
    std::cout << "Unesite maksimalan broj pregleda: ";
    std::cin >> maxbroj;
    Pregledi pregledi(maxbroj);
    int br(0);
    while(br<maxbroj) {
        std::cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: " ;
        std:: string ime;
        std::cin >> ime;
        br++;
        if(ime=="kraj") break;
        std::cout << "Unesite dan mjesec i godinu pregleda: ";
        int dan,mjesec,godina;
        std::cin >> dan>>mjesec>>godina;
        std::cout << "Unesite sate i minute pregleda: ";
        int sat,minute;
        std::cin >> sat>>minute;
        pregledi.RegistrirajPregled(ime,dan,mjesec,godina,sat,minute);
    }
    std::cout << "Trenutno su registrovani sljedeci pregledi" << std::endl;

    pregledi.IspisiSvePreglede();

    std::cout<<std::endl << "Odaberite jednu od sljedecih opcija"<<std::endl<< "1 - Broj pregleda na datum"<<std::endl<< "2 - Najraniji pregled"<<std::endl<<
              "3 - Obrisi pregled pacijenta"<<std::endl<< "4 - Obrisi najraniji pregled"<<std::endl<< "5 - Ispisi sve pregleda na datum"<<
              std::endl<< "6 - Ispisi sve preglede"<<std::endl<< "7 - Kraj programa" << std::endl;
    int x;
    std::cin >> x;
    while(x!=7) {
        if(x==1) {
            std::cout << "Unesite dan mjesec i godinu : ";
            int dan,mjesec,godina;
            std::cin >> dan>>mjesec>>godina;
            try {
                Datum datum(dan, mjesec, godina);
                int broj_pregleda_na_datum = pregledi.DajBrojPregledaNaDatum(datum);
                std::cout << "Broj pregleda na datum " << dan << " " << mjesec << " " << godina << " je: " << broj_pregleda_na_datum <<std::endl;
            } catch(std::domain_error izuzetak) {
                std::cout << izuzetak.what();
            }
        }
        else if(x==2) {
            try {
                std::cout << "Najraniji pregled je:" << std::endl;
                pregledi.DajNajranijiPregled().Ispisi();
            } catch (std::domain_error poruka) {
                std::cout << poruka.what()<< std::endl;
            }
        }
        else if(x==3){
            std::cout << "Unesite ime pacijenta: ";
            std::string ime;
            std::cin >> ime;
            int brojprije=pregledi.DajBrojPregleda();
            pregledi.ObrisiPregledePacijenta(ime);
            int brojposlije=pregledi.DajBrojPregleda();
            std::cout << "Uspjesno obrisano "<< brojprije-brojposlije<<" pregleda" << std::endl;
        }
        else if(x==4) {
            try {
                pregledi.ObrisiNajranijiPregled();
                std::cout << "Najraniji pregled uspjesno obrisan" << std::endl;
            } catch(std::range_error izuzetak) {
                std::cout << izuzetak.what();
            }
        }
        else if(x==5) {
            std::cout << "Unesite dan mjesec i godinu : ";
            int dan,mjesec,godina;
            std::cin >> dan>>mjesec>>godina;
            try {
                Datum datum(dan, mjesec, godina);
                std::cout << "Pregledi na datum " << dan << " " << mjesec << " " << godina << " su: "<<std::endl;
                pregledi.IspisiPregledeNaDatum(datum);
            } catch(std::domain_error izuzetak) {
                std::cout << izuzetak.what();
            }
        }
        else if(x==6){
            pregledi.IspisiSvePreglede();
        }
        std::cin >> x;
         std::cout << std::endl<<"Odaberite jednu od sljedecih opcija"<<std::endl<< "1 - Broj pregleda na datum"<<std::endl<< "2 - Najraniji pregled"<<std::endl<<
              "3 - Obrisi pregled pacijenta"<<std::endl<< "4 - Obrisi najraniji pregled"<<std::endl<< "5 - Ispisi sve pregleda na datum"<<
              std::endl<< "6 - Ispisi sve preglede"<<std::endl<< "7 - Kraj programa" << std::endl;
    }

    return 0;
}
