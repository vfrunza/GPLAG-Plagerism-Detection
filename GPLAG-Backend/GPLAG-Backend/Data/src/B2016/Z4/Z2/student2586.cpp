/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!


#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>


int u_cifru(char znak)
{
    return znak - '0';
}

class GradjaninBiH
{
public:
    enum Pol{Musko, Zensko};
private:
    GradjaninBiH* prethodni = nullptr;
    static GradjaninBiH* zadnji;
    std::string _ime;
    std::string _jmbg;
    Pol _pol;
    
    bool provjera_jmbg(long long int jmbg);
    bool da_li_vec_postoji();
    
    void dodaj_u_listu(long long int);
    
    void kreiraj_jmbg(int d, int m, int g, int sr, Pol p);
    void kod_gradjana();
    void popravi_kod();
    
public:
    
    GradjaninBiH(const GradjaninBiH&) = delete;
    GradjaninBiH(GradjaninBiH&&) = delete;

    GradjaninBiH& operator= (const GradjaninBiH&) = delete;
    GradjaninBiH& operator= (GradjaninBiH&&) = delete;

    GradjaninBiH(const std::string& ime, long long int jmbg)
    {
        _ime = ime;
        dodaj_u_listu(jmbg);
        _pol = DajPol();
    }
    
    GradjaninBiH(const std::string& ime, int d, int m, int g, int sr, Pol p);
    
    void PromijeniImeIPrezime(const std::string& s)
    {
        _ime = s;
    }
    
    
    std::string DajImeIPrezime()const
    {
        return _ime;
    }
    
    long long int DajJMBG()const
    {
        return std::stoll(_jmbg);
    }
    
    int DajDanRodjenja()const
    {
        return std::stoi(_jmbg.substr(0, 2));
    }
    
    int DajMjesecRodjenja()const
    {
        return std::stoi(_jmbg.substr(2, 2));
    }
    
    int DajSifruRegije()const
    {
        return std::stoi(_jmbg.substr(7, 2));
    }
    
    Pol DajPol()const
    {
        auto p = std::stoi(_jmbg.substr(9, 3));
        return p < 500 ? Pol::Musko : Pol::Zensko;
    }
    
    int DajGodinuRodjenja()const;
    
    
    ~GradjaninBiH();
};
GradjaninBiH* GradjaninBiH::zadnji = nullptr;

GradjaninBiH::GradjaninBiH(const std::string& ime, int d, int m, int g, int sr, Pol p)
{
    _ime = ime;
    _pol = p;
    kreiraj_jmbg(d, m, g, sr, p);
    if(zadnji == nullptr)
        zadnji = this;
    else{
        prethodni = zadnji;
        zadnji = this;
    }
}

void GradjaninBiH::popravi_kod()
{
    if(_jmbg[11] == '9')
    {
        _jmbg[11] = '0';
        auto a = u_cifru(_jmbg[10]);
        ++a;
        if(a == 10)
        {
            _jmbg = '0';
            _jmbg[9] = u_cifru(_jmbg[9]) + 1 + '0';
        }
        else
            _jmbg[10] = a + '0';
    }
    else 
        _jmbg[11] = u_cifru(_jmbg[11]) + 1 + '0';
}

void GradjaninBiH::kod_gradjana()
{
    OPET:
    for(auto pok = zadnji; pok != nullptr; pok = pok->prethodni)
    {
        if(this == pok)
            continue;
        if(_jmbg == pok->_jmbg.substr(0, 12))
        {
            popravi_kod();
            goto OPET;
        }
            
    }
}

void GradjaninBiH::kreiraj_jmbg(int d, int m, int g, int sr, Pol p)
{
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((g % 4 == 0 && g % 100 != 0) || g % 400 == 0)
        ++broj_dana[1]; 
    if(d < 1 || m < 1 || g < 1 || m > 12 || d > broj_dana[m - 1])
        throw std::logic_error("Neispravni podaci");
    if(sr < 0 || sr > 99)
        throw std::logic_error("Neispravni podaci");
    if(g > 2017 || g <= 1017)
        throw std::logic_error("Neispravni podaci");
    
    if(d < 10)
        _jmbg = "0" + std::to_string(d);
    else
        _jmbg = std::to_string(d);
    if(m < 10)
        _jmbg += "0" + std::to_string(m);
    else
        _jmbg += std::to_string(m);
    
    _jmbg += std::to_string(g).substr(1, 3) + std::to_string(sr);

    if(p == Pol::Musko)
        _jmbg += "000";
    else
        _jmbg += "500";
    
    kod_gradjana();
    
     auto c13 = 11 - (7 * (u_cifru(_jmbg[0]) + u_cifru(_jmbg[6]))  + 6 * (u_cifru(_jmbg[1]) + u_cifru(_jmbg[7])) + 
                     5 * (u_cifru(_jmbg[2]) + u_cifru(_jmbg[8]))  + 4 * (u_cifru(_jmbg[3]) + u_cifru(_jmbg[9])) +
                     3 * (u_cifru(_jmbg[4]) + u_cifru(_jmbg[10])) + 2 * (u_cifru(_jmbg[5]) + u_cifru(_jmbg[11])) ) % 11;
    if(c13 == 10)
        throw std::logic_error("Neispravni podaci");
    if(c13 == 11)
        _jmbg += std::to_string(0);   
    else
        _jmbg += std::to_string(c13);
}

