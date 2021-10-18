/B 2016/2017, Zadaća 4, Zadatak 4
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

class Datum
{
    int dan, mjesec, godina;
public:
    Datum() {}
    Datum(int d, int m, int g) {
        int broj_dana[12] {
            31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
        }
        ;
        if ((g % 4==0 && g % 100 !=0) || g % 400==0) broj_dana[1]++;
        if (g < 1 || d < 1 || m < 1 || m > 12 || d > broj_dana[m - 1]) throw domain_error("Neispravan datum");
        dan=d;
        mjesec=m;
        godina=g;
    }
    void Postavi (int d, int m, int g) {
        int broj_dana[12] {
            31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
        }
        ;
        if ((g % 4==0 && g % 100 !=0) || g % 400==0) broj_dana[1]++;
        if (g < 1 || d < 1 || m < 1 || m > 12 || d > broj_dana[m - 1]) throw domain_error("Neispravan datum");
        dan=d;
        mjesec=m;
        godina=g;
    }
    int DajDan() const {
        return dan;
    }
    int DajMjesec() const {
        return mjesec;
    }
    int DajGodinu() const {
        return godina;
    }
    void Ispisi () {
        cout << dan << "/" << mjesec << "/" << godina;
    }
};

class Kupac
{
    string ime_i_prezime;
    Datum datum;
public:
    Kupac() {}
    Kupac(const string &ip, const Datum &d): datum(d) {
        for (int i=0; i < ip.size(); i++) {
            if (!(isalnum(ip[i]) && ip[i] !='-' && ip[i] != ' ')) throw domain_error("Neispravno ime i prezime");
        }
        ime_i_prezime=ip;
        datum=d;
    }
    void Postavi (const string &ip, const Datum &d) {
        for (int i=0; i < ip.size(); i++) {
            if ((!isalnum(ip[i]) && ip[i] !='-' && ip[i] != ' ')) throw domain_error("Neispravno ime i prezime");
        }
        ime_i_prezime=ip;
        datum=d;
    }
    string DajImePrezime() const {
        return ime_i_prezime;
    }
    Datum DajDatumRodjenja() const {
        return datum;
    }
    void Ispisi () {
        cout << ime_i_prezime << " (" << datum.DajDan() << "/" << datum.DajMjesec() << "/" << datum.DajGodinu() << ")" << endl;
    }
};

class Stan
{
    string adresa;
    int sprat, broj_soba;
    bool namjesten;
    double kvadratura;
public:
    Stan() {}
    Stan(const string &ad, int s, int br, bool nam, double kv) {
        if (s < 0 || br < 0 || kv < 0 || (nam !=1 && nam !=0)) throw domain_error ("Neispravan unos podataka");
        adresa=ad;
        sprat=s;
        broj_soba=br;
        namjesten=nam;
        kvadratura=kv;
    }
    void Postavi (const string &ad, int s, int br, bool nam, double kv) {
        if (s < 0 || br < 0 || kv < 0 || (nam !=1 && nam !=0)) throw domain_error ("Neispravan unos podataka");
        adresa=ad;
        sprat=s;
        broj_soba=br;
        namjesten=nam;
        kvadratura=kv;
    }
    string DajAdresu() const {
        return adresa;
    }
    int DajSprat() const {
        return sprat;
    }
    int DajBrojSoba() const {
        return broj_soba;
    }
    bool DajNamjesten() const {
        return namjesten;
    }
    double DajKvadraturu() const {
        return kvadratura;
    }
    void Ispisi () {
        cout << "Stan se nalazi na adresi " << adresa << " na " << sprat << ". spratu i ima ";
        if (broj_soba < 5 && broj_soba % 10 !=0 && broj_soba % 10 !=1) cout << broj_soba << " sobe. Kvadratura stana je " << kvadratura << " (m^2) i stan ";
        else if (broj_soba==1) cout << broj_soba << " sobu. Kvadratura stana je " << kvadratura << " (m^2) i stan ";
        else cout << broj_soba << " soba. Kvadratura stana je " << kvadratura << " (m^2) i stan ";
        if (namjesten) cout << "je namjesten.";
        else cout << "nije namjesten.";
    }
};

