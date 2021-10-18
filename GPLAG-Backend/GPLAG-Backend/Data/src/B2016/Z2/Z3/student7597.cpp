#include <type_traits>
#include <iostream>
#include <stdexcept>
#include <deque>
#include <iomanip>
#include <vector>
#include <algorithm>
int SumaCifara (long long int a){
    int suma=0;
    if(a<0) a*=-1;
    while(a!=0){
        int cifra=a%10;
        suma+=cifra;
        a/=10;
    }
    return suma;
}
int SumaDjelilaca(long long int a){
    int suma=0;
    if(a<0) a*=-1;
    for(int i=1;i<=a;i++){
        if(a%i==0) suma+=i;
    }
    return suma;
}
int BrojProstihFaktora(long long int a){
    int br=0,j=2;
    if(a<0) a*=-1;
    while(a!=1){
        if(a%j==0){
            br++;
            a/=j;
        }
        else j++;
    }
    return br;
}
bool Savrsen(long long int a){
    int suma{};
    if(a<0) a*=-1;
    for(int i=1;i<=a/2;i++){
        if(a%i==0) suma+=i;
    }
    if(suma==a) return true;
    return false;
} 
int BrojSavrsenihDjelilaca(long long int a){
    int br{};
    if(a<0) a*=-1;
    for (int i=1;i<=a;i++){
        if(a%i==0&&Savrsen(i)) br++;
    }
    return br;
}

template <typename tip1,typename tip2,typename tip3,typename tip4>
auto UvrnutiPresjek(tip1 a,tip1 b,tip2 c,tip2 d,tip3 f(tip4))->std::vector<std::vector<typename std::remove_reference<decltype(*a+*c)>::type>>{
    int vel1=0,vel2=0;
    tip1 tmp{a};
    tip2 tmp2{c};
    while(tmp++!=b) vel1++;
    while(tmp2++!=d) vel2++;
    std::vector<std::vector<typename std::remove_reference<decltype(*a+*c)>::type>> final;
    int brojac=0;
    for(int i=0;i<vel1;i++){
        for(int j=0;j<vel2;j++){
            if(f(a[i])==f(c[j])){
                final.push_back(std::vector<typename std::remove_reference<decltype(*a+*c)>::type>());
                final[brojac].push_back(a[i]);
                final[brojac].push_back(c[j]);
                final[brojac].push_back(f(a[i]));
                brojac++;
            }
        }
    }
    
    std::sort(final.begin(),final.end(),[](std::vector<typename std::remove_reference<decltype(*a+*c)>::type> v1,std::vector<typename std::remove_reference<decltype(*a+*c)>::type>v2){
       return(v1[2]<v2[2]||(v1[2]==v2[2]&&v1[0]<v2[0])||(v1[2]==v2[2]&&v1[0]==v2[0]&&v1[1]<v2[1]));
    }); 
    return final;
}
template <typename tip1,typename tip2>
auto UvrnutiPresjek(tip1 a,tip1 b,tip2 c,tip2 d)->std::vector<std::vector<typename std::remove_reference<decltype(*a+*c)>::type>>{
    int vel1=0,vel2=0;
    tip1 tmp{a};
    tip2 tmp2{c};
    while(tmp++!=b) vel1++;
    while(tmp2++!=d) vel2++;
    std::vector<std::vector<typename std::remove_reference<decltype(*a+*c)>::type>> final;
    int brojac=0;
    for(int i=0;i<vel1;i++){
        for(int j=0;j<vel2;j++){
            if(a[i]==c[j]){
                final.push_back(std::vector<typename std::remove_reference<decltype(*a+*c)>::type>());
                final[brojac].push_back(a[i]);
                final[brojac].push_back(0);
                final[brojac].push_back(0);
                brojac++;
            }
        }
    }
    std::sort(final.begin(),final.end(),[](std::vector<typename std::remove_reference<decltype(*a+*c)>::type> v1,std::vector<typename std::remove_reference<decltype(*a+*c)>::type>v2){
        return v1[0]<v2[0];
    });
    return final;
}
template <typename tip1,typename tip2,typename tip3,typename tip4>
auto UvrnutaRazlika(tip1 a,tip1 b,tip2 c,tip2 d,tip3 f(tip4))->std::vector<std::vector<typename std::remove_reference<decltype(*a+*c)>::type>>{
    int vel1=0,vel2=0;
    tip1 tmp{a};
    tip2 tmp2{c};
    while(tmp++!=b) vel1++;
    while(tmp2++!=d) vel2++;
    std::vector<std::vector<typename std::remove_reference<decltype(*a+*c)>::type>> final;
    int brojac=0;
    for(int i=0;i<vel1;i++){
        bool dalisiilinisi=false;
        for(int j=0;j<vel2;j++){
            if(f(a[i])==f(c[j])){
              dalisiilinisi=true;
              break;
            }
        }
        if(!dalisiilinisi){
                final.push_back(std::vector<typename std::remove_reference<decltype(*a+*c)>::type>());
                final[brojac].push_back(a[i]);
                final[brojac].push_back(f(a[i]));
                brojac++;            
        }
    }
    brojac=final.size();
    for(int i=0;i<vel2;i++){
        bool dalisiilinisi=false;
        for(int j=0;j<vel1;j++){
            if(f(c[i])==f(a[j])){
              dalisiilinisi=true;
              break;
            }
        }
        if(!dalisiilinisi){
               final.push_back(std::vector<typename std::remove_reference<decltype(*a+*c)>::type>());
                final[brojac].push_back(c[i]);
                final[brojac].push_back(f(c[i]));
                brojac++;            
        }
    }
    
    std::sort(final.begin(),final.end(),[](std::vector<typename std::remove_reference<decltype(*a+*c)>::type> v1,std::vector<typename std::remove_reference<decltype(*a+*c)>::type>v2){
       return(v1[0]>v2[0]||(v1[0]==v2[0]&&v1[1]>v2[1]));
    }); 
    return final;
    
}
template <typename tip1,typename tip2>
auto UvrnutaRazlika(tip1 a,tip1 b,tip2 c,tip2 d)->std::vector<std::vector<typename std::remove_reference<decltype(*a+*c)>::type>>{
    int vel1=0,vel2=0;
    tip1 tmp{a};
    tip2 tmp2{c};
    while(tmp++!=b) vel1++;
    while(tmp2++!=d) vel2++;
    std::vector<std::vector<typename std::remove_reference<decltype(*a+*c)>::type>> final;
    int brojac=0;
    for(int i=0;i<vel1;i++){
        bool dalisiilinisi=false;
        for(int j=0;j<vel2;j++){
            if((a[i])==(c[j])){
              dalisiilinisi=true;
              break;
            }
        }
        if(!dalisiilinisi){
                final.push_back(std::vector<typename std::remove_reference<decltype(*a+*c)>::type>());
                final[brojac].push_back(a[i]);
                final[brojac].push_back(0);
                brojac++;            
        }
    }
    brojac=final.size();
    for(int i=0;i<vel2;i++){
        bool dalisiilinisi=false;
        for(int j=0;j<vel1;j++){
            if((c[i])==(a[j])){
              dalisiilinisi=true;
              break;
            }
        }
        if(!dalisiilinisi){
               final.push_back(std::vector<typename std::remove_reference<decltype(*a+*c)>::type>());
                final[brojac].push_back(c[i]);
                final[brojac].push_back(0);
                brojac++;            
        }
    }
    
    std::sort(final.begin(),final.end(),[](std::vector<typename std::remove_reference<decltype(*a+*c)>::type> v1,std::vector<typename std::remove_reference<decltype(*a+*c)>::type>v2){
       return(v1[0]>v2[0]);
    }); 
    return final;
    
}


