/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>

bool KorektanDatum(int dan, int mjesec, int godina){
    int br_dana[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if((godina%4==0 && godina%100!=0) || godina%400==0 ) br_dana[1]++;
    if(dan<1 || mjesec<1 || mjesec>12 || dan>br_dana[mjesec-1] || godina<1 ) return false;
    return true; 
}

class GradjaninBiH{
    std::string imeiprezime;
    long long int JMBG;
    GradjaninBiH* veza;
    static GradjaninBiH* pocetak;
    public:
    enum Pol {Musko, Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg){
        auto c=jmbg;
        int niz[13];
        for(int i=12;i>=0;i--){
            niz[i]=c%10;
            c/=10;
        }
        int dan=niz[0]*10+niz[1];
        int mjesec=niz[2]*10+niz[3];
        int godina=niz[4]*100+niz[5]*10+niz[6];
        if(niz[4]!=0) godina+=1000;
        else godina+=2000;
        int c13=niz[12];//11-(7*(niz[0]+niz[6])+6*(niz[1]+niz[7])+5*(niz[2]+niz[8])+4*(niz[3]+niz[9])+3*(niz[4]+niz[10])+2*(niz[5]+niz[11])) %11;;
        if(!KorektanDatum(dan,mjesec,godina) || c13==10 || c13 !=niz[12]) throw std::logic_error("JMBG nije validan");
        if(pocetak!=nullptr){
            for(auto it=pocetak;it!=nullptr;it=it->veza){
                if(jmbg==it->JMBG) throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
            }
        }
        veza=pocetak; pocetak=this;
        imeiprezime=ime_i_prezime; JMBG=jmbg; 
    }
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,int godina_rodjenja, int sifra_regije, Pol pol){
        if(!KorektanDatum(dan_rodjenja,mjesec_rodjenja,godina_rodjenja) || sifra_regije>99 || sifra_regije<0) throw std::logic_error("Neispravni podaci");
        int niz[13];
        niz[1]=dan_rodjenja%10; dan_rodjenja/=10; niz[0]=dan_rodjenja%10;
        niz[3]=mjesec_rodjenja%10; mjesec_rodjenja/=10; niz[2]=mjesec_rodjenja%10;
        niz[6]=godina_rodjenja%10; godina_rodjenja/=10; niz[5]=godina_rodjenja%10; godina_rodjenja/=10; niz[4]=godina_rodjenja%10;
        niz[8]=sifra_regije%10; sifra_regije/=10; niz[7]=sifra_regije%10;
        long long int jmbg=0;
        for(int i =0;i<9;i++){
            jmbg=jmbg*10+niz[i]; 
        }
        int min=1000;
        for(auto it=pocetak;it!=nullptr;it=it->veza){
            int dir=(it->JMBG)/10000;
            if(dir==jmbg){
                int s=(it->JMBG/1000)%10;
                if((pol==0 && s<5) || (pol==1 && s>=5)){
                    if((it->JMBG%1000)/10<min) min=(it->JMBG%1000)/10;
                }
            } 
       }
       if(min==1000){
           if(pol==0) min=0;
           else min=500;
       }while(1){
           niz[11]=min%10; min/=10; niz[10]=min%10; min/=10; niz[9]=min%10;
           niz[12]=11-(7*(niz[0]+niz[6])+6*(niz[1]+niz[7])+5*(niz[2]+niz[8])+4*(niz[3]+niz[9])+3*(niz[4]+niz[10])+2*(niz[5]+niz[11])) %11;
           if(niz[12]==11) niz[12]=0;
           if(niz[12]!=10) break;
           min++;
       }
       for(int i=9;i<13;i++){
           jmbg=jmbg*10+niz[i];
       }
       veza=pocetak; pocetak=this;
       imeiprezime=ime_i_prezime; JMBG=jmbg;
    }
    GradjaninBiH(const GradjaninBiH &g) = delete;
    GradjaninBiH operator=(const GradjaninBiH &g) =delete;
   ~GradjaninBiH(){
        if(this==pocetak){
            auto sljedeci=this->veza;
            pocetak=sljedeci;
            veza=nullptr;
        }else if(veza==nullptr){
            for(auto it=pocetak;it!=nullptr;it++){
               if(it->veza==this){
                   it->veza=nullptr; break;
               }
            }
        }
        else{
            auto a=pocetak->veza;
            for(auto it=pocetak;it!=nullptr;it++){
                if(a==this){
                    it->veza=a->veza;
                    break;
                }
                a=a->veza;
            }
        }
    }
    std::string DajImeIPrezime() const { return imeiprezime; }
    long long int DajJMBG() const { return JMBG; }
    int DajDanRodjenja() const;
    int DajMjesecRodjenja() const;
    int DajGodinuRodjenja() const;
    int DajSifruRegije() const;
    Pol DajPol() const;
    void PromijeniImeIPrezime(std::string novo_ime){ imeiprezime=novo_ime; }
};
    GradjaninBiH* GradjaninBiH::pocetak=nullptr;
    int GradjaninBiH::DajDanRodjenja() const{
        return JMBG/(1e11);  
    }
    int GradjaninBiH::DajMjesecRodjenja() const{
        int x=JMBG/(1e9);
        int y=x%10; x/=10;
        y+=10*(x%10);
        return y;
    }
    int GradjaninBiH::DajGodinuRodjenja() const{
        int x=JMBG/(1e6);
        int y=x%10; x/=10;
        y+=10*(x%10); x/=10;
        y+=100*(x%10);
        y+=2000;
        if(y>2017) y-=1000; 
        return y;
    }
    int GradjaninBiH::DajSifruRegije() const{
        return (JMBG/10000)%100;
    }

    GradjaninBiH::Pol GradjaninBiH::DajPol() const{
        int x=(JMBG/1000)%10;
        if(x>=5) return Zensko;
        return Musko;
    }  

