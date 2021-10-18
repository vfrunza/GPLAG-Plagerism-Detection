#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class GradjaninBiH{
private:
    string ime_i_prezime;
    long long int jmbg;
    int dan_rodjenja, mjesec_rodjenja, godina_rodjenja, sifra_regije, razlika;
    GradjaninBiH * prethodni;
    static GradjaninBiH * zadnji;
    void DodajUListu();
    bool PretraziPoJMBG() const;
    int DajNajmanjuRazliku(int, bool dajSljedeci = false) const; // vraca prvi slobodni kod osobe
public:
    enum Pol {Musko, Zensko} pol;
    GradjaninBiH(string, long long int);
    GradjaninBiH(string, int, int, int, int, Pol);
    GradjaninBiH(const GradjaninBiH&) = delete;
    GradjaninBiH(GradjaninBiH&&) = delete;                                  //upitno
    GradjaninBiH &operator= (const GradjaninBiH&) = delete;
    GradjaninBiH &operator= (GradjaninBiH&&) = delete;                      //upitno
    ~GradjaninBiH();
    string DajImeIPrezime() const { return ime_i_prezime; }
    long long int DajJMBG() const { return jmbg; }
    int DajDanRodjenja() const { return dan_rodjenja; }
    int DajMjesecRodjenja() const { return mjesec_rodjenja; }
    int DajGodinuRodjenja() const { return godina_rodjenja; }
    int DajSifruRegije() const { return sifra_regije; }
    Pol DajPol() const { return pol; }
    void PromijeniImeIPrezime(string novo_ime) { this->ime_i_prezime = novo_ime; }
};

GradjaninBiH::~GradjaninBiH(){
    if(zadnji->jmbg == jmbg && prethodni == nullptr) zadnji = nullptr;
    else if(zadnji->jmbg == jmbg) zadnji = prethodni, prethodni = nullptr;
}

void GradjaninBiH::DodajUListu(){
    prethodni = zadnji;
    zadnji = this;
}

bool GradjaninBiH::PretraziPoJMBG() const {
    GradjaninBiH* gradjanin = zadnji;
    while(gradjanin != nullptr){
        cout << gradjanin->DajImeIPrezime() << endl;
        if(gradjanin->DajJMBG() == jmbg) return true;
        gradjanin = gradjanin->prethodni;
    }
    return false;
}

int GradjaninBiH::DajNajmanjuRazliku(int n, bool dajSljedeci) const {
    int rezultat(n);
    //cout << "n = " << n << endl;
    if(dajSljedeci) rezultat++;
    GradjaninBiH* gradjanin = zadnji;
    while(gradjanin != nullptr){
        if(gradjanin->DajPol() == pol && gradjanin->DajDanRodjenja() == dan_rodjenja && gradjanin->DajMjesecRodjenja() == mjesec_rodjenja &&
            gradjanin->DajGodinuRodjenja() == godina_rodjenja && gradjanin->DajSifruRegije() == sifra_regije && gradjanin->razlika == rezultat)
        {
            rezultat++;
            gradjanin = zadnji;
        }
        else gradjanin = gradjanin->prethodni; 
    }
    return rezultat;
}

