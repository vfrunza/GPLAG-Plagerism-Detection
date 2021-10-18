/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <string>

class GradjaninBiH {
    std::string ime_i_prezime;
    int jmbg[13];
    GradjaninBiH *sljedeci;
    static GradjaninBiH *prvi;
    static GradjaninBiH *posljednji;
    static int broj_kreiranih;
    static bool DaLiJeDatumIspravan(int dan, int mjesec, int godina) {
        int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if ((godina%4==0 && godina%100!=0) || godina%400==0) broj_dana[1]++;
        if (godina<1 || mjesec<1 || mjesec>12 || dan<1 || dan>broj_dana[mjesec-1]) return false;
        return true;
    }
public:
    enum Pol {Musko, Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol);
    ~GradjaninBiH();
    GradjaninBiH(const GradjaninBiH &gradjanin)=delete;
    GradjaninBiH(GradjaninBiH &&gradjanin)=delete;
    GradjaninBiH &operator =(const GradjaninBiH &gradjanin)=delete;
    GradjaninBiH &operator =(GradjaninBiH &&gradjanin)=delete;
    std::string DajImeIPrezime() const { return ime_i_prezime; }
    long long int DajJMBG() const;
    int DajDanRodjenja() const { return jmbg[0]*10+jmbg[1]; }
    int DajMjesecRodjenja() const { return jmbg[2]*10+jmbg[3]; }
    int DajGodinuRodjenja() const { 
        int godina=jmbg[4]*100+jmbg[5]*10+jmbg[6];
        if (jmbg[4]==0) return godina+2000;
        return godina+1000; 
    }
    int DajSifruRegije() { return jmbg[7]*10+jmbg[8]; }
    Pol DajPol() const { 
        int kod=jmbg[9]*100+jmbg[10]*10+jmbg[11];
        if (kod>=0 && kod<500) return Pol(0);
        return Pol(1);
    }
    void PromijeniImeIPrezime(std::string novo_ime) { ime_i_prezime=novo_ime; };
};

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg) {
    int novi_jmbg[13];
    for (int i=12; i>=0; i--) {
        novi_jmbg[i]=jmbg%10;
        jmbg/=10;
    }
    int tmp_cifra_13=11-(7*(novi_jmbg[0]+novi_jmbg[6])+6*(novi_jmbg[1]+novi_jmbg[7])+5*(novi_jmbg[2]+novi_jmbg[8])+4*(novi_jmbg[3]+novi_jmbg[9])
                        +3*(novi_jmbg[4]+novi_jmbg[10])+2*(novi_jmbg[5]+novi_jmbg[11]))%11;
    if (tmp_cifra_13==11) tmp_cifra_13=0;
    int dan=novi_jmbg[0]*10+novi_jmbg[1];
    int mjesec=novi_jmbg[2]*10+novi_jmbg[3];
    int godina=novi_jmbg[4]*100+novi_jmbg[5]*10+novi_jmbg[6];
    if (novi_jmbg[4]==0) godina+=2000;
    else godina+=1000;
    if (!DaLiJeDatumIspravan(dan,mjesec,godina) || tmp_cifra_13!=novi_jmbg[12] || tmp_cifra_13==10) 
        throw std::logic_error("JMBG nije validan");
    if (prvi!=nullptr) {
        auto it=posljednji;
        for (int i=0; i<broj_kreiranih; i++) {
            bool pronadjen=true;
            for (int i=0; i<13; i++)
                if (it->jmbg[i]!=novi_jmbg[i]) 
                    pronadjen=false;
            if (pronadjen) 
                throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
            it=it->sljedeci;
        }
    }
    this->ime_i_prezime=ime_i_prezime;
    for (int i=0; i<13; i++)
        this->jmbg[i]=novi_jmbg[i];
    sljedeci=posljednji;
    posljednji=this;
    if (broj_kreiranih==0) prvi=this;
    else prvi->sljedeci=posljednji;
    broj_kreiranih++;
}

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol) {
    if (!DaLiJeDatumIspravan(dan_rodjenja,mjesec_rodjenja,godina_rodjenja) || sifra_regije<0 || sifra_regije>99 || (int(pol)!=0 && int(pol)!=1))
        throw std::logic_error("Neispravni podaci");
    GradjaninBiH::jmbg[0]=(dan_rodjenja/10)%10;
    GradjaninBiH::jmbg[1]=dan_rodjenja%10;
    GradjaninBiH::jmbg[2]=(mjesec_rodjenja/10)%10;
    GradjaninBiH::jmbg[3]=mjesec_rodjenja%10;
    GradjaninBiH::jmbg[4]=((godina_rodjenja/10)/10)%10;
    GradjaninBiH::jmbg[5]=(godina_rodjenja/10)%10;
    GradjaninBiH::jmbg[6]=godina_rodjenja%10;
    GradjaninBiH::jmbg[7]=(sifra_regije/10)%10;
    GradjaninBiH::jmbg[8]=sifra_regije%10;
    int cifra_10, cifra_11, cifra_12;
    bool konacno_pronadjen=false;
    if (int(pol)==0) {
        for (int i=0; i<500; i++) {
            cifra_10=((i/10)/10)%10;
            cifra_11=(i/10)%10;
            cifra_12=i%10;
            if (prvi!=nullptr) {
                bool pronadjen=true;
                auto it=posljednji;
                for (int i=0; i<broj_kreiranih; i++) {
                    for (int i=0; i<12; i++) {
                        if (i==9 && it->jmbg[i]!=cifra_10) {
                            pronadjen=false;
                            break;
                        }
                        else if (i==10 && it->jmbg[i]!=cifra_11) {
                            pronadjen=false;
                            break;
                        }
                        else if (i==11 && it->jmbg[i]!=cifra_12) {
                            pronadjen=false;
                            break;
                        }
                        else {
                            if (jmbg[i]!=it->jmbg[i]) {
                                pronadjen=false;
                                break;
                            }
                        }
                    }
                    if (!pronadjen) {
                        GradjaninBiH::jmbg[9]=cifra_10;
                        GradjaninBiH::jmbg[10]=cifra_11;
                        GradjaninBiH::jmbg[11]=cifra_12;
                        konacno_pronadjen=true;
                        break;
                    }
                    it=it->sljedeci;
                }
            }
            else {
                GradjaninBiH::jmbg[9]=cifra_10;
                GradjaninBiH::jmbg[10]=cifra_11;
                GradjaninBiH::jmbg[11]=cifra_12;
                konacno_pronadjen=true;
            }
            if (konacno_pronadjen) break;
        }
    }
    else {
        for (int i=500; i<1000; i++) {
            cifra_10=((i/10)/10)%10;
            cifra_11=(i/10)%10;
            cifra_12=i%10;
            if (prvi!=nullptr) {
                bool pronadjen=true;
                auto it=posljednji;
                for (int i=0; i<broj_kreiranih; i++) {
                    for (int i=0; i<12; i++) {
                        if (i==9 && it->jmbg[i]!=cifra_10) {
                            pronadjen=false;
                            break;
                        }
                        else if (i==10 && it->jmbg[i]!=cifra_11) {
                            pronadjen=false;
                            break;
                        }
                        else if (i==11 && it->jmbg[i]!=cifra_12) {
                            pronadjen=false;
                            break;
                        }
                        else {
                            if (jmbg[i]!=it->jmbg[i]) {
                                pronadjen=false;
                                break;
                            }
                        }
                    }
                    if (!pronadjen) {
                        GradjaninBiH::jmbg[9]=cifra_10;
                        GradjaninBiH::jmbg[10]=cifra_11;
                        GradjaninBiH::jmbg[11]=cifra_12;
                        konacno_pronadjen=true;
                        break;
                    }
                    it=it->sljedeci;
                }
            }
            else {
                GradjaninBiH::jmbg[9]=cifra_10;
                GradjaninBiH::jmbg[10]=cifra_11;
                GradjaninBiH::jmbg[11]=cifra_12;
                konacno_pronadjen=true;
            }
            if (konacno_pronadjen) break;
        }
    }
    int cifra_13;
    cifra_13=11-(7*(jmbg[0]+jmbg[6])+6*(jmbg[1]+jmbg[7])+5*(jmbg[2]+jmbg[8])+4*(jmbg[3]+jmbg[9])+3*(jmbg[4]+jmbg[10])+2*(jmbg[5]+jmbg[11]))%11;
    if (cifra_13==11) cifra_13=0;
    else if (cifra_13==10) throw std::logic_error("Neispravni podaci");
    GradjaninBiH::jmbg[12]=cifra_13;
    this->ime_i_prezime=ime_i_prezime;
    sljedeci=posljednji;
    posljednji=this;
    if (broj_kreiranih==0) prvi=this;
    else prvi->sljedeci=posljednji;
    broj_kreiranih++;
}

