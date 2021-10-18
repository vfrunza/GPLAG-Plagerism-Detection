/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class GradjaninBiH
{
    string ime_i_prezime;
    long long int jmb;
    GradjaninBiH* prethodni;
    static GradjaninBiH* zadnji;
    bool ProvjeriDatum(int d, int m, int g) 
    {
        int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if((g % 4 == 0 && g % 100 != 0) || g % 400 == 0) broj_dana[1]++;
        if(g < 1 || d < 1 || m < 1 || m > 12 || d > broj_dana[m - 1]) return false;
        return true;
    }
    void ProvjeriJMBG(long long int jmbg);

    public:
        enum Pol {Musko, Zensko};
        GradjaninBiH(string ime_i_prezime, long long int jmbg);
        GradjaninBiH(string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol);
        GradjaninBiH(const GradjaninBiH &g) = delete;
        GradjaninBiH &operator =(const GradjaninBiH &g) = delete;
        string DajImeIPrezime() const { return ime_i_prezime; }
        long long int DajJMBG() const { return jmb; }
        int DajDanRodjenja() const;
        int DajMjesecRodjenja() const;
        int DajGodinuRodjenja() const;
        int DajSifruRegije() const;
        Pol DajPol() const;
        void PromijeniImeIPrezime(string novo_ime) { ime_i_prezime=novo_ime; }
        ~GradjaninBiH();
};

GradjaninBiH* GradjaninBiH::zadnji(nullptr);

GradjaninBiH::~GradjaninBiH()
{
    if(zadnji==this)
    {
        zadnji=zadnji->prethodni;
        this->prethodni=nullptr;
    }
    else
    {
        auto pom(zadnji);
        auto sljedeci(zadnji);
        while(pom!=this)
        {
            sljedeci=pom;
            pom=pom->prethodni;
        }
        auto pom2(pom->prethodni);
        sljedeci->prethodni=pom2;
        pom->prethodni=nullptr;
    }
}

GradjaninBiH::Pol GradjaninBiH::DajPol() const
{
    int niz[13], pol;
    long long int pom(jmb);
    for(int i=12; i>=0; i--)
    {
        niz[i]=pom%10;
        pom/=10;
        if(i==0) break;
    }
    pol=niz[9]*100+niz[10]*10+niz[11];
    if(pol>=0 && pol<500) return Musko;
    return Zensko;
}

int GradjaninBiH::DajSifruRegije() const
{
    int niz[13];
    long long int pom(jmb);
    for(int i=12; i>=0; i--)
    {
        niz[i]=pom%10;
        pom/=10;
        if(i==0) break;
    }
    
    return niz[7]*10+niz[8];
}

int GradjaninBiH::DajGodinuRodjenja() const
{
    int niz[13], godina_rodjenja;
    long long int pom(jmb);
    for(int i=12; i>=0; i--)
    {
        niz[i]=pom%10;
        pom/=10;
        if(i==0) break;
    }
    godina_rodjenja=niz[4]*100+niz[5]*10+niz[6];
    if(niz[5]*10+niz[6]>=0 && niz[5]*10+niz[6]<=17) godina_rodjenja+=2000;
    else godina_rodjenja+=1000;
    return godina_rodjenja;
}

int GradjaninBiH::DajMjesecRodjenja() const
{
    int niz[13];
    long long int pom(jmb);
    for(int i=12; i>=0; i--)
    {
        niz[i]=pom%10;
        pom/=10;
        if(i==0) break;
    }
    
    return niz[2]*10+niz[3];
}

int GradjaninBiH::DajDanRodjenja() const
{
    int niz[13];
    long long int pom(jmb);
    for(int i=12; i>=0; i--)
    {
        niz[i]=pom%10;
        pom/=10;
        if(i==0) break;
    }
    
    return niz[0]*10+niz[1];
}

void GradjaninBiH::ProvjeriJMBG(long long int jmbg)
{
    int niz[13], dan_rodjenja, mjesec_rodjenja, godina_rodjenja;
    long long int pom(jmbg);
    for(int i=12; i>=0; i--)
    {
        niz[i]=pom%10;
        pom/=10;
        if(i==0) break;
    }
    if(pom!=0) throw std::logic_error("JMBG nije validan");
    dan_rodjenja=niz[0]*10+niz[1];
    mjesec_rodjenja=niz[2]*10+niz[3];
    godina_rodjenja=niz[4]*100+niz[5]*10+niz[6];
    if(niz[5]*10+niz[6]>=0 && niz[5]*10+niz[6]<=17) godina_rodjenja+=2000;
    else godina_rodjenja+=1000;
    if(!ProvjeriDatum(dan_rodjenja, mjesec_rodjenja, godina_rodjenja)) throw std::logic_error("JMBG nije validan");
    int zadnja_cifra(11-(7*(niz[0]+niz[6])+6*(niz[1]+niz[7])+5*(niz[2]+niz[8])+4*(niz[3]+niz[9])+3*(niz[4]+niz[10])+2*(niz[5]+niz[11]))%11);
    if(zadnja_cifra==11) zadnja_cifra=0;
    if(zadnja_cifra!=niz[12] || zadnja_cifra==10) throw std::logic_error("JMBG nije validan");
    
    return;
}

