/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <tuple>
#include <iomanip>
#include <algorithm>

using namespace std;

class Datum
{
    int d,m,g;
public:
    Datum(int dan, int mjesec, int godina) {
        Postavi(dan,mjesec,godina);
    }
    void Postavi(int dan, int mjesec, int godina);
    std::tuple<int, int, int> Ocitaj() const {
        return make_tuple(d,m,g);
    }
    void Ispisi() const {
        cout<<d<<"/"<<m<<"/"<<g;
    }
};

void Datum::Postavi(int dan, int mjesec, int godina)
{
    int broj_dana[12] {31,28,31,30,31,30,31,31,30,31,30,31};
    if( (godina%4==0 && godina%100 !=0 )|| godina%400==0) broj_dana[1]++;
    if( godina <1 or dan <1 or mjesec <1 or mjesec >12 || dan > broj_dana[mjesec-1])
        throw std::domain_error("Neispravan datum");
    d=dan;
    m=mjesec;
    g=godina;
}

class Vrijeme
{
    int h,m;

public:
    Vrijeme(int sati, int minute) {
        Postavi(sati,minute);
    }
    void Postavi(int sati, int minute);
    std::pair<int, int> Ocitaj () const {
        return make_pair(h,m);
    }
    void Ispisi() const {
        cout<<setw(2)<<std::right<<setfill('0')<<h;
        cout<<":";
        cout<<setw(2)<<m;
        cout<<setfill(' ');
    }

};

void Vrijeme::Postavi(int sati, int minute)
{
    if(sati<0 or sati>23 || minute<0 || minute >59)
        throw std::domain_error("Neispravno vrijeme");
    h=sati;
    m=minute;

}


class Pregled
{
    string ime_pac;
    Datum dat;
    Vrijeme vr;

public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda,
            const Vrijeme &vrijeme_pregleda): ime_pac(ime_pacijenta), dat(datum_pregleda), vr(vrijeme_pregleda) {};
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,
            int godina_pregleda, int sati_pregleda, int minute_pregleda): ime_pac(ime_pacijenta), dat(dan_pregleda,mjesec_pregleda,godina_pregleda), vr(sati_pregleda,minute_pregleda) {};
    void PromijeniPacijenta(const std::string &ime_pacijenta) {
        ime_pac=ime_pacijenta;
    }
    void PromijeniDatum(const Datum &novi_datum) {
        dat=novi_datum;
    }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme) {
        vr=novo_vrijeme;
    }
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImePacijenta() const {
        return ime_pac;
    }
    Datum DajDatumPregleda() const {
        return dat;
    }
    Vrijeme DajVrijemePregleda() const {
        return vr;
    }
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
    void Ispisi() const;

};

bool Pregled::DolaziPrije(const Pregled &p1, const Pregled &p2)
{
    auto tr1 = p1.DajDatumPregleda().Ocitaj();
    auto tr2 = p2.DajDatumPregleda().Ocitaj();
    int d1=get<0>(tr1), m1 = get<1>(tr1), g1=get<2>(tr1);
    int d2=get<0>(tr2), m2=get<1>(tr2), g2 = get<2>(tr2);

    if(g1<g2) return true;
    else if (g1>g2) return false;
    else if (g1==g2) {
        if(m1<m2) return true;
        else if(m1>m2) return false;
        else if (m1==m2) {
            if(d1<d2) return true;
            else if(d1>d2) return false;
            else if (d1==d2) {
                auto v1 = p1.DajVrijemePregleda().Ocitaj();
                auto v2 = p2.DajVrijemePregleda().Ocitaj();

                int s1 = v1.first, m1=v1.second;
                int s2 = v2.first, m2=v2.second;

                if(s1<s2) return true;
                else if(s1>s2) return false;
                else if(s1==s2) {
                    if(m1<m2) return true;
                    else return false;
                }
            }
        }

    }
    return false; //da utisamo kompajler za upozorenja
}

void Pregled::Ispisi() const
{
    cout<<left<<setw(30)<<ime_pac;
    dat.Ispisi();
    cout<<" ";
    vr.Ispisi();
    cout<<endl;
}


void Pregled::PomjeriDanUnaprijed()
{
    int broj_dana[12] {31,28,31,30,31,30,31,31,30,31,30,31};
    auto trojka = dat.Ocitaj();

    int dan = std::get<0>(trojka);
    int mjesec = std::get<1>(trojka);
    int godina = std::get<2>(trojka);
    if( (godina%4==0 && godina%100 !=0 )|| godina%400==0) broj_dana[1]++;


    dan++;
    if(dan> broj_dana[mjesec-1]) {
        dan=1;
        mjesec++;
        if(mjesec>12) {
            mjesec=1;
            godina++;

        }
    }
    dat=Datum(dan,mjesec,godina);

}

