/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <iomanip>

class GradjaninBiH
{
    std::string ime_i_prezime;
    long long int JMBG;

    GradjaninBiH *prethodni = nullptr;
    static GradjaninBiH *posljednji;
public:
    enum Pol {Musko, Zensko};
    
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol);
    ~GradjaninBiH();
    
    std::string DajImeIPrezime() const { return ime_i_prezime; }
    long long int DajJMBG() const { return JMBG; }
    int DajDanRodjenja() const { return JMBG / 100000000000; }
    int DajMjesecRodjenja() const { return (JMBG / 1000000000)%100; }
    int DajGodinuRodjenja() const 
    {
        int godina((JMBG / 1000000)%1000);
        if(godina <= 17) godina += 2000;
        else godina += 1000;
        return godina;
    }
    int DajSifruRegije() const { return (JMBG / 10000)%100; }
    Pol DajPol() const
    {
        short x((JMBG / 10)%1000);
        if(x >= 0 && x < 500) return Pol::Musko;
        return Pol::Zensko;
    }
    void PromijeniImeIPrezime(std::string novo_ime) { ime_i_prezime = novo_ime;}
};

GradjaninBiH* GradjaninBiH::posljednji = nullptr;

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg) : ime_i_prezime(ime_i_prezime), JMBG(jmbg)
{
    int dan(DajDanRodjenja()), mjesec(DajMjesecRodjenja()), godina(DajGodinuRodjenja()%1000);
    if(dan <= 0 || dan > 31 || mjesec <= 0 || mjesec > 12 || godina < 0)
      throw std::logic_error("JMBG nije validan");
    
    int sifra(DajSifruRegije()), pol(JMBG/10%1000), Kc(JMBG%10);
    int c[]{dan/10, dan%10, mjesec/10, mjesec%10, godina/100, godina/10%10, godina%10, sifra/10, sifra%10, pol/100, pol/10%10, pol%10};
    int c13(11 - (7 * (c[0] + c[6]) + 6 * (c[1] + c[7]) + 5 * (c[2] + c[8]) + 4 * (c[3] + c[9]) + 3 * (c[4] + c[10]) + 2 * (c[5] + c[11]))%11);
    
    if(c13 == 11) c13 = 0;
    if(c13 == 10 || c13 != Kc)
      throw std::logic_error("JMBG nije validan");
      
    for(auto i(posljednji); i != nullptr; i = i->prethodni)
      if(jmbg == i->DajJMBG()) 
        throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
    
    if(posljednji != nullptr)
    {
        prethodni = posljednji;
    }
    posljednji = this;
}

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol) : ime_i_prezime(ime_i_prezime)
{
    if(dan_rodjenja <= 0 || dan_rodjenja > 31 || mjesec_rodjenja <= 0 || mjesec_rodjenja > 12 || godina_rodjenja < 0 || sifra_regije < 0 || sifra_regije > 99)
      throw std::logic_error("Neispravni podaci");
    
    godina_rodjenja = godina_rodjenja%1000;
    
    int br(0);
    for(auto i(posljednji); i != nullptr; i = i->prethodni)
    {
        if(dan_rodjenja == i->DajDanRodjenja() && mjesec_rodjenja == i->DajMjesecRodjenja() && godina_rodjenja == i->DajGodinuRodjenja() && 
           sifra_regije == i->DajSifruRegije() && pol == i->DajPol())
        {
            br++;
        }
    }
    
    int sex(((pol == Pol::Musko) ? 0 : 500) + br);
    int c[]{dan_rodjenja/10, dan_rodjenja%10, mjesec_rodjenja/10, mjesec_rodjenja%10, godina_rodjenja/100, godina_rodjenja/10%10, godina_rodjenja%10,
            sifra_regije/10, sifra_regije%10, sex/100, sex/10%10, sex%10};
    int c13(11 - (7 * (c[0] + c[6]) + 6 * (c[1] + c[7]) + 5 * (c[2] + c[8]) + 4 * (c[3] + c[9]) + 3 * (c[4] + c[10]) + 2 * (c[5] + c[11]))%11);
    
    if(c13 == 11) c13 = 0;
    
    JMBG = dan_rodjenja;
    JMBG *= 100;
    JMBG += mjesec_rodjenja;
    JMBG *= 1000;
    JMBG += godina_rodjenja;
    JMBG *= 100;
    JMBG += sifra_regije;
    JMBG *= 1000;
    JMBG += sex;
    JMBG *= 10;
    JMBG += c13;
    
    prethodni = posljednji;
    posljednji = this;
}