GradjaninBiH::GradjaninBiH(string ime_i_prezime, long long int jmbg) : ime_i_prezime(ime_i_prezime)
{
    ProvjeriJMBG(jmbg);
    
    auto pom_pok(zadnji);
    while(pom_pok!=nullptr)
    {
        if(pom_pok->jmb==jmbg) throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
        pom_pok=pom_pok->prethodni;
    }
    prethodni=zadnji;
    zadnji=this;
    jmb=jmbg;
}

GradjaninBiH::GradjaninBiH(string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol) : ime_i_prezime(ime_i_prezime)
{
    if(!ProvjeriDatum(dan_rodjenja, mjesec_rodjenja, godina_rodjenja) || !(sifra_regije>=0 && sifra_regije<=99)) throw std::logic_error("Neispravni podaci");
    
    long long int niz[13];
    
    if(dan_rodjenja>=0 && dan_rodjenja<=9)
    {
        niz[0]=0;
        niz[1]=dan_rodjenja;
    }
    else if(dan_rodjenja>=10 && dan_rodjenja<=31)
    {
        niz[0]=dan_rodjenja/10;
        niz[1]=dan_rodjenja%10;
    }
    if(mjesec_rodjenja>=0 && mjesec_rodjenja<=9)
    {
        niz[2]=0;
        niz[3]=mjesec_rodjenja;
    }
    else if(mjesec_rodjenja>=10 && mjesec_rodjenja<=12)
    {
        niz[2]=1;
        niz[3]=mjesec_rodjenja%10;
    }
    godina_rodjenja%=1000;
    if(godina_rodjenja>=0 && godina_rodjenja<=9)
    {
        niz[4]=0;
        niz[5]=0;
        niz[6]=godina_rodjenja;
    }
    else if(godina_rodjenja>=10 && godina_rodjenja<=17)
    {
        niz[4]=0;
        niz[5]=godina_rodjenja/10;
        niz[6]=godina_rodjenja%10;
    }
    else
    {
        niz[4]=godina_rodjenja/100;
        niz[5]=(godina_rodjenja/10)%10;
        niz[6]=godina_rodjenja%10;
    }
    if(sifra_regije>=0 && sifra_regije<=9)
    {
        niz[7]=0;
        niz[8]=sifra_regije;
    }
    else if(sifra_regije>=10 && sifra_regije<=99)
    {
        niz[7]=sifra_regije/10;
        niz[8]=sifra_regije%10;
    }
    
    if(zadnji==nullptr)
    {
        if(pol==Zensko)
        {
            niz[9]=5; niz[10]=0; niz[11]=0;
            niz[12]=11-(7*(niz[0]+niz[6])+6*(niz[1]+niz[7])+5*(niz[2]+niz[8])+4*(niz[3]+niz[9])+3*(niz[4]+niz[10])+2*(niz[5]+niz[11]))%11;
            if(niz[12]==11) niz[12]=0;
            
        }
        else if(pol==Musko)
        {
            niz[9]=0; niz[10]=0; niz[11]=0;
            niz[12]=11-(7*(niz[0]+niz[6])+6*(niz[1]+niz[7])+5*(niz[2]+niz[8])+4*(niz[3]+niz[9])+3*(niz[4]+niz[10])+2*(niz[5]+niz[11]))%11;
            if(niz[12]==11) niz[12]=0;
        }
    }
    else
    {
        auto pom_pok(zadnji);
        int maks_m(0), maks_z(500);
        bool nasao_m(false), nasao_z(false);
        while(pom_pok!=nullptr)
        {
            auto pom(pom_pok->jmb);
            int niz2[13];
            for(int i=12; i>=0; i--)
            {
                niz2[i]=pom%10;
                pom/=10;
                if(i==0) break;
            }
            int dan, mjesec, godina, regija, kod;
            
            dan=niz2[0]*10+niz2[1];
            mjesec=niz2[2]*10+niz2[3];
            godina=niz2[4]*100+niz2[5]*10+niz2[6];
            regija=niz2[7]*10+niz2[8];
            kod=niz2[9]*100+niz2[10]*10+niz2[11];
            
            if(kod>=0 && kod<=499 && dan==dan_rodjenja && mjesec==mjesec_rodjenja && godina==godina_rodjenja && regija==sifra_regije && kod>=maks_m && pol==Musko)
            {
                maks_m=kod;
                nasao_m=true;
            }
            if(kod>=500 && kod<=999 && dan==dan_rodjenja && mjesec==mjesec_rodjenja && godina==godina_rodjenja && regija==sifra_regije && kod>=maks_z && pol==Zensko)
            {
                maks_z=kod;
                nasao_z=true;
            }
            
            pom_pok=pom_pok->prethodni;
        }
        if(nasao_z) maks_z++;
        if(nasao_m) maks_m++;
        
        if(pol==Zensko) 
        {
            niz[9]=maks_z/100;
            niz[10]=(maks_z/10)%10;
            niz[11]=maks_z%10;
            niz[12]=11-(7*(niz[0]+niz[6])+6*(niz[1]+niz[7])+5*(niz[2]+niz[8])+4*(niz[3]+niz[9])+3*(niz[4]+niz[10])+2*(niz[5]+niz[11]))%11;
            if(niz[12]==11) niz[12]=0;
        }
        else
        {
            if(maks_m>=0 && maks_m<=9)
            {
                niz[9]=0;
                niz[10]=0;
                niz[11]=maks_m;
            }
            if(maks_m>=10 && maks_m<=99)
            {
                niz[9]=0;
                niz[10]=maks_m/10;
                niz[11]=maks_m%10;
            }
            if(maks_m>=100 && maks_m<=499)
            {
                niz[9]=maks_m/100;
                niz[10]=(maks_m/10)%10;
                niz[11]=maks_m%10;
            }
            niz[12]=11-(7*(niz[0]+niz[6])+6*(niz[1]+niz[7])+5*(niz[2]+niz[8])+4*(niz[3]+niz[9])+3*(niz[4]+niz[10])+2*(niz[5]+niz[11]))%11;
            if(niz[12]==11) niz[12]=0;
        }
    }
    jmb=(((((((((((niz[0]*10+niz[1])*10+niz[2])*10+niz[3])*10+niz[4])*10+niz[5])*10+niz[6])*10+niz[7])*10+niz[8])*10+niz[9])*10+niz[10])*10+niz[11])*10+niz[12];
    
    prethodni=zadnji;
    zadnji=this;
}