int main ()
{
        GradjaninBiH* niz[100];
        std::cout << "Koliko gradjana zelite unijeti po JMBG? " << std::endl;
        int n;
        std::cin >> n;
            for(int i=0;i<n;i++){
                std::cin.ignore(1000,'\n');
                std::cout << "Unesite ime i prezime (u istom redu): " << std::endl ;
                std::string ime; std::getline(std::cin,ime);
                std::cout << "Unesite JMBG: " << std::endl; long long int jmbg; std::cin >> jmbg;
                try{
                    niz[i]=new GradjaninBiH(ime,jmbg);
                    std::cout << "Unijeli ste gradjanina " << niz[i]->DajImeIPrezime() << " rodjenog " << niz[i]->DajDanRodjenja() << "." << niz[i]->DajMjesecRodjenja() << "." << niz[i]->DajGodinuRodjenja() << " u regiji " << niz[i]->DajSifruRegije() << ", ";
                    if(niz[i]->DajPol()==GradjaninBiH::Musko) std::cout << "musko." << std::endl;
                    else
                    std::cout << "zensko." << std::endl;
                }catch(std::logic_error e){
                    std::cout << e.what() <<std::endl;
                    i--;
                }
            }
        int k;
        std::cout << "Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? " << std::endl;
        std::cin >> k;
            for(int i=n;i<k+n;i++){
                std::string ime, datum; int sifra; char pol;
                std::cin.ignore(1000,'\n');
                std::cout << "Unesite ime i prezime (u istom redu): " << std::endl;
                std::getline(std::cin,ime);
                std::cout << "Unesite datum rodjenja (format dd/mm/gggg): " << std::endl;
                std::getline(std::cin,datum);
                int dan=(datum[0]-'0')*10 + datum[1]-'0';
                int mjesec=(datum[3]-'0')*10 + datum[4]-'0';
                int godina=(datum[6]-'0')*1000 + (datum[7]-'0')*100 + (datum[8]-'0')*10 +datum[9]-'0';
                std::cout << "Unesite sifru regije: " << std::endl;
                std::cin >> sifra; std::cin.ignore();
                std::cout << "Unesite M za musko, Z za zensko: " << std::endl;
                pol=std::cin.get();
                GradjaninBiH::Pol p=GradjaninBiH::Musko;
                if(pol=='M') p=GradjaninBiH::Musko;
                else if(pol=='Z') p=GradjaninBiH::Zensko;
                try{
                    niz[i] = new GradjaninBiH(ime,dan,mjesec,godina,sifra,p);
                    std::cout << "Unijeli ste gradjanina " << niz[i]->DajImeIPrezime() <<" JMBG: " << niz[i]->DajJMBG() << "." << std::endl;
                }catch(std::logic_error e){
                    std::cout << e.what() << std::endl;
                    i--;
                }
            }
	return 0;
}