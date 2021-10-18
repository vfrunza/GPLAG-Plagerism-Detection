#include <iostream>
#include <stdexcept>
#include <cmath>
enum Pol {Musko, Zensko};

bool Validnost_Datuma(int dan,int mjesec,int godina){
     int broj_dana[]{31,28,31,30,31,30,31,31,30,31,30,31};
     if((godina%4==0&&godina%100!=0)||godina%400==0)
     broj_dana[1]++;
     if(godina<1||mjesec<1||mjesec>12||dan<1||dan>broj_dana[mjesec-1])
     return true;
     return false;
}
void RastavinaCifreJMBG(long long int JMBG,int* cifreJMBG){
    int cifra;
    int i=12;
    while(JMBG!=0){
        cifra=JMBG%10;
        cifreJMBG[i]=cifra;
        JMBG=JMBG/10;
      i--;
    }
}

long long int KreirajJMBG(int dan_rodjenja,int mjesec_rodjenja,int godina_rodjenja,int sifra_regije,int kod){
    int c[13]{0};
    int cifra;
    int c13;
    long long int  JMBG;
    for(int i=11;i>=0;i--){
        if(i==11||i==10||i==9){
            cifra=kod%10;
            kod=kod/10;
            c[i]=cifra;
        }
        else if(i==7||i==8){
            cifra=sifra_regije%10;
            sifra_regije=sifra_regije/10;
            c[i]=cifra;
        }
        else if(i==4||i==5||i==6){
            cifra=godina_rodjenja%10;
            godina_rodjenja=godina_rodjenja/10;
            c[i]=cifra;
        }
    
    else if(i==2||i==3){
            cifra=mjesec_rodjenja%10;
            mjesec_rodjenja=mjesec_rodjenja/10;
            c[i]=cifra;
        }
        else if(i==0||i==1){
            cifra=dan_rodjenja%10;
            dan_rodjenja=dan_rodjenja/10;
            c[i]=cifra;
        }}
       c13=11-(7*(c[0]+c[6])+6*(c[1]+c[7])+5*(c[2]+c[8])+4*(c[3]+c[9])+3*(c[4]+c[10])+2*(c[5]+c[11]))%11;
    if(c13==11)c13=0;
      c[12]=c13;
       JMBG=c[0]*pow(10,12)+c[1]*pow(10,11)+c[2]*pow(10,10)+c[3]*pow(10,9)+c[4]*pow(10,8)+c[5]*pow(10,7)+c[6]*pow(10,6)+c[7]*pow(10,5)+c[8]*pow(10,4)+c[9]*pow(10,3)+c[10]*pow(10,2)+c[11]*pow(10,1)+c[12];
       return JMBG;
}

void OcitajJMBG(long long int JMBG,int& dan_rodjenja,int& mjesec_rodjenja,int& godina_rodjenja,int& sifra_regije,int& kod){
    
    int cifreJMBG[13]{0};
    RastavinaCifreJMBG(JMBG,cifreJMBG);
        dan_rodjenja=cifreJMBG[0]*10+cifreJMBG[1];
        mjesec_rodjenja=cifreJMBG[2]*10+cifreJMBG[3];
        if(cifreJMBG[4]==0)godina_rodjenja=2*1000+cifreJMBG[4]*100+cifreJMBG[5]*10+cifreJMBG[6];
        else godina_rodjenja=1*1000+cifreJMBG[4]*100+cifreJMBG[5]*10+cifreJMBG[6];
        sifra_regije=cifreJMBG[7]*10+cifreJMBG[8];
        kod=cifreJMBG[9]*100+cifreJMBG[10]*10+cifreJMBG[11];
}

int Kod(long long int JMBG){
    int dr;int mr;int god;int sr;int p;
    OcitajJMBG(JMBG,dr,mr,god,sr,p);
    return p;
}
bool Provjeri_JMBG(long long int JMBG){
    int dan,mjesec,godina;
    int c[13]{0};
    int c13;
    int p;
    int sifra_regije;
    OcitajJMBG(JMBG,dan,mjesec,godina,sifra_regije,p);
    if(Validnost_Datuma(dan,mjesec,godina))return true;
    RastavinaCifreJMBG(JMBG,c);
    c13=11-(7*(c[0]+c[6])+6*(c[1]+c[7])+5*(c[2]+c[8])+4*(c[3]+c[9])+3*(c[4]+c[10])+2*(c[5]+c[11]))%11;
    if(c13==11)c13=0;
    if(c13!=10&&c[12]==c13){
        return true;
    }
    else return false;
}

