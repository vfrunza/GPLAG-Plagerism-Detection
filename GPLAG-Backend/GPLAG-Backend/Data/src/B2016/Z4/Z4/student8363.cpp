/B 2016/2017, Zadaća 4, Zadatak 4
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <initializer_list>
#include <algorithm>
#include <vector>
#include <type_traits>
using std::string;
using std::cout;
using std::endl;
using std::cin;
const int dd[] {31,28,31,  30,31,30,   31,31,30,   31,30,31};
class Datum
{
    int d,m,g;
    void throwerr() {
        throw std::domain_error("Datum nije ispravan");
    }
public:
    Datum(int d, int m, int g) {
        Postavi(d,m,g);
    }
    void Postavi(int d, int m, int g) {
        if(d<0 || m<0 || m>12 || g<0 || (((g%4==0 && g%100!=0) || (g%400==0)) && m==2 && d>29))throwerr();
        if(d>dd[m-1])throwerr();
        this->d=d;
        this->m=m;
        this->g=g;
    }
    int DajDan()const {
        return d;
    }
    int DajMjesec()const {
        return m;
    }
    int DajGodinu()const {
        return g;
    }
    void Ispisi()const {
        cout<<d<<'/'<<m<<'/'<<g;
    }
};
class Kupac
{
    string a;
    Datum r;
    void checkIme()const{
        for (int i = 0; i < a.size(); i++) {
            if(!((a[i]>='a' && a[i]<='z')
            || (a[i]>='A' && a[i]<='Z')
            || (a[i]==' ' || a[i]=='-' || a[i]==39)))throw std::domain_error("Neispravno ime i prezime");
        }
    }
public:
    Kupac(const string &i_p,const Datum &d):a(i_p),r(d) {
        checkIme();
    }
    void Postavi(const string &i_p,const Datum &d) {
        a = i_p;
        this->r = d;
        checkIme();
    }
    string DajImePrezime()const {
        return a;
    }
    Datum DajDatumRodjenja()const {
        return r;
    }
    void Ispisi()const {
        cout<<a<<" (";
        r.Ispisi();
        cout<<")";
    }
};
class Stan
{
    string adr;
    int s,b_s;
    bool n;
    double k;
    void checkParam(int s, int b_s,double k) {
        if(s<0 || b_s<0 || k<0)throw std::domain_error("Neispravan unos podataka.");
    }
public:
    Stan(const string &adr,int s, int b_s,bool n,double k) {
        Postavi(adr,s,b_s,n,k);
    }
    void Postavi(const string &adr,int s, int b_s,bool n,double k) {
        checkParam(s,b_s,k);
        this->adr =adr;
        this->s=s;
        this->b_s=b_s;
        this->n=n;
        this->k=k;
    }
    string DajAdresu()const {
        return adr;
    }
    int DajSprat()const {
        return s;
    }
    int DajBrojSoba()const {
        return b_s;
    }
    bool DajNamjesten()const {
        return n;
    }
    double DajKvadraturu()const {
        return k;
    }
    void Ispisi()const {
        cout<<"Stan se nalazi na adresi "<<adr<<" na "<<s<<". spratu i ima "<<b_s;
        if(b_s==1 || b_s>=5) cout<<" soba";
        else cout<<" sobe";
        cout<<". Kvadratura stana je "<<std::fixed<<std::setprecision(2)<<k<<" (m^2) i stan ";
        if(!n)cout<<"ni";
        cout<<"je namjesten.";
    }
};
class Prodaja
{
    string i_a;
    double c;
    Datum d_p;
    Kupac k;
    Stan s;
    void throwerr() {
        throw std::domain_error("Cijena ne moze biti negativna");
    }
    //mozda da bacim error
    friend void IzmijeniImeAgenta(Prodaja&,const string &);
    friend Kupac DajKupca(const Prodaja&);
    friend Stan DajStan(const Prodaja&);
public:
    Prodaja(const string &i_a,double c,const Datum &d_p,const Kupac &k,const Stan &k_s) :
        i_a(i_a),c(c),d_p(d_p),k(k),s(k_s) {
        if(c<0)throwerr();
    }
    Prodaja(const string &i_a,double c,int d, int m, int g, const string &i_k,const Datum &d_r,const string &adr,int s,int b_s,bool n, double k) :
        i_a(i_a),c(c),d_p(d_r),k(i_k,d_r),s(adr,s,b_s,n,k) {
        if(c<0)throwerr();
    }
    void PromijeniKupca(const Kupac &n_k) {
        k=n_k;
    }
    void PromijeniStan(const Stan &n) {
        s=n;
    }
    void PromijeniDatumKupovine(const Datum &d_k) {
        d_p=d_k;
    }
    void PromijeniCijenuProdaje(const double &nc) {
        if(c<0)throwerr();
        c=nc;
    }
    void PomjerjiDanUnaprijed() {
        int d= d_p.DajDan();
        int m= d_p.DajMjesec();
        int g = d_p.DajGodinu();
        if(d>=1 && d<28) {
            PromijeniDatumKupovine(Datum(d+1,m,g));
        } else if(m==2 && ((!g%4 && !g%100) || !g%400)) {
            if(d==29)PromijeniDatumKupovine(Datum(1,3,g));
            else PromijeniDatumKupovine(Datum(29,2,g));
        } else if(d==dd[m-1]) {
            if(m==12) PromijeniDatumKupovine(Datum(1,1,g+1));
            else PromijeniDatumKupovine(Datum(1,m+1,g));
        }
    }
    void PomjerjiDanUnazad() {
        int d= d_p.DajDan();
        int m= d_p.DajMjesec();
        int g = d_p.DajGodinu();
        if(d>1)PromijeniDatumKupovine(Datum(d-1,m,g));
        else if(m==3 && ((!g%4 && !g%100) || (!g%400)))PromijeniDatumKupovine(Datum(29,2,g));
        else if(m==1) {
            PromijeniDatumKupovine(Datum(31,12,g-1));
        } else PromijeniDatumKupovine(Datum(dd[m-1],m-1,g));
    }
    string DajImeAgenta()const {
        return i_a;
    }
    string DajImeKupca()const {
        return k.DajImePrezime();
    }
    Datum DajDatumProdaje()const {
        return d_p;
    }
    double DajCijenuStana()const {
        return c;
    }
    friend bool ProdatPrije(const Prodaja &p1,const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1,const Prodaja &p2);
    void Ispisi()const {
        cout<<"Ime agenta:                  "<<i_a<<endl
            <<"Ime kupca:                   ";
        k.Ispisi();
        cout<<"\nZakazani datum prodaje:      ";
        d_p.Ispisi();
        cout<<"\nCijena stana:                "<<c<<endl
            <<"Informacije o stanu:\n";
        s.Ispisi();
    }
};
int datum_u_Danima(const Datum &d1){
    int suma = d1.DajDan();
    for (int i = 0; i < d1.DajMjesec()-1; i++) {
        suma+=dd[i];
    }
    suma+=d1.DajGodinu()/4 - d1.DajGodinu()/100 + d1.DajGodinu()/400;
    return suma;
}
class Prodaje
{
    int poz_z = 0 ;
    Prodaja **p=nullptr;
    int max_p = 0 ;
    void throwerr(int i=0) const{
        switch(i){
            case 0:
            std::range_error("Dostignut maksimalni broj prodaja");
            case 1:
            std::domain_error("Nema registriranih prodaja");
        }
    }
    void DodajProdaju(Prodaja P) {
        //test curenja mem
        //cout<<"Na poziciji "<<poz_z<<endl;
        try {
            if(poz_z==max_p)throwerr();
            p[poz_z] = new Prodaja(P);
            poz_z++;
        } catch(...) {
            cout<<"Neuspjela alokacija"<<endl;
            throw;
        }
    }
    
