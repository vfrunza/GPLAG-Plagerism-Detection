/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath>

class GradjaninBiH{
    std::string ime_i_prezime;
    long long int jmbg;
    GradjaninBiH* prethodni; //pok na prethodno kreiranog gradjanina
    
    void PostaviPrethodnika(GradjaninBiH* p) { prethodni = p; }
    GradjaninBiH* VratiPrethodnika() { return prethodni; }
    void PostaviJMBG(long long int jmb) { jmbg=jmb;}
    int DajSifruPola() const {
        long long int jmb=DajJMBG();
        int cifre[13];
        int i=0;
        while(jmb>0) {
            cifre[i]=jmb%10;
            i++;
            jmb/=10;
        }
        if(i==12) cifre[12]=0;
        
         for(int i=0;i<7;i++){
            int temp=cifre[i];
            cifre[i]=cifre[12-i];
            cifre[12-i]=temp;
        }
        
        return cifre[9]*100+cifre[10]*10+cifre[11];
    }
    
    bool IspitajJMBG(long long int jmbg){
        
        GradjaninBiH* novi=posljednji;
        while(novi!=nullptr) {
            if(novi->DajJMBG()==jmbg) return false;
            
            GradjaninBiH* pom=novi;
            novi=pom->VratiPrethodnika();
            pom->PostaviPrethodnika(nullptr);
            pom=nullptr;
        }
        return true;
    }
    
    //pomocna za generisanje pola
    //ako nema nijednog kreiranog gradjanina, vraca 0 ako je musko, 500 ako je zensko
    // ako ima, naci ce dvije najmanje sifra pola i na osnovu toga generisati
    int generisiPol(int sifra_regije, std::string pol){ 
        int prviNajmanjiMuskarci=2000; // 2000 jer je dovoljno velik broj, svakako ne moze nicija sifra biti > 1000
        int drugiNajmanjiMuskarci=2000;
        int prviNajmanjiZene=2000;
        int drugiNajmanjiZene=2000;
        
        if(posljednji==nullptr){ // nema kreiranih gradjana
            if(pol == "Musko") return 0;
            return 500;
        }
        
        GradjaninBiH* novi=posljednji;
        while(novi!=nullptr){
            GradjaninBiH* pom=novi;
            if(sifra_regije==pom->DajSifruRegije()){
                int sifra=pom->DajSifruPola();
                if(pol=="Musko" && pom->DajPol()==Pol::Musko){
                    if(sifra <prviNajmanjiMuskarci){
                        
                        drugiNajmanjiMuskarci=prviNajmanjiMuskarci;
                        prviNajmanjiMuskarci =sifra;
                    }
                    else if(sifra < drugiNajmanjiMuskarci && sifra!= prviNajmanjiMuskarci){
                        drugiNajmanjiMuskarci=sifra;
                    }
                }
                else if(pol=="Zensko" && pom->DajPol()==Pol::Zensko){
                    if(sifra < prviNajmanjiZene){
                        drugiNajmanjiZene=prviNajmanjiZene;
                        prviNajmanjiZene=sifra;
                    }
                    else if(sifra < drugiNajmanjiZene && sifra!=prviNajmanjiZene){
                        drugiNajmanjiZene=sifra;
                    }
                }
            }
             //prolazak kroz listu
            novi=pom->VratiPrethodnika();
            pom=nullptr;
        }
         novi=nullptr;
                
                //znak da nije pronadjen nijedan muskarac
                if(pol=="Musko"){
                    if(prviNajmanjiMuskarci==2000) { return 0; }
                    if(prviNajmanjiMuskarci+1 != drugiNajmanjiMuskarci && prviNajmanjiMuskarci+1 <500) return prviNajmanjiMuskarci+1;
                    if(prviNajmanjiMuskarci+1 ==drugiNajmanjiMuskarci && drugiNajmanjiMuskarci+1 <500) return drugiNajmanjiMuskarci+1;
                 
                 }
             
             if(pol=="Zensko"){
                 if(prviNajmanjiZene==2000) return 500;
                 if(prviNajmanjiZene+1 != drugiNajmanjiZene && prviNajmanjiZene+1<1000) return prviNajmanjiZene+1;
                 if(prviNajmanjiZene+1 == drugiNajmanjiZene && drugiNajmanjiZene+1 < 1000) return drugiNajmanjiZene+1;
             }
            
        return -1; //znak da je doslo do greske
        }
    
    public:
    
    enum Pol {Musko, Zensko};
    static GradjaninBiH* posljednji;

