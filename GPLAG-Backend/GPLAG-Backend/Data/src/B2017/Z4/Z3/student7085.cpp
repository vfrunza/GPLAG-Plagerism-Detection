/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>
#include <utility>
#include <iomanip>

class Datum
{


public:
    int Dan,Mjesec,Godina;
    Datum(int dan, int mjesec, int godina) {
        int brojdana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (dan < 1 || mjesec < 1 || godina < 1 || mjesec > 12 || dan > brojdana[mjesec-1]) throw std::domain_error ("Neispravan datum");
        Dan = dan;
        Mjesec = mjesec;
        Godina = godina;
    };

    void Postavi(int dan, int mjesec, int godina) {
        int brojdana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (godina % 4 ==0 && godina % 100 !=0 || godina%400==0) brojdana[1]++;
        if (dan < 1 || mjesec < 1 || godina < 1 || mjesec > 12 || dan > brojdana[mjesec-1]) throw std::domain_error ("Neispravan datum");
        Dan = dan, Mjesec = mjesec, Godina = godina;
    };

    std::tuple<int, int, int> Ocitaj() const {
        std::tuple<int,int,int> datumy;
        std::get<0> (datumy) = Dan;
        std::get<1> (datumy) = Mjesec;
        std::get<2> (datumy) = Godina;
        return datumy;
    };

    void Ispisi() const {
        std::cout << Dan << "/" << Mjesec << "/" << Godina;

    };

    int DajDan() const {
        return this->Dan;
    }
    int DajMjesec() const {
        return this->Mjesec;
    }
    int DajGodinu() const {
        return this->Godina;
    }



};

class Vrijeme
{


public:
    int Sati, Minute;
    Vrijeme(int sati, int minute) {
        if (sati<0 || sati > 12 || minute < 0 || minute > 59) throw std::domain_error ("Neispravno vrijeme");
        Sati = sati, Minute = minute;
    };
    void Postavi(int sati, int minute) {
        if (sati<0 || sati > 12 || minute < 0 || minute > 59) throw std::domain_error ("Neispravno vrijeme");
        Sati = sati, Minute = minute;
    };
    std::pair<int, int> Ocitaj () const {
        std::pair<int,int> pary;
        pary.first = Sati;
        pary.second = Minute;
        return pary;
    };
    void Ispisi() const {

        std::cout << Sati << ":" << Minute;

    };
    int DajSate() const {
        return this->Sati;
    };
    int DajMinute() const {
        return this->Minute;
    };
};

class Pregled
{
    std::string Name;
    Datum Date;
    Vrijeme Time;
    
public:

    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda,
            const Vrijeme &vrijeme_pregleda):Name(ime_pacijenta),Date(datum_pregleda),Time(vrijeme_pregleda) {}

    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,int godina_pregleda, int sati_pregleda, int minute_pregleda):
        Name(ime_pacijenta),Date(dan_pregleda,mjesec_pregleda,godina_pregleda), Time(sati_pregleda,minute_pregleda) {}

    void PromijeniPacijenta(const std::string &ime_pacijenta) {
        Name = ime_pacijenta;

    };
    void PromijeniDatum(const Datum &novi_datum) {
        Date = (novi_datum);
    };
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme) {
        Time = (novo_vrijeme);
    };
    void PomjeriDanUnaprijed() {
        Date.Dan +=1;
    };
    void PomjeriDanUnazad() {
        Date.Dan -=1;
    };
    std::string DajImePacijenta() const {
        return Name;
    };
    Datum DajDatumPregleda() const {
        return Date;
    };
    Vrijeme DajVrijemePregleda() const {
        return Time;
    };
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2) {

        // true ako je prvi prije drugog op op opa

        bool jesam;
        Datum temp (p1.Date);
        Datum temp2 (p2.Date);
        std::tuple<int,int,int> PRVA,DRUGA;
        PRVA = temp.Ocitaj();
        DRUGA = temp2.Ocitaj();

        if (std::get<2>(PRVA) < std::get<2>(DRUGA) ) return true;
        if (std::get<1>(PRVA) < std::get<1>(DRUGA) ) return true;
        if (std::get<0>(PRVA) < std::get<0>(DRUGA) ) return true;
        Vrijeme majko(p1.Time);
        Vrijeme draga (p2.Time);

        std::pair<int,int> aoj,oj;

        aoj = majko.Ocitaj();
        oj =  draga.Ocitaj();

        if (aoj.first < oj.first) return true;
        if (aoj.second < oj.second) return true;


        return false;


    };
    void Ispisi() const {
        std::cout <<std::setw(30) << std::left << Name <<" ";
        Date.Ispisi();
        std::cout << " ";
        Time.Ispisi();
        std::cout << std::endl;
    };

 

    friend bool DolaziPrije3( Pregled p1,  Pregled p2) {

        // true ako je prvi prije drugog op op opa

        bool jesam;
        Datum temp (p1.Date);
        Datum temp2 (p2.Date);
        std::tuple<int,int,int> PRVA,DRUGA;
        PRVA = temp.Ocitaj();
        DRUGA = temp2.Ocitaj();

        if (std::get<2>(PRVA) < std::get<2>(DRUGA) ) return true;
        if (std::get<1>(PRVA) < std::get<1>(DRUGA) ) return true;
        if (std::get<0>(PRVA) < std::get<0>(DRUGA) ) return true;
        Vrijeme majko(p1.Time);
        Vrijeme draga (p2.Time);

        std::pair<int,int> aoj,oj;

        aoj = majko.Ocitaj();
        oj =  draga.Ocitaj();

        if (aoj.first < oj.first) return true;
        if (aoj.second < oj.second) return true;


        return false;


    };

};

