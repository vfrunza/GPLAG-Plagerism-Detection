/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <string>
#include <algorithm>
#include <iomanip>
#include <new>
#include <vector>

bool dat(int d,int  m, int g)
{
    if(m>12 || m<=0 || d<=0) return false;
    if((m==1 || m==3 || m==5 || m==7 || m==8|| m==10|| m==12)&&d>31) return false;
    if((m==4 || m==6 || m==9 || m==11)&&d>30) return false;
    if((g%400==0 || (g%4==0 && g%100!=0))&&d>29&&m==2) return false;
    if(d>28&&m==2&&!(g%400==0 || (g%4==0 && g%100!=0))) return false;
    return true;
}

class Datum
{
    int d,m,g;
public:
    Datum(int dan, int mjesec, int godina)
    {
        if(!dat(dan,mjesec,godina)) throw std::domain_error("Neispravan datum");
        d=dan,m=mjesec,g=godina;
    }
    void Postavi(int dan, int mjesec, int godina)
    {
        if(!dat(dan,mjesec,godina)) throw std::domain_error("Neispravan datum");
        d=dan,m=mjesec,g=godina;
    }
    int DajDan() const{return d;}
    int DajMjesec() const{return m;}
    int DajGodinu() const{return g;}
    void Ispisi() const{std::cout << d << "/" << m << "/" <<g;}
};

class Kupac
{
    Datum dr;
    std::string ip;
public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja):dr(datum_rodjenja)
    {
        if(std::any_of(ime_i_prezime.begin(),ime_i_prezime.end(),[](char x){return (x!='-'&&x!=' '&&x!=39&&(x<'A'||x>'z'||(x<'a'&&x>'Z')));})) throw std::domain_error("Neispravno ime i prezime");
        ip=ime_i_prezime;
    }
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja)
    {
        dr.Postavi(datum_rodjenja.DajDan(),datum_rodjenja.DajMjesec(),datum_rodjenja.DajGodinu());
        if(std::any_of(ime_i_prezime.begin(),ime_i_prezime.end(),[](char x){return (x!='-'&&x!=' '&&x!=39&&(x<'A'||x>'z'||(x<'a'&&x>'Z')));})) throw std::domain_error("Neispravno ime i prezime");
        ip=ime_i_prezime;
    }
    std::string DajImePrezime() const{return ip;}
    Datum DajDatumRodjenja() const{return dr;}
    void Ispisi() const{std::cout << ip << " (";dr.Ispisi();std::cout << ")";}
};

class Stan
{
    std::string ad;
    int sp,bs;
    bool n;
    double kv;
public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten,double kvadratura)
    {
        if(sprat<0||broj_soba<=0||kvadratura<=0) throw std::domain_error("Neispravan unos podataka");
        ad=adresa;sp=sprat;bs=broj_soba;n=namjesten;kv=kvadratura;
    }
    void Postavi(const std::string &adresa, int sprat, int broj_soba,bool namjesten, double kvadratura)
    {
        if(sprat<0||broj_soba<=0||kvadratura<=0) throw std::domain_error("Neispravan unos podataka");
        ad=adresa;sp=sprat;bs=broj_soba;n=namjesten;kv=kvadratura;
    }
    std::string DajAdresu() const{return ad;}
    int DajSprat() const{return sp;}
    int DajBrojSoba() const{return bs;}
    bool DajNamjesten() const{return n;}
    double DajKvadraturu() const{return kv;}
    void Ispisi() const;
};

class Prodaja
{
    std::string ip;
    double cs;
    Datum dp;
    Kupac kp;
    Stan st;
public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,const Datum &datum_prodaje, const Kupac &kupac_stana,const Stan &kupljeni_stan):dp(datum_prodaje),kp(kupac_stana),st(kupljeni_stan)
    {
        ip=ime_agenta_prodaje;cs=cijena_stana;
    }
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,int dan_prodaje, int mjesec_prodaje, int godina_prodaje,std::string &ime_kupca, const Datum &datum_rodjenja_kupca,const std::string &adresa_stana, int sprat_stana, int broj_soba,bool namjesten_stan, double broj_kvadrata):dp(dan_prodaje,mjesec_prodaje,godina_prodaje),kp(ime_kupca,datum_rodjenja_kupca),st(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata)
    {
        ip=ime_agenta_prodaje;cs=cijena_stana;
    }
    void PromijeniKupca(const Kupac &novi_kupac){kp.Postavi(novi_kupac.DajImePrezime(),novi_kupac.DajDatumRodjenja());} 
    void PromijeniStan(const Stan &novi_stan){st.Postavi(novi_stan.DajAdresu(),novi_stan.DajSprat(),novi_stan.DajBrojSoba(),novi_stan.DajNamjesten(),novi_stan.DajKvadraturu());}
    void PromijeniDatumKupovine(const Datum &novi_datum){dp.Postavi(novi_datum.DajDan(),novi_datum.DajMjesec(),novi_datum.DajGodinu());}
    void PromijeniCijenuProdaje(const double &nova_cijena){cs=nova_cijena;}
    void PromijeniAgenta(const std::string &ime_agenta_prodaje){ip=ime_agenta_prodaje;}
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImeAgenta() const{return ip;}
    std::string DajImeKupca() const{return kp.DajImePrezime();}
    Datum DajDatumProdaje() const{return dp;}
    double DajCijenuStana() const{return cs;}
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
    void Ispisi() const;
};

