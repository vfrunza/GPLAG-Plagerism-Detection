#include <iostream>
#include <tuple>
#include <utility>
#include <stdexcept>
#include <initializer_list>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <memory>
using std::get;
using std::vector;
using std::string;
using std::cin;
using std::cout;
class Datum
{
    int Dan,Mjesec,Godina;
    static int BrojDana(int mjesec, int godina) {
        int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0)
            broj_dana[1]++;
        return broj_dana[mjesec - 1];
    }
public:
    Datum(int dan,int mjesec,int godina) {
        Postavi(dan,mjesec,godina);
    }
    void Postavi(int dan,int mjesec,int godina) {
        int broj_dana[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0) broj_dana[1]++;
        if(godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > broj_dana[mjesec - 1])
            throw std::domain_error("Neispravan datum!");
        Dan=dan;
        Mjesec=mjesec;
        Godina=godina;
    }
    std::tuple<int, int, int> Ocitaj() const {
        auto t(std::make_tuple(Dan,Mjesec,Godina));
        return t;
    }
    void Ispisi() const {
        // if(Dan<10) std::cout<<"0"<<Dan<<"/";
        std::cout<<Dan<<"/";
        std::cout<<Mjesec<<"/"<<Godina;
    }
};
class Vrijeme
{
    int Sati,Minute;
public:
    Vrijeme(int sati,int minute) {
        Postavi(sati,minute);
    }
    void Postavi(int sati,int minute) {
        if(sati<0 || sati >23 || minute<0 || minute>59) throw std::domain_error("Neispravno vrijeme");
        Sati=sati;
        Minute=minute;
    }
    std::pair<int, int> Ocitaj () const {
        auto par(std::make_pair(Sati,Minute));
        return par;
    }
    void Ispisi() const {
        if(Sati<10) std::cout<<"0"<<Sati<<":";
        else std::cout<<Sati<<":";
        if(Minute<10)
            std::cout<<"0"<<Minute;
        else std::cout<<Minute;
    }
};

class Pregled
{
    string ime;
    Datum dat;
    Vrijeme vr;
    int dan,mjesec,godina,sat,min;
    static int BrojDana(int mjesec, int godina) {
        int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0)
            broj_dana[1]++;
        return broj_dana[mjesec - 1];
    }
public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda,const Vrijeme &vrijeme_pregleda):
        dat(get<0>(datum_pregleda.Ocitaj()),get<1>(datum_pregleda.Ocitaj()),get<2>(datum_pregleda.Ocitaj())),
        vr(vrijeme_pregleda.Ocitaj().first,vrijeme_pregleda.Ocitaj().second),ime(ime_pacijenta) {

        dan=get<0>(datum_pregleda.Ocitaj());
        mjesec=get<1>(datum_pregleda.Datum::Ocitaj());
        godina=get<2>(datum_pregleda.Datum::Ocitaj());
        sat=vrijeme_pregleda.Vrijeme::Ocitaj().first;
        min=vrijeme_pregleda.Vrijeme::Ocitaj().second;
    }



    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,int godina_pregleda, int sati_pregleda, int minute_pregleda): ime(ime_pacijenta),dan(dan_pregleda),
        mjesec(mjesec_pregleda),godina(godina_pregleda), sat(sati_pregleda),min(minute_pregleda), dat(dan,mjesec,godina),
        vr(sat,min) {}
    void PromijeniPacijenta(const std::string &ime_pacijenta) {
        ime=ime_pacijenta;
    }
    void PromijeniDatum(const Datum &novi_datum) {
        //dat=novi_datum;
        //da li je ok..
        //OBRATITI PAZNJU
        dat.Datum::Postavi(get<0>(novi_datum.Ocitaj()),get<1>(novi_datum.Ocitaj()),get<2>(novi_datum.Ocitaj()));

    }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme) {
        //vr=novo_vrijeme;
        vr.Vrijeme::Postavi(novo_vrijeme.Ocitaj().first,novo_vrijeme.Ocitaj().second);
    }
    void PomjeriDanUnaprijed() {
        dan++;
        if(dan >BrojDana(mjesec, godina)) dan = 1, mjesec++;
        if(mjesec > 12) mjesec = 1, godina++;
    }
    void PomjeriDanUnazad() {
        dan--; //da li treba --mj ili mj--
        if(dan<1) {
            --mjesec;
            dan=BrojDana(mjesec,godina);
        }
        if(mjesec<1) {
            mjesec=12;
            godina--;
        }
    }
    std::string DajImePacijenta() const {
        return ime;
    }
    Datum DajDatumPregleda() const {
        return dat;
    }
    Vrijeme DajVrijemePregleda() const {
        return vr;
    }
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2) {
        //ako je prvi prije drugog true
        if(p1.godina==p2.godina) {
            if(p1.mjesec==p2.mjesec) {
                if(p1.dan==p2.dan) {
                    if(p1.sat==p2.sat) {
                        return p1.min<p2.min;
                    } else if(p1.sat<p2.sat) return true;
                    else return false;

                } else if(p1.dan<p2.dan) return true;
                else return false;
            } else if(p1.mjesec<p2.mjesec) return true;
            else return false;
        } else if(p1.godina<p2.godina) return true;
        else return false;
    }

    void Ispisi() const {
        std::cout<<std::setw(30)<<std::left<<ime;
        dat.Datum::Ispisi();
        std::cout<<" ";
        vr.Vrijeme::Ispisi();
        std::cout<<std::endl;
    }
};
class Pregledi
{
    std::vector<std::shared_ptr<Pregled>> pregledii;
public:
    explicit Pregledi(){}
    Pregledi(std::initializer_list<Pregled> spisak_pregleda){
        for(auto it(spisak_pregleda.begin()); it!=spisak_pregleda.end(); it++) {
            pregledii.push_back(std::make_shared<Pregled>(*it));
        }
        // Brojac++;
    }
    ~Pregledi() {for(int i(0);i<pregledii.size();i++) pregledii[i]=nullptr;}

