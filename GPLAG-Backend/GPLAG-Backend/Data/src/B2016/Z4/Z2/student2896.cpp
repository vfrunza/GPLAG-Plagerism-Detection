/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <string>

class GradjaninBiH
{
    public:
    enum Pol
    {
        Musko, Zensko  
    };
    private:
    std::string ime;
    int JMBG[13];
    GradjaninBiH* prethodni;
    static GradjaninBiH* posljedni;
    static bool IspravanDatum(int d, int m, int g)
    {
        if(g < 1917 || g > 2017) return false;
        if(d<0 || d>31) return false;
        if(m<0 || m>12) return false;
        if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
        {
            if(d>31) return false;
        }
        if(m==4 || m==6 || m==9 || m==11)
        {
            if(d>30) return false;
        }
        if(m==2)
        {
            if((g%4 == 0 && g%100 != 0) || g%400 == 0)
            {
                if(d>29) return false;
            }
            else
            {
                if(d>28) return false;
            }
        }
        return true;
    }
    int ce13()
    {
    return 11-(7*(JMBG[0]+JMBG[6])+6*(JMBG[1]+JMBG[7])+5*(JMBG[2]+JMBG[8])+4*(JMBG[3]+JMBG[9])+3*(JMBG[4]+JMBG[10])+2*(JMBG[5]+JMBG[11]))%11;
    }
    public:
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg)
    {
        auto it = posljedni;
        for(it = posljedni; it!=nullptr; it=it->prethodni)
        {
            if(it->DajJMBG() == jmbg) throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
        }
        ime = ime_i_prezime;
        int br = 0;
        long long int pomocni = jmbg;
        while(pomocni!=0)
        {
            JMBG[12-br] = pomocni%10;
            pomocni = pomocni/10;
            br++;
        }
        if(br< 12 || br > 13) throw std::logic_error("JMBG nije validan");
        if(br==12) JMBG[0] = 0;
        int dan,mjesec,godina,regija,kod,kontrolna;
        dan = JMBG[0]*10 + JMBG[1];
        mjesec = JMBG[2]*10 + JMBG[3];
        godina = JMBG[4]*100 + JMBG[5]*10 + JMBG[6];
        regija = JMBG[7]*10 + JMBG[8];
        kod = JMBG[9]*100 + JMBG[10]*10 + JMBG[11];
        kontrolna = JMBG[12];
    int c13=11-(7*(JMBG[0]+JMBG[6])+6*(JMBG[1]+JMBG[7])+5*(JMBG[2]+JMBG[8])+4*(JMBG[3]+JMBG[9])+3*(JMBG[4]+JMBG[10])+2*(JMBG[5]+JMBG[11]))%11;
        if(c13 == 11) c13  = 0;
        if(c13 == 10) throw std::logic_error("JMBG nije validan");
        if(c13 != JMBG[12]) throw std::logic_error("JMBG nije validan");
        int god;
        if(godina > 17 && godina < 917) throw std::logic_error("JMBG nije validan");
        if(godina <= 17) god = 2000 + 17;
        if(godina >= 917) god = 1000 + godina;
        if(!IspravanDatum(dan, mjesec, god)) throw std::logic_error("JMBG nije validan");
        if(!posljedni)
        {
            prethodni = nullptr;
        }
        else
        {
            prethodni = posljedni;
        }
        posljedni = this;
    }
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol)
    {
        ime = ime_i_prezime;
        if(!IspravanDatum(dan_rodjenja,mjesec_rodjenja,godina_rodjenja)) throw std::logic_error("Neispravni podaci");
        if(sifra_regije < 0 ||sifra_regije > 99) throw std::logic_error("Neispravni podaci");
        JMBG[0] = (dan_rodjenja/10)%10;
        JMBG[1] = dan_rodjenja%10;
        JMBG[2] = (mjesec_rodjenja/10)%10;
        JMBG[3] = mjesec_rodjenja%10;
        JMBG[4] = (godina_rodjenja/100)%10;
        JMBG[5] = (godina_rodjenja/10)%10;
        JMBG[6] = godina_rodjenja%10;
        JMBG[7] = (sifra_regije/10)%10;
        JMBG[8] = sifra_regije%10;
       
            if(pol == GradjaninBiH::Pol::Musko)
            {
                for(int i=0; i<500; i++)
                {
                    JMBG[9] = (i/100)%10;
                    JMBG[10] = (i/10)%10;
                    JMBG[11] = i%10;
                    if(ce13()==10) continue;
                    int ima=0;
                    for(auto it = posljedni; it!=nullptr; it=it->prethodni)
                    {
                        int isti=1;
                        for(int j=0; j<12; j++)
                        {
                            if(JMBG[j] != it->JMBG[j]) isti = 0;
                        }
                        if(isti == 1) ima=1;
                    }
                    if(ima==0) break;
                }
            }
            if(pol== GradjaninBiH::Pol::Zensko)
            {
                for(int i=500; i<1000; i++)
                {
                    JMBG[9] = (i/100)%10;
                    JMBG[10] = (i/10)%10;
                    JMBG[11] = i%10;
                    if(ce13() == 10) continue;
                    int ima=0;
                    for(auto it = posljedni; it!=nullptr; it=it->prethodni)
                    {
                        int isti=1;
                        for(int j=0; j<12; j++)
                        {
                            if(JMBG[j] != it->JMBG[j]) isti = 0;
                        }
                        if(isti == 1) ima=1;
                    }
                    if(ima==0) break;
                }
            }
    
    int c13=11-(7*(JMBG[0]+JMBG[6])+6*(JMBG[1]+JMBG[7])+5*(JMBG[2]+JMBG[8])+4*(JMBG[3]+JMBG[9])+3*(JMBG[4]+JMBG[10])+2*(JMBG[5]+JMBG[11]))%11;
            if(c13==11) c13=0;
            if(c13==10) 
            {
                
            }
            JMBG[12] = c13;
        
        if(!posljedni)
        {
            prethodni = nullptr;
        }
        else
        {
            prethodni = posljedni;
        }
        posljedni = this;
    }
    ~GradjaninBiH()
    {
        if(prethodni == nullptr)
        {
            for(auto it = posljedni; it!=nullptr; it = it->prethodni)
            {
                if(it->prethodni == this)
                {
                    it->prethodni = nullptr;
                    break;
                }
            }
        }
        else if(this == posljedni)
        {
            posljedni = prethodni;
        }
        else
        {
            for(auto it = posljedni; it!=nullptr; it=it->prethodni)
            {
                if(it->prethodni == this)
                {
                    it->prethodni = prethodni;
                }
            }
        }
        
    }
    GradjaninBiH(const GradjaninBiH &g) = delete;
    GradjaninBiH &operator=(const GradjaninBiH &g) = delete;
    std::string DajImeIPrezime() const
    {
        std::string imee = ime;
        return imee;
    }
    long long int DajJMBG() const
    {
        long long int broj = 0;
        for(int i=0; i<13; i++)
        {
            broj = broj*10+JMBG[i];
        }
        return broj;
    }
    int DajDanRodjenja() const
    {
        int danr=0;
        danr = JMBG[0]*10+JMBG[1];
        return danr;
    }
    int DajMjesecRodjenja() const
    {
        return JMBG[2]*10+JMBG[3];
    }
    int DajGodinuRodjenja() const
    {
        if(JMBG[4] == 9) return 1000+JMBG[4]*100+JMBG[5]*10+JMBG[6];
        if(JMBG[4] == 0) return 2000+JMBG[4]*100+JMBG[5]*10+JMBG[6];
        return 0;
    }
    int DajSifruRegije() const
    {
        return JMBG[7]*10+JMBG[8];
    }
    Pol DajPol() const
    {
        if(JMBG[9] <= 4) return GradjaninBiH::Pol::Musko;
        return GradjaninBiH::Pol::Zensko;
    }
    void PromijeniImeIPrezime(std::string novo_ime)
    {
        ime = novo_ime;
    }
 
};