int main ()
{
    std::cout<<"Unesite broj elemenata prvog kontejnera: ";
    int n;
    std::cin>>n;
    std::cout<<"Unesite elemente prvog kontejnera: ";
    std::vector<int> d1,d2;
    for(;;){
        if(d1.size()==n) break;
        bool bio=false;
        int tmp;
        std::cin>>tmp;
        for(int i=0;i<d1.size();i++) if(tmp==d1[i]) bio=true;
        if(!bio) d1.push_back(tmp);
    }
    
    std::cout<<"Unesite broj elemenata drugog kontejnera: ";
    std::cin>>n;
    std::cout<<"Unesite elemente drugog kontejnera: ";  
        for(;;){
        if(d2.size()==n) break;
        bool bio=false;
        int tmp;
        std::cin>>tmp;
        for(int i=0;i<d2.size();i++) if(tmp==d2[i]) bio=true;
        if(!bio) d2.push_back(tmp);
    }
    std::cout<<"Uvrnuti presjek kontejnera: "<<std::endl;
    std::vector<std::vector<int>> d3=UvrnutiPresjek(d1.begin(),d1.end(),d2.begin(),d2.end(),SumaCifara),d4=UvrnutaRazlika(d1.begin(),d1.end(),d2.begin(),d2.end(),BrojProstihFaktora);
    for(int i=0;i<d3.size();i++){
        for(int j=0;j<d3[i].size();j++) std::cout<<std::fixed<<std::setw(6)<<d3[i][j]<<" ";
        std::cout<<std::endl;
    }
    std::cout<<"Uvrnuta razlika kontejnera: "<<std::endl;
    for(int i=0;i<d4.size();i++){
        for(int j=0;j<d4[i].size();j++) std::cout<<std::setw(6)<<d4[i][j]<<" ";
        std::cout<<std::endl;
    }
    std::cout<<"Dovidjenja!";
	return 0;
} 