    GradjaninBiH(std::string ime_i_prezime, long long int jmbg) {
        this->ime_i_prezime = ime_i_prezime;
        
        if(!IspitajJMBG(jmbg))  throw std::logic_error("Vec postoji gradjanin sa istim JMBG"); //radi
        PromijeniImeIPrezime(ime_i_prezime);
        
        long long int jmb=jmbg;
        if(jmbg<0) throw std::logic_error("JMBG nije validan");
        int cifre[13];
        int i=0;
        while (jmbg>0) {
            cifre[i]=jmbg%10;
            i++;
            jmbg/=10;
        }
        
        if(i==12) cifre[12]=0;
        if(i<12 || i>13) throw std::logic_error("JMBG nije validan");
        
        for(int i=0;i<7;i++){
            int temp=cifre[i];
            cifre[i]=cifre[12-i];
            cifre[12-i]=temp;
        }

        int dan=cifre[0]*10+cifre[1];
        int mjesec=cifre[2]*10+cifre[3];
        int godina;
    
        if(cifre[4]==0) godina= 2000+cifre[5]*10+cifre[6];
        else godina = 1000 + cifre[4]*100 +cifre[5]*10+cifre[6]; 
        

       if(dan>31) throw std::logic_error("JMBG nije validan");
       
       //mjeseci sa 30 dana
       if(((mjesec==4) || (mjesec==6) || (mjesec==9) || (mjesec==11)) && dan>=31) throw std::logic_error("JMBG nije validan");
       
       //provjera za februar
       if(mjesec == 2){
           //prestupna godina
           if(godina%4 == 0 && godina%400 == 0 && godina%100 != 0){
               if(dan > 29) throw std::logic_error("JMBG nije validan");
           }
           else{
               if(dan > 28) throw std::logic_error("JMBG nije validan");
           }
           
       }
       
       if(godina>2017 || godina < 1917) throw std::logic_error("JMBG nije validan"); //provjeriti
     
     int kontrolnacifra= 11-((7*(cifre[0]+cifre[6])+6*(cifre[1]+cifre[7])+5*(cifre[2]+cifre[8])+4*(cifre[3]+cifre[9])+3*(cifre[4]+cifre[10])+2*(cifre[5]+cifre[11]))%11);
        
     if(kontrolnacifra>=12 || (kontrolnacifra==10)) throw std::logic_error ("JMBG nije validan");
     if(kontrolnacifra!=cifre[12]){
         if(kontrolnacifra==11 && cifre[12]==0){
             this->jmbg = jmb;
             PostaviPrethodnika(posljednji);
             posljednji=this;
         }
         else throw std::logic_error ("JMBG nije validan");
     }
     else{
          this->jmbg = jmb;
          PostaviPrethodnika(posljednji);
          posljednji=this;
     }
    
     
    }
    
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol) {
        this->ime_i_prezime = ime_i_prezime;
        
        if(dan_rodjenja > 31 || dan_rodjenja < 0) throw std::logic_error("Neispravni podaci");
        if(mjesec_rodjenja < 0 || mjesec_rodjenja > 13) throw std::logic_error("Neispravni podaci");
        
        if((mjesec_rodjenja== 4 || mjesec_rodjenja==6 || mjesec_rodjenja == 9 || mjesec_rodjenja==11) && dan_rodjenja > 30) 
            throw std::logic_error("Neispravni podaci");
            
        //februar    
        if(mjesec_rodjenja == 2){
            if(godina_rodjenja %4 == 0 && godina_rodjenja%100 != 0 && godina_rodjenja %400 == 0){
                if(dan_rodjenja > 29) throw std::logic_error("Neispravni podaci");
            }else {
                if(dan_rodjenja > 28) throw std::logic_error("Neispravni podaci");
            } }
            
            if(godina_rodjenja > 2017) throw std::logic_error("Neispravni podaci");
            if(godina_rodjenja < 1917) throw std::logic_error("Neispravni podaci");
            
            if(sifra_regije<0 || sifra_regije>99) throw std::logic_error("Neispravni podaci");
            
            int cifre[13];
            
            if(dan_rodjenja<10) {cifre[0]=0; cifre[1]=dan_rodjenja;}
            else {cifre[0]= dan_rodjenja/10; cifre[1]=dan_rodjenja%10;}
            
            if(mjesec_rodjenja < 10){cifre[2]=0; cifre[3]=mjesec_rodjenja; }
            else {cifre[2] =mjesec_rodjenja/10; cifre[3]=mjesec_rodjenja%10;}
            
            if(godina_rodjenja==2000) { cifre[4]=0; cifre[5]=0; cifre[6]=0; }
            else if(godina_rodjenja > 2000 && godina_rodjenja<2010) { cifre[4]=0; cifre[5]=0; cifre[6]=godina_rodjenja%10;}
            else if(godina_rodjenja > 2010 && godina_rodjenja<2018) {cifre[4] = 0; cifre[5] = (godina_rodjenja/10)%10; cifre[6]=godina_rodjenja%10; }
            else {cifre[4] = (godina_rodjenja/100)%10 ; cifre[5] =(godina_rodjenja/10)%10; cifre[6]=godina_rodjenja%10;}
    
            if(sifra_regije<10) {cifre[7]=0; cifre[8]=sifra_regije;}
            else {cifre[7]=sifra_regije/10; cifre[8]=sifra_regije%10;}
            
            int sifra;
            if(pol==Pol::Musko) sifra=generisiPol(sifra_regije, "Musko");
            else sifra=generisiPol(sifra_regije,"Zensko");
            if(sifra<10 && sifra>=0) { cifre[9]=cifre[10]=cifre[11] =0; }
            else if(sifra>=10 && sifra<100){ cifre[9]=0; cifre[10]=sifra/10 ;cifre[11]=sifra%10;}
            else if(sifra>=100 && sifra<1000) {cifre[9]=sifra/100 ; cifre[10]=(sifra/10)%10 ;cifre[11]=sifra%10; }
            //if(sifra==-1) - ako je metoda vratila gresku sta onda???
            
            int kontrolnacifra= 11-((7*(cifre[0]+cifre[6])+6*(cifre[1]+cifre[7])+5*(cifre[2]+cifre[8])+4*(cifre[3]+cifre[9])+3*(cifre[4]+cifre[10])+2*(cifre[5]+cifre[11]))%11);
 
            if(kontrolnacifra==10 || kontrolnacifra < 0 || kontrolnacifra > 11)  throw std::logic_error("JMBG nije validan"); 
            
            
            //kad je kontrolnaCifra 11, onda je 0?
            if(kontrolnacifra==11)cifre[12] =0;
            else cifre[12]=kontrolnacifra;

            
            if(cifre[0]==0){
                long long int jmb=0;
                for(int i=1;i<13;i++){
                    jmb=jmb+pow(10,12-i)*cifre[i];
                }
                jmbg=jmb;
            }
            else {
            long long int jmb=0;
            for(int i = 0; i < 13; i++){
                jmb = jmb + pow(10,12-i)*cifre[i];
                
            }
  
            jmbg = jmb;
            
            }
      GradjaninBiH* novi=this;
      novi->prethodni=posljednji;
      posljednji=novi;
     }
     
     ~GradjaninBiH(){
         if(posljednji->VratiPrethodnika() == nullptr) posljednji=nullptr; //ako je samo 1 element u listi
         else if(this == posljednji){
             posljednji=this->VratiPrethodnika();
         }
         else{
             GradjaninBiH* novi=posljednji;
             while(novi->VratiPrethodnika()!=this){
                 GradjaninBiH* pom= novi;
                 novi=pom->VratiPrethodnika();
                 pom=nullptr;
             }
             
             novi->PostaviPrethodnika(this->VratiPrethodnika());
         }
     }
    
    std::string DajImeIPrezime() const { return ime_i_prezime ; }
    
    long long int DajJMBG() const { return jmbg; }
    
    int DajDanRodjenja() const {
        long long int jmb=DajJMBG();
        int cifre[13];
        int i=0;
        while(jmb>0){
            cifre[i]=jmb%10;
            i++;
            jmb/=10;
        }
        
        if(i==12) cifre[12]=0;
        
        for(int i=0;i<7;i++){
            int temp=cifre[i];
            cifre[i]=cifre[12-i];
            cifre[12-i]=temp;
        }
        
        if(cifre[0]==0) return cifre[1];
        else {
            return cifre[0]*10+cifre[1];
        }
    }
    
    int DajMjesecRodjenja() const {
        long long int jmb=DajJMBG();
        
        int cifre[13];
        int i=0;
        while(jmb>0) {
            cifre[i]=jmb%10;
            i++;
            jmb/=10;
        }
        if(i==12) cifre[12]=0;
        
         for(int i=0;i<7;i++){
            int temp=cifre[i];
            cifre[i]=cifre[12-i];
            cifre[12-i]=temp;
        }
        
        if(cifre[2]==0) return cifre[3];
        else {
            return cifre[2]*10+cifre[3];
        }
        
    }
    
    int DajGodinuRodjenja() const {
        long long int jmb=DajJMBG();
        
        int cifre[13];
        int i=0;
        while(jmb>0) {
            cifre[i]=jmb%10;
            i++;
            jmb/=10;
        }
        if(i==12) cifre[12]=0;
        
         for(int i=0;i<7;i++){
            int temp=cifre[i];
            cifre[i]=cifre[12-i];
            cifre[12-i]=temp;
        }
        
        if(cifre[4]==0){ 
            return 2000 + cifre[5]*10+cifre[6];
        } 
        
        return 1000+cifre[4]*100+cifre[5]*10+cifre[6];
        
    }
    
    int DajSifruRegije() const {
        long long int jmb=DajJMBG();
        int cifre[13];
        int i=0;
        while(jmb>0) {
            cifre[i]=jmb%10;
            i++;
            jmb/=10;
        }
        if(i==12) cifre[12]=0;
        
         for(int i=0;i<7;i++){
            int temp=cifre[i];
            cifre[i]=cifre[12-i];
            cifre[12-i]=temp;
        }
        if(cifre[7]==0) return cifre[8];
        else {
            return cifre[7]*10+cifre[8];
        }
    }
    
    Pol DajPol() const {
        int spol=this->DajSifruPola();
        if(spol>=0 && spol<500) return Pol::Musko;
        return Pol::Zensko;
    }
    
    void PromijeniImeIPrezime(std::string novo_ime) { ime_i_prezime = novo_ime; }
};

