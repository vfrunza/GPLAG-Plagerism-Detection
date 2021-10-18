/B2017/2018: Zadaća 5, Zadatak 5
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <utility>
#include <functional>
#include <vector>


const double pi=4*atan(1);


class FourierovRed {
    int n;
    double T;
    std::vector<double> A;
    std::vector<double> B;
  public:
  
    FourierovRed (double T, std::initializer_list<double> a, std::initializer_list<double> b) {
        int veci(0);
        if (a.size()>=b.size()) veci=a.size();
        else veci=b.size()+1;
        n=veci;
        FourierovRed::T=T;
        
        try {
            A.resize(n);
            B.resize(n);
            
            auto it1(a.begin());
            auto it2(b.begin());
            
            for (int i=0; i<n; i++) {
                
                if (it1!=a.end()) { A.at(i)=(*it1); it1++; }
                else A.at(i)=0;
                
                if (i==0) B.at(i)=0;
                else if (it2!=b.end()) { B.at(i)=(*it2); it2++; }
                else B.at(i)=0;
            }
        }
        catch(...) {
            throw;
        }
    }
    
    FourierovRed (int n, double T, double f1 (int), double f2(int)) {
        if (n<=0) throw std::domain_error("Stepen mora biti pozitivan");
        FourierovRed::n=n+1; 
        FourierovRed::T=T;
        
        try {
            A.resize(n+1);
            B.resize(n+1);
            
            for (int i=0; i<n+1; i++) {
                A.at(i)=f1(i);
                if (i==0) B.at(i)=0;
                else B.at(i)=f2(i);
            }
        }
        catch(...) {
            throw;
        }
        
    }
    
    FourierovRed (int n, double p, double q, double f(double), int M) {
        if (n<=0) throw std::domain_error("Stepen mora biti pozitivan");
        if (M<=0) throw std::domain_error("Broj podintervala mora biti pozitivan");
        if (!(p<q)) throw std::range_error("Neispravan interval");
        
        FourierovRed::n=n+1;
        T=q-p;
        
        try {
            A.resize(n+1);
            B.resize(n+1);
            
            for (int i=0; i<n+1; i++) {
                
                double suma1(0), suma2(0);
                
                for (int j=1; j<=M-1; j++) {
                    suma1+=f(p+j*T/M)*std::cos(2*i*pi*(p/T+double(j)/M));
                    suma2+=f(p+j*T/M)*std::sin(2*i*pi*(p/T+double(j)/M));
                }
                A.at(i)=(((f(p)+f(q))/M)*std::cos(2*i*pi*p/T)+(2./M)*suma1);
                B.at(i)=(((f(p)+f(q))/M)*std::sin(2*i*pi*p/T)+(2./M)*suma2);
            }
        }
        catch(...) {
            
        }
    }
    
    FourierovRed &operator =(const FourierovRed &red) { 
        if (&red!=this) {
            A.resize(0);
            B.resize(0);
            
            n=red.n;
            T=red.T;
            
            try {
                A.resize(n);
                B.resize(n);
                
                for (int i=0; i<n; i++) {
                    A.at(i)=(red.A.at(i));
                    B.at(i)=(red.B.at(i));
                }
            }
            catch(...) {
                throw;
            }
            
        }
        return *this;
    }
  
    FourierovRed &operator =(FourierovRed &&red) { 
        if (&red!=this) {
            A.resize(0);
            B.resize(0);
            
            n=red.n;
            T=red.T;
            
            A=red.A;
            B=red.B;
            
            red.A.resize(0);
            red.B.resize(0);
        }
        return *this;
    }
  
    FourierovRed(const FourierovRed &red) {
        
        n=red.n;
        T=red.T;
        
        try {
            A.resize(n);
            B.resize(n);
            
            for (int i=0; i<n; i++) {
                A.at(i)=red.A.at(i);
                B.at(i)=red.B.at(i);
            }
        }
        catch(...) {
            throw;
        }
    }
    
    FourierovRed(FourierovRed &&red) {
        n=red.n;
        T=red.T;
        
        A=red.A;
        B=red.B;
        
        red.A.resize(0); red.B.resize(0);
    }
    
    
    double operator() (double x) const {
        double vrijednost(A.at(0)/2);
        for (int i=1; i<n; i++) {
            vrijednost+=((A.at(i)*std::cos(2*i*pi*x/T))+(B.at(i)*std::sin(2*i*pi*x/T)));
        }
        return vrijednost;
    }
    
    std::pair<double, double> operator[] (int k) const {
        if (k<0 || k>=n) throw std::range_error("Neispravan indeks");
        return std::make_pair(A.at(k), B.at(k));
    }
    
    std::pair<double &, double &> operator[] (int k) {
        if (k<0 || k>=n) throw std::range_error("Neispravan indeks");
        return std::make_pair(std::ref(A.at(k)), std::ref(B.at(k)));
    }
};


int main ()
{
	return 0;
}
