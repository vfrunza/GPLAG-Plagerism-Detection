/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>

class GradjaninBiH {
    std::string ime_i_prezime;
    long long int jmbg;
    GradjaninBiH *prethodni;
    static GradjaninBiH *posljednji;
    void TestDatum(int d, int m, int g) {
        int temp(g/100);
        if(temp==9) g+=1000;
        else g+=2000;
        int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if((g%4==0 and g%100!=0) or g%400==0) broj_dana[1]++;
        if(g<1 or m<1 or m>12 or d<1 or d>broj_dana[m-1])
            throw std::logic_error("");
    }
    void TestJMBG(long long int jmbg) {
        int c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12,c13;
        c13=jmbg%10; jmbg/=10; c12=jmbg%10; jmbg/=10; c11=jmbg%10; jmbg/=10; c10=jmbg%10; jmbg/=10;
        c9=jmbg%10; jmbg/=10; c8=jmbg%10; jmbg/=10; c7=jmbg%10; jmbg/=10; c6=jmbg%10; jmbg/=10;
        c5=jmbg%10; jmbg/=10; c4=jmbg%10; jmbg/=10; c3=jmbg%10; jmbg/=10; c2=jmbg%10; jmbg/=10;
        c1=jmbg%10;
        int c = 11-(7*(c1+c7)+6*(c2+c8)+5*(c3+c9)+4*(c4+c10)+3*(c5+c11)+2*(c6+c12))%11;
        if(c==11) c=0;
        if(c13!=c or c13==10) throw std::logic_error("JMBG nije validan");
        int d(c2+c1*10), m(c4+c3*10), g(c7+c6*10+c5*100);
        try{
            TestDatum(d,m,g);
        } catch(...) {
            throw std::logic_error("JMBG nije validan");
        }
    }
public:
    enum Pol {Musko, Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol);
    GradjaninBiH &operator =(const GradjaninBiH &g)=delete;
    GradjaninBiH(const GradjaninBiH &g)=delete;
    std::string DajImeIPrezime() const {return ime_i_prezime;}
    long long int DajJMBG() const {return jmbg;}
    int DajDanRodjenja() const {return jmbg/100000000000;}
    int DajMjesecRodjenja() const;
    int DajGodinuRodjenja() const;
    int DajSifruRegije() const;
    Pol DajPol() const;
    void PromijeniImeIPrezime(std::string novo_ime) {ime_i_prezime = novo_ime;}
    ~GradjaninBiH();
    void Ispisi() const { std::cout << ime_i_prezime;}
};

GradjaninBiH::~GradjaninBiH() {
    GradjaninBiH *temp(posljednji), *temp2(posljednji);
    if(posljednji->jmbg!=jmbg) posljednji=posljednji->prethodni;
    while(posljednji->jmbg!=jmbg) {
        posljednji=posljednji->prethodni;
        if(posljednji->jmbg==jmbg) break;
        temp2=temp2->prethodni;
    }
    temp2->prethodni=prethodni;
    prethodni=nullptr;
    posljednji=temp;
}

GradjaninBiH* GradjaninBiH::posljednji = nullptr;

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg) : ime_i_prezime(ime_i_prezime) {
        TestJMBG(jmbg);
        GradjaninBiH::jmbg=jmbg;
        if(!posljednji) {
            prethodni=nullptr;
            posljednji=this;
        } else {
            prethodni=posljednji;
            posljednji=this;
        }
        auto temp(prethodni);
        while(temp!=nullptr) {
            if(temp->jmbg==GradjaninBiH::jmbg) throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
            temp=temp->prethodni;
        }
}

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol) : ime_i_prezime(ime_i_prezime) {
    try{
        TestDatum(dan_rodjenja,mjesec_rodjenja,godina_rodjenja);
        if(sifra_regije<0 or sifra_regije>99) throw;
    } catch(...) {
        throw std::logic_error("Neispravni podaci");
    }
    long long int temp(0);
    long long int d(dan_rodjenja), m(mjesec_rodjenja);
    d *= 100000000000;
    m *= 1000000000;
    temp+=d+m;
    long long int temp3=godina_rodjenja%1000;
    temp3 *= 1000000; 
    temp+=temp3+sifra_regije*10000;
    jmbg=temp;
    if(!posljednji) {
        prethodni=nullptr;
        posljednji=this;
    } else {
        prethodni=posljednji;
        posljednji=this;
    }
    GradjaninBiH *temp2(prethodni);
    if(pol==Pol::Zensko) jmbg+=5000;
    while(temp2!=nullptr) {
        long long int jmbg2(temp2->jmbg);
        int dan(jmbg2/100000000000), mjesec(jmbg2/1000000000), godina(jmbg2/1000000);
        mjesec%=100; godina%=1000;
        long long int kod2(jmbg2/10); kod2%=1000;
        Pol pol2(Pol::Musko);
        if(kod2>=500) pol2=Pol::Zensko;
        int regija(jmbg2/10000); regija%=100;
        if(dan==dan_rodjenja and mjesec==mjesec_rodjenja and godina==(godina_rodjenja%1000) and pol2==pol and regija==sifra_regije)
            jmbg+=kod2*10+1;
        temp2=temp2->prethodni;
    }
    int c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12,c13;
    long long int jmbg3(jmbg);
    jmbg3/=10; c12=jmbg3%10; jmbg3/=10; c11=jmbg3%10; jmbg3/=10; c10=jmbg3%10; jmbg3/=10;
    c9=jmbg3%10; jmbg3/=10; c8=jmbg3%10; jmbg3/=10; c7=jmbg3%10; jmbg3/=10; c6=jmbg3%10; jmbg3/=10;
    c5=jmbg3%10; jmbg3/=10; c4=jmbg3%10; jmbg3/=10; c3=jmbg3%10; jmbg3/=10; c2=jmbg3%10; jmbg3/=10;
    c1=jmbg3%10;
    c13 = 11-(7*(c1+c7)+6*(c2+c8)+5*(c3+c9)+4*(c4+c10)+3*(c5+c11)+2*(c6+c12))%11;
    if(c13==11) c13=0;
    jmbg+=c13;
}