GradjaninBiH::~GradjaninBiH()
{
    // ako brisem zadnji
    if(this == zadnji)
        zadnji = this->prethodni;
    else if(prethodni == nullptr) //ako brisem prvi
    {
        auto q = zadnji->prethodni, p = zadnji;
        while( q != nullptr)
        {
            p = p->prethodni;
            q = q->prethodni;
        }
        p->prethodni = nullptr;
    }
    else //brisem ostale
    {
        auto q = zadnji->prethodni, p = zadnji;
        while( q != this)
        {
            p = p->prethodni;
            q = q->prethodni;
        }
        p->prethodni = this->prethodni;
    }
}

void GradjaninBiH::dodaj_u_listu(long long int jmbg)
{
    if(!provjera_jmbg(jmbg))
        throw std::logic_error("JMBG nije validan");
    if(da_li_vec_postoji())
        throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
        
    if(zadnji == nullptr)
        zadnji = this;
    else{
        prethodni = zadnji;
        zadnji = this;
    }
}

int GradjaninBiH::DajGodinuRodjenja()const
{
    auto b =  std::stoi(_jmbg.substr(4, 3));;
    if(b <= 17 && b >= 10)
        return std::stoll("20" + std::to_string(b));
    if(b >= 0 && b < 10)
        return std::stoll("200" + std::to_string(b));
    if(b > 17 && b <= 99)
        return std::stoll("10" + std::to_string(b));
    return std::stoll("1" + std::to_string(b));
}


bool GradjaninBiH::da_li_vec_postoji()
{
    for(auto pok = zadnji; pok != nullptr; pok = pok->prethodni)
    {
        if(this == pok)
            continue;
        if(_jmbg == pok->_jmbg)
            return true;
    }
    return false;
}

bool GradjaninBiH::provjera_jmbg(long long int jmbg)
{
    if(jmbg < 0)
        return false;

    if( int (std::log10(jmbg)) + 1 == 12  )
        _jmbg = "0" + std::to_string(jmbg);
    else
        _jmbg = std::to_string(jmbg);

    if(_jmbg.size() != 13U)
        return false;
    
    int d = DajDanRodjenja();
    int m = DajMjesecRodjenja();
    int g = DajGodinuRodjenja();
    
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((g % 4 == 0 && g % 100 != 0) || g % 400 == 0)
        ++broj_dana[1]; 
    if(d < 1 || m < 1 || g < 1 || m > 12 || d > broj_dana[m - 1])
        return false;
    if(g > 2017 || g <= 1017)
        return false;
    auto c13 = 11 - (7 * (u_cifru(_jmbg[0]) + u_cifru(_jmbg[6]))  + 6 * (u_cifru(_jmbg[1]) + u_cifru(_jmbg[7])) + 
                     5 * (u_cifru(_jmbg[2]) + u_cifru(_jmbg[8]))  + 4 * (u_cifru(_jmbg[3]) + u_cifru(_jmbg[9])) +
                     3 * (u_cifru(_jmbg[4]) + u_cifru(_jmbg[10])) + 2 * (u_cifru(_jmbg[5]) + u_cifru(_jmbg[11])) ) % 11;
    if(c13 == 10)
        return false;
    if(c13 == 11)
        return _jmbg[12] == '0';
     
    return c13 == u_cifru(_jmbg[12]);
}

int main ()
{
    std::cout << "Koliko gradjana zelite unijeti po JMBG? \n";
    int br_gradjana;
    std::cin >> br_gradjana;
    std::cin.ignore(1000, '\n');
    for(int i = 0; i < br_gradjana; ++i)
    {
        std::cout << "Unesite ime i prezime (u istom redu): \n";
        std::string ime;
        std::getline(std::cin, ime);
        long long int j;
        std::cout << "Unesite JMBG: \n";
        std::cin >> j;
        std::cin.ignore(1000, '\n');
        try {
            GradjaninBiH g (ime, j);
            std::cout << "Unijeli ste gradjanina " << g.DajImeIPrezime() << " rodjenog "
                << g.DajDanRodjenja() << "." << g.DajMjesecRodjenja() << "." << g.DajGodinuRodjenja()
                << " u regiji " << g.DajSifruRegije() << ", " 
                << (g.DajPol() == GradjaninBiH::Pol::Musko ? "musko." : "zensko.") << '\n';
        }
        catch (std::logic_error e) {
            std::cout << e.what() << std::endl;
            --i;
        }
    }
    std::cout << "Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? \n";
    std::cin >> br_gradjana;
    std::cin.ignore(1000, '\n');
    for(int i = 0; i < br_gradjana; ++i)
    {
        std::cout << "Unesite ime i prezime (u istom redu): \n";
        std::string ime;
        std::getline(std::cin, ime);    
        std::cout << "Unesite datum rodjenja (format dd/mm/gggg): \n";
        char znak;
        int d, m, go;
        std::cin >> d >> znak >> m >> znak >> go;
        std::cout << "Unesite sifru regije: \n";
        int sr;
        std::cin >> sr;
        std::cout << "Unesite M za musko, Z za zensko: \n";
        std::cin >> znak;
        std::cin.ignore(1000, '\n');
        try {
            GradjaninBiH g (ime, d, m, go, sr, (znak == 'M' ? GradjaninBiH::Pol::Musko : GradjaninBiH::Pol::Zensko));
            std::cout << "Unijeli ste gradjanina " << g.DajImeIPrezime() << " JMBG: "
                        << g.DajJMBG() << ".\n";
        }
        catch (std::logic_error e) {
            std::cout << e.what() << std::endl;
            --i;
        }
        
    }
	return 0;
}