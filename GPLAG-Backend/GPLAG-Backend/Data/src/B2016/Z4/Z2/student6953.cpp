#include <iostream>
#include<stdexcept>
#include <cstdlib>
#include <ctime>
class GradjaninBiH
{
    std::string imeiprezime;
    long long int JMBG;
    static GradjaninBiH *novi;
    GradjaninBiH * posljednji=nullptr;
public:
    enum Pol {Musko, Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg) {
        long long int a=jmbg;
        int v1[]= {0,0,0,0,0,0,0,0,0,0,0,0,0};
        int br=12;
        while(jmbg!=0) {
            v1[br]=(jmbg%10);
            jmbg/=10;
            br--;
        }
        int dan=v1[0]*10+v1[1];
        int mjesec=v1[2]*10+v1[3];
        int godina=v1[4]*100+v1[5]*10+v1[6];
        if((godina+1000)<=2017 && (godina +1000) >=2017-100) godina=godina+1000;
        else godina=godina +2000;
        int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
        if((godina%4==0 && godina%100!=0)|| godina%400==0) broj_dana[1]++;
        if(godina<1917 || godina>2017 || mjesec<1 || mjesec>12 || dan<1 || dan>broj_dana[mjesec-1]) throw std::logic_error("JMBG nije validan");
        int f=(11-(7*(v1[0]+v1[6])+6*(v1[1]+v1[7])+5*(v1[2]+v1[8])+4*(v1[3]+v1[9])+3*(v1[4]+v1[10])+2*(v1[5]+v1[11]))%11);
        if(f==11) f=0;
        if(v1[12]!=f) throw std::logic_error("JMBG nije validan");