class Prodaja
{
    string ime_agenta_prodaje;
    double cijena_stana;
    Datum datum_prodaje;
    Kupac kupac_stana;
    Stan kupljeni_stan;
public:
    Prodaja() {}
    Prodaja(const string &ime, double cijena, const Datum &datum, const Kupac &kupac, const Stan &stan) {
        ime_agenta_prodaje=ime;
        cijena_stana=cijena;
        datum_prodaje=datum;
        kupac_stana=kupac;
        kupljeni_stan=stan;
    }
    Prodaja(const string &ime_agenta, double cijena, int dan, int mjesec, int godina, string &ime_kupca, const Datum &datum_rodjenja, const string &adresa, int sprat_stana, int soba, bool nam, double kv) {
        ime_agenta_prodaje=ime_agenta;
        cijena_stana=cijena;
        datum_prodaje.Postavi(dan, mjesec, godina);
        kupac_stana.Postavi(ime_kupca, datum_rodjenja);
        kupljeni_stan.Postavi(adresa, sprat_stana, soba, nam, kv);
    }
    void PromijeniKupca(const Kupac &novi_kupac) {
        kupac_stana=novi_kupac;
    }
    void PromijeniStan(const Stan &novi_stan) {
        kupljeni_stan=novi_stan;
    }
    void PromijeniDatumKupovine(const Datum &novi_datum) {
        datum_prodaje=novi_datum;
    }
    void PromijeniCijenuProdaje(const double &nova_cijena) {
        cijena_stana=nova_cijena;
    }
    string DajImeAgenta () const {
        return ime_agenta_prodaje;
    }
    string DajImeKupca () const {
        return kupac_stana.DajImePrezime();
    }
    Datum DajDatumProdaje () const {
        return datum_prodaje;
    }
    double DajCijenuStana () const {
        return cijena_stana;
    }
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
    void Ispisi () {
        cout << "Ime agenta:                   " << ime_agenta_prodaje << endl;
        cout << "Ime kupca:                    ";
        kupac_stana.Ispisi();
        cout << "Zakazani datum prodaje:       ";
        datum_prodaje.Ispisi();
        cout << endl;
        cout << "Cijena stana:                 " << cijena_stana << endl;
        cout << "Informacije o stanu:" << endl;
        kupljeni_stan.Ispisi();
        cout << endl;
    }
};

bool SkupljiStan(const Prodaja &p1, const Prodaja &p2)
{
    return p1.cijena_stana > p2.cijena_stana;
}

bool ProdatPrije(const Prodaja &p1, const Prodaja &p2)
{
    int dat1=p1.datum_prodaje.DajDan() + p1.datum_prodaje.DajMjesec() * 100 + p1.datum_prodaje.DajGodinu() * 10000;
    int dat2=p2.datum_prodaje.DajDan() + p2.datum_prodaje.DajMjesec() * 100 + p2.datum_prodaje.DajGodinu() * 10000;
    return dat1 < dat2;
}

int PorediDatume(const Prodaja &p1, const Prodaja &p2)
{
    int dat1=p1.DajDatumProdaje().DajDan() + p1.DajDatumProdaje().DajMjesec() * 100 + p1.DajDatumProdaje().DajGodinu() * 10000;
    int dat2=p2.DajDatumProdaje().DajDan() + p2.DajDatumProdaje().DajMjesec() * 100 + p2.DajDatumProdaje().DajGodinu() * 10000;
    if (dat1 > dat2) return 1;
    if (dat1==dat2) return 0;
    if (dat1 < dat2) return -1;
}

