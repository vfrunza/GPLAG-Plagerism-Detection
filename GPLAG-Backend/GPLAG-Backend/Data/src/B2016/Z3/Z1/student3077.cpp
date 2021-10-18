/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <typeinfo>
class Base{
    public:
    void f(){std::cout<<2<<" ";}
    virtual void g(){std::cout<<7<<" ";}
};

class Derived: public Base{
    public:
    void f(){std::cout<<1<<" ";}
    void g(){std::cout<<3<<" ";}
    virtual void h(){std::cout<<4<<" ";}
};

class Young: public Derived{
    public:
    void h(){std::cout<<9<<" ";}
};

void p(Base x){ x.f(); x.g();}
void q(Base &y){y.f(); y.g();}
int main ()
{
    Base a; Derived b;
    Base *c=new Base; Base *d=new Derived; Derived *e=new Derived;
    p(a);
    q(a);
    std::cout<<std::endl;
    p(b);
    q(b);
    Base *u=new Young;
    std::cout<<std::boolalpha;
    std::cout<<(static_cast<Derived*>(c)==nullptr)<<std::endl;
    std::cout<<(dynamic_cast<Derived*>(e)==nullptr)<<std::endl;
    std::cout<<(static_cast<Derived*>(d)==nullptr)<<std::endl;
    std::cout<<(dynamic_cast<Derived*>(d)==nullptr)<<std::endl;
    std::cout<<(static_cast<Derived*>(u)==nullptr)<<std::endl;
    std::cout<<(dynamic_cast<Derived*>(u)==nullptr)<<std::endl;
    std::cout<<(typeid(*u)==typeid(Base))<<std::endl;
    std::cout<<(typeid(*u)==typeid(Derived))<<std::endl;
    std::cout<<(typeid(*u)==typeid(Young))<<std::endl;
    dynamic_cast<Derived*>(u)->h();
	return 0;
}