void Pregled::PomjeriDanUnazad()
{
    int broj_dana[12] {31,28,31,30,31,30,31,31,30,31,30,31};
    auto trojka = dat.Ocitaj();

    int dan = std::get<0>(trojka);
    int mjesec = std::get<1>(trojka);
    int godina = std::get<2>(trojka);

    if( (godina%4==0 && godina%100 !=0 )|| godina%400==0) broj_dana[1]++;

    dan--;
    if(dan==0) {
        if(mjesec==1) {
            mjesec=12;
            godina--;
        }

        dan=broj_dana[mjesec-1];

    }

    dat=Datum(dan,mjesec,godina);
}



class Pregledi
{
    Pregled** aktivni_pregledi;
    int maks_pregleda, br_pregleda;


    void obrisiOstatke(int i) {
        for(int j=0; j<i; j++) delete aktivni_pregledi[j];
        delete[] aktivni_pregledi;
        br_pregleda=0;
        maks_pregleda=0;
        throw;
    }

    void ObrisiPregled(int indeks) {
        //stavimo na kraj obrisani
        auto pomocni = aktivni_pregledi[br_pregleda-1];
        aktivni_pregledi[br_pregleda-1]=aktivni_pregledi[indeks];
        aktivni_pregledi[indeks]=pomocni;
        //obrisemo ga na kraju
        delete aktivni_pregledi[br_pregleda-1];
        br_pregleda--;
    }

public:
    explicit Pregledi(int max_broj_pregleda);
    Pregledi(std::initializer_list<Pregled> spisak_pregleda);
    ~Pregledi() {
        IsprazniKolekciju();
    }
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


    int DajBrojPregleda() const {
        return br_pregleda;
    }
    int DajBrojPregledaNaDatum(const Datum &datum) const;
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum(const Datum &datum) const;
    void IspisiSvePreglede() const;

};

void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const
{
    for_each(aktivni_pregledi,aktivni_pregledi+br_pregleda,[&datum](Pregled* pok) {
        Datum dat = pok->DajDatumPregleda();
        if(get<0>(datum.Ocitaj()) == get<0>(dat.Ocitaj()) && get<1>(datum.Ocitaj()) == get<1>(datum.Ocitaj()) && get<2>(datum.Ocitaj()) == get<2>(datum.Ocitaj()))
            pok->Ispisi();
    });
}

void Pregledi::IspisiSvePreglede() const
{
    for_each(aktivni_pregledi,aktivni_pregledi+br_pregleda,[](Pregled* pok) {
        pok->Ispisi();
    });
}


void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta)
{

    for(int i=0; i<br_pregleda; i++){
        string imence = aktivni_pregledi[i]->DajImePacijenta();
        if(imence==ime_pacijenta){
            this->ObrisiPregled(i);
            i--; //jer smo sad na njegovo mjesto nakon brisanja stavili posljednji
        }
    }
    
    sort(aktivni_pregledi,aktivni_pregledi+br_pregleda,[](Pregled* pok1, Pregled* pok2){
        return Pregled::DolaziPrije(*pok1,*pok2);
    });
    
}



void Pregledi::ObrisiNajranijiPregled()
{
    if(br_pregleda==0) throw range_error("Prazna kolekcija");

    //pronadjemo ga pomocu algoritamske funkcije
    int indeks_najmanjeg(0);
    for(int i=1; i<br_pregleda; i++){
        if(Pregled::DolaziPrije(*aktivni_pregledi[i],*aktivni_pregledi[indeks_najmanjeg]))
            indeks_najmanjeg=i;
    }

    ObrisiPregled(indeks_najmanjeg);
    sort(aktivni_pregledi,aktivni_pregledi+br_pregleda,[](Pregled* pok1, Pregled* pok2){
        return Pregled::DolaziPrije(*pok1,*pok2);
    });

}

void Pregledi::IsprazniKolekciju()
{
    for(int i=0; i<br_pregleda; i++) {
        delete aktivni_pregledi[i];
    }
    delete[] aktivni_pregledi;
    br_pregleda=0;
}


Pregled& Pregledi::DajNajranijiPregled()
{
    if(br_pregleda==0) throw domain_error("Nema registriranih pregleda");
    return **min_element(aktivni_pregledi,aktivni_pregledi+br_pregleda,[](Pregled* pok1, Pregled* pok2) {
        return Pregled::DolaziPrije(*pok1,*pok2);
    });
}

Pregled Pregledi::DajNajranijiPregled() const
{
    if(br_pregleda==0) throw domain_error("Nema registriranih pregleda");
    return **min_element(aktivni_pregledi,aktivni_pregledi+br_pregleda,[](Pregled* pok1, Pregled* pok2) {
        return Pregled::DolaziPrije(*pok1,*pok2);
    });
}


