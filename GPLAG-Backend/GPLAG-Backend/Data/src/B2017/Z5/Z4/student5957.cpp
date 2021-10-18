/B2017/2018: Zadaća 5, Zadatak 4
#include <iostream>
#include <vector>
#include <cmath>
#include <initializer_list>
#include <functional>
#include <stdexcept>
using std::vector;
using std::cout;
using std::cin;
const double PI=4*std::atan(1);

class FurierovRed{
    int a1,b1;
    double T,N;
    double *a;
    double *b;
    public:
    FurierovRed(double period,std::initializer_list<double> l1,std::initializer_list<double> l2);
    FurierovRed(int N,double period,std::function<double(int)>f1,std::function<double(int)>f2);
};
FurierovRed::FurierovRed(double period,std::initializer_list<double> l1,std::initializer_list<double> l2)
    :T(period),a1(l1.size()),b1(l2.size()){
        if(l1.size()==l2.size()){
            a=new double[l1.size()+1]{}; a1++;
            b=new double[l2.size()]{};
            auto it1(l1.begin()),it2(l2.begin());
            for(int i(0);i<a1;i++){
                a[i]=*it1;
                if(i>0){
                    b[i-1]=*it2;
                    it2++;
                }
                it1++;
            }
        }
        else if(l1.size()>l2.size()){
            N=l1.size()-1;
            b1=a1-1;
            a=new double[l1.size()]{};
            b=new double[l2.size()]{};
            auto it1(l1.begin()),it2(l2.begin());
            for(int i(0);i<a1;i++){
                a[i]=*it1;
                if(i>0){
                    b[i-1]=*it2;
                    it2++;
                }
                it1++;
            }
        }
        else{
            N=l2.size();
            a=b+1;
        }
        a=new double[l1.size()]{};
            b=new double[l2.size()]{};
            auto it1(l1.begin()),it2(l2.begin());
            for(int i(0);i<a1;i++){
                a[i]=*it1;
                if(i>0){
                    b[i-1]=*it2;
                    it2++;
                }
                it1++;
            }
    /*    for(auto x:a) cout<<x<<"  ";
        cout<<"\n   ";
        for(auto x:b) cout<<x<<"  ";*/
}
FurierovRed::FurierovRed(int N,double period,std::function<double(int)>f1,std::function<double(int)>f2){
    if(N<0) throw std::domain_error("Stepen mora biti pozitivan");
    T=period; FurierovRed::N=N;
    for(int i(0);i<N;i++){
  //      a.push_back(f1(i));
    //    if(i>0) b.push_back(f2(i));
    }
}

int main ()
{
    
    FurierovRed f(1,{3,3},{4,4});
    
	return 0;
}
