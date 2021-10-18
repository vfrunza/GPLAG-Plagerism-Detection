/B2017/2018: Zadaća 4, Zadatak 4
#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <iomanip>
#include <exception>
#include <memory>

using namespace std;

bool JelPrestupna(int n)
{
    if((n % 4 == 0 && n % 100 != 0) || n % 400 == 0)
        return true;
    return false;
}

class Datum
{

    int dan,mjesec,godina;
public:
    Datum(int dan=1, int mjesec=1, int godina=1) {
        vector<int> dani {31,28,31,30,31,30,31,31,30,31,30,31};
        if(JelPrestupna(godina)) dani[1]++;
        if(godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > dani[mjesec-1]) throw domain_error("Neispravan datum!");
        Datum::dan = dan;
        Datum::mjesec = mjesec;
        Datum::godina = godina;


    };
    void Postavi(int dan, int mjesec, int godina) {
        vector<int> dani {31,28,31,30,31,30,31,31,30,31,30,31};
        if(JelPrestupna(godina)) dani[1]++;
        if(godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > dani[mjesec-1]) throw domain_error("Neispravan datum!");
        Datum::dan=dan;
        Datum::mjesec=mjesec;
        Datum::godina=godina;
    }

    std::tuple<int, int, int> Ocitaj() const {
        return make_tuple(dan,mjesec,godina);
    }
    void Ispisi() const {
        cout<<dan<<"/"<<mjesec<<"/"<<godina<<" ";
    }
    void ispisi() const {
        cout<<dan<<" "<<mjesec<<" "<<godina<<" ";
    }

};

bool IstiDatum(Datum d1,Datum d2)
{
    return get<0>(d1.Ocitaj())==get<0>(d2.Ocitaj()) && get<1>(d1.Ocitaj())==get<1>(d2.Ocitaj())
           && get<2>(d1.Ocitaj())==get<2>(d2.Ocitaj());
}

class Vrijeme
{
    int sati,minute;

public:
    Vrijeme(int sati=0, int minute=0) {
        if(sati>23 || sati<0 || minute>59 || minute<0)throw domain_error("Neispravno vrijeme!");
        Postavi(sati,minute);
    }

    void Postavi(int sati, int minute) {

        Vrijeme::sati=sati;
        Vrijeme::minute=minute;
    }

    std::pair<int, int> Ocitaj () const {

        return make_pair(sati,minute);
    }
    void Ispisi() const {
        cout <<setw(2)<<right<<setfill('0')<<sati << ":" <<setfill('0') <<setw(2) << minute<<endl ;
    }
};

class Pregled
{
    string ime;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;

public:

    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda,const Vrijeme &vrijeme_pregleda)
        :ime(ime_pacijenta),datum_pregleda(datum_pregleda),vrijeme_pregleda(vrijeme_pregleda) {};

    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,int godina_pregleda, int sati_pregleda, int minute_pregleda)
        :ime(ime_pacijenta),datum_pregleda(dan_pregleda,mjesec_pregleda,godina_pregleda),vrijeme_pregleda(sati_pregleda,minute_pregleda) {};

    void PromijeniPacijenta(const std::string &ime_pacijenta) {
        ime=ime_pacijenta;
    }
    void PromijeniDatum(const Datum &novi_datum) {

        datum_pregleda=novi_datum;
    }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme) {
        vrijeme_pregleda=novo_vrijeme;
    }
    void PomjeriDanUnaprijed() {
        int dan =(get<0>(datum_pregleda.Ocitaj()));
        int mjesec=(get<1>(datum_pregleda.Ocitaj()));
        int godina=(get<2>(datum_pregleda.Ocitaj()));

        vector<int> dani {31,28,31,30,31,30,31,31,30,31,30,31};
        if(JelPrestupna(godina)) dani[1]++;

        if (mjesec==12 && dan==31)
            datum_pregleda.Postavi(1,1,godina++);
        else if (dan==dani[mjesec-1])
            datum_pregleda.Postavi(1,mjesec++,godina);
        else
            datum_pregleda.Postavi(dan+1,mjesec,godina);
        datum_pregleda.Postavi(get<0>(datum_pregleda.Ocitaj())+1,get<1>(datum_pregleda.Ocitaj()),get<2>(datum_pregleda.Ocitaj()));
    }
    void PomjeriDanUnazad() {
        int dan =(get<0>(datum_pregleda.Ocitaj()));
        int mjesec=(get<1>(datum_pregleda.Ocitaj()));
        int godina=(get<2>(datum_pregleda.Ocitaj()));

        vector<int> dani {31,28,31,30,31,30,31,31,30,31,30,31};
        if(JelPrestupna(godina)) dani[1]++;

        if (mjesec==1 && dan==1)
            datum_pregleda.Postavi(31,12,godina-1);
        else if (dan==1)
            datum_pregleda.Postavi(dani[mjesec-2],mjesec-1,godina);
        else
            datum_pregleda.Postavi(dan-1,mjesec,godina);

    }
    std::string DajImePacijenta() const {
        return ime;
    }
    Datum DajDatumPregleda() const {
        return datum_pregleda;
    }
    Vrijeme DajVrijemePregleda() const {
        return vrijeme_pregleda;
    }
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2) {
        if ( get<2>(p1.DajDatumPregleda().Ocitaj()) < get<2>(p2.DajDatumPregleda().Ocitaj()) )
            return true;

        else if ( get<2>(p1.DajDatumPregleda().Ocitaj()) == get<2>(p2.DajDatumPregleda().Ocitaj()) && get<1>(p1.DajDatumPregleda().Ocitaj()) < get<1>(p2.DajDatumPregleda().Ocitaj()) )
            return true;

        else if (get<2>(p1.DajDatumPregleda().Ocitaj()) == get<2>(p2.DajDatumPregleda().Ocitaj()) && get<1>(p1.DajDatumPregleda().Ocitaj())==get<1>(p2.DajDatumPregleda().Ocitaj()) &&  get<0>(p1.DajDatumPregleda().Ocitaj())<get<0>(p2.DajDatumPregleda().Ocitaj()))
            return true;


        else if ( get<2>(p1.DajDatumPregleda().Ocitaj()) == get<2>(p2.DajDatumPregleda().Ocitaj()) && get<1>(p1.DajDatumPregleda().Ocitaj())==get<1>(p2.DajDatumPregleda().Ocitaj()) &&  get<0>(p1.DajDatumPregleda().Ocitaj())==get<0>(p2.DajDatumPregleda().Ocitaj())) {

            return true;
        }

        return false;
    }
    void Ispisi() const {
        cout<<left<<setw(30)<<setfill(' ')<<ime;
        datum_pregleda.Ispisi();
        vrijeme_pregleda.Ispisi();
    }


};

