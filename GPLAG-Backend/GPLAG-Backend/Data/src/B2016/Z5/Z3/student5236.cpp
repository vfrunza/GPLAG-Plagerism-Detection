/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <vector>
#include <cmath>
class Razlomak{
       mutable long long int nazivnik; mutable long long int brojnik;
    public:
    Razlomak(  long long int brojnik1,  long long int nazivnik1){
        nazivnik=nazivnik1;brojnik=brojnik1;
        if(nazivnik<0){
            brojnik=-brojnik;
            nazivnik=fabs(nazivnik1);
        }else if(brojnik<0 && nazivnik<0){
            brojnik=fabs(brojnik1);
            nazivnik=fabs(nazivnik1);
        }
        SkratiRazlomak(brojnik,nazivnik);
    }
    Razlomak(long long int brojnik1){
       brojnik=brojnik1;nazivnik=1;
    }
    Razlomak(){
        brojnik=0;nazivnik=1;
    }
    static void SkratiRazlomak(long long int &brojnik,long long int &nazivnik){
        int d=2;
        std::vector<int>v1;
        int br1=fabs(brojnik);
        while(br1!=1){
            if(br1%d==0){
                br1=br1/d;
                v1.push_back(d);
            }else if(br1%d!=0){
                d++;
            }
        }
        d=2;
        std::vector<int>v2;
        int nk1=fabs(nazivnik);
        while(nk1!=1){
            if(nk1%d==0){
                nk1=nk1/d;
                v2.push_back(d);
            }else if(nk1%d!=0){
                d++;
            }
        }
        std::vector<int>v3;
        
        for(int i=0;i<v1.size();i++){
            for(int j=0;j<v2.size();j++){
                if(v1[i]==v2[j]){
                    v3.push_back(v1[i]);
                    break;
                }
            }
     }
    int p=1;
    for(int x:v3){
       p=p*x; 
    }
    brojnik=brojnik/p;
    nazivnik=nazivnik/p;
   }
   static int NZD(const long long int brojnik,const long long int nazivnik){
       int d=2;
       std::vector<int>v1;
       int br1=fabs(brojnik);
       while(br1!=1){
           if(br1%d==0){
               br1=br1/d;
               v1.push_back(d);
           }else if(br1%d!=0){
               d++;
           }
       }
       d=2;
       std::vector<int>v2;
       int nk1=fabs(nazivnik);
       while(nk1!=1){
           if(nk1%d==0){
               nk1=nk1/d;
               v2.push_back(d);
           }else if(nk1%d!=0){
               d++;
           }
       }
       std::vector<int>v3;
       
       for(int i=0;i<v1.size();i++){
           for(int j=0;j<v2.size();j++){
               if(v1[i]==v2[j]){
                   v3.push_back(v1[i]);
                   break;
               }
           }
       }
       int p=1;
       for(int x:v3){
           p=p*x;
       }
       return p;
   }
   friend std::ostream &operator <<(std::ostream &tok,const Razlomak &r){
       
       if(r.brojnik!=0 && r.nazivnik!=1){
   return tok<<r.brojnik<<"/"<<r.nazivnik;
       }else if(r.brojnik==0){
           return tok<<"0";
       }else if(r.nazivnik==1)
           return tok<<r.brojnik;
       
   }
   friend std::istream &operator >>(std::istream &tok,const Razlomak &r){
       char znak;
      tok>>r.brojnik;
        if(tok.peek()!='/'){
           r.nazivnik=1;
       }
       else{
           tok>>znak;
           if(znak !='/')tok.setstate(std::ios::failbit);
           tok>>r.nazivnik;
           SkratiRazlomak(r.brojnik,r.nazivnik);
          }
       
       return tok;
       
   }
   long long int DajBrojnik()const{return brojnik;}
   long long int DajNazivnik()const{return nazivnik;}
   friend Razlomak operator +(const Razlomak &r1,const Razlomak &r2);
   friend Razlomak operator -(const Razlomak &r1,const Razlomak &r2);
   friend Razlomak operator *(const Razlomak &r1,const Razlomak &r2);
   friend Razlomak operator /(const Razlomak &r1,const Razlomak &r2);
   
};
Razlomak operator +(const Razlomak &r1,const Razlomak &r2){
    return {r1.brojnik*(r2.nazivnik/Razlomak::NZD(r1.nazivnik,r2.nazivnik)) + r2.brojnik*(r1.nazivnik/Razlomak::NZD(r1.nazivnik,r2.nazivnik)), r1.nazivnik*(r2.nazivnik/Razlomak::NZD(r1.nazivnik,r2.nazivnik))};
}
Razlomak operator -(const Razlomak &r1,const Razlomak &r2){
    return {r1.brojnik*(r2.nazivnik/Razlomak::NZD(r1.nazivnik,r2.nazivnik)) - r2.brojnik*(r1.nazivnik/Razlomak::NZD(r1.nazivnik,r2.nazivnik)), r1.nazivnik*(r2.nazivnik/Razlomak::NZD(r1.nazivnik,r2.nazivnik))};
}
Razlomak operator *(const Razlomak &r1,const Razlomak &r2){
    return {(r1.brojnik/Razlomak::NZD(r1.brojnik,r2.nazivnik))*(r2.brojnik/Razlomak::NZD(r2.brojnik,r1.nazivnik)), (r1.nazivnik/Razlomak::NZD(r2.brojnik,r1.nazivnik))*(r2.nazivnik/Razlomak::NZD(r1.brojnik,r2.nazivnik))};
}
Razlomak operator /(const Razlomak &r1,const Razlomak &r2){
    return {(r1.brojnik/Razlomak::NZD(r1.brojnik,r2.brojnik))*(r2.nazivnik/Razlomak::NZD(r1.nazivnik,r2.nazivnik)), (r1.nazivnik/Razlomak::NZD(r1.nazivnik,r2.nazivnik))*(r2.brojnik/Razlomak::NZD(r1.brojnik,r2.brojnik))};
}
int main ()
{
    Razlomak r3;
    std::cin>>r3;
    std::cout<<r3;
    Razlomak r{10,15};
    Razlomak r1(2,4);
    Razlomak r2;
    r2=r/r1;
    std::cout<<"r2="<<r2;
	return 0;
}