class GradjaninBiH {
    std::string ime_i_prezime;
    long long int jmbg;
    GradjaninBiH* prethodni=nullptr;
    static GradjaninBiH* posljednji;
    public:
GradjaninBiH(std::string ime_i_prezime, long long int JMBG){
    std::cout<<posljednji->ime_i_prezime;
     for(GradjaninBiH* p=posljednji;p!=nullptr;p=p->prethodni){
             if(JMBG==(*p).DajJMBG()){
             throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
         }
     }
    if(!Provjeri_JMBG(JMBG))throw std::logic_error("JMBG nije validan");
    jmbg=JMBG;
    this->ime_i_prezime=ime_i_prezime;
     if(posljednji!=nullptr){
    std::cout<<"bla";
    this->prethodni=posljednji;
     }
    posljednji=this;
     
 //       OcitajJMBG(JMBG,dan_rodjenja,mjesec_rodjenja,godina_rodjenja,sifra_regije,pol);
}
GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,int godina_rodjenja, int sifra_regije, Pol pol){
    this->ime_i_prezime=ime_i_prezime;
    int kod(0);
     for(GradjaninBiH* p=posljednji;p!=nullptr;p=p->prethodni){
         if((*p).DajPol()==pol){
             if(kod>Kod((*p).DajJMBG()))
             kod=Kod((*p).DajJMBG());
         }
     }
     if(kod==0&&pol==Musko)kod=0;
     else if(kod==0&&pol==Zensko)kod=500;
     else
     kod++;
     for(GradjaninBiH* p=posljednji;p!=nullptr;p=p->prethodni){
             if(kod==Kod((*p).DajJMBG())){
             kod++;p=posljednji;
         }
     }
     if(Validnost_Datuma(dan_rodjenja,mjesec_rodjenja,godina_rodjenja)||sifra_regije<0||sifra_regije>99)throw std::logic_error("Neispravni podaci");
     auto JMBG=KreirajJMBG(dan_rodjenja,mjesec_rodjenja,godina_rodjenja,sifra_regije,kod);
     if(!Provjeri_JMBG(JMBG))throw std::logic_error("JMBG nije validan");
       for(GradjaninBiH* p=posljednji;p!=nullptr;p=p->prethodni){
             if(JMBG==(*p).DajJMBG()){
             throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
         }
     }
     jmbg=JMBG;
      if(posljednji!=nullptr)
    this->prethodni=posljednji;
    posljednji=this;
 }
std::string DajImeIPrezime() const;
long long int DajJMBG() const{
    return jmbg;
}
int DajDanRodjenja() const{
    int dr;int mr;int god;int sr;int p;
    OcitajJMBG(jmbg,dr,mr,god,sr,p);
    return dr;
}
int DajMjesecRodjenja() const{
    int dr;int mr;int god;int sr;int p;
    OcitajJMBG(jmbg,dr,mr,god,sr,p);
    return mr;
}
int DajGodinuRodjenja() const{
    int dr;int mr;int god;int sr;int p;
    OcitajJMBG(jmbg,dr,mr,god,sr,p);
    return god;
}
int DajSifruRegije() const{
    int dr;int mr;int god;int sr;int p;
    OcitajJMBG(jmbg,dr,mr,god,sr,p);
    return sr;
}
Pol DajPol() const{
    Pol pol;
    int dr;int mr;int god;int sr;int p;
    OcitajJMBG(jmbg,dr,mr,god,sr,p);
    if(p<=499&&p>=0)pol=Musko;
    else pol=Zensko;
    return pol;
}
void PromijeniImeIPrezime(std::string novo_ime);
};
GradjaninBiH* GradjaninBiH::posljednji=nullptr;
int main ()
{
    Pol pol=Musko;
 //   GradjaninBiH neko("Avdo Palic",1,9,2001,17,pol);
 //   std::cout<<neko.DajJMBG()<<std::endl;
 //   pol=Musko;
  GradjaninBiH neko4("Zemska kalic",802998150026);
  GradjaninBiH h("Harun Mesan", 806996191588);
//  std::cout<<neko4.DajJMBG()<<std::endl;
//    GradjaninBiH neko2("ina Palic",1,9,20014,17,pol);
 //   std::cout<<neko2.DajJMBG()<<std::endl;
	return 0;
}