GradjaninBiH::~GradjaninBiH()
{
    if(this == posljednji)
    {
        posljednji = posljednji->prethodni;
        return;
    }
    
    GradjaninBiH* prethodni;
    for(auto i(posljednji); i != this; i = i->prethodni) prethodni = i;
    
    if(this->prethodni == nullptr) prethodni = nullptr;
    else prethodni->prethodni = this->prethodni; 
}

int main ()
{
    int n;
    std::cout << "Koliko gradjana zelite unijeti po JMBG? ";
    std::cin >> n;
    
    for(int i(0); i < n; i++)
    {
        try
        {
            std::cin.ignore(10000, '\n');
            std::cout << std::endl;
            
            std::string ime_i_prezime;
            std::cout << "Unesite ime i prezime (u istom redu): ";
            std::getline(std::cin, ime_i_prezime);
            std::cout << std::endl;
            
            long long int jmbg;
            std::cout << "Unesite JMBG: ";
            std::cin >> jmbg;
            std::cout << std::endl;
            
            GradjaninBiH jadan(ime_i_prezime, jmbg);
            
            std::cout << "Unijeli ste gradjanina " << jadan.DajImeIPrezime() << " rodjenog "
                      << jadan.DajDanRodjenja() << "." << jadan.DajMjesecRodjenja() << "." << jadan.DajGodinuRodjenja() 
                      << " u regiji " << jadan.DajSifruRegije();
            
            if(jadan.DajPol() == GradjaninBiH::Pol::Musko)
              std::cout << ", musko.";
            else
              std::cout << ", zensko.";
        }
        catch(const std::exception &e)
        {
            std::cout << e.what();
            i--;
        }
    }
    
    std::cout << std::endl << "Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? ";
    std::cin >> n;
    
    for(int i(0); i < n; i++)
    {
        try
        {
            std::cin.ignore(10000, '\n');
            std::cout << std::endl;
            
            std::string ime_i_prezime;
            std::cout << "Unesite ime i prezime (u istom redu): ";
            std::getline(std::cin, ime_i_prezime);
            std::cout << std::endl;
            
            char znak;
            int d, m, g;
            std::cout << "Unesite datum rodjenja (format dd/mm/gggg): ";
            std::cin >> d >> znak >> m >> znak >> g;
            std::cout << std::endl;
            
            int sifra;
            std::cout << "Unesite sifru regije: ";
            std::cin >> sifra;
            std::cout << std::endl;
            std::cin.ignore(10000, '\n');
            
            char rod;
            std::cout << "Unesite M za musko, Z za zensko: ";
            std::cin >> rod;
            std::cout << std::endl;
            
            if(rod == 'M')
            {
                GradjaninBiH jadan(ime_i_prezime, d, m, g, sifra, GradjaninBiH::Pol::Musko);
                std::cout << "Unijeli ste gradjanina " << jadan.DajImeIPrezime() << " JMBG: " << jadan.DajJMBG() << ".";
            }
            else
            {
                GradjaninBiH jadan(ime_i_prezime, d, m, g, sifra, GradjaninBiH::Pol::Zensko);
                std::cout << "Unijeli ste gradjanina " << jadan.DajImeIPrezime() << " JMBG: " << jadan.DajJMBG() << ".";
            }
        }
        catch(const std::exception &e)
        {
            std::cout << e.what();
            i--;
        }
    }
	return 0;
}