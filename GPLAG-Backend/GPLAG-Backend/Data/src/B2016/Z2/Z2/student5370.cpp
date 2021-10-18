#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <type_traits>

#define E 0.00001

int BrojDjelioca(int n);
bool SavrsenBroj(int n);

template <typename Ona>
    int* Izdvajanje (Ona p1, Ona &p2,int &n){
        n=0; //Neophodno je da imamo ovo na 0
        Ona p{p1}; //ovdje ćemo pisati template
        while(p!=p2)
            if(SavrsenBroj(int(*p++)))
                n++;
        int *pok{nullptr};
        try{
            if(n>0)
            pok=new int[n];
        }
        catch(...){
            delete pok;
            throw std::domain_error("Nedovoljno memorije!");
        }
        int *t{pok};
        p=p1;
        while(p!=p2){
            if(SavrsenBroj(int(*p)))
                *pok++=int(*p);
            p++;
        }
        
        Ona m{p1};
        //imamo pokazivace TIP p,p1,p2  i int pok
        while(p1!=p2){
            int mjerilo{BrojDjelioca(int(*p1))};
            p=p2-1;
            bool brisi{false};
            while(p!=p1){
                if(mjerilo==BrojDjelioca(int(*p))){
                    brisi=true;
                    auto z=p;
                    while(z++!=p2);
                    z-=2;
                    *p=*z;
                    p2--;
                }
                p--;
            }
            if(brisi){
                *p1=*(p2-1);
                p2--;p1--;
            }
            p1++;
        }
        
        std::sort(m,p2,[](typename std::remove_reference <decltype (*m)>::type x,typename std::remove_reference <decltype (*p2)>::type y)->bool{int a=x,b=y,t{0};for(int i=a;i>=1;i--)if(a%i==0)t+=i;int t1{0};for(int i=b;i>=1;i--)if(b%i==0)t1+=i;if(t==t1) return a>b;return t<t1;});
        
        return t; //ovo se ne dira!
    }  
   

int main() {
    int n;
    std::vector<float> v;
    std::cout<<"Unesite brojeve: ";
    for(;;){
        float t{-1};
        std::cin>>t;
        if(std::abs(t+1)<E)
            break;
        v.push_back(t);
    }
    float *t=&v[0]+v.size();
    float *s=&v[0];
    try{
        auto p=Izdvajanje(s,t,n);
        std::cout<<"Modificirani kontejner: ";
        while(s!=t-1 && s!=t)         //ovdje ce ispisati modificirane
            std::cout<<*s++<<", ";
        if(s!=t)
            std::cout<<*s;
        std::cout<<"\nSavrseni brojevi: ";
        auto r=p;
        int i{0};
        for(i=0;i<n-1;i++)
            std::cout<<*p++<<" ";
        if(n!=0)
            std::cout<<*p;
        delete[] r;
    }
    catch(std::domain_error tekst){
        std::cout<<tekst.what();
    }
    return 0;
}

bool SavrsenBroj(int n){
    int t{0};
    for(int i=n-1;i>=1;i--)
        if(n%i==0)
            t+=i;
    if(n<=0)
        return false;
    if(n==t)
        return true;
    return false;
}

int BrojDjelioca(int n){
    int t{0};
    if(n<0)
        n*=-1;
    for(int i=n;i>=1;i--)
        if(n%i==0)
            t++;
    return t;
}