class Pregledi
{

    int broj_pregleda;
    int Max_broj_pregleda;
    Pregled **prregledi;
   

public:
    Pregledi &operator =(const Pregledi &pregledi);
    Pregledi &operator =(Pregledi &&pregledi);


    explicit Pregledi(int max_broj_pregleda) : broj_pregleda(0),Max_broj_pregleda(max_broj_pregleda),prregledi(new Pregled*[Max_broj_pregleda] {}) {


    }


    Pregledi(std::initializer_list<Pregled> spisak_pregleda); // Done

    ~Pregledi(); // Done
    Pregledi(const Pregledi &pregledi) {
        prregledi = new Pregled* [pregledi.broj_pregleda] {};
        for (int i = 0; i < pregledi.broj_pregleda; i++)
            prregledi[i] = new Pregled { "Inicijalizacija", { 1, 1, 1 }, { 1, 1 } };


    }

    Pregledi(Pregledi &&pregledi) {


    }


    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) {
        if (broj_pregleda>=Max_broj_pregleda) throw std::range_error ("Dostignut maksimalan broj pregleda");
        prregledi[broj_pregleda++] = new Pregled(ime_pacijenta,datum_pregleda,vrijeme_pregleda);
    }

    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,
                            int mjesec_pregleda, int godina_pregleda, int sati_pregleda,
                            int minute_pregleda) {

        if (broj_pregleda>=Max_broj_pregleda) throw std::range_error ("Dostignut maksimalan broj pregleda");
        
      
        prregledi[broj_pregleda++] = new Pregled(ime_pacijenta,dan_pregleda,mjesec_pregleda,godina_pregleda,sati_pregleda,minute_pregleda);


    }
    void RegistrirajPregled(Pregled *pregled) {
        if (broj_pregleda>=Max_broj_pregleda) throw std::range_error ("Dostignut maksimalan broj pregleda");

        prregledi[broj_pregleda++] = pregled;
}
    
    int DajBrojPregleda() const {
        return broj_pregleda;
    };
    int DajBrojPregledaNaDatum(const Datum &datum) const;
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    void IsprazniKolekciju() {
        for (int i = 0; i < Max_broj_pregleda; i++) prregledi[i] == nullptr;
        broj_pregleda=0;

    };
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum(const Datum &datum) const;
    void IspisiSvePreglede() const;
};

Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda): broj_pregleda(spisak_pregleda.size()),Max_broj_pregleda(spisak_pregleda.size())
{
    prregledi = new Pregled *[Max_broj_pregleda];
    int i=0;

    for (auto it (std::begin(spisak_pregleda)); it != (std::end(spisak_pregleda)); it++) {
        prregledi[i] = new Pregled(*it);
        i++;
        broj_pregleda++;
    }

}

Pregledi::~Pregledi()
{
    for (int i = 0; i < Max_broj_pregleda; i++)
        delete prregledi[i];
        delete []prregledi;

}
int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const
{
    if (broj_pregleda==0) throw std::domain_error ("Nema registriranih pregleda");
    int brojnadatum;
    brojnadatum = std::count_if(*prregledi,*prregledi+broj_pregleda,[=](Pregled &pregled) {
        return (pregled.DajDatumPregleda().DajDan() ==
                datum.DajDan() && pregled.DajDatumPregleda().DajMjesec() == datum.DajMjesec() && pregled.DajDatumPregleda().DajGodinu()==datum.DajGodinu()
               );
    });
    return brojnadatum;
}

Pregled &Pregledi::DajNajranijiPregled()
{
    if (broj_pregleda==0) throw std::domain_error ("Nema registriranih pregleda");
    return *std::min_element(*prregledi,*prregledi+broj_pregleda,[](Pregled a, Pregled b) {
        return DolaziPrije3(a,b);
    });
}

Pregled Pregledi::DajNajranijiPregled() const
{

    if (broj_pregleda==0) throw std::domain_error ("Nema registriranih pregleda");
    return *std::min_element(*prregledi,*prregledi+broj_pregleda,[](Pregled a, Pregled b) {
        return DolaziPrije3(a,b);
    });

}

