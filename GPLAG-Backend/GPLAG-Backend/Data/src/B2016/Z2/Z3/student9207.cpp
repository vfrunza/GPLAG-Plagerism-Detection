//B 16/17, Zadaća 2, Zadatak 3
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <deque>
int sumacifara(long long int n) {
    int suma(0);
    while(n!=0) {
        suma+=n%10;
        n/=10;
    }
    return suma;
}
int SumaDjelilaca(long long int n){
    int suma(0);
    for(int i=1;i<=n;i++) if(n%i==0) suma+=i;
    
    return suma;
}

int BrojProstihFaktora(long long int n){
    int br(0);
    int i=2;
    while(n!=1){
        if(n%i==0){
            br++;
            n=n/i;
        }
        else i++;
    }
    return br;
}
bool savrsen(long long int n){
   int suma(0);
    for(int i=1;i<n;i++) if(n%i==0) suma+=i;
    return (n==suma);
}

int BrojSavrsenihDjelilaca(long long int n){
    int br(0);
    for(long long int i=1;i<n;i++) if(n%i==0 && savrsen(i)) br++;
    
    return br;
}
typedef std::vector<std::vector<int>> Matrica;

template <typename tip1,typename tip2,typename tipfun,typename tip >
Matrica UvrnutiPresjek(tip1 poc1 ,tip1 kraj1 ,tip2 poc2, tip2 kraj2, tipfun f(tip ) )  {                         
    Matrica m;
    auto k2(poc2);
    auto k1(poc1);
    int i(0);
    while(k1!=kraj1  && k2!=kraj2) {
        if(f(*k2)==f(*k1)) {

            m.resize(int(m.size())+1);
            for(  ; i<m.size() && k2!=kraj2 &&k1!=kraj1 ; ) {
                m[i].resize(3);
                m[i][0]=*k1;
                m[i][1]=*k2;
                m[i][2]=f(*k2);

                i++;

            }

        }

        k2++;

        if(k2==kraj2 ) {
            k2=poc2;
            k1++;
            if(k1==kraj1) break;

        }
    }
    std::sort(m.begin(),m.end());

std::sort(m.begin(),m.end(),[](const std::vector<int>&a,const std::vector<int> &b){return a[2]<b[2];});

    return m;
}
template<typename tipa,typename tipb>
Matrica UvrnutiPresjek(tipa poc1,tipa kraj1,tipb poc2,tipb kraj2){
   Matrica m;
    auto  kopija2(poc2);
    auto kopija1(poc1);
    int i(0);
    while(kopija1!=kraj1 && kopija2!=kraj2) {
        if((*kopija2) == (*kopija1)) {
            m.resize(int(m.size())+1);

            for(; i<m.size() && kopija2!=kraj2;) {

                m[i].resize(3);
                m[i][0]=*kopija1;
                m[i][1]=0;
                m[i][2]=0;

                i++;
            }

        }
        kopija2++;
        if(kopija2==kraj2) {
            kopija2=poc2;
            kopija1++;
            if(kopija1==kraj1) break;

        }
    }

    return m;
}

template<typename itertip1,typename itertip2,typename tipfun,typename tip>
Matrica UvrnutaRazlika(itertip1 poc1,itertip1 kraj1,itertip2 poc2,itertip2 kraj2,tipfun f (tip)){
    Matrica m;
    std::vector<int>v;
    std::vector<int >d;
              
   for(auto p1(poc1);p1!=kraj1;p1++){
       
      bool  bio(false);
      for(auto p2(poc2);p2!=kraj2;p2++){
      if(f(*p1)==f(*p2)){
              bio=true;
              break;
          }
      }  

      if(!bio){
          v.push_back(*p1);
          d.push_back(f(*p1));
      }
      
   }
   
   
   
   for(auto p2(poc2);p2!=kraj2;p2++){
       bool bio(false);
       for(auto p1(poc1);p1!=kraj1;p1++){
           if(f(*p2)==f(*p1)){
               bio=true;
               break;
               
           }
       }
       if(!bio){
           v.push_back(*p2);
           d.push_back(f(*p2));
       }
       
   }
  
  m.resize(int(m.size())+int(v.size()));
  for(int i=0;i<m.size();i++){
      m[i].resize(2);
      for(int j=0;j<=i;j++) m[i][0]=v[j];
     for(int p=0;p<=i;p++)  m[i][1]=d[p];
      
      
  }
  
std::sort(m.begin(),m.end(),[](const std::vector<int>&a,const std::vector<int>&b){return a[0]>b[0];});

   return m;

 }

