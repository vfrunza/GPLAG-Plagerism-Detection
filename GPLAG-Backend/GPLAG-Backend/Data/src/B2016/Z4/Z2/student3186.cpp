/B 2016/2017, Zadaća 4, Zadatak 2
#include <stdexcept>
#include <iostream>
#include <string>

class GradjaninBiH {
public: enum Pol { Musko, Zensko };
private:
    std::string ImePrezime; Pol pol;
    int dan_rodjenja, mjesec_rodjenja, godina_rodjenja, sifra_regije;
    long long int maticni_broj; // Veze izmedju cvorova ..
    GradjaninBiH *veza; static GradjaninBiH *zadnji;
    // Pomocne privatne metode ..
    bool DaLiValjaDatum           (int d, int m, int g)                   const;
    bool ImalIstogMaticnog        (long long int n)                       const;
    long long int GenerisiMaticni (int d, int m, int g, int s_r, int kod) const;
public:
    GradjaninBiH (std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH (std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
        int godina_rodjenja, int sifra_regije, Pol pol);
    ~GradjaninBiH() {
        if (zadnji == this) zadnji = this -> veza; 
        else {
            GradjaninBiH *destruktPOK; for (destruktPOK = zadnji; destruktPOK -> veza != this; destruktPOK = destruktPOK -> veza);
            destruktPOK -> veza = this -> veza;
        }
    }
    std::string DajImeIPrezime() const { return GradjaninBiH::ImePrezime;           };
    long long int DajJMBG()      const { return GradjaninBiH::maticni_broj;         };
    int DajDanRodjenja()         const { return GradjaninBiH::dan_rodjenja;         };
    int DajMjesecRodjenja()      const { return GradjaninBiH::mjesec_rodjenja;      };
    int DajGodinuRodjenja()      const { return GradjaninBiH::godina_rodjenja;      };
    int DajSifruRegije()         const { return GradjaninBiH::sifra_regije;         };
    Pol DajPol()                 const { return GradjaninBiH::pol;                  };
    void PromijeniImeIPrezime (std::string novo_ime);
};  GradjaninBiH *GradjaninBiH::zadnji = nullptr;

bool GradjaninBiH::DaLiValjaDatum (int d, int m, int g) const {
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((g % 4 == 0 and g % 100 != 0) or g % 400 == 0) broj_dana[1]++;
    if (g < 1 or d < 1 or m < 1 or m > 12 or d > broj_dana[m - 1])
        return false;   return true;
}

bool GradjaninBiH::ImalIstogMaticnog (long long int n) const {
    for (auto *it = GradjaninBiH::zadnji; it != nullptr; it = it->veza)
        if (n == it->DajJMBG()) return true; return false;
}

long long int GradjaninBiH::GenerisiMaticni (int d, int m, int g, int s_r, int kod) const {
    long long int mat_generic = 1e11*d + 1e9*m + 1e6*(g%1000) + 1e4*s_r + 1e1*kod;
    int n_mat[13];
    {
        int brojac_cifri{0}, pocetni_index{0}; long long int temp{mat_generic};
        while (temp != 0)   brojac_cifri++, temp /= 10;
        if      (brojac_cifri == 13) pocetni_index = 0;
        else if (brojac_cifri == 12) pocetni_index = 1, n_mat[0] = 0;
        else throw std::logic_error ("Izuzetak"); temp = mat_generic; n_mat[12] = 0;
        for (int i=12; i>=pocetni_index; --i)   n_mat[i] = temp%10, temp /= 10;
    }   //for (int i=0; i<=12; ++i)   std::cout << n_mat[i] << " "; std::cout << std::endl;
    int c13{11-(7*(n_mat[0] + n_mat[6])+ 6*(n_mat[1] + n_mat[7]) + 5*(n_mat[2] + n_mat[8]) + 4*(n_mat[3] + n_mat[9] ) + 3 * (n_mat[4] + n_mat[10]) + 2 * (n_mat[5] + n_mat[11]))%11};
    if (c13 == 11) c13 = 0; else if (c13 == 10)  throw std::logic_error("Izuzetak");  
    return (mat_generic + c13);
}

// Prvi konstruktor ..
GradjaninBiH::GradjaninBiH (std::string ime_i_prezime, long long int jmbg) {
    
    int maticni_niz[13];
    {   // Testiranje da li je format maticnog broja okej.. Takodjer dodavanje nule za 12-cifreni..
        int brojac_cifri{0}, pocetni_index{0}; long long int temp{jmbg};
        while (temp != 0)   brojac_cifri++,   temp /= 10; temp = jmbg;
        if      (brojac_cifri == 13) pocetni_index = 0;
        else if (brojac_cifri == 12) pocetni_index = 1, maticni_niz[0] = 0;
        else throw std::logic_error ("JMBG nije validan");
        for (int i=12; i>=pocetni_index; --i) maticni_niz[i] = temp%10, temp /= 10;
    }
    
    int d{0}, m{0}, g{0}, s_r{0}, kod{0};
    for (int i=0;  i<12; ++i) {
        if      (i >= 0 and i <= 1)  d *= 10, d += maticni_niz[i];
        else if (i >= 2 and i <= 3)  m *= 10, m += maticni_niz[i];
        else if (i >= 4 and i <= 6) {
            if      (maticni_niz[i] == 9 and i == 4) g = 1;
            else if (maticni_niz[i] == 0 and i == 4) g = 2;
                    g *= 10, g += maticni_niz[i];
        }
        else if (i >= 7 and i <= 8)  s_r *= 10, s_r += maticni_niz[i];
        else if (i >= 9 and i <= 11) kod *= 10, kod += maticni_niz[i];
    }   // std::cout << "Dan: " << d << " Mj: " << m << " godina: " << g << " kod: " << kod << " s_r: " << s_r; for (int i=0; i<=12; ++i)   std::cout << maticni_niz[i];    std::cout << std::endl;
    int c13 {11-(7*(maticni_niz[0]+maticni_niz[6])+6*(maticni_niz[1]+maticni_niz[7])+5*(maticni_niz[2]+maticni_niz[8])+4*(maticni_niz[3]+maticni_niz[9])+3*(maticni_niz[4]+maticni_niz[10])+2*(maticni_niz[5]+maticni_niz[11]))%11};
    if (c13 == 11)  c13 = 0;    if (not(DaLiValjaDatum(d, m, g)) or not(c13 == maticni_niz[12]) or g > 2017 or g < 1917 or kod > 999 or kod < 0)    throw std::logic_error ("JMBG nije validan"); 
    if (GradjaninBiH::ImalIstogMaticnog(jmbg)) throw std::logic_error ("Vec postoji gradjanin sa istim JMBG");
    GradjaninBiH::ImePrezime = ime_i_prezime;   GradjaninBiH::dan_rodjenja = d; GradjaninBiH::mjesec_rodjenja = m;  GradjaninBiH::godina_rodjenja = g;  GradjaninBiH::sifra_regije = s_r;   GradjaninBiH::maticni_broj = jmbg;  
    if (kod >= 0 and kod <= 499)  GradjaninBiH::pol = Pol::Musko; else    GradjaninBiH::pol = Pol::Zensko;  veza = zadnji;  zadnji = this;
}

// Drugi konstruktor ..
GradjaninBiH::GradjaninBiH (std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol) {
    if (DaLiValjaDatum(dan_rodjenja, mjesec_rodjenja, godina_rodjenja)) {
        GradjaninBiH::dan_rodjenja = dan_rodjenja;
        GradjaninBiH::mjesec_rodjenja = mjesec_rodjenja;
        GradjaninBiH::godina_rodjenja = godina_rodjenja;
    }   else throw std::logic_error ("Neispravni podaci");
    if (sifra_regije <= 99 and sifra_regije >= 0) {
        GradjaninBiH::sifra_regije = sifra_regije;
    }   else throw std::logic_error ("Neispravni podaci");
    GradjaninBiH::ImePrezime = ime_i_prezime; GradjaninBiH::pol = pol;
    
    int kod_setter(0);  if (pol == Pol::Zensko) kod_setter = 500;
    for (;;) {  // Ovdje treba generisati maticni broj osobe ..
        try {
            long long int mat = GenerisiMaticni(dan_rodjenja, mjesec_rodjenja, godina_rodjenja, sifra_regije, kod_setter);
            if (ImalIstogMaticnog(mat)) kod_setter++;
            else {
                GradjaninBiH::maticni_broj = mat; 
                veza = zadnji; zadnji = this; break;
            }
        }   catch (std::logic_error) {
            kod_setter++;
        }
    }
}

void GradjaninBiH::PromijeniImeIPrezime (std::string novo_ime) {
    GradjaninBiH::ImePrezime = novo_ime;
}

int main ()
{ 
    try {
        int broj_gradjana;
        std::cout << "Koliko gradjana zelite unijeti po JMBG? " << std::endl;
        std::cin >> broj_gradjana; std::cin.ignore (10000, '\n');
        
        for (int i=0; i<broj_gradjana; ++i) {
            std::string input_;
            std::cout << "Unesite ime i prezime (u istom redu): " << std::endl;
            std::getline (std::cin, input_);
            
            long long int input_maticni_;
            std::cout << "Unesite JMBG: " << std::endl;
            std::cin >> input_maticni_;
            
            try {
                GradjaninBiH neka_osoba (input_, input_maticni_);
                std::cout << "Unijeli ste gradjanina " << neka_osoba.DajImeIPrezime() << " rodjenog " << neka_osoba.DajDanRodjenja() << ".";
                std::cout << neka_osoba.DajMjesecRodjenja() << "." << neka_osoba.DajGodinuRodjenja() << " u regiji " << neka_osoba.DajSifruRegije();
                std::cout << ", "; if (neka_osoba.DajPol() == GradjaninBiH::Pol::Musko) std::cout << "musko."; else std::cout << "zensko.";
                std::cout << std::endl; std::cin.clear(); std::cin.ignore(10000, '\n');
            }   catch (std::logic_error txt) {
                std::cout << txt.what() << std::endl; --i;
                std::cin.clear(); std::cin.ignore(10000, '\n');
            }
        }
        
        std::cout << "Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? " << std::endl;
        std::cin >> broj_gradjana; std::cin.ignore(10000, '\n');
        
        for (int i=0; i<broj_gradjana; ++i) {
            std::string input_;
            std::cout << "Unesite ime i prezime (u istom redu): " << std::endl;
            std::getline (std::cin, input_);

            std::string input;
            std::cout << "Unesite datum rodjenja (format dd/mm/gggg): " << std::endl;
            std::getline (std::cin, input);
            
            int d{0}, m{0}, g{0};
            for (int x=0; x<input.length(); ++x) {
                if      (x == 0 or x == 1)  d *= 10, d += input[x] - '0';
                else if (x == 3 or x == 4)  m *= 10, m += input[x] - '0';
                else if (x >= 6 and x <= 9) g *= 10, g += input[x] - '0';
                else if (input[x] == '/' or input[x] == '\n')   continue;
                else throw std::logic_error ("Neispravni podaci");
            }
            
            int s_r;
            std::cout << "Unesite sifru regije: " << std::endl;
            std::cin >> s_r; std::cin.clear(); std::cin.ignore (10000, '\n');
            
            char znak;
            std::cout << "Unesite M za musko, Z za zensko: " << std::endl;
            std::cin >> znak;
            
            try {
                GradjaninBiH::Pol pol = GradjaninBiH::Pol::Musko;
                if      (znak == 'M') pol = GradjaninBiH::Pol::Musko;
                else if (znak == 'Z') pol = GradjaninBiH::Pol::Zensko;
                GradjaninBiH neka_osoba (input_, d, m, g, s_r, pol);
                std::cout << "Unijeli ste gradjanina " << neka_osoba.DajImeIPrezime() << " JMBG: " << neka_osoba.DajJMBG() << "." << std::endl;
                std::cin.clear(); std::cin.ignore(10000, '\n');
            }   catch (std::logic_error txt) {
                std::cout << txt.what() << std::endl; --i;
                std::cin.clear(); std::cin.ignore(10000, '\n');
            }
        }
    }   catch (std::logic_error txt) {
        std::cout << txt.what() << std::endl;
    }
	return 0;
}