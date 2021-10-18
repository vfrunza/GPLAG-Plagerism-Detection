/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath>


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::logic_error;
using std::getline;


class GradjaninBiH{
    
    string iip;//ImeIPrezime
    long long int jmb;
    int dr,mr,gr,sifr,kod;
    
   
    GradjaninBiH *prije_njega;
    static GradjaninBiH * posljednji_kreirani;
    
    
    
    public:
    enum Pol {Musko, Zensko};
    GradjaninBiH(string ime_i_prezime, long long int jmbg){
        
        
       
        for(GradjaninBiH *p = posljednji_kreirani; p!=nullptr; p = p->prije_njega){
                if(jmbg == p->jmb)throw logic_error("Vec postoji gradjanin sa istim JMBG");
            }
            
            
        
        int dr1 = int(jmbg/(pow(10,11)));
        if(dr1<1 || dr1>31)throw logic_error("JMBG nije validan");
        int mr1 = int(jmbg/pow(10,9))%100;
        if(mr1<1 || mr1>12)throw logic_error("JMBG nije validan");
        int gr1 = int(jmbg/pow(10,6))%1000;
        int tmp = gr1/100;
        int tmp2;
        if(tmp==0)tmp2 = gr1+2000;
        else tmp2 = gr1+1000;
        
        if(tmp2>2017 || tmp2<1917)throw logic_error("JMBG nije validan");
        
        int c[13];
        
        long long int x = jmbg;
        for(int i=12; i>=0; i--){
            c[i] = x%10;
            x=x/10;
        }
        
        int rez = 11 - (7*(c[0]+c[6]) + 6*(c[1]+c[7]) + 5*(c[2] + c[8]) + 4*(c[3] + c[9]) + 3*(c[4]+c[10]) + 2*(c[5]+c[11]))%11;
        
        if(rez == 10)throw logic_error("JMBG nije validan");
        if(rez == 11)rez=0;
        if(c[12]!=rez)throw logic_error("JMBG nije validan");
        
        
        iip = ime_i_prezime;
        jmb = jmbg;
        dr = dr1;
        mr = mr1;
        gr = gr1;
        sifr = int(jmbg/pow(10,4))%100;
        kod = (jmbg/10)%1000;
        
        prije_njega = posljednji_kreirani;
        posljednji_kreirani = this;
        
        
     }
    
    GradjaninBiH(string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol){
        
        if((dan_rodjenja<1 || dan_rodjenja>31)||(mjesec_rodjenja<1 || mjesec_rodjenja>12)||(godina_rodjenja<1917 || godina_rodjenja>2017))throw logic_error("Neispravni podaci");
        if(sifra_regije<0 || sifra_regije>99)throw logic_error("Neispravni podaci");
        
        
        prije_njega = posljednji_kreirani;
        posljednji_kreirani = this;
            
        iip = ime_i_prezime;
        dr = dan_rodjenja;
        mr = mjesec_rodjenja;
        gr = godina_rodjenja;
        sifr = sifra_regije;
        
        int c[13];
        c[0] = dan_rodjenja/10;
        c[1] = dan_rodjenja%10;
        
        c[2] = mjesec_rodjenja/10;
        c[3] = mjesec_rodjenja%10;
        
        c[4] = (godina_rodjenja%1000)/100;
        c[5] = ((godina_rodjenja%1000)%100)/10;
        c[6] = ((godina_rodjenja%1000)%100)%10;
        
        c[7] = sifra_regije/10;
        c[8] = sifra_regije%10;
        
        
        //trayimo sa istim datumima i regiji i polu
        if(prije_njega == nullptr){//za prvi clan
            if(pol == Musko)this->kod=0;
            if(pol == Zensko)this->kod=500;
        }
        else{
            if(pol == Musko){
            for(GradjaninBiH *p = posljednji_kreirani; p!=nullptr; p = p->prije_njega){//ovdje trazim zadnjeg muskarca sa istim datumom i regijom
                    if(p->kod>=500 && p->kod<=999)continue;                 //ne gledaj zene
                    if((p->dr == this->dr)&&(p->mr == this->mr)&&(p->gr == this->gr)&&(p->sifr == this->sifr)){this->kod = (p->kod)+1;break;}
                }
            }
            
            if(pol == Zensko){
                for(GradjaninBiH *p = posljednji_kreirani; p!=nullptr; p = p->prije_njega){
                if(p->kod>=0 && p->kod<=499)continue;
                if((p->dr == this->dr)&&(p->mr == this->mr)&&(p->gr == this->gr)&&(p->sifr == this->sifr)){this->kod = (p->kod)+1;break;}
            }
            }
        }
        
        
        c[9] = kod/100;
        c[10] = (kod%100)/10;
        c[11] = (kod%100)%10;
        
        int rez = 11 - (7*(c[0]+c[6]) + 6*(c[1]+c[7]) + 5*(c[2] + c[8]) + 4*(c[3] + c[9]) + 3*(c[4]+c[10]) + 2*(c[5]+c[11]))%11;
        if(rez == 11){
            c[12] = 0;
        }
        else if(rez == 10){
            (this->kod)++;
            c[9] = kod/100;
            c[10] = (kod%100)/10;
             c[11] = (kod%100)%10;
            rez = 11 - (7*(c[0]+c[6]) + 6*(c[1]+c[7]) + 5*(c[2] + c[8]) + 4*(c[3] + c[9]) + 3*(c[4]+c[10]) + 2*(c[5]+c[11]))%11;
        }
        c[12] = rez;
        long long int jmbg = 0;
        int b=12;
        for(int i=0; i<13; i++){
            jmbg = jmbg + pow(10,b);
            b--;
        }
        
        jmb = jmbg;
        
        
    }
    
    
    string DajImeIPrezime()const{
        return iip;
    }
    
