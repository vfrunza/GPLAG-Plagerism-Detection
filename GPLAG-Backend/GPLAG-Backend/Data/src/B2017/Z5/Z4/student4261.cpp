/B2017/2018: Zadaća 5, Zadatak 4
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <utility>
#include <functional>

#include <iomanip>


const double pi=4*atan(1);


class FourierovRed {
    int n;
    double T;
    double** A=nullptr;
    double** B=nullptr;
  public:
  
    ~FourierovRed() {
        if (A!=nullptr) {
            for (int i=0; i<n; i++) { delete A[i]; A[i]=nullptr; }
            delete[] A; A=nullptr;
        }
        if (B!=nullptr) {
            for (int i=0; i<n; i++) { delete B[i]; B[i]=nullptr; }
            delete[] B; B=nullptr;
        }
    }  
  
    FourierovRed (double T, std::initializer_list<double> a, std::initializer_list<double> b) {
        int veci(0);
        if (a.size()>=b.size()) veci=a.size();
        else veci=b.size()+1;
        n=veci;
        FourierovRed::T=T;
        
        try {
            A=new double*[n]{};
            B=new double*[n]{};
            
            auto it1(a.begin());
            auto it2(b.begin());
            
            for (int i=0; i<n; i++) {
                
                if (it1!=a.end()) { A[i]=new double(*it1); it1++; }
                else A[i]=new double(0);
                
                if (i==0) { B[i]=new double(0); }
                else if (it2!=b.end()) { B[i]=new double(*it2); it2++; }
                else B[i]=new double(0);
            }
        }
        catch(...) {
            if (A!=nullptr) for (int i=0; i<n; i++) { delete A[i]; A[i]=nullptr; }
            delete[] A; A=nullptr;
            if (B!=nullptr) for (int i=0; i<n; i++) { delete B[i]; B[i]=nullptr; }
            delete[] B; B=nullptr;
        }
    }
    
    FourierovRed (int n, double T, double f1 (int), double f2(int)) {
        if (n<=0) throw std::domain_error("Stepen mora biti pozitivan");
        FourierovRed::n=n+1; 
        FourierovRed::T=T;
        
        try {
            A=new double*[n+1]{};
            B=new double*[n+1]{};
            
            for (int i=0; i<n+1; i++) {
                A[i]=new double(f1(i));
                if (i==0) B[i]=new double(0);
                else B[i]=new double(f2(i));
            }
        }
        catch(...) {
            if (A!=nullptr) for (int i=0; i<=n; i++) { delete A[i]; A[i]=nullptr; }
            delete[] A; A=nullptr;
            if (B!=nullptr) for (int i=0; i<=n; i++) { delete B[i]; B[i]=nullptr; }
            delete[] B; B=nullptr;
        }
        
    }
    
    FourierovRed (int n, double p, double q, double f(double), int M) {
        if (n<=0) throw std::domain_error("Stepen mora biti pozitivan");
        if (M<=0) throw std::domain_error("Broj podintervala mora biti pozitivan");
        if (!(p<q)) throw std::range_error("Neispravan interval");
        
        FourierovRed::n=n+1;
        T=q-p;
        
        try {
            A=new double*[n+1]{};
            B=new double*[n+1]{};
            
            for (int i=0; i<n+1; i++) {
                
                double suma1(0), suma2(0);
                
                for (int j=1; j<=M-1; j++) {
                    suma1+=f(p+j*T/M)*std::cos(2*i*pi*((p/T)+double(j)/M));
                    suma2+=f(p+j*T/M)*std::sin(2*i*pi*((p/T)+double(j)/M));
                }
                A[i]=new double(((f(p)+f(q))/M)*std::cos(2*i*pi*p/T)+(2./M)*suma1);
                if (i==0) B[i]=new double(0);
                else B[i]=new double(((f(p)+f(q))/M)*std::sin(2*i*pi*p/T)+(2./M)*suma2);
            }
        }
        catch(...) {
            if (A!=nullptr) for (int i=0; i<n+1; i++) { delete A[i]; A[i]=nullptr; }
            delete[] A; A=nullptr;
            if (B!=nullptr) for (int i=0; i<n+1; i++) { delete B[i]; B[i]=nullptr; }
            delete[] B; B=nullptr;
        }
    }
    
    FourierovRed &operator =(const FourierovRed &red) { 
        if (&red!=this) {
            if (A!=nullptr) for (int i=0; i<n; i++) { delete A[i]; A[i]=nullptr; }
            delete[] A; A=nullptr;
            if (B!=nullptr) for (int i=0; i<n; i++) { delete B[i]; B[i]=nullptr; }
            delete[] B; B=nullptr;
            
            n=red.n;
            T=red.T;
            
            try {
                A=new double*[n]{};
                B=new double*[n]{};
                
                for (int i=0; i<n; i++) {
                    A[i]=new double(*(red.A[i]));
                    B[i]=new double(*(red.B[i]));
                }
            }
            catch(...) {
                if (A!=nullptr) for (int i=0; i<n; i++) { delete A[i]; A[i]=nullptr; }
                delete[] A; A=nullptr;
                if (B!=nullptr) for (int i=0; i<n; i++) { delete B[i]; B[i]=nullptr; }
                delete[] B; B=nullptr;
            }
            
        }
        return *this;
    }
  
    FourierovRed &operator =(FourierovRed &&red) { 
        if (&red!=this) {
            if (A!=nullptr) for (int i=0; i<n; i++) { delete A[i]; A[i]=nullptr; }
            delete[] A; A=nullptr;
            if (B!=nullptr) for (int i=0; i<n; i++) { delete B[i]; B[i]=nullptr; }
            delete[] B; B=nullptr;
            
            n=red.n;
            T=red.T;
            
            A=red.A;
            B=red.B;
            
            red.A=nullptr; red.B=nullptr;
        }
        return *this;
    }
  
    FourierovRed(const FourierovRed &red) {
        
        n=red.n;
        T=red.T;
        
        try {
            A=new double*[n]{};
            B=new double*[n]{};
            
            for (int i=0; i<n; i++) {
                A[i]=new double(*(red.A[i]));
                B[i]=new double(*(red.B[i]));
            }
        }
        catch(...) {
            if (A!=nullptr) for (int i=0; i<n; i++) { delete A[i]; A[i]=nullptr; }
            delete[] A; A=nullptr;
            if (B!=nullptr) for (int i=0; i<n; i++) { delete B[i]; B[i]=nullptr; }
            delete[] B; B=nullptr;
        }
    }
    
    FourierovRed(FourierovRed &&red) {
        n=red.n;
        T=red.T;
        
        A=red.A;
        B=red.B;
        
        red.A=nullptr; red.B=nullptr;
    }
    
    
    double operator() (double x) const {
        double vrijednost(*A[0]/2);
        for (int i=1; i<n; i++) {
            vrijednost+=((*A[i])*std::cos(2*i*pi*x/T)+(*B[i])*std::sin(2*i*pi*x/T));
        }
        return vrijednost;
    }
    
    std::pair<double, double> operator[] (int k) const {
        if (k<0 || k>=n) throw std::range_error("Neispravan indeks");
        return std::make_pair(*A[k], *B[k]);
    }
    
    std::pair<double &, double &> operator[] (int k) {
        if (k<0 || k>=n) throw std::range_error("Neispravan indeks");
        return std::make_pair(std::ref(*(A[k])), std::ref(*(B[k])));
    }
};


int main ()
{
   
	return 0;
}
