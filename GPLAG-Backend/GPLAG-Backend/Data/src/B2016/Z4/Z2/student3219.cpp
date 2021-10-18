/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>
#define VEL 100

using namespace std;

class GradjaninBiH {
    string ImePrezime;
    long long int JMBG;
    int dan_rodjenja,mjesec_rodjenja,godina_rodjenja;
    int sifra_regije;
    int MZ;
    GradjaninBiH *pok=nullptr;
    static GradjaninBiH *staticki;
    int BrojPola(long long int jmbg) { long long int pom=jmbg/10000; return (jmbg/10000-pom)*1000; }
    
    public:
    enum Pol {Musko, Zensko}; 
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);  
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol);  
    std::string DajImeIPrezime() const { return ImePrezime; } 
    long long int DajJMBG() const  { return JMBG; };
    int DajDanRodjenja() const { return dan_rodjenja; };  
    int DajMjesecRodjenja() const  { return mjesec_rodjenja; };
    int DajGodinuRodjenja() const   { return godina_rodjenja; };
    int DajSifruRegije() const  { return sifra_regije; };
    Pol DajPol() const  { if(MZ==0) return Pol::Musko; else return Pol::Zensko; };
    void PromijeniImeIPrezime(std::string novo_ime);
    ~GradjaninBiH() {
        if(staticki->pok==nullptr)  { staticki=nullptr; }
        else if(this==staticki) { staticki=staticki->pok;}
        else if(this->pok==nullptr) { GradjaninBiH* pom=staticki; while(pom->pok != this) pom=pom->pok; pom->pok=nullptr;}
        else {
            GradjaninBiH* pom=staticki;
            while(pom->pok != this) pom=pom->pok;
            pom->pok=this->pok;
        }
    }
};
 GradjaninBiH* GradjaninBiH::staticki=nullptr;


bool DaLiJeIspravanDatum(int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja) {
    int BrojDanaPoMjesecu[]{31,28,31,30,31,30,31,31,30,31,30,31};
    if((godina_rodjenja%4==0 && godina_rodjenja%100!=0) || godina_rodjenja%400==0) BrojDanaPoMjesecu[1]++;
    if(dan_rodjenja<1 || dan_rodjenja>BrojDanaPoMjesecu[mjesec_rodjenja-1] || mjesec_rodjenja<1 || mjesec_rodjenja>12 || godina_rodjenja<1) return false;
    return true;
}

int ZadnjiBroj(int niz[]) {
    int n=11-(7*(niz[0]+niz[6]) + 6*(niz[1]+niz[7]) + 5*(niz[2]+niz[8]) + 4*(niz[3]+niz[9]) + 3*(niz[4]+niz[10]) + 2*(niz[5]+niz[11]))%11;

    if(n==11) n=0;
    if(n==10) throw logic_error ("JMBG nije validan");
    return n;
}

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg) {
    int pomJMBG[13];
    int i=12;
    long long int n=jmbg;
    while(n!=0) {
        pomJMBG[i]=n%10;
        n/=10;
        i--;
    }
    int Dan=pomJMBG[0]*10+pomJMBG[1];
    int Mjesec=pomJMBG[2]*10+pomJMBG[3];
    int Godina=pomJMBG[4]*100+pomJMBG[5]*10+pomJMBG[6];
    if(!DaLiJeIspravanDatum(Dan,Mjesec,Godina)) throw logic_error ("JMBG nije validan");
    if(pomJMBG[12] != ZadnjiBroj(pomJMBG)) throw logic_error ("JMBG nije validan");
    
    GradjaninBiH* pom=staticki;
    while(pom!=nullptr) {
        if(pom->DajJMBG()==jmbg) throw logic_error ("Vec postoji gradjanin sa istim JMBG");
        pom=pom->pok;
    }
   
    pok=staticki;
    staticki=this;
    JMBG=jmbg;
    ImePrezime=ime_i_prezime;
    dan_rodjenja=Dan;
    mjesec_rodjenja=Mjesec;
    if(Godina>=917) godina_rodjenja=1000+Godina;
    else if(Godina<=17) godina_rodjenja=2000+Godina;
    if(pomJMBG[9]*100+pomJMBG[10]*10+pomJMBG[11]<500) MZ=0;
    else MZ=1;
    sifra_regije=pomJMBG[7]*10+pomJMBG[8];
    
}

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol) {
    if(!DaLiJeIspravanDatum(dan_rodjenja,mjesec_rodjenja,godina_rodjenja)) throw logic_error ("Neispravni podaci");
    if(sifra_regije<0 || sifra_regije > 99) throw logic_error ("Neispravni podaci");
    
    pok=staticki;
    staticki=this;
    
    ImePrezime=ime_i_prezime;
    GradjaninBiH::dan_rodjenja=dan_rodjenja;
    GradjaninBiH::mjesec_rodjenja=mjesec_rodjenja;
    GradjaninBiH::godina_rodjenja=godina_rodjenja;
    GradjaninBiH::sifra_regije=sifra_regije;
    if(pol==GradjaninBiH::Pol::Musko) MZ=0;
    else MZ=1;
    int spol=0;
    if(MZ==1) spol=500;
    GradjaninBiH* pom=pok;
    while(pom!=nullptr) {
        if(pom->DajDanRodjenja()==dan_rodjenja && pom->DajMjesecRodjenja()==mjesec_rodjenja && pom->DajGodinuRodjenja()==godina_rodjenja && pom->DajSifruRegije()==sifra_regije && pom->DajPol()==pol) {
            if(spol==BrojPola(pom->DajJMBG())) {
                spol++; pom=pok;
            }
        }
        pom=pom->pok;
    }
    int pomgod;
    if(godina_rodjenja>=2000) pomgod=godina_rodjenja-2000;
    else pomgod=godina_rodjenja-1000;
    
    int niz[]={dan_rodjenja/10,dan_rodjenja%10,mjesec_rodjenja/10,mjesec_rodjenja%10,pomgod/100,(pomgod/10)%10,pomgod%10,sifra_regije/10,sifra_regije%10,spol/100,(spol/10)%10,spol%10};
    
    long long int dan=dan_rodjenja*100000000000; 
    long long int mjesec=(mjesec_rodjenja*10000000000)/10; 
    long long int godina=pomgod*1000000;
    long long int jmbg=dan+mjesec+godina+(sifra_regije*10000)+(spol*10)+ZadnjiBroj(niz);
    GradjaninBiH::JMBG=jmbg;
    
}

