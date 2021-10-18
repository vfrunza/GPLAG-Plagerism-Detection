/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>
using std::string;
using std::pow;
using std::cin;
using std::cout;
using std::endl;

class GradjaninBiH{
private:
    void checkchain(bool &ista_regij_i){
        GradjaninBiH *p =zadnji;
        while (p) {
            bool jednaki = true;
            for (int i = 0; i < 13; i++) {
                if(this->JMBG[i]!=p->JMBG[i]){jednaki=false;break;}
            }
            if(jednaki)throw std::logic_error("JMBG je identican sa prethodnim");
            if(this->DajDanRodjenja()== p->DajDanRodjenja() 
            && this->DajMjesecRodjenja()==p->DajMjesecRodjenja() 
            && this-> DajGodinuRodjenja()==p->DajDanRodjenja()
            && this->DajPol() == p->DajPol())
            ista_regij_i=true;
            p=p->prethodni;
        }
        if(!zadnji)zadnji = this;
        else{
            this->prethodni=zadnji;
            zadnji = this;
        }
    }   
public:
    enum Pol{Musko,Zensko};
    GradjaninBiH(GradjaninBiH&)=delete;
    GradjaninBiH(string i_p, long long int jmbg){
        int i(0);
        for (i = 12; i >=0; i--) {
            JMBG[i] = jmbg%10;
            jmbg/=10;
            if(jmbg==0 && i!=0)throw std::logic_error("JMBG nije ispravan");
        }
        if(!provjeriDatum(DajDanRodjenja(),DajMjesecRodjenja(),DajGodinuRodjenja()))
            throw std::logic_error("Datum nije ispravan");
        bool a;
        checkchain(a);
    }
    GradjaninBiH(string i_p,int d, int m,int g, int s_r,Pol pol){
        Postavi(i_p,d,m,g,s_r,pol);
    }
private:
    void Postavi(string i_p,int d, int m,int g, int s_r,Pol pol){
        this->i_p = i_p;
        if(!provjeriDatum(d,m,g) || s_r>99)
            throw std::logic_error("Neispravni podaci");
        int t(0);
        if(pol==Pol::Musko){
            t= slj_m[s_r];
        }
        else {
            t = slj_z[s_r]+500;
        }
        int poz=0;
        int tmp[13]{d/10,d%10,  m/10,m%10,  (g%1000)/100,(g%100)/10,g%10,  s_r/10,s_r%10,  t/100,(t%100)/10,t%10};
        tmp[12]=0;
        for (int i = 7; i >= 2; i--) {
            tmp[12]+=i*(tmp[poz]+tmp[poz+6]);
            poz++;
        }
        tmp[12]=11-tmp[12]%11;
        if(tmp[12]==11)tmp[12]=0;
        else if(tmp[12]==10)throw std::logic_error("JMBG nije ispravan");
        for (int i = 0; i < 13; i++) {
            JMBG[i]=tmp[i];
        }
        bool jes=false;
        checkchain(jes);
        if(jes){
            if(this->DajPol()==Pol::Musko)slj_m[s_r]++;
            else slj_z[s_r]++;
        }
    }
public:
    long long int DajJMBG()const{
        long long int a(0);
        for (int i = 12; i >=0; i--) a+=JMBG[i]*pow(10,12-i);
        return a;
    }
    string DajImeIPrezime()const{
        return i_p;
    }
    int DajDanRodjenja()const{
        return JMBG[0]*10+JMBG[1];
    }
    int DajMjesecRodjenja()const{
        return JMBG[2]*10+JMBG[3];
    }
    int DajGodinuRodjenja()const{
        return JMBG[4]*100+JMBG[5]*10+JMBG[6] + 2000 - ((JMBG[4]==9))*1000;
    }
    int DajSifruRegije()const{
        return JMBG[7]*10+JMBG[8];
    }
    Pol DajPol()const{
        return Pol(JMBG[9]>=5);
    }
    ~GradjaninBiH(){
        if(zadnji){
            GradjaninBiH *p = zadnji;
            if(p==this){
                zadnji = this->prethodni;
            }
            else 
            while (p) {
                if(p->prethodni==this){
                    p->prethodni = this->prethodni;
                    break;
                }
                p=p->prethodni;
            }
        }
    }
    void PromijeniImeIPrezime(string a){
        i_p = a;
    }
private:
    static GradjaninBiH* zadnji;
    GradjaninBiH* prethodni= nullptr;
    static int slj_m[100];
    static int slj_z[100];
    int JMBG[13]{};
    string i_p;
    bool provjeriDatum(int d, int m, int g){
        int dd[12]{31,28,31,    30,31,30,   31,31,30,  31,30,31};
        if(m<0 || m>12 || d<0 || g < 0 || (((g%4==0 && g%100!=0) || (g%400==0)) && m==2 && d>29)) 
            return false;
        return d<=dd[m-1];
    }
};
GradjaninBiH* GradjaninBiH::zadnji=nullptr;
int GradjaninBiH::slj_m[100]{};
int GradjaninBiH::slj_z[100]{};

int main ()
{
    string a;
    int n;
    cout<<"Koliko gradjana zelite unijeti po JMBG?\n";
    cin>>n;
    long long int jm;
    GradjaninBiH *niz[100];
    int poz=0;
    for (int i = 0; i < n; i++) {
        while (cin.peek()=='\n' || cin.peek()==' ')
        cin.ignore(1);
        cout<<"Unesite ime i prezime (u istom redu): \n";
        std::getline(cin,a);
        cout<<"Unesite JMBG: \n";
        cin>>jm;
        try{
            string c[]{"musko.","zensko."};
            niz[poz]=new GradjaninBiH(a,jm);
            cout<<"Unijeli ste gradjanina ";
            cout<<a<<" rodjenog "<<niz[poz]->DajDanRodjenja()<<"."<<niz[poz]->DajMjesecRodjenja()<<"."<<niz[poz]->DajGodinuRodjenja()<<" u regiji "<<niz[poz]->DajSifruRegije()
            <<", "<<c[int(niz[poz]->DajPol())]<<endl;
            poz++;
        }catch(...){
            cout<<"JMBG nije validan \n";i--;
        }
    }
    cout<<"Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu?\n";
    int tx=n;
    cin>>n;
    for (int i = 0; i < n; i++) {
        cout<<"Unesite ime i prezime (u istom redu): \n";
        string s;
        cin.ignore(1);
        std::getline(cin,s);
        cout<<"Unesite datum rodjenja (format dd/mm/gggg): \n";
        int q[3];
        for(int j=0;j<3;j++){
            cin>>q[j];
            cin.ignore(1);
        }
        int sr;
        cout<<"Unesite sifru regije: \n";
        cin>>sr;
        char pol;
        cout<<"Unesite M za musko, Z za zensko: \n";
        cin>>pol;
        bool pp = pol - 'M';
        try{
            niz[poz]= new GradjaninBiH(s,q[0],q[1],q[2],sr,static_cast<GradjaninBiH::Pol>(pp));
            cout<<"Unijeli ste gradjanina ";
            cout<<s<<" JMBG: "<<niz[poz]->DajJMBG()<<"."<<endl;
            poz++;
        }catch(std::logic_error e){
            cout<<e.what()<<"\n";
            i--;
        }
    }
    for (int i = 0; i < tx+n; i++) {
        delete niz[i];
    }
	return 0;
}