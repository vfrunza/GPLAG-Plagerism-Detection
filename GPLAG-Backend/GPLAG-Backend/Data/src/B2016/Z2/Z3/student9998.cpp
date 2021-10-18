#include<iostream>
#include<vector>
#include<algorithm>
#include<type_traits>
#include<iomanip>
#include<deque>
#include<cstdlib>

int SumaDjelilaca (long long int n){ //za min_int max_int
    long long int suma=0;
    for(int i=1;i<=abs(n);i++){
        if(n%i==0) suma+=i;
    }
    return suma;
}

int SumaCifara(long long int n){
    long long int suma=0;
    if(n<0) n=-n;
    while(n!=0){
        suma+=n%10;
        n/=10;
    }
    return suma;
}


int BrojProstihFaktora (long long int n){ //max int i sta za negativne brojeve
    long long int broj=0;
    for(int i=2;i<=n;i++){
        if(n%i==0){ 
            broj++;
            n/=i;
            i--;
        }
    }
    return broj;
}

bool savrsen(int n){
    if(n<=0) return false;
    int suma=0;
    for(int i=1;i<=n/2;i++){
        if(n%i==0) suma+=i;
    }
   return suma==n;
}

int BrojSavrsenihDjelilaca(long long int n){ //max int
    long long int broj=0;
    for(int i=1;i<=n;i++){
        if(n%i==0 && savrsen(i)) broj++;
    }
    return broj;
}


template<typename iter_pok1, typename iter_pok2>

auto UvrnutiPresjek (iter_pok1 p1, iter_pok1 k1, iter_pok2 p2, iter_pok2 k2)->std::vector<std::vector<typename std::remove_reference<decltype(*p1+*p2)>::type>> { //ispravi ovo, pomocna 
    std::vector<std::vector<typename std::remove_reference<decltype(*p1+*p2)>::type>>mat;

        while(p1!=k1){
            auto j=p2;
            while(j!=k2){
                if(*p1==*j){
                   mat.push_back({*p1,0,0});
                }
                j++;
            }
            p1++;
        }
        
        std::sort(mat.begin(), mat.end(), [](std::vector<typename std::remove_reference<decltype(*p1+*p2)>::type>red1, std::vector<typename std::remove_reference<decltype(*p1+*p2)>::type> red2){
            if(red1[2]==red2[2]){
                if(red1[0]!=red2[0]) return red1[0]<red2[0];
                else return red1[1]<red1[1];
            }
            return red1[2]<red2[2];
        });
        
        return mat;
}
   
   
    
    template<typename iter_pok1, typename iter_pok2,typename tip1, typename tip2>
    
auto UvrnutiPresjek(iter_pok1 p1,iter_pok1 k1, iter_pok2 p2, iter_pok2 k2, tip1 (*f)(tip2)) -> std::vector<std::vector<typename std::remove_reference<decltype(*p1+*p2)>::type>> {
    std::vector<std::vector<typename std::remove_reference<decltype(*p1+*p2)>::type>>mat ;
    
    //popuni matricu
        while(p1!=k1){
            iter_pok2 j=p2;
            while(j!=k2){
                if(f(*p1)==f(*j)){
                    mat.push_back({*p1,*j,f(*p1)});
                    
                }
                j++;
            }
            p1++;
        }
        
    // sortiraj
    std::sort(mat.begin(), mat.end(),[](std::vector<typename std::remove_reference<decltype(*p1+*p2)>::type>red1, std::vector<typename std::remove_reference<decltype(*p1+*p2)>::type>red2){ //tip
        if(red1[2]==red2[2]){
            if(red1[0]!=red2[0]) return red1[0]<red2[0];
            else return red1[1]<red2[1];
        }
        return red1[2]<red2[2];
    });
   
    return mat;
}



template<typename iter_pok1, typename iter_pok2>

