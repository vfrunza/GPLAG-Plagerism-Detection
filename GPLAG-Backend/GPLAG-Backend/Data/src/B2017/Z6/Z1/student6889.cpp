/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <functional>
#include <memory>
#include <vector>
#include <new>
#include <utility>

void KreiirajMatricu(int** &stra,int n,int m){
    stra=new int*[n];
    for(int i=0;i<n;i++) stra[i]=new int[m];
    
}






template <typename NekiTip>
void funkcija(NekiTip x){
    for(int c : x) std::cout << c ;
}


int Funkcija(int x){
    return x*x*x;
}
int Druga(int x){
    return x*x-2*x;
}
std::function<int(int)> NekaFunkcija(int f(int),int g(int)){
    return [f,g](int x){return f(x)+g(x);};
}
int main ()
{
    auto m=NekaFunkcija(Funkcija,Druga);
    std::cout << NekaFunkcija(Funkcija,Druga)(5) << std::endl;
    std::cout << m(5);
    std::vector<int> v{1,2,3,4,5,6};
    funkcija(v);
    std::cout << "\n";
    int **p;
    KreiirajMatricu(p,3,3);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++) std::cin >> p[i][j];
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++) std::cout << p[i][j] << " ";
        std::cout <<std::endl;
    }
    for(int i=0;i<3;i++) delete[] p[i];
    delete[] p;
	return 0;
}