class Prodaje
{
    Prodaja **pok;
    int max,lok;
public:
    explicit Prodaje(int max_broj_prodaja)
    {
        try
        {
            pok=new Prodaja*[max_broj_prodaja];
        }
        catch(std::bad_alloc x)
        {
            delete[] pok;
        }
        for(int i=0;i<max_broj_prodaja;i++) pok[i]=nullptr;
        max=max_broj_prodaja;
        lok=0;
    }
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);//
    ~Prodaje()
    {
        for(int i=0;i<lok;i++) delete pok[i];
        delete[] pok;
    }
    Prodaje(const Prodaje &prodaje);//
    Prodaje(Prodaje &&prodaje);//
    Prodaje &operator =(const Prodaje &prodaje)
    {
        try
        {
            for(int i=0;i<lok;i++) delete pok[i];
            delete[] pok;
            pok=new Prodaja*[prodaje.max];
            for (int i=0;i<prodaje.max;i++) pok[i]=nullptr;
            try
            {
                for(int i=0;i<prodaje.max;i++) pok[i]=new Prodaja(*prodaje.pok[i]);
                max=prodaje.max;
                lok=prodaje.lok;
            }
            catch(std::bad_alloc x)
            {
                for(int i=0;i<prodaje.max;i++) delete pok[i];
                throw x;
            }
        }
        catch(std::bad_alloc x)
        {
            delete[] pok;
        }
        return *this;
    }
    Prodaje &operator =(Prodaje &&prodaje)
    {
        for(int i=0;i<lok;i++) delete pok[i];
        delete[] pok;
        pok=prodaje.pok;
        max=prodaje.max;
        lok=prodaje.lok;
        prodaje.pok=nullptr;
        prodaje.lok=0;
        return *this;
    }
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,const Stan &kupljeni_stan)
    {
        if(lok<max)
        {
            pok[lok]=new Prodaja(ime_agenta_prodaje,cijena_stana,datum_prodaje,kupac_stana,kupljeni_stan);
            lok++;
        }
        else throw std::range_error("Dostignut maksimalni broj prodaja");
    }
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana, int dan_prodaje,int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata)
    {
        if(lok<max)
        {
            pok[lok]=new Prodaja(ime_agenta_prodaje,cijena_stana,dan_prodaje,mjesec_prodaje,godina_prodaje,ime_kupca,datum_rodjenja_kupca,adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata);
            lok++;
        }
        else throw std::range_error("Dostignut maksimalni broj prodaja");
    }
    void RegistrirajProdaju(Prodaja *prodaja)
    {
        if(lok<max)
        {
            pok[lok]=prodaja;
            lok++;
        }
        else throw std::range_error("Dostignut maksimalni broj prodaja");
    }
    int DajBrojProdaja() const
    {
        return lok;
    }
    int DajBrojProdajaNaDatum(const Datum &datum) const {return std::count_if(pok,pok+lok,[datum](Prodaja* p){return p->DajDatumProdaje().DajDan()==datum.DajDan()&&p->DajDatumProdaje().DajMjesec()==datum.DajMjesec()&&p->DajDatumProdaje().DajGodinu()==datum.DajGodinu();});}
    int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const {return std::count_if(pok,pok+lok,[ime_agenta](Prodaja* p){return p->DajImeAgenta()==ime_agenta;});}
    Prodaja &DajNajranijuProdaju(){return **std::max_element(pok,pok+lok,[](Prodaja* p1,Prodaja* p2){return ProdatPrije(*p1,*p2);});}
    Prodaja DajNajranijuProdaju() const{return **std::max_element(pok,pok+lok,[](Prodaja* p1,Prodaja* p2){return ProdatPrije(*p1,*p2);});}
    Prodaja &DajNajskupljuProdaju(){return **std::max_element(pok,pok+lok,[](Prodaja* p1,Prodaja* p2){return SkupljiStan(*p1,*p2);});}
    Prodaja DajNajskupljuProdaju() const{return **std::max_element(pok,pok+lok,[](Prodaja* p1,Prodaja* p2){return SkupljiStan(*p1,*p2);});}
    void IsprazniKolekciju(){for (int i=0;i<lok;i++) delete pok[i],pok[i]=nullptr;lok=0;}
    void ObrisiNajranijuProdaju();//
    void ObrisiProdajeAgenta(const std::string &ime_agenta);//
    void ObrisiProdajeNaDatum(const Datum &datum);//
    void IspisiProdajeNaDatum(const Datum &datum) const;//
    void IspisiSveProdaje() const;
    Prodaja &DajProdaju(int ind){if(ind>=lok) throw lok;return *pok[ind];}
};

