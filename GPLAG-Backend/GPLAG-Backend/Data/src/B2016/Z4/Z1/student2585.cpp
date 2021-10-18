/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
using std:: cout;
using std:: cin;
using std:: endl;
using std:: pair;

typedef std:: pair<double, double> Tacka;

class Trougao{
    Tacka t1, Tacka t2, Tacka t3;
    public:
        Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3);
        void Postavi (const Tacka &t1, const Tacka &t2, const Tacka &t3);
        void Postavi (int indeks, const Tacka &t1);
        static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3);
        Tacka DajTjeme(int indeks) const;
        Tacka DajCentar()const;
        
};
int main ()
{
	return 0;
}