int GradjaninBiH::DajMjesecRodjenja() const {
    long long int temp(jmbg);
    temp/=1000000000;
    return temp%100;
}

int GradjaninBiH::DajGodinuRodjenja() const {
    long long int temp(jmbg);
    temp/=1000000;
    int temp2=temp%1000;
    int temp3=temp2/100;
    if(temp3==9) return temp2+1000;
    return temp2+2000;
}

int GradjaninBiH::DajSifruRegije() const {
    long long int temp(jmbg);
    temp/=10000;
    return temp%100;
}

GradjaninBiH::Pol GradjaninBiH::DajPol() const {
    long long int temp(jmbg);
    temp/=10;
    int temp2=temp%1000;
    if(temp2<500) return Musko;
    return Zensko;
}

int main ()
{
    GradjaninBiH *gradjanin[100];
    std::cout << "Koliko gradjana zelite unijeti po JMBG? " << std::endl;
    int n, m;
    std::cin >> n;
    for(int i(0); i<n; i++) {
        try {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Unesite ime i prezime (u istom redu): " << std::endl;
        std::string ime_i_prezime;
        std::getline(std::cin, ime_i_prezime);
        std::cout << "Unesite JMBG: " << std::endl;
        long long int jmbg;
        std::cin >> jmbg;
        gradjanin[i]=new GradjaninBiH(ime_i_prezime, jmbg);
        std::cout << "Unijeli ste gradjanina " << ime_i_prezime << " rodjenog " << gradjanin[i]->DajDanRodjenja()
                  << "." << gradjanin[i]->DajMjesecRodjenja() << "." << gradjanin[i]->DajGodinuRodjenja()
                  << " u regiji " << gradjanin[i]->DajSifruRegije() << ", ";
        if(gradjanin[i]->DajPol()==GradjaninBiH::Pol::Musko) std::cout << "musko." << std::endl;
        else std::cout << "zensko." << std::endl;
        }
        catch(std::logic_error a) {
            i--;
            std::cout << a.what() << std::endl;
        }
    }
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    std::cout << "Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? " << std::endl;
    std::cin >> m;
    for(int i(n); i<m+n; i++) {
        try {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Unesite ime i prezime (u istom redu): " << std::endl;
        std::string ime_i_prezime;
        std::getline(std::cin, ime_i_prezime);
        std::cout << "Unesite datum rodjenja (format dd/mm/gggg): " << std::endl;
        int d,m,g; char z1,z2;
        std::cin >> d >> z1 >> m >> z2 >> g;
        int sifra;
        std::cout << "Unesite sifru regije: " << std::endl;
        std::cin >> sifra;
        std::cout << "Unesite M za musko, Z za zensko: " << std::endl;
        std::cin >> z1;
        GradjaninBiH::Pol pol;
        if(z1=='M') pol=GradjaninBiH::Pol::Musko;
        else if(z1=='Z') pol=GradjaninBiH::Pol::Zensko;
        else {
            i--;
            std::cout << "Neispravni podaci" << std::endl;
            continue;
        }
        gradjanin[i]=new GradjaninBiH(ime_i_prezime, d,m,g, sifra, pol);
        std::cout << "Unijeli ste gradjanina " << ime_i_prezime << " JMBG: " << gradjanin[i]->DajJMBG() << "." << std::endl;
        }
        catch(std::logic_error a) {
            i--;
            std::cout << a.what() << std::endl;
        }
    }
	return 0;
}