class Pregledi
{

    vector<shared_ptr<Pregled>> pok;

public:
    explicit Pregledi() {}

    Pregledi(std::initializer_list<Pregled> spisak_pregleda) {

        for(auto it=spisak_pregleda.begin(); it!=spisak_pregleda.end(); it++)
            pok.push_back(make_shared<Pregled>(*it));
    }

    ~Pregledi() {

        pok.resize(0);
    }

    Pregledi(const Pregledi &pregledi) {



        for(int i=0; i<pregledi.pok.size(); i++)
            pok.push_back(make_shared<Pregled>(*pregledi.pok[i]));

    }
    Pregledi(Pregledi &&pregledi) {


        for(int i=0; i<pregledi.pok.size(); i++)
            pok.push_back(pregledi.pok[i]);

        pregledi.pok.resize(0);
    }

    Pregledi &operator =(const Pregledi &pregledi) {
        if(this!=&pregledi) {

            pok.resize(0);
            for(int i=0; i<pregledi.pok.size(); i++)
                pok.push_back(make_shared<Pregled>(*pregledi.pok[i]));
        }
        return *this;
    }

    Pregledi &operator =(Pregledi &&pregledi) {
        if(this!=&pregledi) {
            pok.resize(0);


            for(int i=0; i<pregledi.pok.size(); i++)
                pok.push_back(pregledi.pok[i]);

            pregledi.pok.resize(0);
        }
        return *this;
    }

