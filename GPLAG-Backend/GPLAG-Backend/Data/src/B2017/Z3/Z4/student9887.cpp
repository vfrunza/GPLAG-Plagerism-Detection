/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <new>
#include <stdexcept>
//tutorijal 6 zadatak 3
int** KreirajTrougao(int n)
{
    if(n<=0) throw std::domain_error("Broj redova mora biti pozitivan!\n");
    int** a=nullptr;
    try {
        a=new int*[n];
        for(int i=0; i<n; i++) {
            a[i]=nullptr;
        }
        for(int i=0; i<n; i++) {
            a[i]=new int[2*(i+1)-1];
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<(2*(i+1)-1); j++) {
                
                int broj_reda(i+1);
                while(j<=i) {
                        a[i][j]=broj_reda;
                        broj_reda--;
                        j++;
                    
                }
                 broj_reda+=2;
                while(j>i && j<(2*(i+1)-1)){
                   
                        
                        a[i][j]=broj_reda;
                        broj_reda++;
                        j++;
                    }
                

            }
        }
    } catch(...) {
        for(int i=0; i<n; i++) delete[] a[i];
        delete[] a;
        std::cout<<"Problemi sa memorijom";
    }
    return a;
}
int main ()
{ 
    std::cout<<"Koliko zelite redova: \n";
    int n;
    std::cin>>n;
    int** a=nullptr;
    try{
    a=KreirajTrougao(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<(2*(i+1)-1);j++){
            std::cout<<a[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    for(int i=0; i<n; i++) delete[] a[i];
        delete[] a;
    }
    catch(...){
        std::cout<<"Problemi sa memorijom\n";
    }
    return 0;
}