int Pregledi::DajBrojPregledaNaDatum(const Datum& datum) const
{
    return count_if(aktivni_pregledi,aktivni_pregledi+br_pregleda, [&datum](Pregled* pok) {
        Datum dat = pok->DajDatumPregleda();
        return get<0>(datum.Ocitaj()) == get<0>(dat.Ocitaj()) && get<1>(dat.Ocitaj()) == get<1>(datum.Ocitaj()) && get<2>(dat.Ocitaj()) == get<2>(datum.Ocitaj());
    });
}



void Pregledi::RegistrirajPregled(Pregled *pregled)
{
    if(maks_pregleda==br_pregleda) throw std::range_error("Dostignut maksimalan broj pregleda");
    aktivni_pregledi[br_pregleda] = pregled;
    br_pregleda++;
    sort(aktivni_pregledi,aktivni_pregledi+br_pregleda,[](Pregled* pok1, Pregled* pok2) {
        return Pregled::DolaziPrije(*pok1,*pok2);
    });
}


void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,int mjesec_pregleda, int godina_pregleda, int sati_pregleda,int minute_pregleda)
{
    Datum dat(dan_pregleda,mjesec_pregleda,godina_pregleda);
    Vrijeme vr(sati_pregleda,minute_pregleda);

    RegistrirajPregled(ime_pacijenta,dat,vr);

}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta,const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda)
{

    if(maks_pregleda==br_pregleda) throw std::range_error("Dostignut maksimalan broj pregleda");
    aktivni_pregledi[br_pregleda]=new Pregled(ime_pacijenta,datum_pregleda,vrijeme_pregleda);
    br_pregleda++;
    sort(aktivni_pregledi,aktivni_pregledi+br_pregleda,[](Pregled* pok1, Pregled* pok2) {
        return Pregled::DolaziPrije(*pok1,*pok2);
    });

}


Pregledi::Pregledi(int max_broj_pregleda)
{
    maks_pregleda=max_broj_pregleda;
    try {
        aktivni_pregledi=new Pregled*[maks_pregleda];
    } catch(std::bad_alloc e) {
        maks_pregleda=0;
        throw;
    }

}

Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda)
{
    int i=0;        //pratimo koliko smo alocirali da mozemo obrisati kasnije
    try {
        maks_pregleda=1000000;
        aktivni_pregledi=new Pregled*[maks_pregleda];

        for(auto pok: spisak_pregleda) {
            aktivni_pregledi[i]=new Pregled(pok);
            i++;
        }
        br_pregleda=spisak_pregleda.size(); // ovo stavljamo samo ako uspije alokacija
        sort(aktivni_pregledi,aktivni_pregledi+br_pregleda,[](Pregled* pok1, Pregled* pok2) {
            return Pregled::DolaziPrije(*pok1,*pok2);
        });

    } catch(std::bad_alloc e) {
        obrisiOstatke(i);
        throw;
    }

}

Pregledi::Pregledi(const Pregledi& izvor_pregledi)
{

    int i=0;

    try {
        aktivni_pregledi=new Pregled*[izvor_pregledi.maks_pregleda];
        maks_pregleda=izvor_pregledi.maks_pregleda;

        for(; i<izvor_pregledi.br_pregleda; i++) {
            aktivni_pregledi[i] = new Pregled(*izvor_pregledi.aktivni_pregledi[i]);
        }
        br_pregleda=izvor_pregledi.br_pregleda;
    }

    catch(std::bad_alloc e) {
        obrisiOstatke(i);
        throw;
    }
}


Pregledi::Pregledi(Pregledi&& izvor_pregledi):aktivni_pregledi(izvor_pregledi.aktivni_pregledi),maks_pregleda(izvor_pregledi.maks_pregleda),br_pregleda(izvor_pregledi.br_pregleda)
{
    izvor_pregledi.aktivni_pregledi=nullptr;
    izvor_pregledi.br_pregleda=0;
    izvor_pregledi.maks_pregleda=0;
}



Pregledi& Pregledi::operator =(const Pregledi &izvor_pregledi)
{
    if(&izvor_pregledi==this) return *this;       //samododjela

    int i=0,
        IsprazniKolekciju();
    maks_pregleda=izvor_pregledi.maks_pregleda;

    try {

        aktivni_pregledi=new Pregled*[izvor_pregledi.maks_pregleda];
        maks_pregleda=izvor_pregledi.maks_pregleda;

        for(; i<izvor_pregledi.br_pregleda; i++) {
            aktivni_pregledi[i]=new Pregled(*izvor_pregledi.aktivni_pregledi[i]);
        }
        br_pregleda=izvor_pregledi.br_pregleda;

    }

    catch(std::bad_alloc e) {

        obrisiOstatke(i);
        throw;

    }
    return *this;

}