    Pregledi(const Pregledi &pregledi) {
        try {
            for(int i(0); i<pregledii.size(); i++)
                if(pregledii[i] != nullptr)
                    pregledii.push_back(std::make_shared<Pregled>(*pregledi.pregledii[i]));
            //  Brojac++;

        } catch(...) {
            for(int i(0); i<pregledii.size(); i++)  pregledii[i]=nullptr;
            
            throw;
        }
    }
    Pregledi(Pregledi &&pregledi):pregledii(pregledi.pregledii) {
       pregledi.pregledii.resize(0);
    }
    Pregledi &operator =(const Pregledi &pregledi) {
        if(pregledi.pregledii.size()>pregledii.size()) {
            int pocetna(pregledii.size());
            try {
                for(int i=pregledii.size(); i<pregledi.pregledii.size(); i++)
pregledii.push_back(std::make_shared<Pregled>(*pregledi.pregledii[i]));

            } catch(...) {
                pregledii.resize(pocetna);
                throw;
            }

        } else {
            pregledii.resize(pregledi.pregledii.size());
        }
        for(int i(0); i<pregledii.size(); i++) {
            pregledii[i]=nullptr;
            pregledii[i]=std::make_shared<Pregled>(*pregledi.pregledii[i]);
        }
 return *this;
    }

    Pregledi &operator =(Pregledi &&pregledi) {
        std::swap(pregledii,pregledi.pregledii);
       // std::swap(broj,pregledi.broj);
        pregledi.pregledii.resize(0);
        return *this;
    }
    void RegistrirajPregled(const std::string &ime_pacijenta,const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,int mjesec_pregleda, int godina_pregleda, int sati_pregleda,int minute_pregleda);
    void RegistrirajPregled(std::shared_ptr<Pregled> pregled);
    int DajBrojPregleda() const;
    int DajBrojPregledaNaDatum(const Datum &datum) const;
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum(const Datum &datum) const;
    void IspisiSvePreglede() const;
};

//int Pregledi::Brojac = 0;
void Pregledi:: RegistrirajPregled(const std::string &ime_pacijenta,const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda)
{
   try{ std::shared_ptr<Pregled> p(std::make_shared<Pregled>(ime_pacijenta,datum_pregleda,vrijeme_pregleda));
    /*for(int i(0); i<pregledii.size(); i++) {
        if(pregledii[i]==nullptr) {
            pregledii[i]=p;
            break;
        }
    } */
    pregledii.push_back(p);
   }catch(...){throw;}
    
}
void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,int mjesec_pregleda, int godina_pregleda, int sati_pregleda,int minute_pregleda)
{
   std::shared_ptr<Pregled> p(std::make_shared<Pregled>(ime_pacijenta,dan_pregleda,mjesec_pregleda,godina_pregleda,sati_pregleda,minute_pregleda));
   /*
    for(int i(0); i<pregledii.size(); i++) {
        if(pregledii[i]==nullptr) {
            pregledii[i]=p;
            break;
        }
    }*/
    //broj++;
    pregledii.push_back(p);
}
/*objektom, tj. preuzima odgovornost za njegovo brisanje.*/
void Pregledi::RegistrirajPregled(std::shared_ptr<Pregled> pregled)
{
    //if(broj>=max_broj) throw std::range_error("Dostignut maksimalni broj pregleda");
    // pregledii[broj++]=pregled;
    /*for(int i(0); i<max_broj; i++) {
        if(pregledii[i]==nullptr) {
            pregledii[i]=pregled;
            break;
        }
    }*/
    //broj++;
    pregledii.push_back(pregled);
}

