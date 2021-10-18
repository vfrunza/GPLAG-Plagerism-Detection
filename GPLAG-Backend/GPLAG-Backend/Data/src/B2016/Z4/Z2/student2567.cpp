/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!

#include <iostream>
#include <stdexcept>
#include <string>
#include <cmath>

class GradjaninBiH {
    
    std::string ime_i_prezime; 
    long long int jmbg; 
    int dan_rodjenja, mjesec_rodjenja, godina_rodjenja; 
    int sifra_regije; 
    
    static GradjaninBiH* p; 
    static GradjaninBiH* q; 
    static int br; 
    
    void Pretvori (long long int jmbg, int*pok) const {
        int br(0); 
        long long int tmp(jmbg); 
        
        while (jmbg!=0) {
            jmbg=jmbg/10; br++; 
        }
        
        if (br==12) {
            pok[0]=0; 
            for (int i=12; i>0; i--) { pok[i]=tmp%10; tmp/=10; }
        }
        if (br==13) {
            for (int i=13; i>0; i--) { pok[i]=tmp%10; tmp/=10; }
        }
    }
    
    bool Datum (int d, int m, int g) {
        int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
        if (g%4==0 || g%100!=0 || g%400==0) broj_dana[1]++;
        if (d<1 || d>broj_dana[m-1] || m<1 || m>12 || g<1) return false; 
        else return true; 
        
    }
    public:
    
    enum Pol {Musko, Zensko}; 
    GradjaninBiH (std::string ime_i_prezime, long long int jmbg); 
    GradjaninBiH (std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol);
    long long int DajJMBG() const { return jmbg; }
    int DajDanRodjenja() const;
    int DajMjesecRodjenja() const;
    int DajGodinuRodjenja() const;
    int DajSifruRegije() const;
    Pol DajPol() const;
    void PromijeniImeIPrezime(std::string novo_ime) { ime_i_prezime=novo_ime; }
    ~GradjaninBiH(); 
    GradjaninBiH(const GradjaninBiH &gradjanin) = delete; 
    GradjaninBiH &operator =(const GradjaninBiH &gradjanin) = delete; 
};
GradjaninBiH::GradjaninBiH (std::string ime_i_prezime, long long int jmbg) {
    
    if (br==0) { p=nullptr; q=this; }
    else { p=q; q=this; } br++; 
    
    ime_i_prezime=ime_i_prezime; 
    
    int br1(0); auto temp(jmbg); 
    
    while (temp!=0) {
        br1++; 
        temp=temp/10; 
    }
    
    int niz1[13]; 
    if (br1==13) {
        auto novi=jmbg; 
        for (int i=13; i>0; i--) { niz1[i]=novi%10; novi=novi/10; }
    }
    if (br1==12) {
        niz1[0]=0; 
        auto novi=jmbg; 
        for (int i=12; i>0; i--) { niz1[i]=novi%10; novi=novi/10; } 
    }
    
    int d=niz1[0]*10+niz1[1]; int m=niz1[2]*10+niz1[3]; int g; 
    if (niz1[4]==9) g=1900+niz1[5]*10+niz1[6];
    else g=2000+niz1[5]*10+niz1[6]; 
    
    if (Datum(d,m,g)==false) throw std::logic_error ("JMBG nije validan"); 
    
    int c=11-(7*(niz1[0]+niz1[6])+6*(niz1[1]+niz1[7])+5*(niz1[2]+niz1[8])+4*(niz1[3]+niz1[9])+3*(niz1[4]+niz1[10])+2*(niz1[5]+niz1[11]))%11;
    if (niz1[12]!=c || niz1[12]!=10) throw std::logic_error("JMBG nije validan"); 
    
    for (GradjaninBiH*pokazivac=p; pokazivac!=nullptr; pokazivac=pokazivac->p) {
        if (jmbg==pokazivac->jmbg) throw std::logic_error ("Vec postoji gradjanin sa istim JMBG");
    }
    this->jmbg=jmbg; 
}

