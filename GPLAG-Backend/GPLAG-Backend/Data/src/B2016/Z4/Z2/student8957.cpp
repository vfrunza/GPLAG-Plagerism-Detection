/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

class GradjaninBiH
{
    string imePrezime;
    long long int Jmbg;
    int danRodjenja, godinaRodjenja, mjesecRodjenjena, sifraRegije;
    int spol;
public:
    enum Pol {Musko, Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol);
    std::string DajImeIPrezime() const { return imePrezime; }
    long long int DajJMBG() const { return Jmbg; }
    int DajDanRodjenja() const { return danRodjenja; }
    int DajMjesecRodjenja() const { return mjesecRodjenjena; }
    int DajGodinuRodjenja() const { return godinaRodjenja; }
    int DajSifruRegije() const { return sifraRegije; }
    Pol DajPol() const 
    { 
        if(spol == 1) return GradjaninBiH::Pol::Musko;
        else return GradjaninBiH::Pol::Zensko;
    }
    void PromijeniImeIPrezime(std::string novo_ime) { imePrezime = novo_ime; }
};

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg)
{
    int kontrolna, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13;
    long long int jmbg1;
    bool validan = true;

    jmbg1 = jmbg;
    
    c13 = jmbg1 % 10;
    jmbg1 /= 10;
    c12 = jmbg1 % 10;
    jmbg1 /= 10;
    c11 = jmbg1 % 10;
    jmbg1 /= 10;
    c10 = jmbg1 % 10;
    jmbg1 /= 10;
    c9 = jmbg1 % 10;
    jmbg1 /= 10;
    c8 = jmbg1 % 10;
    jmbg1 /= 10;
    c7 = jmbg1 % 10;
    jmbg1 /= 10;
    c6 = jmbg1 % 10;
    jmbg1 /= 10;
    c5 = jmbg1 % 10;
    jmbg1 /= 10;
    c4 = jmbg1 % 10;
    jmbg1 /= 10;
    c3 = jmbg1 % 10;
    jmbg1 /= 10;
    c2 = jmbg1 % 10;
    jmbg1 /= 10;
    c1 = jmbg1 % 10;
    
    kontrolna = 11 - (7 * (c1 + c7) + 6 * (c2 + c8) + 5 * (c3 + c9) + 4 * (c4 + c10) + 3 * (c5 + c11) + 2 * (c6 + c12)) % 11;
    
    if(kontrolna == 11) kontrolna = 0;
    
    if(kontrolna != c13)
        throw logic_error("JMBG nije validan");
        
    if((c1 * 10 + c2) < 1 || (c1 * 10 + c2) > 31) validan = false; // prevjerava da li je dan izmedju 1-31
    if((c3 * 10 + c4) < 1 || (c3 * 10 + c4) > 12) validan = false; // provjerava da li je mjesec izmedju 1-12
    
    int godina;
    
    if((c5 * 100 + c6 * 10 + c7) >= 917 && (c5 * 100 + c6 * 10 + c7) <= 999) godina = 1000 + (c5 * 100 + c6 * 10 + c7); // odredjuje godinu
        else godina = 2000 + (c5 * 100 + c6 * 10 + c7);
    
    int brojDana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // iskoristit za provjeru imal mjesec 30 ili 31 dan
    
    if((c1 * 10 + c2) < 1 || (c1 * 10 + c2) > brojDana[(c3 * 10 + c4) - 1]) validan = false; // provjera za broj dana u mjesecu
    
    if((c10 + c2) == 29 && (c3 * 10 + c4) == 2) // provjera da li je ta godina bila prestupna
    {
        if(!(godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0)) validan = false;
    }
    
    if(!validan)
        throw logic_error("JMBG nije validan");
    
    if((c10 * 100 + c11 * 10 + c12) >= 0 && (c10 * 100 + c11 * 10 + c12) <= 499) spol = 1; // odredjivanje spola
    else spol = 2;
    imePrezime = ime_i_prezime;
    Jmbg = jmbg;
    danRodjenja = c1 * 10 + c2;
    mjesecRodjenjena = c3 * 10 + c4;
    godinaRodjenja = godina;
    sifraRegije = c8 * 10 + c9;
    if((c10 * 100 + c11 * 10 + c12) < 500) spol = 1;
    else spol = 2;
}

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol)
{
    bool validan = true;
    int kontrolna, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, godina;
    godina = godina_rodjenja;
    
    if(dan_rodjenja < 1 || dan_rodjenja > 31) validan = false;
    if(mjesec_rodjenja < 1 || mjesec_rodjenja > 12) validan = false;
    if(godina_rodjenja < 1917 || godina_rodjenja > 2017) validan = false;
    
    int brojDana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if(mjesec_rodjenja <= 12)
        if(dan_rodjenja < 1 || dan_rodjenja > brojDana[mjesec_rodjenja - 1]) validan = false; // provjera za broj dana u mjesecu
    
    if(dan_rodjenja == 29 && mjesec_rodjenja == 2) // provjera da li je ta godina bila prestupna
    {
        if(!(godina_rodjenja % 4 == 0 && godina_rodjenja % 100 != 0 || godina_rodjenja % 400 == 0)) validan = false;
    }
    
    if(sifra_regije < 0 || sifra_regije > 99) validan = false; // provjera regije
    
    c9 = sifra_regije % 10;
    sifra_regije /= 10;
    c8 = sifra_regije % 10;
    
    c7 = godina_rodjenja % 10;
    godina_rodjenja /= 10;
    c6 = godina_rodjenja % 10;
    godina_rodjenja /= 10;
    c5 = godina_rodjenja % 10;
    
    c4 = mjesec_rodjenja % 10;
    mjesec_rodjenja /= 10;
    c3 = mjesec_rodjenja % 10;
    
    c2 = dan_rodjenja % 10;
    dan_rodjenja /= 10;
    c1 = dan_rodjenja % 10;
    
    int muskoZensko;
    
    for(;;)
    {
        if(pol == GradjaninBiH::Pol::Musko)
        {
            muskoZensko = 0;
            c12 = muskoZensko % 10;
            muskoZensko /= 10;
            c11 = muskoZensko % 10;
            muskoZensko /= 10;
            c10 = muskoZensko % 10;
            
            c13 = 11 - (7 * (c1 + c7) + 6 * (c2 + c8) + 5 * (c3 + c9) + 4 * (c4 + c10) + 3 * (c5 + c11) + 2 * (c6 + c12)) % 11;
            
            if(c13 == 10) muskoZensko++;
            else if(c13 == 11) c13 = 0;
            else muskoZensko++;
        }
        else
        {
            muskoZensko = 500;
            c12 = muskoZensko % 10;
            muskoZensko /= 10;
            c11 = muskoZensko % 10;
            muskoZensko /= 10;
            c10 = muskoZensko % 10;
            
            c13 = 11 - (7 * (c1 + c7) + 6 * (c2 + c8) + 5 * (c3 + c9) + 4 * (c4 + c10) + 3 * (c5 + c11) + 2 * (c6 + c12)) % 11;
            
            if(c13 == 10) muskoZensko++;
            else if(c13 == 11) c13 = 0;
            else muskoZensko++;
        }
        
        if(c13 >= 0 && c13 <= 9) break;
    }
    
    if(!validan)
        throw logic_error("Neispravni podaci");
        
    imePrezime = ime_i_prezime;
    danRodjenja = c1 * 10 + c2;
    mjesecRodjenjena = c3 * 10 + c4;
    godinaRodjenja = godina;
    sifraRegije = c8 * 10 + c9;
    if((c10 * 100 + c11 * 10 + c12) < 500) spol = GradjaninBiH::Pol::Musko;
    else spol = GradjaninBiH::Pol::Zensko;
    
    if((c3 * 10 + c4) < 10)
        Jmbg = c1 * 1000000000000 + c2 * 100000000000 + c4 * 1000000000 + c5 * 100000000 + c6 * 10000000 + c7 * 1000000 + c8 * 100000 + c9 * 10000 + c10 * 1000 + c11 * 100 + c12 * 10 + c13;
    else
        Jmbg = c1 * 1000000000000 + c2 * 100000000000 + c3 * 10000000000 + c4 * 1000000000 + c5 * 100000000 + c6 * 10000000 + c7 * 1000000 + c8 * 100000 + c9 * 10000 + c10 * 1000 + c11 * 100 + c12 * 10 + c13;
}