        for(auto it=novi; it!=nullptr; it=it->posljednji) {
            if((it->JMBG)==a) throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
        }
        GradjaninBiH *trenutni=this;
        trenutni->imeiprezime=ime_i_prezime;
        trenutni->JMBG=a;
        trenutni->posljednji=novi;
        novi=trenutni;
    }
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol) {
        imeiprezime=ime_i_prezime;
        int dan_rodjenja1=dan_rodjenja;
        int sifra_regije1=sifra_regije;
        int matbroj[]= {0,0,0,0,0,0,0,0,0,0,0,0,0};
        int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
        if((godina_rodjenja%4==0 && godina_rodjenja%100!=0)|| godina_rodjenja%400==0) broj_dana[1]++;
        if(godina_rodjenja<1917 || godina_rodjenja>2017 || mjesec_rodjenja<1 || mjesec_rodjenja>12 || dan_rodjenja<1 || dan_rodjenja>broj_dana[mjesec_rodjenja-1] || sifra_regije<0 || sifra_regije>99) throw std::logic_error("Neispravni podaci");

        if(dan_rodjenja/10==0)  matbroj[1]=dan_rodjenja;
        else {
            matbroj[1]=dan_rodjenja%10;
            matbroj[0]=dan_rodjenja/10;
        }

        if(mjesec_rodjenja/10==0) matbroj[3]=mjesec_rodjenja;
        else {
            matbroj[3]=mjesec_rodjenja%10;
            matbroj[2]=mjesec_rodjenja/10;
        }
        matbroj[6]=godina_rodjenja%10;
        godina_rodjenja/=10;
        matbroj[5]=godina_rodjenja%10;
        godina_rodjenja/=10;
        matbroj[4]=godina_rodjenja%10;
        matbroj[8]=sifra_regije%10;
        sifra_regije/=10;
        matbroj[7]=sifra_regije%10;
        if(pol==Musko) {
            int i=0;
            for(int p=0; p<500; p++) {
                bool postaoje=0;
                for(auto it1=novi; it1!=nullptr; it1=it1->posljednji) {
                    if(it1->DajPol()==Musko) {
                        if(it1->DajDanRodjenja()==dan_rodjenja1 && it1->DajSifruRegije()==sifra_regije1) {
                            long long int h=it1->JMBG;
                            int v12[13]= {0,0,0,0,0,0,0,0,0,0,0,0,0};
                            int br=12;
                            while(h!=0) {
                                v12[br]=(h%10);
                                h/=10;
                                br--;
                            }
                            i=v12[9]*100+v12[10]*10+v12[11];

                            if(i==p) {
                                i=i++;
                                break;
                            } else {
                                break;
                            }
                        }
                        i=p;
                    }
                }
                break;
            }
            matbroj[11]=i%10;
            i/=10;
            matbroj[10]=i%10;
            i/=10;
            matbroj[9]=i%10;
        } else if(pol==Zensko) {
            int i=0;
            for(int p=500; p<1000; p++) {
                bool postaoje=0;
                for(auto it1=novi; it1!=nullptr; it1=it1->posljednji) {
                    if(it1->DajPol()==Zensko) {
                        long long int h=it1->JMBG;
                        int v12[13]= {0,0,0,0,0,0,0,0,0,0,0,0,0};
                        int br=12;
                        while(h!=0) {
                            v12[br]=(h%10);
                            h/=10;
                            br--;
                        }
                        i=v12[9]*100+v12[10]*10+v12[11];
                        if(it1->DajDanRodjenja()==dan_rodjenja1 && it1->DajSifruRegije()==sifra_regije1) {
                            if(i==p)p++;
                            else {
                                i=p;
                                postaoje=1;
                                break;
                            }
                        }
                    }
                }
                if(postaoje==1)break;
                else if(postaoje==0) {
                    i=p;
                    break;
                }
            }

            matbroj[11]=i%10;
            i/=10;
            matbroj[10]=i%10;
            i/=10;
            matbroj[9]=i%10;
        }
        int x=(11-(7*(matbroj[0]+matbroj[6])+6*(matbroj[1]+matbroj[7])+5*(matbroj[2]+matbroj[8])+4*(matbroj[3]+matbroj[9])+3*(matbroj[4]+matbroj[10])+2*(matbroj[5]+matbroj[11]))%11);
        if(x==11) x=0;
        if(x==10) std::logic_error("Neispravni podaci");
        matbroj[12]=x;
        long long int broj=0;
        for(int i=0; i<13; i++) {
            broj=broj*10+matbroj[i];
        }

        for(auto it=novi; it!=nullptr; it=it->posljednji) {
            if((it->JMBG)==broj) throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
        }
        GradjaninBiH *trenutni=this;
        trenutni->imeiprezime=ime_i_prezime;
        trenutni->JMBG=broj;
        trenutni->posljednji=novi;
        novi=trenutni;
    }
    std::string DajImeIPrezime() const {
        return imeiprezime;
    }
    long long int DajJMBG() const {
        return JMBG;
    }
    int DajDanRodjenja() const {
        long long int a=JMBG;
        int v1[13]= {};
        int br=12;
        while(a!=0) {
            v1[br]=(a%10);
            a/=10;
            br--;
        }
        return v1[0]*10+v1[1];
    }
    int DajMjesecRodjenja() const {
        long long int a=JMBG;
        int v1[13]= {};
        int br=12;
        while(a!=0) {
            v1[br]=(a%10);
            a/=10;
            br--;
        }
        return v1[2]*10+v1[3];
    }
    int DajGodinuRodjenja() const {
        long long int a=JMBG;
        int v1[13]= {};
        int br=12;
        while(a!=0) {
            v1[br]=(a%10);
            a/=10;
            br--;
        }
        int godina=v1[4]*100+v1[5]*10+v1[6];
        if((godina+1000)<=2017 && (godina +1000) >=2017-100) godina=godina+1000;
        else godina=godina +2000;
        return godina;
    }
    int DajSifruRegije() const {
        long long int a=JMBG;
        int v1[13]= {};
        int br=12;
        while(a!=0) {
            v1[br]=(a%10);
            a/=10;
            br--;
        }
        return v1[7]*10+v1[8];
    }
    Pol DajPol() const {
        long long int a=JMBG;
        int v1[13]= {};
        int br=12;
        while(a!=0) {
            v1[br]=(a%10);
            a/=10;
            br--;
        }
        int sifra=v1[9]*100+v1[10]*10+v1[11];
        if(sifra>=0 && sifra<=499) return Pol(Musko);
        else if(sifra>=500 && sifra<=999) return  Pol(Zensko);
    }
    void PromijeniImeIPrezime(std::string novo_ime) {
        imeiprezime=novo_ime;
    }
    GradjaninBiH(const GradjaninBiH &a)=delete;
    GradjaninBiH &operator=(const GradjaninBiH &a)=delete;
    ~GradjaninBiH() {
        if(this==novi) {
            novi=this->posljednji;
            this->posljednji=nullptr;
        }
        if(this->posljednji==nullptr) {
            for(auto it=novi; it!=nullptr; it=it->posljednji) {
                if(it->posljednji==this) it->posljednji=nullptr;
            }
        }
        for(auto it=novi; it!=nullptr; it=it->posljednji) {
            if(it->posljednji==this) it->posljednji=this->posljednji;
        }

    }
};
GradjaninBiH *GradjaninBiH::novi(nullptr);
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
            if(g.DajPol()==0) std::cout << "musko"<<"."<<std::endl;
            else std::cout << "zensko"<<"."<<std::endl;
        } catch(std::logic_error izuzetak) {
            i--;
            std::cout<<izuzetak.what()<<std::endl;
        }
        std::cin.ignore(1000,'\n');
    }
    std::cout<<"Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? \n";
    int m;
    std::cin>>m;
    std::cin.ignore(1000,'\n');
    int dan, mjesec, godina;
    for(int i=0; i<m; i++) {
        try {
            std::cout<<"Unesite ime i prezime (u istom redu): ";
            std::string ime;
            std::getline(std::cin, ime);
            std::cout<<std::endl;
            std::cout<<"Unesite datum rodjenja (format dd/mm/gggg): "<<std::endl;
            char znak;
            std::cin >> dan >> znak >> mjesec >> znak >> godina;
            std::cout<<"Unesite sifru regije: "<<std::endl;
            int sr;
            std::cin.ignore(1000,'\n');
            std::cin>>sr;
            std::cout<<"Unesite M za musko, Z za zensko: \n";
            std::cin.ignore(1000,'\n');
            char slovo;
            std::cin>>slovo;
            if(slovo=='M') {
                GradjaninBiH gradjanin1(ime, dan, mjesec, godina, sr, GradjaninBiH::Pol::Musko);
                std::cout<<"Unijeli ste gradjanina "<<gradjanin1.DajImeIPrezime()<<" JMBG: "<<gradjanin1.DajJMBG()<<"."<<std::endl;
            }
            if(slovo=='Z') {
                GradjaninBiH gradjanin1(ime, dan, mjesec, godina, sr, GradjaninBiH::Pol::Zensko);
                std::cout<<"Unijeli ste gradjanina "<<gradjanin1.DajImeIPrezime()<<" JMBG: "<<gradjanin1.DajJMBG()<<"."<<std::endl;
            }
        } catch(std::logic_error izuzetak) {
            std::cout<<izuzetak.what()<<std::endl;
            i--;
        }
        std::cin.ignore(1000,'\n');
    }

    return 0;
}