    void unistiJedanElement(Prodaja *q){
        for(int i=0;i<poz_z;i++){
            if(p[i]==q)
                for (;i < poz_z-1; i++)
                    p[i]=p[i+1];
        }
        delete q;
        poz_z--;
    }
    void unistiElemente(){
        for (int i = 0; i < poz_z; i++) {
            delete p[i];
            p[i]=nullptr;
        }
    }
    void dubokaKopija(const Prodaje &px){
        unistiElemente();
        delete[] p;
        p = new Prodaja*[px.max_p];
        for (int i = 0; i < px.poz_z; i++) {
            p[i]=new Prodaja(*(px.p[i]));
        }
        poz_z = px.poz_z;
    }
    void plitkaKopija(Prodaje &px){
        unistiElemente();
        delete[] p;
        p = px.p;
        max_p = px.max_p;
        poz_z = px.poz_z;
        px.p = nullptr;
        px.max_p = 0;
        px.poz_z = 0;
    }
    void dodajProdaju(const string &a_p, double c, const Datum &d_p, const Kupac &k, const Stan &s){
        if(poz_z>=max_p)throwerr();
        try{
            p[poz_z] = new Prodaja(a_p,c,d_p,k,s);
            poz_z++;
        }catch(...){
            throw;
        }
    }
public:
    explicit Prodaje(int m_p):max_p(m_p) {
        //predvidjet za m_p<=0
        p = new Prodaja*[max_p];
        poz_z=0;
    }
    Prodaje(std::initializer_list<Prodaja> sp_p) {
        if(p) {
            for(auto i = sp_p.begin(); i!=sp_p.end(); i++)
                DodajProdaju(*i);
        }
    }
    ~Prodaje(){
        unistiElemente();
        delete[] p;
    }
    Prodaje(const Prodaje &px) {
        dubokaKopija(px);
    }
    Prodaje(Prodaje &&px){
        plitkaKopija(px);
    }
    Prodaje &operator=(const Prodaje &px){
        dubokaKopija(px);
        return *this;
    }
    Prodaje &operator=(Prodaje &&px){
        plitkaKopija(px);
        return *this;
    }
    void RegistrirajProdaju(const string &a_p, double c, const Datum &d_p, const Kupac &k, const Stan &s){
        dodajProdaju(a_p,c,d_p,k,s);
    }
    void RegistrirajProdaju(const string &a_p, double c, int d, int m, int g, string &i_k, const Datum &d_r, const string &adr,int s, int b_s,bool n,double k){
        dodajProdaju(a_p,c,Datum(d,m,g),Kupac(i_k,d_r),Stan(adr,s,b_s,n,k));
    }
    void RegistrirajProdaju(Prodaja *prodaja){
        if(poz_z>=max_p)throwerr();
        p[poz_z]=prodaja;
        poz_z++;
    }
    int DajBrojProdaja() const {
        return poz_z;
    }
    int DajBrojProdajaNaDatum(const Datum &d)const{
        int _d = datum_u_Danima(d);
        return std::count_if(p,p+poz_z,[_d](Prodaja *p1){
            return (datum_u_Danima(p1->DajDatumProdaje())==_d);
        });
    }
    int DajBrojProdajaOdAgenta(const string &i_a)const{
        return std::count_if(p,p+poz_z,[&i_a](Prodaja *p1){return (p1->DajImeAgenta()==i_a);});
    }
    Prodaja &DajProdaju(int i) {
        if(i>=poz_z)
            throw std::range_error("Ne postoji prodaja pod trazenim indeksom");
        return *p[i];
    }
    Prodaja &DajNajranijuProdaju(){
        if(poz_z==0)throwerr(1);
        return **std::min_element(p,p+poz_z,[](Prodaja *p1, Prodaja *p2){
            return datum_u_Danima(p1->DajDatumProdaje())<datum_u_Danima(p2->DajDatumProdaje());
        });
    }
    Prodaja DajNajranijuProdaju()const{
        if(poz_z==0)throwerr(1);
        return Prodaja(**std::min_element(p,p+poz_z,[](Prodaja *p1, Prodaja *p2){
            return (datum_u_Danima(p1->DajDatumProdaje())<datum_u_Danima(p2->DajDatumProdaje()));
        }));
    }
    Prodaja &DajNajskupljuProdaju(){
        if(!poz_z)throwerr(1);
        return **std::max_element(p,p+poz_z,[](Prodaja *p1,Prodaja *p2){
            return (p1->DajCijenuStana()>p1->DajCijenuStana());
        });
    }
    Prodaja DajNajskupljuProdaju()const{
        if(!poz_z)throwerr(1);
        return Prodaja(**std::max_element(p,p+poz_z,[](Prodaja *p1,Prodaja *p2){
            return (p1->DajCijenuStana()>p1->DajCijenuStana());
        }));
    }
    void IsprazniKolekciju() {
        unistiElemente();
        poz_z=0;
    }
    void ObrisiNajranijuProdaju(){
        //opasno;
        Prodaja *q = &DajNajranijuProdaju();
        unistiJedanElement(q);
    }
    void ObrisiProdajeAgenta(const string &i_a){
        for (int i = 0; i < poz_z; i++) {
            if(p[i]->DajImeAgenta()==i_a){
                unistiJedanElement(p[i]);
                // mozda ne treba 
                i--;
            }
        }
    }
    void ObrisiProdajeNaDatum(const Datum &d){
        int _d = datum_u_Danima(d);
        for (int i=0; i<poz_z;i++){
            if(datum_u_Danima(p[i]->DajDatumProdaje())==_d){
                unistiJedanElement(p[i]);
                i--;
            }
        }
    }
    void IspisiProdajeNaDatum(const Datum &d)const{
        int b_d = datum_u_Danima(d);
        for (int i = 0; i < poz_z; i++) {
            if(datum_u_Danima(p[i]->DajDatumProdaje())==b_d){
                p[i]->Ispisi();
                cout<<endl;
            }
        }
    }
    void IspisiSveProdaje()const{
        for (int i = 0; i < poz_z; i++) {
            p[i]->Ispisi();
            cout<<endl;
        }
    }
};
void IzmijeniImeAgenta(Prodaja &p,const string &i){p.i_a = i;}
Kupac DajKupca(const Prodaja &p){return p.k;}
Stan DajStan(const Prodaja &p){return p.s;}
#define END_SIGNAL -1;
using std::vector ;
template <typename T>
void ispisi_redom(vector<T> &s){
    for (int i = 0; i < s.size(); i++) {
        cout<<i+1<<". ";
        s[i].Ispisi();
        cout<<endl;
    }
}
int GlavniMeni(int &n){
    cout<<"Izaberite opciju:\n0 - kraj\n1 - uredjivanje stanova\n2 - uredjivanje kupaca\n3 - uredjivanje prodaja\n";
    cin>>n;
    return n;
}
int UredjivanjeStana(int &n){
    cout<<"Izaberite opciju:\n0 - nazad\n1 - dodavanje stana\n2 - uredjivanje stanova\n3 - ispis svih stanova\n4 - kraj\n";
    cin>>n;
    return n;
}

