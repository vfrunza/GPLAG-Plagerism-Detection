/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <new>
class GradjaninBiH
{
    std::string ime_i_prezime;
    int jmbg_niz[13];
    GradjaninBiH *prethodni;
    static GradjaninBiH *posljednji;
    bool NeispravanDatum(const int &d, const int &m, const int &g);
    public:
        enum Pol {Musko, Zensko};
        GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
        GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol);
        ~GradjaninBiH()
        {
            if(this==posljednji)
            {
                auto *temp(posljednji->prethodni);
                if(temp==posljednji || temp==nullptr) posljednji=nullptr;
                else
                {
                    posljednji=nullptr;
                    posljednji=temp;
                }
            }
            else
            {
                for(auto pok=posljednji;pok!=nullptr; pok=pok->prethodni)
                if(this==pok->prethodni)
                {
                    auto*temp(pok->prethodni->prethodni
                    );
                    if(temp==nullptr || temp==pok->prethodni) pok->prethodni=nullptr;
                    else
                    {
                        pok->prethodni=nullptr;
                        pok->prethodni=temp;
                    }
                }
            }
        }
        std::string DajImeIPrezime() const{return ime_i_prezime;}
        long long int DajJMBG() const{long long int broj(0), n(1); for(int i=12; i>=0; i--){broj+=(static_cast<long long int>(jmbg_niz[i]))*n; n*=10;} return broj;}
        int DajDanRodjenja() const{return jmbg_niz[0]*10+jmbg_niz[1];}
        int DajMjesecRodjenja() const{return jmbg_niz[2]*10+jmbg_niz[3];}
        int DajGodinuRodjenja() const{if(jmbg_niz[4]==0) return 2000+jmbg_niz[4]*100+jmbg_niz[5]*10+jmbg_niz[6]; else return 1000+jmbg_niz[4]*100+jmbg_niz[5]*10+jmbg_niz[6];};
        int DajSifruRegije() const{return jmbg_niz[7]*10+jmbg_niz[8];}
        Pol DajPol() const{if(jmbg_niz[9]<5) return Pol::Musko; else return Pol::Zensko;};
        void PromijeniImeIPrezime(std::string novo_ime){ime_i_prezime=novo_ime;}
};
GradjaninBiH *GradjaninBiH::posljednji(nullptr);

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg)
{
    if(jmbg<static_cast<long long int>(10000000000) || (jmbg>static_cast<long long int>(912999999999) && jmbg<static_cast<long long int>(1000000000000)) || jmbg>static_cast<long long int>(3112999999999)) throw std::logic_error("JMBG nije validan");
    int niz[13]={};
    for(int i=12; jmbg!=0; i--, jmbg/=10)   niz[i]=jmbg%10;
    int KontrolnaCifra(0), k(7);
    for(int i=0; i<6; i++)  KontrolnaCifra+=(k--)*(niz[i]+niz[i+6]);
    KontrolnaCifra=11-(KontrolnaCifra%11);
    if(KontrolnaCifra==11)  KontrolnaCifra=0;
    if(NeispravanDatum(niz[0]*10+niz[1],niz[2]*10+niz[3],niz[4]*100+niz[5]*10+niz[6]) || niz[12]!=KontrolnaCifra) throw std::logic_error("JMBG nije validan");
    for(auto pok=posljednji; pok!=nullptr; pok=pok->prethodni)
    {
        if(prethodni==pok) break;
        if(std::equal(std::begin(pok->jmbg_niz), std::end(pok->jmbg_niz), std::begin(niz))) 
        throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
    }
    this->ime_i_prezime=ime_i_prezime;
    for(int i=0; i<12; i++)
    (this->jmbg_niz[i])=niz[i];
    prethodni=posljednji;
    posljednji=this;
}
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
    int godina_rodjenja, int sifra_regije, Pol pol)
    {
        if(NeispravanDatum(dan_rodjenja, mjesec_rodjenja, godina_rodjenja) || sifra_regije<0 || sifra_regije>99) throw std::logic_error("Neispravni podaci");
        else
        {
            jmbg_niz[0]=dan_rodjenja/10; jmbg_niz[1]=dan_rodjenja%10;
            jmbg_niz[2]=mjesec_rodjenja/10; jmbg_niz[3]=mjesec_rodjenja%10;
            jmbg_niz[4]=(godina_rodjenja%1000)/100; jmbg_niz[5]=(godina_rodjenja%100)/10; jmbg_niz[6]=godina_rodjenja%10;
            jmbg_niz[7]=sifra_regije/10; jmbg_niz[8]=sifra_regije%10;
            int brojac(0);
            for(auto pok=posljednji; pok!=nullptr; pok=pok->prethodni)
            {
                if(prethodni==pok) break;
                bool NijePronadjen(false);
                for(int i=0; i<8; i++)
                    if(pok->jmbg_niz[i]!=jmbg_niz[i])   {NijePronadjen=true; break;}
                if(NijePronadjen || pol==Pol::Musko && jmbg_niz[9]>4 || pol==Pol::Zensko && jmbg_niz[9]<5)  continue;
                else brojac++;
            }
            if(pol==Pol::Zensko) brojac+=500;
            jmbg_niz[9]=brojac/100; jmbg_niz[10]=(brojac%100)/10; jmbg_niz[11]=brojac%10; //<--------------------------
            jmbg_niz[12]=0;
            int k(7);
            for(int i=0; i<6; i++) jmbg_niz[12]+=(k--)*(jmbg_niz[i]+jmbg_niz[i+6]);
            jmbg_niz[12]=11-(jmbg_niz[12]%11);
            if(jmbg_niz[12]==10) throw std::logic_error("JMBG nije validan");
            else if(jmbg_niz[12]==11) jmbg_niz[12]=0;//<------------------------- FORMULA
        }
    }