// postaviti posljednjeg na nullptr
GradjaninBiH* GradjaninBiH::posljednji=nullptr;

int main ()
{
    GradjaninBiH* niz[100];
    int brojGradjana=0;
    std::cout << "Koliko gradjana zelite unijeti po JMBG? "<< std::endl;
    int n;
    std::cin >> n;
    for(int i =0; i < n; i++){
    try{
            
            std::cout<<"Unesite ime i prezime (u istom redu): "<<std::endl;
            std::string ime_prezime;
            std::cin.ignore(256, '\n');
            std::getline(std::cin, ime_prezime);
            
            std::cin.clear();
            std::cout<<"Unesite JMBG: "<<std::endl;
            long long int jmb;
            std::cin>>jmb;
            
            GradjaninBiH g(ime_prezime, jmb);
            niz[brojGradjana]=&g;
            brojGradjana++;
            std::cout <<"Unijeli ste gradjanina " << ime_prezime << " rodjenog " << g.DajDanRodjenja() << "." << g.DajMjesecRodjenja() << "." << g.DajGodinuRodjenja() 
                      << " u regiji " << g.DajSifruRegije() << ", ";
                      if(g.DajPol() == GradjaninBiH::Musko) std::cout <<"musko."<<std::endl;
                      else std::cout << "zensko." << std::endl;
        }
    
        catch(std::logic_error e){
            std::cout << e.what() << std::endl;
            i--;
        }
    }
    
    std::cout << "Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? " << std::endl;
    std::cin >> n;
    
    for(int i = 0; i < n; i++){
        try{
            std::cout<<"Unesite ime i prezime (u istom redu): "<<std::endl;
            std::string ime_prezime;
            std::cin.ignore();
            std::getline(std::cin, ime_prezime);
            std::cin.clear();
            
            std::cout<<"Unesite datum rodjenja (format dd/mm/gggg): " << std::endl;
            std::string datumRodjenja;
            std::getline(std::cin, datumRodjenja);
            int danRodjenja=stoi(datumRodjenja.substr(0,2));
            int mjesecRodjenja=stoi(datumRodjenja.substr(3,2));
            int godRodjenja=stoi(datumRodjenja.substr(6,4));
            
            std::cout <<"Unesite sifru regije: "<< std::endl;
            int sifraRegije;
            std::cin >> sifraRegije;
            
            std::cout << "Unesite M za musko, Z za zensko: "<< std::endl;
            char spol;
            std::cin>>spol;
            if(spol!='M' && spol!= 'Z') throw std::logic_error("Neispravni podaci");
            GradjaninBiH::Pol p;
            if(spol=='M') p=GradjaninBiH::Musko;
            else  p=GradjaninBiH::Zensko;
            GradjaninBiH g(ime_prezime, danRodjenja, mjesecRodjenja, godRodjenja, sifraRegije, p);
            niz[brojGradjana]=&g; 
            brojGradjana++;
            std::cout <<"Unijeli ste gradjanina " << ime_prezime << " JMBG: " << g.DajJMBG() << "." << std::endl;
        }
        catch(std::logic_error e){
            std::cout << e.what() << std::endl;
            i--;
        }
    }
    
    
	return 0;
}