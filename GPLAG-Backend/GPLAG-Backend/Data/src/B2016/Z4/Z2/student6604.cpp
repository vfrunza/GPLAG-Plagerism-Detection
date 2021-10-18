/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>

class GradjaninBiH
{
    std::string ime_i_prezime;
    long long int jmbg;
    GradjaninBiH* pok {nullptr};
    static GradjaninBiH* pok2;


public:
    enum Pol {Musko, Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg) {
        GradjaninBiH::ime_i_prezime=ime_i_prezime;
        GradjaninBiH::jmbg=jmbg;
        long long int j=jmbg;
        int kontrolna_cifra;
        kontrolna_cifra=11-(7*(jmbg/1000000000000+(jmbg/1000000)%10)+6*((jmbg/100000000000)%10+(jmbg/100000)%10)+5*((jmbg/10000000000)%10+(jmbg/10000)%10)+4*((jmbg/1000000000)%10+(jmbg/1000)%10)+3*((jmbg/100000000)%10+(jmbg/100)%10)+2*((jmbg/10000000)%10+(jmbg/10)%10))%11;
        if(kontrolna_cifra==11) kontrolna_cifra=0;
        int mjesec=(jmbg/1000000000)%100;
        int dan=jmbg/100000000000;
        int godina=(jmbg/1000000)%1000;
        if(godina>0 && godina<=17) godina+=2000;
        else godina+=1000;
        int prestupna(0), pogresna(0);
        if(godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0)prestupna=1;
        int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(prestupna && mjesec==2 && dan==28) pogresna=1;
        for(auto it=pok2; it!=nullptr; it=it->pok) {
            if(it->jmbg==j)throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
        }
        pok2=pok;
        pok=this;
        if(kontrolna_cifra==10 || dan<1|| dan>broj_dana[mjesec-1] || mjesec<1 || mjesec >12  || godina>2017 || pogresna) throw std::logic_error("JMBG nije validan");

    }
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol) {


        int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int prestupna(0), pogresna(0);
        if(godina_rodjenja % 4 == 0 && godina_rodjenja % 100 != 0 || godina_rodjenja % 400 == 0) prestupna=1;
        if(prestupna==1 && mjesec_rodjenja==2 && dan_rodjenja==28) pogresna=1;
        long long int j(0);
        j+=dan_rodjenja;
        j*=100;

        j+=(mjesec_rodjenja);
        j*=1000;
        j+=(godina_rodjenja%1000);
        j*=100;
        j+=sifra_regije;
        j*=1000;
        int nema=0;
        long long int k(500), l(0);
        if(pol==Zensko)j+=k;
        else j+=l;
        for(auto it=pok2; it!=nullptr; it=it->pok) {
            if(it->DajPol()==Zensko &&  it->jmbg/4==j) {
                j++;
                it=pok2;

            }
            if(it->DajPol()==Musko && it->jmbg/4==j) {
                j++;
                it=pok2;
            } else {
                nema=1;
            }
        }

        if(nema && pol==Musko) {
            j=k;
            GradjaninBiH::jmbg=j;
        }
        if(nema && pol==Zensko) {
            j=l;
            GradjaninBiH::jmbg=j;
        }
        j*=10;
        int kontrolna_cifra(0);
        kontrolna_cifra=11-(7*(j/1000000000000+(j/1000000)%10)+6*((j/100000000000)%10+(j/100000)%10)+5*((j/10000000000)%10+(j/10000)%10)+4*((j/1000000000)%10+(j/1000)%10)+3*((j/100000000)%10+(j/100)%10)+2*((j/10000000)%10+(j/10)%10))%11;
        if(kontrolna_cifra==11) kontrolna_cifra=0;
        j+=kontrolna_cifra;
        if(kontrolna_cifra==10 || godina_rodjenja < 1917 || godina_rodjenja>2017 || mjesec_rodjenja< 1 || mjesec_rodjenja>12 || dan_rodjenja<1 || dan_rodjenja>broj_dana[mjesec_rodjenja-1] || sifra_regije<0 || sifra_regije>99 || pogresna) throw std::logic_error("Neispravni podaci");

        for(auto it=pok2; it!=nullptr; it=it->pok) {
            if(it->jmbg==j)throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
        }
        pok2=pok;
        pok=this;
        GradjaninBiH::jmbg=j;
        GradjaninBiH::ime_i_prezime=ime_i_prezime;
    }
    std::string DajImeIPrezime() const {
        return ime_i_prezime;
    }
    GradjaninBiH(const GradjaninBiH &g)=delete;
    GradjaninBiH &operator=(const GradjaninBiH &g)=delete;

    long long int DajJMBG() const {
        return jmbg;
    }
    int DajDanRodjenja() const {
        return jmbg/100000000000;
    }
    int DajMjesecRodjenja() const {
        return (jmbg/1000000000)%100;
    }
    int DajGodinuRodjenja() const {
        int godina=(jmbg/1000000)%1000;
        if(godina>0 && godina<=17) godina+=2000;
        else godina+=1000;
        return godina;
    }
    int DajSifruRegije() const {
        return (jmbg/10000)%100;
    }
    Pol DajPol() const {
        int x;
        x=(jmbg/10)%1000;
        if(x>=0 && x<500) return Pol(Musko);
        if(x>=500 && x<1000) return Pol(Zensko);
    }
    void PromijeniImeIPrezime(std::string novo_ime) {
        ime_i_prezime=novo_ime;
    }
};
GradjaninBiH*GradjaninBiH::pok2(nullptr);

