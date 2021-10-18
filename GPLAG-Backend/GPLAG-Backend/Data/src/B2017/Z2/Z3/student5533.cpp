#include <iostream>
#include <stdexcept>
#include <vector>
class KutijaApstraktna {
protected:
	double tezina;
	KutijaApstraktna *pok;
public:
    KutijaApstraktna (double tezina): tezina (tezina) {}
    double DajTezinu () const { return tezina; }
    virtual double DajUkupnuTezinu () const=0;
    virtual KutijaApstraktna* DajKopiju() const=0;
    virtual ~KutijaApstraktna() {}
};
class KutijaObicna: public KutijaApstraktna {
	double  tezina_sadrzaja;
public:
    KutijaObicna (double tezina, double tezina_sadrzaja): KutijaApstraktna(tezina), tezina_sadrzaja (tezina_sadrzaja) {}
    double DajUkupnuTezinu () const override { return tezina+tezina_sadrzaja; }
    KutijaApstraktna* DajKopiju () const override { return new KutijaObicna (*this); }
};
class KutijaSaPregradama: public KutijaApstraktna {
	std::vector <double> v;
public:
    KutijaSaPregradama (double tezina, std::vector<double> v1): KutijaApstraktna(tezina), v(v1) {}
    KutijaApstraktna* DajKopiju () const override { return new KutijaSaPregradama (*this); }
    double DajUkupnuTezinu() const override { 
    	double suma(0);
    	for (int i=0; i<v.size(); i++) suma+=v[i];
    	suma+=tezina;
    	return suma;
    }
};
int main ()
{
    /*std::vector <KutijaApstraktna*> v(4);
    for (int i=0;i<v.size();i++) {
        std::cin>> 
    }*/
	return 0;
}