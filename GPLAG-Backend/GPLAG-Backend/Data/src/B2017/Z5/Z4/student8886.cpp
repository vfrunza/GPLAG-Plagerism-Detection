/B2017/2018: Zadaća 5, Zadatak 4
#include <iostream>
#include <cmath>
#include <stdexcept>
static constexpr double PI=(4*atan(1));
class FourierovRed{
    double T;
    int N;
    double f(int);
    double g(int);
    double *koef_a;
    double *koef_b;
    public:
    FourierovRed(double T, std::initializer_list<double> lista_koef_a, std::initializer_list<double> lista_koef_b){
        if(lista_koef_a.size() > lista_koef_b.size()) N=lista_koef_a.size();
        if(lista_koef_a.size() < lista_koef_b.size()) N=lista_koef_b.size();
        koef_a = new double[N];
        koef_b = new double[N];
        int i=0;
        for(auto it=std::begin(lista_koef_a); it!=std::end(lista_koef_a); it++){
            koef_a[i++] = *it;
        }
        i=0;
        for(auto it=std::begin(lista_koef_b); it!=std::end(lista_koef_b); it++){
            koef_a[i++] = *it;
        }
    }
    FourierovRed(int N, double T, double f(int x), double g(int y)):T(T){
        if(N < 0) throw std::domain_error("Stepen mora biti pozitivan");
        FourierovRed::N=N;
        //FourierovRed::f=f(int x);
    }
};
int main ()
{
    FourierovRed red(10, 2 * PI, [](int k){ return 2*PI;}, [](int k){ return 0.1;} ); 
	return 0;
}