int main ()
{
    std::cout << "Dobrodosli!\n \n ";
    int a,z;
    Prodaje pr(20);
    std::vector<Stan> st;
    std::vector<Kupac> kup;
    while(std::cout << "\nIzaberite opciju:\n 0 - kraj\n 1 - uredjivanje stanova\n 2 - uredjivanje kupaca\n 3 - uredjivanje prodaja\n",std::cin >>a,a)
    {
        if(a==1)
        {
            while(std::cout << "\nIzaberite opciju:\n 0 - nazad\n 1 - dodavanje stana\n 2 - uredjivanje stanova\n 3 - ispis svih stanova\n 4 - kraj\n",std::cin >> z, z)
            {
                if(z==1)
                {
                    label:
                    try
                    {
                        std::string adr;
                        int b,c,e;
                        double d;
                        std::cout << "Unesite adresu: ";
                        char p;
                        if(p=std::cin.peek(),p=='\n') p=getchar();
                        std::getline(std::cin,adr);
                        std::cout << "Unesite sprat: ";
                        std::cin >> b;
                        std::cout << "Unesite broj soba: ";
                        std::cin >> c;
                        std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                        std::cin >> e;
                        std::cout << "Unesite kvadraturu: ";
                        std::cin >> d;
                        if(e!=0 && e!=1) throw std::domain_error("Neispravan unos podataka");
                        Stan s(adr,b,c,e,d);
                        st.push_back(s);
                        std::cout << "Stan je uspjesno dodan!\n";
                    }
                    catch(std::domain_error x)
                    {
                        std::cout << "Izuzetak: " << x.what() << ". Molimo unesite opet.\n";
                        goto label;
                    }
                }
                if(z==3)
                {
                    for(int i=0;i<st.size();i++)
                    {
                        std::cout << i+1 << ". ";
                        st[i].Ispisi();
                        std::cout << "\n";
                    }
                }
                if(z==2)
                {
                    int n,m;
                    std::cout <<"Odaberite stan. Dostupni stanovi su:\n";
                    for(int i=0;i<st.size();i++)
                    {
                        std::cout <<" " << i+1 << " - ";
                        st[i].Ispisi();
                    }
                    std::cin >> n;
                    std::cout << "Odaberite polje koje zelite urediti:\n 0 - nazad\n 1 - adresa\n 2 - sprat\n 3 - broj soba\n 4 - da li je stan namjesten\n 5 - kvadratura\n 6 - sve\n";
                    std::cin >> m;
                    std::string adr=st[n-1].DajAdresu();
                    int b=st[n-1].DajSprat(),c=st[n-1].DajBrojSoba(),e=st[n-1].DajNamjesten();
                    double d=st[n-1].DajKvadraturu();
                    label2:
                    try
                    {
                        if(m==1 || m==6)
                        {
                            char p;
                            std::cout << "Unesite adresu: ";
                            if(p=std::cin.peek(),p=='\n') p=getchar();
                            std::getline(std::cin,adr);
                        }
                        if(m==2 || m==6)
                        {
                            std::cout << "Unesite sprat: ";
                            std::cin >> b;
                        }
                        if(m==3 || m==6)
                        {
                            std::cout << "Unesite broj soba: ";
                            std::cin >> c;
                        }
                        if(m==4 || m==6)
                        {
                            std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                            std::cin >> e;
                        }
                        if(m==5 ||m==6)
                        {
                            std::cout << "Unesite kvadraturu: ";
                            std::cin >> d;
                        }
                        st[n-1].Postavi(adr,b,c,e,d);
                        std::cout <<"Stan je uspjesno izmijenjen!\n";
                    }
                    catch(std::domain_error x)
                    {
                        std::cout << "Izuzetak: " << x.what() << ". Molimo unesite opet.\n";
                        goto label2;
                    }
                }
                if(z==4) goto kraj;
            }
        }
        else if(a==2)
        {
            while(std::cout << "\nIzaberite opciju:\n 0 - nazad\n 1 - dodavanje kupca\n 2 - uredjivanje kupaca\n 3 - ispis svih kupaca\n 4 - kraj\n",std::cin >>z,z)
            {
                if(z==1)
                {
                    label3:
                    try
                    {
                        std::string ip;
                        int d,m,g;
                        std::cout << "Unesite ime i prezime kupca: ";
                        char p;
                        if(p=std::cin.peek(),p=='\n') p=getchar();
                        std::getline(std::cin,ip);
                        std::cout << "Unesite datum rodjenja (formata d/m/g): ";
                        std::cin >> d >> p >> m >> p >> g;
                        Kupac k(ip,Datum(d,m,g));
                        kup.push_back(k);
                        std::cout << "Kupac je uspjesno dodan!\n";
                    }
                    catch(std::domain_error x)
                    {
                        std::cout << "Izuzetak: " << x.what() << ". Molimo unesite opet.\n";
                        goto label3;
                    }
                }
                if(z==3)
                {
                    for(int i=0;i<kup.size();i++)
                    {
                        kup[i].Ispisi();
                        std::cout << "\n";
                    }
                }
                if(z==2)
                {
                    int n;
                    std::cout <<"Odaberite kupca kojeg zelite urediti. Dostupni kupci su:\n";
                    for(int i=0;i<kup.size();i++)
                    {
                        std::cout <<" " << i+1 << " - ";
                        kup[i].Ispisi();
                        std::cout << "\n";
                    }
                    std::cin >> n;
                    label4:
                    try
                    {
                        std::string ip;
                        int d,m,g;
                        std::cout << "Unesite ime i prezime kupca: ";
                        char p;
                        if(p=std::cin.peek(),p=='\n') p=getchar();
                        std::getline(std::cin,ip);
                        std::cout << "Unesite datum rodjenja (formata d/m/g): ";
                        std::cin >> d >> p >> m >> p >> g;
                        kup[n-1].Postavi(ip,Datum(d,m,g));
                        std::cout <<"Kupac je uspjesno izmijenjen!\n";
                    }
                    catch(std::domain_error x)
                    {
                        std::cout << "Izuzetak: " << x.what() << ". Molimo unesite opet.\n";
                        goto label4;
                    }
                }
                if(z==4) goto kraj;
            }
        }
        else if(a==3)
        {
            while(std::cout << "\nIzaberite opciju:\n 0 - nazad\n 1 - dodavanje prodaje\n 2 - uredjivanje prodaje\n 3 - ispis prodaja\n 4 - brisanje prodaja\n 5 - kraj\n",std::cin >>z,z)
            {
                if(z==5) goto kraj;
                if(z==1)
                {
                    int b;
                    while(std::cout << "\nIzaberite opciju:\n 0 - nazad\n 1 - dodavanje potpuno nove prodaje\n 2 - dodavanje nove prodaje na osnovu arhive\n 3 - kraj\n",std::cin >>b,b)
                    {
                        if(b==1)
                        {
                            label5:
                            try
                            {
                                std::string ip,ipk,adr;
                                int d,m,g,dk,mk,gk,sp,so,na;
                                double c,kv;
                                std::cout << "Unesite ime i prezime agenta prodaje: ";
                                char p;
                                if(p=std::cin.peek(),p=='\n') p=getchar();
                                std::getline(std::cin,ip);
                                std::cout << "Unesite datum prodaje (formata d/m/g): ";
                                std::cin >> d >> p >> m >> p >> g;
                                std::cout << "Unesite cijenu stana: ";
                                std::cin >> c;
                                std::cout << "Unesite ime kupca: ";
                                if(p=std::cin.peek(),p=='\n') p=getchar();
                                std::getline(std::cin,ipk);
                                std::cout << "Unesite datum rodjenja kupca (formata d/m/g): ";
                                std::cin >> dk >> p >> mk >> p >> gk;
                                Kupac k(ipk,Datum(dk,mk,gk));
                                std::cout << "Unesite adresu: ";
                                if(p=std::cin.peek(),p=='\n') p=getchar();
                                std::getline(std::cin,adr);
                                std::cout << "Unesite sprat: ";
                                std::cin >> sp;
                                std::cout << "Unesite broj soba: ";
                                std::cin >> so;
                                std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                                std::cin >> na;
                                std::cout << "Unesite kvadraturu: ";
                                std::cin >> kv;
                                if(na!=0 && na!=1) throw std::domain_error("Neispravan unos podataka");
                                Stan s(adr,sp,so,na,kv);
                                st.push_back(s);
                                kup.push_back(k);
                                pr.RegistrirajProdaju(ip,c,Datum(d,m,g),k,s);
                                std::cout << "Prodaja uspjesno dodana!\n";
                            }
                            catch(std::domain_error x)
                            {
                                std::cout << "Izuzetak: " << x.what() << ". Molimo unesite opet.\n";
                                goto label5;
                            }
                        }
                        if(b==3) goto kraj;
                        if(b==2)
                        {
                            label6:
                            try
                            {
                                std::string ip,ipk,adr;
                                int d,m,g;
                                double c;
                                std::cout << "Unesite ime i prezime agenta prodaje: ";
                                char p;
                                if(p=std::cin.peek(),p=='\n') p=getchar();
                                std::getline(std::cin,ip);
                                std::cout << "Unesite datum prodaje (formata d/m/g): ";
                                std::cin >> d >> p >> m >> p >> g;
                                std::cout << "Unesite cijenu stana: ";
                                std::cin >> c;
                                int q,n;
                                std::cout <<"Odaberite kupca. Dostupni kupci su:\n";
                                for(int i=0;i<kup.size();i++)
                                {
                                    std::cout <<" " << i+1 << " - ";
                                    kup[i].Ispisi();
                                    std::cout << "\n";
                                }
                                std::cin >> q;
                                std::cout <<"Odaberite stan. Dostupni stanovi su:\n";
                                for(int i=0;i<st.size();i++)
                                {
                                    std::cout <<" " << i+1 << " - ";
                                    st[i].Ispisi();
                                    std::cout << "\n";
                                }
                                std::cin >> n;
                                pr.RegistrirajProdaju(ip,c,Datum(d,m,g),kup[q-1],st[n-1]);
                                std::cout << "Prodaja uspjesno dodana!\n";
                            }
                            catch(std::domain_error x)
                            {
                                std::cout << "Izuzetak: " << x.what() << ". Molimo unesite opet.\n";
                                goto label6;
                            }
                        }
                    }
                }
                if(z==2)
                {
                    int n;
                    std::cout << "Odaberite prodaju koju želite urediti. Dostupne prodaje su: \n";
                    for(int i=0;i<pr.DajBrojProdaja();i++)
                    {
                        std::cout <<i+1 << ".\n";
                        pr.DajProdaju(i).Ispisi();
                    }
                    std::cin >> n;
                    Prodaja &p=pr.DajProdaju(n-1);
                    std::cout << "\nIzaberite opciju:\n 0 - nazad\n 1 - izmjena agenta\n 2 - izmjena datuma prodaje\n 3 - izmjena kupca\n 4 - izmjena stana\n 5 - izmjena cijene stana\n";
                    std::cin >> n;
                    if(n==1)
                    {
                        std::string ip;
                        std::cout << "Unesite ime i prezime agenta prodaje: ";
                        char q;
                        if(q=std::cin.peek(),q=='\n') q=getchar();
                        std::getline(std::cin,ip);
                        p.PromijeniAgenta(ip);
                    }
                    if(n==2)
                    {
                        label7:
                        try
                        {
                            int d,m,g;
                            char c;
                            std::cout << "Unesite datum prodaje (formata d/m/g): ";
                            std::cin >> d >> c >> m >> c >> g;
                            p.PromijeniDatumKupovine(Datum(d,m,g));
                        }
                        catch(std::domain_error x)
                        {
                            std::cout << "Izuzetak: " << x.what() << ". Molimo unesite opet.\n";
                            goto label7;
                        }
                    }
                    if(n==3)
                    {
                        int b;
                        std::cout << "\nIzaberite opciju:\n 0 - nazad\n 1 - odabir postojeceg kupca\n 2 - dodavanje novog kupca\n";
                        std::cin >> b;
                        if(b==1)
                        {
                            int q;
                            std::cout <<"Odaberite kupca. Dostupni kupci su:\n";
                            for(int i=0;i<kup.size();i++)
                            {
                                std::cout <<" " << i+1 << " - ";
                                kup[i].Ispisi();
                                std::cout << "\n";
                            }
                            std::cin >>q;
                            p.PromijeniKupca(kup[q-1]);
                        }
                        if(b==2)
                        {
                            label8:
                            try
                            {
                                std::string ip;
                                int d,m,g;
                                std::cout << "Unesite ime i prezime kupca: ";
                                char q;
                                if(q=std::cin.peek(),q=='\n') q=getchar();
                                std::getline(std::cin,ip);
                                std::cout << "Unesite datum rodjenja (formata d/m/g): ";
                                std::cin >> d >> q >> m >> q >> g;
                                kup[n-1].Postavi(ip,Datum(d,m,g));
                                p.PromijeniKupca(Kupac(ip,Datum(d,m,g)));
                            }
                            catch(std::domain_error x)
                            {
                                std::cout << "Izuzetak: " << x.what() << ". Molimo unesite opet.\n";
                                goto label8;
                            }
                        }
                    }
                    if(n==4)
                    {
                        int b;
                        std::cout << "\nIzaberite opciju:\n 0 - nazad\n 1 - odabir postojeceg stana\n 2 - dodavanje novog stana\n";
                        std::cin >> b;
                        if(b==1)
                        {
                            int q;
                            std::cout <<"Odaberite stan. Dostupni stanovi su:\n";
                            for(int i=0;i<st.size();i++)
                            {
                                std::cout <<" " << i+1 << " - ";
                                st[i].Ispisi();
                                std::cout << "\n";
                            }
                            std::cin >>q;
                            p.PromijeniStan(st[q-1]);
                        }
                        if(b==2)
                        {
                            label9:
                            try
                            {
                                std::string adr;
                                int f,c,e;
                                double d;
                                std::cout << "Unesite adresu: ";
                                char q;
                                if(q=std::cin.peek(),q=='\n') q=getchar();
                                std::getline(std::cin,adr);
                                std::cout << "Unesite sprat: ";
                                std::cin >> f;
                                std::cout << "Unesite broj soba: ";
                                std::cin >> c;
                                std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                                std::cin >> e;
                                std::cout << "Unesite kvadraturu: ";
                                std::cin >> d;
                                if(e!=0 && e!=1) throw std::domain_error("Neispravan unos podataka");
                                Stan s(adr,f,c,e,d);
                                st.push_back(s);
                                p.PromijeniStan(s);
                            }
                            catch(std::domain_error x)
                            {
                                std::cout << "Izuzetak: " << x.what() << ". Molimo unesite opet.\n";
                                goto label9;
                            }
                        }
                    }
                    if(n==5)
                    {
                        double cj;
                        std::cout << "Unesite cijenu stana: ";
                        std::cin >> cj;
                        p.PromijeniCijenuProdaje(cj);
                    }
                    std::cout << "Prodaja je uspjesno izmijenjena!\n";
                }
                if(z==3)
                {
                    int b;
                    while(std::cout << "\nIzaberite opciju:\n 0 - nazad\n 1 - ispis svih prodaja\n 2 - ispis prodaja na datum\n 3 - ispis najranije prodaje\n 4 - ispis najskuplje prodaje\n 5 - ispis broja prodaja\n 6 - ispis broja prodaja po datumu\n 7 - ispis broja prodaja po agentu\n 8 - kraj\n",std::cin >>b,b)
                    {
                        if(b==8) goto kraj;
                        if(b==1)
                        {
                            pr.IspisiSveProdaje();
                        }
                        if(b==2)
                        {
                            label10:
                            try
                            {
                                int d,m,g;
                                std::cout << "Unesite datum (d/m/g): ";
                                char q;
                                std::cin >> d >> q >> m >> q >> g;
                                std::cout << "Prodaje na datum 29/5/2017 su: \n";
                                pr.IspisiProdajeNaDatum(Datum(d,m,g));
                            }
                            catch(std::domain_error x)
                            {
                                std::cout << "Izuzetak: " << x.what() << ". Molimo unesite opet.\n";
                                goto label10;
                            }
                        }
                        if(b==3)
                        {
                            pr.DajNajranijuProdaju().Ispisi();
                        }
                        if(b==4)
                        {
                            pr.DajNajskupljuProdaju().Ispisi();
                        }
                        if(b==5)
                        {
                            std::cout << "Broj prodaja: " << pr.DajBrojProdaja();
                        }
                        if(b==6)
                        {
                            int d,m,g;
                            std::cout << "Unesite datum (d/m/g): ";
                            char q;
                            std::cin >> d >> q >> m >> q >> g;
                            std::cout << "Broj prodaja na uneseni datum: " << pr.DajBrojProdajaNaDatum(Datum(d,m,g));
                        }
                        if(b==7)
                        {
                            std::string ip;
                            std::cout << "Unesite ime agenta: ";
                            char q;
                            if(q=std::cin.peek(),q=='\n') q=getchar();
                            std::getline(std::cin,ip);
                            std::cout << "Broj prodaja: " << pr.DajBrojProdajaOdAgenta(ip);
                        }
                    }
                }
                if(z==4)
                {
                    int b;
                    while(std::cout << "\nIzaberite opciju:\n 0 - nazad\n 1 - brisanje najranije prodajee\n 2 - brisanje prodaja agenta\n 3 - brisanje prodaja po datumu\n 4 - brisanje svih prodaja\n",std::cin >>b,b)
                    {
                        if(b==1)
                        {
                            try
                            {
                                pr.ObrisiNajranijuProdaju();
                                std::cout << "Najranija prodaja je obrisana!\n";
                            }
                            catch(std::range_error x)
                            {
                                std::cout << "Izuzetak: " << x.what() << ".\n";
                            }
                        }
                        if(b==2)
                        {
                            std::string ip;
                            std::cout << "Unesite ime agenta: ";
                            char q;
                            if(q=std::cin.peek(),q=='\n') q=getchar();
                            std::getline(std::cin,ip);
                            pr.ObrisiProdajeAgenta(ip);
                            std::cout << "Sve prodaje tog agenta su obrisane.\n";
                        }
                        if(b==3)
                        {
                            int d,m,g;
                            std::cout << "Unesite datum (d/m/g): ";
                            char q;
                            std::cin >> d >> q >> m >> q >> g;
                            pr.ObrisiProdajeNaDatum(Datum(d,m,g));
                            std::cout << "Sve prodaje na taj datum su obrisane.\n";
                        }
                        if(b==4)
                        {
                            pr.IsprazniKolekciju();
                            std::cout << "Sve prodaje su obrisane.\n";
                        }
                    }
                }
            }
        }
    }
    kraj:
    std::cout << "\nDovidjenja!";
	return 0;
}

