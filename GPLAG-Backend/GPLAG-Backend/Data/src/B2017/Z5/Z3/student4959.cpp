/B2017/2018: Zadaća 5, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <cstring>
#include <vector>
const  std::vector<char*> ImenaDana{"Ponedjeljak","Utorak","Srijeda",
                                        "Cetvrtak","Petak","Subota","Nedjelja"};
const  std::vector<char*> ImenaMjeseci{"Januar","Februar","Mart","April","Maj","Juni","Juli",
                                           "August","Septembar","Oktobar","Novembar","Decembar"};
class Datum{
    
    int d,m,g;
    char *ime_mjeseca;
    char *ime_dana;
    
    public:
    
    enum Mjeseci {Januar = 1, Februar, Mart, April, Maj, Juni, Juli, August,
        Septembar, Oktobar, Novembar, Decembar};
    enum Dani {Ponedjeljak = 1, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja};


    Datum(int dan, Mjeseci mjesec,int god){
        Postavi(dan,mjesec,god);
    }
    Datum(int dan,int mjesec, int god){
        Postavi(dan,mjesec,god);
    }
    void Postavi(int dan, Mjeseci mjesec,int god){
        int dani[12]{31,28,31,30,31,30,31,31,30,31,30,31};
        if((god % 4 == 0 && god % 100 != 0) || god % 400 == 0) dani[1]++;
        if(god<1800 || dan<0 || dan> dani[int(mjesec)-1])
            throw std::domain_error("Nelegalan datum");
        d = dan; m = int(mjesec); g = god;
        std::strcpy(ime_mjeseca,ImenaMjeseci[m-1]);
        
    }
    void Postavi(int dan, int mjesec, int god){
        int dani[12]{31,28,31,30,31,30,31,31,30,31,30,31};
        if((god % 4 == 0 && god % 100 != 0) || god % 400 == 0) dani[1]++;
        if(god<1800 || dan<0 || dan> dani[mjesec-1] || mjesec<0 || mjesec>12)
            throw std::domain_error("Nelegalan datum");
        d = dan; m = mjesec; g = god;
        std::strcpy(ime_mjeseca,ImenaMjeseci[m-1]);
        std::strcpy(ime_dana,ImenaDana[int(DanUSedmici())]);
    }
    
    int DajDan() const { return d; }
    Mjeseci DajMjesec() const { return Mjeseci(m); }
    int DajGodinu() const { return g; }
    Dani DanUSedmici() const { return Dani(CalculateTheDay(*this)+1);}
    
    char *DajImeMjeseca(){ return ime_mjeseca; }
    char *DajImeDanaUSedmici(){ return ime_dana; }
    
    
    
    friend int CalculateTheDay(Datum d){
        int MCode[]{0,3,3,6,1,4,6,2,5,0,3,5};
        int yc = (d.g+(d.g%4))%7;
        int mc = MCode[d.m - 1];
        int cc;
        if(d.g >= 1800 && d.g < 1900) cc = 2;
        else if(d.g >= 1900 && d.g < 2000) cc = 0;
        else if(d.g >= 2000 && d.g < 2100) cc = 6;
        else if(d.g >= 2100 && d.g < 2200) cc = 4;
        int prestupna(0);
        if((d.g % 4 == 0 && d.g % 100 != 0) || d.g % 400 == 0)prestupna=1;
        int sum((yc + mc + cc + d.d - prestupna)%7);
        sum = (sum+4)%7;
        if(sum == 0)return 6;
        else return sum-1;
    }
    
};
int main ()
{
	return 0;
}
