#include <iomanip>
#include <vector>
#include <iostream>
#include <type_traits>
#include <algorithm>
#include <deque>
int SumaCifara(int n){
 int suma(0);
 while(n!=0){
     int c=n%10;
     suma+=c;
     n/=10;
 }
 return suma;
}
int SumaDjelilaca(long long int x){
    int suma(0);
    for(int i=1; i<=x; i++){
        if(x%i==0) suma+=i;
    }
    return suma;
}
int BrojProstihFaktora(long long int x){
    int brojac(0),d;
    for(int j=2; j<=x; j++){
        d=0;
        for(int i=2; i<j; i++){
            if(j%i==0){
                d=1;
                break;
            }
        }
        if(d==0){
            if(x%j==0) brojac++;
           if(x%(j*j)==0) brojac++;
          if(x%(j*j*j)==0) brojac++;
          if(x%(j*j*j*j)==0) brojac++;
          if(x%(j*j*j*j*j)==0) brojac++;
          if(x%(j*j*j*j*j*j)==0) brojac++;
           if(x%(j*j*j*j*j*j*j)==0) brojac++;
           if(x%(j*j*j*j*j*j*j*j)==0) brojac++;
        }
    }
    return brojac;
}
int BrojSavrsenihDjelilaca(long long int x){
    int brojac(0), suma(0);
    for(int i=2; i<=x; i++){
        if(x%i==0){
            suma=0;
            for(int j=1; j<i; j++){
                if(i%j==0) suma+=j;
            }
            if(suma==i) brojac++;
        }
    }
    
    return brojac;
}
template <typename pok1, typename pok2>
auto UvrnutiPresjek(pok1 pocetak1, pok1 kraj1, pok2 pocetak2, pok2 kraj2)
-> typename std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>>
{
    typedef typename std::remove_reference<decltype(*pocetak1)>::type parametar;
    std::vector<std::vector<parametar>> matrica(10,std::vector<parametar>(3,0));
    int brojac(0);
    auto rezervni=pocetak2;
    while(pocetak1!=kraj1){
        rezervni=pocetak2;
        while(rezervni!=kraj2){
            if(*pocetak1==*rezervni){
                matrica[brojac][0]=*pocetak1;
                brojac++;
                break;
            }
            rezervni++;
        }
        pocetak1++;
    }
    matrica.resize(brojac);
    sort(std::begin(matrica), std::end(matrica), [](std::vector<parametar>x, std::vector<parametar>y)->bool{
      if(x[2]<y[2]){
          return true;
      }else if(x[2]>y[2]){
          return false;
      }  else if(x[2]==y[2]){
          if(x[0]<y[0]){
              return true;
          } else if(x[0]>y[0]){
              return false;
          }else if(x[0]==y[0]){
              if(x[1]<=y[1]){
                  return true;
              }else if(x[1]>y[1]){
                  return false;
              }
          }
      }
        
    return false;    
    });
    
    return matrica;
}
    
    template <typename pok1, typename pok2, typename tip1, typename tip2>
    auto UvrnutiPresjek(pok1 pocetak1, pok1 kraj1, pok2 pocetak2, pok2 kraj2, tip1 pok_na_fun(tip2))
-> typename std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>>
{
    typedef typename std::remove_reference<decltype(*pocetak1)>::type parametar;
    std::vector<std::vector<parametar>> matrica(20,std::vector<parametar>(3,0));
    int brojac(0);
    auto rezervni=pocetak2;
    while(pocetak1!=kraj1){
        rezervni=pocetak2;
        while(rezervni!=kraj2){
            auto x=pok_na_fun(*pocetak1);
            auto y=pok_na_fun(*rezervni);
            if(x==y){
                matrica[brojac][0]=*pocetak1;
                 matrica[brojac][1]=*rezervni;
                  matrica[brojac][2]=x;
                  brojac++;
            }
            rezervni++;
        }
        pocetak1++;
    }
     matrica.resize(brojac);
    sort(std::begin(matrica), std::end(matrica), [](std::vector<parametar>x, std::vector<parametar>y)->bool{
      if(x[2]<y[2]){
          return true;
      }else if(x[2]>y[2]){
          return false;
      }  else if(x[2]==y[2]){
          if(x[0]<y[0]){
              return true;
          } else if(x[0]>y[0]){
              return false;
          }else if(x[0]==y[0]){
              if(x[1]<=y[1]){
                  return true;
              }else if(x[1]>y[1]){
                  return false;
              }
          }
      }
        
return false;       
    });
    return matrica;
}
   template <typename pok1, typename pok2>
    auto UvrnutaRazlika(pok1 pocetak1, pok1 kraj1, pok2 pocetak2, pok2 kraj2)