int Pregledi::DajBrojPregleda() const
{
    return int(pregledii.size());
}
int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const
{
    auto datum1(datum.Ocitaj());
    int rez=std::count_if(pregledii.begin(),pregledii.end(),[datum1](std::shared_ptr<Pregled> p1) {
        auto datum2((p1->DajDatumPregleda()).Ocitaj()); //vraca se datum pa se onda ocitava
        if(get<0>(datum1)==get<0>(datum2) && get<1>(datum1)==get<1>(datum2) && get<2>(datum1)==get<2>(datum2) )
            return true;
        else return false;
    });
    return rez;
}
Pregled &Pregledi:: DajNajranijiPregled()
{
    if(pregledii.size()==0) throw std::domain_error("Nema registriranih pregleda");
    Pregled &rez(**std::min_element(pregledii.begin(),pregledii.end(),[](std::shared_ptr<Pregled> p1,std::shared_ptr<Pregled> p2) {
        auto pomoc1((p1->DajDatumPregleda()).Ocitaj()); //datum trenutnog pregledda
        auto pomoc2((p2->DajDatumPregleda()).Ocitaj());
        //datum organiziran kao tuple
        if(std::get<2>(pomoc1)==std::get<2>(pomoc2)) {
            if(std::get<1>(pomoc1)==std::get<1>(pomoc2)) {
                return std::get<0>(pomoc1)<std::get<0>(pomoc2);

            } else if(std::get<1>(pomoc1)<std::get<1>(pomoc2)) return true;
            else return false;

        } else if(std::get<2>(pomoc1)<std::get<2>(pomoc2)) return true;
        else return false;

    }));
    return rez;
}
void Pregledi::IsprazniKolekciju()
{
    for(int i(0); i<pregledii.size(); i++) {
        //delete pregledii[i];
        pregledii[i]=nullptr;
    }
    pregledii.resize(0);
    //broj = 0;//brisu se samo pregledi
}
void Pregledi::ObrisiNajranijiPregled()
{
    if(pregledii.size()==0) throw std::range_error("Prazna kolekcija");
    auto rez(std::min_element(pregledii.begin(),pregledii.end(),[](std::shared_ptr<Pregled> p1,std::shared_ptr<Pregled> p2) {
        if(p1 == nullptr && p2 != nullptr)
            return false;
        if(p2 == nullptr && p1 != nullptr)
            return true;
        if(p1 == nullptr && p2 == nullptr)
            return true;
        auto pomoc1((p1->DajDatumPregleda()).Ocitaj()); //datum trenutnog pregledda
        auto pomoc2((p2->DajDatumPregleda()).Ocitaj());
        //datum organiziran kao tuple
        if(std::get<2>(pomoc1)==std::get<2>(pomoc2)) {
            if(std::get<1>(pomoc1)==std::get<1>(pomoc2)) {
                return std::get<0>(pomoc1)<std::get<0>(pomoc2);

            } else if(std::get<1>(pomoc1)<std::get<1>(pomoc2)) return true;
            else return false;

        } else if(std::get<2>(pomoc1)<std::get<2>(pomoc2)) return true;
        else return false;

    }));
   int n(rez-pregledii.begin());
    pregledii.erase(pregledii.begin()+n);

}

void Pregledi:: ObrisiPregledePacijenta(const std::string &ime_pacijenta)
{
    int brojac = 0;
   // for(int i(0); i<max_broj; i++)
   for(int i(0);i<pregledii.size();i++)
        if(pregledii[i] != nullptr)
            if(pregledii[i]->DajImePacijenta()==ime_pacijenta) {
                pregledii.erase(pregledii.begin()+i);
                i--;
                brojac++;
            }
    cout << "Uspjesno obrisano " << brojac << " pregleda\n";
}

void Pregledi:: IspisiPregledeNaDatum(const Datum &datum) const
{
    std::vector<Pregled> vektor;
    for(int i(0); i<pregledii.size(); i++) {
        if(pregledii[i] != nullptr) {
            auto pomoc5((pregledii[i]->DajDatumPregleda()).Ocitaj()); //tuple
            auto pomoc6(datum.Ocitaj());
            if(get<0>(pomoc5)==get<0>(pomoc6) && get<1>(pomoc5)==get<1>(pomoc6) && get<2>(pomoc5)==get<2>(pomoc6) )
                vektor.push_back(*pregledii[i]);
        }
    }
    std::sort(vektor.begin(),vektor.end(),[](Pregled p1,Pregled p2) {
        auto vr1((p1.DajVrijemePregleda()).Ocitaj());
        auto vr2((p2.DajVrijemePregleda()).Ocitaj());
        if(vr1.first==vr2.first) {
            return vr1.second<vr2.second;
        } else if(vr1.first<vr2.first) return true;
        else return false;
    });
    for(int i(0); i<vektor.size(); i++)
        vektor[i].Pregled::Ispisi();
}