GradjaninBiH* GradjaninBiH::posljedni(nullptr);

int main ()
{
    /*std::string ime = "Gile Sampion";
    //GradjaninBiH g(ime,12,12,1992,17,GradjaninBiH::Pol::Musko);
    GradjaninBiH g(ime, 1212992170000);
    GradjaninBiH d(ime, 12, 12, 1992, 17, GradjaninBiH::Pol::Musko);
    std::cout << g.DajJMBG() << std::endl;
    std::cout << d.DajJMBG();
    std::cout << g.DajImeIPrezime() << std::endl;
    g.PromijeniImeIPrezime("Medo Brundo");
    std::cout << g.DajImeIPrezime() << std::endl;
    GradjaninBiH g("Hasiba",10,9,1994,18,GradjaninBiH::Pol::Zensko);
    std::cout << g.DajJMBG() << std::endl;*/
    std::cout << "Koliko gradjana zelite unijeti po JMBG? \n";
    int n;
    std::cin >> n;
    std::cin.ignore(1000,'\n');
    GradjaninBiH *niz[100];
    for(int i=0; i<100; i++)
    {
        niz[i] = nullptr;
    }
    int i;
    for(i=0; i<n; i++)
    {
        std::cout << "Unesite ime i prezime (u istom redu): \n";
        std::string imeiprezime;
        std::getline(std::cin, imeiprezime);
        long long int jmbg;
        std::cout << "Unesite JMBG: \n";
        std::cin >> jmbg;
        std::cin.ignore(1000,'\n');
        try
        {
            niz[i] = new GradjaninBiH(imeiprezime,jmbg);
            std::cout << "Unijeli ste gradjanina " << niz[i]->DajImeIPrezime() << " rodjenog " << niz[i]->DajDanRodjenja();
            std::cout << "." << niz[i]->DajMjesecRodjenja() << "." << niz[i]->DajGodinuRodjenja() << " u regiji ";
            std::cout << niz[i]->DajSifruRegije() << ", ";
            if(niz[i]->DajPol() == GradjaninBiH::Pol::Musko) std::cout << "musko.";
            else std::cout << "zensko.";
            std::cout << std::endl;
        }
        catch(std::logic_error &e)
        {
            std::cout << e.what() << std::endl;
            delete niz[i];
            niz[i] = nullptr;
            i--;
        }
        
    }
    std::cout << "Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? \n";
    int m;
    std::cin >> m;
    std::cin.ignore(1000,'\n');
    for(int j=i; j<i+m; j++)
    {
        std::cout << "Unesite ime i prezime (u istom redu): \n";
        std::string imeiprezime;
        std::getline(std::cin, imeiprezime);
        std::cout << "Unesite datum rodjenja (format dd/mm/gggg): \n";
        char z1,z2;
        int d,m,g;
        std::cin >> d >> z1 >> m >> z2 >> g;
        if(z1!='/' || z2!='/')
        {
            std::cout << "Neispravni podaci\n";
            j--;
            continue;
        }
        std::cout << "Unesite sifru regije: \n";
        int sifra;
        std::cin >> sifra;
        std::cout << "Unesite M za musko, Z za zensko: \n";
        char spol;
        std::cin >> spol;
        std::cin.ignore(1000,'\n');
        GradjaninBiH::Pol spoll;
        if(spol == 'M') spoll = GradjaninBiH::Pol::Musko;
        else if(spol == 'Z') spoll = GradjaninBiH::Pol::Zensko;
        else
        {
            std::cout << "Neispravni podaci" << std::endl;
            j--;
            continue;
        }
        try
        {
            niz[j] = new GradjaninBiH(imeiprezime,d,m,g,sifra,spoll);
            std::cout << "Unijeli ste gradjanina " << niz[j]->DajImeIPrezime() << " JMBG: ";
            std::cout << niz[j]->DajJMBG() << ".";
            std::cout << std::endl;
        }
        catch(std::logic_error &e)
        {
            std::cout << e.what() << std::endl;
            delete niz[j];
            niz[j] = nullptr;
            j--;
        }
        
    }
    for(i=0;i<100;i++)
    {
        delete niz[i];
    }
	return 0;
}