/* 
   B16/17 (Tutorijal 12, Zadatak 1)
	Autotestove napisao Kerim Hodzic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: khodzic2@etf.unsa.ba.
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <iomanip>


class Sat {
    int sat,minut,sekunda;
    static bool DaLiJeIspravno (int sat, int minut, int sekunda) {
        if ((sat<0 || sat>23) || (minut>59 || minut<0) || (sekunda<0 || sekunda>59))
            return false;
        return true;
    }
    public:
    Sat () : sat(0), minut(0), sekunda(0)	{};
    Sat (int h, int m, int s) : sat(0), minut(0), sekunda(0) {
        Sat temp(PostaviNormalizirano(h,m,s));
        sat=temp.sat;
        minut=temp.minut;
        sekunda=temp.sekunda;
    } 
    double DajSate() const { return sat; }
    double DajMinute() const { return minut; }
    double DajSekunde() const { return sekunda; }
    Sat PostaviNormalizirano (int sati, int minute, int sekunde);
    friend int BrojSekundiIzmedju (Sat v1, Sat v2);
    friend Sat operator ++ (Sat &vrijeme, int);
    friend Sat& operator ++ (Sat &vrijeme);
    friend Sat operator  -- (Sat &vrijeme, int);
    friend Sat& operator -- (Sat &vrijeme);
    friend Sat& operator -= (Sat &vrijeme, int x);
    friend Sat& operator += (Sat &vrijeme, int x);
    friend Sat operator - (const Sat& vrijeme, int x);
    friend Sat operator + (const Sat& vrijeme, int x);
    friend int operator - (const Sat& vrijeme, const Sat& vrijeme2);
    friend int operator + (const Sat& vrijeme, const Sat& vrijeme2);
    friend std::ostream& operator << (std::ostream &stream, const Sat &vrijeme);
    void Postavi(int sati, int minute, int sekunde); 
    int Razmak (const Sat &v1, const Sat &v2);
};

int Sat::Razmak (const Sat &v1, const Sat &v2) {
        int vrijeme1(0), vrijeme2(0);
    	vrijeme1=v1.DajSate()*3600+v1.DajMinute()*60+v1.DajSekunde();
    	vrijeme2=v2.DajSate()*3600+v2.DajMinute()*60+v2.DajSekunde();
    	return (vrijeme1-vrijeme2);
}

void Sat::Postavi (int sati, int minute, int sekunde) {
    if (!DaLiJeIspravno(sati,minute,sekunde)) 
            throw std::domain_error ("Neispravno vrijeme");
        Sat::sat = sati; 
        Sat::minut = minute; 
        Sat::sekunda = sekunde; 
}

int operator + (const Sat& vrijeme, const Sat& vrijeme2) {
    Sat temp;
    temp.sat=vrijeme.sat+vrijeme2.sat;
    temp.minut=vrijeme.minut+vrijeme2.minut; 
    temp.sekunda=vrijeme.sat+vrijeme2.sekunda;
    temp.PostaviNormalizirano(temp.sat,temp.minut,temp.sekunda);
    int sekunde (temp.sat*3600+temp.minut*60+temp.sekunda);
    return sekunde;
} 

int operator - (const Sat& vrijeme, const Sat& vrijeme2) {
    Sat temp;
    temp.sat=vrijeme.sat-vrijeme2.sat;
    temp.minut=vrijeme.minut-vrijeme2.minut;
    temp.sekunda=vrijeme.sekunda-vrijeme2.sekunda;
    temp.PostaviNormalizirano(temp.sat,temp.minut,temp.sekunda);
    int sekunde (temp.sat*3600+temp.minut*60+temp.sekunda);
    return sekunde;
}

Sat operator + (const Sat& vrijeme, int x) {
    Sat temp;
    temp.sat=vrijeme.sat;
    temp.minut=vrijeme.minut;
    temp.sekunda=vrijeme.sekunda;
    temp.sekunda+=x;
    temp.PostaviNormalizirano(temp.sat,temp.minut,temp.sekunda);
    return temp;
}

Sat operator - (const Sat& vrijeme, int x) {
    Sat temp;
    temp.sat=vrijeme.sat;
    temp.minut=vrijeme.minut;
    temp.sekunda=vrijeme.sekunda;
    temp.sekunda-=x;
    temp.PostaviNormalizirano(temp.sat,temp.minut,temp.sekunda);
    return temp;
}

Sat operator ++ (Sat &vrijeme, int) {
	Sat temp(vrijeme.sat, vrijeme.minut, vrijeme.sekunda);
	++vrijeme;
	return temp;
}

Sat &operator ++ (Sat &vrijeme) {
	if (++vrijeme.sekunda==60) { vrijeme.minut++;  vrijeme.sekunda=0;}
	if (vrijeme.minut==60) { vrijeme.sat++; vrijeme.minut=0; }
	if (vrijeme.sat==24) vrijeme.sat=0;
	return vrijeme;
}

Sat operator -- (Sat &vrijeme, int) {
	Sat temp (vrijeme.sat, vrijeme.minut, vrijeme.sekunda);
	--vrijeme;
	return temp;
}

Sat &operator -- (Sat &vrijeme) {
	if (--vrijeme.sekunda<0) { vrijeme.sekunda=59; vrijeme.minut--; }
	if (vrijeme.minut<0) { vrijeme.minut=59; vrijeme.sat--; }
	if (vrijeme.sat<0) { vrijeme.sat=23;}
	return vrijeme;
}

Sat &operator += (Sat &vrijeme, int x) {
    vrijeme.sekunda+=x;
    vrijeme.PostaviNormalizirano(vrijeme.sat, vrijeme.minut, vrijeme.sekunda);
    return vrijeme;    
}

Sat &operator -= (Sat &vrijeme, int x) {
    vrijeme.sekunda-=x;
    vrijeme.PostaviNormalizirano(vrijeme.sat, vrijeme.minut, vrijeme.sekunda);
    return vrijeme;    
}

std::ostream &operator << (std::ostream &stream, const Sat &vrijeme) {
        stream << std::setfill('0') << std::setw(2) << vrijeme.sat << ":" << std::setfill('0') << std::setw(2) <<  
            vrijeme.minut  << ":" << std::setfill('0') << std::setw(2) << vrijeme.sekunda;  
    return stream;
}
    
Sat Sat::PostaviNormalizirano (int sati, int minute, int sekunde) {
            int  ss=sati*3600+minute*60+sekunde;
            
            while (ss>=24*3600) 
                ss-=24*3600;
            sat=ss/3600;
            minut=(ss-(sat*3600))/60;
            sekunda=(ss-(sat*3600)) - (minut*60);
            return *this;
}


int main ()
{
	return 0;
}