int main ()
{
    cout << "Dobrodosli!" << endl;
    int input;
    vector<Stan> stanovi;
    vector<Kupac> kupci;
    vector<Prodaja> prodaje;
    do
    {
        cout << "\nIzaberite opciju:" << endl;
        cout << " 0 - kraj\n 1 - uredjivanje stanova\n 2 - uredjivanje kupaca\n 3 - uredjivanje prodaja" << endl;
        cin >> input;
        if (input==0) return 0;
        //Stanovi
        if (input==1)
        {
            int input1;
            do {
                cout << "Izaberite opciju:" << endl;
                cout << " 0 - nazad\n 1 - dodavanje stana\n 2 - uredjivanje stanova\n 3 - ispis svih stanova\n 4 - kraj" << endl;
                cin >> input1;
                cin.ignore(10000, '\n');
                if (input1==0) break;
                //dodaj
                if (input1==1) {
                    while (1) {
                        try {
                            cout << "Unesite adresu: ";
                            string adresa;
                            getline(cin, adresa);
                            cout << "Unesite sprat: ";
                            int sprat;
                            cin >> sprat;
                            cin.ignore(1000, '\n');
                            cout << "Unesite broj soba: ";
                            int sobe;
                            cin >> sobe;
                            cin.ignore(1000, '\n');
                            cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                            int nam;
                            cin >> nam;
                            cout << "Unesite kvadraturu: ";
                            double kv;
                            cin >> kv;
                            Stan tmp;
                            if (nam !=0 && nam !=1) throw domain_error("Neispravan unos podataka");
                            tmp.Postavi(adresa, sprat, sobe, nam, kv);
                            stanovi.push_back(tmp);
                            cout << "Stan je uspjesno dodan!" << endl;
                            cin.ignore(1000, '\n');
                            break;
                        } catch (domain_error x) {
                            cout << "Izuzetak: " << x.what() << endl;
                            cin.ignore(10000, '\n');
                            continue;
                        }
                    }
                }
                //promijeni
                if (input1==2) {
                    try {
                        cout << "Odaberite stan. Dostupni stanovi su:" << endl;
                        for (int i=0;
                                i < stanovi.size();
                                i++) {
                            cout << " " << i + 1 << " - ";
                            stanovi[i].Ispisi();
                            cout << endl;
                        }
                        int k;
                        cin >> k;
                        int inputk;
                        do {
                            cout << "Odaberite polje koje zelite urediti:" << endl;
                            cout << " 0 - nazad\n 1 - adresa\n 2 - sprat\n 3 - broj soba\n 4 - da li je stan namjesten\n 5 - kvadratura\n 6 - sve" << endl;
                            cin >> inputk;
                            cin.ignore(1000, '\n');
                            if (inputk==0) break;
                            if (inputk==1) {
                                while(1) {
                                    try {
                                        string adresa;
                                        cout << "Unesite adresu: ";
                                        getline(cin, adresa);
                                        stanovi[k - 1].Postavi(adresa, stanovi[k - 1].DajSprat(), stanovi[k - 1].DajBrojSoba(), stanovi[k - 1].DajNamjesten(), stanovi[k - 1].DajKvadraturu());
                                        cin.ignore(1000, '\n');
                                        cout << "Stan je uspjesno izmijenjen!";
                                        break;
                                    } catch (domain_error x) {
                                        cout << "Izuzetak: " << x.what() << endl;
                                        cin.ignore(10000, '\n');
                                        continue;
                                    }
                                }break;
                            }
                            if (inputk==2) {
                                while(1) {
                                    try {
                                        int sprat;
                                        cout << "Unesite sprat: ";
                                        cin >> sprat;
                                        stanovi[k - 1].Postavi(stanovi[k - 1].DajAdresu(), sprat, stanovi[k - 1].DajBrojSoba(), stanovi[k - 1].DajNamjesten(), stanovi[k - 1].DajKvadraturu());
                                        cin.ignore(1000, '\n');
                                        cout << "Stan je uspjesno izmijenjen!";
                                        break;
                                    } catch (domain_error x) {
                                        cout << "Izuzetak: " << x.what() << endl;
                                        cin.ignore(10000, '\n');
                                        continue;
                                    }
                                }break;
                            }
                            if (inputk==3) {
                                while(1) {
                                    try {
                                        int sobe;
                                        cout << "Unesite broj soba: ";
                                        cin >> sobe;
                                        stanovi[k - 1].Postavi(stanovi[k - 1].DajAdresu(), stanovi[k - 1].DajSprat(), sobe, stanovi[k - 1].DajNamjesten(), stanovi[k - 1].DajKvadraturu());
                                        cin.ignore(1000, '\n');
                                        cout << "Stan je uspjesno izmijenjen!";
                                        break;
                                    } catch (domain_error x) {
                                        cout << "Izuzetak: " << x.what() << endl;
                                        cin.ignore(10000, '\n');
                                        continue;
                                    }
                                }break;
                            }
                            if (inputk==4) {
                                while(1) {
                                    try {
                                        bool nam;
                                        cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                                        cin >> nam;
                                        stanovi[k - 1].Postavi(stanovi[k - 1].DajAdresu(), stanovi[k - 1].DajSprat(), stanovi[k - 1].DajBrojSoba(), nam, stanovi[k - 1].DajKvadraturu());
                                        cin.ignore(1000, '\n');
                                        cout << "Stan je uspjesno izmijenjen!";
                                        break;
                                    } catch (domain_error x) {
                                        cout << "Izuzetak: " << x.what() << endl;
                                        cin.ignore(10000, '\n');
                                        continue;
                                    }
                                }break;
                            }
                            if (inputk==5) {
                                while(1) {
                                    try {
                                        double kv;
                                        cout << "Unesite kvadraturu: ";
                                        cin >> kv;
                                        stanovi[k - 1].Postavi(stanovi[k - 1].DajAdresu(), stanovi[k - 1].DajSprat(), stanovi[k - 1].DajBrojSoba(), stanovi[k - 1].DajNamjesten(), kv);
                                        cout << "Stan je uspjesno izmijenjen!";
                                        break;
                                    } catch (domain_error x) {
                                        cout << "Izuzetak: " << x.what() << endl;
                                        cin.ignore(10000, '\n');
                                        continue;
                                    }
                                }break;
                            }
                            if (inputk==6) {
                                while(1) {
                                    try {
                                        string adresa;
                                        int sprat, sobe;
                                        bool nam;
                                        double kv;
                                        cout << "Unesite adresu: ";
                                        getline(cin, adresa);
                                        cout << "Unesite sprat: ";
                                        cin >> sprat;
                                        cout << "Unesite broj soba: ";
                                        cin >> sobe;
                                        cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                                        cin >> nam;
                                        cout << "Unesite kvadraturu: ";
                                        cin >> kv;
                                        stanovi[k - 1].Postavi(adresa, sprat, sobe, nam, kv);
                                        cin.ignore(1000, '\n');
                                        cout << "Stan je uspjesno izmijenjen!";
                                        break;
                                    } catch (domain_error x) {
                                        cout << "Izuzetak: " << x.what() << endl;
                                        cin.ignore(10000, '\n');
                                        continue;
                                    }
                                }break;
                            }
                        } while (1);
                    } catch (domain_error x) {
                        cout << "Izuzetak: " << x.what() << endl;
                        cin.ignore(10000, '\n');
                        continue;
                    }
                }
                //ispisi
                if (input1==3) {
                    for (int i=0; i < stanovi.size(); i++) {
                        cout << i + 1 << ". ";
                        stanovi[i].Ispisi();
                        cout << endl;
                    }
                }
                if (input1==4) return 0;
            } while (input1 !=0);
        }
        //Kupci
        if (input==2)
        {
            int input1;
            do {
                cout << "Izaberite opciju:" << endl;
                cout << " 0 - nazad\n 1 - dodavanje kupca\n 2 - uredjivanje kupaca\n 3 - ispis svih kupaca\n 4 - kraj" << endl;
                cin >> input1;
                cin.ignore(10000, '\n');
                if (input1==0) break;
                if (input1==1) {
                    while (1) {
                        try {
                            string ime;
                            int d, m, g;
                            char c;
                            cout << "Unesite ime i prezime kupca: ";
                            getline(cin, ime);
                            cout << "Unesite datum rodjenja (formata d/m/g): ";
                            cin >> d >> c >> m >> c >> g;
                            Kupac tmp;
                            tmp.Postavi(ime, Datum(d, m, g));
                            cin.ignore(10000, '\n');
                            kupci.push_back(tmp);
                            cout << "Kupac je uspjesno dodan!" << endl;
                            break;
                        } catch (domain_error x) {
                            cout << "Izuzetak: " << x.what() << endl;
                            cin.ignore(10000, '\n');
                            continue;
                        }
                    }
                }
                if (input1 == 2) {
                    cout << "Odaberite kupce kojeg zelite urediti. Dostupni kupci su:" << endl;
                    for (int i = 0; i < kupci.size(); i++) {
                        cout << " " << i + 1 << " - ";
                        kupci[i].Ispisi();
                    }
                    int inputk;
                    cin >> inputk;
                    cin.ignore(1000, '\n');
                    while (1) {
                        try {
                            cout << "Unesite ime i prezime kupca: ";
                            string ip;
                            getline(cin, ip);
                            cout << "Unesite datum rodjenja (formata d/m/g): ";
                            int d, m, g;
                            char c;
                            cin >> d >> c >> m >> c >> g;
                            kupci[inputk - 1].Postavi(ip, Datum(d, m, g));
                            cin.ignore(1000, '\n');
                            cout << "Kupac uspjesno izmijenjen!" << endl;
                            break;
                        } catch (domain_error x) {
                            cout << "Izuzetak: " << x.what() << endl;
                            cin.ignore(10000, '\n');
                            continue;
                        }
                    }
                }
                if (input1 == 3) {
                    for (int i = 0; i < kupci.size(); i++) kupci[i].Ispisi();
                }
                if (input1 == 4) return 0;
            } while (1);
        }
        //Prodaje
        if (input==3) {
            int input1;
            do{
                cout << "Izaberite opciju:" << endl;
                cout << " 0 - nazad\n 1 - dodavanje prodaje\n 2 - uredjivanje prodaje\n 3 - ispis prodaja\n 4 - brisanje prodaja\n 5 - kraj" << endl;
                cin >> input1;
                cin.ignore(1000, '\n');
                if (input1 == 0) break;
                if (input1 == 1)
                {
                    while (1)
                    {
                        try
                        {
                            int inputk;
                            cout << "Izaberite opciju: " << endl;
                            cout << " 0 - nazad\n 1 - dodavanje potpuno nove prodaje\n 2 - dodavanje nove prodaje na osnovu arhive\n 3 - kraj" << endl;
                            cin >> inputk;
                            cin.ignore(10000,'\n');
                            if (inputk == 0) break;
                            if(inputk == 1)
                            {
                                while(1)
                                {
                                    try
                                    {
                                        string imea, imek, adresa;
                                        Datum datump, datumk;
                                        double cijena, kv;
                                        int sprat, sobe, nam, d, m, g;
                                        
                                        cout << "Unesite ime i prezime agenta prodaje: ";
                                        getline(cin, imea);
                                        
                                        cout << "Unesite datum prodaje (formata d/m/g): ";
                                        char c;
                                        cin >> d >> c >> m >> c >> g;
                                        
                                        cout << "Unesite cijenu stana: ";
                                        cin >> cijena;
                                        cin.ignore(1000, '\n');
                                        
                                        cout << "Unesite ime kupca: ";
                                        getline(cin, imek);
                                        
                                        cout << "Unesite datum rodjenja kupca (formata d/m/g): ";
                                        cin >> d >> c >> m >> c >> g;
                                        cin.ignore(1000, '\n');
                                        
                                        cout << "Unesite adresu: ";
                                        getline(cin, adresa);
                                        
                                        cout << "Unesite sprat: ";
                                        cin >> sprat;
                                        
                                        cout << "Unesite broj soba: ";
                                        cin >> sobe;
                                        
                                        cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                                        cin >> nam;
                                        
                                        cout << "Unesite kvadraturu: ";
                                        cin >> kv;
                                        
                                        if (nam !=0 && nam !=1) throw domain_error("Neispravan unos podataka");
                                        
                                        Prodaja tmp(imea, cijena, d, m, g, imek, Datum (d, m, g), adresa, sprat, sobe, nam, kv);
                                        prodaje.push_back(tmp);
                                        cout << "Prodaja uspjesno dodana!" << endl;
                                        break;
                                    }
                                    catch (domain_error x) {
                                        cout << "Izuzetak: " << x.what() << endl;
                                        cin.ignore(10000, '\n');
                                        continue;
                                    }
                                }
                            }
                            if (inputk == 2)
                            {
                                
                            }
                            if (inputk == 3) return 0;
                        }
                        catch (domain_error x) {
                            cout << "Izuzetak: " << x.what() << endl;
                            cin.ignore(10000, '\n');
                            continue;
                        }
                        break;
                    }
                }
                if (input1 == 3)
                {
                    for (int i = 0; i < prodaje.size(); i++) 
                    {
                        cout << i + 1 << "." << endl;
                        prodaje[i].Ispisi();
                    }
                }
                if (input1 == 5) return 0;
            } while (1);
        }
    } while (input !=0);
    return 0;
}