GradjaninBiH::GradjaninBiH (std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol) {
    
    if (br==0) { p=nullptr; q=this; } 
    else {p=q; q=this; }
    br++;
    
    ime_i_prezime=ime_i_prezime; 

    if (Datum(dan_rodjenja,mjesec_rodjenja,godina_rodjenja)==false || sifra_regije<0 || sifra_regije>99) throw std::logic_error ("Neispravni podaci"); 
    
    int niz[13]; 
    if (dan_rodjenja<=9) { niz[0]=0; niz[1]=dan_rodjenja; } 
    else { niz[1]=dan_rodjenja%10; niz[0]=dan_rodjenja/10; }
    
    if (mjesec_rodjenja<=9) { niz[2]=0; niz[3]=mjesec_rodjenja; } 
    else { niz[3]=mjesec_rodjenja%10; niz[2]=mjesec_rodjenja/10; }
    
    niz[6]=godina_rodjenja%10; godina_rodjenja=godina_rodjenja/10; niz[5]=godina_rodjenja%10; godina_rodjenja=godina_rodjenja/10; 
    niz[4]=godina_rodjenja%10; godina_rodjenja=godina_rodjenja/10; 
    
    niz[8]=sifra_regije%10; niz[7]=sifra_regije/10; 
    
    long long int jmbg(0); 
    
    for (;;) {
        int u(0); 
        for (int i=12; i>9; i--) {
            niz[i]=u%10;
            u=u/10;
        }
        niz[12]=11-(7*(niz[0]+niz[6])+6*(niz[1]+niz[7])+5*(niz[2]+niz[8])+4*(niz[3]+niz[9])+3*(niz[4]+niz[10])+2*(niz[5]+niz[11]))%11;
        if (niz [12]==11) niz[12]=0; 
        
        bool da(true); 
        for (int j=13; j>0; j--) {
            jmbg+=niz[13-j]*std::pow(10,j); 
        }
        
        for (GradjaninBiH*pokazivac=p; pokazivac!=nullptr; pokazivac=pokazivac->p) {
            if (jmbg==pokazivac->jmbg) { u++; da=false; break; }
        }
        if (da) break; 
    }
    std::cout << jmbg << std::endl; 
    this->jmbg=jmbg; 
}

GradjaninBiH::~GradjaninBiH() {
    delete p; 
    delete q;
}

GradjaninBiH* GradjaninBiH::q=nullptr; 
GradjaninBiH* GradjaninBiH::p=nullptr;
int GradjaninBiH::br=0; 

int GradjaninBiH::DajDanRodjenja() const {
    int niz[13]; 
    Pretvori(jmbg, niz);
    int dan=niz[0]*10+niz[1]; 
    return dan; 
}

int GradjaninBiH::DajMjesecRodjenja() const {
    int niz[13]; 
    Pretvori(jmbg, niz); 
    int mjesec=niz[2]*10+niz[3]; 
    return mjesec; 
} 

int GradjaninBiH::DajGodinuRodjenja() const {
    int niz[13]; 
    Pretvori(jmbg, niz); 
    if (niz[4]==9) {
        int godina=1900+niz[5]*10+niz[6];
        return godina; 
    }
    else {
        int godina=2000+niz[5]*10+niz[6];
        return godina; 
    }
}

int GradjaninBiH::DajSifruRegije() const {
    int niz[13]; 
    Pretvori(jmbg, niz); 
    int sifra=niz[7]*10+niz[8];
    return sifra; 
}

GradjaninBiH::Pol GradjaninBiH::DajPol() const {
    int niz[13]; 
    Pretvori(jmbg, niz); 
    int a=niz[9]*100+niz[10]*10+niz[11]; 
    if (a>0 && a<499) return Musko; 
    else return Zensko; 
}

int main ()
{
    std::cout << "Koliko gradjana zelite unijeti po JMBG: ";
    int n; 
    std::cin >> n; 
    
    GradjaninBiH*p; 
    
    for (int i=0; i<n; i++) {
        std::cout << "Unesite ime i prezime (u istom redu): "; 
        std::string s; 
        std::getline(std::cin, s); 
        std::cin.clear(); 
        std::cin.ignore(10000, '\n'); 
        std::cout << std::endl << "Unesite JMBG: "; 
        long long int jmbg; 
        std::cin >> jmbg; 
        try {
         std::cout << std::endl << "Unijeli ste gradjanina " << s << " rodjenog " << p->DajDanRodjenja() << "." << p->DajMjesecRodjenja() << "." << p->DajGodinuRodjenja();
         std::cout << " u regiji " << p->DajSifruRegije() << "," << p->DajPol() << "."; 
        }
        catch(std::logic_error e) {
            std::cout << e.what() << std::endl; 
        }
    }
    
    GradjaninBiH*q; 
    
    std::cout << std::endl << "Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu?"; 
    int m; 
    std::cin >> m; 
    
    for (int i=0; i<m; i++) {
        std::cout << "Unesite ime i prezime (u istom redu): "; 
        std::string s; 
        std::getline(std::cin, s); 
        std::cin.clear(); 
        std::cin.ignore(10000, '\n'); 
        std::cout << std::endl << "Unesite datum rodjenja (format dd/mm/gg) ";
        int d,m,g; 
        std::cin >> d >> m >> g; 
        std::cout << std::endl << "Unesite sifru regije: "; 
        int sifra; 
        std::cin >> sifra; 
        std::cout << std::endl << "Unesite M za musko, Z za zensko: ";  
        char znak; 
        std::cin >> znak; 
        
        std::cout << "Unijeli ste gradjana "; 
        for(int i=0; i<s.size(); i++) { std::cout << s[i]; if (s[i]==' ') break; }
        try {
            std::cout << "JMBG: " << p->DajJMBG() << "."; 
        }
        catch (std::logic_error e) {
            std::cout << e.what() << std::endl; 
        }
    }
    

    
    
  
	return 0;
}