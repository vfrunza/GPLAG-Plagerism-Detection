#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

class GradjaninBiH
{
    public:
    enum Pol {Musko, Zensko};
    private:
    std::string IME;
    long long int JMBG;
    GradjaninBiH* prethodni = nullptr;
    static GradjaninBiH* posljednji;
    bool IstiJMBG(long long int jmbg);
    bool DaLiJeValidanJMBG(long long int jmbg);
    long long int VratiJMBG(int dan, int mjesec, int godina, int sifra, Pol p);
    int VratiDan(long long int JMBG2) const;
    int VratiMjesec(long long int JMBG2) const;
    int VratiGodinu(long long int JMBG2) const;
    int VratiSifru(long long int JMBG2) const;
    Pol VratiPol(long long int JMBG2) const;
    void IzbaciGradjana();
    int BrojPomjeranjaPola(long long int jmbg2);
    GradjaninBiH(const GradjaninBiH &gradjaninBiH);
    GradjaninBiH(GradjaninBiH &&gradjaninBiH);
    GradjaninBiH &operator =(const GradjaninBiH &gradjaninBiH);
    GradjaninBiH &operator =(GradjaninBiH &&gradjaninBiH);
    public:
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
     int godina_rodjenja, int sifra_regije, Pol pol);
    ~GradjaninBiH() {IzbaciGradjana();}
    std::string DajImeIPrezime() const {return IME;}
    long long int DajJMBG() const {return JMBG;}
    int DajDanRodjenja() const {return VratiDan(JMBG);}
    int DajMjesecRodjenja() const {return VratiMjesec(JMBG);}
    int DajGodinuRodjenja() const {return VratiGodinu(JMBG);}
    int DajSifruRegije() const {return VratiSifru(JMBG);}
    Pol DajPol() const {return VratiPol(JMBG);}
    void PromijeniImeIPrezime(std::string novo_ime){
        IME = novo_ime;}
};
GradjaninBiH* GradjaninBiH::posljednji = nullptr;
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg):IME(ime_i_prezime)
{
    if(!DaLiJeValidanJMBG(jmbg))
        throw std::logic_error("JMBG nije validan");
    if(IstiJMBG(jmbg))
        throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
    JMBG = jmbg;
    if(posljednji == nullptr)
        posljednji = this;
    else
    {
        prethodni = posljednji;
        posljednji = this;
    }
}
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
     int godina_rodjenja, int sifra_regije, Pol pol): IME(ime_i_prezime)
{
    auto jmbg = VratiJMBG(dan_rodjenja, mjesec_rodjenja, godina_rodjenja, sifra_regije, pol);
    if(!DaLiJeValidanJMBG(jmbg))
        throw std::logic_error("JMBG nije validan");
    if(IstiJMBG(jmbg))
        throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
    JMBG = jmbg;
    if(posljednji == nullptr)
        posljednji = this;
    else
    {
        prethodni = posljednji;
        posljednji = this;
    }
}
int GradjaninBiH::VratiDan(long long int JMBG2) const
{
    auto temp = JMBG2/100000000000;
    int suma = 0;
    int k = 1;
    for(int i(0); i < 2; i++)
    {
        suma += (temp % 10) * k;
        k *= 10;
        temp /= 10;
    }
    return suma;
}
int GradjaninBiH::VratiMjesec(long long int JMBG2) const
{
    auto temp = JMBG2/1000000000;
    int suma = 0;
    int k = 1;
    for(int i(0); i < 2; i++)
    {
        suma += (temp % 10) * k;
        k *= 10;
        temp /= 10;
    }
    return suma;
}
int GradjaninBiH::VratiGodinu(long long int JMBG2) const
{
    auto temp = JMBG2/1000000;
    int suma = 0;
    int k = 1;
    for(int i(0); i < 3; i++)
    {
        suma += (temp % 10) * k;
        k *= 10;
        temp /= 10;
    }
    if(suma < 20)
        suma += 2000;
    else suma += 1000;
    return suma;
    
}
int GradjaninBiH::VratiSifru(long long int JMBG2) const
{
    auto temp = JMBG2/10000;
    int suma = 0;
    int k = 1;
    for(int i(0); i < 2; i++)
    {
        suma += (temp % 10) * k;
        k *= 10;
        temp /= 10;
    }
    return suma;
}
GradjaninBiH::Pol GradjaninBiH::VratiPol(long long int JMBG2) const
{
    auto temp = JMBG2/10;
    int suma = 0;
    int k = 1;
    for(int i(0); i < 3; i++)
    {
        suma += (temp % 10) * k;
        k *= 10;
        temp /= 10;
    }
    if(suma < 500)
        return Pol::Musko;
    else
        return Pol::Zensko;
}
bool GradjaninBiH::IstiJMBG(long long int jmbg)
{
    for(auto it(posljednji); it != nullptr; it = it->prethodni)
    {
        if(it == this)
            continue;
        if(it->JMBG == jmbg)
            return true;
    }
    return false;
}
bool GradjaninBiH::DaLiJeValidanJMBG(long long int jmbg)
{
    if(jmbg < 0) return false;
    int dan = VratiDan(jmbg);
    int mjesec = VratiMjesec(jmbg);
    int godina = VratiGodinu(jmbg);
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0)
        ++broj_dana[1];
    if(dan < 1 || dan > broj_dana[mjesec - 1] || mjesec < 1 || mjesec > 12 || godina > 2017 || godina < 1916)
        return false;
        
    int c[14];
    for(int i(13); i > 0; i--)
    {
        c[i] = jmbg % 10;
        jmbg /= 10;
    }
    auto c13 = 11 - (7 * (c[1] + c[7]) + 6 * (c[2] + c[8]) + 5 * (c[3] + c[9]) + 4 * (c[4] + c[10]) +
        3 * (c[5] + c[11]) + 2 * (c[6] + c[12])) % 11;
    if(c13 == 11)
        c13 = 0;
    return c13 == c[13];
}
long long int GradjaninBiH::VratiJMBG(int dan, int mjesec, int godina, int sifra, Pol p)
{
    if(mjesec < 1 || mjesec > 12 || godina > 2017 || godina < 1916)
       throw std::logic_error("Neispravni podaci");
       
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0)
        ++broj_dana[1];
    if(dan < 1 || dan > broj_dana[mjesec - 1])
       throw std::logic_error("Neispravni podaci");
    if(sifra < 0 || sifra > 99)
        throw std::logic_error("Neispravni podaci");
        
    int niz[14];
    if(dan < 10){
        niz[1] = 0;
        niz[2] = dan;
    }
    else{
        niz[1] = dan / 10;
        niz[2] = dan % 10;
    }
    if(mjesec < 10){
        niz[3] = 0;
        niz[4] = mjesec;
    }
    else{
        niz[3] = mjesec / 10;
        niz[4] = mjesec % 10;
    }
    for(int i(7); i >= 5; i--)
    {
        niz[i] = godina % 10;
        godina = godina / 10;
    }
    if(sifra < 10){
        niz[8] = 0;
        niz[9] = sifra;
    }
    else{
        niz[8] = sifra / 10;
        niz[9] = sifra % 10;
    }
    if(p == Pol::Musko)
        for(int i(10); i <= 12; i++)
            niz[i] = 0;
    else{
        niz[10] = 5; niz[11] = 0; niz[12] = 0;
    }
    long long int temp = 0;
    long long int k = 1;
    for(int i(12); i > 0; i--)
    {
        temp += niz[i] * k;
        k *= 10;
    }
    int pomjeranjePola = BrojPomjeranjaPola(temp);
    temp += pomjeranjePola;
    //! Po postavci zadatka gdje pise da 13. cifra treba da krene od najmanjeg broja:
    //int pomjeranjeKoda = BrojPomjeranjaPola(temp);
    //temp *= 10;
    //temp += pomjeranjeKoda;
    //return temp;
    
    /* Po AT-u */
    auto vrati = temp;
    int c[13];
    for(int i(12); i > 0; i--)
    {
        c[i] = temp % 10;
        temp /= 10;
    }
    auto c13 = 11 - (7 * (c[1] + c[7]) + 6 * (c[2] + c[8]) + 5 * (c[3] + c[9]) + 4 * (c[4] + c[10]) +
        3 * (c[5] + c[11]) + 2 * (c[6] + c[12])) % 11;
    if(c13 == 10)
        throw std::logic_error("Neispravni podaci");
    if(c13 == 11)
        c13 = 0;    
    vrati *= 10;
    vrati += c13;
    return vrati;
}
void GradjaninBiH::IzbaciGradjana()
{
    if(this == posljednji)
        posljednji = this->prethodni;
    else
    {
        GradjaninBiH* sljedeci(posljednji->prethodni);
        for(auto it(posljednji); it != nullptr; it = it->prethodni)
            if(sljedeci == this)
            {
                it->prethodni = sljedeci->prethodni;
                break;
            }
    }
}
int GradjaninBiH::BrojPomjeranjaPola(long long int jmbg2)
{
    int brojac = 0;
    for(auto it(posljednji); it != nullptr; it = it->prethodni)
    {
        if(it == this)
            continue;
        auto temp = it->JMBG;
        if(temp/10 == jmbg2)
            brojac++;
    }
    return brojac;
}
int main ()
{
    GradjaninBiH* niz[100];
    int BrojGradjana = 0;
    std::cout << "Koliko gradjana zelite unijeti po JMBG?" << std::endl;
    int brojGradjana;
    std::cin >> brojGradjana;
    std::cin.ignore(1000, '\n');
    for(int i(0); i < brojGradjana; i++)
    {
        std::cout << "Unesite ime i prezime (u istom redu): " << std::endl;
        std::string Ime;
        std::getline(std::cin, Ime);
        long long int Jmbg;
        std::cout << "Unesite JMBG: " << std::endl;
        std::cin >> Jmbg;
        std::cin.ignore(1000, '\n');
        try
        {
            niz[BrojGradjana] = new GradjaninBiH(Ime, Jmbg);
            std::cout << "Unijeli ste gradjanina " << niz[BrojGradjana]->DajImeIPrezime() << " rodjenog " <<
                niz[BrojGradjana]->DajDanRodjenja()<< "." << niz[BrojGradjana]->DajMjesecRodjenja() << "." << 
                niz[BrojGradjana]->DajGodinuRodjenja() << " u regiji " << niz[BrojGradjana]->DajSifruRegije() << ", ";
            if(niz[BrojGradjana]->DajPol() == GradjaninBiH::Pol::Musko)
                std::cout << "musko." << std::endl;
            else
                std::cout << "zensko." << std::endl;
            BrojGradjana++;
        }
        catch(std::bad_alloc)
        {
            for(int i(0); i < BrojGradjana; i++)
                delete niz[i];
            return 0;
        }
        catch(const std::exception &izuzetak)
        {
            std::cout << izuzetak.what() << std::endl;
            i--;
        }
    }
    std::cout << "Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? " << std::endl;
    std::cin >> brojGradjana;
    std::cin.ignore(1000, '\n');
    for(int i(0); i < brojGradjana; i++)
    {
        std::cout << "Unesite ime i prezime (u istom redu): " << std::endl;
        std::string Ime;
        std::getline(std::cin, Ime);
        std::cout << "Unesite datum rodjenja (format dd/mm/gggg): " << std::endl;
        char c;
        int dan, mjesec, godina;
        std::cin >> dan >> c >> mjesec >> c >> godina;
        std::cout << "Unesite sifru regije: " << std::endl;
        int sifra;
        std::cin >> sifra;
        std::cout << "Unesite M za musko, Z za zensko: " << std::endl;
        std::cin >> c;
        std::cin.ignore(1000, '\n');
        try
        {
            if(c == 'M')
                niz[BrojGradjana] = new GradjaninBiH(Ime, dan, mjesec, godina, sifra, GradjaninBiH::Pol::Musko);
            else
                niz[BrojGradjana] = new GradjaninBiH(Ime, dan, mjesec, godina, sifra, GradjaninBiH::Pol::Zensko);
            std::cout << "Unijeli ste gradjanina " << niz[BrojGradjana]->DajImeIPrezime() << " JMBG: " <<
                niz[BrojGradjana]->DajJMBG() << "." << std::endl;
            BrojGradjana++;
        }
        catch(std::bad_alloc)
        {
            for(int i(0); i < BrojGradjana; i++)
                delete niz[i];
            return 0;
        }
        catch(const std::exception &izuzetak)
        {
            std::cout << izuzetak.what() << std::endl;
            i--;
        }
    }
	return 0;
}