GradjaninBiH::~GradjaninBiH() {
    if (this==posljednji) {
        posljednji=posljednji->sljedeci;
        if (broj_kreiranih==1) prvi=nullptr;
        else prvi->sljedeci=posljednji;
    }
    else if (this==prvi) {
        auto it=posljednji;
        while (it=it->sljedeci,it->sljedeci!=prvi);
        prvi=it;
        prvi->sljedeci=posljednji;
    }
    else {
        auto it=this;
        while (it=it->sljedeci,it->sljedeci!=this);
        it->sljedeci=this->sljedeci;
    } 
    broj_kreiranih--;
}

long long int GradjaninBiH::DajJMBG() const {
    long long int novi_jmbg=0;
    for (int i=0; i<13; i++) {
        novi_jmbg*=10;
        novi_jmbg+=jmbg[i];
    }
    return novi_jmbg;
}

GradjaninBiH* GradjaninBiH::posljednji=nullptr;
GradjaninBiH* GradjaninBiH::prvi=nullptr;
int GradjaninBiH::broj_kreiranih=0;

int main () {
    int broj_gradjana1;
    std::cout << "Koliko gradjana zelite unijeti po JMBG? " << std::endl;
    std::cin >> broj_gradjana1;
    GradjaninBiH *niz[100]{};
    for (int i=0; i<broj_gradjana1; i++) {
        bool bacen_izuzetak=false;
        do {
            std::string ime_i_prezime;
            long long int jmbg;
            std::cin.ignore(10000,'\n');
            bacen_izuzetak=false;
            std::cout << "Unesite ime i prezime (u istom redu): " << std::endl;
            std::getline(std::cin,ime_i_prezime);
            std::cout << "Unesite JMBG: " << std::endl;
            std::cin >> jmbg;
            try {
                niz[i]=new GradjaninBiH(ime_i_prezime,jmbg);
                std::cout << "Unijeli ste gradjanina " << niz[i]->DajImeIPrezime() << " rodjenog "
                << niz[i]->DajDanRodjenja() << "." << niz[i]->DajMjesecRodjenja() << "." 
                << niz[i]->DajGodinuRodjenja() << " u regiji " << niz[i]->DajSifruRegije() << ",";
                if (int(niz[i]->DajPol())==0) std::cout << " musko." << std::endl;
                else std::cout << " zensko." << std::endl;
            }
            catch(std::logic_error izuzetak) {
                std::cout << izuzetak.what() << std::endl;
                bacen_izuzetak=true;
            }
        } while(bacen_izuzetak);
    }
    int broj_gradjana2;
    std::cout << "Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? " << std::endl;
    std::cin >> broj_gradjana2;
    for (int i=broj_gradjana1; i<broj_gradjana1+broj_gradjana2; i++) {
        bool bacen_izuzetak=false;
        do {
            std::string ime_i_prezime;
            int dan, mjesec, godina, sifra_regije;
            char znak;
            std::cin.ignore(10000,'\n');
            bacen_izuzetak=false;
            std::cout << "Unesite ime i prezime (u istom redu): " << std::endl;
            std::getline(std::cin,ime_i_prezime);
            std::cout << "Unesite datum rodjenja (format dd/mm/gggg): " << std::endl;
            std::cin >> dan >> znak >> mjesec >> znak >> godina;
            std::cout << "Unesite sifru regije: " << std::endl;
            std::cin >> sifra_regije;
            std::cout << "Unesite M za musko, Z za zensko: " << std::endl;
            std::cin >> znak;
            try {
                if (znak=='M') niz[i]=new GradjaninBiH(ime_i_prezime,dan,mjesec,godina,sifra_regije,GradjaninBiH::Pol(0));
                else niz[i]=new GradjaninBiH(ime_i_prezime,dan,mjesec,godina,sifra_regije,GradjaninBiH::Pol(1));
                std::cout << "Unijeli ste gradjanina " << niz[i]->DajImeIPrezime() << " JMBG: " << niz[i]->DajJMBG() << "." << std::endl;
            }
            catch(std::logic_error izuzetak) {
                std::cout << izuzetak.what() << std::endl;
                bacen_izuzetak=true;
            }
        } while(bacen_izuzetak);
    }
    for (int i=0; i<broj_gradjana1+broj_gradjana2; i++)
        delete niz[i];
	return 0;
}