bool GradjaninBiH::NeispravanDatum(const int &d, const int &m, const int &g)
{
    int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if(g%4==0 && g%100!=0 || g%400==0)   broj_dana[1]++;
    if(g<1 || d<1 || m<1 || m>12 || d>broj_dana[m-1])   return true;
    return false;
}
/*long long int DajJMBG()
{
    long long int broj, n(1);
    for(int i=12; i>=0;i--)
    {
        broj+=jmbg_niz[i]*n;
        n*=10;
    }
    return broj;
}*/
int main ()
{
    int n;
    std::cout<<"Koliko gradjana zelite unijeti po JMBG? "<<std::endl;
    std::cin>>n;
    GradjaninBiH *pok_niz[100];
    for(int i=0; i<n; i++)
    {
        std::cin.ignore(10000,'\n');
        std::cin.clear();
        try
        {
            long long int jmbg;
            std::string ime;
            std::cout<<"Unesite ime i prezime (u istom redu): "<<std::endl;
            std::getline(std::cin, ime);
            std::cout<<"Unesite JMBG: "<<std::endl;
            std::cin>>jmbg;
                GradjaninBiH gradjanin(ime, jmbg);
                std::cout<<"Unijeli ste gradjanina "<<ime<<" rodjenog "<<gradjanin.DajDanRodjenja()<<"."<<gradjanin.DajMjesecRodjenja()<<"."<<gradjanin.DajGodinuRodjenja()<<" u regiji "<<gradjanin.DajSifruRegije()<<", ";
                if(gradjanin.DajPol()==0) std::cout<<"musko."<<std::endl; else std::cout<<"zensko."<<std::endl;
            pok_niz[i]=new GradjaninBiH(gradjanin);
        }
        catch(std::logic_error izuzetak){i--; std::cout<<izuzetak.what()<<std::endl;}
        catch(...){return 0;}
    }
    int m;
    std::cout<<"Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? "<<std::endl;
    std::cin>>m;
    std::cin.ignore(10000,'\n');
    std::cin.clear();
    for(int i=0; i<m; i++)
    {
        try
        {
            std::string ime;
            std::string datum;
            int sifra;
            std::string pol;
            GradjaninBiH::Pol pol_br;
            std::cout<<"Unesite ime i prezime (u istom redu): "<<std::endl;
            std::getline(std::cin, ime);
            std::cout<<"Unesite datum rodjenja (format dd/mm/gggg): "<<std::endl;
            std::cin>>datum;
            std::cout<<"Unesite sifru regije: "<<std::endl;
            std::cin>>sifra;
            std::cin.ignore(10000,'\n');
            std::cin.clear();
            std::cout<<"Unesite M za musko, Z za zensko: "<<std::endl;
            std::getline(std::cin, pol);
            if(pol=="M") pol_br=GradjaninBiH::Pol::Musko; else if(pol=="Z") pol_br=GradjaninBiH::Pol::Zensko;
            GradjaninBiH gradjanin(ime, datum[0]*10+datum[1]-528, datum[3]*10+datum[4]-528, datum[6]*1000+datum[7]*100+datum[8]*10+datum[9]-53328, sifra, pol_br);
            std::cout<<"Unijeli ste gradjanina "<<ime<<" JMBG: "<<gradjanin.DajJMBG()<<"."<<std::endl;
            pok_niz[n+i]=new GradjaninBiH(gradjanin);
            
        }
        catch(std::logic_error izuzetak){i--;std::cout<<izuzetak.what()<<std::endl;}
        catch(...){return 0;}
        
    }
    for(int i=0; i<n+m; i++)
    {
        delete pok_niz[i];
    }
    
}