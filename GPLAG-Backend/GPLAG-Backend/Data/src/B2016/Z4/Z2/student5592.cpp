/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <string>
class GradjaninBiH{
    
    std::string ime;
    long long int j;
    int niz[13];
    GradjaninBiH* p;
    int dan,mjesec,godina,sifra,rod,kod;
    
    static GradjaninBiH* prethodni;
    
    public:
    enum Pol {Musko,Zensko};
    GradjaninBiH(std::string ime_i_prezime,long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,int godina_rodjenja,
                int sifra_regije, Pol pol);
                
    std::string DajImeIPrezime() const{ return ime; }
    long long int DajJMBG() const { return j;}
    int DajDanRodjenja() const {return dan; }
    int DajMjesecRodjenja() const {return mjesec; }
    int DajGodinuRodjenja() const { return godina; }
    int DajSifruRegije() const { return sifra; }
    Pol DajPol() const;
    void PromijeniImeIPrezime(std::string novo_ime) { ime=novo_ime; }
    
    
};

GradjaninBiH::Pol GradjaninBiH::DajPol() const{
    
    int kod=niz[9]*100+niz[10]*10+niz[11];
    
    if(kod>=0 && kod<=499)
        return Pol::Musko;
    else
        return Pol::Zensko;
}
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg):ime(ime_i_prezime) {
    
    long long int pomocni=jmbg;
    for(int i(12);i>=0;i--){
        niz[i]=pomocni%10;
        pomocni/=10;
    }
    int brojdana[]{31,28,31,30,31,30,31,31,30,31,30,31};
    
    
     if(niz[4]==0)
        godina=2000+niz[5]*10+niz[6];
    else godina=1000+niz[4]*100+niz[5]*10+niz[6];
    
     mjesec=niz[2]*10+niz[3];
     dan=niz[0]*10+niz[1];
    sifra=niz[7]*10+niz[8];
    rod=niz[9]*100+niz[10]*10+niz[11];
    int o=11-(7*(niz[0]+niz[6])+6*(niz[1]+niz[7])+5*(niz[2]+niz[8])+4*(niz[3]+niz[9])+3*(niz[4]+niz[10])+2*(niz[5]+niz[11]))%11;
    
    if(godina<1 || mjesec<1 || mjesec>12 || dan<1 || (dan>brojdana[mjesec-1]) || !(sifra>=0 || sifra<=99)
        || (niz[12]!=o && o!=11))
        throw std::logic_error ("JMBG nije validan");
        
        
    if(prethodni==nullptr){
        j=jmbg;
        p=nullptr;
    }
    
    else if(prethodni!=nullptr){
        p=prethodni;
        
        GradjaninBiH* pom=p;
        while(pom!=nullptr){
            
          if(pom->j==jmbg){
                throw std::logic_error ("Vec postoji gradjanin sa istim JMBG");
            }
                
            pom=pom->p;
        }
        
    }
    kod=niz[9]*100+niz[10]*10+niz[11];
    j=jmbg;
    prethodni=this;
}
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime,int dan_rodjenja,int mjesec_rodjenja,int godina_rodjenja,int sifra_regije, Pol pol): ime(ime_i_prezime){
    
    int brojdana[]{31,28,31,30,31,30,31,31,30,31,30,31};
    if(godina_rodjenja % 4==0 || godina_rodjenja%100!=0 || godina_rodjenja%400==0) brojdana[1]++;
    
    if(godina_rodjenja<1 || mjesec_rodjenja<1 || mjesec_rodjenja>12 || dan_rodjenja<1 || (dan_rodjenja>brojdana[mjesec_rodjenja-1])
     || !(sifra_regije>=0 && sifra_regije<=99))
        throw std::logic_error ("Neispravni podaci");
        
    
    niz[0]=dan_rodjenja/10;
    niz[1]=dan_rodjenja%10;
    niz[2]=mjesec_rodjenja/10;
    niz[3]=mjesec_rodjenja%10;
    niz[4]=(godina_rodjenja%1000)/100;
    niz[5]=(godina_rodjenja%100)/10;
    niz[6]=godina_rodjenja%10;
    niz[7]=sifra_regije/10;
    niz[8]=sifra_regije%10;
    
    dan=dan_rodjenja;
    mjesec=mjesec_rodjenja;
    godina=godina_rodjenja;
    sifra=sifra_regije;
    
    if (pol==0) rod=0;
    else rod=1;
    
    //godina_rodjenja=godina_rodjenja/10;
    
    if(prethodni==nullptr){
        if(pol==0){
            niz[9]=0;
            niz[10]=0;
            niz[11]=0;
            kod=niz[9]*100+niz[10]*10+niz[11];
            }
        else if(pol==1){
            niz[9]=5;
            niz[10]=0;
            niz[11]=0;
            kod=niz[9]*100+niz[10]*10+niz[11];
            }
        p=nullptr;
    }
    else if(prethodni!=nullptr){
        p=prethodni;
        GradjaninBiH* pom=p;
        bool e(false);
        
        while(pom!=nullptr){
            if(dan_rodjenja==pom->dan && mjesec_rodjenja==pom->mjesec && godina_rodjenja==pom->godina
                && sifra_regije==pom->sifra && pom->rod==pol){
                    
                    
                    kod=pom->kod+1;
                 
                  
                    niz[9]=kod/100;
                    niz[10]=(kod/10)%10;
                    niz[11]=kod%10;
                    e=true;
                }
            
            pom=pom->p;
        }
        if(!e){
            if(pol==0){
            niz[9]=0;
            niz[10]=0;
            niz[11]=0;
        }
        else if(pol==1) {
            niz[9]=5;
            niz[10]=0;
            niz[11]=0;
        }
    }
    
    }
    
    niz[12]=11-(7*(niz[0]+niz[6])+6*(niz[1]+niz[7])+5*(niz[2]+niz[8])+4*(niz[3]+niz[9])+3*(niz[4]+niz[10])+2*(niz[5]+niz[11]))%11;
   
    if(niz[12]==11) niz[12]=0;
    //if(niz[12]==10) throw std::logic_error (JMBG nije validan)
    
    
    j=0;
    long long int broj(1000000000000);
    
    for(int i(0);i<=12;i++){
        j+=niz[i]*broj;
        broj/=10;

    }
    
    prethodni=this;
    
    
    
}

