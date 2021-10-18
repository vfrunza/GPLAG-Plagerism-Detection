/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
enum Pol {Musko, Zensko};
class GradjaninBiH{
    std::string ime_i_prezime;
    long long int jmbg;
    int dan_rodjenja;
    int mjesec_rodjenja;
    int godina_rodjenja;
    int sifra_regije;
    Pol pol;
    public:
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg) { 
        GradjaninBiH::ime_i_prezime=ime_i_prezime; 
        GradjaninBiH::jmbg=jmbg; 
        long long int pomoc{jmbg};
        int br{0};
        while(pomoc != 0){
            br++;
            pomoc=pomoc / 10;
        }
        if(br<12 || br>13)throw std::logic_error("JMBG nije validan");
        pomoc=jmbg;
        int kontrolna, kod;
        for(int i{br}; i>0; i--){
            if(i==br) {
                kontrolna=pomoc%10;
                pomoc/=10;
            }
            else if(i==br-1){
                kod=pomoc%1000;
                if(kod < 500) GradjaninBiH::pol=Pol::Musko;
                else GradjaninBiH::pol=Pol::Zensko;
                pomoc=pomoc/1000;
            }
            else if(i==br-4){
                GradjaninBiH::sifra_regije=pomoc%100;
                pomoc=pomoc/100;
            }
            else if(i==br-6){
                GradjaninBiH::godina_rodjenja=pomoc%1000;
                if(GradjaninBiH::godina_rodjenja>17)GradjaninBiH::godina_rodjenja+=1000;
                else GradjaninBiH::godina_rodjenja+=2000;
                pomoc=pomoc/1000;
            }
            else if(i==br-9){
                GradjaninBiH::mjesec_rodjenja=pomoc%100;
                pomoc=pomoc/100;
            }
            else if(i==br-11){
                GradjaninBiH::dan_rodjenja=pomoc%100;
                pomoc=pomoc/100;
            }
        }
    }
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol) {
        if(dan_rodjenja>31 || dan_rodjenja<0 || mjesec_rodjenja > 12 || mjesec_rodjenja<0 || godina_rodjenja>2017 || godina_rodjenja<1917 || sifra_regije<0 || sifra_regije>99)
           throw std::logic_error("Neispravni podaci");
        int c1{dan_rodjenja}, c2{dan_rodjenja};
        if(c1>=10) {
            c1=c1/10;
            c2=c2%10;
        }
        else c1=0;
        int kontrolna{ 11 - (7*(c1 + godina_rodjenja%10) + 6*(c2 + sifra_regije/10) + 5*(mjesec_rodjenja/10 + sifra_regije%10) + 4*(mjesec_rodjenja%10 )) };
        GradjaninBiH::jmbg=(((dan_rodjenja*100+mjesec_rodjenja)*1000+godina_rodjenja)*100+sifra_regije)*10000;
        if(pol==Pol::Zensko) GradjaninBiH::jmbg+=5000;
    }
    std::string DajImeIPrezime() const { return GradjaninBiH::ime_i_prezime; }
    long long int DajJMBG() const { return GradjaninBiH::jmbg; }
    int DajDanRodjenja() const { return GradjaninBiH::dan_rodjenja; }
    int DajMjesecRodjenja() const { return GradjaninBiH::mjesec_rodjenja; }
    int DajGodinuRodjenja() const { return GradjaninBiH::godina_rodjenja; }
    int DajSifruRegije() const { return GradjaninBiH::sifra_regije; }
    Pol DajPol() const { return GradjaninBiH::pol; }
    void PromijeniImeIPrezime(std::string novo_ime) { GradjaninBiH::ime_i_prezime=novo_ime; }
};

int main ()
{
	return 0;
}