    long long int DajJMBG()const{
        return jmb;
    }
    
    int DajDanRodjenja()const{
        return dr;
    }
    
    int DajMjesecRodjenja()const{
        return mr;
    }
    
    int DajGodinuRodjenja()const{
        int gdr;
        if(gr/100 != 0)gdr = gr+1000;
        else gdr = gr+2000;
        
        return gdr;
        
    }
    
    int DajSifruRegije()const{
        return sifr;
    }
    
    Pol DajPol()const{
        if(kod>=0 && kod<=499)return Musko;
        return Zensko;
    }
    
    void PromijeniImeIPrezime(string novo_ime){
        iip = novo_ime;
    }
            
    
};
    
GradjaninBiH* GradjaninBiH::posljednji_kreirani=nullptr;



int main ()
{
    cout<<"Koliko gradjana zelite unijeti po JMBG? ";
    int n; cin>>n;
    cin.ignore(1000,'\n');
    GradjaninBiH *p[100];
    
    for(int i=0; i<n; i++){
        cout<<"Unesite ime i prezime (u istom redu): "<<endl;
        
        string ime;
        getline(cin,ime);
        cout<<"Unesite JMBG: "<<endl;
        long long int jmb; cin>>jmb;
        cin.ignore(1000,'\n');
        try{
            GradjaninBiH g(ime, jmb);
            p[i] = &g;
        cout<<"Unijeli ste gradjanina "<<g.DajImeIPrezime()<<"  rodjenog "<<g.DajDanRodjenja()<<"."<<g.DajMjesecRodjenja()<<"."<<g.DajGodinuRodjenja()<<" u regiji "<<g.DajSifruRegije();
        cout<<", ";
        if(g.DajPol()==0)cout<<"musko."<<endl;
        else cout<<"zensko."<<endl;
        
        }
        catch(logic_error e){
            cout<<e.what()<<endl;
            i--;
        }
    }
    
   
    
    cout<<"Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? ";
    int m; cin>>m;
    cin.ignore(1000,'\n');
    
    for(int i=n; i<m; i++){
        cout<<"Unesite ime i prezime (u istom redu): "<<endl;
         string ime;
        getline(cin,ime);
        cout<<"Unesite datum rodjenja (format dd/mm/gggg): "<<endl;
        int d,m,g; cin>>d>>m>>g;
        cin.ignore(1000,'\n');
        cout<<"Unesite sifru regije: "<<endl;
        int s; cin>>s;
        cin.ignore(1000,'\n');
        cout<<"Unesite M za musko, Z za zensko: ";
       
        char q; cin>>q;
         cin.ignore(1000,'\n');
         GradjaninBiH::Pol pol;
         if(q=='M')pol = GradjaninBiH::Musko;
         if(q=='Z')pol = GradjaninBiH::Zensko;
         try{
         GradjaninBiH gr(ime,d,m,g,s,pol);
         p[i]=&gr;
         cout<<"Unijeli ste gradjanina "<<gr.DajImeIPrezime()<<" JMBG: "<<gr.DajJMBG()<<".";
         }
         catch(logic_error e){
             cout<<e.what()<<endl;
             i--;
         }
    }
	return 0;
}