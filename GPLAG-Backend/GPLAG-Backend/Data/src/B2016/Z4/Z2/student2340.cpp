/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <cmath>
#include <utility>
#include <stdexcept>
#include <memory>
#include <algorithm>
#include <vector>
#include <string>

class GradjaninBiH{
    std::string _ime_i_prezime;
    long long int _jmbg;
    int _dan_rodjenja, _mjesec_rodjenja,_godina_rodjenja,_sifra_regije;
    int _pol;
    GradjaninBiH* prethodni;
    
    int DajKodPola (){
        return (_jmbg/10)%1000;
    }
    
    bool IspravnostDatuma(int d, int m, int g){
        int broj_dana[]{31,28,31,30,31,30,31,31,30,31,30,31};
        if((g%4==0 && g%100!=0) || g%400==0) broj_dana[1]++;
        if(g<1 || m<1 || m>12 || d<1 || d>broj_dana[m-1]) return false;
        return true;
    }
    
    bool IspravnostJMBG(long long int jmbg){
        int jmbg_niz[13]={0};
        if(jmbg/100000000000==0) return false;
        if(!IspravnostDatuma(DajDanRodjenja(),DajMjesecRodjenja(),DajGodinuRodjenja())) return false;
        if(DajDanRodjenja()<10){
            jmbg_niz[0]=0;
            jmbg_niz[1]=DajDanRodjenja();
        } else{
            jmbg_niz[0]=DajDanRodjenja()/10;
            jmbg_niz[1]=DajDanRodjenja()%10;
        }
        if(DajMjesecRodjenja()<10){
            jmbg_niz[2]=0;
            jmbg_niz[3]=DajMjesecRodjenja();
        } else {
            jmbg_niz[2]=DajMjesecRodjenja()/10;
            jmbg_niz[3]=DajMjesecRodjenja()%10;
        }
        if(DajGodinuRodjenja()>=2000){
            jmbg_niz[4]=0;
            jmbg_niz[5]=(DajGodinuRodjenja()/10)%10;
            jmbg_niz[6]=DajGodinuRodjenja()%10;
        }else {
            jmbg_niz[4]=(DajGodinuRodjenja()/100)%10;
            jmbg_niz[5]=(DajGodinuRodjenja()/10)%10;
            jmbg_niz[6]=DajGodinuRodjenja()%10;
        }
        jmbg_niz[7]=(jmbg/100000)%10;
        jmbg_niz[8]=(jmbg/10000)%10;
        jmbg_niz[9]=(jmbg/1000)%10;
        jmbg_niz[10]=(jmbg/100)%10;
        jmbg_niz[11]=(jmbg/10)%10;
        jmbg_niz[12]=jmbg%10;
        
        int c13=11-(7*(jmbg_niz[0]+jmbg_niz[6])+
                    6*(jmbg_niz[1]+jmbg_niz[7])+
                    5*(jmbg_niz[2]+jmbg_niz[8])+
                    4*(jmbg_niz[3]+jmbg_niz[9])+
                    3*(jmbg_niz[4]+jmbg_niz[10])+
                    2*(jmbg_niz[5]+jmbg_niz[11]))%11;
                    
        if(c13==10) return false;
        
        return true;
    }
    
