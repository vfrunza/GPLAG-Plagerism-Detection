/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <string>
class GradjaninBiH{
    std::string ime;
    int jmbg[13];
    GradjaninBiH *veza;
    static GradjaninBiH *posljednji;
    static bool ProvjeriDatum(int dan, int mjesec, int godina);
    static bool ProvjeriJmbg(int niz1[], int niz2[]){
        for(int i=0; i<13; i++){                        //f-a koja provjerava da li su podudarni nizovi od 13 elem(tj jmbg)
            if(niz1[i]!=niz2[i]) return false;          //poziva se npr iz konstruktora sa 2 parametra
        }
        return true;
    }
    public:
    GradjaninBiH(const GradjaninBiH &x)=delete; //zabrana kopiranja
    GradjaninBiH &operator =(const GradjaninBiH &x)=delete; //zabrana dodjele
    ~GradjaninBiH(){
        GradjaninBiH *p=posljednji;
        GradjaninBiH *v=this;
        if(p==this && v->veza==nullptr) posljednji=nullptr; //lista od samo 1 clana
        else if(p==this && v->veza!=nullptr) posljednji=posljednji->veza; //lista u kojoj se otklanja posljednji, a ima vise od jednog clana
        else if(v->veza==nullptr) {
            while(p->veza!=this){
                if(p->veza==this) {
                    p->veza=nullptr;
                    break;
                }
            }
        }
        else if(v->veza!=nullptr){
            GradjaninBiH *pom(this);
            while(p->veza!=this){
                if(p->veza==this) {
                    v=v->veza;
                    p->veza=v;
                    break;
                }
            }
            pom->veza=nullptr;
        }
    }
    enum Pol {Musko, Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
    int godina_rodjenja, int sifra_regije, Pol pol);
    std::string DajImeIPrezime() const{return ime;}
    long long int DajJMBG() const{
        long long int x(0);
        for(int i=12; i>=0; i--){
            x=x*10+jmbg[i];
        }
        return x;
    }
    int DajDanRodjenja() const{int dan(10*jmbg[12]+jmbg[11]); return dan;}
    int DajMjesecRodjenja() const{int mjesec(10*jmbg[10]+jmbg[9]); return mjesec;}
    int DajGodinuRodjenja() const{
        int godina(100*jmbg[8]+10*jmbg[7]+jmbg[6]);
        if(godina>=917 && godina<=999) godina+=1000;
        if(godina>=0 && godina<=17) godina+=2000;
        return godina;
    }
    int DajSifruRegije() const{
        int sifra(10*jmbg[5]+jmbg[4]);
        return sifra;
    }
    Pol DajPol() const{
        int kontrolni_kod(100*jmbg[3]+10*jmbg[2]+jmbg[1]);
        if(kontrolni_kod<500) return Musko;
        return Zensko;
    }
    void PromijeniImeIPrezime(std::string ime_i_prezime){
        ime=ime_i_prezime;
    }
};
GradjaninBiH *GradjaninBiH::posljednji=nullptr;

