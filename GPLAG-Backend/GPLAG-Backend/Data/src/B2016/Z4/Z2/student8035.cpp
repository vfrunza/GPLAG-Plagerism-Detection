/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <deque>
#include <stdexcept>


class GradjaninBiH{
    Drzava d;
    std::string ImeIprezime;
    long long int JMBG;
    public:
    enum Pol{musko,zensko};
    GradjaninBiH(std::string ime_i_prezime,long long int jmbg)
    {
       int cifra;
       long long int temp=jmbg;
        std::deque<int>d;
        while(temp!=0)
        {
            cifra=temp%10;
            d.push_front(cifra);
            temp/=10;
        }
        
        int c13;
        c13=11-(7*(d[0]+d[6])+6*(d[1]+d[7])+5*(d[2]+d[8])+4*(d[3]+d[9])+3*(d[4]+d[10])+2*(d[5]+d[11]))%11;
        if(c13==11) c13=10;
        if(c13==10) throw std::logic_error("JMBG nije validan");

        ImeIprezime=ime_i_prezime;
        JMBG=jmbg;
    }
   GradjaninBiH(std::string ime_i_prezime,int dan_rodjenja,int mjesec_rodjenja,int godina rodjena,int sifra regije,Pol pol)
{
    
    
}
  };
    
    
int main ()
{
    try{
        GradjaninBiH g("Ahmo Ahmic",3407993178897);
        
    }
    catch(std::logic_error e)
    {
        std::cout << e.what() << std::endl;
    }
	return 0;
}