    public:
        enum Pol {Musko, Zensko};
        static GradjaninBiH* posljednjiKreirani;
        GradjaninBiH(std::string ime_i_prezime, long long int jmbg) : _ime_i_prezime(ime_i_prezime), _jmbg(jmbg){
            if(IspravnostJMBG(jmbg)==false) throw std::logic_error("JMBG nije validan");
            int temp(0);
            
            temp=(_jmbg/100000000000)%100;
            _dan_rodjenja=temp;
            temp=(_jmbg/1000000000)%100;
            _mjesec_rodjenja=temp;
            temp=(_jmbg/1000000)%1000+1000;
            _godina_rodjenja=temp;
            if(temp<1900) _godina_rodjenja=temp+1000;
            temp=_jmbg/10000;
            _sifra_regije=temp%100;
            
            int zaPol = (_jmbg/10)%1000;
            if(zaPol<500) _pol=Pol::Musko;
            else _pol=Pol::Zensko;
            
            if(posljednjiKreirani==nullptr) {
                prethodni=nullptr;
                posljednjiKreirani=this;
            }
            else {
                prethodni=posljednjiKreirani;
                posljednjiKreirani=this;
            }
            
            GradjaninBiH* tempG=posljednjiKreirani->prethodni;
            while(tempG!=nullptr){
                if(tempG->DajJMBG()==jmbg) throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
                tempG=tempG->prethodni;
            }
        }
        
        
        GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
        int godina_rodjenja, int sifra_regije, Pol pol) : _ime_i_prezime(ime_i_prezime),_dan_rodjenja(dan_rodjenja),
                                                        _mjesec_rodjenja(mjesec_rodjenja), _godina_rodjenja(godina_rodjenja),
                                                        _sifra_regije(sifra_regije),_pol(pol){
            if(IspravnostDatuma(dan_rodjenja,mjesec_rodjenja,godina_rodjenja)==false) throw std::logic_error("Neispravni podaci");
            _jmbg=0;
            _jmbg=10000000000*dan_rodjenja;
            _jmbg+=100000000*mjesec_rodjenja;
            
            _jmbg+=100000*(godina_rodjenja-1000);
            int max_muskarac(-1);
            int max_zena(499);
            
            //std::cout << dan_rodjenja << mjesec_rodjenja << godina_rodjenja;
            
            if(posljednjiKreirani==nullptr) {
                prethodni=nullptr;
                posljednjiKreirani=this;
            }
            else {
                prethodni=posljednjiKreirani;
                posljednjiKreirani=this;
            }
            
            GradjaninBiH* tempG=posljednjiKreirani->prethodni;
            while(tempG!=nullptr){
                if(tempG->DajDanRodjenja()==dan_rodjenja && tempG->DajMjesecRodjenja()==mjesec_rodjenja &&
                   tempG->DajGodinuRodjenja()==godina_rodjenja && tempG->DajSifruRegije()==sifra_regije){
                       if(tempG->DajKodPola()>max_muskarac)
                        max_muskarac=tempG->DajKodPola();
                        if(tempG->DajKodPola()>max_zena)
                        max_zena=tempG->DajKodPola();
                   }
                
                tempG=tempG->prethodni;
            }
            
        
            _jmbg+=sifra_regije*1000;
            _jmbg*=10;
            if(_pol==Pol::Musko) _jmbg+=max_muskarac*1+1;
            else _jmbg+=(max_zena+1)*10;
            
        int jmbg_niz[13]={0};
        if(dan_rodjenja<10){
            jmbg_niz[0]=0;
            jmbg_niz[1]=dan_rodjenja;
        } else{
            jmbg_niz[0]=dan_rodjenja/10;
            jmbg_niz[1]=dan_rodjenja%10;
        }
        if(mjesec_rodjenja<10){
            jmbg_niz[2]=0;
            jmbg_niz[3]=mjesec_rodjenja;
        } else {
            jmbg_niz[2]=mjesec_rodjenja/10;
            jmbg_niz[3]=mjesec_rodjenja%10;
        
        }
        if(godina_rodjenja>=2000){
            jmbg_niz[4]=0;
            jmbg_niz[5]=(godina_rodjenja/10)%10;
            jmbg_niz[6]=godina_rodjenja%10;
        }else {
            jmbg_niz[4]=(godina_rodjenja/100)%10;
            jmbg_niz[5]=(godina_rodjenja/10)%10;
            jmbg_niz[6]=godina_rodjenja%10;
        }
        jmbg_niz[7]=(_jmbg/100000)%10;
        jmbg_niz[8]=(_jmbg/10000)%10;
        jmbg_niz[9]=(_jmbg/1000)%10;
        jmbg_niz[10]=(_jmbg/100)%10;
        jmbg_niz[11]=(_jmbg/10)%10;
        jmbg_niz[12]=_jmbg%10;
        
        int c13=11-(7*(jmbg_niz[0]+jmbg_niz[6])+
                    6*(jmbg_niz[1]+jmbg_niz[7])+
                    5*(jmbg_niz[2]+jmbg_niz[8])+
                    4*(jmbg_niz[3]+jmbg_niz[9])+
                    3*(jmbg_niz[4]+jmbg_niz[10])+
                    2*(jmbg_niz[5]+jmbg_niz[11]))%11;
                    
        if(c13==10) throw std::logic_error("JMBG nije validan");
        if(c13==11) c13=0;
        
        if(!IspravnostJMBG(_jmbg)) throw std::logic_error("JMBG nije validan");
        _jmbg+=c13;
        
        tempG=posljednjiKreirani->prethodni;
        while(tempG!=nullptr){
            if(tempG->DajJMBG()==_jmbg)
             throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
            tempG=tempG->prethodni;
        }
            
    }
    
    ~GradjaninBiH(){
        if(prethodni!=nullptr){
            posljednjiKreirani=prethodni;
            prethodni=prethodni->prethodni;
        }
        else{ posljednjiKreirani=nullptr;
        }
    }
        std::string DajImeIPrezime() const{
            return _ime_i_prezime;
        }
        long long int DajJMBG() const{
            return _jmbg;
        }
        int DajDanRodjenja() const{
            int temp(0);
            temp=(_jmbg/100000000000)%100;
            return temp;
        }
        GradjaninBiH* DajPrethodni() const{
            return prethodni;
        }
        
        int DajMjesecRodjenja() const{
            int temp(0);
            temp=(_jmbg/1000000000)%100;
            return temp;
        }
        int DajGodinuRodjenja() const{
            int temp(0);
            temp=(_jmbg/1000000)%1000+1000;
            if(temp<1900) temp+=1000;
            return temp;
        }
        int DajSifruRegije() const{
            int temp(0);
            temp=_jmbg/10000;
            return temp%100;
        }
        Pol DajPol() const{
            return Pol(_pol);
        }
        void PromijeniImeIPrezime(std::string novo_ime){
            _ime_i_prezime=novo_ime;
        }

};