void Stan::Ispisi() const
{
    std::cout << "Stan se nalazi na adresi " << ad << " na " << sp << ". spratu i ima " << bs << " sob";
    if(bs%10==1 && bs%100!=11) std::cout << "u";
    else if((bs%10==4||bs%10==3||bs%10==2) && (bs%100!=12 &&bs%100!=13&&bs%100!=14)) std::cout << "e";
    else std::cout << "a";
    std::cout << ". Kvadratura stana je "<<kv << " (m^2) i stan ";
    if(!n) std::cout << "ni";
    std::cout << "je namjesten.\n";
}

bool SkupljiStan(const Prodaja &p1, const Prodaja &p2)
{
    return p1.DajCijenuStana()>p2.DajCijenuStana();
}
bool ProdatPrije(const Prodaja &p1, const Prodaja &p2)
{
    if(p1.DajDatumProdaje().DajGodinu()<p2.DajDatumProdaje().DajGodinu()) return true;
    if(p1.DajDatumProdaje().DajGodinu()>p2.DajDatumProdaje().DajGodinu()) return false;
    if(p1.DajDatumProdaje().DajMjesec()<p2.DajDatumProdaje().DajMjesec()) return true;
    if(p1.DajDatumProdaje().DajMjesec()>p2.DajDatumProdaje().DajMjesec()) return false;
    if(p1.DajDatumProdaje().DajDan()<p2.DajDatumProdaje().DajDan()) return true;
    return false;
}
void Prodaja::Ispisi() const
{
    std::cout << "Ime agenta:                     " << DajImeAgenta() << "\nIme kupca:                      ";
    kp.Ispisi();
    std::cout << "\nZakazani datum prodaje:         ";
    dp.Ispisi();
    std::cout << "\nCijena stana:                   " << cs << "\nInformacije o stanu:            \n";
    st.Ispisi();
}
void Prodaja::PomjeriDanUnaprijed()
{
    try
    {
        dp.Postavi(dp.DajDan()+1,dp.DajMjesec(),dp.DajGodinu());
    }
    catch(...)
    {
        try
        {
            dp.Postavi(1,dp.DajMjesec()+1,dp.DajGodinu());
        }
        catch(...)
        {
            dp.Postavi(1,1,dp.DajGodinu()+1);
        }
    }
}
void Prodaja::PomjeriDanUnazad()
{
    try
    {
        dp.Postavi(dp.DajDan()-1,dp.DajMjesec(),dp.DajGodinu());
    }
    catch(...)
    {   
        int a;
        if(dp.DajMjesec()==1) dp.Postavi(31,12,dp.DajGodinu()-1);
        else 
        {
            if(dp.DajMjesec()==2 || dp.DajMjesec()==4||dp.DajMjesec()==6||dp.DajMjesec()==8 ||dp.DajMjesec()==9 ||dp.DajMjesec()==10) a=31;
            else if(dp.DajMjesec()==5 || dp.DajMjesec()==7 || dp.DajMjesec()==10 || dp.DajMjesec()==12) a=30;
            else if(dp.DajMjesec()==3)
            {
                if(dp.DajGodinu()%400==0 || (dp.DajGodinu()%4==0 && dp.DajGodinu()%100!=0)) a=29;
                else a=28;
            }
            dp.Postavi(a,dp.DajMjesec()-1,dp.DajGodinu());
        }
    }
}

Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja)
{
    try
    {
        pok=new Prodaja*[spisak_prodaja.size()];
        for (int i=0;i<spisak_prodaja.size();i++) pok[i]=nullptr;
        try
        {
            int i=0;
            for(auto it=spisak_prodaja.begin();it!=spisak_prodaja.end();it++,i++) pok[i]=new Prodaja(*it);
            max=spisak_prodaja.size();
            lok=spisak_prodaja.size();
        }
        catch(std::bad_alloc x)
        {
            for(int i=0;i<spisak_prodaja.size();i++) delete pok[i];
            throw x;
        }
    }
    catch(std::bad_alloc x)
    {
        delete[] pok;
    }
}
Prodaje::Prodaje(const Prodaje &prodaje)
{
    try
    {
        pok=new Prodaja*[prodaje.max];
        for (int i=0;i<prodaje.max;i++) pok[i]=nullptr;
        try
        {
            for(int i=0;i<prodaje.lok;i++) pok[i]=new Prodaja(*prodaje.pok[i]);
            max=prodaje.max;
            lok=prodaje.lok;
        }
        catch(std::bad_alloc x)
        {
            for(int i=0;i<prodaje.max;i++) delete pok[i];
            throw x;
        }
    }
    catch(std::bad_alloc x)
    {
        delete[] pok;
    }
}
Prodaje::Prodaje(Prodaje &&prodaje)
{
    pok=prodaje.pok;
    max=prodaje.max;
    lok=prodaje.lok;
    prodaje.pok=nullptr;
    prodaje.lok=0;
}
void Prodaje::ObrisiNajranijuProdaju()
{
    if(!lok) throw std::range_error ("Prazna kolekcija");
    Prodaja *pom=*std::max_element(pok,pok+lok,[](Prodaja* p1,Prodaja* p2){return ProdatPrije(*p1,*p2);});
    delete pom;
    pom=nullptr;
    lok--;
    if(lok)
    {
        pom=pok[lok];
        delete pok[lok];
    }
}
void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta)
{
    for(int i=0;i<lok;i++)
    {
        if(pok[i]->DajImeAgenta()==ime_agenta)
        {
            for(int k=i;k<lok-1;k++)
            {
                *pok[k]=*pok[k+1];
            }
            i--;
            lok--;
            delete pok[lok];
            pok[lok]=nullptr;
        }
    }
}
void Prodaje::ObrisiProdajeNaDatum(const Datum &datum)
{
    for(int i=0;i<lok;i++)
    {
        if(pok[i]->DajDatumProdaje().DajDan()==datum.DajDan()&&pok[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec()&&pok[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu())
        {
            for(int k=i;k<lok-1;k++)
            {
                *pok[k]=*pok[k+1];
            }
            i--;
            lok--;
            delete pok[lok];
            pok[lok]=nullptr;
        }
    }
}
void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const
{
    Prodaje p(*this);
    std::sort(p.pok,p.pok+lok,[](Prodaja* p1,Prodaja* p2){return p1->DajImeKupca()<p2->DajImeKupca();});
    int pom=1;
    for(int i=0;i<lok;i++)
    {
        if(p.pok[i]->DajDatumProdaje().DajDan()==datum.DajDan()&&p.pok[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec()&&p.pok[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu())
            std::cout<<"\n" << pom++ << ".\n",p.pok[i]->Ispisi(),std::cout << "\n";
    }
}
void Prodaje::IspisiSveProdaje() const
{
    Prodaje p(*this);
    std::sort(p.pok,p.pok+lok,[](Prodaja* p1,Prodaja* p2){return (p1->DajImeKupca()<p2->DajImeKupca()&&p1->DajDatumProdaje().DajDan()==p2->DajDatumProdaje().DajDan()&&p1->DajDatumProdaje().DajMjesec()==p2->DajDatumProdaje().DajMjesec()&&p1->DajDatumProdaje().DajGodinu()==p2->DajDatumProdaje().DajGodinu())||ProdatPrije(*p1,*p2);});
    for(int i=0;i<lok;i++) std::cout<<"\n",p.pok[i]->Ispisi(),std::cout << "\n";
}