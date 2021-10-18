/B2017/2018: Zadaća 5, Zadatak 4
#include <iostream>
#include <functional>
#include <cmath>

class FourierovRed{
    double *a;
    double *b;
    double T;
    int vel;
    public:
    FourierovRed(double period,const std::initializer_list<double> &l1,const std::initializer_list<double> &l2);
    FourierovRed(int stepen,double period,std::function<double(int)> f1,std::function<double(int)> f2);
    ~FourierovRed();
    void Ispisi(){
        std::cout << "a_k: ";
        for(int i(0); i<vel ;i++){
            std::cout << a[i] << " ";
        }
        std::cout << std::endl << "b_k: ";
        for(int i(0); i<vel ;i++){
            std::cout << b[i] << " ";
        }
    }
};

FourierovRed::FourierovRed(int stepen,double period,std::function<double(int)> f1,std::function<double(int)> f2){
    if(stepen<0) throw std::domain_error("Stepen mora biti pozitivan");
    a=nullptr;
    b=nullptr;
    vel=stepen+1;
    a=new double[vel];
    b=new double[vel];
    for(int i(0);i<vel;i++) { a[i]=0; b[i]=0; }
    for(int k(0);k<vel;k++) { a[k]=f1(k);}
    for(int k(1);k<vel;k++) { b[k]=f2(k);}
    
}


FourierovRed::FourierovRed(double period,const std::initializer_list<double> &l1,const std::initializer_list<double> &l2){
    a=nullptr;
    b=nullptr;
    int velicina(0);
    if(l1.size()>l2.size()+1) { velicina=l1.size(); }
    else { velicina=l2.size()+1; }
    a=new double[velicina];
    b=new double[velicina];
    for(int i(0);i<velicina;i++) { a[i]=0; b[i]=0; }
    auto it1(l1.begin());
    auto it2(l2.begin());
    int i(0);
    while(it1!=l1.end()){
        a[i]=*it1;
        it1++;
        i++;
    }
    i=1;
    while(it2!=l2.end()){
        b[i]=*it2;
        it2++;
        i++;
    }
    T=period; vel=velicina;
}

FourierovRed::~FourierovRed(){
    delete[] a;
    delete[] b;
}

int main ()
{
    try {
    const double PI=4*atan(1);
    FourierovRed red(3,{1,2,3},{4,5,6,7});
    red.Ispisi();
    FourierovRed f(10, 2 * PI,[](int k) { return k == 0 ? 1 : 1./k;},[](int k) { return 0; });
    std::cout << std::endl;
    f.Ispisi();
    }
    catch(std::domain_error iz){
        std::cout << iz.what();
    }
    catch(std::range_error iz){
        std::cout << iz.what();
    }
    return 0;
}
