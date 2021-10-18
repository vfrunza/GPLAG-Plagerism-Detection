/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
class GradjaninBiH{
  public:
    enum Pol{Musko,Zensko};
  private:    
    GradjaninBiH *prethodni;
    long long int JMBG;
    std::string imeprezime;
    int dan,mjesec,godina,sifra,regija;
    Pol pol;
    static GradjaninBiH* prvi;  
    bool IstiJMBG(long long int temp);
    int IstiKod(Pol spol,int d,int m,int g,int s);
  public:
    GradjaninBiH(const GradjaninBiH&g)=delete;
    GradjaninBiH&operator=(const GradjaninBiH&g)=delete;
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
    int godina_rodjenja, int sifra_regije, Pol pol);
    std::string DajImeIPrezime() const{return imeprezime;}
    long long int DajJMBG() const{return JMBG;}
    int DajDanRodjenja() const{return dan;}
    int DajMjesecRodjenja() const{return mjesec;}
    int DajGodinuRodjenja() const{return godina;}
    int DajSifruRegije() const{return regija;}
    Pol DajPol() const{return pol;}
    void PromijeniImeIPrezime(std::string novo_ime);
    ~GradjaninBiH();
};
GradjaninBiH* GradjaninBiH::prvi=nullptr;
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime,long long int jmbg){
    auto temp1(prethodni);
    auto temp2(prvi);
    prethodni=prvi;
    prvi=this;
    if(IstiJMBG(jmbg)){
        prethodni=temp1;
        prvi=temp2;
        throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
    }
    imeprezime=ime_i_prezime;
    JMBG=jmbg;
    sifra=jmbg%10; jmbg/=10;
    int polovi(jmbg%1000);
    if(polovi<500) pol=Musko;
    else pol=Zensko;
    jmbg/=1000;
    regija=jmbg%100;
    jmbg/=100;
    godina=jmbg%1000;
    if(godina<18)godina+=2000;
    else godina+=1000;
    jmbg/=1000;
    mjesec=jmbg%100; jmbg/=100;
    dan=jmbg%100;
    int brdana[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if((godina%4==0 && godina%100==0)||godina%400==0)brdana[1]++;
    if(regija<0 || regija>99 || godina<1 || mjesec<1 || dan<1 || mjesec>12 || dan>brdana[mjesec-1]){
        prethodni=temp1;
        prvi=temp2;
        throw std::logic_error("JMBG nije validan");
    }
}
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,int godina_rodjenja, int sifra_regije, Pol polovi){
        int brdana[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        if((godina_rodjenja%4==0 && godina_rodjenja%100==0)||godina_rodjenja%400==0)brdana[1]++;
        if(sifra_regije<0||sifra_regije>99||godina_rodjenja<1||mjesec_rodjenja<1||dan_rodjenja<1||mjesec_rodjenja>12||dan_rodjenja>brdana[mjesec_rodjenja-1])
            throw std::logic_error("Neispravni podaci");
        imeprezime=ime_i_prezime; dan=dan_rodjenja; mjesec=mjesec_rodjenja;
        godina=godina_rodjenja; regija=sifra_regije; pol=polovi;
        prethodni=prvi;
        prvi=this;
        long long int x(0);
        int c[14];
        c[1]=dan_rodjenja/10;
        c[2]=dan_rodjenja%10;
        c[3]=mjesec_rodjenja/10;
        c[4]=mjesec_rodjenja%10;
        c[5]=(godina_rodjenja%1000)/100;
        c[6]=(godina_rodjenja%100)/10;
        c[7]=godina_rodjenja%10;
        c[8]=sifra_regije/10;
        c[9]=sifra_regije%10;
        int kod;
        if(pol==Musko)kod=0;
        else kod=500;
        kod+=IstiKod(pol,dan,mjesec,godina,regija);
        c[10]=kod/100;
        c[11]=(kod%100)/10;
        c[12]=kod%10;
        bool trinaest(true);
        do{
            trinaest=false;
            c[13]=11-(7*(c[1]+c[7])+6*(c[2]+c[8])+5*(c[3]+c[9])+4*(c[4]+c[10])+3*(c[5]+c[11])+2*(c[6]+c[12]))%11;
            if (c[13]==11)c[13]=0;
            if (c[13]==10){
                do{
                    trinaest=true;
                    kod++;c[10]=kod/100;c[11]=(kod%100)/10;c[12]=kod%10;
                    long long int faktor(1);  
                    x=0;
                    for(int i=13;i>0;i--){
                        x+=c[i]*faktor;
                        faktor*=10;
                    }
                }while(!IstiJMBG(x));
            }
            else{
                x=0;
                long long int faktor(1);
                for(int i=13;i>0;i--){
                    x+=c[i]*faktor;
                    faktor*=10;
                }
            }
        }while(trinaest);
        JMBG=x;
    }
void GradjaninBiH::PromijeniImeIPrezime(std::string novo_ime){
    imeprezime=novo_ime;
}
bool GradjaninBiH::IstiJMBG(long long int temp){
    long long int broj=temp;
    GradjaninBiH *pok(prethodni);
    while (pok!=nullptr){
        //std::cout<<"Isti JMBG";
        if (broj==pok->JMBG) return true;
        pok=pok->prethodni;
    }
    return false;
}
int GradjaninBiH::IstiKod(Pol spol,int d,int m,int g,int s){
    int brojac(0);
    GradjaninBiH *pok(prethodni);
    while (pok!=nullptr){
        if(spol==pok->pol && d==pok->dan && m==pok->mjesec && g==pok->godina && s==pok->regija)brojac++;
        pok=pok->prethodni;
    }
    return brojac;
}
GradjaninBiH::~GradjaninBiH(){
    if(prvi==this) prvi=this->prethodni;
    else{
    auto p1(prvi);
    auto p2(p1->prethodni);
    while(p2!=this && p2!=nullptr){
        p1=p1->prethodni;
        p2=p2->prethodni;
    }
    if(p2==nullptr) p1->prethodni=nullptr;
    else p1->prethodni=p2->prethodni;
    }     
}
int main ()
{
    GradjaninBiH* niz[100]{};
    int n(0);
    std::cout<<"Koliko gradjana zelite unijeti po JMBG? \n";
    int a;
    std::cin>>a;
    for(int i=0;i<a;i++){
        try{
        std::cout<<"Unesite ime i prezime (u istom redu): \n";
        std::string ime;
        std::cin.ignore(1000,'\n');
        std::getline(std::cin,ime);
        std::cout<<"Unesite JMBG: \n";
        long long int x;
        std::cin>>x;
        niz[n]=new GradjaninBiH(ime,x);
        std::cout<<"Unijeli ste gradjanina "<<niz[n]->DajImeIPrezime()<<" rodjenog "<<niz[n]->DajDanRodjenja()<<"."<<niz[n]->DajMjesecRodjenja()<<"."
        <<niz[n]->DajGodinuRodjenja()<<" u regiji "<<niz[n]->DajSifruRegije()<<", ";
        if(niz[n]->DajPol()==GradjaninBiH::Musko)std::cout<<"musko.\n";else std::cout<<"zensko.\n";
        n++;
        }catch(std::logic_error a){
            std::cout<<a.what()<<std::endl;
            i--;
        }
    }
    std::cout<<"Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? \n";
    int b;
    std::cin>>b;
    for(int i=0;i<b;i++){
      try{
        std::cout<<"Unesite ime i prezime (u istom redu): \n";
        std::string ime;
        std::cin.ignore(1000,'\n');
        std::getline(std::cin,ime);
        std::cout<<"Unesite datum rodjenja (format dd/mm/gggg): \n";
        char znak;
        int d,m,g;
        std::cin>>d>>znak>>m>>znak>>g;
        std::cout<<"Unesite sifru regije: \n";
        int sifra; std::cin>>sifra;
        std::cout<<"Unesite M za musko, Z za zensko: \n";
        std::cin>>znak;
        GradjaninBiH::Pol pol;
        if(znak=='M')pol=GradjaninBiH::Pol::Musko;
        else pol=GradjaninBiH::Pol::Zensko;
        niz[n]= new GradjaninBiH(ime,d,m,g,sifra,pol);
        std::cout<<"Unijeli ste gradjanina "<<niz[n]->DajImeIPrezime()<<" JMBG: "<<niz[n]->DajJMBG()<<"."<<std::endl;
        n++;
        }catch(std::logic_error a){std::cout<<a.what()<<std::endl; i--;}
      }
      for(int i=0;i<n;i++)delete niz[i];
	return 0;
}