GradjaninBiH::GradjaninBiH(string ime_i_prezime, long long int jmbg){
    int c[13]{0};
    int index(12);
    long long int tjmbg(jmbg);
    /*
        pravimo kopiju jer moramo uzeti cifre iz jmbg
        da bi uzeli cifre moramo smanjiti jmbg na 0 a ne zelimo da mjenjamo jmbg
    */
    // provjera da li ima 12 cifara ?!
    while(index != -1){
        c[index] = tjmbg % 10;
        tjmbg /= 10;
        index--;
    }
    int dan = c[0] * 10 + c[1];
    int mjesec = c[2] * 10 + c[3];
    int godina = (c[4] * 10 + c[5]) * 10 + c[6];
    godina < 18 ? godina += 2000 : godina += 1000;
    int regija = c[7] * 10 + c[8];
    int razlika = (c[9] * 10 + c[10]) * 10 + c[11];
    int c13 = 11 - (7 * (c[0] + c[6]) + 6 * (c[1] + c[7]) + 5 * (c[2] + c[8]) + 4 * (c[3] + c[9]) + 3 * (c[4] + c[10]) + 2 * (c[5] + c[11])) % 11;
    if(c13 == 11) c13 = 0;
    int mjeseci[12] { 31, (godina % 4 == 0 || (godina % 100 == 0 && godina % 400 == 0) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    //provjere
    bool nevalja(false);
    if(jmbg < 0) nevalja = true;
    else if(mjesec < 1 || mjesec > 12) nevalja = true;
    else if(dan < 1 || dan > mjeseci[mjesec - 1]) nevalja = true;
    else if(c13 != c[12]) nevalja = true;
    if(nevalja) throw logic_error("JMBG nije validan");
    this->ime_i_prezime = ime_i_prezime;
    dan_rodjenja = dan; mjesec_rodjenja = mjesec; godina_rodjenja = godina; sifra_regije = regija; this->razlika = razlika; this->jmbg = jmbg;
    razlika >= 0 && razlika <= 499 ? pol = Pol::Musko : pol = Pol::Zensko;
    PretraziPoJMBG() ? throw logic_error("Vec postoji gradjanin sa istim JMBG") : DodajUListu(); 
}

GradjaninBiH::GradjaninBiH(string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol){
    bool nevalja(false);
    int mjeseci[12] {31, (godina_rodjenja % 4 == 0 || (godina_rodjenja % 100 == 0 && godina_rodjenja % 400 == 0) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina_rodjenja < 1917 || godina_rodjenja > 2017) nevalja = true;
    else if(mjesec_rodjenja < 1 || mjesec_rodjenja > 12) nevalja = true;
    else if(dan_rodjenja < 1 || dan_rodjenja > mjeseci[mjesec_rodjenja - 1]) nevalja = true;
    else if(sifra_regije < 0 || sifra_regije > 99) nevalja = true;
    if(nevalja) throw logic_error("Neispravni podaci");
    this->ime_i_prezime = ime_i_prezime;
    this->dan_rodjenja = dan_rodjenja;
    this->mjesec_rodjenja = mjesec_rodjenja;
    this->godina_rodjenja = godina_rodjenja;
    this->sifra_regije = sifra_regije;
    this->pol = pol;
    int trazlika = DajNajmanjuRazliku(pol == Pol::Musko ? 0 : 500);
    int c[12] {0};
    int temp = trazlika;
    c[11] = trazlika % 10; trazlika /= 10;
    c[10] = trazlika % 10; trazlika /= 10;
    c[9] = trazlika;
    c[8] = sifra_regije % 10; sifra_regije /= 10;
    c[7] = sifra_regije;
    c[6] = godina_rodjenja % 10; godina_rodjenja /= 10;
    c[5] = godina_rodjenja % 10; godina_rodjenja /= 10;
    c[4] = godina_rodjenja % 10;
    c[3] = mjesec_rodjenja % 10; mjesec_rodjenja /= 10;
    c[2] = mjesec_rodjenja;
    c[1] = dan_rodjenja % 10; dan_rodjenja /= 10;
    c[0] = dan_rodjenja;
    int c13 = 11 - (7 * (c[0] + c[6]) + 6 * (c[1] + c[7]) + 5 * (c[2] + c[8]) + 4 * (c[3] + c[9]) + 3 * (c[4] + c[10]) + 2 * (c[5] + c[11])) % 11;
    
    while(c13 == 10){
        trazlika = DajNajmanjuRazliku(temp, true);
        temp = trazlika;
        c[11] = trazlika % 10; trazlika /= 10;
        c[10] = trazlika % 10; trazlika /= 10;
        c[9] = trazlika;
        c13 = 11 - (7 * (c[0] + c[6]) + 6 * (c[1] + c[7]) + 5 * (c[2] + c[8]) + 4 * (c[3] + c[9]) + 3 * (c[4] + c[10]) + 2 * (c[5] + c[11])) % 11;
        //cout << "c13 = " << c13 << endl;
    }
    //cout << "Ovdje" << endl;
    if(c13 == 11) c13 = 0;
    this->razlika = trazlika;
    this->jmbg = 0;
    for(int i(0); i < 12; i++) this->jmbg += c[i], this->jmbg *= 10;
    this->jmbg += c13;
    while(PretraziPoJMBG()){
        
        trazlika = DajNajmanjuRazliku(temp, true);
        temp = trazlika;
        c[11] = trazlika % 10; trazlika /= 10;
        c[10] = trazlika % 10; trazlika /= 10;
        c[9] = trazlika;
        c13 = 11 - (7 * (c[0] + c[6]) + 6 * (c[1] + c[7]) + 5 * (c[2] + c[8]) + 4 * (c[3] + c[9]) + 3 * (c[4] + c[10]) + 2 * (c[5] + c[11])) % 11;
        while(c13 == 10){
            trazlika = DajNajmanjuRazliku(trazlika, true);
            c[11] = trazlika % 10; trazlika /= 10;
            c[10] = trazlika % 10; trazlika /= 10;
            c[9] = trazlika;
            c13 = 11 - (7 * (c[0] + c[6]) + 6 * (c[1] + c[7]) + 5 * (c[2] + c[8]) + 4 * (c[3] + c[9]) + 3 * (c[4] + c[10]) + 2 * (c[5] + c[11])) % 11;
        }
        if(c13 == 11) c13 = 0;
        this->razlika = trazlika;
        this->jmbg = 0;
        for(int i(0); i < 12; i++) this->jmbg += c[i], this->jmbg *= 10;
        this->jmbg += c13;
        
    }
    
    DodajUListu();
}


GradjaninBiH* GradjaninBiH::zadnji = nullptr;

int main()
{
    return 0;
}

int main2(){
    int pojmbg = 0;
    GradjaninBiH* niz[100];
    int brojac(0);
    cout << "Koliko gradjana zelite unijeti po JMBG? " << endl;
    cin >> pojmbg;
    for(int i(0); i < pojmbg; i++){
        string ime_i_prezime;
        long long int jmbg;
        cout << "Unesite ime i prezime (u istom redu): " << endl;
        cin.clear(); cin.ignore(100, '\n');
        getline(cin, ime_i_prezime);
        cout << "Unesite JMBG: " << endl;
        cin >> jmbg;
        try{
            GradjaninBiH g(ime_i_prezime, jmbg);
            cout << "Unijeli ste gradjanina " << ime_i_prezime << " rodjenog " << g.DajDanRodjenja() << "." << g.DajMjesecRodjenja() << "." <<
                    g.DajGodinuRodjenja() << " u regiji " << g.DajSifruRegije() << ", " << (g.pol == GradjaninBiH::Pol::Musko ? "musko" : "zensko") << "." << endl;
            niz[brojac] = &g;
            brojac++;
        }catch(exception &e){
            cout << e.what() << endl;
            i--;
        }
    }
    int n;
    cout << "Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? " << endl;
    cin >> n;
    for(int i(0); i < n; i++){
        int dan, mjesec, godina;
        string ime_i_prezime;
        int sifra_regije;
        char pol, c;
        cout << "Unesite ime i prezime (u istom redu): " << endl;
        cin.clear(); cin.ignore(100, '\n');
        getline(cin, ime_i_prezime);
        cout << "Unesite datum rodjenja (format dd/mm/gggg): " << endl;
        cin >> dan >> c >> mjesec >> c >> godina;
        cout << "Unesite sifru regije: " << endl;
        cin >> sifra_regije;
        cout << "Unesite M za musko, Z za zensko: " << endl;
        cin >> pol;
        try{
            GradjaninBiH g(ime_i_prezime, dan, mjesec, godina, sifra_regije, pol == 'M' ? GradjaninBiH::Pol::Musko : GradjaninBiH::Pol::Zensko);
            niz[brojac] = &g;
            brojac++;
            cout << "Unijeli ste gradjanina " << ime_i_prezime << " JMBG: " << g.DajJMBG() << "." << endl;
        }catch(exception &e){
            cout << e.what() << endl;
            i--;
        }
    }
    return 0;
}
