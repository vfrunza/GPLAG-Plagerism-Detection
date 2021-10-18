#include <iostream>
#include <stdexcept>
#include <string>

using std::cin;
using std::cout;

int BrojacCifara(long long int x){
    int brojac(0);
    while(x!=0){
        x/=10;
        brojac++;
    }
    return brojac;
}
bool PrestupnaGodina(int g){
    if(g%4==0 && g%100!=0 || g%400==0) return true;
    return false;
}

bool IspravnostDatuma(int d,int m,int g){
    if(d==0 || d>31 || m==0 || m>12 || g<1917 || g>2017) return false;
    if(d==31 && m==4 && m==6 && m==9 && m==11) return false;
    if(d==29 && m==2 && !PrestupnaGodina(g)) return false;
    return true;
}

class GradjaninBiH{
    std::string imeiprez;
    long long int JMBG;
    int danrodj,mjrodj,godrodj,sifrareg;
    static GradjaninBiH *posljedni;
    GradjaninBiH *prije;
    int kodosobe;
    public:
    enum Pol{Musko,Zensko};
    GradjaninBiH(std::string ime_i_prezime,long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime,int dan_rodjenja,int mjesec_rodjenja,int godina_rodjenja,int sifra_regije,Pol pol);
    GradjaninBiH(const GradjaninBiH &g)=delete;
    GradjaninBiH &operator =(const GradjaninBiH &g)=delete;
    ~GradjaninBiH() {
        for(auto p=posljedni;p!=nullptr;p=p->prije){
            if(posljedni==this){
                posljedni=posljedni->prije;
                break;
            }
            if(p->prije==this){
                p->prije=this->prije;
                break;
            }
        }
    }
    std::string DajImeIPrezime() const{ return imeiprez;}
    long long int DajJMBG() const{return JMBG;}
    int DajDanRodjenja() const{return danrodj;}
    int DajMjesecRodjenja() const{return mjrodj;}
    int DajGodinuRodjenja() const{return godrodj;}
    int DajSifruRegije() const{return sifrareg;}
    Pol DajPol() const{
        if(kodosobe<500) return Musko;
        else return Zensko;
    }
    void PromijeniImeIPrezime(std::string novo_ime){imeiprez=novo_ime;}
};

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime,long long int jmbg){
    int niz[13];
    if(BrojacCifara(jmbg)==12)
    niz[0]=0;
    int indeks(12);
    long long int temp(jmbg);
    while(temp!=0){
        niz[indeks]=temp%10;
        indeks--;
        temp/=10;
    }
    int danrodj1=10*niz[0]+niz[1];
    int mjrodj1=10*niz[2]+niz[3];
    int godrodj1=100*niz[4]+10*niz[5]+niz[6];
    if(godrodj1<=17) godrodj1+=2000;
    else godrodj1+=1000;
    int sifrareg1=10*niz[7]+niz[8];
    int kod;
    kod=100*niz[9]+10*niz[10]+niz[11];
    int x;
    x=11-(7*(niz[0]+niz[6])+6*(niz[1]+niz[7])+5*(niz[2]+niz[8])+4*(niz[3]+niz[9])+3*(niz[4]+niz[10])+2*(niz[5]+niz[11]))%11;
    if(x==11) x=0;
    if(!IspravnostDatuma(danrodj1,mjrodj1,godrodj1) || x!=niz[12]) throw std::domain_error("JMBG nije validan");
    for(auto r=posljedni;r!=nullptr;r=r->prije){
        if((r->JMBG)==jmbg) throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
    }
    prije=posljedni;
    posljedni=this;
    imeiprez=ime_i_prezime;
    JMBG=jmbg;
    danrodj=danrodj1;
    mjrodj=mjrodj1;
    godrodj=godrodj1;
    sifrareg=sifrareg1;
    kodosobe=kod;
}

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime,int dan_rodjenja,int mjesec_rodjenja,int godina_rodjenja,int sifra_regije,Pol pol){
    if(!IspravnostDatuma(dan_rodjenja,mjesec_rodjenja,godina_rodjenja) || sifra_regije<0 || sifra_regije>99) throw std::logic_error("Neispravni podaci");
    int kod;
    if(pol==Musko) kod=0;
    else kod=500;
    for(auto r=posljedni;r!=nullptr;r=r->prije){
        if(pol==Musko){
            if((r->kodosobe)<500 && (r->danrodj)==dan_rodjenja && (r->mjrodj)==mjesec_rodjenja && (r->godrodj)==godina_rodjenja && (r->sifrareg)==sifra_regije){
                kod=++(r->kodosobe);
                break;
            }
        }
        else if(pol==Zensko){
            if((r->kodosobe)>499 && (r->danrodj)==dan_rodjenja && (r->mjrodj)==mjesec_rodjenja && (r->godrodj)==godina_rodjenja && (r->sifrareg)==sifra_regije){
                kod=++(r->kodosobe);
                break;
            }
        }
    }
    prije=posljedni;
    posljedni=this;
    kodosobe=kod;
    imeiprez=ime_i_prezime;
    danrodj=dan_rodjenja;
    mjrodj=mjesec_rodjenja;
    godrodj=godina_rodjenja;
    sifrareg=sifra_regije;
    if(godina_rodjenja>2000)
    godina_rodjenja-=2000;
    else godina_rodjenja-=1000;
    long long int jmbg(0);
    jmbg+=dan_rodjenja;
    jmbg*=100;
    jmbg+=mjesec_rodjenja;
    jmbg*=1000;
    jmbg+=godina_rodjenja;
    jmbg*=100;
    jmbg+=sifra_regije;
    jmbg*=1000;
    jmbg+=kod;
    jmbg*=10;
    int niz[13];
    niz[0]=(dan_rodjenja-dan_rodjenja%10)/10;
    niz[1]=dan_rodjenja%10;
    niz[2]=(mjesec_rodjenja-mjesec_rodjenja%10)/10;
    niz[3]=mjesec_rodjenja%10;
    niz[4]=(godina_rodjenja-godina_rodjenja%100)/100;
    niz[5]=((godina_rodjenja-100*niz[4])-godina_rodjenja%10)/10;
    niz[6]=godina_rodjenja%10;
    niz[7]=(sifra_regije-sifra_regije%10)/10;
    niz[8]=sifra_regije%10;
    niz[9]=(kod-kod%100)/100;
    niz[10]=((kod-100*niz[9])-kod%10)/10;
    niz[11]=kod%10;
    niz[12]=11-(7*(niz[0]+niz[6])+6*(niz[1]+niz[7])+5*(niz[2]+niz[8])+4*(niz[3]+niz[9])+3*(niz[4]+niz[10])+2*(niz[5]+niz[11]))%11;
    if(niz[12]==11) niz[12]=0;
    if(niz[12]!=10) jmbg+=niz[12];
    else{
        jmbg/=10;
        jmbg-=kod;
        kod++;
        jmbg+=kod;
        niz[9]=(kod-kod%100)/100;
        niz[10]=((kod-100*niz[9])-kod%10)/10;
        niz[11]=kod%10;
        niz[12]=11-(7*(niz[0]+niz[6])+6*(niz[1]+niz[7])+5*(niz[2]+niz[8])+4*(niz[3]+niz[9])+3*(niz[4]+niz[10])+2*(niz[5]+niz[11]))%11;
        jmbg+=niz[12];
    }
    JMBG=jmbg;
}

