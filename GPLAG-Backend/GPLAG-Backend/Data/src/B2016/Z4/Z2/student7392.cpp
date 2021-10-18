/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>
#include <new>
enum PraviPol{m, z};

bool testdatuma(int dan, int mjesec, int godina){
    int dani[]{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina%4!=0 || godina%400==0)dani[1]--;
    return !(dan<1 || mjesec<1 || godina<1 || dan>dani[mjesec-1] || mjesec>12);
}

int dajbrojcifri(long long int a){
    int k=0;
    while(a){
        k++;
        a/=10;
    }
    return k;
}

void obradijmbg(long long int a, int &dan, int &mjesec, int &godina, int &sifraregije, int &kod, PraviPol &pol){
    if(dajbrojcifri(a)<12 || dajbrojcifri(a)>13)throw std::domain_error("JMBG nije validan");
    int niz[13];
    for(int i=12;i>=0;i--){
        niz[i]=a%10;
        a/=10;
    }
    int c=11-(7*(niz[0]+niz[6])+6*(niz[1]+niz[7])+5*(niz[2]+niz[8])+4*(niz[3]+niz[9])+3*(niz[4]+niz[10])+2*(niz[5]+niz[11]))%11;
    if(c==11)c=0;
    if(c!=niz[12])throw std::domain_error("JMBG nije validan");
    dan=niz[0]*10+niz[1];
    mjesec=niz[2]*10+niz[3];
    godina=1000+niz[4]*100+niz[5]*10+niz[6];
    if(godina<1018)godina+=1000;
    if(!testdatuma(dan, mjesec, godina))throw std::domain_error("JMBG nije validan");
    sifraregije=niz[7]*10+niz[8];
    kod=niz[9]*100+niz[10]*10+niz[11];
    if(kod<500)pol=PraviPol::m; else pol=PraviPol::z;
}

long long int napravijmbg(int dan, int mjesec, int godina, int sifraregije, int kod){
    long long int jmbg=0;
    jmbg+=dan;
    jmbg=jmbg*100+mjesec;
    godina%=1000;
    jmbg=jmbg*1000+godina;
    jmbg=jmbg*100+sifraregije;
    jmbg=jmbg*1000+kod;
    jmbg=jmbg*10;
    int niz[13];
    long long int a=jmbg;
    for(int i=12;i>=0;i--){
        niz[i]=a%10;
        a/=10;
    }
    int c=11-(7*(niz[0]+niz[6])+6*(niz[1]+niz[7])+5*(niz[2]+niz[8])+4*(niz[3]+niz[9])+3*(niz[4]+niz[10])+2*(niz[5]+niz[11]))%11;
    if(c==11)c=0;
    if(c==10)return 0;
    jmbg+=c;
    return jmbg;
}

class GradjaninBiH{
    std::string imeiprezime;
    long long int jmbg;
    int dan, mjesec, godina, sifraregije, kod;
    PraviPol pol;
    GradjaninBiH *prethodni;
    static GradjaninBiH *zadnji;
    
public:
    GradjaninBiH(const GradjaninBiH &g)=delete;
    void operator =(const GradjaninBiH &g)=delete;
    enum Pol{Musko, Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol);
    ~GradjaninBiH();
    std::string DajImeIPrezime() const{return imeiprezime;}
    long long int DajJMBG() const{return jmbg;}
    int DajDanRodjenja() const{return dan;}
    int DajMjesecRodjenja() const{return mjesec;}
    int DajGodinuRodjenja() const{return godina;}
    int DajSifruRegije() const{return sifraregije;}
    Pol DajPol() const{if(pol==PraviPol::m)return Pol::Musko; return Pol::Zensko;}
    void PromijeniImeIPrezime(std::string novo_ime){imeiprezime=novo_ime;}
};

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg){
        obradijmbg(jmbg, dan, mjesec, godina, sifraregije, kod, pol);
        this->jmbg=jmbg;
        imeiprezime=ime_i_prezime;
        if(zadnji==nullptr){
            prethodni=nullptr;
        } else {
            GradjaninBiH *test=zadnji;
            for(;test!=nullptr;test=test->prethodni){
                if(jmbg==test->DajJMBG())throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
            }
            prethodni=zadnji;
        }
        zadnji=this;
    }
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol){
        if(!testdatuma(dan_rodjenja, mjesec_rodjenja, godina_rodjenja) || sifra_regije<0 || sifra_regije>99){
            throw std::domain_error("Neispravni podaci");
        }
        int min=0, max=500;
        if(pol!=Pol::Musko){
            min=500;
            max=1000;
        }
        dan=dan_rodjenja;
        mjesec=mjesec_rodjenja;
        godina=godina_rodjenja;
        sifraregije=sifra_regije;
        if(pol==Pol::Musko)this->pol=PraviPol::m; else this->pol=PraviPol::z;
        imeiprezime=ime_i_prezime;
        long long int tempjmbg;
        for(int i=min;i<max;i++){
            tempjmbg=napravijmbg(dan, mjesec, godina, sifraregije, i);
            if(tempjmbg==0){
                if(i==max-1)throw std::range_error("nema mjesta");
                continue;
            }
            bool naso=false;
            GradjaninBiH *test=zadnji;
            for(;test!=nullptr;test=test->prethodni){
                if(test->DajJMBG()==tempjmbg){
                    naso=true;
                    break;
                }
            }
            if(!naso){
                jmbg=tempjmbg;
                break;
            }
            if(i==max-1)throw std::range_error("nema mjesta");
        }
        if(zadnji==nullptr){
            prethodni=nullptr;
        } else {
            prethodni=zadnji;
        }
        zadnji=this;
    }