void GradjaninBiH::PromijeniImeIPrezime(std::string novo_ime) {
     ImePrezime=novo_ime;
 }

int main () {
    GradjaninBiH* NPok[VEL]={nullptr};
    cout<<"Koliko gradjana zelite unijeti po JMBG? "<<endl;
    int n; cin>>n;
    for(int i(0);i<n;i++) {
        cout<<"Unesite ime i prezime (u istom redu): "<<endl;
        cin.ignore(10000,'\n');
        string Ime; getline(cin,Ime);
        cout<<"Unesite JMBG: "<<endl;
        long long int jmbg; cin>>jmbg;
        
        try{
            NPok[i]= new GradjaninBiH (Ime,jmbg);
        } catch(logic_error e) { cout<<e.what()<<endl; i--; continue; }
        
        cout<<"Unijeli ste gradjanina "<<NPok[i]->DajImeIPrezime()<<" rodjenog "<<NPok[i]->DajDanRodjenja()<<"."<<NPok[i]->DajMjesecRodjenja()<<"."<<NPok[i]->DajGodinuRodjenja()<<" u regiji "<<NPok[i]->DajSifruRegije()<<", ";
        if(NPok[i]->DajPol()) cout<<"zensko."<<endl;
        else cout<<"musko."<<endl;
        
    }
    int k; 
    cout<<"Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? "<<endl;
    cin>>k;
    for(int i(0);i<k;i++) {
        cin.ignore(10000,'\n');
        cout<<"Unesite ime i prezime (u istom redu): "<<endl;
        string Ime; getline(cin,Ime);
        cout<<"Unesite datum rodjenja (format dd/mm/gggg): "<<endl;
        string datum;
        getline(cin,datum);
        int d,m,g;
        d=stoi(datum.substr(0,2)); datum=datum.substr(3);
        m=stoi(datum.substr(0,2)); datum=datum.substr(3);
        g=stoi(datum.substr(0));
        cout<<"Unesite sifru regije: "<<endl;
        int sifra; cin>>sifra; cin.ignore(10000,'\n');
        cout<<"Unesite M za musko, Z za zensko: "<<endl;
        char slovo; cin>>slovo;
        if(slovo=='M') {
            try{
                
                NPok[n+i]= new GradjaninBiH (Ime, d, m, g, sifra, GradjaninBiH::Pol::Musko);
            } catch(logic_error e) { cout<<e.what()<<endl; i--;  continue; }
        }
        else if(slovo=='Z') {
            try{
                NPok[n+i]= new GradjaninBiH (Ime, d, m, g, sifra, GradjaninBiH::Pol::Zensko);
            } catch(logic_error e) { cout<<e.what()<<endl; i--;  continue; }
        }
        cout<< "Unijeli ste gradjanina "<<NPok[n+i]->DajImeIPrezime()<<" JMBG: "<<NPok[n+i]->DajJMBG()<<"."<<endl;
    }
    for(int i(0);i<n+k;i++) {
        delete NPok[i];
        NPok[i]=nullptr;
    }
	return 0;
}