Pregledi& Pregledi::operator =(Pregledi&& pregledi)
{

    if(&pregledi==this) return *this;

    IsprazniKolekciju();
    maks_pregleda=pregledi.maks_pregleda;
    br_pregleda=pregledi.br_pregleda;
    aktivni_pregledi=pregledi.aktivni_pregledi;

    pregledi.br_pregleda=0;
    pregledi.aktivni_pregledi=nullptr;
    pregledi.maks_pregleda=0;

    return *this;
}







int main ()
{
    
        /* Test konstr kopije, operatora dodjele i sl.
    Pregledi pregledi12{Pregled("mujo",2,2,2,2,2), Pregled("haso",3,3,3,3,3),Pregled("elmir",4,4,4,4,4)};
    auto pregledi2(pregledi12);
    auto pregledi3 = pregledi12;
    Pregledi pregledi5={Pregled("mujo",2,2,2,3,3)};*/
    
    
    
    
    
    
    cout<<"Unesite maksimalan broj pregleda: ";
    int maxi;
    cin>>maxi;
    Pregledi pregledi(maxi);
    string ime;

    do {
        try {
            cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
            cin.ignore(10000,'\n');
            getline(cin,ime);
            if(ime=="kraj")
                break;
            cout<<"Unesite dan mjesec i godinu pregleda: ";
            int d,mj,g;
            cin>>d>>mj>>g;
            cout<<"Unesite sate i minute pregleda: ";
            int h,m;
            cin>>h>>m;
            pregledi.RegistrirajPregled(ime,d,mj,g,h,m);
            maxi--;


        } catch(std::range_error e) {
            cout<<e.what()<<endl;
            break;      //ako je dostignut max broj pregleda nema smisla opet trazit unos jer moramo obrisati nekog sigurno
        } catch(std::domain_error e) {
            cout<<e.what()<<endl;
        }




    } while(maxi>0);
    
    cout<<"Trenutno su registrovani sljedeci pregledi"<<endl;
    pregledi.IspisiSvePreglede();

    int unos(0);

    do {
        cout<<"Odaberite jednu od sljedecih opcija"<<endl;
        cout<<"1 - Broj pregleda na datum"<<endl;
        cout<<"2 - Najraniji pregled"<<endl;
        cout<<"3 - Obrisi pregled pacijenta"<<endl;
        cout<<"4 - Obrisi najraniji pregled"<<endl;
        cout<<"5 - Ispisi sve pregleda na datum"<<endl;
        cout<<"6 - Ispisi sve preglede"<<endl;
        cout<<"7 - Kraj programa"<<endl;

        cin>>unos;

        try {

            switch(unos) {


    
                    //opcija 1
                case 1: {
                    cout<<"Unesite dan mjesec i godinu : ";
                    int dan,mj,godina;
                    cin>>dan>>mj>>godina;
                    cout<<"Broj pregleda na datum "<<dan<<" "<<mj<<" "<<godina<<" je: "<<pregledi.DajBrojPregledaNaDatum(Datum(dan,mj,godina));
                    break;
                }
    
                //opcija 2
                case 2: {

                    cout<<"Najraniji pregled je:"<<endl;
                    pregledi.DajNajranijiPregled().Ispisi();
                    break;
                }
    
                //opcija 3
                case 3: {
                    cout<<"Unesite ime pacijenta: ";
                    cin.ignore(10000,'\n');
                    getline(cin,ime);
                    int n = pregledi.DajBrojPregleda();
                    pregledi.ObrisiPregledePacijenta(ime);
                    int m = pregledi.DajBrojPregleda();
                    cout<<"Uspjesno obrisano "<<n-m<<" pregleda"<<endl;
                    break;
                }
    
                case 4: {
                    pregledi.ObrisiNajranijiPregled();
                    cout<<"Najraniji pregled uspjesno obrisan"<<endl;
                    break;
                }
    
                //opcija 4
                case 5: {
                    cout<<"Unesite dan mjesec i godinu : ";
                    int dan,mj,godina;
                    cin>>dan>>mj>>godina;
                    cout<<"Pregledi na datum "<<dan<<" "<<mj<<" "<<godina<<" su:"<<endl;
                    pregledi.IspisiPregledeNaDatum(Datum(dan,mj,godina));
                    break;
                }
    
                case 6: {
                    pregledi.IspisiSvePreglede();
                    break;
    
                }

            }
        
        } 
        catch(std::domain_error e) {
            cout<<e.what()<<endl;
        } catch(std::range_error e) {
            cout<<e.what()<<endl;
        }

        cout<<endl;
    } while(unos!=7);
    
    

    return 0;
}