template <typename tip1,typename tip2>
Matrica UvrnutaRazlika (tip1 poc1,tip1 kraj1,tip2 poc2,tip2 kraj2) {
std::vector<int>v;
    Matrica m;
    for(auto p1(poc1);p1!=kraj1;p1++) {
        
        bool bio(false);
        for(auto p2(poc2);p2!=kraj2;p2++){
            
      if(*(p1)==*(p2)){
          bio=true; break; 
          
      }
        }
        auto kopija1(p1);
        
      if(!bio){
            v.push_back(*kopija1);
            }
            
    }
    
    for(auto p2(poc2);p2!=kraj2;p2++){
        bool bio (false);
        
        for(auto p1(poc1);p1!=kraj1;p1++){
            if(*p2==*p1){
                bio=true;
                break;
            }
        }
        
        if(!bio){
            v.push_back(*p2);
        }
    }

m.resize(int(m.size())+int(v.size()));
for(int i=0;i<m.size();i++){
    m[i].resize(2);
    for(int j=0;j<=i;j++) m[i][0]=v[j];
    m[i][1]=0;
}
   
   std::sort(m.begin(),m.end(),[](const std::vector<int>&a,const std::vector<int>&b){return a[0]>b[0] ;});
    return m;

}


int main () {

    int br1;
    std::cout<<"Unesite broj elemenata prvog kontejnera: ";
    std::cin>>br1;
    std::deque<long long int>a ;
    std::cout<<"Unesite elemente prvog kontejnera: ";
    int brr;
    std::cin>>brr;
    a.push_back(brr);
    while(a.size()!=br1){
        int br;
        bool bio(false);
        std::cin>>br;
        for(int i=0;i<a.size();i++) 
        for(int j=0;j<a.size();j++) if(a[j]==br ) bio=true;
        
       if(!bio) a.push_back(br); 
        
    }

    int br2;
   std::cout<<"Unesite broj elemenata drugog kontejnera: ";
    std::cin>>br2;
    std::deque<long long int>b;
    std::cout<<"Unesite elemente drugog kontejnera: ";
   int br22;
   std::cin>>br22;
   b.push_back(br22);
   while(b.size()!=br2){
       int br;
       bool bio (false);
       std::cin>>br;
       for(int i=0;i<b.size();i++)
       for(int j=0;j<b.size();j++) if(b[j]==br) bio=true;
       
       if(!bio) b.push_back(br);
   }
   
  
    std::vector<std::vector<int>>m;

    m=(UvrnutiPresjek(a.begin(),a.end(),b.begin(),b.end(),sumacifara));
    std::cout<<"Uvrnuti presjek kontejnera:"<<std::endl;

    for(int i=0; i<m.size(); i++) {
        for(int j=0; j<m[0].size(); j++) {
           
            std::cout<<std::right<<std::setw(6)<<m[i][j]<<" ";
        }
        std::cout<<std::endl;
    }

   std::vector<std::vector<int>>r;
    r=(UvrnutaRazlika(a.begin(),a.end(),b.begin(),b.end(),BrojProstihFaktora));

    std::cout<<"Uvrnuta razlika kontejnera:"<<std::endl;
    for(int i=0; i<r.size(); i++) {
        for(int j=0; j<r[0].size(); j++)
            std::cout<<std::right<<std::setw(6)<<r[i][j]<<" ";
        std::cout<<std::endl;
    }
    
    std::cout<<"Dovidjenja!";

    return 0;
}
