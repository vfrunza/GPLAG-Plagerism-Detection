#include <iostream>
int main ()
{
    int a,i,suma,b=1;
    while(b==1) {
        std::cout<<"Unesite prirodan broj ili 0 za kraj: ";
        std::cin>>a;
        if(a!=0) {
            if(a<0) std::cout<<"Niste unijeli prirodan broj!\n";
            else {
                suma=0;
                for(i=a-1; i>0; i--) {
                    if(a%i==0)
                        suma+=i;
                }
                if(suma>a)
                    std::cout<<"Broj "<< a <<" je obilan!\n";
                else if(suma==a)
                    std::cout<<"Broj "<< a <<" je savrsen!\n";
                else
                    std::cout<<"Broj "<< a <<" je manjkav!\n";
            }
        }
        if(a==0) b=0;
    }
    std::cout<<"Dovidjenja!\n";
    return 0;
}