/*enum Pol {Musko, Zensko};
GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
 int godina_rodjenja, int sifra_regije, Pol pol);
std::string DajImeIPrezime() const;
long long int DajJMBG() const;
int DajDanRodjenja() const;
int DajMjesecRodjenja() const;
int DajGodinuRodjenja() const;
int DajSifruRegije() const;
Pol DajPol() const;
void PromijeniImeIPrezime(std::string novo_ime);
*/
#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

GradjaninBiH {
    string ime_i_prezime;
    long long int jmbg;
    void ProvjeriDatum(int dan, int mjesec, int godina) {
    int broj dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0)
    broj dana[1]++;
    if(godina < 1 || mjesec < 1 || mjesec > 12 || dan < 1 || dan > broj dana[mjesec – 1])
    throw std::domain_error("JMBG nije validan");
}
    void ProvjeriJMBG(long long int jmbg) {
        long long int temp(jmbg);
        int br(0);
        while(temp!=0) { br++; temp/=10; }¸
        if(br<12 || temp<0) throw logic_error("JMBG nije validan");
        int c12,c34,c567,c89,c101112,c13;
        c12=temp/pow(10,11);
        temp%=pow(10,11);
        c34=temp/pow(10,9);
        temp%=pow(10,9);
        c567=temp/pow(10,6);
        temp%=pow(10,6);
        c89=temp/pow(10,4);
        temp%=pow(10,4);
        c101112=temp/pow(10,1);
        temp%=pow(10,1);
        c13=temp;
        
    }
    
public:
GradjaninBiH(string ime_i_prezime, long long int jmbg) { this->ime_i_prezime=ime_i_prezime; this->jmbg=jmbg; }

GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
 int godina_rodjenja, int sifra_regije, Pol pol) {
        this->ime_i_prezime=ime_i_prezime;
        if(dan_rodjenja<10) jmbg=dan_rodjenja*pow(10,12);
        else jmbg=dan_rodjenja*pow(10,13);
        if(mjesec_rodjenja<10) jmbg+=mjesec_rodjenja*pow(10,10);
        else jmbg+=mjesec_rodjenja*pow(10,11);
        int temp(godina_rodjenja), br(0);
        while(temp!=0) { br++; temp/=10; }
        
 }
};
int main ()
{
	return 0;
}