GradjaninBiH::~GradjaninBiH(){
        GradjaninBiH *test=zadnji;
        if(test==this){
            if(test->prethodni==nullptr){
                zadnji=nullptr;
            } else {
                zadnji=zadnji->prethodni;
            }
        } else {
            for(;test!=nullptr;test=test->prethodni){
                if(test->prethodni==this){
                   break;
                }
            }
            test->prethodni=this->prethodni;
        } 
    }

GradjaninBiH* GradjaninBiH::zadnji=nullptr;

int main ()
{
    std::cout<<"Koliko gradjana zelite unijeti po JMBG? \n";
    GradjaninBiH *niz[100];
    for(int i=0;i<100;i++)niz[i]=nullptr;
    int n;
    std::cin>>n;
    for(int i=0;i<n;i++){
        do{
            try{
                std::cout<<"Unesite ime i prezime (u istom redu): \n";
                std::string a;
                std::cin.ignore(1000, '\n');
                std::getline(std::cin, a, '\n');
                std::cout<<"Unesite JMBG: \n";
                long long int b;
                std::cin>>b;
                niz[i]=new GradjaninBiH(a, b);
                std::cout<<"Unijeli ste gradjanina "<<niz[i]->DajImeIPrezime()<<" rodjenog "<<niz[i]->DajDanRodjenja()<<"."<<niz[i]->DajMjesecRodjenja();
                std::cout<<"."<<niz[i]->DajGodinuRodjenja()<<" u regiji "<<niz[i]->DajSifruRegije()<<", ";
                if(niz[i]->DajPol()==GradjaninBiH::Pol::Musko)std::cout<<"musko"; else std::cout<<"zensko";
                std::cout<<".\n";
                break;
            }
            catch(std::domain_error gg){
                std::cout<<gg.what()<<'\n';
            }
            catch(std::bad_alloc){
                for(int i=0;i<100;i++)delete niz[i];
                return 0;
            }
        }while(true);
    }
    std::cout<<"Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? \n";
    int m;
    std::cin>>m;
    for(int i=n;i<n+m;i++){
        do{
            try{
                std::cout<<"Unesite ime i prezime (u istom redu): \n";
                std::string a;
                std::cin.ignore(1000, '\n');
                std::getline(std::cin, a, '\n');
                std::cout<<"Unesite datum rodjenja (format dd/mm/gggg): \n";
                int dan, mjesec, godina;
                std::scanf("%d/%d/%d", &dan, &mjesec, &godina);
                std::cout<<"Unesite sifru regije: \n";
                int sifra;
                std::cin>>sifra;
                std::cout<<"Unesite M za musko, Z za zensko: \n";
                char c;
                std::cin.ignore(1000, '\n');
                std::cin>>c;
                if(c=='M'){
                    niz[i]=new GradjaninBiH(a, dan, mjesec, godina, sifra, GradjaninBiH::Pol::Musko);
                    std::cout<<"Unijeli ste gradjanina "<<niz[i]->DajImeIPrezime()<<" JMBG: "<<niz[i]->DajJMBG()<<".\n";
                } 
                if(c=='Z'){
                    niz[i]=new GradjaninBiH(a, dan, mjesec, godina, sifra, GradjaninBiH::Pol::Zensko);
                    std::cout<<"Unijeli ste gradjanina "<<niz[i]->DajImeIPrezime()<<" JMBG: "<<niz[i]->DajJMBG()<<".\n";
                }
                break;
            }
            catch(std::domain_error gg){
                std::cout<<gg.what()<<'\n';
            }
            catch(std::bad_alloc){
                for(int i=0;i<100;i++)delete niz[i];
                return 0;
            }
        }while(true);
    }
	return 0;
}