string uAdresu(){
    string adr;
    cout<<"Unesite adresu: ";
    cin.ignore(1);
    std::getline(cin,adr);
    return adr;
}
int uSprat(){
    int s;
    cout<<"Unesite sprat: ";
    cin>>s;
    return s;
}
int uBrojSoba(){
    int b_s;
    cout<<"Unesite broj soba: ";
    cin>>b_s;
    return b_s;
}
void throwerr(){
    throw std::domain_error("Neispravan unos podataka");
}
bool uNamjesten(bool &dobar){
    int nk;
    cout<<"Da li je stan namjesten (1 - da,0 - ne): ";
    cin>>nk;
    if(nk==1 || nk==0)
    return nk;
    else dobar = false;
}
double uKvadraturu(){
    double k;
    cout<<"Unesite kvadraturu: ";
    cin>>k;
    return k;
}
Stan uStan(){
    bool dobar = true;
    string adr = uAdresu();
    int i = uSprat(),j = uBrojSoba();
    bool u = uNamjesten(dobar);
    double k = uKvadraturu();
    if(!dobar)throwerr();
    return Stan(adr,i,j,u,k);
}
int UredjivanjeStana_dodavanje_stana(int &n, vector<Stan> &vs){
    bool dobar = true;
    try{
        vs.push_back(uStan());
        cout<<"Stan je uspjesno dodan!\n";
        
    }catch(std::domain_error e){
        cout<<e.what()<<endl;
        return UredjivanjeStana_dodavanje_stana(n,vs);
    }
    return 1;
}
string uImeKupca(){
    cout<<"Unesite ime i prezime kupca: ";
    string s;
    if(cin.peek()=='\n')cin.get();
    std::getline(cin,s);
    return s;
}
Datum uDatum(string s,bool catcherr = true){
    cout<<s;
    int d,m,g;
    cin>>d;
    cin.ignore(1);
    cin>>m;
    cin.ignore(1);
    cin>>g;
    try{
        return Datum(d,m,g);
    }catch(std::domain_error e){
        if(!catcherr)throw;
        cout<<"Izuzetak: "<<e.what()<<". Molimo unesite ponovo.\n";
        return uDatum(s);
    }
}
//baca error
Datum uDatumR(string s = "Unesite datum rodjenja (formata d/m/g): "){
    return uDatum(s);
}
int UredjivanjeStana_uredjivanje_stanova(int &n,vector<Stan> &vs){
    cout<<"Odaberite stan. Dostupni stanovi su: \n";
    ispisi_redom(vs);
    cin>>n;
    Stan &v = vs[n-1];
    string adr(v.DajAdresu());
    int s(v.DajSprat()),bs(v.DajBrojSoba());
    bool nm(v.DajNamjesten());
    double k(v.DajKvadraturu());
    while (true) {
    cout<<"Odaberite polje koje zelite urediti:\n0 - nazad\n1 - adresa\n2 - sprat\n3 - broj soba\n4 - da li je stan namjesten\n5 - kvadratura\n6 - sve\n";
    cin>>n;
    bool dobar = true;
    while (true) {
        switch(n){
            case 0: n=1;return 1;
            case 6:
            case 1: adr = uAdresu();    if(n!=6)break;
            case 2: s = uSprat();       if(n!=6)break;
            case 3: bs = uBrojSoba();   if(n!=6)break;
            case 4: nm = uNamjesten(dobar);  if(n!=6)break;
            case 5: k = uKvadraturu();  if(n!=6)break;
        }
        try{
            if(!dobar)throwerr();
            v.Postavi(adr,s,bs,nm,k);
            cout<<"Stan je uspjesno izmijenjen!\n";
            break;
        }
        catch(std::domain_error e){
            cout<<"Izuzetak: "<<e.what()<<" Molimo unesite opet.\n"<<endl;
        }
        }
    }
    return UredjivanjeStana(n);
}
Kupac dodavanjeKupca(){
    try{
        Kupac a(uImeKupca(),uDatumR());
        cout<<"Kupac je uspjesno dodan.\n";
        return a;
    }catch(std::domain_error e){
        cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet.\n";
        return dodavanjeKupca();
    }
}
void uredjivanjeKupca(int &n,vector<Kupac> &v){
    cout<<"Odaberite kupca kojeg zelite urediti. Dostupni kupci su: \n";
    ispisi_redom(v);
    int a;
    cin>>a;
    v[a-1].Postavi(uImeKupca(),uDatumR());
    cout<<"Kupac je uspjesno izmjenjen!\n";
}
int UredjivanjeKupca(int &n,vector<Kupac> &v ){
    cout<<"Izaberite opciju: \n0 - nazad\n1 - dodavanje kupca\n2 - uredjivanje kupaca\n3 - ispis svih kupaca\n4 - kraj\n";
    cin>>n;
    if(n==1)
        v.push_back(dodavanjeKupca());
    else if(n==2)
        uredjivanjeKupca(n,v);
    else if(n==3)
        ispisi_redom(v);
    else return END_SIGNAL;
    return n;
}
string uImeAgenta(){
    cout<<"Unesite ime agenta prodaje: ";
    string a;
    cin.ignore(1);
    std::getline(cin,a);
    return a;
}
Datum uDatumP(){
    return uDatum("Unesite datum prodaje (formata d/m/g): ");
}
int uCijenuS(){
    cout<<"Unesite cijenu stana: ";
    int a;
    cin>>a;
    return a;
}