bool GradjaninBiH::ProvjeriDatum(int dan, int mjesec, int godina){
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0) broj_dana[1]++;
    if(godina<1 || mjesec<1 || mjesec>12 || dan<1 || dan>broj_dana[mjesec-1]){
        return false;
    }
    return true;
}
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg){
    int niz[13];
    long long int x(jmbg);
    int br(0);
    while(x>0){
        niz[br]=x%10;
        x=x/10;
        br++;
    }
    if(!(br==12 || br==13)) throw std::logic_error("JMBG nije validan");
    if(br==12) niz[12]=0;
    int dan(10*niz[12]+niz[11]);
    int mjesec(10*niz[10]+niz[9]);
    int godina(100*niz[8]+10*niz[7]+niz[6]);
    if(!( (godina>=917 && godina<=999) || (godina>=0 && godina<=17) )) throw std::logic_error("JMBG nije validan");
    if(godina>=917 && godina<=999) godina+=1000;
    if(godina>=0 && godina<=17) godina+=2000;
    if(!ProvjeriDatum(dan,mjesec,godina)) throw std::logic_error("JMBG nije validan");
    int kontrolni_kod(100*niz[3]+10*niz[2]+niz[1]);
    Pol pol;
    int koef(11-(7*(niz[12]+niz[6])+ 6*(niz[11]+niz[5])+ 5*(niz[10]+niz[4])+ 4*(niz[9]+niz[3])+ 3*(niz[8]+niz[2])+ 2*(niz[7]+niz[1]))%11);//11−(7*(niz[12]+niz[6])+6*(niz[11]+niz[5])+5*(niz[10]+niz[4])+4*(niz[9]+niz[3])+3*(niz[8]+niz[2])+2*(niz[7]+niz[1]))%11);
    if(koef==11) koef=0;
    if(koef==10 || koef!=niz[0]) throw std::logic_error("JMBG nije validan");
    //TREBA IZVRŠIT PROVEJRU JMBGA SA OSTALIM!!!
    if(posljednji==nullptr){        //uslov koji vrijedi ako do sada nema nijednog elementa u listi
    if(kontrolni_kod<500) pol=Musko;
    else pol=Zensko;         //ukoliko su prosle sve provjere
    ime=ime_i_prezime;      //vrsi se dodjela podataka ovom objektu
    for(int i=0; i<13; i++){
        this->jmbg[i]=niz[i];
    }
    posljednji=this;            //uvezivanje ovog objekta u listu tj formiranje liste
    this->veza=nullptr;         //buduci da je ovo prvi objekat u listi
    }
    else if(posljednji!=nullptr){
        bool nalazise(false);
        for(GradjaninBiH *p=posljednji; p!=nullptr; p=p->veza){
            nalazise=ProvjeriJmbg(p->jmbg,niz);
            if(nalazise) throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
        }
        if(!nalazise){      //uslov koji govori da u listi nema osobe sa istim jmbg
            if(kontrolni_kod<500) pol=Musko;
            else pol=Zensko;
            ime=ime_i_prezime;                      //dodjela podataka
            for(int i=0; i<13; i++){
                this->jmbg[i]=niz[i];
            }
            this->veza=posljednji;      //uvezivanje ovog objekta u listu, tj sada pokazuje na objekat prije sebe
            posljednji=this;            //posljednji pokazuje na ovaj objekat, tj novi posljedni objekat u listi
        }
    }
}
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,int godina_rodjenja, int sifra_regije, Pol pol){
    if(!ProvjeriDatum(dan_rodjenja,mjesec_rodjenja,godina_rodjenja)) throw std::logic_error("Neispravni podaci");
    if(sifra_regije<0 || sifra_regije>=99) throw std::logic_error("Neispravni podaci");
    ime=ime_i_prezime;
    jmbg[11]=dan_rodjenja%10; jmbg[12]=dan_rodjenja/10; //postavljanje dana u jmbg
    jmbg[10]=mjesec_rodjenja/10; jmbg[9]=mjesec_rodjenja%10; //postavljanje mjeseca u jmbg
    int x(godina_rodjenja);
    int br1(6);
    while(br1<9){
        jmbg[br1]=x%10;       //postavljanje godine u jmbg
        x/=10;              
        br1++;
    }
    jmbg[4]=sifra_regije%10; jmbg[5]=sifra_regije/10; //postavljanje sifre regije
    if(posljednji==nullptr){        //dodjeljivanje koda za pol
        if(pol==Musko){
            jmbg[1]=0; jmbg[2]=0; jmbg[3]=0;
        }
        if(pol==Zensko){
            jmbg[1]=0; jmbg[2]=0; jmbg[3]=5;
        }
    }
    else if(posljednji!=nullptr){    //dodjeljivanje koda za pol
        int br(0);
        for(GradjaninBiH *pok=posljednji; pok!=nullptr; pok=pok->veza){
            bool datum(false), sifra(false);
            if(dan_rodjenja==pok->DajDanRodjenja() && mjesec_rodjenja==pok->DajMjesecRodjenja() && godina_rodjenja==pok->DajGodinuRodjenja())
                datum=true;
            if(pok->DajSifruRegije()==sifra_regije)
                sifra=true;
            if(sifra==true || datum==true) br++;
        }
        if(pol==Musko){
            if(br>=500) throw std::logic_error("Neispravni podaci");
            int br2(1);
            while(br2<4){
                jmbg[br2]=br%10;
                br/=10;
                br2++;
            }
        }
        if(pol==Zensko){
            br+=500;
            if(br>999) throw std::logic_error("Neispravni podaci");
            int br2(1);
            while(br2<4){
                jmbg[br2]=br%10;
                br/=10;
                br2++;
            }
        }
    }
    if(posljednji==nullptr){
        int koef(11-(7*(jmbg[12]+jmbg[6])+ 6*(jmbg[11]+jmbg[5])+ 5*(jmbg[10]+jmbg[4])+ 4*(jmbg[9]+jmbg[3])+ 3*(jmbg[8]+jmbg[2])+ 2*(jmbg[7]+jmbg[1]))%11);
        if(koef==11) koef=0;
        if(koef==10) throw std::logic_error("Neispravni podaci");
        jmbg[0]=koef;
        posljednji=this;                //dodjeljivanje i uvezivanje ukoliko se radi o prvome elemenut liste
        this->veza=nullptr;
    }
    else if(posljednji!=nullptr){
        int koef(11-(7*(jmbg[12]+jmbg[6])+ 6*(jmbg[11]+jmbg[5])+ 5*(jmbg[10]+jmbg[4])+ 4*(jmbg[9]+jmbg[3])+ 3*(jmbg[8]+jmbg[2])+ 2*(jmbg[7]+jmbg[1]))%11);
        if(koef==11) koef=0;
        if(koef==10) throw std::logic_error("Neispravni podaci");
        jmbg[0]=koef;
        this->veza=posljednji;
        posljednji=this;            //uvezivanje u listu u slucaju da nije ovo prvi element liste
    }
}
int main ()
{   enum Pol {Musko, Zensko};
    int n;
    std::cout<<"Koliko gradjana zelite unijeti po JMBG? "<<std::endl;
    std::cin>>n;
    while(n>0){
        std::string s;
        long long int x;
        std::cout<<"Unesite ime i prezime (u istom redu): "<<std::endl;
        std::cin.ignore(10000,'\n');
        std::getline(std::cin, s);
        std::cout<<"Unesite JMBG: "<<std::endl;
        std::cin>>x;
        try{
            GradjaninBiH gradj(s,x);
            auto pol=gradj.DajPol();
            std::cout<<"Unijeli ste gradjanina "<<gradj.DajImeIPrezime()<<" rodjenog "<<gradj.DajDanRodjenja()<<"."<<gradj.DajMjesecRodjenja()<<"."<<gradj.DajGodinuRodjenja()<<" u regiji "<<gradj.DajSifruRegije()<<", ";
            if(pol==GradjaninBiH::Musko) std::cout<<"musko."<<std::endl;
            if(pol!=GradjaninBiH::Musko) std::cout<<"zensko."<<std::endl;
        }
        catch(std::logic_error e){
            std::cout<<e.what()<<std::endl;
            n++;//3005017180005 2905017170007 1234567891234 1612994175008
        }
        n--;
    }
    std::cout<<"Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? "<<std::endl;
    std::cin>>n;
    while(n>0){
        std::string s;
        std::cout<<"Unesite ime i prezime (u istom redu): "<<std::endl;
        std::cin.ignore(10000,'\n');
        std::getline(std::cin,s);
        std::cout<<"Unesite datum rodjenja (format dd/mm/gggg): "<<std::endl;
        int dan,mj,god;
        char znak;
        std::cin>>dan>>znak>>mj>>znak>>god;
        int sifra;
        std::cout<<"Unesite sifru regije: "<<std::endl;
        std::cin>>sifra;
        std::cout<<"Unesite M za musko, Z za zensko: "<<std::endl;
        std::cin>>znak;
        Pol pol;
        if(znak=='Z') pol=Zensko;
        else pol=Musko;
        try{
            if(znak=='M'){
            GradjaninBiH gradj(s,dan,mj,god,sifra,GradjaninBiH::Pol::Musko);
            std::cout<<"Unijeli ste gradjanina "<<gradj.DajImeIPrezime()<<" JMBG: "<<gradj.DajJMBG()<<"."<<std::endl;
            }
            else{
                GradjaninBiH gradj(s,dan,mj,god,sifra,GradjaninBiH::Pol::Zensko);
                std::cout<<"Unijeli ste gradjanina "<<gradj.DajImeIPrezime()<<" JMBG: "<<gradj.DajJMBG()<<"."<<std::endl;
            }
        }
        catch(std::logic_error e){
            std::cout<<e.what()<<std::endl;
            n++;
        }
    n--;
    }
	return 0;
}