void Pregledi::ObrisiNajranijiPregled()
{

    if (broj_pregleda==0) throw std::domain_error ("Prazna kolekcija");
    Pregled p2 = Pregledi::DajNajranijiPregled();
    Pregledi temp = Pregledi(Max_broj_pregleda);
    int count=0;

    for (int i = 0 ; i < broj_pregleda; i++) {
        auto p1 = prregledi[i];
        if (p1->DajImePacijenta() == p2.DajImePacijenta()  &&
                p1->DajDatumPregleda().DajDan() == p2.DajDatumPregleda().DajDan() &&
                p1->DajDatumPregleda().DajMjesec() == p2.DajDatumPregleda().DajMjesec()&&
                p1->DajDatumPregleda().DajGodinu() == p2.DajDatumPregleda().DajGodinu() &&
                p1->DajVrijemePregleda().DajSate() == p2.DajVrijemePregleda().DajSate() &&
                p1->DajVrijemePregleda().DajMinute() == p2.DajVrijemePregleda().DajMinute())     continue;

        temp.prregledi[count++] = prregledi[i];

    }
    std::copy (temp.prregledi,temp.prregledi+Max_broj_pregleda,prregledi);
    broj_pregleda--;

}

void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta)
{

    if (broj_pregleda>0) {
        Pregledi pomocni = Pregledi(Max_broj_pregleda);
        int count = 0;
        for (int i = 0; i < broj_pregleda; i++) {
            if (prregledi[i]->DajImePacijenta()==ime_pacijenta) continue;
            pomocni.prregledi[count++] = prregledi[i];
        }
        broj_pregleda = count;
        std::copy (pomocni.prregledi,pomocni.prregledi+Max_broj_pregleda,prregledi);
    }
}

void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const
{
    int count = 0;
    Pregledi temp = Pregledi(Max_broj_pregleda);
    for (int i = 0; i < broj_pregleda; i++) {
        if (prregledi[i]->DajDatumPregleda().DajDan() ==
                datum.DajDan() && prregledi[i]->DajDatumPregleda().DajMjesec() == datum.DajMjesec() && prregledi[i]->DajDatumPregleda().DajGodinu()==datum.DajGodinu())
            temp.prregledi[count++] = prregledi[i];
        else continue;

    }
    std::sort (temp.prregledi,temp.prregledi+count,[](Pregled *a, Pregled *b) {
        return DolaziPrije3(*a,*b);
    });

    for (int i = 0; i <count; i++) temp.prregledi[i]->Ispisi();
}

void Pregledi::IspisiSvePreglede() const
{
 
    std::vector<Pregled> temp;
    for (int i = 0; i < broj_pregleda; i++) 
    temp.push_back(*prregledi[i]);
    
    
    
    std::sort (temp.begin(),temp.end(),[](Pregled *a, Pregled *b) {
        return DolaziPrije3(*a,*b);
    });
    
    
    for (int i = 0; i < broj_pregleda; i++) temp[i].Ispisi();

}

Pregledi &Pregledi::operator = (const Pregledi &pregled)
{

    Max_broj_pregleda = pregled.Max_broj_pregleda;
    broj_pregleda = pregled.Max_broj_pregleda;
    for (int i = 0; i < Max_broj_pregleda; i++)
        this->prregledi[i] = new Pregled { "Inicijalizacija", { 1, 1, 1 }, { 1, 1 } };
    std::copy (pregled.prregledi, pregled.prregledi+pregled.Max_broj_pregleda,prregledi);
    return *this;


}

Pregledi &Pregledi::operator = (Pregledi &&pregled)
{

    Max_broj_pregleda = pregled.Max_broj_pregleda;
    broj_pregleda = pregled.Max_broj_pregleda;
    this->prregledi = pregled.prregledi;
    pregled.prregledi = 0;
    return *this;

}




int main ()

{
    int n;




    std::cout << "Unesite maksimalan broj pregleda: ";
    std::cin >> n;
    Pregledi glavni (n);

    
try {
    for (int i = 0; i < n; i++) {
        std::cin.ignore (1000,'\n');
    std::string stringy;
        std::cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        std::getline (std::cin,stringy);
        int a,b,c,d,e;
        if (stringy=="kraj") break;


        std::cout << "Unesite dan mjesec i godinu pregleda: ";
        std::cin >>a >> b >> c;

        std::cout << "Unesite sate i minute pregleda: ";
        std::cin >> d >> e;



        Datum pomocni (a,b,c);
        Vrijeme pomocno (d,e);
        Pregled temp (stringy,pomocni,pomocno);
        
        glavni.RegistrirajPregled(&temp);
        
    }
    std::cout << "Trenutno su registrovani sljedeci pregledi\n";
    glavni.IspisiSvePreglede();

} catch(...){};


    return 0;
}
