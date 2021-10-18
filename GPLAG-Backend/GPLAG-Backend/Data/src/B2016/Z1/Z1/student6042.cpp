#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>



    int Pretvorba(int dec) {
        int broj=dec;
        if (dec<0) dec=-dec; 
    int rem,i=1,sum=0;
    do {
        rem=dec%3;
        sum=sum + (i*rem);
        dec=dec/3;
        i=i*10;
    } while(dec>0);
    if (broj<0) { sum=-sum; return sum; }
    return sum;
    }


int Provjera (int n) {
    if (n>60000) return -1;
int broj=(Pretvorba(n));
int brojaci_0=0,brojaci_1=0,brojaci_2=0;
while (broj!=0) {
    int Broj=broj%10;
    if (Broj==0) brojaci_0++;
    if (Broj==1) brojaci_1++;
    if (Broj==2) brojaci_2++;
    broj/=10;
} 
if ( (brojaci_0%2==0 && brojaci_1%2==0 && brojaci_2%2==0) || (brojaci_0==0 && brojaci_1%2==0 && brojaci_2%2==0) || (brojaci_1==0 && brojaci_0%2==0 && brojaci_2%2==0) || (brojaci_2==0 && brojaci_0%2==0 && brojaci_1%2==0) || (brojaci_0==0 && brojaci_1==0 && brojaci_2%2==0) || (brojaci_1==0 && brojaci_2==0 && brojaci_0%2==0) || (brojaci_2==0 && brojaci_0==0 && brojaci_1%2==0) || (brojaci_0==0 && brojaci_1==0 && brojaci_2%2==0) || (brojaci_0==0 && brojaci_2==0 && brojaci_1%2==0) || (brojaci_1==0 && brojaci_2==0 && brojaci_0%2==0) ) 
    return 1;
if ( (brojaci_0%2!=0 && brojaci_1%2!=0 && brojaci_2%2!=0) || (brojaci_0==0 && brojaci_1%2!=0 && brojaci_2%2!=0) || (brojaci_1==0 && brojaci_0%2!=0 && brojaci_2%2!=0) || (brojaci_2==0 && brojaci_0%2!=0 && brojaci_1%2!=0) || (brojaci_0==0 && brojaci_1%2!=0 && brojaci_2%2!=0) || (brojaci_1==0 && brojaci_2%2!=0 && brojaci_0%2!=0) || (brojaci_2==0 && brojaci_0%2!=0 && brojaci_1%2!=0) || (brojaci_0==0 && brojaci_1==0 && brojaci_2%2!=0) || (brojaci_0==0 && brojaci_2==0 && brojaci_1%2!=0) || (brojaci_1==0 && brojaci_2==0 && brojaci_0%2!=0) ) 
    return 0;

return -1;
}




std::vector<int> duplikati (std::vector<int> vec) {
    for (int i=0;i<vec.size();i++) {
        for (int j=0;j<vec.size();j++) {
            if (vec[i]==vec[j] && i!=j ) { vec.erase(vec.begin()+j); j--; }
        }
    }
    return vec;
}







std::vector<int> IzdvojiGadne(const std::vector<int>&a,bool n) {
   std::vector <int> b;
   for (int broj : a) {
    if (n==true && Provjera(broj)==1) {
         b.push_back(broj);
      }
      else if (n==false && Provjera(broj)==0) {
         b.push_back(broj);
      }
      else continue;
   }
    b=duplikati(b);
   return b;
}








int main () {
   
    std::cout<<"Unesite brojeve (0 za prekid unosa): ";
      std::vector<int> v;
      int i;
      int broj;
      for ( i=0;i<100;i++) {
         std::cin>>broj;
         if (broj==0) break;
         v.push_back(broj);
      }

      
     
     auto opaki = IzdvojiGadne(v, true);
      std::cout<<"Opaki: ";
      opaki=duplikati(opaki);
      for  (auto x : opaki) {
         std::cout<<x<<" ";
      }
      std::cout<<std::endl;

      
    auto odvratni=IzdvojiGadne(v,false);
      std::cout<<"Odvratni: ";
      odvratni=duplikati(odvratni);
    for (auto x : odvratni) {
         std::cout<<x<<" ";
      }
 
 
 
 return 0; 
}