int main ()
{
    std::cout<<"Koliko gradjana zelite unijeti po JMBG? "<<std::endl;
    int n;
    std::cin>>n;
    std::cin.ignore(1000,'\n');
    for(int i=0; i<n; i++) {
        std::cout<<"Unesite ime i prezime (u istom redu): ";
        std::string ime_i_prezime;
        std::getline(std::cin, ime_i_prezime);
        std::cout<<std::endl;
        std::cout<<"Unesite JMBG: "<<std::endl;
        long long int jmbg;
        try {
            std::cin>>jmbg;
            GradjaninBiH g(ime_i_prezime, jmbg);
            std::cout<<"Unijeli ste gradjanina "<<g.DajImeIPrezime()<<" rodjenog "<<g.DajDanRodjenja()<<"."<<g.DajMjesecRodjenja()<<"."<<g.DajGodinuRodjenja()<<" u regiji "<<g.DajSifruRegije()<<", ";
            if(g.DajPol())std::cout<<"zensko."<<std::endl;
            else std::cout << "musko." << std::endl;
        } catch(std::logic_error izuzetak) {
            i--;
            std::cout<<izuzetak.what()<<std::endl;
        }
        std::cin.ignore(1000,'\n');
    }
    std::cout<<"Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? "<<std::endl;
    int m;
    std::cin>>m;
    std::cin.ignore(1000,'\n');
    for(int i=0; i<m; i++) {
        try {
            std::cout<<"Unesite ime i prezime (u istom redu): ";
            std::string ime;
            std::getline(std::cin, ime);
            std::cout<<std::endl;
            std::cout<<"Unesite datum rodjenja (format dd/mm/gggg): "<<std::endl;
            char znak;
            int d, mj, g;

            std::cin >> d >> znak >> mj >> znak >> g;
            std::cout<<"Unesite sifru regije: "<<std::endl;
            int sr;
            std::cin>>sr;
            std::cout<<"Unesite M za musko, Z za zensko: "<<std::endl;
            char slovo;
            std::cin>>slovo;
            if(slovo=='M') {
                GradjaninBiH g1(ime, d,mj,g, sr, GradjaninBiH::Pol::Musko);
                std::cout<<"Unijeli ste gradjanina "<<g1.DajImeIPrezime()<<" JMBG: "<<g1.DajJMBG()<<"."<<std::endl;

            }
            if(slovo=='Z') {
                GradjaninBiH g1(ime, d,mj,g, sr, GradjaninBiH::Pol::Zensko);
                std::cout<<"Unijeli ste gradjanina "<<g1.DajImeIPrezime()<<" JMBG: "<<g1.DajJMBG()<<"."<<std::endl;

            }
        } catch(std::logic_error izuzetak) {
            i--;
            std::cout<<izuzetak.what()<<std::endl;
        }
        std::cin.ignore(1000,'\n');
    }

    return 0;
}