GradjaninBiH* GradjaninBiH::posljednjiKreirani=nullptr;
int main ()
{       std::string ime_i_prezime,_ime_i_prezime;
        long long int JMBG;
        int dd,mm,gggg,sifra_regije,m,n;
        //enum Pol{M,Z};
        char a(0);
    
    std::cout<<"Koliko gradjana zelite unijeti po JMBG? ";
    std::cin>>n;
    std::cout<<std::endl;
    for(int i=0; i<n; i++){

        std::cin.ignore(100000,'\n');
        std::cout<<"Unesite ime i prezime (u istom redu): ";
        std::getline(std::cin,ime_i_prezime);
        
        std::cout<<"\nUnesite JMBG: ";
        
        
        std::cin>>JMBG;
        
        try{
        GradjaninBiH g (ime_i_prezime,JMBG);
        std::cout<<"\nUnijeli ste gradjanina "<<g.DajImeIPrezime()<<" rodjenog "<<g.DajDanRodjenja()<<"."
                <<g.DajMjesecRodjenja()<<"."<<g.DajGodinuRodjenja()<<" u regiji "
                <<g.DajSifruRegije()<<", ";
                     if(g.DajPol()==1) std::cout<<"zensko.";
                     else std::cout<<"musko.";
        }catch(std::logic_error e){
             std::cout<<std::endl<<e.what();
             i--;
        }
        std::cout<<std::endl;
    }
    std::cout<<"Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? ";
    std::cin>>m;
    std::cout<<std::endl;
    for(int i=0; i<m; i++){

        std::cin.ignore(10000,'\n');
        std::cout<<"Unesite ime i prezime (u istom redu): ";
        std::getline(std::cin, ime_i_prezime);
        std::cout<<"\nUnesite datum rodjenja (format dd/mm/gggg): ";
        char t(0);
        std::cin>>dd>>t>>mm>>t>>gggg;
        std::cout<<"\nUnesite sifru regije: ";
        std::cin>>sifra_regije;
        std::cout<<"\nUnesite M za musko, Z za zensko: ";
        std::cin>>a;
        try{
        if(a=='M') {
            GradjaninBiH g (ime_i_prezime,dd,mm,gggg,sifra_regije,GradjaninBiH::Pol::Musko);
            std::cout<<"\nUnijeli ste gradjanina "<<g.DajImeIPrezime()<<" JMBG: "<<g.DajJMBG() << ".";
        }
        
        else if(a=='Z') {
        
            GradjaninBiH g (ime_i_prezime,dd,mm,gggg,sifra_regije,GradjaninBiH::Pol::Zensko);
            std::cout<<"\nUnijeli ste gradjanina "<<g.DajImeIPrezime()<<" JMBG: "<<g.DajJMBG() << ".";
        }
        else throw std::domain_error("Neispravni podaci");
        }catch(std::logic_error &e){
             std::cout<<std::endl<<e.what();
             i--;
        }
        catch (std::domain_error &e) {
            std::cout << std::endl<<e.what();
            i--;
        }
        //std::cout<<""
        std::cout<<std::endl;
    }

	return 0;
}