int main ()
{
    GradjaninBiH* niz[100]{nullptr};
    
    int n;
    cout << "Koliko gradjana zelite unijeti po JMBG? ";
    cin >> n;
    cout << endl;
    if(!cin) cin.clear();
    cin.ignore(1000, '\n');
    
    for(int i=0; i<n; i++)
    {
        string ime_i_prezime;
        cout << "Unesite ime i prezime (u istom redu): ";
        getline(cin, ime_i_prezime);
        
        try
        {
            long long int jmbg;
            cout << endl << "Unesite JMBG: ";
            cin >> jmbg;
            niz[i] = new GradjaninBiH(ime_i_prezime, jmbg);
            if(niz[i]->DajPol()==0) cout << endl << "Unijeli ste gradjanina " << niz[i]->DajImeIPrezime() << " rodjenog " << niz[i]->DajDanRodjenja() << "." << niz[i]->DajMjesecRodjenja() << "." << niz[i]->DajGodinuRodjenja() << " u regiji " << niz[i]->DajSifruRegije() << ", " << "musko." << endl;
            else cout << endl << "Unijeli ste gradjanina " << niz[i]->DajImeIPrezime() << " rodjenog " << niz[i]->DajDanRodjenja() << "." << niz[i]->DajMjesecRodjenja() << "." << niz[i]->DajGodinuRodjenja() << " u regiji " << niz[i]->DajSifruRegije() << ", " << "zensko." << endl;
            if(!cin) cin.clear();
            cin.ignore(1000, '\n');
        }
        catch(std::logic_error izuzetak)
        {
            cout << endl << izuzetak.what() << endl;
            i--;
            if(!cin) cin.clear();
            cin.ignore(1000, '\n');
        }
    }
    
    int m;
    cout << "Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? ";
    cin >> m;
    cout << endl;
    if(!cin) cin.clear();
    cin.ignore(1000, '\n');
    
    for(int i=n; i<n+m; i++)
    {
        string ime_i_prezime;
        cout << "Unesite ime i prezime (u istom redu): ";
        getline(cin, ime_i_prezime);
        
        try
        {
            int dan, mjesec, godina;
            char znak;
            cout << endl << "Unesite datum rodjenja (format dd/mm/gggg): ";
            cin >> dan >> znak >> mjesec >> znak >> godina;
            
            int sifra_regije;
            cout << endl << "Unesite sifru regije: ";
            cin >> sifra_regije;
            if(!cin) cin.clear();
            cin.ignore(1000, '\n');
            
            cout << endl << "Unesite M za musko, Z za zensko: ";
            cin >> znak;
            
            if(znak=='M') niz[i]=new GradjaninBiH(ime_i_prezime, dan, mjesec, godina, sifra_regije, GradjaninBiH::Musko);
            else niz[i]=new GradjaninBiH(ime_i_prezime, dan, mjesec, godina, sifra_regije, GradjaninBiH::Zensko);
            
            cout << endl << "Unijeli ste gradjanina " << niz[i]->DajImeIPrezime() << " JMBG: " << niz[i]->DajJMBG() << "." << endl;
            
            if(!cin) cin.clear();
            cin.ignore(1000, '\n');
        }
        catch(std::logic_error izuzetak)
        {
            cout << endl << izuzetak.what() << endl;
            i--;
            if(!cin) cin.clear();
            cin.ignore(1000, '\n');
        }
    }
    for(int i=0; i<100; i++)
        delete niz[i];
	
	return 0;
}