int main ()
{
    GradjaninBiH *gradjani[100];
    int izbor, brEl = 0;
    char a;
    string imePrezime;
    long long int jmbg;
    int dRodjenja, gRodjenja, mRodjenja, sRegije;
    GradjaninBiH::Pol pol;
    
    cout << "Koliko gradjana zelite unijeti po JMBG? " << endl;
    cin >> izbor;
    
    for(int i = 0; i < izbor; i++)
    {
        cin.ignore(1000, '\n');
        cout << "Unesite ime i prezime (u istom redu): " << endl;
        getline(cin, imePrezime);
        cout << "Unesite JMBG: " << endl;
        cin >> jmbg;
        try
        {
            gradjani[brEl] = new GradjaninBiH(imePrezime, jmbg);
            string spol;
            if(gradjani[brEl]->DajPol() == GradjaninBiH::Pol::Musko) spol = "musko";
            else spol = "zensko";
            cout << "Unijeli ste gradjanina " << gradjani[brEl]->DajImeIPrezime() << " rodjenog " << gradjani[brEl]->DajDanRodjenja() << "." << gradjani[brEl]->DajMjesecRodjenja() << "." << gradjani[brEl]->DajGodinuRodjenja() << " u regiji " << gradjani[brEl]->DajSifruRegije() << ", " << spol << "." << endl;
            brEl++;
        }
        catch(logic_error e)
        {
            cout << e.what() << endl;
            i--;
        }
    }
    
    cout << "Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? " << endl;
    cin >> izbor;
    
    for(int i = 0; i < izbor; i++)
    {
        cin.ignore(10000, '\n');
        cout << "Unesite ime i prezime (u istom redu): " << endl;
        getline(cin, imePrezime);
        cout << "Unesite datum rodjenja (format dd/mm/gggg): " << endl;
        cin >> dRodjenja >> a >> mRodjenja >> a >> gRodjenja;
        cout << "Unesite sifru regije: " << endl;
        cin >> sRegije;
        cout << "Unesite M za musko, Z za zensko: " << endl;
        cin >> a;
        if(a == 'M') pol = GradjaninBiH::Pol::Musko;
        else pol = GradjaninBiH::Pol::Zensko;
        try
        {
            gradjani[brEl] = new GradjaninBiH(imePrezime, dRodjenja, mRodjenja, gRodjenja, sRegije, pol);
            string spol;
            cout << "Unijeli ste gradjanina " << gradjani[brEl]->DajImeIPrezime() << " JMBG: " << gradjani[brEl]->DajJMBG() << "." << endl;
            brEl++;
        }
        catch(logic_error e)
        {
            cout << e.what() << endl;
            i--;
        }
    }

	return 0;
}