void Pregledi::IspisiSvePreglede()const
{
    std::vector<Pregled> vektor;
    for(int i(0); i<pregledii.size(); i++)
        if(pregledii[i] != nullptr)
            vektor.push_back(*pregledii[i]);
    std::sort(vektor.begin(),vektor.end(),[](Pregled p1,Pregled p2) {
        auto datum1((p1.DajDatumPregleda()).Ocitaj());
        auto datum2((p2.DajDatumPregleda()).Ocitaj());
        auto vr1((p1.DajVrijemePregleda()).Ocitaj());
        auto vr2((p2.DajVrijemePregleda()).Ocitaj());
        if(get<0>(datum1)==get<0>(datum2) && get<1>(datum1)==get<1>(datum2) && get<2>(datum1)==get<2>(datum2)) {
            if(vr1.first==vr2.first) {
                return vr1.second<vr2.second;
            } else if(vr1.first<vr2.first) return true;
            else return false;
        } else if(Pregled::DolaziPrije(p1,p2)) return true;
        else return false;
    });
    for(int i(0); i<vektor.size(); i++)
        vektor[i].Ispisi();

}
int main ()
{
 Pregledi p;
   // Pregledi p2;
    //Pregledi p2(maxi);
    for(; ; ) {
        std:: cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        string ime;
        //cin.ignore(1000, '\n');
        std::getline(cin,ime);
        if(ime == "kraj") break;
        cout<<"Unesite dan mjesec i godinu pregleda: ";
        int dan,mjesec,godina;
        cin>>dan>>mjesec>>godina;
        Datum d(dan,mjesec,godina);
        cout<<"Unesite sate i minute pregleda: ";
        int satii,minutee;
        cin>>satii>>minutee;
        Vrijeme v(satii,minutee);
        p.RegistrirajPregled(ime,d,v);
        cin.ignore(1000, '\n');
    }
    cout<<"Trenutno su registrovani sljedeci pregledi\n";
    p.IspisiSvePreglede();
  //  p.ObrisiNajranijiPregled();
  //cout<<  p.DajBrojPregleda()<<std::endl;
  //  p.IsprazniKolekciju();
 // cout<< p.DajBrojPregleda()<<std::endl;
   // p2=p;
   // p.IsprazniKolekciju();
//try{  p.ObrisiNajranijiPregled();}catch(std::range_error e){cout<<e.what();}
    //p2.IspisiSvePreglede();
    while(true) {
        cout<<"\nOdaberite jednu od sljedecih opcija\n"
            <<"1 - Broj pregleda na datum\n"
            <<"2 - Najraniji pregled\n"
            <<"3 - Obrisi pregled pacijenta\n"
            <<"4 - Obrisi najraniji pregled\n"
            <<"5 - Ispisi sve pregleda na datum\n"
            <<"6 - Ispisi sve preglede\n"
            <<"7 - Kraj programa\n";
        int opcija;
        cin >> opcija;
        switch(opcija) {
        case 1: {
            cout<<"Unesite dan mjesec i godinu : ";
            int d,mj,gd;
            cin>>d>>mj>>gd;
            Datum dat(d,mj,gd);
            cout<<"Broj pregleda na datum "<<d<<" "<<mj<<" "<<gd<<" je: "<<p.DajBrojPregledaNaDatum(dat) << "\n";
            break;
        }
        case 2: {
            cout<<"Najraniji pregled je:\n";
            (p.DajNajranijiPregled()).Ispisi();
            break;
        }
        case 3: {
            cin.ignore(1000, '\n');
            cout<<"Unesite ime pacijenta: ";
            string imee;
            std::getline(cin,imee);
            p.ObrisiPregledePacijenta(imee);
            break;

        }
        case 4: {
            try {
                p.ObrisiNajranijiPregled();
                cout<<"Najraniji pregled uspjesno obrisan\n";
            } catch(std::range_error e) {
                cout<<e.what();
            }
            break;
        }
        case 5: {
            int d,m,g;
            cout<<"Unesite dan mjesec i godinu :";
            cin>>d>>m>>g;
            //cout<<"Broj pregleda na datum"<<d<<" "<<m<<" "<<g;
            Datum datumm(d,m,g);
            cout<<" Pregledi na datum "<<d<<" "<<m<<" "<<g<<" su:"<<std::endl;
            p.IspisiPregledeNaDatum(datumm);
            break;
        }
        case 6: {
            p.IspisiSvePreglede();
            break;
        }
        case 7: {
            break;
        }
        }
        if(opcija == 7)
            break;
    }

    return 0;
}