GradjaninBiH* GradjaninBiH::prethodni=nullptr;
int main ()
{
    int broj,br,p(0);
    GradjaninBiH* niz[100];
    std::cout<<"Koliko gradjana zelite unijeti po JMBG? "<<std::endl;
    std::cin>>broj;
    
    for(int i(0);i<broj;i++){
        
        std::cout<<"Unesite ime i prezime (u istom redu): "<<std::endl;
        std::cin.ignore(1000,'\n');
        std::cin.clear();
        std::string s;
        getline(std::cin,s);
        
        std::cout<<"Unesite JMBG: "<<std::endl;
        long long int jmbg;
        std::cin>>jmbg;
        
        try{
            niz[p]=new GradjaninBiH (s,jmbg);
            std::cout<<"Unijeli ste gradjanina "<<niz[p]->DajImeIPrezime()<<" rodjenog "<<niz[p]->DajDanRodjenja()<<"."<<niz[p]->DajMjesecRodjenja()<<"."<<niz[p]->DajGodinuRodjenja()<<
                    " u regiji "<<niz[p]->DajSifruRegije()<<", ";
            if(niz[p]->DajPol()) std::cout<<"zensko."<<std::endl;
            else std::cout<<"musko."<<std::endl;
          
            
        }
        catch(std::logic_error e) {std::cout<<e.what()<<std::endl; i--;}
    
        
    }
    
    std::cout<<"Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? "<<std::endl;
    std::cin>>br;
    
    
    for(int i(0);i<br;i++){
    
            
            std::cout<<"Unesite ime i prezime (u istom redu): "<<std::endl;
            std::cin.ignore(1000,'\n');
            std::cin.clear();
            std::string ime;
            getline(std::cin,ime);
            
            std::cout<<"Unesite datum rodjenja (format dd/mm/gggg): "<<std::endl;
            int d,m,g;
            char z1,z2;
            std::cin>>d>>z1>>m>>z2>>g;
            
            std::cout<<"Unesite sifru regije: "<<std::endl;
            int sifra;
            std::cin>>sifra;
            
            std::cout<<"Unesite M za musko, Z za zensko: "<<std::endl;
            char pol;
            std::cin>>pol;
            
            try{
                if(pol=='M')    
                    niz[p]=new GradjaninBiH (ime,d,m,g,sifra, GradjaninBiH::Pol::Musko);
                else 
                    niz[p]=new GradjaninBiH (ime,d,m,g,sifra, GradjaninBiH::Pol::Zensko);
                
                std::cout<<"Unijeli ste gradjanina "<<niz[p]->DajImeIPrezime()<<" JMBG: "<<niz[p]->DajJMBG()<<"."<<std::endl;
                p++;
            }
            
            catch(std::logic_error e) {std::cout<<e.what()<<std::endl; i--;}

    }
   

	return 0;
}