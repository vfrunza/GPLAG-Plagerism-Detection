/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
class GradjaninBiH{
    int jmbg_c[13];
    void convert_to_date(long long int n,int &dan,int &mjesec, int &godina){
        n/=1000000000;
        godina=1000+n%1000;
        n/=1000;
        mjesec=n%100;
        n/=100;
        dan=n;
    }
    bool cifra13(long long int n)
    {
        int c[13];
        //pretvaramo u cifre
        for(int i=0;i<13;i++)
        {
            c[12-i]=n%10;
            n/=10;
        }
    }
    bool ValidanJMBG(long long int jmbg){
    //komplikovanije neg sto sa mislio lol
        int dan,mjesec,godina;
        convert_to_date(jmbg,dan,mjesec,godina);
        int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
        if(godina%4==0 && godina%100!=0 || godina%400==0)broj_dana[2]++;
        if(godina<1 || dan<1 || dan>broj_dana[mjesec-1] || mjesec>12 || mjesec<1)return false;
        return true;
    }
    public:
    enum Pol{Musko,Zensko};
    GradjaninBiH(std::string ime_i_prezime,long long int jmbg);
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
}
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime,long long int jmbg)
{
    //prvo u funkciji testirati ispravnost
    if(!ValidanJMBG(jmbg))throw std::logic_error("JMBG nije validan");
    for(int i=12;i>=0;i--)
    {
        jmbg_c[i]=jmbg%10;
        jmbg/=10;
    }
}
int main ()
{
	return 0;
}