-> typename std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>>
{
    typedef typename std::remove_reference<decltype(*pocetak1)>::type parametar;
    std::vector<std::vector<parametar>> matrica(20,std::vector<parametar>(2,0));
    int brojac(0),d(0);
    auto drugi=pocetak1;
    auto rezervni=pocetak2;
    while(drugi!=kraj1){
        rezervni=pocetak2;
        while(rezervni!=kraj2){
            if(*drugi==*rezervni){
                d=1;
                break;
            }
            rezervni++;
        }
        if(d==0){
        matrica[brojac][0]=*drugi;
                brojac++;
                d=0;
        }
        drugi++;
    }
    d=0;
     while(pocetak2!=kraj2){
        rezervni=pocetak1;
        d=0;
        while(rezervni!=kraj1){
            if(*pocetak2==*rezervni){
                d=1;
                break;
            }
            rezervni++;
        }
        if(d==0){
        matrica[brojac][0]=*pocetak2;
                brojac++;
                d=0;
        }
        pocetak2++;
    }
    matrica.resize(brojac);
    sort(std::begin(matrica), std::end(matrica), [](std::vector<parametar>x, std::vector<parametar>y)->bool{
      if(x[1]>y[1]){
          return true;
      }else if(x[1]<y[1]){
          return false;
      }  else if(x[1]==y[1]){
          if(x[0]>=y[0]){
              return true;
          } else if(x[0]<y[0]){
              return false;
          }
      }
    return false;    
    });
    
    return matrica;
}

    template <typename pok1, typename pok2, typename tip1, typename tip2>
    auto UvrnutaRazlika(pok1 pocetak1, pok1 kraj1, pok2 pocetak2, pok2 kraj2, tip1 pok_na_fun(tip2))
-> typename std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>>
{
    typedef typename std::remove_reference<decltype(*pocetak1)>::type parametar;
    std::vector<std::vector<parametar>> matrica(20,std::vector<parametar>(2,0));
    int brojac(0),k(0),var1;
    auto rezervni=pocetak2;
    auto drugi=pocetak1;
    while(drugi!=kraj1){
        rezervni=pocetak2;
        while(rezervni!=kraj2){
            auto x=pok_na_fun(*drugi);
            auto y=pok_na_fun(*rezervni);
             var1=x;
            if(x==y){
            k=1;
                break;
            }
            rezervni++;
        }
        if(k==0){
            matrica[brojac][0]=*drugi;
           matrica[brojac][1]=var1;
                 brojac++;
        }
        drugi++;
        k=0;
    }
    k=0;
    int var2;
    while(pocetak2!=kraj2){
        rezervni=pocetak1;
        while(rezervni!=kraj1){
            auto x=pok_na_fun(*pocetak2);
            auto y=pok_na_fun(*rezervni);
            var2=x;
            if(x==y){
            k=1;
                break;
            }
            rezervni++;
        }
        if(k==0){
            matrica[brojac][0]=*pocetak2;
           matrica[brojac][1]=var2;
                 brojac++;
        }
        pocetak2++;
        k=0;
    }
     matrica.resize(brojac);
    sort(std::begin(matrica), std::end(matrica), [](std::vector<parametar>x, std::vector<parametar>y)->bool{
      if(x[0]<y[0]){
          return false;
      }else if(x[0]>y[0]){
          return true;
      }  else if(x[0]==y[0]){
          if(x[1]<y[1]){
              return false;
          } else if(x[1]>=y[1]){
              return true;
          }
          }
      
        
    return false;    
    });
    return matrica;
}

int main ()
{
  std::deque<long long int> d1;  
  std::deque<long long int> d2;
  int n,m,a,b,k,brojac(0);
  std::cout<<"Unesite broj elemenata prvog kontejnera: ";
   std::cin>>n;
   std::cout<<"Unesite elemente prvog kontejnera: ";
 
   while(brojac<n){
       std::cin>>a;
       k=0;
       for(int j=0; j<brojac; j++){
           if(d1[j]==a){
             k=1;
             break;
           } 
       }
       if(k==0) {
           d1.push_back(a);
           brojac++;
       }
   }
   brojac=0;
   std::cout<<"Unesite broj elemenata drugog kontejnera: ";
   std::cin>>m;
   std::cout<<"Unesite elemente drugog kontejnera: ";
   while(brojac<m){
       std::cin>>b;
       k=0;
       for(int j=0; j<brojac; j++){
           if(d2[j]==b){
             k=1;
             break;
           } 
       }
       if(k==0){ d2.push_back(b);
       brojac++;
       }
   }
   auto M=UvrnutiPresjek(d1.begin(), d1.end(), d2.begin(), d2.end(), SumaCifara);
   std::cout<<"Uvrnuti presjek kontejnera: "<<std::endl;
    for(int i=0; i<M.size(); i++){
        for(int j=0; j<M[i].size(); j++){
            std::cout<<std::setw(6)<<M[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    auto N=UvrnutaRazlika(d1.begin(), d1.end(), d2.begin(), d2.end(), BrojProstihFaktora);
    std::cout<<"Uvrnuta razlika kontejnera: "<<std::endl;
    for(int i=0; i<N.size(); i++){
        for(int j=0; j<N[i].size(); j++){
            std::cout<<std::setw(6)<<N[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<"Dovidjenja!";
    return 0;
}