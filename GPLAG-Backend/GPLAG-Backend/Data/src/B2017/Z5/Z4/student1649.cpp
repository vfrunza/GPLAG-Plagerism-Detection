/B2017/2018: Zadaća 5, Zadatak 4
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <functional>
#include <list>
#include <cmath>
#include <initializer_list>
using namespace std;

double  PI = 4*atan(1);

class FourierovRed{
    double T;
    int N;
    double *koef_a, *koef_b;
public:
    FourierovRed(int br, double t, double fun1(int), double fun2(int)){
        if(br<=0) throw domain_error("Stepen mora biti pozitivan");
        N=br+1; T=t;
        koef_a=new double[N]; 
        koef_b= new double[N]; 
        koef_b[0]=0;
        for(int i=0; i<N; i++) koef_a[i]=fun1(i);
        for(int i=1; i<N; i++) koef_b[i]=fun2(i);
    }
    ~FourierovRed() { delete [] koef_a; delete [] koef_b;}
    FourierovRed(double t, initializer_list<double> lista1, initializer_list<double>lista2)
    {
        list<double> l1=lista1;
        list<double> l2; l2.push_back(0);
        for(auto it=lista2.begin(); it!=lista2.end(); it++) l2.push_back(*it);
        while(l1.size()<l2.size()) l1.push_back(0);
        while(l2.size()<l1.size()) l2.push_back(0);
        koef_a=new double[l1.size()];
        N=l2.size()+1; 
        koef_b=new double [l2.size()];
        int i=0;
        for(auto it=l1.begin(), it1=l2.begin(); it!=l1.end(); it++, it1++){ koef_a[i]=*it; koef_b[i]=*it1; i++;}
    }
    FourierovRed(int br, double p, double q, double f(double), int M){
        if(M<=0) throw domain_error("Broj podintervala mora biti pozitivan");
        if(br<0) throw domain_error("Stepen mora biti pozitivan");
        if(p>=q) throw range_error("Neispravan interval");
        T=q-p; N=br+1;
        koef_a=new double[N];
        koef_b=new double[N];
         koef_b[0]=0;
        for(int i=0; i<N; i++)
        {
            double prvi=((f(p)+f(q))/M)*cos((2*i*PI*p)/T);
            double suma=0;
            for(int j=1; j<=M-1; j++)
               {
                   suma+=(f(p+(j*T)/M)*cos(2*j*PI*((p/T)+(j/M))));
               }
            koef_a[i]=prvi+(2/M)*suma;
            
             double prvi1=((f(p)+f(q))/M)*sin((2*(i+1)*PI*p)/T);
            double suma1=0;
            for(int j=1; j<=M-1; j++)
                {
                    suma1+=f(p+(j*T)/2)*sin(2*j*PI*((p/T)+(j/M)));
                }
            koef_b[i]=prvi1+(2/M)*suma1;
        
        }
    }
    pair<double &,double &> operator [] (int ind){
        if(ind<0 || ind>=N-1) throw range_error("Neispravan indeks");
        pair<double&,double&> p(koef_a[ind],koef_b[ind]);
        return p;
    }
    FourierovRed(const FourierovRed &f){
        N=f.N; T=f.T; 
        koef_a = new double [f.N+1];
        koef_b = new double [f.N+1];
        for(int i=0; i<N; i++) { koef_a[i]=(f.koef_a[i]); }
        for(int i=0; i<N; i++) { koef_b[i]=(f.koef_b[i]); }
    }    
    FourierovRed &operator = (FourierovRed &f)
    {
        delete [] koef_a; delete [] koef_b;
        N=f.N; T=f.T;
        koef_a = new double [N];
        koef_b = new double [N];
        for(int i=0; i<N; i++) { koef_a[i]=(f.koef_a[i]); }
        for(int i=0; i<N; i++) { koef_b[i]=(f.koef_b[i]); }
        return *this;

    }
    pair<double,double> operator [] (int ind) const{
        if(ind<0 || ind>=N-1) throw range_error("Neispravan indeks");
        pair<double,double> p=make_pair(koef_a[ind],koef_b[ind]);
        return p;
    }
    FourierovRed(FourierovRed &&f)
    {
        N=f.N; T=f.T; koef_a=f.koef_a; koef_b=f.koef_b;
        f.N=0; f.T=0; f.koef_a=nullptr; f.koef_b=nullptr;
    }
    double operator ()(double x){
        double prvia=(koef_a[0])/2;
        double sumaa=0;
        for(int i=1; i<N; i++)
            sumaa+=((koef_a[i]*cos((2*i*PI*x)/T)) + (koef_b[i]*sin((2*i*PI*x)/T)));
        return prvia + sumaa;

    }
    FourierovRed &operator = (FourierovRed &&f)
    {
        if(this==&f) return *this;
        delete [] koef_a; delete [] koef_b;
        N=f.N; T=f.T; koef_a=f.koef_a; koef_b=f.koef_b;
        f.N=0; f.T=0; f.koef_a=nullptr; f.koef_b=nullptr;
        return *this;
    }
    
};

int main ()
{
    
   
	return 0;
}