GradjaninBiH* GradjaninBiH::posljedni=nullptr;

int main ()
{
    cout<<"Koliko gradjana zelite unijeti po JMBG? ";
    int n(0);
    cin>>n;
    cin.ignore(1000,'\n');
    cout<<std::endl;
    GradjaninBiH *niz[100];
    for(int i=0;i<n;i++){
        cout<<"Unesite ime i prezime (u istom redu): ";
        std::string s;
        std::getline(cin,s);
        cout<<std::endl;
        cout<<"Unesite JMBG: ";
        long long int x;
        cin>>x;
        cin.ignore(1000,'\n');
        cout<<std::endl;
        try{
            niz[i]=new GradjaninBiH(s,x);
            cout<<"Unijeli ste gradjanina "<<(*niz[i]).DajImeIPrezime()<<" rodjenog "<<(*niz[i]).DajDanRodjenja()<<"."<<(*niz[i]).DajMjesecRodjenja()<<"."<<(*niz[i]).DajGodinuRodjenja()<<" u regiji "<<(*niz[i]).DajSifruRegije()<<", ";
            if((*niz[i]).DajPol()==GradjaninBiH::Musko)
            cout<<"musko."<<std::endl;
            else cout<<"zensko."<<std::endl;
        }
        catch(std::domain_error iz){
            cout<<iz.what()<<std::endl;
            i--;
        }
        catch(std::logic_error izu){
            cout<<izu.what()<<std::endl;
            i--;
        }
    }
    cout<<"Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? ";
    int k;
    cin>>k;
    cin.ignore(1000,'\n');
    cout<<std::endl;
    for(int i=n;i<n+k;i++){
        cout<<"Unesite ime i prezime (u istom redu): ";
        std::string s;
        std::getline(cin,s);
        cout<<std::endl;
        cout<<"Unesite datum rodjenja (format dd/mm/gggg): ";
        char znak1,znak2;
        int dan,mjesec,godina;
        cin>>dan>>znak1>>mjesec>>znak2>>godina;
        cout<<std::endl;
        cout<<"Unesite sifru regije: ";
        int sifra;
        cin>>sifra;
        cin.ignore(1000,'\n');
        cout<<std::endl;
        cout<<"Unesite M za musko, Z za zensko: ";
        char p;
        cin>>p;
        cout<<std::endl;
        cin.ignore(1000,'\n');
        try{
        GradjaninBiH::Pol p1;
        if(p=='M')
        p1=GradjaninBiH::Musko;
        else
        p1=GradjaninBiH::Zensko;
        niz[i]=new GradjaninBiH(s,dan,mjesec,godina,sifra,p1);
        cout<<"Unijeli ste gradjanina "<<(*niz[i]).DajImeIPrezime()<<" JMBG: "<<(*niz[i]).DajJMBG()<<"."<<std::endl;
        }
        catch(std::logic_error iz){
            cout<<iz.what()<<std::endl;
            i--;
        }
    }
	return 0;
}