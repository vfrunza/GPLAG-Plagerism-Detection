#include <iostream>
#include <memory>
#include <utility>
#include <cmath>
#include <string>
#include <stdexcept>
#include <iomanip>

class GradjaninBiH{         
    std::string ime;
     long long int JMBG;

long long int spoji(long long int x,int y){
    long long int power(10);
    while(y>=power){
        power*=10;
    }
    return power*x+y;
}


public:
    private GradjaninBiH* prethodni(nullptr);
    static GradjaninBiH *zadnji;
    std::shared_ptr<GradjaninBiH>prethodni,sljedeci;

int DajKod()const{
    int x;
    if(this->DajPol()==Musko)
   return  
}

    enum Pol {Musko,Zensko};              
    GradjaninBiH(std::string ime_i_prezime,long long int jmbg){
        try{
        int niz[13];long long int *pok(jmbg);
    for(int (0);i<13;i++){
        niz[i]=*pok;
        pok++;      
    }
    niz[12]=11-(7*(niz[0]+niz[7])+6*(niz[1]+niz[7])+5*(niz[2]+niz[8])+4*(niz[3]+niz[8])+3*(niz[4]+niz[10])+2*(niz[5]+niz[11]))%11;
        if(niz[12]==11) niz[12]=0;
        if(niz[12]==10||)
            throw std::logic_error("JMBG nije validan.");          
        }     
        JMBG=jmbg;
        ime=ime_i_prezime;
        catch(std::logic_error &e){                                         
            throw;                                       
        }
    }
    
    GradjaninBiH(std::string ime_i_prezime,int dan_rodjenja,int mjesec_rodjenja,int godina_rodjenja,int sifra_regije,Pol pol){
        try{
        int brojdana[12]{31, 28, 31,30, 31, 30, 31, 31, 30, 31, 30, 31};
if(godina_rodjenja %4 == 0 &&godina_rodjenja %100 != 0 || godina_rodjenja %400 == 0) brojdana[1]++;
if(godina_rodjenja < 1 || dan_rodjenja < 1 || mjesec_rodjenja < 1 || mjesec_rodjenja> 12 || dan_rodjenja > brojdana[mjesec_rodjenja –1]);
if(sifra_regije<0&&sifra_regije>99)   throw std::logic_error("Neispravni podaci!");

int kod(0), niz[6]{dan_rodjenja,mjesec_rodjenja,godina_rodjenja,sifra_regije,kod,},i(0); 
        prethodni=zadnji;
        zadnji=this;
        auto p=zadnji;
        while(p!=nullptr){
            if((prethodni->DajDanRodjenja()==zadnji->DajDanRodjenja())&&(prethodni->DajPol()==zadnji->Pol)&&)
            p=p->zadnji
        }
std::string s; 
 while(i<=6){
     s+=std::to_string(niz[i]);
     i++;
 }
 JMBG=std::stoll(s);
 trinaesti= 11-(7*(dan_rodjenja/10+godina_rodjenja%10)+6*(dan_rodjenja%10+sifra_regije/10)+5*(mjesec_rodjenja/10+sifra_regije%10)+4*(mjesec_rodjenja%10+kod/10)+3*(godina_rodjenja/10+(kod/10)%10)+2
 *((godina_rodjenja/10)%10+kod%100))%11;               
        }       
                         
        catch(std::logic_error &e){              
            throw;
        }                                                                                                                         
                         
    }
    ~GradjaninBiH(){
        this=nullptr;
    }
    std::string DajImeIPrezime() const{
                           
    }
    long long int DajJMBG() const{
        return JMBG;
    }
    int DajDanRodjenja() const {
    return 
    }
    int DajMjesecRodjenja() const{
        return JMBG;
    }
    int DajGodinuRodjenja() const{
        return ;
    }
    int DajSifruRegije() const{
        return ;
    }
    Pol DajPol() const{
        Pol x(Musko);
       if()
        return x;
    }
    void PromijeniImeIPrezime(std::string novo_ime){
         ime=novo_ime;
    }
    
};

int main ()
{
    try{

    std::cout<<"Koliko gradjana zelite unijeti: "<<std::endl; int q;
    std::cin>>q; GradjaninBiH **niz=new GradjaninBiH*[q];
    for(int i(0);i<q;i++){
    std::cout<<"Unesite ime gradjanina: "; std::string s;
    std::getline(std::cin,s);
      std::cout<<"Unesite jmbg gradjanina: "; long long int ID;
      std::cin>>ID;
        niz[i]=new GradjaninBiH(s,ID);
            
            }
    }
    catch(std::logic_error e){
        std::cout<<e.what();
    }
	return 0;
}