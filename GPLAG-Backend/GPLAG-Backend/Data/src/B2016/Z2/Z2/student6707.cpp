// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	
#include <iostream>
#include <stdexcept>
#include <vector>


int main(){
 
 int a,b,c;
 std::cout<<"Unesite dimenzije (x y z): ";
 std::cin>>a>>b>>c;
 int broj;
 std::vector<std::vector<std::vector<int>>> v;
 
 v.resize(a);
 for(int i=0; i<b; i++)
 {
  v[i].resize(b);
 for (int j=0;j<c; j++) v[i][j].resize(c);
 }
 std::cout<<"Unesite elemente kontejnera: "<<std::endl;
 for(int i=0; i<a; i++)
 {
   for(int j=0; j<b; j++)
   {
    for(int k=0; k<c; k++)
    { 
     std::cin>>broj;
     v[i][j][k]=broj;
    }
   }
 }
 
 for(int i=0; i<a; i++)
 {
   for(int j=0; j<b; j++)
   {
    for(int k=0; k<c; k++)
    {
      std::cout<<v[i][j][k]<<" ";
    }
    std::cout<<std::endl;
   }
   std::cout<<std::endl;
 }
 
 
 
 
 return 0;
}