#define debug if(false)
//spageti kod
//uN opasno
//bugavo skroz
int dodavanjeProdaje(int &n,Prodaje &ps,vector<Kupac> &vk,vector<Stan> &vs){
    cout<<"Izaberite opciju: \n0 - nazad\n1 - dodavanje potpuno nove prodaje\n2 - dodavanje nove prodaje na osnovu arhive\n3 - kraj\n";
    cin>>n;
    if(n==1){
        while (true) {
            try{
                string ime = uImeAgenta();
                int c= uCijenuS();
                Datum d = uDatumP();
                string imek = uImeKupca();
                Datum dp = uDatumR();
                ps.RegistrirajProdaju(ime,c,d,Kupac(imek,dp),uStan());
                break;
            }catch(std::domain_error e){
                cout<<"Izuzetak: Neispravan unos podataka. Molimo unesite ponovo.\n";
            }
        }
    }else if(n==2){
        cout<<"Odaberite prodaju. Dostupne prodaje su: \n";
        ps.IspisiSveProdaje();
        cin>>n;
        Prodaja &p = ps.DajProdaju(n-1);
        IzmijeniImeAgenta(p,uImeAgenta());
        p.PromijeniDatumKupovine(uDatum("Unesite datum prodaje (formata d/m/g): "));
        p.PromijeniCijenuProdaje(uCijenuS());
        cout<<"Odaberite kupca dostupni kupci su: \n";
        ispisi_redom(vk);
        cin>>n;
        p.PromijeniKupca(vk[n-1]);
        cout<<"Odaberite stan. Dostupni stanovi su: ";
        ispisi_redom(vs);
        cin>>n;
        p.PromijeniStan(vs[n-1]);
    }
    return 1;
}
int uredjivanjeProdaje(int &n, Prodaje &pr,vector<Kupac> &ku,vector<Stan> &vs){
    cout<<"Odaberite prodaju koju zelite urediti. Dostpune prodaje su: \n";
    int a;
    for (int i = 0; i < pr.DajBrojProdaja(); i++) {
        cout<<i+1<<endl;
        pr.DajProdaju(i).Ispisi();
    }
    cin>>a;
    Prodaja &p = pr.DajProdaju(a-1);
    cout<<"Izaberite opciju: \n0 - nazad\n1 - izmjenjena agenta\n2 - izmjenjena datuma prodaje\n3 - izmjena kupca\n4 - izmjena stana\n5 - izmjenjena cijene stana\n";
    cin>>n;
    bool q=false;
    if(n==1){
        q=true;
        IzmijeniImeAgenta(p,uImeAgenta());
    }
    else if(n==2){
        q=true;
        p.PromijeniDatumKupovine(uDatumP());
    }
    else if(n==3){
        cout<<"Izaberite opciju: \n0 - nazad\n1 - odabir postojeceg kupca\n2 - dodavanje novog kupca\n";
        int a;
        cin>>a;
        if(a==1){
            cout<<"Odaberite kupca. Dostupni kupci su: \n";
            ispisi_redom(ku);
            int e;
            cin>>e;
            p.PromijeniKupca(ku[e-1]);
        }
        else if(a==2){
            p.PromijeniKupca(Kupac(uImeKupca(),uDatum("Unesite datum (formata dan/mjesec/godina): ")));
        }
        q=true;
    }
    else if(n==4){
        cout<<"Izaberite opciju: \n0 - nazad\n1 - odabir postojeceg stana\n2 - dodavanje novog stana";{
            int e;
            cin>>e;
            if(e==1){
                p.PromijeniStan(uStan());
                q=true;
            }
            else if(e==2){
                int w;
                ispisi_redom(vs);
                cin>>w;
                p.PromijeniStan(vs[w-1]);
                q=true;
            }
        }
    }
    else if(n==5){p.PromijeniCijenuProdaje(uCijenuS());}
    if(q)cout<<"Prodaja je uspjesno izmjenjena! \n";
    return n;
}
int ispisProdaja(int &n, Prodaje &p){
    cout<<"Izaberite opciju\n0 - nazad\n1 - ispis svih prodaja\n2 - ispis prodaja na datum\n3 - ispis najranije prodaje\n4 - ispis najskuplje prodaje\n5 - ispis broja prodaja\n6 - ispis broja prodaja po datumu\n7 - ispis broja prodaja po agentu\n8 - kraj\n";
    int a;
    cin>>a;
    if(a==1){
        p.IspisiSveProdaje();
    }
    else if(a==2)p.IspisiProdajeNaDatum(uDatum("Unesite datum (d/m/g"));
    else if(a==3)p.DajNajranijuProdaju().Ispisi();
    else if(a==4)p.DajNajskupljuProdaju().Ispisi();
    else if(a==5)cout<<"Broj prodaja: "<<p.DajBrojProdaja()<<endl;
    else if(a==6)cout<<"Broj prodaja: "<<p.DajBrojProdajaNaDatum(uDatum("Unesite datum (d/m/g)"))<<endl;
    else if(a==7)cout<<"Broj prodaja: "<<p.DajBrojProdajaOdAgenta(uImeAgenta())<<endl;
    if(!a || a==8){
        if(a==8){n=-1;return END_SIGNAL;}
        if(a==0)n=1;return 0;}
    else return ispisProdaja(n,p);
}
int brisanjeProdaja(int &n,Prodaje &p){
    cout<<"Izaberite opciju: \n0 - nazad\n1 - brisanje najranije prodaje\n2 - brisanje prodaja agenta\n3 - brisanje prodaja po datumu\n4 - brisanje svih podaja\n";
    cin>>n;
    bool ok= false;
    do{
    try{
    switch(n){
        //sta ako nema nikako prodaja
        case 1: p.ObrisiNajranijuProdaju();cout<<"Najranija prodaja je obrisana\n";break;
        case 2: p.ObrisiProdajeNaDatum(uDatum("Unesite datum: "));cout<<"Sve prodaje na taj datum su obrisane.\n";break;
        case 3: p.ObrisiProdajeAgenta(uImeAgenta());cout<<"Sve prodaje tog agenta su obrisane.\n";break;
        case 4: p.IsprazniKolekciju();cout<<"Sve prodaje su obrisane.\n";break;
    }
        ok=false;
    }catch(std::domain_error e){
        cout<<"Izuzetak: Neispravan unos podataka. Molimo unesite ponovo."<<endl;
        ok = true;
    }}while (n>=1 && n<=4);
    if(!n)return n;
    else return brisanjeProdaja(n,p);
}
int UredjivanjeProdaja(int &n, Prodaje &p,vector<Kupac> &ku,vector<Stan> &vs){
    cout<<"0 - nazad\n1 - dodavanje prodaje\n2 - uredjivanje prodaje\n3 - ispis prodaja\n4 - brisanje prodaja\n5 - kraj\n";
    cin>>n;
    switch(n){
        case 0: return 0;
        case 1: dodavanjeProdaje(n,p,ku,vs);break;
        case 2: uredjivanjeProdaje(n,p,ku,vs);break;
        case 3: ispisProdaja(n,p);break;
        case 4: brisanjeProdaja(n,p);break;
        case 5: return END_SIGNAL;break;
    }
    return -1;
}

int main ()
{
    cout<<"Dobrodosli!\n\n";
    int n(0);
    Prodaje p(20);
    vector<Stan> vs;
    vector<Kupac> vk;
    while (n!=-1 && !n) {
        GlavniMeni(n);
        switch(n){
            case 0: return 0;
            case 1: while (n && n!=-1) {
                        UredjivanjeStana(n);
                        if(n==1)UredjivanjeStana_dodavanje_stana(n,vs);
                        else if(n==2)UredjivanjeStana_uredjivanje_stanova(n,vs);
                        else if(n==3)ispisi_redom(vs);
                        else if(n==4)n=-1;
                    }break;
            case 2: while (n && n!=-1) {
                        UredjivanjeKupca(n,vk);
                        if(n==4)n=-1;
                    }
            case 3: while (n && n!=-1) {
                        UredjivanjeProdaja(n,p,vk,vs);
                    }
            
        }
    }
    return 0;
}