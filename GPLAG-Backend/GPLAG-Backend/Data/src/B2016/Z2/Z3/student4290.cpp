#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <string>
#include <iomanip>
#include <cmath>
bool JeLiProst(int n){
    n=std::abs(n);
    for(int i=2;i<n;i++)if(n%i==0)return false;
    return true;
}
template<typename T1,typename T2>
bool imal(T1 p1,T1 p2,T2 n){
    while(p1!=p2){
        if(*p1==n)return true;
        p1++;
    }
    return false;
}
template<typename T1,typename T2,typename T3>
bool ImalPoFunkciji(T1 p1,T1 p2,T2 n,T2 fun(T3)){
    while(p1!=p2){
        if(fun(*p1)==fun(n))return true;
        p1++;
    }
    return false;
}
template<typename T1,typename T2,typename T3>
std::vector<std::vector<T3>> UvrnutiPresjek(T1 p1,T1 p2,T2 p3,T2 p4){
    std::vector<std::vector<T3>> mat;
    for(auto i=p1;p1!=p2;p1++){
        for(auto j=p3;p3!=p4;p3++){
            if(*i==*j)mat.push_back({*i,0,0});
        }
    }
    std::sort(mat.begin(),mat.end(),[](std::vector<T3> a,std::vector<T3> b){
        return(a[0]<b[0]);
    });
    return mat;
}
template <typename T1,typename T2,typename T3,typename T4>
std::vector<std::vector<T3>> UvrnutiPresjek(T1 p1,T1 p2,T2 p3,T2 p4,T3 fun(T4)){
    std::vector<std::vector<T3>> mat;
    for(auto i=p1;i!=p2;i++){
        for(auto j=p3;j!=p4;j++){
            if(fun(*i)==fun(*j))mat.push_back({*i,*j,fun(*i)});
        }
    }
    std::sort(mat.begin(),mat.end(),[](std::vector<T3> a,std::vector<T3> b){
        return((a[2]<b[2])||(a[2]==b[2] && a[0]<b[0])||(a[2]==b[2] && a[0]==b[0] && a[1]<b[1]));
        
    });
    return mat;
    
}
template <typename T1,typename T2,typename T3,typename T4>
std::vector<std::vector<T3>> UvrnutaRazlika(T1 p1,T1 p2,T2 p3,T2 p4,T3 fun(T4)){
    std::vector<std::vector<T3>> mat;
    while(p1!=p2){
        if(ImalPoFunkciji(p3,p4,*p1,fun)==false)mat.push_back({*p1,fun(*p1)});
        p1++;
    }
    std::sort(mat.begin(),mat.end(),[](std::vector<T3> a,std::vector<T3> b){
        return((a[1]>b[1])||(a[1]==b[1] && a[0]>b[0]));
    });
    return mat;
}
int SumaCifara(long long int n){
    int suma(0);
    n=std::abs(n);
    while(n!=0){
        suma+=n%10;
        n/=10;
    }
    return suma;
}
int SumaDjelilaca(long long int n){
    int suma(0);
    if(JeLiProst(n))return n+1;
    for(auto i=1;i<=n;i++){
        if(n%i==0)suma+=i;
    }
    return suma;
}
int BrojProstihFaktora(long long int n){
    if(JeLiProst(n))return 1;
    int suma(0);
    for(auto i=2;i<n/i;i++){
        if(n%i==0){
            suma++;
            while(n>1 && n%i==0){
                suma++;
                n=n/i;
            }
        }
    }
    return suma;
}
int BrojSavrsenihDjelilaca(long long int n){
    int br(0);
    for(auto i=2;i<=n;i++){
        if((n%i==0)&&(SumaDjelilaca(i)==2*i))br++;
    }
    return br;
}
int main(){
    std::cout<<"Unesite broj elemenata prvog kontejnera: ";
    int n;
    std::cin>>n;
    std::deque<int> d;
    std::cout<<"Unesite elemente prvog kontejnera: ";
    int i(0);
    while(i<n){
        int a;
        std::cin>>a;
        if(imal(d.begin(),d.end(),a)==false){
            d.push_back(a);
            i++;
        }
    }
    std::cout<<"Unesite broje elemenata drugog kontejnera: ";
    std::cin>>n;
    std::deque<int> v;
    std::cout<<"Unesite elemente drugog kontejnera: ";
    i=0;
    while(i<n){
        int a;
        std::cin>>a;
        if(imal(v.begin(),v.end(),a)==false){
            v.push_back(a);
            i++;
        }
    }
    std::vector<std::vector<int>> mat1=UvrnutiPresjek(d.begin(),d.end(),v.begin(),v.end(),SumaCifara);

    std::vector<std::vector<int>> mat2=UvrnutaRazlika(d.begin(),d.end(),v.begin(),v.end(),BrojProstihFaktora);
    std::cout<<"Uvrnuti presjek kontejnera:"<<std::endl;
    for(int i=0;i<mat1.size();i++){
        for(int j=0;j<mat1[i].size();j++)std::cout<<std::setw(6)<<mat1[i][j]<<" ";
        std::cout<<std::endl;
    }
    std::cout<<"Uvrnuta razlika kontejnera:"<<std::endl;
    for(int i=0;i<mat2.size();i++){
        for(int j=0;j<mat2[i].size();j++)std::cout<<std::setw(6)<<mat2[i][j];
        std::cout<<std::endl;
    }
    std::cout<<"Dovidjenja!";
}