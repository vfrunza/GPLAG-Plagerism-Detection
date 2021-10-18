#include <iostream>
#include <stdexcept>
 enum Pol {Musko, Zensko} ;
class GradjaninBiH{
    std::string i_i_p;
   
     long long int broj;
     
      Pol Polo;
        
     GradjaninBiH* veza;
      
      
        int dan,mjesec,godina,regija;
        void Provjeri(long long int bra){
        long long int br=bra;
        int a=(br/1000000000000)%10;
        int b=(br/100000000000)%10;
        int c=(br/10000000000)%10;
        int dd=(br/1000000000)%10;
        int e=(br/100000000)%10;
        int f=(br/10000000)%10;
        int gg=(br/1000000)%10;
        int ee=(br/100000)%10;
        int jj=(br/10000)%10;
        int mm=br%10;
        int g=e*100+f*10+gg+1000;
        int m=c*10+dd;
        int d=a*10+b;
        int r=ee*10+jj;
        int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
        if((g%4==0 && g%100!=0 ) || g%400==0 ) broj_dana[1]++;
    if(g<1 || d<1 || m<1 || m>12 || d>broj_dana[m-1] || mm==10) {throw std::logic_error("JMBG nije validan");}
        broj=bra; dan=d; mjesec=m; godina=g; regija=r;
    }
       

 
    void Postavi2(int d,int m,int g,int sifrareg,Pol pol){
        int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
        if((g%4==0 && g%100!=0 ) || g%400==0) broj_dana[1]++;
    if(g<1 || d<1 || m<1 || m>12 || d>broj_dana[m-1] || (sifrareg<0 || sifrareg>99)) throw std::logic_error("Neispravni podaci");
        dan=d; mjesec=m; godina=g; regija=sifrareg; Polo=pol;
       
    }
 
        
    
    public:
    
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg) { Provjeri(jmbg); i_i_p=ime_i_prezime;}
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,int godina_rodjenja, int sifra_regije, Pol pol){
        i_i_p=ime_i_prezime;  Postavi2(dan_rodjenja,mjesec_rodjenja,godina_rodjenja,sifra_regije,pol); 
    }
    
    std::string DajImeIPrezime() const{ return i_i_p;}
    long long int DajJMBG() const { return broj;}
     long long int DajDanRodjenja() const { return dan;}
    int DajMjesecRodjenja() const {return mjesec;}
    int DajGodinuRodjenja() const {return godina;}
    int DajSifruRegije() const {return regija;}
    Pol DajPol() const{ return Polo;}
    void PromijeniImeIPrezime(std::string novo_ime){ i_i_p=novo_ime; }
};

int main ()
{
    try{
    GradjaninBiH g("Emir Jusic",18,10,1996,102,Pol::Zensko);
    g.PromijeniImeIPrezime("Sandra Afrika");
    std::cout<<g.DajJMBG();
    }
    catch(std::logic_error e){
        std::cout<<e.what();
    }
	return 0;
}