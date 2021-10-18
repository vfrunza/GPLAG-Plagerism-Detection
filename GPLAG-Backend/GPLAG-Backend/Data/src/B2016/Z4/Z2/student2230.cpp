#include <iostream>
#include <stdexcept>
#include <cmath>



class GradjaninBiH{
    static int brojitelj;
    static int brojcanipol1;
    static int brojcanipol2;
    static int brojac;
    static GradjaninBiH *trenutni;
    GradjaninBiH *p;
    GradjaninBiH *zadnji;
    //1. : trenutni=this; zadnji=this; p=this
    //2. : zadnji=trenutni; p=trenutni;  trenutni=this; while (p->zadnji!=null) {   p=zadnji;} 
    std::string imeiprezime;
    long long int jmbgg;
    int niz[13];
    //long long int pomocnijmbg=jmbgg;
    void funkcija(long long int jmbgg,int *niz){
        int k=12;
        while(jmbgg!=0){
            int cifra=jmbgg%10;
            niz[k]=cifra;
            jmbgg/=10;
            k--;
        }
    }
    
public:
    enum Pol{Musko,Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg):imeiprezime(ime_i_prezime), jmbgg(jmbg){ funkcija(GradjaninBiH::jmbgg,GradjaninBiH::niz);imeiprezime=ime_i_prezime; jmbgg=jmbg;
        if(niz[12]==10) throw std::logic_error("JMBG nije validan");
        if(niz[0]*10+niz[1]<1 || niz[0]*10+niz[1]>31) throw std::logic_error("JMBG nije validan");
        if(niz[2]*10+niz[3]<1 || niz[2]*10+niz[3]>12) throw std::logic_error("JMBG nije validan");
        //std::cout<<"SDAADSSDAD"<<std::endl;
        if(niz[4]==0){
            if(2000+niz[4]*100+niz[5]*10+niz[6]>2017) throw std::logic_error("JMBG nije validan");
            
        }
        else{
        if(1000+niz[4]*100+niz[5]*10+niz[6]<1917) throw std::logic_error("JMBG nije validan");}
        if(brojitelj==0){
            p=this;
            zadnji=nullptr;
            trenutni=this;
        }
        else{ 
            p=this;
            zadnji=trenutni;
            trenutni=this;
            while(p->zadnji!=nullptr){
                p=p->zadnji->p;
              
                if(jmbgg==p->jmbgg) throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
            }
        }
        brojitelj++;
    }
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, GradjaninBiH::Pol pol): imeiprezime(ime_i_prezime){
        if(brojitelj==0){
            trenutni=this;
            p=this;
            zadnji=nullptr;
        }
        else{
            p=this;
            zadnji=trenutni;
            trenutni=this;
        }
        if(dan_rodjenja<1 || dan_rodjenja>31 || mjesec_rodjenja<1 || mjesec_rodjenja>12 || godina_rodjenja<1 || sifra_regije<0 || sifra_regije>99) throw std::logic_error("Neispravni podaci");        
        if(dan_rodjenja<10) {niz[0]=0; niz[1]=dan_rodjenja;}
        else{
        GradjaninBiH::niz[1]=dan_rodjenja%10;
        dan_rodjenja/=10;
        GradjaninBiH::niz[0]=dan_rodjenja%10;
        
        }
        if(mjesec_rodjenja<10){niz[2]=0; niz[3]=mjesec_rodjenja;}
        else{
        GradjaninBiH::niz[3]=mjesec_rodjenja%10;
        mjesec_rodjenja/=10;
        GradjaninBiH::niz[2]=mjesec_rodjenja%10;
        
        }
        if(godina_rodjenja<2000) godina_rodjenja-=1000;
        GradjaninBiH::niz[6]=godina_rodjenja%10;
        godina_rodjenja/=10;
        GradjaninBiH::niz[5]=godina_rodjenja%10;
        
        godina_rodjenja/=10;
        GradjaninBiH::niz[4]=godina_rodjenja%10;
        
        GradjaninBiH::niz[8]=sifra_regije%10;
        sifra_regije/=10;
        GradjaninBiH::niz[7]=sifra_regije%10;

       
       // if(GradjaninBiH::niz[0]*10+GradjaninBiH::niz[1]<1 || GradjaninBiH::niz[0]*10+GradjaninBiH::niz[1]>31) throw std::logic_error("JMBG nije validan");
        if(GradjaninBiH::niz[2]*10+GradjaninBiH::niz[3]<1 || GradjaninBiH::niz[2]*10+GradjaninBiH::niz[3]>12) throw std::logic_error("JMBG nije validan");
        if(niz[4]==0){
            //if(2000+niz[4]*100+niz[5]*10+niz[6]>2017) throw std::logic_error("JMBG nije validan");
        }
        else{
            if(1000+GradjaninBiH::niz[4]*100+GradjaninBiH::niz[5]*10+GradjaninBiH::niz[6]<1917) throw std::logic_error("JMBG nije validan");}
        if(pol==Pol::Musko){
            if(brojcanipol1>499) throw std::logic_error("Prekoraceno");
            niz[9]=0; niz[10]=0; niz[11]=0;
           
             GradjaninBiH::niz[12]=11-(7*(GradjaninBiH::niz[0]+GradjaninBiH::niz[6])+6*(GradjaninBiH::niz[1]+GradjaninBiH::niz[7])+5*(GradjaninBiH::niz[2]+GradjaninBiH::niz[8])+4*(GradjaninBiH::niz[3]+GradjaninBiH::niz[9])+3*(GradjaninBiH::niz[4]+GradjaninBiH::niz[10])+2*(GradjaninBiH::niz[5]+GradjaninBiH::niz[11]))%11;
            brojac=0;
            jmbgg=0;        
            if(GradjaninBiH::niz[12]==11) GradjaninBiH::niz[12]=0; 
            if(GradjaninBiH::niz[12]==10) throw std::logic_error("JMBG nije validan");
            for(int i=12;i>=0;i--){GradjaninBiH::jmbgg+=niz[i]*std::pow(10,brojac); brojac++;}
            brojac=0;
            while(p->zadnji!=nullptr){
                p=p->zadnji;
                if(jmbgg==p->jmbgg){
                    brojcanipol1++;
                    if(brojcanipol1<10){niz[9]=0; niz[10]=0; niz[11]=brojcanipol1;
                    }
                    else if(brojcanipol1<100){niz[9]=0; niz[11]=brojcanipol1%10; brojcanipol1/=10; niz[10]=brojcanipol1%10;
                    }
                    else{
                        niz[11]=brojcanipol1%10; brojcanipol1/=10; niz[10]=brojcanipol1%10; brojcanipol1/=10; niz[9]=brojcanipol1%10;
                        }
                    GradjaninBiH::niz[12]=11-(7*(GradjaninBiH::niz[0]+GradjaninBiH::niz[6])+6*(GradjaninBiH::niz[1]+GradjaninBiH::niz[7])+5*(GradjaninBiH::niz[2]+GradjaninBiH::niz[8])+4*(GradjaninBiH::niz[3]+GradjaninBiH::niz[9])+3*(GradjaninBiH::niz[4]+GradjaninBiH::niz[10])+2*(GradjaninBiH::niz[5]+GradjaninBiH::niz[11]))%11;
                    jmbgg=0;
                    brojac=0;
                   for(int i=12;i>=0;i--){jmbgg+=niz[i]*std::pow(10,brojac); brojac++;}
                }
            }
        }
        else{
           // if(brojcanipol2<0) throw std::logic_error("Prekoraceno");
        //    if(brojcanipol2<499 || brojcanipol2>999) throw std::logic_error("Prekoraceno");
          /*  if(brojcanipol2<10){niz[9]=5; niz[10]=0; niz[11]=brojcanipol2;}
            else if(brojcanipol2<100){niz[9]=5; niz[11]=brojcanipol2%10; brojcanipol2/=10; niz[10]=brojcanipol2%10;}
            else{
                niz[11]=brojcanipol2%10; brojcanipol2/=10; niz[10]=brojcanipol2%10; brojcanipol2/=10; niz[9]=brojcanipol2%10;}*/
            //}
            niz[9]=5; niz[10]=0; niz[11]=0;
            GradjaninBiH::niz[12]=11-(7*(GradjaninBiH::niz[0]+GradjaninBiH::niz[6])+6*(GradjaninBiH::niz[1]+GradjaninBiH::niz[7])+5*(GradjaninBiH::niz[2]+GradjaninBiH::niz[8])+4*(GradjaninBiH::niz[3]+GradjaninBiH::niz[9])+3*(GradjaninBiH::niz[4]+GradjaninBiH::niz[10])+2*(GradjaninBiH::niz[5]+GradjaninBiH::niz[11]))%11;
            brojac=0;
            jmbgg=0;
            if(niz[12]==11) niz[12]=0;
            if(niz[12]==10) throw std::logic_error("JMBG nije validan");
            for(int i=12; i>=0; i--){jmbgg+=niz[i]*std::pow(10,brojac); brojac++;}
            while(p->zadnji!=nullptr){
                //std::cout<<p->zadnji->imeiprezime;
                p=p->zadnji;
               // std::cout<<p->imeiprezime;
                if(jmbgg==p->jmbgg){
                    brojcanipol2++;
                    if(brojcanipol2<10) {niz[9]=5; niz[10]=0;niz[11]=brojcanipol2%10;}
                    else if(brojcanipol2<100){niz[9]=5; niz[11]=brojcanipol2%10; brojcanipol2/=10; niz[10]=brojcanipol2%10;}
                    else {niz[11]=brojcanipol2%10; brojcanipol2/=10; niz[10]=brojcanipol2%10; brojcanipol2/=10; niz[9]=brojcanipol2%10;
                    }
                    GradjaninBiH::niz[12]=11-(7*(GradjaninBiH::niz[0]+GradjaninBiH::niz[6])+6*(GradjaninBiH::niz[1]+GradjaninBiH::niz[7])+5*(GradjaninBiH::niz[2]+GradjaninBiH::niz[8])+4*(GradjaninBiH::niz[3]+GradjaninBiH::niz[9])+3*(GradjaninBiH::niz[4]+GradjaninBiH::niz[10])+2*(GradjaninBiH::niz[5]+GradjaninBiH::niz[11]))%11;
                    jmbgg=0;
                    brojac=0;
                    for(int i=12;i>=0;i--){GradjaninBiH::jmbgg+=niz[i]*std::pow(10,brojac); brojac++;}

                }

            }
        }
    
    brojitelj++;
    }
    ~GradjaninBiH(){
       // std::cout<<"DESTRUKTOR"<<std::endl;
  /*      GradjaninBiH *pokazatelj1=trenutni, *pokazatelj2=trenutni;
        if(pokazatelj1==this){pokazatelj1=pokazatelj1->p; trenutni=trenutni->p;}
        else{
            while(pokazatelj1!=nullptr){
                pokazatelj1=pokazatelj1->p;
                if(pokazatelj1==this){
        
                    pokazatelj1=pokazatelj1->p;
                    pokazatelj2->p=pokazatelj1;
                    break;
                }
                
                pokazatelj2=pokazatelj2->p;
            }
        }*/
    }
    std::string DajImeIPrezime() const {return imeiprezime;}
    long long int DajJMBG() const {return jmbgg;}
    int DajDanRodjenja() const { return GradjaninBiH::niz[0]*10 + GradjaninBiH::niz[1];}
    int DajMjesecRodjenja() const{ return GradjaninBiH::niz[2]*10+GradjaninBiH::niz[3];}
    int DajGodinuRodjenja() const {if(niz[4]==0) return 2000+niz[4]*100+niz[5]*10+niz[6]; else return 1000+GradjaninBiH::niz[4]*100+GradjaninBiH::niz[5]*10+GradjaninBiH::niz[6];} //
    int DajSifruRegije() const{return GradjaninBiH::niz[7]*10+GradjaninBiH::niz[8];}
    Pol DajPol() const{ if(GradjaninBiH::niz[9]*100+GradjaninBiH::niz[10]*10+GradjaninBiH::niz[11]>=0 && GradjaninBiH::niz[9]*100+GradjaninBiH::niz[10]*10+GradjaninBiH::niz[11]<499) return Pol::Musko; else return Pol::Zensko;}
    void PromijeniImeIPrezime(std::string novo_ime){imeiprezime=novo_ime;}
    void Ispisi() const;
};
void GradjaninBiH::Ispisi()const {
    std::cout<<GradjaninBiH::jmbgg<<std::endl;
}
int GradjaninBiH::brojitelj=0;
int GradjaninBiH::brojcanipol1=0;
int GradjaninBiH::brojcanipol2=0;
int GradjaninBiH::brojac=0;
GradjaninBiH* GradjaninBiH::trenutni=nullptr;