    void RegistrirajPregled(const std::string &ime_pacijenta,const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) {
        pok.push_back(make_shared<Pregled>(ime_pacijenta,datum_pregleda,vrijeme_pregleda));

    }
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,
                            int mjesec_pregleda, int godina_pregleda, int sati_pregleda,
                            int minute_pregleda) {
        pok.push_back(make_shared<Pregled>(ime_pacijenta,Datum(dan_pregleda,mjesec_pregleda,godina_pregleda),Vrijeme(sati_pregleda,minute_pregleda)));



    }
    void RegistrirajPregled(Pregled *pregled) {
        pok.push_back(make_shared<Pregled>(*pregled));

    }

    int DajBrojPregleda() const {
        return pok.size();
    }
    int DajBrojPregledaNaDatum(const Datum &datum) const {
        int br=0;
        if(pok.size()==0)throw domain_error ("Nema registriranih pregleda");

        for(int i=0; i<pok.size(); i++) {
            if(IstiDatum(pok[i]->DajDatumPregleda(),datum)) {
                br++;
            }
        }
        return br;
    }

    Pregled &DajNajranijiPregled(){
        if (pok.size()>0) {
        return *pok[0];
         } else throw domain_error ("Nema registriranih pregleda");
    
    };



    Pregled DajNajranijiPregled() const {
        if (pok.size()>0) {
           return *pok[0];
        } else throw domain_error ("Nema registriranih pregleda");
    }

    void IsprazniKolekciju() {
        for(int i=0; i<pok.size(); i++)
            pok[i]=nullptr;

    }

    void ObrisiNajranijiPregled() {
        if (pok.size() == 0)throw domain_error ("Nema registriranih pregleda");

        pok[0]=nullptr ;
        for(int j=0; j<pok.size()-1; j++) {
            pok[j]=pok[j+1];
        }

        pok.resize(pok.size()-1);
    }

    bool RanijiDatum(Datum d1,Datum d2) {


        if ( get<2>(d1.Ocitaj()) < get<2>(d2.Ocitaj()) )
            return true;

        else if ( get<2>(d1.Ocitaj()) == get<2>(d2.Ocitaj()) && get<1>(d1.Ocitaj()) < get<1>(d2.Ocitaj()) )
            return true;

        else if (get<2>(d1.Ocitaj()) == get<2>(d2.Ocitaj()) && get<1>(d1.Ocitaj())==get<1>(d2.Ocitaj()) &&  get<0>(d1.Ocitaj())<get<0>(d2.Ocitaj()))
            return true;


        else if ( get<2>(d1.Ocitaj()) == get<2>(d2.Ocitaj()) && get<1>(d1.Ocitaj())==get<1>(d2.Ocitaj()) &&  get<0>(d1.Ocitaj())==get<0>(d2.Ocitaj())) {

            // provjera vremena

        }

        return false;
    };

    void Sortiraj() {
        if (pok.size()>1) {
            for(int i=0; i<pok.size(); i++) {
                for(int j=i+1; j<pok.size(); j++) {
                    if(RanijiDatum(pok[j]->DajDatumPregleda(),pok[i]->DajDatumPregleda())) {


                        auto p=pok[i];
                        pok [i]=pok[j];
                        pok [j]=p;

                    }
                }
            }
        }
    }




    int  ObrisiPregledePacijenta(const std::string &ime_pacijenta) {
        int br=0;
        for(int i=0; i<pok.size(); i++) {
            if(pok[i]->DajImePacijenta()==ime_pacijenta) {
                br++;
                pok[i]=nullptr;

                for(int j=i; j<pok.size()-1; j++)
                    pok[j]=pok[j+1];
                pok.resize(pok.size()-1);
            }
        }

        return br;
    }
    void IspisiPregledeNaDatum(const Datum &datum) const {
        for(int i=0; i<pok.size(); i++) {
            if(IstiDatum(pok[i]->DajDatumPregleda(),datum))
                pok[i]->Ispisi();
        }
    }
    void IspisiSvePreglede() const {
        for(int i=0; i<pok.size(); i++)
            pok[i]->Ispisi();
    }


};

int main ()
{

    int dan,mjesec,godina,sati,minute,opcija,brojac=0;

    string ime;
    //  cout<<"radim";

    try {
        Pregledi k;
        while(1) {
            cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
            cin>>ime;
            if(ime=="kraj")break;
            cout<<"Unesite dan mjesec i godinu pregleda: ";
            cin>>dan>>mjesec>>godina;
            Datum d(dan,mjesec,godina);
            cout<<"Unesite sate i minute pregleda: ";
            cin>>sati>>minute;
            Vrijeme v(sati,minute);
            k.RegistrirajPregled(ime,d,v);
            brojac++;
        }
        k.Sortiraj();
        cout<<"Trenutno su registrovani sljedeci pregledi";
        cout<<endl;
        k.IspisiSvePreglede();


        while (1) {
            cout<<endl<<
                "Odaberite jednu od sljedecih opcija"<<endl<<
                "1 - Broj pregleda na datum"<<endl<<
                "2 - Najraniji pregled"<<endl<<
                "3 - Obrisi pregled pacijenta"<<endl<<
                "4 - Obrisi najraniji pregled"<<endl<<
                "5 - Ispisi sve pregleda na datum"<<endl<<
                "6 - Ispisi sve preglede"<<endl<<
                "7 - Kraj programa"<<endl;

            cin>>opcija;


            switch(opcija) {

            case 1: {
                cout<<"Unesite dan mjesec i godinu : ";
                cin>>dan>>mjesec>>godina;
                Datum d(dan,mjesec,godina);
                int n=k.DajBrojPregledaNaDatum(d);

                cout<<"Broj pregleda na datum ";
                d.ispisi();
                cout<<"je: "<<n<<endl;
            }
            break;

            case 2: {
                cout<<"Najraniji pregled je:"<<endl;
                k.DajNajranijiPregled().Ispisi();

            }
            break;

            case 3: {
                cout<<"Unesite ime pacijenta: ";
                cin>>ime;

                int n(k.ObrisiPregledePacijenta(ime));



                cout<<"Uspjesno obrisano "<<n<<" pregleda"<<endl;
            }
            break;

            case 4: {
                k.ObrisiNajranijiPregled();
                cout<<"Najraniji pregled uspjesno obrisan"<<endl;
            }
            break;

            case 5: {
                cout<<"Unesite dan mjesec i godinu : ";
                cin>>dan>>mjesec>>godina;
                Datum d(dan,mjesec,godina);
                cout<<"Pregledi na datum ";
                d.ispisi();
                cout<<"su:"<<endl;
                k.IspisiPregledeNaDatum(d);
            }
            break;
            case 6: {
                k.IspisiSvePreglede();
            }
            break;

            case 7:
                return 0;
            }
        }

    } catch(domain_error greska) {
        cout<<greska.what();
    } catch(range_error greska) {
        cout<<greska.what();
    } catch(...) {
        cout<<"Greska!!!";
    };


    return 0;
}
