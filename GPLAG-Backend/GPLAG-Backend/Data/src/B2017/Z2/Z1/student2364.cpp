/* 
   B16/17 (Tutorijal 13, Zadatak 1)
	Autotestove pisala Ivona Ivkovic. Sva pitanja, sugestije, prijave gresaka
	slati na mail iivkovic2@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>
class Lik {
public:
	virtual ~Lik() {}
	virtual void IspisiSpecificnosti() const = 0;
	virtual double DajObim() const = 0;
	virtual double DajPovrsinu() const = 0;
	void Ispisi() const { IspisiSpecificnosti(); std::cout<<"Obim: "<<DajObim()<<" Povrsina: "<<DajPovrsinu()<<std::endl; }
};
class Krug : public Lik {
	double r;
	static constexpr double PI=4*atan(1.);
public: 
	Krug(double r) { if (r<=0) throw std::domain_error("Neispravni parametri"); Krug::r=r; }
	double DajObim() const override { return 2*r*PI; }
	double DajPovrsinu() const override { return r*r*PI; }
	void IspisiSpecificnosti() const override { std::cout<<"Krug poluprecnika "<<r<<std::endl; }
};
class Pravougaonik : public Lik {
	double a, b;
public:
	Pravougaonik(double a, double b) { if (a<=0 || b<=0) throw std::domain_error("Neispravni parametri"); Pravougaonik::a=a; Pravougaonik::b=b; }
	double DajObim() const override { return 2*a+2*b; }
	double DajPovrsinu() const override { return a*b; }
	void IspisiSpecificnosti() const override { std::cout<<"Pravougaonik sa stranicama duzine "<<a<<" i "<<b<<std::endl; }
};
class Trougao : public Lik {
	double a,b,c;
public:
	Trougao(double x, double y, double z) { if ( x<=0 || y<=0 || z<=0 || x+y<=z || y+z<=x || x+z<=y) throw std::domain_error("Neispravni parametri"); a=x;b=y;c=z; }
	double DajObim() const override { return a+b+c; }
	double DajPovrsinu() const override { 
		double s=(a+b+c)/2;
		return sqrt(s*(s-a)*(s-b)*(s-c)); }
	void IspisiSpecificnosti() const override { std::cout<<"Trougao sa stranicama duzine "<<a<<", "<<b<<" i "<<c<<std::endl; }
};
int main ()
{
	std::cout<<"Koliko zelite likova: ";
	int broj;
	std::cin>>broj;
	std::vector<std::shared_ptr<Lik>> vektor;
	int i(1);
	 for(;;) {
        try {
            std::cout<<"Lik "<<i<<": ";
            char znak;
            std::cin>>znak;
            if(znak=='P')
            {
                double a,b;
                std::cin>>a;
                std::cin>>znak;
                std::cin>>b;
                if(!std::cin || std::cin.peek()!='\n')
                {
                    std::cin.clear();
                    std::cin.ignore(1000,'\n');
                    std::cout<<"Pogresni podaci, ponovite unos!"<<std::endl;
                    continue;
                }
                auto p(std::shared_ptr<Lik>(new Pravougaonik(a,b)));
                vektor.push_back(p);
            }
            else if(znak=='K')
            {
                double r;
                std::cin>>r;
                if(!std::cin || std::cin.peek()!='\n')
                {
                    std::cin.clear();
                    std::cin.ignore(1000,'\n');
                    std::cout<<"Pogresni podaci, ponovite unos!"<<std::endl;
                    continue;
                }
                auto p(std::shared_ptr<Lik>(new Krug(r)));
                vektor.push_back(p);
            }
            else if(znak=='T')
            {
                double a,b,c;
                std::cin>>a;
                std::cin>>znak;
                std::cin>>b;
                std::cin>>znak;
                std::cin>>c;
                if(!std::cin || std::cin.peek()!='\n')
                {
                    std::cin.clear();
                    std::cin.ignore(1000,'\n');
                    std::cout<<"Pogresni podaci, ponovite unos!"<<std::endl;
                    continue;
                }
                auto p(std::shared_ptr<Lik>(new Trougao(a,b,c)));
                vektor.push_back(p);
            }
            else
            {
                std::cin.clear();
                std::cin.ignore(1000,'\n');
                std::cout<<"Pogresni podaci, ponovite unos!"<<std::endl;
                continue;
            }
            if(i==broj) break;
            i++;
        }
        catch(...)
        {
            std::cout<<"Pogresni podaci, ponovite unos!"<<std::endl;
        }
    }
    std::cout<<std::endl;
    std::for_each(vektor.begin(),vektor.end(),[](std::shared_ptr<Lik> p) { p->Ispisi();});
	return 0;
}