auto UvrnutaRazlika (iter_pok1 p1, iter_pok1 k1, iter_pok2 p2, iter_pok2 k2)->std::vector<std::vector<typename std::remove_reference<decltype(*p1+ *p2)>::type>>{
    
     std::vector<std::vector<typename std::remove_reference<decltype(*p1+*p2)>::type>>mat;
     
        iter_pok1 p=p1;
        while(p!=k1){
            auto j=p2;
            bool ima=false; //ima istih
            while(j!=k2){
                if(*p==*j) {ima=true; break;}
                j++;
            }
            if(!ima) mat.push_back({*p,0});
            p++;
        }
        
        while(p2!=k2){
            auto j=p1;
            bool ima=false;
            while(j!=k1){
                if(*p2==*j) {ima=true; break;}
                j++;
            }
           if(!ima) mat.push_back({*p2,0});
            p2++;
        }
         
     
     std::sort(mat.begin(), mat.end(), [](std::vector<typename std::remove_reference<decltype(*p1+*p2)>::type>red1, std::vector<typename std::remove_reference<decltype(*p1+*p2)>::type>red2){
         if(red1[0]==red2[0]){
             return red1[1]>red2[1];
         }
         return red1[0]>red2[0];
     });
     
     return mat;
}

     
template<typename iter_pok1, typename iter_pok2, typename tip1, typename tip2>
auto UvrnutaRazlika(iter_pok1 p1, iter_pok1 k1, iter_pok2 p2, iter_pok2 k2, tip1 (*f)(tip2))->std::vector<std::vector<typename std::remove_reference<decltype(*p1+*p2)>::type>>{

std::vector<std::vector<typename std::remove_reference<decltype(*p1+*p2)>::type>> mat;
     iter_pok1 prvi=p1;
     iter_pok2 drugi=p2;
     
     while(p1!=k1){
         auto j=p2;
         bool ima=false;
         while(j!=k2){
             if(f(*p1)==f(*j)){
                ima=true;
                break;
             }
             j++;
         }
         if(!ima){ 
             mat.push_back({*p1,f(*p1)});
         }
         p1++;
     }
     
      while(drugi!=k2){
         auto j=prvi;
         bool ima=false;
         while(j!=k1){
             if(f(*drugi)==f(*j)){
                 ima=true;
                 break;
             }
             j++;
         }
         if(!ima){
             mat.push_back({*drugi,f(*drugi)});
         }
         drugi++;
     }
     
     
     std::sort(mat.begin(), mat.end(),[](std::vector<typename std::remove_reference<decltype(*p1+*p2)>::type> red1, std::vector<typename std::remove_reference<decltype(*p1+*p2)>::type> red2){ //tip
         if(red1[0]==red2[0]){
             return red1[1]>red2[1];
         }
         return red1[0]>red2[0];
     });
    
    return mat;
}


int main ()
{
    std::deque<int>d1, d2;
    std::cout<<"Unesite broj elemenata prvog kontejnera: ";
    int n1;
    std::cin>>n1;
    std::cout<<"Unesite elemente prvog kontejnera: ";
    for(int i=0;i<n1;i++){
        int a;
        std::cin>>a;
        if(std::find(d1.begin(),d1.end(),a)==d1.end()) d1.push_back(a);
        else i--;
    }
    
    
    std::cout<<"Unesite broj elemenata drugog kontejnera: ";
    int n2;
    std::cin>>n2;
    
    std::cout<<"Unesite elemente drugog kontejnera: ";
    for(int i=0;i<n2;i++){
        int b;
        std::cin>>b;
        if(std::find(d2.begin(),d2.end(),b)==d2.end()) d2.push_back(b);
        else i--;
    }
  
    std::cout<<"Uvrnuti presjek kontejnera:"<<std::endl;
    std::vector<std::vector<int>>mat=UvrnutiPresjek(d1.begin(),d1.end(),d2.begin(),d2.end(),SumaCifara);
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[i].size();j++)
        std::cout<<std::setw(6)<<mat[i][j]<<" ";
        std::cout<<std::endl;
    }
    
    std::cout<<"Uvrnuta razlika kontejnera:"<<std::endl;
    std::vector<std::vector<int>>mat1=UvrnutaRazlika(d1.begin(),d1.end(), d2.begin(), d2.end(),BrojProstihFaktora);
    for(int i=0;i<mat1.size();i++){
        for(int j=0;j<mat1[i].size();j++)
            std::cout<<std::setw(6)<<mat1[i][j]<<" ";
            std::cout<<std::endl;
    }
    
    std::cout<<"Dovidjenja!";
	return 0;
}