int main ()
{
    int br_JMBG;
    int brojpodrp;
    std::string ime_i_prezime;
    long long int jmbg;
    GradjaninBiH **niz=new GradjaninBiH*[100];
    for(int i(0);i<100;i++) niz[i]=nullptr;
    
    std::cout<<"Koliko gradjana zelite unijeti po JMBG? ";
    std::cin>>br_JMBG;
    std::cout<<std::endl;
    for(int i(0);i<br_JMBG;i++){
        jodja:
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        if(i==br_JMBG) break;
        try{
        //std::cin.clear();
        //std::cin.ignore(1000,'\n');
        std::cout<<"Unesite ime i prezime (u istom redu): ";
        std::getline(std::cin,ime_i_prezime);
        std::cout<<std::endl;
        std::cout<<"Unesite JMBG: "<<std::endl;
        std::cin>>jmbg;
        niz[i]=new GradjaninBiH(ime_i_prezime,jmbg);
       // niz[i]=nullptr;
        std::cout<<"Unijeli ste gradjanina "<<niz[i]->DajImeIPrezime()<<" rodjenog "<<niz[i]->DajDanRodjenja()<<"."<<niz[i]->DajMjesecRodjenja()<<"."<<niz[i]->DajGodinuRodjenja()<<" u regiji "<<niz[i]->DajSifruRegije()<<",";
        if(niz[i]->DajPol()==0) std::cout<<" musko."<<std::endl;
        else std::cout<<" zensko."<<std::endl;
    } 
    catch(std::logic_error e){
        std::cout<<e.what()<<std::endl;
        //i--;
        goto jodja;
    }
    catch(...){
        std::cout<<"Neispravni podaci";
    }}
    std::cout<<"Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? "<<std::endl;
    std::cin>>brojpodrp;
    for(int i(0);i<brojpodrp;i++){
       ponovo:
       try{
        int d,m,g;
        char spol;
        char c1,c2;
        int sifra;
        if(i==brojpodrp) break;
        GradjaninBiH::Pol pol;
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        std::cout<<"Unesite ime i prezime (u istom redu): "<<std::endl;
        std::getline(std::cin,ime_i_prezime);
        std::cout<<"Unesite datum rodjenja (format dd/mm/gggg): "<<std::endl;
        std::cin>>d; 
        std::cin>>c1; 
        std::cin>>m; 
        std::cin>>c2; 
        std::cin>>g; 
        std::cout<<"Unesite sifru regije: "<<std::endl;
        std::cin>>sifra; 
        std::cout<<"Unesite M za musko, Z za zensko: "<<std::endl;
        std::cin>>spol;
        if(d<0 || d>31) throw std::logic_error("Neispravni podaci");
        if(c1!='/') throw std::logic_error("Neispravni podaci");
        if(m<0 || m>12) throw std::logic_error("Neispravni podaci");
        if(c2!='/') throw std::logic_error("Neispravni podaci");
        if(g<1917 || g>2017) throw std::logic_error("Neispravni podaci");
        if(sifra<0 || sifra > 99 ) throw std::logic_error("Neispravni podaci");
         if(spol!='M' && spol!='Z') throw std::logic_error("Neispravni podaci");
        if(spol=='M') pol=GradjaninBiH::Pol::Musko;
        else pol=GradjaninBiH::Pol::Zensko;
        niz[i+br_JMBG]=new GradjaninBiH(ime_i_prezime,d,m,g,sifra,pol);
    //    niz[i]=nullptr;
        std::cout<<"Unijeli ste gradjanina "<<niz[i+br_JMBG]->DajImeIPrezime()<<" JMBG: "<<niz[i+br_JMBG]->DajJMBG()<<"."<<std::endl;
    }
    catch(std::logic_error e){
        std::cout<<e.what()<<std::endl;
        //std::cin.clear();
        //std::cin.ignore(1000,'\n');
        //i--;
        goto ponovo;
    }}
   
     
     for(int i(0);i<100;i++) delete niz[i];
     delete [] niz;
	return 0;
}